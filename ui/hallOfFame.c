
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../defs.h"

#include "../graphics.h"
#include "hallOfFame.h"
#include "../drivers.h"
#include "../cars.h"
#include "../imageUtil.h"
#include "util/menus.h"

#include "../config.h"
#include "../dr.h"
#include "../circuit.h"
#include <SDL_stdinc.h>



int dword_461FD4; // weak
int dword_461F30[256]; //weak

int dword_461F2C[256]; // weak

extern char  unk_445928[];
extern int dword_45FC00; // wea
extern  int dword_461250; // weak
extern  int dword_462D7C; // weak

extern _UNKNOWN unk_45F8B0; // weak
extern _UNKNOWN unk_45F8BC; // weak

extern char aDeliverator[12] = "Deliverator"; // weak

char byte_456618[] = { 'A' }; // weak
char byte_45665E[] = { 'S' }; // weak
char byte_4566A4[] = { 'f' }; // weak
char byte_4566EA[] = { 'k' }; // weak


//----- (00431510) --------------------------------------------------------
int seeHallOfFame()
{
  int v0; // esi@1
  int v1; // ebp@2
  char *v2; // edi@2
  char v3; // al@3
  int v4; // edx@4
  int v5; // edi@7
  int *v6; // eax@7
//  char *v7; // edx@7
//  char v8; // cl@8
  int v9; // esi@9
  int v10; // eax@9
//  int v11; // eax@12
//  int v12; // eax@17
//  char *v13; // edx@17
//  char v14; // cl@18
  char *v15; // eax@19
  char v16; // al@21
  signed int v17; // ebx@25
  int result; // eax@26
  signed int v19; // esi@32
  signed int v20; // esi@38
  char v21; // [sp+Bh] [bp-29h]@2
  char DstBuf[40]; // [sp+Ch] [bp-28h]@2

  memcpy((void *)dword_45FC00, screenBuffer, 0x4B000u);
  screenBuffer = (void *)dword_45FC00;
  memcpy((void *)(dword_45FC00 + 67200), (char *)graphicsGeneral.menubg5Bpk + 67200, 0x28F00u);
  drawImageWithPosition((int)graphics2.fametxtBpk, 640, 54, (int)((char *)screenBuffer + 53760));
  v0 = 0;
  do
  {
    v1 = v0 + 1;
    SDL_itoa(v0 + 1, DstBuf, 10);
    v2 = &v21;
    do
      v3 = (v2++)[1];
    while ( v3 );
    v4 = (int)graphicsGeneral.fmed1aBpk;
    *(_WORD *)v2 = 46;
    if ( v0 == 9 )
		//rank
      drawTextWithFont(v4, (int)&unk_445928, DstBuf, 218908);
    else
      drawTextWithFont(v4, (int)&unk_445928, DstBuf, 14080 * v0 + 92196);
    v5 = 5 * v0;
    /*v6 = &configuration.hallOfFameEntries[v0];
    v7 = (char *)(DstBuf - (char *)v6);
    do
    {
      v8 = *(BYTE *)v6;
      *((BYTE *)v6 + (_DWORD)v7) = *(BYTE *)v6;
      v6 = (int *)((char *)v6 + 1);
    }
    while ( v8 );
    strupr(DstBuf);*/
    v9 = 14080 * v0;
	//driver
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, _strupr(configuration.hallOfFameEntries[v0].name), v9 + 92297);
    SDL_itoa(configuration.hallOfFameEntries[v0].races, DstBuf, 10);
    v10 = configuration.hallOfFameEntries[v0].races;
	//races
    if ( v10 >= 0 && v10 < 10 )
		
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v9 + 92504);
    if (v10 >= 10 && v10 < 100 )
		
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v9 + 92496);
    if (v10 >= 100 )
		
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v9 + 92488);
  
//coge el indice y suma digficultad
	/*v12 = 24 * dword_461F30[v5] + 4485952;
    v13 = &DstBuf[-v12];
    do
    {
      v14 = *(BYTE *)v12;
      v13[v12] = *(BYTE *)v12;
      ++v12;
    }
    while ( v14 );*/
	//dificulty
    v15 = getDifficultyText(configuration.hallOfFameEntries[v0].difficulty);
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, v15, v9 + 92589);
    v0 = v1;
  }
  while ( v1 < 10 );
  screenBuffer = (void *)dword_461250;
  sub_42C560(-1);

 //FIX ME LOWORD(dword_462D7C) = sub_43C1F0() & 0xFF00;

  dword_462D7C = (unsigned __int16)dword_462D7C;
  musicSetOrder(20736);
  setMusicVolume(0x10000);
  eventDetected();
  sub_418090();
  do
  {
    while ( 1 )
    {
      refreshAndCheckConnection_42A570();
      v16 = eventDetected();
      if ( v16 != 59 )
        break;
      if ( !isMultiplayerGame )
        goto LABEL_25;
      //multiplayer_sub_42CCF0();
    }
  }
  while ( !v16 );
LABEL_25:
  eventDetected();
  sub_418090();
  memcpy((void *)dword_45FC00, screenBuffer, 0x4B000u);
  screenBuffer = (void *)dword_45FC00;
  memcpy((void *)(dword_45FC00 + 53760), (char *)graphicsGeneral.menubg5Bpk + 53760, 0x2C380u);
  v17 = 0;
  drawImageWithPosition((int)graphics2.recotxtBpk, 640, 16, (int)((char *)screenBuffer + 58880));
  drawRecordByCircuit((unsigned __int8)circuitOrder_45673C[0]);
  drawImageWithPosition2(graphics2.trsnap2m1Bpk[circuitOrder_45673C[0]], 128, 98, (int)((char *)screenBuffer + 137000));
  //drawImageWithPosition2((int)*(&trsnap2m1Bpk + (unsigned __int8)circuitOrder_45673C[0]), 128, 98, (int)((char *)screenBuffer + 137000));
  drawImageWithPosition2((int)graphics2.trarr1Bpk, 16, 84, (int)((char *)screenBuffer + 145944));
  drawImageWithPosition2((int)((char *)graphics2.trarr1Bpk + 1344), 16, 84, (int)((char *)screenBuffer + 146088));
  drawBorder(15, 204, 178, 117);
  screenBuffer = (void *)dword_461250;
  sub_42C4A0();
  while ( 1 )
  {
    refreshAndCheckConnection_42A570();
    result = (unsigned __int8)eventDetected() - 1;
    switch ( result )
    {
      default:
        continue;
      case 58:
        //if ( isMultiplayerGame )
        //  multiplayer_sub_42CCF0();
        break;
      case 74:
      case 202://right
        if ( v17 <= 0 )
          v17 = 17;
        else
          --v17;
        loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
        drawImageWithPosition2((int)((char *)graphics2.trarr1Bpk + 2688), 16, 84, (int)((char *)screenBuffer + 145944));
        drawImageWithPosition2(
          graphics2.trsnap2m1Bpk[circuitOrder_45673C[v17]],
          128,
          98,
          (int)((char *)screenBuffer + 137000));
		/*drawImageWithPosition2(
			(int)*(&trsnap2m1Bpk + (unsigned __int8)circuitOrder_45673C[v17]),
			128,
			98,
			(int)((char *)screenBuffer + 137000));*/
        drawRecordByCircuit((unsigned __int8)circuitOrder_45673C[v17]);
        refreshAllScreen();
        v19 = 8;
        do
        {
          refreshAndCheckConnection_42A570();
          --v19;
        }
        while ( v19 );
        drawImageWithPosition2((int)graphics2.trarr1Bpk, 16, 84, (int)((char *)screenBuffer + 145944));
        refreshAllScreen();
        break;
      case 76://left
      case 204:
        if ( v17 >= 17 )
          v17 = 0;
        else
          ++v17;
        loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
        drawImageWithPosition2((int)((char *)graphics2.trarr1Bpk + 4032), 16, 84, (int)((char *)screenBuffer + 146088));
        drawImageWithPosition2(
          (int)graphics2.trsnap2m1Bpk[circuitOrder_45673C[v17]],
          128,
          98,
          (int)((char *)screenBuffer + 137000));
		/*drawImageWithPosition2(
			(int)*(&trsnap2m1Bpk + (unsigned __int8)circuitOrder_45673C[v17]),
			128,
			98,
			(int)((char *)screenBuffer + 137000));*/
        drawRecordByCircuit((unsigned __int8)circuitOrder_45673C[v17]);
        refreshAllScreen();
        v20 = 8;
        do
        {
          refreshAndCheckConnection_42A570();
          --v20;
        }
        while ( v20 );
        drawImageWithPosition2((int)((char *)graphics2.trarr1Bpk + 1344), 16, 84, (int)((char *)screenBuffer + 146088));
        refreshAllScreen();
        break;
      case 0://enter esc
      case 27:
      case 155:
        memcpy((void *)dword_45FC00, screenBuffer, 0x4B000u);
        screenBuffer = (void *)dword_45FC00;
        return result;
    }
  }
}

CircuitRecords* getDefaulRecords() {

	CircuitRecords* circuitRecords = malloc(sizeof(CircuitRecords) * 18 * 6);
	int i = 0;
	while (i < 18 * 6) {
		strcpy(circuitRecords[i].name, "REMEDY");
		circuitRecords[i].min=0;
		i++;
	}
	
	circuitRecords[SUBURBIA_CIRCUIT + VAGABOND].sec = 15;
	circuitRecords[ SUBURBIA_CIRCUIT + VAGABOND].cen = 55;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DERVISH].cen = 49;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SENTINEL].cen = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SHRIEKER].cen = 89;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * WRAITH].sec = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * WRAITH].cen = 22;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DELIVERATOR].sec = 11;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DELIVERATOR].cen = 36;

	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * VAGABOND].sec = 18;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * VAGABOND].cen = 16;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * DERVISH].sec = 17;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * DERVISH].cen = 8;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SENTINEL].sec = 16;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SENTINEL].cen = 23;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SHRIEKER].sec = 15;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SHRIEKER].cen = 52;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * WRAITH].sec = 14;
	circuitRecords[DOWNTOWN_CIRCUIT + 18 * WRAITH].cen = 51;
	circuitRecords[DOWNTOWN_CIRCUIT + 18 * DELIVERATOR].sec = 13;
	circuitRecords[DOWNTOWN_CIRCUIT + 18 * DELIVERATOR].cen = 36;

	circuitRecords[UTOPIA_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[UTOPIA_CIRCUIT + 18 * VAGABOND].cen = 89;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DERVISH].sec = 25;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DERVISH].cen = 85;
	circuitRecords[UTOPIA_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[UTOPIA_CIRCUIT + 18* SENTINEL].cen = 58;
	circuitRecords[UTOPIA_CIRCUIT + 18 * SHRIEKER].sec = 24;
	circuitRecords[UTOPIA_CIRCUIT + 18 * SHRIEKER].cen = 02;
	circuitRecords[UTOPIA_CIRCUIT + 18 * WRAITH].sec = 22;
	circuitRecords[UTOPIA_CIRCUIT + 18 * WRAITH].cen = 15;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DELIVERATOR].sec = 20;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DELIVERATOR].cen = 38;

	circuitRecords[ROCKZONE_CIRCUIT + 18 * VAGABOND].sec = 12;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * VAGABOND].cen = 83;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DERVISH].cen = 21;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SENTINEL].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SENTINEL].cen = 95;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SHRIEKER].cen = 88;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * WRAITH].cen = 2;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DELIVERATOR].cen = 42;

	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * VAGABOND].sec = 26;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * VAGABOND].cen = 79;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DERVISH].cen = 42;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SENTINEL].sec = 25;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SENTINEL].cen = 55;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SHRIEKER].sec = 24;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SHRIEKER].cen = 82;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * WRAITH].cen = 80;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DELIVERATOR].cen = 91;

	circuitRecords[OASIS_CIRCUIT + 18 * VAGABOND].sec = 13;
	circuitRecords[OASIS_CIRCUIT + 18 * VAGABOND].cen = 42;
	circuitRecords[OASIS_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[OASIS_CIRCUIT + 18 * DERVISH].cen = 81;
	circuitRecords[OASIS_CIRCUIT + 18 * SENTINEL].sec = 12;
	circuitRecords[OASIS_CIRCUIT + 18 * SENTINEL].cen = 01;
	circuitRecords[OASIS_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[OASIS_CIRCUIT + 18 * SHRIEKER].cen = 66;
	circuitRecords[OASIS_CIRCUIT + 18 * WRAITH].sec = 10;
	circuitRecords[OASIS_CIRCUIT + 18 * WRAITH].cen = 96;
	circuitRecords[OASIS_CIRCUIT + 18 * DELIVERATOR].sec = 9;
	circuitRecords[OASIS_CIRCUIT + 18 * DELIVERATOR].cen = 66;

	circuitRecords[VELODROME_CIRCUIT + 18 * VAGABOND].sec = 15;
	circuitRecords[VELODROME_CIRCUIT + 18 * VAGABOND].cen = 90;
	circuitRecords[VELODROME_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[VELODROME_CIRCUIT + 18 * DERVISH].cen = 89;
	circuitRecords[VELODROME_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[VELODROME_CIRCUIT + 18 * SENTINEL].cen = 0;
	circuitRecords[VELODROME_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[VELODROME_CIRCUIT + 18 * SHRIEKER].cen = 12;
	circuitRecords[VELODROME_CIRCUIT + 18 * WRAITH].sec = 12;
	circuitRecords[VELODROME_CIRCUIT + 18 * WRAITH].cen = 5;
	circuitRecords[VELODROME_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[VELODROME_CIRCUIT + 18 * DELIVERATOR].cen = 86;

	circuitRecords[HOLOCAUST_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * VAGABOND].cen = 80;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DERVISH].cen = 96;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SENTINEL].cen = 50;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SHRIEKER].sec = 22;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SHRIEKER].cen = 78;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * WRAITH].cen = 30;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DELIVERATOR].cen = 58;

	circuitRecords[BOGOTA_CIRCUIT + 18 * VAGABOND].sec = 17;
	circuitRecords[BOGOTA_CIRCUIT + 18 * VAGABOND].cen = 57;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DERVISH].sec = 16;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DERVISH].cen = 72;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SENTINEL].sec = 15;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SENTINEL].cen = 62;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SHRIEKER].sec = 14;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SHRIEKER].cen = 15;
	circuitRecords[BOGOTA_CIRCUIT + 18 * WRAITH].sec = 13;
	circuitRecords[BOGOTA_CIRCUIT + 18 * WRAITH].cen = 85;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DELIVERATOR].sec = 13;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DELIVERATOR].cen = 1;

	circuitRecords[WESTEND_CIRCUIT + 18 * VAGABOND].sec = 15;
	circuitRecords[WESTEND_CIRCUIT + 18 * VAGABOND].cen = 42;
	circuitRecords[WESTEND_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[WESTEND_CIRCUIT + 18 * DERVISH].cen = 63;
	circuitRecords[WESTEND_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[WESTEND_CIRCUIT + 18 * SENTINEL].cen = 1;
	circuitRecords[WESTEND_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[WESTEND_CIRCUIT + 18 * SHRIEKER].cen = 76;
	circuitRecords[WESTEND_CIRCUIT + 18 * WRAITH].sec = 13;
	circuitRecords[WESTEND_CIRCUIT + 18 * WRAITH].cen = 14;
	circuitRecords[WESTEND_CIRCUIT + 18 * DELIVERATOR].sec = 11;
	circuitRecords[WESTEND_CIRCUIT + 18 * DELIVERATOR].cen = 48;

	circuitRecords[NEWARK_CIRCUIT + 18 * VAGABOND].sec = 18;
	circuitRecords[NEWARK_CIRCUIT + 18 * VAGABOND].cen = 0;
	circuitRecords[NEWARK_CIRCUIT + 18 * DERVISH].sec = 16;
	circuitRecords[NEWARK_CIRCUIT + 18 * DERVISH].cen = 98;
	circuitRecords[NEWARK_CIRCUIT + 18 * SENTINEL].sec = 16;
	circuitRecords[NEWARK_CIRCUIT + 18 * SENTINEL].cen = 11;
	circuitRecords[NEWARK_CIRCUIT + 18 * SHRIEKER].sec = 15;
	circuitRecords[NEWARK_CIRCUIT + 18 * SHRIEKER].cen = 62;
	circuitRecords[NEWARK_CIRCUIT + 18 * WRAITH].sec = 14;
	circuitRecords[NEWARK_CIRCUIT + 18 * WRAITH].cen = 52;
	circuitRecords[NEWARK_CIRCUIT + 18 * DELIVERATOR].sec = 13;
	circuitRecords[NEWARK_CIRCUIT + 18 * DELIVERATOR].cen = 31;

	circuitRecords[COMPLEX_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[COMPLEX_CIRCUIT + 18 * VAGABOND].cen = 49;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DERVISH].sec = 25;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DERVISH].cen = 63;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SENTINEL].cen = 22;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SHRIEKER].sec = 23;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SHRIEKER].cen = 76;
	circuitRecords[COMPLEX_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[COMPLEX_CIRCUIT + 18 * WRAITH].cen = 91;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DELIVERATOR].sec = 20;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DELIVERATOR].cen = 25;

	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * VAGABOND].sec = 12;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * VAGABOND].cen = 68;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DERVISH].cen = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SENTINEL].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SENTINEL].cen = 98;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SHRIEKER].cen = 71;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * WRAITH].cen = 14;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DELIVERATOR].cen = 31;

	circuitRecords[DESERTRUN_CIRCUIT + 18 * VAGABOND].sec = 26;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * VAGABOND].cen = 82;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DERVISH].cen = 37;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SENTINEL].sec = 25;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SENTINEL].cen = 61;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SHRIEKER].sec = 24;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SHRIEKER].cen = 96;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * WRAITH].cen = 91;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DELIVERATOR].cen = 69;

	circuitRecords[PALMSIDE_CIRCUIT + 18 * VAGABOND].sec = 13;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * VAGABOND].cen = 36;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DERVISH].cen = 62;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SENTINEL].sec = 12;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SENTINEL].cen = 24;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SHRIEKER].cen = 71;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * WRAITH].cen = 8;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DELIVERATOR].sec = 9;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DELIVERATOR].cen = 81;

	circuitRecords[EIDOLON_CIRCUIT + 18 * VAGABOND].sec = 16;
	circuitRecords[EIDOLON_CIRCUIT + 18 * VAGABOND].cen = 8;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DERVISH].cen = 67;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SENTINEL].cen = 24;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SHRIEKER].cen = 1;
	circuitRecords[EIDOLON_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[EIDOLON_CIRCUIT + 18 * WRAITH].cen = 85;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DELIVERATOR].cen = 78;

	circuitRecords[TOXICDUMP_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * VAGABOND].cen = 98;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * DERVISH].cen = 82;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SENTINEL].cen = 62;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SHRIEKER].sec = 22;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SHRIEKER].cen = 57;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * WRAITH].cen = 33;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[TOXICDUMP_CIRCUIT + 18*DELIVERATOR].cen = 47;

	circuitRecords[BORNEO_CIRCUIT + VAGABOND * 18].sec = 17;
	circuitRecords[BORNEO_CIRCUIT + VAGABOND * 18].cen = 42;
	circuitRecords[BORNEO_CIRCUIT + DERVISH * 18].sec = 16;
	circuitRecords[BORNEO_CIRCUIT + DERVISH * 18].cen = 86;
	circuitRecords[BORNEO_CIRCUIT + SENTINEL * 18].sec = 15;
	circuitRecords[BORNEO_CIRCUIT + SENTINEL * 18].cen = 45;
	circuitRecords[BORNEO_CIRCUIT + SHRIEKER * 18].sec = 13;
	circuitRecords[BORNEO_CIRCUIT + SHRIEKER * 18].cen = 98;
	circuitRecords[BORNEO_CIRCUIT + WRAITH * 18].sec = 13;
	circuitRecords[BORNEO_CIRCUIT + WRAITH * 18].cen = 79;
	circuitRecords[BORNEO_CIRCUIT + DELIVERATOR * 18].sec = 12;
	circuitRecords[BORNEO_CIRCUIT + DELIVERATOR * 18].cen = 94;

	return circuitRecords;
}

HallOfFameEntry* getDefaultHallOfFame() {
	HallOfFameEntry* hallOfFameEntry =malloc(sizeof(HallOfFameEntry)*10);
	strcpy(hallOfFameEntry[0].name,"SAM SPEED");
	strcpy(hallOfFameEntry[1].name,"JANE HONDA");
	strcpy(hallOfFameEntry[2].name,"DUKE NUKEM");
	strcpy(hallOfFameEntry[3].name,"NASTY NICK");
	strcpy(hallOfFameEntry[4].name,"MOTOR MARY");
	strcpy(hallOfFameEntry[5].name,"MAD MAC");
	strcpy(hallOfFameEntry[6].name,"MATT MILLER");
	strcpy(hallOfFameEntry[7].name,"CLINT WEST");
	strcpy(hallOfFameEntry[8].name,"LEE VICE");
	strcpy(hallOfFameEntry[9].name,"DARK RIDER");
	
	hallOfFameEntry[0].races = 50;
	hallOfFameEntry[1].races = 66;
	hallOfFameEntry[2].races = 82;
	hallOfFameEntry[3].races = 98;
	hallOfFameEntry[4].races = 114;
	hallOfFameEntry[5].races = 130;
	hallOfFameEntry[6].races = 146;
	hallOfFameEntry[7].races = 162;
	hallOfFameEntry[8].races = 178;
	hallOfFameEntry[9].races = 194;

	hallOfFameEntry[0].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[1].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[2].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[3].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[4].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[5].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[6].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[7].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[8].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[9].difficulty = MEDIUM_DIFFICULTY;
	

	return hallOfFameEntry;
}

//----- (0041E490) --------------------------------------------------------
int   drawRecordByCircuit(int a1)
{
  signed int v1; // eax@1
  char *v2; // esi@2
  char *v3; // edi@2
  signed int v4; // eax@3
  char *v5; // esi@4
  char *v6; // edi@4
//  char *v7; // eax@5
//  char *v8; // edx@5
//  char v9; // cl@6
//  char *v10; // eax@7
  signed int v11; // ecx@7
  unsigned int v12; // esi@7
//  char v13; // dl@8
  signed int v14; // edx@11
  signed int v15; // esi@11
  int v16; // ebx@11
  char *v17; // ebp@11
//  int v18; // eax@13
//  char v19; // cl@14
//  int v20; // eax@15
//  char v21; // cl@16
//  int v22; // eax@23
//  char v23; // cl@24
//  char *v24; // edi@25
//  char v25; // al@26
//  unsigned int v26; // eax@27
//  char *v27; // edi@27
//  char v28; // cl@28
//  char *v29; // edi@29
//  char v30; // al@30
//  unsigned int v31; // eax@31
//  char *v32; // edi@31
//  char v33; // cl@32
  int v34; // edx@33
  bool v35; // zf@33
  int result; // eax@33
  int v37; // [sp+10h] [bp-5Ch]@11
  signed int v38; // [sp+14h] [bp-58h]@11
  int v39; // [sp+18h] [bp-54h]@11
  char Str[60]; // [sp+1Ch] [bp-50h]@5
  char *DstBuf = malloc(60); // [sp+30h] [bp-3Ch]@17
//  char v42; // [sp+31h] [bp-3Bh]@18
//  char v43; // [sp+32h] [bp-3Ah]@18
  char* v44=malloc(2); // [sp+44h] [bp-28h]@17
//  char v45; // [sp+45h] [bp-27h]@20
//  char v46; // [sp+46h] [bp-26h]@20
  char* v47 = malloc(2); // [sp+58h] [bp-14h]@17
//  char v48; // [sp+59h] [bp-13h]@22
//  char v49; // [sp+5Ah] [bp-12h]@22
  signed int v50; // [sp+70h] [bp+4h]@11
  char *name = malloc(20);
   int index = 5;
  v1 = 0;
  do
  {
    v2 = (char *)graphicsGeneral.menubg5Bpk + v1 + 85345;
    v3 = (char *)screenBuffer + v1 + 85345;
    memcpy(v3, v2, 0x17Cu);
    v1 += 640;
    v3[380] = v2[380];
  }
  while ( v1 < 18560 );
  v4 = 0;
  do
  {
    v5 = (char *)graphicsGeneral.menubg5Bpk + v4 + 132064;
    v6 = (char *)screenBuffer + v4 + 132064;
    v4 += 640;
    memcpy(v6, v5, 0x170u);
  }
  while ( v4 < 83200 );
  drawImageWithPosition((int)graphics2.recobarBpk, 640, 68, (int)((char *)screenBuffer + 84480));
  strcpy(Str, circuits[a1]);
  /*v8 = (char *)(Str - v7);
  do
  {
    v9 = *v7;
    v7[(_DWORD)v8] = *v7;
    ++v7;
  }
  while ( v9 );
  v10 = Str;
  v11 = 0;
  v12 = 0;
  do
    v13 = *v10++;
  while ( v13 );*/
  //if ( v10 != &Str[1] )
  //{
  v11 = 0;
  v12 = 0;
    do
	v11 += (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET + (unsigned __int8)Str[v12++]];
    while ( v12 < strlen(Str) );
  //}
	//escribe el circuito
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, Str, 87453 - (v11 >> 1));
  v14 = Str - aDeliverator;
  v15 = &Str[-24 * a1] - (char *)&unk_45F8B0;
  v16 = 133480;
  v37 = (int)aDeliverator;
  v17 = (char *)&unk_45F8BC + 24 * a1;
  v50 = Str - aDeliverator;
  v38 = v15;
  v39 = 6;
 
  while (index>-1)
  {
    /*v18 = v37;
    do
    {
      v19 = *(BYTE *)v18;
      *(BYTE *)(v18 + v14) = *(BYTE *)v18;
      ++v18;
    }
    while ( v19 );
	
    strupr(Str);*/
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, getCarName(index), v16 - 132);
    /*v20 = (int)(v17 - 12);
    do
    {
      v21 = *(BYTE *)v20;
      *(BYTE *)(v20 + v15) = *(BYTE *)v20;
      ++v20;
    }
    while ( v21 );
    strupr(Str);*/
	memset(name, "\0",strlen(name));
	strcpy(name, configuration.circuitRecords[a1  + index*18].name);
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, name, v16);
    SDL_itoa(configuration.circuitRecords[a1  + index*18].min, DstBuf, 10);
    SDL_itoa(configuration.circuitRecords[a1  + index*18].sec, v44, 10);
    SDL_itoa(configuration.circuitRecords[a1  + index*18].cen, v47, 10);
    /*if ( strlen(DstBuf) == 1 )
    {
      v42 = DstBuf;
      DstBuf = 48;
      v43 = 0;
    }
    if ( strlen(&v44) == 1 )
    {
      v45 = v44;
      v44 = 48;
      v46 = 0;
    }
    if ( strlen(&v47) == 1 )
    {
      v48 = v47;
      v47 = 48;
      v49 = 0;
    }
    v22 = 0;
    do
    {
      v23 = *(DstBuf + v22);
      Str[v22++] = v23;
    }
    while ( v23 );
    v24 = (char *)&v39 + 3;
    do
      v25 = (v24++)[1];
    while ( v25 );
    *(_WORD *)v24 = 58;
    v26 = strlen(&v44) + 1;
    v27 = (char *)&v39 + 3;
    do
      v28 = (v27++)[1];
    while ( v28 );
    memcpy(v27, &v44, v26);
    v29 = (char *)&v39 + 3;
    do
      v30 = (v29++)[1];
    while ( v30 );
    *(_WORD *)v29 = 46;
    v31 = strlen(&v47) + 1;
    v32 = (char *)&v39 + 3;
    do
      v33 = (v32++)[1];
    while ( v33 );
	memcpy(v32, &v47, v31);*/
    v34 = (int)graphicsGeneral.fmed1aBpk;
    
	
	memset(Str, "\0" ,strlen(Str));
	strcpy(Str, DstBuf);
	strcat(Str, ":");
	strcat(Str, v44);
	strcat(Str, ".");
	strcat(Str, v47);
    drawTextWithFont(v34, (int)&unk_445928, Str, v16 + 154);
    v17 -= 432;
    v16 += 14080;
    result = v39 - 1;
    v35 = v39 == 1;
    v50 += 1760;
    v37 -= 1760;
    v38 += 432;
    --v39;
    if ( v35 )
      break;
    v15 = v38;
    v14 = v50;
	index--;
  }
  return result;
}

//----- (00430FA0) --------------------------------------------------------
char showHallOfFameEndGame_430FA0()//muestra hall of fame
{
  int v0; // edi@1
  signed int v1; // esi@1
  signed int v2; // eax@1
  int *v3; // eax@7
  int v4; // edx@7
  int v5; // ebx@8
  char *v6; // eax@9
  int v7; // edi@9
  char *v8; // edx@9
  char v9; // cl@10
  int v10; // ecx@11
  int v11; // esi@12
  int v12; // ebx@13
  char *v13; // edi@13
  char v14; // al@14
  int v15; // edx@15
  int v16; // edi@18
  int *v17; // eax@18
  char *v18; // edx@18
  char v19; // cl@19
  int v20; // esi@20
  int v21; // eax@20
  int v22; // eax@23
  int v23; // eax@28
  char *v24; // edx@28
  char v25; // cl@29
  char *v26; // eax@30
  char v27; // al@32
  char v29; // [sp-1h] [bp-29h]@13
  char DstBuf[40]; // [sp+0h] [bp-28h]@13

  memcpy(screenBuffer, graphicsGeneral.menubg5Bpk, 0x4B000u);
  drawTransparentBlock(0, 371, 639, 109);
  sub_427BC0();
  drawBottomMenuText();
  drawImageWithPosition((int)graphics2.fametxtBpk, 640, 54, (int)((char *)screenBuffer + 53760));
  v0 = driverId;
  v1 = 0;
  v2 = (signed int)dword_461F2C;
  while ( drivers[driverId].totalRaces >= configuration.hallOfFameEntries[0].races )
  {
    v2 += 20;
    ++v1;
    if ( v2 >= (signed int)&event2Bpk )
      goto LABEL_12;
  }
  if ( v1 >= 0 )
  {
    if ( v1 < 9 )
    {

      v3 = &dword_461FD4;
      v4 = 9 - v1;
      do
      {
        --v4;
        *v3 = *(v3 - 5);
        v3[1] = *(v3 - 4);
        v3[2] = *(v3 - 3);
        v5 = *(v3 - 1);
        v3[3] = *(v3 - 2);
        v3[4] = v5;
        v3 -= 5;
      }
      while ( v4 );
    }
    v6 = &byte_460840[v0];
    v7 = 5 * v1;
   //TODO FIX halloffame v8 = (char *)((char *)&configuration.dword_461F20[5 * v1] - v6);
    do
    {
      v9 = *v6;
      v6[(_DWORD)v8] = *v6;
      ++v6;
    }
    while ( v9 );
	//TODO FIX halloffame strupr((char *)&configuration.dword_461F20[5 * v1]);
    v10 = configuration.difficulty;
    dword_461F2C[v7] = drivers[driverId].totalRaces;
    dword_461F30[v7] = v10;
    sub_421980(17, 22 * v1 + 138, 603, 24);
    saveConfiguration();
  }
LABEL_12:
  v11 = 0;
  do
  {
    v12 = v11 + 1;
    SDL_itoa(v11 + 1, DstBuf, 10);
    v13 = &v29;
    do
      v14 = (v13++)[1];
    while ( v14 );
    v15 = (int)graphicsGeneral.fmed1aBpk;
    *(_WORD *)v13 = 46;
    if ( v11 == 9 )
      drawTextWithFont(v15, (int)&unk_445928, DstBuf, 218908);
    else
      drawTextWithFont(v15, (int)&unk_445928, DstBuf, 14080 * v11 + 92196);
    v16 = 5 * v11;
	//TODO FIX  v17 = &configuration.dword_461F20[5 * v11];
    v18 = (char *)(DstBuf - (char *)v17);
    do
    {
      v19 = *(BYTE *)v17;
      *((BYTE *)v17 + (_DWORD)v18) = *(BYTE *)v17;
      v17 = (int *)((char *)v17 + 1);
    }
    while ( v19 );
    _strupr(DstBuf);
    v20 = 14080 * v11;
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v20 + 92297);
    SDL_itoa(dword_461F2C[v16], DstBuf, 10);
    v21 = dword_461F2C[v16];
    if ( v21 >= 0 && v21 < 10 )
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v20 + 92504);
    v22 = dword_461F2C[v16];
    if ( v22 >= 10 && v22 < 100 )
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v20 + 92496);
    if ( dword_461F2C[v16] >= 100 )
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v20 + 92488);
    v23 = 24 * dword_461F30[v16] + 4485952;
    v24 = &DstBuf[-v23];
    do
    {
      v25 = *(BYTE *)v23;
      v24[v23] = *(BYTE *)v23;
      ++v23;
    }
    while ( v25 );
    v26 = _strupr(DstBuf);
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, v26, v20 + 92589);
    v11 = v12;
  }
  while ( v12 < 10 );
  refreshAllScreen();
  sub_4224E0();
  transitionToCurrentImage();
  eventDetected();
  sub_418090();
  do
  {
    while ( 1 )
    {
      refreshAndCheckConnection_42A570();
      v27 = eventDetected();
      if ( v27 != 59 )
        break;
      if ( !isMultiplayerGame )
        goto LABEL_36;
      //multiplayer_sub_42CCF0();
    }
  }
  while ( !v27 );
LABEL_36:
  eventDetected();
  return sub_418090();
}

//----- (00427BC0) --------------------------------------------------------
int sub_427BC0()
{
  char v0; // bl@1
  signed int v1; // edi@1
  char v2; // al@2
  signed int v3; // edx@2
  signed int v4; // eax@3
  char v5; // cl@4
  int v6; // eax@7
  char v7; // cl@8
  int v8; // eax@9
  char v9; // cl@10
  int v10; // eax@11
  char v11; // cl@12
  int result; // eax@13
  char v13; // cl@14

  v0 = unk_461EC1;
  v1 = 6;
  do
  {
    v2 = unk_461EC3;
    unk_461EC3 = word_461EC4;
    unk_461EC0[0] = v0;
    v0 = unk_461EC2;
    unk_461EC2 = v2;
    HIBYTE(word_461EC4) = unk_461EC6;
    unk_461EC6 = unk_461EC7;
    unk_461EC7 = word_461EC8;
    HIBYTE(word_461EC8) = unk_461ECA;
    unk_461ECA = unk_461ECB;
    unk_461ECB = word_461ECC;
    HIBYTE(word_461ECC) = unk_461ECE;
    unk_461ECE = unk_461ECF;
    unk_461ECF = word_461ED0;
    HIBYTE(word_461ED0) = unk_461ED2;
    unk_461ED2 = unk_461ED3;
    v3 = (signed int)&unk_462096;
    unk_461ED3 = word_461ED4;
    do
    {
      v4 = v3;
      do
      {
        v5 = *(BYTE *)v4;
        *(BYTE *)(v4 - 150) = *(BYTE *)v4;
        ++v4;
      }
      while ( v5 );
      v3 += 150;
    }
    while ( v3 < (signed int)&blacktx1Bpk );
    --v1;
  }
  while ( v1 );
  unk_461EC1 = v0;
  v6 = 0;
  do
  {
    v7 = byte_456618[v6];
    byte_4629F6[v6++] = v7;
  }
  while ( v7 );
  HIBYTE(word_461ED0) = 1;
  v8 = 0;
  do
  {
    v9 = byte_45665E[v8];
    byte_462A8C[v8++] = v9;
  }
  while ( v9 );
  unk_461ED2 = 1;
  v10 = 0;
  do
  {
    v11 = byte_4566A4[v10];
    byte_462B22[v10++] = v11;
  }
  while ( v11 );
  unk_461ED3 = 1;
  result = 0;
  do
  {
    v13 = byte_4566EA[result];
    byte_462BB8[result++] = v13;
  }
  while ( v13 );
  LOBYTE(word_461ED4) = 1;
  return result;
}
