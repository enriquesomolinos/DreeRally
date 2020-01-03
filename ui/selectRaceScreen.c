#include "selectRaceScreen.h"
#include "blackMarketScreen.h"
#include "../variables.h"
#include "../circuit.h"
#include "util/menus.h"
#include "../imageUtil.h"
#include "../config.h"
#include "../defs.h"
#include "../drivers.h"
#include "../dr.h"
#include "../graphics.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char byte_461F00[256]; // weak
int lastCircuitsSelected_456780[3];
int dword_445184 = 163840; // weak

//----- (0042B1B0) --------------------------------------------------------
void   selectRaceWarningPopup(int a1)
{
  int v1; // edi@1
//  const char *v2; // esi@1

  memcpy(dword_461ED8, (char *)screenBuffer + 108800, 0x1F400u);
  createPopup(33, 182, 580, 145, 1);
  v1 = 125500;
  //v2 = (char *)&unk_450890 + 300 * a1;
  if (a1 == 0) 
  {
	  char *v2 = "[Hold on to your reins{, you mad, motorized";
	    writeTextInScreen(v2, v1);
		  v1 += 10240;
		  v2 += 60;
		  v2 = "berserker! They would mow you dead out there,";
		  writeTextInScreen(v2, v1);
		  v1 += 10240;
		  v2 += 60;
		  v2 = "[Sign up here only when you have a Sentinel";
		  writeTextInScreen(v2, v1);
		  v1 += 10240;
		  v2 += 60;
		  v2 = "[or something even wilder under your tail.";
		  writeTextInScreen(v2, v1);
		  v1 += 10240;
		  v2 += 60;
	  
  }
  else if (a1 ==1) 
  {
	  char *v2 = "[Hold on to your reins{, you mad, motorized";
	  writeTextInScreen(v2, v1);
	  v1 += 10240;
	  v2 += 60;
	  v2 = "berserker! They would mow you dead out there,";
	  writeTextInScreen(v2, v1);
	  v1 += 10240;
	  v2 += 60;
	  v2 = "[Sign up here only when you have a Wraith";
	  writeTextInScreen(v2, v1);
	  v1 += 10240;
	  v2 += 60;
	  v2 = "[or something even wilder under your tail.";
	  writeTextInScreen(v2, v1);
	  v1 += 10240;
	  v2 += 60;

  }
  
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Press any key to continue."), 189008);
  refreshAllScreen();
  loadMenuSoundEffect(1u, 23, 0, configuration.effectsVolume, dword_44518C - 4096);
  do
    refreshAndCheckConnection_42A570();
  while ( !eventDetected() );
  memcpy((char *)screenBuffer + 108800, dword_461ED8, 0x1F400u);
  refreshAllScreen();
}
// 44518C: using guessed type int dword_44518C;
// 4458B0: using guessed type char letterSpacing_4458B0;
// 45DC18: using guessed type int configuration.effectsVolume;

//----- (00423F40) --------------------------------------------------------
//
int drawSelectRaceScreen()
{
  memcpy((char *)screenBuffer + 234880, (char *)graphicsGeneral.menubg5Bpk + 234880, 0x2800u);
  drawTransparentBlock(0, 371, 639, 109);
  drawBottomMenuText();
  drawImageWithPosition2(graphics2.trsnap2m1Bpk[circuitsToSelect_46126C[0]], 128, 112, (int)((char *)screenBuffer + 81952));
  drawImageWithPosition2(graphics2.trsnap2m1Bpk[circuitsToSelect_46126C[1]], 128, 112, (int)((char *)screenBuffer + 82112));
  drawImageWithPosition2(graphics2.trsnap2m1Bpk[circuitsToSelect_46126C[2]], 128, 112, (int)((char *)screenBuffer + 82272));
  /*drawImageWithPosition2((int)*(&trsnap2m1Bpk + (unsigned __int8)byte_46126D), 128, 112, (int)((char *)screenBuffer + 82112));
  drawImageWithPosition2((int)*(&trsnap2m1Bpk + (unsigned __int8)byte_46126E), 128, 112, (int)((char *)screenBuffer + 82272));*/
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "$750", 143433);
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "$3000", 143586);
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "$12000", 143743);
  createPopup(22, 256, 148, 105, 1);
  createPopup(182, 256, 148, 105, 1);
  createPopup(342, 256, 148, 105, 1);
  drawImageWithPosition((int)graphics2.enterx2Bpk, 640, 32, (int)((char *)screenBuffer + 51200));
  return drawCarRightSide();
}

//----- (004240B0) --------------------------------------------------------
int calculateNextRaces()
{
  int v0; // edi@1
  int v1; // ecx@1
  int v2; // edx@5
  signed int v3; // eax@5
  char v4; // bl@8
  bool v5; // zf@10
  unsigned int v6; // eax@10
  bool v7; // zf@16
  unsigned int v8; // eax@16
  char v9; // al@18
  int result; // eax@23

  v0 = driverId;
  v1 = driverId - 7;
  if ( driverId - 7 >= 0 )
  {
    if ( v1 > 5 )
      v1 = 5;
  }
  else
  {
    v1 = 0;
  }
  v2 = 0;
  v3 = 0;
  do
  {
    if ( &byte_461F00[v1 - (signed int)byte_461F00] + v3 == v0 )
      ++v2;
    v4 = v2++ + v1;
    byte_461F00[v3++] = v4;
  }
  while ( v3 < 14 );
  participantInRaceById_45EA80[0] = 0;
  participantInRaceById_45EA80[1] = 0;
  participantInRaceById_45EA80[2] = 0;
  participantInRaceById_45EA80[3] = 0;
  participantInRaceById_45EA80[4] = 0;
  participantInRaceById_45EA80[5] = 0;
  participantInRaceById_45EA80[6] = 0;
  participantInRaceById_45EA80[7] = 0;
  participantInRaceById_45EA80[8] = 0;
  participantInRaceById_45EA80[9] = 0;
  participantInRaceById_45EA80[10] = 0;
  participantInRaceById_45EA80[11] = 0;
  participantInRaceById_45EA80[12] = 0;
  participantInRaceById_45EA80[13] = 0;
  participantInRaceById_45EA80[14] = 0;
  participantInRaceById_45EA80[15] = 0;
  participantInRaceById_45EA80[16] = 0;
  participantInRaceById_45EA80[17] = 0;
  participantInRaceById_45EA80[18] = 0;
  participantInRaceById_45EA80[19] = 0;

  //dword_45EB50[0] = 0;
  //dword_45EB54 = 0;
  // dword_45EB58 = 0;
  racePositions[0][0] = 0;
  racePositions[0][1] = 0;
  racePositions[0][2] = 0;
  racePositions[0][3] = 0;
  racePositions[1][0] = 0;
  racePositions[1][1] = 0;
  racePositions[1][2] = 0;
  racePositions[1][3] = 0;
  racePositions[2][0] = 0;
  racePositions[2][1] = 0;
  racePositions[2][2] = 0;
  racePositions[2][3] = 0;
  //word_461EB4 = 0;
  //byte_461EB6 = 0;
  participantsRace[0] = 0;
  participantsRace[1] = 0;
  participantsRace[2] = 0;
  //dword_45EB54 = 0;
  
  participantInRaceById_45EA80[v0] = 1;
  
 
  do
  {
    circuitsToSelect_46126C[0] = circuitOrder_45673C[rand() % 5];
    v6 = rand() & 0x80000001;
    v5 = v6 == 0;
    if ( (v6 & 0x80000000) != 0 )
      v5 = (((BYTE)v6 - 1) | 0xFFFFFFFE) == -1;
    if ( v5 )
      circuitsToSelect_46126C[0] += 9;
  }  
  while (lastCircuitsSelected_456780[0] == (unsigned __int8)circuitsToSelect_46126C[0]);
  lastCircuitsSelected_456780[0] = (unsigned __int8)circuitsToSelect_46126C[0];
  do
  {
    circuitsToSelect_46126C[1] = circuitOrder_45673C[rand() % 6];
	//circuitsToSelect_46126C[1] = byte_45673E[rand() % 6];
	//byte_46126D = byte_45673E[rand() % 6];
    v8 = rand() & 0x80000001;
    v7 = v8 == 0;
    if ( (v8 & 0x80000000) != 0 )
      v7 = (((BYTE)v8 - 1) | 0xFFFFFFFE) == -1;
    v9 = circuitsToSelect_46126C[1];
	//v9 = byte_46126D;
    if ( v7 )
    {
      v9 = circuitsToSelect_46126C[1] + 9;
	  circuitsToSelect_46126C[1] += 9;
	  /*v9 = byte_46126D + 9;
	  byte_46126D += 9;*/
    }
  }
  while (lastCircuitsSelected_456780[1] == (unsigned __int8)v9 || circuitsToSelect_46126C[0] == v9);
  lastCircuitsSelected_456780[1] = (unsigned __int8)v9;
  do
  {
    circuitsToSelect_46126C[2] = circuitOrder_45673C[rand() % 4];
	//byte_46126E = byte_456741[rand() % 4];
    result = rand() % 2;
    v5 = result == 0;
    LOBYTE(result) = circuitsToSelect_46126C[2];
	//LOBYTE(result) = byte_46126E;
    if ( v5 )
    {
      LOBYTE(result) = circuitsToSelect_46126C[2] + 9;
	  circuitsToSelect_46126C[2] += 9;
	  //LOBYTE(result) = byte_46126E + 9;
	  //byte_46126E += 9;
    }
  }
  //while ( dword_456788 == (unsigned __int8)result || byte_46126D == (BYTE)result );
  while (lastCircuitsSelected_456780[2] == (unsigned __int8)result || circuitsToSelect_46126C[1] == (BYTE)result);
  lastCircuitsSelected_456780[2] = (unsigned __int8)result;

  //TODO esto es para que salgan fijas
if(debug==1){

	//circuito
  //circuitsToSelect_46126C[0] =WESTEND_CIRCUIT;//4
	//  ;//6;//18 arena;//4;//15 eidolon invertido 6 velodrome 14 falla ilumicion 11 no carga
//  circuitsToSelect_46126C[1] = 14;
 // circuitsToSelect_46126C[2] = 18;
}
  return result;
}

//----- (004357F0) --------------------------------------------------------
void selectRaceScreen()
{
  unsigned __int8 v0; // di@1
//  signed int v1; // esi@1
  int v2; // ST48_4@2
  int v3; // ST44_4@2
  int v4; // eax@2
  int v5; // ST14_4@10
  int v6; // ST14_4@12
  int v7; // edi@31
  signed int v8; // ebx@31
  unsigned __int8 v9; // bp@35
  signed int v10; // esi@35
  int v11; // ST48_4@36
  int v12; // ST44_4@36
  int v13; // eax@36
  signed int v14; // esi@41
//  char *v15; // edi@46
//  char v16; // al@47
//  unsigned int v17; // eax@49
//  char *v18; // edi@49
//  char v19; // cl@50
//  char *v20; // edi@51
//  char v21; // al@52
//  int v22; // eax@53
//  char *v23; // eax@53
//  char *v24; // edx@53
//  char v25; // cl@54
//  unsigned int v26; // eax@55
//  char *v27; // edi@55
//  char v28; // cl@56
  int v29; // ecx@57
  unsigned __int8 v30; // al@57
  signed int v31; // edx@61
  char v32; // cl@62
  char v33; // bl@62
  char v34; // al@62
  char v35; // cl@62
  signed int v36; // esi@62
  signed int v37; // edi@62
  signed int v38; // ebp@62
  char *v39; // ecx@63
  signed int v40; // eax@64
  bool v41; // zf@74
  signed int v42; // esi@78
//  const char **v43; // [sp+0h] [bp-6Ch]@0
//  const char **v44; // [sp+4h] [bp-68h]@0
  char Str; // [sp+10h] [bp-5Ch]@53
  char v46; // [sp+11h] [bp-5Bh]@62
  char v47; // [sp+12h] [bp-5Ah]@62
  char v48; // [sp+13h] [bp-59h]@62
  char DstBuf[256]; // [sp+1Ch] [bp-50h]@45
  int v50; // [sp+20h] [bp-4Ch]@62
  int v51; // [sp+24h] [bp-48h]@62
  int v52; // [sp+28h] [bp-44h]@62
  int v53; // [sp+2Ch] [bp-40h]@46
  char *name =malloc(100); // [sp+30h] [bp-3Ch]@45
  int index = 176;
  selectedRace_462CE8 = -1;
  calculateNextRaces();
  v0 = -80;
  
  //v1 = unk_460484;
  //v1 = (signed int)&unk_460484; offset en la paleta de 176
  do
  {
   /* v2 = (convertColorToPaletteColor(*(_DWORD *)(v1 + 4), 6553600) + 0x8000) >> 16;
    v3 = (convertColorToPaletteColor(*(_DWORD *)v1, 6553600) + 0x8000) >> 16;
    v4 = convertColorToPaletteColor(*(_DWORD *)(v1 - 4), 6553600);
    setPaletteAndGetValue(v0, (v4 + 0x8000) >> 16, v3, v2);
    v1 += 12;
    ++v0;*/
	v2 = (convertColorToPaletteColor(palette1[index+2], 6553600) + 0x8000) >> 16;
	v3 = (convertColorToPaletteColor(palette1[index+1], 6553600) + 0x8000) >> 16;
	v4 = convertColorToPaletteColor(palette1[index], 6553600);
	setPaletteAndGetValue(v0, (v4 + 0x8000) >> 16, v3, v2);
	//v1 += 12;
	++v0;
	index+=3;
  }
  //while ( v1 < (signed int)&unk_4604D8 );
  while (index < 176+16);

  
  memcpy((void *)dword_45FC00, graphicsGeneral.menubg5Bpk, 0x4B000u);
  screenBuffer = (void *)dword_45FC00;
  memcpy((void *)(dword_45FC00 + 65920), (char *)graphicsGeneral.menubg5Bpk + 65920, 0x28A00u);
  drawSelectRaceScreen();
  if ( showWelcomePopup_456B74 || (drawBorder(160 * selectedRaceId + 22, 118, 148, 132), showWelcomePopup_456B74) )
    welcomePopup();
  screenBuffer = (void *)dword_461250;
  sub_42C4A0();
  refreshAllScreen();
  if ( showWelcomePopup_456B74 )
  {
    drawPopupCursor_42C780 ();
    memcpy((char *)screenBuffer + 65920, (char *)graphicsGeneral.menubg5Bpk + 65920, 0x28A00u);
    drawSelectRaceScreen();
    drawBorder(160 * selectedRaceId + 22, 118, 148, 132);
    refreshAllScreen();
  }
  while ( 2 )
  {
    refreshAndCheckConnection_42A570();
    refreshAndCheckConnection_42A570();
    addParticipantToRace(75);
    switch ( eventDetected() )
    {
      case KEY_LEFT:
      case 0xCB:
        if ( selectedRaceId > 0 )
        {
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
          drawBorder2(160 * selectedRaceId + 22, 118, 0x94u, 132);
          v5 = 160 * (selectedRaceId-- - 1) + 22;
          drawBorder(v5, 118, 148, 132);
          refreshAllScreen();
        }
        goto LABEL_26;
      case KEY_RIGHT:
      case 0xCD:
        if ( selectedRaceId < 2 )
        {
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
          drawBorder2(160 * selectedRaceId + 22, 118, 0x94u, 132);
          v6 = 160 * (selectedRaceId++ + 1) + 22;
          drawBorder(v6, 118, 148, 132);
          refreshAllScreen();
        }
        goto LABEL_26;
      case KEY_ENTER:
      case 0x9C:
        if ( selectedRaceId == 1 )
        {
          if ( showMediumWarningRace == 1 && drivers[driverId].carType < 2 )
			  //if (showMediumWarningRace == 1 && dword_46085C[27 * driverId] < 2)
          {
            selectRaceWarningPopup(0);
            showMediumWarningRace = 0;
            goto LABEL_26;
          }
        }
        else if ( selectedRaceId == 2 && showHardWarningRace == 1 && drivers[driverId].carType < 4 )
		//else if (selectedRaceId == 2 && showHardWarningRace == 1 && dword_46085C[27 * driverId] < 4)
        {
          selectRaceWarningPopup(1);
          showHardWarningRace = 0;
          goto LABEL_26;
        }
		//if (*((BYTE *)&word_461EB4 + selectedRaceId) >= 4u)
        if (participantsRace[selectedRaceId] >= 4u )			
        {
          loadMenuSoundEffect(1u, 29, 0, configuration.effectsVolume, dword_4451A4);
	 LABEL_26:
		  
		  if (participantsRace[0] == 4 && participantsRace[1] == 4 && participantsRace[2] == 4)
          //if ( (BYTE)word_461EB4 == 4 && HIBYTE(word_461EB4) == 4 && byte_461EB6 == 4 )
          {
            createPopup(33, 200, 580, 112, 1);
			drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("You did not sign up in any race."), 144048);
			drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Press any key to continue."), 167248);
            refreshAllScreen();
            loadMenuSoundEffect(1u, 23, 0, configuration.effectsVolume, dword_44518C - 4096);
            do
              refreshAndCheckConnection_42A570();
            while ( !eventDetected() );
            sub_4224E0();
            v7 = 6553600;
            v8 = 65500;
            do
            {
              if ( useWeapons && undergroundPricesSet_456B84 )
                setMusicVolume(v8);
              waitWithRefresh();
              v9 = 0;
              v10 = 0;
			  //v10 = (signed int)dword_45FC44;
              do
              {
                v11 = (convertColorToPaletteColor((palette1[v10+2]), v7) + 0x8000) >> 16;
                v12 = (convertColorToPaletteColor(palette1[v10 + 1], v7) + 0x8000) >> 16;
                v13 = convertColorToPaletteColor((palette1[v10]), v7);
                setPaletteAndGetValue(v9, (v13 + 0x8000) >> 16, v12, v11);
                v10 += 3;
                ++v9;
              }
              while ( v10 < maxPaletteEntries );
              v8 -= 1310;
              v7 -= 0x20000;
            }
            while ( v8 >= 0 );
            if ( useWeapons && undergroundPricesSet_456B84 )
            {
              musicSetOrder(dword_462D7C);
              dword_456B60 = 1;
              stopSoundChannel_43C3E0(1u);
            }
            loadPaletteMenu();
            v14 = 0;
            do
              setPaletteAndGetValue(v14++, 0, 0, 0);
            while ( v14 < 256 );
         // //TODO fix   postRaceMain(1, v43, v44);
			postRaceMain(1, (char **)"", (char **)"");
            goto LABEL_44;
          }
          continue;
        }
        loadMenuSoundEffect(1u, 21, 0, configuration.effectsVolume, dword_445184);
        drawImageWithPosition(
          (int)graphics4.signlineBpk,
          136,
          2,
          (int)((char *)screenBuffer + 160 * (selectedRaceId + 72 * participantsRace[selectedRaceId]) + 179227));
        _itoa(drivers[driverId].rank, name, 10);
		/*drawImageWithPosition(
			(int)graphics4.signlineBpk,
			136,
			2,
			(int)((char *)screenBuffer + 160 * (selectedRaceId + 72 * *((BYTE *)&word_461EB4 + selectedRaceId)) + 179227));
		itoa(dword_460888[27 * driverId], DstBuf, 10);*/
        //v54 = 0;
        /*if ( strlen(DstBuf) < 2 )
        {
          v15 = (char *)&v53 + 3;
          do
            v16 = (v15++)[1];
          while ( v16 );
          *(_WORD *)v15 = 32;
        }
        v17 = strlen(DstBuf) + 1;
        v18 = (char *)&v53 + 3;
        do
          v19 = (v18++)[1];
        while ( v19 );
        memcpy(v18, DstBuf, v17);
        v20 = (char *)&v53 + 3;
        do
          v21 = (v20++)[1];
        while ( v21 );
        v22 = 108 * driverId;
        *(_WORD *)v20 = 46;
        v23 = &byte_460840[v22];
        v24 = (char *)(&Str - v23);
        do
        {
          v25 = *v23;
          v23[(_DWORD)v24] = *v23;
          ++v23;
        }
        while ( v25 );
        strupr(&Str);
        v26 = strlen(&Str) + 1;
        v27 = (char *)&v53 + 3;
        do
          v28 = (v27++)[1];
        while ( v28 );
        memcpy(v27, &Str, v26);*/
		strcat(name, " ");
		strcat(name, drivers[driverId].name);
		_strupr(name);
        drawTextWithFont(
          (int)graphicsGeneral.fmed1aBpk,
          (int)&unk_445928,
			name,
          160 * (selectedRaceId + 72 * participantsRace[selectedRaceId]) + 175394);
		/*drawTextWithFont(
			(int)graphicsGeneral.fmed1aBpk,
			(int)&unk_445928,
			&v54,
			160 * (selectedRaceId + 72 * *((BYTE *)&word_461EB4 + selectedRaceId)) + 175394);*/
        v29 = selectedRaceId;
		v30 = participantsRace[selectedRaceId];
		//v30 = *((BYTE *)&word_461EB4 + selectedRaceId);
        selectedRace_462CE8 = selectedRaceId;
		racePositions[selectedRaceId][v30] = driverId;
        //*((BYTE *)&dword_45EB50[selectedRaceId] + v30) = driverId;
        userRaceOrder_45FC20 = v30;
        participantsRace[v29] = v30 + 1;
		//*((BYTE *)&word_461EB4 + v29) = v30 + 1;
        refreshAllScreen();
        do
        {
          do
          {
            refreshAndCheckConnection_42A570();
            refreshAndCheckConnection_42A570();
            addParticipantToRace(3);
          }
          while ( participantsRace[1] < 4u );
		  //while ((unsigned __int8)word_461EB4 < 4u);
        }
        while (participantsRace[0] < 4u || participantsRace[2] < 4u );
		///while (HIBYTE(word_461EB4) < 4u || (unsigned __int8)byte_461EB6 < 4u);
		//este codigo ordena los participantes en la parrilla
        v31 = &dword_45EB50[2];//45EB52
        do
        {
          v32 = *(BYTE *)(v31 - 2);
          v33 = *(BYTE *)(v31 + 1);
          *(_DWORD *)DstBuf = 0;
          v50 = 0;
          v51 = 0;
          v52 = 0;
          v53 = 0;
          v34 = *(BYTE *)(v31 - 1);
          Str = v32;
          v35 = *(BYTE *)v31;
          v48 = v33;
          v46 = v34;
          v47 = v35;
          v36 = 0;
          v37 = (unsigned __int8)v34;
          v38 = (unsigned __int8)v35;
          do
          {
            v39 = &Str;
            do
              v40 = (unsigned __int8)*v39++;
            while ( DstBuf[v40] );
            if ( v37 > v40 && !DstBuf[v37] )
              v40 = v37;
            if ( v38 > v40 && !DstBuf[v38] )
              v40 = v38;
            if ( (unsigned __int8)v33 > v40 && !DstBuf[(unsigned __int8)v33] )
              v40 = (unsigned __int8)v33;
            v41 = v40 == driverId;
            DstBuf[v40] = 1;
           //>TODO FIX LO HE QUITADO PORQU PETA *(BYTE *)(v31 + v36 - 2) = v40;
            if ( v41 )
              userRaceOrder_45FC20 = v36;
            ++v36;
          }
          while ( v36 < 4 );
          v31 += 4;
        }
        while ( v31 < 4582238 );
		/*v31 = 4582226;//45EB52
        do
        {
          v32 = *(BYTE *)(v31 - 2);
          v33 = *(BYTE *)(v31 + 1);
          *(_DWORD *)DstBuf = 0;
          v50 = 0;
          v51 = 0;
          v52 = 0;
          v53 = 0;
          v34 = *(BYTE *)(v31 - 1);
          Str = v32;
          v35 = *(BYTE *)v31;
          v48 = v33;
          v46 = v34;
          v47 = v35;
          v36 = 0;
          v37 = (unsigned __int8)v34;
          v38 = (unsigned __int8)v35;
          do
          {
            v39 = &Str;
            do
              v40 = (unsigned __int8)*v39++;
            while ( DstBuf[v40] );
            if ( v37 > v40 && !DstBuf[v37] )
              v40 = v37;
            if ( v38 > v40 && !DstBuf[v38] )
              v40 = v38;
            if ( (unsigned __int8)v33 > v40 && !DstBuf[(unsigned __int8)v33] )
              v40 = (unsigned __int8)v33;
            v41 = v40 == driverId;
            DstBuf[v40] = 1;
            *(BYTE *)(v31 + v36 - 2) = v40;
            if ( v41 )
              userRaceOrder_45FC20 = v36;
            ++v36;
          }
          while ( v36 < 4 );
          v31 += 4;
        }
        while ( v31 < 4582238 );*/
        v42 = 0;
        if ( !sabotageScreen() && !showHitmanScreen() )
        {
          do
          {
            refreshAndCheckConnection_42A570();
            ++v42;
          }
          while ( !eventDetected() && v42 < 280 );
        }
        previewRaceScreen(4);
LABEL_44:
        dword_456B58 = 1;
        return;
      case KEY_ESCAPE:
        do
        {
          do
            addParticipantToRace(1);
          //while ( (unsigned __int8)word_461EB4 < 4u );
		  while (participantsRace[1] < 4u);

        }
        while (participantsRace[0] < 4u || participantsRace[2] < 4u );
		//while (HIBYTE(word_461EB4) < 4u || (unsigned __int8)byte_461EB6 < 4u);
        goto LABEL_26;
      default:
        goto LABEL_26;
    }
  }
}

//----- (00423A20) --------------------------------------------------------
void   addParticipantToRace(signed int a1)
{
  signed int v1; // esi@2
  int race; // ebx@3
  signed int v3; // edx@7
  signed int v4; // esi@9
  int v5; // eax@10
  int v6; // eax@10
  signed int v7; // esi@16
  int v8; // eax@17
  int v9; // ecx@19
  int v10; // eax@23
  signed int v11; // esi@28
  int v12; // eax@29
  int v13; // eax@29
  unsigned __int8 v14; // al@34
  int v15; // ebp@34
  char *v16; // edi@35
  char v17; // al@36
  unsigned int v18; // eax@38
  void *v19; // edi@38
  char v20; // cl@39
//  char *v21; // edi@40
//  char v22; // al@41
//  char *v23; // eax@42
  char *v24; // edx@42
//  char v25; // cl@43
//  unsigned int v26; // eax@44
//  void *v27; // edi@44
//  char v28; // cl@45
//  void *v29; // edi@46
//  const void *v30; // esi@46
//  int v31; // ecx@46
  int v32; // eax@46
 
  char v34; // [sp+17h] [bp-51h]@35
  char v35; // [sp+18h] [bp-50h]@34
  char* DstBuf; // [sp+4h] [bp-64h]@34
  char * buffer=malloc(2);
  DstBuf = malloc(0x1000);
  if ( !(rand() % a1) )
  {
    v1 = 0;
    while ( 1 )
    {
      ++v1;
	  race = rand() % 3;
      if (participantsRace[race] <= 3u )
        break;
      if ( v1 >= 50 )
        return;
    }
    if ( v1 < 50 )
    {
      v3 = a1;
      do
      {
        if (race)
        {
          if (race == 1 )
          {
            v7 = 0;
            do
            {
              v3 = rand() % 20;
			  v8 = drivers[driverId].carType;
			  //v8 = dword_46085C[27 * driverId];
              ++v7;
              if ( v8 >= 0 && v8 <= 2 )
              {
                v9 = drivers[v3].carType;
				//v9 = dword_46085C[27 * v3];
                if ( v9 >= 1 && v9 <= 3 )
                  break;
              }
              if ( v8 >= 3 && v8 <= 5 )
              {
                v10 = drivers[v3].carType;
				//v10 = dword_46085C[27 * v3];
                if ( v10 >= 2 && v10 <= 4 )
                  break;
              }
            }
            while ( v7 < 100 );
          }
          else if (race == 2 )
          {
            v11 = 0;
            do
            {
              v12 = rand();
              v3 = v12 % 20;
              ++v11;
              v13 = drivers[(v12 % 20)].carType;
			  //v13 = dword_46085C[27 * (v12 % 20)];
            }
            while ( v13 != 3 && v13 != 4 && v13 != 5 && v11 < 100 );
          }
        }
        else
        {
          v4 = 0;
          do
          {
            v5 = rand();
            v3 = v5 % 20;
            ++v4;
            v6 = drivers[(v5 % 20)].carType;
			//v6 = dword_46085C[27 * (v5 % 20)];
          }
          while ( v6 && v6 != 1 && v6 != 2 && v4 < 100 );
        }
      }
      while ( participantInRaceById_45EA80[v3] == 1 );
      v14 = participantsRace[race];
	  //v14 = *((BYTE *)&word_461EB4 + race);
	  
      v15 = v3;
	  //v15 = 108 * v3;
      participantInRaceById_45EA80[v3] = 1;
	  
	  racePositions[race][v14] = v3;
	  //*((BYTE *)&dword_45EB50[race] + v14) = v3;

	 
	 //* ((BYTE *)&word_461EB4 + race) = v14 + 1;
	  participantsRace[race ] = v14 + 1;
      _itoa(drivers[v3].rank, &DstBuf, 10);
	  //itoa(dword_460888[27 * v3], &DstBuf, 10);
      v35 = 0;
      if ( strlen(&DstBuf) < 2 )
      {
        v16 = &v34;
        do
          v17 = (v16++)[1];
        while ( v17 );
        *(_WORD *)v16 = 32;
      }
      v18 = strlen(&DstBuf) + 1;
      v19 = &v34;
      do
      {
        v20 = *((BYTE *)v19 + 1);
        v19 = (char *)v19 + 1;
      }
      while ( v20 );
      memcpy(v19, &DstBuf, v18);
      /*v21 = &v34;
      do
        v22 = (v21++)[1];
      while ( v22 );*/
      //v23 =drivers[v15].name;
	  //v23 = &byte_460840[v15];
     // *(_WORD *)v21 = 46;
	  v24 = malloc(24);
	  
	  _itoa(drivers[v3].rank, buffer, 10);
	  strcpy(v24, buffer);
	  strcat(v24, ".");
	  strcat(v24, drivers[v3].name);
	  //v24 = &byte_460840[v15];
     /* do
        v25 = *v23++;
      while ( v25 );
      v26 = v23 - v24;
      v27 = &v34;
      do
      {
        v28 = *((BYTE *)v27 + 1);
        v27 = (char *)v27 + 1;
      }
      while ( v28 );
      memcpy(v27, v24, 4 * (v26 >> 2));
      v30 = &v24[4 * (v26 >> 2)];
      v29 = (char *)v27 + 4 * (v26 >> 2);
      v31 = v26 & 3;
	  */
	  //v32 = 9 * *((BYTE *)&word_461EB4 + race);
	  v32 = 9 * participantsRace[race];
      //memcpy(v29, v30, v31);
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, v24, 160 * (race  + 8 * v32) + 163874);
      refreshAllScreen();
    }
  }
}
