#include "shopScreen.h"

#include "../cars.h"
#include "../variables.h"
#include "util/anim.h"
#include "util/menus.h"
#include "../imageUtil.h"
#include "../config.h"
#include "../defs.h"
#include "../drivers.h"
#include "../dr.h"
#include "../graphics.h"
#include "../i18n/i18n.h"
#include "util/popup.h"
#include <SDL_stdinc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_UNKNOWN unk_444160; // weak
int dword_4451AC = 163840; // weak
_UNKNOWN unk_44E168; // weak
_UNKNOWN unk_45FDC4; // weak

_UNKNOWN unk_44E208; // weak

char shopScreenaStartRacing[13] = "Start Racing"; // weak
char shopScreenaStartANewGame[17] = "Start A New Game"; // weak
char shopScreenaStartANewGam_0[17] = "Start A New Game"; // weak

char aAroundButSheLl[33] = "around, but she'll get you there"; // weak
char aOnHerOwnSweetT[33] = "- on her own sweet time, is all."; // weak
char aVagabondBought[17] = "[Vagabond bought"; // weak
char aFaceItNotTheHo[31] = "Face it, not the hottest thing"; // weak
char aVagabond[9] = "Vagabond"; // weak
//----- (0042D8C0) --------------------------------------------------------
void shopScreenMoveLeft_421DF0()
{
  loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
  switch ( menuOptionSelected_463DF0 )
  {
    case BUY_CAR:
      if ( actualCarSelected <= 0 )
        actualCarSelected = 5;
      else
        --actualCarSelected;
      reloadCarAnimation2();
      drawImageWithPosition((int)((char *)arrows1dBpk + 2048), 16, 64, (int)((char *)screenBuffer + 90240));
      refreshAllScreen();
      reloadCarAnimation2();
      sub_42D780();
      drawImageWithPosition((int)arrows1dBpk, 16, 64, (int)((char *)screenBuffer + 90240));
      refreshAllScreen();
      break;
    case BUY_ENGINE:
      menuOptionSelected_463DF0 = 0;
      reloadCarAnimation2();
      removeBorder(10, 243, 0x6Cu, 114);
      drawBorder(0, 115, 128, 114);
      refreshAllScreen();
      break;
    case BUY_TIRE:
      menuOptionSelected_463DF0 = 1;
      reloadEngineAnimation2();
      removeBorder(114, 243, 0x6Cu, 114);
      drawBorder(10, 243, 108, 114);
      refreshAllScreen();
      break;
    case BUY_ARMOUR:
      menuOptionSelected_463DF0 = 2;
      reloadTireAnimation2();
      removeBorder(218, 243, 0x6Cu, 114);
      drawBorder(114, 243, 108, 114);
      refreshAllScreen();
      break;
    case REPAIR:
      menuOptionSelected_463DF0 = 3;
      reloadArmourAnimation2();
      removeBorder(322, 243, 0x6Cu, 114);
      drawBorder(218, 243, 108, 114);
      refreshAllScreen();
      break;
    case CONTINUE:
      menuOptionSelected_463DF0 = 4;
      reloadRepairAnimation();
      removeBorder(426, 243, 0x6Cu, 114);
      drawBorder(322, 243, 108, 114);
      refreshAllScreen();
      break;
    default:
      return;
  }
}

//----- (0042DAB0) --------------------------------------------------------
void shopScreenMoveRight_42DAB0()
{
  int v0; // eax@1

  v0 = menuOptionSelected_463DF0;
  if ( menuOptionSelected_463DF0 < 5 )
  {
    loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
    v0 = menuOptionSelected_463DF0;
  }
  switch ( v0 )
  {
     case BUY_CAR:
      if ( actualCarSelected >= 5 )
        actualCarSelected = 0;
      else
        ++actualCarSelected;
      reloadCarAnimation2();
      drawImageWithPosition((int)((char *)arrows1dBpk + 3072), 16, 64, (int)((char *)screenBuffer + 90352));
      refreshAllScreen();
      sub_42D780();
      drawImageWithPosition((int)((char *)arrows1dBpk + 1024), 16, 64, (int)((char *)screenBuffer + 90352));
      refreshAllScreen();
      break;
    case BUY_ENGINE:
      menuOptionSelected_463DF0 = 2;
      reloadTireAnimation2();
      removeBorder(10, 243, 0x6Cu, 114);
      drawBorder(114, 243, 108, 114);
      refreshAllScreen();
      break;
    case BUY_TIRE:
      menuOptionSelected_463DF0 = 3;
      reloadArmourAnimation2();
      removeBorder(114, 243, 0x6Cu, 114);
      drawBorder(218, 243, 108, 114);
      refreshAllScreen();
      break;
    case BUY_ARMOUR:
      menuOptionSelected_463DF0 = 4;
      reloadRepairAnimation();
      removeBorder(218, 243, 0x6Cu, 114);
      drawBorder(322, 243, 108, 114);
      refreshAllScreen();
      break;
    case REPAIR:
      menuOptionSelected_463DF0 = 5;
      reloadContinueAnimation();
      removeBorder(322, 243, 0x6Cu, 114);
      drawBorder(426, 243, 108, 114);
      refreshAllScreen();
      break;
    default:
      return;
  }
}

//----- (004373B0) --------------------------------------------------------
void enterShop()
{
  int v0; // edi@1
  int v1; // ecx@1
  __int64 v2; // rax@2
  int v3; // esi@2
  int v4; // edi@4
  int v5; // ebx@6
  unsigned int v6; // eax@9
  char *v7; // edi@9
  char v8; // cl@10
  char *v9; // edi@11
  char v10; // al@12
  int v11; // ST44_4@13
  int v12; // eax@13
  char *v13; // edi@13
  char v14; // al@14
  unsigned int v15; // eax@15
  char *v16; // edi@15
  char v17; // cl@16
  int v18; // ST44_4@17
  char *v19; // eax@17
  char v20; // dl@18
  unsigned int v21; // eax@19
  char *v22; // edi@19
  char v23; // cl@20
  char *v24; // edi@21
  char v25; // al@22
  int v26; // ST44_4@23
  unsigned int v27; // eax@25
  char *v28; // edi@25
  char v29; // cl@26
  char *v30; // edi@27
  char v31; // al@28
  int v32; // ST44_4@29
  int v33; // ecx@29*
  char *v34; // eax@29
  char *v35; // esi@29
  char v36; // dl@30
  char *v37; // edi@31
  char v38; // al@32
  char *v39; // edi@33
  char v40; // al@34
  unsigned int v41; // eax@35
  char *v42; // edi@35
  char v43; // cl@36
  int v44; // ST44_4@37
  signed int v45; // ebp@38
  int v46; // esi@39
//  bool v47; // zf@39
//  bool v48; // sf@39
//  unsigned __int8 v49; // of@39
  signed int v50; // eax@41
  char *v51; // ecx@42
  char v52; // al@45
  signed int v53; // edx@54
  char *v54; // edi@55
  signed int v55; // edx@59
  char *v56; // edi@60
  int v57; // ecx@63
  int v58; // eax@63
  char v59; // bl@63
  int v60; // eax@69
  int v61; // eax@70
  char *v62; // edx@70
  signed int v63; // ecx@70
  int v64; // eax@70
  signed int v65; // edx@70
  float v66; // ST50_4@70
  float v67; // ST4C_4@70
  float v68; // ST48_4@70
  signed int v69; // edx@70
  char *v70; // edi@71
  int v71; // eax@75
  int v72; // edx@78
  int *v73; // ecx@81
  int v74; // edx@84
  int *v75; // ecx@87
  int v76; // eax@91
  int v77; // eax@93
  int v78; // ecx@93
  int v79; // eax@95
  int v80; // eax@97
  int v81; // ecx@97
  int v82; // eax@99
  int v83; // eax@101
  int v84; // ecx@101
  int v85; // ecx@103
  int v86; // edi@103
  __int64 v87; // rax@105
  __int64 v88; // rax@108
  int v89; // eax@117
//  int v90; // esi@121
  signed int v91; // eax@125
  signed int v92; // eax@129
  int v93; // eax@132
  signed int v94; // edx@132
  int v95; // ecx@132
  char* youcould = malloc(100);
  int v96; // [sp+8h] [bp-68h]@7
  int v99[50]; // [sp+34h] [bp-3Ch]@9   8//coger 100 101 102 103 y juntarlo
  char DstBuf[100]; // [sp+20h] [bp-50h]@6
  signed int v97; // [sp+1Ch] [bp-54h]@70
  
  int v100; // [sp+38h] [bp-38h]@9
  int v101; // [sp+3Ch] [bp-34h]@9
  int v102; // [sp+40h] [bp-30h]@9
  __int16 v103; // [sp+44h] [bp-2Ch]@9
  
  DstBuf[0] = "\0";
  if (getModIntEntry("FEATURE_SKIP_SHOP_SCREEN", 0) == 1) {
      v92 = setUndergroundMarketPrices();
      undergroundPricesSet_456B84 = v92;
      if (useWeapons && v92)
      {
          enterBlackMarketScreen();
      }
      else
      {
          loadMenuSoundEffect(1u, 24, 0, configuration.effectsVolume, dword_445190);
          v93 = 0;
          v94 = 2;
          v95 = (int)dword_4608F0;///bucle de puntos de puloto
          do
          {
              if (*(_DWORD*)(v95 - 108) > v93)
              {
                  v5 = v94 - 2;
                  if (v94 - 2 != driverId)
                      v93 = *(_DWORD*)(v95 - 108);
              }
              if (*(_DWORD*)v95 > v93)
              {
                  v5 = v94 - 1;
                  if (v94 - 1 != driverId)
                      v93 = *(_DWORD*)v95;
              }
              if (*(_DWORD*)(v95 + 108) > v93 && v94 != driverId)
                  v93 = *(_DWORD*)(v95 + 108);
              if (*(_DWORD*)(v95 + 216) > v93)
              {
                  v5 = v94 + 1;
                  if (v94 + 1 != driverId)
                      v93 = *(_DWORD*)(v95 + 216);
              }
              if (*(_DWORD*)(v95 + 324) > v93)
              {
                  v5 = v94 + 2;
                  if (v94 + 2 != driverId)
                      v93 = *(_DWORD*)(v95 + 324);
              }
              v94 += 5;
              v95 += 540;
          }             while (v94 - 2 < 20);

          if (drivers[driverId].points <= v93)
              selectRaceScreen();
          else
              adversaryPreviewScreen((const char**)v5);
      }
  }




  v0 = (unsigned __int64)((double)drivers[driverId].carMoneyCost  * 0.25)-5;
  v1 =  driverId;
  if ( useWeapons )
  {
    v2 = drivers[v1].damage * (cars[drivers[v1].carType].repairCost / 10);
    v3 = ((signed int)v2 - HIDWORD(v2)) >> 1;
  }
  else
  {
    v3 = drivers[v1].damage * (cars[drivers[v1].carType].repairCost / 10);
  }
  v4 = v0 - v3;
  if ( v4 < 0 )
    v4 = 0;
  _itoa(v4, DstBuf, 10);
  //todo comentado porque falla
  //*((BYTE *)&v97 + strlen(DstBuf) + 3) = 48;
  v5 = atoi(DstBuf);
  switch ( menuOptionSelected_463DF0 )
  {
    case BUY_CAR:
      v96 =  cars[actualCarSelected].cost - v5;
      if ( v96 >= 0 )
      {
        if ( hasInsuficientMoneyToBuy(v96) )
          return;
        loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
        createPopup(144, 114, 384, 119, 1);
        ///v101 = 1701257316;//d eg	
        v99[0] = 544567129;//you
        v100 = 1819635575;//woul
        v102 = 543236212;//t a
        v103 = 36;
        _itoa(v5, DstBuf, 10);
        v27 = strlen(DstBuf) + 1;
        v28 = &DstBuf[19];
        do
          v29 = (v28++)[1];
        while ( v29 );
        memcpy(v28, DstBuf, v27);
        v30 = &DstBuf[19];
        do
          v31 = (v30++)[1];
        while ( v31 );
        *(_DWORD *)v30 = 1717924384;
        v32 = (int)graphicsGeneral.fsma3cBpk;
        *((_DWORD *)v30 + 1) = 6581877;
        
        youcould = "You could get a $";
        _itoa(v5, DstBuf, 10);
        strcat(youcould, DstBuf);
        strcat(youcould, " refund");
        drawTextWithFont(v32, (int)&letterSpacing_4458B0, youcould, 79530);
        memcpy(&v99, "from your old car and upgrades.", 0x20u);
        drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, (const char *)&v99, 89770);
        //v33 = 1760 * actualCarSelected;
        v34 = &aVagabond[1760 * actualCarSelected];
        v35 = (char *)((char *)&v99 - v34);
        do
        {
          v36 = *v34;
          v34[(_DWORD)v35] = *v34;
          ++v34;
        }
        while ( v36 );
        v37 = &DstBuf[19];
        do
          v38 = (v37++)[1];
        while ( v38 );
        *(_DWORD *)v37 = 1970239264;
        *((_DWORD *)v37 + 1) = 1663067244;
        *((_DWORD *)v37 + 2) = 544502639;
        v37[12] = 0;
        _itoa((cars[actualCarSelected].cost) - v5, DstBuf, 10);
        v39 = &DstBuf[19];
        do
          v40 = (v39++)[1];
        while ( v40 );
        *(_WORD *)v39 = 36;
        v41 = strlen(DstBuf) + 1;
        v42 = &DstBuf[19];
        do
          v43 = (v42++)[1];
        while ( v43 );
        memcpy(v42, DstBuf, 4 * (v41 >> 2));
        v44 = (int)graphicsGeneral.fsma3cBpk;
        memcpy(&v42[4 * (v41 >> 2)], &DstBuf[4 * (v41 >> 2)], v41 & 3);

        youcould = cars[actualCarSelected].name;
        strcat(youcould, " would cost $\0");
        _itoa((cars[actualCarSelected].cost) - v5, DstBuf, 10);
        strcat(youcould, DstBuf);
        drawTextWithFont(v44, (int)&letterSpacing_4458B0, youcould, 100010);
        v100 = 1702060392;
        //v101 = 544500000;
        v99[0] = 1668445520;
        LOWORD(v102) = 63;
        drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, "purchase it ?", 110250);
      }
      else
      {
        if ( hasInsuficientMoneyToBuy(v96) )
          return;
        loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
        createPopup(144, 114, 384, 119, 1);
        //v101 = 1701257316;
        v99[0] = 544567129;
        v100 = 1819635575;
        v102 = 543236212;
        v103 = 36;
        _itoa(v5, DstBuf, 10);
        v6 = strlen(DstBuf) + 1;
        v7 = &DstBuf[19];
        do
          v8 = (v7++)[1];
        while ( v8 );
        memcpy(v7, DstBuf, v6);
        v9 = &DstBuf[19];
        do
          v10 = (v9++)[1];
        while ( v10 );
        *(_DWORD *)v9 = 1717924384;
        v11 = (int)graphicsGeneral.fsma3cBpk;
        *((_DWORD *)v9 + 1) = 6581877;
        drawTextWithFont(v11, (int)&letterSpacing_4458B0, (const char *)&v99, 79530);
        memcpy(&v99, "from your old car and upgrades.", 0x20u);
        drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, (const char *)&v99, 89770);
        v99[0] = 1701736269;
        v102 = 540697701;
        v12 = cars[actualCarSelected].cost;
        //v101 = 1852994932;
        v100 = 1701978233;
        LOBYTE(v103) = 0;
        _itoa(abs(v12 - v5), DstBuf, 10);
        v13 = &DstBuf[19];
        do
          v14 = (v13++)[1];
        while ( v14 );
        *(_WORD *)v13 = 36;
        v15 = strlen(DstBuf) + 1;
        v16 = &DstBuf[19];
        do
          v17 = (v16++)[1];
        while ( v17 );
        memcpy(v16, DstBuf, 4 * (v15 >> 2));
        v18 = (int)graphicsGeneral.fsma3cBpk;
        memcpy(&v16[4 * (v15 >> 2)], &DstBuf[4 * (v15 >> 2)], v15 & 3);
        drawTextWithFont(v18, (int)&letterSpacing_4458B0, (const char *)&v99, 100010);
        BYTE2(v100) = 0;
        v19 = &aVagabond[1760 * actualCarSelected];
        v99[0] = 544830786; //buy
        LOWORD(v100) = 8289;
        do
          v20 = *v19++;
        while ( v20 );
        v21 = v19 - &aVagabond[1760 * actualCarSelected];
        v22 = &DstBuf[19];
        do
          v23 = (v22++)[1];
        while ( v23 );
        memcpy(v22, &aVagabond[1760 * actualCarSelected], v21);
        v24 = &DstBuf[19];
        do
          v25 = (v24++)[1];
        while ( v25 );
        *(_WORD *)v24 = 16160;
        v26 = (int)graphicsGeneral.fsma3cBpk;
        v24[2] = 0;
        drawTextWithFont(v26, (int)&letterSpacing_4458B0, (const char *)&v99, 110250);
      }
      drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("yes"), 118640);
      drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("no"), 118810);
      refreshAllScreen();
      v45 = 0;
      while ( 2 )
      {
        v46 = 170 * v45 + 123097;
        updateCursor(0);//this is a menuType we dont have now
        refreshAndCheckConnection_42A570();
        refreshAndCheckConnection_42A570();
        drawMenuAnimation(16, 141, carAnimCurrentFrame_45FBA0, getCarBpkById(actualCarSelected), (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
        drawKeyCursor(90256, (char *)screenBuffer + 90256, 0x60u, 64);
		carAnimCurrentFrame_45FBA0 = carAnimCurrentFrame_45FBA0 % 64;
        v50 = 0;
        do
        {
          v51 = (char *)screenBuffer + v50 + v46;
          *(_DWORD *)v51 = -993737532;
          *((_DWORD *)v51 + 1) = -993737532;
          *((_DWORD *)v51 + 2) = -993737532;
          v50 += 640;
          *((_DWORD *)v51 + 3) = -993737532;
          *((_DWORD *)v51 + 4) = -993737532;
        }
        while ( v50 < 12800 );
        drawImageWithPosition((int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame), 20, 20, (int)((char *)screenBuffer + v46));
        drawKeyCursor(123045, (char *)screenBuffer + 123045, 0x14Fu, 28);
		cursorBpkFrame = cursorBpkFrame % 48;
        v52 = eventDetected();
        if ( v52 == 21 )
        {
          v52 = -53;
        }
        else if ( v52 == 49 )
        {
          v52 = -51;
        }
        switch ( v52 )
        {
          default:
            continue;
          //case KEY_F1:
            //if ( isMultiplayerGame )
            //  multiplayer_sub_42CCF0();
            continue;
          case KEY_LEFT:
          case 0xCB:
            if ( v45 == 1 )
              loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
            v45 = 0;
            v53 = 0;
            do
            {
              v54 = (char *)screenBuffer + v53 + 123048;
              memset(v54, 0xC4u, 0x14Cu);
              v54 += 332;
              *(_WORD *)v54 = -15164;
              v53 += 640;
              v54[2] = -60;
            }
            while ( v53 < 16000 );
            drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("yes"), 118640);
            drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("no"), 118810);
            continue;
          case KEY_RIGHT:
          case 0xCD:
            if ( !v45 )
              loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
            v45 = 1;
            v55 = 0;
            do
            {
              v56 = (char *)screenBuffer + v55 + 123048;
              memset(v56, 0xC4u, 0x14Cu);
              v56 += 332;
              *(_WORD *)v56 = -15164;
              v55 += 640;
              v56[2] = -60;
            }
            while ( v55 < 16000 );
            drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("yes"), 118640);
            drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("no"), 118810);
            continue;
          case KEY_ENTER:
          case 0x9C:
            loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
            if ( v45 )
              goto LABEL_90;
            loadMenuSoundEffect(5u, 4, 0, configuration.effectsVolume, 147456);
            //v57 = actualCarSelected;
            //v58 =  driverId;
            drivers[driverId].carType = actualCarSelected;
			drivers[driverId].money += v5 - cars[drivers[driverId].carType].cost;
			drivers[driverId].carMoneyCost = cars[drivers[driverId].carType].cost;
			drivers[driverId].damage = 0;
			drivers[driverId].engine = 0;
			drivers[driverId].tire = 0;
			drivers[driverId].armour = 0;
            drawCarRightSide();
            reloadEngineAnimation2();
            reloadArmourAnimation2();
            reloadTireAnimation2();
            reloadRepairAnimation();
            reloadCarAnimation2();
            createPopup(144, 114, 384, 119, 1);
            drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 124988));
            memcpy(&v99, "Use arrows to change the color", 0x1Fu);
            drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, (const char *)&v99, 79530);
            memcpy(&v99, "of your car and press Enter", 0x1Cu);
            drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, (const char *)&v99, 89770);
            v99[0] = 1852139639;
            v100 = 1852401184;
            //v101 = 1701344105;
            LOWORD(v102) = 11876;
            BYTE2(v102) = 0;
            drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, (const char *)&v99, 100010);
            refreshAllScreen();
            v59 = 0;
            do
            {
              if ( v59 == -100 || dword_456B9C )
                break;
              v59 = eventDetected();
              if ( v59 == 59 )
              {
                //if ( isMultiplayerGame )
                //  multiplayer_sub_42CCF0();
                //v60 = driverId;
              }
              else
              {
                //v60 = driverId;
                if ( v59 == -53 )
                {
					v72 = drivers[driverId].colour;
                  if ( v72 > 0 )
					  drivers[driverId].colour = v72 - 2;
                }
				if ( v59 == KEY_LEFT )
                {
                  v73 = &drivers[driverId].colour;
                  if ( *v73 > 0 )
                    *v73 -= 2;
                }
                else
                {
                  if ( v59 == -51 )
                  {
                    v74 = drivers[driverId].colour;
                    if ( v74 < 253 )
						drivers[driverId].colour = v74 + 2;
                  }
				  if ( v59 == KEY_RIGHT )
                  {
                    v75 = &drivers[driverId].colour;
                    if ( *v75 < 253 )
                      *v75 += 2;
                  }
                }
              }
              v61 = drivers[driverId].colour;
              v62 = (char *)graphicsGeneral.copperPal + 2 * v61;
              v63 = (unsigned __int8)v62[v61 + 2];
              v64 = (int)&v62[v61];
              v65 = *(BYTE *)(v64 + 1);
              v66 = (double)v63;
              v97 = *(BYTE *)v64;
              v67 = (double)v65;
              v68 = (double)v97;
			  sub_424240(224,v4,v67,v66);
			  /*		  v1 = *((BYTE *)graphicsGeneral.copperPal + 1);
					  v66 = (double)*((BYTE *)graphicsGeneral.copperPal + 2);
					  v58 = *((BYTE *)graphicsGeneral.copperPal + 0);
					  v67 = (double)v1;
					  v4 = (double)v58;
					  setPaletteValueWithFloats(v4, v67, v66);
              *///
			  setPaletteValueWithFloats(v68, v67, v66);
              v69 = 0;
              do
              {
                v70 = (char *)screenBuffer + v69 + 122422;
                memset(v70, 0xC4u, 0x124u);
                v69 += 640;
                *((_WORD *)v70 + 146) = -15164;
              }
              while ( v69 < 15360 );
              drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 124988));
              drawImageWithPosition(
                (int)slidcur3Bpk,
                10,
                24,
                (int)((char *)screenBuffer + drivers[driverId].colour + 122442));
              refreshAndCheckConnection_42A570();
              refreshAndCheckConnection_42A570();
              drawKeyCursor(
				  drivers[driverId].colour + 122440,
                (char *)screenBuffer + drivers[driverId].colour + 122440,
                0xEu,
                24);
              drawMenuAnimation(
                16,
                141,
                carAnimCurrentFrame_45FBA0,
				  getCarBpkById(actualCarSelected),
                (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
              drawKeyCursor(90256, (char *)screenBuffer + 90256, 0x60u, 64);
			  carAnimCurrentFrame_45FBA0 = carAnimCurrentFrame_45FBA0 % 64;
            }
            while ( v59 != 28 );
            v71 = drivers[driverId].carType;
            if ( v71 >= 5 )
            {
              actualCarSelected = 5;
              showCarBought();
              framesToWaitAfterBuy_456B70 = 310;
              refreshAllScreen();
            }
            else
            {
              actualCarSelected = v71 + 1;
              showCarBought();
              framesToWaitAfterBuy_456B70 = 310;
              refreshAllScreen();
            }
            break;
          case 1:
LABEL_90:
            reloadCarAnimation2();
            refreshAllScreen();
            break;
        }
        break;
      }
      break;
    case BUY_ENGINE:
      v76 = drivers[driverId].engine;
      if ( v76 >= cars[drivers[driverId].carType].engineUpgrades)
      {
        reloadEngineAnimation2();
        refreshAllScreen();
      }
      else if ( !hasInsuficientMoneyToBuy(cars[drivers[driverId].carType].engineUpgradeCosts[drivers[driverId].engine]) )
      {
        loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
        //v77 = 27 * driverId;
		drivers[driverId].money = drivers[driverId].money - cars[drivers[driverId].carType].engineUpgradeCosts[drivers[driverId].engine];
		drivers[driverId].carMoneyCost += cars[drivers[driverId].carType].engineUpgradeCosts[drivers[driverId].engine];
        reloadEngineAnimation();
        v78 = drivers[driverId].engine + 1;
        framesToWaitAfterBuy_456B70 = 310;
		drivers[driverId].engine = v78;
        drawCarRightSide();
        refreshAllScreen();
      }
      break;
    case BUY_TIRE:
      v79 = drivers[driverId].tire;
      if ( v79 >= cars[drivers[driverId].carType].tireUpgrades)
      {
        reloadTireAnimation2();
        refreshAllScreen();
      }
      else if ( !hasInsuficientMoneyToBuy(cars[drivers[driverId].carType].tireUpgradeCosts[drivers[driverId].tire]) )
      {
        loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
        //v80 = 27 * driverId;
		drivers[driverId].money = drivers[driverId].money- cars[drivers[driverId].carType].tireUpgradeCosts[drivers[driverId].tire];
		drivers[driverId].carMoneyCost += cars[drivers[driverId].carType].tireUpgradeCosts[drivers[driverId].tire];
        reloadTireAnimation();
        v81 = drivers[driverId].tire + 1;
        framesToWaitAfterBuy_456B70 = 310;
		drivers[driverId].tire = v81;
        drawCarRightSide();
        refreshAllScreen();
      }
      break;
    case BUY_ARMOUR:
      v82 = drivers[driverId].armour;
      if ( v82 >= cars[drivers[driverId].carType].armourUpgrades)
      {
        reloadArmourAnimation2();
        refreshAllScreen();
      }
      else if ( !hasInsuficientMoneyToBuy(cars[drivers[driverId].carType].armourUpgradeCosts[drivers[driverId].armour]) )
      {
        loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
        //v83 = driverId;
		drivers[driverId].money = drivers[driverId].money - cars[drivers[driverId].carType].armourUpgradeCosts[drivers[driverId].armour];
			
			
		drivers[driverId].carMoneyCost += cars[drivers[driverId].carType].armourUpgradeCosts[drivers[driverId].armour];
        reloadArmourAnimation();
        v84 = drivers[driverId].armour + 1;
        framesToWaitAfterBuy_456B70 = 310;
		drivers[driverId].armour = v84;
        drawCarRightSide();
        refreshAllScreen();
      }
      break;
    case REPAIR:
      v85 = driverId;
      v86 = drivers[ driverId].damage;
      if ( v86 >= 10 )
        goto LABEL_155;
      if ( useWeapons )
      {
        v87 = v86 * (cars[drivers[v85].carType].repairCost / 10);
        v3 = ((signed int)v87 - HIDWORD(v87)) >> 1;
      }
      if ( v86 >= 10 )
      {
LABEL_155:
        if ( useWeapons )
        {
          v88 = cars[drivers[v85].carType].repairCost;
          v3 = ((signed int)v88 - HIDWORD(v88)) >> 1;
        }
        if ( v86 >= 10 )
          goto LABEL_154;
      }
      if ( !useWeapons )
        v3 = v86 * (cars[drivers[v85].carType].repairCost / 10);
      if ( v86 >= 10 )
      {
LABEL_154:
        if ( !useWeapons )
          v3 = cars[drivers[v85].carType].repairCost;
      }
      if ( v86 > 0 && !hasInsuficientMoneyToBuy(v3) )
      {
        loadMenuSoundEffect(1u, 31, 0, configuration.effectsVolume, dword_4451AC);
        v89 = driverId;
        if ( drivers[v89].damage >= 10 )
			drivers[v89].damage -= 10;
        else
			drivers[driverId].damage = 0;
		drivers[v89].money -= v3;
		drivers[v89].carMoneyCost += v3;
        drawCarRightSide();
        reloadRepairAnimation();
        refreshAllScreen();
      }
      break;
    case CONTINUE:
        free(youcould);
      if ( drivers[driverId].damage != 100 || useWeapons )
      {
        if ( isMultiplayerGame )
        {
          selectedRace_462CE8 = 0;
          v91 = setUndergroundMarketPrices();
          undergroundPricesSet_456B84 = v91;
          if (useWeapons && v91 )
          {
            enterBlackMarketScreen();
            dword_456B58 = 1;
          }
          else
          {
            loadMenuSoundEffect(1u, 24, 0, configuration.effectsVolume, dword_445190);
            previewRaceScreen(raceDrivers_456758);
            dword_456B58 = 1;
          }
        }
        else
        {
          v92 = setUndergroundMarketPrices();
          undergroundPricesSet_456B84 = v92;
          if (useWeapons && v92 )
          {
            enterBlackMarketScreen();
          }
          else
          {
            loadMenuSoundEffect(1u, 24, 0, configuration.effectsVolume, dword_445190);
            v93 = 0;
            v94 = 2;
            v95 = (int)dword_4608F0;///bucle de puntos de puloto
            do
            {
              if ( *(_DWORD *)(v95 - 108) > v93 )
              {
                v5 = v94 - 2;
                if ( v94 - 2 != driverId )
                  v93 = *(_DWORD *)(v95 - 108);
              }
              if ( *(_DWORD *)v95 > v93 )
              {
                v5 = v94 - 1;
                if ( v94 - 1 != driverId )
                  v93 = *(_DWORD *)v95;
              }
              if ( *(_DWORD *)(v95 + 108) > v93 && v94 != driverId )
                v93 = *(_DWORD *)(v95 + 108);
              if ( *(_DWORD *)(v95 + 216) > v93 )
              {
                v5 = v94 + 1;
                if ( v94 + 1 != driverId )
                  v93 = *(_DWORD *)(v95 + 216);
              }
              if ( *(_DWORD *)(v95 + 324) > v93 )
              {
                v5 = v94 + 2;
                if ( v94 + 2 != driverId )
                  v93 = *(_DWORD *)(v95 + 324);
              }
              v94 += 5;
              v95 += 540;
            }
            while ( v94 - 2 < 20 );
			
            if ( drivers[ driverId].points <= v93 )
              selectRaceScreen();
            else
              adversaryPreviewScreen((const char **)v5);
          }
        }
      }
      else
      {
        createPopup(144, 114, 384, 119, 1);
        writeTextInScreen("[Repair your car first.", 79530);
        writeTextInScreen((const char *)&unk_444160, 89770);
        writeTextInScreen("What'cha gonna do with that pile of", 100010);
        writeTextInScreen("junk, carry it around? Let me spell", 110250);
        writeTextInScreen("this out for you: R-E-P-A-I-R.", 120490);
        refreshAllScreen();
        loadMenuSoundEffect(2u, 23, 0, configuration.effectsVolume, dword_44518C);
      }
      break;
    default:
        free(youcould);
      return;
  }
}
//----- (004387D0) --------------------------------------------------------
char postLoadedOrLicense()
{
  int v0; // esi@1
  int v1; // ecx@1
  __int64 v2; // rax@2
  int v3; // eax@2
  int v4; // eax@9
  char *v5; // ecx@9
  signed int v6; // edx@9
  int v7; // eax@9
  float v8; // ST3C_4@9
  float v9; // ST38_4@9
  float v10; // ST34_4@9
  int v11; // eax@10
  int v12; // ebp@13
  int v13; // esi@35
  int v14; // edi@39
  int v15; // esi@59
  int v16; // edi@60
//  bool v17; // zf@63
  bool v18; // sf@63
  unsigned __int8 v19 = 0; // of@63
  int v20; // esi@73
  int v21; // edi@74
  unsigned __int8 v22; // di@78
  signed int v23; // esi@78
  int v24; // ST3C_4@79
  int v25; // ST38_4@79
  int v26; // eax@79
  unsigned __int8 v27; // di@80
  signed int v28; // esi@80
  int v29; // ST3C_4@81
  int v30; // ST38_4@81
  int v31; // eax@81
  int v32; // esi@93
  int v33; // edi@94
  signed int continuePlaying; // edi@99
  signed int v35; // ebp@100
  int v36; // eax@117
  int v37; // eax@147
  int v38; // esi@150
  int v39; // edi@150
  int v40; // edx@178
//  double v41; // ST38_8@179
  char v42; // bl@195
  char v43; // dl@196
  char v44; // cl@196
  char v45; // dl@196
  char v46; // al@197
  int *v47; // eax@212
  int v48; // ebp@212
  signed int v49; // ebx@231
  unsigned __int8 v50; // di@232
  signed int v51; // esi@232
  int v52; // ST3C_4@233
  int v53; // ST38_4@233
  int v54; // eax@233
  signed int v56; // [sp+1Ch] [bp-2Ch]@17
  signed int v57; // [sp+20h] [bp-28h]@1
  int v58; // [sp+24h] [bp-24h]@4
  signed int v59; // [sp+28h] [bp-20h]@1
  signed int v60; // [sp+2Ch] [bp-1Ch]@48
  signed int v61; // [sp+30h] [bp-18h]@48
  signed int v62; // [sp+34h] [bp-14h]@17
  signed int v63; // [sp+38h] [bp-10h]@10
  char v64; // [sp+41h] [bp-7h]@196
  char v65=0; // [sp+42h] [bp-6h]@0
  char v66=0; // [sp+43h] [bp-5h]@0
  char v67 = 0; // [sp+44h] [bp-4h]@0
  char v68 = 0; // [sp+45h] [bp-3h]@0

  v57 = 0;
  v59 = 0;
  v0 = (unsigned __int64)ceil((double)drivers[driverId].carMoneyCost * 0.25);
  v1 = driverId;
  if ( useWeapons )
  {
    v2 = drivers[v1].damage * (cars[drivers[v1].carType].repairCost / 10);
    v3 = ((signed int)v2 - HIDWORD(v2)) >> 1;
  }
  else
  {
    v3 = drivers[v1].damage * (cars[drivers[v1].carType].repairCost / 10);
  }
  v58 = v0 - v3;
  if ( v0 - v3 < 0 )
    v58 = 0;

  if ( !dword_456B64 && (!showWelcomePopup_456B74 || isMultiplayerGame) )
  {
    memcpy((void *)dword_45FC00, screenBuffer, 0x4B000u);
    screenBuffer = (void *)dword_45FC00;
    memcpy((void *)(dword_45FC00 + 61440), (char *)graphicsGeneral.menubg5Bpk + 61440, 0x29B80u);
    drawShopAnimationAndRightSide();
	v4 = drivers[driverId].colour;
	//v4 = dword_46086C[27 * driverId];
    v5 = (char *)graphicsGeneral.copperPal + 2 * v4;
    v6 = (unsigned __int8)v5[v4 + 2];
    v7 = (int)&v5[v4];
    v8 = (double)v6;
    v9 = (double)*(BYTE *)(v7 + 1);
    v10 = (double)*(BYTE *)v7;
    setPaletteValueWithFloats(v10, v9, v8);
    screenBuffer = (void *)dword_461250;
    sub_42C4A0();
    refreshAllScreen();
  }
  v11 = isMultiplayerGame;
  menuOptionSelected_463DF0 = 5;
  v63 = 0;
  dword_456B58 = 0;
  do
  {
    if ( dword_456B64 || v57 )
      break;
    v12 = 0;
    if ( showWelcomePopup_456B74 && !v11 )
    {
      sub_4224E0();	  
      selectRaceScreen();
    }
    if ( dword_456B58 != 1 )
      goto LABEL_166;
    dword_456B58 = 0;
    v62 = 0;
    memcpy(screenBuffer, graphicsGeneral.menubg5Bpk, 0x4B000u);
    drawShopAnimationAndRightSide();
    v56 = 0;
    if ( showWelcomePopup_456B74 )
    {
      welcomeShopPopup();
      v56 = 1;
    }
    else
    {
      if ( lapped_456BC0 == 1 )
      {
        lappedPopUp();
        v56 = 9;
LABEL_43:
        v62 = 1;
        goto LABEL_44;
      }
	  //resultados de carrera
      if ( consecutiveWins_456BA8 == 3 )
      {
        winStreakPopUp();
        v56 = 2;
      }
      else if ( noPaintJob_456BAC == 1 )
      {
        noPaintJobPopUp();
        v56 = 3;
      }
      else if ( allCarsCrash_456BB0 == 1 )
      {
        allCarsCrashPopUp();
        v56 = 4;
      }
      else
      {
        if ( drugQuest_456BB4 )
        {
          if ( steriodsNotFoundPopup() )
            v59 = 1;
          v56 = 5;
          goto LABEL_44;
        }
        if ( killOneQuest_456BB8 )
        {
          if ( killOnePopup() )
            v59 = 1;
          v56 = 6;
          goto LABEL_44;
        }
        v13 = 27 * driverId;
        if ( drivers[driverId].loanRaces == 4 )
		//if (dword_460878[27 * driverId] == 4)
        {
          if ( payBackTimePopup() )
            v59 = 1;
          v56 = 7;
          goto LABEL_44;
        }
		v14 = drivers[v13].money;
		///v14 = dword_460870[v13];
        if ( v14 + v58 < 1000 && v14 < getReapirCostByCarType() && drivers[v13].damage > 95 )
        {
          endGamePopup();
          v56 = 8;
          goto LABEL_43;
        }
      }
    }
LABEL_44:
    menuOptionSelected_463DF0 = 5;
    drawTransparentBlock(0, 371, 639, 109);
    if ( isMultiplayerGame )
    {
      drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to enter chat mode", 233635);
      drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 233689);
    }
    drawBottomMenuText();
    refreshAllScreen();
    if ( dword_456B60 )
      musicSetOrder(dword_462D7C);
    sub_4224E0();
    v60 = 0;
    v61 = 0;
    do
    {
      waitWithRefresh();
      if ( dword_456B60 )
        setMusicVolume(v61);
      if ( v60 % 2 )
      {
        if ( !showWelcomePopup_456B74
          && consecutiveWins_456BA8 != 3
          && noPaintJob_456BAC != 1
          && allCarsCrash_456BB0 != 1
          && !drugQuest_456BB4
          && !killOneQuest_456BB8
          && lapped_456BC0 != 1 )
        {
          //v15 = 27 * driverId;
          //if ( dword_460878[27 * driverId] != 4 )
		  v15 = driverId;
		  if (drivers[driverId].loanRaces != 4)
          {
            v16 = drivers[v15].money;
            if ( v16 + v58 >= 1000 && v16 >= getReapirCostByCarType() && drivers[v15].damage <= 95 )
            {
              drawMenuAnimation(432, 269, continueAnimCurrentFrame_4611D0, (int)contaniBpk, (int)continueAnimFramesSize_4611D0);
              drawKeyCursor(172592, (char *)screenBuffer + 172592, 0x60u, 64);
			  continueAnimCurrentFrame_4611D0 = continueAnimCurrentFrame_4611D0 % 22;
            }
          }
        }
      }
      if ( v60 % 2 )
      {
        if ( showWelcomePopup_456B74
          || consecutiveWins_456BA8 == 3
          || noPaintJob_456BAC == 1
          || allCarsCrash_456BB0 == 1
          || drugQuest_456BB4
          || killOneQuest_456BB8
          || lapped_456BC0 == 1
          || (v20 = driverId, drivers[ driverId].loanRaces == 4)
          || (v21 = drivers[v20].money, v21 + v58 < 1000) && v21 < getReapirCostByCarType() && drivers[v20].damage > 95 )
          drawCursor(164, 321);
      }
      v22 = 0;
      v23 = 0;
	  //v23 = (signed int)dword_45FC44;
      do
      {
        v24 = (convertColorToPaletteColor((palette1[v23+2]), v12) + 0x8000) >> 16;
        v25 = (convertColorToPaletteColor(palette1[v23 +1], v12) + 0x8000) >> 16;
        v26 = convertColorToPaletteColor((palette1[v23 ]), v12);
        setPaletteAndGetValue(v22, (v26 + 0x8000) >> 16, v25, v24);
        v23 += 3;
        ++v22;
      }
      while ( v23 <289 );
	  //while (v23 < (signed int)&unk_4600C4);
      v27 = -128;
	  v28 = 384;
	  //v28 = (signed int)&unk_460244;
      do
      {
        v29 = (convertColorToPaletteColor((palette1[v28 + 2]), v12) + 0x8000) >> 16;
        v30 = (convertColorToPaletteColor((palette1[v28 + 1]), v12) + 0x8000) >> 16;
        v31 = convertColorToPaletteColor((palette1[v28]), v12);
        setPaletteAndGetValue(v27, (v31 + 0x8000) >> 16, v30, v29);
        v28 += 3;
        ++v27;
      }
      while ( v28 < maxPaletteEntries );
      v12 += 0x20000;
      v19 = __OFSUB__(v61 + 1310, 65500);
      v18 = v61 - 64190 < 0;
      ++v60;
      v61 += 1310;
    }
    while ( v18 ^ v19 );
    if ( !showWelcomePopup_456B74
      && consecutiveWins_456BA8 != 3
      && noPaintJob_456BAC != 1
      && allCarsCrash_456BB0 != 1
      && !drugQuest_456BB4
      && !killOneQuest_456BB8
      && lapped_456BC0 != 1
      && (isMultiplayerGame || drivers[driverId].rank > 7)
      && userRacePosition_456B50 != 4 )
    {
      v32 =driverId;
      if ( drivers[driverId].loanRaces != 4 )
      {
        v33 = drivers[v32].money;
        if ( v33 + v58 >= 1000 || v33 >= getReapirCostByCarType() || drivers[v32].damage <= 95 )
          goto LABEL_165;
      }
    }
    if ( v56 )
    {
      drawPopupCursor_42C780 ();
      drawCarRightSide();
      refreshAllScreen();
    }
	continuePlaying = v59;
    if ( v59 == 1 )
    {
      endGamePopup();
      v35 = v59;
      refreshAllScreen();
      drawPopupCursor_42C780 ();
      if ( isMultiplayerGame )
      {
        drivers[driverId].money = 495 - (unsigned __int64)((double)dword_4456E8 * -0.2);
        drawCarRightSide();
      }
      else
      {
        v57 = 1;
      }
    }
    else
    {
      v35 = v62;
    }
    switch ( v56 )
    {
      case 1:
        showWelcomePopup_456B74 = 0;
        break;
      case 2:
        consecutiveWins_456BA8 = 0;
        break;
      case 3:
        noPaintJob_456BAC = 0;
        break;
      case 4:
        allCarsCrash_456BB0 = 0;
        break;
      case 5:
        drugQuest_456BB4 = 0;
        break;
      case 6:
        killOneQuest_456BB8 = 0;
        break;
      case 7:
        v36 = driverId;
        drivers[v36].loanType = NO_LOAN;
        drivers[v36].loanRaces = -1;
        break;
      case 9:
        lapped_456BC0 = 0;
        break;
      case 8:
        if ( isMultiplayerGame )
        {
          drivers[driverId].money = 495 - (unsigned __int64)((double)dword_4456E8 * -0.2);
          drawCarRightSide();
        }
        else
        {
          v57 = 1;
        }
        break;
      default:
          break;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              if ( v57 )
              {
                v59 = continuePlaying;
                goto LABEL_157;
              }
              if ( lapped_456BC0 != 1 )
                break;
              lappedPopUp();
              refreshAllScreen();
              drawPopupCursor_42C780 ();
              lapped_456BC0 = 0;
              drawCarRightSide();
              refreshAllScreen();
              v35 = 1;
            }
            if ( consecutiveWins_456BA8 != 3 )
              break;
            winStreakPopUp();
            refreshAllScreen();
            drawPopupCursor_42C780 ();
            consecutiveWins_456BA8 = 0;
            drawCarRightSide();
            refreshAllScreen();
          }
          if ( noPaintJob_456BAC != 1 )
            break;
          noPaintJobPopUp();
          refreshAllScreen();
          drawPopupCursor_42C780 ();
          noPaintJob_456BAC = 0;
          drawCarRightSide();
          refreshAllScreen();
        }
        if ( allCarsCrash_456BB0 != 1 )
          break;
        allCarsCrashPopUp();
        refreshAllScreen();
        drawPopupCursor_42C780 ();
        allCarsCrash_456BB0 = 0;
        drawCarRightSide();
        refreshAllScreen();
      }
      if ( drugQuest_456BB4 )
      {
        if ( steriodsNotFoundPopup() )
			continuePlaying = 1;
        refreshAllScreen();
        drawPopupCursor_42C780 ();
        drugQuest_456BB4 = 0;
        goto LABEL_137;
      }
      if ( killOneQuest_456BB8 )
      {
        if ( killOnePopup() )
			continuePlaying = 1;
        refreshAllScreen();
        drawPopupCursor_42C780 ();
        killOneQuest_456BB8 = 0;
        goto LABEL_137;
      }
      if ( drivers[driverId].loanRaces != 4 )
        break;
      if ( payBackTimePopup() )
		  continuePlaying = 1;
      refreshAllScreen();
      drawPopupCursor_42C780 ();
      v37 =  driverId;
      drivers[v37].loanType = NO_LOAN;
      drivers[v37].loanRaces = -1;
LABEL_137:
      if (continuePlaying != 1 )
        goto LABEL_149;
	  continuePlaying = 0;
      endGamePopup();
      refreshAllScreen();
      v35 = 1;
      drawPopupCursor_42C780 ();
      if ( isMultiplayerGame )
      {
        drivers[driverId].money = 495 - (unsigned __int64)((double)dword_4456E8 * -0.2);
        drawCarRightSide();
        drawCarRightSide();
        refreshAllScreen();
      }
      else
      {
        v57 = 1;
LABEL_149:
        drawCarRightSide();
        refreshAllScreen();
      }
    }
    v38 = driverId;
    v59 = continuePlaying;
    v39 = drivers[ driverId].money;
    if ( v39 + v58 < 1000 && v39 < getReapirCostByCarType() && drivers[v38].damage > 95 )
    {
      endGamePopup();
      refreshAllScreen();
      v35 = 1;
      drawPopupCursor_42C780 ();
      if ( isMultiplayerGame )
      {
        drivers[driverId].money = 495 - (unsigned __int64)((double)dword_4456E8 * -0.2);
        drawCarRightSide();
        drawCarRightSide();
        refreshAllScreen();
      }
      else
      {
        v57 = 1;
        drawCarRightSide();
        refreshAllScreen();
      }
    }
LABEL_157:
    if ( userRacePosition_456B50 == 4 )
    {
      if ( !isMultiplayerGame && !v35 )
        noCollectPopup_42E6F0();
      userRacePosition_456B50 = 0;
    }
    memcpy((char *)screenBuffer + 61440, (char *)graphicsGeneral.menubg5Bpk + 61440, 0x29B80u);
    drawShopAnimationAndRightSide();
    drawTransparentBlock(0, 371, 639, 109);
    if ( isMultiplayerGame )
    {
      drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to enter chat mode", 233635);
      drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 233689);
    }
    drawBottomMenuText();
    drawBorder(426, 243, 108, 114);
    refreshAllScreen();
LABEL_165:
    dword_456B60 = 0;
LABEL_166:
    refreshAndCheckConnection_42A570();
    refreshAndCheckConnection_42A570();
    if ( framesToWaitAfterBuy_456B70 > 0 )
      --framesToWaitAfterBuy_456B70;
    switch ( menuOptionSelected_463DF0 )
    {
      case BUY_CAR:
        drawMenuAnimation(16, 141, carAnimCurrentFrame_45FBA0, getCarBpkById(actualCarSelected), (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
        drawKeyCursor(90256, (char *)screenBuffer + 90256, 0x60u, 64);
		carAnimCurrentFrame_45FBA0 = (carAnimCurrentFrame_45FBA0 + 1) % 64; 
        if ( framesToWaitAfterBuy_456B70 == 1 )
        {
          reloadCarAnimation2();
          refreshAllScreen();
        }
        break;
      case BUY_ENGINE:
        if ( drivers[driverId].engine < cars[drivers[ driverId].carType].engineUpgrades )
        {
          drawMenuAnimation(
            16,
            269,
            engineAnimCurrentFrame_462D80,
			  getEngineBpkById(drivers[driverId].engine),
            (int)((char *)&engineAnimFrameSize_445F68 + 4*24 * drivers[driverId].engine));
          drawKeyCursor(172176, (char *)screenBuffer + 172176, 0x60u, 64);
		  engineAnimCurrentFrame_462D80 = (engineAnimCurrentFrame_462D80 + 1) % 24; ///aqui va 24 p\F2prque son 24 frames
          
        }
        if ( framesToWaitAfterBuy_456B70 == 1 )
        {
          reloadEngineAnimation2();
          refreshAllScreen();
        }
        break;
		case BUY_TIRE:
        v40 = drivers[driverId].tire;
        if ( v40 < cars[drivers[driverId].carType].tireUpgrades )
        {
          drawMenuAnimation(120, 269, tireAnimCurrentFrame_45F034, 
			  getTireBpkById(drivers[driverId].tire) , (int)((char *)&tireAnimFrameSize_4460E8 + 4*12 * drivers[driverId].tire));
          drawKeyCursor(172280, (char *)screenBuffer + 172280, 0x60u, 64);
		  tireAnimCurrentFrame_45F034 = (tireAnimCurrentFrame_45F034 + 1) % 12; ///aqui va 23 p\F2prque son 23 frames
          
        }
        if ( framesToWaitAfterBuy_456B70 == 1 )
        {
          reloadTireAnimation2();
          refreshAllScreen();
        }
        break;
      case BUY_ARMOUR:
        if ( drivers[driverId].armour < cars[drivers[driverId].carType].armourUpgrades )
        {
          drawMenuAnimation(
            224,
            269,
            armourAnimCurrentFrame_461288,
			  getArmourBpkById(drivers[driverId].armour),
            (int)((char *)&armourAnimFrameSize_4461A8 + 4* 16 * drivers[driverId].armour));
          drawKeyCursor(172384, (char *)screenBuffer + 172384, 0x60u, 64);
          if ( armourAnimFrameDirection_45F034 )
          {
            --armourAnimCurrentFrame_461288;
            if ( armourAnimCurrentFrame_461288 < 1 )
              armourAnimFrameDirection_45F034 = 0;
          }
          else
          {
            ++armourAnimCurrentFrame_461288;
            if ( armourAnimCurrentFrame_461288 > 14 )
              armourAnimFrameDirection_45F034 = 1;
          }
        }
        if ( framesToWaitAfterBuy_456B70 == 1 )
        {
          reloadArmourAnimation2();
          refreshAllScreen();
        }
        break;
      case REPAIR:
        drawMenuAnimation(328, 269, repairAnimCurrentFrame_45EEAC, (int)repaaniBpk, (int)&repairAnimFrameSize_446308);
        drawKeyCursor(172488, (char *)screenBuffer + 172488, 0x60u, 64);
		repairAnimCurrentFrame_45EEAC = (repairAnimCurrentFrame_45EEAC + 1) % 23; ///aqui va 23 p\F2prque son 23 frames
        break;
      case CONTINUE:
        drawMenuAnimation(432, 269, continueAnimCurrentFrame_4611D0, (int)contaniBpk, (int)continueAnimFramesSize_4611D0);
        drawKeyCursor(172592, (char *)screenBuffer + 172592, 0x60u, 64);
		continueAnimCurrentFrame_4611D0 = (continueAnimCurrentFrame_4611D0 + 1)%2; ///aqui va 24 p\F2prque son 22 frames
        
        break;
      default:
        break;
    }
    v42 = eventDetected();
    if ( !v42 )
      goto LABEL_220;
    v43 = v65;
    v65 = v66;
    v44 = v67;
    v64 = v43;
    v45 = v68;
    v66 = v67;
    v67 = v68;
    v68 = v42;
    if ( isMultiplayerGame )
      goto LABEL_220;
    v46 = v65;
    if ( v65 != 32 || v44 != 19 || v45 != 30 || v42 != 17 )
    {
LABEL_203:
      if ( v64 != 32 || v46 != 19 )
      {
        if ( v46 != 32 || v66 != 19 || v67 != 24 || v42 != 25 )
          goto LABEL_220;
        v47 = &drivers[ driverId].points;
        v48 = drivers[ driverId].points - 10;
      }
      else
      {
        if ( v66 == 24 )
        {
          if ( v67 != 24 || v42 != 38 )
            goto LABEL_220;
          loadMenuSoundEffect(2u, 23, 0, 62720, dword_44518C - 28672);
          drivers[driverId].money = 500000;
LABEL_219:
          drawCarRightSide();
          refreshAllScreen();
          goto LABEL_220;
        }
        if ( v66 != 23 || v67 != 47 || v42 != 18 )
          goto LABEL_220;
        v47 = &drivers[ driverId].points;
        v48 = drivers[ driverId].points + 10;
      }
      *v47 = v48;
      //sub_423C90(0, 19);  //modiffica una variable de adversary pero no se que hace
     // recalcRank(20); //QUITADO porque solo hace multiplayer
      goto LABEL_219;
    }
    drivers[driverId].money += 1000;
    drawCarRightSide();
    refreshAllScreen();
    if ( !isMultiplayerGame )
    {
      v46 = 32;
      goto LABEL_203;
    }
LABEL_220:
    switch ( v42 )
    {
      //case KEY_F1:
        //-//if ( isMultiplayerGame )
        //  multiplayer_sub_42CCF0();
      //  break;
      case KEY_UP:
      case 0xC8:
        shopScreenMoveUp_421D90();
        break;
      case KEY_DOWN:
      case 0xD0:
        shopScreenMoveDown_421DF0();
        break;
      case KEY_LEFT:
      case 0xCB:
        shopScreenMoveLeft_421DF0();
        break;
      case KEY_RIGHT:
      case 0xCD:
        shopScreenMoveRight_42DAB0();
        break;
      case KEY_ENTER:
      case 0x9C:
        enterShop();
        break;
      case KEY_ESCAPE:
        v63 = -1;
        break;
      default:
        break;
    }
    if ( isDemo_456B10 )
      keysRead_45E0C0[KEY_F2] = 1;
    v49 = autoLoadSave();
    if ( v49 > 0 )
    {
      memcpy((char *)screenBuffer + 61440, (char *)graphicsGeneral.menubg5Bpk + 61440, 0x29B80u);
      drawShopAnimationAndRightSide();
      sub_4224E0();
      v50 = 32;
      v51 = (signed int)&unk_45FDC4;
      do
      {
        v52 = (convertColorToPaletteColor(*(_DWORD *)(v51 + 4), 6553600) + 0x8000) >> 16;
        v53 = (convertColorToPaletteColor(*(_DWORD *)v51, 6553600) + 0x8000) >> 16;
        v54 = convertColorToPaletteColor(*(_DWORD *)(v51 - 4), 6553600);
        setPaletteAndGetValue(v50, (v54 + 0x8000) >> 16, v53, v52);
        v51 += 12;
        ++v50;
      }
      while ( v51 < maxPaletteEntries );
      removeBorder(426, 243, 0x6Cu, 114);
      removeBorder(0, 115, 0x80u, 114);
      removeBorder(10, 243, 0x6Cu, 114);
      removeBorder(114, 243, 0x6Cu, 114);
      removeBorder(218, 243, 0x6Cu, 114);
      removeBorder(322, 243, 0x6Cu, 114);
      if ( !menuOptionSelected_463DF0 )
      {
        drawBorder(0, 115, 128, 114);
        reloadCarAnimation2();
      }
      if ( menuOptionSelected_463DF0 == 1 )
      {
        drawBorder(10, 243, 108, 114);
        reloadEngineAnimation2();
      }
      if ( menuOptionSelected_463DF0 == 2 )
      {
        drawBorder(114, 243, 108, 114);
        reloadTireAnimation2();
      }
      if ( menuOptionSelected_463DF0 == 3 )
      {
        drawBorder(218, 243, 108, 114);
        reloadArmourAnimation2();
      }
      if ( menuOptionSelected_463DF0 == 4 )
      {
        drawBorder(322, 243, 108, 114);
        reloadRepairAnimation();
      }
      if ( menuOptionSelected_463DF0 == 5 )
      {
        drawBorder(426, 243, 108, 114);
        reloadContinueAnimation();
      }
      drawTransparentBlock(0, 371, 639, 109);
      if ( isMultiplayerGame )
      {
        drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to enter chat mode", 233635);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 233689);
      }
      drawBottomMenuText();
      refreshAllScreen();
      memcpy(dword_461ED8, screenBuffer, 0x4B000u);
      switch ( v49 )
      {
        case 1:
          confirmationPopup("Game Saved.");
          break;
        case 2:
          confirmationPopup("Game Loaded.");
          break;
        case 3:
          confirmationPopup("Game not found.");
          break;
        default:
            break;
      }
      memcpy(screenBuffer, dword_461ED8, 0x4B000u);
      refreshAllScreen();
    }
    v11 = isMultiplayerGame;
  }
  while ( (!isMultiplayerGame || !dword_456B9C) && !v63 );
  if ( v57 == 1 )
    sub_4291D0();
  memcpy((void *)dword_45FC00, graphicsGeneral.menubg5Bpk, 0x4B000u);
  screenBuffer = (void *)dword_45FC00;
  drawTransparentBlock(0, 371, 639, 109);
  if ( isMultiplayerGame )
  {
    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to enter chat mode", 233635);
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 233689);
  }
  return drawBottomMenuText();
}

//----- (00421D90) --------------------------------------------------------
void shopScreenMoveUp_421D90()
{
  if ( menuOptionSelected_463DF0 == 1 )
  {
    loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
    menuOptionSelected_463DF0 = 0;
    reloadCarAnimation2();
    removeBorder(10, 243, 0x6Cu, 114);
    drawBorder(0, 115, 128, 114);
    refreshAllScreen();
  }
}

//----- (00421DF0) --------------------------------------------------------
void shopScreenMoveDown_421DF0()
{
  if ( !menuOptionSelected_463DF0 )
  {
    loadMenuSoundEffect(1u, 26, 0, configuration.effectsVolume, dword_445198);
    menuOptionSelected_463DF0 = 1;
    reloadEngineAnimation2();
    removeBorder(0, 115, 0x80u, 114);
    drawBorder(10, 243, 108, 114);
    refreshAllScreen();
  }
}

//----- (004210C0) --------------------------------------------------------
int showCarBought()
{
  unsigned int v0; // eax@1
//  void *v1; // edi@1
//  char v2; // cl@2
  //int v3; // eax@3
  char * v5; // [sp-1h] [bp-29h]@1
  __int16 v6; // [sp+0h] [bp-28h]@1
  char DstBuf[100] = ""; // [sp+14h] [bp-14h]@1

  drawImageWithPosition2((int)carbas2Bpk, 96, 96, (int)((char *)screenBuffer + 80016));
  drawImageWithPosition2((int)((char *)carnameBpk + 1536 * actualCarSelected), 96, 16, (int)((char *)screenBuffer + 80016));
  drawMenuAnimation(16, 141, carAnimCurrentFrame_45FBA0, getCarBpkById(actualCarSelected), (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
  _itoa(cars[actualCarSelected].cost, &DstBuf, 10);
  /*v6 = 36;
  v0 = strlen(&DstBuf) + 1;
  v1 = &v5;
  do
  {
    v2 = *((BYTE *)v1 + 1);
    v1 = (char *)v1 + 1;
  }
  while ( v2 );
  memcpy(v1, &DstBuf, v0);*/

   
  v0 = strlen(DstBuf) + 1;

  v5 = malloc(v0); //coste + el $
strcpy(v5,"$"); /* copy name into the new var */
	strcat(v5, DstBuf);
	v6 = getBoxTextOffset(v5);//get small text size

  drawInGamePrices(v5, v6 + 132496);
  free(v5);
  createPopup(144, 114, 384, 119, 1);
  writeTextInScreen(&aVagabondBought[1760 * drivers[driverId].carType], 79530);
  writeTextInScreen((const char *)&unk_44E168 + 1760 * drivers[driverId].carType, 89770);
  writeTextInScreen(&aFaceItNotTheHo[1760 * drivers[driverId].carType], 100010);
  writeTextInScreen(&aAroundButSheLl[1760 * drivers[driverId].carType], 110250);
  writeTextInScreen(&aOnHerOwnSweetT[1760 * drivers[driverId].carType], 120490);
  writeTextInScreen((const char *)&unk_44E208 + 1760 * drivers[driverId].carType, 130730);
  drawImageWithPosition((int)arrows1dBpk, 16, 64, (int)((char *)screenBuffer + 90240));
  return drawImageWithPosition((int)((char *)arrows1dBpk + 1024), 16, 64, (int)((char *)screenBuffer + 90352));
}
// 445968: using guessed type int carAnimFrameSize_45FBA0[];
// 45FBA0: using guessed type int carAnimCurrentFrame_45FBA0;
// 45FC30: using guessed type int actualCarSelected;
// 46085C: using guessed type int dword_46085C[];
// 463CE8: using guessed type int driverId;

//----- (00429100) --------------------------------------------------------
int drawShopAnimationAndRightSide()
{
  void *v1; // [sp-10h] [bp-10h]@2
  int v2; // [sp-4h] [bp-4h]@2

  if ( isMultiplayerGame )
  {
    v2 = (int)((char *)screenBuffer + 58880);
    v1 = graphics2.shoptxt2Bpk;
  }
  else
  {
    v2 = (int)((char *)screenBuffer + 58880);
    v1 = graphics2.shoptxt1Bpk;
  }
  drawImageWithPosition((int)v1, 640, 16, v2);
  drawCarRightSide();
  if ( !showWelcomePopup_456B74
    && consecutiveWins_456BA8 != 3
    && noPaintJob_456BAC != 1
    && allCarsCrash_456BB0 != 1
    && !drugQuest_456BB4
    && !killOneQuest_456BB8
    && drivers[driverId].loanRaces != 4 )
    drawBorder(426, 243, 108, 114);
  reloadCarAnimation2();
  reloadEngineAnimation2();
  reloadTireAnimation2();
  reloadArmourAnimation2();
  reloadRepairAnimation();
  return reloadContinueAnimation();
}

//----- (004227C0) --------------------------------------------------------
int getReapirCostByCarType()
{
  __int64 v0; // rax@2
  int result; // eax@2

  if ( useWeapons )
  {
    v0 = cars[drivers[ driverId].carType].repairCost;
    result = ((signed int)v0 - HIDWORD(v0)) >> 1;
  }
  else
  {
    result = cars[drivers[driverId].carType].repairCost;
  }
  return result;
}

//----- (004291D0) --------------------------------------------------------
int sub_4291D0()
{
  int result; // eax@1

  *(_DWORD *)shopScreenaStartANewGam_0 = *(_DWORD *)"Start A New Game";
  *(_DWORD *)&shopScreenaStartANewGam_0[4] = *(_DWORD *)"t A New Game";
  *(_DWORD *)&shopScreenaStartANewGam_0[8] = *(_DWORD *)"New Game";
  *(_DWORD *)&shopScreenaStartANewGam_0[12] = *(_DWORD *)"Game";
  shopScreenaStartANewGam_0[16] = shopScreenaStartANewGame[16];
  *(_DWORD *)shopScreenaStartRacing = 1918989395;
  *(_DWORD *)&shopScreenaStartRacing[4] = 1632772212;
  *(_DWORD *)&shopScreenaStartRacing[8] = 1735289187;
  shopScreenaStartRacing[12] = 0;
  menuActive_4457F0[10] = 0;
  menuActive_4457F0[11] = 0;
  menuActive_4457F0[13] = 0;
  showHardWarningRace = 0;
  showMediumWarningRace = 0;
  showUndergroundPopup_456B78 = 0;
  showWelcomePopup_456B74 = 0;
  result = initDrivers();
  dword_445724 = 0;
  firstRacePlayed_464F44 = 1;
  return result;
}
