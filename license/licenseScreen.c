#define _CRT_NONSTDC_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#pragma warning ( disable: 4146  4700 4703 4005)

#pragma warning(push)
#pragma warning(disable: warning-code) //4996 for _CRT_SECURE_NO_WARNINGS equivalent

#pragma warning(pop)

#include "../graphics.h"
#include "../defs.h"
#include "../menus.h"
#include "../dr.h"
#include "licenseScreen.h"
#include <windows.h>
#include "../imageUtil.h"
#include "../drivers.h"
#include "../config.h"


char aSpeedMakesMeDi[21] = "speed makes me dizzy"; // weak
char aILiveToRide[15] = "i live to ride"; // weak
char aPetrolInMyVein[19] = "petrol in my veins"; // weak

 byte unk_4455B0_2[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

//----- (00434800) --------------------------------------------------------
int __cdecl licenseScreen(int useWeapons_mal)
{
  signed int v1; // edx@1
  float v2; // ST3C_4@1
  float v3; // ST38_4@1
  float v4; // ST34_4@1
  signed int v5; // edx@5
  signed int v6; // ecx@5
  int i; // eax@6
  unsigned int v8; // eax@9
  char *v9; // edi@9
  char v10; // cl@10
  int v11; // eax@11
  int v12; // eax@11
  int j; // ecx@11
//  bool v14; // zf@13
//  bool v15; // sf@13
//  unsigned __int8 v16; // of@13
  char *v17; // ecx@15
  char *v18; // eax@15
  char v19; // dl@16
  int v20; // eax@18
  unsigned int v21; // eax@21
  char *v22; // edi@21
  char v23; // cl@22
  int v24; // eax@23
  signed int v25; // edx@25
  signed int v26; // ecx@25
  int k; // eax@26
  signed int v28; // esi@31
  char v29; // bl@39
  signed int v30; // edx@49
  char *v31; // edi@50
  int v32; // ebp@74
  char v33; // al@74
  char *v34; // ecx@74
  int v35; // ebx@77
  char *v36; // eax@77
  unsigned int v37; // esi@77
  char v38; // dl@78
  int v39; // eax@82
  char *v40; // edx@82
  signed int v41; // ecx@82
  int v42; // eax@82
  float v43; // ST3C_4@82
  float v44; // ST38_4@82
  float v45; // ST34_4@82
  char v46; // bl@82
  char *v47; // eax@83
  char *v48; // edx@83
  char v49; // cl@84
  int result; // eax@88
  void *v51; // [sp-4h] [bp-4Ch]@34
  void *v52; // [sp-4h] [bp-4Ch]@54
  int v53; // [sp+0h] [bp-48h]@34
  int v54; // [sp+0h] [bp-48h]@54
//  float v55; // [sp+4h] [bp-44h]@34
//  float v56; // [sp+4h] [bp-44h]@54
  char v57; // [sp+1Fh] [bp-29h]@1
  int v58; // [sp+20h] [bp-28h]@1
  __int16 v59; // [sp+24h] [bp-24h]@9
  
  char v61[120]; // [sp+3Ch] [bp-Ch]@16
  char* DstBuf; // [sp+30h] [bp-18h]@9
  DstBuf = malloc(0x1000);
  extractFromBpa("MENU.BPA", tsahpeBpk_45EB5C, (int)"licence3.bpk");
  copyImageToBuffer((int)tsahpeBpk_45EB5C, (int)textureTemp);
  carAnimCurrentFrame_45FBA0 = 0;
  v57 = 1;
  //dword_46086C[27 * driverId] = 0;
  drivers[driverId].colour = 0;
  drawTransparentBlock(0, 371, 639, 109);
  drawBottomMenuText();
  v1 = *((byte *)graphicsGeneral.copperPal + 385);
  v2 = (double)*((byte *)graphicsGeneral.copperPal + 386);
  v58 = *((byte *)graphicsGeneral.copperPal + 384);
  v3 = (double)v1;
  v4 = (double)v58;
  setPaletteValueWithFloats(v4, v3, v2);
  if (useWeapons_mal)
    drawImageWithPosition((int)textureTemp, 530, 249, (int)((char *)screenBuffer + 71743));
  else
    drawImageWithPosition((int)textureTemp, 530, 178, (int)((char *)screenBuffer + 71743));
  drawImageWithPosition2((int)fasesel1Bpk, 68, 102, (int)((char *)screenBuffer + 110168));
  drawImageWithPosition2((int)graphicsGeneral.face01Bpk, 64, 64, (int)((char *)screenBuffer + 122330));
  if (useWeapons_mal)
  {
    drawTextWithFont((int)fbig3bBpk, (int)&bigLetterSpacing_445848, "yes", 202463);
    drawTextWithFont((int)fbig3bBpk, (int)&bigLetterSpacing_445848, "no", 202633);
    v5 = 0;
    v6 = 186240;
    do
    {
      for ( i = v5 % 2; i < 530; i += 2 )
        *((byte *)screenBuffer + v6 + i + 63) = -60;
      v6 += 640;
      ++v5;
    }
    while ( v6 < 230400 );
  }
  drawImageWithPosition2((int)carbas2Bpk, 96, 96, (int)((char *)screenBuffer + 113119));
  drawImageWithPosition2((int)carnameBpk, 96, 16, (int)((char *)screenBuffer + 113119));
  itoa(dword_44DF5C, &DstBuf, 10);


   v8 = strlen(&DstBuf) + 1;

	v9 = malloc(v3); //coste + el $
	strcpy(v9,"$"); /* copy name into the new var */
	strcat(v9, &DstBuf);


  v11 = getBoxTextOffset(v9);
  drawInGamePrices(v9, v11 + 165599);
  v12 = 0;
  for ( j = 0; j < carAnimCurrentFrame_45FBA0; ++j )
    v12 += carAnimFrameSize_45FBA0[j];
  copyImageToBuffer((int)((char *)kuplaBpk + v12), (int)dword_461EA4);
  drawImageWithPosition2((int)dword_461EA4, 96, 64, (int)((char *)screenBuffer + 123359));
  drawKeyCursor(123359, (char *)screenBuffer + 123359, 0x60u, 64);
  carAnimCurrentFrame_45FBA0 = (carAnimCurrentFrame_45FBA0 + 1) % 64;
  drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 163370));
  drawImageWithPosition((int)slidcur3Bpk, 10, 24, (int)((char *)screenBuffer + 160952));
  refreshAllScreen();
  eventDetected();
  sub_418090();
  //v17 = &byte_460840[108 * driverId];
  //v18 = &byte_460840[108 * driverId];
  v17 = &drivers[driverId];
  v18 = &drivers[driverId];

 
  do
  {
    v19 = *v18;
    v18[v61 - v17] = *v18;
    ++v18;
  }
  while ( v19 );
  *v17 = 0;
  if ( !readKeyboard(v17, 173, 208, (int)&unk_4455B0_2, 0xAu, 300, 0, 1, 1) )
  {
    loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
    v47 = v61;
    v48 = &drivers[driverId - (signed int)v61];
    do
    {
      v49 = *v47;
      v48[(_DWORD)v47] = *v47;
      ++v47;
    }
    while ( v49 );
    v46 = 0;
    goto LABEL_86;
  }
  loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
  v20 = driverId;
  //si es dukenuken toco sonido
  //if ( dword_460880[27 * driverId] == 2 )
  if (drivers[driverId].face== 2)
  {
    loadMenuSoundEffect(5u, 6, 0, configuration.effectsVolume, 147456);
    v20 = driverId;
  }
  if ( !useWeapons_mal)
    goto LABEL_74;
  drawImageWithPosition((int)textureTemp, 530, 249, (int)((char *)screenBuffer + 71743));
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848,&drivers[driverId], 133293);
  //drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, &byte_460840[108 * driverId], 133293);
  drawImageWithPosition2((int)fasesel1Bpk, 68, 102, (int)((char *)screenBuffer + 110168));
  drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + drivers[driverId].face), 64, 64, (int)((char *)screenBuffer + 122330));
  drawImageWithPosition2((int)carbas2Bpk, 96, 96, (int)((char *)screenBuffer + 113119));
  drawImageWithPosition2((int)carnameBpk, 96, 16, (int)((char *)screenBuffer + 113119));
  itoa(dword_44DF5C, &DstBuf, 10);
  v59 = 36;
  v21 = strlen(&DstBuf) + 1;
  v22 = (char *)&v58 + 3;
  do
    v23 = (v22++)[1];
  while ( v23 );
  memcpy(v22, &DstBuf, v21);
  v24 = getBoxTextOffset((const char *)&v59);
  drawInGamePrices((const char *)&v59, v24 + 165599);
  drawMenuAnimation(479, 192, carAnimCurrentFrame_45FBA0, (int)kuplaBpk, (int)carAnimFrameSize_45FBA0);
  drawKeyCursor(123359, (char *)screenBuffer + 123359, 0x60u, 64);
  carAnimCurrentFrame_45FBA0 = (carAnimCurrentFrame_45FBA0 + 1) % 64;
  drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 163370));
  //drawImageWithPosition((int)slidcur3Bpk, 10, 24, (int)((char *)screenBuffer + dword_46086C[27 * driverId] + 160824));
  
  drawImageWithPosition((int)slidcur3Bpk, 10, 24, (int)((char *)screenBuffer + drivers[driverId].colour + 160824));
  v25 = 0;
  v26 = 71680;
  do
  {
    for ( k = v25 % 2; k < 530; k += 2 )
      *((byte *)screenBuffer + v26 + k + 63) = -60;
    v26 += 640;
    ++v25;
  }
  while ( v26 < 185600 );
  useWeapons = 1;
  if ( !drawYesNoMenu(193, 323, 1, &useWeapons) )
  {
    loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
    v57 = 0;
    goto LABEL_73;
  }
  memcpy((char *)screenBuffer + 53760, (char *)graphicsGeneral.menubg5Bpk + 53760, 0x2C380u);
  drawMenu(INITIAL_MENU, 0);
  createPopup(93, 142, 440, 186, 1);
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "Select difficulty:", 102573);
  drawCursor(115, 28 * configuration.difficulty + 221);
  v28 = configuration.difficulty;
  if (configuration.difficulty )
  {
    drawTextWithFont((int)fbig3bBpk, (int)&bigLetterSpacing_445848, aSpeedMakesMeDi, 138379);
    if ( v28 == 1 )
    {
      drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, aILiveToRide, 156299);
      goto LABEL_37;
    }
  }
  else
  {
    drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, aSpeedMakesMeDi, 138379);
  }
  drawTextWithFont((int)fbig3bBpk, (int)&bigLetterSpacing_445848, aILiveToRide, 156299);
  if ( v28 != 2 )
  {
LABEL_37:
 
	  //v55 = COERCE_FLOAT(aPetrolInMyVein);
   // v55 =  *((float*)aPetrolInMyVein);
    v53 = (int)&bigLetterSpacing_445848;
    v51 = fbig3bBpk;
    goto LABEL_38;
  }
  //v55 = COERCE_FLOAT(aPetrolInMyVein);
  // v55 =  *((float*)aPetrolInMyVein);
  v53 = (int)&bigLetterSpacing_445848;
  v51 = graphicsGeneral.fbig3aBpk;
LABEL_38:
  drawTextWithFont((int)v51, v53, aPetrolInMyVein, 174219);
  refreshAllScreen();
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v29 = eventDetected();
          refreshAndCheckConnection_42A570();
          refreshAndCheckConnection_42A570();
          drawCursor(115, 28 * v28 + 221);
          if ( v29 != -56 )
            break;
          if ( v28 > 0 )
          {
            --v28;
LABEL_49:
            v30 = 90880;
            do
            {
              v31 = (char *)screenBuffer + v30 + 47475;
              memset(v31, 0xC4u, 0x160u);
              v31 += 352;
              *(_WORD *)v31 = -15164;
              v30 += 640;
              v31[2] = -60;
            }
            while ( v30 < 144640 );
            if ( v28 )
            {
              drawTextWithFont((int)fbig3bBpk, (int)&bigLetterSpacing_445848, aSpeedMakesMeDi, 138379);
              if ( v28 == 1 )
              {
                drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, aILiveToRide, 156299);
                goto LABEL_57;
              }
            }
            else
            {
              drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, aSpeedMakesMeDi, 138379);
            }
            drawTextWithFont((int)fbig3bBpk, (int)&bigLetterSpacing_445848, aILiveToRide, 156299);
            if ( v28 == 2 )
            {
				// v56 =  *((float*)aPetrolInMyVein);
              //v56 = COERCE_FLOAT(aPetrolInMyVein);
              v54 = (int)&bigLetterSpacing_445848;
              v52 = graphicsGeneral.fbig3aBpk;
LABEL_58:
              drawTextWithFont((int)v52, v54, aPetrolInMyVein, 174219);
              drawKeyCursor(138355, (char *)screenBuffer + 138355, 0x190u, 84);
              loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
              goto LABEL_59;
            }
LABEL_57:
			// v56 =  *((float*)aPetrolInMyVein);
            //v56 = COERCE_FLOAT(aPetrolInMyVein);
            v54 = (int)&bigLetterSpacing_445848;
            v52 = fbig3bBpk;
            goto LABEL_58;
          }
        }
        if ( v29 != 72 )
          break;
        if ( v28 > 0 )
        {
          --v28;
          goto LABEL_49;
        }
      }
      if ( v29 != -48 && v29 != 80 )
        break;
      if ( v28 < 2 )
      {
        ++v28;
        goto LABEL_49;
      }
    }
LABEL_59:
    if ( v29 == 28 || v29 == -100 || v29 == 57 )
    {
		configuration.difficulty = v28;
      if ( !v28 )
		  //Speed makes me dizzy
        loadMenuSoundEffect(5u, 1, 0, configuration.effectsVolume, 147456);
      if (configuration.difficulty == 1 )
        loadMenuSoundEffect(5u, 2, 0, configuration.effectsVolume, 147456);
      if (configuration.difficulty == 2 )
        loadMenuSoundEffect(5u, 3, 0, configuration.effectsVolume, 147456);
    }
    if ( v29 == 1 )
      break;
    if ( v29 == 28 || v29 == -100 )
      goto LABEL_73;
  }
  v57 = 0;
  loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
LABEL_73:
  v20 = driverId;
LABEL_74:
  strcpy(drivers[v20].name ,v17);
  strlwr(drivers[v20].name);
  //strlwr(&byte_460840[108 * v20]);
  v32 = 27 * driverId;
  //v33 = byte_460840[108 * driverId];
  v33 = drivers[driverId].name;
  v34 = drivers[driverId].name;
  //v34 = &byte_460840[108 * driverId];
  if ( (unsigned __int8)v33 > 0x60u && (unsigned __int8)v33 < 0x7Bu )
    *v34 = v33 - 32;
  v35 = 0;
  v36 = v34;
  dword_45FA78 = 0;
  v37 = 0;
  do
    v38 = *v36++;
  while ( v38 );
  if ( v36 != v34 + 1 )
  {
    do
      v35 += (unsigned __int8)byte_445892[(unsigned __int8)v34[v37++]];
    while ( v37 < strlen(v34) );
    dword_45FA78 = v35;
  }
  v39 = drivers[v32].colour; //era dword_46086C
  v40 = (char *)graphicsGeneral.copperPal + 2 * v39;
  v41 = (unsigned __int8)v40[v39 + 2];
  v42 = (int)&v40[v39];
  v43 = (double)v41;
  v44 = (double)*(byte *)(v42 + 1);
  v45 = (double)*(byte *)v42;
  setPaletteValueWithFloats(v45, v44, v43);
  v46 = v57;
LABEL_86:
  if ( isMultiplayerGame )
  {
    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to enter chat mode", 233635);
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 233689);
  }
  drawBottomMenuText();
  refreshAllScreen();
  result = (unsigned __int8)v46;
  carAnimCurrentFrame_45FBA0 = 0;

  
  return result;
}

