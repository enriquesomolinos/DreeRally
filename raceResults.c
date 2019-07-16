
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "dr.h"
#include "raceParticipant.h"
#include "raceResults.h"
#include "graphics.h"
#include "imageUtil.h"
#include "drivers.h"



const  int EASY_RACE=0;
 const int MEDIUM_RACE=1;
 const int HARD_RACE=2;

extern const int NUM_RACES = 3;
int racePositions[3][4];//para cada carrera 4 participantes ordenados por posicion 

//----- (00429280) --------------------------------------------------------
void __fastcall easyRaceResults(int ecx0, int a2, int a1)
{
  signed int v3; // edi@37
  int v4; // eax@39
  int v5; // ecx@46
  int v6; // ST24_4@49
  int v7; // ecx@50
  int v8; // ST24_4@53
  int v9; // eax@53
  int v10; // ecx@54
  int v11; // ST24_4@57
  int v12; // [sp+0h] [bp-4h]@1

  v12 = ecx0;
  
  if ( selectedRace_462CE8 )
  {
    sub_424510(0, 3, 0);

	LOBYTE(v12) = racePositions[EASY_RACE][3];
	BYTE1(v12) = racePositions[EASY_RACE][2];
	BYTE2(v12) = racePositions[EASY_RACE][1];
	BYTE3(v12) = racePositions[EASY_RACE][0];
	

  /*  LOBYTE(v12) = BYTE3(dword_45EB50[0]);
    BYTE1(v12) = BYTE2(dword_45EB50[0]);
    BYTE2(v12) = BYTE1(dword_45EB50[0]);
    BYTE3(v12) = LOBYTE(dword_45EB50[0]);*/
  }
  else
  {
    switch ( raceParticipant[0].racePosition )
    {
      case 1:
        LOBYTE(v12) = racePositions[EASY_RACE][0];
        break;
      case 2:
        BYTE1(v12) = racePositions[EASY_RACE][0];
        break;
      case 3:
        BYTE2(v12) = racePositions[EASY_RACE][0];
        break;
      case 4:
        BYTE3(v12) = racePositions[EASY_RACE][0];
        break;
    }
    switch (raceParticipant[1].racePosition)
    {
      case 1:
        LOBYTE(v12) = racePositions[EASY_RACE][1];
        break;
      case 2:
        BYTE1(v12) = racePositions[EASY_RACE][1];
        break;
      case 3:
        BYTE2(v12) = racePositions[EASY_RACE][1];
        break;
      case 4:
        BYTE3(v12) = racePositions[EASY_RACE][1];
        break;
    }
    switch (raceParticipant[2].racePosition)
    {
      case 1:
        LOBYTE(v12) = racePositions[EASY_RACE][2];
        break;
      case 2:
        BYTE1(v12) = racePositions[EASY_RACE][2];
        break;
      case 3:
        BYTE2(v12) = racePositions[EASY_RACE][2];
        break;
      case 4:
        BYTE3(v12) = racePositions[EASY_RACE][2];
        break;
    }
    switch (raceParticipant[3].racePosition)
    {
      case 1:
        LOBYTE(v12) = racePositions[EASY_RACE][3];
        break;
      case 2:
        BYTE1(v12) = racePositions[EASY_RACE][3];
        break;
      case 3:
        BYTE2(v12) = racePositions[EASY_RACE][3];
        break;
      case 4:
        BYTE3(v12) = racePositions[EASY_RACE][3];
        break;
    }
	
  }
  if ( !a1 )
  {
    sub_424420();
    drawImageWithPosition((int)graphicsGeneral.raceeasBpk, 272, 20, (int)((char *)screenBuffer + 54114));
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Easy Race Results", 55440);
    drawRightPositions(4, (int)&v12);
  }
  v3 = 0;
  do
  {
    if ( !a1 )
    {
      v4 = *((byte *)&v12 + v3);
      if (drivers[v4].damage != 100 )
		  //if (dword_46084C[27 * v4] != 100)
      {
        if ( v4 == driverId && lapped_456BC0 == 1 )
          goto LABEL_60;
        drawImageWithPosition((int)graphicsGeneral.ptseasyBpk, 42, 18, (int)((char *)screenBuffer + 12160 * v4 + 55897));
      }
    }
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v7 = BYTE1(v12);
		//v7 = 27 * BYTE1(v12);
        if (drivers[v7].damage != 100 && (BYTE1(v12) != driverId || lapped_456BC0 != 1) )
			//if (dword_46084C[v7] != 100 && (BYTE1(v12) != driverId || lapped_456BC0 != 1))
        {
          v8 = 12160 * BYTE1(v12) + 57190;
          v9 = (int)graphicsGeneral.fmed1aBpk;
          drivers[v7].points += 2;
		  //dword_460884[v7] += 2;
          drawTextWithFont(v9, (int)&unk_445928, "+2", v8);
        }
      }
      else if ( v3 == 2 )
      {
        v5 =  BYTE2(v12);
		//v5 = 27 * BYTE2(v12);
        if (drivers[v5].damage != 100 && (BYTE2(v12) != driverId || lapped_456BC0 != 1) )
	//if ( dword_46084C[v5] != 100 && (BYTE2(v12) != driverId || lapped_456BC0 != 1) )
        {
          v6 = 12160 * BYTE2(v12) + 57190;
          ++drivers[v5].points;
		  // ++dword_460884[v5];
          drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, "+1", v6);
        }
      }
    }
    else
    {
      v10 = (unsigned __int8)v12;
	  //v10 = 27 * (unsigned __int8)v12;
      if (drivers[v10].damage != 100 && ((unsigned __int8)v12 != driverId || lapped_456BC0 != 1) )
		  //if (dword_46084C[v10] != 100 && ((unsigned __int8)v12 != driverId || lapped_456BC0 != 1))
      {
        v11 = 12160 * (unsigned __int8)v12 + 57190;
       drivers[v10].points += 3;
		//dword_460884[v10] += 3;
        drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, "+3", v11);
      }
    }
    ++v3;
  }
  while ( v3 < 3 );
  if ( a1 )
    return;
LABEL_60:
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press any key to continue...", 289646);
  refreshAllScreen();
}

//----- (004295E0) --------------------------------------------------------
void __fastcall mediumRaceResults(int ecx0, int a2, int a1)
{
  signed int v3; // edi@37
  int v4; // eax@39
  int v5; // ecx@46
  int v6; // ST24_4@49
  int v7; // ecx@50
  int v8; // ST24_4@53
  int v9; // eax@53
  int v10; // ecx@54
  int v11; // ST24_4@57
  unsigned __int8 v12; // di@60
  signed int v13; // esi@60
  int v14; // ST24_4@61
  int v15; // ST20_4@61
  int v16; // eax@61
  int v17; // [sp+0h] [bp-4h]@1

  v17 = ecx0;
  if ( selectedRace_462CE8 == 1 )
  {
    switch ( raceParticipant[0].racePosition )
    {
      case 1:
        LOBYTE(v17) = racePositions[MEDIUM_RACE][0];
        break;
      case 2:
        BYTE1(v17) = racePositions[MEDIUM_RACE][0];
        break;
      case 3:
        BYTE2(v17) = racePositions[MEDIUM_RACE][0];
        break;
      case 4:
        BYTE3(v17) = racePositions[MEDIUM_RACE][0];
        break;
    }
    switch (raceParticipant[1].racePosition)
    {
      case 1:
        LOBYTE(v17) = racePositions[MEDIUM_RACE][1];
        break;
      case 2:
        BYTE1(v17) = racePositions[MEDIUM_RACE][1];
        break;
      case 3:
        BYTE2(v17) = racePositions[MEDIUM_RACE][1];
        break;
      case 4:
        BYTE3(v17) = racePositions[MEDIUM_RACE][1];
        break;
    }
    switch (raceParticipant[2].racePosition)
    {
      case 1:
        LOBYTE(v17) = racePositions[MEDIUM_RACE][2];
        break;
      case 2:
        BYTE1(v17) = racePositions[MEDIUM_RACE][2];
        break;
      case 3:
        BYTE2(v17) = racePositions[MEDIUM_RACE][2];
        break;
      case 4:
        BYTE3(v17) = racePositions[MEDIUM_RACE][2];
        break;
    }
    switch (raceParticipant[3].racePosition)
    {
      case 1:
        LOBYTE(v17) = racePositions[MEDIUM_RACE][3];
        break;
      case 2:
        BYTE1(v17) = racePositions[MEDIUM_RACE][3];
        break;
      case 3:
        BYTE2(v17) = racePositions[MEDIUM_RACE][3];
        break;
      case 4:
        BYTE3(v17) = racePositions[MEDIUM_RACE][3];
        break;
    }
	
  }
  else
  {
    sub_424510(0, 3, 1);
	
	LOBYTE(v17) = racePositions[MEDIUM_RACE][3];
	BYTE1(v17) = racePositions[MEDIUM_RACE][2];
	BYTE2(v17) = racePositions[MEDIUM_RACE][1];
	BYTE3(v17) = racePositions[MEDIUM_RACE][0];
    /*LOBYTE(v17) = BYTE3(dword_45EB54);
    BYTE1(v17) = BYTE2(dword_45EB54);
    BYTE2(v17) = BYTE1(dword_45EB54);
    BYTE3(v17) = dword_45EB54;*/
  }
  if ( !a1 )
  {
    sub_424420();
    drawImageWithPosition((int)graphicsGeneral.racemedBpk, 272, 20, (int)((char *)screenBuffer + 54114));
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Medium Race Results", 55440);
    drawRightPositions(4, (int)&v17);
  }
  v3 = 0;
  do
  {
    if ( !a1 )
	{
      v4 = *((byte *)&v17 + v3);
      if (drivers[v4].damage != 100 )
      {
        if ( v4 == driverId && lapped_456BC0 == 1 )
          goto LABEL_60;
        drawImageWithPosition((int)graphicsGeneral.ptsmedBpk, 42, 18, (int)((char *)screenBuffer + 12160 * v4 + 55897));
      }
    }
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v7 =  BYTE1(v17);
        if (drivers[v7].damage != 100 && (BYTE1(v17) != driverId || lapped_456BC0 != 1) )
        {
          v8 = 12160 * BYTE1(v17) + 57190;
          v9 = (int)graphicsGeneral.fmed1aBpk;
		  drivers[v7].points += 3;
          drawTextWithFont(v9, (int)&unk_445928, "+3", v8);
        }
      }
      else if ( v3 == 2 )
      {
        v5 =  BYTE2(v17);
        if (drivers[v5].damage != 100 && (BYTE2(v17) != driverId || lapped_456BC0 != 1) )
        {
          v6 = 12160 * BYTE2(v17) + 57190;
          ++drivers[v5].points;
          drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, "+1", v6);
        }
      }
    }
    else
    {
      v10 = (unsigned __int8)v17;
      if (drivers[v10].damage != 100 && ((unsigned __int8)v17 != driverId || lapped_456BC0 != 1) )
      {
        v11 = 12160 * (unsigned __int8)v17 + 57190;
		drivers[v10].points += 5;
        drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, "+5", v11);
      }
    }
    ++v3;
  }
  while ( v3 < 3 );
  if ( a1 )
    return;
LABEL_60:
  v12 = 0;
  v13 = 0;
  //v13 = (signed int)dword_45FC44;
  do
  {
    v14 = (convertColorToPaletteColor((palette1[v13+2]), 6553600) + 0x8000) >> 16;
    v15 = (convertColorToPaletteColor(palette1[v13 + 1], 6553600) + 0x8000) >> 16;
    v16 = convertColorToPaletteColor((palette1[v13 ]), 6553600);
    setPaletteAndGetValue(v12, (v16 + 0x8000) >> 16, v15, v14);
    v13 += 3;
    ++v12;
  }
  while ( v13 < maxPaletteEntries );
  refreshAllScreen();
}


//----- (00429990) --------------------------------------------------------
void __fastcall hardRaceResults(int ecx0, int a2, int a1)
{
  signed int v3; // edi@37
  int v4; // eax@39
  int v5; // ecx@46
  int v6; // ST1C_4@49
  int v7; // ecx@50
  int v8; // ST1C_4@53
  int v9; // eax@53
  int v10; // ecx@54
  int v11; // ST1C_4@57
  unsigned __int8 v12; // di@60
  signed int v13; // esi@60
  int v14; // ST1C_4@61
  int v15; // ST18_4@61
  int v16; // eax@61
  int v17; // [sp+0h] [bp-4h]@1

  v17 = ecx0;
  if ( selectedRace_462CE8 == 2 )
  {
    switch (raceParticipant[0].racePosition)
    {
      case 1:
        LOBYTE(v17) = racePositions[HARD_RACE][0];
        break;
      case 2:
        BYTE1(v17) = racePositions[HARD_RACE][0];
        break;
      case 3:
        BYTE2(v17) = racePositions[HARD_RACE][0];
        break;
      case 4:
        BYTE3(v17) = racePositions[HARD_RACE][0];
        break;
    }
    switch (raceParticipant[1].racePosition)
    {
      case 1:
        LOBYTE(v17) = racePositions[HARD_RACE][1];
        break;
      case 2:
        BYTE1(v17) = racePositions[HARD_RACE][1];
        break;
      case 3:
        BYTE2(v17) = racePositions[HARD_RACE][1];
        break;
      case 4:
        BYTE3(v17) = racePositions[HARD_RACE][1];
        break;
    }
    switch (raceParticipant[2].racePosition)
    {
      case 1:
        LOBYTE(v17) = racePositions[HARD_RACE][2];
        break;
      case 2:
        BYTE1(v17) = racePositions[HARD_RACE][2];
        break;
      case 3:
        BYTE2(v17) = racePositions[HARD_RACE][2];
        break;
      case 4:
        BYTE3(v17) = racePositions[HARD_RACE][2];
        break;
    }
    switch (raceParticipant[3].racePosition)
    {
      case 1:
        LOBYTE(v17) = racePositions[HARD_RACE][3];
        break;
      case 2:
        BYTE1(v17) = racePositions[HARD_RACE][3];
        break;
      case 3:
        BYTE2(v17) = racePositions[HARD_RACE][3];
        break;
      case 4:
        BYTE3(v17) = racePositions[HARD_RACE][3];
        break;
    }
	
  }
  else
  {
    sub_424510(0, 3, 2);

	
    LOBYTE(v17) = racePositions[HARD_RACE][3];
    BYTE1(v17) = racePositions[HARD_RACE][2];
    BYTE2(v17) = racePositions[HARD_RACE][1];
    BYTE3(v17) = racePositions[HARD_RACE][0];
	/*LOBYTE(v17) = BYTE3(dword_45EB58);
    BYTE1(v17) = BYTE2(dword_45EB58);
    BYTE2(v17) = BYTE1(dword_45EB58);
    BYTE3(v17) = dword_45EB58;*/
  }
  if ( !a1 )
  {
    sub_424420();
    drawImageWithPosition((int)graphicsGeneral.raceharBpk, 272, 20, (int)((char *)screenBuffer + 54114));
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Hard Race Results", 55440);
    drawRightPositions(4, (int)&v17);
  }
  v3 = 0;
  do
  {
    if ( !a1 )
    {
      v4 = *((byte *)&v17 + v3);
      if (drivers[v4].damage != 100 )
      {
        if ( v4 == driverId && lapped_456BC0 == 1 )
          goto LABEL_60;
        drawImageWithPosition((int)graphicsGeneral.ptshardBpk, 42, 18, (int)((char *)screenBuffer + 12160 * v4 + 55897));
      }
    }
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v7 = BYTE1(v17);
        if (drivers[v7].damage != 100 && (BYTE1(v17) != driverId || lapped_456BC0 != 1) )
        {
          v8 = 12160 * BYTE1(v17) + 57190;
          v9 = (int)graphicsGeneral.fmed1aBpk;
		  drivers[v7].points += 7;
          drawTextWithFont(v9, (int)&unk_445928, "+7", v8);
        }
      }
      else if ( v3 == 2 )
      {
        v5 =  BYTE2(v17);
        if (drivers[v5].damage != 100 && (BYTE2(v17) != driverId || lapped_456BC0 != 1) )
        {
          v6 = 12160 * BYTE2(v17) + 57190;
		  drivers[v5].points += 4;
          drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, "+4", v6);
        }
      }
    }
    else
    {
      v10 =  (unsigned __int8)v17;
      if (drivers[v10].damage != 100 && ((unsigned __int8)v17 != driverId || lapped_456BC0 != 1) )
      {
        v11 = 12160 * (unsigned __int8)v17 + 57190;
		drivers[v10].points += 10;
        drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, "+10", v11);
      }
    }
    ++v3;
  }
  while ( v3 < 3 );
  if ( a1 )
    return;
LABEL_60:
  v12 = 0;
  v13 = 0;
  //v13 = (signed int)dword_45FC44;
  do
  {
    v14 = (convertColorToPaletteColor((palette1[v13+2]), 6553600) + 0x8000) >> 16;
    v15 = (convertColorToPaletteColor(palette1[v13 + 1], 6553600) + 0x8000) >> 16;
    v16 = convertColorToPaletteColor((palette1[v13]), 6553600);
    setPaletteAndGetValue(v12, (v16 + 0x8000) >> 16, v15, v14);
    v13 += 3;
    ++v12;
  }
  while ( v13 <maxPaletteEntries );
  refreshAllScreen();
}

