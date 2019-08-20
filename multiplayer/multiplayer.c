int multiplayer_415280();
int   multiplayer_406D30(int a1);
void   multiplayer_406BE0(char a1);
void multiplayer_403960();
int multiplayer_403D50();
int multiplayer_4039D0();
int multiplayer_403B30();
int multiplayer_403BB0();
int multiplayer_403E30();
signed int   multiplayer_4069D0(char a1);
void multiplayer_4181B0();
void   multiplayer_41EA70(int a1, int a2, char a3);
void multiplayer_42A300();
int multiplayer_sub_42CCF0(void); // weak
signed int   sub_41EB80(int a1, int a2);
char sub_41E9A0();
void   sub_428070(int a1);
char multiplayer_42BD10();

char multiplayer_42BD10()
{
/*  int v0; // eax@1
  unsigned int v1; // eax@1
  char *v2; // edi@1
  char v3; // cl@2
  char *v4; // edi@3
  char v5; // al@4
  int v6; // ST2C_4@5
  int v7; // edx@5
  int i; // eax@5
  int v9; // ecx@6
  int v10; // eax@7
  signed int v11; // ecx@11
  int v12; // esi@12
  char *v13; // edx@17
  char *v14; // eax@17
  int v15; // edx@20
  int v16; // eax@22
  char *v17; // ebx@26
  signed int v18; // ecx@26
  int v19; // esi@27
  char *v20; // edx@32
  char *v21; // eax@32
  int v22; // eax@35
  int v23; // ecx@36
  int v24; // edx@36
  int v25; // ecx@38
  char *v26; // eax@38
  signed int v27; // edx@38
  char v28; // cl@39
  char *v29; // edi@40
  char v30; // al@41
  unsigned int v31; // eax@42
  char *v32; // edi@42
  char v33; // cl@43
  char *v34; // edi@44
  char v35; // al@45
  int *v36; // ecx@46
  signed int v37; // eax@46
  unsigned int v38; // esi@46
  char v39; // dl@47
//  int v40; // eax@50
//  int v41; // edx@51
  int v42; // ecx@52
  int v43; // edi@61
  unsigned __int8 v44; // bp@62
  signed int v45; // esi@62
  int v46; // ST38_4@63
  int v47; // ST34_4@63
  int v48; // eax@63
//  signed int v49; // eax@68
  int v50; // esi@79
  unsigned __int8 v51; // bp@80
  signed int v52; // edi@80
  int v53; // ST38_4@81
  int v54; // ST34_4@81
  int v55; // eax@81
  unsigned __int8 v56; // bp@82
  signed int v57; // edi@82
  int v58; // ST38_4@83
  int v59; // ST34_4@83
  int v60; // eax@83
  char result; // al@85
  int v62; // [sp+10h] [bp-58h]@48
  int v63; // [sp+14h] [bp-54h]@1
  int v64; // [sp+18h] [bp-50h]@1
  int v65; // [sp+1Ch] [bp-4Ch]@1
  int v66; // [sp+20h] [bp-48h]@1
  __int16 v67; // [sp+24h] [bp-44h]@1
  char DstBuf; // [sp+40h] [bp-28h]@1
   int indexRaceParticipant = 0;
  v0 = raceDrivers_456758;
  memcpy(screenBuffer, graphicsGeneral.menubg5Bpk, 0x4B000u);
  v63 = v0;
  drawImageWithPosition((int)graphicsGeneral.rank1cBpk, 54, 386, (int)((char *)screenBuffer + 54060));
  drawImageWithPosition((int)graphicsGeneral.resupok1Bpk, 272, 386, (int)((char *)screenBuffer + 54114));
  drawImageWithPosition((int)graphicsGeneral.resupok1Bpk, 272, 386, (int)((char *)screenBuffer + 53770));
  v66 = 1919251558;
  v64 = 1952543827;
  v65 = 1629516661;
  v67 = 32;
  itoa(drivers[driverId].totalRaces, &DstBuf, 10);
  v1 = strlen(&DstBuf) + 1;
  v2 = (char *)&v63 + 3;
  do
    v3 = (v2++)[1];
  while ( v3 );
  memcpy(v2, &DstBuf, v1);
  v4 = (char *)&v63 + 3;
  do
    v5 = (v4++)[1];
  while ( v5 );
  *(_DWORD *)v4 = 1667330592;
  *((_DWORD *)v4 + 1) = 695412837;
  v6 = (int)graphicsGeneral.fsma3aBpk;
  v4[8] = 0;
  drawTextWithFont(v6, (int)&letterSpacing_4458B0, (const char *)&v64, 289326);
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Multiplayer Ranking", 55096);
  sub_424420();
  v7 = 0;
  for ( i = raceDrivers_456758 - 1; v7 < raceDrivers_456758 - 1; i = raceDrivers_456758 - 1 )
  {
    v9 = 108 * v7;
    if (drivers[v7].totalIncome <= drivers[v7+1].totalIncome)
    {
      ++v7;
    }
    else
    {
      v10 = v7 + 1;
      if ( driverId == v7 )
      {
        driverId = v7 + 1;
      }
      else if ( driverId == v10 )
      {
        driverId = v7;
      }
      memcpy(&unk_4611E0, &byte_460840[v9], 0x6Cu);
      memcpy(&byte_460840[v9], &byte_460840[108 * v10], 0x6Cu);
      memcpy(&byte_460840[108 * v10], &unk_4611E0, 0x6Cu);
      v11 = 0;
      do
      {
        v12 = *((BYTE *)&dword_45FA74 + v11);
        if ( v12 == v7 )
        {
          *((BYTE *)&dword_45FA74 + v11) = v10;
        }
        else if ( v12 == v10 )
        {
          *((BYTE *)&dword_45FA74 + v11) = v7;
        }
        ++v11;
      }
      while ( v11 < 4 );
      v13 = raceParticipant[v7].name;
      memcpy(&unk_4611E0, v13, 0x54u);
      v14 = raceParticipant[v10].name;
      memcpy(v13, v14, 0x54u);
      memcpy(v14, &unk_4611E0, 0x54u);
      v7 = 0;
    }
  }
  v15 = 0;
  if ( i > 0 )
  {
    do
    {
      if (drivers[v15].points<= drivers[v15+1].points)
      {
        ++v15;
      }
      else
      {
        v16 = v15 + 1;
        if ( driverId == v15 )
        {
          driverId = v15 + 1;
        }
        else if ( driverId == v16 )
        {
          driverId = v15;
        }
        v17 = &byte_460840[108 * v15];
        memcpy(&unk_4611E0, v17, 0x6Cu);
        memcpy(v17, &byte_460840[108 * v16], 0x6Cu);
        memcpy(&byte_460840[108 * v16], &unk_4611E0, 0x6Cu);
        v18 = 0;
        do
        {
          v19 = *((BYTE *)&dword_45FA74 + v18);
          if ( v19 == v15 )
          {
            *((BYTE *)&dword_45FA74 + v18) = v16;
          }
          else if ( v19 == v16 )
          {
            *((BYTE *)&dword_45FA74 + v18) = v15;
          }
          ++v18;
        }
        while ( v18 < 4 );
        v20 = raceParticipant[v15].name;
        memcpy(&unk_4611E0, v20, 0x54u);
        v21 = raceParticipant[v16].name;
        memcpy(v20, v21, 0x54u);
        memcpy(v21, &unk_4611E0, 0x54u);
        v15 = 0;
      }
    }
    while ( v15 < raceDrivers_456758 - 1 );
  }
  v22 = raceDrivers_456758;
  if ( raceDrivers_456758 > 0 )
  {
    v23 = (int)drivers[0].rank;
    v24 = raceDrivers_456758;
    do
    {
      *(_DWORD *)v23 = v22--;
      v23 += 108;
      --v24;
    }
    while ( v24 );
  }
  sub_426280();
  v25 = (unsigned __int8)byte_45FC0F[dword_456BCC];
  v26 = &aSuburbia[15 * v25];
  v27 = (char *)&v64 - 15 * v25 - aSuburbia;
  do
  {
    v28 = *v26;
    v26[v27] = *v26;
    ++v26;
  }
  while ( v28 );
  itoa(raceDrivers_456758, &DstBuf, 10);
  v29 = (char *)&v63 + 3;
  do
    v30 = (v29++)[1];
  while ( v30 );
  *(_WORD *)v29 = 32;
  v31 = strlen(&DstBuf) + 1;
  v32 = (char *)&v63 + 3;
  do
    v33 = (v32++)[1];
  while ( v33 );
  memcpy(v32, &DstBuf, v31);
  v34 = (char *)&v63 + 3;
  do
    v35 = (v34++)[1];
  while ( v35 );
  *(_DWORD *)v34 = 1634496557;
  *((_DWORD *)v34 + 1) = 544367993;
  *((_DWORD *)v34 + 2) = 1701011826;
  *((_WORD *)v34 + 6) = 58;
  v36 = &v64;
  v37 = 0;
  v38 = 0;
  do
  {
    v39 = *(BYTE *)v36;
    v36 = (int *)((char *)v36 + 1);
  }
  while ( v39 );
  v62 = (char *)v36 - ((char *)&v64 + 1);
  if ( v36 != (int *)((char *)&v64 + 1) )
  {
    do
      v37 += (unsigned __int8)byte_445892[*((BYTE *)&v64 + v38++)];
    while ( v38 < strlen((const char *)&v64) );
  }
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, (const char *)&v64, 55530 - v37 / 2);
  
  v62 = 50462976;
  if ( v63 > 0 )
  {
	int indexRaceParticipant = 0;
	  
    
    do
    {
      v42 = raceParticipant[indexRaceParticipant].racePosition;
      if (v42 == 1 )
        LOBYTE(v62) = indexRaceParticipant;
      if ( v42 == 2 )
        BYTE1(v62) = indexRaceParticipant;
      if ( v42 == 3 )
        BYTE2(v62) = indexRaceParticipant;
      if ( v42 == 4 )
        BYTE3(v62) = indexRaceParticipant;
      
      
	  indexRaceParticipant++;
    }
    while (indexRaceParticipant < v63 );
  }
  drawRightPositions(raceDrivers_456758, (int)&v62);
  sub_426080();
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press any key to continue...", 289646);
  refreshAllScreen();
  v43 = 0;
  do
  {
    waitWithRefresh();
    v44 = 0;
    v45 = 0;
	//v45 = (signed int)dword_45FC44;
    do
    {
      v46 = (convertColorToPaletteColor((palette1[v45+2]), v43) + 0x8000) >> 16;
      v47 = (convertColorToPaletteColor(palette1[v45 + 1], v43) + 0x8000) >> 16;
      v48 = convertColorToPaletteColor((palette1[v45] ), v43);
      setPaletteAndGetValue(v44, (v48 + 0x8000) >> 16, v47, v46);
      v45 += 3;
      ++v44;
    }
    while ( v45 < maxPaletteEntries );
    v43 += 0x20000;
  }
  while ( v43 < 6553600 );
  do
  {
    refreshAndCheckConnection_42A570();
    drawPressAnyKeyToContinue();
  }
  while ( !eventDetected() );
  drawStadistics();
  sub_426280();
  sub_426080();
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Please wait while loading...", 289646);
  refreshAllScreen();
  loadGraphics2();
  loadGraphics3();
  loadGraphics4();
  sub_426080();
  loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press any key to continue...", 289646);
  refreshAllScreen();
  do
  {
    refreshAndCheckConnection_42A570();
    drawPressAnyKeyToContinue();
  }
  while ( !eventDetected() );
 
  //v49 = (signed int)&dword_4A7AA4; ///raceParticipant[0].difficulty
  while (raceParticipant[indexRaceParticipant].difficulty != -1 || dword_456B9C )
	  //while (*(_DWORD *)v49 != -1 || dword_456B9C)
  {
    //v49 += 84;
	  indexRaceParticipant++;
    if (raceParticipant[indexRaceParticipant].difficulty >= (signed int)&unk_4A7BF4 )
      goto LABEL_76;
  }
  multiplayer_42A300();
  if ( dword_45E0A8 != 2 )
    sub_428070(0);
  driverId = 19;
LABEL_76:
  sub_4224E0();
  if ( !useWeapons && !dword_456B98 && !dword_456B9C )
  {
    v50 = 6553600;
    do
    {
      waitWithRefresh();
      v51 = 0;
      v52 = 0;
	  ///v52 = (signed int)dword_45FC44;
      do
      {
        v53 = (convertColorToPaletteColor((palette1[v52+2]), v50) + 0x8000) >> 16;
        v54 = (convertColorToPaletteColor(palette1[v52 + 1], v50) + 0x8000) >> 16;
        v55 = convertColorToPaletteColor((palette1[v52 ] - 4), v50);
        setPaletteAndGetValue(v51, (v55 + 0x8000) >> 16, v54, v53);
        v52 += 3;
        ++v51;
      }
      while ( v52 < 289 );
	  //while (v52 < (signed int)&unk_4600C4);
      v56 = -128;
	  v57 = 384;
      //v57 = (signed int)&unk_460244;
      do
      {
        v58 = (convertColorToPaletteColor(palette1[v57 + 2], v50) + 0x8000) >> 16;
        v59 = (convertColorToPaletteColor(palette1[v57 + 1], v50) + 0x8000) >> 16;
        v60 = convertColorToPaletteColor(palette1[v57 ], v50);
        setPaletteAndGetValue(v56, (v60 + 0x8000) >> 16, v59, v58);
        v57 += 3;
        ++v56;
		/*v58 = (convertColorToPaletteColor(*(_DWORD *)(v57 + 4), v50) + 0x8000) >> 16;
        v59 = (convertColorToPaletteColor(*(_DWORD *)v57, v50) + 0x8000) >> 16;
        v60 = convertColorToPaletteColor(*(_DWORD *)(v57 - 4), v50);
        setPaletteAndGetValue(v56, (v60 + 0x8000) >> 16, v59, v58);
        v57 += 12;
        ++v56;
      }
      while ( v57 < maxPaletteEntries );
      v50 -= 0x20000;
    }
    while ( v50 >= 0 );
  }
  result = eventDetected();
  dword_456730 = 1;
  return result;*/
}


void   sub_428070(int a1)
{
  /*char v1; // al@2
  char v2; // bl@2
  signed int v3; // edx@2
  signed int v4; // eax@3
  char v5; // cl@4
  char *v6; // eax@6
  char *v7; // edx@6
  char v8; // cl@7
  unsigned int v9; // eax@8
  char *v10; // edi@8
  char v11; // cl@9
  char *v12; // edi@10
  char v13; // al@11
  signed int v14; // edx@12
  signed int v15; // eax@13
  char v16; // cl@14

  dword_4466EC = 1953066569;
  dword_4466F0 = 1768710505;
  dword_4466F4 = 1092642170;
  dword_4466F8 = 2003127840;
  dword_4466FC = 1835091744;
  word_446700 = 101;
  dword_44671E = 1852403530;
  dword_446722 = 544096544;
  dword_446726 = 1936291909;
  dword_44672A = 1735289204;
  dword_44672E = 1835091744;
  word_446732 = 101;
  dword_446782 = 1769104723;
  dword_446786 = 1126198369;
  dword_44678A = 1701736047;
  dword_44678E = 1869182051;
  word_446792 = 110;
  dword_4467B4 = 1818323268;
  dword_4467B8 = 1685015840;
  word_4467BC = 28005;
  byte_4467BE = 0;
  dword_4467E6 = 2004053569;
  dword_456B9C = 1;
  dword_456B94 = 1;
  menuActive_4457F0[0] = 1;
  menuActive_4457F0[18] = 0;
  menuActive_4457F0[19] = 0;
  menuActive_4457F0[20] = 1;
  menuActive_4457F0[21] = 1;
  menuActive_4457F0[22] = 1;
  menuActive_4457F0[23] = 1;
  menuActive_4457F0[24] = 1;
  dword_4467EA = 1293972069;
  dword_4467EE = 1835361391;
  byte_4467F2 = 0;
  dword_445740 = 2;
  nullsub_1();
  nullsub_1();
  if ( a1 == 1 )
  {
    v1 = unk_461EC3;
    unk_461EC0[0] = unk_461EC1;
    unk_461EC3 = word_461EC4;
    v2 = unk_461EC2;
    unk_461EC2 = v1;
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
    dword_456B8C = 0;
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
    v6 = &byte_460840[108 * driverId];
    dword_462C4E = 2108717;
    v7 = &byte_460840[108 * driverId];
    do
      v8 = *v6++;
    while ( v8 );
    v9 = v6 - v7;
    v10 = (char *)&dword_462C4E - 1;
    do
      v11 = (v10++)[1];
    while ( v11 );
    memcpy(v10, v7, v9);
    v12 = (char *)&dword_462C4E - 1;
    do
      v13 = (v12++)[1];
    while ( v13 );
    memcpy(v12, " has left from Death Rally.", 0x1Cu);
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
    unk_461EC0[0] = v2;
    v14 = (signed int)&unk_462096;
    unk_461ED3 = word_461ED4;
    word_461ED4 = 0;
    do
    {
      v15 = v14;
      do
      {
        v16 = *(BYTE *)v15;
        *(BYTE *)(v15 - 150) = *(BYTE *)v15;
        ++v15;
      }
      while ( v16 );
      v14 += 150;
    }
    while ( v14 < (signed int)&blacktx1Bpk );
    LOBYTE(dword_462C4E) = 0;
  }
  if ( dword_456B90 )
  {
    drawMenu(2, 1);
    dword_456B9C = 0;
    dword_456B94 = 0;
    isMultiplayerGame = 0;
    dword_45E0A8 = 0;
    drawTransparentBlock(0, 371, 639, 109);
    drawBottomMenuText();
    refreshAllScreen();
  }*/
}
char sub_41E9A0()
{
  /*signed int v0; // eax@1
  char *v1; // esi@2
  char *v2; // edi@2
  int v3; // ebp@3
  const char *v4; // edi@3
  int v5; // esi@3
  char result; // al@4

  v0 = 0;
  do
  {
    v1 = (char *)graphicsGeneral.menubg5Bpk + v0 + 76812;
    v2 = (char *)screenBuffer + v0 + 76812;
    memcpy(v2, v1, 0x274u);
    v0 += 640;
    *((_WORD *)v2 + 314) = *((_WORD *)v1 + 314);
  }
  while ( v0 < 212480 );
  v3 = 0;
  v4 = (const char *)&unk_462000;
  v5 = 76172;
  do
  {
    result = unk_461EC0[v3];
    if ( !result )
      result = drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, v4, v5);
    if ( unk_461EC0[v3] == 1 )
      result = drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, v4, v5);
    if ( unk_461EC0[v3] == 2 )
      result = drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, v4, v5);
    v5 += 9600;
    ++v3;
    v4 += 150;
  }
  while ( v5 < 287372 );
  return result;*/
}

signed int   sub_41EB80(int a1, int a2)
{
  /*int v2; // eax@2
  int v3; // ecx@2
  int v4; // esi@2
  signed int v5; // edx@2
  int v6; // edi@2
  int v7; // ecx@3
  int v8; // esi@5
  int i; // esi@10
  int j; // eax@12
  int v12; // edi@13
  int v13; // [sp+0h] [bp-4h]@2

  return 0;
  //TODO fix dword_45DC24 no se que es pero hace que pete

  if ( !isMultiplayerGame )
    return 0;
  nullsub_1();
  v2 = dword_45DC24;
  v3 = *(_WORD *)dword_45DC24;
  v4 = v3 - 1;
  v5 = 0;
  v6 = 10 * a2;
  v13 = v3 - 1;
  while ( 1 )
  {
    v7 = *(BYTE *)((((_WORD)v4 - 2) & 0xFFF) + dword_45DC24 + 4);
    if ( *(BYTE *)((v4 & 0xFFF) + dword_45DC24 + 4) != v6 + 3
      || *(BYTE *)((((_WORD)v4 - 1) & 0xFFF) + dword_45DC24 + 4) != v6 + 2 )
      goto LABEL_8;
    v8 = *(_WORD *)dword_45DC24 - v7 - v5;
    if ( *(BYTE *)((((_WORD)v8 - 4) & 0xFFF) + dword_45DC24 + 4) == v6 + 1
      && *(BYTE *)((((_WORD)v8 - 5) & 0xFFF) + dword_45DC24 + 4) == v6 )
      break;
    v4 = v13;
LABEL_8:
    ++v5;
    --v4;
    v13 = v4;
    if ( v5 >= 1000 )
      return 0;
  }
  for ( i = 0; i < v7; ++i )
  {
    *(BYTE *)(i + a1) = *(BYTE *)(v2 + ((i + *(_WORD *)v2 - v7 - v5 - 3) & 0xFFF) + 4);
    v2 = dword_45DC24;
  }
  *(BYTE *)(((*(_WORD *)v2 - (_WORD)v5 - 1) & 0xFFF) + v2 + 4) = 0;
  *(BYTE *)(((*(_WORD *)dword_45DC24 - (_WORD)v5 - 2) & 0xFFF) + dword_45DC24 + 4) = 0;
  *(BYTE *)(((*(_WORD *)dword_45DC24 - (_WORD)v5 - 3) & 0xFFF) + dword_45DC24 + 4) = 0;
  *(BYTE *)(((*(_WORD *)dword_45DC24 - (_WORD)v7 - (_WORD)v5 - 4) & 0xFFF) + dword_45DC24 + 4) = 0;
  *(BYTE *)(((*(_WORD *)dword_45DC24 - (_WORD)v7 - (_WORD)v5 - 5) & 0xFFF) + dword_45DC24 + 4) = 0;
  for ( j = 0; j < v7; *(BYTE *)(v12 + dword_45DC24 + 4) = 0 )
    v12 = (*(_WORD *)dword_45DC24 - v7 - v5 + j++ - 3) & 0xFFF;
  return 1;*/
}

int multiplayer_sub_42CCF0()
{
  /*int v0; // ebp@1
  int v1; // eax@1
  const char *v2; // edi@1
  int v3; // esi@1
  int v4; // ebx@9
  int i; // esi@9
  int v6; // esi@11
  signed int v7; // eax@12
  char *v8; // ecx@13
  char *v9; // edx@13
  char v10; // al@18
  unsigned int v11; // eax@24
  char *v12; // edi@24
  char v13; // cl@25
  signed int v14; // eax@26
  char *v15; // edx@27
  char *v16; // ecx@27
  int v17; // esi@28
  unsigned int v18; // ebx@29
  unsigned int v19; // eax@29
  int v20; // eax@34
  char v21; // cl@35
  signed int v22; // eax@36
  char *v23; // esi@37
  char *v24; // edi@37
  signed int v25; // esi@38
  signed int v26; // eax@39
  char v27; // cl@40
  char *v28; // eax@42
  char v29; // dl@43
  unsigned int v30; // eax@44
  char *v31; // edi@44
  char v32; // cl@45
  char *v33; // edi@46
  char v34; // al@47
  unsigned int v35; // eax@48
  char *v36; // edi@48
  char v37; // cl@49
  char *v38; // eax@51
  char v39; // cl@52
  unsigned int v40; // eax@53
  char *v41; // edi@53
  char v42; // cl@54
  int v43; // ST20_4@55
  char *v44; // eax@55
  unsigned int v45; // ecx@55
  char v46; // dl@56
  char *v47; // eax@61
  char v48; // cl@62
  signed int v49; // eax@64
  char *v50; // esi@65
  char *v51; // edi@65
  signed int v52; // esi@66
  signed int v53; // eax@67
  char v54; // cl@68
  unsigned int v55; // eax@71
  char *v56; // edi@71
  char v57; // cl@72
  char *v58; // eax@74
  char v59; // dl@75
  unsigned int v60; // eax@76
  char *v61; // edi@76
  char v62; // cl@77
  char *v63; // edi@78
  char v64; // al@79
  unsigned int v65; // eax@80
  char *v66; // edi@80
  char v67; // cl@81
  char *v68; // eax@83
  char v69; // cl@84
  signed int v70; // eax@86
  char *v71; // esi@87
  char *v72; // edx@87
  int result; // eax@94
  unsigned __int8 v74; // [sp+0h] [bp-144h]@18
  char v75; // [sp+1h] [bp-143h]@1
  int v76; // [sp+4h] [bp-140h]@9
  int v77; // [sp+8h] [bp-13Ch]@1
  int v78; // [sp+Ch] [bp-138h]@10
  int v79; // [sp+10h] [bp-134h]@24
  char v80[152]; // [sp+14h] [bp-130h]@9
  char DstBuf; // [sp+ACh] [bp-98h]@35
  char v82[151]; // [sp+ADh] [bp-97h]@51

  v0 = 0;
  v1 = dword_456B90 != 0;
  dword_456B54 = 1;
  dword_456B90 = 0;
  memcpy(dword_461ED8, screenBuffer, 0x4B000u);
  v75 = 0;
  v77 = v1;
  memcpy((char *)screenBuffer + 53760, (char *)graphicsGeneral.menubg5Bpk + 53760, 0x3C500u);
  drawTransparentBlock(0, 111, 639, 369);
  drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to minimize chat window", 67875);
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 67929);
  v2 = (const char *)&unk_462000;
  v3 = 76172;
  do
  {
    if ( !unk_461EC0[v0] )
      drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, v2, v3);
    if ( unk_461EC0[v0] == 1 )
      drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, v2, v3);
    if ( unk_461EC0[v0] == 2 )
      drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, v2, v3);
    v3 += 9600;
    ++v0;
    v2 += 150;
  }
  while ( v3 < 287372 );
  refreshAllScreen();
  v4 = 0;
  v80[0] = 0;
  v76 = 0;
  for ( i = 0; ; i = v78 )
  {
    refreshAndCheckConnection_42A570();
    v6 = i + 1;
    v78 = v6;
    if ( v6 <= 10 )
    {
      drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, (const char *)&unk_443C40, v4 + 288012);
    }
    else
    {
      v7 = 0;
      do
      {
        v8 = (char *)graphicsGeneral.menubg5Bpk + v7 + v4 + 288012;
        v9 = (char *)screenBuffer + v7 + v4 + 288012;
        *(_DWORD *)v9 = *(_DWORD *)v8;
        *((_DWORD *)v9 + 1) = *((_DWORD *)v8 + 1);
        *((_DWORD *)v9 + 2) = *((_DWORD *)v8 + 2);
        v7 += 640;
        *((_DWORD *)v9 + 3) = *((_DWORD *)v8 + 3);
      }
      while ( v7 < 10240 );
    }
    if ( v6 > 20 )
      v78 = 0;
    //drawKeyCursor(v4 + 288012, (char *)screenBuffer + v4 + 288012, (unsigned __int8)byte_445911, 15);
	drawKeyCursor(v4 + 288012, (char *)screenBuffer + v4 + 288012, (unsigned __int8)letterSpacing_4458B0[92], 15);
    v10 = sub_418090();
    v74 = v10;
    switch ( v10 )
    {
      case 8:
        v68 = v80;
        do
          v69 = *v68++;
        while ( v69 );
        v79 = v68 - &v80[1];
        if ( v68 != &v80[1] )
        {
          v4 -= (unsigned __int8)byte_445892[(unsigned __int8)v80[strlen(v80) - 1]];
          v70 = 0;
          do
          {
            v71 = (char *)graphicsGeneral.menubg5Bpk + v70 + v4 + 288012;
            v72 = (char *)screenBuffer + v70;
            v70 += 640;
            memcpy(&v72[v4 + 288012], v71, 0x20u);
          }
          while ( v70 < 10240 );
          drawKeyCursor(v4 + 288012, (char *)screenBuffer + v4 + 288012, 0x20u, 16);
          *((BYTE *)&v79 + strlen(v80) + 3) = 0;
        }
        break;
      case 13:
        v47 = v80;
        do
          v48 = *v47++;
        while ( v48 );
        v79 = v47 - &v80[1];
        if ( v47 != &v80[1] )
        {
          v4 = 0;
          v49 = 0;
          do
          {
            v50 = (char *)graphicsGeneral.menubg5Bpk + v49 + 288012;
            v51 = (char *)screenBuffer + v49 + 288012;
            memcpy(v51, v50, 0x260u);
            v49 += 640;
            *((_WORD *)v51 + 304) = *((_WORD *)v50 + 304);
          }
          while ( v49 < 10240 );
          unk_461EC0[0] = unk_461EC1;
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
          v52 = (signed int)&unk_462096;
          unk_461ED2 = unk_461ED3;
          unk_461ED3 = word_461ED4;
          do
          {
            v53 = v52;
            do
            {
              v54 = *(BYTE *)v53;
              *(BYTE *)(v53 - 150) = *(BYTE *)v53;
              ++v53;
            }
            while ( v54 );
            v52 += 150;
          }
          while ( v52 < (signed int)&blacktx1Bpk );
          if ( !memcmp(v80, "/memavail", 0xAu) )
          {
            dword_462C4E = 1293954349;
            dword_462C5A = 1634494817;
            dword_462C52 = 1919905125;
            dword_462C56 = 1986076793;
            dword_462C5E = 979725410;
            word_462C62 = 32;
            itoa(0x40000000, &DstBuf, 10);
            v55 = strlen(&DstBuf) + 1;
            v56 = (char *)&dword_462C4E - 1;
            do
              v57 = (v56++)[1];
            while ( v57 );
            memcpy(v56, &DstBuf, v55);
            HIBYTE(word_461ED4) = 0;
            sub_41E8D0();
            v80[0] = 0;
            refreshAllScreen();
          }
          else
          {
            v58 = &byte_460840[108 * driverId];
            LOWORD(dword_462C4E) = 60;
            do
              v59 = *v58++;
            while ( v59 );
            v60 = v58 - &byte_460840[108 * driverId];
            v61 = (char *)&dword_462C4E - 1;
            do
              v62 = (v61++)[1];
            while ( v62 );
            memcpy(v61, &byte_460840[108 * driverId], v60);
            v63 = (char *)&dword_462C4E - 1;
            do
              v64 = (v63++)[1];
            while ( v64 );
            *(_WORD *)v63 = 8254;
            v63[2] = 0;
            v65 = strlen(v80) + 1;
            v66 = (char *)&dword_462C4E - 1;
            do
              v67 = (v66++)[1];
            while ( v67 );
            memcpy(v66, v80, v65);
            HIBYTE(word_461ED4) = 2;
            //multiplayer_41EA70((int)&dword_462C4E, strlen((const char *)&dword_462C4E) + 1, 1);
            sub_41E8D0();
            v80[0] = 0;
            refreshAllScreen();
          }
        }
        break;
      case 27:
        v76 = -1;
        break;
      default:
        if ( v4 >= 579 - dword_45FA78 )
        {
          v18 = strlen(v80);
          v19 = strlen(v80);
          if ( (v19 & 0x80000000) == 0 )
          {
            while ( v80[v19] != 32 )
            {
              --v19;
              if ( (v19 & 0x80000000) != 0 )
                goto LABEL_34;
            }
            v18 = v19;
          }
LABEL_34:
          v20 = 0;
          do
          {
            v21 = v80[v20];
            *(&DstBuf + v20++) = v21;
          }
          while ( v21 );
          v80[v18] = 0;
          v22 = 0;
          do
          {
            v23 = (char *)graphicsGeneral.menubg5Bpk + v22 + 288012;
            v24 = (char *)screenBuffer + v22 + 288012;
            memcpy(v24, v23, 0x260u);
            v22 += 640;
            *((_WORD *)v24 + 304) = *((_WORD *)v23 + 304);
          }
          while ( v22 < 10240 );
          unk_461EC0[0] = unk_461EC1;
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
          v25 = (signed int)&unk_462096;
          unk_461ED2 = unk_461ED3;
          unk_461ED3 = word_461ED4;
          do
          {
            v26 = v25;
            do
            {
              v27 = *(BYTE *)v26;
              *(BYTE *)(v26 - 150) = *(BYTE *)v26;
              ++v26;
            }
            while ( v27 );
            v25 += 150;
          }
          while ( v25 < (signed int)&blacktx1Bpk );
          v28 = &byte_460840[108 * driverId];
          LOWORD(dword_462C4E) = 60;
          do
            v29 = *v28++;
          while ( v29 );
          v30 = v28 - &byte_460840[108 * driverId];
          v31 = (char *)&dword_462C4E - 1;
          do
            v32 = (v31++)[1];
          while ( v32 );
          memcpy(v31, &byte_460840[108 * driverId], v30);
          v33 = (char *)&dword_462C4E - 1;
          do
            v34 = (v33++)[1];
          while ( v34 );
          *(_WORD *)v33 = 8254;
          v33[2] = 0;
          v35 = strlen(v80) + 1;
          v36 = (char *)&dword_462C4E - 1;
          do
            v37 = (v36++)[1];
          while ( v37 );
          memcpy(v36, v80, v35);
          HIBYTE(word_461ED4) = 2;
          //multiplayer_41EA70((int)&dword_462C4E, strlen((const char *)&dword_462C4E) + 1, 1);
          sub_41E8D0();
          v80[0] = 0;
          if ( v18 != strlen(&DstBuf) )
          {
            v38 = &v82[v18];
            do
            {
              v39 = *v38;
              v38[v80 - &v82[v18]] = *v38;
              ++v38;
            }
            while ( v39 );
          }
          v40 = strlen((const char *)&v74) + 1;
          v41 = (char *)&v79 + 3;
          do
            v42 = (v41++)[1];
          while ( v42 );
          memcpy(v41, &v74, 4 * (v40 >> 2));
          v43 = (int)graphicsGeneral.fsma3cBpk;
          memcpy(&v41[4 * (v40 >> 2)], &v74 + 4 * (v40 >> 2), v40 & 3);
          drawTextWithFont(v43, (int)&letterSpacing_4458B0, v80, 288012);
          v44 = v80;
          v4 = 0;
          v45 = 0;
          do
            v46 = *v44++;
          while ( v46 );
          v79 = v44 - &v80[1];
          if ( v44 != &v80[1] )
          {
            do
              v4 += (unsigned __int8)byte_445892[(unsigned __int8)v80[v45++]];
            while ( v45 < strlen(v80) );
          }
          refreshAllScreen();
        }
        else if ( (unsigned __int8)v10 >= 0x20u && (unsigned __int8)v10 <= 0x7Eu )
        {
          v11 = strlen((const char *)&v74) + 1;
          v12 = (char *)&v79 + 3;
          do
            v13 = (v12++)[1];
          while ( v13 );
          memcpy(v12, &v74, v11);
          v14 = 0;
          do
          {
            v15 = (char *)graphicsGeneral.menubg5Bpk + v14 + v4 + 288012;
            v16 = (char *)screenBuffer + v14 + v4 + 288012;
            *(_DWORD *)v16 = *(_DWORD *)v15;
            *((_DWORD *)v16 + 1) = *((_DWORD *)v15 + 1);
            *((_DWORD *)v16 + 2) = *((_DWORD *)v15 + 2);
            v14 += 640;
            *((_DWORD *)v16 + 3) = *((_DWORD *)v15 + 3);
          }
          while ( v14 < 10240 );
          drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, (const char *)&v74, v4 + 288012);
          v17 = v74;
          drawKeyCursor(v4 + 288012, (char *)screenBuffer + v4 + 288012, (unsigned __int8)byte_445892[v74], 15);
          v4 += (unsigned __int8)byte_445892[v17];
        }
        break;
    }
    if ( eventDetected() == 59 )
      v76 = -1;
    if ( isMultiplayerGame && dword_456B9C || v76 )
      break;
  }
  dword_456B54 = 0;
  memcpy(screenBuffer, dword_461ED8, 0x4B000u);
  result = isMultiplayerGame;
  if ( isMultiplayerGame )
  {
    result = dword_456B9C;
    if ( dword_456B9C )
    {
      dword_456B90 = v77;
    }
    else
    {
      drawBottomMenuText();
      refreshAllScreen();
      result = v77;
      dword_456B90 = v77;
    }
  }
  else
  {
    dword_456B90 = v77;
  }
  return result;*/
}

void multiplayer_42A300()
{
  /*int v0; // eax@1
  const char *v1; // [sp-Ch] [bp-10h]@21

  dword_4466EC = 1953066569;
  dword_4466F8 = 2003127840;
  dword_4466F0 = 1768710505;
  dword_4466F4 = 1092642170;
  dword_44671E = 1852403530;
  dword_4466FC = 1835091744;
  word_446700 = 101;
  dword_44672A = 1735289204;
  v0 = dword_45E0A8;
  dword_446722 = 544096544;
  dword_446726 = 1936291909;
  dword_456B9C = 1;
  dword_44672E = 1835091744;
  word_446732 = 101;
  menuActive_4457F0[20] = 0;
  menuActive_4457F0[21] = 0;
  menuActive_4457F0[22] = 0;
  menuActive_4457F0[23] = 0;
  dword_445740 = 0;
  switch ( dword_45E0A8 )
  {
    case 2:
		menuActive_4457F0[20] = 1;
      break;
    case 1:
		menuActive_4457F0[21] = 1;
      break;
    case 3:
		menuActive_4457F0[22] = 1;
      break;
    case 4:
		menuActive_4457F0[23] = 1;
      break;
  }
  if ( dword_456B90 )
  {
    drawMenu(2, 1);
    dword_456B9C = 0;
    initDrivers();
    refreshAllScreen();
    v0 = dword_45E0A8;
  }
  if ( v0 == 2 )
  {
    nullsub_1();
    dword_45DC20 = 0;
    if ( !sub_43C4B0() )
    {
	  freeMemoryGraphics();
      freeMemoryGraphics1();
      freeMemoryGraphics2();
      freeMemoryGraphics3();
      freeMemoryGraphics4();
      stopAndOpenMusic();
      freeMusic();
      nullsub_1();
      setWindowCaption();
      switch ( dword_45E5E4 )
      {
        case 100:
          v1 = "DEATH RALLY MP-ERROR: Not enough low memory available. About 570k needed!\n";
          break;
        case 101:
          v1 = "DEATH RALLY MP-ERROR: IPX-driver not installed!\n";
          break;
        case 102:
          v1 = "DEATH RALLY MP-ERROR: Socket table is full!\n";
          break;
        case 103:
          v1 = "DEATH RALLY MP-ERROR: Socket already open!\n";
          break;
        case 104:
          v1 = "DEATH RALLY MP-ERROR: COM-PORT not detected!\n";
          break;
        default:
          v1 = "DEATH RALLY MP-ERROR: Unknown error!\n";
          break;
      }
      printf(v1);
      printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
      exit(112);
    }
    if ( isMultiplayerGame )
    {
      if ( dword_45E0A8 == 2 )
        removeBackgroundRefreshFunction_43C730();
      if ( isMultiplayerGame && dword_45E0A8 == 2 )
        nullsub_1();
    }
  }
  isMultiplayerGame = 1;
}
void   multiplayer_41EA70(int a1, int a2, char a3)
{
  char v3; // al@2
  int i; // ecx@2

  if ( isMultiplayerGame )
  {
    v3 = 10 * a3;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = 10 * a3;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = 10 * a3 + 1;
    for ( i = 0; i < a2; ++i )
      *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = *(BYTE *)(i + a1);
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a2;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = v3 + 2;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = v3 + 3;
    nullsub_1();
  }
}
void multiplayer_4181B0()
{
  if ( isMultiplayerGame )
  {
    if ( dword_45E0A8 == 2 )
      nullsub_1();
  }
}
signed int   multiplayer_4069D0(char a1)
{
  int v1; // edi@2
  int v2; // ecx@3
  __int16 v3; // si@3
  __int16 v4; // ax@3
  int v5; // ebp@4
  bool v6; // sf@17
  unsigned __int8 v7; // of@17
  __int16 v9; // ax@20
  int v10; // [sp+10h] [bp-8h]@3
  signed int v11; // [sp+14h] [bp-4h]@4

  if ( isMultiplayerGame )
  {
    nullsub_1();
    v1 = 0;
    if ( numberOfParticipants_508D24 > 0 )
    {
      while ( 2 )
      {
        v2 = dword_45DC30[v1];
        v3 = *(_WORD *)v2;
        v10 = 0;
        v4 = *(_WORD *)v2 - 2;
        do
        {
          v5 = 0;
          v11 = 2;
          do
          {
            if ( *(BYTE *)((v3 & 0xFFF) + v2 + 4) == a1 )
              ++v5;
            if ( *(BYTE *)(((v4 + 1) & 0xFFF) + v2 + 4) == a1 )
              ++v5;
            if ( *(BYTE *)((v4 & 0xFFF) + v2 + 4) == a1 )
              ++v5;
            if ( *(BYTE *)(((v4 - 1) & 0xFFF) + v2 + 4) == a1 )
              ++v5;
            if ( *(BYTE *)(((v4 - 2) & 0xFFF) + v2 + 4) == a1 )
              ++v5;
            v3 -= 5;
            v4 -= 5;
            --v11;
          }
          while ( v11 );
          if ( v5 == 9 )
          {
            v9 = 10 * v10;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - 10 * (_WORD)v10) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 1) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 2) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 3) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 4) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 5) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 6) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 7) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - v9 - 8) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            *(BYTE *)(((*(_WORD *)dword_45DC30[v1] - 10 * (_WORD)v10 - 9) & 0xFFF) + dword_45DC30[v1] + 4) = 0;
            return 1;
          }
          v7 = __OFSUB__(v10 + 1, 10);
          v6 = v10++ - 9 < 0;
        }
        while ( v6 ^ v7 );
        ++v1;
        if ( v1 < numberOfParticipants_508D24 )
          continue;
        break;
      }
    }
  }
  return 0;
}


int multiplayer_403E30()
{
  int v0; // ecx@1
  int v1; // edi@1
  int v2; // eax@2
  int v3; // esi@3
  BYTE *v4; // eax@8
  signed int v5; // eax@8
  int v6; // ecx@14
  int v7; // eax@14
  int v8; // eax@16
  int v9; // ebp@16
  signed int v10; // edi@16
  int v11; // eax@23
  int v12; // eax@25
  int v13; // ebp@25
  signed int v14; // edi@25
  int v15; // eax@32
  int v16; // eax@34
  int v17; // esi@36
  signed int v18; // esi@37
  int v19; // eax@42
  int v20; // eax@44
  int v21; // ebp@44
  signed int v22; // edi@44
  int v23; // eax@51
  int v24; // esi@54
  int v25; // eax@57
  int v26; // eax@59
  int v27; // ebp@59
  signed int v28; // edi@59
  int v29; // edx@66
  int v30; // ecx@66
  int result; // eax@78

  v0 = numberOfParticipants_508D24;
  v1 = 0;
  dword_50E540 = 0;
  currentDriverSelectedIndex_503518 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    v2 = dword_45E0A8;
    do
    {
      v3 = v1;
      dword_46F208 = v1;
      if ( v2 == 1 || v2 == 3 || v2 == 4 )
      {
        v3 = 0;
        dword_46F208 = 0;
      }
      if ( v1 != userRaceOrder_4A9EA8 )
      {
        v4 = &dword_4A7D20[v1];
        *(_DWORD *)v4 = 0;
        *((_DWORD *)v4 + 1) = 0;
        *((_DWORD *)v4 + 2) = 0;
        *((_DWORD *)v4 + 3) = 0;
        *((_DWORD *)v4 + 4) = 0;
        *((_DWORD *)v4 + 5) = 0;
        *((_DWORD *)v4 + 6) = 0;
        *((_DWORD *)v4 + 7) = 0;
        *((_DWORD *)v4 + 8) = 0;
        *((_DWORD *)v4 + 9) = 0;
        *((_DWORD *)v4 + 10) = 0;
        *((_DWORD *)v4 + 11) = 0;
        *((_DWORD *)v4 + 12) = 0;
        *((_DWORD *)v4 + 13) = 0;
        *((_DWORD *)v4 + 14) = 0;
        *((_DWORD *)v4 + 15) = 0;
        v5 = 0;
        dword_456AEC = 0;
        dword_481BE8 = 0;
        dword_4A7A38 = 16;
        dword_456AF0 = 0;
        while ( dword_481BE8 < dword_503510 )
        {
          if ( v5 >= 16 || dword_47968C || dword_4A7A38 <= 0 || dword_4A6B04 )
            break;
          --dword_4A7A38;
          nullsub_1();
          v3 = dword_46F208;
          if ( *(_WORD *)(dword_45DC30[dword_46F208] + 2) == *(_WORD *)dword_45DC30[dword_46F208] )
          {
            v18 = 4;
            do
            {
              nullsub_1();
              --v18;
            }
            while ( v18 );
          }
          else
          {
            v6 = currentDriverSelectedIndex_503518;
            dword_464F30[currentDriverSelectedIndex_503518] = dword_503500;
            v7 = dword_45DC30[v3];
            if ( *(BYTE *)((*(_WORD *)(v7 + 2) & 0xFFF) + v7 + 4) <= 0x7Fu )
            {
              v17 = dword_45DC30[v3];
			  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_481BE8] = *(BYTE *)((*(_WORD *)(v17 + 2) & 0xFFF)
                                                                                 + v17
                                                                                 + 4);
              *(BYTE *)((*(_WORD *)(v17 + 2) & 0xFFF) + v17 + 4) = 0;
              ++*(_WORD *)(dword_45DC30[dword_46F208] + 2);
              dword_456AF0 = dword_481BE8++;
            }
            else
            {
              if ( *(BYTE *)((*(_WORD *)(v7 + 2) & 0xFFF) + v7 + 4) == -2 )
              {
                v8 = refreshScreenWithDelay();
                v3 = dword_46F208;
                v9 = v8;
                v10 = 0;
                if ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 18) & 0xFFF)
                              + dword_45DC30[dword_46F208]
                              + 4) == -1 )
                  goto LABEL_86;
                do
                {
                  if ( v10 )
                    break;
                  nullsub_1();
                  if ( refreshScreenWithDelay() > (unsigned int)(v9 + 2) )
                  {
                    v10 = 1;
                    *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2))++ & 0xFFF) + dword_45DC30[dword_46F208] + 4) = 0;
                  }
                  v3 = dword_46F208;
                }
                while ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 18) & 0xFFF)
                                 + dword_45DC30[dword_46F208]
                                 + 4) != -1 );
                if ( v10 != 1 )
                {
LABEL_86:
                  //multiplayer_403B30();
                  v3 = dword_46F208;
                }
              }
              v11 = dword_45DC30[v3];
              if ( *(BYTE *)((*(_WORD *)(v11 + 2) & 0xFFF) + v11 + 4) == -45
                || *(BYTE *)((*(_WORD *)(v11 + 2) & 0xFFF) + v11 + 4) == -59 )
              {
                v12 = refreshScreenWithDelay();
                v3 = dword_46F208;
                v13 = v12;
                v14 = 0;
                if ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 7) & 0xFFF)
                              + dword_45DC30[dword_46F208]
                              + 4) == -1 )
                  goto LABEL_87;
                do
                {
                  if ( v14 )
                    break;
                  nullsub_1();
                  if ( refreshScreenWithDelay() > (unsigned int)(v13 + 2) )
                  {
                    v14 = 1;
                    *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2))++ & 0xFFF) + dword_45DC30[dword_46F208] + 4) = 0;
                  }
                  v3 = dword_46F208;
                }
                while ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 7) & 0xFFF)
                                 + dword_45DC30[dword_46F208]
                                 + 4) != -1 );
                if ( v14 != 1 )
                {
LABEL_87:
                  *(_WORD *)(dword_45DC30[v3] + 2) += 8;
                  v3 = dword_46F208;
                }
              }
              v15 = dword_45DC30[v3];
              if ( *(BYTE *)((*(_WORD *)(v15 + 2) & 0xFFF) + v15 + 4) == -3 )
              {
                dword_47968C = 1;
                *(BYTE *)((*(_WORD *)(v15 + 2) & 0xFFF) + v15 + 4) = 0;
                ++*(_WORD *)(dword_45DC30[dword_46F208] + 2);
                v3 = dword_46F208;
              }
              v16 = dword_45DC30[v3];
              if ( *(BYTE *)((*(_WORD *)(v16 + 2) & 0xFFF) + v16 + 4) != -4 )
                goto LABEL_40;
              dword_4A6B04 = 1;
              *(BYTE *)((*(_WORD *)(v16 + 2) & 0xFFF) + v16 + 4) = 0;
              ++*(_WORD *)(dword_45DC30[dword_46F208] + 2);
            }
          }
          v3 = dword_46F208;
LABEL_40:
          v5 = dword_481BE8;
        }
        if ( *(_WORD *)(dword_45DC30[v3] + 2) != *(_WORD *)dword_45DC30[v3] )
        {
          while ( 1 )
          {
            v19 = dword_45DC30[v3];
            if ( *(BYTE *)((*(_WORD *)(v19 + 2) & 0xFFF) + v19 + 4) <= 0x7Fu )
              break;
            if ( *(BYTE *)((*(_WORD *)(v19 + 2) & 0xFFF) + v19 + 4) != -2 )
            {
              v23 = dword_45DC30[v3];
              if ( *(BYTE *)((*(_WORD *)(v23 + 2) & 0xFFF) + v23 + 4) == -45
                || *(BYTE *)((*(_WORD *)(v23 + 2) & 0xFFF) + v23 + 4) == -59 )
              {
                v26 = refreshScreenWithDelay();
                v3 = dword_46F208;
                v27 = v26;
                v28 = 0;
                if ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 7) & 0xFFF)
                              + dword_45DC30[dword_46F208]
                              + 4) != -1 )
                {
                  do
                  {
                    if ( v28 )
                      break;
                    nullsub_1();
                    if ( refreshScreenWithDelay() > (unsigned int)(v27 + 2) )
                    {
                      v28 = 1;
                      *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2))++ & 0xFFF)
                               + dword_45DC30[dword_46F208]
                               + 4) = 0;
                    }
                    v3 = dword_46F208;
                  }
                  while ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 7) & 0xFFF)
                                   + dword_45DC30[dword_46F208]
                                   + 4) != -1 );
                  if ( v28 == 1 )
                    goto LABEL_75;
                }
                *(_WORD *)(dword_45DC30[v3] + 2) += 8;
                goto LABEL_74;
              }
              if ( *(BYTE *)((*(_WORD *)(v23 + 2) & 0xFFF) + v23 + 4) == -3 )
              {
                dword_47968C = 1;
                v24 = v23;
                goto LABEL_57;
              }
              v24 = dword_45DC30[v3];
              if ( *(BYTE *)((*(_WORD *)(v24 + 2) & 0xFFF) + v24 + 4) == -4 )
              {
                dword_4A6B04 = 1;
LABEL_57:
                *(BYTE *)((*(_WORD *)(v24 + 2) & 0xFFF) + v24 + 4) = 0;
                v25 = dword_45DC30[dword_46F208];
              }
              else
              {
                *(BYTE *)((*(_WORD *)(v24 + 2) & 0xFFF) + v24 + 4) = 0;
                v25 = dword_45DC30[dword_46F208];
              }
LABEL_73:
              ++*(_WORD *)(v25 + 2);
              goto LABEL_74;
            }
            v20 = refreshScreenWithDelay();
            v3 = dword_46F208;
            v21 = v20;
            v22 = 0;
            if ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 18) & 0xFFF) + dword_45DC30[dword_46F208] + 4) != -1 )
            {
              do
              {
                if ( v22 )
                  break;
                nullsub_1();
                if ( refreshScreenWithDelay() > (unsigned int)(v21 + 2) )
                {
                  v22 = 1;
                  *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2))++ & 0xFFF) + dword_45DC30[dword_46F208] + 4) = 0;
                }
                v3 = dword_46F208;
              }
              while ( *(BYTE *)(((*(_WORD *)(dword_45DC30[dword_46F208] + 2) + 18) & 0xFFF)
                               + dword_45DC30[dword_46F208]
                               + 4) != -1 );
              if ( v22 == 1 )
                goto LABEL_75;
            }
            //multiplayer_403B30();
LABEL_74:
            v3 = dword_46F208;
LABEL_75:
            if ( *(_WORD *)(dword_45DC30[v3] + 2) == *(_WORD *)dword_45DC30[v3] )
              goto LABEL_76;
          }
          v29 = dword_456AF0;
          v30 = currentDriverSelectedIndex_503518;
          if ( *(BYTE *)((*(_WORD *)(v19 + 2) & 0xFFF) + v19 + 4) & IN_RACE_TURBO )
			  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_456AF0] |= IN_RACE_TURBO;
          if ( *(BYTE *)((*(_WORD *)(dword_45DC30[v3] + 2) & 0xFFF) + dword_45DC30[v3] + 4) & IN_RACE_GUN )
			raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_456AF0] |= IN_RACE_GUN;
          if ( *(BYTE *)((*(_WORD *)(dword_45DC30[v3] + 2) & 0xFFF) + dword_45DC30[v3] + 4) & IN_RACE_MINE )
            raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_456AF0] |= IN_RACE_MINE;
          *(BYTE *)((*(_WORD *)(dword_45DC30[v3] + 2) & 0xFFF) + dword_45DC30[v3] + 4) = 0;
          v25 = dword_45DC30[dword_46F208];
          goto LABEL_73;
        }
LABEL_76:
        multiplayer_403BB0();
        *(_WORD *)(dword_45DC30[v3] + 2) = *(_WORD *)dword_45DC30[v3];
        v0 = numberOfParticipants_508D24;
        v2 = dword_45E0A8;
      }
      v1 = currentDriverSelectedIndex_503518++ + 1;
    }
    while ( currentDriverSelectedIndex_503518 < v0 );
  }
  result = 0;
  for ( currentDriverSelectedIndex_503518 = 0; result < v0; currentDriverSelectedIndex_503518 = result )
  {
    if ( result != userRaceOrder_4A9EA8 && dword_464F30[result] + 700 < dword_503500 )
      dword_4A6B04 = 1;
    ++result;
  }
  dword_50E540 = 1;
  return result;
}

int multiplayer_403BB0()
{
  int result; // eax@1
  unsigned int v1; // ecx@3
  int v2; // esi@3
  int v3; // edx@3
  int v4; // ecx@3
  signed int v5; // edx@3
  double v6; // st7@3
  signed int v7; // ecx@3
  signed int v8; // ST08_4@3
  signed int v9; // edx@3
  double v10; // st7@3
  signed int v11; // ST08_4@3
  signed int v12; // ecx@3
  double v13; // st7@3
  signed int v14; // ST08_4@3
  signed int v15; // edx@3
  double v16; // st7@3
  signed int v17; // ST08_4@3
  signed int v18; // ecx@3
  signed int v19; // ST08_4@3
  int v20; // ecx@3
  double v21; // st7@3
  signed int v22; // ST08_4@3

  result = dword_456AEC;
  if ( dword_456AEC )
  {
    if ( byte_4A6832 == -1 )
    {
      v1 = (unsigned __int8)byte_4A6827;
      v2 = currentDriverSelectedIndex_503518;
      result = 864 * currentDriverSelectedIndex_503518;
      raceParticipantIngame[currentDriverSelectedIndex_503518].currentLap_4A7E08 = (unsigned __int8)byte_4A6827 >> 4;
      v3 = (unsigned __int8)byte_4A6823;
	  raceParticipantIngame[currentDriverSelectedIndex_503518].hasFinishedTheRace_4A7E0C = (v1 >> 3) & 1;
      v4 = 37*v2;
	  raceParticipant2[v2].damageBar_4A6898 = 16 * ((unsigned __int8)byte_4A6822 + (v3 << 8));
	  raceParticipant2[v2].turboBar_4A68B4 = (unsigned __int8)byte_4A6824 << 10;
      raceParticipant2[v2].weaponsBar_4A68B0 = (unsigned __int8)byte_4A6825 << 10;
	  raceParticipant2[v2].moneyPicked = (unsigned __int8)byte_4A6826;
      v5 = (unsigned __int8)byte_4A6829;
	  raceParticipantIngame[currentDriverSelectedIndex_503518].actualVaiZone_4A7D00 = (unsigned __int8)byte_4A6828;
      //*(int *)((char *)actualVaiZone_4A7D00 + result) = (unsigned __int8)byte_4A6828;
      v6 = (double)v5;
      v7 = (unsigned __int8)byte_4A682C;
      v8 = (unsigned __int8)byte_4A682B;
      v9 = (unsigned __int8)byte_4A682D;
      raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 = v6 * 256.0 + (double)(unsigned __int8)byte_4A682A;
      v10 = (double)v8;
      v11 = v7;
      v12 = (unsigned __int8)byte_4A682E;
      v13 = v10 * 256.0 + (double)v11;
      v14 = v9;
      v15 = (unsigned __int8)byte_4A682F;
      raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 = v13;
      v16 = (double)v14;
      v17 = v12;
      v18 = (unsigned __int8)byte_4A6830;
      *(float *)(result + 4882000) = v16 * 256.0 + (double)v17;
      v19 = v18;
      v20 = (unsigned __int8)byte_4A6831;
      v21 = (double)v15 * 256.0 + (double)v19;
      v22 = (unsigned __int8)byte_4A6831;
      *(float *)(result + 4882004) = v21;
      raceParticipantIngame[currentDriverSelectedIndex_503518].directionRotation_4A7D0C = v20;
      raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC = (double)v22 * 3.75;
      //*(int *)((char *)participantBpkOffser_4A7D10 + result) = 1600 * (*(int *)((char *)directionRotation_4A7D0C + result) + 96 * v2);
	 // raceParticipantIngame[currentDriverSelectedIndex_503518].participantBpkOffser_4A7D10
    }
    dword_456AEC = 0;
  }
  return result;
}


int multiplayer_403B30()
{
  int v0; // ecx@1
  signed int v1; // eax@1
  signed int v2; // ecx@3
  int result; // eax@4

  v0 = dword_45DC30[dword_46F208];
  v1 = 0;
  do
  {
    byte_4A6820[v1] = *(BYTE *)((((_WORD)v1 + *(_WORD *)(v0 + 2)) & 0xFFF) + v0 + 4);
    ++v1;
  }
  while ( v1 < 19 );
  v2 = 19;
  do
  {
    *(BYTE *)((*(_WORD *)(dword_45DC30[dword_46F208] + 2) & 0xFFF) + dword_45DC30[dword_46F208] + 4) = 0;
    result = dword_45DC30[dword_46F208];
    ++*(_WORD *)(result + 2);
    --v2;
  }
  while ( v2 );
  dword_456AEC = 1;
  return result;
}

int multiplayer_4039D0()
{
  int result; // eax@3
  __int64 v1; // [sp+4h] [bp-10h]@1
  __int64 v2; // [sp+Ch] [bp-8h]@1

  dword_45E080 = 0;
  dword_45E084 = 0;
  word_45E088 = 0;
  dword_45E09E = 0;
  dword_45E08A = 0;
  dword_45E0A2 = 0;
  dword_45E08E = 0;
  dword_45E094 = 0;
  dword_45E098 = 0;
  word_45E0A6 = 0;
  word_45E092 = 0;
  word_45E09C = 0;
  *(_WORD *)dword_45DC24 = 0;
  *(_WORD *)(dword_45DC24 + 2) = 0;
  LODWORD(v1) = 10 * (unsigned __int8)dword_45FA74 + 4579456;
  LODWORD(v2) = 10 * BYTE2(dword_45FA74) + 4579456;
  HIDWORD(v1) = 10 * BYTE1(dword_45FA74) + 4579456;
  HIDWORD(v2) = 10 * BYTE3(dword_45FA74) + 4579456;
  nullsub_1();
  do
    nullsub_1();
  while ( sub_43C4B0() != 255 );
  sub_43C4B0();
  *(_WORD *)dword_45DC24 = 0;
  *(_WORD *)(dword_45DC24 + 2) = 0;
  *(_WORD *)dword_45DC30[0] = 0;
  *(_WORD *)(dword_45DC30[0] + 2) = 0;
  *(_WORD *)dword_45DC34 = 0;
  *(_WORD *)(dword_45DC34 + 2) = 0;
  *(_WORD *)dword_45DC38 = 0;
  *(_WORD *)(dword_45DC38 + 2) = 0;
  *(_WORD *)dword_45DC3C = 0;
  result = dword_45DC3C;
  *(_WORD *)(dword_45DC3C + 2) = 0;
  return result;
}

int multiplayer_403D50()
{
  int result; // eax@1

  nullsub_1();
  result = 0;
  *(_WORD *)dword_45DC24 = 0;
  *(_WORD *)(dword_45DC24 + 2) = 0;
  *(_WORD *)dword_45E064 = 0;
  *(_WORD *)(dword_45E064 + 2) = 0;
  *(_WORD *)dword_45DC30[0] = 0;
  *(_WORD *)(dword_45DC30[0] + 2) = 0;
  *(_WORD *)dword_45DC34 = 0;
  *(_WORD *)(dword_45DC34 + 2) = 0;
  *(_WORD *)dword_45DC38 = 0;
  *(_WORD *)(dword_45DC38 + 2) = 0;
  *(_WORD *)dword_45DC3C = 0;
  *(_WORD *)(dword_45DC3C + 2) = 0;
  memset((void *)(dword_45DC24 + 4), 0, 0x1000u);
  memset((void *)(dword_45DC30[0] + 4), 0, 0x1000u);
  memset((void *)(dword_45DC34 + 4), 0, 0x1000u);
  memset((void *)(dword_45DC38 + 4), 0, 0x1000u);
  memset((void *)(dword_45DC3C + 4), 0, 0x1000u);
  memset((void *)(dword_45E064 + 4), 0, 0x1000u);
  return result;
}


void multiplayer_403960()
{
  nullsub_1();
  do
    nullsub_1();
  while ( (unsigned __int8)sub_43C4B0() != -1 );
  sub_43C4B0();
  nullsub_1();
  dword_503510 = 0;
  dword_4A9EAC = 0;
  dword_503500 = 0;
  dword_4A8D2C = 0;
  dword_4A7CFC = 0;
}

void   multiplayer_406BE0(char a1)
{
  if ( isMultiplayerGame )
  {
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = a1;
    nullsub_1();
  }
}
// 45E064: using guessed type int dword_45E064;
// 45EA04: using guessed type int isMultiplayerGame;

int   multiplayer_406D30(int a1)
{
  void *v1; // eax@1
  void *v2; // eax@5
  signed int v3; // eax@9
  int v4; // edx@9
  const void *v5; // esi@10
  char *v6; // edi@10
  signed int v7; // eax@11
  signed int v8; // esi@13
  int v9; // esi@15
  signed int v10; // edi@15
  signed int v11; // eax@20
  int v12; // ecx@21
  int v13; // edx@21
  char v14; // al@24
  signed int v15; // ecx@39
  signed int v16; // eax@41
  char *v17; // ecx@41
  int v18; // edi@43
  signed int v19; // esi@43
  int v20; // eax@46
  int v21; // ebp@46
  int v22; // ecx@46
  int result; // eax@53
  int v24[102]; // [sp+8h] [bp-330h]@40
  char v25; // [sp+1A0h] [bp-198h]@41

  dword_4A7CF4 = 0;
  dword_503220 = 0;
  dword_464F18 = 0;
  dword_479268 = 0;
  dword_481E08 = 0;

  v1=malloc(0xFA00u);
  if ( !v1 )
  {
    freeMusic();
    setWindowCaption();
    printf("DEATH RALLY Error: Cannot allocate memory!\n");
    printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
    if ( isMultiplayerGame )
      nullsub_1();
    exit(112);
  }
  Memory = v1;
  	//TODO correct
  v2 = malloc(0xFA00u);
  if ( !v2 )
  {
    freeMusic();
    setWindowCaption();
    printf("DEATH RALLY Error: Cannot allocate memory!\n");
    printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
    if ( isMultiplayerGame )
      nullsub_1();
    exit(112);
  }
  dword_47926C = v2;
  v3 = 0;
  memset(Memory, 0, 0xFA00u);
  v4 = 0;
  do
  {
    v5 = (const void *)(dword_464F14 + v4 + 96);
    v6 = (char *)dword_47926C + v3;
    v3 += 320;
    v4 += 512;
    memcpy(v6, v5, 0x140u);
  }
  while ( v3 < 64000 );

  v7=0;
  //v7 = (signed int)&unk_479EE0;
  do
  {
	  racePopupMemory[v7].unk_479F00 = 100;
	  racePopupMemory[v7].unk_479EE0 = 0;
	  racePopupMemory[v7].unk_479EE4= 0;
	  racePopupMemory[v7].unk_479EEC = 0;
	  racePopupMemory[v7].unk_479EE8 = 0;
	  racePopupMemory[v7].unk_479EF0 = malloc(4); ///TODO FIX puesto por mi
    v7 += 1;
  }
  while(v7<969);
  //while ( v7 < (signed int)&unk_481BC9 );
  //v8 = (signed int)dword_50E560;
  v8=0;
  do
  {
    racePopupMemory2[v8].dword_50E560 = rand() % 316;
  v8 += 1;
	
  }
  while(v8 <100);
  //while ( v8 < (signed int)&unk_50E6F0 );
  copyBuffer2Screen(Memory, dword_47926C, 16000);
  copyBuffer2Screen((void *)screenPtr, Memory, 16000);
  stopSoundChannel_43C3E0(5u);
  loadMenuSoundEffect(5u, 17, 0, 0x10000, 163840);
  memset(keysRead_45E0C0, 0, 0x100u);
  v9 = 0;
  dword_479270 = 0;
  v10 = 0;
  do
  {
    if ( dword_479270 >= 968 )
    {
      if ( !v10 )
      {
        v10 = 1;
        stopSoundChannel_43C3E0(5u);
      }
      if ( a1 )
      {
        if ( a1 == 1 )
        {
          if ( multiplayer_4069D0(99) )
            v9 = 1;
          if ( multiplayer_4069D0(98) )
          {
            v9 = 1;
            dword_464F68 = 1;
            v14 = 98;
            goto LABEL_33;
          }
        }
      }
      else
      {
        transformJoystickReadValue_418150();
        v11 = 0;
        do
        {
          v12 = (unsigned __int8)byte_45E0C3[v11]
              + (unsigned __int8)byte_45E0C1[v11]
              + (unsigned __int8)keysRead_45E0C0[v11];
          v13 = v9 + (unsigned __int8)byte_45E0C2[v11];
          v11 += 4;
          v9 = v13 + v12;
        }
        while ( v11 < 256 );
        if ( dword_464F68 == -1 )
        {
          if ( keysRead_45E0C0[KEY_Y] != 1 )
            goto LABEL_32;
          dword_464F68 = 1;
          v14 = 98;
          goto LABEL_33;
        }
      }
    }
    if ( dword_464F68 != 1 )
    {
LABEL_32:
      v14 = 99;
      goto LABEL_33;
    }
    v14 = 98;
LABEL_33:
    if ( !a1 && v9 )
      //multiplayer_406BE0(v14);
    dword_4A9EAC = 0;
    dword_503510 = 0;
    waitWithRefresh();
    copyBuffer2Screen((void *)(screenPtr + 20480), (char *)Memory + 20480, 10880);
    copyBuffer2Screen((char *)Memory + 20480, (char *)dword_47926C + 20480, 10880);
    drawRacepopupEffect_406100();
    dword_5034F0 = dword_4A9EAC;
    if ( dword_4A9EAC < 1 )
      dword_5034F0 = 1;
  }
  while ( !v9 );
  memset(keysRead_45E0C0, 0, 0x100u);
  stopSoundChannel_43C3E0(5u);
  v15 = 0;
  do
  {
    v24[v15] = v15 / -25;
    ++v15;
  }
  while ( v15 < 102 );
  v16 = 102;
  v17 = &v25;
  do
  {
    v24[v16++] = *(_DWORD *)v17;
    v17 -= 4;
  }
  while ( v16 < 204 );
  dword_503220 = 0;
  dword_464F18 = 0;
  v18 = 0;
  dword_4A8AA0 = 13107;

  v19=0;
  //v19 = (signed int)&unk_479EEC;
  do
  {
	  if ( racePopupMemory[v19].unk_479F00 != 100 )
      ++v18;
    *(_DWORD *)v19 = (v24[dword_503220] + rand() % 3) << 16;
    v20 = rand() % 4;
    v21 = dword_503220;
    v22 = 204 * dword_464F18;
	racePopupMemory[v19].unk_479EE8 = (v20 - 2) << 16;
	sub_43AE80(racePopupMemory[v19].unk_479EF0, (int)((char *)inRaceMessagePopup_479690 + v22 + v21), 4, 204);
    dword_464F18 += 4;
    if ( dword_464F18 == 76 )
    {
      dword_464F18 = 0;
      dword_503220 += 4;
    }
    v19 += 1;
  }
  while(v19<969);
  //while ( v19 < 4725717 );
  loadMenuSoundEffect(5u, 21, 0, 0x10000, 163840);
  dword_4A9EAC = 0;
  dword_503510 = 0;
  waitWithRefresh();
  copyBuffer2Screen((void *)screenPtr, Memory, 16000);
  copyBuffer2Screen(Memory, dword_47926C, 16000);
  while ( sub_406330() < v18 )
  {
    dword_5034F0 = dword_4A9EAC;
    if ( dword_4A9EAC < 1 )
      dword_5034F0 = 1;
    dword_4A9EAC = 0;
    dword_503510 = 0;
    waitWithRefresh();
    copyBuffer2Screen((void *)screenPtr, Memory, 16000);
    copyBuffer2Screen(Memory, dword_47926C, 16000);
  }
  stopSoundChannel_43C3E0(5u);
  copyBuffer2Screen((void *)screenPtr, dword_47926C, 16000);
  free(Memory);
  free(dword_47926C);
  dword_503510 = 0;
  dword_503500 = dword_4A8D2C;
  dword_4A9EAC = 0;
  dword_4A7CFC = dword_4A8D2C;
  result = multiplayer_403D50();
  dword_4A7CF4 = 1;
  return result;
}


int multiplayer_415280()
{
  int result; // eax@1
  char v1; // al@2
  unsigned __int64 v2; // rax@2
  unsigned __int64 v3; // rax@2
  unsigned __int64 v4; // rax@2
  unsigned __int64 v5; // rax@2

  result = dword_4A8D2C;
  if ( dword_503500 >= dword_4A8D2C )
  {
    v1 = 8 * (LOBYTE(raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C) + 2 *raceParticipantIngame[ userRaceOrder_4A9EA8].currentLap_4A7E08);
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = -2;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = userRaceOrder_4A9EA8;
	*(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 >> 4;
	*(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 >> 12;
	*(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 >> 10;
	*(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 >> 10;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = LOBYTE(raceParticipant2[userRaceOrder_4A9EA8].moneyPicked);
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = v1;
	*(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = LOBYTE(raceParticipantIngame[ userRaceOrder_4A9EA8].actualVaiZone_4A7D00);
	v2 =raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = BYTE1(v2);
	*(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
    v3 = raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = BYTE1(v3);
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
    v4 = (unsigned __int64)*(float *)&dword_4A7E50[216 * userRaceOrder_4A9EA8];
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = BYTE1(v4);
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = (unsigned __int64)*(float *)&dword_4A7E50[ userRaceOrder_4A9EA8];
    v5 = (unsigned __int64)*(float *)&dword_4A7E54[216 * userRaceOrder_4A9EA8];
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = BYTE1(v5);
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = (unsigned __int64)*(float *)&dword_4A7E54[ userRaceOrder_4A9EA8];
	*(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = LOBYTE(raceParticipantIngame[userRaceOrder_4A9EA8].directionRotation_4A7D0C);
    *(BYTE *)(((*(_WORD *)dword_45E064)++ & 0xFFF) + dword_45E064 + 4) = -1;
    dword_4A6AD4 = 1;
    nullsub_1();
    if ( dword_5034F4 > 0 )
    {
      sub_4138A0();
      dword_5034F4 = 0;
    }
    result = dword_45E0A8;
    dword_4A6AD4 = 0;
    switch ( dword_45E0A8 )
    {
      case 2:
        result = dword_503500 + 1;
        dword_4A8D2C = dword_503500 + 1;
        break;
      case 1:
        dword_4A8D2C = dword_503500 + 2;
        break;
      case 3:
      case 4:
        dword_4A8D2C = dword_503500 + 3;
        break;
    }
  }
  return result;*/
}

