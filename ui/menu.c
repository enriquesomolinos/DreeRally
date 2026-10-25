#include <SDL_keysym.h>
#include "util/bottomText.h"
#include "menu.h"

#include "util/menus.h"
#include <SDL_stdinc.h>
#include "util/anim.h"
#include "../imageUtil.h"
#include "../config.h"
#include "../defs.h"
#include "../drivers.h"
#include "../dr.h"
#include "../graphics.h"
#include "../circuit.h"
#include "../variables.h"
#include "../i18n/i18n.h"
#include "util/popup.h"
#include "../sfx/sound.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/keyNames.h"
#include "util/menuTexts.h"

_WORD word_4429FC[14] = //Ma..
{
  24909,  26723,  28265,  8293,  30023,  8302,  64032,  64250,  64250,  64250,  64250,  64250,  250,  0
}; // idb
_WORD word_442A18[14] =
{
  30036,  25202,  8303,  28482,  29551,  8308,  64032,  64250,  64250,  64250,  64250,  64250,  250,  0
}; // idb

//Nombres de las teclas para los menus de teclado y joystick, 15 bytes por codigo. Eran un solo
//byte: se escribian y leian como (char *)&unk_462DA0 + 15 * tecla sobre otras globales.
char unk_462DA0[KEY_NAMES * KEY_NAME_SIZE];
//Botones del joystick (codigos 0 a 8); el original reserva 0x90 bytes.
char unk_45EAC0[0x90];
//Plantilla de "Horn" (.rdata del original): era un byte y el memcpy de 32 copiaba basura.
char unk_4429C0[32] = "Horn        \372\372\372\372\372\372\372\372\372\372\372\372\372\372\372\372\372\372\372";















int dword_445798 = 9; // weak
int dword_4457B0 = 0; // weak



int dword_4457D0 = 8; // weak
int dword_4457E8 = 0; // weak
int dword_44575C = 0; // weak
int dword_445744 = 6; // weak


BYTE byte_4429E0[28] = //drop mines
{
  68,  114,  111,  112,  32,  77,  105,  110,  101,  32,  32,  32,  32,  250,  250,  250,
  250,  250,  250,  250,  250,  250,  250,  250,  0,  0,  0,  0
}; // idb
int gameStarted_456B5C = 0; // weak

int dword_45E1C0; // weak
int dword_456BC8 = 0; // idb
int dword_456A1C = 1; // weak

/*menus sizes*///la entrada 9 es para el menu de continuar
int dword_4456F0[] = { 6,6,8,6,5,8,9,8,8   }; // weak  //entradas del menu
#define dword_44570C (dword_4456F0[1]) // 0x44570C: cantidad de opciones del menu 1
/*menus sizes*///la entrada 9 es para el menu de continuar
int dword_4456F4[] = { 145,0x6d,0x67,0x5f,0xa8,0xe7,0x32,0xd3,0x32   }; // weak
int dword_4456F8[] = { 124,0xab,0x76,0x92,0xc8,0x72,0x5d,0x74,0x71  }; // weak
int dword_4456FC[] = { 28,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c   }; // weak
int dword_445700[] = { 349,0x1a5,0x1af,0x1e5,0x12f,0x17f,0x214,0x14f ,0x214  }; // weak
//Alto del recuadro de cada menu, verificado contra dr.exe (0x4456F4, 7 enteros por menu): los
//indices 2, 4 y 6 eran 175, 2576 y 352 en lugar de 250, 161 y 278.
int dword_445704[] = { 192,192,250,192,161,250,278,250,250 }; // weak
int dword_445708[] = { 0,0,2,0,0,0,0,0,0 }; // weak


int dword_445188 = 163840; // weak
char byte_45FC10[256]; // weak
char menuaStartANewGame[17] = "Start A New Game"; // weak
//----- (0042E0B0) --------------------------------------------------------
signed int   readEventInMenu(int menuType)
{
  int v1; // edi@6
  signed int result; // eax@14
  int key;
  while ( 2 )
  {
    if ( dword_456B9C )
      goto LABEL_14;

	refreshAndCheckConnection_42A570();
    refreshAndCheckConnection_42A570();
    updateCursor(menuType);
	//Sin signo como en el original (movzx en 0x42E0E5): el joystick devuelve 0xC8/0xD0.
	key = (unsigned __int8)eventDetected();
    switch (key)
    {
      default:
        if(key != 0){
          key =1;
        }
        continue; 
      case KEY_ESCAPE :
        if ( !menuType)
        {
          if ( dword_445708[0] != dword_4456F0[0] - 1 )
          {
            sub_41ACF0(0);
            loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
          }
          continue;
        }
        v1 = -1;
        loadMenuSoundEffect(1u, 22, 0, configuration.effectsVolume, dword_445188);
LABEL_13:
        if ( dword_456B9C )
LABEL_14:
          result = -1;
        else
          result = v1;
        return result;
      case KEY_ENTER:
      case KEY_ESPACE:
      case 0x41:
      case SDLK_KP_ENTER:
      case 0x9C:


		  v1 = dword_445708[menuType];
		///v1 = dword_445708[7 * a1];
        loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
        if ( v1 != -2 )
          goto LABEL_13;
        continue;
      case KEY_F1:
      
        //if ( isMultiplayerGame )
         // multiplayer_sub_42CCF0();
        continue;
      case KEY_UP:
      case 0xC8:

		  refreshMenuUp(menuType);
        loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
        continue;
      case KEY_DOWN:
      case SDLK_DOWN:
      case 0xD0:
        refreshMenuDown(menuType);
	    loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);

        continue;
     
    }
  }
}

//----- (0042E310) --------------------------------------------------------
bool   drawYesNoMenu(int a1, int a2, int a3, signed int *a4)
{
  signed int v4; // ebx@1
  int v5; // esi@1
  int v6; // eax@5
  signed int v7; // edx@5
  char *v8; // ebp@6
  bool v9; // zf@7
  bool v10; // sf@7
  unsigned __int8 v11; // of@7
  char v12; // al@9
  signed int v13; // edx@18
  char *v14; // edi@19
  signed int v15; // edx@23
  char *v16; // edi@24
  signed int v17; // esi@27
  int v19; // [sp-4h] [bp-14h]@1

  v4 = *a4;
  v5 = 640 * a2 + a1 + 7;
  v19 = 640 * a2 + a1 - 4450;
  if ( *a4 == 1 )
  {
    drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("yes"), v19);
    drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("no"), 640 * a2 + a1 - 4280);
  }
  else
  {
    drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("yes"), v19);
    drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("no"), 640 * a2 + a1 - 4280);
  }
  refreshAllScreen();
  while ( 2 )
  {
    refreshAndCheckConnection_42A570();
    refreshAndCheckConnection_42A570();
    v6 = -170 * v4;
    v7 = 20;
    do
    {
      v8 = (char *)screenBuffer + v6 + v5 + 170;
      *(_DWORD *)v8 = -993737532;
      *((_DWORD *)v8 + 1) = -993737532;
      *((_DWORD *)v8 + 2) = -993737532;
      *((_DWORD *)v8 + 3) = -993737532;
      v6 += 640;
      --v7;
      *((_DWORD *)v8 + 4) = -993737532;
    }
    while ( v7 );
    drawImageWithPosition(
      (int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame),
      20,
      20,
      (int)((char *)screenBuffer + v5 + -170 * v4 + 170));
    drawKeyCursor(640 * a2 + a1 + 2, (char *)screenBuffer + 640 * a2 + a1 + 2, 0xF0u, 28);
    v11 = __OFSUB__(cursorBpkFrame + 1, 49);
    v9 = cursorBpkFrame == 48;
    v10 = cursorBpkFrame++ - 48 < 0;
    if ( !((unsigned __int8)(v10 ^ v11) | v9) )
      cursorBpkFrame = 0;
    v12 = eventDetected();
    if ( v12 == 21 )
    {
      v12 = -53;
    }
    else if ( v12 == 49 )
    {
      v12 = -51;
    }
    switch ( (unsigned __int8)v12 )
    {
      default:
        continue;
      case KEY_F1:
        //if ( isMultiplayerGame )
        //  multiplayer_sub_42CCF0();
        continue;
      case KEY_LEFT:
      case 0xCB:
        if ( !v4 )
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
        v4 = 1;
        v13 = 0;
        do
        {
          v14 = (char *)screenBuffer + v13;
          v13 += 640;
          memset(&v14[v5 - 5], 0xC4u, 0xF0u);
        }
        while ( v13 < 16000 );
        drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("yes"), 640 * a2 + a1 - 4450);
        drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("no"), 640 * a2 + a1 - 4280);
        continue;
      case KEY_RIGHT:
      case 0xCD:
        if ( v4 == 1 )
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
        v4 = 0;
        v15 = 0;
        do
        {
          v16 = (char *)screenBuffer + v15;
          v15 += 640;
          memset(&v16[v5 - 5], 0xC4u, 0xF0u);
        }
        while ( v15 < 16000 );
        drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("yes"), 640 * a2 + a1 - 4450);
        drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("no"), 640 * a2 + a1 - 4280);
        continue;
      case 1:
        if ( !a3 )
          continue;
        v4 = 0;
        v17 = -2;
        break;
      case KEY_ENTER:
      case 0x9C:
        v17 = -1;
        break;
    }
    break;
  }
  loadMenuSoundEffect(1u, 28, 0, configuration.effectsVolume, dword_4451A0);
  *a4 = v4;
  return v17 != -2;
}

//----- (00439CD0) --------------------------------------------------------
void startRacingMenu()
{
  signed int v0; // eax@6
  int v1; // esi@9
  int v2; // eax@11
  int v3; // eax@20
  int v4; // [sp+10h] [bp-4h]@11

  gameStarted_456B5C = 0;
LABEL_2:
  while ( !dword_456B64 )
  {
    memcpy((char *)screenBuffer + 58880, (char *)graphicsGeneral.menubg5Bpk + 58880, 0x2AF80u);
    drawMenu(INITIAL_MENU, 0);
	
	drawMenu(START_NEW_GAME_MENU, 1);
	if ( gameStarted_456B5C )
    {
      screenBuffer = (void *)dword_461250;
      sub_42C4A0();
      refreshAllScreen();
      gameStarted_456B5C = 0;
    }
    else
    {
      refreshAllScreen();
    }
	v0 = readEventInMenu(START_NEW_GAME_MENU);
	
    switch ( v0 )
    {
      case START_CONTINUE_GAME:
        if ( memcmp(menuaStartANewGam_0, "Start A New Game", 0x11u) )
          goto LABEL_10;
        drawMenu(START_NEW_GAME_MENU, 0);
        if ( licenseScreen(1) )
        {
          v1 = drivers[driverId].colour;
		  menuActive_4457F0[1] = 0;
		  menuActive_4457F0[10] = 1;
		  menuActive_4457F0[11] = 1;
		  menuActive_4457F0[13] = 1;
          showHardWarningRace = 1;
          showMediumWarningRace = 1;
          showUndergroundPopup_456B78 = 1;
          showWelcomePopup_456B74 = 1;
		  
		  isMultiplayerGame = 0; ///puesto por mi!
		  //0x439DD1: con la cara ya elegida, los rivales se reparten las otras 19 (antes uno repetia
		  //la del jugador y faltaba SAM SPEED). Estaba quitada porque initDrivers pisaba al jugador.
		  initDrivers();
          drivers[driverId].colour = v1;
          copyPalette1toPalette();
          *(_DWORD *)menuaStartANewGam_0 = 1702129221;
          *(_DWORD *)&menuaStartANewGam_0[4] = 1750343794;
          *(_DWORD *)&menuaStartANewGam_0[8] = 1750278245;
          *(_WORD *)&menuaStartANewGam_0[12] = 28783;
          menuaStartANewGam_0[14] = 0;
          *(_DWORD *)menuaStartRacing = 1953394499;
          firstRacePlayed_464F44 = 1;
		  menuActive_4457F0[10] = 1;
          *(_DWORD *)&menuaStartRacing[4] = 1702194793;
          *(_DWORD *)&menuaStartRacing[8] = 1667322400;
          *(_DWORD *)&menuaStartRacing[12] = 6778473;
LABEL_10:
          postLoadedOrLicense();
          gameStarted_456B5C = 1;
        }
        goto LABEL_2;
      case END_CURRENT_GAME:
        drawMenu(START_NEW_GAME_MENU, 0);
        createPopup(170, 220, 300, 80, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "End current game?", 146152);
        v4 = 1;
        v2 = drawYesNoMenu(180, 258, 1, &v4);
        if ( v4 )
        {
          if ( v2 )
          {
            *(_DWORD *)menuaStartANewGam_0 = *(_DWORD *)"Start A New Game";
            *(_DWORD *)&menuaStartANewGam_0[4] = *(_DWORD *)"t A New Game";
            *(_DWORD *)&menuaStartANewGam_0[8] = *(_DWORD *)"New Game";
            *(_DWORD *)&menuaStartANewGam_0[12] = *(_DWORD *)"Game";
            menuaStartANewGam_0[16] = menuaStartANewGame[16];
            *(_DWORD *)menuaStartRacing = 1918989395;
            *(_DWORD *)&menuaStartRacing[4] = 1632772212;
            *(_DWORD *)&menuaStartRacing[8] = 1735289187;
            menuaStartRacing[12] = 0;
			menuActive_4457F0[10] = 0;
			menuActive_4457F0[11] = 0;
			menuActive_4457F0[13] = 0;
            showHardWarningRace = 0;
            showMediumWarningRace = 0;
            showUndergroundPopup_456B78 = 0;
            showWelcomePopup_456B74 = 0;
            initDrivers();
            copyPalette1toPalette();
            firstRacePlayed_464F44 = 1;
            dword_445724 = 0;
          }
        }
        goto LABEL_2;
      case SEE_STADISTICS:
        seeStadistics_42C940();
        goto LABEL_2;
      case LOAD_GAME:
        if ( loadGame() )
        {
          postLoadedOrLicense();
          gameStarted_456B5C = 1;
        }
        goto LABEL_2;
      case SAVE_GAME:
        savegameWithName();
        goto LABEL_2;
      case PREVIOUS_MENU: //previous menu
        v3 = 0;
        dword_445724 = 0;
        if ( !menuActive_4457F0[9] )
        {
          do
          {
            if ( v3 >= dword_44570C - 1 )
              v3 = 0;
            else
              ++v3;
          }
          while ( !menuActive_4457F0[9+v3] );
          dword_445724 = v3;
        }
        return;
      default:
        if ( v0 == -1 )
          return;
        break;
    }
  }
}

//----- (0043A020) --------------------------------------------------------
int mainMenu()
{
  unsigned int v0; // eax@7
  void *v1 =malloc(0x4B000u); // eax@10
  int v2; // eax@10
  char *v3; // edx@10
  signed int v4; // ecx@10
  int v5; // eax@10
  float v6; // ST38_4@10
  float v7; // ST34_4@10
  float v8; // ST30_4@10
//  int v9; // eax@10
//  signed int v10; // eax@10
//  char v11; // bl@12
//  char v12; // dl@12
//  char v13; // cl@12
//  char v14; // dl@12
//  signed int v15; // esi@12
//  signed int v16; // eax@13
//  char v17; // cl@14
//  char v18; // dl@16
//  char v19; // bl@16
//  char v20; // cl@16
//  signed int v21; // esi@16
//  char v22; // cl@18
//  char v23; // dl@20
///  signed int v24; // esi@20
//  signed int v25; // edx@21
//  char v26; // cl@22
//  char v27; // dl@24
//  signed int v28; // esi@24
//  signed int v29; // eax@25
//  char v30; // cl@26
  signed int v31; // ebx@32
  unsigned __int8 v32; // bp@35
  signed int v33; // esi@35
  int v34; // ST38_4@36
  int v35; // ST34_4@36
  int v36; // eax@36
//  char *v37; // eax@54
//  char v38; // dl@55
//  unsigned int v39; // eax@56
//  char *v40; // edi@56
//  char v41; // cl@57
//  char *v42; // edi@58
//  char v43; // al@59
//  char *v44; // eax@60
//  char v45; // dl@61
//  unsigned int v46; // eax@62
//  char *v47; // edi@62
//  char v48; // cl@63
//  char *v49; // edi@64
//  char v50; // al@65
//  bool v51; // zf@66
//  char *v52; // eax@68
//  char *v53; // edx@68
//  char v54; // cl@69
//  unsigned int v55; // eax@70
//  char *v56; // edi@70
//  char v57; // cl@71
//  char *v58; // edi@72
//  char v59; // al@73
//  signed int v61; // [sp+1Ch] [bp-Ch]@17
  signed int v62; // [sp+20h] [bp-8h]@1
  int v63; // [sp+24h] [bp-4h]@1

  v62 = 0;
  v63 = 0;
  //checkIntro(); //esto solo chequea intro
  dword_45F000 = 0;
  dword_45F004 = 0;
  dword_45F008 = 0;
  dword_45F00C = 0;
  word_45F010 = 0;
  dword_45E1C0 = 0;
  byte_45F012 = 0;
  byte_45FB84 = 0;
  initCars();
  initDrivers();
  initShopMessages();
  loadConfig();
  //TODO review because is not necesary
	//dword_4A9140 = (int)exitGame;
  ++configuration.timesPlayed;
  saveConfiguration();
  printf("\nLoading music & effects, please wait..\n");
  
  
  checkAndOpenAnimation();
  
  loadMusic(1, "MEN-MUS.CMF", 2,"MEN-SAM.CMF");
  //es men-sam pero carga mal! loadMusic(1, "MEN-MUS.CMF", 2,"GEN-EFE.CMF");
  musicSetmusicVolume(configuration.musicVolume);
  musicSetVolume(configuration.effectsVolume);
  musicSetOrder(11520);
  nullsub_1();
  musicPlayMusic();
  nullsub_1();
  //estos arrays setean los circuitos iniciales de la partida
  byte_45FC10[0] = circuitOrder_45673C[0];
  byte_45FC10[3] = circuitOrder_45673C[3];
  //byte_45FC13 = byte_45673F;
  dword_456BC8 = 4;
  //byte_45FC11 = byte_45673D;
  byte_45FC10[1] = circuitOrder_45673C[1];
  byte_45FC10[2] = circuitOrder_45673C[2];
  //byte_45FC12 = byte_45673E[0];
  if ( configuration.useJoystick == 1 || configuration.useJoystick == 2 )
  {
    configJoystick();
    memcpy(aGamepadDisable, "Gamepad/Joystick Enabled", 0x19u);
  }
  else
  {
    memcpy(aGamepadDisable, "Gamepad/Joystick Disabled", 0x1Au);
  }
  if ( !configuration.dword_456734 )
  {
    dword_4470E2 = 1936487760; //Puls
    dword_4470E6 = 1766072421; //e Di
    dword_4470EA = 1852402785;//alin
    word_4470EE = 103;//g
  }
  v0 = SDL_GetTicks();
  srand(v0);
  nullsub_1();
  setWindowCaption2();
  if ( isVesaCompatible() )
  {
    setWindowCaption();
    printf("DEATH RALLY Error: Your VGA-adapter is not fully VESA (VBE 1.0) compliant.\n                   Use UNIVBE or similar emulator to fix the problem.\n");
    printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
    stopAndOpenMusic();
    freeMusic();
    nullsub_1();
    exit(112);
  }
  recalculateSDLTicks_43C740();
 // allocateMemoryPtr((void *)&v1,0x4B000u); //tama\F1o pantalla
  //puesto por mi
  screenBuffer = v1;
  dword_461250 = v1;  
  //apogeeScreen();  
  showStartScreen();
 
  inicializeGraphicVars();
  loadGraphics1();
  loadGraphics2();
  loadGraphics3();
  loadGraphics4();
  //SDL_Delay(2000);
  transitionToBlack();
  loadPaletteMenu();
  
 
  
  v2 = drivers[driverId].colour;
  v3 = (char *)graphicsGeneral.copperPal + 2 * v2;
  //allocateMemoryPtr(v3, 0x2u);
  v4 = (unsigned __int8)v3[v2 + 2];
  v5 = (int)&v3[v2];
  v6 = (double)v4;
  v7 = (double)*(BYTE *)(v5 + 1);
  v8 = (double)*(BYTE *)v5;
  sub_418B00(v8, v7, v6);
  
  memcpy(screenBuffer, graphicsGeneral.menubg5Bpk, 0x4B000u); //tama\F1o pantalla

  

  /*v9 = 27 * driverId;
  *(_DWORD *)unk_461EC0 = 0;
  *(_DWORD *)&word_461EC4 = 0;
  *(_DWORD *)&word_461EC8 = 0;
  *(_DWORD *)&word_461ECC = 0;
  byte_460840[v9 * 4] = 0;
  *(_DWORD *)&word_461ED0 = 0;
  dword_460880[v9] = 0;
  v10 = (signed int)&unk_462000;
  word_461ED4 = 0;
  do
  {
    *(BYTE *)v10 = 0;
    v10 += 150;
  }
  while ( v10 < (signed int)&blacktx1Bpk );
  v11 = unk_461EC3;
  memcpy(&dword_462C4E, "     Welcome to Death Rally(tm) - Windows Version 1.0", 0x34u);
  unk_461EC3 = word_461EC4;
  HIBYTE(word_461EC4) = *(_DWORD *)&word_461EC4 >> 16;
  unk_461EC6 = unk_461EC7;
  unk_461EC7 = word_461EC8;
  HIBYTE(word_461EC8) = unk_461ECA;
  v12 = unk_461EC1;
  unk_461ECA = unk_461ECB;
  unk_461ECB = word_461ECC;
  HIBYTE(word_461ECC) = unk_461ECE;
  unk_461ECE = unk_461ECF;
  unk_461ECF = word_461ED0;
  HIBYTE(word_461ED0) = unk_461ED2;
  unk_461ED2 = unk_461ED3;
  v13 = word_461ED4;
  *((_WORD *)&dword_462C4E + 26) = *(_WORD *)"0";
  unk_461EC0[0] = v12;
  v14 = unk_461EC2;
  v15 = (signed int)&unk_462096;
  unk_461ED3 = v13;
  LOBYTE(word_461ED4) = 1;
  do
  {
    v16 = v15;
    do
    {
      v17 = *(BYTE *)v16;
      *(BYTE *)(v16 - 150) = *(BYTE *)v16;
      ++v16;
    }
    while ( v17 );
    v15 += 150;
  }
  while ( v15 < (signed int)&blacktx1Bpk );
  memcpy(&dword_462C4E, "         Port by Jari Komppa - http://iki.fi/sol/", 0x30u);
  unk_461EC0[0] = v14;
  v18 = v11;
  v19 = unk_461EC3;
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
  v20 = word_461ED4;
  *((_WORD *)&dword_462C4E + 24) = *(_WORD *)"/";
  v21 = (signed int)&unk_462096;
  unk_461ED3 = v20;
  do
  {
    v61 = v21;
    do
    {
      v22 = *(BYTE *)v61;
      *(BYTE *)(v61 - 150) = *(BYTE *)v61;
      ++v61;
    }
    while ( v22 );
    v21 += 150;
  }
  while ( v21 < (signed int)&blacktx1Bpk );
  unk_461EC0[0] = v18;
  unk_461EC2 = unk_461EC3;
  unk_461EC3 = word_461EC4;
  HIBYTE(word_461EC4) = unk_461EC6;
  unk_461EC6 = unk_461EC7;
  unk_461EC7 = word_461EC8;
  HIBYTE(word_461EC8) = unk_461ECA;
  unk_461ECA = unk_461ECB;
  unk_461ECB = word_461ECC;
  HIBYTE(word_461ECC) = unk_461ECE;
  memcpy(&dword_462C4E, "    (c)Remedy Entertainment - http://www.remedygames.com", 0x38u);
   unk_461ECE = unk_461ECF;
  unk_461ECF = word_461ED0;
  HIBYTE(word_461ED0) = unk_461ED2;
  v23 = unk_461ED3;
  *((BYTE *)&dword_462C4E + 56) = aCRemedyEnterta[56];
  v24 = (signed int)&unk_462096;
  unk_461ED2 = v23;
  LOBYTE(word_461ED4) = 1;
  do
  {
    v25 = v24;
    do
    {
      v26 = *(BYTE *)v25;
      *(BYTE *)(v25 - 150) = *(BYTE *)v25;
      ++v25;
    }
    while ( v26 );
    v24 += 150;
  }
  while ( v24 < (signed int)&blacktx1Bpk );
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
  v27 = unk_461ED2;
  LOBYTE(dword_462C4E) = 0;
  unk_461ED2 = 1;
  v28 = (signed int)&unk_462096;
  unk_461EC0[0] = v19;
  HIBYTE(word_461ED0) = v27;
  unk_461ED3 = word_461ED4;
  LOBYTE(word_461ED4) = 1;
  do
  {
    v29 = v28;
    do
    {
      v30 = *(BYTE *)v29;
      *(BYTE *)(v29 - 150) = *(BYTE *)v29;
      ++v29;
    }
    while ( v30 );
    v28 += 150;
  }
  while ( v28 < (signed int)&blacktx1Bpk );
  memcpy(&dword_462C4E, "Use arrow keys to change selection and press enter to confirm.", 0x3Fu);
  HIBYTE(word_461ED4) = 1;*/
  initMenuNews();
  drawTransparentBlock(0, 371, 639, 109);
  
  drawBottomMenuText();
  
  
  
  do
  {
	  menuActive_4457F0[1] = 0;
	  memcpy((char *)screenBuffer + 53760, (char *)graphicsGeneral.menubg5Bpk + 53760, 0x2C380u);
	  drawMenu(INITIAL_MENU, 1);
	  
	  if ((dword_456A1C || dword_456B64) && !dword_456B9C)
	  {
		  refreshAllScreen();
		  sub_4224E0();
		  v31 = 0;
		  do
		  {
			  waitWithRefresh();
			  if (v31 % 2)
				  updateCursor(0);
			  v32 = 0;
			  v33 = 0;
			  //FIXED
			  //v33 = (signed int)dword_45FC44;
			  do
			  {
				  v34 = (convertColorToPaletteColor((palette1[v33+2]), v31 << 17) + 0x8000) >> 16;
				  v35 = (convertColorToPaletteColor(palette1[v33 +1], v31 << 17) + 0x8000) >> 16;
				  v36 = convertColorToPaletteColor((palette1[v33 ]), v31 << 17);
				  setPaletteAndGetValue(v32, (v36 + 0x8000) >> 16, v35, v34);
				  v33 += 3;
				  ++v32;
			  } while (v33 < maxPaletteEntries);
			  ++v31;
		  } while (v31 < 50);
		  dword_456A1C = 0;
		  if (dword_456B64)
		  {
			  dword_456B64 = 0;
			  memcpy((void *)dword_461250, dword_461ED8, 0x4B000u);
			  screenBuffer = (void *)dword_461250;
			  dword_461ED8 = (void *)dword_45FC00;
		  }
	  }
	  
	   if (v62)
	  {
		  if (dword_456B9C)
			  goto LABEL_45;
		  screenBuffer = (void *)dword_461250;
		  sub_42C560(-1);
		  stopSong();
		  musicPlayMusic();
		  musicSetOrder(dword_462D7C);
		  setMusicVolume(0x10000);
		  v62 = 0;
	  }
	  if (!dword_456B9C)
		  refreshAllScreen();
  LABEL_45:
	  switch ( readEventInMenu(INITIAL_MENU) )
	  {
		case 0:
		  startRacingMenu();
		  break;
		case 2:
		  showAdjustOptions();
		  break;
		case 3:
		  seeHallOfFame();
		  v62 = 1;
		  break;
		case 4:
		  showCredits();
		  break;
		case 5:
			//exit to os
		  drawMenu(INITIAL_MENU, 0);
		  createPopup(170, 200, 300, 80, 1);
		  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, getLanguageEntry("Are you sure?"), 133373);
		  drawYesNoMenu(180, 238, 1, &v63);
		  break;
		default:

		  break;
	  }
	  if (!dword_456B9C) {
		  v62 = 0;
	  }
  

  }
  while ( !v63 );
  /*if ( isMultiplayerGame )
  {
    if ( !memcmp(&dword_44671E, "Abort Current Game", 0x13u) )
    {
      v37 = &byte_460840[108 * driverId];
      dword_462C4E = 2108717;
      do
        v38 = *v37++;
      while ( v38 );
      v39 = v37 - &byte_460840[108 * driverId];
      v40 = (char *)&dword_462C4E - 1;
      do
        v41 = (v40++)[1];
      while ( v41 );
      memcpy(v40, &byte_460840[108 * driverId], v39);
      v42 = (char *)&dword_462C4E - 1;
      do
        v43 = (v42++)[1];
      while ( v43 );
      memcpy(v42, " has left from Death Rally.", 0x1Cu);
      HIBYTE(word_461ED4) = 0;
      multiplayer_41EA70((int)&dword_462C4E, 100, 20);
      v44 = &byte_460840[108 * driverId];
      dword_462C4E = 2108717;
      do
        v45 = *v44++;
      while ( v45 );
      v46 = v44 - &byte_460840[108 * driverId];
      v47 = (char *)&dword_462C4E - 1;
      do
        v48 = (v47++)[1];
      while ( v48 );
      memcpy(v47, &byte_460840[108 * driverId], v46);
      v49 = (char *)&dword_462C4E - 1;
      do
        v50 = (v49++)[1];
      while ( v50 );
      memcpy(v49, " aborted current netgame.", 0x18u);
      HIBYTE(word_461ED4) = 0;
      v51 = dword_45E0A8 == 2;
      *((_WORD *)v49 + 12) = *(_WORD *)".";
      if ( !v51 )
      {
        multiplayer_41EA70((int)&dword_462C4E, 100, 9);
        goto LABEL_76;
      }
    }
    else
    {
      v52 = &byte_460840[108 * driverId];
      dword_462C4E = 2108717;
      v53 = &byte_460840[108 * driverId];
      do
        v54 = *v52++;
      while ( v54 );
      v55 = v52 - v53;
      v56 = (char *)&dword_462C4E - 1;
      do
        v57 = (v56++)[1];
      while ( v57 );
      memcpy(v56, v53, v55);
      v58 = (char *)&dword_462C4E - 1;
      do
        v59 = (v58++)[1];
      while ( v59 );
      memcpy(v58, " has left from Death Rally.", 0x1Cu);
      HIBYTE(word_461ED4) = 0;
    }
    multiplayer_41EA70((int)&dword_462C4E, 100, 6);
LABEL_76:
    nullsub_1();
    nullsub_1();
    isMultiplayerGame = 0;
    dword_45E0A8 = 0;
  }*/
  showEndScreen();
  saveConfiguration();
  freeMemoryGraphics();
  freeMemoryGraphics1();
  freeMemoryGraphics2();
  freeMemoryGraphics3();
  freeMemoryGraphics4();
  stopSong();
  return stopAndOpenMusic();
}

//----- (0041A880) --------------------------------------------------------

//pinta el menu
//menu type
// 0 es el menu principal
// 1 es comenzar racing
int   drawMenu(int menuType, int top)
{
  int v2; // edi@1
  int v3; // esi@1
  int result; // eax@1
  int v5; // ebx@1
  signed int v6; // ebp@1
  int v7; // eax@2
  const char *v8; // edi@2
  int v9; // eax@5
  int v10; // eax@14
  int v11; // ecx@14
  int v12; // [sp+10h] [bp-4h]@2
  signed int v13; // [sp+18h] [bp+4h]@1
  int menuEntryIndex = 0;
  v2 = menuType;
  //v3 = 7 * a1;
  v3 = menuType;
  //createPopup(dword_4456F4[7 * a1], dword_4456F8[7 * a1], dword_445700[7 * a1], dword_445704[7 * a1], checked);
  createPopup(dword_4456F4[menuType], dword_4456F8[menuType], dword_445700[menuType], dword_445704[menuType], top);
  result = dword_4456F0[menuType];
  //result = dword_4456F0[7 * a1];
  v5 = 0;
  v6 = 3232;
  v13 = 7049;
  if ( result > 0 )
  {
    v7 = 9 * v2;
    v12 = 9 * v2;
   // v8 = &aStartRacing[450 * v2];

	///si el menu es 6 keyboard definition hay que poner la tecla
	v8 = getMenuText(menuType, menuEntryIndex);
	
    while ( dword_445708[v3] != v5 )
    {
      if ( *(&menuActive_4457F0[v7] + v5) != 1 )
      {
        v9 = dword_4456F8[v3];
LABEL_13:
        drawTextWithFont((int)graphics2.fbig3dBpk, (int)&bigLetterSpacing_445848, v8, v6 + dword_4456F4[v3] + 640 * v9);
        goto LABEL_14;
      }
      if (top == 1 )
      {
        drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, v8, v6 + dword_4456F4[v3] + 640 * dword_4456F8[v3]);
      }
      else if ( !top)
      {
        drawTextWithFont((int)graphics2.fbig3dBpk, (int)&bigLetterSpacing_445848, v8, v6 + dword_4456F4[v3] + 640 * dword_4456F8[v3]);
      }
LABEL_14:
      v10 = 640 * dword_4456FC[v3];
      v11 = v10 + v13;
      v6 += v10;
      result = dword_4456F0[v3];
      ++v5;
	   if ( v5 >= result )
        return result;
	  v8 = getMenuText(menuType, ++menuEntryIndex);
      v13 = v11;
      if ( v5 >= result )
        return result;
      v7 = v12;
    }
    v9 = dword_4456F8[v3];
    if (top > 0 )
    {
      drawImageWithPosition(
        (int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame),
        20,  20,
        (int)((char *)screenBuffer + 640 * v9 + dword_4456F4[v3] + v13));
      drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, v8, v6 + dword_4456F4[v3] + 640 * dword_4456F8[v3]);
      goto LABEL_14;
    }
    goto LABEL_13;
  }
  return result;
}

//----- (0041AA40) --------------------------------------------------------
int   drawKeyCursor(signed int a1, const void *a2, unsigned int a3, int a4)
{
  signed int v4; // ebx@1
  signed int v5; // edi@1
  int result; // eax@1
  const void *v7; // ebp@2
  unsigned int v8; // esi@3
  signed int v9; // esi@9
  bool v10; // zf@11
  unsigned int v11; // [sp+8h] [bp+4h]@8

  v4 = a1;
  v5 = a1 >> 16;
  updateScreenPtr(a1 >> 16);
  result = a4;
  if ( a4 > 0 )
  {
    v7 = a2;
    while ( 1 )
    {
      v8 = a3;
      if ( (signed int)(a3 + v4 % 0x10000) < 0xFFFF )
        break;
      if ( (signed int)a3 > 0 )
      {
        v11 = a3;
        do
        {
          v9 = v4 >> 16;
          if ( v5 != v4 >> 16 )
            updateScreenPtr(v4 >> 16);
          *(BYTE *)(v4++ % 0x10000 + screenPtr) = *(BYTE *)v7;
          v7 = (char *)v7 + 1;
          v10 = v11 == 1;
          v5 = v9;
          --v11;
        }
        while ( !v10 );
        goto LABEL_12;
      }
LABEL_13:
      v4 += 640 - v8;
      v7 = (char *)v7 + 640 - v8;
      result = a4-- - 1;
      if ( !a4 )
        return result;
    }
    if ( v5 != v4 >> 16 )
      updateScreenPtr(v4 >> 16);
    memcpy((void *)(v4 % 0x10000 + screenPtr), v7, a3);
    v5 = v4 >> 16;
    v4 += a3;
    v7 = (char *)v7 + a3;
LABEL_12:
    v8 = a3;
    goto LABEL_13;
  }
  return result;
}
// 456BF0: using guessed type int screenPtr;

//----- (0041AB50) --------------------------------------------------------
int   updateCursor(int a1)
{
  int v1; // esi@1
  int v2; // edi@1
  signed int v3; // ecx@1
  char *v4; // eax@2
  int v5; // eax@3
  int result; // eax@3
  bool v7; // zf@3
  bool v8; // sf@3
  unsigned __int8 v9; // of@3

  v1 = a1;
  //v1 = 7 * a1;
  v2 = 640 * dword_4456FC[ a1] * dword_445708[ a1] + 7049;
  //v2 = 640 * dword_4456FC[7 * a1] * dword_445708[7 * a1] + 7049;
  v3 = 0;
  do
  {
    v4 = (char *)screenBuffer + 640 * (v3 + dword_4456F8[v1]) + v2 + dword_4456F4[v1];
    *(_DWORD *)v4 = -993737532;
    *((_DWORD *)v4 + 1) = -993737532;
    *((_DWORD *)v4 + 2) = -993737532;
    ++v3;
    *((_DWORD *)v4 + 3) = -993737532;
    *((_DWORD *)v4 + 4) = -993737532;
  }
  while ( v3 < 20 );
  drawImageWithPosition(
    (int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame),
    20,
    20,
    (int)((char *)screenBuffer + 640 * dword_4456F8[v1] + v2 + dword_4456F4[v1]));
  v5 = dword_4456F4[v1] + 640 * dword_4456F8[v1];
  drawKeyCursor(v2 + v5, (char *)screenBuffer + v5 + v2, 0x14u, 20);
  result = cursorBpkFrame + 1;
  v9 = __OFSUB__(cursorBpkFrame + 1, 49);
  v7 = cursorBpkFrame == 48;
  v8 = cursorBpkFrame++ - 48 < 0;
  if ( !((unsigned __int8)(v8 ^ v9) | v7) )
    cursorBpkFrame = 0;
  return result;
}

//----- (0041AC50) --------------------------------------------------------
int   drawCursor(int a1, int a2)
{
  signed int v2; // esi@1
  signed int v3; // eax@1
  char *v4; // edx@2
  int result; // eax@3
  bool v6; // zf@3
  bool v7; // sf@3
  unsigned __int8 v8; // of@3

  v2 = a1 + 640 * a2;
  v3 = 0;
  do
  {
    v4 = (char *)screenBuffer + v3 + v2;
    *(_DWORD *)v4 = -993737532;
    *((_DWORD *)v4 + 1) = -993737532;
    *((_DWORD *)v4 + 2) = -993737532;
    v3 += 640;
    *((_DWORD *)v4 + 3) = -993737532;
    *((_DWORD *)v4 + 4) = -993737532;
  }
  while ( v3 < 12800 );
  drawImageWithPosition((int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame), 20, 20, (int)((char *)screenBuffer + v2));
  drawKeyCursor(v2, (char *)screenBuffer + v2, 0x14u, 20);
  result = cursorBpkFrame + 1;
  v8 = __OFSUB__(cursorBpkFrame + 1, 49);
  v6 = cursorBpkFrame == 48;
  v7 = cursorBpkFrame++ - 48 < 0;
  if ( !((unsigned __int8)(v7 ^ v8) | v6) )
    cursorBpkFrame = 0;
  return result;
}
// 45FBF8: using guessed type int cursorBpkFrame;

//----- (0041ACF0) --------------------------------------------------------
int   sub_41ACF0(int a1)
{
  int v1; // esi@1
  int v2; // ebx@1
  int v3; // edx@1
  int v4; // eax@3
  int v5; // edx@3
  int v6; // eax@3
  int v7; // ebp@3
  bool v8; // zf@4
  int v9; // edx@5
  int v10; // eax@5
  int v11; // edi@5
  signed int v13; // [sp+10h] [bp-10h]@1
  signed int v14; // [sp+10h] [bp-10h]@3
  unsigned int v15; // [sp+14h] [bp-Ch]@1
  unsigned int v16; // [sp+18h] [bp-8h]@1
  int v17; // [sp+18h] [bp-8h]@3
  int v18; // [sp+1Ch] [bp-4h]@1
  int v19; // [sp+24h] [bp+4h]@3

  v1 =  a1;
  v2 = dword_4456F4[ a1];
  v15 = dword_445700[ a1] - 10;
  v16 = dword_445700[ a1] - 20;
  v18 = 640 * (dword_445708[ a1] * dword_4456FC[ a1] + dword_4456F8[ a1] + 6);
  v3 = 640 * (dword_445708[ a1] * dword_4456FC[a1] + dword_4456F8[ a1] + 6);
  /*v1 = 7 * a1;
  v2 = dword_4456F4[7 * a1];
  v15 = dword_445700[7 * a1] - 10;
  v16 = dword_445700[7 * a1] - 20;
  v18 = 640 * (dword_445708[7 * a1] * dword_4456FC[7 * a1] + dword_4456F8[7 * a1] + 6);
  v3 = 640 * (dword_445708[7 * a1] * dword_4456FC[7 * a1] + dword_4456F8[7 * a1] + 6);*/
  v13 = 22;
  do
  {
    memset((char *)screenBuffer + v3 + v2 + 2569, 0xC4u, v16);
    v3 += 640;
    --v13;
  }
  while ( v13 );
  v17 = 9 * a1;
  drawTextWithFont(
    (int)graphics2.fbig3bBpk,
    (int)&bigLetterSpacing_445848,
    getMenuText(a1, dword_445708[v1]),
    640 * (dword_4456F8[v1] + dword_445708[v1] * dword_4456FC[v1]) + dword_4456F4[v1] + 3232);
  v4 = dword_4456F0[v1] - 1;
  v5 = v4 * dword_4456FC[v1];
  dword_445708[v1] = v4;
  v6 = dword_4456F8[v1];
  v7 = 640 * (v5 + v6 + 6);
  v19 = 640 * (v5 + v6 + 6);
  v14 = 22;
  do
  {
    memset((char *)screenBuffer + v19 + v2 + 2569, 0xC4u, v15 - 10);
    v8 = v14 == 1;
    v19 += 640;
    --v14;
  }
  while ( !v8 );
  v9 = dword_445708[v1];
  v10 = v9 * dword_4456FC[v1];
  v11 = 640 * v10 + 7049;
  drawTextWithFont(
    (int)graphicsGeneral.fbig3aBpk,
    (int)&bigLetterSpacing_445848,
    getMenuText(a1, v9),
    640 * (v10 + dword_4456F8[v1]) + dword_4456F4[v1] + 3232);
  drawImageWithPosition(
    (int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame),
    20,
    20,
    (int)((char *)screenBuffer + 640 * dword_4456F8[v1] + dword_4456F4[v1] + v11));
  drawKeyCursor(v18 + v2 + 7, (char *)screenBuffer + v18 + v2 + 7, v15, 32);
  return drawKeyCursor(v2 + v7 + 7, (char *)screenBuffer + v7 + v2 + 7, v15, 32);
}
// 4456F0: using guessed type int dword_4456F0[];
// 4456F4: using guessed type int dword_4456F4[];
// 4456F8: using guessed type int dword_4456F8[];
// 4456FC: using guessed type int dword_4456FC[];
// 445700: using guessed type int dword_445700[];
// 445708: using guessed type int dword_445708[];
// 45FBF8: using guessed type int cursorBpkFrame;

//----- (0041AF40) --------------------------------------------------------
int   refreshMenuUp(int a1)
{
  int v1; // esi@1
  int v2; // ebx@1
  int v3; // edx@1
  int v4; // eax@3
  int v6; // edx@7
  int v7; // eax@7
  int v8; // ebp@7
  bool v9; // zf@8
  int v10; // edx@9
  int v11; // eax@9
  int v12; // edi@9
  signed int v14; // [sp+10h] [bp-10h]@1
  signed int v15; // [sp+10h] [bp-10h]@7
  unsigned int v16; // [sp+14h] [bp-Ch]@1
  unsigned int v17; // [sp+18h] [bp-8h]@1
  int v18; // [sp+18h] [bp-8h]@3
  int v19; // [sp+1Ch] [bp-4h]@1
  int v20; // [sp+24h] [bp+4h]@7

  v1 = a1;
  v2 = dword_4456F4[ a1];
  v16 = dword_445700[ a1] - 10;
  v17 = dword_445700[ a1] - 20;
  v19 = 640 * (dword_445708[ a1] * dword_4456FC[ a1] + dword_4456F8[ a1] + 6);
  v3 = 640 * (dword_445708[ a1] * dword_4456FC[ a1] + dword_4456F8[ a1] + 6);
  /*v1 = 7 * a1;
  v2 = dword_4456F4[7 * a1];
  v16 = dword_445700[7 * a1] - 10;
  v17 = dword_445700[7 * a1] - 20;
  v19 = 640 * (dword_445708[7 * a1] * dword_4456FC[7 * a1] + dword_4456F8[7 * a1] + 6);
  v3 = 640 * (dword_445708[7 * a1] * dword_4456FC[7 * a1] + dword_4456F8[7 * a1] + 6);*/
  v14 = 22;
  do
  {
    memset((char *)screenBuffer + v3 + v2 + 2569, 0xC4u, v17);
    v3 += 640;
    --v14;
  }
  while ( v14 );
  v18 = 9 * a1;
  /*drawTextWithFont(
    (int)fbig3bBpk,
    (int)&bigLetterSpacing_445848,
    &aStartRacing[50 * (9 * a1 + dword_445708[v1])],
    640 * (dword_4456F8[v1] + dword_445708[v1] * dword_4456FC[v1]) + dword_4456F4[v1] + 3232);*/
  drawTextWithFont(
	  (int)graphics2.fbig3bBpk,
	  (int)&bigLetterSpacing_445848,
	  getMenuText(a1, dword_445708[v1]),
	  640 * (dword_4456F8[v1] + dword_445708[v1] * dword_4456FC[v1]) + dword_4456F4[v1] + 3232);

  
  v4 = dword_445708[v1];
  do
  {
    if ( v4 <= 0 )
      v4 = dword_4456F0[v1];
  }
  //ver si es menuactive o bigletterspacing
  while ( !*(&menuActive_4457F0[9 * a1]-1 + v4--) );
  //while (!*(&byte_4457EF[9 * a1] + v4--));
  v6 = v4 * dword_4456FC[v1];
  dword_445708[v1] = v4;
  v7 = dword_4456F8[v1];
  v8 = 640 * (v6 + v7 + 6);
  v20 = 640 * (v6 + v7 + 6);
  v15 = 22;
  do
  {
    memset((char *)screenBuffer + v20 + v2 + 2569, 0xC4u, v16 - 10);
    v9 = v15 == 1;
    v20 += 640;
    --v15;
  }
  while ( !v9 );
  v10 = dword_445708[v1];
  v11 = v10 * dword_4456FC[v1];
  v12 = 640 * v11 + 7049;
 /* drawTextWithFont(
    (int)graphicsGeneral.fbig3aBpk,
    (int)&bigLetterSpacing_445848,
    &aStartRacing[50 * (v10 + v18)],
    640 * (v11 + dword_4456F8[v1]) + dword_4456F4[v1] + 3232);*/
  drawTextWithFont(
	  (int)graphicsGeneral.fbig3aBpk,
	  (int)&bigLetterSpacing_445848,
	  getMenuText(a1, v10),
	  640 * (v11 + dword_4456F8[v1]) + dword_4456F4[v1] + 3232);
 
  drawImageWithPosition(
    (int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame),
    20,
    20,
    (int)((char *)screenBuffer + 640 * dword_4456F8[v1] + dword_4456F4[v1] + v12));
  drawKeyCursor(v19 + v2 + 7, (char *)screenBuffer + v19 + v2 + 7, v16, 32);
  return drawKeyCursor(v2 + v8 + 7, (char *)screenBuffer + v8 + v2 + 7, v16, 32);
}

//----- (0041B1A0) --------------------------------------------------------
int   refreshMenuDown(int a1)
{
  int v1; // esi@1
  int v2; // ebx@1
  int v3; // edx@1
  int v4; // eax@3
  int v5; // edx@8
  int v6; // eax@8
  int v7; // ebp@8
  bool v8; // zf@9
  int v9; // edx@10
  int v10; // eax@10
  int v11; // edi@10
  signed int v13; // [sp+10h] [bp-10h]@1
  signed int v14; // [sp+10h] [bp-10h]@8
  unsigned int v15; // [sp+14h] [bp-Ch]@1
  unsigned int v16; // [sp+18h] [bp-8h]@1
  int v17; // [sp+18h] [bp-8h]@3
  int v18; // [sp+1Ch] [bp-4h]@1
  int v19; // [sp+24h] [bp+4h]@8

  v1 =  a1;
  v2 = dword_4456F4[ a1];
  v15 = dword_445700[ a1] - 10;
  v16 = dword_445700[ a1] - 20;
  v18 = 640 * (dword_445708[ a1] * dword_4456FC[ a1] + dword_4456F8[ a1] + 5);
  v3 = 640 * (dword_445708[a1] * dword_4456FC[ a1] + dword_4456F8[ a1] + 5);
 /*v1 = 7 * a1;
  v2 = dword_4456F4[7 * a1];
  v15 = dword_445700[7 * a1] - 10;
  v16 = dword_445700[7 * a1] - 20;
  v18 = 640 * (dword_445708[7 * a1] * dword_4456FC[7 * a1] + dword_4456F8[7 * a1] + 5);
  v3 = 640 * (dword_445708[7 * a1] * dword_4456FC[7 * a1] + dword_4456F8[7 * a1] + 5);*/
  v13 = 22;
  do
  {
    memset((char *)screenBuffer + v3 + v2 + 2569, 0xC4u, v16);
    v3 += 640;
    --v13;
  }
  while ( v13 );
  v17 = 9 * a1;
  /*drawTextWithFont(
	  (int)fbig3bBpk,
	  (int)&bigLetterSpacing_445848,
	  &aStartRacing[50 * (9 * a1 + dword_445708[v1])],
	  640 * (dword_4456F8[v1] + dword_445708[v1] * dword_4456FC[v1]) + dword_4456F4[v1] + 3232);*/
  drawTextWithFont(
    (int)graphics2.fbig3bBpk,
    (int)&bigLetterSpacing_445848,
	  getMenuText(a1, dword_445708[v1]),
    640 * (dword_4456F8[v1] + dword_445708[v1] * dword_4456FC[v1]) + dword_4456F4[v1] + 3232);
  v4 = dword_445708[v1];
  do
  {
    if ( v4 >= dword_4456F0[v1] - 1 )
      v4 = 0;
    else
      ++v4;
  }
  while ( !*(&menuActive_4457F0[9 * a1] + v4) );
  v5 = v4 * dword_4456FC[v1];
  dword_445708[v1] = v4;
  v6 = dword_4456F8[v1];
  v7 = 640 * (v5 + v6 + 5);
  v19 = 640 * (v5 + v6 + 5);
  v14 = 22;
  do
  {
    memset((char *)screenBuffer + v19 + v2 + 2569, 0xC4u, v15 - 10);
    v8 = v14 == 1;
    v19 += 640;
    --v14;
  }
  while ( !v8 );
  v9 = dword_445708[v1];
  v10 = v9 * dword_4456FC[v1];
  v11 = 640 * v10 + 7049;
  /*drawTextWithFont(
	  (int)graphicsGeneral.fbig3aBpk,
	  (int)&bigLetterSpacing_445848,
	  &aStartRacing[50 * (v9 + v17)],
	  640 * (v10 + dword_4456F8[v1]) + dword_4456F4[v1] + 3232);*/
  drawTextWithFont(
    (int)graphicsGeneral.fbig3aBpk,
    (int)&bigLetterSpacing_445848,
	  getMenuText(a1, v9 ), 
    640 * (v10 + dword_4456F8[v1]) + dword_4456F4[v1] + 3232);
  drawImageWithPosition(
    (int)((char *)graphics2.cursorBpk + 400 * cursorBpkFrame),
    20,
    20,
    (int)((char *)screenBuffer + 640 * dword_4456F8[v1] + dword_4456F4[v1] + v11));
  drawKeyCursor(v18 + v2 + 7, (char *)screenBuffer + v18 + v2 + 7, v15, 32);
  return drawKeyCursor(v2 + v7 + 7, (char *)screenBuffer + v7 + v2 + 7, v15, 32);
}

//----- (0042C940) --------------------------------------------------------
char seeStadistics_42C940()
{
  signed int v0; // ebp@1
  int v1; // esi@1
  unsigned __int8 v2; // bl@4
  signed int v3; // edi@4
  int v4; // ST20_4@5
  int v5; // ST1C_4@5
  int v6; // eax@5
  unsigned __int8 v7; // bl@6
  signed int v8; // edi@6
  int v9; // ST20_4@7
  int v10; // ST1C_4@7
  int v11; // eax@7
  signed int v12; // ebp@11
  int v13; // esi@11
  unsigned __int8 v14; // bl@14
  signed int v15; // edi@14
  int v16; // ST20_4@15
  int v17; // ST1C_4@15
  int v18; // eax@15
  unsigned __int8 v19; // bl@16
  signed int v20; // edi@16
  int v21; // ST20_4@17
  int v22; // ST1C_4@17
  int v23; // eax@17
  const char **v25; // [sp+0h] [bp-10h]@0
  const char **v26; // [sp+4h] [bp-Ch]@0

  sub_4224E0();
  v0 = 50;
  v1 = 6553600;
  do
  {
    waitWithRefresh();
    if ( v0 % 2 )
      updateCursor(1);
    v2 = 0;
    v3 = 0;
	//FIXED
	//v3 = (signed int)dword_45FC44;
    do
    {
      v4 = (convertColorToPaletteColor((palette1[v3+2]), v1) + 0x8000) >> 16;
      v5 = (convertColorToPaletteColor(palette1[v3 + 1], v1) + 0x8000) >> 16;
      v6 = convertColorToPaletteColor((palette1[v3]), v1);
      setPaletteAndGetValue(v2, (v6 + 0x8000) >> 16, v5, v4);
      v3 += 3;
      ++v2;
    }
    while ( v3 <288);
	//while (v3 < (signed int)&unk_4600C4);
    v7 = -128;
    v8 = 384;
	//FIXED
	//v8 = (signed int)&unk_460244;
    do
    {
      v9 = (convertColorToPaletteColor(palette1[v8+2], v1) + 0x8000) >> 16;
      v10 = (convertColorToPaletteColor(palette1[v8 + 1], v1) + 0x8000) >> 16;
      v11 = convertColorToPaletteColor(palette1[v8 ], v1);
      setPaletteAndGetValue(v7, (v11 + 0x8000) >> 16, v10, v9);
      v8 += 3;
      ++v7;
	  /* v9 = (convertColorToPaletteColor(*(_DWORD *)(v8 + 4), v1) + 0x8000) >> 16;
      v10 = (convertColorToPaletteColor(*(_DWORD *)v8, v1) + 0x8000) >> 16;
      v11 = convertColorToPaletteColor(*(_DWORD *)(v8 - 4), v1);
      setPaletteAndGetValue(v7, (v11 + 0x8000) >> 16, v10, v9);
      v8 += 12;
      ++v7;*/
    }
    while ( v8 < maxPaletteEntries);
	//while (v8 < (signed int)&unk_460844);
    --v0;
    v1 -= 0x20000;
  }
  while ( v1 >= 0 );
  sub_418090();
  eventDetected();
  //esto es mio 
  v26 = malloc(10);
  v25 = malloc(10);
  //mismo caso: postRaceMain solo mira argc, y v25/v26 no estaban inicializados.
  postRaceMain(2, (const char **)"", (const char **)"");
  memcpy(screenBuffer, graphicsGeneral.menubg5Bpk, 0x4B000u);
  drawMenu(INITIAL_MENU, 0);
  drawMenu(START_NEW_GAME_MENU, 1);
  drawTransparentBlock(0, 371, 639, 109);
  if ( isMultiplayerGame )
  {
    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "press   to enter chat mode", 233635);
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "F1", 233689);
  }
  drawBottomMenuText();
  refreshAllScreen();
  sub_4224E0();
  v12 = 0;
  v13 = 0;
  do
  {
    waitWithRefresh();
    if ( v12 % 2 )
      updateCursor(1);
    v14 = 0;
    v15 =0;
	//FIXED
	//v15 = (signed int)dword_45FC44;
    do
    {
      v16 = (convertColorToPaletteColor((palette1[v15+2]), v13) + 0x8000) >> 16;
      v17 = (convertColorToPaletteColor(palette1[v15 + 1], v13) + 0x8000) >> 16;
      v18 = convertColorToPaletteColor((palette1[v15 ]), v13);
      setPaletteAndGetValue(v14, (v18 + 0x8000) >> 16, v17, v16);
      v15 += 3;
      ++v14;
    }
    while ( v15 < 288 );
	//while (v15 < (signed int)&unk_4600C4);
    v19 = -128;
	v20 = 384;
	//FIXED
    //v20 = (signed int)&unk_460244;
    do
    {
      v21 = (convertColorToPaletteColor(palette1[v20 + 2], v13) + 0x8000) >> 16;
      v22 = (convertColorToPaletteColor(palette1[v20 + 1], v13) + 0x8000) >> 16;
      v23 = convertColorToPaletteColor(palette1[v20], v13);
      setPaletteAndGetValue(v19, (v23 + 0x8000) >> 16, v22, v21);
      v20 += 3;
      ++v19;
	  /* v21 = (convertColorToPaletteColor(*(_DWORD *)(v20 + 4), v13) + 0x8000) >> 16;
      v22 = (convertColorToPaletteColor(*(_DWORD *)v20, v13) + 0x8000) >> 16;
      v23 = convertColorToPaletteColor(*(_DWORD *)(v20 - 4), v13);
      setPaletteAndGetValue(v19, (v23 + 0x8000) >> 16, v22, v21);
      v20 += 12;
      ++v19;*/

    }
    while ( v20 < maxPaletteEntries);
	//while ( v20 < (signed int)&unk_460844 );
    v13 += 0x20000;
    ++v12;
  }
  while ( v13 < 6553600 );
  sub_418090();
  
  return eventDetected();
}

//----- (004302E0) --------------------------------------------------------
signed int defineGamepadJoystickMenu()
{
  signed int v0; // eax@2
  signed int v1; // ebx@2
  signed int result; // eax@2
  char *v3; // eax@3
  char v4; // dl@4
  char *v5; // edi@5
  char v6; // cl@6
  char *v7; // eax@8
  char v8; // dl@9
  char *v9; // edi@10
  char v10; // cl@11
  char *v11; // eax@13
  char v12; // dl@14
  char *v13; // edi@15
  char v14; // cl@16
  char *v15; // eax@18
  char v16; // dl@19
  char *v17; // edi@20
  char v18; // cl@21
  char *v19; // eax@23
  char *v20; // ecx@23
  char v21; // dl@24
  const void *v22; // esi@25
  char *v23; // edi@25
  char v24; // cl@26
  char *v25; // eax@28
  char *v26; // ecx@28
  char v27; // dl@29
  const void *v28; // esi@30
  char *v29; // edi@30
  char v30; // cl@31
  char *v31; // eax@33
  char *v32; // ecx@33
  char v33; // dl@34
  const void *v34; // esi@35
  void *v35; // edi@35
  char v36; // cl@36

  sub_41CA40();
  while ( 2 )
  {
    memcpy((char *)screenBuffer + 67200, (char *)graphicsGeneral.menubg5Bpk + 67200, 0x28F00u);
    drawMenu(INITIAL_MENU, 0);
    drawMenu(CONFIGURE_MENU, 0);
    drawMenu(DEFINE_GAMEPAD_MENU, 1);
    refreshAllScreen();
    v0 = readEventInMenu(DEFINE_GAMEPAD_MENU);
    v1 = v0;
    result = v0 + 1;
    switch ( result )
    {
      case 1:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_GAMEPAD_MENU, 0);
        createPopup(295, 121, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Move gamepad for accelerate...", 86065);
        refreshAllScreen();
		configuration.accelerateGamepad = (unsigned __int8)sub_42CBF0();
        sub_418090();
        eventDetected();
        dword_44717C = 1634887020;
        byte_447186 = 0;
        dword_447178 = 1701012289;
        v3 = (char *)&unk_45EAC0 + 15 * configuration.accelerateGamepad;
        dword_447180 = 538994036;
        word_447184 = 8224;
        do
          v4 = *v3++;
        while ( v4 );
        result = v3 - ((char *)&unk_45EAC0 + 15 * configuration.accelerateGamepad);
        v5 = (char *)&dword_447178 - 1;
        do
          v6 = (v5++)[1];
        while ( v6 );
        memcpy(v5, (char *)&unk_45EAC0 + 15 * configuration.accelerateGamepad, result);
        goto LABEL_40;
      case 2:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_GAMEPAD_MENU, 0);
        createPopup(295, 149, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Move gamepad for brake...", 103985);
        refreshAllScreen();
		configuration.brakeGamepad = (unsigned __int8)sub_42CBF0();
        sub_418090();
        eventDetected();
        dword_4471AA = 1801548354;
        word_4471B6 = 32;
        v7 = (char *)&unk_45EAC0 + 15 * configuration.brakeGamepad;
        dword_4471AE = 538976357;
        dword_4471B2 = 538976288;
        do
          v8 = *v7++;
        while ( v8 );
        result = v7 - ((char *)&unk_45EAC0 + 15 * configuration.brakeGamepad);
        v9 = (char *)&dword_4471AA - 1;
        do
          v10 = (v9++)[1];
        while ( v10 );
        memcpy(v9, (char *)&unk_45EAC0 + 15 * configuration.brakeGamepad, result);
        goto LABEL_40;
      case 3:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_GAMEPAD_MENU, 0);
        createPopup(295, 177, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Move gamepad for left steer...", 121905);
        refreshAllScreen();
		configuration.leftSteeringGamepad = (unsigned __int8)sub_42CBF0();
        sub_418090();
        eventDetected();
        dword_4471DC = 1701147731;
        dword_4471E8 = -84271072;
        dword_4471E0 = 1699487858;
        v11 = (char *)&unk_45EAC0 + 15 * configuration.leftSteeringGamepad;
        byte_4471EC = 0;
        dword_4471E4 = 538997862;
        do
          v12 = *v11++;
        while ( v12 );
        result = v11 - ((char *)&unk_45EAC0 + 15 * configuration.leftSteeringGamepad);
        v13 = (char *)&dword_4471DC - 1;
        do
          v14 = (v13++)[1];
        while ( v14 );
        memcpy(v13, (char *)&unk_45EAC0 + 15 * configuration.leftSteeringGamepad, result);
        goto LABEL_40;
      case 4:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_GAMEPAD_MENU, 0);
        createPopup(295, 205, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Move gamepad for right steer...", 139825);
        refreshAllScreen();
		configuration.rightSteeringGamepad = (unsigned __int8)sub_42CBF0();
        sub_418090();
        eventDetected();
        dword_447216 = 544499815;
        byte_447222 = 0;
        dword_44720E = 1701147731;
        dword_447212 = 1766989938;
        v15 = (char *)&unk_45EAC0 + 15 * configuration.rightSteeringGamepad;
        dword_44721A = -84271072;
        dword_44721E = -84215046;
        do
          v16 = *v15++;
        while ( v16 );
        result = v15 - ((char *)&unk_45EAC0 + 15 * configuration.rightSteeringGamepad);
        v17 = (char *)&dword_44720E - 1;
        do
          v18 = (v17++)[1];
        while ( v18 );
        memcpy(v17, (char *)&unk_45EAC0 + 15 * configuration.rightSteeringGamepad, result);
        goto LABEL_40;
      case 5:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_GAMEPAD_MENU, 0);
        createPopup(295, 233, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Move gamepad for turbo boost...", 157745);
        refreshAllScreen();
		configuration.turboGamepad = (unsigned __int8)sub_42CBF0();
        sub_418090();
        eventDetected();
        memcpy(&unk_447240, word_442A18, 0x18u);
        v19 = (char *)&unk_45EAC0 + 15 * configuration.turboGamepad;
        *((_WORD *)&unk_447240 + 12) = word_442A18[12];
        v20 = v19;
        do
          v21 = *v19++;
        while ( v21 );
        result = v19 - v20;
        v22 = v20;
        v23 = (char *)&unk_447240 - 1;
        do
          v24 = (v23++)[1];
        while ( v24 );
        memcpy(v23, v22, result);
        goto LABEL_40;
      case 6:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_GAMEPAD_MENU, 0);
        createPopup(295, 261, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Move gamepad  for machine gun...", 175665);
        refreshAllScreen();
		configuration.gunGamepad = (unsigned __int8)sub_42CBF0();
        sub_418090();
        eventDetected();
        memcpy(&unk_447272, word_4429FC, 0x18u);
        v25 = (char *)&unk_45EAC0 + 15 * configuration.gunGamepad;
        *((_WORD *)&unk_447272 + 12) = word_4429FC[12];
        v26 = v25;
        do
          v27 = *v25++;
        while ( v27 );
        result = v25 - v26;
        v28 = v26;
        v29 = (char *)&unk_447272 - 1;
        do
          v30 = (v29++)[1];
        while ( v30 );
        memcpy(v29, v28, result);
        goto LABEL_40;
      case 7:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_GAMEPAD_MENU, 0);
        createPopup(295, 289, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Move gamepad for drop mine...", 193585);
        refreshAllScreen();
		configuration.mineGamepad = (unsigned __int8)sub_42CBF0();
        sub_418090();
        eventDetected();
        memcpy(byte_4472A4, byte_4429E0, 0x18u);
        v31 = (char *)&unk_45EAC0 + 15 * configuration.mineGamepad;
        byte_4472A4[24] = byte_4429E0[24];
        v32 = v31;
        do
          v33 = *v31++;
        while ( v33 );
        result = v31 - v32;
        v34 = v32;
        v35 = &byte_4472A4[-1];
        do
        {
          v36 = *((BYTE *)v35 + 1);
          v35 = (char *)v35 + 1;
        }
        while ( v36 );
        memcpy(v35, v34, result);
        goto LABEL_40;
      case 0:
      case 8:
        result = sub_428740();
        if ( result == 1 )
          continue;
        if ( v1 != 7 )
          goto LABEL_40;
        result = 0;
        dword_4457E8 = 0;
        if ( !menuActive_4457F0 [72] )
        {
          do
          {
            if ( result >= dword_4457D0 - 1 )
              result = 0;
            else
              ++result;
          }
          while ( !menuActive_4457F0[72+result] );
          dword_4457E8 = result;
        }
        return result;
      default:
LABEL_40:
        if ( v1 != -1 )
          continue;
        return result;
    }
  }
}
// 4457D0: using guessed type int dword_4457D0;
// 4457E8: using guessed type int dword_4457E8;
// 4458B0: using guessed type char letterSpacing_4458B0;
// 447178: using guessed type int dword_447178;
// 44717C: using guessed type int dword_44717C;
// 447180: using guessed type int dword_447180;
// 447184: using guessed type __int16 word_447184;
// 447186: using guessed type char byte_447186;
// 4471AA: using guessed type int dword_4471AA;
// 4471AE: using guessed type int dword_4471AE;
// 4471B2: using guessed type int dword_4471B2;
// 4471B6: using guessed type __int16 word_4471B6;
// 4471DC: using guessed type int dword_4471DC;
// 4471E0: using guessed type int dword_4471E0;
// 4471E4: using guessed type int dword_4471E4;
// 4471E8: using guessed type int dword_4471E8;
// 4471EC: using guessed type char byte_4471EC;
// 44720E: using guessed type int dword_44720E;
// 447212: using guessed type int dword_447212;
// 447216: using guessed type int dword_447216;
// 44721A: using guessed type int dword_44721A;
// 44721E: using guessed type int dword_44721E;
// 447222: using guessed type char byte_447222;
// 45EEA0: using guessed type int configuration.leftSteeringGamepad;
// 461294: using guessed type int configuration.accelerateGamepad;
// 461F14: using guessed type int configuration.brakeGamepad;
// 462CFC: using guessed type int configuration.gunGamepad;
// 462D6C: using guessed type int configuration.rightSteeringGamepad;
// 463CA4: using guessed type int configuration.mineGamepad;
// 463D8C: using guessed type int configuration.turboGamepad;

//----- (004309A0) --------------------------------------------------------
int showAdjustOptions()
{
  int v0; // ebp@1
  signed int v1; // eax@3
  char v2; // bl@4
  char v3; // al@8
  signed int v4; // edx@23
  char *v5; // edi@24
  int v8; // eax@27
  char v9; // bl@29
  char v10; // al@33
  signed int v11; // edx@46
  char *v12; // edi@47
  int v15; // eax@50
  int v17; // eax@62
  int v18; // [sp+10h] [bp-14h]@1
  int v19; // [sp+14h] [bp-10h]@1
  char DstBuf[12]; // [sp+18h] [bp-Ch]@25

  v18 = configuration.musicVolume / 512;
  v0 = configuration.effectsVolume / 512;
  v19 = configuration.effectsVolume / 512;
LABEL_2:
  while ( !dword_456B9C )
  {
    memcpy((char *)screenBuffer + 53760, (char *)graphicsGeneral.menubg5Bpk + 53760, 0x2C380u);
    drawMenu(INITIAL_MENU, 0);
    drawMenu(CONFIGURE_MENU, 1);
    refreshAllScreen();
    v1 = readEventInMenu(CONFIGURE_MENU);
    switch ( v1 )
    {
      case 0:
        drawMenu(CONFIGURE_MENU, 0);
        createPopup(214, 218, 330, 70, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Adjust music volume:", 144864);
        drawImageWithPosition((int)slidmus2Bpk, 172, 24, (int)((char *)screenBuffer + 160314));
        refreshAllScreen();
        v2 = 0;
        do
        {
          if ( v2 == -100 || v2 == 1 || dword_456B9C )
            break;
          v3 = eventDetected();
          v2 = v3;
          switch ( v3 )
          {
            case -53:
              if ( v18 > 0 )
                v18 -= 2;
              break;
            case KEY_LEFT:
              if ( v18 > 0 )
                v18 -= 2;
              break;
            case -51:
              if ( v18 < 128 )
                v18 += 2;
              break;
            case KEY_RIGHT:
              if ( v18 < 128 )
                v18 += 2;
              break;
            default:
              //if ( v3 == 59 && isMultiplayerGame )
              //  multiplayer_sub_42CCF0();
              break;
          }
          v4 = 0;
          do
          {
            v5 = (char *)screenBuffer + v4 + 157660;
            memset(v5, 0xC4u, 0x110u);
            v5 += 272;
            *(_WORD *)v5 = -15164;
            v4 += 640;
            v5[2] = -60;
          }
          while ( v4 < 19200 );
          drawImageWithPosition((int)slidmus2Bpk, 172, 24, (int)((char *)screenBuffer + 160314));
          drawImageWithPosition((int)volcur2Bpk, 10, 24, (int)((char *)screenBuffer + v18 + 160329));
          drawKeyCursor(v18 + 160327, (char *)screenBuffer + v18 + 160327, 0xEu, 24);

          
          SDL_itoa((unsigned __int64)((double)v18 * 0.78125), DstBuf, 10);
          // DstBuf followed v19 on the original stack: the scan from &v19 found its end
          strcat(DstBuf, "%");
          v8 = getBoxBigTextOffset(DstBuf);
          drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, DstBuf, 157109 - v8);
          drawKeyCursor(157024, (char *)screenBuffer + 157024, 0x78u, 32);
          musicSetmusicVolume(v18 << 9);
          refreshAndCheckConnection_42A570();
        }
        while ( v2 != 28 );
        configuration.musicVolume = v18 << 9;
        loadMenuSoundEffect(1u, 22, 0, configuration.effectsVolume, dword_4451A0);
        goto LABEL_2;
      case 1:
        drawMenu(CONFIGURE_MENU, 0);
        createPopup(214, 218, 330, 70, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Adjust effect volume:", 144864);
        drawImageWithPosition((int)slidmus2Bpk, 172, 24, (int)((char *)screenBuffer + 160314));
        refreshAllScreen();
        v9 = 0;
        do
        {
          if ( v9 == -100 || v9 == 1 || dword_456B9C )
            break;
          v10 = eventDetected();
          v9 = v10;
          if ( v10 == -53 )
          {
            if ( v0 > 0 )
            {
              v0 -= 2;
              v19 = v0;
            }
          }
          else if ( v10 == KEY_LEFT)
          {
            if ( v0 > 0 )
            {
              v0 -= 2;
              v19 = v0;
            }
          }
          else if ( v10 != -51 && v10 != KEY_RIGHT)
          {
            //if ( v10 == 59 && isMultiplayerGame )
            //  multiplayer_sub_42CCF0();
          }
          else if ( v0 < 128 )
          {
            v0 += 2;
            v19 = v0;
          }
          v11 = 0;
          do
          {
            v12 = (char *)screenBuffer + v11 + 157660;
            memset(v12, 0xC4u, 0x110u);
            v12 += 272;
            *(_WORD *)v12 = -15164;
            v11 += 640;
            v12[2] = -60;
          }
          while ( v11 < 19200 );
          drawImageWithPosition((int)slidmus2Bpk, 172, 24, (int)((char *)screenBuffer + 160314));
          drawImageWithPosition((int)volcur2Bpk, 10, 24, (int)((char *)screenBuffer + v0 + 160329));
          drawKeyCursor(v0 + 160327, (char *)screenBuffer + v0 + 160327, 0xEu, 24);
          SDL_itoa((unsigned __int64)((double)v19 * 0.78125),DstBuf, 10);
          strcat(DstBuf, "%");
          v15 = getBoxBigTextOffset(DstBuf);
          drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, DstBuf, 157109 - v15);
          drawKeyCursor(157024, (char *)screenBuffer + 157024, 0x78u, 32);
          musicSetVolume(v0 << 9);
          refreshAndCheckConnection_42A570();
        }
        while ( v9 != 28 );
        configuration.effectsVolume = v0 << 9;
        loadMenuSoundEffect(1u, 22, 0, configuration.effectsVolume, dword_4451A0);
        goto LABEL_2;
      case 2:
        redefineControls();
        goto LABEL_2;
      case 3:
        defineGamepadJoystickMenu();
        goto LABEL_2;
      case 4:
        if ( configuration.useJoystick )
        {
          configuration.useJoystick = 0;
LABEL_58:
          memcpy(aGamepadDisable, "Gamepad/Joystick Disabled", 0x1Au);
          goto LABEL_2;
        }
        configuration.useJoystick = 1;
        SDLConfigureJoystick();
        if ( !configuration.useJoystick )
          GamepadNotFoundPopup_41E3B0();
        configJoystick();
        memcpy(aGamepadDisable, "Gamepad/Joystick Enabled", 0x19u);
        if ( !configuration.useJoystick )
          goto LABEL_58;
        break;
      case PREVIOUS_MENU:
        v17 = 0;
        dword_44575C = 0;
        if ( !menuActive_4457F0[27] )
        {
          do
          {
            if ( v17 >= dword_445744 - 1 )
              v17 = 0;
            else
              ++v17;
          }
          while ( !menuActive_4457F0[27+v17] );
          dword_44575C = v17;
        }
        return saveConfiguration();
      default:
        if ( v1 != -1 )
          goto LABEL_2;
        return saveConfiguration();
    }
  }
  return saveConfiguration();
}

//----- (0042FB00) --------------------------------------------------------
signed int redefineControls()
{
  signed int v0; // eax@2
  signed int v1; // ebx@2
  signed int result; // eax@2
  char *v3; // eax@6
  char *v4; // edx@6
  char v5; // cl@7
  char *v6; // edi@8
  char v7; // cl@9
  char *v8; // eax@14
  char v9; // cl@15
  char v10; // cl@17
  char *v11; // eax@22
  char v12; // cl@23
  char v13; // cl@25
  char *v14; // eax@30
  char v15; // cl@31
  char v16; // cl@33
  char *v17; // eax@38
  char *v18; // ecx@38
  char v19; // dl@39
  const void *v20; // esi@40
  char *v21; // edi@40
  char v22; // cl@41
  char *v23; // eax@46
  char *v24; // ecx@46
  char v25; // dl@47
  const void *v26; // esi@48
  char *v27; // edi@48
  char v28; // cl@49
  char *v29; // eax@54
  char *v30; // ecx@54
  char v31; // dl@55
  const void *v32; // esi@56
  void *v33; // edi@56
  char v34; // cl@57
  char *v35; // eax@62
  char v36; // dl@63
  char *v37; // edi@64
  char v38; // cl@65

  sub_41CA40();
  while ( 2 )
  {
    memcpy((char *)screenBuffer + 67200, (char *)graphicsGeneral.menubg5Bpk + 67200, 0x28F00u);
    drawMenu(INITIAL_MENU, 0);
    drawMenu(CONFIGURE_MENU, 0);
    drawMenu(DEFINE_KEYBOARD_MENU, 1);
    refreshAllScreen();
    v0 = readEventInMenu(DEFINE_KEYBOARD_MENU);
    v1 = v0;
    result = v0 + 1;
    switch ( result )
    {
      case 1:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 121, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for accelerate...", 86065);
        refreshAllScreen();
        do
        {
          do
          {
			  configuration.accelerateKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.accelerateKey);
        }
        while (configuration.accelerateKey == 170 );
        sub_418090();
        eventDetected();
        dword_446DF8 = 1634887020;//lera
        byte_446E02 = 0;
        dword_446DF4 = 1701012289;//Acce
        v3 = (char *)&unk_462DA0 + 15 * configuration.accelerateKey;
        word_446E00 = 8224;
        dword_446DFC = 538994036;//te  
        v4 = (char *)&unk_462DA0 + 15 * configuration.accelerateKey;
        do
          v5 = *v3++;
        while ( v5 );
        result = v3 - v4;
        v6 = (char *)&dword_446DF4 - 1;
        do
          v7 = (v6++)[1];
        while ( v7 );
        goto LABEL_34;
      case 2:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 149, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for brake...", 103985);
        refreshAllScreen();
        do
        {
          do
          {
			  configuration.brakeKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.brakeKey );
        }
        while (configuration.brakeKey == 170 );
        sub_418090();
        eventDetected();
        dword_446E26 = 1801548354;
        word_446E32 = 32;
        v8 = (char *)&unk_462DA0 + 15 * configuration.brakeKey;
        dword_446E2E = 538976288;
        dword_446E2A = 538976357;
        v4 = (char *)&unk_462DA0 + 15 * configuration.brakeKey;
        do
          v9 = *v8++;
        while ( v9 );
        result = v8 - v4;
        v6 = (char *)&dword_446E26 - 1;
        do
          v10 = (v6++)[1];
        while ( v10 );
        goto LABEL_34;
      case 3:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 177, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for left steer...", 121905);
        refreshAllScreen();
        do
        {
          do
          {
			  configuration.leftSteeringKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.leftSteeringKey);
        }
        while (configuration.leftSteeringKey == 170 );
        sub_418090();
        eventDetected();
        dword_446E58 = 1701147731;
        dword_446E64 = -84271072;
        dword_446E5C = 1699487858;
        v11 = (char *)&unk_462DA0 + 15 * configuration.leftSteeringKey;
        dword_446E60 = 538997862;
        byte_446E68 = 0;
        v4 = (char *)&unk_462DA0 + 15 * configuration.leftSteeringKey;
        do
          v12 = *v11++;
        while ( v12 );
        result = v11 - v4;
        v6 = (char *)&dword_446E58 - 1;
        do
          v13 = (v6++)[1];
        while ( v13 );
        goto LABEL_34;
      case 4:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 205, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for right steer...", 139825);
        refreshAllScreen();
        do
        {
          do
          {
			configuration.rightSteeringKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.rightSteeringKey);
        }
        while (configuration.rightSteeringKey == 170 );
        sub_418090();
        eventDetected();
        dword_446E92 = 544499815;
        byte_446E9E = 0;
        dword_446E8E = 1766989938;
        dword_446E8A = 1701147731;
        v14 = (char *)&unk_462DA0 + 15 * configuration.rightSteeringKey;
        dword_446E9A = -84215046;
        dword_446E96 = -84271072;
        v4 = (char *)&unk_462DA0 + 15 * configuration.rightSteeringKey;
        do
          v15 = *v14++;
        while ( v15 );
        result = v14 - v4;
        v6 = (char *)&dword_446E8A - 1;
        do
          v16 = (v6++)[1];
        while ( v16 );
LABEL_34:
        memcpy(v6, v4, result);
        goto LABEL_69;
      case 5:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 233, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for turbo boost...", 157745);
        refreshAllScreen();
        do
        {
          do
          {
			  configuration.turboKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.turboKey);
        }
        while (configuration.turboKey == 170 );
        sub_418090();
        eventDetected();
        memcpy(&unk_446EBC, word_442A18, 0x18u);
        v17 = (char *)&unk_462DA0 + 15 * configuration.turboKey;
        *((_WORD *)&unk_446EBC + 12) = word_442A18[12];
        v18 = v17;
        do
          v19 = *v17++;
        while ( v19 );
        result = v17 - v18;
        v20 = v18;
        v21 = (char *)&unk_446EBC - 1;
        do
          v22 = (v21++)[1];
        while ( v22 );
        memcpy(v21, v20, result);
        goto LABEL_69;
      case 6:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 261, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for machine gun...", 175665);
        refreshAllScreen();
        do
        {
          do
          {
			  configuration.gunKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.gunKey);
        }
        while (configuration.gunKey == 170 );
        sub_418090();
        eventDetected();
        memcpy(&unk_446EEE, word_4429FC, 0x18u);
        v23 = (char *)&unk_462DA0 + 15 * configuration.gunKey;
        *((_WORD *)&unk_446EEE + 12) = word_4429FC[12];
        v24 = v23;
        do
          v25 = *v23++;
        while ( v25 );
        result = v23 - v24;
        v26 = v24;
        v27 = (char *)&unk_446EEE - 1;
        do
          v28 = (v27++)[1];
        while ( v28 );
        memcpy(v27, v26, result);
        goto LABEL_69;
      case 7:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 289, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for drop mine...", 193585);
        refreshAllScreen();
        do
        {
          do
          {
			  configuration.mineKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.mineKey);
        }
        while (configuration.mineKey == 170 );
        sub_418090();
        eventDetected();
        memcpy(byte_446F20, byte_4429E0, 0x18u);
        v29 = (char *)&unk_462DA0 + 15 * configuration.mineKey;
        byte_446F20[24] = byte_4429E0[24];
        v30 = v29;
        do
          v31 = *v29++;
        while ( v31 );
        result = v29 - v30;
        v32 = v30;
        v33 = &byte_446F20[-1];
        do
        {
          v34 = *((BYTE *)v33 + 1);
          v33 = (char *)v33 + 1;
        }
        while ( v34 );
        memcpy(v33, v32, result);
        goto LABEL_69;
      case 8:
        drawMenu(INITIAL_MENU, 0);
        drawMenu(CONFIGURE_MENU, 0);
        drawMenu(DEFINE_KEYBOARD_MENU, 0);
        createPopup(295, 317, 323, 48, 1);
        drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, "Press a key for horn...", 211505);
        refreshAllScreen();
        do
        {
          do
          {
			  configuration.hornKey = (unsigned __int8)eventDetected();
            waitWithRefresh();
          }
          while ( !configuration.hornKey);
        }
        while (configuration.hornKey == 170 );
        sub_418090();
        eventDetected();
        v35 = (char *)&unk_462DA0 + 15 * configuration.hornKey;
        memcpy(&unk_446F52, &unk_4429C0, 0x20u);
        do
          v36 = *v35++;
        while ( v36 );
        result = v35 - ((char *)&unk_462DA0 + 15 * configuration.hornKey);
        v37 = (char *)&unk_446F52 - 1;
        do
          v38 = (v37++)[1];
        while ( v38 );
        memcpy(v37, (char *)&unk_462DA0 + 15 * configuration.hornKey, result);
        goto LABEL_69;
      case 0:
      case 9:
        result = sub_4284E0();
        if ( result == 1 )
          continue;
        if ( v1 != 8 )
          goto LABEL_69;
        result = 0;
        dword_4457B0 = 0;
        if ( !menuActive_4457F0[54] )
        {
          do
          {
            if ( result >= dword_445798 - 1 )
              result = 0;
            else
              ++result;
          }
          while ( !menuActive_4457F0[54+result] );
          dword_4457B0 = result;
        }
        return result;
      default:
LABEL_69:
        if ( v1 != -1 )
          continue;
        return result;
    }
  }
}
// 445798: using guessed type int dword_445798;
// 4457B0: using guessed type int dword_4457B0;
// 4458B0: using guessed type char letterSpacing_4458B0;
// 446DF4: using guessed type int dword_446DF4;
// 446DF8: using guessed type int dword_446DF8;
// 446DFC: using guessed type int dword_446DFC;
// 446E00: using guessed type __int16 word_446E00;
// 446E02: using guessed type char byte_446E02;
// 446E26: using guessed type int dword_446E26;
// 446E2A: using guessed type int dword_446E2A;
// 446E2E: using guessed type int dword_446E2E;
// 446E32: using guessed type __int16 word_446E32;
// 446E58: using guessed type int dword_446E58;
// 446E5C: using guessed type int dword_446E5C;
// 446E60: using guessed type int dword_446E60;
// 446E64: using guessed type int dword_446E64;
// 446E68: using guessed type char byte_446E68;
// 446E8A: using guessed type int dword_446E8A;
// 446E8E: using guessed type int dword_446E8E;
// 446E92: using guessed type int dword_446E92;
// 446E96: using guessed type int dword_446E96;
// 446E9A: using guessed type int dword_446E9A;
// 446E9E: using guessed type char byte_446E9E;
// 45EA68: using guessed type int configuration.rightSteeringKey;
// 45FBF4: using guessed type int configuration.turboKey;
// 461270: using guessed type int configuration.mineKey;
// 461EA8: using guessed type int configuration.accelerateKey;
// 461FF8: using guessed type int configuration.leftSteeringKey;
// 463CA8: using guessed type int configuration.brakeKey;
// 463CE4: using guessed type int configuration.gunKey;
// 463D18: using guessed type int configuration.hornKey;


//----- (0041CA40) --------------------------------------------------------
unsigned int sub_41CA40()
{
  char *v0; // eax@1
  char *v1; // eax@1
  char *v2; // eax@1
  char *v3; // eax@1
  char *v4; // eax@1
  char *v5; // eax@1
  char *v6; // eax@1
  char *v7; // eax@1
  char *v8; // eax@1
  char *v11; // eax@3
  char v12; // dl@4
  unsigned int v13; // eax@5
  char *v14; // esi@5
  char *v15; // edi@5
  char v16; // cl@6
  void *v17; // edi@7
  const void *v18; // esi@7
  int v19; // ecx@7
  char *v20; // eax@7
  char *v21; // ecx@7
  char v22; // dl@8
  unsigned int v23; // eax@9
  const void *v24; // esi@9
  char *v25; // edi@9
  char v26; // cl@10
  void *v27; // edi@11
  const void *v28; // esi@11
  int v29; // ecx@11
  char *v30; // eax@11
  char *v31; // ecx@11
  char v32; // dl@12
  unsigned int v33; // eax@13
  const void *v34; // esi@13
  char *v35; // edi@13
  char v36; // cl@14
  void *v37; // edi@15
  const void *v38; // esi@15
  int v39; // ecx@15
  char *v40; // eax@15
  char *v41; // ecx@15
  char v42; // dl@16
  unsigned int v43; // eax@17
  const void *v44; // esi@17
  char *v45; // edi@17
  char v46; // cl@18
  void *v47; // edi@19
  const void *v48; // esi@19
  int v49; // ecx@19
  char *v50; // eax@19
  char *v51; // ecx@19
  char v52; // dl@20
  unsigned int v53; // eax@21
  const void *v54; // esi@21
  char *v55; // edi@21
  char v56; // cl@22
  void *v57; // edi@23
  const void *v58; // esi@23
  int v59; // ecx@23
  char *v60; // eax@23
  char *v61; // ecx@23
  char v62; // dl@24
  unsigned int v63; // eax@25
  const void *v64; // esi@25
  char *v65; // edi@25
  char v66; // cl@26
  void *v67; // edi@27
  const void *v68; // esi@27
  int v69; // ecx@27
  char *v70; // eax@27
  char *v71; // ecx@27
  char v72; // dl@28
  unsigned int v73; // eax@29
  const void *v74; // esi@29
  void *v75; // edi@29
  char v76; // cl@30
  void *v77; // edi@31
  const void *v78; // esi@31
  int v79; // ecx@31
  char *v80; // eax@31
  const void *v81; // esi@31
  char v82; // cl@32
  unsigned int v83; // eax@33
  char *v84; // edi@33
  char v85; // cl@34
  int v86; // eax@35
  char *v87; // eax@35
  char *v88; // ecx@35
  char v89; // dl@36
  unsigned int v90; // eax@37
  const void *v91; // esi@37
  char *v92; // edi@37
  char v93; // cl@38
  void *v94; // edi@39
  const void *v95; // esi@39
  int v96; // ecx@39
  char *v97; // eax@39
  char *v98; // ecx@39
  char v99; // dl@40
  unsigned int v100; // eax@41
  const void *v101; // esi@41
  char *v102; // edi@41
  char v103; // cl@42
  void *v104; // edi@43
  const void *v105; // esi@43
  int v106; // ecx@43
  char *v107; // eax@43
  char *v108; // ecx@43
  char v109; // dl@44
  unsigned int v110; // eax@45
  const void *v111; // esi@45
  char *v112; // edi@45
  char v113; // cl@46
  void *v114; // edi@47
  const void *v115; // esi@47
  int v116; // ecx@47
  char *v117; // eax@47
  char *v118; // ecx@47
  char v119; // dl@48
  unsigned int v120; // eax@49
  const void *v121; // esi@49
  char *v122; // edi@49
  char v123; // cl@50
  void *v124; // edi@51
  const void *v125; // esi@51
  int v126; // ecx@51
  char *v127; // eax@51
  char *v128; // ecx@51
  char v129; // dl@52
  unsigned int v130; // eax@53
  const void *v131; // esi@53
  char *v132; // edi@53
  char v133; // cl@54
  void *v134; // edi@55
  const void *v135; // esi@55
  int v136; // ecx@55
  char *v137; // eax@55
  char *v138; // ecx@55
  char v139; // dl@56
  unsigned int v140; // eax@57
  const void *v141; // esi@57
  char *v142; // edi@57
  char v143; // cl@58
  void *v144; // edi@59
  const void *v145; // esi@59
  int v146; // ecx@59
  char *v147; // eax@59
  char *v148; // ecx@59
  char v149; // dl@60
  unsigned int result; // eax@61
  const void *v151; // esi@61
  void *v152; // edi@61
  char v153; // cl@62

  v0 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)byte_456B01;
  *(_DWORD *)v0 = 538976301;
  *((_DWORD *)v0 + 1) = 538976288;
  *((_DWORD *)v0 + 2) = 538976288;
  v0[12] = 0;
  v1 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)configuration.defaultLeftSteeringGamepad;
  *(_DWORD *)v1 = 1952867692;
  *((_DWORD *)v1 + 1) = 538976288;
  *((_DWORD *)v1 + 2) = 538976288;
  v1[12] = 0;
  v2 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)configuration.defaultRightSteeringGamepad;
  *(_DWORD *)v2 = 1751607666;
  *((_DWORD *)v2 + 1) = 538976372;
  *((_DWORD *)v2 + 2) = 538976288;
  v2[12] = 0;
  v3 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)byte_44512A;
  *(_DWORD *)v3 = 538996853;
  *((_DWORD *)v3 + 1) = 538976288;
  *((_DWORD *)v3 + 2) = 538976288;
  v3[12] = 0;
  v4 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)configuration.defaultBrakeGamepad;
  *(_DWORD *)v4 = 1853321060;
  *((_DWORD *)v4 + 1) = 538976288;
  *((_DWORD *)v4 + 2) = 538976288;
  v4[12] = 0;
  v5 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)configuration.defaultAccelerateGamepad;
  *(_DWORD *)v5 = 1953789282;
  *((_DWORD *)v5 + 1) = 824209007;
  *((_DWORD *)v5 + 2) = 538976288;
  v5[12] = 0;
  v6 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)configuration.defaultTurboGamepad;
  *(_DWORD *)v6 = 1953789282;
  *((_DWORD *)v6 + 1) = 840986223;
  *((_DWORD *)v6 + 2) = 538976288;
  v6[12] = 0;
  v7 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)configuration.defaultGunGamepad;
  *(_DWORD *)v7 = 1953789282;
  *((_DWORD *)v7 + 1) = 857763439;
  *((_DWORD *)v7 + 2) = 538976288;
  v7[12] = 0;
  v8 = (char *)&unk_45EAC0 + 15 * (unsigned __int8)configuration.defaultMineGamepad;
  *(_DWORD *)v8 = 1953789282;
  *((_DWORD *)v8 + 1) = 874540655;
  *((_DWORD *)v8 + 2) = 538976288;
  v8[12] = 0;
  //Nombres de las teclas (0x462DA0, 256 x 15). Se llenaba con "UNAVAILABLE " hasta &numberOfLaps,
  //que aqui esta en cualquier lado (pisaba cientos de KB de globales al entrar al menu), y
  //despues con 400 escrituras a globales sueltas que el menu nunca leia.
  memcpy(unk_462DA0, originalKeyNames, sizeof(unk_462DA0));
  dword_446DF4 = 1701012289;
  byte_446E02 = 0;
  word_446E00 = 8224;
  dword_446E2E = 538976288;
  dword_446DFC = 538994036;
  dword_446E2A = 538976357;
  dword_446E5C = 1699487858;
  dword_446E26 = 1801548354;
  dword_446E58 = 1701147731;
  byte_446E68 = 0;
  word_446E32 = 32;
  dword_446E64 = -84271072;
  dword_446E92 = 544499815;
  dword_446E60 = 538997862;
  dword_446E8E = 1766989938;
  byte_446E9E = 0;
  dword_446E8A = 1701147731;
  dword_446E9A = -84215046;
  dword_446DF8 = 1634887020;
  dword_446E96 = -84271072;
  memcpy(&unk_446EBC, word_442A18, 0x1Au);
  memcpy(&unk_446EEE, word_4429FC, 0x1Au);
  memcpy(byte_446F20, byte_4429E0, 0x19u);
  v11 = (char *)&unk_462DA0 + 15 * configuration.accelerateKey;
  memcpy(&unk_446F52, &unk_4429C0, 0x20u);
  do
    v12 = *v11++;
  while ( v12 );
  v13 = v11 - ((char *)&unk_462DA0 + 15 * configuration.accelerateKey);
  v14 = (char *)&unk_462DA0 + 15 * configuration.accelerateKey;
  v15 = (char *)&dword_446DF4 - 1;
  do
    v16 = (v15++)[1];
  while ( v16 );
  memcpy(v15, v14, 4 * (v13 >> 2));
  v18 = &v14[4 * (v13 >> 2)];
  v17 = &v15[4 * (v13 >> 2)];
  v19 = v13 & 3;
  v20 = (char *)&unk_462DA0 + 15 * configuration.brakeKey;
  memcpy(v17, v18, v19);
  v21 = v20;
  do
    v22 = *v20++;
  while ( v22 );
  v23 = v20 - v21;
  v24 = v21;
  v25 = (char *)&dword_446E26 - 1;
  do
    v26 = (v25++)[1];
  while ( v26 );
  memcpy(v25, v24, 4 * (v23 >> 2));
  v28 = (char *)v24 + 4 * (v23 >> 2);
  v27 = &v25[4 * (v23 >> 2)];
  v29 = v23 & 3;
  v30 = (char *)&unk_462DA0 + 15 * configuration.leftSteeringKey;
  memcpy(v27, v28, v29);
  v31 = v30;
  do
    v32 = *v30++;
  while ( v32 );
  v33 = v30 - v31;
  v34 = v31;
  v35 = (char *)&dword_446E58 - 1;
  do
    v36 = (v35++)[1];
  while ( v36 );
  memcpy(v35, v34, 4 * (v33 >> 2));
  v38 = (char *)v34 + 4 * (v33 >> 2);
  v37 = &v35[4 * (v33 >> 2)];
  v39 = v33 & 3;
  v40 = (char *)&unk_462DA0 + 15 * configuration.rightSteeringKey;
  memcpy(v37, v38, v39);
  v41 = v40;
  do
    v42 = *v40++;
  while ( v42 );
  v43 = v40 - v41;
  v44 = v41;
  v45 = (char *)&dword_446E8A - 1;
  do
    v46 = (v45++)[1];
  while ( v46 );
  memcpy(v45, v44, 4 * (v43 >> 2));
  v48 = (char *)v44 + 4 * (v43 >> 2);
  v47 = &v45[4 * (v43 >> 2)];
  v49 = v43 & 3;
  v50 = (char *)&unk_462DA0 + 15 * configuration.turboKey;
  memcpy(v47, v48, v49);
  v51 = v50;
  do
    v52 = *v50++;
  while ( v52 );
  v53 = v50 - v51;
  v54 = v51;
  v55 = (char *)&unk_446EBC - 1;
  do
    v56 = (v55++)[1];
  while ( v56 );
  memcpy(v55, v54, 4 * (v53 >> 2));
  v58 = (char *)v54 + 4 * (v53 >> 2);
  v57 = &v55[4 * (v53 >> 2)];
  v59 = v53 & 3;
  v60 = (char *)&unk_462DA0 + 15 * configuration.gunKey;
  memcpy(v57, v58, v59);
  v61 = v60;
  do
    v62 = *v60++;
  while ( v62 );
  v63 = v60 - v61;
  v64 = v61;
  v65 = (char *)&unk_446EEE - 1;
  do
    v66 = (v65++)[1];
  while ( v66 );
  memcpy(v65, v64, 4 * (v63 >> 2));
  v68 = (char *)v64 + 4 * (v63 >> 2);
  v67 = &v65[4 * (v63 >> 2)];
  v69 = v63 & 3;
  v70 = (char *)&unk_462DA0 + 15 * configuration.mineKey;
  memcpy(v67, v68, v69);
  v71 = v70;
  do
    v72 = *v70++;
  while ( v72 );
  v73 = v70 - v71;
  v74 = v71;
  v75 = &byte_446F20[-1];
  do
  {
    v76 = *((BYTE *)v75 + 1);
    v75 = (char *)v75 + 1;
  }
  while ( v76 );
  memcpy(v75, v74, 4 * (v73 >> 2));
  v78 = (char *)v74 + 4 * (v73 >> 2);
  v77 = (char *)v75 + 4 * (v73 >> 2);
  v79 = v73 & 3;
  v80 = (char *)&unk_462DA0 + 15 * configuration.hornKey;
  memcpy(v77, v78, v79);
  v81 = v80;
  do
    v82 = *v80++;
  while ( v82 );
  //TODO fix
  v83 = v80 - (char *)v81;
  v84 = (char *)&unk_446F52 - 1;
  do
    v85 = (v84++)[1];
  while ( v85 );
  memcpy(v84, v81, v83);
  byte_447186 = 0;
  word_447184 = 8224;
  dword_4471B2 = 538976288;
  dword_447180 = 538994036;
  dword_4471AE = 538976357;
  dword_4471E0 = 1699487858;
  dword_4471AA = 1801548354;
  dword_4471DC = 1701147731;
  byte_4471EC = 0;
  word_4471B6 = 32;
  dword_4471E8 = -84271072;
  dword_447216 = 544499815;
  dword_4471E4 = 538997862;
  dword_447212 = 1766989938;
  byte_447222 = 0;
  dword_44720E = 1701147731;
  dword_44721E = -84215046;
  dword_447178 = 1701012289;
  dword_44717C = 1634887020;
  dword_44721A = -84271072;
  memcpy(&unk_447240, word_442A18, 0x18u);
  v86 = configuration.accelerateGamepad;
  *((_WORD *)&unk_447240 + 12) = word_442A18[12];
  memcpy(&unk_447272, word_4429FC, 0x1Au);
  memcpy(byte_4472A4, byte_4429E0, 0x18u);
  v87 = (char *)&unk_45EAC0 + 15 * v86;
  byte_4472A4[24] = byte_4429E0[24];
  v88 = v87;
  do
    v89 = *v87++;
  while ( v89 );
  v90 = v87 - v88;
  v91 = v88;
  v92 = (char *)&dword_447178 - 1;
  do
    v93 = (v92++)[1];
  while ( v93 );
  memcpy(v92, v91, 4 * (v90 >> 2));
  v95 = (char *)v91 + 4 * (v90 >> 2);
  v94 = &v92[4 * (v90 >> 2)];
  v96 = v90 & 3;
  v97 = (char *)&unk_45EAC0 + 15 * configuration.brakeGamepad;
  memcpy(v94, v95, v96);
  v98 = v97;
  do
    v99 = *v97++;
  while ( v99 );
  v100 = v97 - v98;
  v101 = v98;
  v102 = (char *)&dword_4471AA - 1;
  do
    v103 = (v102++)[1];
  while ( v103 );
  memcpy(v102, v101, 4 * (v100 >> 2));
  v105 = (char *)v101 + 4 * (v100 >> 2);
  v104 = &v102[4 * (v100 >> 2)];
  v106 = v100 & 3;
  v107 = (char *)&unk_45EAC0 + 15 * configuration.leftSteeringGamepad;
  memcpy(v104, v105, v106);
  v108 = v107;
  do
    v109 = *v107++;
  while ( v109 );
  v110 = v107 - v108;
  v111 = v108;
  v112 = (char *)&dword_4471DC - 1;
  do
    v113 = (v112++)[1];
  while ( v113 );
  memcpy(v112, v111, 4 * (v110 >> 2));
  v115 = (char *)v111 + 4 * (v110 >> 2);
  v114 = &v112[4 * (v110 >> 2)];
  v116 = v110 & 3;
  v117 = (char *)&unk_45EAC0 + 15 * configuration.rightSteeringGamepad;
  memcpy(v114, v115, v116);
  v118 = v117;
  do
    v119 = *v117++;
  while ( v119 );
  v120 = v117 - v118;
  v121 = v118;
  v122 = (char *)&dword_44720E - 1;
  do
    v123 = (v122++)[1];
  while ( v123 );
  memcpy(v122, v121, 4 * (v120 >> 2));
  v125 = (char *)v121 + 4 * (v120 >> 2);
  v124 = &v122[4 * (v120 >> 2)];
  v126 = v120 & 3;
  v127 = (char *)&unk_45EAC0 + 15 * configuration.turboGamepad;
  memcpy(v124, v125, v126);
  v128 = v127;
  do
    v129 = *v127++;
  while ( v129 );
  v130 = v127 - v128;
  v131 = v128;
  v132 = (char *)&unk_447240 - 1;
  do
    v133 = (v132++)[1];
  while ( v133 );
  memcpy(v132, v131, 4 * (v130 >> 2));
  v135 = (char *)v131 + 4 * (v130 >> 2);
  v134 = &v132[4 * (v130 >> 2)];
  v136 = v130 & 3;
  v137 = (char *)&unk_45EAC0 + 15 * configuration.gunGamepad;
  memcpy(v134, v135, v136);
  v138 = v137;
  do
    v139 = *v137++;
  while ( v139 );
  v140 = v137 - v138;
  v141 = v138;
  v142 = (char *)&unk_447272 - 1;
  do
    v143 = (v142++)[1];
  while ( v143 );
  memcpy(v142, v141, 4 * (v140 >> 2));
  v145 = (char *)v141 + 4 * (v140 >> 2);
  v144 = &v142[4 * (v140 >> 2)];
  v146 = v140 & 3;
  v147 = (char *)&unk_45EAC0 + 15 * configuration.mineGamepad;
  memcpy(v144, v145, v146);
  v148 = v147;
  do
    v149 = *v147++;
  while ( v149 );
  result = v147 - v148;
  v151 = v148;
  v152 = &byte_4472A4[-1];
  do
  {
    v153 = *((BYTE *)v152 + 1);
    v152 = (char *)v152 + 1;
  }
  while ( v153 );
  memcpy(v152, v151, result);
  return result;
}

//----- (0041E3B0) --------------------------------------------------------
char GamepadNotFoundPopup_41E3B0()
{
  loadMenuSoundEffect(1u, 29, 0, configuration.effectsVolume, dword_4451A4);
  memcpy((char *)screenBuffer + 67200, (char *)graphicsGeneral.menubg5Bpk + 67200, 0x28F00u);
  drawMenu(INITIAL_MENU, 0);
  drawMenu(CONFIGURE_MENU, 0);
  createPopup(28, 198, 595, 86, 1);
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "Gamepad not detected!", 133260);
  drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, getLanguageEntry("Press any key to continue."), 153697);
  refreshAllScreen();
  eventDetected();
  sub_418090();
  while ( !eventDetected() )
    waitWithRefresh();
  eventDetected();
  return sub_418090();
}
// 4451A4: using guessed type int dword_4451A4;
// 45DC18: using guessed type int configuration.effectsVolume;

//----- (004284E0) --------------------------------------------------------
signed int sub_4284E0()
{
  // Keys the game keeps for itself: P, Tab, F1-F10, F11, F12 and Esc. The original kept them in
  // consecutive stack bytes and walked them from the first one; here they were not consecutive.
  static const unsigned char reservedKeys[15] = { 25, 15, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 87, 88, 1 };
  signed int v1; // ebp@1
  int v2; // eax@2
  signed int result; // eax@41
  int v4; // eax@42
  char v5; // [sp+13h] [bp-39h]@1
  char v21; // [sp+24h] [bp-28h]@42

  v5 = 0;
  for ( v1 = 0; v1 < 15; ++v1 )
  {
    v2 = reservedKeys[v1];
    if (configuration.accelerateKey == v2
      || configuration.brakeKey == v2
      || configuration.leftSteeringKey == v2
      || configuration.rightSteeringKey == v2
      || configuration.turboKey == v2
      || configuration.gunKey == v2
      || configuration.mineKey == v2
      || configuration.hornKey == v2 )
      v5 = 1;
  }
  if (configuration.accelerateKey == configuration.brakeKey
    || configuration.accelerateKey == configuration.leftSteeringKey
    || configuration.accelerateKey == configuration.rightSteeringKey
    || configuration.accelerateKey == configuration.turboKey
    || configuration.accelerateKey == configuration.gunKey
    || configuration.accelerateKey == configuration.mineKey
    || configuration.accelerateKey == configuration.hornKey
    || configuration.brakeKey == configuration.leftSteeringKey
    || configuration.brakeKey == configuration.rightSteeringKey
    || configuration.brakeKey == configuration.turboKey
    || configuration.brakeKey == configuration.gunKey
    || configuration.brakeKey == configuration.mineKey
    || configuration.brakeKey == configuration.hornKey
    || configuration.leftSteeringKey == configuration.rightSteeringKey
    || configuration.leftSteeringKey == configuration.turboKey
    || configuration.leftSteeringKey == configuration.gunKey
    || configuration.leftSteeringKey == configuration.mineKey
    || configuration.leftSteeringKey == configuration.hornKey
    || configuration.rightSteeringKey == configuration.turboKey
    || configuration.rightSteeringKey == configuration.gunKey
    || configuration.rightSteeringKey == configuration.mineKey
    || configuration.rightSteeringKey == configuration.hornKey
    || configuration.turboKey == configuration.gunKey
    || configuration.turboKey == configuration.mineKey
    || configuration.turboKey == configuration.hornKey
    || configuration.gunKey == configuration.mineKey
    || configuration.gunKey == configuration.hornKey
    || configuration.mineKey == configuration.hornKey
    || v5 == 1 )
  {
    memcpy(dword_461ED8, screenBuffer, 0x4B000u);
    createPopup(26, 194, 595, 86, 1);
    memcpy(&v21, "Invalid key configuration!", 0x1Bu);
    v4 = getBigTextMidSize(&v21);
    drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, &v21, 130242 - v4);
    drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "Press any key to re-enter.", 150495);
    refreshAllScreen();
    loadMenuSoundEffect(1u, 29, 0, configuration.effectsVolume, dword_4451A4);
    eventDetected();
    sub_418090();
    while ( !eventDetected() )
      waitWithRefresh();
    eventDetected();
    sub_418090();
    memcpy(screenBuffer, dword_461ED8, 0x4B000u);
    refreshAllScreen();
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 4451A4: using guessed type int dword_4451A4;
// 45DC18: using guessed type int configuration.effectsVolume;
// 45EA68: using guessed type int configuration.rightSteeringKey;
// 45FBF4: using guessed type int configuration.turboKey;
// 461270: using guessed type int configuration.mineKey;
// 461EA8: using guessed type int configuration.accelerateKey;
// 461FF8: using guessed type int configuration.leftSteeringKey;
// 463CA8: using guessed type int configuration.brakeKey;
// 463CE4: using guessed type int configuration.gunKey;
// 463D18: using guessed type int configuration.hornKe;

//----- (00428740) --------------------------------------------------------
signed int sub_428740()
{
  int v0; // ebp@1
  char v1; // bl@1
  int v2; // eax@15
  int v3; // ecx@24
  int v4; // eax@40
  signed int result; // eax@42
  char v6; // [sp+10h] [bp-28h]@40

  v0 = configuration.turboGamepad;
  v1 = 0;
  if (configuration.accelerateGamepad == (unsigned __int8)byte_456B01 )
    goto LABEL_11;
  if (configuration.accelerateGamepad != configuration.brakeGamepad
    && configuration.accelerateGamepad != configuration.leftSteeringGamepad
    && configuration.accelerateGamepad != configuration.rightSteeringGamepad
    && configuration.accelerateGamepad != configuration.turboGamepad)
  {
    if (configuration.accelerateGamepad != configuration.gunGamepad && configuration.accelerateGamepad != configuration.mineGamepad)
    {
      v0 = configuration.turboGamepad;
      goto LABEL_11;
    }
    v0 = configuration.turboGamepad;
  }
  v1 = 1;
LABEL_11:
  if (configuration.brakeGamepad != (unsigned __int8)byte_456B01 )
  {
    if (configuration.brakeGamepad == configuration.leftSteeringGamepad || configuration.brakeGamepad == configuration.rightSteeringGamepad || configuration.brakeGamepad == v0 )
      goto LABEL_46;
    v2 = configuration.gunGamepad;
    if (configuration.brakeGamepad == configuration.gunGamepad)
    {
LABEL_18:
      v1 = 1;
      goto LABEL_20;
    }
    if (configuration.brakeGamepad == configuration.mineGamepad)
    {
LABEL_46:
      v2 = configuration.gunGamepad;
      goto LABEL_18;
    }
  }
  v2 = configuration.gunGamepad;
LABEL_20:
  if (configuration.leftSteeringGamepad == (unsigned __int8)byte_456B01 )
  {
    v3 = configuration.mineGamepad;
  }
  else if (configuration.leftSteeringGamepad == configuration.rightSteeringGamepad || configuration.leftSteeringGamepad == v0 || configuration.leftSteeringGamepad == v2 )
  {
    v3 = configuration.mineGamepad;
    v1 = 1;
  }
  else
  {
    v3 = configuration.mineGamepad;
    if (configuration.leftSteeringGamepad == configuration.mineGamepad)
      v1 = 1;
  }
  if (configuration.rightSteeringGamepad != (unsigned __int8)byte_456B01 && (configuration.rightSteeringGamepad == v0 || configuration.rightSteeringGamepad == v2 || configuration.rightSteeringGamepad == v3) )
    v1 = 1;
  if ( v0 != (unsigned __int8)byte_456B01 && (v0 == v2 || v0 == v3) )
    v1 = 1;
  if ( (v2 == (unsigned __int8)byte_456B01 || v2 != v3) && v1 != 1 )
  {
    result = 0;
  }
  else
  {
    memcpy(dword_461ED8, screenBuffer, 0x4B000u);
    createPopup(26, 194, 595, 86, 1);
    memcpy(&v6, "Invalid gamepad configuration!", 0x1Fu);
    v4 = getBigTextMidSize(&v6);
    drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, &v6, 130242 - v4);
    drawTextWithFont((int)graphicsGeneral.fbig3aBpk, (int)&bigLetterSpacing_445848, "Press any key to re-enter.", 150495);
    refreshAllScreen();
    loadMenuSoundEffect(1u, 29, 0, configuration.effectsVolume, dword_4451A4);
    eventDetected();
    sub_418090();
    while ( !eventDetected() )
      waitWithRefresh();
    eventDetected();
    sub_418090();
    memcpy(screenBuffer, dword_461ED8, 0x4B000u);
    refreshAllScreen();
    result = 1;
  }
  return result;
}

//----- (0042CBF0) --------------------------------------------------------
char sub_42CBF0()
{
  char v0; // bl@1
  signed int v1; // esi@1
  char v2; // al@20
  char result; // al@25

  v0 = -1;
  byte_456B00 = 1;
  v1 = 0;
  do
  {
    refreshAndCheckConnection_42A570();
    if ( configuration.useJoystick > 0 )
    {
      SDLConfigureJoystick();
      if ( v1 > 15 )
      {
        if ( joystick_x_axis_4A7A44 < joystick_x_axis_default_4AA3E0 - 50 )
          v0 = configuration.defaultLeftSteeringGamepad;
        if ( joystick_x_axis_4A7A44 > joystick_x_axis_default_4AA3E0 + 50 )
          v0 = configuration.defaultRightSteeringGamepad;
        if ( joystick_y_axis_4A9EB8 < joystick_y_axis_default_4A9EA0 - 50 )
          v0 = byte_44512A;
        if ( joystick_y_axis_4A9EB8 > joystick_y_axis_default_4A9EA0 + 50 )
          v0 = configuration.defaultBrakeGamepad;
        if ( byte_463E00[(unsigned __int8)configuration.defaultAccelerateGamepad] )
          v0 = configuration.defaultAccelerateGamepad;
        if ( byte_463E00[(unsigned __int8)configuration.defaultTurboGamepad] )
          v0 = configuration.defaultTurboGamepad;
        if ( byte_463E00[(unsigned __int8)configuration.defaultGunGamepad] )
          v0 = configuration.defaultGunGamepad;
        if ( byte_463E00[(unsigned __int8)configuration.defaultMineGamepad] )
          v0 = configuration.defaultMineGamepad;
      }
    }
    v2 = eventDetected();
    if ( v2 == 28 || v2 == -100 || v2 == 1 )
      v0 = byte_456B01;
    ++v1;
  }
  while ( v0 == -1 );
  result = v0;
  byte_456B00 = 0;
  return result;
}
