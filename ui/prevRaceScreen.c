#include "prevRaceScreen.h"

#include "util/menus.h"
#include "blackMarketScreen.h"
#include "../imageUtil.h"
#include "../config.h"
#include "../defs.h"
#include "../dr.h"
#include "../graphics.h"
#include "../asset/bpaUtil.h"
#include "../drivers.h"
#include "../raceParticipant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

char aThisIsIt_Here_[68] = "This is it. Here. Now. In Death Rally, where life is short and hot,"; // weak
char aFastAndDeadly_[58] = "fast and deadly. The race is on. Watch the road. Hear the"; // weak
char aRumble_WannaPl[62] = "rumble. Wanna play it sweet or play it dirty, by the rules or"; // weak
char aFryTheRulesThe[59] = "fry the rules, there's only one way to do it, play to win."; // weak
int multiplayerWaitCounter_456BE8 = 0; // weak
int dword_4A7AC4; // weak
int dword_4A7A6C; // weak
char prevSreenaStartANewGame[17] = "Start A New Game"; // weak
char prevScreenaStartANewGam_0[17] = "Start A New Game"; // weak
char prevScreenaStartRacing[13] = "Start Racing"; // weak
int dword_45E0A8; // weak
char *tShape[] = { "TSHAPE01" ,"TSHAPE02" ,"TSHAPE03","TSHAPE04" ,"TSHAPE05" ,"TSHAPE06","TSHAPE07" ,"TSHAPE08" ,"TSHAPE09","TSHAPE10" ,"TSHAPE11" ,"TSHAPE12","TSHAPE13" ,"TSHAPE14" ,"TSHAPE15","TSHAPE16" ,"TSHAPE17" ,"TSHAPE18","TSHAPE19" };

//----- (00435320) --------------------------------------------------------
int  adversaryPreviewScreen(const char **a1)
{
  unsigned __int8 v1; // di@1
  signed int v2; // esi@1
  int v3; // ST3C_4@2
  int v4; // ST38_4@2
  int v5; // eax@2
  unsigned __int8 v6; // bp@3
  signed int v7; // esi@3
  char v8; // al@3
  int result; // eax@9
  int v10; // edi@11
  signed int v11; // ebx@11
  signed int v12; // esi@15
  int v13; // ST38_4@16
  int v14; // ST34_4@16
  int v15; // eax@16
  signed int v16; // esi@21
//  signed int v17; // esi@26
  int v18; // eax@27
  char v19; // cl@27
  int v20; // eax@27
//  signed int v21; // edx@29
//  int v22; // ecx@29
  bool v23; // zf@47
  bool v24; // sf@47
  unsigned __int8 v25; // of@47
  const char **v26; // [sp-4h] [bp-38h]@11
  const char **v27; // [sp+0h] [bp-34h]@0
  char v28; // [sp+Bh] [bp-29h]@27
  int v29; // [sp+Ch] [bp-28h]@26
int indexRaceParticipant = 0;
  v1 = -80;

 

  v2 = 528;
  do
  {
  v3 = (convertColorToPaletteColor(palette1[v2+2], 6553600) + 0x8000) >> 16;
  v4 = (convertColorToPaletteColor(palette1[v2 + 1], 6553600) + 0x8000) >> 16;
  v5 = convertColorToPaletteColor(palette1[v2], 6553600);
  setPaletteAndGetValue(v1, (v5 + 0x8000) >> 16, v4, v3);
  v2 += 3;
  ++v1;
  }
  while ( v2 <  528 + 16);

  /*v2 = (signed int)&unk_460484;
  do
  {
    v3 = (convertColorToPaletteColor(*(_DWORD *)(v2 + 4), 6553600) + 0x8000) >> 16;
    v4 = (convertColorToPaletteColor(*(_DWORD *)v2, 6553600) + 0x8000) >> 16;
    v5 = convertColorToPaletteColor(*(_DWORD *)(v2 - 4), 6553600);
    setPaletteAndGetValue(v1, (v5 + 0x8000) >> 16, v4, v3);
    v2 += 12;
    ++v1;
  }
  while ( v2 < (signed int)&unk_4604D8 );*/
  memcpy((void *)dword_45FC00, screenBuffer, 0x4B000u);
  screenBuffer = (void *)dword_45FC00;
  memcpy((void *)(dword_45FC00 + 57600), (char *)graphicsGeneral.menubg5Bpk + 57600, 0x2AA80u);
  v6 = 0;
  memcpy((char *)screenBuffer + 234880, (char *)graphicsGeneral.menubg5Bpk + 234880, 0x2800u);
  drawTransparentBlock(0, 371, 639, 109);
  drawBottomMenuText();
  drawCarRightSide();
  drawImageWithPosition((int)graphics4.badtitBpk, 440, 16, (int)((char *)screenBuffer + 58920));
  drawImageWithPosition((int)graphics4.badsnapBpk, 256, 228, (int)((char *)screenBuffer + 82096));
  drawImageWithPosition((int)graphics4.escboxBpk, 115, 104, (int)((char *)screenBuffer + 154908));
  drawBorder(170, 120, 268, 244);
  screenBuffer = (void *)dword_461250;
  sub_42C4A0();
  refreshAllScreen();
  v7 = 0;
  v8 = 0;
  do
  {
    if ( v8 == 28 || v8 == -100 )
      break;
    if ( v8 == 1 )
      goto LABEL_11;
    ++v7;
    refreshAndCheckConnection_42A570();
    v8 = eventDetected();
  }
  while ( v7 < 480 );
  if ( v8 != 1 )
  {
    selectedRace_462CE8 = 3;
    userRaceOrder_45FC20 = 1;
    userLastRaceIncomeNoPrice_456BE0 = 0;
    userLasRacePriceIncome_456BDC = 0;
    previewRaceScreen(2);
    result = dword_456BD8;
    if ( dword_456BD8 == 1 )
    {
      *(_DWORD *)prevScreenaStartANewGam_0 = *(_DWORD *)"Start A New Game";
      *(_DWORD *)&prevScreenaStartANewGam_0[4] = *(_DWORD *)"t A New Game";
      *(_DWORD *)&prevScreenaStartANewGam_0[8] = *(_DWORD *)"New Game";
      *(_DWORD *)&prevScreenaStartANewGam_0[12] = *(_DWORD *)"Game";
      prevScreenaStartANewGam_0[16] = prevSreenaStartANewGame[16];
      *(_DWORD *)prevScreenaStartRacing = 1918989395;
      *(_DWORD *)&prevScreenaStartRacing[4] = 1632772212;
      *(_DWORD *)&prevScreenaStartRacing[8] = 1735289187;
      prevScreenaStartRacing[12] = 0;
	  menuActive_4457F0[10] = 0;
	  menuActive_4457F0[11] = 0;
	  menuActive_4457F0[13] = 0;
      showHardWarningRace = 0;
      showMediumWarningRace = 0;
      showUndergroundPopup_456B78 = 0;
      showWelcomePopup_456B74 = 0;
      result = initDrivers();
      firstRacePlayed_464F44 = 1;
      dword_456B64 = 1;
      dword_445724 = 0;
      dword_456BD8 = 0;
    }
    return result;
  }
LABEL_11:
  v26 = a1;
  loadMenuSoundEffect(1u, 23, 0, configuration.effectsVolume, dword_44518C - 4096);
  sub_4224E0();
  v10 = 6553600;
  v11 = 65500;
  do
  {
    if ( useWeapons && undergroundPricesSet_456B84 )
      setMusicVolume(v11);
    waitWithRefresh();
	v12 = 0;
	//v12 = (signed int)dword_45FC44;
    do
    {
      v13 = (convertColorToPaletteColor((palette1[v12+2]), v10) + 0x8000) >> 16;
      v14 = (convertColorToPaletteColor(palette1[v12 + 1], v10) + 0x8000) >> 16;
      v15 = convertColorToPaletteColor((palette1[v12 ]), v10);
      setPaletteAndGetValue(v6, (v15 + 0x8000) >> 16, v14, v13);
      v12 += 3;
      ++v6;
    }
    while ( v12 <maxPaletteEntries );
    v11 -= 1310;
    v10 -= 0x20000;
    v6 = 0;
  }
  while ( v11 >= 0 );
  if ( useWeapons && undergroundPricesSet_456B84 )
  {
    musicSetOrder(dword_462D7C);
    dword_456B60 = 1;
    stopSoundChannel_43C3E0(1u);
  }
  loadPaletteMenu();
  v16 = 0;
  do
    setPaletteAndGetValue(v16++, 0, 0, 0);
  while ( v16 < 256 );
  do
  {
    do
      addParticipantToRace(1);
    while (participantsRace[1] < 4u );
	//while ((unsigned __int8)word_461EB4 < 4u);
	
  }
  while (participantsRace[0] < 4u || participantsRace[2] < 4u );
  //while (HIBYTE(word_461EB4) < 4u || (unsigned __int8)byte_461EB6 < 4u);
  v29 = 0;
  indexRaceParticipant = 0;
 // v17 = (signed int)dword_4A7AA0;
  do
  {
    do
    {
      v18 = rand() % 4;
      v19 = *(&v28 + v18 + 1);
      v20 = v18 + 1;
      raceParticipant[indexRaceParticipant].racePosition = v20;
    }
    while ( v19 );
    //v17 += 84;
    *(&v28 + v20) = 1;

	indexRaceParticipant++;
  }
  while (indexRaceParticipant < 4 );
  //while (v17 < (signed int)&unk_4A7BF0);
  postRaceMain(1, v26, v27);
  result = 0;
  result = getMaxDriverPoints(driverId);
  if ( isMultiplayerGame
    || (v25 = __OFSUB__(drivers[driverId].points, result),
        v23 = drivers[driverId].points == result,
        v24 = drivers[driverId].points - result < 0,
        sabotageAvailable_45EFFC = 0,
        (unsigned __int8)(v24 ^ v25) | v23) )
    sabotageAvailable_45EFFC = 1;
  dword_456B58 = 1;
  return result;
}

//----- (004321B0) --------------------------------------------------------
void   previewRaceScreen(signed int participants)
{
  signed int v1; // edi@2
  signed int v2; // esi@2
  int v3; // ecx@3
  int v4; // edx@4
  unsigned int v5; // eax@4
  signed int v6; // edi@8
  signed int v7; // esi@8
  int v8; // ecx@9
  int v9; // edx@10
  unsigned int v10; // eax@10
  void *v11 = malloc(4u); // eax@14
  int v12; // eax@14
  char *v13; // ecx@14
  signed int v14; // eax@14
  char v15; // dl@15
  char *v16; // edi@16
  char v17; // al@17
  char v18; // bl@18
  int v19; // eax@18
  int *v20; // ecx@18
  signed int v21; // eax@18
  char v22; // dl@19
  int v23; // eax@21
  char *v24; // eax@22
//  signed int v25; // edx@22
//  char v26; // cl@23
//  char *v27; // edi@24
//  char v28; // al@25
  int *v29; // ecx@26
  signed int v30; // eax@26
  char v31; // dl@27
//  char *v32; // eax@29
//  signed int v33; // edx@29
//  char v34; // cl@30
//  char *v35; // edi@31
//  char v36; // al@32
  int *v37; // ecx@33
  signed int v38; // eax@33
  char v39; // dl@34
//  char *v40; // eax@36
//  signed int v41; // edx@36
//  char v42; // cl@37
//  char *v43; // edi@38
//  char v44; // al@39
  int *v45; // ecx@40
  signed int v46; // eax@40
  char v47; // dl@41
//  unsigned __int8 v48; // cl@45
//  unsigned __int8 v49; // dl@45
//  unsigned __int8 v50; // cl@45
//  unsigned int v51; // eax@47
//  char *v52; // edi@47
//  char v53; // cl@48
  char *v54; // edi@50
  char v55; // al@51
  double v56; // st7@52
  unsigned int v57; // eax@52
  char *v58; // edi@52
  char v59; // cl@53
  char *v60=malloc(10); // edi@56
//  char v61; // al@57
  char *v62 = malloc(10); // edi@60
//  char v63; // al@61
  char *v64 = malloc(10); // edi@64
//  char v65; // al@65
  char *v66 = malloc(10); // edi@68
//  char v67; // al@69
  char *v68; // eax@71
  int v69; // edi@71
  unsigned int v70; // edx@71
  char v71; // cl@72
  int v72; // ebp@76
  int v73; // esi@76
  char *v74; // edi@76
  char v75; // al@77
  char *v76; // eax@78
  int v77; // ebx@78
  unsigned int v78; // edx@78
  char v79; // cl@79
  char *v80; // ecx@82
  char v81; // dl@83
  signed int i; // ebp@85
//  int v83; // esi@86
//  int v84; // ebx@86
//  char *v85; // edi@86
//  char v86; // al@87
  unsigned int v87; // edx@88
//  char *v88; // eax@88
//  char v89; // cl@89
//  char *v90; // ecx@92
//  char v91; // dl@93
  int v92; // eax@99
  void *v93 = malloc(4u); // eax@100
  int v94; // edi@100
  signed int v95; // esi@100
  int v96; // edx@112

//  signed int v98; // esi@112
//  int v99; // ecx@112
  int numberOfParticipants; // ebp@132
  signed int v101; // ebx@132
//  int v102; // esi@133
  int v103; // edi@134
//  char *v104; // eax@134
//  char v105; // dl@135
  int v106; // ecx@136
//  int v107; // eax@136
  bool v108; // zf@136
  int v109; // ecx@139
//  int v110; // eax@139
  int v111; // eax@147
  void *v112; // ecx@150
  int v113; // eax@152
  char *v114; // eax@152
  int v115; // eax@152
  char *v116; // eax@153
//  signed int v117; // eax@162
  int maxPoints; // ebx@164
  int v119; // eax@164
  
  int v121; // edx@170
  int userPoints; // esi@170
  int v123; // eax@173
  int v124; // edi@173
  
  int v126; // edi@207
  int v127; // ebx@207
  int v128; // eax@207
  int v129; // eax@207
  signed int v130; // edx@207
  int v131; // ecx@207
  int v132; // edx@224
  signed int v133; // edx@226
  int v134; // eax@226
//  int v135; // ecx@227
//  signed int v136; // eax@265
  int v137; // eax@267
  int v138; // edx@267
  int v139; // ecx@267
  int v140; // ebp@267
  signed int v141; // ecx@267
  int v142; // eax@267
  int v143; // ebx@291
  int v144; // eax@291
 // signed int v145; // esi@291
  int v146; // ecx@294
  signed int v147; // ecx@296
  signed int v148; // ecx@309
  signed int v149; // ecx@322
  signed int v150; // ecx@335
  int v151; // edx@351
  int v152; // edx@363
  int v153; // edx@375
  int v154; // ecx@387
  int v155; // ecx@391
//  char v156; // bl@392
//  int v157; // ebp@392
//  bool v158; // sf@392
//  unsigned __int8 v159; // of@392
//  char v160; // al@392
//  char v161; // al@392
//  signed int v162; // edx@392
//  signed int v163; // eax@394
//  char v164; // cl@395
//  char *v165; // eax@397
//  char *v166; // edx@397
//  char v167; // cl@398
//  unsigned int v168; // eax@399
//  char *v169; // edi@399
//  char v170; // cl@400
//  char *v171; // edi@401
//  char v172; // al@402
//  signed int v173; // edx@403
//  signed int v174; // eax@404
//  char v175; // cl@405
//  signed int v176; // eax@408
//  char v177; // cl@409
//  char *v178; // eax@413
//  char *v179; // ecx@413
//  char v180; // dl@414
//  unsigned int v181; // eax@415
//  const void *v182; // esi@415
//  char *v183; // edi@415
//  char v184; // cl@416
//  char *v185; // edi@417
//  char v186; // al@418
//  char *v187; // eax@419
//  char *v188; // ecx@419
//  char v189; // dl@420
//  unsigned int v190; // eax@421
//  const void *v191; // esi@421
//  char *v192; // edi@421
//  char v193; // cl@422
//  char *v194; // edi@423
//  char v195; // al@424
//  signed int v196; // edx@426
//  signed int v197; // eax@427
//  char v198; // cl@428
//  int v199; // esi@430
//  double v200; // st7@431
//  int v201; // ebp@431
//  int v202; // eax@432
//  int v203; // ebx@434
//  int *v204; // edi@435
//  int *v205; // edi@439
//  int *v206; // edi@443
//  int *v207; // edi@447
//  int v208; // eax@449
  int v209; // eax@452
//  signed int v210; // edx@452
//  int v211; // ecx@452
  int v212; // edi@469
  int v213; // ecx@470
  signed int v214; // ecx@472
//  int *v215; // edx@473
  int v216; // eax@474
  int v217; // ebx@474
  void *v218 = malloc(0x4B000u); // eax@477
  
//  signed int v220; // edx@477
//  int v221; // ecx@477
  int v222; // eax@497
  char *v223; // edx@497
  signed int v224; // ecx@497
  int v225; // eax@497
  signed int v226; // edx@497
  float v227; // ST30_4@497
  float v228; // ST2C_4@497
  float v229; // ST28_4@497
  signed int v230; // esi@498
  
////  signed int v232; // edx@503
//  int v233; // ecx@503
//  signed int v234; // esi@525
  int v235; // eax@526
  char v236; // cl@526
  int v237; // eax@526
 // const char **v238; // [sp+Ch] [bp-E8h]@0
 // const char **v239; // [sp+10h] [bp-E4h]@0
 /* unsigned __int8 v240; // [sp+1Ch] [bp-D8h]@14
  unsigned __int8 v241; // [sp+1Dh] [bp-D7h]@14
  unsigned __int8 v242; // [sp+1Eh] [bp-D6h]@14
  unsigned __int8 v243; // [sp+1Fh] [bp-D5h]@14*/

  int raceIdParticipants[4];
  int v244; // [sp+20h] [bp-D4h]@73
  int v245; // [sp+24h] [bp-D0h]@88
  int v246; // [sp+28h] [bp-CCh]@16
  char Str[16]; // [sp+2Ch] [bp-C8h]@14
  int v248; // [sp+30h] [bp-C4h]@43
  int v249; // [sp+34h] [bp-C0h]@43
  int v250; // [sp+38h] [bp-BCh]@43
  int v251; // [sp+54h] [bp-A0h]@1
  int v252; // [sp+58h] [bp-9Ch]@1
  int v253; // [sp+5Ch] [bp-98h]@1
  int v254; // [sp+60h] [bp-94h]@1
  int v255; // [sp+64h] [bp-90h]@1
  int v256; // [sp+68h] [bp-8Ch]@1
  int v257; // [sp+6Ch] [bp-88h]@1
  int v258; // [sp+70h] [bp-84h]@1
  int v259; // [sp+74h] [bp-80h]@1
  int v260; // [sp+78h] [bp-7Ch]@1
  int v261; // [sp+7Ch] [bp-78h]@1
  int v262; // [sp+80h] [bp-74h]@1
  int v263; // [sp+84h] [bp-70h]@1
  int v264; // [sp+88h] [bp-6Ch]@1
  int v265; // [sp+8Ch] [bp-68h]@1
  int v266; // [sp+90h] [bp-64h]@1
  int v267; // [sp+94h] [bp-60h]@1
  int v268; // [sp+98h] [bp-5Ch]@1
  int v269; // [sp+9Ch] [bp-58h]@1
  int v270; // [sp+A0h] [bp-54h]@1
  int v271; // [sp+A4h] [bp-50h]@1
  int v272; // [sp+A8h] [bp-4Ch]@1
  int v273; // [sp+ACh] [bp-48h]@1
  char *v274; // [sp+B0h] [bp-44h]@100
  char *v275; // [sp+B4h] [bp-40h]@100
  char *v276; // [sp+B8h] [bp-3Ch]@100
  char *v277; // [sp+BCh] [bp-38h]@100
  int v278; // [sp+C0h] [bp-34h]@1
  int v279; // [sp+C4h] [bp-30h]@1
  int v280; // [sp+C8h] [bp-2Ch]@1
  int v281; // [sp+CCh] [bp-28h]@1
  int v282; // [sp+D0h] [bp-24h]@1
  int v283; // [sp+D4h] [bp-20h]@1
  int v284; // [sp+D8h] [bp-1Ch]@1
  int v285; // [sp+DCh] [bp-18h]@1
  char DstBuf; // [sp+E0h] [bp-14h]@47
   int indexRaceParticipant = 0;
  int iDriver = 0;  
  int maxDriverPoints = getMaxDriverPoints(driverId);
   int iRacePArticipant = 0;
 
  int  facePosition[4] = {82613,107685,144693,169765};
  int namePosition[4] = {128664,153736,190744,215816};
  int numberPosition[4] = {113331,138403,175411,200483};

  /* 82613=129 con resto 53
 107685=168 con resto 165
 144693=226 con resto 53
 169765=265 con resto 165
 113331=177 con resto 51
 138403=216 con resto 163
 175411= 274 con resto 51
 200483=313 con resto 163
 
 128664=201 con resto 24
 153736=240 con resto 136
 190744=298 con resto 24
 215816= 337 con resto 136*/

   v258 = 3691092;//TR8
  v267 = 3691092;//TR8
  v255 = 3494484;//TR5
  v256 = 3560020;//TR6
  v264 = 3494484;//TR5
  v265 = 3560020;//TR6
  dword_456730 = 0;
  memcpy((void *)dword_45FC00, screenBuffer, 0x4B000u);
  screenBuffer = (void *)dword_45FC00;
  v259 = 3756628;//TR9
  v268 = 3756628;//TR9
  memcpy((void *)dword_45FC00, graphicsGeneral.menubg5Bpk, 0x4B000u);
  v253 = 3363412;//TR3
  v262 = 3363412;//TR3
  v251 = 3232340; //TR1
  v252 = 3297876; //TR2
  v254 = 3428948; //TR4
  v257 = 3625556; //TR7
  v260 = 3232340; //TR1
  v261 = 3297876;//TR2
  v263 = 3428948;//TR4
  v266 = 3625556;//TR7
  v269 = 3166804;//TR0
  
  
  //posiciones de textos
  
 
  v282 = 113331;
  v283 = 138403;
  v284 = 175411;
  v285 = 200483;
  v270 = 128664;
  v271 = 153736;
  v272 = 190744;
  v273 = 215816;
  v278 = 82613;
  v279 = 107685;
  v280 = 144693;
  v281 = 169765;
  drawImageWithPosition((int)graphics4.prep4Bpk, 640, 54, (int)((char *)screenBuffer + 272640));
  drawImageWithPosition((int)graphics4.prepw1Bpk, 225, 274, (int)((char *)screenBuffer + 64013));
  if (participants < 4 )
  {
    v1 = 0;
    v2 = 0;
    do
    {
      v3 = v1 % 2;
      if ( v1 % 2 < 100 )
      {
        v4 = v2 + v3;
        v5 = ((unsigned int)(99 - v3) >> 1) + 1;
        do
        {
          *((BYTE *)screenBuffer + v4 + 167171) = -60;
          v4 += 2;
          --v5;
        }
        while ( v5 );
      }
      v2 += 640;
      ++v1;
    }
    while ( v2 < 58240 );
  }
  if (participants < 3 )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = v6 % 2;
      if ( v6 % 2 < 100 )
      {
        v9 = v7 + v8;
        v10 = ((unsigned int)(99 - v8) >> 1) + 1;
        do
        {
          *((BYTE *)screenBuffer + v9 + 142099) = -60;
          v9 += 2;
          --v10;
        }
        while ( v10 );
      }
      v7 += 640;
      ++v6;
    }
    while ( v7 < 58240 );
  }
  /*if ( isMultiplayerGame )
  {
	raceIdParticipants[0] = 0;
	raceIdParticipants[1] = 1;
	raceIdParticipants[2] = 2;
	raceIdParticipants[3] = 3;
    //allocateMemoryPtr((void*)&v11,4u);
    //TODO fix
	//Str = v11;
    *(BYTE *)v11 = driverId;
    multiplayer_41EA70((int)Str, 1, 19);
    free(Str);
    v12 = (unsigned __int8)byte_45FC10[dword_456BCC];
	v13 = tShape[v12];
	//v13 = &aTshape01[9 * v12];
    v14 = &Str[-9 * v12] - aTshape01;
	//v14 = &Str[-9 * v12] - aTshape01;
    do
    {
      v15 = *v13;
      v13[v14] = *v13;
      ++v13;
    }
    while ( v15 );
    v16 = (char *)&v246 + 3;
    do
      v17 = (v16++)[1];
    while ( v17 );
    *(_DWORD *)v16 = 1802527278; //.bpk
    v16[4] = 0;
    extractFromBpa("MENU.BPA", textureTemp, Str);
    copyImageToBuffer((int)textureTemp, (int)tsahpeBpk_45EB5C);
    drawImageWithPosition((int)tsahpeBpk_45EB5C, 360, 274, (int)((char *)screenBuffer + 64264));
    v18 = byte_45FC10[dword_456BCC];
    v19 = (unsigned __int8)byte_45FC10[dword_456BCC];
    v20 = &v251 + v19;
	//ni idea de que es esto pero es multiplayer
    v21 = (char *)&raceFilePrefix_45EA50[-v19] - (char *)&v251;
    do
    {
      v22 = *(BYTE *)v20;
      *((BYTE *)v20 + v21) = *(BYTE *)v20;
      v20 = (int *)((char *)v20 + 1);
    }
    while ( v22 );
    numberOfLaps = 5;
	raceParticipant[0].isCircuitReversed_4A7AA8 = (unsigned __int8)v18 > 8u;
  }
  else*/
  {
    v23 = selectedRace_462CE8;
	raceParticipant[0].isCircuitReversed_4A7AA8 = (unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] > 8u;
    switch ( selectedRace_462CE8 )
    {
      case 0:
       /* v24 = &aTshape01[9 * (unsigned __int8)circuitsToSelect_46126C[0]];
        v25 = &Str[-9 * (unsigned __int8)circuitsToSelect_46126C[0]] - aTshape01;
        do
        {
          v26 = *v24;
          v24[v25] = *v24;
          ++v24;
        }
        while ( v26 );
        v27 = (char *)&v246 + 3;
        do
          v28 = (v27++)[1];
        while ( v28 );
        *(_DWORD *)v27 = 1802527278; //bpk
        v27[4] = 0;*/
		  v24 = tShape[(unsigned __int8)circuitsToSelect_46126C[0]];
		  strcpy(Str, v24);
		  strcat(Str, ".bpk");
		  extractFromBpa("MENU.BPA", textureTemp, Str);
        //extractFromBpa("MENU.BPA", textureTemp, (int)Str);
        copyImageToBuffer((int)textureTemp, (int)tsahpeBpk_45EB5C);
        drawImageWithPosition((int)tsahpeBpk_45EB5C, 360, 274, (int)((char *)screenBuffer + 64264));
        

		//en funcion del circuito seleccionado saca el TRx
		v29 = &v251 + (unsigned __int8)circuitsToSelect_46126C[0];
		strcpy(raceFilePrefix_45EA50, "TR");
		_itoa((circuitsToSelect_46126C[0]%9)+1, &DstBuf, 10);
		strcat(raceFilePrefix_45EA50, &DstBuf);
        v30 = (char *)&raceFilePrefix_45EA50[-(unsigned __int8)circuitsToSelect_46126C[0]] - (char *)&v251;
        do
        {
          v31 = *(BYTE *)v29;
          *((BYTE *)v29 + v30) = *(BYTE *)v29;
          v29 = (int *)((char *)v29 + 1);
        }
        while ( v31 );
        numberOfLaps = getModIntEntry("RACE_EASY_LAPS", 4);
		
		goto LABEL_44;
      case 1:
        /*v32 = &aTshape01[9 * (unsigned __int8)circuitsToSelect_46126C[1]]; //TSHAPE01-19 9 bytes por texto
		//v32 = &aTshape01[9 * (unsigned __int8)byte_46126D];
        v33 = &Str[-9 * (unsigned __int8)circuitsToSelect_46126C[1]] - aTshape01;
		//v33 = &Str[-9 * (unsigned __int8)byte_46126D] - aTshape01;
        do
        {
          v34 = *v32;
          v32[v33] = *v32;
          ++v32;
        }
        while ( v34 );
        v35 = (char *)&v246 + 3;
        do
          v36 = (v35++)[1];
        while ( v36 );
        *(_DWORD *)v35 = 1802527278; //.bpk
        v35[4] = 0;
        extractFromBpa("MENU.BPA", textureTemp, (int)Str);*/
		v24 = tShape[(unsigned __int8)circuitsToSelect_46126C[1]];
		strcpy(Str, v24);
		strcat(Str, ".bpk");
		extractFromBpa("MENU.BPA", textureTemp, Str);
        copyImageToBuffer((int)textureTemp, (int)tsahpeBpk_45EB5C);
        drawImageWithPosition((int)tsahpeBpk_45EB5C, 360, 274, (int)((char *)screenBuffer + 64264));
        v37 = &v251 + (unsigned __int8)circuitsToSelect_46126C[1];
		//v37 = &v251 + (unsigned __int8)byte_46126D;
		strcpy(raceFilePrefix_45EA50, "TR");
		_itoa((circuitsToSelect_46126C[1] % 9) + 1, &DstBuf, 10);
		strcat(raceFilePrefix_45EA50, &DstBuf);
        v38 = (char *)&raceFilePrefix_45EA50[-(unsigned __int8)circuitsToSelect_46126C[1]] - (char *)&v251;
		//v38 = (char *)&raceFilePrefix_45EA50[-(unsigned __int8)byte_46126D] - (char *)&v251;
        do
        {
          v39 = *(BYTE *)v37;
          *((BYTE *)v37 + v38) = *(BYTE *)v37;
          v37 = (int *)((char *)v37 + 1);
        }
        while ( v39 );
        numberOfLaps = getModIntEntry("RACE_MEDIUM_LAPS", 5);
        goto LABEL_44;
      case 2:
		  v24 = tShape[(unsigned __int8)circuitsToSelect_46126C[2]];
		  strcpy(Str, v24);
		  strcat(Str, ".bpk");
       // v40 = &aTshape01[9 * (unsigned __int8)circuitsToSelect_46126C[2]];
       // v41 = &Str[-9 * (unsigned __int8)circuitsToSelect_46126C[2]] - aTshape01;
		///v40 = &aTshape01[9 * (unsigned __int8)byte_46126E];
		//v41 = &Str[-9 * (unsigned __int8)byte_46126E] - aTshape01;
        /*do
        {
          v42 = *v40;
          v40[v41] = *v40;
          ++v40;
        }
        while ( v42 );
        v43 = (char *)&v246 + 3;
        do
          v44 = (v43++)[1];
        while ( v44 );
        *(_DWORD *)v43 = 1802527278; //.bpk
        v43[4] = 0;*/
        extractFromBpa("MENU.BPA", textureTemp,Str);
        copyImageToBuffer((int)textureTemp, (int)tsahpeBpk_45EB5C);
        drawImageWithPosition((int)tsahpeBpk_45EB5C, 360, 274, (int)((char *)screenBuffer + 64264));
        v45 = &v251 + (unsigned __int8)circuitsToSelect_46126C[2];
		strcpy(raceFilePrefix_45EA50, "TR");
		_itoa((circuitsToSelect_46126C[2] % 9) + 1, &DstBuf, 10);
		strcat(raceFilePrefix_45EA50, &DstBuf);
        v46 = (char *)&raceFilePrefix_45EA50[-(unsigned __int8)circuitsToSelect_46126C[2]] - (char *)&v251;
		//v45 = &v251 + (unsigned __int8)byte_46126E;
		//v46 = (char *)&raceFilePrefix_45EA50[-(unsigned __int8)byte_46126E] - (char *)&v251;
        do
        {
          v47 = *(BYTE *)v45;
          *((BYTE *)v45 + v46) = *(BYTE *)v45;
          v45 = (int *)((char *)v45 + 1);
        }
        while ( v47 );
        numberOfLaps = getModIntEntry("RACE_HARD_LAPS", 6);
        goto LABEL_44;
      case 3:
        /*v248 = 959530320;
        *(_DWORD *)Str = 1095258964;
        v249 = 1263551022;
        LOBYTE(v250) = 0;*/
        extractFromBpa("MENU.BPA", textureTemp, "TSHAPE19.BPK");
        copyImageToBuffer((int)textureTemp, (int)tsahpeBpk_45EB5C);
        drawImageWithPosition((int)tsahpeBpk_45EB5C, 360, 274, (int)((char *)screenBuffer + 64264));
        //raceFilePrefix_45EA50[0] = 3166804; //TR0
		strcat(raceFilePrefix_45EA50, "TR0");
        numberOfLaps = getModIntEntry("RACE_ADVERSARY_LAPS", 9);
		raceParticipant[0].isCircuitReversed_4A7AA8 = 0;
LABEL_44:
        v23 = selectedRace_462CE8;
        break;
      default:
        break;
    }
	//cambiar a racePositions[0][0];
    /*v48 = BYTE1(dword_45EB50[v23]);
	raceIdParticipants[0] = LOBYTE(dword_45EB50[v23]);
    v49 = BYTE2(dword_45EB50[v23]);
	raceIdParticipants[1] = v48;
    v50 = BYTE3(dword_45EB50[v23]);
	raceIdParticipants[2] = v49;
	raceIdParticipants[3] = v50;*/

	
	raceIdParticipants[0] = racePositions[selectedRaceId][0];
	
	raceIdParticipants[1] = racePositions[selectedRaceId][1];
	
	raceIdParticipants[2] = racePositions[selectedRaceId][2];
	raceIdParticipants[3] = racePositions[selectedRaceId][3];

	//si la carrera es con adversary
    if ( v23 == 3 )
    {
		raceIdParticipants[1] = driverId;
		raceIdParticipants[0] = driverId;
    }
  }
  strcpy(Str, getLanguageEntry("NUMBER OF LAPS: "));
  _itoa(numberOfLaps, &DstBuf, 10);
  strcat(Str, &DstBuf);
  /*v51 = strlen(&DstBuf) + 1;
  v52 = (char *)&v246 + 3;
  do
    v53 = (v52++)[1];
  while ( v53 );
  memcpy(v52, &DstBuf, v51);*/
  drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, 229389);
  v248 = 1330454597; //duke
  *(_DWORD *)Str = 1514754640;//nukem
  v249 = 978928974;
  LOWORD(v250) = 32;
  if ( isMultiplayerGame )
  {
    v54 = (char *)&v246 + 3;
    do
      v55 = (v54++)[1];
    while ( v55 );
    v56 = (double)dword_4456E8 * 0.3;
    *(_WORD *)v54 = 36;
    _itoa((unsigned __int64)v56, &DstBuf, 10);
    v57 = strlen(&DstBuf) + 1;
    v58 = (char *)&v246 + 3;
    do
      v59 = (v58++)[1];
    while ( v59 );
    memcpy(v58, &DstBuf, v57);
  }
  else if ( selectedRace_462CE8 )
  {
    switch ( selectedRace_462CE8 )
    {
      case 1: //race medium
       /* v62 = (char *)&v246 + 3;
        do
          v63 = (v62++)[1];
        while ( v63 );
        *(_DWORD *)v62 = *(_DWORD *)"$3000";
        *((_WORD *)v62 + 2) = *(_WORD *)"0";*/
		strcpy(v60, getModCharEntry("MONEY_SYMBOL" ,"$"));
		strcat(v60,getModCharEntry("RACE_MEDIUM_FIRST_POSITION_PRIZE" ,"3000"));
        break;
      case 2: //race hard
        /*v64 = (char *)&v246 + 3;
        do
          v65 = (v64++)[1];
        while ( v65 );
        *(_DWORD *)v64 = *(_DWORD *)"$12000";
        *((_WORD *)v64 + 2) = *(_WORD *)"00";
        v64[6] = a12000[6];*/
		strcpy(v60, getModCharEntry("MONEY_SYMBOL" ,"$"));
		strcat(v60,getModCharEntry("RACE_HARD_FIRST_POSITION_PRIZE" ,"12000"));
        break;
      case 3:
        /*v66 = (char *)&v246 + 3;
        do
          v67 = (v66++)[1];
        while ( v67 );
        *(_DWORD *)v66 = 1380928583; //GLORY
        *((_WORD *)v66 + 2) = 89;*/
		strcpy(v60, getLanguageEntry("GLORY"));
        break;
    }
  }
  else //race 0 easy
  {
    /*v60 = (char *)&v246 + 3;
    do
      v61 = (v60++)[1];
    while ( v61 );
    *(_DWORD *)v60 = *(_DWORD *)"$750";
    v60[4] = a750[4];*/
	  strcpy(v60, getModCharEntry("MONEY_SYMBOL" ,"$"));
	  strcat(v60, getModCharEntry("RACE_EASY_FIRST_POSITION_PRIZE" ,"750"));
  }
  strcpy(Str, getLanguageEntry("PRIZE: "));
  strcat(Str, v60);
  /*v69 = 0;
  v70 = 0;
  do
    v71 = *v68++;
  while ( v71 );
  v244 = v68 - &Str[1];*/
  //if ( v60 != &Str[1] )
  //{
  v69 = 0;
  v70 = 0;
    do
      v69 += (unsigned __int8)letterSpacing_4458B0[90+(unsigned __int8)Str[v70++]];
    while ( v70 < strlen(Str) );
  //}
  drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, 229739 - v69);
  if ( selectedRace_462CE8 == 3 )
  {
    strcpy(Str, "adversary");
    _strupr(Str);
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, 128664);
    drawImageWithPosition2((int)graphicsGeneral.facexxBpk, 64, 64, (int)((char *)screenBuffer + 82613));
    v72 = raceIdParticipants[0];
	v73 = raceIdParticipants[0];
    _itoa(drivers[v73].rank, Str, 10);
    v74 = (char *)&v246 + 3;
    do
      v75 = (v74++)[1];
    while ( v75 );
    *(_WORD *)v74 = 46;
    v76 = Str;
    v77 = 0;
    v78 = 0;
    do
      v79 = *v76++;
    while ( v79 );
    v244 = v76 - &Str[1];
    if ( v76 != &Str[1] )
    {
      do
        v77 += (unsigned __int8)letterSpacing_4458B0[90+(unsigned __int8)Str[v78++]];
      while ( v78 < strlen(Str) );
    }
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, 138403 - v77);
    v80 = &byte_460840[v73 * 4];
    do
    {
      v81 = *v80;
      v80[&Str[-108 * v72] - byte_460840] = *v80;
      ++v80;
    }
    while ( v81 );
    _strupr(Str);
    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, 153736);
    drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + drivers[v73].face), 64, 64, (int)((char *)screenBuffer + 107685));
  }
  else
  {
    for ( i = 0; i < participants; ++i )
    {
		int currentDriverId = racePositions[selectedRaceId][i];

		

      /*v83 = *(&v240 + i);
      v84 = v83;
      itoa(drivers[v83].rank, Str, 10);
      v85 = (char *)&v246 + 3;
      do
        v86 = (v85++)[1];
      while ( v86 );
      *(_WORD *)v85 = 46;
      v87 = 0;
      v88 = Str;
      v245 = 0;
      do
        v89 = *v88++;
      while ( v89 );
      v244 = v88 - &Str[1];
      if ( v88 != &Str[1] )
      {*/
		v87 = 0;
		v245 = 0;
		memset(Str, "\0", strlen(Str));
		_itoa(drivers[currentDriverId].rank, &DstBuf, 10);
		strcpy(Str, &DstBuf);
		strcat(Str, ".\0");
        do
          v245 += (unsigned __int8)letterSpacing_4458B0[90+(unsigned __int8)Str[v87++]];
        while ( v87 < strlen(Str) );
      //}
		drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, numberPosition[i]- v245);

		memset(Str, "\0", strlen(Str));
		strcpy(Str, drivers[currentDriverId].name);
		_strupr(Str);
		drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, namePosition[i]);
		drawImageWithPosition2(*(&graphicsGeneral.face01Bpk + drivers[currentDriverId].face), 64, 64, (int)((char *)screenBuffer + facePosition[i]));
		
		
		/*drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, v282 + i - v245);

		memset(Str, "\0", strlen(Str));
		strcpy(Str, drivers[currentDriverId].name);
		strupr(Str);
		drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, v270 + i);
		drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + drivers[currentDriverId].face), 64, 64, (int)((char *)screenBuffer + v278 + i));*/

		
	  //position
      //TODO FIX drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, *(&v282 + i) - v245);
      /*v90 = &byte_460840[v84 * 4];
      do
      {
        v91 = *v90;
        v90[&Str[-108 * v83] - byte_460840] = *v90;
        ++v90;
      }
      while ( v91 );
      strupr(Str);*/
	  //name
      //TODO FIXdrawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, *(&v270 + i));
	  //image
	  //TODO FIXdrawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + dword_460880[v84]), 64, 64, (int)((char *)screenBuffer + *(&v278 + i)));
    }
  }
  screenBuffer = (void *)dword_461250;
  sub_42C670(-1);
  if ( isMultiplayerGame )
    musicSetOrder(7680);
  else
    musicSetOrder(10240);
  setMusicVolume(0x10000);
  refreshAllScreen();
  if ( !isMultiplayerGame )
  {
LABEL_110:
    v92 = dword_456B9C;
    if ( !dword_456B9C )
      goto LABEL_112;
    goto LABEL_111;
  }
  v92 = dword_456B9C;
  if ( !dword_456B9C )
  {
    v274 = &byte_460840[108 * (unsigned __int8)dword_45FA74];
    v275 = &byte_460840[108 * BYTE1(dword_45FA74)];
    v276 = &byte_460840[108 * BYTE2(dword_45FA74)];
    v277 = &byte_460840[108 * BYTE3(dword_45FA74)];
    //allocateMemory(4u);
    //TODO fix
   // Str = v93;
    *(BYTE *)v93 = driverId;
    nullsub_1();
    v94 = 0;
    v95 = 0;
    do
    {
      if ( dword_456B9C )
        break;
      drawWaitMultiplayer_4261D0();
      refreshAndCheckConnection_42A570();
      refreshAndCheckConnection_42A570();
      if ( v95 % 10 == 1 )
        v94 = sub_43C4B0();
      if ( v95 % 900 == 899 )
       // multiplayer_41EA70((int)Str, 1, 19);
      ++v95;
    }
    while ( v94 != 255 );
    sub_43C4B0();
    if ( v94 == 255 )
      drawCircuitPreviewImage();
    refreshAllScreen();
    free(Str);
    goto LABEL_110;
  }
LABEL_111:
  dword_456B6C = 1;
  if ( v92 )
    return;
LABEL_112:
  v96 = driverId;
  currentRaceBestLapMilliseconds_461FEC = 0;
  currentRaceBestLapSeconds_45EB48 = 0;
  currentRaceBestLapMinutes_463CAC = 0;
  currentLapMilliseconds_45FC1C = 0;
  currentLapSeconds_463CD4 = 0;
  currentLapMinutes_45EA64 = 0;
  totalRaceMilliseconds_462D74 = 0;
  totalRaceSeconds_45EEBC = 0;
  totalRaceMinutes_45EEC0 = 0;
  lapped_456BC0 = 0;
 
  if ( isMultiplayerGame || (raceParticipant[0].drugPicked = 1, drugQuest_456BB4 <= 0) )//dword_4A7AAC offset de 76 en la estructura de participante
	  raceParticipant[0].drugPicked = 0;
  numberOfParticipants = participants;
  v101 = 0;
  if (participants > 0 )
  {
	 
    //v102 = raceParticipant[iRacePArticipant];
	//v102 = (int)dword_4A7A60;
    while ( 1 )
    {
		v103 = raceIdParticipants[v101];
		//esto no se usa puede que este copiando le nombre!
      /*v103 = *(&v240 	  + v101);
      v104 = &byte_460840[108 * v103];
      do
      {
        v105 = *v104;
        v104[v102 - 108 * v103 - (_DWORD)byte_460840] = *v104;
        ++v104;
      }
      while ( v105 );*/
	  strcpy(raceParticipant[iRacePArticipant].name, drivers[v103].name);
      //strupr((char *)v102);
      v106 = raceIdParticipants[v101];
	  raceParticipant[iRacePArticipant].damage = drivers[v106].damage;
	  raceParticipant[iRacePArticipant].engine = drivers[v106].engine;
	  raceParticipant[iRacePArticipant].tire = drivers[v106].tire;
      
	  raceParticipant[iRacePArticipant].armour = drivers[v106].armour;
      v96 = driverId;
      v108 = v106 == driverId;
	  raceParticipant[iRacePArticipant].carType = drivers[v106].carType;
      if ( v108 )
		  raceParticipant[iRacePArticipant].difficulty = 3;
      else
		  raceParticipant[iRacePArticipant].difficulty = configuration.difficulty;
      v109 = raceIdParticipants[v101];
	  raceParticipant[iRacePArticipant].useWeapons = useWeapons;
	  raceParticipant[iRacePArticipant].rocket = drivers[v109].rocket;
      
	  raceParticipant[iRacePArticipant].spikes = drivers[v109].spikes;
	  raceParticipant[iRacePArticipant].mines = drivers[v109].mines;
	  //asigna aleatoriamente a los contrincantes los mines rocket y spikes
      if ( v109 != driverId && !isMultiplayerGame )
      {
		  raceParticipant[iRacePArticipant].mines = 0;
		  raceParticipant[iRacePArticipant].spikes = 0;
		  raceParticipant[iRacePArticipant].rocket = 0; //rocket
        if ( !(rand() % 5) && useWeapons )
			raceParticipant[iRacePArticipant].rocket = 1;
        if ( !(rand() % 5) && useWeapons )
			raceParticipant[iRacePArticipant].spikes = 1;//spikes
        v111 = rand();
        v96 = driverId;
        if ( !(v111 % 5) && useWeapons )
			raceParticipant[iRacePArticipant].mines = 8;//mines
      }
      v112 = graphicsGeneral.carcolPal;
	  //aqui se asigna el color rgb
      if ( v103 == driverId || isMultiplayerGame )
      {
        v116 = (char *)graphicsGeneral.copperPal + 2 * drivers[raceIdParticipants[v101]].colour + drivers[raceIdParticipants[v101]].colour;
		raceParticipant[iRacePArticipant].r = (unsigned __int8)*v116;
		raceParticipant[iRacePArticipant].g = (unsigned __int8)v116[1];
		raceParticipant[iRacePArticipant].b = (unsigned __int8)v116[2];
        if ( !isMultiplayerGame || v101 <= raceDrivers_456758 - 1 )
          goto LABEL_157;
		raceParticipant[iRacePArticipant].r = *((BYTE *)v112 + 30);
		raceParticipant[iRacePArticipant].g = *((BYTE *)v112 + 31);
        v115 = *((BYTE *)v112 + 32);
      }
      else
      {
        v113 = drivers[raceIdParticipants[v101]].colour;
        v114 = (char *)graphicsGeneral.carcolPal + 2 * v113 + v113;
		raceParticipant[iRacePArticipant].r = (unsigned __int8)*v114;
		raceParticipant[iRacePArticipant].g = (unsigned __int8)v114[1];
        v115 = (unsigned __int8)v114[2];
      }
	  raceParticipant[iRacePArticipant].b = v115;
LABEL_157:
	  numberOfParticipants = participants;
      ++v101;
      //v102 += 84;
	  iRacePArticipant++;
      if (iRacePArticipant >= participants)
        goto LABEL_160;
    }
  }
  v112 = graphicsGeneral.carcolPal;
LABEL_160:
  if ( isMultiplayerGame && numberOfParticipants < 4 )//claramente setea los colores de los participantes
  {
	 int iRacePArticipant = 0;

    do
    {
		raceParticipant[iRacePArticipant].r=  *((BYTE *)v112 + 30);
		raceParticipant[iRacePArticipant].g = *((BYTE *)v112 + 31);
		raceParticipant[iRacePArticipant].b = *((BYTE *)v112 + 32);
		iRacePArticipant++;
    }
    while (iRacePArticipant < participants);
  }
  maxPoints = 0;
  v119 = 0;
  //saca el maximo de puntos
  if (numberOfParticipants > 0 )
  {
	  int driverIndex = 0;
    do
    {
      if (drivers[driverIndex].points > maxPoints && v119 != v96 )
		  maxPoints = drivers[driverIndex].points;
      ++v119;
	  driverIndex = driverIndex + 1;
    }
    while ( v119 < numberOfParticipants);
  }
  v121 =  v96;
  userPoints = drivers[v121].points;
  if (userPoints > maxPoints && !isMultiplayerGame )
  {
    
	  strcpy(raceParticipant[0].name, "Adversary");
	  /**(_DWORD *)dword_4A7A60 = 1163281473; ///adversary
    dword_4A7A64 = 1380012882;
    word_4A7A68 = 89;*/
	  raceParticipant[0].difficulty = configuration.difficulty;
	  raceParticipant[0].damage = 0;
	  raceParticipant[0].rocket = 0;
	  raceParticipant[0].carType = 6;
	  raceParticipant[0].spikes = 1;
	  raceParticipant[0].useWeapons = useWeapons;
	  raceParticipant[0].mines = useWeapons != 0 ? 8 : 0;
	  raceParticipant[2].r = *((BYTE *)v112 + 30);
	raceParticipant[2].g = *((BYTE *)v112 + 31);
	raceParticipant[2].b = *((BYTE *)v112 + 32);
	raceParticipant[3].r = *((BYTE *)v112 + 30);
	raceParticipant[3].g = *((BYTE *)v112 + 31);
	raceParticipant[3].b = *((BYTE *)v112 + 32);
  }
  v123 = 24 * ((unsigned __int8)circuitsToSelect_46126C[selectedRace_462CE8] + 18 * drivers[v121].carType);
  circuitRecordMinutes_50A160 = *(int *)((char *)&dword_45F04C + v123);
  v124 = *(int *)((char *)&dword_45F050 + v123);
  circuitRecordMilliseconds_4A9B8C = *(int *)((char *)&dword_45F054 + v123);
  circuitRecordSeconds_501260 = v124;
  Val = 0;
  if ( isMultiplayerGame )
  {
    Val = (unsigned __int64)((double)dword_4456E8 * 0.02);
  }
  else
  {
    if (userPoints > maxPoints)
      goto LABEL_534;
    if ( !selectedRace_462CE8 )
      Val = 50;
    
    if (drivers[driverId].rank > 0 && drivers[driverId].rank < 6 )
    {
      if ( selectedRace_462CE8 == 1 )
      {
        Val = 260;
      }
      else if ( selectedRace_462CE8 == 2 )
      {
        Val = 500;
      }
    }
    if (drivers[driverId].rank > 5 && drivers[driverId].rank < 11 )
    {
      if ( selectedRace_462CE8 == 1 )
      {
        Val = 200;
      }
      else if ( selectedRace_462CE8 == 2 )
      {
        Val = 300;
      }
    }
    if (drivers[driverId].rank > 10 && drivers[driverId].rank < 16 )
    {
      if ( selectedRace_462CE8 == 1 )
      {
        Val = 120;
      }
      else if ( selectedRace_462CE8 == 2 )
      {
        Val = 150;
      }
    }
    if (drivers[driverId].rank > 15 && drivers[driverId].rank < 21 )
    {
      if ( selectedRace_462CE8 == 1 )
      {
        Val = 60;
      }
      else if ( selectedRace_462CE8 == 2 )
      {
        Val = 80;
      }
    }
    if (userPoints > maxPoints)
LABEL_534:
      Val = 400;
  }
  freeMemoryGraphics();
  freeMemoryGraphics1();
  freeMemoryGraphics2();
  freeMemoryGraphics3();
  freeMemoryGraphics4();
  if ( isMultiplayerGame )
  {
    userRaceOrder_45FC20 = driverId;
    if ( dword_45E0A8 == 2 )
      removeBackgroundRefreshFunction_43C730();
  }

  startRace(userRaceOrder_45FC20, numberOfParticipants);
  if ( isMultiplayerGame && dword_45E0A8 == 2 )
    //setBackgroundRefreshFunction_43C7B0((int (*)(void))multiplayer_4181B0);
  v126 = userRaceOrder_45FC20;
  v127 = driverId;
  v244 = 84 * userRaceOrder_45FC20;
  v128 = raceParticipant[userRaceOrder_45FC20].racePosition;
  userRacePosition_456B50 = v128;
  dword_456BD8 = v128;
  v129 = 0;
  v130 = 2;
  v131 = (int)dword_4608F0;//bucle puntos piloto
  do
  {
    if ( *(_DWORD *)(v131 - 108) > v129 )
    {
      v126 = userRaceOrder_45FC20;
      if ( v130 - 2 != driverId )
        v129 = *(_DWORD *)(v131 - 108);
    }
    if ( *(_DWORD *)v131 > v129 )
    {
      v126 = userRaceOrder_45FC20;
      if ( v130 - 1 != driverId )
        v129 = *(_DWORD *)v131;
    }
    if ( *(_DWORD *)(v131 + 108) > v129 && v130 != driverId )
      v129 = *(_DWORD *)(v131 + 108);
    if ( *(_DWORD *)(v131 + 216) > v129 )
    {
      v126 = userRaceOrder_45FC20;
      if ( v130 + 1 != driverId )
        v129 = *(_DWORD *)(v131 + 216);
    }
    if ( *(_DWORD *)(v131 + 324) > v129 )
    {
      v126 = userRaceOrder_45FC20;
      if ( v130 + 2 != driverId )
        v129 = *(_DWORD *)(v131 + 324);
    }
    v130 += 5;
    v131 += 540;
  }
  while ( v130 - 2 < 20 );
  v132 = drivers[driverId].points;
  v245 =  driverId;
  if ( v132 <= v129 || isMultiplayerGame )
  {
    v133 = 0;
    v134 = 0;
    if (numberOfParticipants > 0 )
    {
     // v135 = (int)dword_4A7A70;
      do
      {
        if ( v134 != v126 && raceParticipant[v134].damage == 100 )
          ++v133;
        ++v134;
       // v135 += 84;
      }
      while ( v134 < numberOfParticipants);
    }
    if ( v133 == numberOfParticipants - 1 && raceParticipant[userRaceOrder_45FC20].damage < 100 )
      allCarsCrash_456BB0 = 1;
    if ( (isMultiplayerGame || userRacePosition_456B50 != 4) && raceParticipant[userRaceOrder_45FC20].damage < 3 && useWeapons == 1 )
      noPaintJob_456BAC = 1;
    if ( userRacePosition_456B50 == 1 )
      ++consecutiveWins_456BA8;
    else
      consecutiveWins_456BA8 = 0;
    if ( !isMultiplayerGame )
    {
      if ( drugQuest_456BB4 > 0 && (raceParticipant[0].drugPicked != 1 || userRacePosition_456B50 != 1 || raceParticipant[userRaceOrder_45FC20].damage >= 100) )
        drugQuest_456BB4 = -drugQuest_456BB4;
      if ( killOneQuest_456BB8 > 0 )
      {
		  //cambiar a racePositions[0][0];
        if ( LOBYTE(dword_45EB50[selectedRace_462CE8]) == killQuestDriverId_456BBC )
          v133 = 0;
        if ( BYTE1(dword_45EB50[selectedRace_462CE8]) == killQuestDriverId_456BBC )
          v133 = 1;
        if ( BYTE2(dword_45EB50[selectedRace_462CE8]) == killQuestDriverId_456BBC )
          v133 = 2;
        if ( BYTE3(dword_45EB50[selectedRace_462CE8]) == killQuestDriverId_456BBC )
          v133 = 3;
        if ( raceParticipant[v133].damage != 100 )
          killOneQuest_456BB8 = -killOneQuest_456BB8;
      }
    }
  }
  if ( drivers[driverId].loanType != -1 )
    ++drivers[driverId].loanRaces;
  firstRacePlayed_464F44 = 0;
  //pone a 0 las cosas del underground

 
  do {
	  drivers[iDriver].mines = 0;
	  drivers[iDriver].spikes = 0;
	  drivers[iDriver].rocket = 0;
	  drivers[iDriver].sabotage = 0;

	  iDriver++;
  } while (iDriver < 20);

  reInitUnderGroundMarketStock();
  v137 = raceIdParticipants[2];
  v138 = raceIdParticipants[1];
  drivers[raceIdParticipants[0]].lastRaceIncome = 0;
  v139 = raceIdParticipants[3];
  drivers[raceIdParticipants[1]].lastRaceIncome = 0;
  drivers[raceIdParticipants[2]].lastRaceIncome = 0;
  v140 = 0;
  drivers[raceIdParticipants[3]].lastRaceIncome = 0;
  userLastRaceIncomeNoPrice_456BE0 = 0;
  userLasRacePriceIncome_456BDC = 0;
  v246 = 0;
  v141 = 2;
  v142 = (int)dword_4608F0; //bucle puntos de polotos
  do
  {
    if ( *(_DWORD *)(v142 - 108) > v140 )
    {
      if ( v141 - 2 == v127 )
      {
        v140 = v246;
      }
      else
      {
        v140 = *(_DWORD *)(v142 - 108);
        v246 = *(_DWORD *)(v142 - 108);
      }
    }
    if ( *(_DWORD *)v142 > v140 )
    {
      if ( v141 - 1 == v127 )
      {
        v140 = v246;
      }
      else
      {
        v140 = *(_DWORD *)v142;
        v246 = *(_DWORD *)v142;
      }
    }
    if ( *(_DWORD *)(v142 + 108) > v140 && v141 != v127 )
    {
      v140 = *(_DWORD *)(v142 + 108);
      v246 = *(_DWORD *)(v142 + 108);
    }
    if ( *(_DWORD *)(v142 + 216) > v140 )
    {
      if ( v141 + 1 == v127 )
      {
        v140 = v246;
      }
      else
      {
        v140 = *(_DWORD *)(v142 + 216);
        v246 = *(_DWORD *)(v142 + 216);
      }
    }
    if ( *(_DWORD *)(v142 + 324) > v140 )
    {
      if ( v141 + 2 == v127 )
      {
        v140 = v246;
      }
      else
      {
        v140 = *(_DWORD *)(v142 + 324);
        v246 = *(_DWORD *)(v142 + 324);
      }
    }
    v141 += 5;
    v142 += 540;
  }
  while ( v141 - 2 < 20 );
  if ( isMultiplayerGame )
  {
   /* v156 = unk_461EC2;
    unk_461EC2 = unk_461EC3;
    v157 = dword_456BCC + 1;
    v159 = __OFSUB__(dword_456BCC + 1, dword_456BC8);
    v158 = dword_456BCC + 1 - dword_456BC8 < 0;
    unk_461EC0[0] = unk_461EC1;
    unk_461EC3 = word_461EC4;
    v160 = unk_461EC6;
    unk_461EC6 = unk_461EC7;
    HIBYTE(word_461EC4) = v160;
    unk_461EC7 = word_461EC8;
    v161 = unk_461ECA;
    unk_461ECA = unk_461ECB;
    HIBYTE(word_461EC8) = v161;
    unk_461ECB = word_461ECC;
    HIBYTE(word_461ECC) = unk_461ECE;
    unk_461ECE = unk_461ECF;
    unk_461ECF = word_461ED0;
    HIBYTE(word_461ED0) = unk_461ED2;
    unk_461ED2 = unk_461ED3;
    ++dword_456BCC;
    v162 = (signed int)&unk_462096;
    unk_461ED3 = word_461ED4;
    if ( v158 ^ v159 )
    {
      do
      {
        v176 = v162;
        do
        {
          v177 = *(BYTE *)v176;
          *(BYTE *)(v176 - 150) = *(BYTE *)v176;
          ++v176;
        }
        while ( v177 );
        v162 += 150;
      }
      while ( v162 < (signed int)&blacktx1Bpk );
      if (raceParticipant[0].difficulty == -1 )
      {
        memcpy(&dword_462C4E, "-- Multiplayer connection lost!", 0x20u);
      }
      else
      {
        v178 = &aSuburbia[15 * (unsigned __int8)byte_45FC0F[v157]];
        dword_462C4E = 2108717;
        v179 = v178;
        do
          v180 = *v178++;
        while ( v180 );
        v181 = v178 - v179;
        v182 = v179;
        v183 = (char *)&dword_462C4E - 1;
        do
          v184 = (v183++)[1];
        while ( v184 );
        memcpy(v183, v182, v181);
        v185 = (char *)&dword_462C4E - 1;
        do
          v186 = (v185++)[1];
        while ( v186 );
        v187 = &aSuburbia[15 * (unsigned __int8)byte_45FC10[v157]];
        memcpy(v185, " race completed. Next race ", 0x1Cu);
        v188 = v187;
        do
          v189 = *v187++;
        while ( v189 );
        v190 = v187 - v188;
        v191 = v188;
        v192 = (char *)&dword_462C4E - 1;
        do
          v193 = (v192++)[1];
        while ( v193 );
        memcpy(v192, v191, v190);
        v194 = (char *)&dword_462C4E - 1;
        do
          v195 = (v194++)[1];
        while ( v195 );
        *(_WORD *)v194 = 46;
      }
      unk_461EC1 = unk_461EC2;
      unk_461EC2 = unk_461EC3;
      unk_461EC3 = word_461EC4;
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
      v196 = (signed int)&unk_462096;
      unk_461EC0[0] = v156;
      unk_461ED3 = word_461ED4;
      LOBYTE(word_461ED4) = 0;
      do
      {
        v197 = v196;
        do
        {
          v198 = *(BYTE *)v197;
          *(BYTE *)(v197 - 150) = *(BYTE *)v197;
          ++v197;
        }
        while ( v198 );
        v196 += 150;
      }
      while ( v196 < (signed int)&blacktx1Bpk );
    }
    else
    {
      dword_456B98 = 1;
      do
      {
        v163 = v162;
        do
        {
          v164 = *(BYTE *)v163;
          *(BYTE *)(v163 - 150) = *(BYTE *)v163;
          ++v163;
        }
        while ( v164 );
        v162 += 150;
      }
      while ( v162 < (signed int)&blacktx1Bpk );
      v165 = &byte_460840[v245];
      dword_462C4E = 2108717;
      v166 = &byte_460840[v245];
      do
        v167 = *v165++;
      while ( v167 );
      v168 = v165 - v166;
      v169 = (char *)&dword_462C4E - 1;
      do
        v170 = (v169++)[1];
      while ( v170 );
      memcpy(v169, v166, v168);
      v171 = (char *)&dword_462C4E - 1;
      do
        v172 = (v171++)[1];
      while ( v172 );
      *(_DWORD *)v171 = 1836016416;
      *((_DWORD *)v171 + 1) = 1952803952;
      *((_DWORD *)v171 + 2) = 1948279909;
      *((_DWORD *)v171 + 3) = 1847616872;
      *((_DWORD *)v171 + 4) = 1634169957;
      *((_DWORD *)v171 + 5) = 3040621;
      unk_461EC1 = unk_461EC2;
      unk_461EC2 = unk_461EC3;
      unk_461EC3 = word_461EC4;
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
      v173 = (signed int)&unk_462096;
      unk_461EC0[0] = v156;
      unk_461ED3 = word_461ED4;
      LOBYTE(word_461ED4) = 0;
      do
      {
        v174 = v173;
        do
        {
          v175 = *(BYTE *)v174;
          *(BYTE *)(v174 - 150) = *(BYTE *)v174;
          ++v174;
        }
        while ( v175 );
        v173 += 150;
      }
      while ( v173 < (signed int)&blacktx1Bpk );
    }
    v199 = 0;
    LOBYTE(dword_462C4E) = 0;
    HIBYTE(word_461ED4) = 0;
    userLastRaceIncomeNoPrice_456BE0 = 0;
    userLasRacePriceIncome_456BDC = 0;
    if ( raceDrivers_456758 > 0 )
    {
      v200 = (double)dword_4456E8;
      v244 = (unsigned __int64)(0.02 * v200);
      v201 = (int)dword_4A7AA0;
      do
      {
        v202 = v244 * *(_DWORD *)(v201 - 52);
        v108 = v199 == userRaceOrder_45FC20;
        drivers[raceIdParticipants[v199]].lastRaceIncome = v202;
        if ( v108 )
          userLastRaceIncomeNoPrice_456BE0 = v202;
        v203 = *(_DWORD *)v201;
		//es multiplayer no me interesa
        /*if ( *(_DWORD *)v201 == 1 )
        {
          v204 = &dword_460894[27 * *(&v240 + v199)];
          v108 = v199 == userRaceOrder_45FC20;
          *v204 += (unsigned __int64)(0.3 * v200);
          if ( v108 )
            userLasRacePriceIncome_456BDC = (unsigned __int64)(0.3 * v200);
          dword_460884[27 * *(&v240 + v199)] += 6;
        }
        if ( v203 == 2 )
        {
          v205 = &dword_460894[27 * *(&v240 + v199)];
          v108 = v199 == userRaceOrder_45FC20;
          *v205 += (unsigned __int64)(0.25 * v200);
          if ( v108 )
            userLasRacePriceIncome_456BDC = (unsigned __int64)(0.25 * v200);
          dword_460884[27 * *(&v240 + v199)] += 4;
        }
        if ( v203 == 3 )
        {
          v206 = &dword_460894[27 * *(&v240 + v199)];
          v108 = v199 == userRaceOrder_45FC20;
          *v206 += (unsigned __int64)(0.2 * v200);
          if ( v108 )
            userLasRacePriceIncome_456BDC = (unsigned __int64)(0.2 * v200);
          dword_460884[27 * *(&v240 + v199)] += 2;
        }
        if ( v203 == 4 )
        {
          v207 = &dword_460894[27 * *(&v240 + v199)];
          v108 = v199 == userRaceOrder_45FC20;
          *v207 += (unsigned __int64)(0.15 * v200);
          if ( v108 )
            userLasRacePriceIncome_456BDC = (unsigned __int64)(0.15 * v200);
        }*/
        /*v208 = raceIdParticipants[v199];
        drivers[v208].money += drivers[v208].lastRaceIncome;
        drivers[v208].totalIncome += drivers[v208].lastRaceIncome;
        if ( v203 == 1 )
          ++drivers[raceIdParticipants[v199]].racesWon;
        ++v199;
        v201 += 84;
      }
      while ( v199 < raceDrivers_456758 );
    }*/
  }
  else
  {//calculo del dinero ganado en la carrera
	  //140 son los puntos del que mas lleva
    if ( drivers[v245].points <= v140 && !lapped_456BC0 )
    {
      v143 = selectedRace_462CE8;
      v144 = 0;
	 
     // v145 = (signed int)&dword_4A7A6C;//posicion en carrera raceParticipant[].racePosition
      do
      {
        if ( userRacePosition_456B50 != 4 && !v143 )
        {
          v146 = 50 * raceParticipant[indexRaceParticipant].moneyPicked;
		  drivers[raceIdParticipants[v144]].lastRaceIncome = v146;
          if ( v144 == v126 )
            userLastRaceIncomeNoPrice_456BE0 = v146;
        }
        v147 =drivers[v245].rank;
        if ( v147 > 0 && v147 < 6 && userRacePosition_456B50 != 4 )
        {
          if ( v143 == RACE_EASY)
          {
			  drivers[raceIdParticipants[v144]].lastRaceIncome = 260 * raceParticipant[indexRaceParticipant].moneyPicked;
LABEL_304:
            if ( v144 == v126 )
              userLastRaceIncomeNoPrice_456BE0 = 260 * raceParticipant[indexRaceParticipant].moneyPicked;
            goto LABEL_309;
          }
          if ( v143 == RACE_MEDIUM)
          {
			  drivers[raceIdParticipants[v144]].lastRaceIncome = 500 * raceParticipant[indexRaceParticipant].moneyPicked;
          }
          else
          {
            if ( v143 == RACE_EASY)
              goto LABEL_304;
            if ( v143 != RACE_MEDIUM )
              goto LABEL_309;
          }
          if ( v144 == v126 )
            userLastRaceIncomeNoPrice_456BE0 = 500 * raceParticipant[indexRaceParticipant].moneyPicked;
        }
LABEL_309:
        v148 = drivers[v245].rank;
        if ( v148 <= 5 || v148 >= 11 || userRacePosition_456B50 == 4 )
          goto LABEL_322;
        if ( v143 == RACE_MEDIUM)
        {
			drivers[raceIdParticipants[v144]].lastRaceIncome = 200 * raceParticipant[indexRaceParticipant].moneyPicked;
LABEL_317:
          if ( v144 == v126 )
            userLastRaceIncomeNoPrice_456BE0 = 200 * raceParticipant[indexRaceParticipant].moneyPicked;
          goto LABEL_322;
        }
        if ( v143 == RACE_HARD)
        {
			drivers[raceIdParticipants[v144]].lastRaceIncome = 300 * raceParticipant[indexRaceParticipant].moneyPicked;
        }
        else
        {
          if ( v143 == RACE_MEDIUM)
            goto LABEL_317;
          if ( v143 != RACE_HARD)
            goto LABEL_322;
        }
        if ( v144 == v126 )
          userLastRaceIncomeNoPrice_456BE0 = 300 * raceParticipant[indexRaceParticipant].moneyPicked;
LABEL_322:
        v149 = drivers[v245].rank;
        if ( v149 <= 10 || v149 >= 16 || userRacePosition_456B50 == 4 )
          goto LABEL_335;
        if ( v143 == RACE_MEDIUM )
        {
			drivers[raceIdParticipants[v144]].lastRaceIncome = 120 * raceParticipant[indexRaceParticipant].moneyPicked;
LABEL_330:
          if ( v144 == v126 )
            userLastRaceIncomeNoPrice_456BE0 = 120 * raceParticipant[indexRaceParticipant].moneyPicked;
          goto LABEL_335;
        }
        if ( v143 == RACE_HARD)
        {
			drivers[raceIdParticipants[v144]].lastRaceIncome = 150 * raceParticipant[indexRaceParticipant].moneyPicked;
        }
        else
        {
          if ( v143 == RACE_MEDIUM )
            goto LABEL_330;
          if ( v143 != RACE_HARD )
            goto LABEL_335;
        }
        if ( v144 == v126 )
          userLastRaceIncomeNoPrice_456BE0 = 150 * raceParticipant[indexRaceParticipant].moneyPicked;
LABEL_335:
        v150 =drivers[v245].rank;
        if ( v150 > 15 && v150 < 21 && userRacePosition_456B50 != 4 )
        {
          if ( v143 == RACE_MEDIUM )
          {
			  drivers[raceIdParticipants[v144]].lastRaceIncome = 60 * raceParticipant[indexRaceParticipant].moneyPicked;
LABEL_343:
            if ( v144 == v126 )
              userLastRaceIncomeNoPrice_456BE0 = 60 * raceParticipant[indexRaceParticipant].moneyPicked;
            goto LABEL_348;
          }
          if ( v143 == RACE_HARD )
          {
			  drivers[raceIdParticipants[v144]].lastRaceIncome = 80 * raceParticipant[indexRaceParticipant].moneyPicked;
LABEL_346:
            if ( v144 == v126 )
              userLastRaceIncomeNoPrice_456BE0 = 80 * raceParticipant[indexRaceParticipant].moneyPicked;
            goto LABEL_348;
          }
          if ( v143 == RACE_MEDIUM )
            goto LABEL_343;
          if ( v143 == RACE_HARD )
            goto LABEL_346;
        }
LABEL_348:
        if ( v143 )
        {
          if ( v143 == RACE_MEDIUM)
          {
            v152 = raceParticipant[indexRaceParticipant].racePosition;
            if ( v152 == RACE_POSITION_1 && raceParticipant[indexRaceParticipant].damage != 100 )
            {
              drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_MEDIUM_FIRST_POSITION_PRIZE" ,3000);
              if ( v144 == v126 )
                userLasRacePriceIncome_456BDC = getModIntEntry("RACE_MEDIUM_FIRST_POSITION_PRIZE" ,3000);
            }
            if ( v152 == RACE_POSITION_2 && raceParticipant[indexRaceParticipant].damage != 100 )
            {
				drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_MEDIUM_SECOND_POSITION_PRIZE" ,1500);
              if ( v144 == v126 )
                userLasRacePriceIncome_456BDC = getModIntEntry("RACE_MEDIUM_SECOND_POSITION_PRIZE" ,1500);
            }
            if ( v152 == RACE_POSITION_3 && raceParticipant[indexRaceParticipant].damage != 100 )
            {
				drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_MEDIUM_THIRD_POSITION_PRIZE" ,375);
              if ( v144 == v126 )
                userLasRacePriceIncome_456BDC = getModIntEntry("RACE_MEDIUM_THIRD_POSITION_PRIZE" ,375);
            }
          }
          else if ( v143 == RACE_HARD )
          {
            v151 = raceParticipant[indexRaceParticipant].racePosition;
            if ( v151 == RACE_POSITION_1 && raceParticipant[indexRaceParticipant].damage != 100 )
            {
				drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_HARD_FIRST_POSITION_PRIZE" ,12000);
              if ( v144 == v126 )
                userLasRacePriceIncome_456BDC = getModIntEntry("RACE_HARD_FIRST_POSITION_PRIZE" ,12000);
            }
            if ( v151 == RACE_POSITION_2 && raceParticipant[indexRaceParticipant].damage != 100 )
            {
				drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_HARD_SECOND_POSITION_PRIZE" ,6000);
              if ( v144 == v126 )
                userLasRacePriceIncome_456BDC = getModIntEntry("RACE_HARD_SECOND_POSITION_PRIZE" ,6000);;
            }
            if ( v151 == RACE_POSITION_3 && raceParticipant[indexRaceParticipant].damage != 100 )
            {
				drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_HARD_THIRD_POSITION_PRIZE" ,1500);
              if ( v144 == v126 )
                userLasRacePriceIncome_456BDC = getModIntEntry("RACE_HARD_THIRD_POSITION_PRIZE" ,1500);
            }
          }
        }
        else
        {//RACE_EASY
          v153 = raceParticipant[indexRaceParticipant].racePosition;
          if ( v153 == RACE_POSITION_1 && raceParticipant[indexRaceParticipant].damage != 100 )
          {
			  drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_EASY_FIRST_POSITION_PRIZE" ,750);
            if ( v144 == v126 )
              userLasRacePriceIncome_456BDC = getModIntEntry("RACE_EASY_FIRST_POSITION_PRIZE" ,750);
          }
          if ( v153 == RACE_POSITION_2 && raceParticipant[indexRaceParticipant].damage != 100 )
          {
			  drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_EASY_SECOND_POSITION_PRIZE" ,375);
            if ( v144 == v126 )
              userLasRacePriceIncome_456BDC = getModIntEntry("RACE_EASY_SECOND_POSITION_PRIZE" ,375);
          }
          if ( v153 == RACE_POSITION_3 && raceParticipant[indexRaceParticipant].damage != 100 )
          {
			  drivers[raceIdParticipants[v144]].lastRaceIncome += getModIntEntry("RACE_EASY_THIRD_POSITION_PRIZE" ,187);
            if ( v144 == v126 )
              userLasRacePriceIncome_456BDC = getModIntEntry("RACE_EASY_THIRD_POSITION_PRIZE" ,187);;
          }
        }
        v154 = raceIdParticipants[v144];
        drivers[v154].money += drivers[v154].lastRaceIncome;
        drivers[v154].totalIncome += drivers[v154].lastRaceIncome;
        if ( raceParticipant[indexRaceParticipant].racePosition == 1 )
          ++drivers[raceIdParticipants[v144]].racesWon;
       
        ++v144;
		indexRaceParticipant++;
      }
      while (indexRaceParticipant < 4 );
    }
    if (drivers[v245].points > v140 )
    {
      v155 = raceIdParticipants[userRaceOrder_45FC20];
      userLastRaceIncomeNoPrice_456BE0 = 400 * *(int *)((char *)&dword_4A7A6C + v244);
      drivers[v155].lastRaceIncome = userLastRaceIncomeNoPrice_456BE0;
    }
  }
  v209 = getMaxDriverPoints(driverId);
  
  v212 = isMultiplayerGame;
  if ( isMultiplayerGame || (v213 = v245, drivers[v245].points <= v209) )
  {
    v214 = 0;
    if (participants > 0 )
    {
      //v215 = dword_4A7A70;
      do
      {
        v216 = raceIdParticipants[ v214];
        ++drivers[v216].totalRaces;
        v217 = raceParticipant[v214].damage;
        ++v214;
       // v215 += 21;
        drivers[v216].racesWon = v217;
      }
      while ( v214 < participants);
    }
    if ( v212 )
      goto LABEL_477;
  }
  else
  {
    ++drivers[v245].totalRaces;
	drivers[v213].damage = dword_4A7AC4;
    //*(int *)((char *)dword_46084C + v213) = dword_4A7AC4;
  }
  sub_4279C0();//parece que abre el popup de terminar porque no tienes pasta
LABEL_477:
  //allocateMemory(0x4B000u);
  screenBuffer = v218;
  dword_461250 = (int)v218;
  loadGraphics1();
  
  maxDriverPoints = getMaxDriverPoints(driverId);
  if ( drivers[driverId].points <= maxDriverPoints || dword_456BD8 != 1 || isMultiplayerGame )
  {
    v222 = drivers[driverId].colour;
    v223 = (char *)graphicsGeneral.copperPal + 2 * v222;
    v224 = (unsigned __int8)v223[v222 + 2];
    v225 = (int)&v223[v222];
    v226 = *(BYTE *)(v225 + 1);
    v227 = (double)v224;
    v244 = *(BYTE *)v225;
    v228 = (double)v226;
    v229 = (double)v244;
    setPaletteValueWithFloats(v229, v228, v227);
    loadMusic(1, "MEN-MUS.CMF", 2, "MEN-SAM.CMF");
    musicSetmusicVolume(configuration.musicVolume);
    nullsub_1();
    musicPlayMusic();
    nullsub_1();
    nullsub_1();
    setWindowCaption2();
    recalculateSDLTicks_43C740();
  }
  loadPaletteMenu();
  v230 = 0;
  do
    setPaletteAndGetValue(v230++, 0, 0, 0);
  while ( v230 < 256 );
  if ( isMultiplayerGame )
  {
  //  multiplayer_42BD10();
    //if ( dword_456B98 )
      //multiplayer_42A300();
  }
  else
  {
    
	maxDriverPoints = getMaxDriverPoints(driverId);
    if ( drivers[driverId].points <= maxDriverPoints)
    {
      postRaceMain(0, (char **)"", (char **)"");
    }
    else
    {
      calculateNextRaces();
      do
      {
        do
          addParticipantToRace(1);
        while (participantsRace[1]< 4u );
		///while ((unsigned __int8)word_461EB4 < 4u);
      }
      //while ( HIBYTE(word_461EB4) < 4u || (unsigned __int8)byte_461EB6 < 4u );
	  while (participantsRace[0] < 4u || participantsRace[2] < 4u);
      *(_DWORD *)Str = 0;
	   indexRaceParticipant = 0;
      //v234 = (signed int)dword_4A7AA0;
      do
      {
        do
        {
          v235 = rand() % 4;
          v236 = *((BYTE *)&v246 + v235 + 4);
          v237 = v235 + 1;
          raceParticipant[indexRaceParticipant].racePosition = v237;
        }
        while ( v236 );
        //v234 += 84;
        *((BYTE *)&v246 + v237 + 3) = 1;
		indexRaceParticipant++;
      }
      while (indexRaceParticipant < 4 );
	  //while (v234 < (signed int)&unk_4A7BF0);
      if ( dword_456BD8 == 1 )
      {
        showEndAnim_4312D0();
      }
      else
      {
        postRaceMain(0, (char **)"", (char **)"");
        dword_456B58 = 1;
      }
    }
  }
}

//----- (004261D0) --------------------------------------------------------
int drawWaitMultiplayer_4261D0()
{
  int result; // eax@1

  result = multiplayerWaitCounter_456BE8++ + 1;
  if ( multiplayerWaitCounter_456BE8 == 15 )
  {
    drawCircuitPreviewImage();
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "waiting for other players...", 66238);
    result = drawKeyCursor(64264, (char *)screenBuffer + 64264, 0x168u, 20);
  }
  if ( multiplayerWaitCounter_456BE8 == 30 )
  {
    drawCircuitPreviewImage();
    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "waiting for other players...", 66238);
    result = drawKeyCursor(64264, (char *)screenBuffer + 64264, 0x168u, 20);
    multiplayerWaitCounter_456BE8 = 0;
  }
  return result;
}
// 4458B0: using guessed type char letterSpacing_4458B0;
// 456BE8: using guessed type int multiplayerWaitCounter_456BE8;
//----- (004279C0) --------------------------------------------------------
char sub_4279C0()
{
  char v0; // bl@1
  signed int v1; // edi@1
  char v2; // al@2
  signed int v3; // edx@2
  signed int v4; // eax@3
  char v5; // cl@4
  int v6; // edx@8
  int v7; // edx@9
  char *v8; // eax@9
  char v9; // cl@10
  char *v10; // eax@11
  char v11; // cl@12
  char *v12; // eax@13
  char v13; // cl@14
  char *v14; // eax@15
  signed int v15; // edx@15
  char v16; // cl@16
  char result; // al@17
  bool v18; // cf@17
  bool v19; // zf@17

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
  do
    v6 = rand() % 19;
  while ( *((BYTE *)&dword_45F000 + v6) == 1 );
  *((BYTE *)&dword_45F000 + v6) = 1;
  v7 = 280 * v6;
  v8 = &aThisIsIt_Here_[v7];
  do
  {
    v9 = *v8;
    v8[byte_4629F6 - &aThisIsIt_Here_[v7]] = *v8;
    ++v8;
  }
  while ( v9 );
  v10 = &aFastAndDeadly_[v7];
  HIBYTE(word_461ED0) = 1;
  do
  {
    v11 = *v10;
    v10[byte_462A8C - &aFastAndDeadly_[v7]] = *v10;
    ++v10;
  }
  while ( v11 );
  v12 = &aRumble_WannaPl[v7];
  unk_461ED2 = 1;
  do
  {
    v13 = *v12;
    v12[byte_462B22 - &aRumble_WannaPl[v7]] = *v12;
    ++v12;
  }
  while ( v13 );
  v14 = &aFryTheRulesThe[v7];
  unk_461ED3 = 1;
  v15 = byte_462BB8 - &aFryTheRulesThe[v7];
  do
  {
    v16 = *v14;
    v14[v15] = *v14;
    ++v14;
  }
  while ( v16 );
  result = byte_45FB84 + 1;
  v18 = (unsigned __int8)(byte_45FB84 + 1) < 0x12u;
  v19 = byte_45FB84 == 17;
  LOBYTE(word_461ED4) = 1;
  ++byte_45FB84;
  if ( !v18 && !v19 )
  {
    dword_45F000 = 0;
    dword_45F004 = 0;
    dword_45F008 = 0;
    dword_45F00C = 0;
    word_45F010 = 0;
    byte_45F012 = 0;
    byte_45FB84 = 0;
  }
  return result;
}

//----- (0042C670) --------------------------------------------------------
int   sub_42C670(int a1)
{
  signed int v1; // ebp@1
  int v2; // ebx@2
  signed int v3; // edi@3
  int v4; // esi@3
  bool v5; // zf@10
  bool v6; // sf@10
  signed int v8; // [sp+10h] [bp-Ch]@1
  signed int v9; // [sp+14h] [bp-8h]@1
  signed int v10; // [sp+18h] [bp-4h]@2

  v9 = 0;
  v1 = 46720;
  v8 = 65532;
  do
  {
    sub_42A480();
    v2 = v1 + 1280;
    v10 = 27;
    do
    {
      v3 = 0;
      v4 = v2;
      do
      {
        sub_43B080(
          (int)((char *)graphicsGeneral.t15x150Bpk + v3),
          (int)((char *)dword_461ED8 + v4 - 1280),
          15,
          15,
          (int)((char *)screenBuffer + v4 - 1280));
        v3 += 225;
        v4 += 15;
      }
      while ( v3 < 2250 );
      v2 += 9600;
      --v10;
    }
    while ( v10 );
    drawKeyCursor(v1, (char *)screenBuffer + v1, 0x96u, 405);
    if ( a1 == -1 )
    {
      setMusicVolume(v8);
    }
    else if ( a1 == 1 )
    {
      setMusicVolume(v9);
    }
    v1 += 15;
    v5 = v8 == 1524;
    v6 = v8 - 1524 < 0;
    v8 -= 1524;
    v9 += 1524;
  }
  while ( !v6 && !v5 );
  eventDetected();
  sub_418090();
  return sub_42A480();
}
