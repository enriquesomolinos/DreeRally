#include "loadSaveGameScreen.h"
#include <SDL_stdinc.h>
#include "../savegame.h"
#include "blackMarketScreen.h"
#include "util/menus.h"
#include "../imageUtil.h"
#include "../config.h"
#include "../defs.h"
#include "../drivers.h"
#include "../dr.h"
#include "../graphics.h"
#include "util/input.h"
#include "util/popup.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_UNKNOWN unk_446C32; // weak
BYTE unk_4455B0[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

void *Str; // idb
int dword_443D18 = 1953525061; // weak
char loadSaveScreenaStartANewGam_0[17] = "Start A New Game"; // weak
char loadSaveScreenaStartRacing[13] = "Start Racing"; // weak
//----- (0042F2E0) --------------------------------------------------------
signed int loadGame()
{
  int v0; // ebp@1-
  int v1; // ebx@1
  unsigned int v2; // eax@2
//  void *v3; // edi@2
//  char v4; // cl@3
  signed int v5; // eax@8
  int v6; // esi@8
  char v7; // bl@8
  void *v9 = malloc(0x883u); // eax@17
  int v10; // edi@17

  int savegameEnabled[10];
  int v19;
  //  unsigned int v11; // eax@17
//  void *v12; // edi@17
//  char v13; // cl@18
  FILE *v14; // esi@19
  unsigned int v15; // ebx@19
  int v16; // edi@21
  int v17; // esi@21
  char *DstBuf =malloc(32); // [sp+10h] [bp-1Ch]@2
 
//  char v20; // [sp+1Bh] [bp-11h]@2
  char Filename[32]; // [sp+1Ch] [bp-10h]@2

  v0 = 0;
  v1 = (int)&unk_446C32;
  do
  {
    *(_DWORD *)v1 = 1953525061; //Empty slot
    *(_DWORD *)(v1 + 4) = 1817387129;
    *(_WORD *)(v1 + 8) = 29807;
    *(BYTE *)(v1 + 10) = 0;
    menuActive_4457F0[45+v0] = 1;
    strcpy(Filename, "DR.SG");
    SDL_itoa(v0, DstBuf, 10);
	//v2 = strlen(DstBuf) + 1;
   /* v3 = &v20;
    do
    {
      v4 = *((BYTE *)v3 + 1);
      v3 = (char *)v3 + 1;
    }
    while ( v4 );
    memcpy(v3, &DstBuf, v2);*/
   savegameEnabled[ v0] = 0;
	strcat(Filename, DstBuf);
	
    if ( (signed int)fileExists(Filename)> 0 )
    {
		savegameEnabled[v0] = 1;
      decryptEntireSavegame(v1, Filename);
    }
    v1 += 50;
    ++v0;
  }
  //while ( v1 < (signed int)&unk_446DC2 );
  while ( v0 < savegames_unk_446DC2 );

    

	
  while ( 1 )
  {
    memcpy((char *)screenBuffer + 67200, (char *)graphicsGeneral.menubg5Bpk + 67200, 0x28F00u);
    drawMenu(INITIAL_MENU, 0);
    drawMenu(START_NEW_GAME_MENU, 0);
    drawMenu(5, 1);
    refreshAllScreen();
    v5 = readEventInMenu(5);
    v6 = v5;
    v7 = savegameEnabled[ v5];
    if ( !v7 && v5 != -1 )
      loadMenuSoundEffect(1u, 29, 0, configuration.effectsVolume, dword_4451A4);
    if ( v6 >= 0 && v6 <= 7 && v7 == 1 )
      break;
    if ( v6 == -1 )
      return 0;
  }

  if ( v6 < 0 )
    return 0;
  *(_DWORD *)loadSaveScreenaStartANewGam_0 = 1702129221;
  *(_DWORD *)&loadSaveScreenaStartANewGam_0[4] = 1750343794;
  *(_DWORD *)&loadSaveScreenaStartANewGam_0[8] = 1750278245;
  *(_WORD *)&loadSaveScreenaStartANewGam_0[12] = 28783;
  loadSaveScreenaStartANewGam_0[14] = 0;
  *(_DWORD *)loadSaveScreenaStartRacing = 1953394499;
  menuActive_4457F0[1] = 0;
  menuActive_4457F0[10] = 1;
  menuActive_4457F0[11] = 1;
  menuActive_4457F0[13] = 1;
  *(_DWORD *)&loadSaveScreenaStartRacing[4] = 1702194793;
  *(_DWORD *)&loadSaveScreenaStartRacing[8] = 1667322400;
  *(_DWORD *)&loadSaveScreenaStartRacing[12] = 6778473;
  showHardWarningRace = 0;
  showMediumWarningRace = 0;
  showUndergroundPopup_456B78 = 0;
  showWelcomePopup_456B74 = 0;
  firstRacePlayed_464F44 = 0;
  useHasMorePoints_456BC4 = 0;
  //allocateMemory(0x883u);
  Str = v9;
  memset(v9, 0, 0x880u);
  v10 = (int)((char *)v9 + 2176);
  *(_WORD *)v10 = 0;
  *(BYTE *)(v10 + 2) = 0;
  strcpy(Filename, "DR.SG");
  SDL_itoa(v6, DstBuf, 10);
  /*v11 = strlen(&DstBuf) + 1;
  v12 = &v20;
  do
  {
    v13 = *((BYTE *)v12 + 1);
    v12 = (char *)v12 + 1;
  }
  while ( v13 );
  memcpy(v12, &DstBuf, v11);*/
  strcat(Filename, DstBuf);
  v14 = fopen(Filename, "rb");
  fread(Str, 0x883u, 1u, v14);
  fclose(v14);
  v19 = *(BYTE *)Str;
  v15 = 1;
  do
  {
	  decryptByteSavegame((int)((char *)Str + v15), v15 % 6);
    //decryptByteSavegame((int)((char *)Str + v15), v15 % 6);
    *((BYTE *)Str + v15) += -17 * v15;
    *((BYTE *)Str + v15++) += v19;
  }
  while ( (signed int)v15 < 2179 );

  driverId = *((BYTE *)Str + 1);
  useWeapons = *((BYTE *)Str + 2);
  configuration.difficulty = *((BYTE *)Str + 3);
  memcpy(drivers, (char *)Str + 19, 0x870u);
  free(Str);
  v16 = drivers[driverId].spikes;
  v17 = drivers[driverId].rocket;
  minesAvailable_45EFF0 = drivers[driverId].mines != 8;
  spikesAvailable_45EFF4 = v16 != 1;
  rocketAvailable_45EFF8 = v17 != 1;
  sabotageAvailable_45EFFC = drivers[driverId].sabotage != 1;
  confirmationPopup("Game Loaded.");
 
  
  return 1;
}

//----- (0042F6E0) --------------------------------------------------------
__int16 savegameWithName()
{
  int v0; // ebx@1
  int v1; // ebp@1
//  unsigned int v2; // eax@2
//  char *v3; // edi@2
//  char v4; // cl@3
  signed int v5; // eax@8
  int v6; // ebp@8
  char *v7; // eax@10
  char *v8; // edx@11
  char v9; // cl@12
  void *v10 = malloc(0x883u); // eax@19
  int v11; // edi@19
  int v12; // eax@19
  int v13; // edx@19
  unsigned int v14; // esi@19
  char *v15; // eax@19
  char v16; // cl@20
  unsigned int v17; // ebx@23
//  unsigned int v18; // eax@26
//  char *v19; // edi@26
//  char v20; // cl@27
  FILE *v21; // esi@28
  char *DstBuf=malloc(100); // [sp+10h] [bp-2Ch]@2
  int v24; // [sp+14h] [bp-28h]@19
  int v25; // [sp+18h] [bp-24h]@2
  char Filename[8]; // [sp+1Ch] [bp-20h]@2
  char v27[16]; // [sp+2Ch] [bp-10h]@11

  v0 = 0;
  v1 = (int)&unk_446C32;
  do
  {
    *(_DWORD *)v1 = 1953525061; //EMPTY slot
    *(_DWORD *)(v1 + 4) = 1817387129;
    *(_WORD *)(v1 + 8) = 29807;
    *(BYTE *)(v1 + 10) = 0;
	menuActive_4457F0[45+v0] = 1;
    strcpy(Filename, "DR.SG");
    SDL_itoa(v0, DstBuf, 10);
   /* v2 = strlen(&DstBuf) + 1;
    v3 = (char *)&v25 + 3;
    do
      v4 = (v3++)[1];
    while ( v4 );
    memcpy(v3, &DstBuf, v2);*/
	strcat(Filename, DstBuf);
    if ( (signed int)fileExists(Filename) > 0 )
      decryptEntireSavegame(v1, Filename);
    v1 += 50;
    ++v0;
  }
 // while ( v1 < (signed int)&unk_446DC2 );
  while ( v0 < savegames_unk_446DC2 );
  
  while ( 1 )
  {
    memcpy((char *)screenBuffer + 67200, (char *)graphicsGeneral.menubg5Bpk + 67200, 0x28F00u);
    drawMenu(INITIAL_MENU, 0);
    drawMenu(START_NEW_GAME_MENU, 0);
    drawMenu(5, 1);
    refreshAllScreen();
    v5 = readEventInMenu(5);
    v6 = v5;
    if ( v5 >= 0 && v5 <= 7 )
    {
      drawMenu(5, 0);
      createPopup(120, 275, 390, 70, 1);
      drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Enter the name of save game?", 180610);
      refreshAllScreen();
      v7 = (char *)&unk_446C32 + 50 * v6;
      if ( !memcmp((char *)&unk_446C32 + 50 * v6, &dword_443D18, 0xBu) )
      {
        v27[0] = 0;
      }
      else
      {
        v8 = (char *)(v27 - v7);
        do
        {
          v9 = *v7;
          v7[(_DWORD)v8] = *v7;
          ++v7;
        }
        while ( v9 );
      }
      v5 = readKeyboard(v27, 130, 298, (int)&unk_4455B0, 0xFu, 320, 1, 1, 0);
      if ( v5 )
        break;
    }
    if ( v6 == -1 )
      return v5;
  }
  if ( v6 >= 0 )
  {
   // allocateMemory(0x883u);
    Str = v10;
    memset(v10, 0, 0x880u);
    v11 = (int)((char *)v10 + 2176);
    *(_WORD *)v11 = 0;
    *(BYTE *)(v11 + 2) = 0;
    v12 = rand();
    v13 = v12 % 255;
    v14 = 0;
    *(BYTE *)Str = v12 % 255;
    *((BYTE *)Str + 1) = driverId;
    *((BYTE *)Str + 2) = useWeapons;
    *((BYTE *)Str + 3) = configuration.difficulty;
    v15 = v27;
    v24 = v13;
    do
      v16 = *v15++;
    while ( v16 );
   // v25 = v15 - &v27[1];
    if ( v15 != &v27[1] )
    {
      do
      {
        *((BYTE *)Str + v14 + 4) = v27[v14];
        ++v14;
      }
      while ( v14 < strlen(v27) );
    }

    memcpy((char *)Str + 19, drivers, 0x870u);
    v17 = 1;
    while ( 1 )
    {
      *((BYTE *)Str + v17) -= v13;
      *((BYTE *)Str + v17) += 17 * v17;
      encryptByteSavegame((int)((char *)Str + v17), v17 % 6);
      ++v17;
      if ( (signed int)v17 >= 2179 )
        break;
      LOBYTE(v13) = v24;
    }
    strcpy(Filename, "DR.SG");
    SDL_itoa(v6, DstBuf, 10);
    /*v18 = strlen(&DstBuf) + 1;
    v19 = (char *)&v25 + 3;
    do
      v20 = (v19++)[1];
    while ( v20 );
    memcpy(v19, &DstBuf, v18);*/
	strcat(Filename, DstBuf);
    v21 = fopen(Filename, "wb");
    fwrite(Str, 0x883u, 1u, v21);
    fclose(v21);
    free(Str);
    drawMenu(INITIAL_MENU, 0);
    drawMenu(START_NEW_GAME_MENU, 0);
    drawMenu(5, 0);
    confirmationPopup("Game Saved.");
   
  }
  return v5;
}
