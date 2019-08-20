#ifndef _NO_MINIFMOD


	#include "minifmod/Sound.h"
	#include "minifmod/Music.h"
	#include "minifmod/minifmod.h"

	#include "minifmod/Mixer.h"
	#include "minifmod/mixer_clipcopy.h"
	#include "minifmod/mixer_fpu_ramp.h"
	#include "minifmod/music_formatxm.h"
#endif



#include "fmod.h"
#include "../defs.h"

#ifndef _NO_MINIFMOD
	char   FMUSIC_StopSong_43D8E0(FMUSIC_MODULE* mod);
	char   FMUSIC_FreeSong_43D940(FMUSIC_MODULE *mod);
	char   FMUSIC_PlaySong_43DA40(FMUSIC_MODULE* musicModuleModified_456C24);
	int   FMUSIC_LoadSong_43DC50(int a1, int a2);
	int   FSOUND_Software_Fill_43DCB0(signed int a1, int a2);
	int   FSOUND_MixerClipCopy_Float32_43DE30(void *dest, void *src, long len);
	//int __usercall FSOUND_Mixer_FPU_Ramp_43DEA0_43DEA0@<eax>(int a1@<ebp>);
	char   FMUSIC_XM_InstrumentVibrato_43E550(FMUSIC_CHANNEL *cptr, FMUSIC_INSTRUMENT *iptr);
	char   FMUSIC_XM_ProcessEnvelope_43E670(FMUSIC_CHANNEL *cptr, int *pos, int *tick, unsigned char type, int numpoints, unsigned short *points, unsigned char loopend, unsigned char loopstart, unsigned char sustain, int *value, int *valfrac, signed char *envstopped, int *envdelta, unsigned char control);
	char   FMUSIC_XM_ProcessVolumeByte_43E7A0(FMUSIC_CHANNEL *cptr, unsigned char volume);
	int   FMUSIC_XM_UpdateFlags_43E8C0(FMUSIC_CHANNEL *cptr, FSOUND_SAMPLE *sptr, FMUSIC_MODULE *mod);
	int   FMUSIC_XM_Resetcptr_43EB10(FMUSIC_CHANNEL *cptr, FSOUND_SAMPLE	*sptr);
	char   sub_43EBB0(int channelId, unsigned __int8 a2);
	unsigned __int64   sub_43EBD0(int channelId, signed int a2);
	int   FMUSIC_UpdateXMNote_43EC40(FMUSIC_MODULE *mod, int channelId, unsigned __int8 soundId, int a4, char volume);
	int   FMUSIC_UpdateXM_Effects_43EDC0(int a1);
	int   FMUSIC_UpdateXM_43EF50(FMUSIC_MODULE *mod); // weak
	char   FMUSIC_LoadXM_43EF60(FMUSIC_MODULE *mod, FSOUND_FILE_HANDLE *fp);


	int (  *  FSOUND_File_SetCallbacks_43F6B0(int (  *a1)(_DWORD), int (  *a2)(_DWORD), int (  *a3)(_DWORD, _DWORD, _DWORD), int (  *a4)(_DWORD), int (  *a5)(_DWORD)))(_DWORD);
	FSOUND_FILE_HANDLE * FSOUND_File_Open_43F720(int size, void *data, signed char type, int length);
	void   FSOUND_File_Close_43F770(FSOUND_FILE_HANDLE *handle);
	int   FSOUND_File_Read_43F790(void *buffer, int size, FSOUND_FILE_HANDLE *handle);
	int   FSOUND_File_Seek_43F7B0(int a1);
	int   FSOUND_File_Tell_43F7D0(FSOUND_FILE_HANDLE *handle);


	void *  FSOUND_File_OpenCallback_43AD80(int size,char *name);
	void   FSOUND_File_CloseCallback_43ADD0(unsigned int handle);
	int   FSOUND_File_ReadCallback_43ADF0(void *buffer, int size, unsigned int handle);
	int   FSOUND_File_SeekCallback_43AE30(unsigned int handle, int pos, signed char mode);
	int   FSOUND_File_TellCallback_43AE70(unsigned int handle);


	typedef struct struct_userhandle
	{
		int		size;
		int		pos;
		char*   data;
	
	} struct_userhandle;
#endif