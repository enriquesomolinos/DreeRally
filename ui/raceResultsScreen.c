#include "raceResultsScreen.h"
#include "../variables.h"
#include "../circuit.h"
#include "util/menus.h"
#include "../imageUtil.h"
#include "../config.h"
#include "../defs.h"
#include "../drivers.h"
#include "../dr.h"
#include "../graphics.h"
#include "../raceParticipant.h"
#include "../i18n/i18n.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL_stdinc.h>
#include <string.h>

char showEndAnim_463DF8; // weak
char byte_45FC0F[256]; // weak
int dword_456BCC = 0; // weak
int waitCounter2_456BE4 = 0; // weak

char aSuburbia[9] = "Suburbia"; // weak

//----- (00425980) --------------------------------------------------------
int   writeDriverList(int a1)
{
  int result; // eax@1
  int v2; // esi@1
//  int v3; // ebp@2
  void *v4; // eax@4
////  char *v5; // edi@6
//  char v6; // al@7
//  char *v7; // eax@8
//  int v8; // ebx@8
//  unsigned int v9; // edx@8
//  char v10; // cl@9
//  int v11; // eax@12
//  char v12; // cl@13
//  char *v13; // eax@14
//  int v14; // edi@14
//  unsigned int v15; // ecx@14
//  char v16; // dl@15
//  bool v17; // sf@18
//  unsigned __int8 v18; // of@18
  int v19; // [sp-10h] [bp-34h]@3
  int v20; // [sp+4h] [bp-20h]@1
//  signed int v21; // [sp+8h] [bp-1Ch]@2
//  int v22; // [sp+Ch] [bp-18h]@6
  char DstBuf[20]; // [sp+10h] [bp-14h]@2
  int indexDriver = 0;
  
 int v8 = 0;
int v9 = 0;
int v14 = 0;
 int v15 = 0;
  result = a1;
  v2 = 0;
  v20 = 0;
  if (a1 > 0)
  {
	 
	  do
	  {
		  v19 = (int)((char *)screenBuffer + v2 + 55709);
		  if (v20 == driverId)
		  {
			  drawImageWithPosition((int)graphicsGeneral.prankBpk, 31, 18, v19);
			  drawImageWithPosition((int)graphicsGeneral.pnameBpk, 101, 18, (int)((char *)screenBuffer + v2 + 55741));
			  v4 = graphicsGeneral.ppistBpk;
		  }
		  else
		  {
			  drawImageWithPosition((int)graphicsGeneral.rankinf1Bpk, 31, 18, v19);
			  drawImageWithPosition((int)graphicsGeneral.rankinf2Bpk, 101, 18, (int)((char *)screenBuffer + v2 + 55741));
			  v4 = graphicsGeneral.rankinf3Bpk;
		  }
		  drawImageWithPosition((int)v4, 53, 18, (int)((char *)screenBuffer + v2 + 55843));
		 

		  memset(DstBuf, 0, 20);
		  SDL_itoa(drivers[indexDriver].rank, DstBuf, 10);
		  strcat(DstBuf, ".");
		  v8 = 0;
		  v9=0;
		  do
			  v8 += (unsigned __int8)letterSpacing_4458B0[90 + (unsigned __int8)DstBuf[v9++]];
		  while (v9 < strlen(DstBuf));

		  drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v2 -v8 + 57662);
		  
		  memset(DstBuf, 0, 20);
		  strcpy(DstBuf, drivers[indexDriver].name);
		  _strupr(DstBuf);
		  
		  drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v2 + 57026);
		 
		  memset(DstBuf, 0, 20);
		  
		  SDL_itoa(drivers[indexDriver].points, DstBuf, 10);
		  v14 = 0;
		  v15=0;
		  do
			  v14 += (unsigned __int8)letterSpacing_4458B0[90+(unsigned __int8)DstBuf[v15++]];
		  while (v15 < strlen(DstBuf));
		  
		  drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v2 - v14 + 57160);
		  result = v20 + 1;
		 // v3 += 108;
		  v2 += 19*640; //19 lineas en pantalla
		  
		  indexDriver++;
	  } while (indexDriver <20);
  }
  return result;  
}

//----- (0042B290) --------------------------------------------------------
int   postRaceMain(int argc, const char **argv, const char **envp)
{
  signed int v3; // ebx@1
  int v4; // esi@2
  unsigned __int8 v5; // bp@3
  signed int v6; // edi@3
  int v7; // ST34_4@4
  int v8; // ST30_4@4
  int v9; // eax@4
  unsigned __int8 v10; // bp@5
  signed int v11; // edi@5
  int v12; // ST34_4@6
  int v13; // ST30_4@6
  int v14; // eax@6
  int v15; // esi@9
  unsigned __int8 v16; // bp@10
  signed int v17; // edi@10
  int v18; // ST34_4@11
  int v19; // ST30_4@11
  int v20; // eax@11
  unsigned __int8 v21; // bp@12
  signed int v22; // edi@12
  int v23; // ST34_4@13
  int v24; // ST30_4@13
  int v25; // eax@13
  int v26; // edi@15
  unsigned __int8 v27; // bp@17
  signed int v28; // esi@17
  int v29; // ST34_4@18
  int v30; // ST30_4@18
  int v31; // eax@18
  unsigned int v32; // eax@22
  void *v33; // edi@22
  char v34; // cl@23
  char *v35; // edi@25
  char v36; // al@26
  FILE *v37; // eax@27
  FILE *v38; // esi@27
  __int32 v39; // edi@28
  unsigned __int8 v40; // di@30
  signed int v41; // esi@30
  int v42; // ST34_4@31
  int v43; // ST30_4@31
  int v44; // eax@31
  int result; // eax@32
//  int v46; // edx@33
//  int v47; // ecx@33
  int v48; // edi@33
  unsigned __int8 v49; // bp@36
  signed int v50; // esi@36
  int v51; // ST34_4@37
  int v52; // ST30_4@37
  int v53; // eax@37
  char v54; // al@40
//  int v55; // ecx@40
  char v56; // bl@40
//  int v57; // edx@43
//  int v58; // ecx@43
  char v59; // al@44
  int maxDriverPoints = 0; // ebx@1
//  signed int v61; // edx@50
//  int v62; // ecx@50
  int v63; // ecx@67
  int v64; // esi@78
  unsigned __int8 v65; // bp@79
  signed int v66; // edi@79
  int v67; // ST34_4@80
  int v68; // ST30_4@80
  int v69; // eax@80
  int v70; // ST34_4@82
  int v71; // ST30_4@82
  int v72; // eax@82
  unsigned __int8 v73; // bp@83
  signed int v74; // edi@83
  int v75; // ST34_4@84
  int v76; // ST30_4@84
  int v77; // eax@84
  unsigned int v78; // eax@88
  void *v79; // edi@88
  char v80; // cl@89
  char *v81; // edi@91
  char v82; // al@92
  FILE *v83; // eax@93
  FILE *v84; // esi@93
  __int32 v85; // edi@94
  unsigned __int8 v86; // di@96
  signed int v87; // esi@96
  int v88; // ST34_4@97
  int v89; // ST30_4@97
  int v90; // eax@97
  char v91; // [sp+Fh] [bp-65h]@22
  char Filename; // [sp+10h] [bp-64h]@21

  v3 = 0;
  showEndAnim_463DF8 = 0;
  dword_456730 = 0;
  if ( argc == 2 )
  {
    drawStadistics();
    writeDriverList(20);
	drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Press any key to continue..."), 289646);
    refreshAllScreen();
    sub_4224E0();
    v4 = 0;
    do
    {
      waitWithRefresh();
      v5 = 0;
	  v6 = 0;
	  //v6 = (signed int)dword_45FC44;
      do
      {
        v7 = (convertColorToPaletteColor((palette1[v6+2]), v4) + 0x8000) >> 16;
        v8 = (convertColorToPaletteColor(palette1[v6 + 1], v4) + 0x8000) >> 16;
        v9 = convertColorToPaletteColor((palette1[v6]), v4);
        setPaletteAndGetValue(v5, (v9 + 0x8000) >> 16, v8, v7);
        v6 += 3;
        ++v5;
      }
      while ( v6 < 288);
	  //while (v6 < (signed int)&unk_4600C4);
      v10 = -128;
	  v11= 384;
      //v11 = (signed int)&unk_460244;
      do
      {
        v12 = (convertColorToPaletteColor(palette1[v11+2], v4) + 0x8000) >> 16;
        v13 = (convertColorToPaletteColor(palette1[v11 + 1], v4) + 0x8000) >> 16;
        v14 = convertColorToPaletteColor(palette1[v11 ], v4);
        setPaletteAndGetValue(v10, (v14 + 0x8000) >> 16, v13, v12);
        v11 += 3;
        ++v10;
		/* v12 = (convertColorToPaletteColor((v11 + 4), v4) + 0x8000) >> 16;
        v13 = (convertColorToPaletteColor(v11, v4) + 0x8000) >> 16;
        v14 = convertColorToPaletteColor((v11 - 4), v4);
        setPaletteAndGetValue(v10, (v14 + 0x8000) >> 16, v13, v12);
        v11 += 12;
        ++v10;*/
      }
      while ( v11 < maxPaletteEntries );
	  //while (v9 < (signed int)&unk_460844);
      v4 += 0x20000;
    }
    while ( v4 < 6553600 );
    do
    {
      refreshAndCheckConnection_42A570();
      drawPressAnyKeyToContinue();
    }
    while ( !eventDetected() );
    sub_4224E0();
    v15 = 6553600;
    do
    {
      waitWithRefresh();
      v16 = 0;
      v17 = 0;
	  //v17 = (signed int)dword_45FC44;
      do
      {
        v18 = (convertColorToPaletteColor((palette1[v17+2]), v15) + 0x8000) >> 16;
        v19 = (convertColorToPaletteColor(palette1[v17 + 1], v15) + 0x8000) >> 16;
        v20 = convertColorToPaletteColor((palette1[v17]), v15);
        setPaletteAndGetValue(v16, (v20 + 0x8000) >> 16, v19, v18);
        v17 += 3;
        ++v16;
      }
      while ( v17 < 288);
	  //while ( v15 < (signed int)&unk_4600C4 );
      v21 = -128;
	  v22 = 384;
      //v22 = (signed int)&unk_460244;
      do
      {
        v23 = (convertColorToPaletteColor(palette1[v22+2], v15) + 0x8000) >> 16;
        v24 = (convertColorToPaletteColor(palette1[v22 + 1], v15) + 0x8000) >> 16;
        v25 = convertColorToPaletteColor(palette1[v22], v15);
        setPaletteAndGetValue(v21, (v25 + 0x8000) >> 16, v24, v23);
        v22 += 3;
        ++v21;
		/*v23 = (convertColorToPaletteColor(*(_DWORD *)(v22 + 4), v15) + 0x8000) >> 16;
        v24 = (convertColorToPaletteColor(*(_DWORD *)v22, v15) + 0x8000) >> 16;
        v25 = convertColorToPaletteColor(*(_DWORD *)(v22 - 4), v15);
        setPaletteAndGetValue(v21, (v25 + 0x8000) >> 16, v24, v23);
        v22 += 12;
        ++v21;*/
      }
      while ( v22 < maxPaletteEntries );
	  // while (v20 < (signed int)&unk_460844);
      v15 -= 0x20000;
    }
    while ( v15 >= 0 );
    goto LABEL_15;
  }
  memcpy(screenBuffer, graphicsGeneral.menubg5Bpk, 0x4B000u);
  drawImageWithPosition((int)graphicsGeneral.rank1cBpk, 54, 386, (int)((char *)screenBuffer + 54060));
  drawImageWithPosition((int)graphicsGeneral.resupok1Bpk, 272, 386, (int)((char *)screenBuffer + 54114));
  writeDriverList(20);
  easyRaceResults(0, 0, 0);
  //TODO fix easyRaceResults(v47, v46, 0);
  refreshAllScreen();
  v48 = 0;
  do
  {
    if ( dword_456B60 )
      setMusicVolume(v3);
    waitWithRefresh();
    v49 = 0;
    v50 =0;
	//v50 = (signed int)dword_45FC44;
    do
    {
      v51 = (convertColorToPaletteColor((palette1[v50+2]), v48) + 0x8000) >> 16;
      v52 = (convertColorToPaletteColor(palette1[v50 + 1], v48) + 0x8000) >> 16;
      v53 = convertColorToPaletteColor((palette1[v50 ]), v48);
      setPaletteAndGetValue(v49, (v53 + 0x8000) >> 16, v52, v51);
      v50 += 3;
      ++v49;
    }
    while ( v50 < maxPaletteEntries );
	//while ( v47 < (signed int)&unk_460844 );
    v3 += 1310;
    v48 += 0x20000;
  }
  while ( v3 < 65500 );
  dword_456B60 = 0;
  do
  {
    refreshAndCheckConnection_42A570();
    drawPressAnyKeyToContinue();
    v54 = eventDetected();
    v56 = v54;
  }
  while ( !v54 || v54==28 );
  if ( v54 != 1 )
    v56 = 0;
  mediumRaceResults(v56,0 , 0);
   //TODO fix mediumRaceResults(v55, (unsigned __int8)v56, (unsigned __int8)v56);
  if ( !v56 )
  {
    do
    {
      refreshAndCheckConnection_42A570();
      drawPressAnyKeyToContinue();
      v59 = eventDetected();
      v56 = v59;
    }
    while ( !v59 );
    if ( v59 != 1 )
      v56 = 0;
  }
  //TODO fix hardRaceResults(v58, v57, (unsigned __int8)v56);
  hardRaceResults(v56, 0, 0);
  if ( !v56 )
  {
    do
    {
      refreshAndCheckConnection_42A570();
      drawPressAnyKeyToContinue();
    }
    while ( !eventDetected() );
  }
  //sub_423C90(0, 19); //modiffica una variable de adversary pero no se que hace
  //recalcRank(20);  //QUITADO porque solo hace multiplayer
  drawStadistics();
  writeDriverList(20);
  refreshAllScreen();
  maxDriverPoints = argc;
  if ( argc )
  {
    if ( argc != 1 )
      goto LABEL_74;
	drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Press any key to continue..."), 289646);
  }
  else
  {
	  
	  maxDriverPoints = getMaxDriverPoints(driverId);

    v63 = drivers[ driverId].points;
    if ( v63 > maxDriverPoints && !useHasMorePoints_456BC4 )
      showEndAnim_463DF8 = 1;
    useHasMorePoints_456BC4 = v63 > maxDriverPoints;
    sub_426080();
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Please wait while loading..."), 289646);
    refreshAllScreen();
    loadGraphics2();
    loadGraphics3();
    loadGraphics4();
    sub_426080();
    loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Press any key to continue..."), 289646);
  }
  refreshAllScreen();
  do
  {
LABEL_74:
    refreshAndCheckConnection_42A570();
    drawPressAnyKeyToContinue();
  }
  while ( !eventDetected() );
  if ( useWeapons && !showWelcomePopup_456B74 && undergroundPricesSet_456B84 )
  {
LABEL_15:
    sub_4224E0();
    v26 = 6553600;
    do
    {
      waitWithRefresh();
      if ( showEndAnim_463DF8 == 1 )
      {
        v27 = 0;
        v28 = 0;
		//v28 = (signed int)dword_45FC44;
        do
        {
          v29 = (convertColorToPaletteColor((palette1[v28+2]), v26) + 0x8000) >> 16;
          v30 = (convertColorToPaletteColor(palette1[v28 + 1], v26) + 0x8000) >> 16;
          v31 = convertColorToPaletteColor((palette1[v28 ]), v26);
          setPaletteAndGetValue(v27, (v31 + 0x8000) >> 16, v30, v29);
          v28 += 3;
          ++v27;
        }
        while ( v28 < maxPaletteEntries );
		//while ( v26 < (signed int)&unk_460844 );
      }
      v26 -= 0x20000;
    }
    while ( v26 >= 0 );
    if ( showEndAnim_463DF8 == 1 )
    {
      stopSong();
      stopAndOpenMusic();
      Filename = 0;
      if ( byte_462D50 == 2 )
      {
        v32 = strlen(byte_45FAA0) + 1;
        v33 = &v91;
        do
        {
          v34 = *((BYTE *)v33 + 1);
          v33 = (char *)v33 + 1;
        }
        while ( v34 );
        memcpy(v33, byte_45FAA0, v32);
      }
      v35 = &v91;
      do
        v36 = (v35++)[1];
      while ( v36 );
      *(_DWORD *)v35 = 1633971813; //endanim
      *((_DWORD *)v35 + 1) = 774924654;
      *((_DWORD *)v35 + 2) = 6709608;
      v37 = fopen(&Filename, "rb");
      v38 = v37;
      if ( v37 )
      {
        fseek(v37, 0, 2);
        v39 = ftell(v38);
        fclose(v38);
        if ( v39 > 0 )
        {
          openAnimation("ENDANI0.HAF", 1, "tr0-mus.cmf", 2, "endani0e.cmf", 1, 120);
          stopSong();
          stopAndOpenMusic();
        }
      }
      loadMusic(1, "MEN-MUS.CMF", 2, "MEN-SAM.CMF");
      musicSetmusicVolume(configuration.musicVolume);
      nullsub_1();
      musicPlayMusic();
      nullsub_1();
      showEndAnim_463DF8 = 0;
      nullsub_1();
      setWindowCaption2();
      sub_4224E0();
      recalculateSDLTicks_43C740();
      allCarsCrash_456BB0 = 0;
      noPaintJob_456BAC = 0;
      consecutiveWins_456BA8 = 0;
      v40 = 96;
	  v41 = 288;
      //v41 = (signed int)&unk_4600C4;
      do
      {
        v42 = (convertColorToPaletteColor(palette1[v41+2], 6553600) + 0x8000) >> 16;
        v43 = (convertColorToPaletteColor(palette1[v41 + 1], 6553600) + 0x8000) >> 16;
        v44 = convertColorToPaletteColor(palette1[v41 ], 6553600);
        setPaletteAndGetValue(v40, (v44 + 0x8000) >> 16, v43, v42);
        v41 += 3;
        ++v40;
		/*v42 = (convertColorToPaletteColor(*(_DWORD *)(v41 + 4), 6553600) + 0x8000) >> 16;
        v43 = (convertColorToPaletteColor(*(_DWORD *)v41, 6553600) + 0x8000) >> 16;
        v44 = convertColorToPaletteColor(*(_DWORD *)(v41 - 4), 6553600);
        setPaletteAndGetValue(v40, (v44 + 0x8000) >> 16, v43, v42);
        v41 += 12;
        ++v40;*/
      }
	  while (v41 < 389);
      //while ( v41 < (signed int)&unk_460244 );

    }
    goto LABEL_32;
  }
  sub_4224E0();
  v64 = 6553600;
  do
  {
    waitWithRefresh();
    v65 = 0;
    v66 = 0;
	//v66 = (signed int)dword_45FC44;
    if ( showEndAnim_463DF8 == 1 )
    {
      do
      {
        v67 = (convertColorToPaletteColor((palette1[v66+2]), v64) + 0x8000) >> 16;
        v68 = (convertColorToPaletteColor(palette1[v66 + 1], v64) + 0x8000) >> 16;
        v69 = convertColorToPaletteColor((palette1[v66 ]), v64);
        setPaletteAndGetValue(v65, (v69 + 0x8000) >> 16, v68, v67);
        v66 += 3;
        ++v65;
      }
      while ( v66 < maxPaletteEntries );
	  //while (v60 < (signed int)&unk_460844);
    }
    else
    {	
      do
      {
        v70 = (convertColorToPaletteColor((palette1[v66 + 2]), v64) + 0x8000) >> 16;
        v71 = (convertColorToPaletteColor(palette1[v66 + 1], v64) + 0x8000) >> 16;
        v72 = convertColorToPaletteColor((palette1[v66]), v64);
        setPaletteAndGetValue(v65, (v72 + 0x8000) >> 16, v71, v70);
        v66 += 3;
        ++v65;
      }
      while ( v66 <  385);
	  /* do
      {
        v70 = (convertColorToPaletteColor(*(_DWORD *)(v66 + 4), v64) + 0x8000) >> 16;
        v71 = (convertColorToPaletteColor(*(_DWORD *)v66, v64) + 0x8000) >> 16;
        v72 = convertColorToPaletteColor(*(_DWORD *)(v66 - 4), v64);
        setPaletteAndGetValue(v65, (v72 + 0x8000) >> 16, v71, v70);
        v66 += 12;
        ++v65;
      }
      while ( v66 < (signed int)&unk_4600C4 );*/
      v73 = -128;
      v74 = 384;
      do
      {
        v75 = (convertColorToPaletteColor(palette1[v74 + 2], v64) + 0x8000) >> 16;
        v76 = (convertColorToPaletteColor(palette1[v74+1], v64) + 0x8000) >> 16;
        v77 = convertColorToPaletteColor(palette1[v74], v64);
        setPaletteAndGetValue(v73, (v77 + 0x8000) >> 16, v76, v75);
        v74 += 3;
        ++v73;
      }
      while ( v74 <maxPaletteEntries );
	  /*v74 = (signed int)&unk_460244;
      do
      {
        v75 = (convertColorToPaletteColor(*(_DWORD *)(v74 + 4), v64) + 0x8000) >> 16;
        v76 = (convertColorToPaletteColor(*(_DWORD *)v74, v64) + 0x8000) >> 16;
        v77 = convertColorToPaletteColor(*(_DWORD *)(v74 - 4), v64);
        setPaletteAndGetValue(v73, (v77 + 0x8000) >> 16, v76, v75);
        v74 += 12;
        ++v73;
      }
      while ( v74 <maxPaletteEntries );*/
	  //while ( v68 < (signed int)&unk_460844 );
    }
    v64 -= 0x20000;
  }
  while ( v64 >= 0 );
  if ( showEndAnim_463DF8 == 1 )
  {
    stopSong();
    stopAndOpenMusic();
    Filename = 0;
    if ( byte_462D50 == 2 )
    {
      v78 = strlen(byte_45FAA0) + 1;
      v79 = &v91;
      do
      {
        v80 = *((BYTE *)v79 + 1);
        v79 = (char *)v79 + 1;
      }
      while ( v80 );
      memcpy(v79, byte_45FAA0, v78);
    }
    v81 = &v91;
    do
      v82 = (v81++)[1];
    while ( v82 );
    *(_DWORD *)v81 = 1633971813;
    *((_DWORD *)v81 + 1) = 774924654;
    *((_DWORD *)v81 + 2) = 6709608;
    v83 = fopen(&Filename, "rb");
    v84 = v83;
    if ( v83 )
    {
      fseek(v83, 0, 2);
      v85 = ftell(v84);
      fclose(v84);
      if ( v85 > 0 )
      {
        openAnimation("ENDANI0.HAF", 1, "tr0-mus.cmf", 2, "endani0e.cmf", 1, 120);
        stopSong();
        stopAndOpenMusic();
      }
    }
    loadMusic(1, "MEN-MUS.CMF", 2, "MEN-SAM.CMF");
    musicSetmusicVolume(configuration.musicVolume);
    nullsub_1();
    musicPlayMusic();
    nullsub_1();
    showEndAnim_463DF8 = 0;
    nullsub_1();
    setWindowCaption2();
    sub_4224E0();
    recalculateSDLTicks_43C740();
    v86 = 96;
	v87 = 288;
    //v87 = (signed int)&unk_4600C4;
    do
    {
      v88 = (convertColorToPaletteColor(palette1[v87+2], 6553600) + 0x8000) >> 16;
      v89 = (convertColorToPaletteColor(palette1[v87 + 1], 6553600) + 0x8000) >> 16;
      v90 = convertColorToPaletteColor(palette1[v87 ], 6553600);
      setPaletteAndGetValue(v86, (v90 + 0x8000) >> 16, v89, v88);
      v87 += 3;
      ++v86;
	  /*v88 = (convertColorToPaletteColor(*(_DWORD *)(v87 + 4), 6553600) + 0x8000) >> 16;
	  v89 = (convertColorToPaletteColor(*(_DWORD *)v87, 6553600) + 0x8000) >> 16;
	  v90 = convertColorToPaletteColor(*(_DWORD *)(v87 - 4), 6553600);
	  setPaletteAndGetValue(v86, (v90 + 0x8000) >> 16, v89, v88);
	  v87 += 12;
	  ++v86;*/
    }
	//while ( v87 < (signed int)&unk_460244 );
    while ( v87 < 389);
  }
LABEL_32:
  LOBYTE(result) = eventDetected();
  dword_456730 = 1;
  return result;
}
//----- (004245D0) --------------------------------------------------------
unsigned int drawStadistics()
{
  unsigned int v0; // eax@2
  char *v1; // edi@2
  char v2; // cl@3
  char *v3; // edi@4
  char v4; // al@5
  int v5; // ST24_4@6
//  char *v6; // edi@8
//  char v7; // al@9
  int v8; // ecx@10
//  unsigned int v9; // eax@10
//  char *v10; // edi@10
//  char v11; // cl@11
  int v12; // edx@12
//  unsigned int v13; // eax@12
//  char *v14; // edi@12
//  char v15; // cl@13
  int v16; // edx@14
//  unsigned int v17; // eax@14
//  char *v18; // edi@14
//  char v19; // cl@15
//  bool v20; // zf@16
//  char *v21; // edi@17
//  char v22; // al@18
//  int v23; // ST28_4@19
//  unsigned int v24; // eax@19
//  char *v25; // edi@19
//  char v26; // cl@20
//  unsigned int v27; // eax@22
//  char *v28; // edi@22
//  char v29; // cl@23
//  unsigned int v30; // eax@24
//  char *v31; // edi@24
//  char v32; // cl@25
  int v33; // edx@26
  unsigned int result; // eax@26
  int v35; // esi@27
  int v36; // edx@27
  char *v37; // eax@27
  signed int v38; // ecx@27
  char v39; // dl@28
  int v40; // ecx@30
  char *v41; // eax@30
  signed int v42; // edx@30
  char v43; // cl@31
  char *v44; // edi@32
  char v45; // al@33
  unsigned int v46; // eax@34
  char *v47; // edi@34
  char v48; // cl@35
  char *v49; // edi@36
  char v50; // al@37
  char *v51; // edi@39
  char v52; // al@40
  unsigned int v53; // eax@41
  char *v54; // edi@41
  char v55; // cl@42
  unsigned int v56; // eax@43
  char *v57; // edi@43
  char v58; // cl@44
  unsigned int v59; // eax@45
  char *v60; // edi@45
  char v61; // cl@46
  int v62; // edx@47
  unsigned int v63; // eax@47
  char *v64; // edi@47
  char v65; // cl@48
  int v66; // edx@49
  unsigned int v67; // eax@49
  char *v68; // edi@49
  char v69; // cl@50
  int v70; // ST24_4@51
  int v71; // eax@57
  char v72; // cl@58
  char *v73; // edi@59
  char v74; // al@60
  unsigned int v75; // eax@61
  void *v76; // edi@61
  char v77; // cl@62
  char *v78; // edi@63
  char v79; // al@64
  unsigned int v80; // eax@65
  void *v81; // edi@65
  char v82; // cl@66
  unsigned int v83; // eax@67
  char *v84; // edi@67
  char v85; // cl@68
  int v86; // edx@69
  int v87; // eax@69
  char *v88; // edx@69
  int v89; // ecx@69
  int v90; // edi@69
  int v91; // esi@69
  char *v92; // ecx@71
  int v93; // eax@71
  char *v94; // esi@71
  char *v95; // edx@71
  char v96; // al@72
  int v97; // ebx@73
  int v98; // ecx@73
  int v99; // ecx@74
  char *v100; // ecx@76
  int v101; // eax@76
  char *v102; // esi@76
  char *v103; // edx@76
  char v104; // bl@76
  char v105; // al@77
  int v106; // edx@78
  int v107; // ecx@78
  int v108; // eax@78
  char *v109; // edi@80
//  char v110; // al@81
  char *v111; // edi@84
  char v112; // al@85
  char *v113; // edi@88
  char v114; // al@89
  char *v115; // eax@94
  char v116; // cl@95
  char *v117; // eax@98
  char v118; // cl@99
  char *v119; // eax@102
  char v120; // cl@103
  int v121; // eax@106
  char v122; // cl@107
  char *v123; // edi@108
  char v124; // al@109
  char *v125; // eax@110
  char v126; // cl@111
  unsigned int v127; // eax@112
  void *v128; // edi@112
  char v129; // cl@113
  char *v130; // edi@114
  char v131; // al@115
  char *v132; // eax@116
  char v133; // cl@117
  unsigned int v134; // eax@118
  void *v135; // edi@118
  char v136; // cl@119
  char *v137; // eax@120
  char v138; // cl@121
  unsigned int v139; // eax@122
  char *v140; // edi@122
  char v141; // cl@123
  int v142; // ST24_4@124
  char *v143; // eax@124
  char v144; // dl@125
  char *v145; // eax@128
  char v146; // cl@129
  char *v147; // eax@132
  char v148; // cl@133
  int v149; // eax@136
  char v150; // cl@137
  char *v151; // edi@138
  char v152; // al@139
  char *v153; // eax@140
  char v154; // cl@141
  unsigned int v155; // eax@142
  void *v156; // edi@142
  char v157; // cl@143
  char *v158; // edi@144
  char v159; // al@145
  char *v160; // eax@146
  char v161; // cl@147
  unsigned int v162; // eax@148
  void *v163; // edi@148
  char v164; // cl@149
  char *v165; // eax@150
  char v166; // dl@151
  unsigned int v167; // eax@152
  char *v168; // edi@152
  char v169; // cl@153
  int v170; // ST24_4@154
  char v171; // [sp+Fh] [bp-A1h]@8
  char DstBuf[20]; // [sp+10h] [bp-A0h]@2
  int v173; // [sp+24h] [bp-8Ch]@2
  int v174; // [sp+28h] [bp-88h]@2
  int v175; // [sp+2Ch] [bp-84h]@2
  int v176; // [sp+30h] [bp-80h]@2
  __int16 v177; // [sp+34h] [bp-7Ch]@47
  char v178; // [sp+74h] [bp-3Ch]@51
  char v179; // [sp+75h] [bp-3Bh]@54
  char v180; // [sp+76h] [bp-3Ah]@54
  char v181; // [sp+88h] [bp-28h]@51
  char v182; // [sp+89h] [bp-27h]@56
  char v183; // [sp+8Ah] [bp-26h]@56
  char v184; // [sp+9Ch] [bp-14h]@51
  char v185; // [sp+9Dh] [bp-13h]@52
  char v186; // [sp+9Eh] [bp-12h]@52
  char *tmp = (char *)malloc(15);
  memcpy(screenBuffer, graphicsGeneral.menubg5Bpk, 0x4B000u);
  drawImageWithPosition((int)graphicsGeneral.rank1cBpk, 54, 386, (int)((char *)screenBuffer + 54060));
  drawImageWithPosition((int)graphicsGeneral.resupok1Bpk, 272, 386, (int)((char *)screenBuffer + 54114));
  if ( isMultiplayerGame )
  {
    drawImageWithPosition((int)graphicsGeneral.resupok1Bpk, 272, 386, (int)((char *)screenBuffer + 53770));
    v175 = 1919251558;
    v173 = 1952543827;
    v174 = 1629516661;
    LOWORD(v176) = 32;
    SDL_itoa(drivers[driverId].totalRaces, DstBuf, 10);
    v0 = strlen(DstBuf) + 1;
    v1 = &DstBuf[19];
    do
      v2 = (v1++)[1];
    while ( v2 );
    memcpy(v1, DstBuf, v0);
    v3 = &DstBuf[19];
    do
      v4 = (v3++)[1];
    while ( v4 );
    *(_DWORD *)v3 = 1667330592;
    *((_DWORD *)v3 + 1) = 695412837;
    v5 = (int)graphicsGeneral.fsma3aBpk;
    v3[8] = 0;
    drawTextWithFont(v5, (int)&letterSpacing_4458B0, (const char *)&v173, 289326);
    if ( isMultiplayerGame )
      drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Multiplayer Ranking", 55096);
  }
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Your Statistics:", 55456);
  
  /*v6 = &v171;
  do
    v7 = (v6++)[1];
  while ( v7 );
  */
  
  v8 = (int)graphicsGeneral.fsma3aBpk;
  /**(_WORD *)v6 = 46;
  LOBYTE(v175) = 0;*/
  drawTextWithFont(v8, (int)&letterSpacing_4458B0, "Position", 73960);
  
  memset(DstBuf, 0, 20);
  memset(tmp, 0, 15);

  strcat(DstBuf, ":  ");
  SDL_itoa(drivers[driverId].rank, tmp, 10);
  strcat(DstBuf, tmp);
  strcat(DstBuf, ".");

  /*BYTE2(v173) = 0;
  LOWORD(v173) = 8250;
  v9 = strlen(DstBuf) + 1;
  v10 = &DstBuf[19];
  do
    v11 = (v10++)[1];
  while ( v11 );
  
  memcpy(v10, DstBuf, v9);*/
  v12 = (int)graphicsGeneral.fsma3aBpk;
  drawTextWithFont(v12, (int)&letterSpacing_4458B0, DstBuf, 74126);

  memset(DstBuf, 0, 20);
  memset(tmp, 0, 15);
  strcpy(DstBuf, ":  ");
  
  SDL_itoa(drivers[driverId].racesWon, tmp, 10);
  strcat(DstBuf, tmp);
  
  
  //LOWORD(v175) = 110;
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Races won", 88680);
  /*BYTE2(v173) = 0;
  LOWORD(v173) = 8250;
  v13 = strlen(DstBuf) + 1;
  v14 = &DstBuf[19];
  do
    v15 = (v14++)[1];
  while ( v15 );
  
  memcpy(v14, DstBuf, v13);*/
  v16 = (int)graphicsGeneral.fsma3aBpk;
  drawTextWithFont(v16, (int)&letterSpacing_4458B0, DstBuf, 88846);

  memset(DstBuf, 0, 20);
  memset(tmp, 0, 15);
  strcpy(DstBuf, ":  ");
  
  SDL_itoa(drivers[driverId].totalRaces, tmp, 10);
  strcat(DstBuf, tmp);

 
  
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Total races", 103400);
  /*BYTE2(v173) = 0;
  LOWORD(v173) = 8250;
  v17 = strlen(DstBuf) + 1;
  v18 = &DstBuf[19];
  do
    v19 = (v18++)[1];
  while ( v19 );
  memcpy(v18, DstBuf, 4 * (v17 >> 2));
  v20 = isMultiplayerGame == 0;
  memcpy(&v18[4 * (v17 >> 2)], &DstBuf[4 * (v17 >> 2)], v17 & 3);
  if ( !v20 )
  {
    v21 = &DstBuf[19];
    do
      v22 = (v21++)[1];
    while ( v22 );
    v23 = dword_456BC8;
    *(_DWORD *)v21 = 2109216;
    itoa(v23, DstBuf, 10);
    v24 = strlen(DstBuf) + 1;
    v25 = &DstBuf[19];
    do
      v26 = (v25++)[1];
    while ( v26 );
    memcpy(v25, DstBuf, v24);
  }*/
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, DstBuf, 103566);
  memset(DstBuf, 0, 20);
  memset(tmp, 0, 15);
  strcpy(DstBuf, ":  $");
 
  SDL_itoa(drivers[driverId].totalIncome, tmp, 10);
  strcat(DstBuf, tmp);

  //v175 = 1701670755;
  //v173 = 1635020628;
  //LOBYTE(v176) = 0;
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Total income", 118120);
 /* v173 = 2367546;
  v27 = strlen(DstBuf) + 1;
  v28 = &DstBuf[19];
  do
    v29 = (v28++)[1];
  while ( v29 );
  memcpy(v28, DstBuf, v27);*/
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, DstBuf, 118286);
  memset(DstBuf, 0, 20);
  memset(tmp, 0, 15);
  strcpy(DstBuf, ":  $");
  
  SDL_itoa(drivers[driverId].money, tmp, 10);
  strcat(DstBuf, tmp);
  
  //v174 = 1869422700;
  //v175 = 7955822;
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Total money", 132840);
/*  v173 = 2367546;
  v30 = strlen(DstBuf) + 1;
  v31 = &DstBuf[19];
  do
    v32 = (v31++)[1];
  while ( v32 );*/
  v33 = (int)graphicsGeneral.fsma3aBpk;
 // memcpy(v31, DstBuf, v30);
  drawTextWithFont(v33, (int)&letterSpacing_4458B0, DstBuf, 133006);
  result = dword_456BD8;
  
  if ( dword_456BD8 <= 0 )
  {
    dword_456BD8 = 0;
  }
  else
  {
    v35 = selectedRace_462CE8;
    v36 = (unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8];
    v37 = &aSuburbia[15 * v36];
    v38 = (char *)&v173 - 15 * v36 - aSuburbia;
    do
    {
      v39 = *v37;
      v37[v38] = *v37;
      ++v37;
    }
    while ( v39 );
	if (isMultiplayerGame)
	{
		v40 = (unsigned __int8)byte_45FC0F[dword_456BCC];
		v41 = &aSuburbia[15 * v40];
		v42 = (char *)&v173 - 15 * v40 - aSuburbia;
		do
		{
			v43 = *v41;
			v41[v42] = *v41;
			++v41;
		} while (v43);
		SDL_itoa(raceDrivers_456758, DstBuf, 10);
		v44 = &DstBuf[19];
		do
			v45 = (v44++)[1];
		while (v45);
		*(_WORD *)v44 = 32;
		v46 = strlen(DstBuf) + 1;
		v47 = &DstBuf[19];
		do
			v48 = (v47++)[1];
		while (v48);
		memcpy(v47, DstBuf, v46);
		v49 = &DstBuf[19];
		do
			v50 = (v49++)[1];
		while (v50);
		*(_DWORD *)v49 = 1634496557;//easy race
		*((_DWORD *)v49 + 1) = 544367993;
		*((_DWORD *)v49 + 2) = 1701011826;
		*((_WORD *)v49 + 6) = 58;
	}
	else if (selectedRace_462CE8)
	{
		switch (selectedRace_462CE8)
		{
		case RACE_MEDIUM:
			v111 = &DstBuf[19];
			do
				v112 = (v111++)[1];
			while (v112);
			*(_DWORD *)v111 = 1684368672;//race medium

			*((_DWORD *)v111 + 1) = 544044393;
			*((_DWORD *)v111 + 2) = 1701011826;
			*((_WORD *)v111 + 6) = 58;
			break;
		case RACE_HARD:
			v113 = &DstBuf[19];
			do
				v114 = (v113++)[1];
			while (v114);
			*(_DWORD *)v113 = 1918986272;//race hard
			*((_DWORD *)v113 + 1) = 1634869348;
			*((_DWORD *)v113 + 2) = 3827043;
			break;
		case RACE_ARENA:
			v173 = 543516756;//the arena
			v174 = 1852142145;
			LOWORD(v175) = 14945;
			BYTE2(v175) = 0;
			break;
		}
	}
	else
	{
		v109 = (char *)malloc(20);
		strcpy(v109, "easy race:");
     /* v109 = &DstBuf[19];
      do
        v110 = (v109++)[1];
      while ( v110 );
      *(_DWORD *)v109 = 1935762720; //easy race:
      *((_DWORD *)v109 + 1) = 1634869369;
      *((_DWORD *)v109 + 2) = 3827043;*/
    }
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 158440);
    SDL_itoa(dword_456BD8, DstBuf, 10);
    v51 = &v171;
    do
      v52 = (v51++)[1];
    while ( v52 );
    *(_WORD *)v51 = 46;
    v173 = 1667329104;//Plac
    v174 = 6778473;//ing
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 173160);
    LOWORD(v173) = 8250;//:
    BYTE2(v173) = 0;
    v53 = strlen(DstBuf) + 1;
    v54 = &DstBuf[19];
    do
      v55 = (v54++)[1];
    while ( v55 );
    memcpy(v54, DstBuf, v53);
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 173326);
    SDL_itoa(userLasRacePriceIncome_456BDC, DstBuf, 10);
    v173 = 1701011794;//Race
    v174 = 1668180256;//inc
    v175 = 6647151;//ome
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 187880);
    v173 = 2367546;//: 4
    v56 = strlen(DstBuf) + 1;
    v57 = &DstBuf[19];
    do
      v58 = (v57++)[1];
    while ( v58 );
    memcpy(v57, DstBuf, v56);
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 188046);
    SDL_itoa(userLastRaceIncomeNoPrice_456BE0, DstBuf, 10);
    v174 = 1852383347; //s in
    v175 = 1701670755;//come
    v173 = 1970171714;//Bonu
    LOBYTE(v176) = 0;
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 202600);
    v173 = 2367546;//: S
    v59 = strlen(DstBuf) + 1;
    v60 = &DstBuf[19];
    do
      v61 = (v60++)[1];
    while ( v61 );
    v62 = (int)graphicsGeneral.fsma3aBpk;
    memcpy(v60, DstBuf, v59);
    drawTextWithFont(v62, (int)&letterSpacing_4458B0, (const char *)&v173, 202766);
    SDL_itoa(userLasRacePriceIncome_456BDC + userLastRaceIncomeNoPrice_456BE0, DstBuf, 10);
    v173 = 1635020628;//Total
    v175 = 1763730787;//ce i
    v176 = 1836016494;//ncom
    v174 = 1634869356;//l ra
    v177 = 101;///e
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 217320);
    v173 = 2367546;//: e
    v63 = strlen(DstBuf) + 1;
    v64 = &DstBuf[19];
    do
      v65 = (v64++)[1];
    while ( v65 );
    v66 = (int)graphicsGeneral.fsma3aBpk;
    memcpy(v64, DstBuf, v63);
    drawTextWithFont(v66, (int)&letterSpacing_4458B0, (const char *)&v173, 217486);
    SDL_itoa(numberOfLaps, DstBuf, 10);
    v173 = 1651340622;//Numb
    v175 = 1634476134;//f la
    LOWORD(v176) = 29552;//ps
    v174 = 1864397413;//er o
    BYTE2(v176) = 0;
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 232040);
    LOWORD(v173) = 8250;// :
    BYTE2(v173) = 0;
    v67 = strlen(DstBuf) + 1;
    v68 = &DstBuf[19];
    do
      v69 = (v68++)[1];
    while ( v69 );
    memcpy(v68, DstBuf, 4 * (v67 >> 2));
    v70 = (int)graphicsGeneral.fsma3aBpk;
    memcpy(&v68[4 * (v67 >> 2)], &DstBuf[4 * (v67 >> 2)], v67 & 3);
    drawTextWithFont(v70, (int)&letterSpacing_4458B0, (const char *)&v173, 232206);
    SDL_itoa(totalRaceMinutes_45EEC0, &v184, 10);
    SDL_itoa(totalRaceSeconds_45EEBC, &v178, 10);
    SDL_itoa(totalRaceMilliseconds_462D74, &v181, 10);
    if ( strlen(&v184) == 1 )
    {
      v185 = v184;
      v184 = 48;
      v186 = 0;
    }
    if ( strlen(&v178) == 1 )
    {
      v179 = v178;
      v178 = 48;
      v180 = 0;
    }
    if ( strlen(&v181) == 1 )
    {
      v182 = v181;
      v181 = 48;
      v183 = 0;
    }
    v71 = 0;
    do
    {
      v72 = *(&v184 + v71);
      DstBuf[v71++] = v72;
    }
    while ( v72 );
    v73 = &v171;
    do
      v74 = (v73++)[1];
    while ( v74 );
    *(_WORD *)v73 = 58;
    v75 = strlen(&v178) + 1;
    v76 = &v171;
    do
    {
      v77 = *((BYTE *)v76 + 1);
      v76 = (char *)v76 + 1;
    }
    while ( v77 );
    memcpy(v76, &v178, v75);
    v78 = &v171;
    do
      v79 = (v78++)[1];
    while ( v79 );
    *(_WORD *)v78 = 46;
    v80 = strlen(&v181) + 1;
    v81 = &v171;
    do
    {
      v82 = *((BYTE *)v81 + 1);
      v81 = (char *)v81 + 1;
    }
    while ( v82 );
    memcpy(v81, &v181, v80);
    v173 = 1701011794;//Race
    v174 = 1835627552;//tim
    LOWORD(v175) = 101;//e
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 246760);
    BYTE2(v173) = 0;
    LOWORD(v173) = 8250;// :
    v83 = strlen(DstBuf) + 1;
    v84 = &DstBuf[19];
    do
      v85 = (v84++)[1];
    while ( v85 );
    v86 = (int)graphicsGeneral.fsma3aBpk;
    memcpy(v84, DstBuf, v83);
    drawTextWithFont(v86, (int)&letterSpacing_4458B0, (const char *)&v173, 246926);
    v87 = 27 * driverId;
    v88 = &circuitsToSelect_46126C[selectedRace_462CE8];
    v89 = 24 * ((unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] + 18 * drivers[driverId].carType);
    v90 = currentRaceBestLapSeconds_45EB48;
    v91 = currentRaceBestLapMinutes_463CAC;
    if ( currentRaceBestLapMilliseconds_461FEC + 100 * (currentRaceBestLapSeconds_45EB48 + 60 * currentRaceBestLapMinutes_463CAC) < *(int *)((char *)&dword_45F054 + v89)
                                                                 + 100
                                                                 * (*(int *)((char *)&dword_45F050 + v89)
                                                                  + 60 * *(int *)((char *)&dword_45F04C + v89))
      && currentRaceBestLapMinutes_463CAC + currentRaceBestLapSeconds_45EB48 + currentRaceBestLapMilliseconds_461FEC )
    {
      v92 = &byte_460840[v87 * 4];
      v93 = (unsigned __int8)*v88 + 18 * drivers[driverId].carType;
      v94 = (char *)(24 * v93 + 4583488);
      //TODO FIX configuration.circuitRecords v95 = &configuration.byte_45F040[24 * v93 - (_DWORD)v92];
      do
      {
        v96 = *v92;
        v95[(_DWORD)v92] = *v92;
        ++v92;
      }
      while ( v96 );
      _strupr(v94);
      v87 = 27 * driverId;
      v90 = currentRaceBestLapSeconds_45EB48;
      v97 = currentRaceBestLapMilliseconds_461FEC;
      v88 = &circuitsToSelect_46126C[selectedRace_462CE8];
      v91 = currentRaceBestLapMinutes_463CAC;

	  //esto es de circuit record
      v98 = 24 * ((unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] + 18 * drivers[driverId].carType);
      *(int *)((char *)&dword_45F04C + v98) = currentRaceBestLapMinutes_463CAC;
      *(int *)((char *)&dword_45F050 + v98) = v90;
      *(int *)((char *)&dword_45F054 + v98) = v97;
    }
    v99 = 24 * ((unsigned __int8)*v88 + 18 * drivers[driverId].carType);
    if ( *(int *)((char *)&dword_45F04C + v99)
       + *(int *)((char *)&dword_45F050 + v99)
       + *(int *)((char *)&dword_45F054 + v99)
      || currentRaceBestLapMilliseconds_461FEC + 100 * (v90 + 60 * v91) <= 0 )
    {
      v104 = 0;
    }
    else
    {
      v100 = &byte_460840[v87 * 4];
      v101 = (unsigned __int8)*v88 + 18 * drivers[driverId].carType;
      v102 = (char *)(24 * v101 + 4583488);
      //TODO FIX configuration.circuitRecords v103 = &configuration.byte_45F040[24 * v101 - (_DWORD)v100];
      v104 = 0;
      do
      {
        v105 = *v100;
        v103[(_DWORD)v100] = *v100;
        ++v100;
      }
      while ( v105 );
      _strupr(v102);
      v91 = currentRaceBestLapMinutes_463CAC;
      v106 = currentRaceBestLapMilliseconds_461FEC;
      v107 = currentRaceBestLapSeconds_45EB48;
      v108 = 24 * ((unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] + 18 * drivers[driverId].carType);
      *(int *)((char *)&dword_45F04C + v108) = currentRaceBestLapMinutes_463CAC;
      *(int *)((char *)&dword_45F050 + v108) = v107;
      *(int *)((char *)&dword_45F054 + v108) = v106;
    }
    SDL_itoa(v91, &v184, 10);
    SDL_itoa(currentRaceBestLapSeconds_45EB48, &v178, 10);
    SDL_itoa(currentRaceBestLapMilliseconds_461FEC, &v181, 10);
    v115 = &v184;
    do
      v116 = *v115++;
    while ( v116 != v104 );
    if ( v115 - &v185 == 1 )
    {
      v185 = v184;
      v184 = 48;
      v186 = v104;
    }
    v117 = &v178;
    do
      v118 = *v117++;
    while ( v118 != v104 );
    if ( v117 - &v179 == 1 )
    {
      v179 = v178;
      v178 = 48;
      v180 = v104;
    }
    v119 = &v181;
    do
      v120 = *v119++;
    while ( v120 != v104 );
    if ( v119 - &v182 == 1 )
    {
      v182 = v181;
      v181 = 48;
      v183 = v104;
    }
    v121 = 0;
    do
    {
      v122 = *(&v184 + v121);
      DstBuf[v121++] = v122;
    }
    while ( v122 != v104 );
    v123 = &v171;
    do
      v124 = (v123++)[1];
    while ( v124 != v104 );
    v125 = &v178;
    *(_WORD *)v123 = 58;
    do
      v126 = *v125++;
    while ( v126 != v104 );
    v127 = v125 - &v178;
    v128 = &v171;
    do
    {
      v129 = *((BYTE *)v128 + 1);
      v128 = (char *)v128 + 1;
    }
    while ( v129 != v104 );
    memcpy(v128, &v178, v127);
    v130 = &v171;
    do
      v131 = (v130++)[1];
    while ( v131 != v104 );
    *(_WORD *)v130 = 46;
    v132 = &v181;
    do
      v133 = *v132++;
    while ( v133 != v104 );
    v134 = v132 - &v181;
    v135 = &v171;
    do
    {
      v136 = *((BYTE *)v135 + 1);
      v135 = (char *)v135 + 1;
    }
    while ( v136 != v104 );
    memcpy(v135, &v181, v134);
    v173 = 1953719618;//Best
    v174 = 1885432864;//lap
    LOBYTE(v175) = 0;
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 261480);
    LOWORD(v173) = 8250;// :
    v137 = DstBuf;
    BYTE2(v173) = 0;
    do
      v138 = *v137++;
    while ( v138 != v104 );
    v139 = v137 - DstBuf;
    v140 = &DstBuf[19];
    do
      v141 = (v140++)[1];
    while ( v141 != v104 );
    memcpy(v140, DstBuf, 4 * (v139 >> 2));
    v142 = (int)graphicsGeneral.fsma3aBpk;
    memcpy(&v140[4 * (v139 >> 2)], &DstBuf[4 * (v139 >> 2)], v139 & 3);
    drawTextWithFont(v142, (int)&letterSpacing_4458B0, (const char *)&v173, 261646);
    SDL_itoa(
      *(&dword_45F04C + 6 * ((unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] + 18 * drivers[driverId].carType)),
      &v184,
      10);
    SDL_itoa(
      *(&dword_45F050 + 6 * ((unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] + 18 * drivers[driverId].carType)),
      &v178,
      10);
    SDL_itoa(
      *(&dword_45F054 + 6 * ((unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] + 18 * drivers[driverId].carType)),
      &v181,
      10);
    v143 = &v184;
    do
      v144 = *v143++;
    while ( v144 != v104 );
    if ( v143 - &v185 == 1 )
    {
      v185 = v184;
      v184 = 48;
      v186 = v104;
    }
    v145 = &v178;
    do
      v146 = *v145++;
    while ( v146 != v104 );
    if ( v145 - &v179 == 1 )
    {
      v179 = v178;
      v178 = 48;
      v180 = v104;
    }
    v147 = &v181;
    do
      v148 = *v147++;
    while ( v148 != v104 );
    if ( v147 - &v182 == 1 )
    {
      v182 = v181;
      v181 = 48;
      v183 = v104;
    }
    v149 = 0;
    do
    {
      v150 = *(&v184 + v149);
      DstBuf[v149++] = v150;
    }
    while ( v150 != v104 );
    v151 = &v171;
    do
      v152 = (v151++)[1];
    while ( v152 != v104 );
    v153 = &v178;
    *(_WORD *)v151 = 58;
    do
      v154 = *v153++;
    while ( v154 != v104 );
    v155 = v153 - &v178;
    v156 = &v171;
    do
    {
      v157 = *((BYTE *)v156 + 1);
      v156 = (char *)v156 + 1;
    }
    while ( v157 != v104 );
    memcpy(v156, &v178, v155);
    v158 = &v171;
    do
      v159 = (v158++)[1];
    while ( v159 != v104 );
    v160 = &v181;
    *(_WORD *)v158 = 46;
    do
      v161 = *v160++;
    while ( v161 != v104 );
    v162 = v160 - &v181;
    v163 = &v171;
    do
    {
      v164 = *((BYTE *)v163 + 1);
      v163 = (char *)v163 + 1;
    }
    while ( v164 != v104 );
    memcpy(v163, &v181, v162);
    v174 = 1885432864;//lap
    v175 = 1702257952;//eve
    v173 = 1953719618;//Best
    LOWORD(v176) = 114;//r
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v173, 276200);
    LOWORD(v173) = 8250;// :
    v165 = DstBuf;
    BYTE2(v173) = 0;
    do
      v166 = *v165++;
    while ( v166 != v104 );
    v167 = v165 - DstBuf;
    v168 = &DstBuf[19];
    do
      v169 = (v168++)[1];
    while ( v169 != v104 );
    memcpy(v168, DstBuf, 4 * (v167 >> 2));
    v170 = (int)graphicsGeneral.fsma3aBpk;
    memcpy(&v168[4 * (v167 >> 2)], &DstBuf[4 * (v167 >> 2)], v167 & 3);
    result = drawTextWithFont(v170, (int)&letterSpacing_4458B0, (const char *)&v173, 276366);
    dword_456BD8 = 0;
  }
  return result;
}

//----- (00425980) --------------------------------------------------------
//int   writeDriverList(int a1)

//----- (00425BD0) --------------------------------------------------------
int   drawRightPositions(int numDrivers, int a2)
{
  int v2; // ebx@1
  int v3; // eax@1
  int v4; // esi@1
  int v5; // eax@1
  int v6; // esi@2
  int v7; // ebx@3
  int v8; // ebp@3
  char *v9=malloc(100); // edi@3
//  char v10; // al@4
  unsigned int v11; // edx@5
  char *v12 = malloc(100); // eax@5
//  char v13; // cl@6
  char *v14 = malloc(100); // ecx@9
//  char v15; // dl@10
  int v16; // eax@15
  char *v17 = malloc(100); // edx@15
  signed int v18; // ecx@15
  int v19; // eax@15
  double v20; // st7@15
  int v21; // eax@16
  char *v22 = malloc(100); // edx@16
  signed int v23; // ecx@16
  int v24; // eax@16
  float v25; // ST30_4@17
  int v26; // eax@19
  char *v27 = malloc(100); // edx@19
  signed int v28; // ecx@19
  int v29; // eax@19
  double v30; // st7@19
  int v31; // eax@20
  char *v32 = malloc(100); // edx@20
  signed int v33; // ecx@20
  int v34; // eax@20
  float v35; // ST38_4@21
  int v36; // eax@24
  char *v37 = malloc(100); // edx@24
  signed int v38; // ecx@24
  int v39; // eax@24
  double v40; // st7@24
  int v41; // eax@25
  char *v42 = malloc(100); // edx@25
  signed int v43; // ecx@25
  int v44; // eax@25
  float v45; // ST38_4@26
  int v46; // eax@29
  char *v47 = malloc(100); // edx@29
  signed int v48; // ecx@29
  int v49; // eax@29
  float v50; // ST40_4@29
  float v51; // ST3C_4@29
  float v52; // ST38_4@29
  int result; // eax@29
  int v54; // eax@30
  char *v55 = malloc(100); // edx@30
  signed int v56; // ecx@30
  int v57; // eax@30
  float v58; // ST40_4@30
  float v59; // ST3C_4@30
  float v60; // ST38_4@30
  float v61; // [sp+4h] [bp-34h]@15
  float v62; // [sp+8h] [bp-30h]@15
  float v63; // [sp+Ch] [bp-2Ch]@19
  float v64; // [sp+Ch] [bp-2Ch]@24
  float v65; // [sp+10h] [bp-28h]@19
  float v66; // [sp+10h] [bp-28h]@24
  int v67; // [sp+14h] [bp-24h]@5
  int v68; // [sp+18h] [bp-20h]@1
  int v69; // [sp+1Ch] [bp-1Ch]@2
//  int v70; // [sp+20h] [bp-18h]@3
  char DstBuf[20]; // [sp+24h] [bp-14h]@3
  char *tmp = malloc(20);
  v2 = *(_DWORD *)a2;
  v3 = (350 - 79 * numDrivers) / (numDrivers + 1);
  a2 = *(_DWORD *)a2;
  v68 = 0;
  v4 = v3 + 108;
  v5 = v3 + 79;
  if (numDrivers > 0 )
  {
    v69 = 640 * v5;
    v6 = 640 * v4;
    do
    {
      v7 = *((BYTE *)&a2 + v68);
      //v8 = 27 * v7;
	  v8 =  v7;
	  memset(DstBuf, 0, 20);
	  
	  memset(tmp, 0, 20);
      SDL_itoa(drivers[v7].rank, tmp, 10);
	  strcpy(DstBuf, tmp);
	  strcat(DstBuf, ".");
	  //itoa(dword_460888[27 * v7], DstBuf, 10);
      /*v9 = (char *)&v70 + 3;
      do
        v10 = (v9++)[1];
      while ( v10 );
    //  *(_WORD *)v9 = 46;
      
      v12 = DstBuf;*/
	  v11 = 0;
      v67 = 0;
      /*do
        v13 = *v12++;
      while ( v13 );
      v70 = v12 - &DstBuf[1];*/
      //if ( v12 != &DstBuf[1] )
      //{
        do
          v67 += (unsigned __int8)letterSpacing_4458B0[90+(unsigned __int8)DstBuf[v11++]];
        while ( v11 < strlen(DstBuf) );
      //}
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v6 - v67 + 33700);	  
	  strcpy(DstBuf,drivers[v8].name);
	  //v14 = &byte_460840[v8 * 4];
     /* do
      {
        v15 = *v14;
        v14[&DstBuf[-108 * v7] - byte_460840] = *v14;
        ++v14;
      }
	  
      while ( v15 );*/
      _strupr(DstBuf);
      drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, DstBuf, v6 + 36975);
      drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + drivers[v8].face), 64, 64, (int)((char *)screenBuffer + v6 + 2342));
	  //drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + dword_460880[v8]), 64, 64, (int)((char *)screenBuffer + v6 + 2342));
      drawImageWithPosition2(
        (int)((char *)graphicsGeneral.carresBpk + 5200 * (v68 + 4 * drivers[v8].carType)),
        100,
        52,
        (int)((char *)screenBuffer + v6 + 490));
	  /*drawImageWithPosition2(
		  (int)((char *)graphicsGeneral.carresBpk + 5200 * (v68 + 4 * dword_46085C[v8])),
		  100,
		  52,
		  (int)((char *)screenBuffer + v6 + 490));*/
      v6 += v69;
      ++v68;
    }
    while ( v68 < numDrivers);
    LOWORD(v2) = a2;
  }
  sub_4224E0();
	  if ( (unsigned __int8)v2 == driverId || isMultiplayerGame )
  {
	v21 = drivers[(unsigned __int8)v2].colour;
	//v21 = dword_46086C[27 * (unsigned __int8)v2];
    v22 = (char *)graphicsGeneral.copperPal + 2 * v21;
    v23 = (unsigned __int8)v22[v21 + 2];
    v24 = (int)&v22[v21];
    v62 = (double)v23;
    v61 = (double)*(BYTE *)(v24 + 1);
    v20 = (double)*(BYTE *)v24;
  }
  else
  {
    v16 = drivers[(unsigned __int8)v2].colour;
	///v16 = dword_46086C[27 * (unsigned __int8)v2];
    v17 = (char *)graphicsGeneral.carcolPal + 2 * v16;
    v18 = (unsigned __int8)v17[v16 + 2];
    v19 = (int)&v17[v16];
    v62 = (double)v18;
    v61 = (double)*(BYTE *)(v19 + 1);
    v20 = (double)*(BYTE *)v19;
  }
  v25 = v20;
  sub_424240(64, v25, v61, v62);
  if ( BYTE1(v2) == driverId || isMultiplayerGame )
  {
    v31 = drivers[BYTE1(v2)].colour;
	//v31 = dword_46086C[27 * BYTE1(v2)];
    v32 = (char *)graphicsGeneral.copperPal + 2 * v31;
    v33 = (unsigned __int8)v32[v31 + 2];
    v34 = (int)&v32[v31];
    v65 = (double)v33;
    v63 = (double)*(BYTE *)(v34 + 1);
    v30 = (double)*(BYTE *)v34;
  }
  else
  {
    v26 = drivers[BYTE1(v2)].colour;
	//v26 = dword_46086C[27 * BYTE1(v2)];
    v27 = (char *)graphicsGeneral.carcolPal + 2 * v26;
    v28 = (unsigned __int8)v27[v26 + 2];
    v29 = (int)&v27[v26];
    v65 = (double)v28;
    v63 = (double)*(BYTE *)(v29 + 1);
    v30 = (double)*(BYTE *)v29;
  }
  v35 = v30;
  sub_424240(80, v35, v63, v65);
  if ( BYTE2(a2) == driverId || isMultiplayerGame && raceDrivers_456758 > 2 )
  {
    v41 = drivers[BYTE2(v2)].colour;
	//v41 = dword_46086C[27 * BYTE2(a2)];
    v42 = (char *)graphicsGeneral.copperPal + 2 * v41;
    v43 = (unsigned __int8)v42[v41 + 2];
    v44 = (int)&v42[v41];
    v66 = (double)v43;
    v64 = (double)*(BYTE *)(v44 + 1);
    v40 = (double)*(BYTE *)v44;
  }
  else
  {
    v36 = drivers[BYTE2(v2)].colour;
	//v36 = dword_46086C[27 * BYTE2(a2)];
    v37 = (char *)graphicsGeneral.carcolPal + 2 * v36;
    v38 = (unsigned __int8)v37[v36 + 2];
    v39 = (int)&v37[v36];
    v66 = (double)v38;
    v64 = (double)*(BYTE *)(v39 + 1);
    v40 = (double)*(BYTE *)v39;
  }
  v45 = v40;
  sub_424240(224, v45, v64, v66);
  if ( BYTE3(a2) == driverId || isMultiplayerGame && raceDrivers_456758 > 3 )
  {
    v54 = drivers[BYTE3(v2)].colour;
	//v54 = dword_46086C[27 * BYTE3(a2)];
    v55 = (char *)graphicsGeneral.copperPal + 2 * v54;
    v56 = (unsigned __int8)v55[v54 + 2];
    v57 = (int)&v55[v54];
    v58 = (double)v56;
    v59 = (double)*(BYTE *)(v57 + 1);
    v60 = (double)*(BYTE *)v57;
    result = sub_424240(240, v60, v59, v58);
  }
  else
  {
    v46 = drivers[BYTE3(v2)].colour;
	//v46 = dword_46086C[27 * BYTE3(a2)];
    v47 = (char *)graphicsGeneral.carcolPal + 2 * v46;
    v48 = (unsigned __int8)v47[v46 + 2];
    v49 = (int)&v47[v46];
    v50 = (double)v48;
    v51 = (double)*(BYTE *)(v49 + 1);
    v52 = (double)*(BYTE *)v49;
    result = sub_424240(240, v52, v51, v50);
  }
  return result;
}

//----- (00426080) --------------------------------------------------------
signed int sub_426080()
{
  int v0; // edx@1
  signed int result; // eax@1
  char *v2; // esi@2
  char *v3; // edi@2

  v0 = 0;
  result = 100368;
  do
  {
    v2 = (char *)graphicsGeneral.resupok1Bpk + result;
    v3 = (char *)screenBuffer + v0 + 290274;
    result += 272;
    v0 += 640;
    memcpy(v3, v2, 0x110u);
  }
  while ( result < 104992 );
  return result;
}

//----- (004260D0) --------------------------------------------------------
int drawPressAnyKeyToContinue()
{
  int result; // eax@1

  result = waitCounter2_456BE4++ + 1;
  if ( waitCounter2_456BE4 == 30 )
  {
    sub_426080();
    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Press any key to continue..."), 289646);
    result = drawKeyCursor(289634, (char *)screenBuffer + 289634, 0x10Eu, 16);
  }
  if ( waitCounter2_456BE4 == 60 )
  {
    sub_426080();
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Press any key to continue..."), 289646);
    result = drawKeyCursor(289634, (char *)screenBuffer + 289634, 0x10Eu, 16);
    waitCounter2_456BE4 = 0;
  }
  return result;
}
// 4458B0: using guessed type char letterSpacing_4458B0;
// 456BE4: using guessed type int waitCounter2_456BE4;

//----- (00424240) --------------------------------------------------------
int   sub_424240(int a1, float a2, float a3, float a4)
{
  signed int v4; // edi@1
  int v5; // esi@1
  float v6; // ST2C_4@2
  float v7; // ST30_4@2
  float v8; // ST34_4@2
  float v9; // ST28_4@2
  signed int v10; // edi@3
  int v11; // esi@3
  float v12; // ST2C_4@4
  float v13; // ST30_4@4
  float v14; // ST34_4@4
  float v15; // ST28_4@4
  int result; // eax@4
  signed int v17; // [sp+4h] [bp-28h]@1
  signed int v18; // [sp+4h] [bp-28h]@3
  double v19; // [sp+14h] [bp-18h]@1
  double v20; // [sp+1Ch] [bp-10h]@1
  double v21; // [sp+24h] [bp-8h]@1
   int index = 0;
  v4 = 0;
  v19 = 0.1 * a2;
  v17 = 0;
  
  v5 = ((12 * a1) / 4)-1;
  //v5 = 12 * a1 + 4586564; //45FC44
 
  v20 = 0.1 * a3;
  v21 = 0.1 * a4;
  do
  {
    v9 = (double)v17;
    v6 = (a2 - v19) * 0.125;
    palette1[v5] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v9 * v6 + v19) << 16, 6553600);
    v7 = (a3 - v20) * 0.125;
	palette1[v5+1] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v9 * v7 + v20) << 16, 6553600);
    v8 = (a4 - v21) * 0.125;
	palette1[v5+2] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v9 * v8 + v21) << 16, 6553600);
    v5 += 3;
    ++v4;
    v17 = v4;
	
  }
  while ( v4 < 8 );
 /* do
  {
	  v9 = (double)v17;
	  v6 = (a2 - v19) * 0.125;
	  *(_DWORD *)(v5 - 4) = colorToPaletteEntry((unsigned int)(unsigned __int64)(v9 * v6 + v19) << 16, 6553600);
	  v7 = (a3 - v20) * 0.125;
	  *(_DWORD *)v5 = colorToPaletteEntry((unsigned int)(unsigned __int64)(v9 * v7 + v20) << 16, 6553600);
	  v8 = (a4 - v21) * 0.125;
	  *(_DWORD *)(v5 + 4) = colorToPaletteEntry((unsigned int)(unsigned __int64)(v9 * v8 + v21) << 16, 6553600);
	  v5 += 12;
	  ++v4;
	  v17 = v4;
  } while (v4 < 8);*/
  v10 = 0;
  v18 = 0;
  v11 = (12 * (a1+8) / 4)-1;
  //v11 = 12 * (a1 + 8) + 4586564;//45FC44
  do
  {
    v15 = (double)v18;
    v12 = (63.0 - a2) * 0.125;
   palette1[v11] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v15 * v12 + a2) << 16, 6553600);
    v13 = (63.0 - a3) * 0.125;
	palette1[v11+1] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v15 * v13 + a3) << 16, 6553600);
    v14 = (63.0 - a4) * 0.125;
    result = colorToPaletteEntry((unsigned int)(unsigned __int64)(v15 * v14 + a4) << 16, 6553600);
	palette1[v11+2] = result;
    v11 += 3;
    ++v10;
    v18 = v10;
  }
  while ( v10 < 8 );
  /*do
  {
    v15 = (double)v18;
    v12 = (63.0 - a2) * 0.125;
    *(_DWORD *)(v11 - 4) = colorToPaletteEntry((unsigned int)(unsigned __int64)(v15 * v12 + a2) << 16, 6553600);
    v13 = (63.0 - a3) * 0.125;
    *(_DWORD *)v11 = colorToPaletteEntry((unsigned int)(unsigned __int64)(v15 * v13 + a3) << 16, 6553600);
    v14 = (63.0 - a4) * 0.125;
    result = colorToPaletteEntry((unsigned int)(unsigned __int64)(v15 * v14 + a4) << 16, 6553600);
    *(_DWORD *)(v11 + 4) = result;
    v11 += 12;
    ++v10;
    v18 = v10;
  }
  while ( v10 < 8 );*/
  return result;
}
