#include <SDL_keysym.h>
#include "menu.h"

#include "util/menus.h"

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

__int16 word_4636DF; // weak
__int16 word_446E00 = 8224; // weak


__int16 word_446E32 = 31264; // weak




__int16 word_447184 = 8224; // weak


__int16 word_4471B6 = 31264; // weak


_WORD word_4429FC[14] = //Ma..
{
  24909,  26723,  28265,  8293,  30023,  8302,  64032,  64250,  64250,  64250,  64250,  64250,  250,  0
}; // idb
_WORD word_442A18[14] =
{
  30036,  25202,  8303,  28482,  29551,  8308,  64032,  64250,  64250,  64250,  64250,  64250,  250,  0
}; // idb

_UNKNOWN unk_462DA0; // weak
_UNKNOWN unk_45EAC0; // weak
_UNKNOWN unk_447240; // weak
_UNKNOWN unk_447272; // weak

_UNKNOWN unk_446EEE; // weak

_UNKNOWN unk_446F52; // weak

_UNKNOWN unk_446EBC; // weak
_UNKNOWN unk_4429C0; // weak
char byte_463A09; // weak
int dword_46383B; // weak
int dword_46383F; // weak
int dword_463843; // weak
char byte_463847; // weak
int dword_463859; // weak
int dword_46385D; // weak
int dword_463861; // weak
char byte_463865; // weak
int dword_463868; // weak
int dword_46386C; // weak
int dword_463870; // weak
char byte_463874; // weak
int dword_463949; // weak
int dword_46394D; // weak
int dword_463951; // weak
char byte_463955; // weak
int dword_463958; // weak
int dword_46395C; // weak
int dword_463960; // weak
char byte_463964; // weak
int dword_463967; // weak
int dword_46396B; // weak
int dword_46396F; // weak
char byte_463973; // weak
int dword_463985; // weak
int dword_463989; // weak
int dword_46398D; // weak
char byte_463991; // weak
int dword_4639A3; // weak
int dword_4639A7; // weak
int dword_4639AB; // weak
char byte_4639AF; // weak
int dword_4639C1; // weak
int dword_4639C5; // weak
int dword_4639C9; // weak
char byte_4639CD; // weak
int dword_4639D0; // weak
int dword_4639D4; // weak
int dword_4639D8; // weak
char byte_4639DC; // weak
int dword_4639DF; // weak
int dword_4639E3; // weak
int dword_4639E7; // weak
char byte_4639EB; // weak
int dword_4639EE; // weak
int dword_4639F2; // weak
int dword_4639F6; // weak
char byte_4639FA; // weak
int dword_4639FD; // weak
int dword_463A01; // weak
int dword_463A05; // weak


char byte_46307C; // weak
int dword_46307F; // weak
int dword_463083; // weak
int dword_463087; // weak
char byte_46308B; // weak
int dword_46308E; // weak
int dword_463092; // weak
int dword_463096; // weak
char byte_46309A; // weak
int dword_46309D; // weak
int dword_4630A1; // weak
int dword_4630A5; // weak
char byte_4630A9; // weak
int dword_4630AC; // weak
int dword_4630B0; // weak
int dword_4630B4; // weak
char byte_4630B8; // weak
int dword_4630BB; // weak
int dword_4630BF; // weak
int dword_4630C3; // weak
char byte_4630C7; // weak
int dword_4630CA; // weak
int dword_4630CE; // weak
int dword_4630D2; // weak
char byte_4630D6; // weak
int dword_4630D9; // weak
int dword_4630DD; // weak
int dword_4630E1; // weak
char byte_4630E5; // weak
int dword_4630E8; // weak
int dword_4630EC; // weak
int dword_4630F0; // weak
char byte_4630F4; // weak
int dword_4630F7; // weak
int dword_4630FB; // weak
int dword_4630FF; // weak
char byte_463103; // weak
int dword_463106; // weak
int dword_46310A; // weak
int dword_46310E; // weak
char byte_463112; // weak
int dword_463115; // weak
int dword_463119; // weak
int dword_46311D; // weak
char byte_463121; // weak
int dword_463124; // weak
int dword_463128; // weak
int dword_46312C; // weak
char byte_463130; // weak
int dword_463133; // weak
int dword_463137; // weak
int dword_46313B; // weak
char byte_46313F; // weak
int dword_463142; // weak
int dword_463146; // weak
int dword_46314A; // weak
char byte_46314E; // weak
int dword_463151; // weak
int dword_463155; // weak
int dword_463159; // weak
char byte_46315D; // weak
int dword_463160; // weak
int dword_463164; // weak
int dword_463168; // weak
char byte_46316C; // weak
int dword_46316F; // weak
int dword_463173; // weak
int dword_463177; // weak
char byte_46317B; // weak
int dword_46317E; // weak
int dword_463182; // weak
int dword_463186; // weak
char byte_46318A; // weak
int dword_46318D; // weak
int dword_463191; // weak
int dword_463195; // weak
char byte_463199; // weak
int dword_46319C; // weak
int dword_4631A0; // weak
int dword_4631A4; // weak
char byte_4631A8; // weak
int dword_4631AB; // weak
int dword_4631AF; // weak
int dword_4631B3; // weak
char byte_4631B7; // weak
int dword_4631BA; // weak
int dword_4631BE; // weak
int dword_4631C2; // weak
char byte_4631C6; // weak
int dword_4631C9; // weak
int dword_4631CD; // weak
int dword_4631D1; // weak
char byte_4631D5; // weak
int dword_4631D8; // weak
int dword_4631DC; // weak
int dword_4631E0; // weak
char byte_4631E4; // weak
int dword_4631E7; // weak
int dword_4631EB; // weak
int dword_4631EF; // weak
char byte_4631F3; // weak
int dword_4631F6; // weak
int dword_4631FA; // weak
int dword_4631FE; // weak
char byte_463202; // weak
int dword_463205; // weak
int dword_463209; // weak
int dword_46320D; // weak
char byte_463211; // weak
int dword_463214; // weak
int dword_463218; // weak
int dword_46321C; // weak
char byte_463220; // weak
int dword_463223; // weak
int dword_463227; // weak
int dword_46322B; // weak
char byte_46322F; // weak
int dword_463232; // weak
int dword_463236; // weak
int dword_46323A; // weak
char byte_46323E; // weak
int dword_463241; // weak
int dword_463245; // weak
int dword_463249; // weak
char byte_46324D; // weak
int dword_463250; // weak
int dword_463254; // weak
int dword_463258; // weak
char byte_46325C; // weak
int dword_46325F; // weak
int dword_463263; // weak
int dword_463267; // weak
char byte_46326B; // weak
int dword_46326E; // weak
int dword_463272; // weak
int dword_463276; // weak
char byte_46327A; // weak
int dword_46327D; // weak
int dword_463281; // weak
int dword_463285; // weak
char byte_463289; // weak
int dword_46328C; // weak
int dword_463290; // weak
int dword_463294; // weak
char byte_463298; // weak
int dword_4632B9; // weak
int dword_4632BD; // weak
int dword_4632C1; // weak
char byte_4632C5; // weak
int dword_4632C8; // weak
int dword_4632CC; // weak
int dword_4632D0; // weak
char byte_4632D4; // weak
int dword_4636C4; // weak
int dword_4636C8; // weak
int dword_4636CC; // weak
char byte_4636D0; // weak
int dword_4636D3; // weak
int dword_4636D7; // weak
int dword_4636DB; // weak

char byte_463022; // weak
int dword_463025; // weak
int dword_463029; // weak
int dword_46302D; // weak
char byte_463031; // weak
int dword_463034; // weak
int dword_463038; // weak
int dword_46303C; // weak
char byte_463040; // weak
int dword_463043; // weak
int dword_463047; // weak
int dword_46304B; // weak
char byte_46304F; // weak
int dword_463052; // weak
int dword_463056; // weak
int dword_46305A; // weak
char byte_46305E; // weak
int dword_463061; // weak
int dword_463065; // weak
int dword_463069; // weak
char byte_46306D; // weak
int dword_463070; // weak
int dword_463074; // weak
int dword_463078; // weak
char byte_462FC8; // weak
int dword_462FCB; // weak
int dword_462FCF; // weak
int dword_462FD3; // weak
char byte_462FD7; // weak
int dword_462FDA; // weak
int dword_462FDE; // weak
int dword_462FE2; // weak
char byte_462FE6; // weak
int dword_462FE9; // weak
int dword_462FED; // weak
int dword_462FF1; // weak
char byte_462FF5; // weak
int dword_462FF8; // weak
int dword_462FFC; // weak
int dword_463000; // weak
char byte_463004; // weak
int dword_463007; // weak
int dword_46300B; // weak
int dword_46300F; // weak
char byte_463013; // weak
int dword_463016; // weak
int dword_46301A; // weak
int dword_46301E; // weak
char byte_462F6E; // weak
int dword_462F71; // weak
int dword_462F75; // weak
int dword_462F79; // weak
char byte_462F7D; // weak
int dword_462F80; // weak
int dword_462F84; // weak
int dword_462F88; // weak
char byte_462F8C; // weak
int dword_462F8F; // weak
int dword_462F93; // weak
int dword_462F97; // weak
char byte_462F9B; // weak
int dword_462F9E; // weak
int dword_462FA2; // weak
int dword_462FA6; // weak
char byte_462FAA; // weak
int dword_462FAD; // weak
int dword_462FB1; // weak
int dword_462FB5; // weak
char byte_462FB9; // weak
int dword_462FBC; // weak
int dword_462FC0; // weak
int dword_462FC4; // weak

char byte_462F14; // weak
int dword_462F17; // weak
int dword_462F1B; // weak
int dword_462F1F; // weak
char byte_462F23; // weak
int dword_462F26; // weak
int dword_462F2A; // weak
int dword_462F2E; // weak
char byte_462F32; // weak
int dword_462F35; // weak
int dword_462F39; // weak
int dword_462F3D; // weak
__int16 word_462F41; // weak
int dword_462F44; // weak
int dword_462F48; // weak
int dword_462F4C; // weak
char byte_462F50; // weak
int dword_462F53; // weak
int dword_462F57; // weak
int dword_462F5B; // weak
char byte_462F5F; // weak
int dword_462F62; // weak
int dword_462F66; // weak
int dword_462F6A; // weak


int dword_462EB6; // weak
char byte_462EBA; // weak
int dword_462EBD; // weak
int dword_462EC1; // weak
int dword_462EC5; // weak
char byte_462EC9; // weak
int dword_462ECC; // weak
int dword_462ED0; // weak
int dword_462ED4; // weak
char byte_462ED8; // weak
int dword_462EDB; // weak
int dword_462EDF; // weak
int dword_462EE3; // weak
char byte_462EE7; // weak
int dword_462EEA; // weak
int dword_462EEE; // weak
int dword_462EF2; // weak
char byte_462EF6; // weak
int dword_462EF9; // weak
int dword_462EFD; // weak
int dword_462F01; // weak
char byte_462F05; // weak
int dword_462F08; // weak
int dword_462F0C; // weak
int dword_462F10; // weak
int dword_462E5C; // weak
char byte_462E60; // weak
int dword_462E63; // weak
int dword_462E67; // weak
int dword_462E6B; // weak
char byte_462E6F; // weak
int dword_462E72; // weak
int dword_462E76; // weak
int dword_462E7A; // weak
char byte_462E7E; // weak
int dword_462E81; // weak
int dword_462E85; // weak
int dword_462E89; // weak
char byte_462E8D; // weak
int dword_462E90; // weak
int dword_462E94; // weak
int dword_462E98; // weak
char byte_462E9C; // weak
int dword_462E9F; // weak
int dword_462EA3; // weak
int dword_462EA7; // weak
char byte_462EAB; // weak
int dword_462EAE; // weak
int dword_462EB2; // weak
int dword_462E3A; // weak
int dword_462E3E; // weak
char byte_462E42; // weak
int dword_462E45; // weak
int dword_462E49; // weak
int dword_462E4D; // weak
char byte_462E51; // weak
int dword_462E54; // weak
int dword_462E58; // weak

char byte_462E06; // weak
int dword_462E09; // weak
int dword_462E0D; // weak
int dword_462E11; // weak
char byte_462E15; // weak
int dword_462E18; // weak
int dword_462E1C; // weak
int dword_462E20; // weak
char byte_462E24; // weak
int dword_462E27; // weak
int dword_462E2B; // weak
int dword_462E2F; // weak
char byte_462E33; // weak
int dword_462E36; // weak

int dword_462DDC; // weak
int dword_462DE0; // weak
int dword_462DE4; // weak

int dword_462DEB; // weak
int dword_462DEF; // weak
int dword_462DF3; // weak

int dword_462DFA; // weak
int dword_462DFE; // weak
int dword_462E02; // weak

int dword_462DAF; // weak
int dword_462DB3; // weak
int dword_462DB7; // weak

int dword_462DBE; // weak
int dword_462DC2; // weak
int dword_462DC6; // weak

int dword_462DCD; // weak
int dword_462DD1; // weak
int dword_462DD5; // weak

char byte_462DF7; // weak
char byte_462DE8; // weak
BYTE byte_446F20[50] =  //Drop mine
{
  68,  114,  111,  112,  32,  77,  105,  110,  101,  32,  32,  32,  32,  250,  250,  250,  250,  250,  250,  250,  250,  250,  250,  250,  108,  101,  102,  116,  32,  97,  108,
  116,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}; // idb

char byte_462DBB; // weak
char byte_462DCA; // weak
char byte_462DD9; // weak
int dword_4471DC = 1701147731; // weak
int dword_4471E0 = 1699487858; // weak
int dword_4471E4 = 538997862; // weak
int dword_4471E8 = 4210696224; // weak

int dword_44720E = 1701147731; // weak
int dword_447212 = 1766989938; // weak
int dword_447216 = 544499815; // weak
int dword_44721A = 4210696224; // weak
int dword_44721E = 4210752250; // weak

int dword_4471AA = 1801548354; // weak
int dword_4471AE = 538976357; // weak
int dword_4471B2 = 538976288; // weak
int dword_447178 = 1701012289; // weak
int dword_44717C = 1634887020; // weak
int dword_447180 = 538994036; // weak
int dword_445798 = 9; // weak
int dword_4457B0 = 0; // weak


int dword_446E58 = 1701147731; // weak
int dword_446E5C = 1699487858; // weak
int dword_446E60 = 538997862; // weak
int dword_446E64 = 4210696224; // weak

int dword_446E8A = 1701147731; // weak
int dword_446E8E = 1766989938; // weak
int dword_446E92 = 544499815; // weak
int dword_446E96 = 4210696224; // weak
int dword_446E9A = 4210752250; // weak
int dword_446E26 = 1801548354; // weak
int dword_446E2A = 538976357; // weak
int dword_446E2E = 538976288; // weak
int dword_446DF4 = 1701012289; // weak
int dword_446DF8 = 1634887020; // weak
int dword_446DFC = 538994036; // weak
int dword_4457D0 = 8; // weak
int dword_4457E8 = 0; // weak
int dword_44575C = 0; // weak
int dword_445744 = 6; // weak
BYTE byte_4472A4[156] =
{
  68,  114,  111,  112,  32,  77,  105,  110,  101,  32,  32,  32,  32,  250,  250,  250,  250,  250,  250,  250,  250,  250,
  250,  250,  108,  101,  102,  116,  32,  97,  108,  116,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, 0,  0,  0,  0,  0,  80,  114,  101,  118,  105,  111,  117,  115,  32,  77,  101,  110,  117,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}; // idb


char byte_447222 = 'r'; // weak
char byte_447186 = 'a'; // weak
char byte_446E9E = 'r'; // weak
char byte_446E02 = 'a'; // weak
char byte_446E68 = 'l'; // weak
char byte_4471EC = 'l'; // weak
BYTE byte_4429E0[28] = //drop mines
{
  68,  114,  111,  112,  32,  77,  105,  110,  101,  32,  32,  32,  32,  250,  250,  250,
  250,  250,  250,  250,  250,  250,  250,  250,  0,  0,  0,  0
}; // idb
__int16 word_4470EE = 0; // weak
int gameStarted_456B5C = 0; // weak

int dword_45E1C0; // weak
int dword_456BC8 = 0; // idb
int dword_456A1C = 1; // weak

int dword_44570C = 6; // weak
/*menus sizes*///la entrada 9 es para el menu de continuar
int dword_4456F0[] = { 6,6,8,6,5,8,9,8,8   }; // weak  //entradas del menu
/*menus sizes*///la entrada 9 es para el menu de continuar
int dword_4456F4[] = { 145,0x6d,0x67,0x5f,0xa8,0xe7,0x32,0xd3,0x32   }; // weak
int dword_4456F8[] = { 124,0xab,0x76,0x92,0xc8,0x72,0x5d,0x74,0x71  }; // weak
int dword_4456FC[] = { 28,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c   }; // weak
int dword_445700[] = { 349,0x1a5,0x1af,0x1e5,0x12f,0x17f,0x214,0x14f ,0x214  }; // weak
int dword_445704[] = { 192,0xc0,0xaf,0xc0,0xa10,0xfa,0x160,0xfa,0xfa  }; // weak
int dword_445708[] = { 0,0,2,0,0,0,0,0,0 }; // weak

int dword_4470E2 = 1701736276; // weak
int dword_4470E6 = 1634288672; // weak
int dword_4470EA = 1735289196; // weak

int dword_445188 = 163840; // weak
char byte_45FC10[256]; // weak
char menuaStartANewGame[17] = "Start A New Game"; // weak
char menuaStartANewGam_0[17] = "Start A New Game"; // weak
char menuaStartRacing[13] = "Start Racing"; // weak
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
	key = eventDetected();
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
    switch ( v12 )
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
		 //initDrivers();
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
    &menuaStartRacing[50 * (dword_445708[v1] + 9 * a1)],
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
    &menuaStartRacing[50 * (v9 + v17)],
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
  postRaceMain(2, v25, v26);
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
  char *v6; // edi@25
  char v7; // al@26
  int v8; // eax@27
  char v9; // bl@29
  char v10; // al@33
  signed int v11; // edx@46
  char *v12; // edi@47
  char *v13; // edi@48
  char v14; // al@49
  int v15; // eax@50
  int v17; // eax@62
  int v18; // [sp+10h] [bp-14h]@1
  int v19; // [sp+14h] [bp-10h]@1
  char* DstBuf=malloc(200); // [sp+18h] [bp-Ch]@25

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
          _itoa((unsigned __int64)((double)v18 * 0.78125), DstBuf, 10);
          v6 = (char *)&v19 + 3;
          do
            v7 = (v6++)[1];
          while ( v7 );
         //TODO FIX quitado porque peta *(_WORD *)v6 = 37;
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
          _itoa((unsigned __int64)((double)v19 * 0.78125),DstBuf, 10);
          v13 = (char *)&v19 + 3;
          do
            v14 = (v13++)[1];
          while ( v14 );
          *(_WORD *)v13 = 37;
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
  signed int v9; // eax@1
  signed int v10; // ebx@2
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
  v9 = (signed int)&unk_462DA0;
  do
  {
    v10 = v9;
    *(_DWORD *)v9 = 1447120469;
    *(_DWORD *)(v9 + 4) = 1095518529;
    v9 += 15;
    *(_DWORD *)(v10 + 8) = 541412418;
    *(BYTE *)(v10 + 12) = 0;
  }
  while ( v9 < (signed int)&numberOfLaps );
  dword_462DAF = 543388517;
  dword_462DB3 = 538976288;
  dword_462DB7 = 538976288;
  byte_462DBB = 0;
  dword_462DBE = 538976305;
  dword_462DC2 = 538976288;
  dword_462DC6 = 538976288;
  byte_462DCA = 0;
  dword_462DCD = 538976306;
  dword_462DD1 = 538976288;
  dword_462DD5 = 538976288;
  byte_462DD9 = 0;
  dword_462DDC = 538976307;
  dword_462DE0 = 538976288;
  dword_462DE4 = 538976288;
  byte_462DE8 = 0;
  dword_462DEB = 538976308;
  dword_462DEF = 538976288;
  dword_462DF3 = 538976288;
  byte_462DF7 = 0;
  dword_462DFA = 538976309;
  dword_462DFE = 538976288;
  dword_462E02 = 538976288;
  byte_462E06 = 0;
  dword_462E09 = 538976310;
  dword_462E0D = 538976288;
  dword_462E11 = 538976288;
  byte_462E15 = 0;
  dword_462E18 = 538976311;
  dword_462E1C = 538976288;
  dword_462E20 = 538976288;
  byte_462E24 = 0;
  dword_462E27 = 538976312;
  dword_462E2B = 538976288;
  dword_462E2F = 538976288;
  byte_462E33 = 0;
  dword_462E36 = 538976313;
  dword_462E3A = 538976288;
  dword_462E3E = 538976288;
  byte_462E42 = 0;
  dword_462E45 = 538976304;
  dword_462E49 = 538976288;
  dword_462E4D = 538976288;
  byte_462E51 = 0;
  dword_462E54 = 1970170221;
  dword_462E58 = 538976371;
  dword_462E5C = 538976288;
  byte_462E60 = 0;
  dword_462E63 = 1635086693;
  dword_462E67 = 538976364;
  dword_462E6B = 538976288;
  byte_462E6F = 0;
  dword_462E72 = 1801675106;
  dword_462E76 = 1667330163;
  dword_462E7A = 538976357;
  byte_462E7E = 0;
  dword_462E81 = 543318388;
  dword_462E85 = 538976288;
  dword_462E89 = 538976288;
  byte_462E8D = 0;
  dword_462E90 = 538976369;
  dword_462E94 = 538976288;
  dword_462E98 = 538976288;
  byte_462E9C = 0;
  dword_462E9F = 538976375;
  dword_462EA3 = 538976288;
  dword_462EA7 = 538976288;
  byte_462EAB = 0;
  dword_462EAE = 538976357;
  dword_462EB2 = 538976288;
  dword_462EB6 = 538976288;
  byte_462EBA = 0;
  dword_462EBD = 538976370;
  dword_462EC1 = 538976288;
  dword_462EC5 = 538976288;
  byte_462EC9 = 0;
  dword_462ECC = 538976372;
  dword_462ED0 = 538976288;
  dword_462ED4 = 538976288;
  byte_462ED8 = 0;
  dword_462EDB = 538976377;
  dword_462EDF = 538976288;
  dword_462EE3 = 538976288;
  byte_462EE7 = 0;
  dword_462EEA = 538976373;
  dword_462EEE = 538976288;
  dword_462EF2 = 538976288;
  byte_462EF6 = 0;
  dword_462EF9 = 538976361;
  dword_462EFD = 538976288;
  dword_462F01 = 538976288;
  byte_462F05 = 0;
  dword_462F08 = 538976367;
  dword_462F0C = 538976288;
  dword_462F10 = 538976288;
  byte_462F14 = 0;
  dword_462F17 = 538976368;
  dword_462F1B = 538976288;
  dword_462F1F = 538976288;
  byte_462F23 = 0;
  dword_462F26 = 1952867692;
  dword_462F2A = 1634886176;
  dword_462F2E = 1952803683;
  byte_462F32 = 0;
  dword_462F35 = 1751607666;
  dword_462F39 = 1919033460;
  dword_462F3D = 1701536609;
  word_462F41 = 116;
  dword_462F44 = 1702129253;
  dword_462F48 = 538976370;
  dword_462F4C = 538976288;
  byte_462F50 = 0;
  dword_462F53 = 1952867692;
  dword_462F57 = 1852793632;
  dword_462F5B = 1819243124;
  byte_462F5F = 0;
  dword_462F62 = 538976353;
  dword_462F66 = 538976288;
  dword_462F6A = 538976288;
  byte_462F6E = 0;
  dword_462F71 = 538976371;
  dword_462F75 = 538976288;
  dword_462F79 = 538976288;
  byte_462F7D = 0;
  dword_462F80 = 538976356;
  dword_462F84 = 538976288;
  dword_462F88 = 538976288;
  byte_462F8C = 0;
  dword_462F8F = 538976358;
  dword_462F93 = 538976288;
  dword_462F97 = 538976288;
  byte_462F9B = 0;
  dword_462F9E = 538976359;
  dword_462FA2 = 538976288;
  dword_462FA6 = 538976288;
  byte_462FAA = 0;
  dword_462FAD = 538976360;
  dword_462FB1 = 538976288;
  dword_462FB5 = 538976288;
  byte_462FB9 = 0;
  dword_462FBC = 538976362;
  dword_462FC0 = 538976288;
  dword_462FC4 = 538976288;
  byte_462FC8 = 0;
  dword_462FCB = 538976363;
  dword_462FCF = 538976288;
  dword_462FD3 = 538976288;
  byte_462FD7 = 0;
  dword_462FDA = 538976364;
  dword_462FDE = 538976288;
  dword_462FE2 = 538976288;
  byte_462FE6 = 0;
  dword_462FE9 = 1768777075;
  dword_462FED = 1869377379;
  dword_462FF1 = 538976366;
  byte_462FF5 = 0;
  dword_462FF8 = 1801677172;
  dword_462FFC = 538976288;
  dword_463000 = 538976288;
  byte_463004 = 0;
  dword_463007 = 1936683105;
  dword_46300B = 1886351988;
  dword_46300F = 538994024;
  byte_463013 = 0;
  dword_463016 = 1952867692;
  dword_46301A = 1768452896;
  dword_46301E = 538997862;
  byte_463022 = 0;
  dword_463025 = 1801675106;
  dword_463029 = 1935764595;
  dword_46302D = 538976360;
  byte_463031 = 0;
  dword_463034 = 538976378;
  dword_463038 = 538976288;
  dword_46303C = 538976288;
  byte_463040 = 0;
  dword_463043 = 538976376;
  dword_463047 = 538976288;
  dword_46304B = 538976288;
  byte_46304F = 0;
  dword_463052 = 538976355;
  dword_463056 = 538976288;
  dword_46305A = 538976288;
  byte_46305E = 0;
  dword_463061 = 538976374;
  dword_463065 = 538976288;
  dword_463069 = 538976288;
  byte_46306D = 0;
  dword_463070 = 538976354;
  dword_463074 = 538976288;
  dword_463078 = 538976288;
  byte_46307C = 0;
  dword_46307F = 538976366;
  dword_463083 = 538976288;
  dword_463087 = 538976288;
  byte_46308B = 0;
  dword_46308E = 538976365;
  dword_463092 = 538976288;
  dword_463096 = 538976288;
  byte_46309A = 0;
  dword_46309D = 1835888483;
  dword_4630A1 = 538976353;
  dword_4630A5 = 538976288;
  byte_4630A9 = 0;
  dword_4630AC = 1769104752;
  dword_4630B0 = 538993775;
  dword_4630B4 = 538976288;
  byte_4630B8 = 0;
  dword_4630BB = 1935764595;
  dword_4630BF = 538976360;
  dword_4630C3 = 538976288;
  byte_4630C7 = 0;
  dword_4630CA = 1751607666;
  dword_4630CE = 1752375412;
  dword_4630D2 = 544499305;
  byte_4630D6 = 0;
  dword_4630D9 = 1887004011;
  dword_4630DD = 1932354657;
  dword_4630E1 = 544366964;
  byte_4630E5 = 0;
  dword_4630E8 = 1952867692;
  dword_4630EC = 1953259808;
  dword_4630F0 = 538976288;
  byte_4630F4 = 0;
  dword_4630F7 = 1667330163;
  dword_4630FB = 538976357;
  dword_4630FF = 538976288;
  byte_463103 = 0;
  dword_463106 = 1936744803;
  dword_46310A = 1801678700;
  dword_46310E = 538976288;
  byte_463112 = 0;
  dword_463115 = 538980710;
  dword_463119 = 538976288;
  dword_46311D = 538976288;
  byte_463121 = 0;
  dword_463124 = 538980966;
  dword_463128 = 538976288;
  dword_46312C = 538976288;
  byte_463130 = 0;
  dword_463133 = 538981222;
  dword_463137 = 538976288;
  dword_46313B = 538976288;
  byte_46313F = 0;
  dword_463142 = 538981478;
  dword_463146 = 538976288;
  dword_46314A = 538976288;
  byte_46314E = 0;
  dword_463151 = 538981734;
  dword_463155 = 538976288;
  dword_463159 = 538976288;
  byte_46315D = 0;
  dword_463160 = 538981990;
  dword_463164 = 538976288;
  dword_463168 = 538976288;
  byte_46316C = 0;
  dword_46316F = 538982246;
  dword_463173 = 538976288;
  dword_463177 = 538976288;
  byte_46317B = 0;
  dword_46317E = 538982502;
  dword_463182 = 538976288;
  dword_463186 = 538976288;
  byte_46318A = 0;
  dword_46318D = 538982758;
  dword_463191 = 538976288;
  dword_463195 = 538976288;
  byte_463199 = 0;
  dword_46319C = 540029286;
  dword_4631A0 = 538976288;
  dword_4631A4 = 538976288;
  byte_4631A8 = 0;
  dword_4631AB = 1819112814;
  dword_4631AF = 543908719;
  dword_4631B3 = 538976288;
  byte_4631B7 = 0;
  dword_4631BA = 1869767539;
  dword_4631BE = 1869376620;
  dword_4631C2 = 538995555;
  byte_4631C6 = 0;
  dword_4631C9 = 1887004011;
  dword_4631CD = 925721697;
  dword_4631D1 = 538976288;
  byte_4631D5 = 0;
  dword_4631D8 = 1887004011;
  dword_4631DC = 942498913;
  dword_4631E0 = 538976288;
  byte_4631E4 = 0;
  dword_4631E7 = 1887004011;
  dword_4631EB = 959276129;
  dword_4631EF = 538976288;
  byte_4631F3 = 0;
  dword_4631F6 = 1887004011;
  dword_4631FA = 1831691361;
  dword_4631FE = 1937075817;
  byte_463202 = 0;
  dword_463205 = 1887004011;
  dword_463209 = 875390049;
  dword_46320D = 538976288;
  byte_463211 = 0;
  dword_463214 = 1887004011;
  dword_463218 = 892167265;
  dword_46321C = 538976288;
  byte_463220 = 0;
  dword_463223 = 1887004011;
  dword_463227 = 908944481;
  dword_46322B = 538976288;
  byte_46322F = 0;
  dword_463232 = 1887004011;
  dword_463236 = 1882023009;
  dword_46323A = 544437612;
  byte_46323E = 0;
  dword_463241 = 1887004011;
  dword_463245 = 825058401;
  dword_463249 = 538976288;
  byte_46324D = 0;
  dword_463250 = 1887004011;
  dword_463254 = 841835617;
  dword_463258 = 538976288;
  byte_46325C = 0;
  dword_46325F = 1887004011;
  dword_463263 = 858612833;
  dword_463267 = 538976288;
  byte_46326B = 0;
  dword_46326E = 1887004011;
  dword_463272 = 808281185;
  dword_463276 = 538976288;
  byte_46327A = 0;
  dword_46327D = 1887004011;
  dword_463281 = 1680696417;
  dword_463285 = 538995813;
  byte_463289 = 0;
  dword_46328C = 1920170355;
  dword_463290 = 538997093;
  dword_463294 = 538976288;
  byte_463298 = 0;
  dword_4632B9 = 540094822;
  dword_4632BD = 538976288;
  dword_4632C1 = 538976288;
  byte_4632C5 = 0;
  dword_4632C8 = 540160358;
  dword_4632CC = 538976288;
  dword_4632D0 = 538976288;
  byte_4632D4 = 0;
  dword_4636C4 = 1887004011;
  dword_4636C8 = 1697473633;
  dword_4636CC = 1919251566;
  byte_4636D0 = 0;
  dword_4636D3 = 1751607666;
  dword_4636D7 = 1868767348;
  dword_4636DB = 1869771886;
  word_4636DF = 108;
  dword_46383B = 1887004011;
  dword_46383F = 1932354657;
  dword_463843 = 1752392044;
  byte_463847 = 0;
  dword_463859 = 1852404336;
  dword_46385D = 1919120244;
  dword_463861 = 538976288;
  byte_463865 = 0;
  dword_463868 = 1751607666;
  dword_46386C = 1818304628;
  dword_463870 = 538976372;
  byte_463874 = 0;
  dword_463949 = 1701670760;
  dword_46394D = 538976288;
  dword_463951 = 538976288;
  byte_463955 = 0;
  dword_463958 = 1629515893;
  dword_46395C = 2003792498;
  dword_463960 = 538976288;
  byte_463964 = 0;
  dword_463967 = 1701273968;
  dword_46396B = 544240928;
  dword_46396F = 538976288;
  byte_463973 = 0;
  dword_463985 = 1952867692;
  dword_463989 = 1920098592;
  dword_46398D = 538998639;
  byte_463991 = 0;
  dword_4639A3 = 1751607666;
  dword_4639A7 = 1918967924;
  dword_4639AB = 544698226;
  byte_4639AF = 0;
  dword_4639C1 = 543452773;
  dword_4639C5 = 538976288;
  dword_4639C9 = 538976288;
  byte_4639CD = 0;
  dword_4639D0 = 1853321060;
  dword_4639D4 = 1920098592;
  dword_4639D8 = 538998639;
  byte_4639DC = 0;
  dword_4639DF = 1701273968;
  dword_4639E3 = 2003788832;
  dword_4639E7 = 538976366;
  byte_4639EB = 0;
  dword_4639EE = 544435817;
  dword_4639F2 = 538976288;
  dword_4639F6 = 538976288;
  byte_4639FA = 0;
  dword_4639FD = 543974756;
  dword_463A01 = 538976288;
  dword_463A05 = 538976288;
  byte_463A09 = 0;
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
  char *v0; // edx@1
  signed int v1; // ebp@1
  int v2; // eax@2
  signed int result; // eax@41
  int v4; // eax@42
  char v5; // [sp+13h] [bp-39h]@1
  char v6; // [sp+14h] [bp-38h]@1
  char v7; // [sp+15h] [bp-37h]@1
  char v8; // [sp+16h] [bp-36h]@1
  char v9; // [sp+17h] [bp-35h]@1
  char v10; // [sp+18h] [bp-34h]@1
  char v11; // [sp+19h] [bp-33h]@1
  char v12; // [sp+1Ah] [bp-32h]@1
  char v13; // [sp+1Bh] [bp-31h]@1
  char v14; // [sp+1Ch] [bp-30h]@1
  char v15; // [sp+1Dh] [bp-2Fh]@1
  char v16; // [sp+1Eh] [bp-2Eh]@1
  char v17; // [sp+1Fh] [bp-2Dh]@1
  char v18; // [sp+20h] [bp-2Ch]@1
  char v19; // [sp+21h] [bp-2Bh]@1
  char v20; // [sp+22h] [bp-2Ah]@1
  char v21; // [sp+24h] [bp-28h]@42

  v6 = 25;
  v7 = 15;
  v8 = 59;
  v9 = 60;
  v10 = 61;
  v11 = 62;
  v12 = 63;
  v13 = 64;
  v14 = 65;
  v15 = 66;
  v16 = 67;
  v17 = 68;
  v18 = 87;
  v19 = 88;
  v20 = 1;
  v5 = 0;
  v0 = &v6;
  v1 = 15;
  do
  {
    v2 = (unsigned __int8)*v0;
    if (configuration.accelerateKey == v2
      || configuration.brakeKey == v2
      || configuration.leftSteeringKey == v2
      || configuration.rightSteeringKey == v2
      || configuration.turboKey == v2
      || configuration.gunKey == v2
      || configuration.mineKey == v2
      || configuration.hornKey == v2 )
      v5 = 1;
    ++v0;
    --v1;
  }
  while ( v1 );
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
