#include "sound.h"
#include "../asset/bpaUtil.h"
#include "stdlib.h"

#include "../config.h"


#define FSOUND_LOOP_NORMAL   0x00000002  /* For forward looping samples. */
FMUSIC_MODULE *musicModule = NULL; // weak
	
FSOUND_STREAM *soundStream = NULL; // weak

int channel_456C10 = 0; // weak

//esto es para la muscia
int dword_45E1E0[400u]; // weak
int dword_45E5E0; // weak
int dword_45E5E4; // weak
int effectVolume_456A2C = 255; // weak
int musicVolume_456A30 = 255; // weak
int volumeMask_456A34 = 255; // weak
FMUSIC_MODULE *musicModuleModified_456C24 = NULL; // idb
int musicOrder_45DC60[400u]; // weak

int   getSizeMusic(char * music)
{
  return getFileSizeFromBpa("MUSICS.BPA", music);
}

void *  getMusicStream(char* musicName)
{
  size_t v1; // eax@1
  unsigned int v2; // edi@1
//  int v3; // eax@1
  char *fileContent; // ebp@1
  unsigned int filePos; // ebx@1
  int v6; // esi@2
  char a1;
  int a2;
  int result;
//  char v7; // dl@2

  v1 = getFileSizeFromBpa("MUSICS.BPA", musicName);
  v2 = v1;
  fileContent = malloc(v1);
  	//TODO correct
  //operator delete(v1);
  
  //fileContent = &v3;
  
   extractFromBpa("MUSICS.BPA", fileContent, musicName);
  filePos = 0;
  if ( v2 )
  {
    do
    {
		if (filePos ==69) {
			int z = 0;
		}
		v6 = (BYTE)fileContent[filePos];
		 a1 = v6;
		 a2 = filePos % 7;
		 result = (BYTE)a1 << a2;
		v6 = result | (BYTE)a1 >> (8 - a2);
		v6 = -109 - (17 * filePos) + (BYTE)v6;
		v6 = (BYTE)v6;
		
		fileContent[filePos] = v6;
		++filePos;

    }
    while (filePos < v2 );
  }
  return fileContent;
}
/*---------------------*/

int   sub_43C1B0(unsigned __int8 channelNumber, int a2, signed int a3)
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  if ( !mainArgs.configNoSound )
  {
	#ifndef _NO_MINIFMOD
		sub_43EBB0(channelNumber - 1, (a2 << 6 >> 16) + 16);
		result = sub_43EBD0((unsigned int)channelNumber - 1, a3);
	#endif
  }
  return result;
}

int sub_43C1F0()
{
  int result; // eax@2

  if ( mainArgs.configNoSound )
    result = 0;
  else
    result = dword_45E1E0[FMUSIC_GetOrder(musicModule)] << 8;
  return result;
}

char __stdcall sub_43C220(int a1, int a2, signed int a3, int a4)//void streamcallback(FSOUND_STREAM *stream, void *buff, int len, int param) 
{
  if ( !mainArgs.configNoSound )
	  #ifndef _NO_MINIFMOD
			FSOUND_Software_Fill_43DCB0(a3 / 4, a2);
		#endif
  return 1;
}

//----- (0043C250) --------------------------------------------------------
int   musicSetVolume(signed int a1)
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  if ( !mainArgs.configNoSound )
  {
	  effectVolume_456A2C = a1 >> 8;
    result = FSOUND_SetVolume(channel_456C10, (a1 >> 8) * volumeMask_456A34 >> 8);
  }
  return result;
}

//----- (0043C280) --------------------------------------------------------
int   musicSetmusicVolume(signed int a1)
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  if ( !mainArgs.configNoSound )
  {
	  musicVolume_456A30 = a1 >> 8;
     //TODO
    // result = FMUSIC_SetmusicVolume((a1 >> 8) * volumeMask_456A34 >> 9, dword_456C08, (a1 >> 8) * volumeMask_456A34 >> 9);
    result = FMUSIC_SetMasterVolume(musicModule, (a1 >> 8) * volumeMask_456A34 >> 9);
  }
  return result;
}

//----- (0043C2B0) --------------------------------------------------------
int   setMusicVolume(signed int a1)
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  volumeMask_456A34 = a1 >> 8;
  if ( !mainArgs.configNoSound )
  {
	  musicVolume_456A30 = musicVolume_456A30 << 8 >> 8;
    FMUSIC_SetMasterVolume(musicModule, (a1 >> 8) * musicVolume_456A30 >> 9);
    //TODO
     //FMUSIC_SetmusicVolume(a1 >> 8, musicModule, (a1 >> 8) * musicVolume_456A30 >> 9);
    result = mainArgs.configNoSound;
    if ( !mainArgs.configNoSound )
    {
		effectVolume_456A2C = effectVolume_456A2C << 8 >> 8;
      result = FSOUND_SetVolume(channel_456C10, volumeMask_456A34 * effectVolume_456A2C >> 8);
    }
  }
  return result;
}

//----- (0043C320) --------------------------------------------------------
char   musicSetOrder(signed int a1)
{
  if ( !mainArgs.configNoSound )
    FMUSIC_SetOrder(musicModule, (a1 >> 8) - musicOrder_45DC60[a1 >> 8]);
  return 0;
}

//----- (0043C360) --------------------------------------------------------
int musicPlayMusic()
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  if ( !mainArgs.configNoSound )
    result = FMUSIC_PlaySong(musicModule);
  return result;
}

//----- (0043C380) --------------------------------------------------------
int   loadMenuSoundEffect(unsigned __int8 channelNumber, char soundNumber, int a3, int a4, int a5) 
//  loadMenuSoundEffect(2u, 23, 0, 62720, dword_44518C - 28672)
// indice del fichero, numero de entrada
{
	//a1 es el fichero 
	//a2 es el indice del sonido
  int result; // eax@1

  result = mainArgs.configNoSoundEffect;
  if ( mainArgs.configNoSoundEffect)	
	#ifndef _NO_MINIFMOD
	    result = FMUSIC_UpdateXMNote_43EC40(musicModuleModified_456C24, channelNumber - 1, soundNumber - 1, a5, (a4 << 6 >> 16) + 16);
	#endif

  return result;
}
// 456C04: using guessed type int configNoSound;

//----- (0043C3C0) --------------------------------------------------------
int stopSong()
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  if ( !mainArgs.configNoSound )
    result = FMUSIC_StopSong(musicModule);
  return result;
}

//----- (0043C3E0) --------------------------------------------------------
int   stopSoundChannel_43C3E0(unsigned __int8 a1)
{

  #ifndef _NO_MINIFMOD
	  int result; // eax@1
	  FSOUND_CHANNEL *ccptr;
	  result = mainArgs.configNoSound;
	  if ( !mainArgs.configNoSound )
	  {
		//result = &FSOUND_Channel[43 * (a1 - 1)];
		//result = dword_45C4E4[43 * (a1 - 1)]; //cambiado porque tiene la direccion de memoria
		ccptr = &FSOUND_Channel[(a1 - 1)];
		ccptr->mixposlo = 0;
		ccptr->mixpos = 0;
		ccptr->sptr = NULL;
		ccptr->sampleoffset = 0;
		/**(_DWORD *)(result + 44) = 0;
		*(_DWORD *)(result + 40) = 0;
		*(_DWORD *)(result + 28) = 0;
		*(_DWORD *)(result + 24) = 0;*/
	
	  }
	  return ccptr;
	#endif
}

//----- (0043C400) --------------------------------------------------------
int stopAndOpenMusic()
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  if ( !mainArgs.configNoSound )
  {
    FSOUND_Stream_Stop(soundStream);
    FSOUND_Stream_Close(soundStream);
	#ifndef _NO_MINIFMOD
	 FMUSIC_FreeSong_43D940(musicModuleModified_456C24);
	 result = FMUSIC_FreeSong_43D940(musicModule);
	#endif
	musicModule = NULL;
    musicModuleModified_456C24 = 0;
  }
  return result;
}

//----- (0043C4D0) --------------------------------------------------------
int freeMusic()
{
  int result; // eax@1

  result = mainArgs.configNoSound;
  if ( !mainArgs.configNoSound )
  //TODO
	result = 0;
    //result = FSOUND_Close();
  return result;
}

//----- (0043CBF0) --------------------------------------------------------
void   loadMusic(int a1, char * music1, int a3, char* soundEffect)
{
	char *musicStream = NULL; // esi@1
	char *soundEffectStream = NULL; // ebx@1
	int musicSize; // eax@2
	FMUSIC_MODULE *music_module; // ebp@2
	int v8; // eax@2
	int v9; // edx@2
	int v10; // ecx@2
	int channel; // eax@8
	int soundEffectSize; // [sp+Ch] [bp-8h]@8
	FSOUND_STREAM *sound_stream; // eax@8
	
	if (!mainArgs.configNoSound)
	{
		musicSize = getSizeMusic(music1);
		musicStream = malloc(musicSize);
		soundEffectSize = getSizeMusic(soundEffect);
		soundEffectStream = malloc(soundEffectSize);

		soundEffectStream = getMusicStream(soundEffect);
		
		musicStream = getMusicStream(music1);
		volumeMask_456A34 = 255;

		music_module = FMUSIC_LoadSongEx(musicStream, 0, musicSize, FSOUND_LOOP_NORMAL | FSOUND_LOADMEMORY, 0, 0); //32770
		v8 = 0;
		memset(musicOrder_45DC60, 0, 0x400u);
		musicModule = music_module;
		//16*4 bytes son la cabecera
		//esto lee las pistas que hay en los ficheros de musica
		v9 = *((_WORD *)musicStream + 16);
		v10 = 0;
		if (v9 > 0)
		{
			do
			{
				//96 es 60h huele a que son los instrumentos del xm
				if (*((BYTE *)musicStream + v8 + 96) >= 0xFEu)
					++v10;
				musicOrder_45DC60[v8] = v10;
				dword_45E1E0[v8] = v8 + v10;
				++v8;
			} while (v8 < v9);
		}
		if (!mainArgs.configNoSound)
		{
			musicVolume_456A30 = musicVolume_456A30 << 8 >> 8;
			//TODO
			//FMUSIC_SetmusicVolume(v10, music_module, volumeMask_456A34 * musicVolume_456A30 >> 9);
			FMUSIC_SetMasterVolume(music_module, volumeMask_456A34 * musicVolume_456A30 >> 9);
		}

		if (mainArgs.configNoSoundEffect) {
			//musicModuleModified_456C24 = (void *)FMUSIC_LoadSong_43DC50((int)&v13, 0);
			#ifndef _NO_MINIFMOD

				musicModuleModified_456C24 = FMUSIC_LoadSong_43DC50(soundEffectSize,soundEffectStream, 0);
			//	musicModuleModified_456C24 = (void *)FMUSIC_LoadSong_43DC50(soundEffectStream, 0);
			

				FMUSIC_PlaySong_43DA40(musicModuleModified_456C24);
				sound_stream = FSOUND_Stream_Create(sub_43C220, 4096, FSOUND_UNSIGNED, 44100, 0); //int length,unsigned int mode 80,int samplerate,int userdata
				soundStream = sound_stream;
				channel = FSOUND_Stream_Play(-1, sound_stream);
				channel_456C10 = channel;
				if (!mainArgs.configNoSound)
				{
					effectVolume_456A2C = effectVolume_456A2C << 8 >> 8;
					FSOUND_SetVolume(channel, volumeMask_456A34 * effectVolume_456A2C >> 8);
				}
			#endif
		}
		//free(musicStream);
		//free(soundEffectStream);
	}
}
