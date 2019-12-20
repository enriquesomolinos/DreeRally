//#include "fmod.h"
//#include "system_file.h"
//#include "Music.h"

#include "minifmod/soundSystem.h"

extern int effectVolume_456A2C;

int   getSizeMusic(char * music);
 void *  getMusicStream(char* musicName);

 int   sub_43C1B0(unsigned __int8 a1, int a2, signed int a3);
int sub_43C1F0();
char __stdcall sub_43C220(int a1, int a2, signed int a3, int a4);
int   musicSetVolume(signed int a1);
int   musicSetmusicVolume(signed int a1);
int   setMusicVolume(signed int a1);
char   musicSetOrder(signed int a1);

int musicPlayMusic();
int   loadMenuSoundEffect(unsigned __int8 a1, char a2, int a3, int a4, int a5);

#ifndef _NO_MINIFMOD
	unsigned __int64   FMUSIC_SetBPM_43D8A0(FMUSIC_MODULE *mod_456C24, int bpm);
#endif
int stopSong();
int   stopSoundChannel_43C3E0(unsigned __int8 a1);
int stopAndOpenMusic();
int freeMusic();
void   loadMusic(int a1, char* music1, int a3, char* music2);

