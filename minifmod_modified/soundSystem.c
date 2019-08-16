#include "soundSystem.h"
#include "../defs.h"
#include <math.h>


int (__cdecl *FSOUND_File_OpenCallback_456C9C)(_DWORD) = NULL; // weak
int (__cdecl *FSOUND_File_CloseCallback_456CA0)(_DWORD) = NULL; // weak
int (__cdecl *FSOUND_File_ReadCallback_456CA4)(_DWORD, _DWORD, _DWORD) = NULL; // weak
int (__cdecl *FSOUND_File_SeekCallback_456CA8)(_DWORD) = NULL; // weak
int (__cdecl *FSOUND_File_TellCallback_456CAC)(_DWORD) = NULL; // weak

int debug2=1;
char streamId_4444F8[] = "Extended Module:"; // weak
char byte_456C35 = '\0'; // weak

FMUSIC_MODULE * FMUSIC_PlayingSong_456C30 = NULL; // weak

int FSOUND_Software_FillBlock_456C3C = 0; // weak
int FSOUND_BufferSize_45C4C4; // weak
int FSOUND_MixRate_456A40 = 44100; // weak
int FSOUND_BufferSizeMs_456A44 = 1000; // weak
int dword_456C44 = 0; // weak
int dword_456C48 = 0; // weak
int dword_456C4C = 0; // weak
int dword_456C50 = 0; // weak
int dword_456C54 = 0; // weak
int mix_volumerampsteps_456C94 = 0; // weak
float mix_1overvolumerampsteps_456C98 =  0.0; // weak

signed char		* FSOUND_MixBuffer_45DA60; // weak
signed char		* FSOUND_MixBufferMem_45DA64; // idb
int FSOUND_BlockSize_45DA68; // weak
int FMUSIC_DummySample_45DA80; // weak
FMUSIC_TIMMEINFO *FMUSIC_TimeInfo_45DAB0; // idb
float FSOUND_OOMixRate_45DAB4; // weak

void *Memory; // idb


static unsigned int mix_numsamples	= 0;	// number of samples to mix 
static unsigned int mix_mixptr		= 0;
static unsigned int mix_mixbuffend	= 0;
static unsigned int mix_mixbuffptr	= 0;
static unsigned int mix_endflag		= 0;
static unsigned int mix_sptr		= 0;
static unsigned int mix_cptr		= 0;
static unsigned int mix_count		= 0;
static unsigned int mix_samplebuff	= 0;
static float		mix_leftvol		= 0;
static float		mix_rightvol	= 0;
static unsigned int mix_temp1		= 0;

static unsigned int mix_count_old	= 0;
static unsigned int mix_rampleftvol = 0;
static unsigned int mix_ramprightvol= 0;
static unsigned int mix_rampcount	= 0;
static unsigned int mix_rampspeedleft	= 0;
static unsigned int mix_rampspeedright	= 0;
//unsigned int		mix_volumerampsteps	= 0;
//float				mix_1overvolumerampsteps = 0;

static const float	mix_255			= 255.0f;	
static const float	mix_256			= 256.0f;	
static const float	mix_1over255	= 1.0f / 255.0f;	
static const float	mix_1over256	= 1.0f / 256.0f;
static const float	mix_1over2gig	= 1.0f / 2147483648.0f;

int __cdecl FMUSIC_UpdateXM_43EF50(FMUSIC_MODULE *mod)
{
  return FMUSIC_UpdateXMEffects_43EDC0(mod);
}

//----- (0043AD80) --------------------------------------------------------
void *__cdecl FSOUND_File_OpenCallback_43AD80(int size,char *data)
//void *__cdecl sub_43AD80(int soundEffectSize)
{
  const void *v1; // esi@1
  size_t v2; // edi@1
  void *v3=calloc(0xCu, 1u); // eax@1//estructura handle
  struct_userhandle *handle; // ebx@1
  void *v5; // eax@1
  unsigned int v6; // ecx@1

 // v1 = data + 4;
  //v1 = &soundEffectSize + 4;
  //v1 = *(const void **)(a1 + 4);
  v2 = size;//strlen(name); //es el tamaño del audio
  //v2 = *(_DWORD *)soundEffectSize; //es el tamaño del audio
 // v3 = calloc(0xCu, 1u);
  handle = v3;
  *(_DWORD *)v3 = v2;
  v5 = calloc(v2, 1u);

 // v1 = calloc(v2, 1u);//esto lo he puesto yo para que no falle
 // v6 = *(_DWORD *)handle; //v4 es el tamaño del audio
 v6 = handle->size; //v4 es el tamaño del audio
  //*((_DWORD *)handle + 2) = v5;//handle->data
  handle->data = v5;//handle->data
  //*((_DWORD *)handle + 1) = 0;//handle->pos
  handle->pos = 0;//handle->pos
  //memcpy(v5, name, v2);//copiar estructura handle en handle 
  //fix a esto que no se sabe el tama?o porque es un string
  handle->data = data;
  return handle;
}

//----- (0043ADD0) --------------------------------------------------------
void __cdecl FSOUND_File_CloseCallback_43ADD0(unsigned int handle)
{
  //free(*((void **)handle + 2));free del handle->data
  free((void *)handle);
}

 void *qmemcpy(void *dst, const void *src, size_t cnt)
{
  char *out = (char *)dst;
  const char *in = (const char *)src;
  while ( cnt > 0 )
  {
    *out++ = *in++;
    --cnt;
  }
  return dst;
}
//----- (0043ADF0) --------------------------------------------------------
int __cdecl FSOUND_File_ReadCallback_43ADF0(void *buffer, int size, unsigned int handle)
{
  
 struct_userhandle *handleTemp =(struct_userhandle *)handle;
  int result; // eax@1
  int v4; // edi@1
  ///parece que mueve el puntero y cmabia el userhandle para no tener que hacer el file seek 
  result = size;
  //v4 = *(_DWORD *)(handle + 4);  //esto es la pos
  v4 = handleTemp->pos;
  //if ( (signed int)(v4 + size) >= *(_DWORD *)handle )
  if ( handleTemp->pos + size >= handleTemp->size )
    //result = *(_DWORD *)handle - v4;
    result = handleTemp->size - handleTemp->pos;
  //memcpy(buffer, (const void *)(v4 + *(_DWORD *)(handle + 8)), result); //handle +8 es data
   memcpy(buffer, &handleTemp->data[handleTemp->pos], result); //handle +8 es data
  
  //*(_DWORD *)(handle + 4) += result;
  handleTemp->pos +=result;
  return handleTemp->pos;
}

//----- (0043AE30) --------------------------------------------------------
int __cdecl FSOUND_File_SeekCallback_43AE30(unsigned int handle, int pos, signed char mode)
{
  int result; // eax@1
  int v4; // ecx@2
  int v5; // edx@4
  int v6; // ecx@4
  struct_userhandle *handleTemp = (struct_userhandle *)handle;
  result = handle;
  if ( mode )
  {
    if ( mode == 1 )
    {
      v5 = pos;
      //v6 = *(_DWORD *)(handle + 4);
	  v6 = handleTemp->pos;
    }
    else
    {
      if ( mode != 2 )
        goto LABEL_9;
      v6 = handleTemp->size;
	  //v6 = *(_DWORD *)handle;
      v5 = pos;
    }
    v4 = v5 + v6;
  }
  else
  {
    v4 = pos;
  }
  //*(_DWORD *)(handle + 4) = v4;
  handleTemp->pos = v4;
LABEL_9:
  if ( handleTemp->pos > handleTemp->size)
  //if ( *(_DWORD *)(handle + 4) > *(_DWORD *)handle )
    handleTemp->pos = handleTemp->size;
	//*(_DWORD *)(handle + 4) = *(_DWORD *)handle;
  return result;
}

//----- (0043AE70) --------------------------------------------------------
int __cdecl FSOUND_File_TellCallback_43AE70(unsigned int handle)
{
//  return *(_DWORD *)(a1 + 4);
	struct_userhandle *handleTemp = (struct_userhandle *)handle;
  
	return handleTemp->pos;
}

//----- (0043D8A0) --------------------------------------------------------
unsigned __int64 __cdecl FMUSIC_SetBPM_43D8A0(FMUSIC_MODULE *mod_456C24, int bpm)
{
  unsigned __int64 result; // rax@1

  mod_456C24->bpm = bpm;
  result = (unsigned __int64)(1000.0 / ((double)bpm * 0.40000001) * (double)FSOUND_MixRate_456A40 * 0.001);
  //result =882; //todo fix
  mod_456C24->mixer_samplespertick = result;
  return result;
}
// 456A40: using guessed type int FSOUND_MixRate_456A40;
//----- (0043D8E0) --------------------------------------------------------
char __cdecl FMUSIC_StopSong_43D8E0(FMUSIC_MODULE *mod)
{
  char result; // al@2

  if ( mod )
  {
    if ( FSOUND_MixBufferMem_45DA64)
    {
      free(FSOUND_MixBufferMem_45DA64);
      FSOUND_MixBufferMem_45DA64= 0;
    }
    FMUSIC_PlayingSong_456C30= 0;
    if ( FMUSIC_TimeInfo_45DAB0)
    {
      free(FMUSIC_TimeInfo_45DAB0);
      FMUSIC_TimeInfo_45DAB0 = 0;
    }
    FSOUND_Software_FillBlock_456C3C = 0;
    FSOUND_Software_RealBlock = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
  
}
//----- (0043D940) --------------------------------------------------------
char __cdecl FMUSIC_FreeSong_43D940(FMUSIC_MODULE *mod)
{
  void *v1; // edi@1
  char result; // al@2
  int v3; // esi@7
  int v4; // eax@7
  int v5; // esi@7
  int v6; // ebx@7
  int v7; // ebp@8
  void **v8; // edi@9
  int v9; // ecx@13
  bool v10; // sf@13
  unsigned __int8 v11; // of@13
  int i; // esi@17
  int v13; // [sp+8h] [bp-8h]@6
  int v14; // [sp+Ch] [bp-4h]@5

  v1 = Memory;
  if ( mod )
  {
    while ( byte_456C35 )//while(FSOUND_Software_UpdateMutex);
      ;
    FMUSIC_StopSong_43D8E0(mod);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 456C35: using guessed type char byte_456C35;

//----- (0043DA40) --------------------------------------------------------
char __cdecl FMUSIC_PlaySong_43DA40(FMUSIC_MODULE *mod_456C24) //a1
{
  signed int v1; // edi@7
  int v2; // esi@7
  int v3; // ecx@7
  signed int v4; // eax@7
  signed int v5; // ecx@9
  int v6; // edx@9
  signed int v7; // edx@9
  int v8; // ecx@10
  _UNKNOWN *v9; // eax@10
  void *v10; // eax@12
  char result; // al@12
  FMUSIC_CHANNEL	*cptr;

  //FMUSIC_StopSong_43D8E0(mod_456C24);
  if ( mod_456C24 && (FMUSIC_StopSong_43D8E0(mod_456C24), FSOUND_File_OpenCallback_456C9C) && FSOUND_File_CloseCallback_456CA0 && FSOUND_File_ReadCallback_456CA4 && FSOUND_File_SeekCallback_456CA8 && FSOUND_File_TellCallback_456CAC )
  {
    FSOUND_OOMixRate_45DAB4= (float) 1.0 / (double)FSOUND_MixRate_456A40;
    v1 = (FSOUND_LATENCY * FSOUND_MixRate_456A40 / 1000 + 3) & 0xFFFFFFFC;
    FSOUND_BlockSize_45DA68= (FSOUND_LATENCY * FSOUND_MixRate_456A40/ 1000 + 3) & 0xFFFFFFFC;
    FSOUND_BufferSize_45C4C4 = 2 * v1 * (FSOUND_BufferSizeMs_456A44/ FSOUND_LATENCY);
    mix_volumerampsteps_456C94 = (FSOUND_MixRate_456A40 << 7) / 44100;
    mix_1overvolumerampsteps_456C98 = 1.0 / (double)((FSOUND_MixRate_456A40<< 7) / 44100);
    v2 = 2 * v1 * (FSOUND_BufferSizeMs_456A44 / FSOUND_LATENCY) / v1;
    memset(FSOUND_Channel, 0, 0x5800u);
    v3 = 0;
    //v4 = (signed int)&unk_456CF4;
    do
    {
		FSOUND_Channel[v3].index = v3;
		FSOUND_Channel[v3].speedhi  = 1;
      //*(_DWORD *)(v4 - 52) = v3;
      ///*(_DWORD *)v4 = 1;
      //v4 += 88;
      ++v3;
    }
    //while ( v4 < (signed int)&unk_45C4F4 );//5800h /88=256
	 while ( v3 < 256 );//5800h /88=256
   // v5 = *(_WORD *)(mod_456C24 + 38);
   // v6 = *(BYTE *)(mod_456C24 + 296);
   
	 
	 
	mod_456C24->globalvolume  =  mod_456C24->defaultglobalvolume;// *(_DWORD *)(mod_456C24 + 312) = *(_WORD mod_456C24a1 + 36);
	mod_456C24->speed  =(int) mod_456C24->defaultspeed;// *(_DWORD *)(mod_456C24 + 300) = v6;
	
	mod_456C24->row = 0;//    *(_DWORD *)(mod_456C24 + 320) = 0;
    mod_456C24->order = 0;// *(_DWORD *)(mod_456C24 + 324) = 0;
    mod_456C24->nextorder = -1;// *(_DWORD *)(mod_456C24 + 336) = -1;
    mod_456C24->nextrow = -1;// *(_DWORD *)(mod_456C24 + 332) = -1;
    mod_456C24->mixer_samplesleft = 0;// *(_DWORD *)(mod_456C24 + 8) = 0;
    mod_456C24->tick = 0;// *(_DWORD *)(mod_456C24 + 308) = 0;
    mod_456C24->patterndelay  = 0;// *(_DWORD *)(mod_456C24 + 328) = 0;
    mod_456C24->time_ms = 0;// *(_DWORD *)(mod_456C24 + 340) = 0;
    FMUSIC_SetBPM_43D8A0(mod_456C24, mod_456C24->defaultbpm);
    memset(FMUSIC_Channel, 0, 172 * mod_456C24->numchannels);
    v7 = 0;
    if (  mod_456C24->numchannels > 0 )
    {
      v8 = (int)0;
      //v9 = &FSOUND_Channel;
      do
      {
		cptr = &FMUSIC_Channel[v7];
		cptr->cptr = &FSOUND_Channel[v7];
        //*(_DWORD *)v8 = v9;
        ++v7;
        ///v9 = (char *)v9 + 88;
        v8 += 1;
      }
      while ( v7 < mod_456C24->numchannels );
    }
    FMUSIC_PlayingSong_456C30 = mod_456C24;
    FMUSIC_TimeInfo_45DAB0 = calloc(6 * v2, 1u);
    v10 = calloc(8 * FSOUND_BufferSize_45C4C4 + 256, 1u);//FSOUND_MixBufferMem = (signed char *)FSOUND_Memory_Calloc((FSOUND_BufferSize << 3) + 256);
    FSOUND_MixBufferMem_45DA64 = v10;
    FSOUND_MixBuffer_45DA60 = (unsigned int)((char *)v10 + 15) & 0xFFFFFFF0; //FSOUND_MixBuffer = (signed char *)(((unsigned int)FSOUND_MixBufferMem + 15) & 0xFFFFFFF0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


//----- (0043DC50) --------------------------------------------------------
int __cdecl FMUSIC_LoadSong_43DC50(int size,  char *data, SAMPLELOADCALLBACK sampleloadcallback)
{
  FMUSIC_MODULE		*mod;
  signed char			retcode=FALSE;
  FSOUND_FILE_HANDLE	*fp;

  int effectStruct; // edi@1
  int v3; // eax@1
  void *v4; // esi@1
  char v5; // bl@2

  mod = FSOUND_Memory_Calloc(sizeof(FMUSIC_MODULE));
   
	fp = FSOUND_File_Open_43F720(size,data, 0, 0);
	//TODO fix 
	
	if (!fp)
	{
		return NULL;
	}

	mod->Update = NULL;

	// try opening all as all formats until correct loader is found
	retcode = FMUSIC_LoadXM_43EF60(mod, fp);


	FSOUND_File_Close_43F770(fp);

	/*comentadpif (!retcode)
	{
		FMUSIC_FreeSong_43D940(mod);
		return NULL;
	}*/


	return mod;

}

//----- (0043DCB0) --------------------------------------------------------

int __cdecl  FSOUND_Software_Fill_43DCB0(signed int a1, int a2)
{
	int mi_FSOUND_BlockSize= a1;
	void  *	mixbuffer; 
	int		mixpos		= FSOUND_Software_FillBlock_456C3C * mi_FSOUND_BlockSize;
	int		totalblocks = FSOUND_BufferSize_45C4C4 / mi_FSOUND_BlockSize; 


	mixbuffer = (char *)FSOUND_MixBuffer_45DA60 + (mixpos << 3);

	//==============================================================================
	// MIXBUFFER CLEAR
	//==============================================================================

	memset(mixbuffer, 0, mi_FSOUND_BlockSize << 3);

	//==============================================================================
	// UPDATE MUSIC
	//==============================================================================

	{
		int MixedSoFar = 0;
		int MixedLeft = FMUSIC_PlayingSong_456C30->mixer_samplesleft;
		int SamplesToMix;
		signed char *MixPtr;

		// keep resetting the mix pointer to the beginning of this portion of the ring buffer
		MixPtr = mixbuffer;

		while (MixedSoFar < mi_FSOUND_BlockSize)
		{
			if (!MixedLeft)
			{
				FMUSIC_PlayingSong_456C30->Update(FMUSIC_PlayingSong_456C30);		// update new mod tick
				SamplesToMix = FMUSIC_PlayingSong_456C30->mixer_samplespertick;
				MixedLeft = SamplesToMix;
			}
			else 
            {
                SamplesToMix = MixedLeft;
            }

			if (MixedSoFar + SamplesToMix > mi_FSOUND_BlockSize) 
            {
				SamplesToMix = mi_FSOUND_BlockSize - MixedSoFar;
            }
			
			FSOUND_Mixer_FPU_Ramp_43DEA0(MixPtr, SamplesToMix); 

			MixedSoFar	+= SamplesToMix;
			MixPtr		+= (SamplesToMix << 3);
			MixedLeft	-= SamplesToMix;

			FMUSIC_PlayingSong_456C30->time_ms += (int)(((float)SamplesToMix * FSOUND_OOMixRate_45DAB4) * 1000);
		}

		FMUSIC_TimeInfo_45DAB0[FSOUND_Software_FillBlock_456C3C].ms    = FMUSIC_PlayingSong_456C30->time_ms;
		FMUSIC_TimeInfo_45DAB0[FSOUND_Software_FillBlock_456C3C].row   = FMUSIC_PlayingSong_456C30->row;
		FMUSIC_TimeInfo_45DAB0[FSOUND_Software_FillBlock_456C3C].order = FMUSIC_PlayingSong_456C30->order;
		
		FMUSIC_PlayingSong_456C30->mixer_samplesleft = MixedLeft;
	}


	// ====================================================================================
	// CLIP AND COPY BLOCK TO OUTPUT BUFFER
	// ====================================================================================
	{
		void  			*ptr1, *ptr2; 
		unsigned int	len1, len2;

		ptr1 = FSOUND_MixBlock.data + (mixpos << 2);
		ptr2 = NULL;
		len1 = mi_FSOUND_BlockSize << 2;
		len2 = 0;

		FSOUND_MixerClipCopy_Float32_43DE30(a2, mixbuffer, mi_FSOUND_BlockSize & 0x3FFFFFFF);//len1>>2); 
	}

	FSOUND_Software_FillBlock_456C3C++;

	if (FSOUND_Software_FillBlock_456C3C >= totalblocks)
    {
		FSOUND_Software_FillBlock_456C3C = 0;
    }
}

//----- (0043DE30) --------------------------------------------------------
int __cdecl FSOUND_MixerClipCopy_Float32_43DE30(void *dest, void *src, long len)
{
	int count;
	short *destptr = (short *)dest;
	float *srcptr = (float *)src;

	if (len <=0 || !dest || !src) 
		return;

	for (count=0; count<len<<1; count++)
	{
		int val;
		__asm
		{
			mov eax, srcptr
			fld [eax]
			add srcptr, 4
			fistp val
		}
		*destptr++ = (val < -32768 ? -32768 : val > 32767 ? 32767 : val);
	}
		
}

//----- (0043DEA0) --------------------------------------------------------
int __cdecl  FSOUND_Mixer_FPU_Ramp_43DEA0(void *mixptr, int len) 
{
	static FSOUND_CHANNEL *cptr;
	static int count;
	// IMPORTANT no local variables on stack.. we are trashing EBP.  static puts values on heap.

	if (len <=0) 
		return;

	mix_numsamples	= len;
	mix_mixptr		= (unsigned int)mixptr;
	mix_mixbuffend	= (unsigned int)mix_mixptr + (mix_numsamples << 3);


	//==============================================================================================
	// LOOP THROUGH CHANNELS
	//==============================================================================================
	for (count=0; count<64; count++)
	{
		cptr = &FSOUND_Channel[count];
		
		__asm 
		{
		push	ebp
		mov		ebx, mix_mixptr
		mov		mix_mixbuffptr, ebx

		mov		ecx, cptr
		mov		mix_cptr, ecx

		cmp		ecx, 0						// if (!cptr) ...
		je		MixExit						//			  ... then skip this channel!

		mov		ebx, [ecx]FSOUND_CHANNEL.sptr				// load the correct SAMPLE  pointer for this channel
		mov		mix_sptr, ebx				// store sample pointer away
		cmp		ebx, 0						// if (!sptr) ...
		je		MixExit						//			  ... then skip this channel!

		// get pointer to sample buffer
		mov		eax, [ebx].buff
		mov		mix_samplebuff, eax

		//==============================================================================================
		// LOOP THROUGH CHANNELS
		// through setup code:- usually ebx = sample pointer, ecx = channel pointer
		//==============================================================================================

		//= SUCCESS - SETUP CODE FOR THIS CHANNEL ======================================================

		// =========================================================================================
		// the following code sets up a mix counter. it sees what will happen first, will the output buffer
		// end be reached first? or will the end of the sample be reached first? whatever is smallest will
		// be the mixcount.

		// first base mixcount on size of OUTPUT BUFFER (in samples not bytes)
		mov		eax, mix_numsamples

	CalculateLoopCount:
		mov		mix_count, eax
		mov		esi, [ecx].mixpos
		mov		ebp, FSOUND_OUTPUTBUFF_END	
		mov		mix_endflag, ebp			// set a flag to say mixing will end when end of output buffer is reached

		cmp		[ecx].speeddir, FSOUND_MIXDIR_FORWARDS
		jne		samplesleftbackwards

		// work out how many samples left from mixpos to loop end	
		mov		edx, [ebx].loopstart
		add		edx, [ebx].looplen
        cmp     esi, edx
        jle     subtractmixpos
        mov     edx, [ebx+FSOUND_SAMPLE.length]
    subtractmixpos:
		sub		edx, esi					// eax = samples left (loopstart+looplen-mixpos)
		mov		eax, [ecx].mixposlo
		xor		ebp, ebp
		sub		ebp, eax
		sbb		edx, 0
		mov		eax, ebp
		jmp		samplesleftfinish

	samplesleftbackwards:
		// work out how many samples left from mixpos to loop start
		mov		edx, [ecx].mixpos
		mov		eax, [ecx].mixposlo

		sub		eax, 0h
		sbb		edx, [ebx].loopstart

	samplesleftfinish:          

		// edx:eax now contains number of samples left to mix
		cmp		edx, 1000000h
		jae		staywithoutputbuffend

		shrd	eax, edx, 8
		shr		edx, 8
		
		// now samples left = EDX:EAX -> hhhhhlll
		mov		ebp, [ecx].speedhi
		mov		edi, [ecx].speedlo

        // do a paranoid divide by 0 check
        test    ebp, ebp
        jnz     speedvalid
        test    edi, edi
        jnz     speedvalid
        mov     edi, 017C6F8Ch              ; 100hz
    speedvalid:

		shl		ebp, 24
		shr		edi, 8
		and		edi, 000FFFFFFh
		or		ebp, edi
		div		ebp

		or		edx,edx						// if fractional 16-bit part is zero we must add an extra carry number 
		jz		dontaddbyte					//  to the resultant in EDX:EAX.
		inc		eax
	dontaddbyte:							// we must remove the fractional part of the multiply by shifting EDX:EAX
		cmp		eax, mix_count
		ja		staywithoutputbuffend
		mov		mix_count, eax
		mov		edx, FSOUND_SAMPLEBUFF_END	// set a flag to say mix will end when end of output buffer is reached
		mov		mix_endflag, edx
	staywithoutputbuffend:

		mov		ebx, mix_sptr
		mov		ecx, mix_cptr

		//= VOLUME RAMP SETUP =========================================================
		// Reasons to ramp
		// 1. volume change
		// 2. sample starts (just treat as volume change - 0 to volume)
		// 3. sample ends (ramp last n number of samples from volume to 0)

		// now if the volume has changed, make end condition equal a volume ramp
		mov		mix_rampspeedleft, 0		// clear out volume ramp
		mov		mix_rampspeedright, 0		// clear out volume ramp

		mov		eax, mix_count
		mov		mix_count_old, eax			// remember mix count before modifying it	
		
		mov		mix_rampcount, 0
		cmp		[ecx].ramp_count, 0
		je		volumerampstart

		// if it tries to continue an old ramp, but the target has changed, 
		// set up a new ramp
		mov		eax, [ecx].leftvolume
		mov		edx, [ecx].ramp_lefttarget
		cmp		eax,edx
		jne		volumerampstart
		mov		eax, [ecx].rightvolume
		mov		edx, [ecx].ramp_righttarget
		cmp		eax,edx
		jne		volumerampstart

		// restore old ramp
		mov		eax, [ecx].ramp_count
		mov		mix_rampcount, eax
		mov		eax, [ecx].ramp_leftspeed
		mov		mix_rampspeedleft, eax
		mov		eax, [ecx].ramp_rightspeed
		mov		mix_rampspeedright, eax

		jmp		novolumerampR

	volumerampstart:
		mov		eax, [ecx].leftvolume
		mov		edx, [ecx].ramp_leftvolume 
		shr		edx, 8
		mov		[ecx].ramp_lefttarget, eax
		sub		eax, edx
		cmp		eax, 0
		je		novolumerampL

		mov		mix_temp1, eax
		fild	mix_temp1
		fmul	mix_1over255 
		fmul	mix_1overvolumerampsteps_456C98
		fstp	mix_rampspeedleft
		mov		eax, mix_rampspeedleft
		mov		[ecx].ramp_leftspeed, eax
		mov		eax, mix_volumerampsteps_456C94
		mov		mix_rampcount, eax


	novolumerampL:
		mov		eax, [ecx].rightvolume
		mov		edx, [ecx].ramp_rightvolume 
		shr		edx, 8
		mov		[ecx].ramp_righttarget, eax
		sub		eax, edx
		cmp		eax, 0
		je		novolumerampR

		mov		mix_temp1, eax
		fild	mix_temp1
		fmul	mix_1over255 
		fmul	mix_1overvolumerampsteps_456C98
		fstp	mix_rampspeedright
		mov		eax, mix_rampspeedright
		mov		[ecx].ramp_rightspeed, eax
		mov		eax, mix_volumerampsteps_456C94
		mov		mix_rampcount, eax


	novolumerampR:
		mov		eax, mix_rampcount
		cmp		eax, 0
		jle		volumerampend

		mov		[ecx].ramp_count, eax
		cmp		mix_count, eax
		jbe		volumerampend	// dont clamp mixcount 
		mov		mix_count, eax
	volumerampend:
	

		//= SET UP VOLUME MULTIPLIERS ==================================================

		// set up left/right volumes
		mov		ecx, mix_cptr

		// right volume
		mov		eax, [ecx].rightvolume
		mov		mix_temp1, eax
		fild	mix_temp1
		fmul	mix_1over255 
		fstp	mix_rightvol

		// left volume
		mov		eax, [ecx].leftvolume
		mov		mix_temp1, eax
		fild	mix_temp1
		fmul	mix_1over255 
		fstp	mix_leftvol

		// right ramp volume
		mov		eax, [ecx].ramp_rightvolume
		mov		mix_temp1, eax
		fild	mix_temp1
		fmul	mix_1over256			// first convert from 24:8 to 0-255
		fmul	mix_1over255			// now make 0-1.0f
		fstp	mix_ramprightvol

		// left ramp volume
		mov		eax, [ecx].ramp_leftvolume
		mov		mix_temp1, eax
		fild	mix_temp1
		fmul	mix_1over256			// first convert from 24:8 to 0-255
		fmul	mix_1over255			// now make 0-1.0f
		fstp	mix_rampleftvol


		//= SET UP ALL OF THE REGISTERS HERE FOR THE INNER LOOP ====================================
		// eax = ---
		// ebx = speed low
		// ecx = speed high
		// edx = counter
		// esi = mixpos
		// edi = destination pointer
		// ebp = mixpos low

		mov		eax, mix_cptr
		mov		ebx, [eax].speedlo
		mov		ecx, [eax].speedhi
	//  mov		edx, mix_count
		mov		ebp, [eax].mixposlo
		mov		esi, [eax].mixpos
		mov		edi, mix_mixbuffptr		// point edi to 16bit output stream

		cmp		[eax].speeddir, FSOUND_MIXDIR_FORWARDS
		je		NoChangeSpeed
		xor		ebx, 0FFFFFFFFh
		xor		ecx, 0FFFFFFFFh
		add		ebx, 1
		adc		ecx, 0
	NoChangeSpeed:


		//======================================================================================
		// ** 16 BIT NORMAL FUNCTIONS **********************************************************
		//======================================================================================

		mov		eax, mix_samplebuff
		shr		eax, 1
		add		esi, eax

		mov		edx, mix_count

		cmp		mix_rampcount, 0
		jne		MixLoopStart16_2

/*#ifdef ROLLED*/
//		jmp		MixLoopStart16
/*#endif*/
		shr		edx, 1
		or		edx, edx
		jz		MixLoopStart16				// no groups of 2 samples to mix!

// START

		shr		ebp, 1					// 1 make 31bit coz fpu only loads signed values
		add		edi, 16					// 
		fild	word ptr [esi+esi+2]	// 1 [0]samp1+1
		mov		mix_temp1, ebp			// 1
//		nop
		fild	word ptr [esi+esi]		// 1 [0]samp1 [1]samp1+1
		fild	dword ptr mix_temp1		// 1 [0]ifrac1 [1]samp1 [2]samp1+1
		add		ebp, ebp				// 1 
//		nop
		add		ebp, ebx				// 1
		adc		esi, ecx				// 1 
		fmul	mix_1over2gig			// 1 [0]ffrac1 [1]samp1 [2]samp1+1
		fild	word ptr [esi+esi+2]	// 1 [0]samp2+1 [1]ffrac1 [2]samp1 [3]samp1+1
		shr		ebp, 1					// 1
//		nop
		mov		mix_temp1, ebp			// 1
//		nop
		fild	dword ptr mix_temp1		// 1 [0]ifrac2 [1]samp2+1 [2]ffrac1 [3]samp1 [4]samp1+1
		fild	word ptr [esi+esi]		// 1 [0]samp2 [1]ifrac2 [2]samp2+1 [3]ffrac1 [4]samp1 [5]samp1+1
		fxch	st(5)					//   [0]samp1+1 [1]ifrac2 [2]samp2+1 [3]ffrac1 [4]samp1 [5]samp2
		fsub	st(0), st(4)			// 1 [0]delta1 [1]ifrac2 [2]samp2+1 [3]ffrac1 [4]samp1 [5]samp2
//		fnop							// 1 fsub stall
		shl		ebp, 1					// 1 
//		nop
		fmulp	st(3), st(0)			// 1 [0]ifrac2 [1]samp2+1 [2]interp1 [3]samp1 [4]samp2
		fmul	mix_1over2gig			// 1 [0]ffrac2 [1]samp2+1 [2]interp1 [3]samp1 [4]samp2
		fxch	st(1)					//   [0]samp2+1 [1]ffrac2 [2]interp1 [3]samp1 [4]samp2
		fsub	st(0), st(4)			// 1 [0]delta2 [1]ffrac2 [2]interp1 [3]samp1 [4]samp2
		add		ebp, ebx				// 1 
//		nop
		adc		esi, ecx				// 1 
//		nop									 
		fmulp	st(1), st(0)			// 1 [0]interp2 [1]interp1 [2]samp1 [3]samp2
		fxch	st(1)					//   [0]interp1 [1]interp2 [2]samp1 [3]samp2
		faddp	st(2), st(0)			// 1 [0]interp2 [1]newsamp1 [2]samp2
//		fnop							// 1 fadd stall
//		fnop							// 1 fadd stall
		fld		st(1)					// 1 [0]newsamp1 [1]interp2 [2]newsamp1 [3]samp2
		fmul	mix_leftvol				// 1 [0]newsampL1 [1]interp2 [2]newsamp1 [3]samp2
		fxch	st(1)					//   [0]interp2 [1]newsampL1 [2]newsamp1 [3]samp2
		faddp	st(3), st(0)			// 1 [0]newsampL1 [1]newsamp1 [2]newsamp2
		fxch	st(1)					// 1 [0]newsamp1 [1]newsampL1 [2]newsamp2
		jmp		MixLoopUnroll16CoilEntry// 1

		ALIGN 16

	MixLoopUnroll16:
		shr		ebp, 1					// 1 
//		nop
		mov		mix_temp1, ebp			// 1
//		nop
		fild	word ptr [esi+esi+2]	// 1 [0]samp1+1 [1]finalR2 [2]finalR1 [3]finalL2
		fild	word ptr [esi+esi]		// 1 [0]samp1 [1]samp1+1 [2]finalR2 [3]finalR1 [4]finalL2
		fild	dword ptr mix_temp1		// 1 [0]ifrac1 [1]samp1 [2]samp1+1 [3]finalR2 [4]finalR1 [5]finalL2
		add		ebp, ebp				// 1 
//		nop
		add		ebp, ebx				// 1
//		nop
		adc		esi, ecx				// 1 
		add		edi, 16					// 
		fmul	mix_1over2gig			// 1 [0]ffrac1 [1]samp1 [2]samp1+1 [3]finalR2 [4]finalR1 [5]finalL2
		shr		ebp, 1					// 1
//		nop
		mov		mix_temp1, ebp			// 1
//		nop
		fild	dword ptr mix_temp1		// 1 [0]ifrac2 [1]ffrac1 [2]samp1 [3]samp1+1 [4]finalR2 [5]finalR1 [6]finalL2
		fild	word ptr [esi+esi+2]	// 1 [0]samp2+1 [1]ifrac2 [2]ffrac1 [3]samp1 [4]samp1+1 [5]finalR2 [6]finalR1 [7]finalL2
		fxch	st(4)					//   [0]samp1+1 [1]ifrac2 [2]ffrac1 [3]samp1 [4]samp2+1 [5]finalR2 [6]finalR1 [7]finalL2
		fsub	st(0), st(3)			// 1 [0]delta1 [1]ifrac2 [2]ffrac1 [3]samp1 [4]samp2+1 [5]finalR2 [6]finalR1 [7]finalL2
//		fnop							// 1 fsub stall
		shl		ebp, 1					// 1 
//		nop
		fmulp	st(2), st(0)			// 1 [0]ifrac2 [1]interp1 [2]samp1 [3]samp2+1 [4]finalR2 [5]finalR1 [6]finalL2
		fild	word ptr [esi+esi]		// 1 [0]samp2 [1]ifrac2 [2]interp1 [3]samp1 [4]samp2+1 [5]finalR2 [6]finalR1 [7]finalL2
		fxch	st(1)					//   [0]ifrac2 [1]samp2 [2]interp1 [3]samp1 [4]samp2+1 [5]finalR2 [6]finalR1 [7]finalL2
		fmul	mix_1over2gig			// 1 [0]ffrac2 [1]samp2 [2]interp1 [3]samp1 [4]samp2+1 [5]finalR2 [6]finalR1 [7]finalL2
		fxch	st(4)					//   [0]samp2+1 [1]samp2 [2]interp1 [3]samp1 [4]ffrac2 [5]finalR2 [6]finalR1 [7]finalL2
		fsub	st(0), st(1)			// 1 [0]delta2 [1]samp2 [2]interp1 [3]samp1 [4]ffrac2 [5]finalR2 [6]finalR1 [7]finalL2
		add		ebp, ebx				// 1 
//		nop
		adc		esi, ecx				// 1 
//		nop                                  
		fmulp	st(4), st(0)			// 1 [0]samp2 [1]interp1 [2]samp1 [3]interp2 [4]finalR2 [5]finalR1 [6]finalL2
		fxch	st(2)					//   [0]samp1 [1]interp1 [2]samp2 [3]interp2 [4]finalR2 [5]finalR1 [6]finalL2
		faddp	st(1), st(0)			// 1 [0]newsamp1 [1]samp2 [2]interp2 [3]finalR2 [4]finalR1 [5]finalL2
		fxch	st(4)					//	 [0]finalR1 [1]samp2 [2]interp2 [3]finalR2 [4]newsamp1 [5]finalL2
		fstp	dword ptr [edi-28]		// 2 [0]samp2 [1]interp2 [2]finalR2 [3]newsamp1 [4]finalL2
		fxch	st(4)					// 1 [0]finalL2 [1]interp2 [2]finalR2 [3]newsamp1 [4]samp2
		fstp	dword ptr [edi-24]		// 2 [0]interp2 [1]finalR2 [2]newsamp1 [3]samp2
		fld		st(2)					// 1 [0]newsamp1 [1]interp2 [2]finalR2 [3]newsamp1 [4]samp2
		fmul	mix_leftvol				// 1 [0]newsampL1 [1]interp2 [2]finalR2 [3]newsamp1 [4]samp2
		fxch	st(1)					//   [0]interp2 [1]newsampL1 [2]finalR2 [3]newsamp1 [4]samp2
		faddp	st(4), st(0)			// 1 [0]newsampL1 [1]finalR2 [2]newsamp1 [3]newsamp2
		fxch	st(1)					//   [0]finalR2 [1]newsampL1 [2]newsamp1 [3]newsamp2
		fstp	dword ptr [edi-20]		// 2 [0]newsampL1 [1]newsamp1 [2]newsamp2
		fxch	st(1)					// 1 [0]newsamp1 [1]newsampL1 [2]newsamp2 
										
	MixLoopUnroll16CoilEntry:			//   [0]newsamp1 [1]newsampL1 [2]newsamp2

		fmul	mix_rightvol			// 1 [0]newsampR1 [1]newsampL1 [2]newsamp2
		fxch	st(2)					//   [0]newsamp2 [1]newsampL1 [2]newsampR1
		fld		st(0)					// 1 [0]newsamp2 [1]newsamp2 [2]newsampL1 [3]newsampR1
		fmul	mix_leftvol				// 1 [0]newsampL2 [1]newsamp2 [2]newsampL1 [3]newsampR1
		fxch	st(1)					//   [0]newsamp2 [1]newsampL2 [2]newsampL1 [3]newsampR1
//		fnop							// 1 delay on mul unit
		fmul	mix_rightvol			// 1 [0]newsampR2 [1]newsampL2 [2]newsampL1 [3]newsampR1
		fxch	st(2)					//   [0]newsampL1 [1]newsampL2 [2]newsampR2 [3]newsampR1
		fadd	dword ptr [edi-16]		// 1 [0]finalL1 [1]newsampL2 [2]newsampR2 [3]newsampR1
		fxch	st(3)					//   [0]newsampR1 [1]newsampL2 [2]newsampR2 [3]finalL1
		fadd	dword ptr [edi-12]		// 1 [0]finalR1 [1]newsampL2 [2]newsampR2 [3]finalL1
		fxch	st(1)					//   [0]newsampL2 [1]finalR1 [2]newsampR2 [3]finalL1
		fadd	dword ptr [edi-8]		// 1 [0]finalL2 [1]finalR1 [2]newsampR2 [3]finalL1
		fxch	st(3)					//   [0]finalL1 [1]finalR1 [2]newsampR2 [3]finalL2
//		fnop							// 1 delay on store?
		fstp	dword ptr [edi-16]		// 2 [0]finalR1 [1]newsampR2 [2]finalL2
		fxch	st(1)					// 1 [0]newsampR2 [1]finalR1 [2]finalL2
		fadd	dword ptr [edi-4]		// 1 [0]finalR2 [1]finalR1 [2]finalL2

		dec		edx						// 1
		jnz		MixLoopUnroll16			// 

		fxch	st(1)					// 1 [0]finalR1 [1]finalR2 [2]finalL2
		fstp	dword ptr [edi-12]		// 2 [0]finalR2 [1]finalL2
		fxch	st(1)					// 1 [0]finalL2 [1]finalR2
		fstp	dword ptr [edi-8]		// 2 [0]finalR2
		fstp	dword ptr [edi-4]		// 2 

		//= MIX 16BIT, ROLLED ==================================================================
MixLoopStart16:
		mov		edx, mix_count
//#ifndef ROLLED
		and		edx, 1
//#endif
		
 	MixLoopStart16_2:
		or		edx, edx					// if count == 0 dont enter the mix loop
		jz		MixLoopEnd16

    	fld		mix_rampspeedleft		// [0]rampspeedL
		fld		mix_rampspeedright		// [0]rampspeedR [1]rampspeedL
		fld		mix_rampleftvol			// [0]lvol [1]rampspeedR [2]rampspeedL
		fld		mix_ramprightvol		// [0]rvol [1]lvol [2]rampspeedR [3]rampspeedL
		
		/*#else-
		fldz						// [0]rampspeedL
		fldz						// [0]rampspeedR [1]rampspeedL
		fld		mix_leftvol			// [0]lvol [1]rampspeedR [2]rampspeedL
		fld		mix_rightvol		// [0]rvol [1]lvol [2]rampspeedR [3]rampspeedL
#endif*/
		jmp		MixLoop16

		ALIGN 16

	MixLoop16:
		shr		ebp, 1					// 1 make 31bit coz fpu only loads signed values
		add		edi, 8					// 
		fild	word ptr [esi+esi+2]	// 1 [0]samp1+1 [1]rvol [2]lvol [3]rampspeedR [4]rampspeedL
		mov		mix_temp1, ebp			// 1
		fild	word ptr [esi+esi]		// 1 [0]samp1 [2]samp1+1 [3]rvol [4]lvol [5]rampspeedR [6]rampspeedL
		fild	dword ptr mix_temp1		// 1 [0]ifrac [1]samp1 [2]samp1+1 [3]rvol [4]lvol [5]rampspeedR [6]rampspeedL
		shl		ebp, 1					// 1 restore mixpos low
		add		ebp, ebx				//   add speed low to mixpos low
		adc		esi, ecx				// 1 add upper portion of speed plus carry	
		nop
		fmul	mix_1over2gig			// 1 [0]ifrac [1]samp1 [2]samp1+1 [3]rvol [4]lvol [5]rampspeedR [6]rampspeedL
		fxch	st(2)					//   [0]samp1+1 [1]samp1 [2]ffrac [3]rvol [4]lvol [5]rampspeedR [6]rampspeedL
		fsub	st(0), st(1)			// 1 [0]delta1 [1]samp1 [2]ffrac [3]rvol [4]lvol [5]rampspeedR [6]rampspeedL
		fnop							// 1
		fnop							// 1
		fnop							// 1
		fmulp	st(2), st(0)			// 1 [0]sample [1]interp [2]rvol [3]lvol [4]rampspeedR [5]rampspeedL
		fnop							// 1
		fnop							// 1
		fnop							// 1
		fnop							// 1
		faddp	st(1), st(0)			// 1 [0]newsamp [1]rvol [2]lvol [3]rampspeedR [4]rampspeedL
		fnop							// 1
		fnop							// 1
		fld		st(0)					// 1 [0]newsamp [1]newsamp [2]rvol [3]lvol [4]rampspeedR [5]rampspeedL
		fmul	st(0), st(3)			// 1 [0]newsampL [1]newsamp [2]rvol [3]lvol [4]rampspeedR [5]rampspeedL
		fxch	st(3)					//   [0]lvol [1]newsamp [2]rvol [3]newsampL [4]rampspeedR [5]rampspeedL
		fadd	st(0), st(5)			// 1 [0]lvol [1]newsamp [2]rvol [3]newsampL [4]rampspeedR [5]rampspeedL
		fxch	st(1)					//   [0]newsamp [1]lvol [2]rvol [3]newsampL [4]rampspeedR [5]rampspeedL
		fmul	st(0), st(2)			// 1 [0]newsampR [1]lvol [2]rvol [3]newsampL [4]rampspeedR [5]rampspeedL
		fxch	st(2)					//   [0]rvol [1]lvol [2]newsampR [3]newsampL [4]rampspeedR [5]rampspeedL
		fadd	st(0), st(4)			// 1 [0]rvol [1]lvol [2]newsampR [3]newsampL [4]rampspeedR [5]rampspeedL
		fxch	st(3)					//   [0]newsampL [1]lvol [2]newsampR [3]rvol [4]rampspeedR [5]rampspeedL
		fnop							// 1
		fnop							// 1
		fadd	dword ptr [edi-8]		// 1 [0]finalL [1]lvol [2]newsampR [3]rvol [4]rampspeedR [5]rampspeedL
		fxch	st(2)					//   [0]newsampR [1]lvol [2]finalL [3]rvol [4]rampspeedR [5]rampspeedL
		fadd	dword ptr [edi-4]		// 1 [0]finalR [1]lvol [2]finalL [3]rvol [4]rampspeedR [5]rampspeedL
		fxch	st(2)					//   [0]finalL [1]lvol [2]finalR [3]rvol [4]rampspeedR [5]rampspeedL
		fnop							// 1
		fstp	dword ptr [edi-8]		// 1 [0]lvol [1]finalR [2]rvol [3]rampspeedR [4]rampspeedL
		fxch	st(1)					//   [0]finalR [1]lvol [2]rvol [3]rampspeedR [4]rampspeedL
		fstp	dword ptr [edi-4]		// 3 [0]lvol [1]rvol [2]rampspeedR [3]rampspeedL
		fxch	st(1)					//   [0]rvol [1]lvol [2]rampspeedR [3]rampspeedL

		dec		edx						// 1
		jnz		MixLoop16				// 



		fxch	st(2)					// [0]rampspeedR [1]lvol [2]rvol [3]rampspeedL
		fstp	mix_rampspeedright		// [0]lvol [1]rvol [2]rampspeedL
		fxch	st(2)					// [0]rampspeedL [1]rvol [2]lvol
		fstp	mix_rampspeedleft		// [0]rvol [1]lvol
		
		fmul	mix_255					// [0]rvol*255 [1]lvol
		fmul	mix_256					// [0]rvol*255*256 [1]lvol
		fxch	st(1)					// [0]lvol [1]rvol*255*256
		fmul	mix_255					// [0]lvol*255 [1]rvol*255*256
		fmul	mix_256					// [0]lvol*255*256 [1]rvol*255*256

		xor		eax, eax
		fistp	mix_rampleftvol			// [0]rvol*255*256
		fistp	mix_ramprightvol		// 

	MixLoopEnd16:
		mov		eax, mix_samplebuff
		shr		eax, 1
		sub		esi, eax

			//=============================================================================================
			// DID A VOLUME RAMP JUST HAPPEN
			//=============================================================================================
			cmp		mix_rampcount, 0
			je		DoOutputbuffEnd		// no, no ramp

			mov		ebx, mix_sptr		// load ebx with sample pointer
			mov		ecx, mix_cptr		// load ecx with channel pointer

			mov		eax, mix_rampleftvol
			mov		[ecx].ramp_leftvolume, eax
			mov		eax, mix_ramprightvol
			mov		[ecx].ramp_rightvolume, eax

			mov		eax, mix_count
			mov		edx, mix_rampcount

			sub		edx, eax
	
			mov		mix_rampspeedleft, 0		// clear out volume ramp
			mov		mix_rampspeedright, 0		// clear out volume ramp
			mov		mix_rampcount, edx
			mov		[ecx].ramp_count, edx
	
			// if rampcount now = 0, a ramp has FINISHED, so finish the rest of the mix
			cmp		edx, 0
			jne		DoOutputbuffEnd

			// clear out the ramp speeds
			mov		[ecx].ramp_leftspeed, 0
			mov		[ecx].ramp_rightspeed, 0

			// clamp the 2 volumes together in case the speed wasnt accurate enough!
			mov		edx, [ecx].leftvolume
			shl		edx, 8
			mov		[ecx].ramp_leftvolume, edx
			mov		edx, [ecx].rightvolume
			shl		edx, 8
			mov		[ecx].ramp_rightvolume, edx

			// is it 0 because ramp ended only? or both ended together??
			// if sample ended together with ramp.. problems .. loop isnt handled

			cmp		mix_count_old, eax		// ramp and output mode ended together
			je		DoOutputbuffEnd

			// start again and continue rest of mix
			mov		[ecx].mixpos, esi
			mov		[ecx].mixposlo, ebp
			
			mov		eax, mix_mixbuffend	// find out how many OUTPUT samples left to mix 
			sub		eax, edi
			shr		eax, 3				// eax now holds # of samples left, go recalculate mix_count!!!
			mov		mix_mixbuffptr, edi	// update the new mixbuffer pointer

			cmp		eax, 0				// dont start again if nothing left
			jne		CalculateLoopCount

		DoOutputbuffEnd:  


		 
			cmp		mix_endflag, FSOUND_OUTPUTBUFF_END
			je		FinishUpChannel

			//=============================================================================================
			// SWITCH ON LOOP MODE TYPE
			//=============================================================================================
			mov		ebx, mix_sptr				// load ebx with sample pointer
			mov		ecx, mix_cptr				// load ecx with sample pointer

			mov		dl,	[ebx].loopmode

			// check for normal loop
			test	dl, FSOUND_LOOP_NORMAL
			jz		CheckBidiLoop

			mov		eax, [ebx].loopstart
			add		eax, [ebx].looplen
		rewindsample:
			sub		esi, [ebx].looplen
			cmp		esi, eax
			jae		rewindsample

			mov		[ecx].mixpos, esi
			mov		[ecx].mixposlo, ebp
			mov		eax, mix_mixbuffend			// find out how many samples left to mix for the output buffer
			sub		eax, edi
			shr		eax, 3						// eax now holds # of samples left, go recalculate mix_count!!!
			mov		mix_mixbuffptr, edi			// update the new mixbuffer pointer

			cmp		eax, 0
			je		FinishUpChannel

			jmp		CalculateLoopCount

		CheckBidiLoop:
			test	dl, FSOUND_LOOP_BIDI
			jz		NoLoop
			cmp		[ecx].speeddir, FSOUND_MIXDIR_FORWARDS
			je		BidiForward

		BidiBackwards:
			mov		eax, [ebx].loopstart
			dec		eax
	//		mov		edx, 0ffffff00h
			mov		edx, 0ffffffffh
			sub		edx, ebp
			sbb		eax, esi			
				
			mov		esi, eax
			mov		ebp, edx					// esi:ebp = loopstart - mixpos
			mov		eax, [ebx].loopstart
			mov		edx, 0h
			add		ebp, edx
			adc		esi, eax					// esi:ebp += loopstart
				
			mov		[ecx].speeddir, FSOUND_MIXDIR_FORWARDS

			mov		eax, [ebx].loopstart
			add		eax, [ebx].looplen
			cmp		esi, eax
			jge		BidiForward

			jmp		BidiFinish
		BidiForward:
			mov		eax, [ebx].loopstart
			add		eax, [ebx].looplen
			mov		edx, 0h
			sub		edx, ebp
			sbb		eax, esi				
			mov		esi, eax
			mov		ebp, edx					// esi:ebp = loopstart+looplen - mixpos

			mov		eax, [ebx].loopstart
			add		eax, [ebx].looplen
			dec		eax
	//		mov		edx, 0ffffff00h
			mov		edx, 0ffffffffh
			add		ebp, edx
			adc		esi, eax

			mov		[ecx].speeddir, FSOUND_MIXDIR_BACKWARDS

			cmp		esi, [ebx].loopstart
			jl		BidiBackwards

		BidiFinish:

			mov		[ecx].mixpos, esi
			mov		[ecx].mixposlo, ebp

			mov		eax, mix_mixbuffend			// find out how many samples left to mix for the output buffer
			sub		eax, edi
			shr		eax, 3						// eax now holds # of samples left, go recalculate mix_count!!!
			mov		mix_mixbuffptr, edi			// update the new mixbuffer pointer

			cmp		eax, 0
			je		FinishUpChannel

			jmp		CalculateLoopCount

		NoLoop:
			xor		ebp, ebp
			xor		esi, esi
			mov		[ecx]FSOUND_CHANNEL.sptr, esi		// clear the sample pointer out

			//= LEAVE INNER LOOP
		FinishUpChannel:
			mov		ecx, [mix_cptr]

			mov		[ecx].mixposlo, ebp
			mov		[ecx].mixpos, esi			// reset mixpos based on esi for next time around

		//===================================================================================================
		// EXIT
		//===================================================================================================
		MixExit:
			pop		ebp						//= RESTORE EBP
		}
	}
} 


//----- (0043E550) --------------------------------------------------------
char __cdecl FMUSIC_XM_InstrumentVibrato_43E550(FMUSIC_CHANNEL *cptr, FMUSIC_INSTRUMENT *iptr)
{

  unsigned __int64 v2; // rax@2//delta
  char v3; // dl@7
  int v4; // ecx@7
  int v5; // edx@9
  int v6; // eax@9
  int v7; // ecx@9
  int v8; // eax@9
  int v9; // edi@11
  char result; // al@13
  int delta;
  int deltaTemp;//v4

  switch (iptr->VIBtype) //334
  {
    case 0:
      delta = (unsigned __int64)(sin((double)(cptr->ivibpos) * 0.024543688) * 64.0);
      break;
    case 1:
      delta = (unsigned __int8)(cptr->ivibpos >= 128 ? 0 : 0x80) - 64;
      break;
    case 2:
      delta = (128 - (cptr->ivibpos + 128) % 256) >> 1;
      break;
    case 3:
      delta = (128 - (384 - cptr->ivibpos) % 256) >> 1;
      break;
    default:
      delta = iptr;
      break;
  }

  //delta = iptr->VIBsweep;//335
  delta = delta * iptr->VIBdepth;//336
  if (iptr->VIBsweep )
    delta = delta *  cptr->ivibsweeppos /  iptr->VIBsweep;//a1 96
  delta >>=6;
  cptr->freqdelta += delta; //28
  cptr->ivibsweeppos++;//96
  
  
  
  if ( cptr->ivibsweeppos >  iptr->VIBsweep )
    cptr->ivibsweeppos =  iptr->VIBsweep;//96
  
  cptr->ivibpos=iptr->VIBrate + cptr->ivibpos;//337 92
  
  if ( cptr->ivibpos > 255 )
    cptr->ivibpos = cptr->ivibpos - 256;//92
  result =cptr->notectrl | FMUSIC_FREQ;//2
  cptr->notectrl  = result;//2
  return result;
  
}



//----- (0043E670) --------------------------------------------------------
char __cdecl FMUSIC_XM_ProcessEnvelope_43E670(FMUSIC_CHANNEL *cptr, int *pos, int *tick, unsigned char type, int numpoints, unsigned short *points, unsigned char loopend, unsigned char loopstart, unsigned char sustain, int *value, int *valfrac, signed char *envstopped, int *envdelta, unsigned char control)
//parece que es FMUSIC_XM_ProcessEnvelope
//void FMUSIC_XM_ProcessEnvelope_43E670(FMUSIC_CHANNEL *cptr, int *pos, int *tick, unsigned char type, int numpoints, unsigned short *points, unsigned char loopend, unsigned char loopstart, unsigned char sustain, int *value, int *valfrac, signed char *envstopped, int *envdelta, unsigned char control)
{							
		// Envelope
	if (*pos < numpoints) 
	{
		if (*tick == points[(*pos)<<1])	// if we are at the correct tick for the position
		{
			int currpos, nextpos;
			int currtick, nexttick;
			int curr, next, tickdiff;

			// handle loop
			if ((type & FMUSIC_ENVELOPE_LOOP) && *pos == loopend) 
			{
				*pos  = loopstart;
				*tick = points[(*pos) <<1];
			}

			currpos	= *pos;
			nextpos	= (*pos) + 1;
			currtick = points[currpos<<1];				// get tick at this point
			nexttick = points[nextpos<<1];				// get tick at next point
			curr = points[(currpos<<1)+1] << 16;	// get  at this point << 16
			next = points[(nextpos<<1)+1] << 16;	// get  at next point << 16

			// if it is at the last position, abort the envelope and continue last value
			if (*pos == numpoints - 1) 
			{
				*value = points[(currpos<<1)+1];
				*envstopped = TRUE;
				cptr->notectrl |= control;
				return;
			}
			// sustain
			if ((type & FMUSIC_ENVELOPE_SUSTAIN) && currpos == sustain && !cptr->keyoff)
			{
				*value = points[(currpos<<1)+1];
				cptr->notectrl |= control;
				return;
			}
			// interpolate 2 points to find delta step
			tickdiff = nexttick - currtick;
			if (tickdiff) 
				*envdelta = (next-curr) / tickdiff;
			else
				*envdelta = 0;

			*valfrac = curr;

			(*pos)++;
		}
		else
			*valfrac += *envdelta;				// interpolate
	}

	*value = *valfrac >> 16;
	(*tick)++;

	cptr->notectrl |= control;

}

//----- (0043E7A0) --------------------------------------------------------
char __cdecl FMUSIC_XM_ProcessVolumeByte_43E7A0(FMUSIC_CHANNEL *cptr, unsigned char volume)

{
  int v2; // eax@3
  int v3; // edx@5

	  if (volume >= 0x10 && volume <= 0x50) 
	{
		cptr->volume = volume-0x10;
		cptr->notectrl |= FMUSIC_VOLUME;
		
  
	}
  else
  {
	  v2=0;
    LOBYTE(v2) = volume;
    switch ( (unsigned int)volume >> 4 )
    {
      case 0x6 : 
		{
			cptr->volume -= (volume & 0xF);
			if (cptr->volume < 0) 
				cptr->volume = 0;
			cptr->notectrl |= FMUSIC_VOLUME;
			break;
		}
		case 0x7 : 
		{
			cptr->volume += (volume & 0xF);
			if (cptr->volume > 0x40) 
				cptr->volume = 0x40;
			cptr->notectrl |= FMUSIC_VOLUME;
			break;
		}
		case 0x8 :
		{
			cptr->volume -= (volume & 0xF);
			if (cptr->volume < 0) 
				cptr->volume = 0;
			cptr->notectrl |= FMUSIC_VOLUME;
			break;
		}
		case 0x9 :
		{
			cptr->volume += (volume & 0xF);
			if (cptr->volume > 0x40) 
				cptr->volume = 0x40;
			cptr->notectrl |= FMUSIC_VOLUME;
			break;
		}
		case 0xa :
		{
			cptr->vibspeed = (volume & 0xF);
			break;
		}
		case 0xb :
		{
			cptr->vibdepth = (volume & 0xF);
			break;
		}
		case 0xc :
		{
			cptr->pan = (volume & 0xF) << 4;
			cptr->notectrl |= FMUSIC_PAN;
			break;
		}
		case 0xd :
		{
			cptr->pan -= (volume & 0xF);
			cptr->notectrl |= FMUSIC_PAN;
			break;
		}
		case 0xe :
		{
			cptr->pan += (volume & 0xF);
			cptr->notectrl |= FMUSIC_PAN;
			break;
		}
		case 0xf :
		{
			if (volume & 0xF) 
				cptr->portaspeed = 16* volume;
			cptr->portatarget = cptr->period;
			cptr->notectrl &= ~FMUSIC_TRIGGER;
			break;
		}
    }
	return cptr;
  
  }
  //return v2;
}

//----- (0043E8C0) --------------------------------------------------------
int __cdecl FMUSIC_XM_UpdateFlags_43E8C0(FMUSIC_CHANNEL *cptr, FSOUND_SAMPLE *sptr, FMUSIC_MODULE *mod)

{
 // signed int v3; // ebx@1
 FSOUND_CHANNEL *ccptr = cptr->cptr;
  char *v4; // ebp@1
  
  signed int v5; // edx@2
  unsigned __int64 v6; // rax@4
  int v7; // edx@9
  char *v8; // eax@11
  int v9; // esi@16
  signed int v10; // ecx@17
  int v11; // esi@19
  int v12; // ecx@19
  int v13; // ecx@19
  signed int v14; // esi@24
  unsigned __int64 v15; // rax@26
  int v16; // ST0C_4@28
  int v17; // ebx@28
  unsigned int v18; // eax@28
  char *v20; // [sp+10h] [bp-8h]@1
  int channel;
  int freq;
  float finalvol;
  int volume;
int pan;
double temp;
  //v3 = cptr;
  
  /*v4 = ccptr->index;
  v20 = ccptr->index;
  if ( v4 )
    v5 = *(_DWORD *)v4;
  else
    v5 = a1;*/
  if (ccptr)
    channel = ccptr->index;
  
  LODWORD(v6) = (cptr->freqdelta) + (cptr->freq);
  if (!(cptr->freq + cptr->freqdelta)) 
    cptr->notectrl &= ~FMUSIC_FREQ;

  if (cptr->notectrl & FMUSIC_TRIGGER)	
  {
	  
	//==========================================================================================
		// ALLOCATE A CHANNEL
		//==========================================================================================  
	ccptr = &FSOUND_Channel[channel];
	
	
   // v4 = (char *)&FSOUND_Channel + 88 * v5;
    //v20 = (char *)&FSOUND_Channel + 88 * v5;
    if (ccptr->sptr != NULL)
    {
      if (channel < 32)
		channel += 32;
	  else
		channel -= 32;

      //v8 = (char *)&FSOUND_Channel + 88 * v7;
      //memcpy((char *)&FSOUND_Channel + 88 * v7, v4, 0x58u);
	  
	  memcpy(&FSOUND_Channel[channel], ccptr, sizeof(FSOUND_CHANNEL));
      FSOUND_Channel[channel].index = channel; // oops dont want its index
	  
	  // this should cause the old channel to ramp out nicely.
		ccptr->volume = ccptr->actualvolume = 0;
		ccptr->leftvolume  = 0;
		ccptr->rightvolume = 0;

		ccptr = &FSOUND_Channel[channel];
		cptr->cptr = ccptr;
    /*  *(_DWORD *)v8 = v7;
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 1) = 0;
      *((_DWORD *)v4 + 8) = 0;
      *((_DWORD *)v4 + 9) = 0;
      v4 = (char *)&FSOUND_Channel + 88 * v7;
      v20 = (char *)&FSOUND_Channel + 88 * v7;
      *(_DWORD *)(a1 + 4) = v8;*/
    }
    ccptr->sptr = sptr;//*((_DWORD *)v4 + 7) = a2;
	
	//==========================================================================================
		// START THE SOUND!
		//==========================================================================================
	
    if (ccptr->sampleoffset >= sptr->loopstart + sptr->looplen)
		ccptr->sampleoffset = 0;

	LODWORD(v6) = ccptr->sampleoffset;
	ccptr->mixpos    = ccptr->sampleoffset;
	ccptr->mixposlo  = 0;
	ccptr->speeddir  = FSOUND_MIXDIR_FORWARDS;
	ccptr->sampleoffset = 0;	// reset it (in case other samples come in and get corrupted etc)

	// volume ramping
	ccptr->ramp_leftvolume	= 0;
	ccptr->ramp_rightvolume	= 0;
	ccptr->ramp_count		= 0;
  }
  if (cptr->notectrl & FMUSIC_VOLUME)	
  {
	  
	  finalvol = (double)(signed int)64;				//  6 bits (   64)
	finalvol *= (double)(cptr->volume+cptr->voldelta);	//  6 bits (   64)
	finalvol *= (double)(signed int)cptr->fadeoutvol;				// 16 bits (65536)
	finalvol *= (double)(signed int)mod->globalvolume;	
	// Any half arsed compiler will convert this into 1 constant at compile time.
	finalvol *= (double)(255.0f / (64.0f * 64.0f * 65536.0f * 64.0f)) * 0.5f;
	volume = (int)finalvol>>5; ////BYGFIX-------------------------------------------------------------------------/20 sobra
/*    v6 = (unsigned __int64)((double)(*(_DWORD *)(a1 + 16) + *(_DWORD *)(a1 + 24))
                          * (double)*(signed int *)(a1 + 52)
                          * (double)*(signed int *)(a1 + 88)
                          * (double)*(signed int *)(a3 + 300)
                          * 0.0000000074214768);*/
    v6 = finalvol;
	if (ccptr)
	{
		
		ccptr->volume = ccptr->actualvolume = volume;
		//ccptr->leftvolume =20;
		//ccptr->rightvolume =20;
		LODWORD(v6) = -2139062143 * (volume * (255L-ccptr->actualpan));
		ccptr->leftvolume  = (signed int)(volume * ccptr->actualpan) / 255;
		ccptr->rightvolume = (signed int)(volume * (255L-ccptr->actualpan)) / 255;
	}
  }
  if (cptr->notectrl & FMUSIC_PAN)
  {
    pan = cptr->pan+( (cptr->envpan-32) * ( (128-abs(cptr->pan-128))/32 ) );
	LODWORD(v6) = (((128 - (cptr->pan-128)) >> 31) & 0x1F) + 128 - (cptr->pan-128);
	if (pan < 0)
		pan = 0;
	if (pan > 255)
		pan = 255;

	if (ccptr)
	{
		ccptr->pan = ccptr->actualpan = pan;
		ccptr->leftvolume  = (ccptr->actualvolume * pan) / 255;
		ccptr->rightvolume = (ccptr->actualvolume * (255L-pan)) / 255;
		 LODWORD(v6) = -2139062143 * (ccptr->actualvolume * (255L-pan));
	}
  }
  if (cptr->notectrl & FMUSIC_FREQ)
  {
    /*freq = (unsigned __int64)(pow(
                               2.0,
							   (double)
                               (4608.0 - (double)cptr->freq +cptr->freqdelta)
                             * 0.0013020834)
                           * 8363.0);*/
	temp= (double)(4608.0 - (double)cptr->freq +cptr->freqdelta) * 0.0013020834;
	temp =(double)pow(2,temp);
	temp = (double) temp*8363.0;
	freq = (unsigned __int64)temp;
    freq = freq;
	
    ccptr->frequency = freq;
    if ( (signed int)freq < 100 )
      freq = 100;
    v16 = freq;
    v17 = FSOUND_MixRate_456A40;
    v18 = freq / FSOUND_MixRate_456A40;
	
    HIDWORD(v6) = freq % FSOUND_MixRate_456A40;
    ccptr->speedhi = freq / FSOUND_MixRate_456A40;
    ccptr->speedlo = v6 / (unsigned int)v17;
  //ver lo que hace aqui con esto porque parece que se usa
	/*LODWORD(v6) = v16;
	__asm
		{
			push	eax
			push	ebx
			push	ecx			
			push	edx

			// work out low fractional part of the speed using a 64bit divide
			mov		ecx, ccptr
			mov		ebx, FSOUND_MixRate_456A40
			mov		eax, freq
			xor		edx, edx
			div		ebx							// get quotient and remainder
			mov		[ecx].speedhi, eax
			div		ebx							// now divide remainder by rate to get lower 32bit fraction
			mov		[ecx].speedlo, eax

			pop		edx
			pop		ecx
			pop		ebx
			pop		eax
		}
		*/
    //todo fixv3 = cptr;
  }
  if (cptr->notectrl & FMUSIC_STOP)		
  {
    ccptr->mixposlo = 0;
	ccptr->mixpos = 0;
    ccptr->sampleoffset = 0;	// if this channel gets stolen it will be safe
  }
  //return 1000000;
  //return v6;
}
// 456A40: using guessed type int FSOUND_MixRate_456A40_456A40;

//----- (0043EB10) --------------------------------------------------------
int __cdecl FMUSIC_XM_Resetcptr_43EB10(FMUSIC_CHANNEL *cptr, FSOUND_SAMPLE	*sptr)

{
  int result; // eax@1
  char v3; // dl@1

  //result = a1;
  cptr->volume = (int)sptr->defvol;//16 y 16
  //v3 = *(BYTE *)(a1 + 162);
  
  cptr->pan			= sptr->defpan;// 20 y 24
  cptr->envvol		= 32;//52
  cptr->envvolpos		= 0;//44
  cptr->envvoltick	= 0;//40
  cptr->envvoldelta	= 0;//56
  
  cptr->envpan		= 32;//76
  cptr->envpanpos		= 0;//68
  cptr->envpantick	= 0;//64
  cptr->envpandelta	= 0;//80

  cptr->keyoff		= 0;///101
  cptr->fadeoutvol	= 65536;//88
  
  cptr->envvolstopped = FALSE;//60
  cptr->envpanstopped = FALSE;//84
  cptr->ivibsweeppos  = 0; //96
	cptr->ivibpos       = 0;//92
  if ( (cptr->wavecontroltrem & 0xFu) < 4 )
    cptr->vibpos=0; //133
  if ( (cptr->wavecontroltrem & 0xF0u) < 0x40 ) //offset 162
    cptr->tremolopos=0; //137
  cptr->tremorpos	= 0;	 //146
  cptr->notectrl |= FMUSIC_VOLUME;
  cptr->notectrl |= FMUSIC_PAN;//*(BYTE *)(a1 + 2) |= 6u;
  //return result;

}


//----- (0043EBB0) --------------------------------------------------------
char __cdecl sub_43EBB0(int channelId, unsigned __int8 volume)
{
	//el primer parametro que se pasa es FMUSIC_CHANNEL *cptr
  return FMUSIC_XM_ProcessVolumeByte_43E7A0((int)&FMUSIC_Channel[channelId],volume);
}

//----- (0043EBD0) --------------------------------------------------------
unsigned __int64 __cdecl sub_43EBD0(int channelId, signed int a2)
{
  char *v2; // esi@1
  FMUSIC_CHANNEL *cptr; //es v2
  unsigned __int64 result; // rax@1

  //v2 = (char *)&FMUSIC_Channel + 172 * channelId;
  cptr = &FMUSIC_Channel[channelId];	
  
  //cptr->realnote = cptr->note + cptr->sptr->relative - 1;
  /*result = (unsigned __int64)(7680.0
                            - ((double)a2 * 0.000015258789 * 6.0
                             + 52.0
                             - 6.0
                             + (double)*(BYTE *)(*((_DWORD *)v2 + 2) + 31))
                            * 64.0
                            - (double)(*(BYTE *)(*((_DWORD *)v2 + 2) + 17) / 2));*/
    result = (unsigned __int64)((10*12*16*4)
                            - ((double)(a2 * 0.000015258789 * 6.0)
                             + 52.0
                             - 6.0
							 + (double)*(char*)(&cptr->sptr +31)) //samp
                            * 64.0
							- (double)(*(char*)(&cptr->sptr +17) / 2));

	  result = (unsigned __int64)(7680.0
                            -(double) ((a2 * 0.000015258789 * 6.0) + 52.0 - 6.0 + cptr->sptr->relative) * 64.0
                            - (double)(cptr->sptr->finetune / 2));
	
  //*((_DWORD *)v2 + 26) = result;
  //para carreracptr->period = result*0.75;
  	//cptr->freq = result*0.75; //esto esta tuneadisimo
	 cptr->period = result;
	 cptr->freq = result*0.62; //BUGFIX
//  *((_DWORD *)v2 + 3) = result; //unsigned char	notectrl;	
  return result;
}

//----- (0043EC40) --------------------------------------------------------
int __cdecl FMUSIC_UpdateXMNote_43EC40(FMUSIC_MODULE *mod, int channelId, unsigned __int8 soundId, int a4, char volume)
{
	//FMUSIC_UpdateXMNote(FMUSIC_MODULE *mod)  esta modificado claro
	//parece #ifdef FMUSIC_XM_NOTEDELAY_ACTIVE #ifdef FMUSIC_XM_VOLUMEBYTE_ACTIVE
	//a2 es el ficheero de sonido
	//a3 es el indice del fichero
  FMUSIC_CHANNEL			*cptr_v5; // esi@1
  FMUSIC_INSTRUMENT		* iptr_v6; // edi@2
  FSOUND_SAMPLE			*sptr_v7; // ebp@2
  int current_instruent_v8; // ebp@3
  int cprt_inst_v9; // edi@3
  FMUSIC_CHANNEL			* cptr_v10; // al@3
  char v11; // dl@7
  char v12; // al@7
  char v13; // cl@12

  cptr_v5 = (int)((char *)&FMUSIC_Channel[channelId]);
  cptr_v5->inst = soundId;
  if ( soundId < mod->numinsts )//a1+32
  {
	current_instruent_v8 = *(_DWORD *)mod->instrument;//FMUSIC_INSTRUMENT *instrument;	
    cprt_inst_v9 = soundId;//v9 = 340 * soundId; 340 es el tamaño de instrumet
    iptr_v6 = &mod->instrument[soundId];//cprt_inst_v9];

    cptr_v10 = iptr_v6->keymap[cptr_v5->note];//*(BYTE *)(cprt_inst_v9 + current_instruent_v8 + 108);
    if ( iptr_v6->keymap[cptr_v5->note] < 0x10u ){
		sptr_v7 = iptr_v6->sample[iptr_v6->keymap[cptr_v5->note]];
		cptr_v5->sptr = sptr_v7;
      //v7 = *(_DWORD *)(v6 + 4 * v10 + 4);
    }else{
		sptr_v7 = &FMUSIC_DummySample_45DA80;
		cptr_v5->sptr = sptr_v7;
		}
    // v7 = (int)&dword_45DA80;
    //*(_DWORD *)(v5 + 8) = v7;
  }
  else
  {
    iptr_v6 = &FMUSIC_DummyInstrument;
    sptr_v7 = &FMUSIC_DummySample_45DA80;
    sptr_v7->buff = NULL;//dword_45DA80 = 0;
  }
  cptr_v5->voldelta = 0;
  cptr_v5->notectrl = FMUSIC_TRIGGER;
  sub_43EBD0(channelId, a4);
  	
  v11 =cptr_v5->notectrl		| FMUSIC_FREQ;
  v11 =v11		| FMUSIC_VOLUME;
  cptr_v5->freqdelta = 0;
  cptr_v5->notectrl = v11;
  FMUSIC_XM_Resetcptr_43EB10(cptr_v5, sptr_v7);//FMUSIC_CHANNEL *cptr, FSOUND_SAMPLE	*sptr
  FMUSIC_XM_ProcessVolumeByte_43E7A0(cptr_v5, volume);
  v12 = iptr_v6->VOLtype;
  if ( v12 & FMUSIC_ENVELOPE_ON )
  {
    if (!cptr_v5->envvolstopped) 
			FMUSIC_XM_ProcessEnvelope_43E670(cptr_v5, &cptr_v5->envvolpos, &cptr_v5->envvoltick, iptr_v6->VOLtype, iptr_v6->VOLnumpoints, &iptr_v6->VOLPoints[0],
									iptr_v6->VOLLoopEnd, iptr_v6->VOLLoopStart, iptr_v6->VOLsustain, &cptr_v5->envvol, &cptr_v5->envvolfrac, &cptr_v5->envvolstopped, &cptr_v5->envvoldelta, FMUSIC_VOLUME);
		
  }
  else 	if (cptr_v5->keyoff) 
				cptr_v5->envvol = 0;

  v13 =iptr_v6->PANtype;
  if ( v13 & FMUSIC_ENVELOPE_ON && !cptr_v5->envpanstopped )
    FMUSIC_XM_ProcessEnvelope_43E670(cptr_v5, &cptr_v5->envpanpos, &cptr_v5->envpantick, iptr_v6->PANtype, iptr_v6->PANnumpoints, &iptr_v6->PANPoints[0], iptr_v6->PANLoopEnd, iptr_v6->PANLoopStart,
									iptr_v6->PANsustain, &cptr_v5->envpan, &cptr_v5->envpanfrac, &cptr_v5->envpanstopped, &cptr_v5->envpandelta, FMUSIC_PAN);

  return FMUSIC_XM_UpdateFlags_43E8C0(cptr_v5, sptr_v7, mod);
}
// 45DA80: using guessed type int dword_45DA80;

//----- (0043EDC0) --------------------------------------------------------
int __cdecl FMUSIC_UpdateXMEffects_43EDC0(FMUSIC_MODULE *mod)
{
  int result; // eax@1
  _UNKNOWN *v2; // esi@2
  signed int v3; // edi@4
  int v4; // edi@5
  unsigned __int8 v5; // al@6
  int v6; // ebx@7
  char v7; // al@9
  char v8; // cl@12
  int v9; // ecx@16
  bool v10; // sf@16
  signed int v11; // [sp+4h] [bp-4h]@1
  
 /* result = a1;
  v11 = 0;
  if ( *(_WORD *)(a1 + 20) > 0 )
  {*/
  	FMUSIC_NOTE	*current;
	int		count;


	for (count=0; count<mod->numchannels; count++)
	{

		FMUSIC_CHANNEL			*cptr  = NULL;
		FMUSIC_INSTRUMENT		*iptr  = NULL;
		FSOUND_SAMPLE			*sptr  = NULL;
		unsigned char			effect, paramx, paramy;
		
		cptr = &FMUSIC_Channel[count];

//			**** FIXME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//		cptr = LinkedListNextNode(&cptr->vchannelhead);
//
//		if (LinkedListIsRootNode(cptr, &cptr->vchannelhead)) 
//			cptr = &FMUSIC_DummyVirtualChannel; // no channels allocated yet
//			**** FIXME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

		if (cptr->inst >= (int)mod->numinsts)
		{
			iptr = &FMUSIC_DummyInstrument;
			sptr = &FMUSIC_DummySample_45DA80;
			sptr->buff = NULL;
		}
		else
		{
			iptr = &mod->instrument[cptr->inst];
			if (iptr->keymap[cptr->note] >= 16) 
            {
				sptr = &FMUSIC_DummySample_45DA80;
            }
			else 
            {
				sptr = iptr->sample[iptr->keymap[cptr->note]];
            }

			if (!sptr)
            {
				sptr = &FMUSIC_DummySample_45DA80;
            }
		}

	//	effect = current->effect;			// grab the effect number
	//	paramx = current->eparam >> 4;		// grab the effect parameter x
	//	paramy = current->eparam & 0xF;		// grab the effect parameter y

		cptr->voldelta	= 0;				// this is for tremolo / tremor etc
		cptr->freqdelta = 0;				// this is for vibrato / arpeggio etc
		cptr->notectrl	= 0;

		//= PROCESS ENVELOPES ==========================================================================
		if (iptr->VOLtype & FMUSIC_ENVELOPE_ON && !cptr->envvolstopped) 
        {
			FMUSIC_XM_ProcessEnvelope_43E670(cptr, &cptr->envvolpos, &cptr->envvoltick, iptr->VOLtype, iptr->VOLnumpoints, &iptr->VOLPoints[0], iptr->VOLLoopEnd, iptr->VOLLoopStart, iptr->VOLsustain, &cptr->envvol, &cptr->envvolfrac, &cptr->envvolstopped, &cptr->envvoldelta, FMUSIC_VOLUME);
        }
		if (iptr->PANtype & FMUSIC_ENVELOPE_ON && !cptr->envpanstopped) 
        {
			FMUSIC_XM_ProcessEnvelope_43E670(cptr, &cptr->envpanpos, &cptr->envpantick, iptr->PANtype, iptr->PANnumpoints, &iptr->PANPoints[0], iptr->PANLoopEnd, iptr->PANLoopStart, iptr->PANsustain, &cptr->envpan, &cptr->envpanfrac, &cptr->envpanstopped, &cptr->envpandelta, FMUSIC_PAN);
        }


		//= PROCESS VOLUME FADEOUT =====================================================================
		if (cptr->keyoff) 
		{
			cptr->fadeoutvol -= iptr->VOLfade;
			if (cptr->fadeoutvol < 0) 
            {
				cptr->fadeoutvol = 0;
            }
			cptr->notectrl |= FMUSIC_VOLUME;
		}


		FMUSIC_XM_InstrumentVibrato_43E550(cptr, iptr);
		FMUSIC_XM_UpdateFlags_43E8C0(cptr, sptr,mod);
	}
}
// 45DA80: using guessed type int dword_45DA80;

//----- (0043EF60) --------------------------------------------------------
char __cdecl FMUSIC_LoadXM_43EF60(FMUSIC_MODULE *mod, FSOUND_FILE_HANDLE *fp)
{
  signed int v2; // eax@1
  bool v3; // zf@4
  bool v4; // sf@4
  int v5; // eax@5
  int v6; // ecx@6
  signed int v7; // eax@9
  unsigned __int16 v8; // ax@11
  int v9; // eax@12
  FMUSIC_PATTERN *pptr_v10; // ebx@12
  void *v11; // eax@12
  int v12; // edx@13
  int v13; // edi@14
  unsigned __int8 v14; // al@15
  char result; // al@26
  int v16; // eax@30
  int v17; // ecx@34
  int v18; // edi@36
  int v19; // ebx@37
  FMUSIC_INSTRUMENT	*iptr_v20; // ebx@40
  bool v21; // cf@42
  void *v22; // esi@48
  int v23; // edi@48
  int v24; // edx@55
  int v25; // ecx@57
  int v26; // eax@57
  int v27; // eax@59
  int lenbytes_v28; // edi@60
  int v29; // eax@65
  int v30; // esi@70
  int v31; // eax@70
  int samplelenbytes_v32; // edi@70
  BYTE *buff_v33; // ebx@71
  void (__cdecl *v34)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // eax@71
  signed short *wptr_v35; // edi@75
  int i; // eax@75
  __int16 v37; // dx@76
  void *v38; // ecx@80
  int v39; // edx@80
  unsigned int v40; // edi@80
  int v41; // eax@81
  char v42; // cl@82
  void *buff_v43; // eax@82
  int v44; // eax@88
  int v45; // ecx@89
  unsigned __int8 v46; // of@89
  unsigned __int8 dat_v47; // [sp+Ah] [bp-126h]@15
  unsigned __int8 tempchar_v47; // [sp+Bh] [bp-125h]@12
  signed short *buff ;
  char tempchar_v48; // [sp+Bh] [bp-125h]@12
  FSOUND_SAMPLE	*sptr_v48;
  unsigned __int16 rows_v49; // [sp+Ch] [bp-124h]@12
  unsigned __int16 numsamples_v49; // [sp+Ch] [bp-124h]@12
  
  int v50; // [sp+10h] [bp-120h]@13
  unsigned int patternsize_v51; // [sp+14h] [bp-11Ch]@12
  int v51;
  int v52; // [sp+18h] [bp-118h]@11
  int v53; // [sp+1Ch] [bp-114h]@13
  int filenumpatterns_v54; // [sp+20h] [bp-110h]@1
  int patternHDRsize_v55; // [sp+24h] [bp-10Ch]@12
  int instHDRsize_v55;
  int mainHDRsize_v56; // [sp+28h] [bp-108h]@4
  int sampHDRsize_v57; // [sp+2Ch] [bp-104h]@42
  char v58[17]; // [sp+30h] [bp-100h]@1
  int firstsampleoffset = 0;
  FMUSIC_NOTE *nptr;
  filenumpatterns_v54 = 0;
  FSOUND_File_Seek_43F7B0(fp);
  FSOUND_File_Read_43F790(v58, 17, fp);
  v2 = 0;
  do
  {
    if ( v58[v2] != streamId_4444F8[v2] )
      return 0;
    ++v2;
  }
  while ( v2 < 16 );
  mod->Update			     = &FMUSIC_UpdateXM_43EF50;//  *(_DWORD *)(effectStruct + 344) = sub_43EF50;
  mod->defaultglobalvolume = 64;//*(BYTE *)(effectStruct + 296) = 64;
 
 // FSOUND_File_Seek_43F7B0(fp);

  FSOUND_File_SeekCallback_43AE30(fp->userhandle, 60, 0);
 
  FSOUND_File_Read_43F790((int)&mainHDRsize_v56, 4, fp);
  FSOUND_File_Read_43F790(&mod->numorders, 6, fp); //+16

 // cambiadoS
 // FSOUND_File_Read_43F790(&mod->numorders, 2, fp);
///FSOUND_File_Read_43F790(&mod->restart, 2, fp);
	//FSOUND_File_Read_43F790(&mod->numchannels, 2, fp);

  FSOUND_File_Read_43F790(&filenumpatterns_v54, 2, fp);//(int)&v54
  FSOUND_File_Read_43F790(&mod->numinsts, 256+8, fp);//+32 puede estar mal!
  FSOUND_File_SeekCallback_43AE30(fp->userhandle, 0x108 +6+2+4+0x3C,0);//60L+mainHDRsize_v56, 0);
  //FSOUND_File_Seek_43F7B0(fp);
  
  
  
  v3 = mod->numorders == 0; //+16
  v4 = mod->numorders < 0;  //+16
  mod->numpatterns = 0; //++24 aqui por offset es patternsmem
  if ( !v4 && !v3 )
  {
    v5 = 0;// effectStruct + 40; //orderlist
    do
    {
      //v6 = *(BYTE *)v5;
      if ( mod->orderlist[v5] >= mod->numpatterns);//+24
        mod->numpatterns = mod->orderlist[v5] + 1; //+24
      ++v5;
    }
    while ( mod->orderlist[v5] < mod->numorders ); //+16
  }
  
  
  v7 = mod->numpatternsmem;
  if ( v7 <= (unsigned __int16)filenumpatterns_v54 )
    v7 = (unsigned __int16)filenumpatterns_v54;
 
  mod->numpatternsmem = (mod->numpatterns > filenumpatterns_v54 ? mod->numpatterns : filenumpatterns_v54);
  mod->pattern = calloc(8 * v7, 1u);	//FIXME:MEMLEAK

  v8 = filenumpatterns_v54;
  v52 = 0;
  if ( (unsigned __int16)filenumpatterns_v54 > 0u )
  {
    do
    {
      //v9 = *(_DWORD *)effectStruct;
      tempchar_v48 = 0;
  //		pptr = &mod->pattern[count];

	  pptr_v10 = &mod->pattern[v52];
      FSOUND_File_Read_43F790((int)&patternHDRsize_v55, 4, fp);
      FSOUND_File_Read_43F790((int)&tempchar_v48, 1, fp);
      FSOUND_File_Read_43F790((int)&rows_v49, 2, fp);
      pptr_v10->rows = rows_v49;
      FSOUND_File_Read_43F790((int)&patternsize_v51, 2, fp);
      //		// allocate memory for pattern buffer
//		pptr->data = (FMUSIC_NOTE *)FSOUND_Memory_Calloc(mod->numchannels * pptr->rows * sizeof(FMUSIC_NOTE));	//FIXME:MEMLEAK

	  pptr_v10->data = (FMUSIC_NOTE *)FSOUND_Memory_Calloc(mod->numchannels * pptr_v10->rows * sizeof(FMUSIC_NOTE));	//FIXME:MEMLEAK

//	  v11 = calloc(5 * *(_DWORD *)v10 * *(_WORD *)(effectStruct + 20), 1u);
  //    *(_DWORD *)(v10 + 4) = v11;
      if ( (_WORD)patternsize_v51 )
      {
        v12 = mod->numchannels * pptr_v10->rows;//+20
        //v50 = (int)v11;
        v53 = 0;
        if ( v12 > 0 )
        {
			nptr = pptr_v10->data;
      //    v13 = (int)((char *)v11 + 1);
          do
          {
            FSOUND_File_Read_43F790((int)&dat_v47, 1, fp);
            v14 = dat_v47;
            if ( (dat_v47 & 0x80u) == 0 )
            {
              if ( dat_v47 )
                nptr->note= dat_v47; //v50
              FSOUND_File_Read_43F790(&nptr->number, 4, fp); //v13
            }
            else
            {
              if ( dat_v47 & 1 )
              {
                FSOUND_File_Read_43F790(&nptr->note, 1, fp); //v50
                v14 = dat_v47;
              }
              if ( v14 & 2 )
              {
                FSOUND_File_Read_43F790(&nptr->number, 1, fp);
                v14 = dat_v47;
              }
              if ( v14 & 4 )
              {
                FSOUND_File_Read_43F790(&nptr->volume, 1, fp);
                v14 = dat_v47;
              }
              if ( v14 & 8 )
              {
                FSOUND_File_Read_43F790(&nptr->effect, 1, fp);
                v14 = dat_v47;
              }
              if ( v14 & 0x10 )
                FSOUND_File_Read_43F790(&nptr->eparam, 1, fp);
            }
            v16 = nptr->note ; //v50
            if ( nptr->note == 97 ) //v50
              nptr->note  = FMUSIC_KEYOFF; //-1 v50
             if ( nptr->number > 0x80u )
              nptr->number = 0;
            v17 = pptr_v10->rows * mod->numchannels; //+20
            v50 = v16 + 5;
            //v13 += 5;
			nptr++;
            ++v53;
          }
          while ( v53 < v17 );
        }
      }
      v8 = filenumpatterns_v54;
      ++v52;
    }
    while ( v52 < (unsigned __int16)filenumpatterns_v54 );
  }

  
  v18 = filenumpatterns_v54; //v8
  if ( (signed int)filenumpatterns_v54 < mod->numpatterns )//+24
  {
    do
    {
      //v19 = *(_DWORD *)effectStruct + 8 * v18;
      pptr_v10->rows= 64; //v19
      pptr_v10->data = (FMUSIC_NOTE *)FSOUND_Memory_Calloc(mod->numchannels * pptr_v10->rows * sizeof(FMUSIC_NOTE));
	
	//  *(_DWORD *)(v19 + 4) = calloc(320 * *(_WORD *)(effectStruct + 20), 1u);
      ++v18;
    }
    while ( v18 < mod->numpatterns); //+24
  }

  mod->instrument = (FMUSIC_INSTRUMENT *)FSOUND_Memory_Calloc((int)(mod->numinsts) * sizeof(FMUSIC_INSTRUMENT));
//  *(_DWORD *)(effectStruct + 4) = calloc(340 * *(_WORD *)(effectStruct + 32), 1u);
  
  
  v3 = mod->numinsts==0;
  v4 = mod->numinsts <0;
  v52=0;	

 // v3 = *(_WORD *)(effectStruct + 32) == 0;
  //v4 = *(_WORD *)(effectStruct + 32) < 0;
  //v52 = 0;
  if ( v4 || v3 )
  {
LABEL_90:
    result = 1;
  }
  else
  {
    v53 = 0;
	
    while ( 1 )
    {
      iptr_v20 = &mod->instrument[v53];// + *(_DWORD *)(effectStruct + 4);
      firstsampleoffset=FSOUND_File_Tell_43F7D0(fp);
      FSOUND_File_Read_43F790(&instHDRsize_v55, 4, fp);
	  firstsampleoffset += instHDRsize_v55;
	  FSOUND_File_SeekCallback_43AE30(fp->userhandle, 23, SEEK_CUR);
      //FSOUND_File_Seek_43F7B0(fp);
      FSOUND_File_Read_43F790(&numsamples_v49, 2, fp);
      if ( numsamples_v49 > 0x10u )
        break;
      iptr_v20->numsamples = numsamples_v49;
      if ( numsamples_v49 )
      {
        tempchar_v47 = 0;
        FSOUND_File_Read_43F790(&sampHDRsize_v57, 4, fp);
        FSOUND_File_Read_43F790(iptr_v20->keymap, 96, fp);
        FSOUND_File_Read_43F790(iptr_v20->VOLPoints, 48, fp);
        FSOUND_File_Read_43F790(iptr_v20->PANPoints, 48, fp);
        FSOUND_File_Read_43F790(&iptr_v20->VOLnumpoints, 16, fp); //+324
        v21 = iptr_v20->VOLnumpoints < 2u;
        iptr_v20->VOLfade  *= 2;
        if ( v21 )
          iptr_v20->VOLtype = FMUSIC_ENVELOPE_OFF;
        if ( iptr_v20->PANnumpoints< 2u )
          iptr_v20->PANtype = FMUSIC_ENVELOPE_OFF;
		FSOUND_File_SeekCallback_43AE30(fp->userhandle, firstsampleoffset, SEEK_SET);///esto esta puesto a fueguisimo TODO FIX
        //FSOUND_File_Seek_43F7B0(fp);


        v51 = 0;
        if ( !numsamples_v49 )
          goto LABEL_94;
        //v50 = v20 + 4;
		  v50=0;
        do
        {
			iptr_v20->sample[v50] = (FSOUND_SAMPLE *)FSOUND_Memory_Calloc(sizeof(FSOUND_SAMPLE));

//          v22 = calloc(0x30u, 1u);
			sptr_v48 = iptr_v20->sample[v50];

          //v23 = (int)((char *)v22 + 4);
          //*(_DWORD *)v50 = v22;
          FSOUND_File_Read_43F790(&sptr_v48->length, 14, fp);
          sptr_v48->loopmode = FSOUND_LOOP_OFF;
          sptr_v48->bits = 8;
          FSOUND_File_Read_43F790(&tempchar_v48, 1, fp);
          if ( tempchar_v48 & 1 ){
            	sptr_v48->loopmode &= ~(FSOUND_LOOP_OFF);
				sptr_v48->loopmode |= FSOUND_LOOP_NORMAL;
			}	
          if ( tempchar_v48 & 2 ){
          	sptr_v48->loopmode &= ~(FSOUND_LOOP_OFF | FSOUND_LOOP_NORMAL);
			sptr_v48->loopmode |= FSOUND_LOOP_BIDI;		// bidirectional
		  }
			if ( tempchar_v48 & 0x10 )
            sptr_v48->bits = 16;
          if (sptr_v48->loopmode & FSOUND_LOOP_OFF) 
		  {
            sptr_v48->loopstart = 0;
			sptr_v48->looplen = sptr_v48->length;
          }
          if (sptr_v48->bits == 16 )
          {
    		sptr_v48->length >>= 1;
			sptr_v48->loopstart >>= 1;
			sptr_v48->looplen >>= 1;
	
          }
          if ( !sptr_v48->looplen )
          {
            sptr_v48->loopstart = 0;
			sptr_v48->looplen = sptr_v48->length;
			sptr_v48->loopmode = FSOUND_LOOP_OFF;
          }
          FSOUND_File_Read_43F790(&tempchar_v47, 1, fp);
          sptr_v48->defpan = (int)tempchar_v47;
		  FSOUND_File_Read_43F790(&tempchar_v47, 1, fp);
          sptr_v48->relative = tempchar_v47;
		  FSOUND_File_SeekCallback_43AE30(fp->userhandle, 23, SEEK_CUR);
          //FSOUND_File_Seek_43F7B0(fp); //	FSOUND_File_Seek(fp, 23, SEEK_CUR);

          lenbytes_v28 = 2 * sptr_v48->length;//esto esta distinto pero bueno
          if ( sptr_v48->buff )
            FSOUND_Memory_Free(sptr_v48->buff);
          if ( lenbytes_v28 )
            sptr_v48->buff = calloc(lenbytes_v28 + 16, 1u);
          else
            sptr_v48->buff = 0;
          v50 += 1;
          v29 = v51++ + 1;
        }
        while ( v51 < numsamples_v49 );
        if ( (unsigned int)v29 < 0x10 )
LABEL_94:
	
			// clear out the rest of the samples
			//esto esta en la libreriafor (;count2<16; count2++) 
            //{
		//		iptr->sample[count2] = &FMUSIC_DummySample_45DA80;
          //  }
		for (;v50<16; v50++) 
            {
				//iptr_v20->sample[v50] = (int*) &FMUSIC_DummySample_45DA80;
            }
		//TODO FIX esto peta memset32((void *)(v20 + 4 * v51 + 4), (int)&dword_45DA80, 16 - v51);
    
		v51 = 0;
        if ( numsamples_v49 )
        {

          //v50 = v20 + 4;
          do
          {
           //todofix v30 = *(_DWORD *)v50;
            //v31 = *(_DWORD *)(*(_DWORD *)v50 + 4);
            samplelenbytes_v32 = sptr_v48->length * sptr_v48->bits / 8;// (unsigned int)*(BYTE *)(*(_DWORD *)v50 + 28) >> 3;
            if ( sptr_v48->length )
            {
			 buff_v33 = FSOUND_Memory_Calloc((sptr_v48->length * 2)+16);
              //v33 = calloc(2 * sptr_v48->length + 16, 1u);
              //v34 = *(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(effectStruct + 348);
             ///quitado porque parece que no se usa if ( mod->samplecallback ) //v34 parece que esto nunca pasa
             ///quitado porque parece que no se usa  {
				  //mod->samplecallback(buff, samplelenbytes, sptr->bits, count, count2);
						//FSOUND_File_SeekCallback_43AE30(fp, samplelenbytes_v32, SEEK_CUR);
             ///quitado porque parece que no se usa     mod->samplecallback((int)buff_v33, samplelenbytes_v32, sptr_v48->bits,v52,v51);//*(BYTE *)(v30 + 28), v52, v51); v34 al principio
             ///quitado porque parece que no se usa    FSOUND_File_Seek_43F7B0(fp);
             ///quitado porque parece que no se usa  }
              ///quitado porque parece que no se usa else
              ///quitado porque parece que no se usa {
			  FSOUND_File_Read_43F790(buff_v33, samplelenbytes_v32, fp);
               ///quitado porque parece que no se usa}
              if (sptr_v48->bits == 8)// *(BYTE *)(v30 + 28) == 8 )
              {
                //v35 = *(void **)v30;
                wptr_v35 = (signed short *)sptr_v48->buff;
				for ( i = 0; i < sptr_v48->length; i++)//*((_WORD *)v35 - 1) = v37 )
                {
					*wptr_v35 = (signed short)(buff_v33[i]) << 8;
					//LOBYTE(*wptr_v35) = 0;
                  //HIBYTE(*wptr_v35) = *((BYTE *)&buff_v33+i);
					*wptr_v35 ++;

					//LOBYTE(v37) = 0;
                  //HIBYTE(v37) = *((BYTE *)v33 + i);
                  //v35 = (char *)v35 + 2;
       //comentado para uqe funcione  *(_DWORD *)&wptr_v35 + 1 = (signed short)(&buff_v33+i) << 8;
					//++i;
                }
                sptr_v48->bits = 16;
                FSOUND_Memory_Free(buff_v33);//free(v33);
              }
              else
              {
				  FSOUND_Memory_Free(sptr_v48->buff);
					sptr_v48->buff = buff_v33;	
                //free(*(void **)v30);
                //todofix *(_DWORD *)v30 = buff_v33;
              }

			 // mode = FSOUND_DELTA | FSOUND_SIGNED;
				//*/	mode |= FSOUND_16BITS;
              if (1==1)//!mod->samplecallback)// !*(_DWORD *)(effectStruct + 348) )
              {
				  void			*destdata = sptr_v48->buff;
						unsigned int	count;
						unsigned char	*bptr = (unsigned char *)destdata;
						unsigned short	*wptr = (unsigned short *)destdata;
						int				oldval, newval;

						// DO DELTA CONVERSION
						oldval = 0;
						for (count=0; count < sptr_v48->length; count++) 
						{
							newval = *wptr + oldval;
							*wptr = (short)newval;
							oldval = newval;
							wptr++;
						}
               /* v38 = *(void **)v30;
                v39 = 0;
                v40 = 0;
                if ( sptr_v48->length )
                {
					// DO DELTA CONVERSION
						
                  do
                  {
                    v41 = v39 + *(_WORD *)v38;
                    *(_WORD *)v38 = v41;
                    v38 = (char *)v38 + 2;
                    v39 = v41;
                    ++v40;
                  }
                  while ( v40 < sptr_v48->length);
                }*/
              }
				  (signed short *)buff = (signed short *)sptr_v48->buff;
					
						// BUGFIX 1.3 - removed click for end of non looping sample (also size optimized a bit)
						if (sptr_v48->loopmode == FSOUND_LOOP_BIDI)
						{
							buff[sptr_v48->loopstart+sptr_v48->looplen] = buff[sptr_v48->loopstart+sptr_v48->looplen-1];// fix it
						}
						else if (sptr_v48->loopmode == FSOUND_LOOP_NORMAL)
						{
							buff[sptr_v48->loopstart+sptr_v48->looplen] = buff[sptr_v48->loopstart];// fix it
						}
              //v42 = *(BYTE *)(v30 + 29);
              /*buff_v43 = *(void **)v30;


			  //esto se usa en carrera
              if (  sptr_v48->loopmode == FSOUND_LOOP_BIDI )
              {

//ToDO fix				  &buff_v43 +sptr_v48->loopstart+sptr_v48->looplen = &buff_v43 +sptr_v48->loopstart+sptr_v48->looplen-1;// fix it
               // *((_WORD *)v43 + *(_DWORD *)(v30 + 8) + *(_DWORD *)(v30 + 12)) = *((_WORD *)v43
                 //                                                                + *(_DWORD *)(v30 + 8)
                   //                                                              + *(_DWORD *)(v30 + 12)
                     //                                                            - 1);
              }
              else if ( sptr_v48->loopmode == FSOUND_LOOP_NORMAL )
              {
//TODO FIX				  &buff_v43 +sptr_v48->loopstart+sptr_v48->looplen = &buff_v43 +sptr_v48->loopstart;
                //*((_WORD *)v43 + *(_DWORD *)(v30 + 8) + *(_DWORD *)(v30 + 12)) = *((_WORD *)v43 + *(_DWORD *)(v30 + 8));//
              }*/
            }
            v50 += 4;
            ++v51;
          }
          while ( v51 < numsamples_v49 );
        }
      }
      else
      {

		  iptr_v20->sample[0] = &FMUSIC_DummySample_45DA80;
		  iptr_v20->sample[1] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[2] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[3] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[4] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[5] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[6] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[7] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[8] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[9] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[10] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[11] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[12] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[13] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[14] = &FMUSIC_DummySample_45DA80;
          iptr_v20->sample[15] = &FMUSIC_DummySample_45DA80;
          FSOUND_File_SeekCallback_43AE30(fp->userhandle, firstsampleoffset, SEEK_SET);
        //FSOUND_File_Seek_43F7B0(fp);
      }
	  v45 = mod->numinsts;
	  if(v45<v53)
		goto LABEL_90;
	  v53++;

	  //esto hay que cambiarlo porque ni idea
      /*v45 = *(_WORD *)(effectStruct + 32);
      v46 = __OFSUB__(v52 + 1, v45);
      v4 = v52++ + 1 - v45 < 0;
      v53 += 340;
      if ( !(v4 ^ v46) )
        goto LABEL_90;*/
    }
    result = 0;
  }
//return mod;
  return result;
}
// 43EF50: using guessed type int __cdecl sub_43EF50(int);
// 45DA80: using guessed type int dword_45DA80;
// 43EF60: using guessed type char var_100[256];

//----- (0043F6B0) --------------------------------------------------------
int (__cdecl *__cdecl FSOUND_File_SetCallbacks_43F6B0(int (__cdecl *OpenCallback)(_DWORD), int (__cdecl *CloseCallback)(_DWORD), int (__cdecl *ReadCallback)(_DWORD, _DWORD, _DWORD), int (__cdecl *SeekCallback)(_DWORD), int (__cdecl *TellCallback)(_DWORD)))(_DWORD)
{
	/*void FSOUND_File_SetCallbacks(unsigned int (*OpenCallback)(char *name), void	(*CloseCallback)(unsigned int handle),	int (*ReadCallback)(void *buffer, int size, unsigned int handle), void (*SeekCallback)(unsigned int handle, int pos, signed char mode), int (*TellCallback)(unsigned int handle))
{
	if (!OpenCallback || !CloseCallback || !ReadCallback || !SeekCallback || !TellCallback)*/
  int (__cdecl *result)(_DWORD); // eax@5

  if ( OpenCallback && CloseCallback && ReadCallback && SeekCallback && (result = TellCallback) != 0 )
  {
    FSOUND_File_OpenCallback_456C9C = OpenCallback;
    FSOUND_File_CloseCallback_456CA0 = CloseCallback;
    FSOUND_File_ReadCallback_456CA4 = ReadCallback;
    FSOUND_File_SeekCallback_456CA8 =SeekCallback;
    FSOUND_File_TellCallback_456CAC = TellCallback;
  }
  else
  {
    FSOUND_File_OpenCallback_456C9C = 0;
    FSOUND_File_CloseCallback_456CA0 = 0;
    FSOUND_File_ReadCallback_456CA4 = 0;
    FSOUND_File_SeekCallback_456CA8 = 0;
    FSOUND_File_TellCallback_456CAC = 0;
  }
  return result;
}

//----- (0043F720) --------------------------------------------------------
FSOUND_FILE_HANDLE * FSOUND_File_Open_43F720(int size,char *data, signed char type, int length)
//void *__cdecl sub_43F720(int soundEffectSize, char a2, int a3)
{

	void *result; // eax@2
  FSOUND_FILE_HANDLE *handle;

  void *v3 = calloc(0x18u, 1u); // esi@1
  handle = calloc(0x18u, 1u);
  result = handle;
  handle->type = type;
  handle->length = length;
  handle->userhandle = FSOUND_File_OpenCallback_43AD80(size,data);
  //handle->userhandle = data;
  if (!handle->userhandle)
	{
		free(handle);
		result = 0;
		
	}
  return result;
}
// 456C9C: using guessed type int (__cdecl *dword_456C9C)(_DWORD);

//----- (0043F770) --------------------------------------------------------
void __cdecl FSOUND_File_Close_43F770(FSOUND_FILE_HANDLE *handle)
{
 /* if ( handle )
  {
	  FSOUND_File_CloseCallback_43ADD0(*((_DWORD *)handle + 4));
 //   dword_456CA0(*((_DWORD *)Memory + 4));
    free(Memory);
  }*/
  
  if (!handle) 
	{
		return;
	}

	FSOUND_File_CloseCallback_43ADD0(handle->userhandle);
	//FSOUND_Memory_Free(handle);
	free(handle);
  
}
// 456CA0: using guessed type int (__cdecl *dword_456CA0)(_DWORD);

//----- (0043F790) --------------------------------------------------------
int __cdecl FSOUND_File_Read_43F790(void *buffer, int size, FSOUND_FILE_HANDLE *handle)
{
  int result; // eax@1

  result = handle;
  if ( handle )
	  return FSOUND_File_ReadCallback_456CA4(buffer, size, handle->userhandle);
	 // result = sub_43ADF0(a1, a2, *(_DWORD *)(a3 + 16));
	  
   // result = FSOUND_File_ReadCallback_456CA4(a1, a2, *(_DWORD *)(a3 + 16));
  
  return result;
}
// 456CA4: using guessed type int (__cdecl *FSOUND_File_ReadCallback_456CA4)(_DWORD, _DWORD, _DWORD);

//----- (0043F7B0) --------------------------------------------------------
int __cdecl FSOUND_File_Seek_43F7B0(FSOUND_FILE_HANDLE *handle)
{
  int result; // eax@1

  //result =handle;
  if ( handle )
	  result = FSOUND_File_SeekCallback_43AE30(handle->userhandle,0,1);//puesto a uno porque sino lee mal
	//TODO FIX result = dword_456CA8(*(_DWORD *)(a1 + 16));
  return result;
}
// 456CA8: using guessed type int (__cdecl *dword_456CA8)(_DWORD);

//----- (0043F7D0) --------------------------------------------------------
int __cdecl FSOUND_File_Tell_43F7D0(FSOUND_FILE_HANDLE *handle)
{
  int result; // eax@1

  //result = handle;
  if ( handle )
	  result = FSOUND_File_TellCallback_43AE70(handle->userhandle);
 //   result = dword_456CAC(*(_DWORD *)(a1 + 16));
  return result;
}
// 456CAC: using guessed type int (__cdecl *dword_456CAC)(_DWORD);