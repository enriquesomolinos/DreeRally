
#include <SDL.h>
#include <SDL_joystick.h>
#ifndef PORTABILITY
  #include "portability/portability.h"
	#include <SDL_opengl.h>
#endif

#include <math.h>

#include "race/anim.h"

#include "ui/mainScreen.h"
#include "ui/startGameScreen.h"
#include "ui/endGameScreen.h"
#include "ui/creditsScreen.h"
#include "ui/prevRaceScreen.h"
#include "ui/raceResultsScreen.h"
#include "ui/shopScreen.h"
#include "asset/bpaUtil.h"
#include "menus.h"
#include "imageUtil.h"
#include "dr.h"
#include "graphics.h"
#include "raceResults.h"
#include "race/pedestrian.h"
#include "defs.h"
#include "race/powerup.h"
#include "sfx/sound.h"
#include "race/terrain.h"
#include "race/3dSystem.h"
#include "i18n/i18n.h"

#include "i18n/i18n.h"
#include "mod/mod.h"

#include "config.h"

#include "cars.h"
#include "drivers.h"
#include "circuit.h"
#include "variables.h"

#include "popup/popup.h"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "savegame.h"
#include "raceParticipant.h"
#include "soundEffects.h"
#include "ui/hallOfFame.h"
#include "ui/blackMarketScreen.h"
#include "dr.h"

#include <string.h>

//-------------------------------------------------------------------------
// Function declarations

int debug=1;
void *Memory;
const int INITIAL_MONEY=495; ///cambiar a 495

//char letterSpacing_4458B0 = '\x10'; // weak

//int screenSurface; // weak

int palette[256]; // weak //dword_45E600
SDL_Surface * screenSurface; // weak

int dword_45F054; // idb
int dword_45F050; // idb

char byte_462D50=2; // weak
float arrayDamageMultiplier[7] ={0.2,0.35,0.5,0.65,0.8,0.95,0.95}; 
   
__int16 word_461ED4; // weak
#define ADS 256;

#define __thiscall   // Test compile in C mode

int drawTransparentBlock(int a1, int a2, int a3, int a4);

int initParticipantValues_401060();
void   allocateMemory(size_t Size);
void   free(void *Memory);

int updateRacePositions();
int sub_4022A0();
unsigned int showEndRaceFlag_402490();
unsigned int   writeTextInRace_402510(int a1, const char *a2);
int   drawSprite_402590(int a1, int a2, int a3, signed int a4, int a5, int a6, int a7, int a8);

//void   __noreturn errorExitScreen(int a1);

signed int loadCircuitPalette();
void loadCircuitImages1();
int loadCarsImages();
void parseCircuitSceFile_403190();
int loadCircuitTabFiles();
int loadCircuitDatFiles();
void loadCircuitShadows();
void loadEngineGraphics();
void loadEngineGraphics2();

int noMemExitScreen();
char *sub_404730();
int drawToBlackScreen();
int setCircuitPalette_4B4020();
int setCircuitPaletteBis_4B4020();
int setCircuitPaletteTransitionToBlack_4B4020();
int setCircuitPaletteTransitionToOriginal_4B4020();
int sub_404C30();
int sub_405430();
int sub_4055A0();
char drawRacepopupEffect_406100();
int sub_406330();
unsigned int   drawTextInRaceScreen(int a1, int a2, const char *a3);
signed int   racePauseMenu_4064A0(int a1);

unsigned int   drawInRaceMenuText_4072C0(int a1, const char *a2);
int keyMenuInRace_407330();
void __noreturn exitCtrlAltDel();
int makeSnapshot_4092B0();
int generateBigPowerUps();
int initRaceValues_409A90();
signed int loadCircuitInfFile();
unsigned __int64   setCircuitPaletteValues(int a1, float a2, float a3, float a4);
int *initRaceValues_409F90();
int processSceFile_40A360();
int calculateSceTextureStructure_40A880();
int calculateCircuitReversed_40A9A0();
int calculateIAMovements_40AFC0();
int balanceIAEngineInRace_40B920(void);
void calculateUserMovements_40BAB0();
int recalculateRaceCarWithOrientation();
int recalculateCircuitImageOffset_40D560();
void recalculatePolygonsInScreeenPosition_40D6B0();
int drawShadows_40D7B0();
int drawCarInRace_40D920();
int shotAction_40E180();
int drawGunFlames_40E960();
int drawShots_40EBC0();
// int __usercall showSmoke_40F070@<eax>(int result@<eax>);
int drawRocket_40F450();
int drawMine_40F6A0();
int drawExplosion_40FE20();
void powerUpTaken_410050();
int generatePowerUps();
char getRacePowerUps_410B90();
int killPedestrian_410FA0();
//char drawShotPedestrian_4111F0();
int sub_411530();
int   sub_4115C0(int a1, int a2);
void draw3dElements_4116D0();
int recalculateCarBoundary_411D10();
int checkVaiZones_412DF0();
void refreshRacePositions_413300();
int recalculateRacePositions_413380();
int sub_413500();
signed int checkPokes_4136C0();
void sub_4138A0();
// int __usercall drawSmallLeftBar_413C90@<eax>(int a1@<ebx>);
// int __usercall drawSmallLeftBar_414110@<eax>(int a1@<ebx>);
int drawLeftRaceBar_414220();
int drawDebugInfo();
int raceSemaphore_414FC0 ();
void loadRaceImagesHUD();

int sub_4156B0();
void   startRace(int a1, int a2);

int configJoystick(void); // weak
char eventDetected();
char sub_418090();
int transformJoystickReadValue_418150();

int   setPaletteValueWithFloats(float, float, float); // idb
int   sub_418B00(float, float, float); // idb

int   loadPaletteMenu();
signed int isVesaCompatible();
void refreshBottomScreen();
void refreshAllScreen();

char drawBottomMenuText();
char sub_41E8D0();

int   sub_41ED20(float, float, float); // idb
void loadGraphics3();
void freeMemoryGraphics3();

int drawCarRightSide();

int   sub_421980(int a1, int a2, int a3, int a4);

signed int   hasInsuficientMoneyToBuy(int a1);

int sub_4220D0();
signed int autoLoadSave();
int sub_4224E0();
int copyPalette1toPalette(void); // weak

int   sub_423C90(int a1, int a2);
void   recalcRank(int a1);

int   sub_424510(int a1, int a2, int a3);

signed int drawCircuitPreviewImage();

int   sub_426460(unsigned __int8 a1, unsigned __int8 a2);

int transitionToCurrentImage();
int transitionToBlack();


//int checkIntro(void); // weak

int   sub_429CF0(unsigned __int8 *a1, signed int a2);
int makeSnapshot_429DC0();
void __noreturn exitGame();

int sub_42A480();
void refreshAndCheckConnection_42A570();

char sub_42C4A0();
char   sub_42C560(int a1);

char drawPopupCursor_42C780 ();
int   sub_42C7F0(int a1, int a2, int a3, int a4, int a5, int a6);



signed int   readKeyboard(const char *a1, int a2, int a3, int a4, unsigned int a5, signed int a6, int a7, int a8, int a9);


void showEndAnim_4312D0();

// int __usercall adversaryPreviewScreen@<eax>(const char **a1@<ebx>);

void __noreturn exitGame_43ACB0();

int   sub_43AE80(int a1, int a2, int a3, int a4);
char   drawCarSprite_43AEC0(int a1, int a2, int a3);
//char   drawPedestrian_43AF30(int a1, int a2, int a3);

char   drawCarFire_43AFC0(int a1, int a2, int a3);
int   sub_43B030(int a1, int a2);
int   sub_43B050(int a1, signed int a2);
int   sub_43B080(int a1, int a2, int a3, int a4, int a5);
void   copyBuffer2Screen(void *a1, const void *a2, int a3);
int   extractBits(int a1, signed int a2, int a3);
int   drawInRaceImageToBuffer_43B160(int a1, int a2, int a3, int a4);
int   drawRaceCharInMenu_43B1A0(int a1, int a2, int a3, int a4);
int   drawCharInRaceScreen(int a1, int a2, int a3, int a4);
int   drawImageInRace_43B240(int a1, int a2, int a3, int a4);
int   colorToPaletteEntry(int a1, signed int a2);
 int   convertColorToPaletteColor(int a1, int a2);
int sub_43B2D0();
int sub_43B2E0();
int   draw3dTexture_43B2F0(int a1, int a2, int a3, int textureId);
int   sub_43B370(int a1, int a2, int a3);
int   drawTurboBar_43B3A0(int a1, int a2, int a3, char a4);
 void   SetVideoMode(int fullScreen);
int   refreshScreen(int a1);
int   setWindowCaption3(int a1);
int setWindowCaption2();
int setWindowCaption();
int setRaceWindowCaption();
 int  drawWeaponsBar_43BEF0(int a1, void *a2, unsigned int a3, int a4, char a5);

int   sub_43BFE0(int a1, int a2);
int   setPaletteValue(int a1, int a2, int a3, int a4);
int   setPaletteAndGetValue(unsigned __int8 a1, unsigned __int8 a2, char a3, unsigned __int8 a4);
int   regenerateRacePalette(int a1);
int   generateSnapshotData_43C160(int a1);

#ifndef PORTABILITY

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

#endif

#ifdef PORTABILITY

int main( int argc, char* argv[] );

#endif

int   sub_43C450(int a1);
__int16   convert320to320_43C470(int a1, int a2);
__int16   conver512to320_43C490(int a1, int a2);
int sub_43C4B0();
//void   operator delete(size_t Size); 
void   free(void *Memory);
void   logJoystickClose();
// int __usercall inicializeScreen@<eax>(double a1@<st0>);
signed int SDLCheckJoystick();
void   nullsub_1();
void removeBackgroundRefreshFunction_43C730();
signed __int64 recalculateSDLTicks_43C740();
int refreshScreenWithDelay();
int (*  setBackgroundRefreshFunction_43C7B0(int (*a1)(void)))(void);
int   updateScreenPtr(int a1);
int   sub_43C7E0(int a1, int a2, int a3, signed int a4, char a5);
int refreshOrExecuteBackgroundFunction_43C850(void); // weak
int callRefreshOrExecuteBackgroundFunction_43C8F0();
SDL_Joystick * SDLConfigureJoystick();
void   decryptTexture(int a1, int a2, int a3, int a4);
void   copyImageToBuffer(int a1, int a2);
unsigned int waitTwoSeconsAndExecFunc_43CBB0();
int   setTriangleValue_43CD50(int a1, int a2, int a3, int a4, int a5, int a6, char a7);
int   sub_43D050(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
int   iluminateTriangle_43D530(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
int waitWithRefresh();

void sub_43FC72();
void   sub_43FCB6();
int sub_43FD12();
// int __usercall initSystem@<eax>(double st7_0@<st0>, int a1, const char **a2);
int   logError(int a1, int a2);
int outOfMemoryError(void); // weak
void   SDL_Quit();
void   generateExitError();

#ifndef PORTABILITY
int   sub_43FF90(int *a1, int a2);
#endif
//-------------------------------------------------------------------------
// Data declarations

  FILE iob[1024];
  const unsigned __int16 pctype[256];
  int _mb_cur_max;
char dukeNukemName[12] = "DUKE NUKEM"; // weak //DUKE



char a12000[7] = "$12000"; // weak
char a750[5] = "$750"; // weak
//int dword_443798 = 1768841587; // weak
char dword_443798[10] = "SANIM.haf"; // weak //cambiado porque es este el nombre del fichero
char aStartANewGame[17] = "Start A New Game"; // weak
char aIswaitingForYo[43] = " is waiting for you to join the next race.";
int dword_443C34 = 1633971813; // weak
BYTE unk_443C40[] = { 0x7f,0,0,0 }; // weak
//_UNKNOWN unk_443C40; // weak

int initialVelocity = 55; // idb
int dword_443FB8 = 1633971813; // weak

char aCRemedyEnterta[57] = "    (c)Remedy Entertainment - http://www.remedygames.com"; // weak

_UNKNOWN unk_444540; // weak
_UNKNOWN unk_444548; // weak
int raceEffectiveWidth_445010 = 320; // weak
int raceEffectiveHalfWidth_445014 = 100; // weak
int raceEffectiveHeight_445018 = 200; // weak
int raceEffectiveHalfHeight_44501C = 100; // weak
int raceMusicEnabled_445020 = 1; // weak
int raceEffectsEnabled_445024 = 1; // weak
int raceShowLeftPanel_445028 = 1; // weak
int raceShowTextures_44502C = 1; // weak
int raceShowShadows_445030 = 1; // weak
int dword_445034 = 163840; // weak

/*char dword_4A9160[]= { '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
					'\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
					'\x0','\x0','\x0','\x0','\x0','\x0','\x0E','\x0A','\x0','\x0','\x0','\x0','\x0D','\x8','\x0','\x0',
					'\x0','\x0','\x0D','\x8','\x0','\x0','\x0','\x0','\x7','\x5','\x0','\x0','\x0','\x0','\x0E','\x8'
				 };*/
/***contiene los nomrbe de los coches para los ficheros bpk*/

//char aKupla[6] = "KUPLA"; // weak

int dword_44509C = 1063675494; // weak
int dword_4450A0 = 1065353216; // weak
_UNKNOWN unk_4450A8; // weak

char byte_44512A = '\x03'; // weak

int dword_44518C = 152832; // weak
int dword_445190 = 163840; // weak
int dword_445194 = 163840; // weak
int dword_445198 = 163840; // weak
int dword_4451A0 = 163840; // weak
int dword_4451A4 = 163840; // weak

//_UNKNOWN unk_4455B0; // weak

int useWeapons = 1; // weak
int dword_4456E8 = 10000; // weak

int dword_445724 = 0; // weak
int dword_445740 = 2; // weak





//contiene para cada menu de 9 posiciones si esta activa o no la entrada
char byte_4457EF[] = { '\0' }; // weak

			
//char menuActive_4457F0[] = { '\x01' }; // weak

//todo esto sobra pero hay referencias que tunear
//char byte_4457F1 = '\0'; // weak
//char byte_4457F9[] = { '\x01' }; // weak
//char byte_4457FA = '\0'; // weak
//char byte_4457FB = '\0'; // weak
//char byte_4457FD = '\0'; // weak
//char byte_445802 = '\0'; // weak 18
//char byte_445803 = '\0'; // weak
//char byte_445804 = '\x01'; // weak 20
///char byte_445805 = '\x01'; // weak
//char byte_445806 = '\x01'; // weak
//char byte_445807 = '\x01'; // weak
//char byte_445808 = '\x01'; // weak//24
//char byte_44580B[] = { '\x01' }; // weak ///27  10 es 32, 1a 42,1d 45
//char byte_44581D[] = { '\x01' }; // weak 
//char byte_445826[] = { '\x01' }; // weak 20 es 48  26 54
char byte_44582A[] = { '\x01' }; // weak //2a es 58
//char byte_445838[] = { '\x01' }; // weak //38 es 72

//char byte_4458B1 = '\x10'; // weak
//char byte_4458E7[] = { '\v' }; // weak
//char byte_44590A[] = { '\n' }; // weak
//char byte_445911 = '\v'; // weak
//char byte_445914 = '\x10'; // weak
//char byte_445915 = '\r'; // weak
//char byte_445916 = '\x0E'; // weak

// esto sirve para hall of fame_UNKNOWN unk_445928; // weak
char aStartRacing[13] = "Start Racing"; // weak

char aStartANewGam_0[17] = "Start A New Game"; // weak
int dword_4466EC = 1953066569; // weak//Init
int dword_4466F0 = 1768710505; // weak
int dword_4466F4 = 1092642170; // weak
int dword_4466F8 = 2003127840; // weak
int dword_4466FC = 1835091744; // weak
__int16 word_446700 = 101; // weak
int dword_44671E = 1852403530; // weak
int dword_446722 = 544096544; // weak
int dword_446726 = 1936291909; // weak
int dword_44672A = 1735289204; // weak
int dword_44672E = 1835091744; // weak
__int16 word_446732 = 101; // weak
int dword_446782 = 1769104723; // weak
int dword_446786 = 1126198369; // weak
int dword_44678A = 1701736047; // weak
int dword_44678E = 1869182051; // weak
__int16 word_446792 = 110; // weak
int dword_4467B4 = 1818323268; // weak
int dword_4467B8 = 1685015840; // weak
__int16 word_4467BC = 28005; // weak
char byte_4467BE = '\0'; // weak
int dword_4467E6 = 2004053569; // weak
int dword_4467EA = 1293972069; // weak
int dword_4467EE = 1835361391; // weak
char byte_4467F2 = '\0'; // weak
char aGamepadDisable[17] = "Gamepad Disabled"; // weak

int dword_4A7DC0;//este no venia
int dword_4A7DBC;//este no venia
//_UNKNOWN unk_446DC2; // weak



//aqui empiezan los datos de los coches :)



int dword_44E5F0[] = { 1 }; // weak
int dword_44E5F4[] = { 2 }; // weak
int dword_44E5F8[] = { 1 }; // weak
int dword_44E5FC = 1000; // idb
int dword_44E600 = 0; // idb
int dword_44E60C = 500; // idb
int dword_44E610 = 1000; // idb
int dword_44E61C = 200; // idb
int dword_44E620 = 0; // idb
int dword_44E62C[] = { 45 }; // weak

///hasta aqui son datos de los coches :)

//int dword_44DF5C[440 * 6];
//int dword_44DF5C = 500; // idb //puntero al precio del coche +440 para el siguiente

char byte_456618[] = { 'A' }; // weak
char byte_45665E[] = { 'S' }; // weak
char byte_4566A4[] = { 'f' }; // weak
char byte_4566EA[] = { 'k' }; // weak
int dword_456730 = 1; // weak

char byte_45673D = '\a'; // weak
char byte_45673E[] = { '\x05' }; // weak
char byte_45673F = '\x03'; // weak
char byte_456741[] = { '\x02' }; // weak
int dword_456754 = 511; // weak
int raceDrivers_456758 = 2; // idb

/*int dword_456780 = 4294967295; // weak
int dword_456784 = 4294967295; // weak
int dword_456788 = 4294967295; // weak*/
int dword_45678C = 5; // weak
char aTshape01[9] = "TSHAPE01"; // weak

_UNKNOWN unk_456848; // weak
_UNKNOWN unk_4568D8; // weak
char aSanim_haf[10] = "SANIM.HAF"; // weak
_UNKNOWN unk_4569F0; // weak

#ifndef PORTABILITY

GLfloat x =  1.0; // idb
GLfloat y =  1.0; // idb

#endif
#ifdef PORTABILITY

float x =  1.0; // idb
float y =  1.0; // idb

#endif

char aWinmainError[16] = "WinMain() error"; // weak
char aSS[] = "%s: %s\n"; // idb
char aFatalError[12] = "Fatal Error"; // weak
char aOutOfMemoryAbo[25] = "Out of memory - aborting"; // weak
char LibFileName[] = "DDRAW.DLL"; // idb
int leftMenuInRaceWidth_456AA0 = 0; // weak
int mushroomTaken_456AA4 = 0; // weak
int isCircuitReversed_456AA8 = 0; // weak
int consecutiveFramesUsingRocket_456AAC = 0; // weak
int pokeDamageSelected_456AB0 = 0; // weak
int pokeWeaponsSelected_456AB4 = 0; // weak
int pokeTurboSelected_456AB8 = 0; // weak
int circuitImageOffsetX_456ABC = 0; // weak  //offest x del a imagen del circuito
int circuitImageOffsetY_456AC0 = 0; // weak //offset y de la imagen del circuito
int dword_456AC4 = 0; // weak
int isRaceFinish_456AC8 = 0; // weak
int totalRacesFrame_456ACC = 0; // weak
int dword_456AD0 = 0; // weak
int raceSemaphorePosition_456AD4 = 0; // weak
int rallyGoSoundPlayed_456AD8 = 0; // weak
int criticalDamageSoundPlayed_456ADC = 0; // weak
int criticalDamage2SoundPlayed_456AE0 = 0; // weak
int isLapRecord_456AE4 = 0; // weak
int dukeNukemEndRaceSoundPlayed_456AE8 = 0; // weak
int dword_456AEC = 0; // weak
int dword_456AF0 = 0; // weak
int dword_456AF4 = 0; // weak
int dword_456AF8 = 0; // weak
int dword_456AFC = 0; // weak
char byte_456B00 = '\0'; // weak
char byte_456B01 = '\0'; // weak
int dword_456B04 = 0; // weak
int dword_456B08 = 0; // weak
int dword_456B0C = 0; // weak
int isDemo_456B10 = 0; // weak
int dword_456B1C = 0; // weak
int dword_456B28 = 0; // weak
int dword_456B2C = 0; // weak
int dword_456B30 = 0; // weak
int dword_456B34 = 0; // weak

int userRacePosition_456B50 = 0; // weak
int dword_456B54 = 0; // weak
int dword_456B58 = 0; // weak

int dword_456B60 = 0; // weak
int dword_456B64 = 0; // weak
int dword_456B68 = 0; // weak
int dword_456B6C = 0; // weak
int framesToWaitAfterBuy_456B70 = 0; // weak
int showWelcomePopup_456B74 = 0; // weak
int showUndergroundPopup_456B78 = 0; // weak
int showMediumWarningRace = 0; // weak
int showHardWarningRace = 0; // weak
int undergroundPricesSet_456B84 = 0; // weak

//circuito seleccionado de los tres
int selectedRaceId = 0; // weak
int dword_456B8C = 0; // weak
int dword_456B90 = 0; // weak
int dword_456B94 = 0; // weak
int dword_456B98 = 0; // weak
int dword_456B9C = 0; // weak
int dword_456BA0 = 0; // weak
int dword_456BA4 = 0; // weak
int consecutiveWins_456BA8 = 0; // weak
int noPaintJob_456BAC = 0; // weak
int allCarsCrash_456BB0 = 0; // weak
int drugQuest_456BB4 = 0; // weak
int killOneQuest_456BB8 = 0; // weak
int killQuestDriverId_456BBC = 0; // weak
int lapped_456BC0 = 0; // weak
int useHasMorePoints_456BC4 = 0; // weak

int dword_456BD0 = 0; // weak
int dword_456BD4 = 0; // weak
int dword_456BD8 = 0; // weak
int userLasRacePriceIncome_456BDC = 0; // weak
int userLastRaceIncomeNoPrice_456BE0 = 0; // weak

int screenPtr = 0; // weak dword_456BF0
int screenPtr_456BF4 = 0; // weak
int dword_456BF8 = 0; // weak
int dword_456BFC = 0; // weak
int (*dword_456C00)(void) = NULL; // weak

int dword_456C14 = 0; // weak
int dword_456C18 = 0; // weak

#ifndef PORTABILITY
GLvoid *pixels = NULL; // idb

#endif

SDL_Joystick *sldJoystick_456C20; // weak

int dword_456C28 = 0; // weak
int sdlTicks14 = 0; // weak

//int dword_456C44 = 0; // weak
//int dword_456C48 = 0; // weak
//int dword_456C4C = 0; // weak
//int dword_456C50 = 0; // weak
//int dword_456C54 = 0; // weak
int dword_456C58 = 0; // weak
int dword_456C5C = 0; // weak
int dword_456C60 = 0; // weak
int dword_456C64 = 0; // weak
int dword_456C68 = 0; // weak
int dword_456C6C = 0; // weak
float flt_456C70 =  0.0; // weak
float flt_456C74 =  0.0; // weak
int dword_456C78 = 0; // weak
int dword_456C7C = 0; // weak
float flt_456C80 =  0.0; // weak
float flt_456C84 =  0.0; // weak
int dword_456C88 = 0; // weak
int dword_456C8C = 0; // weak
int dword_456C90 = 0; // weak
//int mix_volumerampsteps_456C94 = 0; // weak
//float mix_1overvolumerampsteps_456C98 =  0.0; // weak

//FSOUND_CHANNEL FSOUND_Channel_456CC0; // weak
//_UNKNOWN unk_456CC0; // wea
_UNKNOWN unk_456CF4; // weak
_UNKNOWN unk_4582C0; // weak
//int FSOUND_Software_RealBlock; // weak

//FMUSIC_CHANNEL FMUSIC_Channel_45C4E0; // weak
int dword_45C4E4[256]; // weak   //esto tiene la direccion de memoria 456CC0
_UNKNOWN unk_45C4F4; // weak
_UNKNOWN unk_45C546; // weak

_UNKNOWN unk_45DAC0; // weak

int dword_45DC20; // weak
int dword_45DC24; // weak
int screenColors; // weak ///dword_45DC28
int dword_45DC30[256]; // weak
int dword_45DC34; // weak
int dword_45DC38; // weak
int dword_45DC3C; // weak

int screenHeight; // weak // dword_45E060
int dword_45E064; // weak
int screenWidth; // weak //dword_45E068
int dword_45E080; // weak
int dword_45E084; // weak
__int16 word_45E088; // weak
int dword_45E08A; // weak
int dword_45E08E; // weak
__int16 word_45E092; // weak
int dword_45E094; // weak
int dword_45E098; // weak
__int16 word_45E09C; // weak
int dword_45E09E; // weak
int dword_45E0A2; // weak
__int16 word_45E0A6; // weak

//son los caracteres pulsados en el teclado
char keysRead_45E0C0[256]; // weak//
char byte_45E0C1[256]; // weak
char byte_45E0C2[256]; // weak
char byte_45E0C3[256]; // weak
//char keysRead_45E0C0[KEY_TAB]; // weak  //parece cuando tocas tab
//char keysRead_45E0C0[KEY_Y]; // weak
//char keysRead_45E0C0[KEY_P]; // weak
//char keysRead_45E0C0[KEY_ENTER]; // weak
//char keysRead_45E0C0[KEY_N]; // weak
//char byte_45E0FB; // weak//f1/
//char keysRead_45E0C0[KEY_F2]; // weak
//char keysRead_45E0C0[KEY_F3]; // weak
//char keysRead_45E0C0[KEY_F4]; // weak
//char keysRead_45E0C0[KEY_F5]; // weak
//char keysRead_45E0C0[KEY_UP]; // weak
//char keysRead_45E0C0[KEY_LEFT]; // weak
//char keysRead_45E0C0[KEY_RIGHT]; // weak
//char keysRead_45E0C0[KEY_DOWN]; // weak
//char keysRead_45E0C0[KEY_F12]; // weak
char byte_45E15C; // weak
char byte_45E188; // weak
char byte_45E18B; // weak
char byte_45E18D; // weak
char byte_45E190; // weak

//creo que define si es multiplayer o no
int isMultiplayerGame; // weak
//dword_45EA04

int dword_45EA0C; // weak
char *Str2; // idb
int dword_45EA24; // weak
int dword_45EA28; // weak
int dword_45EA2C; // weak
int dword_45EA30; // weak
int dword_45EA34; // weak
int dword_45EA38; // weak
int dword_45EA3C; // weak
int dword_45EA40; // weak
int dword_45EA44; // weak
char raceFilePrefix_45EA50[4]; // weak
void *slidcop2Bpk; // idb
int currentLapMinutes_45EA64; // weak

int participantInRaceById_45EA80[20]; // weak
/*int dword_45EA84; // weak
int dword_45EA88; // weak
int dword_45EA8C; // weak
int dword_45EA90; // weak*/

size_t Size; // idb

int dword_45EAA4; // weak

int currentRaceBestLapSeconds_45EB48; // idb
void *Str; // idb

int dword_45EB50[256]; // weak
int dword_45EB54; // weak
int dword_45EB58; // weak
void *tsahpeBpk_45EB5C; // idb

void *repaaniBpk; // idb

void *reaperxBpk; // idb
void *carbas2Bpk; // idb
void *slidmus2Bpk; // idb
int totalRaceSeconds_45EEBC; // weak
int totalRaceMinutes_45EEC0; // weak
char byte_45EEE0[256]; // weak
char byte_45EEE2; // weak
char byte_45EEE3; // weak
char byte_45EEE4; // weak
char byte_45EEE5; // weak
char byte_45EEE6; // weak
char byte_45EEE7; // weak
char byte_45EEE8; // weak
char byte_45EEE9; // weak
char byte_45EEEA; // weak
char byte_45EEEB; // weak
char byte_45EEEC; // weak
char byte_45EEED; // weak
char byte_45EEF0; // weak
char byte_45EEF1; // weak
char byte_45EEF2; // weak
char byte_45EEF3; // weak
char byte_45EEF4; // weak
char byte_45EEF5; // weak
char byte_45EEF6; // weak
char byte_45EEF7; // weak
char byte_45EEF8; // weak
char byte_45EEF9; // weak
char byte_45EEFE; // weak
char byte_45EEFF; // weak
char byte_45EF00; // weak
char byte_45EF01; // weak
char byte_45EF02; // weak
char byte_45EF03; // weak
char byte_45EF04; // weak
char byte_45EF05; // weak
char byte_45EF06; // weak
char byte_45EF0C; // weak
char byte_45EF0D; // weak
char byte_45EF0E; // weak
char byte_45EF0F; // weak
char byte_45EF10; // weak
char byte_45EF11; // weak
char byte_45EF12; // weak
char byte_45EF13; // weak
char byte_45EF14; // weak
char byte_45EF15; // weak
char byte_45EF19; // weak

int dword_45F000; // weak
int dword_45F004; // weak
int dword_45F008; // weak
int dword_45F00C; // weak
__int16 word_45F010; // weak
char byte_45F012; // weak

void *bases42Bpk; // idb

void *statbas7Bpk; // idb

//void *screenBuffer; // idb //dword_45F038

int dword_45F04C; // idb

int dword_45F110; // weak
int dword_45F114; // weak

_UNKNOWN unk_45F8B0; // weak
_UNKNOWN unk_45F8BC; // weak

void *engi1Bpk; // idb
void *engi2Bpk; // idb
void *engi3Bpk; // idb
void *engi4Bpk; // idb

int dword_45FA74; // weak
int dword_45FA78; // weak

void *blacktx2Bpk; // idb

char byte_45FAA0[256]; // weak

void *fsma3fBpk; // idb

FILE *File; // idb
void *arrows1dBpk; // idb
char byte_45FB84; // weak

void *scenecar1Bpk; // idb
void *scenecar2Bpk; // idb
void *scenecar3Bpk; // idb
void *scenecar4Bpk; // idb
void *scenecar5Bpk; // idb
void *scenecar6Bpk; // idb

int cursorBpkFrame; // weak

int dword_45FC00; // weak
void *bases45Bpk; // idb

char byte_45FC11; // weak
char byte_45FC12; // weak
char byte_45FC13; // weak
int currentLapMilliseconds_45FC1C; // weak

//si es cero es que en el listado sales primero en la carrera y asi.Contra adversary eres el 1 porque adversary es el 0 siempre
int userRaceOrder_45FC20; // weak

//coche seleccionado
int actualCarSelected; // weak
///todo estos son paletas!!!!!!!
int palette1[768];

int palette2[768];//trasformo esos datos separados por colores en una paleta continua
int palette3[768];
/*int dword_45FC40[768]; // weak
int dword_45FC44[768]; // weak
int dword_45FC48[768]; // weak*/
/*int dword_45FD00[256]; // weak
int dword_45FD04[256]; // weak
int dword_45FD08[256]; // weak*/

_UNKNOWN unk_45FF44; // weak
_UNKNOWN unk_460000; // weak
_UNKNOWN unk_460004; // weak
_UNKNOWN unk_4600C4; // weak
_UNKNOWN unk_460244; // weak

//paleta
_UNKNOWN unk_460484; // weak
_UNKNOWN unk_4604D8; // weak
_UNKNOWN unk_460544; // weak
_UNKNOWN unk_4606C4; // weak

int maxPaletteEntries=768; // weak

char byte_460840[256]; // weak
//int dword_46084C[256]; // weak
//int dword_460850[256]; // weak
//int dword_460854[256]; // weak
//int dword_460858[256]; // weak
//int dword_46085C[256]; // weak
//int dword_46086C[256]; // weak
//int dword_460870[256]; // weak
//int dword_460874[256]; // weak
//int dword_460878[256]; // weak
//int dword_46087C[256]; // weak
//int dword_460880[256]; // weak
//int dword_460884[256]; // weak
//int dword_460888[256]; // weak
//int dword_46088C[256]; // weak
//int dword_460890[256]; // weak
//int dword_460894[256]; // weak
//int dword_460898[256]; // weak
//int dword_46089C[256]; // weak
//int dword_4608A0[256]; // weak
//int dword_4608A4[256]; // weak
//int dword_4608A8[256]; // weak
//int dword_4608C8; // weak
int dword_4608F0[256]; // weak
//int dword_460904[256]; // weak
//int dword_460934; // weak
//int dword_4609A0; // weak
//int dword_460A0C; // weak
//int dword_460A78; // weak
//int dword_460AE4; // weak
//int dword_460B50; // weak
//int dword_460BBC; // weak
//int dword_460C28; // weak
//int dword_460C94; // weak
//int dword_460D00; // weak
//int dword_460D6C; // weak
//int dword_460DD8; // weak
//int dword_460E44; // weak
//int dword_460EB0; // weak
//int dword_460F1C; // weak
//int dword_460F88; // weak
//int dword_460FF4; // weak
//int dword_461060; // weak
_UNKNOWN unk_461094; // weak

_UNKNOWN unk_4610BC; // weak

_UNKNOWN unk_461110; // weak
void *prepw1Bpk; // idb

void *statpop4Bpk; // idb

_UNKNOWN unk_4611E0; // weak

int dword_461250; // weak
void *bases44Bpk; // idb

char circuitsToSelect_46126C[3]; 
//estos dos no se usan contiene los 3 circuitos que se muestran en la pantalla de seleccion
//char byte_46126C[3]; // weak
//char byte_46126D; // weak
//char byte_46126E; // weak

void *contaniBpk; // idb

//todo estos son paleta!!!!
int dword_4612A0[768]; // weak
int dword_4612A4[768]; // weak
int dword_4612A8[768]; // weak
int dword_461360[256]; // weak
int dword_461364[256]; // weak
int dword_461368[256]; // weak
_UNKNOWN unk_461424; // weak
void *dealer2bBpk; // idb
void *dword_461EA4; // idb

int participantsRace[3];
//__int16 word_461EB4; // weak
//char byte_461EB6; // weak
char unk_461EC0[256]; // idb
_UNKNOWN unk_461EC1; // weak
_UNKNOWN unk_461EC2; // weak
_UNKNOWN unk_461EC3; // weak
__int16 word_461EC4; // weak
_UNKNOWN unk_461EC6; // weak
_UNKNOWN unk_461EC7; // weak
__int16 word_461EC8; // weak
_UNKNOWN unk_461ECA; // weak
_UNKNOWN unk_461ECB; // weak
__int16 word_461ECC; // weak
_UNKNOWN unk_461ECE; // weak
_UNKNOWN unk_461ECF; // weak
__int16 word_461ED0; // weak
_UNKNOWN unk_461ED2; // weak
_UNKNOWN unk_461ED3; // weak

void *dword_461ED8; // idb

int dword_461EEC; // weak
void *tire1Bpk; // idb
void *tire2Bpk; // idb
void *tire3Bpk; // idb
void *tire4Bpk; // idb

void *slidcur3Bpk; // idb

int currentRaceBestLapMilliseconds_461FEC; // idb
void *bases43Bpk; // idb
void *event2Bpk; // idb

_UNKNOWN unk_462000; // weak
_UNKNOWN unk_462096; // weak
_UNKNOWN unk_462960; // weak
char byte_4629F6[256]; // weak
char byte_462A8C[256]; // weak
char byte_462B22[256]; // weak
char byte_462BB8[256]; // weak
int dword_462C4E; // weak
int dword_462C52; // weak
int dword_462C56; // weak
int dword_462C5A; // weak
int dword_462C5E; // weak
__int16 word_462C62; // weak
void *blacktx1Bpk; // idb
int selectedRace_462CE8; // weak

void *volcur2Bpk; // idb

void *maxi1fBpk; // idb

void *maret1eBpk; // idb

void *kuplaBpk; // idb
void *pickupBpk; // idb
void *sedanBpk; // idb
void *camaroBpk; // idb
void *porscheBpk; // idb
void *lotusBpk; // idb

void *carnameBpk; // idb

int totalRaceMilliseconds_462D74; // weak

int dword_462D7C; // weak

void *drugdealBpk; // idb





int numberOfLaps; // idb

int currentRaceBestLapMinutes_463CAC; // idb

void *armor1Bpk; // idb
void *armor2Bpk; // idb
void *armor3Bpk; // idb
void *armor4Bpk; // idb

int currentLapSeconds_463CD4; // weak

void *DstBuf; // idb

int dword_463CE8; // weak

void *bases41Bpk; // idb

void *spons1bBpk; // idb

int menuOptionSelected_463DF0; // weak
void *choo2Bpk; // idb

char byte_463E00[256]; // weak
int dword_463E08; // weak

int dword_463E2D; // weak
int trxSCE3Bpk_464F10; // weak
int dword_464F14; // weak
int dword_464F18; // weak
int dword_464F1C; // weak
int dword_464F20; // weak
int dword_464F30[256]; // weak
int circuitWidth_464F40; // weak
int firstRacePlayed_464F44; // weak
char circuitSelectedTR_464F50[4]; // idb
//char byte_464F50

int deployedMines_464F60; // weak parece que son las minas desplegadas
int raceSemaphoreWidth_464F64; // weak
int dword_464F68; // weak
int dword_464F6C; // weak
float flt_464F70; // weak
void *pedestrBpk; // idb
void *rast1Bpk_464F78; // idb
char damageBpk_464F80[8064]; // weak
//_UNKNOWN unk_4669C0; // weak
int trxVARJOTab_466F00[257]; // weak
int circuitLR1Bpk_height_467000; // weak
int dword_467020[7504]; // weak
char bugnum6Bpk_46E560[433]; // weak
_UNKNOWN unk_46E880; // weak
int racePositionUserFirst_46E8D0[4]; // weak
//int dword_46E8D4; // weak
//int dword_46E8D8; // weak
int dword_46E8DC; // weak
int trxSHA8Bpk_46E8E0[1024]; // weak
void *mines1aBpk; // idb
int dword_46ECE4; // weak// valor mezclado entre sombras y texturas pero parece que se puede separar
int dword_46ECE8; // weak
_UNKNOWN unk_46ED00; // weak
int trxOHIDat_46EE00[256]; // weak
int dword_46F200; // weak
void *dword_46F204; // idb
int dword_46F208; // weak
//int dword_46F21C[256]; // weak
int dword_46F220[1000][100]; // weak
int trxSHA5Bpk_478E60[1024]; // weak
void *rocket1Bpk; // idb
void *rocket2Bpk; // idb
int dword_479268; // weak
void *dword_47926C; // idb
int dword_479270; // weak
int trxSHA3Bpk_479280[4096]; // weak
void *genlamBpk; // idb
int dword_479684; // weak
void *genmesBpk; // idb
int dword_47968C; // weak
void *inRaceMessagePopup_479690; // idb
float flt_4796A0[256]; // weak
/*_UNKNOWN unk_479AA0; // weak
_UNKNOWN unk_479AA4[256]; // weak
_UNKNOWN unk_479AAC; // weak*/
//_UNKNOWN unk_479AB8; // weak
int trxSCE1Number3DObjects_479D20; // weak
//_UNKNOWN unk_479D24; // weak
//_UNKNOWN unk_479D2C; // weak
//_UNKNOWN unk_479D38; // weak
char trxBLOTab_479D40[257]; // weak
_UNKNOWN unk_479E40; // weak

RacePopupMemory racePopupMemory[969];
/*
_UNKNOWN unk_479EE0; // weak
_UNKNOWN unk_479EE8; // weak
_UNKNOWN unk_479EEC; // weak
_UNKNOWN unk_479F00; // weak
*/
_UNKNOWN unk_481BC9; // weak
int racePositionTemp_481BD0[4]; // weak
//int dword_481BD4; // weak
//int dword_481BD8; // weak
//int dword_481BDC; // weak
int endRaceFlagFrame_481BE0; // weak
float flt_481BE4; // weak
int dword_481BE8; // weak parece un simple contador que se usa para sobmbras texturas y demas 

//parece un array de minas en pantalla estructura de 4 enteros
//int dword_481C00[256]; // weak coordenada x de la mina
//int dword_481C04[256]; // weak coordenada y de la mina
//_UNKNOWN unk_481C08; // weak
//_UNKNOWN unk_481C0C; // weak

int dword_481E00; // weak
void *sidebom1Bpk_481E04; // idb
int dword_481E08; // weak
int currentLapTime_481E0C; // weak
void *smokeBpk; // idb
int raceFrame_481E14; // weak

int dword_481E24[256]; // weak
int dword_481E28; // weak
int dword_481E2C; // weak
int dword_481E30; // weak
int dword_481E34; // weak
int dword_481E38; // weak
int dword_481E3C; // weak
int dword_481E40; // weak
int dword_481E44; // weak
int dword_481E48; // weak
int dword_481E4C; // weak
int dword_481E50; // weak
int dword_481E54; // weak
int dword_481E58; // weak
_UNKNOWN unk_481F20; // weak
_UNKNOWN unk_488020; // weak
_UNKNOWN unk_48E420; // weak
_UNKNOWN unk_48E620; // weak
_UNKNOWN unk_48E720; // weak
_UNKNOWN unk_48E760; // weak
_UNKNOWN unk_491820; // weak
_UNKNOWN unk_491920; // weak
char byte_4A6820[256]; // weak
char byte_4A6822; // weak
char byte_4A6823; // weak
char byte_4A6824; // weak
char byte_4A6825; // weak
char byte_4A6826; // weak
char byte_4A6827; // weak
char byte_4A6828; // weak
char byte_4A6829; // weak
char byte_4A682A; // weak
char byte_4A682B; // weak
char byte_4A682C; // weak
char byte_4A682D; // weak
char byte_4A682E; // weak
char byte_4A682F; // weak
char byte_4A6830; // weak
char byte_4A6831; // weak
char byte_4A6832; // weak
void *dword_4A6854; // idb
int circuitVaiBpk_width_4A6858; // weak
int circuitVaiZones_4A685C; // weak
void *genflaBpk; // idb

//esto es raceparticipant2 en cuanto este sobra!
//int dword_4A6880[256]; // weak
//int dword_4A6884[256]; // weak
//int dword_4A6888; // weak
//int dword_4A688C[256]; // weak
//int dword_4A6890[256]; // weak
//float flt_4A6894[256]; // weak
//int dword_4A6898[256]; // weak
//int dword_4A689C[256]; // weak
//int dword_4A68A0[256]; // weak
//int dword_4A68A4[256]; // weak
//int dword_4A68A8[256]; // weak
//int dword_4A68AC[256]; // weak
//int dword_4A68B0[256]; // weak
//int dword_4A68B4[256]; // weak
//int dword_4A68B8; // weak
//int dword_4A68BC; // weak
//int dword_4A68C0; // weak
//char byte_4A68C4[256]; // weak

//int dword_4A68D0[256]; // weak raceparticipant2[].moneyPicked
//_UNKNOWN racePosition; // weak
int usingRocket_4A68D8[256]; // weak
//int dword_4A68DC[256]; // weak
//int dword_4A68E0[256]; // weak
//int dword_4A68E4[256]; // weak
//int dword_4A68E8; // weak
//int dword_4A68F4[256]; // weak
//int dword_4A68F8; // weak
//int dword_4A6904[256]; // weak
//int dword_4A6908; // weak
int dword_4A694C; // weak
int dword_4A6950; // weak
int dword_4A6954; // weak
char byte_4A6958[256]; // weak
int dword_4A69E0; // weak
int dword_4A69E4; // weak
int dword_4A69E8; // weak
char byte_4A69EC[256]; // weak
int dword_4A6A74; // weak
int dword_4A6A78; // weak
int dword_4A6A7C; // weak
char byte_4A6A80[256]; // weak
int dword_4A6AD0; // weak
int dword_4A6AD4; // weak
int dword_4A6AD8; // weak
/*int dword_4A6AE0[256]; // weak
int dword_4A6AE4; // weak
int dword_4A6AE8; // weak
int dword_4A6AEC; // weak
int dword_4A6AF0; // weak
int dword_4A6AF4; // weak
int dword_4A6AF8; // weak*/
int dword_4A6AFC; // weak
int dword_4A6B00; // weak
int dword_4A6B04; // weak
_UNKNOWN unk_4A6B20; // weak
_UNKNOWN unk_4A6B24; // weak
int dword_4A6B2F; // weak
int dword_4A6B33; // weak
int dword_4A6B37; // weak
__int16 word_4A6B3B; // weak
int dword_4A6B3E; // weak
int dword_4A6B42; // weak
int dword_4A6B46; // weak
__int16 word_4A6B4A; // weak
int dword_4A6B4D; // weak
int dword_4A6B51; // weak
int dword_4A6B55; // weak
__int16 word_4A6B59; // weak
int dword_4A6B5C; // weak
int dword_4A6B60; // weak
int dword_4A6B64; // weak
__int16 word_4A6B68; // weak
int dword_4A6B6B; // weak
int dword_4A6B6F; // weak
int dword_4A6B73; // weak
__int16 word_4A6B77; // weak
int dword_4A6B7A; // weak
int dword_4A6B7E; // weak
int dword_4A6B82; // weak
__int16 word_4A6B86; // weak
int dword_4A6B89; // weak
int dword_4A6B8D; // weak
int dword_4A6B91; // weak
__int16 word_4A6B95; // weak
int dword_4A6B98; // weak
int dword_4A6B9C; // weak
int dword_4A6BA0; // weak
__int16 word_4A6BA4; // weak
int dword_4A6BA7; // weak
int dword_4A6BAB; // weak
int dword_4A6BAF; // weak
__int16 word_4A6BB3; // weak
int dword_4A6BB6; // weak
int dword_4A6BBA; // weak
int dword_4A6BBE; // weak
__int16 word_4A6BC2; // weak
int dword_4A6BC5; // weak
int dword_4A6BC9; // weak
int dword_4A6BCD; // weak
__int16 word_4A6BD1; // weak
int dword_4A6BD4; // weak
int dword_4A6BD8; // weak
int dword_4A6BDC; // weak
__int16 word_4A6BE0; // weak
int dword_4A6BE3; // weak
int dword_4A6BE7; // weak
int dword_4A6BEB; // weak
__int16 word_4A6BEF; // weak
int dword_4A6BF2; // weak
int dword_4A6BF6; // weak
int dword_4A6BFA; // weak
__int16 word_4A6BFE; // weak
int dword_4A6C01; // weak
int dword_4A6C05; // weak
int dword_4A6C09; // weak
__int16 word_4A6C0D; // weak
int dword_4A6C10; // weak
int dword_4A6C14; // weak
int dword_4A6C18; // weak
__int16 word_4A6C1C; // weak
int dword_4A6C1F; // weak
int dword_4A6C23; // weak
int dword_4A6C27; // weak
__int16 word_4A6C2B; // weak
int dword_4A6C2E; // weak
int dword_4A6C32; // weak
int dword_4A6C36; // weak
__int16 word_4A6C3A; // weak
int dword_4A6C3D; // weak
int dword_4A6C41; // weak
int dword_4A6C45; // weak
__int16 word_4A6C49; // weak
int dword_4A6C4C; // weak
int dword_4A6C50; // weak
int dword_4A6C54; // weak
__int16 word_4A6C58; // weak
int dword_4A6C5B; // weak
int dword_4A6C5F; // weak
int dword_4A6C63; // weak
__int16 word_4A6C67; // weak
int dword_4A6C6A; // weak
int dword_4A6C6E; // weak
int dword_4A6C72; // weak
__int16 word_4A6C76; // weak
int dword_4A6C79; // weak
int dword_4A6C7D; // weak
int dword_4A6C81; // weak
__int16 word_4A6C85; // weak
int dword_4A6C88; // weak
int dword_4A6C8C; // weak
int dword_4A6C90; // weak
__int16 word_4A6C94; // weak
int dword_4A6C97; // weak
int dword_4A6C9B; // weak
int dword_4A6C9F; // weak
__int16 word_4A6CA3; // weak
int dword_4A6CA6; // weak
int dword_4A6CAA; // weak
int dword_4A6CAE; // weak
__int16 word_4A6CB2; // weak
int dword_4A6CB5; // weak
int dword_4A6CB9; // weak
int dword_4A6CBD; // weak
__int16 word_4A6CC1; // weak
int dword_4A6CC4; // weak
int dword_4A6CC8; // weak
int dword_4A6CCC; // weak
__int16 word_4A6CD0; // weak
int dword_4A6CD3; // weak
int dword_4A6CD7; // weak
int dword_4A6CDB; // weak
__int16 word_4A6CDF; // weak
int dword_4A6CE2; // weak
int dword_4A6CE6; // weak
int dword_4A6CEA; // weak
__int16 word_4A6CEE; // weak
int dword_4A6CF1; // weak
int dword_4A6CF5; // weak
int dword_4A6CF9; // weak
__int16 word_4A6CFD; // weak
int dword_4A6D00; // weak
int dword_4A6D04; // weak
int dword_4A6D08; // weak
__int16 word_4A6D0C; // weak
int dword_4A6D0F; // weak
int dword_4A6D13; // weak
int dword_4A6D17; // weak
__int16 word_4A6D1B; // weak
int dword_4A6D1E; // weak
int dword_4A6D22; // weak
int dword_4A6D26; // weak
__int16 word_4A6D2A; // weak
int dword_4A6D2D; // weak
int dword_4A6D31; // weak
int dword_4A6D35; // weak
__int16 word_4A6D39; // weak
int dword_4A6D3C; // weak
int dword_4A6D40; // weak
int dword_4A6D44; // weak
__int16 word_4A6D48; // weak
int dword_4A6D4B; // weak
int dword_4A6D4F; // weak
int dword_4A6D53; // weak
__int16 word_4A6D57; // weak
int dword_4A6D5A; // weak
int dword_4A6D5E; // weak
int dword_4A6D62; // weak
__int16 word_4A6D66; // weak
int dword_4A6D69; // weak
int dword_4A6D6D; // weak
int dword_4A6D71; // weak
__int16 word_4A6D75; // weak
int dword_4A6D78; // weak
int dword_4A6D7C; // weak
int dword_4A6D80; // weak
__int16 word_4A6D84; // weak
int dword_4A6D87; // weak
int dword_4A6D8B; // weak
int dword_4A6D8F; // weak
__int16 word_4A6D93; // weak
int dword_4A6D96; // weak
int dword_4A6D9A; // weak
int dword_4A6D9E; // weak
__int16 word_4A6DA2; // weak
int dword_4A6DA5; // weak
int dword_4A6DA9; // weak
int dword_4A6DAD; // weak
__int16 word_4A6DB1; // weak
int dword_4A6DB4; // weak
int dword_4A6DB8; // weak
int dword_4A6DBC; // weak
__int16 word_4A6DC0; // weak
int dword_4A6DC3; // weak
int dword_4A6DC7; // weak
int dword_4A6DCB; // weak
__int16 word_4A6DCF; // weak
int dword_4A6DD2; // weak
int dword_4A6DD6; // weak
int dword_4A6DDA; // weak
__int16 word_4A6DDE; // weak
int dword_4A6DE1; // weak
int dword_4A6DE5; // weak
int dword_4A6DE9; // weak
__int16 word_4A6DED; // weak
int dword_4A6DF0; // weak
int dword_4A6DF4; // weak
int dword_4A6DF8; // weak
__int16 word_4A6DFC; // weak
int dword_4A6DFF; // weak
int dword_4A6E03; // weak
int dword_4A6E07; // weak
__int16 word_4A6E0B; // weak
int dword_4A6E0E; // weak
int dword_4A6E12; // weak
int dword_4A6E16; // weak
__int16 word_4A6E1A; // weak
int dword_4A6E1D; // weak
int dword_4A6E21; // weak
int dword_4A6E25; // weak
__int16 word_4A6E29; // weak
int dword_4A6E2C; // weak
int dword_4A6E30; // weak
int dword_4A6E34; // weak
__int16 word_4A6E38; // weak
int dword_4A6E3B; // weak
int dword_4A6E3F; // weak
int dword_4A6E43; // weak
__int16 word_4A6E47; // weak
int dword_4A6E4A; // weak
int dword_4A6E4E; // weak
int dword_4A6E52; // weak
__int16 word_4A6E56; // weak
int dword_4A6E59; // weak
int dword_4A6E5D; // weak
int dword_4A6E61; // weak
__int16 word_4A6E65; // weak
int dword_4A6E68; // weak
int dword_4A6E6C; // weak
int dword_4A6E70; // weak
__int16 word_4A6E74; // weak
int dword_4A6E77; // weak
int dword_4A6E7B; // weak
int dword_4A6E7F; // weak
__int16 word_4A6E83; // weak
int dword_4A6E86; // weak
int dword_4A6E8A; // weak
int dword_4A6E8E; // weak
__int16 word_4A6E92; // weak
int dword_4A6E95; // weak
int dword_4A6E99; // weak
int dword_4A6E9D; // weak
__int16 word_4A6EA1; // weak
int dword_4A6EA4; // weak
int dword_4A6EA8; // weak
int dword_4A6EAC; // weak
__int16 word_4A6EB0; // weak
int dword_4A6EB3; // weak
int dword_4A6EB7; // weak
int dword_4A6EBB; // weak
__int16 word_4A6EBF; // weak
int dword_4A6EC2; // weak
int dword_4A6EC6; // weak
int dword_4A6ECA; // weak
__int16 word_4A6ECE; // weak
int dword_4A6ED1; // weak
int dword_4A6ED5; // weak
int dword_4A6ED9; // weak
__int16 word_4A6EDD; // weak
int dword_4A6EE0; // weak
int dword_4A6EE4; // weak
int dword_4A6EE8; // weak
__int16 word_4A6EEC; // weak
int dword_4A6EEF; // weak
int dword_4A6EF3; // weak
int dword_4A6EF7; // weak
__int16 word_4A6EFB; // weak
int dword_4A6EFE; // weak
int dword_4A6F02; // weak
int dword_4A6F06; // weak
__int16 word_4A6F0A; // weak
int dword_4A6F0D; // weak
int dword_4A6F11; // weak
int dword_4A6F15; // weak
__int16 word_4A6F19; // weak
int dword_4A6F1C; // weak
int dword_4A6F20; // weak
int dword_4A6F24; // weak
__int16 word_4A6F28; // weak
int dword_4A6F2B; // weak
int dword_4A6F2F; // weak
int dword_4A6F33; // weak
__int16 word_4A6F37; // weak
int dword_4A6F3A; // weak
int dword_4A6F3E; // weak
int dword_4A6F42; // weak
__int16 word_4A6F46; // weak
int dword_4A6F49; // weak
int dword_4A6F4D; // weak
int dword_4A6F51; // weak
__int16 word_4A6F55; // weak
int dword_4A6F58; // weak
int dword_4A6F5C; // weak
int dword_4A6F60; // weak
__int16 word_4A6F64; // weak
int dword_4A6F67; // weak
int dword_4A6F6B; // weak
int dword_4A6F6F; // weak
__int16 word_4A6F73; // weak
int dword_4A6F76; // weak
int dword_4A6F7A; // weak
int dword_4A6F7E; // weak
__int16 word_4A6F82; // weak
int dword_4A6F85; // weak
int dword_4A6F89; // weak
int dword_4A6F8D; // weak
__int16 word_4A6F91; // weak
int dword_4A6F94; // weak
int dword_4A6F98; // weak
int dword_4A6F9C; // weak
__int16 word_4A6FA0; // weak
int dword_4A6FA3; // weak
int dword_4A6FA7; // weak
int dword_4A6FAB; // weak
__int16 word_4A6FAF; // weak
int dword_4A6FB2; // weak
int dword_4A6FB6; // weak
int dword_4A6FBA; // weak
__int16 word_4A6FBE; // weak
int dword_4A6FC1; // weak
int dword_4A6FC5; // weak
int dword_4A6FC9; // weak
__int16 word_4A6FCD; // weak
int dword_4A6FD0; // weak
int dword_4A6FD4; // weak
int dword_4A6FD8; // weak
__int16 word_4A6FDC; // weak
int dword_4A6FDF; // weak
int dword_4A6FE3; // weak
int dword_4A6FE7; // weak
__int16 word_4A6FEB; // weak
int dword_4A6FEE; // weak
int dword_4A6FF2; // weak
int dword_4A6FF6; // weak
__int16 word_4A6FFA; // weak
int dword_4A6FFD; // weak
int dword_4A7001; // weak
int dword_4A7005; // weak
__int16 word_4A7009; // weak
int dword_4A700C; // weak
int dword_4A7010; // weak
int dword_4A7014; // weak
__int16 word_4A7018; // weak
int dword_4A7039; // weak
int dword_4A703D; // weak
int dword_4A7041; // weak
__int16 word_4A7045; // weak
int dword_4A7048; // weak
int dword_4A704C; // weak
int dword_4A7050; // weak
__int16 word_4A7054; // weak
int dword_4A7444; // weak
int dword_4A7448; // weak
int dword_4A744C; // weak
__int16 word_4A7450; // weak
int dword_4A7453; // weak
int dword_4A7457; // weak
int dword_4A745B; // weak
__int16 word_4A745F; // weak
int dword_4A75BB; // weak
int dword_4A75BF; // weak
int dword_4A75C3; // weak
__int16 word_4A75C7; // weak
int dword_4A75D9; // weak
int dword_4A75DD; // weak
int dword_4A75E1; // weak
__int16 word_4A75E5; // weak
int dword_4A75E8; // weak
int dword_4A75EC; // weak
int dword_4A75F0; // weak
__int16 word_4A75F4; // weak
int dword_4A76C9; // weak
int dword_4A76CD; // weak
int dword_4A76D1; // weak
__int16 word_4A76D5; // weak
int dword_4A76D8; // weak
int dword_4A76DC; // weak
int dword_4A76E0; // weak
__int16 word_4A76E4; // weak
int dword_4A76E7; // weak
int dword_4A76EB; // weak
int dword_4A76EF; // weak
__int16 word_4A76F3; // weak
int dword_4A7705; // weak
int dword_4A7709; // weak
int dword_4A770D; // weak
__int16 word_4A7711; // weak
int dword_4A7723; // weak
int dword_4A7727; // weak
int dword_4A772B; // weak
__int16 word_4A772F; // weak
int dword_4A7741; // weak
int dword_4A7745; // weak
int dword_4A7749; // weak
__int16 word_4A774D; // weak
int dword_4A7750; // weak
int dword_4A7754; // weak
int dword_4A7758; // weak
__int16 word_4A775C; // weak
int dword_4A775F; // weak
int dword_4A7763; // weak
int dword_4A7767; // weak
__int16 word_4A776B; // weak
int dword_4A776E; // weak
int dword_4A7772; // weak
int dword_4A7776; // weak
__int16 word_4A777A; // weak
int dword_4A777D; // weak
int dword_4A7781; // weak
int dword_4A7785; // weak
__int16 word_4A7789; // weak
int dword_4A7A20; // weak
int dword_4A7A24; // weak
void *trxSCE5Bpk_4A7A28; // idb
void *splat3Bpk; // idb
void *splat4Bpk; // idb
int dword_4A7A38; // weak
int dword_4A7A3C; // weak
int dword_4A7A40; // weak
int joystick_x_axis_4A7A44; // weak
int dword_4A7A48; // weak
int dword_4A7A4C; // weak

///RaceParticipant.h
char dword_4A7A60[256];
int dword_4A7A64; // weak
__int16 word_4A7A68; // weak

int dword_4A7A70[256]; // weak
//_UNKNOWN unk_4A7A74; // weak
int dword_4A7A80; // weak
int dword_4A7A84; // weak
int dword_4A7A88; // weak
int dword_4A7A8C; // weak
int dword_4A7A90; // weak
int dword_4A7A94; // weak
int dword_4A7A98[256]; // weak
int dword_4A7A9C; // weak
int dword_4A7AA0[256]; // weak
int dword_4A7AA4; // weak
//int isCircuitReversed_4A7AA8; // weak
//int dword_4A7AAC; // weak
int Val; // idb  //parece que es dword_4A7AB0
char byte_4A7AB4[256]; // weak

int dword_4A7AC8; // weak
int dword_4A7AE8; // weak
int dword_4A7AEC; // weak
int dword_4A7AF0; // weak
//int dword_4A7AF4; // weak
int dword_4A7AF8; // weak
char byte_4A7B08[256]; // weak
int dword_4A7B3C; // weak
int dword_4A7B40; // weak
int dword_4A7B44; // weak
int dword_4A7B48; // weak
char byte_4A7B5C[256]; // weak
int dword_4A7B90; // weak
int dword_4A7B94; // weak
int dword_4A7B98; // weak
int dword_4A7B9C; // weak

_UNKNOWN unk_4A7BBC; // weak
_UNKNOWN unk_4A7BC0; // weak
_UNKNOWN unk_4A7BC4; // weak
_UNKNOWN unk_4A7BE8; // weak
_UNKNOWN unk_4A7BF0; // weak
_UNKNOWN unk_4A7BF4; // weak
int dword_4A7CC0[4]; // weak
//int dword_4A7CC4; // weak
//int dword_4A7CC8; // weak
//int dword_4A7CCC; // weak
int dword_4A7CD0; // weak
int dword_4A7CE0[4]; // weak
//int dword_4A7CE4; // weak
//int dword_4A7CE8; // weak
//int dword_4A7CEC; // weak
int dword_4A7CF0; // weak
int dword_4A7CF4; // weak
int circuitHeight_4A7CF8; // weak
int dword_4A7CFC; // weak

//int actualVaiZone_4A7D00[256]; // weak
//int inScreenPositionX_4A7D04[256]; // weak///
//int inScreenPositionY_4A7D08[256]; // weak
// directionRotation_4A7D0C[256]; // weak//
//int participantBpkOffser_4A7D10[256]; // weak
//int dword_4A7D14[256]; // weak
//int dword_4A7D18[256]; // weak
//int dword_4A7D1C[256]; // weak
//BYTE dword_4A7D20[64]; // idb
/// dword_4A7D60[256]; // weak
//int lastKeysReadIndex_4A7DA0[256]; // weak
//int lastKeysReadPreviousIndex_4A7DA4[256]; // weak
//_UNKNOWN currentSteeringAngleDelta_4A7DA8; // weak
//float carAngle_4A7DAC[256]; // weak
//int carVelocity_4A7DB0[256]; // weak
//int absolutePositionX_4A7DB4[256]; // weak
//int absolutePositionY_4A7DB8[256]; // weak
//_UNKNOWN unk_4A7DFC; // weak
//_UNKNOWN unk_4A7E00; // weak
//_UNKNOWN unk_4A7E04; // weak
//char currentLap_4A7E08[256]; // weak
//char racePosition_4A7E09[256]; // weak
//int hasFinishedTheRace_4A7E0C[256]; // weak
//int frontLeftAbsoluteXPosition_4A7E10[256]; // weak
//int frontLeftAbsoluteYPosition_4A7E14[256]; // weak
//int raceParticipantIngame[v156].lastFrontLeftAbsoluteXPosition_4A7E18[256]; // weak
//int raceParticipantIngame[v106].lastFrontLeftAbsoluteYPosition_4A7E1C[256]; // weak
//int frontRightAbsoluteYPosition_4A7E24[256]; // weak
//int frontRightAbsoluteXPosition_4A7E20[256]; // weak
//int lastFrontRightAbsoluteXPosition_4A7E28[256]; // weak
//int raceParticipantIngame[v156].lastFrontRightAbsoluteYPosition_4A7E2C[256]; // weak
//int backLeftAbsoluteXPosition_4A7E30[256]; // weak
//int backLeftAbsoluteYPosition_4A7E34[256]; // weak
//int lastBackLeftAbsoluteXPosition_4A7E38[256]; // weak
//int lastBackLeftAbsoluteYPosition_4A7E3C[256]; // weak
//int backRightAbsoluteXPosition_4A7E40[256]; // weak
//int backRightAbsoluteYPosition_4A7E44[256]; // weak
//int lastBackRightAbsoluteXPosition_4A7E48[256]; // weak
//int lastBackRightAbsoluteYPosition_4A7E4C[256]; // weak
//int dword_4A7E50[256]; // weak
//int dword_4A7E54[256]; // weak
//float flt_4A7E58; // weak
//int advanceXAxis_4A7E5C[256]; // weak
//int advanceYAxis_4A7E60[256]; // weak
//_UNKNOWN unk_4A7E64; // weak
int dword_4A7E6C[256]; // weak
int dword_4A7E70[256]; // weak
int dword_4A7E74[256]; // weak
int dword_4A7E78[256]; // weak
int dword_4A7E80[256]; // weak
//int dword_4A7E84[256]; // weak
//int dword_4A7E88[256]; // weak
int dword_4A7E90[256]; // weak
//int dword_4A7E94[256]; // weak
int dword_4A7E98[256]; // weak
int dword_4A7E9C[256]; // weak
int dword_4A7EA0[256]; // weak
//int dword_4A7EA4[256]; // weak
int ticksToWaitDropMine_4A7EA8[1024]; // weak
int dword_4A7EAC[256]; // weak
int dword_4A7EB0[256]; // weak
int dword_4A7EB4[256]; // weak
int drawFlames_4A7EB8[1024]; // weak
int dword_4A7EBC[256]; // weak
int dword_4A7EC0[256]; // weak
int dword_4A7EC4[256]; // weak
int dword_4A7EC8[256]; // weak
int dword_4A7ECC[256]; // weak
int dword_4A7ED0[256]; // weak
int dword_4A7ED4[256]; // weak
int dword_4A7ED8[256]; // weak
//int spriteBurnOffset_4A7EDC[256]; // weak
int lastUserTicks_4A7EE0[1024]; // weak //son 4 pero esta en estructura
int dword_4A7EE4[256]; // weak
int dword_4A7F20[256]; // weak
int dword_4A7F5C[256]; // weak
int dword_4A7F98[256]; // weak
int dword_4A7FD4[256]; // weak
int dword_4A8010[256]; // weak
///int dword_4A804C[256]; // weak
//int dword_4A8050[256]; // weak
//int dword_4A8054[256]; // weak
int dword_4A8058[256]; // weak
//intraceParticipantIngame[v59].hornPlayed_4A805C][256]; // weak
//int directionRotation_4A7D0C[4]; // weak
//int dword_4A8070; // weak
//float flt_4A810C; // weak
//float absolutePositionX_4A7DB4[4]; // weak
//float absolutePositionY_4A7DB8[4]; // weak
//char byte_4A8168; // weak
//char byte_4A8169; // weak
//int dword_4A81B0; // weak
//int dword_4A81B4; // weak
//float flt_4A81B8; // weak
int dword_4A83AC; // weak
//int directionRotation_4A7D0C[2]; // weak
//int dword_4A83D0; // weak
//float flt_4A846C; // weak
//float absolutePositionX_4A7DB4[2]; // weak
//float absolutePositionY_4A7DB8[2]; // weak
//char byte_4A84C8; // weak
//char byte_4A84C9; // weak
//int dword_4A8510; // weak
//int dword_4A8514; // weak
//float flt_4A8518; // weak
int dword_4A870C; // weak
//int directionRotation_4A7D0C[3]; // weak
//int dword_4A8730; // weak
//float flt_4A87CC; // weak
//float absolutePositionX_4A7DB4[3]; // weak
//float absolutePositionY_4A7DB8[3]; // weak
//char byte_4A8828; // weak
//char byte_4A8829; // weak
//int dword_4A8870; // weak
//int dword_4A8874; // weak
//float flt_4A8878; // weak
int dword_4A8A6C; // weak
int dword_4A8A80; // weak
_UNKNOWN unk_4A8A8C; // weak
int dword_4A8A90[4]; // weak
//int dword_4A8A94; // weak
//int dword_4A8A98; // weak
//int dword_4A8A9C; // weak
int dword_4A8AA0; // weak
int dword_4A8AA4; // weak
float flt_4A8AC0[256]; // weak
float flt_4A8C00[256]; // weak
int dword_4A8D2C; // weak
int trxSHA7Bpk_4A8D40[1024]; // weak

int dword_4A9140; // weak
char smalfo4aBpk_4A9160[924]; // weak
float flt_4A9A60[256]; // weak
int circuitRecordMilliseconds_4A9B8C; // weak
int circuitLR1Bpk_width_4A9B90; // weak

BYTE circuitPalette_4A9BA0[768];
/*char byte_4A9BA0[256]; // weak //paleta del cicuito!
char byte_4A9BA1[256]; // weak
char byte_4A9BA2[256]; // weak*/
//int dword_4A7E68;//este no venia

int joystick_y_axis_default_4A9EA0; // weak
int dword_4A9EA4; // weak
int userRaceOrder_4A9EA8; // weak
int dword_4A9EAC; // weak
int ticksToPauseLapTimeInHud_4A9EB0; // weak

int joystick_y_axis_4A9EB8; // weak
char byte_4A9EC0; // weak
char byte_4A9EC1; // weak
char byte_4A9EC2; // weak
char byte_4A9EC3; // weak
char byte_4A9EC4; // weak
char byte_4A9EC5; // weak
char byte_4A9EC6; // weak
char byte_4A9EC7; // weak
char byte_4A9EC8; // weak
char byte_4A9EC9; // weak
char byte_4A9ECA; // weak
char byte_4A9ECB; // weak
char byte_4A9ECC; // weak
char byte_4A9ECD; // weak
char byte_4A9ECE; // weak
int trxLITTab_4A9EE0[257]; // weak
int trxSHA4Bpk_4A9FE0[1024]; // weak
int joystick_x_axis_default_4AA3E0; // weak
int dword_4AA3E4; // weak
void *shotsBpk; // idb
int dword_4AA3F0[4]; // weak
//int dword_4AA3F4; // weak
//int dword_4AA3F8; // weak
//int dword_4AA3FC; // weak
_UNKNOWN unk_4AA400; // weak
int dword_4AA500; // weak
int dword_4AA504; // weak
int framesAfterEndRaceOrCrash_4AA508; // weak
void *goalnum2Bpk_4AA50C; // idb
int trxSHA6Bpk_4AA520[1024]; // weak
void *trxLR1Bpk_4AA920; // idb
int dword_4AA924; // weak
int dword_4AA928; // weak
int dword_4AA92C; // weak
int boardsBPK_4AA940[4][2048]; // weak
//int boards2BPK_4AC340[2048]; // weak
//int boards3BPK_4ACB40[2048]; // weak
//int boards4BPK_4AD340[2048]; // weak
_UNKNOWN unk_4ADB40; // weak
int raceFlagWidth_4B3140; // weak
int dword_4B3144; // weak
int dword_4B3160[256]; // weak
_UNKNOWN unk_4B3404; // weak
void *burn1aBpk; // idb
void *obstacleBpk; // idb

/*paleta de circutiro que no se cual es*/
BYTE circuitPalette_4B4020[768]; // weak

/*paleta de circuito 2
_UNKNOWN unk_4B4020; // weak
_UNKNOWN unk_4B4021; // weak
*/

//int trxSCE2Bpk_4B4320[78808]; // weak
/*int trxSCE2Bpk_4B4320[315200]; // weak  //estructura de 788 *100*4
int numberTriangles_4B4324[256]; // weak
_WORD dword_4B4328[150]; // idb
int dword_4B4454[256]; // weak
int dword_4B4580[256]; // weak
int dword_4B46BC[256]; // weak
int dword_4B484C[256]; // weak
int dword_4B49DC[256]; // weak
BYTE polygonColour_4B4B6C[404]; // idb
_UNKNOWN unk_4B4D00; // weak
int dword_4B4D04[256]; // weak  //3152* 100 vueltas
int dword_4B4D08[256]; // weak
int dword_4B4D0C[256]; // weak
int dword_4B4E38[256]; // weak
int dword_4B4F64[256]; // weak
int dword_4B4F68[256]; // weak
int dword_4B4F6C[256]; // weak*/

int circuitRecordSeconds_501260; // weak
int dword_501264; // weak
float trxDRVDat_501280[2048]; // weak
_UNKNOWN unk_501680; // weak
int trxSHA2Bpk_501A80; // weak
char trxSKITab_501AA0[257]; // weak

//Estos son los powerups
/*int dword_501BA0[256]; // weak
int dword_501BA4[256]; // weak
int dword_501BA8[256]; // weak
int dword_501BAC[256]; // weak
int dword_501BB0[256]; // weak
_UNKNOWN unk_501BB4; // weak
_UNKNOWN unk_501BB8; // weak
_UNKNOWN unk_501BBC; // weak
_UNKNOWN unk_501BD0; // weak
_UNKNOWN unk_501CC8; // weak
_UNKNOWN unk_502930; // weak
_UNKNOWN unk_502A48; // weak
_UNKNOWN unk_502C94; // weak
_UNKNOWN unk_502DA0; // weak
_UNKNOWN unk_502DA4; // weak*/

int dword_503220; // weak
int lastCompletedLapTime_503224; // weak
_UNKNOWN unk_503228; // weak
_UNKNOWN unk_50322C; // weak
_UNKNOWN unk_503230; // weak
_UNKNOWN unk_503234; // weak
_UNKNOWN unk_503238; // weak
_UNKNOWN unk_50323C; // weak
int dword_503240[256]; // weak
void *blowiBpk; // idb
void *trxVaiBpk_5034D0; // idb
//char trxINFBin_5034E0[256]; // weak
int dword_5034F0; // weak
int dword_5034F4; // weak
void *circuitMatrixHxW_5034F8; // idb
void *participantCarBpk_5034FC; // idb
int dword_503500; // weak
int dword_503504; // weak
int circuitVaiBpk_height_503508; // weak
int dword_50350C; // weak
int dword_503510; // weak
int dword_503514; // weak
int currentDriverSelectedIndex_503518; // weak
int dword_50351C; // weak
int dword_508D20; // weak
int numberOfParticipants_508D24; // weak
int participantRaceOrderUserFirst_508D44[4]; // weak
//int dword_508D48; // weak
//int dword_508D4C; // weak
//int dword_508D50; // weak

int dword_508D6D; // weak
_UNKNOWN unk_509E60; // weak
_UNKNOWN unk_509E61; // weak
int circuitRecordMinutes_50A160; // weak
int totalRaceTime_50A164; // weak
void *damslidBpk; // idb
void *trxImaBpk_50A16C; // idb
int dword_50A170; // weak
/*int tetureWidth_50A180[4400]; // weak
int textureHeight_50A184[256]; // weak
int dword_50A18C[256]; // weak
int dword_50A190[256]; // weak
int dword_50A194[256]; // weak
int dword_50A198[256]; // weak
int dword_50A19C[256]; // weak
_UNKNOWN unk_50A1A8; // weak
*/

int dword_50B2B0; // weak
char ownnum1Bpk_503520[22528]; // weak

char othnum1Bpk_50B2C0[12672]; // weak
char posnum2Bpk_50E440[169]; // weak
int dword_50E540; // weak

RacePopupMemory2 racePopupMemory2[100];
/*
para los race popup
int dword_50E560[256]; // weak
_UNKNOWN unk_50E6F0; // weak
*/

void * flamesBpk[6]; // idb
/*void *flame2Bpk; // idb
void *flame3Bpk; // idb
void *flame4Bpk; // idb
void *flame5Bpk; // idb
void *flame6Bpk; // idb*/
int trxSHA1Bpk_50E718; // weak
int dword_50E71C; // weak
char smallbarBpk_50E720[2048]; // weak
//char byte_50E721[256]; // weak
int dword_50EF20; // weak

//esto es otra paleta de circuito
int circuitPaletteProcesed_50EF40[768]; // weak
/*_UNKNOWN unk_50EF44; // weak
int dword_50FB44; // weak*/

void   nullsub_1() {

}

int callRefreshOrExecuteBackgroundFunction_43C8F0()
{
  return refreshOrExecuteBackgroundFunction_43C850();
}

//----- (00401000) --------------------------------------------------------
void   allocateMemory(size_t Size)
{
  int v1=1; // eax@1

  v1 = malloc(Size);
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
}
// 45EA04: using guessed type int isMultiplayerGame;

//----- (00401060) --------------------------------------------------------
int initParticipantValues_401060()
{

  int v0; // ebp@2
///  int *v1; // ebx@2
//  int v2; // eax@3
//  int v3; // ecx@3
//  signed int v4; // edi@3
  int v5; // esi@3
  int v6; // ecx@3
//  signed int v7; // ST14_4@3
  double v8; // st7@3
//  int v9; // edi@3
  int v10; // edi@3
  double v11; // st7@3
  int v12; // ecx@3
  int v13; // eax@3
  bool v14; // zf@3
//  int v15; // eax@9
//  int v16; // edi@9
  double v17; // st7@36
  int v18; // ecx@36
  int v19; // ecx@36
  int result; // eax@45
  int indexRaceParticipantt; // [sp+Ch] [bp-4F0h]@1

  int arrayv35[24]= {360,370,430,460,510,440,450,460,470,520,510,520,530,580,600,240,280,330,380,440,120,130,140,230};
  int arrayv59[24] = {300,350,130,135,140,230,300,350,150,160,230,300,350,150,190,240,290,360,400};
	  //todo esto son posiciones de memoria :S
  //car sizes
  double arrayv29[6] ={8.3,9.7,9,10.5,8.5,9.2};
  double arrayv79[24] ={1.8,1.7,1.6,1.55,1.45,1.4,1.8,1.7,1.6,1.55,
	                   1.45,1.4,1.6,1.5,1.4,1.3,1.25,1.2,1.75,1.65,
					   1.55,1.5,1.4,1.35};
  double arrayv103[120] ={2.55,2.6,1,1,1,2.7,2.75,2.8,1,1,
	                     2.9,3,3.1,1,1,3.25,3.4,3.55,3.7,1,
						 3.7,3.8,3.9,4,1,4.05,4.1,4.2,4.25,4.3,
						 2.65,2.7,1,1,1,2.75,2.8,2.85,1,1,
						 2.95,3.05,3.15,1,1,3.4,3.5,3.6,3.7,1,
						 3.7,3.8,3.9,4,1,4.1,4.2,4.3,4.35,4.4,
						 2.8,2.85,1,1,1,2.95,3,3.05,1,1,
						 3.15,3.25,3.35,1,1,3.55,3.65,3.75,3.8,1,
						 3.8,3.9,4,4.1,1,4.2,4.3,4.4,4.5,4.6,
						 2.5,2.55,1,1,1,2.65,2.7,2.75,1,1,
						 2.8,2.85,2.9,1,1,3.1,3.2,3.3,3.4,1,
						 3.5,3.55,3.6,3.7,1,3.8,3.9,4,4.1,4.2};
   double arrayv223[120] ={0.5,0.3,0.1,1,1,0.5,0.3,0.1,1,1,
	                      0.8,0.6,0.4,0.2,1,0.8,0.6,0.4,0.2,1,
						  0.8,0.6,0.4,0.2,0,0.8,0.6,0.4,0.2,0,
						  0.5,0.3,0.1,1,1,0.5,0.3,0.1,1,1,
						  0.8,0.6,0.4,0.2,1,0.8,0.6,0.4,0.2,1,
						  0.8,0.6,0.4,0.2,0,0.8,0.6,0.4,0.2,0,
						  0.5,0.3,0.1,1,1,0.5,0.3,0.1,1,1,
						  0.8,0.6,0.4,0.2,1,0.8,0.6,0.4,0.2,1,
						  0.8,0.6,0.4,0.2,0,0.8,0.6,0.4,0.2,0,
						  0.5,0.3,0.1,1,1,0.55,0.3,0.1,1,1,
						  0.6,0.5,0.35,0.2,1,0.65,0.55,0.4,0.2,1,
						  0.75,0.6,0.4,0.2,0,0.75,0.6,0.4,0.2,0};

   double arrayDamageMultiplier[7] ={0.2,0.35,0.5,0.65,0.8,0.95,0.95}; 
   isCircuitReversed_456AA8 = raceParticipant[0].isCircuitReversed_4A7AA8;
 
  /*dword_4A6AE0[0] = 1045220557;
  dword_4A6AE4 = 1051931443;
  dword_4A6AE8 = 1056964608;
  dword_4A6AEC = 1059481190;
  dword_4A6AF0 = 1061997773;
  dword_4A6AF4 = 1064514355;
  dword_4A6AF8 = 1064514355;*/
  indexRaceParticipantt = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
  // v0 = (int)dword_4A689C; //28 de offset sobre la estructura
   
    do
    {

      v5 = 3 * raceParticipant[indexRaceParticipantt].difficulty;//9 como maximo
	  raceParticipant2[indexRaceParticipantt].carType = raceParticipant[indexRaceParticipantt].carType;
      
      v6 = raceParticipant[indexRaceParticipantt].carType + 2 * v5;//24 como tope por coche dificultad
      
      v8 = arrayv103[5 * v6 + raceParticipant[indexRaceParticipantt].engine];//23*5 + 4 posiciones =119
   //   if(debug==1) v8=2.5;
	  raceParticipant2[indexRaceParticipantt].efectiveEngine_4A6884 = v8;
      v10 = 5 * v6 + raceParticipant[indexRaceParticipantt].tire;
	  raceParticipant2[indexRaceParticipantt].efectiveEngineBackup_4A6888 = v8;
	  
      v11 = arrayv79[v6];//24 posiciones
	 // if(debug==1) v11=1.75;
      v12 = arrayv59[v6];//24 posiciones  //era v55 asi que no se
	 /// if(debug==1) v12=0x96;
	  raceParticipant2[indexRaceParticipantt].efectiveTire_4A688C = arrayv223[v10];//23*5 + 4 posiciones=119
	 // if(debug==1)  raceParticipant2[indexRaceParticipantt].efectiveTire_4A688C=1;
      v13 = v12 + arrayv35[ 5 * raceParticipant[indexRaceParticipantt].difficulty + raceParticipant[indexRaceParticipantt].armour];
      //if(debug==1) v13=0x186;
	  
	  v14 = indexRaceParticipantt == userRaceOrder_4A9EA8;
	  raceParticipant2[indexRaceParticipantt].efectiveArmour_4A689C = v13;
	  raceParticipant2[indexRaceParticipantt].steeringCapacity_4A6894 = 3.75 / (v11 - (double)raceParticipant[indexRaceParticipantt].engine * 0.05);
	  if ( v14 )
		  raceParticipant2[indexRaceParticipantt].efectiveArmour_4A689C = v13 + 100;
      if ( !memcmp(raceParticipant[indexRaceParticipantt].name, &dukeNukemName, 0xBu) )
		  raceParticipant2[indexRaceParticipantt].efectiveArmour_4A689C = raceParticipant2[indexRaceParticipantt].efectiveArmour_4A689C  * 2.2;
      if (raceParticipant2[indexRaceParticipantt].efectiveArmour_4A689C  > 900 )
		  raceParticipant2[indexRaceParticipantt].efectiveArmour_4A689C = 900;
      
      
	  raceParticipant2[indexRaceParticipantt].carSize_4A6890 =  arrayv29[raceParticipant[indexRaceParticipantt].carType];//6 posiciones
	  raceParticipant2[indexRaceParticipantt].damageBar_4A6898 = (100 - raceParticipant[indexRaceParticipantt].damage) << 10;
	  raceParticipant2[indexRaceParticipantt].rocket = raceParticipant[indexRaceParticipantt].rocket;
	  raceParticipant2[indexRaceParticipantt].spikes = raceParticipant[indexRaceParticipantt].spikes;
	  raceParticipant2[indexRaceParticipantt].mines = raceParticipant[indexRaceParticipantt].mines;
	  raceParticipant2[indexRaceParticipantt].useWeapons = raceParticipant[indexRaceParticipantt].useWeapons;
	  raceParticipant2[indexRaceParticipantt].weaponsBar_4A68B0 = 102400;
	  raceParticipant2[indexRaceParticipantt].turboBar_4A68B4 = 102400;
	  raceParticipant2[indexRaceParticipantt].moneyPicked = 0;//     *(_DWORD *)(v0 + 52) = 0;
	  raceParticipant2[indexRaceParticipantt].usingRocket_4A68D8 = 0; //*(_DWORD *)(v0 + 60) = 0;
	  raceParticipant2[indexRaceParticipantt].activeWeapon_4A68E0 = 0; //+68
      if ( !raceParticipant[indexRaceParticipantt].carType)//huele a coches
      {
		raceParticipant2[indexRaceParticipantt].weaponsNumber_4A68DC = 1;// *(_DWORD *)(v0 + 64) = 1;
		raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[0] = 22;
		raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[0]  = 8;
		raceParticipant2[indexRaceParticipantt].weaponFlameType[0] = 0; //huele a cartype pero ya esta asi que no se
      }
      if (raceParticipant[indexRaceParticipantt].carType == 1 )
      {
		raceParticipant2[indexRaceParticipantt].weaponsNumber_4A68DC = 1;
		raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[0] = -18; //+72
		raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[0] = 17; //+88
		raceParticipant2[indexRaceParticipantt].weaponFlameType[0] = 1;
      }
      if (raceParticipant[indexRaceParticipantt].carType == 2 )
      {
		 raceParticipant2[indexRaceParticipantt].weaponsNumber_4A68DC = 1;
		 raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[0] = -40;
		 raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[0] = 7;
		 raceParticipant2[indexRaceParticipantt].weaponFlameType[0] = 2;
      }
      if (raceParticipant[indexRaceParticipantt].carType == 3 )
      {
		  raceParticipant2[indexRaceParticipantt].weaponsNumber_4A68DC = 2;
		  raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[0] = 16;
		  raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[0] = 20;
		  
		raceParticipant2[indexRaceParticipantt].weaponFlameType[0] = 3; //104
		raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[1] = -17;
		raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[1] = 20; //92
		
		raceParticipant2[indexRaceParticipantt].weaponFlameType[1] = 3;
      }
      if (raceParticipant[indexRaceParticipantt].carType == 4 )
      {
		  raceParticipant2[indexRaceParticipantt].weaponsNumber_4A68DC = 2;
		  raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[0] = 16;
		  raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[0] = 19;
		  raceParticipant2[indexRaceParticipantt].weaponFlameType[0] = 4;
		raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[1] = -17; //76
		raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[1] = 19;
		raceParticipant2[indexRaceParticipantt].weaponFlameType[1] = 4;
      }
      if (raceParticipant[indexRaceParticipantt].carType == 5 )
      {
		  raceParticipant2[indexRaceParticipantt].weaponsNumber_4A68DC = 2;
		  raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[0] = 16;
		  raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[0] = 20;
		  raceParticipant2[indexRaceParticipantt].weaponFlameType[0] = 5;
		raceParticipant2[indexRaceParticipantt].weaponPosition_4A68E4[1] = -17;
		raceParticipant2[indexRaceParticipantt].weaponStrength_4A68F4[1] = 20;
		raceParticipant2[indexRaceParticipantt].weaponFlameType[1] = 5;
      }
      
    //  v0 += 148;
      ++indexRaceParticipantt;
    }
    while (indexRaceParticipantt < numberOfParticipants_508D24 );
  }
  //si es adversary
  if ( raceParticipant2[0].carType == 6 && !isMultiplayerGame )
  {
    if (raceParticipant2[userRaceOrder_4A9EA8].useWeapons )
		//if (dword_4A68AC[37 * userRaceOrder_4A9EA8])
    {
		
      if ( raceParticipant[0].difficulty )
      {
        if (raceParticipant[0].difficulty == 1 )
        {
			raceParticipant2[0].efectiveEngine_4A6884 = 4.6;
        }
        else if (raceParticipant[0].difficulty == 2 )
        {
			raceParticipant2[0].efectiveEngine_4A6884 = 4.7;
        }
        goto LABEL_36;
      }
      goto LABEL_35;
    }
    if (raceParticipant[0].difficulty)
    {
      if (raceParticipant[0].difficulty == 1 )
      {
		  raceParticipant2[0].efectiveEngine_4A6884 = 4.4;
      }
      else if (raceParticipant[0].difficulty == 2 )
      {
LABEL_35:
		  raceParticipant2[0].efectiveEngine_4A6884 = 4.5;
        goto LABEL_36;
      }
    }
    else
    {
		raceParticipant2[0].efectiveEngine_4A6884 = 4.3;
    }
LABEL_36:
	raceParticipant2[0].efectiveEngineBackup_4A6888 = raceParticipant2[0].efectiveEngine_4A6884;
    
    v17 = arrayv79[ 6 * raceParticipant[1].difficulty+1];//18 posiciones maximo (12)
    v18 = arrayv35[ 5 * raceParticipant[1].difficulty+4];//15 posiciones maximo (10) //v39
	raceParticipant2[0].damageBar_4A6898 = (100 - raceParticipant[0].damage) << 10;
    v19 = arrayv59[6 * raceParticipant[1].difficulty+4] + v18; //era v55
	raceParticipant2[0].efectiveTire_4A688C = 0;
	raceParticipant2[0].efectiveArmour_4A689C = v19;
	raceParticipant2[0].steeringCapacity_4A6894 = 3.75 / (v17 - (double)raceParticipant[0].engine * 0.05);///comprobar si es 0 o 1 el indice
	// if(debug==1)  raceParticipant2[indexRaceParticipantt].steeringCapacity_4A6894  =1;
    if ( v19 > 900 )
		raceParticipant2[0].efectiveArmour_4A689C = 900;
	raceParticipant2[0].rocket = raceParticipant[0].rocket;
	raceParticipant2[0].spikes = raceParticipant[0].spikes;
	raceParticipant2[0].mines = raceParticipant[0].mines;
	raceParticipant2[0].useWeapons = raceParticipant[0].useWeapons;
    raceParticipant2[0].weaponsBar_4A68B0 = 102400;
	raceParticipant2[0].turboBar_4A68B4 = 102400;
	raceParticipant2[0].carSize_4A6890 = 10.5;
	raceParticipant2[0].moneyPicked = 0;
	raceParticipant2[0].weaponsNumber_4A68DC = 2;
	raceParticipant2[0].weaponPosition_4A68E4[0] = 30;
	raceParticipant2[0].weaponStrength_4A68F4[0] = 19;
	raceParticipant2[0].weaponFlameType[1] = 4;
	raceParticipant2[0].weaponPosition_4A68E4[1] = -30;
	raceParticipant2[0].weaponStrength_4A68F4[1] = 19;
	raceParticipant2[0].weaponFlameType[1] = 4;
  }
  //esta copiando los colores de los 4 participantes
  raceParticipant2[0].r = raceParticipant[0].r;
  raceParticipant2[0].g = raceParticipant[0].g;
  raceParticipant2[0].b = raceParticipant[0].b;
  raceParticipant2[1].r = raceParticipant[1].r;
  raceParticipant2[1].g = raceParticipant[1].g;
  raceParticipant2[1].b = raceParticipant[1].b;
  raceParticipant2[2].r = raceParticipant[2].r;
  raceParticipant2[2].g = raceParticipant[2].g;
  raceParticipant2[2].b = raceParticipant[2].b;
  raceParticipant2[3].r = raceParticipant[3].r;
  raceParticipant2[3].g = raceParticipant[3].g;
  raceParticipant2[3].b = raceParticipant[3].b;
  
  //copiamos los nombres!
  strcpy(raceParticipant2[0].name, raceParticipant[0].name);
  strcpy(raceParticipant2[1].name, raceParticipant[1].name);
  strcpy(raceParticipant2[2].name, raceParticipant[2].name);
  strcpy(raceParticipant2[3].name, raceParticipant[3].name);
  result = 0;
  return result;
}

//----- (00402240) --------------------------------------------------------
int updateRacePositions()
{
//  int v0; // edi@1
//  signed int v1; // esi@1
  unsigned __int64 v2; // rax@2
  int v3; // ecx@2
  int result; // eax@2

  int indexRaceParticipant =0 ;
  //v0 = (int)dword_4A7AA0;
  //v1 = (signed int)&racePosition;
  do
  {
    v2 = (unsigned __int64)(100.0 - ceil((double)raceParticipant2[indexRaceParticipant].damageBar_4A6898 * 0.0009765625));
	v3 = raceParticipant2[indexRaceParticipant].moneyPicked;
	raceParticipant[indexRaceParticipant].damage = v2;
    result = raceParticipant2[indexRaceParticipant].racePosition;
    raceParticipant[indexRaceParticipant].racePosition= raceParticipant2[indexRaceParticipant].racePosition;
	raceParticipant[indexRaceParticipant].moneyPicked = v3;
    //v1 += 148;
   // v0 += 84;
	indexRaceParticipant++;
  }
  while (indexRaceParticipant < 4 );
  //while (v1 < (signed int)&unk_4A6B24);
  return result;
}

//----- (004022A0) --------------------------------------------------------
int sub_4022A0()
{
  int v0; // esi@1
  signed int v1; // ebx@1
  long double v2; // st7@2
  long double v3; // st6@2
  long double v4; // st7@2
  long double v5; // st6@2
  unsigned __int64 v6; // rax@3
  unsigned __int64 v7; // rax@6
  signed int v8; // eax@9
  int v9; // edx@11
  int v10; // eax@11
  int v11; // esi@13
  int v12; // eax@13
  int v13; // ecx@15
  int v14; // edx@15
  int v15; // eax@15
  int v16; // eax@15
  int result; // eax@15
  signed int v18; // [sp+10h] [bp-10h]@1
  double v19; // [sp+18h] [bp-8h]@2

  v18 = 11;
  v0 = 0;
  v1 = 162;
  do
  {
    v2 = (double)v18 * 0.01745329251994444;
    v3 = cos(v2);
    v19 = v3;
    v4 = sin(v2);
    v5 = v3 * -26.0 - v4;
    if ( v5 - (double)(signed int)(unsigned __int64)v5 < 0.5 )
      LODWORD(v6) = (unsigned __int64)v5;
    else
      v6 = (unsigned __int64)(1.0 - (v19 * 26.0 + v4));
    dword_503240[v0] = v6 + 30;
    if ( -25.0 * v4 - (double)(signed int)(unsigned __int64)(-25.0 * v4) < 0.5 )
      LODWORD(v7) = (unsigned __int64)(-25.0 * v4);
    else
      v7 = (unsigned __int64)(1.0 - v4 * 25.0);
    dword_4B3160[v0] = v7 + 27;
    ++v0;
    --v1;
    ++v18;
  }
  while ( v1 );
  v8 = 0;
  participantRaceOrderUserFirst_508D44[0] = userRaceOrder_4A9EA8;
  if ( !userRaceOrder_4A9EA8 )
    v8 = 1;
  v9 = v8;
  v10 = v8 + 1;
  participantRaceOrderUserFirst_508D44[1] = v9;
  if ( v10 == userRaceOrder_4A9EA8 )
    ++v10;
  v11 = v10;
  v12 = v10 + 1;
  participantRaceOrderUserFirst_508D44[2] = v11;
  if ( v12 == userRaceOrder_4A9EA8 )
    ++v12;
  participantRaceOrderUserFirst_508D44[3] = v12;
  v13 = (unsigned __int8)raceParticipantIngame[userRaceOrder_4A9EA8].racePosition_4A7E09;
  v14 = (unsigned __int8)raceParticipantIngame[v9].racePosition_4A7E09;
  v15 = (unsigned __int8)raceParticipantIngame[v12].racePosition_4A7E09;
  racePositionUserFirst_46E8D0[2] = (unsigned __int8)raceParticipantIngame[v11].racePosition_4A7E09;
  racePositionUserFirst_46E8D0[0] = v13;
  racePositionUserFirst_46E8D0[1] = v14;
  racePositionUserFirst_46E8D0[3] = v15;
  v16 = 7 * v15 - 7;
  dword_4AA3F0[2] = 7 * racePositionUserFirst_46E8D0[2] - 7;
  dword_4AA3F0[0] = 7 * v13 - 7;
  dword_4AA3F0[1] = 7 * v14 - 7;
  dword_4AA3F0[3] = v16;
  dword_4A7CC0[3] = 0;
  dword_4A7CC0[2] = 0;
  dword_4A7CC0[1] = 0;
  dword_4A7CC0[0] = 0;
  dword_4A9EA4 = 0;
  dword_4A8A90[2] = dword_4AA3F0[2] << 16;
  dword_4A8A90[3] = v16 << 16;
  result = dword_503500;
  dword_4A8A90[0] = dword_4AA3F0[0] << 16;
  dword_4A8A90[1] = dword_4AA3F0[1] << 16;
  dword_4A7CFC = dword_503500;
  return result;
}

//----- (00402490) --------------------------------------------------------
unsigned int showEndRaceFlag_402490()
{
  int v0; // eax@1
  unsigned int result; // eax@1

  raceFlagWidth_4B3140 = raceFlagWidth_4B3140 - dword_4A9EA4 <= 0 ? 0 : raceFlagWidth_4B3140 - dword_4A9EA4;
  drawInRaceImageToBuffer_43B160(
    (int)((char *)genflaBpk + 4800 * ((endRaceFlagFrame_481BE0 + 0x8000) >> 16)),
    80,
    60,
    dword_464F14 + raceFlagWidth_4B3140 + 336);
  v0 = dword_4AA500 + endRaceFlagFrame_481BE0;
  endRaceFlagFrame_481BE0 = v0;
  result = (v0 + 0x8000) & 0xFFFF0000;
  if ( (signed int)result > 4128768 )
    endRaceFlagFrame_481BE0 = 0;
  return result;
}

//----- (00402510) --------------------------------------------------------
unsigned int   writeTextInRace_402510(int a1, const char *a2)
{
  unsigned int v2; // esi@1
  unsigned int result; // eax@1
  int v4; // edi@2

  v2 = 0;
  result = strlen(a2);
  if ( result )
  {
    v4 = 0;
    do
    {
     drawImageInRace_43B240(&smalfo4aBpk_4A9160[36 * (a2[v2++] - 32)] , 6, 6, a1 + v4 + dword_464F14);
		//drawImageInRace_43B240(letterSpacing_4458B0[(a2[v2++] - 32)] , 6, 6, a1 + v4 + dword_464F14);
	 //smalfo4aBpk_4A9160
		
      v4 += 6;
      result = strlen(a2);
    }
    while ( v2 < result );
  }
  return result;
}
// 464F14: using guessed type int dword_464F14;

//----- (00402590) --------------------------------------------------------
int   drawSprite_402590(int baseImage, int width, int height, signed int a4, int spriteNumber, int a6, int a7, int a8)
{
  signed int v8; // eax@1
  int v9; // ebx@1
  int v10; // esi@4
  int v11; // esi@6
  int v12; // esi@12
  int v13; // esi@12
  int v14; // esi@15
  int v15; // esi@15
  int v16; // esi@15
  int v18; // [sp+20h] [bp+10h]@15
  int v19; // [sp+28h] [bp+18h]@12

  v8 = a4;
  v9 = height * width;
  if ( a4 >= 0 )
  {
    if ( a4 >= 10 )
    {
      v11 = a6;
      goto LABEL_8;
    }
  }
  else
  {
    a4 = 0;
    v8 = 0;
  }
  v10 = a6;
  if ( a7 > 0 )
  {
    drawImageInRace_43B240(baseImage + spriteNumber * v9, width, height, a6 - a7 + dword_464F14);
    v8 = a4;
    v10 = width + a6 - a7;
  }
  drawImageInRace_43B240(baseImage + v9 * (spriteNumber + v8), width, height, v10 + dword_464F14);
  v8 = a4;
  v11 = width + v10;
LABEL_8:
  if ( v8 > 9 && v8 < 100 )
  {
    if ( a7 > 0 )
      v11 += -2 * a7;
    v12 = a7 + v11;
    v19 = v8 % 10;
    drawImageInRace_43B240(baseImage + v9 * (spriteNumber + v8 / 10), width, height, v12 + dword_464F14);
    v13 = width + v12;
    drawImageInRace_43B240(baseImage + v9 * (spriteNumber + v19), width, height, v13 + dword_464F14);
    v8 = a4;
    v11 = width + v13;
  }
  if ( v8 > 99 && v8 < 1000 )
  {
    v14 = a8 + v11;
    v18 = v8 % 100;
    drawImageInRace_43B240(baseImage + v9 * (spriteNumber + v8 / 100), width, height, v14 + dword_464F14);
    v15 = width + v14;
    drawImageInRace_43B240(baseImage + v9 * (spriteNumber + v18 / 10), width, height, v15 + dword_464F14);
    v16 =width + v15;
    drawImageInRace_43B240(baseImage + v9 * (spriteNumber + v18 % 10), width, height, v16 + dword_464F14);
    v11 = width + v16;
  }
  return v11;
}
// 464F14: using guessed type int dword_464F14;

//----- (00402780) --------------------------------------------------------
void    errorExitScreen(int a1)
{
  setWindowCaption();
  printf("DEATH RALLY Error: %s\n", a1);
  printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
  nullsub_1();
  exit(112);
}

//----- (004027B0) --------------------------------------------------------
//int   extractFromBpa(char *bpaFilename, void *dest, char * filename)

//----- (00402CF0) --------------------------------------------------------
signed int loadCircuitPalette()
{
//  int v0; // eax@1
//  char v1; // cl@2
//  char *v2; // edi@3
//  char v3; // al@4
  void *v4; // ST1C_4@5
  signed int v5; // eax@5
//  char v6; // dl@6
//  char v7; // cl@6
  signed int result; // eax@7
//  int v9; // eax@8
//  char v10; // cl@9
//  char *v11; // edi@10
//  char v12; // al@11
//  int v13; // eax@12
//  char v14; // cl@13
//  char *v15; // edi@14
////  char v16; // al@15
//  FILE *v17; // eax@16
//  FILE *v18; // esi@16
//  char v19; // dl@19
//  char v20; // cl@19
//  char v21; // [sp-1h] [bp-311h]@3
  char Filename[16]; // [sp+0h] [bp-310h]@2
//  char DstBuf[768]; // [sp+10h] [bp-300h]@5
//  char v24; // [sp+11h] [bp-2FFh]@6
//  char v25[766]; // [sp+12h] [bp-2FEh]@6
  char paletteTmp[768];
  /*v0 = 0;
  do
  {
    v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
    Filename[v0++] = v1;
  }
  while ( v1 );
  v2 = &v21;
  do
    v3 = (v2++)[1];
  while ( v3 );
  *(_DWORD *)v2 = 1095584045;//-ima
  *((_DWORD *)v2 + 1) = 1263551022; //.bpk
  v2[8] = 0;*/

  v4 = trxImaBpk_50A16C;
  
  strcpy(Filename, raceFilePrefix_45EA50);
  strcat(Filename, "-IMA.BPK");
  extractFromBpa(circuitSelectedTR_464F50, v4, Filename);
  decryptTexture((int)trxImaBpk_50A16C, (int)circuitPalette_4A9BA0, 10, 768);
  v5 = 0;
  dword_481BE8 = 256;
/*do
  {
	
	circuitPalette_4A9BA0[v5] = paletteTmp[v5*3];
	circuitPalette_4A9BA0[v5+256] = paletteTmp[v5*3+1];
	circuitPalette_4A9BA0[v5+512] = paletteTmp[v5*3+2];
  /*  v6 = *(&v24 + v5);
    byte_4A9BA0[v5] = *(&DstBuf + v5);
    v7 = v25[v5];
    byte_4A9BA1[v5] = v6;
    byte_4A9BA2[v5] = v7;*/
 /*   v5 += 1;
  }
  while ( v5 < 768 );*/
 // isCircuitReversed_456AA8=1;
  /*do
  {
	

    v6 = *(&v24 + v5);
    byte_4A9BA0[v5] = *(&DstBuf + v5);
    v7 = v25[v5];
    byte_4A9BA1[v5] = v6;
    byte_4A9BA2[v5] = v7;
    v5 += 3;
  }
  while ( v5 < 768 );*/
  decryptTexture((int)trxImaBpk_50A16C, (int)circuitMatrixHxW_5034F8, 778, circuitWidth_464F40 * circuitHeight_4A7CF8); //esto tiene que se 768 porque es una paleta pero se saca del inf.bin!
  result = isCircuitReversed_456AA8;
  if ( isCircuitReversed_456AA8 )
  {
   /* v9 = 0;
    do
    {
      v10 = *((BYTE *)raceFilePrefix_45EA50 + v9);
      Filename[v9++] = v10;
    }
    while ( v10 );
    v11 = &v21;
    do
      v12 = (v11++)[1];
    while ( v12 );
    *(_DWORD *)v11 = 1229735469; //FLIP.pal
    *((_DWORD *)v11 + 1) = 1095773776;
    *((_WORD *)v11 + 4) = 76;
	*/
	strcpy(Filename, raceFilePrefix_45EA50);
	strcat(Filename, "-FLIP.PAL");
    extractFromBpa(circuitSelectedTR_464F50, circuitPalette_4A9BA0, Filename);
	
/*
	result = 0;
    dword_481BE8 = 256;
    do
    {
      v19 = *(&v24 + result);
      byte_4A9BA0[result] = *(&DstBuf + result);
      v20 = v25[result];
      byte_4A9BA1[result] = v19;
      byte_4A9BA2[result] = v20;
      result += 3;
    }
    while ( result < 768 );*/

   /*/aqui se mira un fichero qu eno existe para cargar la paleta!*/
	/* v13 = 0;
    do-
    {
      v14 = *((BYTE *)raceFilePrefix_45EA50 + v13);
      Filename[v13++] = v14;
    }
    while ( v14 );
    v15 = &v21;
    do
      v16 = (v15++)[1];
    while ( v16 );
    *(_DWORD *)v15 = 1229735469; //FLIP-SCX
    *((_DWORD *)v15 + 1) = 1129524816;
    *((_WORD *)v15 + 4) = 88;*/
	/*strcpy(Filename, raceFilePrefix_45EA50);
	strcat(Filename, "-FLIP-SCX"); ///esto esta mal fijo porque no existe
    v17 = fopen(Filename, "rb");
    v18 = v17;
    if ( v17 )
    {
      fseek(v17, 10, 0);
      fread(&DstBuf, 1u, 0x300u, v18);
      fclose(v18);
    }
    result = 0;
    dword_481BE8 = 256;
    do
    {
      v19 = *(&v24 + result);
      byte_4A9BA0[result] = *(&DstBuf + result);
      v20 = v25[result];
      byte_4A9BA1[result] = v19;
      byte_4A9BA2[result] = v20;
      result += 3;
    }
    while ( result < 768 );*/
  }
  return result;
}

//----- (00402EE0) --------------------------------------------------------
void loadCircuitImages1()
{
//  int v0; // eax@1
//  char v1; // cl@2
//  char *v2; // edi@3
//  char v3; // al@4
//  int v4; // eax@5
//  char v5; // cl@6
//  char *v6; // edi@7
//  char v7; // al@8
//  int v8; // eax@9
//  char v9; // cl@10
//  char *v10; // edi@11
//  char v11; // al@12
//  char v12; // [sp-1h] [bp-11h]@3
  BYTE v13[16]; // [sp+0h] [bp-10h]@2

 /* v0 = 0;
  do
  {
    v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
    v13[v0++] = v1;
  }
  while ( v1 );
  v2 = &v12;
  do
    v3 = (v2++)[1];
  while ( v3 );
  *(_DWORD *)v2 = 1396788525; //-mas
  *((_DWORD *)v2 + 1) = 1263551022; //.bpk
  v2[8] = 0;*/

  strcpy((char *)v13, raceFilePrefix_45EA50);
  strcat((char *)v13, "-MAS.BPK");

  extractFromBpa(circuitSelectedTR_464F50, textureTemp, (char *)v13);
  decryptTexture((int)textureTemp, (int)trxImaBpk_50A16C, 778, circuitWidth_464F40 * circuitHeight_4A7CF8);
 /* v4 = 0;
  do
  {
    v5 = *((BYTE *)raceFilePrefix_45EA50 + v4);
    v13[v4++] = v5;
  }
  while ( v5 );
  v6 = &v12;
  do
    v7 = (v6++)[1];
  while ( v7 );
  *(_DWORD *)v6 = 1229018669;
  *((_DWORD *)v6 + 1) = 1263551022;
  v6[8] = 0;*/
  strcpy((char *)v13, raceFilePrefix_45EA50);
  strcat((char *)v13, "-VAI.BPK");
  extractFromBpa(circuitSelectedTR_464F50, textureTemp, (char *)v13);
  decryptTexture((int)textureTemp, (int)trxVaiBpk_5034D0, 778, circuitVaiBpk_width_4A6858 * circuitVaiBpk_height_503508);
 /* v8 = 0;
  do
  {
    v9 = *((BYTE *)raceFilePrefix_45EA50 + v8);
    v13[v8++] = v9;
  }
  while ( v9 );
  v10 = &v12;
  do
    v11 = (v10++)[1];
  while ( v11 );
  *(_DWORD *)v10 = 827477037;
  *((_DWORD *)v10 + 1) = 1263551022;
  v10[8] = 0;
  */
  strcpy((char *)v13, raceFilePrefix_45EA50);
  strcat((char *)v13, "-LR1.BPK");
  extractFromBpa(circuitSelectedTR_464F50, textureTemp, (char *)v13);
  decryptTexture((int)textureTemp, (int)trxLR1Bpk_4AA920, 778, circuitLR1Bpk_width_4A9B90 * circuitLR1Bpk_height_467000);
}

//----- (00403050) --------------------------------------------------------
int loadCarsImages()
{
  int result; // eax@1
  
  int v2; // ebp@2
  signed int v3; // esi@3
  char *v4; // eax@3
  int v11; // ecx@13
  char filename[14];
  int indexRaceParticipant = 0;
  void *v12; // esi@14
  unsigned __int8 v13; // al@15
  
  
//  int v16; // [sp+Ch] [bp-10h]@3
  
  result = numberOfParticipants_508D24;
  
  if ( numberOfParticipants_508D24 > 0 )
  {
    v2 = 0;
    
    
    do
    {
      v3 = raceParticipant2[indexRaceParticipant].carType;
	  v4 = carName[raceParticipant2[indexRaceParticipant].carType];
	  //v4 = &aKupla[14 * *v15];
     /* v5 = (char *)((char *)&v16 - v4);
      do
      {
        v6 = *v4;
        v4[(_DWORD)v5] = *v4;
        ++v4;
      }
      while ( v6 );*/

	  //si no tiene spikes kupla , con spikes es kupla-s
      if (raceParticipant2[indexRaceParticipant].spikes != 1 || v3 >= 6 )
      {
		  strcpy(filename,carName[raceParticipant2[indexRaceParticipant].carType]);
		  strcat(filename, ".BPK");
		/*  v9 = raceParticipant2[indexRaceParticipant].efectiveTire_4A688C;
        do
          v10 = (v9++)[1];
        while ( v10 );
        *(_DWORD *)v9 = 1263551022;//bpk
        v9[4] = 0;*/
      }
      else
      {
		  strcpy(filename, carName[raceParticipant2[indexRaceParticipant].carType]);
		  strcat(filename, "-S.BPK");
        /*v7 = (char *)&v15 + 3;
        do
          v8 = (v7++)[1];
        while ( v8 );
        *(_DWORD *)v7 = 1110332205;//-s.b
        *((_WORD *)v7 + 2) = 19280; //pk
        v7[6] = 0;*/
      }
      extractFromBpa("ENGINE.BPA", textureTemp, filename);
      copyImageToBuffer((int)textureTemp, (int)((char *)participantCarBpk_5034FC + v2));
      v11 = v2;
      if ( __OFSUB__(v2, v2 + 153600) ^ 1 )
      {
        v12 = participantCarBpk_5034FC;
        do
        {
          v13 = *((BYTE *)v12 + v11);
          if ( v13 >= 0xFu && v13 <= 0x18u )
          {
            *((BYTE *)v12 + v11) += 10 * indexRaceParticipant;
            v12 = participantCarBpk_5034FC;
          }
          ++v11;
        }
        while ( v11 < v2 + 153600 );
      }
      result = numberOfParticipants_508D24;
      ++indexRaceParticipant;
      v2 += 153600;
      
    }
    while (indexRaceParticipant < numberOfParticipants_508D24 );
  }
  return result;
}

//----- (00403190) --------------------------------------------------------
void parseCircuitSceFile_403190()
{
//  int v0; // eax@1
//  char v1; // cl@2
//  char *v2; // edi@3
//  char v3; // al@4
  int v4; // eax@5
  
  int v7; // [sp-4h] [bp-14h]@10
  BYTE v8[16]; // [sp+0h] [bp-10h]@2

 /* v0 = 0;
  do
  {
    v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
    v8[v0++] = v1;
  }
  while ( v1 );
  v2 = (char *)&v5 + 3;
  do
    v3 = (v2++)[1];
  while ( v3 );
  *(_DWORD *)v2 = 1162040109;
  *((_DWORD *)v2 + 1) = 1263551022;
  v2[8] = 0;*/
  strcpy((char *)v8, raceFilePrefix_45EA50);
  strcat((char *)v8, "-SCE.BPK");
  extractFromBpa(circuitSelectedTR_464F50, textureTemp, (char *)v8);
  decryptTexture((int)textureTemp, (int)&trxSCE1Number3DObjects_479D20, 0, 1);
 // decryptTexture((int)textureTemp, (int)trxSCE2Bpk_4B4320, 1, 3152 * trxSCE1Number3DObjects_479D20 + 1);
  decryptTexture((int)textureTemp, &sce2Texture, 1, 3152 * trxSCE1Number3DObjects_479D20 + 1);
  decryptTexture((int)textureTemp, (int)&trxSCE3Bpk_464F10, 3152 * trxSCE1Number3DObjects_479D20 + 1, 1);
  v4 = trxSCE3Bpk_464F10;
  if ( 44 * trxSCE3Bpk_464F10 )
  {
	  decryptTexture((int)textureTemp, (int)sce4Texture, 3152 * trxSCE1Number3DObjects_479D20 + 2, 44 * trxSCE3Bpk_464F10);
    v4 = trxSCE3Bpk_464F10;
  }
  switch ( raceFilePrefix_45EA50[2] )
	  //switch (BYTE2(raceFilePrefix_45EA50[0]))
  {
    case 0x31u:
    case 0x32u:
		v7 = 390000;
      goto LABEL_10;
    case 0x30u:
    case 0x33u:
    case 0x34u:
    case 0x35u:
    case 0x36u:
    case 0x37u:
    case 0x38u:
    case 0x39u:
		v7 = 300000;
LABEL_10:
      decryptTexture((int)textureTemp, (int)trxSCE5Bpk_4A7A28, 3152 * trxSCE1Number3DObjects_479D20 + 44 * v4 + 2, v7);
      break;
    default:
      return;
  }
}

//----- (004032F0) --------------------------------------------------------
int loadCircuitTabFiles()
{
//  int v0; // eax@1
//  char v1; // cl@2
//  char *v2; // edi@3
//  char v3; // al@4
//  int v4; // eax@5
//  char v5; // cl@6
//  char *v6; // edi@7
//  char v7; // al@8
//  int v8; // eax@9
///  char v9; // cl@10
//  char *v10; // edi@11
  char v11; // al@12
//  char v13; // [sp-1h] [bp-11h]@3
  BYTE v14[16]; // [sp+0h] [bp-10h]@2

 /* v0 = 0;
  do
  {
    v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
    v14[v0++] = v1;
  }
  while ( v1 );
  v2 = &v13;
  do
    v3 = (v2++)[1];
  while ( v3 );
  *(_DWORD *)v2 = 1229673261;
  *((_DWORD *)v2 + 1) = 1111577646;
  v2[8] = 0;*/

  strcpy((char *)v14, raceFilePrefix_45EA50);
  strcat((char *)v14, "-SKI.TAB");
  extractFromBpa(circuitSelectedTR_464F50, trxSKITab_501AA0, (char *)v14);
 /* v4 = 0;
  do
  {
    v5 = *((BYTE *)raceFilePrefix_45EA50 + v4);
    v14[v4++] = v5;
  }
  while ( v5 );
  v6 = &v13;
  do
    v7 = (v6++)[1];
  while ( v7 );
  *(_DWORD *)v6 = 1330397741;
  *((_DWORD *)v6 + 1) = 1111577646;
  v6[8] = 0;*/
  strcpy((char *)v14, raceFilePrefix_45EA50);
  strcat((char *)v14, "-BLO.TAB");
  extractFromBpa(circuitSelectedTR_464F50, trxBLOTab_479D40, (char *)v14);
 /* v8 = 0;
  do
  {
    v9 = *((BYTE *)raceFilePrefix_45EA50 + v8);
    v14[v8++] = v9;
  }
  while ( v9 );
  v10 = &v13;
  do
    v11 = (v10++)[1];
  while ( v11 );
  *(_DWORD *)v10 = 1414089773;
  *((_DWORD *)v10 + 1) = 1111577646;
  v10[8] = 0;*/
  strcpy((char *)v14, raceFilePrefix_45EA50);
  strcat((char *)v14, "-LIT.TAB");
  extractFromBpa(circuitSelectedTR_464F50, &trxLITTab_4A9EE0, (char *)v14);
  return extractFromBpa("ENGINE.BPA", &trxVARJOTab_466F00, "VARJO.TAB");
}

//----- (00403410) --------------------------------------------------------
int loadCircuitDatFiles()
{
//  int v0; // eax@1
//  char v1; // cl@2
//  char *v2; // edi@3
//  char v3; // al@4
//  int v4; // eax@5
//  char v5; // cl@6
//  char *v6; // edi@7
//  char v7; // al@8
//  char v9; // [sp-1h] [bp-11h]@3
  BYTE v10[16]; // [sp+0h] [bp-10h]@2

  /*v0 = 0;
  do
  {
    v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
    v10[v0++] = v1;
  }
  while ( v1 );
  v2 = &v9;
  do
    v3 = (v2++)[1];
  while ( v3 );
  *(_DWORD *)v2 = 1448231981;
  *((_DWORD *)v2 + 1) = 1413563438;
  v2[8] = 0;*/
  strcpy((char *)v10, raceFilePrefix_45EA50);
  strcat((char *)v10, "-DRV.DAT");
  extractFromBpa(circuitSelectedTR_464F50, trxDRVDat_501280, (char *)v10);
  memcpy(flt_4796A0, &trxDRVDat_501280[400], 0x400u);
  dword_481BE8 = 256;
  /*v4 = 0;
  do
  {
    v5 = *((BYTE *)raceFilePrefix_45EA50 + v4);
    v10[v4++] = v5;
  }
  while ( v5 );
  v6 = &v9;
  do
    v7 = (v6++)[1];
  while ( v7 );
  *(_DWORD *)v6 = 1229475629;
  *((_DWORD *)v6 + 1) = 1413563438;
  v6[8] = 0;*/
  strcpy((char *)v10, raceFilePrefix_45EA50);
  strcat((char *)v10, "-OHI.DAT");
  return extractFromBpa(circuitSelectedTR_464F50, trxOHIDat_46EE00, (char *)v10);
}

//----- (004034F0) --------------------------------------------------------
void loadCircuitShadows()
{
//  int v0; // eax@1
//  char v1; // cl@2
//  char *v2; // edi@3
//  char v3; // al@4
//  char v4; // [sp-1h] [bp-11h]@3
  BYTE v5[16]; // [sp+0h] [bp-10h]@2

 /* v0 = 0;
  do
  {
    v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
    v5[v0++] = v1;
  }
  while ( v1 );
  v2 = &v4;
  do
    v3 = (v2++)[1];
  while ( v3 );
  *(_DWORD *)v2 = 1095258925;
  *((_DWORD *)v2 + 1) = 1263551022;
  v2[8] = 0;*/
  strcpy((char *)v5, raceFilePrefix_45EA50);
  strcat((char *)v5, "-SHA.BPK");

  extractFromBpa(circuitSelectedTR_464F50, textureTemp, (char *)v5);
  decryptTexture((int)textureTemp, (int)&trxSHA1Bpk_50E718, 0, 4);
  decryptTexture((int)textureTemp, (int)&trxSHA2Bpk_501A80, 4, 4);
  decryptTexture((int)textureTemp, (int)trxSHA3Bpk_479280, 8, 4 * trxSHA1Bpk_50E718);
  decryptTexture((int)textureTemp, (int)trxSHA4Bpk_4A9FE0, 4 * trxSHA1Bpk_50E718 + 8, 4 * trxSHA1Bpk_50E718);
  decryptTexture((int)textureTemp, (int)trxSHA5Bpk_478E60, 8 * trxSHA1Bpk_50E718 + 8, 4 * trxSHA1Bpk_50E718);
  decryptTexture((int)textureTemp, (int)trxSHA6Bpk_4AA520, 12 * trxSHA1Bpk_50E718 + 8, 4 * trxSHA2Bpk_501A80);
  decryptTexture((int)textureTemp, (int)trxSHA7Bpk_4A8D40, 4 * (trxSHA1Bpk_50E718 + trxSHA2Bpk_501A80 + 2 * trxSHA1Bpk_50E718) + 8, 4 * trxSHA2Bpk_501A80);
  decryptTexture((int)textureTemp, (int)trxSHA8Bpk_46E8E0, 12 * trxSHA1Bpk_50E718 + 8 * trxSHA2Bpk_501A80 + 8, 4 * trxSHA2Bpk_501A80);
}

//----- (00403670) --------------------------------------------------------
void loadEngineGraphics()
{
  extractFromBpa("ENGINE.BPA", textureTemp, "MINES1A.BPK");
  copyImageToBuffer((int)textureTemp, (int)mines1aBpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "BLOWI.BPK");
  copyImageToBuffer((int)textureTemp, (int)blowiBpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "FLAME1.BPK");
  copyImageToBuffer((int)textureTemp, (int)flamesBpk[0]);
  extractFromBpa("ENGINE.BPA", textureTemp, "FLAME2.BPK");
  copyImageToBuffer((int)textureTemp, (int)flamesBpk[1]);
  extractFromBpa("ENGINE.BPA", textureTemp, "FLAME3.BPK");
  copyImageToBuffer((int)textureTemp, (int)flamesBpk[2]);
  extractFromBpa("ENGINE.BPA", textureTemp, "FLAME4.BPK");
  copyImageToBuffer((int)textureTemp, (int)flamesBpk[3]);
  extractFromBpa("ENGINE.BPA", textureTemp, "FLAME5.BPK");
  copyImageToBuffer((int)textureTemp, (int)flamesBpk[4]);
  extractFromBpa("ENGINE.BPA", textureTemp, "FLAME6.BPK");
  copyImageToBuffer((int)textureTemp, (int)flamesBpk[5]);
  extractFromBpa("ENGINE.BPA", textureTemp,"SHOTS.BPK");
  copyImageToBuffer((int)textureTemp, shotsBpk);
  if ( isCircuitReversed_456AA8 )
    extractFromBpa("ENGINE.BPA", textureTemp,"OBST_REV.BPK");
  else
    extractFromBpa("ENGINE.BPA", textureTemp, "OBSTACLE.BPK");
  copyImageToBuffer((int)textureTemp, obstacleBpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "PEDESTR.BPK");
  copyImageToBuffer((int)textureTemp, pedestrBpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "SPLAT3.BPK");
  copyImageToBuffer((int)textureTemp, splat3Bpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "SPLAT4.BPK");
  copyImageToBuffer((int)textureTemp, splat4Bpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "ROCKET1.BPK");
  copyImageToBuffer((int)textureTemp, rocket1Bpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "ROCKET2.BPK");
  copyImageToBuffer((int)textureTemp, rocket2Bpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "BURN1A.BPK");
  copyImageToBuffer((int)textureTemp, burn1aBpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "SMOKE.BPK");
  copyImageToBuffer((int)textureTemp, smokeBpk);
}

//----- (00403910) --------------------------------------------------------
void loadEngineGraphics2()
{
  extractFromBpa("ENGINE.BPA", textureTemp, "GEN-MES.BPK");
  copyImageToBuffer((int)textureTemp, (int)genmesBpk);
  extractFromBpa("IBFILES.BPA", textureTemp, "DAMSLID.BPK");
  copyImageToBuffer((int)textureTemp, (int)damslidBpk);
}
// 481E20: using guessed type int textureTemp[];

//----- (00403960) --------------------------------------------------------

//----- (004039D0) --------------------------------------------------------

//----- (00403B30) --------------------------------------------------------

//----- (00403BB0) --------------------------------------------------------

//----- (00403D50) --------------------------------------------------------

//----- (00403E30) --------------------------------------------------------

//----- (00404610) --------------------------------------------------------
int noMemExitScreen()
{
  void *v0; // eax@1
  void *v1; // eax@5
  signed int v2; // esi@9
  signed int v3; // esi@11
  unsigned __int64 v4; // rax@12
  signed int v6; // [sp+0h] [bp-4h]@9
  signed int v7; // [sp+0h] [bp-4h]@11

	
  v0 = malloc(0x3844u);
  dword_4A6854 = v0;
 
  v1 = malloc(0x3844u);
  v2 = 0;
  dword_46F204 = v1;
  v6 = 0;
  do
  {
    *((_DWORD *)dword_4A6854 + v2++) = (unsigned __int64)(sin((double)v6 * 0.0175) * 1024.0);
    v6 = v2;
  }
  while ( v2 < 3600 );
  v3 = 0;
  v7 = 0;
  do
  {
    v4 = (unsigned __int64)(cos((double)v7 * 0.0175) * 1024.0);
    *((_DWORD *)dword_46F204 + v3++) = v4;
    v7 = v3;
  }
  while ( v3 < 3600 );
  return v4;
}
// 45EA04: using guessed type int isMultiplayerGame;

//----- (00404730) --------------------------------------------------------
char *sub_404730()
{
  int v0; // eax@1
  bool v1; // sf@1
  unsigned __int8 v2; // of@1
  int v3; // ebx@3
  int v4; // edx@3
  signed int v5; // eax@3
  char v6; // bp@4
  unsigned int v7; // ecx@4
  int v8; // edi@4
  const void *v9; // esi@4
  char *result; // eax@5
  signed int v11; // edi@5
  int v12; // ebp@5
  int v13; // edx@5
  int v14; // ecx@6
  int v15; // esi@8
  int v16; // ebx@8
  signed int v17; // esi@8
  int v18; // ebp@8
  signed int v19; // edx@13
  signed int v20; // ecx@13
  int v21; // edx@13
  signed int v22; // ecx@13
  int v23; // eax@17
  signed int v24; // [sp+0h] [bp-14h]@3
  int v25; // [sp+4h] [bp-10h]@5
  int v26; // [sp+8h] [bp-Ch]@1
  int v27; // [sp+8h] [bp-Ch]@8
  int v28; // [sp+Ch] [bp-8h]@3
  int v29; // [sp+10h] [bp-4h]@3

  v26 = screenPtr;
  v0 = dword_456AF4 + 3;
  v2 = __OFSUB__(dword_456AF4 + 3, 360);
  v1 = dword_456AF4 - 357 < 0;
  dword_456AF4 += 3;
  if ( !(v1 ^ v2) )
  {
    v0 -= 360;
    dword_456AF4 = v0;
  }
  v28 = 2 * *((_DWORD *)dword_4A6854 + 2 * v0) + 4000;
  v29 = 2 * *((_DWORD *)dword_4A6854 + v0 + 125) + 4000;
  v24 = v0;
  v3 = 2 * v0;
  v4 = 0;
  v5 = 0;
  do
  {
    v6 = leftMenuInRaceWidth_456AA0;
    v7 = (unsigned int)leftMenuInRaceWidth_456AA0 >> 2;
    v8 = v4 + screenPtr;
    v9 = (const void *)(v5 + dword_464F14 + 96);
    memcpy((void *)(v4 + screenPtr), v9, 4 * ((unsigned int)leftMenuInRaceWidth_456AA0 >> 2));
    v5 += 512;
    v4 += 320;
    memcpy((void *)(v8 + 4 * v7), (char *)v9 + 4 * v7, v6 & 3);
  }
  while ( v5 < 102400 );
  result = (char *)dword_4A6854;
  v11 = leftMenuInRaceWidth_456AA0;
  v12 = v26;
  v25 = 0;
  v13 = 4 * v3;
  do
  {
    v14 = v28 + v24;
    v24 += v28;
    if ( v24 >= 368640 )
    {
      v14 -= 368640;
      v24 = v14;
    }
    v15 = *(_DWORD *)&result[v13 + 4];
    v13 += 4;
    v16 = dword_456AF4 + 75;
    v17 = v15 << 8;
    v18 = v11 + v12;
    v27 = v13;
    if ( v11 < 320 )
    {
      while ( 1 )
      {
        ++v16;
        if ( v16 >= 360 )
          v16 -= 360;
        v19 = v14 + (*(_DWORD *)&result[4 * v16] << 8);
        v20 = *(_DWORD *)&result[4 * (v17 >> 10) + 1440];
        v17 += v29;
        v21 = *(_DWORD *)&result[4 * (v19 >> 10) + 1440] >> 7;
        v22 = v20 >> 8;
        if ( v17 >= 368640 )
          v17 -= 368640;
        if ( v22 + v11 < leftMenuInRaceWidth_456AA0 || v22 + v11 >= 319 || (v23 = v21 + v25, v21 + v25 < 0) || v23 >= 199 )
          sub_43C450(v18);
        else
          conver512to320_43C490(v18, v22 + dword_464F14 + (v23 << 9) + v11 + 96);
        result = (char *)dword_4A6854;
        v11 += 2;
        v18 += 2;
        if ( v11 >= 320 )
          break;
        v14 = v24;
      }
      v11 = leftMenuInRaceWidth_456AA0;
      v13 = v27;
    }
    v12 = v18 + 320;
    v2 = __OFSUB__(v25 + 2, 200);
    v1 = v25 - 198 < 0;
    v25 += 2;
  }
  while ( v1 ^ v2 );
  return result;
}
// 456AA0: using guessed type int leftMenuInRaceWidth_456AA0;
// 456AF4: using guessed type int dword_456AF4;
// 456BF0: using guessed type int screenPtr;
// 464F14: using guessed type int dword_464F14;

//----- (00404920) --------------------------------------------------------
int drawToBlackScreen()
{
  unsigned __int8 v0; // di@2
  signed int v1; // esi@2
  int result; // eax@4
  signed int v3; // [sp+8h] [bp-18h]@1
  double v4; // [sp+18h] [bp-8h]@2

  regenerateRacePalette(circuitPalette_4B4020);
  v3 = 40;
  do
  {
    v0 = 0;
	v1 = 0;
    //v1 = (signed int)&unk_4B4021;
    v4 = (double)v3;
    do
    {
      setPaletteAndGetValue(
        v0,
        (unsigned __int64)((double)circuitPalette_4B4020[v1] * (v4 * 0.025)),
        (unsigned __int64)((double)circuitPalette_4B4020[v1+1] * (v4 * 0.025)),
        (unsigned __int64)((double)circuitPalette_4B4020[v1+2]* (v4 * 0.025)));
      v1 += 3;
      ++v0;
	} while (v1 < maxPaletteEntries + 1 );
	//}while (v1 < (signed int)((char *)trxSCE2Bpk_4B4320 + 1));
    waitWithRefresh();
    setMusicVolume((unsigned __int64)(v4 * 1638.4));
    result = v3-- - 1;
  }
  while ( v3 >= 0 );
  return result;
}
// 4B4320: using guessed type int trxSCE2Bpk_4B4320[];

//----- (004049F0) --------------------------------------------------------
int setCircuitPalette_4B4020()
{
  unsigned __int8 v0; // bl@1
  //_UNKNOWN *v1; // edi@1
  signed int v2; // esi@1
  int v3; // eax@2
  int v4; // ST08_4@2
  int v5; // eax@2
  int v6; // ST00_4@2
  int result; // eax@2

  v0 = 0;
  //v1 = &unk_50EF44;
  //v2 = (signed int)&unk_4B4021;
  v2 = 0;
  do
  {
    setPaletteAndGetValue(v0, 0, 0, 0);
    v3 = colorToPaletteEntry(circuitPalette_4B4020[v2] << 16, 4128768);
    v4 = circuitPalette_4B4020[v2+1] << 16;
	circuitPaletteProcesed_50EF40[v2] = v3;
    v5 = colorToPaletteEntry(v4, 4128768);
    v6 = circuitPalette_4B4020[v2+2] << 16;
	circuitPaletteProcesed_50EF40[v2+1] = v5;
    result = colorToPaletteEntry(v6, 4128768);
	circuitPaletteProcesed_50EF40[v2+2] = result;
    v2 += 3;
    ++v0;
   // v1 = (char *)v1 + 12;
  }
  while (v2 < maxPaletteEntries + 1);
  //while ( v2 < (signed int)((char *)trxSCE2Bpk_4B4320 + 1) );
  return result;
}

//----- (00404A60) --------------------------------------------------------
int setCircuitPaletteBis_4B4020()
{
  //_UNKNOWN *v0; // edi@1
  signed int v1; // esi@1
  signed int v2; // eax@2
  signed int v3; // ST08_4@2
  signed int v4; // eax@2
  signed int v5; // ST00_4@2
  signed int result; // eax@2

  //v0 = &unk_50EF44;
 //v1 = (signed int)&unk_4B4021;
  v1 = 0;
  do
  {
    v2 = colorToPaletteEntry(circuitPalette_4B4020[v1] << 16, 4128768);
    v3 = circuitPalette_4B4020[v1+1] << 16;
	circuitPaletteProcesed_50EF40[v1] = v2;
    v4 = colorToPaletteEntry(v3, 4128768);
    v5 = circuitPalette_4B4020[v1+2] << 16;
	circuitPaletteProcesed_50EF40[v1+1] = v4;
    result = colorToPaletteEntry(v5, 4128768);
	circuitPaletteProcesed_50EF40 [v1+2]= result;
    v1 += 3;
   // v0 = (char *)v0 + 12;
  }
  while (v1 < maxPaletteEntries + 1);
  //while ( v1 < (signed int)((char *)trxSCE2Bpk_4B4320 + 1) );
  return result;
}
// 4B4320: using guessed type int trxSCE2Bpk_4B4320[];

//----- (00404AD0) --------------------------------------------------------
int setCircuitPaletteTransitionToBlack_4B4020()
{
  int v0; // eax@1
  int v1; // ebp@1
  signed int v2; // ebx@1
  int v3; // esi@3
  int v4; // edi@3
  int v5; // eax@3
  int result; // eax@3
  int v7; // [sp+10h] [bp-4h]@1

  v0 = dword_456AF8++ + 1;
  v7 = 0;
  //v1 = &unk_4B4021;
  v1 = 0;
  //v2 = (signed int)&unk_50EF44;
  while ( 1 )
  {
    v3 = ((circuitPalette_4B4020[v1] << 16) - convertColorToPaletteColor(circuitPaletteProcesed_50EF40[v1], v0 << 16) + 0x8000) >> 16;
    v4 =((circuitPalette_4B4020[v1+1] << 16) - convertColorToPaletteColor(circuitPaletteProcesed_50EF40[v1+1], dword_456AF8 << 16) + 0x8000) >> 16;
    v5 = convertColorToPaletteColor(circuitPaletteProcesed_50EF40[v1+2], dword_456AF8 << 16);
    result = setPaletteAndGetValue(v7, v3, v4, ((circuitPalette_4B4020[v1+2] << 16) - v5 + 0x8000) >> 16);
    //v2 += 12;
    //v1 = (char *)v1 + 3;
	v1 += 3;
    ++v7;
	if (v1 > 768)
		break;

    //if ( v2 >= (signed int)&dword_50FB44 )
      //break;
    v0 = dword_456AF8;
  }
  return result;
}
// 456AF8: using guessed type int dword_456AF8;
// 50FB44: using guessed type int dword_50FB44;

//----- (00404BA0) --------------------------------------------------------
int setCircuitPaletteTransitionToOriginal_4B4020()
{
  int v0; // eax@1
  unsigned __int8 v1; // bp@1
  signed int v2; // esi@1
  int v3; // edi@3
  int v4; // ebx@3
  int v5; // eax@3
  int result; // eax@3

  v0 = dword_456AF8++ + 1;
  v1 = 0;
  v2 = 0;
  //v2 = (signed int)&unk_50EF44;
  while ( 1 )
  {
    v3 = (convertColorToPaletteColor(circuitPaletteProcesed_50EF40[v2], v0 << 16) + 0x8000) >> 16;
    v4 = (convertColorToPaletteColor(circuitPaletteProcesed_50EF40[v2+1], dword_456AF8 << 16) + 0x8000) >> 16;
    v5 = convertColorToPaletteColor(circuitPaletteProcesed_50EF40[v2+2], dword_456AF8 << 16);
    result = setPaletteAndGetValue(v1, v3, v4, (v5 + 0x8000) >> 16);
    v2 += 3;
    ++v1;
	if (v2 > 768)
		break;
    //if ( v2 >= (signed int)&dword_50FB44 )
      //break;
    v0 = dword_456AF8;
  }
  return result;
}
// 456AF8: using guessed type int dword_456AF8;
// 50FB44: using guessed type int dword_50FB44;

//----- (00404C30) --------------------------------------------------------
int sub_404C30()
{
  signed int v0; // ebx@1
  int v1; // ecx@1
  int v2; // ebp@2
  _UNKNOWN *v3; // edi@2
  signed int v4; // esi@2
  int v5; // edx@5
  int v6; // ST34_4@5
  int v7; // edx@5
  double v8; // st7@6
  int v9; // ebx@9
  signed int v10; // eax@9
  int v11; // edx@9
  void *v12; // edi@10
  const void *v13; // esi@10
  signed int v14; // eax@11
  int v15; // edx@11
  void *v16; // edi@12
  const void *v17; // esi@12
  unsigned __int8 v18; // di@14
  signed int v19; // esi@14
  signed int v20; // eax@16
  long double v21; // st7@18
  int v22; // ebp@18
  signed int v23; // ebx@18
  unsigned __int64 v24; // rax@19
  char *v25; // esi@19
  int v26; // edi@19
  int v27; // eax@20
  signed int v28; // esi@20
  unsigned int v29; // eax@21
  double v30; // st7@25
  int v31; // eax@25
  double v32; // st7@28
  signed int v33; // esi@31
  signed int v34; // ebp@34
  signed int v35; // esi@35
  signed int v36; // edi@35
  signed int v37; // ebx@35
  int v38; // ecx@41
  bool v39; // zf@45
  bool v40; // sf@45
  unsigned __int8 v41; // of@45
  signed int v42; // ebp@46
  signed int v43; // ebx@47
  signed int v44; // esi@48
  signed int v45; // edi@48
  signed int v46; // eax@48
  signed int v47; // esi@59
  int v48; // edx@62
  int v49; // ecx@62
  signed int v50; // ebp@62
  signed int v51; // ST40_4@65
  signed int v52; // ST44_4@65
  unsigned __int64 v53; // rax@65
  int result; // eax@68
  int v55; // [sp+14h] [bp-1Ch]@34
  int v56; // [sp+14h] [bp-1Ch]@47
  int v57; // [sp+14h] [bp-1Ch]@62
  signed int v58; // [sp+18h] [bp-18h]@33
  signed int v59; // [sp+18h] [bp-18h]@46
  int v60; // [sp+18h] [bp-18h]@61
  int v61; // [sp+1Ch] [bp-14h]@1
  signed int v62; // [sp+1Ch] [bp-14h]@33
  signed int v63; // [sp+1Ch] [bp-14h]@61
  double v64; // [sp+28h] [bp-8h]@34
  double v65; // [sp+28h] [bp-8h]@47

  memcpy(&unk_509E60, circuitPalette_4A9BA0, 0x300u);
  v0 = 0;
  v1 = 10 * userRaceOrder_4A9EA8;
  v61 = 10 * userRaceOrder_4A9EA8;
  do
  {
    v2 = 0;
    v3 = &unk_4B3404;
    v4 = (signed int)&unk_509E61;
    do
    {
      if ( v2 < v1 + 15
        || v2 > v1 + 24
        || (v5 = v0 * *(BYTE *)v4,
            *((float *)v3 - 1) = (double)((v0 * *(BYTE *)(v4 - 1) + 128) >> 8) * 0.011111111,
            v6 = (v5 + 128) >> 8,
            v7 = v0 * *(BYTE *)(v4 + 1),
            *(float *)v3 = (double)v6 * 0.011111111,
            *((float *)v3 + 1) = (double)((v7 + 128) >> 8) * 0.011111111,
            v2 > v1 + 24) )
      {
        v1 = v61;
        v8 = (double)((signed int)(v0
                                 * (unsigned __int64)(((double)*(BYTE *)(v4 + 1) * 11.3
                                                     + (double)*(BYTE *)(v4 - 1) * 29.9
                                                     + (double)*(BYTE *)v4 * 58.8)
                                                    * 0.01)
                                 + 128) >> 8)
           * 0.011111111;
        *((float *)v3 - 1) = v8;
        *(float *)v3 = v8;
        *((float *)v3 + 1) = v8;
      }
      v4 += 3;
      ++v2;
      v3 = (char *)v3 + 12;
    }
    while ( v4 < (signed int)((char *)&circuitRecordMinutes_50A160 + 1) );
    v0 += 8;
  }
  while ( v0 < 256 );
  memset((void *)screenPtr, 0, 0xFA00u);
  v9 = dword_464F14;
  v10 = (signed int)textureTemp;
  v11 = dword_464F14 + 160;
  do
  {
    v12 = (void *)v10;
    v13 = (const void *)v11;
    v10 += 256;
    v11 += 512;
    memcpy(v12, v13, 0x100u);
  }
  while ( v10 < (signed int)&unk_48E620 );
  v14 = (signed int)&unk_48E720;
  v15 = v9 + 96;
  do
  {
    v16 = (void *)v14;
    v17 = (const void *)v15;
    v14 += 64;
    v15 += 512;
    memcpy(v16, v17, 0x40u);
  }
  while ( v14 < (signed int)&unk_491920 );
  memset(&unk_48E620, 0, 0x100u);
  dword_4A9EAC = 0;
  dword_44509C = 1063675494;
  dword_4450A0 = 1065353216;
  while ( 1 )
  {
    v18 = 0;
    v19 = (signed int)&unk_4B3404;
    do
    {
      setPaletteAndGetValue(
        v18,
        (unsigned __int64)(*(float *)&dword_4450A0 * *(float *)(v19 - 4)),
        (unsigned __int64)(*(float *)&dword_4450A0 * *(float *)v19),
        (unsigned __int64)(*(float *)&dword_4450A0 * *(float *)(v19 + 4)));
      v19 += 12;
      ++v18;
    }
    while ( v19 < (signed int)&obstacleBpk );
    v20 = 728 * (unsigned __int64)*(float *)&dword_4450A0;
    if ( v20 > 0xFFFF )
      v20 = 0xFFFF;
    setMusicVolume(v20);
    v21 = *(float *)&dword_4450A0 * 0.01745329251994444;
    dword_50A170 = screenPtr + 64;
    dword_481E00 = (unsigned __int64)(51200.0 / (sin(v21) * 200.0));
    v22 = 0;
    dword_503514 = (unsigned __int64)(cos(v21) * 170.0);
    dword_4A7CD0 = 0;
    v23 = 0;
    do
    {
      v24 = (unsigned __int64)(*(float *)&dword_4450A0 * 0.7142857142857143);
      v25 = (char *)&unk_48E760 + v23 - v24;
      v26 = screenPtr + v22;
      memcpy((void *)(screenPtr + v22), v25, 4 * ((unsigned int)v24 >> 2));
      v23 += 64;
      v22 += 320;
      memcpy((void *)(v26 + 4 * ((unsigned int)v24 >> 2)), &v25[4 * ((unsigned int)v24 >> 2)], v24 & 3);
    }
    while ( v23 < 12800 );
    v27 = dword_4A7CD0;
    v28 = 200;
    do
    {
      v29 = v27 & 0xFFFFFF00;
      dword_464F20 = v29;
      if ( (signed int)v29 > 51200 )
      {
        v29 = 51200;
        dword_464F20 = 51200;
      }
      dword_4A7A24 = (signed int)(dword_503514 * v29) >> 16;
      sub_43B030(dword_50A170, ((signed int)(dword_503514 * v29) >> 17) - 10);
      sub_43B370(
        dword_50A170 + (dword_4A7A24 >> 1),
        (int)((char *)&textureTemp[0] + dword_464F20 - 1),
        255 - dword_4A7A24);
      sub_43B050(dword_50A170, (dword_4A7A24 >> 1) - dword_4A7A24 + 255);
      v27 = dword_481E00 + dword_4A7CD0;
      --v28;
      dword_50A170 += 320;
      dword_4A7CD0 += dword_481E00;
    }
    while ( v28 );
    if ( *(float *)&dword_4450A0 == 90.0 )
      break;
    v30 = *(float *)&dword_44509C;
    v31 = 0;
    if ( dword_4A9EAC >= 0 )
    {
      do
      {
        v30 = v30 * 1.02;
        ++v31;
      }
      while ( v31 <= dword_4A9EAC );
      *(float *)&dword_44509C = v30;
    }
    v32 = v30 + *(float *)&dword_4450A0;
    *(float *)&dword_4450A0 = v32;
    if ( v32 > 90.0 )
      dword_4450A0 = 1119092736;
    dword_4A9EAC = 0;
    waitWithRefresh();
  }
  v33 = 20;
  do
  {
    waitWithRefresh();
    --v33;
  }
  while ( v33 );
  v58 = 256;
  v62 = 0;
  do
  {
    v55 = 0;
    v34 = (signed int)&unk_509E61;
    v64 = (double)v62;
    do
    {
      v35 = (signed int)(v58 * *(BYTE *)(v34 - 1) - (unsigned __int64)((double)*(BYTE *)(v34 - 1) * v64 * -1.7) + 128) >> 8;
      v36 = (signed int)(v58 * *(BYTE *)v34 - (unsigned __int64)((double)*(BYTE *)v34 * v64 * -1.7) + 128) >> 8;
      v37 = (signed int)(v58 * *(BYTE *)(v34 + 1) - (unsigned __int64)((double)*(BYTE *)(v34 + 1) * v64 * -1.7) + 128) >> 8;
      if ( v35 > 63 )
        LOBYTE(v35) = 63;
      if ( v36 > 63 )
        LOBYTE(v36) = 63;
      if ( v37 > 63 )
        LOBYTE(v37) = 63;
      v38 = v55;
      if ( v55 >= 10 * userRaceOrder_4A9EA8 + 15 && v55 <= 10 * userRaceOrder_4A9EA8 + 24 )
      {
        setPaletteAndGetValue(v55, v35, v36, v37);
        v38 = v55;
      }
      v34 += 3;
      v55 = v38 + 1;
    }
    while ( v34 < (signed int)((char *)&circuitRecordMinutes_50A160 + 1) );
    waitWithRefresh();
    v41 = __OFSUB__(v62 + 50, 256);
    v39 = v62 == 206;
    v40 = v62 - 206 < 0;
    v58 -= 50;
    v62 += 50;
  }
  while ( (unsigned __int8)(v40 ^ v41) | v39 );
  v59 = 256;
  v42 = 0;
  do
  {
    v56 = 0;
    v43 = (signed int)&unk_509E61;
    v65 = (double)v59;
    do
    {
      v44 = (signed int)(*(BYTE *)(v43 - 1) * v42 - (unsigned __int64)((double)*(BYTE *)(v43 - 1) * v65 * -1.7) + 128) >> 8;
      v45 = (signed int)(*(BYTE *)v43 * v42 - (unsigned __int64)((double)*(BYTE *)v43 * v65 * -1.7) + 128) >> 8;
      v46 = (signed int)(*(BYTE *)(v43 + 1) * v42 - (unsigned __int64)((double)*(BYTE *)(v43 + 1) * v65 * -1.7) + 128) >> 8;
      if ( v44 > 63 )
        LOBYTE(v44) = 63;
      if ( v45 > 63 )
        LOBYTE(v45) = 63;
      if ( v46 > 63 )
        LOBYTE(v46) = 63;
      if ( v56 >= 10 * userRaceOrder_4A9EA8 + 15 && v56 <= 10 * userRaceOrder_4A9EA8 + 24 )
        setPaletteAndGetValue(v56, v44, v45, v46);
      v43 += 3;
      ++v56;
    }
    while ( v43 < (signed int)((char *)&circuitRecordMinutes_50A160 + 1) );
    waitWithRefresh();
    v42 += 10;
    v59 -= 10;
  }
  while ( v42 <= 256 );
  v47 = 50;
  do
  {
    waitWithRefresh();
    --v47;
  }
  while ( v47 );
  v60 = 0;
  v63 = 256;
  do
  {
    v48 = userRaceOrder_4A9EA8;
    v49 = 0;
    v57 = 0;
    v50 = (signed int)&unk_509E61;
    do
    {
      if ( v49 < 10 * v48 + 15 || v49 > 10 * v48 + 24 )
      {
        v51 = *(BYTE *)(v50 - 1);
        v52 = *(BYTE *)v50;
        v53 = (unsigned __int64)(((double)*(BYTE *)(v50 + 1) * 11.3 + (double)v51 * 29.9 + (double)v52 * 58.8) * 0.01);
        HIDWORD(v53) = v60 * v52 + v53 * v63 + 128;
        setPaletteAndGetValue(
          v57,
          (unsigned __int16)(v60 * v51 + v53 * v63 + 128) >> 8,
          SBYTE5(v53),
          (unsigned __int16)(v60 * *(BYTE *)(v50 + 1) + v53 * v63 + 128) >> 8);
        v48 = userRaceOrder_4A9EA8;
        v49 = v57;
      }
      ++v49;
      v50 += 3;
      v57 = v49;
    }
    while ( v50 < (signed int)((char *)&circuitRecordMinutes_50A160 + 1) );
    waitWithRefresh();
    v39 = v63 == 8;
    v40 = v63 - 8 < 0;
    v60 += 8;
    v63 -= 8;
  }
  while ( !v40 && !v39 );
  dword_4A9EAC = 0;
  dword_503510 = 0;
  result = dword_4A8D2C;
  dword_503500 = dword_4A8D2C;
  dword_456AF8 = 63;
  dword_4A7CFC = dword_4A8D2C;
  return result;
}

//----- (00405430) --------------------------------------------------------
int sub_405430()
{
  int v0; // edx@1
  signed int v1; // eax@1
  char *v2; // edi@2
  const void *v3; // esi@2
  long double v4; // st7@3
  unsigned __int64 v5; // rax@3
  int v6; // esi@3
  int result; // eax@3
  unsigned int v8; // eax@4
  bool v9; // sf@6
  unsigned __int8 v10; // of@6

  v0 = dword_464F14;
  v1 = 0;
  dword_481BE8 = 0;
  do
  {
    v2 = (char *)&unk_481F20 + 256 * v1;
    v3 = (const void *)((v1++ << 9) + v0 + 160);
    memcpy(v2, v3, 0x100u);
    dword_481BE8 = v1;
  }
  while ( v1 < 200 );
  v4 = *(float *)&dword_4450A0 * 0.01745329251994444;
  dword_50A170 = screenPtr + 32;
  v5 = (unsigned __int64)(51200.0 / (sin(v4) * 200.0));
  v6 = v5;
  dword_481E00 = v5;
  dword_503514 = (unsigned __int64)(cos(v4) * 170.0);
  result = 200 * v5;
  dword_4A7CD0 = 200 * v6;
  dword_481BE8 = 0;
  do
  {
    v8 = result & 0xFFFFFF00;
    dword_464F20 = v8;
    if ( (signed int)v8 > 51456 )
    {
      v8 = 51456;
      dword_464F20 = 51456;
    }
    dword_4A7A24 = (signed int)(dword_503514 * v8) >> 16;
    sub_43B030(dword_50A170, ((signed int)(dword_503514 * v8) >> 17) - 10);
    sub_43B370(dword_50A170 + (dword_4A7A24 >> 1), (int)((char *)&unk_48E720 - dword_464F20), 255 - dword_4A7A24);
    sub_43B050(dword_50A170, (dword_4A7A24 >> 1) - dword_4A7A24 + 255);
    dword_50A170 += 320;
    result = dword_4A7CD0 - dword_481E00;
    v10 = __OFSUB__(dword_481BE8 + 1, 200);
    v9 = dword_481BE8 - 199 < 0;
    dword_4A7CD0 -= dword_481E00;
    ++dword_481BE8;
  }
  while ( v9 ^ v10 );
  return result;
}

//----- (004055A0) --------------------------------------------------------
int sub_4055A0()
{
  _UNKNOWN *v0; // ecx@1
  signed int v1; // eax@1
  signed int v2; // ST3C_4@2
  signed int v3; // edx@2
  double v4; // st7@2
  signed int v5; // ST3C_4@2
  signed int v6; // edx@2
  double v7; // st7@2
  signed int v8; // ST3C_4@2
  signed int v9; // edx@2
  double v10; // st7@2
  signed int v11; // ST3C_4@2
  signed int v12; // edx@2
  double v13; // st7@2
  signed int v14; // ST3C_4@2
  signed int v15; // edx@2
  double v16; // st7@2
  signed int v17; // ST3C_4@2
  signed int v18; // edx@2
  double v19; // st7@2
  signed int v20; // ST3C_4@2
  signed int v21; // edx@2
  double v22; // st7@2
  signed int v23; // ST3C_4@2
  signed int v24; // edx@2
  double v25; // st7@2
  signed int v26; // ST3C_4@2
  signed int v27; // edx@2
  double v28; // st7@2
  signed int v29; // ST3C_4@2
  signed int v30; // edx@2
  double v31; // st7@2
  signed int v32; // ST3C_4@2
  signed int v33; // edx@2
  double v34; // st7@2
  signed int v35; // ST3C_4@2
  signed int v36; // edx@2
  double v37; // st7@2
  signed int v38; // ST3C_4@2
  signed int v39; // edx@2
  double v40; // st7@2
  signed int v41; // ST3C_4@2
  signed int v42; // edx@2
  double v43; // st7@2
  signed int v44; // ST3C_4@2
  signed int v45; // edx@2
  double v46; // st7@2
  signed int v47; // ST3C_4@2
  signed int v48; // edx@2
  double v49; // st7@2
  signed int v50; // ST3C_4@2
  signed int v51; // edx@2
  double v52; // st7@2
  signed int v53; // ST3C_4@2
  signed int v54; // edx@2
  double v55; // st7@2
  signed int v56; // ST3C_4@2
  signed int v57; // edx@2
  double v58; // st7@2
  signed int v59; // ST3C_4@2
  signed int v60; // edx@2
  double v61; // st7@2
  signed int v62; // ST3C_4@2
  signed int v63; // edx@2
  int v64; // ebx@3
  signed int v65; // eax@3
  int v66; // edx@3
  void *v67; // edi@4
  const void *v68; // esi@4
  signed int v69; // eax@5
  int v70; // edx@5
  void *v71; // edi@6
  const void *v72; // esi@6
  _UNKNOWN *v73; // edx@7
  signed int v74; // eax@7
  void *v75; // ebp@8
  unsigned __int8 v76; // di@10
  signed int v77; // esi@10
  long double v78; // st7@12
  int v79; // ebp@12
  signed int v80; // ebx@12
  unsigned __int64 v81; // rax@13
  char *v82; // esi@13
  void *v83; // edi@13
  signed int v84; // esi@14
  unsigned int v85; // ebx@15
  void *v86; // edi@15
  int v87; // eax@16
  signed int v88; // esi@16
  unsigned int v89; // eax@17
  double v90; // st7@21
  int v91; // eax@21
  double v92; // st7@24
  signed int v93; // ST3C_4@27
  signed int v94; // edx@27
  double v95; // st7@27
  signed int v96; // ST3C_4@27
  signed int v97; // edx@27
  double v98; // st7@27
  signed int v99; // ST3C_4@27
  signed int v100; // edx@27
  double v101; // st7@27
  signed int v102; // ST3C_4@27
  signed int v103; // edx@27
  double v104; // st7@27
  signed int v105; // ST3C_4@27
  signed int v106; // edx@27
  double v107; // st7@27
  signed int v108; // ST3C_4@27
  signed int v109; // edx@27
  double v110; // st7@27
  signed int v111; // ST3C_4@27
  signed int v112; // edx@27
  double v113; // st7@27
  signed int v114; // ST3C_4@27
  signed int v115; // edx@27
  double v116; // st7@27
  signed int v117; // ST3C_4@27
  signed int v118; // edx@27
  double v119; // st7@27
  signed int v120; // ST3C_4@27
  signed int v121; // edx@27
  double v122; // st7@27
  signed int v123; // ST3C_4@27
  signed int v124; // edx@27
  double v125; // st7@27
  signed int v126; // ST3C_4@27
  signed int v127; // edx@27
  double v128; // st7@27
  signed int v129; // ST3C_4@27
  signed int v130; // edx@27
  double v131; // st7@27
  signed int v132; // ST3C_4@27
  signed int v133; // edx@27
  double v134; // st7@27
  signed int v135; // ST3C_4@27
  signed int v136; // edx@27
  double v137; // st7@27
  signed int v138; // ST3C_4@27
  signed int v139; // edx@27
  double v140; // st7@27
  signed int v141; // ST3C_4@27
  signed int v142; // edx@27
  double v143; // st7@27
  signed int v144; // ST3C_4@27
  signed int v145; // edx@27
  double v146; // st7@27
  signed int v147; // ST3C_4@27
  signed int v148; // edx@27
  double v149; // st7@27
  signed int v150; // ST3C_4@27
  signed int v151; // edx@27
  double v152; // st7@27
  signed int v153; // ST3C_4@27
  signed int v154; // edx@27
  signed int v155; // eax@28
  int v156; // edx@28
  void *v157; // edi@29
  const void *v158; // esi@29
  signed int v159; // esi@30
  long double v160; // st7@31
  unsigned __int8 v161; // di@33
  signed int v162; // esi@33
  int v163; // ecx@35
  int v164; // edi@35
  int v165; // esi@35
  int v166; // edx@35
  int v167; // ecx@35
  signed int v168; // eax@35
  signed int v169; // ebx@37
  int v170; // ebp@37
  signed int v171; // ecx@37
  int v172; // eax@39
  int v173; // ecx@39
  int v174; // ecx@45
  bool v175; // zf@45
  double v176; // st7@47
  int v177; // ecx@47
  int result; // eax@54
  int v179; // [sp+14h] [bp-2Ch]@35
  signed int v180; // [sp+18h] [bp-28h]@30
  float v181; // [sp+18h] [bp-28h]@32
  signed int v182; // [sp+1Ch] [bp-24h]@37
  signed int v183; // [sp+20h] [bp-20h]@35
  int v184; // [sp+24h] [bp-1Ch]@35
  int v185; // [sp+28h] [bp-18h]@37
  int v186; // [sp+2Ch] [bp-14h]@37
  int v187; // [sp+30h] [bp-10h]@35
  int v188; // [sp+34h] [bp-Ch]@39
  double v189; // [sp+38h] [bp-8h]@33
  int v190; // [sp+38h] [bp-8h]@39

  v0 = &unk_4B3404;
  v1 = &circuitPalette_4A9BA0[1];//cambiado FIX
  //v1 = (signed int)byte_4A9BA1;
  if ( leftMenuInRaceWidth_456AA0 == 64 )
  {
    do
    {
      v2 = *(BYTE *)v1;
      v3 = *(BYTE *)(v1 + 1);
      *((float *)v0 - 1) = (double)*(BYTE *)(v1 - 1) * 0.011111111;
      v4 = (double)v2;
      v5 = v3;
      v6 = *(BYTE *)(v1 + 2);
      *(float *)v0 = v4 * 0.011111111;
      v7 = (double)v5;
      v8 = v6;
      v9 = *(BYTE *)(v1 + 3);
      *((float *)v0 + 1) = v7 * 0.011111111;
      v10 = (double)v8;
      v11 = v9;
      v12 = *(BYTE *)(v1 + 4);
      *((float *)v0 + 2) = v10 * 0.011111111;
      v13 = (double)v11;
      v14 = v12;
      v15 = *(BYTE *)(v1 + 5);
      *((float *)v0 + 3) = v13 * 0.011111111;
      v16 = (double)v14;
      v17 = v15;
      v18 = *(BYTE *)(v1 + 6);
      *((float *)v0 + 4) = v16 * 0.011111111;
      v19 = (double)v17;
      v20 = v18;
      v21 = *(BYTE *)(v1 + 7);
      *((float *)v0 + 5) = v19 * 0.011111111;
      v22 = (double)v20;
      v23 = v21;
      v24 = *(BYTE *)(v1 + 8);
      *((float *)v0 + 6) = v22 * 0.011111111;
      v25 = (double)v23;
      v26 = v24;
      v27 = *(BYTE *)(v1 + 9);
      *((float *)v0 + 7) = v25 * 0.011111111;
      v28 = (double)v26;
      v29 = v27;
      v30 = *(BYTE *)(v1 + 10);
      *((float *)v0 + 8) = v28 * 0.011111111;
      v31 = (double)v29;
      v32 = v30;
      v33 = *(BYTE *)(v1 + 11);
      *((float *)v0 + 9) = v31 * 0.011111111;
      v34 = (double)v32;
      v35 = v33;
      v36 = *(BYTE *)(v1 + 12);
      *((float *)v0 + 10) = v34 * 0.011111111;
      v37 = (double)v35;
      v38 = v36;
      v39 = *(BYTE *)(v1 + 13);
      *((float *)v0 + 11) = v37 * 0.011111111;
      v40 = (double)v38;
      v41 = v39;
      v42 = *(BYTE *)(v1 + 14);
      *((float *)v0 + 12) = v40 * 0.011111111;
      v43 = (double)v41;
      v44 = v42;
      v45 = *(BYTE *)(v1 + 15);
      *((float *)v0 + 13) = v43 * 0.011111111;
      *((float *)v0 + 14) = (double)v44 * 0.011111111;
      v46 = (double)v45;
      v47 = *(BYTE *)(v1 + 16);
      v48 = *(BYTE *)(v1 + 17);
      v1 += 24;
      *((float *)v0 + 15) = v46 * 0.011111111;
      v0 = (char *)v0 + 96;
      v49 = (double)v47;
      v50 = v48;
      v51 = *(BYTE *)(v1 - 6);
      *((float *)v0 - 8) = v49 * 0.011111111;
      v52 = (double)v50;
      v53 = v51;
      v54 = *(BYTE *)(v1 - 5);
      *((float *)v0 - 7) = v52 * 0.011111111;
      v55 = (double)v53;
      v56 = v54;
      v57 = *(BYTE *)(v1 - 4);
      *((float *)v0 - 6) = v55 * 0.011111111;
      v58 = (double)v56;
      v59 = v57;
      v60 = *(BYTE *)(v1 - 3);
      *((float *)v0 - 5) = v58 * 0.011111111;
      v61 = (double)v59;
      v62 = v60;
      v63 = *(BYTE *)(v1 - 2);
      *((float *)v0 - 4) = v61 * 0.011111111;
      *((float *)v0 - 3) = (double)v62 * 0.011111111;
      *((float *)v0 - 2) = (double)v63 * 0.011111111;
    }
    while ( v1 < (signed int)((char *)&joystick_y_axis_default_4A9EA0 + 1) );
    v64 = dword_464F14;
    v65 = (signed int)textureTemp;
    v66 = dword_464F14 + 160;
    do
    {
      v67 = (void *)v65;
      v68 = (const void *)v66;
      v65 += 256;
      v66 += 512;
      memcpy(v67, v68, 0x100u);
    }
    while ( v65 < (signed int)&unk_48E620 );
    v69 = (signed int)&unk_48E720;
    v70 = v64 + 96;
    do
    {
      v71 = (void *)v69;
      v72 = (const void *)v70;
      v69 += 64;
      v70 += 512;
      memcpy(v71, v72, 0x40u);
    }
    while ( v69 < (signed int)&unk_491920 );
    v73 = &unk_481F20;
    v74 = (signed int)&unk_48E420;
    do
    {
      memcpy(&unk_48E620, (const void *)(v74 + 256), 0x100u);
      memcpy((void *)(v74 + 256), (char *)v73 - 256, 0x100u);
      memcpy((char *)v73 - 256, &unk_48E620, 0x100u);
      memcpy(&unk_48E620, (const void *)v74, 0x100u);
      memcpy((void *)v74, v73, 0x100u);
      memcpy(v73, &unk_48E620, 0x100u);
      memcpy(&unk_48E620, (const void *)(v74 - 256), 0x100u);
      memcpy((void *)(v74 - 256), (char *)v73 + 256, 0x100u);
      memcpy((char *)v73 + 256, &unk_48E620, 0x100u);
      memcpy(&unk_48E620, (const void *)(v74 - 512), 0x100u);
      memcpy((void *)(v74 - 512), (char *)v73 + 512, 0x100u);
      memcpy((char *)v73 + 512, &unk_48E620, 0x100u);
      v75 = (char *)v73 + 768;
      memcpy(&unk_48E620, (const void *)(v74 - 768), 0x100u);
      memcpy((void *)(v74 - 768), (char *)v73 + 768, 0x100u);
      v74 -= 1280;
      v73 = (char *)v73 + 1280;
      memcpy(v75, &unk_48E620, 0x100u);
    }
    while ( v74 > (signed int)&unk_488020 );
    memset(&unk_48E620, 0, 0x100u);
    dword_4A9EAC = 0;
    dword_44509C = 1063675494;
    dword_4450A0 = 1119092736;
    dword_4AA504 = 64;
    while ( 1 )
    {
      v76 = 0;
      v77 = (signed int)&unk_4B3404;
      do
      {
        setPaletteAndGetValue(
          v76,
          (unsigned __int64)(*(float *)&dword_4450A0 * *(float *)(v77 - 4)),
          (unsigned __int64)(*(float *)&dword_4450A0 * *(float *)v77),
          (unsigned __int64)(*(float *)&dword_4450A0 * *(float *)(v77 + 4)));
        v77 += 12;
        ++v76;
      }
      while ( v77 < (signed int)&obstacleBpk );
      setMusicVolume(728 * (unsigned __int64)*(float *)&dword_4450A0);
      v78 = *(float *)&dword_4450A0 * 0.01745329251994444;
      dword_50A170 = screenPtr + 64;
      dword_481E00 = (unsigned __int64)(51200.0 / (sin(v78) * 200.0));
      v79 = 0;
      dword_503514 = (unsigned __int64)(cos(v78) * 170.0);
      dword_4A7CD0 = 200 * dword_481E00;
      v80 = 0;
      do
      {
        v81 = (unsigned __int64)(*(float *)&dword_4450A0 * 0.7142857142857143);
        v82 = (char *)&unk_48E760 + v80 - v81;
        v83 = (void *)(dword_50A170 + v79 - 64);
        memcpy(v83, v82, 4 * ((unsigned int)v81 >> 2));
        v80 += 64;
        v79 += 320;
        memcpy((char *)v83 + 4 * ((unsigned int)v81 >> 2), &v82[4 * ((unsigned int)v81 >> 2)], v81 & 3);
      }
      while ( v80 < 12800 );
      v84 = 0;
      do
      {
        v85 = dword_4AA504 - (unsigned __int64)(0.7142857142857143 * *(float *)&dword_4450A0);
        v86 = (void *)(v84 - (unsigned __int64)(*(float *)&dword_4450A0 * -0.7142857142857143) + dword_50A170 - 64);
        memset(v86, 0, 4 * (v85 >> 2));
        v84 += 320;
        memset((char *)v86 + 4 * (v85 >> 2), 0, v85 & 3);
      }
      while ( v84 < 64000 );
      dword_4AA504 = (unsigned __int64)(*(float *)&dword_4450A0 * 0.7142857142857143);
      v87 = dword_4A7CD0;
      v88 = 200;
      do
      {
        v89 = v87 & 0xFFFFFF00;
        dword_464F20 = v89;
        if ( (signed int)v89 > 51200 )
        {
          v89 = 51200;
          dword_464F20 = 51200;
        }
        dword_4A7A24 = (signed int)(dword_503514 * v89) >> 16;
        sub_43B030(dword_50A170, ((signed int)(dword_503514 * v89) >> 17) - 10);
        sub_43B370(
          dword_50A170 + (dword_4A7A24 >> 1),
          (int)((char *)&textureTemp[0] + dword_464F20 - 1),
          255 - dword_4A7A24);
        sub_43B050(dword_50A170, (dword_4A7A24 >> 1) - dword_4A7A24 + 255);
        v87 = dword_4A7CD0 - dword_481E00;
        --v88;
        dword_50A170 += 320;
        dword_4A7CD0 -= dword_481E00;
      }
      while ( v88 );
      if ( *(float *)&dword_4450A0 == 1.0 )
        break;
      v90 = *(float *)&dword_44509C;
      v91 = 0;
      if ( dword_4A9EAC >= 0 )
      {
        do
        {
          v90 = v90 * 1.02;
          ++v91;
        }
        while ( v91 <= dword_4A9EAC );
        *(float *)&dword_44509C = v90;
      }
      v92 = *(float *)&dword_4450A0 - v90;
      *(float *)&dword_4450A0 = v92;
      if ( v92 < 1.0 )
        dword_4450A0 = 1065353216;
      dword_4A9EAC = 0;
      waitWithRefresh();
    }
  }
  else
  {
    do
    {
      v93 = *(BYTE *)v1;
      v94 = *(BYTE *)(v1 + 1);
      *((float *)v0 - 1) = (double)*(BYTE *)(v1 - 1) * 0.0066666668;
      v95 = (double)v93;
      v96 = v94;
      v97 = *(BYTE *)(v1 + 2);
      *(float *)v0 = v95 * 0.0066666668;
      v98 = (double)v96;
      v99 = v97;
      v100 = *(BYTE *)(v1 + 3);
      *((float *)v0 + 1) = v98 * 0.0066666668;
      v101 = (double)v99;
      v102 = v100;
      v103 = *(BYTE *)(v1 + 4);
      *((float *)v0 + 2) = v101 * 0.0066666668;
      v104 = (double)v102;
      v105 = v103;
      v106 = *(BYTE *)(v1 + 5);
      *((float *)v0 + 3) = v104 * 0.0066666668;
      v107 = (double)v105;
      v108 = v106;
      v109 = *(BYTE *)(v1 + 6);
      *((float *)v0 + 4) = v107 * 0.0066666668;
      v110 = (double)v108;
      v111 = v109;
      v112 = *(BYTE *)(v1 + 7);
      *((float *)v0 + 5) = v110 * 0.0066666668;
      v113 = (double)v111;
      v114 = v112;
      v115 = *(BYTE *)(v1 + 8);
      *((float *)v0 + 6) = v113 * 0.0066666668;
      v116 = (double)v114;
      v117 = v115;
      v118 = *(BYTE *)(v1 + 9);
      *((float *)v0 + 7) = v116 * 0.0066666668;
      v119 = (double)v117;
      v120 = v118;
      v121 = *(BYTE *)(v1 + 10);
      *((float *)v0 + 8) = v119 * 0.0066666668;
      v122 = (double)v120;
      v123 = v121;
      v124 = *(BYTE *)(v1 + 11);
      *((float *)v0 + 9) = v122 * 0.0066666668;
      v125 = (double)v123;
      v126 = v124;
      v127 = *(BYTE *)(v1 + 12);
      *((float *)v0 + 10) = v125 * 0.0066666668;
      v128 = (double)v126;
      v129 = v127;
      v130 = *(BYTE *)(v1 + 13);
      *((float *)v0 + 11) = v128 * 0.0066666668;
      v131 = (double)v129;
      v132 = v130;
      v133 = *(BYTE *)(v1 + 14);
      *((float *)v0 + 12) = v131 * 0.0066666668;
      v134 = (double)v132;
      v135 = v133;
      v136 = *(BYTE *)(v1 + 15);
      *((float *)v0 + 13) = v134 * 0.0066666668;
      *((float *)v0 + 14) = (double)v135 * 0.0066666668;
      v137 = (double)v136;
      v138 = *(BYTE *)(v1 + 16);
      v139 = *(BYTE *)(v1 + 17);
      v1 += 24;
      *((float *)v0 + 15) = v137 * 0.0066666668;
      v0 = (char *)v0 + 96;
      v140 = (double)v138;
      v141 = v139;
      v142 = *(BYTE *)(v1 - 6);
      *((float *)v0 - 8) = v140 * 0.0066666668;
      v143 = (double)v141;
      v144 = v142;
      v145 = *(BYTE *)(v1 - 5);
      *((float *)v0 - 7) = v143 * 0.0066666668;
      v146 = (double)v144;
      v147 = v145;
      v148 = *(BYTE *)(v1 - 4);
      *((float *)v0 - 6) = v146 * 0.0066666668;
      v149 = (double)v147;
      v150 = v148;
      v151 = *(BYTE *)(v1 - 3);
      *((float *)v0 - 5) = v149 * 0.0066666668;
      v152 = (double)v150;
      v153 = v151;
      v154 = *(BYTE *)(v1 - 2);
      *((float *)v0 - 4) = v152 * 0.0066666668;
      *((float *)v0 - 3) = (double)v153 * 0.0066666668;
      *((float *)v0 - 2) = (double)v154 * 0.0066666668;
    }
    while ( v1 < (signed int)((char *)&joystick_y_axis_default_4A9EA0 + 1) );
    v155 = (signed int)textureTemp;
    v156 = dword_464F14 + 96;
    do
    {
      v157 = (void *)v155;
      v158 = (const void *)v156;
      v155 += 320;
      v156 += 512;
      memcpy(v157, v158, 0x140u);
    }
    while ( v155 < (signed int)&unk_491820 );
    v159 = 0;
    v180 = 0;
    do
    {
      v160 = (double)v180 * 0.01046666666666667;
      *((_DWORD *)dword_46F204 + v159) = (unsigned __int64)(cos(v160) * 1024.0);
      *((_DWORD *)dword_4A6854 + v159++) = (unsigned __int64)(sin(v160) * 1024.0);
      v180 = v159;
    }
    while ( v159 < 600 );
    v181 = 8.0;
    do
    {
      v161 = 0;
      dword_4A9EAC = 0;
      dword_503510 = 0;
      waitWithRefresh();
      v162 = (signed int)&unk_4B3404;
      v189 = 150.0 - v181;
      do
      {
        setPaletteAndGetValue(
          v161,
          (unsigned __int64)(*(float *)(v162 - 4) * v189),
          (unsigned __int64)(*(float *)v162 * v189),
          (unsigned __int64)(*(float *)(v162 + 4) * v189));
        v162 += 12;
        ++v161;
      }
      while ( v162 < (signed int)&obstacleBpk );
      setMusicVolume(436 * (unsigned __int64)v189);
      v179 = screenPtr;
      v163 = 4 * (599 - ((unsigned __int64)v181 - 8));
      v164 = 2 * *(_DWORD *)((char *)dword_4A6854 + v163);
      v165 = 2 * *(_DWORD *)((char *)dword_46F204 + v163);
      v166 = 2 * *(_DWORD *)((char *)dword_4A6854 + v163) >> 1;
      v167 = 2 * *(_DWORD *)((char *)dword_46F204 + v163) >> 1;
      v184 = v166;
      v168 = v166;
      v187 = v167;
      v183 = 100;
      while ( 1 )
      {
        v169 = v168 >> 10;
        v170 = v167 >> 10;
        v186 = v165 + v167;
        v171 = v187;
        v185 = v164 + v168;
        v182 = 160;
        while ( 1 )
        {
          v188 = v165 + v171;
          v172 = (v171 >> 10) - v169;
          v173 = v170 + (v166 >> 10);
          v190 = v164 + v166;
          if ( v172 <= 0 || v172 >= 319 || v173 <= 0 || v173 >= 199 )
            sub_43C450(v179);
          else
            convert320to320_43C470(v179, (int)((char *)&textureTemp[80 * v173] + v172));
          v174 = v179 + 2;
          v175 = v182 == 1;
          v179 += 2;
          --v182;
          if ( v175 )
            break;
          v166 = v190;
          v171 = v188;
        }
        v175 = v183 == 1;
        v179 = v174 + 320;
        --v183;
        if ( v175 )
          break;
        v166 = v184;
        v167 = v186;
        v168 = v185;
      }
      v176 = v181;
      v177 = 0;
      if ( dword_4A9EAC >= 0 )
      {
        do
        {
          if ( v176 < 150.0 )
            v176 = v176 * 1.04;
          ++v177;
        }
        while ( v177 <= dword_4A9EAC );
        v181 = v176;
      }
    }
    while ( v176 <= 150.0 && v176 != 150.0 );
  }
  dword_4A9EAC = 0;
  dword_503510 = 0;
  result = dword_4A8D2C;
  dword_503500 = dword_4A8D2C;
  dword_4A7CFC = dword_4A8D2C;
  return result;
}

//----- (00406100) --------------------------------------------------------
char drawRacepopupEffect_406100()
{
  signed int v0; // esi@1
  char v1; // al@2
  char result; // al@3
  int v3; // ecx@3
  int v4; // ecx@5
  int v5; // ST08_4@5
  int v6; // edi@5
  int v7; // eax@5
  bool v8; // zf@5
  bool v9; // sf@7
  unsigned __int8 v10; // of@7
  int v11; // edx@9
  int v12; // eax@11
  int v13; // [sp+0h] [bp-4h]@1

  v13 = 0;
  dword_479270 = 0;
//  v0 = (signed int)&unk_479F00;  EL PUNTERO QUE SE PINTA ESTA EN unk_479EEC +4
  v0 = 0;
  //if(debug) v0=100;
    
  do
  {
    v1 = racePopupMemory[v0].unk_479F00 ;
	if ( racePopupMemory[v0].unk_479F00 == 100 )
    {
      result = dword_481E08;
      v3 = v13++ + 1;
      if ( dword_481E08 < 3876 )//204*19
      {
        result = v3;
        if ( v3 < 20 )
        {
			sub_43AE80(racePopupMemory[v0].unk_479EF0, (int)((char *)inRaceMessagePopup_479690 + 204 * dword_464F18 + dword_503220), 4, 204); //puntero pantalla, inicio del puntero de la imagen, algo y ancho //dword_464F18 largo popup 72 para pausa
		  v4 = (int)racePopupMemory2[dword_479268].dword_50E560 << 16;
          v5 = (((leftMenuInRaceWidth_456AA0 >> 1) + dword_503220 + 57) << 16) - v4;
          v6 = dword_464F18 + 64;
		  racePopupMemory[v0].unk_479EE0 = v4;
		  racePopupMemory[v0].unk_479EE4 = 12845056;
          racePopupMemory[v0].unk_479EE8 = colorToPaletteEntry(v5, (signed int)&unk_460000);
          racePopupMemory[v0].unk_479EEC = colorToPaletteEntry((v6 << 16) - racePopupMemory[v0].unk_479EE4, (signed int)&unk_460000);
          dword_481E08 += 4;
          v7 = dword_464F18 + 4;
          v8 = dword_464F18 == 72;
         racePopupMemory[v0].unk_479F00 = 0;
          dword_464F18 = v7;
          if ( v8 )
          {
            dword_464F18 = 0;
            dword_503220 += 4;
          }
          result = dword_479268 + 1;
          v10 = __OFSUB__(dword_479268 + 1, 99);
          v8 = dword_479268 == 98;
          v9 = dword_479268++ - 98 < 0;
          if ( !((unsigned __int8)(v9 ^ v10) | v8) )
            dword_479268 = 0;
        }
      }
    }
    else
    {
      v11 = dword_5034F0;
      if ( (unsigned __int8)v1 + dword_5034F0 >= 70 )
      {
        if ( (signed int)(unsigned __int8)v1 < 70 )
        {
          racePopupMemory[v0].unk_479EE0 += racePopupMemory[v0].unk_479EE8 * (70 - (unsigned __int8)v1);
          if ( (signed int)(unsigned __int8)v1 < 70 )
			  racePopupMemory[v0].unk_479EE4 += racePopupMemory[v0].unk_479EEC * (70 - (unsigned __int8)v1);
        }
        racePopupMemory[v0].unk_479F00 = 70;
LABEL_13:
        sub_43AE80(
          (int)((char *)Memory + 320 * ((racePopupMemory[v0].unk_479EE4 + 0x8000) >> 16) + ((racePopupMemory[v0].unk_479EE0 + 0x8000) >> 16)),
		  racePopupMemory[v0].unk_479EF0,
          320,
          4);
        result = dword_479270++ + 1;
        goto LABEL_14;
      }
	  racePopupMemory[v0].unk_479F00 = dword_5034F0 + v1;
      if ( v11 > 0 )
      {
        v12 = racePopupMemory[v0].unk_479EE4;
        racePopupMemory[v0].unk_479EE0 += v11 * racePopupMemory[v0].unk_479EE8;
        racePopupMemory[v0].unk_479EE4 = v12 + v11 * racePopupMemory[v0].unk_479EEC;
      }
      sub_43AE80(
        (int)((char *)Memory + 320 * (((racePopupMemory[v0].unk_479EE4 + 0x8000) >> 16)) + ((racePopupMemory[v0].unk_479EE0 + 0x8000) >> 16)),
        racePopupMemory[v0].unk_479EF0,
        320,
        4);
      result = racePopupMemory[v0].unk_479F00;
      if ( racePopupMemory[v0].unk_479F00 >= 0x46u )
        goto LABEL_13;
    }
LABEL_14:
    v0 += 1;
  }
  while(v0<969);
  
  //while(v0<31977);
  //while ( v0 < 4725737 )
  return result;
}

//----- (00406330) --------------------------------------------------------
int sub_406330()
{
  int v0; // edx@1
  int v1; // edi@1
  signed int v2; // esi@1
  int v3; // eax@4
  int v4; // ebp@4
  int v5; // ecx@4
  int v6; // ebp@4
  int v7; // ecx@4
  int v8; // eax@6
  int v9; // ecx@8
  int v10; // eax@9

  v0 = dword_5034F0;
  v1 = 0;
  v2=0;
  //v2 = (signed int)&unk_479EE8;
  do
  {
	  if ( racePopupMemory[v2].unk_479F00<= 0x46u )
    {
      if ( v0 > 0 )
      {
		  v3 = v0 * dword_4A8AA0 + racePopupMemory[v2].unk_479EEC;
		v4 = v0 * racePopupMemory[v2].unk_479EE8;
		v5 = racePopupMemory[v2].unk_479EE0;
		racePopupMemory[v2].unk_479EEC = v3;
        v6 = v5 + v4;
		v7 = racePopupMemory[v2].unk_479EE4;
		racePopupMemory[v2].unk_479EE0 = v6;
		racePopupMemory[v2].unk_479EE4 = v7 + v0 * v3;
      }
	  if ( racePopupMemory[v2].unk_479EE0 <= 0 )
      {
		  v8 = -racePopupMemory[v2].unk_479EE8;
		  racePopupMemory[v2].unk_479EE0 = 0;
		  racePopupMemory[v2].unk_479EE8 = v8;
      }
	  if ( racePopupMemory[v2].unk_479EE0 >= 20709376 )
      {
		  v9 = -racePopupMemory[v2].unk_479EE8;
		  racePopupMemory[v2].unk_479EE0 = 20709376;
		  racePopupMemory[v2].unk_479EE8 = v9;
      }
	  v10 = (racePopupMemory[v2].unk_479EE4 + 0x8000) >> 16;
      if ( v10 <= 196 )
      {
		  sub_43AE80((int)((char *)Memory + 320 * v10 + ((racePopupMemory[v2].unk_479EE0 + 0x8000) >> 16)),racePopupMemory[v2].unk_479EF0, 320, 4);
        v0 = dword_5034F0;
      }
      else
      {
		  racePopupMemory[v2].unk_479F00 = 70;
        ++v1;
      }
    }
    //v2 += 33;
	v2+=1;
  }

  //ver porque este bulce no tiene que dar tanta vuelta
  while(v2<969);
  //while ( v2 < (signed int)((char *)dword_481BD0 + 1) );
  return v1;
}
// 481BD0: using guessed type int dword_481BD0[];
// 4A8AA0: using guessed type int dword_4A8AA0;
// 5034F0: using guessed type int dword_5034F0;

//----- (00406410) --------------------------------------------------------
unsigned int   drawTextInRaceScreen(int a1, int a2, const char *text)
{
  unsigned int v3; // esi@1
  unsigned int result; // eax@1
  int v5; // edi@2

  v3 = 0;
  result = strlen(text);
  if ( result )
  {
    v5 = 6 * (272 * a2 + a1 + 205);
    do
    {
		drawCharInRaceScreen(&smalfo4aBpk_4A9160 [36 * (text[v3] - 32)] , 6, 6, (int)((char *)inRaceMessagePopup_479690 + v5));
	  v3++;
      v5 += 6;
      result = strlen(text);
    }
    while ( v3 < result );
  }
  return result;
}

//----- (004064A0) --------------------------------------------------------
signed int   racePauseMenu_4064A0(int a1)
{
  void *v1; // eax@1
  void *v2; // eax@5
  signed int v3; // eax@9
  int v4; // edx@9
  const void *v5; // esi@10
  char *v6; // edi@10
  signed int v7; // eax@11
  signed int v8; // esi@13
  signed int v9; // eax@15
  signed int v10; // esi@15
  signed int v11; // edi@15
  signed int v12; // ecx@34
  signed int v13; // eax@36
  char *v14; // ecx@36
  int v15; // edi@38
  signed int v16; // esi@38
  int v17; // eax@41
  void *v18; // edx@41
  int v19; // ecx@41
  signed int result; // eax@48
  signed int v21; // [sp+8h] [bp-334h]@1
  int v22[102]; // [sp+Ch] [bp-330h]@35
  char v23; // [sp+1A4h] [bp-198h]@36

  v21 = 0;

  //estos valores se usan para el efecto
  dword_503220 = 0;
  dword_464F18 = 0;
  dword_479268 = 0;
  dword_481E08 = 0;
  
  v1 = malloc(0xFA00u);
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
  dword_47926C =malloc(0xFA00u);
  v3 = 0;
  memset(Memory, 0, 0xFA00u);

  //copia de la pantalla
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
	  racePopupMemory[v7].unk_479EE4 = 0;
	  racePopupMemory[v7].unk_479EEC = 0;
	  racePopupMemory[v7].unk_479EE8 = 0;
	  racePopupMemory[v7].unk_479EF0 = malloc(4); ///TODO FIX puesto por mi
    v7 += 1;
  }
  while ( v7 < 969);
  //while ( v7 < (signed int)&unk_481BC9 );
  v8=0;
  
 // v8 = (signed int)dword_50E560;
  do
  {
    racePopupMemory2[v8].dword_50E560 = rand() % 316;
	v8 += 1;
	
  }
  while ( v8 < 100);
  
  //while ( v8 < (signed int)&unk_50E6F0 );
  
  copyBuffer2Screen(Memory, dword_47926C, 16000);
  copyBuffer2Screen((void *)screenPtr, Memory, 16000);
  stopSoundChannel_43C3E0(5u);
  loadMenuSoundEffect(5u, 17, 0, 0x10000, 163840);
  v9 = 0;
  memset(keysRead_45E0C0, 0, 0x100u);
  v10 = 0;
  dword_479270 = 0;
  v11 = 0;
  do
  {
    if ( v9 >= 968 && !v11 )
    {
      v11 = 1;
      stopSoundChannel_43C3E0(5u);
    }
    transformJoystickReadValue_418150();
    if ( keysRead_45E0C0[KEY_ENTER] || byte_45E15C || keysRead_45E0C0[KEY_Y] || keysRead_45E0C0[KEY_N] )
      v10 = 1;
    if ( keysRead_45E0C0[KEY_F1] )
    {
      v10 = 1;
      v21 = 1;
    }
    if ( dword_464F68 == -1 && keysRead_45E0C0[KEY_Y] == 1 )
      dword_464F68 = 1;
    dword_4A9EAC = 0;
    dword_503510 = 0;
    waitWithRefresh();
    copyBuffer2Screen((void *)(screenPtr + 20480), (char *)Memory + 20480, 10880);
    copyBuffer2Screen((char *)Memory + 20480, (char *)dword_47926C + 20480, 10880);
    drawRacepopupEffect_406100();
    dword_5034F0 = dword_4A9EAC;
    if ( dword_4A9EAC < 1 )
      dword_5034F0 = 1;
    v9 = dword_479270;
  }
  while ( (dword_479270 < 968 || !a1) && !v10 );
  memset(keysRead_45E0C0, 0, 0x100u);
  stopSoundChannel_43C3E0(5u);
  v12 = 0;
  do
  {
    v22[v12] = v12 / -25;
    ++v12;
  }
  while ( v12 < 102 );
  v13 = 102;
  v14 = &v23;
  //v14 = &v22;
 /* do
  {
    v22[v13++] = *(_DWORD *)v14;
    v14 -= 4;
  }
  while ( v13 < 204 );*/
  dword_503220 = 0;
  dword_464F18 = 0;
  v15 = 0;
  dword_4A8AA0 = 13107;

  v16=0;
  //v16 = (signed int)&unk_479EEC;
  do
  {
	  if ( racePopupMemory[v16].unk_479F00 != 100 )
      ++v15;
	  racePopupMemory[v16].unk_479EEC = (v22[dword_503220] + rand() % 3) << 16;
    v17 = rand() % 4;
    v18 = inRaceMessagePopup_479690;
    v19 = 204 * dword_464F18;
	racePopupMemory[v16].unk_479EE8 = (v17 - 2) << 16;
	sub_43AE80(racePopupMemory[v16].unk_479EF0, (int)((char *)v18 + v19 + dword_503220), 4, 204);
    dword_464F18 += 4;
    if ( dword_464F18 == 76 )
    {
      dword_464F18 = 0;
      dword_503220 += 4;
    }
	v16+=1;
    //v16 += 33;
  }
  while(v16<969);
  //while ( v16 < (signed int)((char *)&dword_481BD4 + 1) );
  loadMenuSoundEffect(5u, 21, 0, 0x10000, 163840);
  dword_4A9EAC = 0;
  dword_503510 = 0;
  waitWithRefresh();
  copyBuffer2Screen((void *)screenPtr, Memory, 16000);
  copyBuffer2Screen(Memory, dword_47926C, 16000);
  //while ( sub_406330() < v15 )
 // {
    dword_5034F0 = dword_4A9EAC;
    if ( dword_4A9EAC < 1 )
      dword_5034F0 = 1;
    dword_4A9EAC = 0;
    dword_503510 = 0;
    waitWithRefresh();
    copyBuffer2Screen((void *)screenPtr, Memory, 16000);
    copyBuffer2Screen(Memory, dword_47926C, 16000);
  //}
  stopSoundChannel_43C3E0(5u);
  //copyBuffer2Screen((void *)screenPtr, dword_47926C, 16000);
  free(Memory);
 // free(dword_47926C);
  dword_4A9EAC = 0;
  dword_503510 = 0;
  dword_503500 = dword_4A8D2C;
  result = v21;
  dword_4A7CFC = dword_4A8D2C;
  if ( v21 )
    keysRead_45E0C0[KEY_F1] = 1;
  return result;
}

//----- (004069D0) --------------------------------------------------------
// 45DC30: using guessed type int dword_45DC30[];
// 45EA04: using guessed type int isMultiplayerGame;
// 508D24: using guessed type int numberOfParticipants_508D24;

//----- (00406BE0) --------------------------------------------------------

//----- (00406D30) --------------------------------------------------------

//----- (004072C0) --------------------------------------------------------
unsigned int   drawInRaceMenuText_4072C0(int a1, const char *a2)
{
  unsigned int v2; // esi@1
  unsigned int result; // eax@1
  int v4; // edi@2

  v2 = 0;
  result = strlen(a2);
  if ( result )
  {
    v4 = a1;
    do
    {
      //drawRaceCharInMenu_43B1A0(36 * (a2[v2++] - 32) + 4886880, 6, 6, v4);

		
	  drawRaceCharInMenu_43B1A0(&smalfo4aBpk_4A9160[36 * (a2[v2++] - 32)], 6, 6, v4);
	  

	  
      v4 += 6;
      result = strlen(a2);
    }
    while ( v2 < result );
  }
  return result;
}

//----- (00407330) --------------------------------------------------------
int keyMenuInRace_407330()
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
  signed int v9; // esi@1
  char *v10; // eax@3
  char v11; // dl@4
  unsigned int v12; // eax@5
  char *v13; // esi@5
  void *v14; // edi@5
  char v15; // cl@6
  int v16; // ST38_4@7
  char *v17; // eax@7
  char v18; // dl@8
  unsigned int v19; // eax@9
  void *v20; // edi@9
  char v21; // cl@10
  char *v22; // eax@11
  char v23; // dl@12
  unsigned int v24; // eax@13
  void *v25; // edi@13
  char v26; // cl@14
  int v27; // edx@15
  char *v28; // eax@15
  char v29; // dl@16
  unsigned int v30; // eax@17
  char *v31; // esi@17
  void *v32; // edi@17
  char v33; // cl@18
  int v34; // ST38_4@19
  char *v35; // eax@19
  char v36; // dl@20
  unsigned int v37; // eax@21
  void *v38; // edi@21
  char v39; // cl@22
  char *v40; // eax@23
  char v41; // dl@24
  unsigned int v42; // eax@25
  void *v43; // edi@25
  char v44; // cl@26
  int v45; // edx@27
  char *v46; // eax@27
  char v47; // dl@28
  unsigned int v48; // eax@29
  char *v49; // esi@29
  void *v50; // edi@29
  char v51; // cl@30
  int v52; // ST38_4@31
  char *v53; // eax@31
  char v54; // dl@32
  unsigned int v55; // eax@33
  void *v56; // edi@33
  char v57; // cl@34
  char *v58; // eax@35
  char v59; // dl@36
  unsigned int v60; // eax@37
  char *v61; // esi@37
  void *v62; // edi@37
  char v63; // cl@38
  int v64; // ST38_4@39
  char *v65; // eax@39
  char v66; // dl@40
  unsigned int v67; // eax@41
  void *v68; // edi@41
  char v69; // cl@42
  char *v70; // eax@43
  char v71; // dl@44
  unsigned int v72; // eax@45
  void *v73; // edi@45
  char v74; // cl@46
  int v75; // edx@47
  char *v76; // eax@47
  char v77; // dl@48
  unsigned int v78; // eax@49
  char *v79; // esi@49
  void *v80; // edi@49
  char v81; // cl@50
  int v82; // ST38_4@51
  char *v83; // eax@51
  char v84; // dl@52
  unsigned int v85; // eax@53
  void *v86; // edi@53
  char v87; // cl@54
  char *v88; // eax@55
  char v89; // dl@56
  unsigned int v90; // eax@57
  void *v91; // edi@57
  char v92; // cl@58
  int v93; // edx@59
  char *v94; // eax@59
  char v95; // dl@60
  unsigned int v96; // eax@61
  char *v97; // esi@61
  void *v98; // edi@61
  char v99; // cl@62
  int v100; // ST38_4@63
  signed int v101; // esi@63
  int v102; // esi@65
  signed int v103; // eax@66
  int v104; // ecx@67
  int v105; // edx@67
  signed int v106; // esi@69
  signed int v107; // esi@71
  int v108; // esi@73
  signed int v109; // eax@74
  int v110; // ecx@75
  int v111; // edx@75
  signed int v112; // esi@77
  signed int v113; // esi@79
  int result; // eax@81
  char v115; // [sp+Bh] [bp-3Dh]@5
  int v116; // [sp+Ch] [bp-3Ch]@3
  int v117; // [sp+10h] [bp-38h]@3
  int v118; // [sp+14h] [bp-34h]@3
  int v119; // [sp+18h] [bp-30h]@3
  char v120; // [sp+1Ch] [bp-2Ch]@3

  v0 = (char *)&unk_479E40 + 15 * (unsigned __int8)byte_456B01;
  *(_DWORD *)v0 = 774778414;
  *((_DWORD *)v0 + 1) = 774778414;
  *((_DWORD *)v0 + 2) = 1313820206;
  *((_WORD *)v0 + 6) = 69;
  v1 = (char *)&unk_479E40 + 15 * (unsigned __int8)configuration.defaultLeftSteeringGamepad;
  *(_DWORD *)v1 = 774778414;
  *((_DWORD *)v1 + 1) = 774778414;
  *((_DWORD *)v1 + 2) = 1178946606;
  *((_WORD *)v1 + 6) = 84;
  v2 = (char *)&unk_479E40 + 15 * (unsigned __int8)configuration.defaultRightSteeringGamepad;
  *(_DWORD *)v2 = 774778414;
  *((_DWORD *)v2 + 1) = 774778414;
  *((_DWORD *)v2 + 2) = 1212631378;
  *((_WORD *)v2 + 6) = 84;
  v3 = (char *)&unk_479E40 + 15 * (unsigned __int8)byte_44512A;
  *(_DWORD *)v3 = 774778414;
  *((_DWORD *)v3 + 1) = 774778414;//....
  *((_DWORD *)v3 + 2) = 1429089838;//U....
  *((_WORD *)v3 + 6) = 80;
  v4 = (char *)&unk_479E40 + 15 * (unsigned __int8)configuration.defaultBrakeGamepad;
  *(_DWORD *)v4 = 774778414;
  *((_DWORD *)v4 + 1) = 774778414;
  *((_DWORD *)v4 + 2) = 1464812590;
  *((_WORD *)v4 + 6) = 78;
  v5 = (char *)&unk_479E40 + 15 * (unsigned __int8)configuration.defaultAccelerateGamepad;
  *(_DWORD *)v5 = 774778414;
  *((_DWORD *)v5 + 1) = 1414873646;
  *((_DWORD *)v5 + 2) = 542003028;
  *((_WORD *)v5 + 6) = 49;
  v6 = (char *)&unk_479E40 + 15 * (unsigned __int8)configuration.defaultTurboGamepad;
  *(_DWORD *)v6 = 774778414;
  *((_DWORD *)v6 + 1) = 1414873646;
  *((_DWORD *)v6 + 2) = 542003028;
  *((_WORD *)v6 + 6) = 50;
  v7 = (char *)&unk_479E40 + 15 * (unsigned __int8)configuration.defaultGunGamepad;
  *(_DWORD *)v7 = 774778414;
  *((_DWORD *)v7 + 1) = 1414873646;
  *((_DWORD *)v7 + 2) = 542003028;
  *((_WORD *)v7 + 6) = 51;
  v8 = (char *)&unk_479E40 + 15 * (unsigned __int8)configuration.defaultMineGamepad;
  *(_DWORD *)v8 = 774778414;
  *((_DWORD *)v8 + 1) = 1414873646;
  *((_DWORD *)v8 + 2) = 542003028;
  *((_WORD *)v8 + 6) = 52;
  dword_4A6B2F = 774778414;//....
  dword_4A6B33 = 774778414;//....
  dword_4A6B37 = 1397042734;//..ESC
  word_4A6B3B = 67;
  dword_4A6B3E = 774778414;
  dword_4A6B42 = 774778414;
  dword_4A6B46 = 774778414;
  word_4A6B4A = 49;
  dword_4A6B4D = 774778414;
  dword_4A6B51 = 774778414;
  dword_4A6B55 = 774778414;
  word_4A6B59 = 50;
  dword_4A6B5C = 774778414;
  dword_4A6B60 = 774778414;
  dword_4A6B64 = 774778414;
  word_4A6B68 = 51;
  dword_4A6B6B = 774778414;
  dword_4A6B6F = 774778414;
  dword_4A6B73 = 774778414;
  word_4A6B77 = 52;
  dword_4A6B7A = 774778414;
  dword_4A6B7E = 774778414;
  dword_4A6B82 = 774778414;
  word_4A6B86 = 53;
  dword_4A6B89 = 774778414;
  dword_4A6B8D = 774778414;
  dword_4A6B91 = 774778414;
  word_4A6B95 = 54;
  dword_4A6B98 = 774778414;
  dword_4A6B9C = 774778414;
  dword_4A6BA0 = 774778414;
  word_4A6BA4 = 55;
  dword_4A6BA7 = 774778414;
  dword_4A6BAB = 774778414;
  dword_4A6BAF = 774778414;
  word_4A6BB3 = 56;
  dword_4A6BB6 = 774778414;
  dword_4A6BBA = 774778414;
  dword_4A6BBE = 774778414;
  word_4A6BC2 = 57;
  dword_4A6BC5 = 774778414;
  dword_4A6BC9 = 774778414;
  dword_4A6BCD = 774778414;
  word_4A6BD1 = 48;
  dword_4A6BD4 = 774778414;
  dword_4A6BD8 = 774778414;
  dword_4A6BDC = 1431193933;
  word_4A6BE0 = 83;
  dword_4A6BE3 = 774778414;
  dword_4A6BE7 = 774778414;
  dword_4A6BEB = 1096110405;
  word_4A6BEF = 76;
  dword_4A6BF2 = 774778414;
  dword_4A6BF6 = 1262698818;
  dword_4A6BFA = 1128353875;
  word_4A6BFE = 69;
  dword_4A6C01 = 774778414;
  dword_4A6C05 = 774778414;
  dword_4A6C09 = 1096035886;
  word_4A6C0D = 66;
  dword_4A6C10 = 774778414;
  dword_4A6C14 = 774778414;
  dword_4A6C18 = 774778414;
  word_4A6C1C = 81;
  dword_4A6C1F = 774778414;
  dword_4A6C23 = 774778414;
  dword_4A6C27 = 774778414;
  word_4A6C2B = 87;
  dword_4A6C2E = 774778414;
  dword_4A6C32 = 774778414;
  dword_4A6C36 = 774778414;
  word_4A6C3A = 69;
  dword_4A6C3D = 774778414;
  dword_4A6C41 = 774778414;
  dword_4A6C45 = 774778414;
  word_4A6C49 = 82;
  dword_4A6C4C = 774778414;
  dword_4A6C50 = 774778414;
  dword_4A6C54 = 774778414;
  word_4A6C58 = 84;
  dword_4A6C5B = 774778414;
  dword_4A6C5F = 774778414;
  dword_4A6C63 = 774778414;
  word_4A6C67 = 89;
  dword_4A6C6A = 774778414;
  dword_4A6C6E = 774778414;
  dword_4A6C72 = 774778414;
  word_4A6C76 = 85;
  dword_4A6C79 = 774778414;
  dword_4A6C7D = 774778414;
  dword_4A6C81 = 774778414;
  word_4A6C85 = 73;
  dword_4A6C88 = 774778414;
  dword_4A6C8C = 774778414;
  dword_4A6C90 = 774778414;
  word_4A6C94 = 79;
  dword_4A6C97 = 774778414;
  dword_4A6C9B = 774778414;
  dword_4A6C9F = 774778414;
  word_4A6CA3 = 80;
  dword_4A6CA6 = 1178946606;
  dword_4A6CAA = 1380065364;
  dword_4A6CAE = 1162560321;
  word_4A6CB2 = 84;
  dword_4A6CB5 = 1212631378;
  dword_4A6CB9 = 1380065364;
  dword_4A6CBD = 1162560321;
  word_4A6CC1 = 84;
  dword_4A6CC4 = 774778414;
  dword_4A6CC8 = 774778414;
  dword_4A6CCC = 1163152965;
  word_4A6CD0 = 82;
  dword_4A6CD3 = 1178946606;
  dword_4A6CD7 = 1329799252;
  dword_4A6CDB = 1330795598;
  word_4A6CDF = 76;
  dword_4A6CE2 = 774778414;
  dword_4A6CE6 = 774778414;
  dword_4A6CEA = 774778414;
  word_4A6CEE = 65;
  dword_4A6CF1 = 774778414;
  dword_4A6CF5 = 774778414;
  dword_4A6CF9 = 774778414;
  word_4A6CFD = 83;
  dword_4A6D00 = 774778414;
  dword_4A6D04 = 774778414;
  dword_4A6D08 = 774778414;
  word_4A6D0C = 68;
  dword_4A6D0F = 774778414;
  dword_4A6D13 = 774778414;
  dword_4A6D17 = 774778414;
  word_4A6D1B = 70;
  dword_4A6D1E = 774778414;
  dword_4A6D22 = 774778414;
  dword_4A6D26 = 774778414;
  word_4A6D2A = 71;
  dword_4A6D2D = 774778414;
  dword_4A6D31 = 774778414;
  dword_4A6D35 = 774778414;
  word_4A6D39 = 72;
  dword_4A6D3C = 774778414;
  dword_4A6D40 = 774778414;
  dword_4A6D44 = 774778414;
  word_4A6D48 = 74;
  dword_4A6D4B = 774778414;
  dword_4A6D4F = 774778414;
  dword_4A6D53 = 774778414;
  word_4A6D57 = 75;
  dword_4A6D5A = 774778414;
  dword_4A6D5E = 774778414;
  dword_4A6D62 = 774778414;
  word_4A6D66 = 76;
  dword_4A6D69 = 774778414;
  dword_4A6D6D = 1229800787;
  dword_4A6D71 = 1330401091;
  word_4A6D75 = 78;
  dword_4A6D78 = 774778414;
  dword_4A6D7C = 774778414;
  dword_4A6D80 = 1128879150;
  word_4A6D84 = 75;
  dword_4A6D87 = 1093545518;
  dword_4A6D8B = 1414745936;
  dword_4A6D8F = 1213222738;
  word_4A6D93 = 69;
  dword_4A6D96 = 1278094894;
  dword_4A6D9A = 542393925;
  dword_4A6D9E = 1179207763;
  word_4A6DA2 = 84;
  dword_4A6DA5 = 774778414;
  dword_4A6DA9 = 1262698818;
  dword_4A6DAD = 1396788307;
  word_4A6DB1 = 72;
  dword_4A6DB4 = 774778414;
  dword_4A6DB8 = 774778414;
  dword_4A6DBC = 774778414;
  word_4A6DC0 = 90;
  dword_4A6DC3 = 774778414;
  dword_4A6DC7 = 774778414;
  dword_4A6DCB = 774778414;
  word_4A6DCF = 88;
  dword_4A6DD2 = 774778414;
  dword_4A6DD6 = 774778414;
  dword_4A6DDA = 774778414;
  word_4A6DDE = 67;
  dword_4A6DE1 = 774778414;
  dword_4A6DE5 = 774778414;
  dword_4A6DE9 = 774778414;
  word_4A6DED = 86;
  dword_4A6DF0 = 774778414;
  dword_4A6DF4 = 774778414;
  dword_4A6DF8 = 774778414;
  word_4A6DFC = 66;
  dword_4A6DFF = 774778414;
  dword_4A6E03 = 774778414;
  dword_4A6E07 = 774778414;
  word_4A6E0B = 78;
  dword_4A6E0E = 774778414;
  dword_4A6E12 = 774778414;
  dword_4A6E16 = 774778414;
  word_4A6E1A = 77;
  dword_4A6E1D = 774778414;
  dword_4A6E21 = 774778414;
  dword_4A6E25 = 1296912195;
  word_4A6E29 = 65;
  dword_4A6E2C = 774778414;
  dword_4A6E30 = 1345203758;
  dword_4A6E34 = 1330205253;
  word_4A6E38 = 68;
  dword_4A6E3B = 774778414;
  dword_4A6E3F = 774778414;
  dword_4A6E43 = 1396788307;
  word_4A6E47 = 72;
  dword_4A6E4A = 1230122542;
  dword_4A6E4E = 542394439;
  dword_4A6E52 = 1179207763;
  word_4A6E56 = 84;
  dword_4A6E59 = 1162554926;
  dword_4A6E5D = 1145131097;
  dword_4A6E61 = 1096045357;
  word_4A6E65 = 82;
  dword_4A6E68 = 774778414;
  dword_4A6E6C = 1178946606;
  dword_4A6E70 = 1279336532;
  word_4A6E74 = 84;
  dword_4A6E77 = 774778414;
  dword_4A6E7B = 774778414;
  dword_4A6E7F = 1128353875;
  word_4A6E83 = 69;
  dword_4A6E86 = 774778414;
  dword_4A6E8A = 1346454318;
  dword_4A6E8E = 1129270355;
  word_4A6E92 = 75;
  dword_4A6E95 = 774778414;
  dword_4A6E99 = 774778414;
  dword_4A6E9D = 1177431598;
  word_4A6EA1 = 49;
  dword_4A6EA4 = 774778414;
  dword_4A6EA8 = 774778414;
  dword_4A6EAC = 1177431598;
  word_4A6EB0 = 50;
  dword_4A6EB3 = 774778414;
  dword_4A6EB7 = 774778414;
  dword_4A6EBB = 1177431598;
  word_4A6EBF = 51;
  dword_4A6EC2 = 774778414;
  dword_4A6EC6 = 774778414;
  dword_4A6ECA = 1177431598;
  word_4A6ECE = 52;
  dword_4A6ED1 = 774778414;
  dword_4A6ED5 = 774778414;
  dword_4A6ED9 = 1177431598;
  word_4A6EDD = 53;
  dword_4A6EE0 = 774778414;
  dword_4A6EE4 = 774778414;
  dword_4A6EE8 = 1177431598;
  word_4A6EEC = 54;
  dword_4A6EEF = 774778414;
  dword_4A6EF3 = 774778414;
  dword_4A6EF7 = 1177431598;
  word_4A6EFB = 55;
  dword_4A6EFE = 774778414;
  dword_4A6F02 = 774778414;
  dword_4A6F06 = 1177431598;
  word_4A6F0A = 56;
  dword_4A6F0D = 774778414;
  dword_4A6F11 = 774778414;
  dword_4A6F15 = 1177431598;
  word_4A6F19 = 57;
  dword_4A6F1C = 774778414;
  dword_4A6F20 = 774778414;
  dword_4A6F24 = 826682926;
  word_4A6F28 = 48;
  dword_4A6F2B = 774778414;
  dword_4A6F2F = 1431186990;
  dword_4A6F33 = 1129270349;
  word_4A6F37 = 75;
  dword_4A6F3A = 1395535406;
  dword_4A6F3E = 1280266819;
  dword_4A6F42 = 1129270348;
  word_4A6F46 = 75;
  dword_4A6F49 = 774778414;
  dword_4A6F4D = 1497713454;
  dword_4A6F51 = 759447888;
  word_4A6F55 = 55;
  dword_4A6F58 = 774778414;
  dword_4A6F5C = 1497713454;
  dword_4A6F60 = 759447888;
  word_4A6F64 = 56;
  dword_4A6F67 = 774778414;
  dword_4A6F6B = 1497713454;
  dword_4A6F6F = 759447888;
  word_4A6F73 = 57;
  dword_4A6F76 = 1497713454;
  dword_4A6F7A = 759447888;
  dword_4A6F7E = 1431193933;
  word_4A6F82 = 83;
  dword_4A6F85 = 774778414;
  dword_4A6F89 = 1497713454;
  dword_4A6F8D = 759447888;
  word_4A6F91 = 52;
  dword_4A6F94 = 774778414;
  dword_4A6F98 = 1497713454;
  dword_4A6F9C = 759447888;
  word_4A6FA0 = 53;
  dword_4A6FA3 = 774778414;
  dword_4A6FA7 = 1497713454;
  dword_4A6FAB = 759447888;
  word_4A6FAF = 54;
  dword_4A6FB2 = 1162554926;
  dword_4A6FB6 = 1145131097;
  dword_4A6FBA = 1431064621;
  word_4A6FBE = 83;
  dword_4A6FC1 = 774778414;
  dword_4A6FC5 = 1497713454;
  dword_4A6FC9 = 759447888;
  word_4A6FCD = 49;
  dword_4A6FD0 = 774778414;
  dword_4A6FD4 = 1497713454;
  dword_4A6FD8 = 759447888;
  word_4A6FDC = 50;
  dword_4A6FDF = 774778414;
  dword_4A6FE3 = 1497713454;
  dword_4A6FE7 = 759447888;
  word_4A6FEB = 51;
  dword_4A6FEE = 774778414;
  dword_4A6FF2 = 1497713454;
  dword_4A6FF6 = 759447888;
  word_4A6FFA = 48;
  dword_4A6FFD = 1261317678;
  dword_4A7001 = 1095784773;
  dword_4A7005 = 1162095940;
  word_4A7009 = 76;
  dword_4A700C = 774778414;
  dword_4A7010 = 1395535406;
  dword_4A7014 = 1163023193;
  word_4A7018 = 81;
  dword_4A7039 = 774778414;
  dword_4A703D = 774778414;
  dword_4A7041 = 826682926;
  word_4A7045 = 49;
  dword_4A7048 = 774778414;
  dword_4A704C = 774778414;
  dword_4A7050 = 826682926;
  word_4A7054 = 50;
  dword_4A7444 = 1497713454;
  dword_4A7448 = 759447888;
  dword_4A744C = 1163152965;
  word_4A7450 = 82;
  dword_4A7453 = 1212631378;
  dword_4A7457 = 1329799252;
  dword_4A745B = 1330795598;
  word_4A745F = 76;
  dword_4A75BB = 1497713454;
  dword_4A75BF = 759447888;
  dword_4A75C3 = 1396788307;
  word_4A75C7 = 72;
  dword_4A75D9 = 774778414;
  dword_4A75DD = 1230131246;
  dword_4A75E1 = 1129534542;
  word_4A75E5 = 82;
  dword_4A75E8 = 774778414;
  dword_4A75EC = 1212631378;
  dword_4A75F0 = 1279336532;
  word_4A75F4 = 84;
  dword_4A76C9 = 774778414;
  dword_4A76CD = 774778414;
  dword_4A76D1 = 1297041454;
  word_4A76D5 = 69;
  dword_4A76D8 = 774778414;
  dword_4A76DC = 542135598;
  dword_4A76E0 = 1330795073;
  word_4A76E4 = 87;
  dword_4A76E7 = 774778414;
  dword_4A76EB = 1095773742;
  dword_4A76EF = 1428178247;
  word_4A76F3 = 80;
  dword_4A7705 = 1278094894;
  dword_4A7709 = 542393925;
  dword_4A770D = 1330795073;
  word_4A7711 = 87;
  dword_4A7723 = 1230122542;
  dword_4A7727 = 542394439;
  dword_4A772B = 1330795073;
  word_4A772F = 87;
  dword_4A7741 = 774778414;
  dword_4A7745 = 774778414;
  dword_4A7749 = 1313156654;
  word_4A774D = 68;
  dword_4A7750 = 1143877166;
  dword_4A7754 = 542005071;
  dword_4A7758 = 1330795073;
  word_4A775C = 87;
  dword_4A775F = 774778414;
  dword_4A7763 = 1162297680;
  dword_4A7767 = 1464812576;
  dword_4A7772 = 774778414;
  dword_4A777D = 774778414;
  word_4A776B = 78;
  dword_4A776E = 774778414;
  word_4A7789 = 76;
  dword_4A7776 = 1313418798;
  word_4A777A = 83;
  dword_4A7781 = 774778414;
  dword_4A7785 = 1162096174;
  //unk_491820= malloc ( 0xFA00u);

  //esto guarda la ultima imagen para ponerla mas tarde despues del menu
  //memcpy(&unk_491820, (const void *)screenPtr, 0xFA00u);
  //esto estab acon puntero pero se cargaba otras cosas
 // memcpy(&circuitPalette_4B4020, loadCircuitPalette, 0x300u);
 // loadCircuitPalette();
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();
  v9 = 63;
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToBlack_4B4020();
    --v9;
  }
  while ( v9 );
  extractFromBpa("ENGINE.BPA", textureTemp, "KEYCOM3.BPK");
  copyImageToBuffer((int)textureTemp, screenPtr);
  extractFromBpa("ENGINE.BPA", &circuitPalette_4B4020,"KEYCOM3.PAL");
  drawInRaceMenuText_4072C0(screenPtr + 2620, "     GLOBAL KEY-DEFINITIONS");
  drawInRaceMenuText_4072C0(screenPtr + 6460, "   TAB.............STATUS BAR");
  drawInRaceMenuText_4072C0(screenPtr + 8380, "   F1.............INFO SCREEN");
  drawInRaceMenuText_4072C0(screenPtr + 10300, "   F2............MUSIC ON/OFF");
  drawInRaceMenuText_4072C0(screenPtr + 12220, "   F3..............SFX ON/OFF");
  drawInRaceMenuText_4072C0(screenPtr + 14140, "   F4................TEXTURES");
  drawInRaceMenuText_4072C0(screenPtr + 16060, "   F5.................SHADOWS");
  drawInRaceMenuText_4072C0(screenPtr + 17980, "   P....................PAUSE");
  drawInRaceMenuText_4072C0(screenPtr + 23100, "      KEYBOARD DEFINITIONS");
  v116 = 1092624416;
  v119 = 774778437;
  v117 = 1279607619;
  v10 = (char *)&unk_4A6B20 + 15 * configuration.accelerateKey;
  v120 = 0;
  v118 = 1413567045;
  do
    v11 = *v10++;
  while ( v11 );
  v12 = v10 - ((char *)&unk_4A6B20 + 15 * configuration.accelerateKey);
  v13 = (char *)&unk_4A6B20 + 15 * configuration.accelerateKey;
  v14 = &v115;
  do
  {
    v15 = *((BYTE *)v14 + 1);
    v14 = (char *)v14 + 1;
  }
  while ( v15 );
  memcpy(v14, v13, 4 * (v12 >> 2));
  v16 = screenPtr + 26940;
  memcpy((char *)v14 + 4 * (v12 >> 2), &v13[4 * (v12 >> 2)], v12 & 3);
  drawInRaceMenuText_4072C0(v16, (const char *)&v116);
  v118 = 774778414;
  v116 = 1109401632;
  v117 = 1162559826;
  v17 = (char *)&unk_4A6B20 + 15 * configuration.brakeKey;
  v119 = 774778414;
  v120 = 0;
  do
    v18 = *v17++;
  while ( v18 );
  v19 = v17 - ((char *)&unk_4A6B20 + 15 * configuration.brakeKey);
  v20 = &v115;
  do
  {
    v21 = *((BYTE *)v20 + 1);
    v20 = (char *)v20 + 1;
  }
  while ( v21 );
  memcpy(v20, (char *)&unk_4A6B20 + 15 * configuration.brakeKey, v19);
  drawInRaceMenuText_4072C0(screenPtr + 28860, (const char *)&v116);
  v117 = 1380271444;
  v120 = 0;
  v116 = 1394614304;
  v22 = (char *)&unk_4A6B20 + 15 * configuration.leftSteeringKey;
  v118 = 1178946592;
  v119 = 774778452;
  do
    v23 = *v22++;
  while ( v23 );
  v24 = v22 - ((char *)&unk_4A6B20 + 15 * configuration.leftSteeringKey);
  v25 = &v115;
  do
  {
    v26 = *((BYTE *)v25 + 1);
    v25 = (char *)v25 + 1;
  }
  while ( v26 );
  v27 = screenPtr;
  memcpy(v25, (char *)&unk_4A6B20 + 15 * configuration.leftSteeringKey, v24);
  drawInRaceMenuText_4072C0(v27 + 30780, (const char *)&v116);
  v116 = 1394614304;
  v119 = 774788168;
  v117 = 1380271444;
  v28 = (char *)&unk_4A6B20 + 15 * configuration.rightSteeringKey;
  v120 = 0;
  v118 = 1195987488;
  do
    v29 = *v28++;
  while ( v29 );
  v30 = v28 - ((char *)&unk_4A6B20 + 15 * configuration.rightSteeringKey);
  v31 = (char *)&unk_4A6B20 + 15 * configuration.rightSteeringKey;
  v32 = &v115;
  do
  {
    v33 = *((BYTE *)v32 + 1);
    v32 = (char *)v32 + 1;
  }
  while ( v33 );
  memcpy(v32, v31, 4 * (v30 >> 2));
  v34 = screenPtr + 32700;
  memcpy((char *)v32 + 4 * (v30 >> 2), &v31[4 * (v30 >> 2)], v30 & 3);
  drawInRaceMenuText_4072C0(v34, (const char *)&v116);
  v118 = 1330594336;
  v116 = 1411391520;
  v117 = 1329746517;
  v35 = (char *)&unk_4A6B20 + 15 * configuration.turboKey;
  v119 = 774788179;
  v120 = 0;
  do
    v36 = *v35++;
  while ( v36 );
  v37 = v35 - ((char *)&unk_4A6B20 + 15 * configuration.turboKey);
  v38 = &v115;
  do
  {
    v39 = *((BYTE *)v38 + 1);
    v38 = (char *)v38 + 1;
  }
  while ( v39 );
  memcpy(v38, (char *)&unk_4A6B20 + 15 * configuration.turboKey, v37);
  drawInRaceMenuText_4072C0(screenPtr + 34620, (const char *)&v116);
  v117 = 1229472577;
  v120 = 0;
  v116 = 1293951008;
  v40 = (char *)&unk_4A6B20 + 15 * configuration.gunKey;
  v118 = 1193297230;
  v119 = 774786645;
  do
    v41 = *v40++;
  while ( v41 );
  v42 = v40 - ((char *)&unk_4A6B20 + 15 * configuration.gunKey);
  v43 = &v115;
  do
  {
    v44 = *((BYTE *)v43 + 1);
    v43 = (char *)v43 + 1;
  }
  while ( v44 );
  v45 = screenPtr;
  memcpy(v43, (char *)&unk_4A6B20 + 15 * configuration.gunKey, v42);
  drawInRaceMenuText_4072C0(v45 + 36540, (const char *)&v116);
  v116 = 1142956064;
  v119 = 774778414;
  v117 = 542134098;
  v46 = (char *)&unk_4A6B20 + 15 * configuration.mineKey;
  v120 = 0;
  v118 = 1162758477;
  do
    v47 = *v46++;
  while ( v47 );
  v48 = v46 - ((char *)&unk_4A6B20 + 15 * configuration.mineKey);
  v49 = (char *)&unk_4A6B20 + 15 * configuration.mineKey;
  v50 = &v115;
  do
  {
    v51 = *((BYTE *)v50 + 1);
    v50 = (char *)v50 + 1;
  }
  while ( v51 );
  memcpy(v50, v49, 4 * (v48 >> 2));
  v52 = screenPtr + 38460;
  memcpy((char *)v50 + 4 * (v48 >> 2), &v49[4 * (v48 >> 2)], v48 & 3);
  drawInRaceMenuText_4072C0(v52, (const char *)&v116);
  v118 = 774778414;
  v116 = 1210064928;
  v117 = 776884815;
  v53 = (char *)&unk_4A6B20 + 15 * configuration.hornKey;
  v119 = 774778414;
  v120 = 0;
  do
    v54 = *v53++;
  while ( v54 );
  v55 = v53 - ((char *)&unk_4A6B20 + 15 * configuration.hornKey);
  v56 = &v115;
  do
  {
    v57 = *((BYTE *)v56 + 1);
    v56 = (char *)v56 + 1;
  }
  while ( v57 );
  memcpy(v56, (char *)&unk_4A6B20 + 15 * configuration.hornKey, v55);
  drawInRaceMenuText_4072C0(screenPtr + 40380, (const char *)&v116);
  drawInRaceMenuText_4072C0(screenPtr + 45500, "      GAMEPAD DEFINITIONS");
  v116 = 1092624416;
  v119 = 774778437;
  v117 = 1279607619;
  v58 = (char *)&unk_479E40 + 15 * configuration.accelerateGamepad;
  v120 = 0;
  v118 = 1413567045;
  do
    v59 = *v58++;
  while ( v59 );
  v60 = v58 - ((char *)&unk_479E40 + 15 * configuration.accelerateGamepad);
  v61 = (char *)&unk_479E40 + 15 * configuration.accelerateGamepad;
  v62 = &v115;
  do
  {
    v63 = *((BYTE *)v62 + 1);
    v62 = (char *)v62 + 1;
  }
  while ( v63 );
  memcpy(v62, v61, 4 * (v60 >> 2));
  v64 = screenPtr + 49340;
  memcpy((char *)v62 + 4 * (v60 >> 2), &v61[4 * (v60 >> 2)], v60 & 3);
  drawInRaceMenuText_4072C0(v64, (const char *)&v116);
  v118 = 774778414;
  v116 = 1109401632;
  v117 = 1162559826;
  v65 = (char *)&unk_479E40 + 15 * configuration.brakeGamepad;
  v119 = 774778414;
  v120 = 0;
  do
    v66 = *v65++;
  while ( v66 );
  v67 = v65 - ((char *)&unk_479E40 + 15 * configuration.brakeGamepad);
  v68 = &v115;
  do
  {
    v69 = *((BYTE *)v68 + 1);
    v68 = (char *)v68 + 1;
  }
  while ( v69 );
  memcpy(v68, (char *)&unk_479E40 + 15 * configuration.brakeGamepad, v67);
  drawInRaceMenuText_4072C0(screenPtr + 51260, (const char *)&v116);
  v117 = 1380271444;
  v120 = 0;
  v116 = 1394614304;
  v70 = (char *)&unk_479E40 + 15 * configuration.leftSteeringGamepad;
  v118 = 1178946592;
  v119 = 774778452;
  do
    v71 = *v70++;
  while ( v71 );
  v72 = v70 - ((char *)&unk_479E40 + 15 * configuration.leftSteeringGamepad);
  v73 = &v115;
  do
  {
    v74 = *((BYTE *)v73 + 1);
    v73 = (char *)v73 + 1;
  }
  while ( v74 );
  v75 = screenPtr;
  memcpy(v73, (char *)&unk_479E40 + 15 * configuration.leftSteeringGamepad, v72);
  drawInRaceMenuText_4072C0(v75 + 53180, (const char *)&v116);
  v116 = 1394614304;
  v119 = 774788168;
  v117 = 1380271444;
  v76 = (char *)&unk_479E40 + 15 * configuration.rightSteeringGamepad;
  v120 = 0;
  v118 = 1195987488;
  do
    v77 = *v76++;
  while ( v77 );
  v78 = v76 - ((char *)&unk_479E40 + 15 * configuration.rightSteeringGamepad);
  v79 = (char *)&unk_479E40 + 15 * configuration.rightSteeringGamepad;
  v80 = &v115;
  do
  {
    v81 = *((BYTE *)v80 + 1);
    v80 = (char *)v80 + 1;
  }
  while ( v81 );
  memcpy(v80, v79, 4 * (v78 >> 2));
  v82 = screenPtr + 55100;
  memcpy((char *)v80 + 4 * (v78 >> 2), &v79[4 * (v78 >> 2)], v78 & 3);
  drawInRaceMenuText_4072C0(v82, (const char *)&v116);
  v118 = 1330594336;
  v116 = 1411391520;
  v117 = 1329746517;
  v83 = (char *)&unk_479E40 + 15 * configuration.turboGamepad;
  v119 = 774788179;
  v120 = 0;
  do
    v84 = *v83++;
  while ( v84 );
  v85 = v83 - ((char *)&unk_479E40 + 15 * configuration.turboGamepad);
  v86 = &v115;
  do
  {
    v87 = *((BYTE *)v86 + 1);
    v86 = (char *)v86 + 1;
  }
  while ( v87 );
  memcpy(v86, (char *)&unk_479E40 + 15 * configuration.turboGamepad, v85);
  drawInRaceMenuText_4072C0(screenPtr + 57020, (const char *)&v116);
  v117 = 1229472577;
  v120 = 0;
  v116 = 1293951008;
  v88 = (char *)&unk_479E40 + 15 * configuration.gunGamepad;
  v118 = 1193297230;
  v119 = 774786645;
  do
    v89 = *v88++;
  while ( v89 );
  v90 = v88 - ((char *)&unk_479E40 + 15 * configuration.gunGamepad);
  v91 = &v115;
  do
  {
    v92 = *((BYTE *)v91 + 1);
    v91 = (char *)v91 + 1;
  }
  while ( v92 );
  v93 = screenPtr;
  memcpy(v91, (char *)&unk_479E40 + 15 * configuration.gunGamepad, v90);
  drawInRaceMenuText_4072C0(v93 + 58940, (const char *)&v116);
  v116 = 1142956064;
  v119 = 774778414;
  v117 = 542134098;
  v94 = (char *)&unk_479E40 + 15 * configuration.mineGamepad;
  v120 = 0;
  v118 = 1162758477;
  do
    v95 = *v94++;
  while ( v95 );
  v96 = v94 - ((char *)&unk_479E40 + 15 * configuration.mineGamepad);
  v97 = (char *)&unk_479E40 + 15 * configuration.mineGamepad;
  v98 = &v115;
  do
  {
    v99 = *((BYTE *)v98 + 1);
    v98 = (char *)v98 + 1;
  }
  while ( v99 );
  memcpy(v98, v97, 4 * (v96 >> 2));
  v100 = screenPtr + 60860;
  memcpy((char *)v98 + 4 * (v96 >> 2), &v97[4 * (v96 >> 2)], v96 & 3);
  drawInRaceMenuText_4072C0(v100, (const char *)&v116);
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();
  v101 = 63;
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToOriginal_4B4020();
    --v101;
  }
  while ( v101 );
  memset(keysRead_45E0C0, 0, 0x100u);
  v102 = 0;
  do
  {
    transformJoystickReadValue_418150();
    v103 = 0;
  
	do
    {
     v104 = (unsigned __int8)keysRead_45E0C0[v103+3]
           + (unsigned __int8)keysRead_45E0C0[v103+1]
          + (unsigned __int8)keysRead_45E0C0[v103];
      v105 = v102 + (unsigned __int8)keysRead_45E0C0[v103+2];
      v103 += 4;
      v102 = v105 + v104;
    }
    while ( v103 < 256 );

    refreshScreenWithDelay();
  }
  while ( !v102 );
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();
  v106 = 63;

  //degradado hacia el color negro
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToBlack_4B4020();
    --v106;
  }
  while ( v106 );
  extractFromBpa("ENGINE.BPA", textureTemp, "INFO2.BPK");
  copyImageToBuffer((int)textureTemp, screenPtr);
  extractFromBpa("ENGINE.BPA", &circuitPalette_4B4020, "INFO2.PAL");
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();

  //degradado hasta el color de la paleta original
  v107 = 63;
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToOriginal_4B4020();
    --v107;
  }
  while ( v107 );
  memset(keysRead_45E0C0, 0, 0x100u);
  v108 = 0;
  do
  {
    transformJoystickReadValue_418150();
    v109 = 0;
    do
    {
      v110 = (unsigned __int8)keysRead_45E0C0[v109+3]
           + (unsigned __int8)keysRead_45E0C0[v109+1]
           + (unsigned __int8)keysRead_45E0C0[v109+0];
      v111 = v108 + (unsigned __int8)keysRead_45E0C0[v109];
      v109 += 4;
      v108 = v111 + v110;
    }
    while ( v109 < 256 );
    refreshScreenWithDelay();
  }
  while ( !v108 );
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();
  v112 = 63;
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToBlack_4B4020();
    --v112;
  }
  while ( v112 );
  memcpy((void *)screenPtr, &unk_491820, 0xFA00u);
  memcpy(&circuitPalette_4B4020, circuitPalette_4A9BA0, 0x300u);
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();
  v113 = 63;
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToOriginal_4B4020();
    --v113;
  }
  while ( v113 );
  result = 0;
  memset(keysRead_45E0C0, 0, 0x100u);
  if ( mushroomTaken_456AA4 == 1 )
  {
    result = 0;
    memset((void *)screenPtr, 0, 0xFA00u);
  }
  return result;
}

//----- (00407330) --------------------------------------------------------
int refreshPaleteCheat()
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
  signed int v9; // esi@1
  char *v10; // eax@3
  char v11; // dl@4
  unsigned int v12; // eax@5
  char *v13; // esi@5
  void *v14; // edi@5
  char v15; // cl@6
  int v16; // ST38_4@7
  char *v17; // eax@7
  char v18; // dl@8
  unsigned int v19; // eax@9
  void *v20; // edi@9
  char v21; // cl@10
  char *v22; // eax@11
  char v23; // dl@12
  unsigned int v24; // eax@13
  void *v25; // edi@13
  char v26; // cl@14
  int v27; // edx@15
  char *v28; // eax@15
  char v29; // dl@16
  unsigned int v30; // eax@17
  char *v31; // esi@17
  void *v32; // edi@17
  char v33; // cl@18
  int v34; // ST38_4@19
  char *v35; // eax@19
  char v36; // dl@20
  unsigned int v37; // eax@21
  void *v38; // edi@21
  char v39; // cl@22
  char *v40; // eax@23
  char v41; // dl@24
  unsigned int v42; // eax@25
  void *v43; // edi@25
  char v44; // cl@26
  int v45; // edx@27
  char *v46; // eax@27
  char v47; // dl@28
  unsigned int v48; // eax@29
  char *v49; // esi@29
  void *v50; // edi@29
  char v51; // cl@30
  int v52; // ST38_4@31
  char *v53; // eax@31
  char v54; // dl@32
  unsigned int v55; // eax@33
  void *v56; // edi@33
  char v57; // cl@34
  char *v58; // eax@35
  char v59; // dl@36
  unsigned int v60; // eax@37
  char *v61; // esi@37
  void *v62; // edi@37
  char v63; // cl@38
  int v64; // ST38_4@39
  char *v65; // eax@39
  char v66; // dl@40
  unsigned int v67; // eax@41
  void *v68; // edi@41
  char v69; // cl@42
  char *v70; // eax@43
  char v71; // dl@44
  unsigned int v72; // eax@45
  void *v73; // edi@45
  char v74; // cl@46
  int v75; // edx@47
  char *v76; // eax@47
  char v77; // dl@48
  unsigned int v78; // eax@49
  char *v79; // esi@49
  void *v80; // edi@49
  char v81; // cl@50
  int v82; // ST38_4@51
  char *v83; // eax@51
  char v84; // dl@52
  unsigned int v85; // eax@53
  void *v86; // edi@53
  char v87; // cl@54
  char *v88; // eax@55
  char v89; // dl@56
  unsigned int v90; // eax@57
  void *v91; // edi@57
  char v92; // cl@58
  int v93; // edx@59
  char *v94; // eax@59
  char v95; // dl@60
  unsigned int v96; // eax@61
  char *v97; // esi@61
  void *v98; // edi@61
  char v99; // cl@62
  int v100; // ST38_4@63
  signed int v101; // esi@63
  int v102; // esi@65
  signed int v103; // eax@66
  int v104; // ecx@67
  int v105; // edx@67
  signed int v106; // esi@69
  signed int v107; // esi@71
  int v108; // esi@73
  signed int v109; // eax@74
  int v110; // ecx@75
  int v111; // edx@75
  signed int v112; // esi@77
  signed int v113; // esi@79
  int result; // eax@81
  char v115; // [sp+Bh] [bp-3Dh]@5
  int v116; // [sp+Ch] [bp-3Ch]@3
  int v117; // [sp+10h] [bp-38h]@3
  int v118; // [sp+14h] [bp-34h]@3
  int v119; // [sp+18h] [bp-30h]@3
  char v120; // [sp+1Ch] [bp-2Ch]@3

 
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();
  v112 = 63;
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToBlack_4B4020();
    --v112;
  }
  while ( v112 );
  memcpy((void *)screenPtr, &unk_491820, 0xFA00u);
  memcpy(&circuitPalette_4B4020, circuitPalette_4A9BA0, 0x300u);
  dword_456AF8 = 0;
  setCircuitPaletteBis_4B4020();
  v113 = 63;
  do
  {
    waitWithRefresh();
    setCircuitPaletteTransitionToOriginal_4B4020();
    --v113;
  }
  while ( v113 );
  result = 0;
  return result;
}

//----- (00409270) --------------------------------------------------------
void __noreturn exitCtrlAltDel()
{
  nullsub_1();
  freeMusic();
  setWindowCaption();
  printf("DEATH RALLY Exit: CTRL+ALT+DEL pressed!\n");
  if ( isMultiplayerGame )
    nullsub_1();
  exit(112);
}

//----- (004092B0) --------------------------------------------------------
int makeSnapshot_4092B0()
{
  unsigned int v0; // eax@4
  char *v1; // edi@4
  char v2; // cl@5
  char *v3; // edi@6
  char v4; // al@7
  FILE *v5; // eax@8
  FILE *v6; // esi@8
  __int32 v7; // edi@9
  bool v8; // sf@10
  unsigned __int8 v9; // of@10
  signed int v10; // esi@11
  char DstBuf; // [sp+Ch] [bp-318h]@2
  char v13; // [sp+Dh] [bp-317h]@3
  char v14; // [sp+Eh] [bp-316h]@3
  int Val2; // [sp+10h] [bp-314h]@1
  char Filename[10]; // [sp+14h] [bp-310h]@4
  __int16 v17; // [sp+18h] [bp-30Ch]@4
  char v18; // [sp+1Ah] [bp-30Ah]@4
  char Str; // [sp+24h] [bp-300h]@13

  Val2 = 0;
  do
  {
    _itoa(Val2, &DstBuf, 10);
    if ( strlen(&DstBuf) != 2 )
    {
      v13 = DstBuf;
      DstBuf = 48;
      v14 = 0;
    }
	memset(Filename,0,10);
    *(_DWORD *)Filename = 1345147720;//P-SH
	
    v18 = 0;
    v17 = 17225;
    v0 = strlen(&DstBuf) + 1;
    v1 = (char *)&Val2 + 3;
    do
      v2 = (v1++)[1];
    while ( v2 );
    memcpy(v1, &DstBuf, v0);
    v3 = (char *)&Val2 + 3;
    do
      v4 = (v3++)[1];
    while ( v4 );
    *(_DWORD *)v3 = 1480806446;//.pcx
    v3[4] = 0;
	strcat(Filename, v3);
    v5 = fopen(Filename, "rb");
    v6 = v5;
    if ( !v5 )
      break;
    fseek(v5, 0, 2);
    v7 = ftell(v6);
    fclose(v6);
    if ( v7 < 1 )
      break;
    v9 = __OFSUB__(Val2 + 1, 100);
    v8 = Val2++ - 99 < 0;
  }
  while ( v8 ^ v9 );
  File = fopen(Filename, "wb");
  fwrite(&unk_4450A8, 1u, 0x80u, File);
  v10 = 0;
  do
  {
    sub_429CF0((unsigned __int8 *)(v10 + screenPtr), 320);
    v10 += 320;
  }
  while ( v10 < 64000 );
  fputc(12, File);
  generateSnapshotData_43C160((int)&Str);
  fwrite(&Str, 1u, 0x300u, File);
  return fclose(File);
}
// 456BF0: using guessed type int screenPtr;

//----- (00409460) --------------------------------------------------------
int generateBigPowerUps()
{
  signed int v0; // eax@1
  signed int v1; // eax@3
  signed int v2; // eax@5
  signed int v3; // eax@7
  int (  *v4)(); // edi@9
  signed int v5; // esi@9
  signed int v6; // eax@11
  int result; // eax@13
  int v8; // esi@14
  int v9; // eax@15
  void *v10; // edi@15
  int v11; // ebp@15
  signed int v12; // eax@15
  int v13; // ecx@16
  int v14; // edx@16
  int v15; // edx@16
  int v16; // ecx@16
  int v17; // edx@16
  int v18; // edx@16
  int v19; // ecx@16
  signed int v20; // ecx@17
  char v21; // dl@19
  char v22; // dl@21
  char v23; // dl@23
  char v24; // dl@25
  void *v25; // edi@33
  int v26; // ebp@33
  signed int v27; // ecx@33
  int v28; // edx@34
  int v29; // esi@34
  int v30; // edx@34
  int v31; // edx@34
  int v32; // esi@34
  int v33; // edx@34
  int v34; // esi@34
  signed int v35; // esi@35
  signed int v36; // ecx@36
  char v37; // dl@37
  char v38; // dl@39
  char v39; // dl@41
  char v40; // dl@43
  char *v41; // [sp+0h] [bp-4h]@15
  char *v42; // [sp+0h] [bp-4h]@33

  v0 =0;

  do{
	 // powerups[v0].posX_501BA0=0;
	 // powerups[v0].posY_501BA4 =0;
	  powerups[v0].powerUp_ID_501BA8=0;
	  powerups[v0].timeShowed_501BB0 =0;
	  powerups[v0].dword_501BB4 =0;
	  powerups[v0].lastPowerUp_ID_501BB8 =0;
	  powerups[v0].repairpercentage_501BBC =0;
	  v4 = rand;
	  powerups[v0].dword_501BAC = rand() % 50 + 100;
	v0++;
  }
  while ( v0 < 16 );
  
  /*v0 =   (signed int)&unk_501BB4;
  do
  {
    *(_DWORD *)v0 = 0;
    v0 += 288;
  }
  while ( v0 < (signed int)&unk_503234 );
  v1 = (signed int)&unk_501BB8;
  do
  {
    *(_DWORD *)v1 = 0;
    v1 += 288;
  }
  while ( v1 < (signed int)&unk_503238 );
  v2 = (signed int)&unk_501BBC;
  do
  {
    *(_DWORD *)v2 = 0;
    v2 += 288;
  }
  while ( v2 < (signed int)&unk_50323C );*/
  
 /* v3 = (signed int)dword_501BA8;
  do
  {
    *(_DWORD *)v3 = 0;
    v3 += 288;
  }
  while ( v3 < (signed int)&unk_503228 );*/
  
  /*v4 = rand;
  v5 = (signed int)dword_501BAC;
  do
  {
    v5 += 288;
    *(_DWORD *)(v5 - 288) = rand() % 50 + 100;
  }
  while ( v5 < (signed int)&unk_50322C );
  v6 = (signed int)dword_501BB0;
  do
  {
    *(_DWORD *)v6 = 0;
    v6 += 288;
  }
  while ( v6 < (signed int)&unk_503230 );
  */
  dword_456AC4 = 350;
  result = rand() % 4;
  //if(debug)result=0;
  if ( !result )
  {
    //v8 = 72 * (rand() % 2 + 12);
	v8 = (rand() % 2 + 12);
	result = powerups[v8].dword_501BAC;
	//result = dword_501BA0[v8];
    //if(debug)result=1;
    if ( result > 0 )
    {
      v9 = rand() % 2;
      v10 = circuitMatrixHxW_5034F8;
      v11 = circuitWidth_464F40;
	  if(v9==0)
		powerups[v8].powerUp_ID_501BA8 =  POWERUP_BIG_MONEY;
	  if(v9==1)
		  powerups[v8].powerUp_ID_501BA8 =  POWERUP_BIG_REPAIR;
	  //powerups[v8].powerUp_ID_501BA8 =v9+7;
      //dword_501BA8[v8] = v9 + 7;
      v12 = 0;
      //v41 = (char *)&unk_501BD0 + v8 * 4;
		v14=0;
	  	
      do
      {
	    v13 = (int)((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 8) - 8);

		//v14 = (int)(v41 - 16);
        powerups[v8].screenBackup_501BC0[v14+0] =*(_DWORD *)(v13 + 4);
        powerups[v8].screenBackup_501BC0[v14+1]= *(_DWORD *)(v13 + 4);
        powerups[v8].screenBackup_501BC0[v14+2] = *(_DWORD *)(v13 + 8);
        powerups[v8].screenBackup_501BC0[v14+3] = *(_DWORD *)(v13 + 12);
        
		v15 = (int)((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 7) - 8);
        powerups[v8].screenBackup_501BC0[v14+4] = *(_DWORD *)v15;
        powerups[v8].screenBackup_501BC0[v14+5] = *(_DWORD *)(v15 + 4);
        powerups[v8].screenBackup_501BC0[v14+6] = *(_DWORD *)(v15 + 8);
        powerups[v8].screenBackup_501BC0[v14+7] = *(_DWORD *)(v15 + 12);
        v16 = (int)((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 6) - 8);
     //   v17 = (int)(v41 + 16);
        powerups[v8].screenBackup_501BC0[v14+8] = *(_DWORD *)v16;
        powerups[v8].screenBackup_501BC0[v14+9] = *(_DWORD *)(v16 + 4);
        powerups[v8].screenBackup_501BC0[v14+10] = *(_DWORD *)(v16 + 8);
        powerups[v8].screenBackup_501BC0[v14+11] = *(_DWORD *)(v16 + 12);
		v18 = (int)((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 5) - 8);
     //   v19 = (int)(v41 + 32);
        powerups[v8].screenBackup_501BC0[v14+12] = *(_DWORD *)v18;
        powerups[v8].screenBackup_501BC0[v14+13] = *(_DWORD *)(v18 + 4);
        powerups[v8].screenBackup_501BC0[v14+14] = *(_DWORD *)(v18 + 8);
        powerups[v8].screenBackup_501BC0[v14+15] = *(_DWORD *)(v18 + 12);
        v12 += 4;
		v14 +=16;
       // v41 += 64;
      }
      while ( v12 < 16 );
      
	  v20 = 0;
      do
      {
        result = 0;
        do
        {
			v21 = *((BYTE *)obstacleBpk + 16 * (16 * powerups[v8].powerUp_ID_501BA8 + v20 - 16) + result);
          if ( v21 )
          {
			  *((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 8) = v21;
            v10 = circuitMatrixHxW_5034F8;
            v11 = circuitWidth_464F40;
          }
          v22 = *((char *)obstacleBpk + 16 * (v20 + 16 * powerups[v8].powerUp_ID_501BA8) + result - 255);
          if ( v22 )
          {
            *((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 7) = v22;
            v10 = circuitMatrixHxW_5034F8;
            v11 = circuitWidth_464F40;
          }
          v23 = *((char *)obstacleBpk + 16 * (v20 + 16 * powerups[v8].powerUp_ID_501BA8) + result - 254);
          if ( v23 )
          {
            *((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 6) = v23;
            v10 = circuitMatrixHxW_5034F8;
            v11 = circuitWidth_464F40;
          }
          v24 = *((char *)obstacleBpk + 16 * (v20 + 16 * powerups[v8].powerUp_ID_501BA8) + result - 253);
          if ( v24 )
          {
			  *((char *)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 5) = v24;
            v10 = circuitMatrixHxW_5034F8;
            v11 = circuitWidth_464F40;
          }
          result += 4;
        }
        while ( result < 16 );
        ++v20;
      }
      while ( v20 < 16 );
      v4 = rand;
    }
  }
  //if(debug==1)
	///  raceParticipant[0].drugPicked==1;
  if ( raceParticipant[0].drugPicked == 1 )
  {
    result = isMultiplayerGame;
    if ( !isMultiplayerGame )
    {
      //result = 288 * (v4() % 2 + 14);
	  result = (v4() % 2 + 14);
      ///if ( *(int *)((char *)dword_501BA0 + result) > 0 )
      
	  if ( powerups[result].posX_501BA0 > 0 )
      {
        v25 = circuitMatrixHxW_5034F8;
        v26 = circuitWidth_464F40;
		powerups[result].powerUp_ID_501BA8 = POWERUP_DRUGS;
        v27 = 0;
		v29=0;
        //v42 = (char *)&unk_501BD0 + result;
        do
        {
          v28 = (int)((char *)v25
			  + *(int *)((char *)powerups[result].posX_501BA0)
			  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v27 - 8)
                    - 8);
          //v29 = (int)(v42 - 16);
		  
          powerups[result].screenBackup_501BC0[v29+0] = *(_DWORD *)v28;
          powerups[result].screenBackup_501BC0[v29+1] = *(_DWORD *)(v28 + 4);
          powerups[result].screenBackup_501BC0[v29+2] = *(_DWORD *)(v28 + 8);
          powerups[result].screenBackup_501BC0[v29+3] = *(_DWORD *)(v28 + 12);
          v30 = (int)((char *)v25
			  + *(int *)((char *)powerups[result].posX_501BA0)
			  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v27 - 7)
                    - 8);
          powerups[result].screenBackup_501BC0[v29+4] = *(_DWORD *)v30;
          powerups[result].screenBackup_501BC0[v29+5] = *(_DWORD *)(v30 + 4);
          powerups[result].screenBackup_501BC0[v29+6] = *(_DWORD *)(v30 + 8);
          powerups[result].screenBackup_501BC0[v29+7] = *(_DWORD *)(v30 + 12);
          v31 = (int)((char *)v25
			  + *(int *)((char *)powerups[result].posX_501BA0)
			  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v27 - 6)
                    - 8);
         // v32 = (int)(v42 + 16);
          powerups[result].screenBackup_501BC0[v29+8] = *(_DWORD *)v31;
          powerups[result].screenBackup_501BC0[v29+9] = *(_DWORD *)(v31 + 4);
          powerups[result].screenBackup_501BC0[v29+10] = *(_DWORD *)(v31 + 8);
          powerups[result].screenBackup_501BC0[v29+11] = *(_DWORD *)(v31 + 12);
          v33 = (int)((char *)v25
			  + *(int *)((char *)powerups[result].posX_501BA0)
			  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v27 - 5)
                    - 8);
          //v34 = (int)(v42 + 32);
          powerups[result].screenBackup_501BC0[v29+12] = *(_DWORD *)v33;
          powerups[result].screenBackup_501BC0[v29+13] = *(_DWORD *)(v33 + 4);
          powerups[result].screenBackup_501BC0[v29+14] = *(_DWORD *)(v33 + 8);
          powerups[result].screenBackup_501BC0[v29+15] = *(_DWORD *)(v33 + 12);
          v27 += 4;
		  v29 +=16;
          //v42 += 64;
        }
        while ( v27 < 16 );
        
		v35 = 0;
        do
        {
          v36 = 0;
          do
          {
            v37 = *((BYTE *)obstacleBpk + 16 * (16 * *(int *)((char *)powerups[result].powerUp_ID_501BA8) + v35 - 16) + v36);
            if ( v37 )
            {
              *((char *)v25
				  + *(int *)((char *)powerups[result].posX_501BA0)
				  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v35 - 8)
              + v36
              - 8) = v37;
              v25 = circuitMatrixHxW_5034F8;
              v26 = circuitWidth_464F40;
            }
            v38 = *((char *)obstacleBpk + 16 * (v35 + 16 * *(int *)((char *)powerups[result].powerUp_ID_501BA8)) + v36 - 255);
            if ( v38 )
            {
              *((char *)v25
				  + *(int *)((char *)powerups[result].posX_501BA0)
				  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v35 - 8)
              + v36
              - 7) = v38;
              v25 = circuitMatrixHxW_5034F8;
              v26 = circuitWidth_464F40;
            }
            v39 = *((char *)obstacleBpk + 16 * (v35 + 16 * *(int *)((char *)powerups[result].powerUp_ID_501BA8)) + v36 - 254);
            if ( v39 )
            {
              *((char *)v25
				  + *(int *)((char *)powerups[result].posX_501BA0)
				  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v35 - 8)
              + v36
              - 6) = v39;
              v25 = circuitMatrixHxW_5034F8;
              v26 = circuitWidth_464F40;
            }
            v40 = *((char *)obstacleBpk + 16 * (v35 + 16 * *(int *)((char *)powerups[result].powerUp_ID_501BA8)) + v36 - 253);
            if ( v40 )
            {
              *((char *)v25
				  + *(int *)((char *)powerups[result].posX_501BA0)
				  + v26 * (*(int *)((char *)powerups[result].posY_501BA4) + v35 - 8)
              + v36
              - 5) = v40;
              v25 = circuitMatrixHxW_5034F8;
              v26 = circuitWidth_464F40;
            }
            v36 += 4;
          }
          while ( v36 < 16 );
          ++v35;
        }
        while ( v35 < 16 );
      }
	  raceParticipant[0].drugPicked = 0;
    }
  }
  return result;
}

//----- (00409A90) --------------------------------------------------------
int initRaceValues_409A90()
{
  int result; // eax@1
  double v1; // st7@1
  signed int v2; // ecx@1
  signed int v3; // ecx@3

  result = 0;
  dword_464F68 = 0;
  v1 = raceParticipant2[userRaceOrder_4A9EA8].steeringCapacity_4A6894;
  raceEffectiveWidth_445010 = 256;
  raceEffectiveHalfWidth_445014 = 128;
  raceEffectiveHeight_445018 = 200;
  raceEffectiveHalfHeight_44501C = 100;
  leftMenuInRaceWidth_456AA0 = 64;
  circuitImageOffsetX_456ABC = 0;
  circuitImageOffsetY_456AC0 = 0;
  dword_464F1C = 0;
  dword_4A7A3C = 0;
  dword_501264 = 0;
  dword_4A6B00 = 0;
  dword_503504 = 0;
  dword_46ECE8 = 0;
  dword_4A8AA4 = 0;
  deployedMines_464F60 = 0;
  flt_481BE4 = 3.75 / v1;
  
  v2=0;

  do{
	  raceMines[v2].unk_481C08=-1;
	  raceMines[v2].unk_481C0C=0;
	  v2++;
  }while ( v2 < 16);
  /*
  v2 = (signed int)&unk_481C08;
  
  do
  {
    *(_DWORD *)v2 = -1;
    v2 += 16;
  }
  while ( v2 < (signed int)&dword_481E08 );
  v3 = (signed int)&unk_481C0C;
  do
  {
    *(_DWORD *)v3 = 0;
    v3 += 16;
  }
  while ( v3 < (signed int)&currentLapTime_481E0C );*/
  dword_4A7CE0[0] = -1;
  dword_4A7CE0[1] = -1;
  dword_4A7CE0[2] = -1;
  dword_479684 = 0;
  dword_4A7CE0[3] = -1;
  dword_481BE8 = 4;

  dukeNukemEndRaceSoundPlayed_456AE8 = 0;

  pokeDamageSelected_456AB0 = 0;
  pokeWeaponsSelected_456AB4 = 0;
  pokeTurboSelected_456AB8 = 0;
  
  isRaceFinish_456AC8 = 0;
  totalRacesFrame_456ACC = 0;

  raceSemaphorePosition_456AD4 = 0;
  criticalDamageSoundPlayed_456ADC = 0;

  criticalDamage2SoundPlayed_456AE0 = 0;
  isLapRecord_456AE4 = 0;

  consecutiveFramesUsingRocket_456AAC = 0;
  mushroomTaken_456AA4 = 0;
 
  rallyGoSoundPlayed_456AD8 = 0;

  framesAfterEndRaceOrCrash_4AA508 = 0;
  dword_445034 = 163840;
  dword_464F6C = 0;
  raceFrame_481E14 = 0;
  ticksToPauseLapTimeInHud_4A9EB0 = 0;
  currentLapTime_481E0C = 0;
  lastCompletedLapTime_503224 = 0;
  totalRaceTime_50A164 = 0;
  dword_503510 = 0;
  return result;
}

//----- (00409BF0) --------------------------------------------------------
signed int loadCircuitInfFile()
{
//  int v0; // eax@1
//  char v1; // cl@2
//  char *v2; // edi@3
//  char v3; // al@4
//  int v4; // eax@5
//  char v5; // cl@6
//  char *v6; // edi@7
//  char v7; // al@8
  signed int v8; // edi@9
  signed int v9; // ebp@9
  signed int v10; // esi@9
  signed int v11; // eax@9
  int v12; // edx@10
  signed int v13; // eax@11
  int v14; // eax@13
  signed int v15; // ecx@13
  int v16; // edx@14
  int v17; // eax@14
  int v18; // edx@14
  int v19; // edx@14
  int index =0;
  signed int result; // eax@15
  char  trxInfName[16];
  int dstBuffer[128];
  /*v0 = 0;
  do
  {
    v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
    *(&circuitSelectedTR_464F50 + v0++) = v1;
  }
  while ( v1 );
  v2 = &circuitSelectedTR_464F50 - 1;
  do
    v3 = (v2++)[1];
  while ( v3 );
  *(_DWORD *)v2 = 1095778862;//.bpa
  v2[4] = 0;
  */
  strcpy(circuitSelectedTR_464F50, raceFilePrefix_45EA50);
  strcat(circuitSelectedTR_464F50, ".BPA");
  /*v4 = 0;
  do
  {
    v5 = *((BYTE *)raceFilePrefix_45EA50 + v4);
    trxINFBin_5034E0[v4++] = v5;
  }
  while ( v5 );
  v6 = &trxINFBin_5034E0[-1];
  do
    v7 = (v6++)[1];
  while ( v7 );
  *(_DWORD *)v6 = 1179535661;//-inf.bin
  *((_DWORD *)v6 + 1) = 1313423918; //bin
  v6[8] = 0;*/
  strcpy(trxInfName, raceFilePrefix_45EA50);
  strcat(trxInfName, "-INF.BIN");
  extractFromBpa(circuitSelectedTR_464F50, dstBuffer, trxInfName);
  //textureTemp es dword_481E20
  v8 = dstBuffer[0];
  v9 = dstBuffer[1];
  circuitVaiZones_4A685C = dstBuffer[2];
  //ststing points x y y direccion
  raceParticipantIngame[0].absolutePositionX_4A7DB4  = (double)dstBuffer[3];
  circuitWidth_464F40 = dstBuffer[0];//ancho de la imagen del circuito
  raceParticipantIngame[0].absolutePositionY_4A7DB8 = (double)dstBuffer[4];
  circuitHeight_4A7CF8 = dstBuffer[1];
  raceParticipantIngame[0].directionRotation_4A7D0C = (unsigned __int64)(double)dstBuffer[5];
  raceParticipantIngame[1].absolutePositionX_4A7DB4  = (double)dstBuffer[6];
  raceParticipantIngame[1].absolutePositionY_4A7DB8 = (double)dstBuffer[7];
  raceParticipantIngame[1].directionRotation_4A7D0C = (unsigned __int64)(double)dstBuffer[8];
  raceParticipantIngame[2].absolutePositionX_4A7DB4  = (double)dstBuffer[9];
  raceParticipantIngame[2].absolutePositionY_4A7DB8 = (double)dstBuffer[10];
  raceParticipantIngame[2].directionRotation_4A7D0C = (unsigned __int64)(double)dstBuffer[11];
  
  raceParticipantIngame[3].absolutePositionX_4A7DB4  = (double)dstBuffer[12];
  raceParticipantIngame[3].absolutePositionY_4A7DB8= (double)dstBuffer[13];
  raceParticipantIngame[3].directionRotation_4A7D0C = (unsigned __int64)(double)dstBuffer[14];

  /* v9 = dword_481E24[0];
  circuitVaiZones_4A685C = dword_481E28;
  *(float *)absolutePositionX_4A7DB4 = (double)dword_481E2C;
  //esto es de la paelta con esto se calculan los colores!
  circuitWidth_464F40 = textureTemp[0];
  *(float *)absolutePositionY_4A7DB8 = (double)dword_481E30;
  //esto es de la paelta
  circuitHeight_4A7CF8 = dword_481E24[0];
  directionRotation_4A7D0C[0] = (unsigned __int64)(double)dword_481E34;
  absolutePositionX_4A7DB4[1] = (double)dword_481E38;
  absolutePositionY_4A7DB8[1] = (double)dword_481E3C;
  directionRotation_4A7D0C[1] = (unsigned __int64)(double)dword_481E40;
  absolutePositionX_4A7DB4[2] = (double)dword_481E44;
  absolutePositionY_4A7DB8[2] = (double)dword_481E48;
  directionRotation_4A7D0C[2] = (unsigned __int64)(double)dword_481E4C;
  v10 = 15;
  absolutePositionX_4A7DB4[3] = (double)dword_481E50;
  absolutePositionY_4A7DB8[3] = (double)dword_481E54;
  directionRotation_4A7D0C[3] = (unsigned __int64)(double)dword_481E58;*/

  v10 = 15;
  //puntos de control x e y donde van los powerups
  index =0;
  //v11 = (signed int)dword_501BA4; //esto da 16 vueltas
  do
  {
    v12 = dword_481E24[v10];
	powerups[index].posX_501BA0= dstBuffer[v10];
	powerups[index].posY_501BA4=  dstBuffer[v10+1];
    //*(_DWORD *)(v11 - 4) = dstBuffer[v10];
    //*(_DWORD *)v11 = v12;
   // v11 += 288;
    v10 += 2;
	index++;
  }
  while ( index<16 );
  //while ( v11 < (signed int)&unk_502DA4 );
  //v13 = (signed int)&unk_479AAC; //20 vueltas
  index =0;
  do
  {
	  pedestrian_479AA4[index].byte8=0;
	  pedestrian_479AA4[index].rotation=0;
	  
	  pedestrian_479AA4[index].byte7=0;
	  pedestrian_479AA4[index].isDied=0;
    /**(_DWORD *)(v13 + 16) = 0;
    *(_DWORD *)v13 = 0;
    *(_DWORD *)(v13 + 12) = 0;
    *(_DWORD *)(v13 + 8) = 0;
    v13 += 32;*/
	index++;
  }
  //while ( v13 < (signed int)&unk_479D2C );
  while ( index<20 );
  v14 = (int)&dstBuffer[v10];
 // v15 = (signed int)&unk_479AA4; //20 vueltas

  index =0;
  //publico 20 , x y ? ?
  do
  {

    v16 = *(_DWORD *)v14;
    v17 = v14 + 4;
	pedestrian_479AA4[index].positionX = v16;
    //*(_DWORD *)(v15 - 4) = v16;
    v18 = *(_DWORD *)v17;
    v17 += 4;
//    *(_DWORD *)v15 = v18;
	pedestrian_479AA4[index].positionY = v18;
    v19 = *(_DWORD *)v17;
    v17 += 4;
    //*(_DWORD *)(v15 + 4) = v19;
	pedestrian_479AA4[index].pedestrianId = v19;    
    //*(_DWORD *)(v15 + 12) = *(_DWORD *)v17;
	pedestrian_479AA4[index].byte5 = *(_DWORD *)v17;
   // v15 += 32;
    v14 = v17 + 4;
	index++;
  }
  //while ( v15 < (signed int)&unk_479D24 );
   while ( index < 20 );
  result = v8 >> 2;
  circuitVaiBpk_width_4A6858 = v8 >> 2;
  circuitVaiBpk_height_503508 = v9 >> 2;
  circuitLR1Bpk_width_4A9B90 = v8 >> 2;
  circuitLR1Bpk_height_467000 = v9 >> 2;
  return result;
}

//----- (00409E50) --------------------------------------------------------
unsigned __int64   setCircuitPaletteValues(int position, float a2, float a3, float a4)
{
  signed int v4; // edi@1
//  char *v5; // esi@1
  double v6; // st3@1
  float v7; // ST10_4@2
  double v8; // st2@2
  signed int v9; // edi@3
//  char *v10; // esi@3
  double v11; // st4@4
  unsigned __int64 result; // rax@4
  signed int v13; // [sp+0h] [bp-Ch]@1
  signed int v14; // [sp+0h] [bp-Ch]@3
   int paletteIndex = 3 * position;
  v4 = 0;
 
  //v5 = circuitPalette_4A9BA0[3 * position];
  v13 = 0;
  v6 = a4 * 0.1;
  do
  {
    v8 = (double)v13;
	circuitPalette_4A9BA0[paletteIndex] = (unsigned __int64)(v8 * ((a2 - a2 * 0.1) * 0.2) + a2 * 0.1);
	circuitPalette_4A9BA0[paletteIndex+1] = (unsigned __int64)(v8 * ((a3 - a3 * 0.1) * 0.2) + a3 * 0.1);
    v7 = (a4 - v6) * 0.2;
	circuitPalette_4A9BA0[paletteIndex+2] = (unsigned __int64)(v8 * v7 + v6);
	paletteIndex += 3;
    ++v4;
    v13 = v4;
  }
  while ( v4 < 5 );
  v9 = 0;
  v14 = 0;
  //v10 = circuitPalette_4A9BA0[3 * (position + 5)];
  paletteIndex = 3 * (position + 5);
  do
  {
    v11 = (double)v14;
	circuitPalette_4A9BA0[paletteIndex] = (unsigned __int64)(v11 * ((63.0 - a2) * 0.2) + a2);
	circuitPalette_4A9BA0[paletteIndex+1] = (unsigned __int64)(v11 * ((63.0 - a3) * 0.2) + a3);
    result = (unsigned __int64)(v11 * ((63.0 - a4) * 0.2) + a4);
	circuitPalette_4A9BA0[paletteIndex+2] = result;
	paletteIndex += 3;
    ++v9;
    v14 = v9;
  }
  while ( v9 < 5 );
  return result;
}

//----- (00409F90) --------------------------------------------------------
int *initRaceValues_409F90()
{
  double v0; // st7@1
  float v1; // ST0C_4@2
  float v2; // ST08_4@2
  float v3; // ST04_4@2
  double v4; // st7@3
  float v5; // ST0C_4@3
  float v6; // ST08_4@3
  float v7; // ST04_4@3
  double v8; // st7@3
  float v9; // ST0C_4@3
  float v10; // ST08_4@3
  float v11; // ST04_4@3
  double v12; // st7@3
  float v13; // ST0C_4@3
  float v14; // ST08_4@3
  float v15; // ST04_4@3
  int v16; // edx@3
  int *result; // eax@3
//  signed int v18; // ecx@3
  int *v19; // ebx@4
  int *v20; // ebx@4
  int *v21; // ebx@4
  int *v22; // ebx@4
  int indexRaceParticipant = 0;
  v0 = raceParticipantIngame[0].directionRotation_4A7D0C * 3.75;
  raceParticipantIngame[0].carAngle_4A7DAC = v0;
  raceParticipantIngame[0].flt_4A7E58 = v0;
  raceParticipantIngame[0].participantBpkOffser_4A7D10 = 1600 * raceParticipantIngame[0].directionRotation_4A7D0C;
  raceParticipantIngame[0].dword_4A7E50 = raceParticipantIngame[0].absolutePositionX_4A7DB4 ;
  raceParticipantIngame[0].dword_4A7E54 = raceParticipantIngame[0].absolutePositionY_4A7DB8;
  raceParticipantIngame[0].currentLap_4A7E08 = 1;
  raceParticipantIngame[0].racePosition_4A7E09 = 1;
  raceParticipantIngame[0].dword_4A804C = 0;
  if ( raceParticipant2[0].carType != 6 )
  {
    v1 = (double)raceParticipant2[0].b;
    v2 = (double)raceParticipant2[0].g;
    v3 = (double)raceParticipant2[0].r;
    setCircuitPaletteValues(15, v3, v2, v1);
  }
  v4 = raceParticipantIngame[1].directionRotation_4A7D0C * 3.75;
  raceParticipantIngame[1].carAngle_4A7DAC = v4;
  raceParticipantIngame[1].flt_4A7E58 = v4;
  v5 = (double)raceParticipant2[1].b;
  /*dword_4A8070*/raceParticipantIngame[1].participantBpkOffser_4A7D10 = 1600 * (raceParticipantIngame[1].directionRotation_4A7D0C + 96);
  raceParticipantIngame[1].dword_4A7E50 = LODWORD(raceParticipantIngame[1].absolutePositionX_4A7DB4 );
  v6 = (double)raceParticipant2[1].g;
  raceParticipantIngame[1].dword_4A7E54 = LODWORD(raceParticipantIngame[1].absolutePositionY_4A7DB8);
 raceParticipantIngame[1].currentLap_4A7E08 = 1;
  raceParticipantIngame[1].racePosition_4A7E09 = 2;
  dword_4A83AC = 0;
  v7 = (double)raceParticipant2[1].r;
  setCircuitPaletteValues(25, v7, v6, v5);
  v8 = raceParticipantIngame[2].directionRotation_4A7D0C * 3.75;
  raceParticipantIngame[2].carAngle_4A7DAC = v8;
  raceParticipantIngame[2].flt_4A7E58 = v8;
  v9 = (double)raceParticipant2[2].b;
  /*dword_4A83D0*/raceParticipantIngame[2].participantBpkOffser_4A7D10 = 1600 * (raceParticipantIngame[2].directionRotation_4A7D0C + 192);
  raceParticipantIngame[2].dword_4A7E50 = LODWORD(raceParticipantIngame[2].absolutePositionX_4A7DB4 );
  v10 = (double)raceParticipant[2].g;
  raceParticipantIngame[2].dword_4A7E54 = LODWORD(raceParticipantIngame[2].absolutePositionY_4A7DB8);
  raceParticipantIngame[2].currentLap_4A7E08 = 1;
  raceParticipantIngame[2].racePosition_4A7E09 = 3;
  dword_4A870C = 0;
  v11 = (double)raceParticipant2[2].r;
  setCircuitPaletteValues(35, v11, v10, v9);
  v12 = raceParticipantIngame[3].directionRotation_4A7D0C * 3.75;
  raceParticipantIngame[3].carAngle_4A7DAC = v12;
  raceParticipantIngame[3].flt_4A7E58 = v12;
  v13 = (double)raceParticipant2[3].b;
  raceParticipantIngame[3].currentLap_4A7E08 = 1;
  v14 = (double)raceParticipant2[3].g;
  /*dword_4A8730*/raceParticipantIngame[3].participantBpkOffser_4A7D10 = 1600 * (raceParticipantIngame[3].directionRotation_4A7D0C + 288);
  raceParticipantIngame[3].dword_4A7E50 = LODWORD(raceParticipantIngame[3].absolutePositionX_4A7DB4 );
  raceParticipantIngame[3].dword_4A7E54 = LODWORD(raceParticipantIngame[3].absolutePositionY_4A7DB8);
  raceParticipantIngame[3].racePosition_4A7E09 = 4;
  v15 = (double)raceParticipant2[3].r;
  dword_4A8A6C = 0;
  setCircuitPaletteValues(45, v15, v14, v13);
  dword_481BE8 = 15;
  v16 = raceParticipant2[userRaceOrder_4A9EA8].steeringCapacity_4A6894;
  result = dword_4A7EA0;
  //v18 = (signed int)&unk_4A7A74;
  //TODO FIX setear bien estos values
  currentDriverSelectedIndex_503518 = 4;
  do
  {
	 raceParticipantIngame[indexRaceParticipant].dword_4A7E9C =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EA0 = 5000 * raceParticipant[indexRaceParticipant].rocket;
	//*result = 5000 * (*(_DWORD *)v18 + 3);

	raceParticipantIngame[indexRaceParticipant].currentSteeringAngleDelta_4A7DA8 =v16;
 
	raceParticipantIngame[indexRaceParticipant].actualVaiZone_4A7D00 =0;
	//raceParticipantIngame[indexRaceParticipant].carAngle_4A7DAC =0;
    raceParticipantIngame[indexRaceParticipant].hasFinishedTheRace_4A7E0C =0;

	raceParticipantIngame[indexRaceParticipant].dword_4A7E8C=0;

	raceParticipantIngame[indexRaceParticipant].dword_4A7D14=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D18=0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7D1C=0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7D20[0]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[1]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[2]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[3]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[4]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[5]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[6]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[7]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[8]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[9]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[10]=0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7D20[11]=0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7D20[12]=0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7D20[13]=0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7D20[14]=0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7D20[15]=0;
   

	 raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[0]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[1]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[2]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[3]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[4]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[5]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[6]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[7]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[8]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[9]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[10]=0;
	raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[11]=0;
    raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[12]=0;
    raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[13]=0;
    raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[14]=0;
    raceParticipantIngame[indexRaceParticipant].lastKeysRead_4A7D60[15]=0;
	
	raceParticipantIngame[indexRaceParticipant].lastKeysReadPreviousIndex_4A7DA4 =0;
	raceParticipantIngame[indexRaceParticipant].lastKeysReadIndex_4A7DA0 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7DC0 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7DC4 =0;
	raceParticipantIngame[indexRaceParticipant].unk_4A7DFC =0;
	raceParticipantIngame[indexRaceParticipant].unk_4A7E00 =0;
	raceParticipantIngame[indexRaceParticipant].unk_4A7E04 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7E80 =0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7E84 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7E88 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7E94 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7E98 =0;
	raceParticipantIngame[indexRaceParticipant].unk_4A7E64 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7E68 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7E6C =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7E70 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EA8 =0;
	raceParticipantIngame[indexRaceParticipant].timeToDeployMine_4A7EA4 =0;

	raceParticipantIngame[indexRaceParticipant].dword_4A7EAC =0;
    raceParticipantIngame[indexRaceParticipant].dword_4A7EB0 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EB4 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[0] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[1] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[2] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[3] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[4] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[5] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[6] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[7] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[8] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[9] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[10] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[11] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[12] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[13] =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE4[14] =0;

	raceParticipantIngame[indexRaceParticipant].dword_4A7EB8 =0;
	
	raceParticipantIngame[indexRaceParticipant].spriteBurnOffset_4A7EDC =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A7EE0 =0;
	raceParticipantIngame[indexRaceParticipant].mushroomPendingTime_4A8050 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A8054 =0;
	raceParticipantIngame[indexRaceParticipant].dword_4A8058 =0;
	raceParticipantIngame[indexRaceParticipant].hornPlayed_4A805C =0;
	
	
	indexRaceParticipant++;
    v16 += 148;
    result += 216;
  }
  while (indexRaceParticipant < 4 );
  //while (v18 < (signed int)&unk_4A7BC4);
  return result;
}

//----- (0040A360) --------------------------------------------------------
int processSceFile_40A360()
{
  int result; // eax@1
  int v1; // ebp@1
  int v2; // esi@2
  int v3; // ebx@6
  int v4; // eax@7
  int v5; // edx@7
  int v6; // ecx@8
  int v7; // esi@9
  int v8; // esi@12
  int v9; // edi@12
  unsigned int v10; // eax@13
  unsigned int v11; // ecx@13
  double v12; // st7@13
  unsigned int v13; // edx@13
  double v14; // st6@13
  double v15; // st4@13
  double v16; // st2@13
  double v17; // ST48_8@13
  double v18; // ST40_8@13
  double v19; // st6@13
  double v20; // st5@13
  double v21; // st7@13
  double v22; // st7@13
  long double v23; // st6@14
  long double v24; // ST40_8@14
  long double v25; // st7@14
  long double v26; // st6@14
  long double v27; // st5@14
  int v28; // eax@16
  int v29; // ecx@16
  int v30; // edx@16
  int v31; // ebx@17
  int v32; // esi@17
  void *v33; // edi@18
  long double v34; // st7@18
  double v35; // st6@20
  double v36; // st6@21
  long double v37; // st6@23
  long double v38; // st6@23
  long double v39; // st6@25
  long double v40; // st5@25
  unsigned __int64 v41; // rax@26
  bool v42; // zf@29
  int v43; // [sp+10h] [bp-48h]@2
  void *v44; // [sp+14h] [bp-44h]@2
  double v45; // [sp+18h] [bp-40h]@13
  float v46; // [sp+18h] [bp-40h]@23
  double v47; // [sp+20h] [bp-38h]@13
  float v48; // [sp+20h] [bp-38h]@23
  int v49; // [sp+28h] [bp-30h]@2
  int v50; // [sp+2Ch] [bp-2Ch]@2
  double v51; // [sp+30h] [bp-28h]@13
  float v52; // [sp+30h] [bp-28h]@23
  int v53; // [sp+3Ch] [bp-1Ch]@2
  double v54; // [sp+50h] [bp-8h]@25
  int id3dObject=0;
  result = trxSCE1Number3DObjects_479D20;
  v1 = 0;
  dword_4AA928 = 0;
  if ( trxSCE1Number3DObjects_479D20 > 0 )
  {
    //v2 = (int)trxSCE2Bpk_4B4320;
    v49 = 0;
    v44 = dword_467020;
    //v43 = (int)trxSCE2Bpk_4B4320;
	v43 =0;
    //v50 = (int)dword_4B484C;
    v53 = trxSCE1Number3DObjects_479D20;
    dword_4AA928 = trxSCE1Number3DObjects_479D20;
    while ( 1 )
    {
		
		if ( sce2Texture[id3dObject].trxSCE2Bpk_4B4320 > 0 )
        memset(v44, 0, 4 * sce2Texture[id3dObject].trxSCE2Bpk_4B4320);
		v3 = sce2Texture[id3dObject].numberTriangles_4B4324;
      if ( v3 > 0 )
      {
       // v4 = v2 + 1324;
		  v4=0;
        v5 = sce2Texture[id3dObject].numberTriangles_4B4324;
        do
        {

			//dword_467020 es una estructura de 300 bytes
          ++dword_467020[v1 + sce2Texture[id3dObject].dword_4B46BC[v4]];
		  ++dword_467020[v1 + sce2Texture[id3dObject].dword_4B484C[v4]];
		  v6 = v1 + sce2Texture[id3dObject].dword_4B49DC[v4];
          v4 += 1;
          --v5;
          ++dword_467020[v6];
        }
        while ( v5 );
      }
      v7 = sce2Texture[id3dObject].trxSCE2Bpk_4B4320;
      if ( v7 > 0 )
      {
        memset(flt_4A8C00, 0, 4 * ((unsigned int)(4 * v7) >> 2));
        memset(flt_4A8AC0, 0, 4 * ((unsigned int)(4 * v7) >> 2));
        memset(flt_4A9A60, 0, 4 * ((unsigned int)(4 * v7) >> 2));
      }
      if ( v3 > 0 )
      {
        //v8 = v50;
		  v8 =0;
        v9 = v3;
        do
        {
          v10 = 4 * (sce2Texture[id3dObject].dword_4B46BC[v8+v49]);
          v11 = 2 * (sce2Texture[id3dObject].dword_4B484C[v8+v49]);
          v12 = (double)sce2Texture[id3dObject].dword_4B4328[v10 / 2] * 0.00390625; //ver si el /2 esta bien
          v13 = 2 * (sce2Texture[id3dObject].dword_4B49DC[v8+v49]);
          v14 = (double)sce2Texture[id3dObject].dword_4B4454[v10 / 4] * 0.00390625;
          v15 = (double)(sce2Texture[id3dObject].dword_4B4580[v10 / 4] - 256);
          v16 = (double)(sce2Texture[id3dObject].dword_4B4580[v13 / 2] - 256) - v15;
          v17 = (double)sce2Texture[id3dObject].dword_4B4454[v11 / 2] * 0.00390625 - v14;
          v18 = (double)(sce2Texture[id3dObject].dword_4B4580[v11 / 2] - 256) - v15;
          v19 = (double)sce2Texture[id3dObject].dword_4B4454[v13 / 2] * 0.00390625 - v14;
          v47 = v17 * v16 - v19 * v18;
          //v20 = (double)*(signed int *)&dword_4B4328[v13] * 0.00390625 - v12;
          //v21 = (double)*(signed int *)&dword_4B4328[v11] * 0.00390625 - v12;
          v20 = sce2Texture[id3dObject].dword_4B4328[v13] * 0.00390625 - v12;
          v21 = sce2Texture[id3dObject].dword_4B4328[v11] * 0.00390625 - v12;
          
		  
		  v45 = v20 * v18 - v21 * v16;
          v51 = v21 * v19 - v20 * v17;
          v22 = v51 * v51 + v45 * v45 + v47 * v47;
          if ( v22 <= 1.0 )
          {
            v25 = 100.0;
            v26 = 100.0;
            v27 = 100.0;
          }
          else
          {
            v23 = sqrt(10000.0 / v22);
            v24 = v23;
            v25 = v23 * v47;
            v26 = v23 * v45;
            v27 = v24 * v51;
          }
          //v28 = 4 * sce2Texture[polygonIndex].dword_4B46BC[v8];
          //v29 = 4 * sce2Texture[polygonIndex].dword_4B484C[v8];
          //v30 = 4 * sce2Texture[polygonIndex].dword_4B49DC[v8];
          v28 = sce2Texture[id3dObject].dword_4B46BC[v8];
          v29 = sce2Texture[id3dObject].dword_4B484C[v8];
          v30 = sce2Texture[id3dObject].dword_4B49DC[v8];
          
		  v8 += 1;
          --v9;
          flt_4A9A60[v28] +=v25;
		  flt_4A9A60[v29] +=v25;
		  flt_4A9A60[v30] +=v25;

		  flt_4A8AC0[v28] +=v26;
		  flt_4A8AC0[v29] +=v26;
		  flt_4A8AC0[v30] +=v26;

		  flt_4A8C00[v28] +=v27;
		  flt_4A8C00[v29] +=v27;
		  flt_4A8C00[v30] +=v27;
		  
        }
        while ( v9 );
      }
      //v31 = *(_DWORD *)v43;
      v31 = sce2Texture[0].trxSCE2Bpk_4B4320;
	  v32 = 0;
      if ( sce2Texture[id3dObject].trxSCE2Bpk_4B4320  > 0 )
      {
        v33 = v44;
        v34 = sqrt(350.0);
        do
        {
          if ( *(_DWORD *)v33 >= 1 )
          {
            v35 = 1.0 / (double)*(signed int *)v33;
            flt_4A9A60[v32] = v35 * flt_4A9A60[v32];
            flt_4A8AC0[v32] = v35 * flt_4A8AC0[v32];
            flt_4A8C00[v32] = v35 * flt_4A8C00[v32];
          }
          v36 = flt_4A8C00[v32] * flt_4A8C00[v32]
              + flt_4A8AC0[v32] * flt_4A8AC0[v32]
              + flt_4A9A60[v32] * flt_4A9A60[v32];
          if ( v36 < 1.0 )
            v36 = 1.0;
          v37 = sqrt(10000.0 / v36);
          v46 = flt_4A9A60[v32] * v37;
          flt_4A9A60[v32] = v46;
          v48 = flt_4A8AC0[v32] * v37;
          flt_4A8AC0[v32] = v48;
          v38 = v37 * flt_4A8C00[v32];
          flt_4A8C00[v32] = v38;
          v52 = v38 * v38 + v48 * v48;
          if ( v46 * v46 + v52 < 1.0 )
            flt_4A9A60[v32] = v46 + 1.0;
          v39 = v48 * -10.0 - v38 * 15.0 - flt_4A9A60[v32] * 10.0;
          v40 = sqrt(flt_4A9A60[v32] * flt_4A9A60[v32] + v52);
          v54 = v39 / (v40 * v34);
          if ( v54 <= 0.0 )
            v41 = (unsigned __int64)((v39 / (sqrt(425.0) * v40) + 1.0) * 3.0);
          else
            v41 = (unsigned __int64)(v54 * 5.0 + 3.0);
          *(_DWORD *)v33 = v41;
          ++v32;
          v33 = (char *)v33 + 4;
        }
        while ( v32 < sce2Texture[id3dObject].trxSCE2Bpk_4B4320  );
      }
      v1 += 75;
      result = v53 - 1;
      v42 = v53 == 1;
      //v49 += 788;
	  v49++;
      //v50 += 3152;
	  //v43 += 3152;
	  v43+=1;
	  id3dObject++;
      v44 = (char *)v44 + 300;
      --v53;
      if ( v42 )
        break;
      //v2 = v43;
    }
  }
  return result;
}

//----- (0040A880) --------------------------------------------------------
int calculateSceTextureStructure_40A880()
{
  int v0; // edx@1
  void *v1; // ebx@2
  int *v2; // esi@2
  int v3; // ebp@2
  int v4; // edx@3
  bool v5; // zf@3
  bool v6; // sf@3
  int result; // eax@7
  int v8; // ebp@8
  int v9; // ebx@8
  int v10; // ecx@9
  int v11; // edi@9
  int v12; // edx@10
  int v13; // esi@11
  int v14; // ecx@14
  int *v15; // [sp+10h] [bp-8h]@8
  int v16; // [sp+14h] [bp-4h]@9
  int id3dObject =0;
  v0 = trxSCE1Number3DObjects_479D20;
  if ( trxSCE1Number3DObjects_479D20 > 0 )
  {
    v1 = dword_46F220;
   // v2 = numberTriangles_4B4324;
    v3 = trxSCE1Number3DObjects_479D20;
    do
    {
		if(id3dObject==11){
			id3dObject=11;
			}
      //v4 = *v2;
		v4 = sce2Texture[id3dObject].numberTriangles_4B4324;
      
	  v5 = sce2Texture[id3dObject].numberTriangles_4B4324 == 0;
      v6 = sce2Texture[id3dObject].numberTriangles_4B4324 < 0;
      dword_481BE8 = 0;
      if ( !v6 && !v5 )
      {
        memset(v1, 0xFFu, 4 * v4);
        dword_481BE8 = v4;
      }
      //v2 += 788;
	  id3dObject++;
      v1 = (char *)v1 + 400;
	  
      --v3;
    }
    while ( v3 );
    v0 = trxSCE1Number3DObjects_479D20;
  }
  result = 0;
  dword_4AA928 = 0;
  if ( v0 > 0 )
  {

	
    v8 = trxSCE3Bpk_464F10;
    v9 = 0;
	id3dObject=0;
 //   v15 = numberTriangles_4B4324;
    do
    {
	  v10 = sce2Texture[id3dObject].numberTriangles_4B4324;
      v11 = 0;
      v5 = sce2Texture[id3dObject].numberTriangles_4B4324 == 0;
      v6 = sce2Texture[id3dObject].numberTriangles_4B4324 < 0;
      dword_481BE8 = 0;
      v16 = v10;
      if ( !v6 && !v5 )
      {
        do
        {
			//esto no se como va
          v12 = 0;
          dword_4A6AFC = 0;
          if ( v8 > 0 )
          {
            v13 = 0;// &unk_50A1A8;
            do
            {
				if ( id3dObject == sce4Texture[v13].id3dObject_50A1A4 && v11 == sce4Texture[v13].idPolygon_50A1A8)
              {
                v14 = id3dObject + v11;
				//if ( dword_46F220[v9 + v11] == -1 )
                if ( dword_46F220[id3dObject][v11] == -1 )
                  dword_46F220[id3dObject][v11]= v12;
                else
					dword_46F220[id3dObject][v11] = v12;
                
					//dword_46F220[v14-1] = v12;
                
                  //dword_46F21C[v14] = v12;
              }
              ++v12;
              v13 = v13+1;//(char *)v13 + 44;
            }
            while ( v12 < v8 );
            v10 = v16;
            dword_4A6AFC = v12;
          }
          ++v11;
        }
        while ( v11 < v10 );
        v0 = trxSCE1Number3DObjects_479D20;
        dword_481BE8 = v11;
      }
      ++result;
	  id3dObject++;
      v9 += 1;//100;
   //   v15 += 788;
    }
    while ( id3dObject < v0 );
    dword_4AA928 = id3dObject;
  }
  return result;
}

//----- (0040A9A0) --------------------------------------------------------
int calculateCircuitReversed_40A9A0()
{
  int v0; // ebx@1
  int v1; // edi@1
  int v2; // ecx@1
  int i; // esi@1
  char v4; // dl@2
  int v5; // ecx@3
  int v6; // esi@3
  char v7; // dl@4
  int v8; // ecx@5
  int j; // esi@5
  char v10; // dl@6
  int v11; // ecx@7
  int k; // esi@7
  char v13; // dl@8
  int v14; // ecx@10
  signed int v15; // eax@10
  char *v16; // esi@11
  char v17; // dl@11
  int v18; // ebp@12
  int v19; // esi@12
  signed int v20; // eax@13
  char v21; // dl@14
  int v22; // ebp@16
  int v23; // esi@16
  signed int v24; // eax@17
  char *v25; // ecx@18
  char v26; // dl@18
  bool v27; // sf@20
  unsigned __int8 v28; // of@20
  signed int v29; // ebp@21
  signed int v30; // eax@22
  signed int v31; // ecx@22
  char *v32; // esi@23
  char v33; // dl@23
  int v34; // ebx@25
  int v35; // edi@25
  signed int v36; // esi@25
  unsigned __int64 v37; // rax@26
  int v38; // edx@26
  int v39; // ecx@26
  int v40; // eax@26
  int v41; // eax@28
  double v42; // st7@28
  signed int v43; // eax@29
  int v44; // ecx@30
  signed int v45; // eax@35
  int v46; // ecx@36
  int v47; // ecx@41
  int l; // eax@41
  int v49; // edi@42
  unsigned __int64 v50; // rax@43
  int v51; // esi@44
  int v52; // edi@44
  int v53; // ecx@45
  int v54; // eax@46
  int v55; // ecx@48
  int v56; // eax@49
  double v57; // st7@51
  int v58; // ecx@51
  double v59; // st7@51
  int v60; // ecx@51
  int v61; // ebp@51
  int v62; // ebp@53
  double v63; // st7@54
  double v64; // st6@54
  int v65; // esi@54
  int v66; // ebx@54
  int v67; // edi@55
  double v68; // st5@55
  int v69; // ST18_4@55
  int v70; // ecx@57
  __int64 v71; // rax@58
  int v72; // esi@58
  int v73; // eax@59
  char *v74; // edi@59
  char v75; // dl@59
  __int64 v76; // rax@59
  int v78; // [sp+10h] [bp-Ch]@9
  int v79; // [sp+14h] [bp-8h]@9
  signed int v80; // [sp+18h] [bp-4h]@12
  signed int v81; // [sp+18h] [bp-4h]@16
  int v82; // [sp+18h] [bp-4h]@56
  int pedestrianIndex = 0;
  v0 = circuitWidth_464F40;
  v1 = circuitHeight_4A7CF8;
  v2 = circuitWidth_464F40 * circuitHeight_4A7CF8;
  for ( i = 0; i < circuitWidth_464F40 * circuitHeight_4A7CF8 / 2; ++i )
  {
    v4 = *((BYTE *)circuitMatrixHxW_5034F8 + i);
    *((BYTE *)circuitMatrixHxW_5034F8 + i) = *((char *)circuitMatrixHxW_5034F8 + v2 - i - 1);
    *((char *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * circuitHeight_4A7CF8 - i - 1) = v4;
    v1 = circuitHeight_4A7CF8;
    v0 = circuitWidth_464F40;
    v2 = circuitWidth_464F40 * circuitHeight_4A7CF8;
  }
  v5 = v0 * v1;
  v6 = 0;
  if ( v0 * v1 / 2 > 0 )
  {
    do
    {
      v7 = *((BYTE *)trxImaBpk_50A16C + v6);
      *((BYTE *)trxImaBpk_50A16C + v6) = *((char *)trxImaBpk_50A16C + v5 - v6 - 1);
      *((char *)trxImaBpk_50A16C + circuitWidth_464F40 * circuitHeight_4A7CF8 - v6 - 1) = v7;
      v5 = circuitWidth_464F40 * circuitHeight_4A7CF8;
      ++v6;
    }
    while ( v6 < circuitWidth_464F40 * circuitHeight_4A7CF8 / 2 );
  }
  v8 = circuitVaiBpk_width_4A6858 * circuitVaiBpk_height_503508;
  for ( j = 0; j < circuitVaiBpk_width_4A6858 * circuitVaiBpk_height_503508 / 2; ++j )
  {
    v10 = *((BYTE *)trxVaiBpk_5034D0 + j);
    *((BYTE *)trxVaiBpk_5034D0 + j) = *((char *)trxVaiBpk_5034D0 + v8 - j - 1);
    *((char *)trxVaiBpk_5034D0 + circuitVaiBpk_width_4A6858 * circuitVaiBpk_height_503508 - j - 1) = v10;
    v8 = circuitVaiBpk_width_4A6858 * circuitVaiBpk_height_503508;
  }
  v11 = circuitLR1Bpk_width_4A9B90 * circuitLR1Bpk_height_467000;
  for ( k = 0; k < circuitLR1Bpk_width_4A9B90 * circuitLR1Bpk_height_467000 / 2; ++k )
  {
    v13 = *((BYTE *)trxLR1Bpk_4AA920 + k);
    *((BYTE *)trxLR1Bpk_4AA920 + k) = *((char *)trxLR1Bpk_4AA920 + v11 - k - 1);
    *((BYTE *)trxLR1Bpk_4AA920 + circuitLR1Bpk_width_4A9B90 * circuitLR1Bpk_height_467000 - k - 1) = v13;
    //v11 = circuitLR1Bpk_width_4A9B90 * circuitLR1Bpk_height_467000;
  }
  v78 = 0;
  v79 = 0;
  do
  {
    v14 = v78;
    v15 = 0;
    do
    {
      v16 = (char *)participantCarBpk_5034FC + v78 + v15;
      v17 = *v16;
      *v16 = *((BYTE *)participantCarBpk_5034FC + v14 + 153599);
      ++v15;
      *((BYTE *)participantCarBpk_5034FC + v14-- + 153599) = v17;
    }
    while ( v15 < 76800 );
    v18 = v79;
    v19 = v78 + 75200;
    v80 = 24;
    do
    {
      v20 = 0;
      do
      {
        v21 = *((BYTE *)participantCarBpk_5034FC + v18 + v20);
        *((BYTE *)participantCarBpk_5034FC + v18 + v20) = *((BYTE *)participantCarBpk_5034FC + v19 + v20);
        *((BYTE *)participantCarBpk_5034FC + v19 + v20++) = v21;
      }
      while ( v20 < 1600 );
      v18 += 1600;
      v19 -= 1600;
      --v80;
    }
    while ( v80 );
    v22 = v79 + 76800;
    v23 = v78 + 152000;
    v81 = 24;
    do
    {
      v24 = 0;
      do
      {
        v25 = (char *)participantCarBpk_5034FC + v22 + v24;
        v26 = *v25;
        *v25 = *((BYTE *)participantCarBpk_5034FC + v23 + v24);
        *((BYTE *)participantCarBpk_5034FC + v23 + v24++) = v26;
      }
      while ( v24 < 1600 );
      v22 += 1600;
      v23 -= 1600;
      --v81;
    }
    while ( v81 );
    v28 = __OFSUB__(v79 + 153600, 614400);
    v27 = v79 - 460800 < 0;
    v79 += 153600;
    v78 += 153600;
  }
  while ( v27 ^ v28 );
  v29 = 0;
  do
  {
    v30 = 0;
    v31 = v29;
    do
    {
      v32 = (char *)pedestrBpk + v29 + v30;
      v33 = *v32;
      *v32 = *((BYTE *)pedestrBpk + v31 + 255);
      ++v30;
      *((BYTE *)pedestrBpk + v31-- + 255) = v33;
    }
    while ( v30 < 128 );
    v29 += 256;
  }
  while ( v29 < 9216 );
  v34 = circuitWidth_464F40;
  v35 = 0;
 // v36 = (signed int)directionRotation_4A7D0C;raceParticipantIngame[0].directionRotation_4A7D0C
  do
  {
    raceParticipantIngame[v35].absolutePositionX_4A7DB4 = (double)(signed int)(circuitWidth_464F40 - raceParticipantIngame[v35].absolutePositionX_4A7DB4 - 1);//absolutePositionX_4A7DB4
    v37 = raceParticipantIngame[v35].absolutePositionY_4A7DB8;
    v38 = circuitHeight_4A7CF8;
    v39 = circuitHeight_4A7CF8 - raceParticipantIngame[v35].absolutePositionY_4A7DB8;
    v27 = raceParticipantIngame[v35].directionRotation_4A7D0C - 48 < 0;
    v40 = raceParticipantIngame[v35].directionRotation_4A7D0C - 48;
    raceParticipantIngame[v35].directionRotation_4A7D0C = v40;
    raceParticipantIngame[v35].absolutePositionY_4A7DB8 = (double)(v39 - 1);
    if ( v27 )
      raceParticipantIngame[v35].directionRotation_4A7D0C = v40 + 95;
    v41 = 1600 * raceParticipantIngame[v35].directionRotation_4A7D0C;
    v42 = raceParticipantIngame[v35].directionRotation_4A7D0C * 3.75;
    raceParticipantIngame[v35].carAngle_4A7DAC = v42;
    raceParticipantIngame[v35].flt_4A7E58 = v42;
    raceParticipantIngame[v35].participantBpkOffser_4A7D10 = v41;
    //v36 += 864;
    v35 += 1;
  }
  while ( v35 < 4 );

//  v43 = (signed int)dword_501BA4;
  v43 = 0;
  do
  {
    //v44 = *(_DWORD *)(v43 - 4);
	v44 = powerups[v43].posX_501BA0;
    
	if ( v44 > 0 )
       powerups[v43].posX_501BA0 = circuitWidth_464F40 - powerups[v43].posX_501BA0 - 1;
	if (  powerups[v43].posY_501BA4 > 0 )
       powerups[v43].posY_501BA4 = circuitHeight_4A7CF8 - powerups[v43].posY_501BA4 - 1;
	  //*(_DWORD *)v43 = v38 - *(_DWORD *)v43 - 1;
    //v43 += 288;
	v43++;
  }
  //while ( v43 < (signed int)&unk_502DA4 );
  
  while ( v43 < 16);
  //v45 = (signed int)&unk_479AA4;
  do
  {
    //v46 = *(_DWORD *)(v45 - 4);
	  v46 = pedestrian_479AA4[pedestrianIndex].positionX;
    if ( v46 > 0 )
     pedestrian_479AA4[pedestrianIndex].positionX = circuitWidth_464F40 - pedestrian_479AA4[pedestrianIndex].positionX - 17;
    if ( pedestrian_479AA4[pedestrianIndex].positionY > 0 )
      pedestrian_479AA4[pedestrianIndex].positionY = circuitHeight_4A7CF8 - pedestrian_479AA4[pedestrianIndex].positionY - 17;
   // v45 += 32;
	pedestrianIndex++;
  }
  //while ( v45 < (signed int)&unk_479D24 );
  while(pedestrianIndex <20);
  v47 = trxSHA1Bpk_50E718;
  for ( l = 0; l < v47; ++l )
  {
    v49 = trxSHA4Bpk_4A9FE0[l];
    trxSHA3Bpk_479280[l] = circuitWidth_464F40 - trxSHA3Bpk_479280[l] - 1;
    trxSHA4Bpk_4A9FE0[l] = circuitHeight_4A7CF8 - v49 - 1;
  }
  LODWORD(v50) = trxSCE1Number3DObjects_479D20;
 if ( trxSCE1Number3DObjects_479D20 > 0 )
  {
    //v51 = (int)trxSCE2Bpk_4B4320;
    v51=0;
	  v52 = trxSCE1Number3DObjects_479D20;
    do
    {
      v53 = 0;
      if ( sce2Texture[v51].trxSCE2Bpk_4B4320 > 0 )
      {
		  v54=0;
        //v54 = v51 + 8;
        do
        {
         sce2Texture[v51].dword_4B4328[v53] = -sce2Texture[v51].dword_4B4328[v53];
          ++v53;
          v54 += 1;//4;
        }
        while ( v53 < sce2Texture[v51].trxSCE2Bpk_4B4320 );
      }
      v55 = 0;
      if ( sce2Texture[v51].trxSCE2Bpk_4B4320 > 0 )
      {
		  v56=0;
        //v56 = v51 + 308;
        do
        {

			sce2Texture[v51].dword_4B4454[v56] = -sce2Texture[v51].dword_4B4454[v56];
         // *(_DWORD *)v56 = -*(_DWORD *)v56;
          ++v55;
          v56 +=1;// 4;
        }
        while ( v55 < sce2Texture[v51].trxSCE2Bpk_4B4320 );
      }
      v57 =   sce2Texture[v51].dword_4B46AC[0];//  (double)*(signed int *)(v51 + 908);
      sce2Texture[v51].dword_4B46AC[0] = -sce2Texture[v51].dword_4B46AC[1]; //+912
      v50 = (unsigned __int64)-v57;

	      v58 = -sce2Texture[v51].dword_4B46AC[3]; //+920
      v59 = -sce2Texture[v51].dword_4B46AC[2];//916
      sce2Texture[v51].dword_4B46AC[1] = v50;
      sce2Texture[v51].dword_4B46AC[2] = v58;
      v60 =sce2Texture[v51].unk_4B4CFC;// *(_DWORD *)(v51 + 2524);
      v61 = sce2Texture[v51].unk_4B4D00;
      sce2Texture[v51].dword_4B46AC[3] = (unsigned __int64)v59;
      LODWORD(v50) = circuitHeight_4A7CF8 - v61 - 1;
      sce2Texture[v51].unk_4B4CFC= circuitWidth_464F40 - v60 - 1;
	  sce2Texture[v51].unk_4B4D00 =  v50;
      v51++;//= 3152;
      --v52;
    }
    while ( v52 );
    v38 = circuitHeight_4A7CF8;
  }
  v62 = trxSCE3Bpk_464F10;
 if ( trxSCE3Bpk_464F10 > 0 )
  {
    v63 = (double)((circuitWidth_464F40 << 8) - 256);
    v64 = (double)((circuitHeight_4A7CF8 << 8) - 256);
    v65 = 0;//(int)dword_50A18C;
    v66 = trxSCE3Bpk_464F10;
    do
    {
		v67 = sce4Texture[v65].dword_50A194;//  *(_DWORD *)(v65 + 8);
      v68 = sce4Texture[v65].dword_50A190;
	  v69 = v67 * sce4Texture[v65].textureHeight_50A184;
	  sce4Texture[v65].dword_50A18C = (unsigned __int64)(v63 - sce4Texture[v65].dword_50A18C - (double)(v67 * sce4Texture[v65].tetureWidth_50A180));
      v50 = (unsigned __int64)(v64 - v68 - (double)v69);
	  sce4Texture[v65].dword_50A190 = v50;
      v65 +=1;// 44;
      --v66;
    }
    while ( v66 );
  }
  v82 = 0;

  if ( v62 > 0 )
  {
    v70 = 0;//textureHeight_50A184
    do
    {
		v71 = sce4Texture[v70].tetureWidth_50A180  * sce4Texture[v70].textureHeight_50A184;
      v72 = 0;
      if ( ((signed int)v71 - HIDWORD(v71)) >> 1 > 0 )
      {
        do
        {
          v73 =sce4Texture[v70].textureOffset_50A188;
          v74 = (char *)trxSCE5Bpk_4A7A28 + v73 + v72;
          v75 = *v74;
          *v74 = *((char *)trxSCE5Bpk_4A7A28 + v73 + sce4Texture[v70].textureHeight_50A184 * sce4Texture[v70].tetureWidth_50A180 - v72 - 1);
          *((char *)trxSCE5Bpk_4A7A28 + sce4Texture[v70].textureOffset_50A188+ sce4Texture[v70].textureHeight_50A184 * sce4Texture[v70].tetureWidth_50A180 - v72 - 1) = v75;
          v76 = sce4Texture[v70].textureHeight_50A184* sce4Texture[v70].tetureWidth_50A180;
          ++v72;
        }
        while ( v72 < ((signed int)v76 - HIDWORD(v76)) >> 1 );
        v62 = trxSCE3Bpk_464F10;//parece el numero de texturas
      }
      LODWORD(v50) = v82 + 1;
      v70 +=1;// 44;
      ++v82;
    }
    while ( v82 < v62 );
  }
  return v50;
}

//----- (0040AFC0) --------------------------------------------------------
int calculateIAMovements_40AFC0()
{
  int v0; // esi@1
  long double v1; // st7@1
  int v2; // ebp@1
  int v3; // ebx@2
  int v4; // edi@4
  int v5; // ecx@4
  int v6; // eax@4
  int v7; // eax@7
  long double v8; // st7@15
  int v9; // ebx@15
  unsigned __int64 v10; // rax@15
  int v11; // edi@16
  int v12; // ebp@16
  int v13; // ecx@17
  int v14; // edx@17
  long double v15; // st7@33
  double v16; // ST20_8@33
  double v17; // ST18_8@33
  signed int v18; // ebp@33
  signed int v19; // edi@33
  long double v20; // st7@33
  signed int v21; // ebx@33
  unsigned __int64 v22; // rax@33
  char v23; // bl@49
  int v24; // edi@49
  int v25; // ecx@49
  signed int v26; // edx@49
  signed int v27; // eax@49
  int v28; // ecx@58
  signed int v29; // edx@58
  signed int v30; // eax@58
  int v31; // eax@67
  int v32; // ebp@68
  int v33; // cl@68
  int v34; // dl@68
  int v35; // eax@75
  bool v36; // zf@79
  unsigned int v37; // eax@79
  int v38; // ecx@81
  int v39; // eax@99
  int v40; // eax@101
  int v41; // eax@103
  long double v42; // st7@105
  int v43; // ebp@105
  int v44; // ebx@106
  int v45; // edi@108
  int v46; // ecx@108
  int v47; // eax@117
  long double v48; // st7@119
  int v49; // ebp@119
  int v50; // ebx@120
  int v51; // edi@122
  int v52; // ecx@122
  long double v53; // st7@130
  int v54; // ebp@130
  int v55; // ebx@131
  int v56; // edi@133
  int v57; // ecx@133
  long double v58; // st7@141
  int v59; // ebp@141
  int v60; // ebx@142
  int v61; // edi@144
  int v62; // ecx@144
  int v63; // edx@153
  int result; // eax@155
  int v65; // ebp@158
  char v66; // [sp+13h] [bp-15h]@49
  int v67; // [sp+14h] [bp-14h]@1
  int v68; // [sp+14h] [bp-14h]@105
  int v69; // [sp+14h] [bp-14h]@119
  int v70; // [sp+14h] [bp-14h]@130
  int v71; // [sp+14h] [bp-14h]@141
  int v72; // [sp+18h] [bp-10h]@1
  int v73; // [sp+18h] [bp-10h]@105
  int v74; // [sp+18h] [bp-10h]@119
  int v75; // [sp+18h] [bp-10h]@130
  int v76; // [sp+18h] [bp-10h]@141
  int v77; // [sp+20h] [bp-8h]@141

  v0 = currentDriverSelectedIndex_503518;
  dword_50E71C = 0;
  v1 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC + 180.0) * 0.01745329251994444;
  v67 = (unsigned __int64)(sin(v1) * 35.0 + raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 );
  v72 = (unsigned __int64)(cos(v1) * 35.0 + raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8);
  v2 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    //v3 = (int)absolutePositionY_4A7DB8;
    do
    {
      if ( v2 != currentDriverSelectedIndex_503518 )
      {
		  v4 = v67 - raceParticipantIngame[v2].absolutePositionX_4A7DB4;
		  v5 = v72 - raceParticipantIngame[v2].absolutePositionY_4A7DB8;
        v6 = v4;
        if ( v4 < 0 )
          v6 = -v4;
        if ( v6 < 20 )
        {
          v7 = v72 - raceParticipantIngame[v2].absolutePositionY_4A7DB8;
          if ( v5 < 0 )
            v7 = -v5;
          if ( v7 < 20
			  && *((BYTE *)participantCarBpk_5034FC + 40 * v5 + raceParticipantIngame[v2].participantBpkOffser_4A7D10 + v4 + 820) > 3u
            && !raceParticipantIngame[v0].dword_4A7E88
            && ! raceParticipantIngame[v0].hasFinishedTheRace_4A7E0C )
            raceParticipantIngame[v0].dword_4A7E88 = 100;
        }
      }
      ++v2;
      //v3 += 864;
    }
    while ( v2 < numberOfParticipants_508D24 );
  }
  v8 = (raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444;
  v9 = (unsigned __int64)(sin(v8) * 25.0 + raceParticipantIngame[v0].absolutePositionX_4A7DB4);
  v10 = (unsigned __int64)(cos(v8) * 25.0 + raceParticipantIngame[v0].absolutePositionY_4A7DB8);
  if ( deployedMines_464F60 > 0 )
  {
	  v11=0;
    //v11 = (int)dword_481C04;
    v12 = deployedMines_464F60;
    do
    {
      //v13 = v9 - *(_DWORD *)(v11 - 4);
		v13 = v9 - raceMines[v11].dword_481C00;
      //v14 = v10 - *(_DWORD *)v11;
		v14 = v10 - raceMines[v11].dword_481C04;
      if ( v13 < 0 )
        v13 = -v13;
      if ( v13 < 20 )
      {
        if ( v14 < 0 )
          v14 = -v14;
        if ( v14 < 20 && !raceParticipantIngame[v0].dword_4A7E88 && ! raceParticipantIngame[v0].hasFinishedTheRace_4A7E0C )
          raceParticipantIngame[v0].dword_4A7E88 = 60;
      }
      //v11 += 16;
	  v11+=1;
      --v12;
    }
    while ( v12 );
  }

  /*if(v0==1){
	  v0=1;
	  }*/
  if (raceParticipantIngame[v0].dword_4A7E94 > 5 && !raceParticipantIngame[v0].dword_4A7E84 )
    raceParticipantIngame[v0].dword_4A7E84 = 100;
  if ( dword_4A7E98[v0] > 3 && !raceParticipantIngame[v0].dword_4A7E88 )
    raceParticipantIngame[v0].dword_4A7E88 = 100;
  v15 = (raceParticipantIngame[v0].carAngle_4A7DAC + 206.0) * 0.01745329251994444;
  v16 = raceParticipantIngame[v0].absolutePositionX_4A7DB4;
  v17 = raceParticipantIngame[v0].absolutePositionY_4A7DB8;
  v18 = (unsigned __int64)(sin(v15) * 40.0 + v16);
  v19 = (unsigned __int64)(cos(v15) * 40.0 + v17);
  v20 = (raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 - 26.0) * 0.01745329251994444;
  v21 = (unsigned __int64)(sin(v20) * 40.0 + v16);
  v22 = (cos(v20) * 40.0 + v17);
  if ( v18 > circuitWidth_464F40 - 1 )
    v18 = circuitWidth_464F40 - 1;
  if ( v18 < 0 )
    v18 = 0;
  if ( v21 > circuitWidth_464F40 - 1 )
    v21 = circuitWidth_464F40 - 1;
  if ( v21 < 0 )
    v21 = 0;
  if ( v19 > circuitHeight_4A7CF8 - 1 )
    v19 = circuitHeight_4A7CF8 - 1;
  if ( v19 < 0 )
    v19 = 0;
  if ( (signed int)v22 > circuitHeight_4A7CF8 - 1 )
    LODWORD(v22) = circuitHeight_4A7CF8 - 1;
  if ( (v22 & 0x80000000) != 0 )
    LODWORD(v22) = 0;
  BYTE4(v22) = *((BYTE *)trxLR1Bpk_4AA920 + circuitLR1Bpk_width_4A9B90 * (v19 >> 2) + (v18 >> 2));
  v23 = *((BYTE *)trxLR1Bpk_4AA920 + circuitLR1Bpk_width_4A9B90 * ((signed int)v22 >> 2) + (v21 >> 2));
  v24 = &raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20];
  v66 = BYTE4(v22);
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] = 0;
  v25 =raceParticipantIngame[v0].mushroomPendingTime_4A8050;
  v26 = 0;
  v27 = 560;//esto sirve para desviar a la ia cuando coge la seta
  do
  {
    if ( v25 > v27 - 30 && v25 < v27 )
      v26 = 1;
    v27 -= 60;
  }
  while ( v27 >= 60 );
  if ( v26 && !raceParticipantIngame[v0].hasFinishedTheRace_4A7E0C && raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898 > 0 )
    *(_DWORD *)v24 |= IN_RACE_LEFT;
  v28 = raceParticipantIngame[v0].mushroomPendingTime_4A8050;
  v29 = 0;
  v30 = 530;
  do
  {
    if ( v28 > v30 - 30 && v28 < v30 )
      v29 = 1;
    v30 -= 60;
  }
  while ( v30 >= 30 );
  if ( v29 && !raceParticipantIngame[v0].hasFinishedTheRace_4A7E0C && raceParticipant2[ currentDriverSelectedIndex_503518].damageBar_4A6898 > 0 )
    *(_DWORD *)v24 |= IN_RACE_RIGHT;
  v31 = dword_4A7E80[v0];
  if ( v31 < 100 )
  {
    v32 = *((BYTE *)trxVaiBpk_5034D0
          + circuitVaiBpk_width_4A6858 * ((signed int)raceParticipantIngame[v0].absolutePositionY_4A7DB8 >> 2)
          + ( (signed int)raceParticipantIngame[v0].absolutePositionX_4A7DB4 >> 2));
    v33 = 16 - v66;
	if(v33<0)
		v33=-v33;
    v34 = 16 - v23;
    if(v34<0)
		v34=-v34;

	if (  raceParticipant2[currentDriverSelectedIndex_503518].efectiveEngine_4A6884> 0.0 || raceParticipantIngame[ v0].carVelocity_4A7DB0 > 0.5 )
    {
      if ( raceParticipantIngame[v0].dword_4A7E88 )
      {
        v35 = trxOHIDat_46EE00[v32];
        if ( v33 > v35 + 1 )
          *(_DWORD *)v24 |= IN_RACE_RIGHT;
        if ( v34 >= v35 - 1 )
          goto LABEL_79;
      }
      else
      {
        if ( v33 > 9u )
          *(_DWORD *)v24 |= IN_RACE_RIGHT;
        if ( v34 >= 7u )
          goto LABEL_79;
      }
      *(_DWORD *)v24 |= IN_RACE_LEFT;
    }
LABEL_79:
    v37 = rand() & 0x80000001;
    v36 = v37 == 0;
    if ( (v37 & 0x80000000) != 0 )
      v36 = (((BYTE)v37 - 1) | 0xFFFFFFFE) == -1;
    v38 = currentDriverSelectedIndex_503518;
    if ( v36
      && dword_4A7E98[ currentDriverSelectedIndex_503518] > 3
      && !raceParticipantIngame[currentDriverSelectedIndex_503518].hasFinishedTheRace_4A7E0C
	&& raceParticipant2[ currentDriverSelectedIndex_503518].damageBar_4A6898 > 0 )
	raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] |= IN_RACE_RIGHT;
    v0 = v38;
    if ( trxDRVDat_501280[v32] *  raceParticipant2[v38].efectiveEngine_4A6884 > raceParticipantIngame[ v38].carVelocity_4A7DB0 && !raceParticipantIngame[v0].dword_4A7E84 )
     raceParticipantIngame[ v38].dword_4A7D20[dword_4A7A20] |= IN_RACE_ACELERATE;
	
    raceParticipantIngame[v38].currentSteeringAngleDelta_4A7DA8 = flt_4796A0[v32] * raceParticipant2[v38].steeringCapacity_4A6894;
    goto LABEL_97;
  }
  if ( v31 > 148 && raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 > 0.5 )
    *(_DWORD *)v24 |= IN_RACE_BRAKE;
  if ( dword_4A7E80[v0] < 148 )
    *(_DWORD *)v24 |= IN_RACE_LEFT;
  if ( raceParticipantIngame[v0].dword_4A7E84 > 0 )
    *(_DWORD *)v24 = IN_RACE_BRAKE;
LABEL_97:
  if ( raceParticipantIngame[v0].dword_4A7E88 > 0 )
	  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] |= IN_RACE_TURBO;
  v39 = dword_4A7E80[v0];
  if ( v39 > 0 )
    dword_4A7E80[v0] = v39 - 1;
  v40 = raceParticipantIngame[v0].dword_4A7E84;
  if ( v40 > 0 )
    raceParticipantIngame[v0].dword_4A7E84 = v40 - 1;
  v41 = raceParticipantIngame[v0].dword_4A7E88;
  if ( v41 > 0 )
    raceParticipantIngame[v0].dword_4A7E88 = v41 - 1;
  v42 = raceParticipantIngame[v0].carAngle_4A7DAC * 0.01745329251994444;
  v68 = (unsigned __int64)(sin(v42) * 55.0 +  raceParticipantIngame[v0].absolutePositionX_4A7DB4);
  v73 = (unsigned __int64)(cos(v42) * 55.0 + raceParticipantIngame[v0].absolutePositionY_4A7DB8);
  v43 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
  //  v44 = (int)absolutePositionY_4A7DB8;
    do
    {
      if ( v43 != currentDriverSelectedIndex_503518 )
      {
		  v45 = v68 - raceParticipantIngame[v43].absolutePositionX_4A7DB4;
        v46 = v73 - raceParticipantIngame[v43].absolutePositionY_4A7DB8;
        if ( v45 < 0 )
          v45 = -v45;
        if ( v45 < 20 )
        {
          if ( v46 < 0 )
            v46 = -v46;
          if ( v46 < 20 && !raceParticipantIngame[v0].timeToDeployMine_4A7EA4 )
          {
            raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] |= IN_RACE_MINE;
            raceParticipantIngame[v0].timeToDeployMine_4A7EA4 = 350;
          }
        }
      }
      ++v43;
      //v44 += 864;
    }
    while ( v43 < numberOfParticipants_508D24 );
  }
  v47 = raceParticipantIngame[v0].timeToDeployMine_4A7EA4;
  if ( v47 > 0 )
    raceParticipantIngame[v0].timeToDeployMine_4A7EA4 = v47 - 1;
  v48 = raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 * 0.01745329251994444;
  v69 = (unsigned __int64)(sin(v48) * 20.0 +  raceParticipantIngame[v0].absolutePositionX_4A7DB4);
  v74 = (unsigned __int64)(cos(v48) * 20.0 + raceParticipantIngame[v0].absolutePositionY_4A7DB8);
  v49 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    /*v50 = (int)absolutePositionY_4A7DB8;*/
    do
    {
      if ( v49 != currentDriverSelectedIndex_503518 )
      {
		  v51 = v69 - raceParticipantIngame[v49].absolutePositionX_4A7DB4;
        v52 = v74 - raceParticipantIngame[v49].absolutePositionY_4A7DB8;
        if ( v51 < 0 )
          v51 = -v51;
        if ( v51 < 20 )
        {
          if ( v52 < 0 )
            v52 = -v52;
          if ( v52 < 20 )
			  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] |= IN_RACE_GUN;
        }
      }
      ++v49;
      //v50 += 864;
    }
    while ( v49 < numberOfParticipants_508D24 );
  }
  v53 = raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 * 0.01745329251994444;
  v70 = (unsigned __int64)(sin(v53) * 50.0 +  raceParticipantIngame[v0].absolutePositionX_4A7DB4);
  v75 = (unsigned __int64)(cos(v53) * 50.0 + raceParticipantIngame[v0].absolutePositionY_4A7DB8);
  v54 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    /*v55 = (int)absolutePositionY_4A7DB8;*/
    do
    {
      if ( v54 != currentDriverSelectedIndex_503518 )
      {
		  v56 = v70 - raceParticipantIngame[v54].absolutePositionX_4A7DB4;
        v57 = v75 - raceParticipantIngame[v54].absolutePositionY_4A7DB8;
        if ( v56 < 0 )
          v56 = -v56;
        if ( v56 < 20 )
        {
          if ( v57 < 0 )
            v57 = -v57;
          if ( v57 < 20 )
			  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] |= IN_RACE_GUN;
        }
      }
      ++v54;
    //  v55 += 864;
    }
    while ( v54 < numberOfParticipants_508D24 );
  }
  v58 = raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 * 0.01745329251994444;
  v71 = (unsigned __int64)(sin(v58) * 80.0 +  raceParticipantIngame[v0].absolutePositionX_4A7DB4);
  v59 = currentDriverSelectedIndex_503518;
  v76 = (unsigned __int64)(cos(v58) * 80.0 + raceParticipantIngame[v0].absolutePositionY_4A7DB8);
  v77 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    /*v60 = (int)absolutePositionY_4A7DB8;*/
    do
    {
      if ( v77 != v59 )
      {
		  v61 = v71 - raceParticipantIngame[v77].absolutePositionX_4A7DB4;
        v62 = v76 - raceParticipantIngame[v77].absolutePositionY_4A7DB8;
        if ( v61 < 0 )
          v61 = -v61;
        if ( v61 < 20 )
        {
          if ( v62 < 0 )
            v62 = -v62;
          if ( v62 < 20 )
			  raceParticipantIngame[ v59].dword_4A7D20[dword_4A7A20] |= IN_RACE_GUN;
        }
      }
    //  v60 += 864;
      ++v77;
    }
    while ( v77 < numberOfParticipants_508D24 );
  }
  //si estas cerca random y pitido
  if ( raceParticipantIngame[v0].dword_4A7E88 == 70 )
  {
    v63 = rand() % 5;
    v59 = currentDriverSelectedIndex_503518;
    if ( !v63 )
      raceParticipantIngame[currentDriverSelectedIndex_503518].hornPlayed_4A805C = 1;
  }
  result = 864 * v59;
  if ( !raceParticipantIngame[v59].dword_4A7E88 )
    raceParticipantIngame[v59].hornPlayed_4A805C = 0;
  if ( raceParticipantIngame[v59].hornPlayed_4A805C == 1 )
  {
    v65 = dword_4A7A20 + 216 * v59;
    result = raceParticipantIngame[ v59].dword_4A7D20[dword_4A7A20];
    raceParticipantIngame[v59].dword_4A7D20[dword_4A7A20]|= IN_RACE_HORN;
  }
  return result;
}

//----- (0040B920) --------------------------------------------------------
int balanceIAEngineInRace_40B920()
{
  int result; // eax@1
  int v1; // edi@4
  int v2; // ebx@5
  int *v3; // esi@5
  int v4; // edx@5
  double v5; // st7@7
  int v6; // eax@10
  int v7; // ecx@10
  int v8; // [sp+0h] [bp-34h]@2
  int v9; // [sp+4h] [bp-30h]@1
  int v10; // [sp+8h] [bp-2Ch]@1
  int v11; // [sp+Ch] [bp-28h]@1
  int v12; // [sp+10h] [bp-24h]@1
  int v13; // [sp+14h] [bp-20h]@1
  int v14; // [sp+18h] [bp-1Ch]@1
  int v15; // [sp+1Ch] [bp-18h]@1
  int v16; // [sp+20h] [bp-14h]@1
  int v17; // [sp+24h] [bp-10h]@1
  int v18; // [sp+28h] [bp-Ch]@1
  int v19; // [sp+2Ch] [bp-8h]@1
  int v20; // [sp+30h] [bp-4h]@1

  result = userRaceOrder_4A9EA8;
  v9 = 0.07;
  v10 = 0.12;
  v11 = 0.11;
  v12 = 0.2;
  v13 = 0.18;
  v14 = 0.32;
  v15 = 0.12;
  v16 = 0.19;
  v17 = 0.06;
  v18 = 0.12;
  v19 = 0.03;
  v20 = 0.06;
  if ( userRaceOrder_4A9EA8 )
    v8 = raceParticipant[0].difficulty;
  else
    v8 = raceParticipant[1].difficulty;
  v1 = 0;
  currentDriverSelectedIndex_503518 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {    
    //v3 = &dword_4A6888;
	  //v3 = raceParticipant2[4].efectiveEngineBackup_4A6888;
    //v4 = (int)actualVaiZone_4A7D00;
	v4=0;
    while ( 1 )
    {
      v5 = 1.0;
      if ( (v1 != result || dword_464F6C) && raceParticipant2[4].efectiveEngineBackup_4A6888 > 0 )
      {
		  //v6 es el numero de vai zones cubiertas en la carrera
       // v6 = v2 * (unsigned __int8)currentLap_4A7E08[864 * result] + actualVaiZone_4A7D00[216 * result];
	   v6 = circuitVaiZones_4A685C * raceParticipantIngame[result].currentLap_4A7E08 + raceParticipantIngame[result].actualVaiZone_4A7D00;
	   
        v7 = circuitVaiZones_4A685C * raceParticipantIngame[v4].currentLap_4A7E08 + raceParticipantIngame[v4].actualVaiZone_4A7D00;
        if ( v7 == v6 - 1 )
          v5 = *((float *)&v9 + 2 * v8) + 1.0;
        if ( v7 <= v6 - 2 )
          v5 = *((float *)&v10 + 2 * v8) + 1.0;
        if ( selectedRaceId != 2 )
        {
          if ( v7 == v6 + 1 )
            v5 = 1.0 - *((float *)&v15 + 2 * v8);
          if ( v7 >= v6 + 2 )
            v5 = 1.0 - *((float *)&v16 + 2 * v8);
        }
      }
      result = numberOfParticipants_508D24;
      ++v1;
      //v4 += 864;
	  v4++;

	  raceParticipant2[v4].efectiveEngine_4A6884 = v5 * raceParticipant2[v4].efectiveEngineBackup_4A6888;
     // *((float *)v3 - 1) = v5 * *(float *)v3;
      //v3 += 37;
      if ( v1 >= result )
        break;
      result = userRaceOrder_4A9EA8;
    }
    currentDriverSelectedIndex_503518 = v1;
  }
  return result;
}

//----- (0040BAB0) --------------------------------------------------------
void calculateUserMovements_40BAB0()
{
  int v0; // edi@1
  unsigned int v1; // esi@1
  int v2; // ecx@1
  bool v3; // zf@1
  bool v4; // sf@1
  int v5; // edx@3
  int v6; // eax@3
  double v7; // st7@6
  int v8; // eax@7
  double v9; // st7@10
  double v10; // st7@13
  int v11; // eax@15
  double v12; // st7@21
  int v13; // eax@22
  int v14; // eax@29
  double v16; // st7@35
  unsigned __int8 v17; // c0@35
  unsigned __int8 v18; // c2@35
  int v19; // edi@40
  double v20; // st7@43
  double v21; // st6@43
  long double v22; // st7@64
  long double v23; // st7@64
  long double v24; // st6@64
  long double v25; // st6@64
  long double v26; // st5@64
  long double v27; // st5@64
  long double v28; // st4@64
  int v29; // et1@65
  double v31; // st3@65
  unsigned __int8 v32; // c0@65
  unsigned __int8 v33; // c2@65
  long double v34; // st4@67
  double v35; // st6@69
  long double v36; // st7@69
  int v37; // ebp@69
  int v38; // edi@69
  unsigned __int64 v39; // rax@69
  int v40; // edi@69
  void *v41; // ebx@69
  int v42; // edi@73
  int v43; // edi@77
  int v44; // edi@81
  int v45; // edi@85
  int v46; // edi@89
  int v47; // edi@93
  int v48; // rax@97 //TODO FIX unsigned int64
  int v49; // edi@97
  int v50; // eax@97
  int v51; // edx@97
  unsigned int v52; // esi@97
  int v53; // ecx@98
  int v54; // eax@98
  int v55; // ecx@98
  signed int v56; // ebx@99
  int v57; // edi@101
  unsigned int v58; // esi@101
  int v59; // edi@101
  signed int v60; // ecx@101
  int v61; // eax@102
  int v62; // ST44_4@104
  double v63; // st7@104
  double v64; // st7@108
  int v65; // esi@112
  int v66; // edi@112
  unsigned __int64 v67; // rax@112
  int v68; // eax@112
  unsigned int v69; // ecx@112
  int v70; // eax@116
  int v71; // ebx@124
  int v72; // ebp@124
  int v73; // ecx@135
  int v74; // eax@135
  int v75; // esi@187
  double v76; // st7@187
  double v77; // st7@187
  int v78; // ST44_4@199
  double v79; // st7@199
  double v80; // st7@203
  int v81; // [sp+18h] [bp-28h]@91
  int v82; // [sp+1Ch] [bp-24h]@95
  int v83; // [sp+20h] [bp-20h]@79
  int v84; // [sp+24h] [bp-1Ch]@83
  int v85; // [sp+28h] [bp-18h]@87
  float v86; // [sp+2Ch] [bp-14h]@64
  int v87; // [sp+2Ch] [bp-14h]@75
  float v88; // [sp+30h] [bp-10h]@64
  int v89; // [sp+30h] [bp-10h]@71

  v0 = currentDriverSelectedIndex_503518;
  v1 = 864 * currentDriverSelectedIndex_503518;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60 = 0;
  v2 =  37*v0;
  v3 = raceParticipant2[ v0].damageBar_4A6898 == 0;
  v4 = raceParticipant2[ v0].damageBar_4A6898 < 0;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C = 0;
  dword_50E71C = 0;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 * 0.02;
  if ( v4 || v3 )
    goto LABEL_64;
  if ( raceParticipantIngame[currentDriverSelectedIndex_503518].hasFinishedTheRace_4A7E0C )
  {
LABEL_31:
	  if ( raceParticipant2[v0].damageBar_4A6898 > 0 )
      goto LABEL_33;
    goto LABEL_32;
  }
  v5 = &raceParticipantIngame[v0].dword_4A7D20[dword_4A7A20];
 //v5 = 4 * (dword_4A7A20 + 216 * v0) + dword_4A7D20;
 
  v6 = raceParticipantIngame[v0].dword_4A7D20[dword_4A7A20];
  if ( v6 & IN_RACE_ACELERATE )//acelerar
  {
	  if ( v6 & IN_RACE_TURBO && raceParticipant2[v0].turboBar_4A68B4 > 0 )//tecla mayus
    {
      v7 =  raceParticipant2[v0].efectiveEngine_4A6884;
	  if ( raceParticipant2[v0].rocket )
      {
		  v8 = raceParticipant2[v0].damageBar_4A6898;
		  raceParticipant2[v0].damageBar_4A6898 = v8 - 22;
        raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = v7 * 1.5 * 0.03333333333333333 + raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0;
        if ( v8 - 22 < 0 )
			raceParticipant2[v0].damageBar_4A6898 = 0;
        usingRocket_4A68D8[v2] = 1;
        goto LABEL_13;
      }
      v9 = v7 * 1.3;
    }
    else
    {
      v9 = raceParticipant2[v0].efectiveEngine_4A6884 * 0.8;
    }
    raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = v9 * 0.03333333333333333 + raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0;
LABEL_13:
    v10 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 * 0.033333335;
    raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = 0.02 * v10 + v10;
  }
  if ( v0 == userRaceOrder_4A9EA8 )
  {
    v11 = usingRocket_4A68D8[v2];
    if ( v11 == 1 )
      ++consecutiveFramesUsingRocket_456AAC;
    if ( !v11 )
      consecutiveFramesUsingRocket_456AAC = 0;
  }
  if ( *(_DWORD *)v5 & IN_RACE_BRAKE && !(*(_DWORD *)v5 & IN_RACE_MINE) )
  {
    v12 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - raceParticipant2[v0].efectiveEngine_4A6884 * 0.33333334 * 0.03333333333333333;
    raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = 0.02 * (v12 - 0.033333335 * v12) + v12 - 0.033333335 * v12;
  }
  v13 = *(_DWORD *)v5 & IN_RACE_TURBO;
  if ( v13 )
  {
	  if ( raceParticipant2[v0].turboBar_4A68B4 > 0 && raceParticipant2[v0].damageBar_4A6898 > 0 )
    {
		v4 = raceParticipant2[v0].turboBar_4A68B4 - 400 < 0;
		raceParticipant2[v0].turboBar_4A68B4 -= 400;
      if ( v4 )
		  raceParticipant2[v0].turboBar_4A68B4 = 0;
    }
  }
  if ( v13 )
    goto LABEL_31;
  if ( raceParticipant2[v0].damageBar_4A6898 > 0 )
  {
	  v14 = raceParticipant2[v0].turboBar_4A68B4 + 20;
	  v4 = raceParticipant2[v0].turboBar_4A68B4 - 102380 < 0;
	  raceParticipant2[v0].turboBar_4A68B4 = v14;
    if ( !((unsigned __int8)(v4 ^ __OFSUB__(v14, 102400)) | (v14 == 102400)) )
		raceParticipant2[v0].turboBar_4A68B4 = 102400;
    goto LABEL_31;
  }
LABEL_32:
  raceParticipant2[v2].efectiveEngine_4A6884 = 0;
LABEL_33:
  if ( raceParticipantIngame[currentDriverSelectedIndex_503518].hasFinishedTheRace_4A7E0C || raceParticipant2[v0].efectiveEngine_4A6884 <= 0.0 )
  {
   raceParticipantIngame[v0].dword_4A7DBC = raceParticipantIngame[v0].dword_4A7DBC - 0.1 *raceParticipantIngame[v0].dword_4A7DBC;
  }
  else
  {
    raceParticipantIngame[v0].dword_4A7DBC = raceParticipantIngame[v0].dword_4A7DC0
                             * raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0
							 * (raceParticipant2[v0].efectiveTire_4A688C
							 / raceParticipant2[v0].efectiveEngine_4A6884);
    v16 = raceParticipantIngame[v0].dword_4A7DBC;
	if(raceParticipantIngame[v0].dword_4A7DC0 | raceParticipantIngame[v0].dword_4A7DC4)  
		v16 = -v16;
	//if(debug==1) v17=1;if(debug==1)v18=1;
	//if ( v17 | v18 )
      //v16 = -v16;
    if ( v16 > 20.0 )
      raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - 0.02 * raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0;
  }
  v19 = dword_4A7A20 + v0;
  if ( raceParticipantIngame[v0].dword_4A7D20[dword_4A7A20] & 8 )//giro derecha
  {

	  
    if ( !raceParticipantIngame[v0].dword_4A7D18 && !raceParticipantIngame[v0].dword_4A7D1C )
    {
		//if(debug==1) raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8=2;
		//fix para que funcione como el original
		v2 = *((BYTE *)trxVaiBpk_5034D0
          + circuitVaiBpk_width_4A6858 * ((int)raceParticipantIngame[v0].absolutePositionY_4A7DB8 >> 2)
          + ((int)raceParticipantIngame[v0].absolutePositionX_4A7DB4 >> 2));
		//v2=1;
		raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8 = flt_4796A0[v2] * raceParticipant2[v0].steeringCapacity_4A6894;
      v20 = -((raceParticipant2[v0].carSize_4A6890) / (90.0 / raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8));
      v21 =  raceParticipantIngame[v0].dword_4A7DBC * 0.027777778 * v20;
      *(float *)&dword_50E71C = v20 - (v21 + v21);
      raceParticipantIngame[v0].carAngle_4A7DAC = raceParticipantIngame[v0].carAngle_4A7DAC -  raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8;
      if ( raceParticipantIngame[v0].dword_4A7DC0 > -36.0 )
        raceParticipantIngame[v0].dword_4A7DC0 = raceParticipantIngame[v0].dword_4A7DC0 - 2.0;
    }
  }
  if (raceParticipantIngame[v0].carAngle_4A7DAC < 0.0 )
    raceParticipantIngame[v0].carAngle_4A7DAC = raceParticipantIngame[v0].carAngle_4A7DAC+360.0;
  if ( raceParticipantIngame[v0].dword_4A7D20[dword_4A7A20] & 4 )//giro izquierda
  {
    if ( !raceParticipantIngame[v0].dword_4A7D18 && !raceParticipantIngame[v0].dword_4A7D1C)
    {
	//		if(debug==1) raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8=2;
    //fix para que funcione como el original
		v2 = *((BYTE *)trxVaiBpk_5034D0
          + circuitVaiBpk_width_4A6858 * ((int)raceParticipantIngame[v0].absolutePositionY_4A7DB8 >> 2)
          + ((int) raceParticipantIngame[v0].absolutePositionX_4A7DB4 >> 2));
		//v2=1;
		raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8 = flt_4796A0[v2] * raceParticipant2[v0].steeringCapacity_4A6894;
      *(float *)&dword_50E71C = (raceParticipant2[v0].carSize_4A6890 / (90.0 / raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8)
                               + *(float *)&dword_50E71C)
                              * ( raceParticipantIngame[v0].dword_4A7DBC* 0.027777778 + raceParticipantIngame[v0].dword_4A7DBC * 0.027777778 + 1.0);
      raceParticipantIngame[v0].carAngle_4A7DAC = raceParticipantIngame[v0].carAngle_4A7DAC+ raceParticipantIngame[v0].currentSteeringAngleDelta_4A7DA8;
      if (raceParticipantIngame[v0].dword_4A7DC0  < 36.0 )
        raceParticipantIngame[v0].dword_4A7DC0  =raceParticipantIngame[v0].dword_4A7DC0  + 2.0;
    }
  }
  if ( raceParticipantIngame[v0].carAngle_4A7DAC >= 360.0 )
    raceParticipantIngame[v0].carAngle_4A7DAC = raceParticipantIngame[v0].carAngle_4A7DAC - 360.0;
  if ((raceParticipantIngame[v0].dword_4A7DC0) > 0.0 )
    (raceParticipantIngame[v0].dword_4A7DC0) = (raceParticipantIngame[v0].dword_4A7DC0) - 1.0;
  if ( (raceParticipantIngame[v0].dword_4A7DC0) < 0.0 )
    (raceParticipantIngame[v0].dword_4A7DC0)= (raceParticipantIngame[v0].dword_4A7DC0) + 1.0;
  if ( raceParticipant2[v0].damageBar_4A6898 > 0 )
     raceParticipantIngame[v0].carAngle_4A7DAC =  raceParticipantIngame[v0].unk_4A7E04 +  raceParticipantIngame[v0].carAngle_4A7DAC;
  if (  raceParticipantIngame[v0].carAngle_4A7DAC < 0.0 )
     raceParticipantIngame[v0].carAngle_4A7DAC = raceParticipantIngame[v0].carAngle_4A7DAC + 360.0;
  if (  raceParticipantIngame[v0].carAngle_4A7DAC >= 360.0 )
    raceParticipantIngame[v0].carAngle_4A7DAC =  raceParticipantIngame[v0].carAngle_4A7DAC - 360.0;
	
LABEL_64:
  v22 = (raceParticipantIngame[v0].carAngle_4A7DAC + 270.0) * 0.01745329251994444;
  flt_464F70 = sin(v22) * *(float *)&dword_50E71C;
  v23 = cos(v22) * *(float *)&dword_50E71C * 0.833333;

  
  v24 = (raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444;
  v86 = sin(v24) * raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0;
  v25 = cos(v24) * raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 * 0.833333;
  v26 = (raceParticipantIngame[v0].carAngle_4A7DAC - 90.0 + 180.0) * 0.01745329251994444;
  v88 = sin(v26) * raceParticipantIngame[v0].dword_4A7DBC * 0.09090909090909091;
  v27 = cos(v26) * raceParticipantIngame[v0].dword_4A7DBC * 0.07575754545454545;
  v28 = (v88 + v86) * (v88 + v86) + (v27 + v25) * (v27 + v25);
  if ( v28 == 0.0 )
  {
    v34 = 1.0;
  }
  else
  {
    v29 =  raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0;
	v31 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0;
	//if(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4!=0.0 | raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 !=0.0)
		///v31 = -v31;
	/*if ( v32 | v33 )
      v31 = -v31;*/
    v34 = v31 / sqrt(v28);
  }
  dword_4AA924 = 0;
   raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C = (v88 + v86) * v34;
   raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60 = (v27 + v25) * v34;
   if(raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60<-100 || raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60>100)
	   raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60=raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  v35 = flt_464F70;
  LODWORD(flt_464F70) = 0;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C = v35 + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60 = v23 + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
   if(raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60<-100 || raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60>100)
	   raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60=raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C = (raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7DFC) + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60 = (raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7E00) + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
   if(raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60<-100 || raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60>100)
	   raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60=raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DC4 = sin(( raceParticipantIngame[v0].carAngle_4A7DAC + 206.0) * 0.01745329251994444) * 18.0
                           +  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DC8 = cos(( raceParticipantIngame[v0].carAngle_4A7DAC + 206.0) * 0.01745329251994444) * 14.999994
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DCC = sin(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 - 26.0) * 0.01745329251994444) * 18.0
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DD0 = cos(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 - 26.0) * 0.01745329251994444) * 14.999994
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DD4 = sin(( raceParticipantIngame[v0].carAngle_4A7DAC+ 334.0) * 0.01745329251994444) * 18.0
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DD8 = cos(( raceParticipantIngame[v0].carAngle_4A7DAC + 334.0) * 0.01745329251994444) * 14.999994
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DDC = sin(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 - 154.0) * 0.01745329251994444) * 18.0
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DE0 = cos(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 - 154.0) * 0.01745329251994444) * 14.999994
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DE4 = sin(( raceParticipantIngame[v0].carAngle_4A7DAC + 270.0) * 0.01745329251994444) * 8.0
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DE8 = cos(( raceParticipantIngame[v0].carAngle_4A7DAC + 270.0) * 0.01745329251994444) * 6.666664
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DEC = sin(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 - 90.0) * 0.01745329251994444) * 8.0
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DF0 = cos(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0 - 90.0) * 0.01745329251994444) * 6.666664
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60;
  raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7DF4 = sin(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444) * 22.0
                           + raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C;
  
  v36 = cos(( raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444) * 18.333326 +  raceParticipantIngame[ v0].advanceYAxis_4A7E60;
  raceParticipantIngame[v0].dword_4A7DF8 = v36;
  v37 = circuitWidth_464F40;
  v38 = circuitWidth_464F40 * (unsigned __int64)(v36 + raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8);
  v39 = raceParticipantIngame[v0].dword_4A7DF4+  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4;
  v4 = (signed int)v39 + v38 < 0;
  v40 = v39 + v38;
  v41 = trxImaBpk_50A16C;
  if ( v4 || v40 >= circuitWidth_464F40 * circuitHeight_4A7CF8 )
    v89 = 15;
  else
    v89 = *((BYTE *)trxImaBpk_50A16C + v40) & 0xF;
  v42 = raceParticipantIngame[v0].dword_4A7DC4 +  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4
      + circuitWidth_464F40 * (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 +raceParticipantIngame[v0].dword_4A7DC8);
  if ( v42 < 0 || v42 >= circuitWidth_464F40 * circuitHeight_4A7CF8 )
    v87 = 15;
  else
    v87 = *((BYTE *)trxImaBpk_50A16C + v42) & 0xF;
  v43 = raceParticipantIngame[v0].dword_4A7DCC + raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4
      + circuitWidth_464F40 * (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 + raceParticipantIngame[v0].dword_4A7DD0);
  if ( v43 < 0 || v43 >= circuitWidth_464F40 * circuitHeight_4A7CF8 )
    v83 = 15;
  else
    v83 = *((BYTE *)trxImaBpk_50A16C + v43) & 0xF;
  v44 = raceParticipantIngame[v0].dword_4A7DD4 +  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4
      + circuitWidth_464F40 * (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 + raceParticipantIngame[v0].dword_4A7DD8);
  if ( v44 < 0 || v44 >= circuitWidth_464F40 * circuitHeight_4A7CF8 )
    v84 = 15;
  else
    v84 = *((BYTE *)trxImaBpk_50A16C + v44) & 0xF;
  v45 = raceParticipantIngame[v0].dword_4A7DDC +  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4
      + circuitWidth_464F40 * (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 + raceParticipantIngame[v0].dword_4A7DE0);
  if ( v45 < 0 || v45 >= circuitWidth_464F40 * circuitHeight_4A7CF8 )
    v85 = 15;
  else
    v85 = *((BYTE *)trxImaBpk_50A16C + v45) & 0xF;
  v46 = (unsigned __int64)( raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 + raceParticipantIngame[v0].dword_4A7DE4)
      + circuitWidth_464F40 * (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 + raceParticipantIngame[v0].dword_4A7DE8);
  if ( v46 < 0 || v46 >= circuitWidth_464F40 * circuitHeight_4A7CF8 )
    v81 = 15;
  else
    v81 = *((BYTE *)trxImaBpk_50A16C + v46) & 0xF;
  v47 = (unsigned __int64)( raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 + raceParticipantIngame[v0].dword_4A7DEC)
      + circuitWidth_464F40 * (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 + raceParticipantIngame[v0].dword_4A7DF0);
  /*if(debug==1) v47=1;
  if(debug==1) v85=15;
  if(debug==1) v84=15;
  if(debug==1) v83=15;
   if(debug==1) v81=15;*/
  if ( v47 < 0 || v47 >= circuitWidth_464F40 * circuitHeight_4A7CF8 )
    v82 = 15;
  else
    v82 = *((BYTE *)trxImaBpk_50A16C + v47) & 0xF;
  v48 = (unsigned __int64)( raceParticipantIngame[v0].carAngle_4A7DAC * 0.2666666666666667);
   v49 = 1600 * (v48 + 96* currentDriverSelectedIndex_503518);
  raceParticipantIngame[v0].directionRotation_4A7D0C = v48;
  raceParticipantIngame[v0].participantBpkOffser_4A7D10 = v49;
 
  if(raceParticipantIngame[currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C<-1000 || raceParticipantIngame[currentDriverSelectedIndex_503518].advanceYAxis_4A7E60 <-10000){
	  //fix porque esto no pude ser asi
	  v50=0;
	  }
  else {
	
	  v50 = sub_43BFE0(
          (int)((char *)participantCarBpk_5034FC + v49),
          (int)((char *)v41
		  +(unsigned __int64)raceParticipantIngame[currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C+
		  + v37 * (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 - 20.0 +raceParticipantIngame[currentDriverSelectedIndex_503518].advanceYAxis_4A7E60)
              +  (signed int)(unsigned __int64)raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4
              - 20));
  }

 v51 = currentDriverSelectedIndex_503518;
  v52 = currentDriverSelectedIndex_503518;
  raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14= v50;
  
  if ( v50 >= 4 )
  {
    raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14 = 0;
LABEL_134:
    v72 = v85;
    v71 = v87;
    goto LABEL_135;
  }
  v53 = v50;
  v54 = dword_4A7A40;
  dword_4A7E90[v52] = v53;
  v55 = dword_508D20 - 20;
  dword_4A7E74[v52] = v54 - 20;
  dword_4A7E78[v52] = v55;
  if ( raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7E94 > 3 )
  {
    raceParticipantIngame[ v52].carVelocity_4A7DB0 = 0;
    dword_4A7E6C[v52] = 1;
    dword_4A7E70[v52] = 0;
    v56 = 0;

	//esto huele a derrapes
	if ( raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14 < 4 )
    {
      do
      {
        if ( v56 >= 100 )
          break;
        v57 = dword_4A7E6C[ v51];
        ++v56;
        raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7E64 = (double)(rand() % (2 * v57 + 1) - v57);
        v58 = currentDriverSelectedIndex_503518;
        v59 = dword_4A7E6C[currentDriverSelectedIndex_503518];
        raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7E68 = (double)(rand() % (2 * v59 + 1) - v59);
        v60 = dword_4A7E70[v58] + 1;
        dword_4A7E70[v58 ] = v60;
        if ( !(v60 % 5) )
        {
          v61 = dword_4A7E6C[v58 ];
          if ( v61 < 30 )
            dword_4A7E6C[v58 ] = v61 + 1;
        }
        v62 = circuitWidth_464F40 - 20;
         raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 = raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7E64 +  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4;
        raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 + raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7E68;
        v63 = (double)v62;
        if ( v63 <  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 )
           raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 = v63;
        if (  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4< 20.0 )
           raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 = 20;
        v64 = (double)(circuitHeight_4A7CF8 - 20);
        if ( v64 < raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 )
          raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 = v64;
        if ( raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 < 20.0 )
          raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 = 20;
        v65 = circuitWidth_464F40 * (unsigned __int64)floor(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 - 20.0 +  raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceYAxis_4A7E60);
		v66 = (unsigned __int64)floor(*(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4);
        v67 = (unsigned __int64)floor( raceParticipantIngame[ currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C);
        v68 = sub_43BFE0(
                (int)((char *)participantCarBpk_5034FC + raceParticipantIngame[currentDriverSelectedIndex_503518].participantBpkOffser_4A7D10),
                (int)((char *)trxImaBpk_50A16C + v65 + v66 + v67 - 20));
        v51 = currentDriverSelectedIndex_503518;
        v69 = currentDriverSelectedIndex_503518;
        raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14 = v68;
        if ( v68 < 4 )
        {
           raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 - raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7E64;
          raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 - raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7E68;
        }
      }
      while ( raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14 < 4 );
    }
    v52 = v51;
    raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14 = 0;
  }
  v52 = v51;
  v70 =raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7E94 ;
  if ( v70 && v70 <= 3 )
  {
    raceParticipantIngame[v51].unk_4A7DFC =  raceParticipantIngame[ v51].advanceXAxis_4A7E5C * -1.0;
    raceParticipantIngame[v51].unk_4A7E00 =  raceParticipantIngame[ v51].advanceYAxis_4A7E60 * -1.0;

	//TODO FIX 
	/*	if( raceParticipantIngame[v51].unk_4A7E00<-100 || raceParticipantIngame[v51].unk_4A7E00>100 ){
		 raceParticipantIngame[v75].unk_4A7E00= raceParticipantIngame[v75].unk_4A7E00;
		 }
*/
    raceParticipantIngame[ v51].carVelocity_4A7DB0= 0;
    raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14 = 1;
  }
  if ( raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7E94 )
    goto LABEL_134;
  if ( (v83 < 4 || v84 < 4) && v89 >= 4 )
    raceParticipantIngame[v51].carAngle_4A7DAC = raceParticipantIngame[v51].carAngle_4A7DAC + 20.0;
  v71 = v87;
  v72 = v85;
  if ( (v87 < 4 || v85 < 4) && v89 >= 4 )
    raceParticipantIngame[v51].carAngle_4A7DAC = raceParticipantIngame[v51].carAngle_4A7DAC- 20.0;
  if ( raceParticipantIngame[v51].carAngle_4A7DAC < 0.0 )
    raceParticipantIngame[v51].carAngle_4A7DAC = raceParticipantIngame[v51].carAngle_4A7DAC + 360.0;
  if ( raceParticipantIngame[v51].carAngle_4A7DAC >= 360.0 )
    raceParticipantIngame[v51].carAngle_4A7DAC = raceParticipantIngame[v51].carAngle_4A7DAC - 360.0;
  raceParticipantIngame[ v51].carVelocity_4A7DB0 = raceParticipantIngame[ v51].carVelocity_4A7DB0 - 0.125 * raceParticipantIngame[ v51].carVelocity_4A7DB0;
  raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D14 = 1;
LABEL_135:
  v73 = v84;
  v74 = v83;
  if ( v71 == 4 || v83 == 4 || v84 == 4 || v72 == 4 || v81 == 4 || v82 == 4 )
    raceParticipantIngame[ v51].carVelocity_4A7DB0 = raceParticipantIngame[ v51].carVelocity_4A7DB0 -raceParticipantIngame[ v51].carVelocity_4A7DB0 * 0.028571429;
  if ( v83 == 5 || v84 == 5 )
  {
   (raceParticipantIngame[v51].unk_4A7E04) = (raceParticipantIngame[v51].unk_4A7E04) + 0.2;
    raceParticipantIngame[ v51].carVelocity_4A7DB0 = raceParticipantIngame[ v51].carVelocity_4A7DB0 - raceParticipantIngame[ v51].carVelocity_4A7DB0 * 0.033333335;
  }
  if ( v71 == 5 || v72 == 5 )
  {
    raceParticipantIngame[v51].unk_4A7E04 = (raceParticipantIngame[v51].unk_4A7E04) - 0.2;
    raceParticipantIngame[ v51].carVelocity_4A7DB0 = raceParticipantIngame[ v51].carVelocity_4A7DB0 - raceParticipantIngame[ v51].carVelocity_4A7DB0 * 0.033333335;
  }
  if ( v71 == 6 || v83 == 6 || v84 == 6 || v72 == 6 || v81 == 6 || v82 == 6 )
    raceParticipantIngame[ v51].carVelocity_4A7DB0 = raceParticipantIngame[ v51].carVelocity_4A7DB0 - raceParticipantIngame[ v51].carVelocity_4A7DB0 * 0.11111111;
  if ( v71 == 7 || v83 == 7 || v84 == 7 || v72 == 7 || v81 == 7 || v82 == 7 )
    raceParticipantIngame[ v51].carVelocity_4A7DB0 = raceParticipantIngame[ v51].carVelocity_4A7DB0 - raceParticipantIngame[ v51].carVelocity_4A7DB0* 0.050000001;
  if ( v71 == 10 || v84 == 10 )
    (raceParticipantIngame[v51].unk_4A7E04) = (raceParticipantIngame[v51].unk_4A7E04) - 0.15;
  if ( v83 == 10 || v72 == 10 )
    (raceParticipantIngame[v51].unk_4A7E04) = (raceParticipantIngame[v51].unk_4A7E04) + 0.15;
  if ( v71 == TERRAIN_TURBO || v83 == TERRAIN_TURBO || v84 == TERRAIN_TURBO || v72 == TERRAIN_TURBO || v81 == TERRAIN_TURBO || v82 == TERRAIN_TURBO )
    raceParticipantIngame[ v51].carVelocity_4A7DB0 = raceParticipantIngame[ v51].carVelocity_4A7DB0 * 0.013333334 + raceParticipantIngame[ v51].carVelocity_4A7DB0;
  if ( v71 == 12 || v84 == 12 )
    (raceParticipantIngame[v51].unk_4A7E04) = (raceParticipantIngame[v51].unk_4A7E04) - 0.05;
  if ( v83 == 12 || v72 == 12 )
    (raceParticipantIngame[v51].unk_4A7E04) = (raceParticipantIngame[v51].unk_4A7E04) + 0.05;
  if ( v71 == 13 || v83 == 13 || v84 == 13 || v72 == 13 || v81 == 13 || v82 == 13 )
  {
    v75 =  v51;
    v76 = (double)rand() * (raceParticipantIngame[ v51].carVelocity_4A7DB0 * 7.0) * 0.0000152587890625 + raceParticipantIngame[v51].carAngle_4A7DAC;
    raceParticipantIngame[v51].carAngle_4A7DAC = v76;
    v52 = currentDriverSelectedIndex_503518;
    v77 = v76 - (double)rand() * (raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0* 7.0) * 0.0000152587890625;
    raceParticipantIngame[v51].carAngle_4A7DAC= v77;
    if ( v77 < 0.0 )
      raceParticipantIngame[v51].carAngle_4A7DAC = raceParticipantIngame[v51].carAngle_4A7DAC + 360.0;
    if ( raceParticipantIngame[v51].carAngle_4A7DAC >= 360.0 )
      raceParticipantIngame[v51].carAngle_4A7DAC = raceParticipantIngame[v51].carAngle_4A7DAC- 360.0;
    v74 = v83;
    v73 = v84;
    raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 * 0.033333335;
  }
  if ( v71 == 14 || v74 == 14 || v73 == 14 || v72 == 14 || v81 == 14 || v82 == 14 )
    raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 * 0.025;
  v78 = circuitWidth_464F40 - 20;

 // aqui viene lo que se mueven en cada eje!
   raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4=  raceParticipantIngame[currentDriverSelectedIndex_503518].advanceXAxis_4A7E5C +  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4;
  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 =  raceParticipantIngame[currentDriverSelectedIndex_503518].advanceYAxis_4A7E60 + raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8;
  v79 = (double)v78;
  if ( v79 <  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 )
     raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 = v79;
  if (  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 < 20.0 )
	  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 = 20;
  v80 = (double)(circuitHeight_4A7CF8 - 20);
  if ( v80 < raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 )
    raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 = v80;
  if ( raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 < 20.0 )
	raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 = 20;
	
}

//----- (0040CD10) --------------------------------------------------------
int recalculateRaceCarWithOrientation()
{
  int v0; // ecx@1
  int v1; // eax@2
  int v2; // edx@2
  double v3; // st7@3
  int result; // eax@4
  unsigned int v5; // edi@8
  int v6; // esi@9
  signed int v7; // ebx@9
  unsigned __int64 v8; // rax@9
  int v9; // ecx@14
  signed int v10; // ebp@17
  signed int v11; // edx@17
  int v12; // eax@17
  int v13; // ebx@20
  int v14; // ecx@20
  int v15; // eax@20
  int v16; // ecx@21
  int v17; // edx@22
  double v18; // st7@30
  double v19; // st6@30
  double v20; // st6@30
  signed int v21; // ebx@30
  float v22; // ST3C_4@30
  double v23; // st5@30
  bool v24; // sf@30
  bool v25; // sf@37
  bool v26; // sf@44
  double v27; // st7@44
  bool v28; // sf@51
  double v29; // st7@63
  double v30; // st7@66
  int v31; // et1@68
  int v32; // et1@68
  double v34; // st7@68
  char v35; // c0@68
  double v36; // st7@69
  int v37; // et1@71
  int v38; // et1@71
  double v40; // st7@71
  char v41; // c0@71
  double v42; // st7@72
  double v44; // st7@75
  unsigned __int8 v45; // c0@75
  unsigned __int8 v46; // c2@75
  double v48; // st7@78
  unsigned __int8 v49; // c0@78
  unsigned __int8 v50; // c2@78
  double v52; // st7@81
  unsigned __int8 v53; // c0@81
  unsigned __int8 v54; // c2@81
  double v56; // st7@84
  unsigned __int8 v57; // c0@84
  unsigned __int8 v58; // c2@84
  double v59; // st7@87
  double v60; // st7@89
  int v61; // ebp@94
  int v62; // ebx@94
  int v63; // ecx@94
  int v64; // eax@94
  int v65; // eax@97
  int v66; // ebp@102
  int v67; // eax@102
  int v68; // ecx@102
  int v69; // ecx@105
  int v70; // esi@110
  unsigned __int64 v71; // rax@110
  signed int v72; // [sp+0h] [bp-3Ch]@19
  float v73; // [sp+0h] [bp-3Ch]@75
  signed int v74; // [sp+0h] [bp-3Ch]@92
  int v75; // [sp+4h] [bp-38h]@7
  int v76; // [sp+8h] [bp-34h]@19
  int v77; // [sp+Ch] [bp-30h]@14
  int v78; // [sp+10h] [bp-2Ch]@20
  int v79; // [sp+14h] [bp-28h]@20
  int v80; // [sp+18h] [bp-24h]@0
  int v81; // [sp+1Ch] [bp-20h]@0
  signed int v82; // [sp+20h] [bp-1Ch]@0
  int v83; // [sp+24h] [bp-18h]@14
  signed int v84; // [sp+28h] [bp-14h]@19
  signed int v85; // [sp+28h] [bp-14h]@30
  int v86; // [sp+2Ch] [bp-10h]@20
  float v87; // [sp+2Ch] [bp-10h]@87
  int v88; // [sp+2Ch] [bp-10h]@94
  int v89; // [sp+30h] [bp-Ch]@0
  int v90; // [sp+38h] [bp-4h]@7

  if(debug==1) v11=40;
  if(debug==1) v35=0;
  if(debug==1) v41=0;
  v0 = numberOfParticipants_508D24;
  if ( numberOfParticipants_508D24 > 0 )
  {
    //v1 = &unk_4A7E00;

	   //v1 = &unk_4A7E00;
	  v1 = 0;
    v2 = numberOfParticipants_508D24;
    do
    {
      v3 = raceParticipantIngame[v1].unk_4A7DFC;
      v1 ++;
      --v2;
	  raceParticipantIngame[v1-1].unk_4A7DFC = v3 * 0.8695652173913044;
	  raceParticipantIngame[v1-1].unk_4A7E00 = raceParticipantIngame[v1-1].unk_4A7E00* 0.8695652173913044; 
	  
	  raceParticipantIngame[v1-1].unk_4A7E04 = raceParticipantIngame[v1-1].unk_4A7E04* 0.8333333333333334; 
      
	  /*
	  v1 = &raceParticipantIngame[0].unk_4A7E00;
    v2 = numberOfParticipants_508D24;
    do
    {
      v3 = *((float *)v1 - 1);
      v1 = (char *)v1 + 864;
      --v2;
      *((float *)v1 - 217) = v3 * 0.8695652173913044;
      *((float *)v1 - 216) = *((float *)v1 - 216) * 0.8695652173913044;
      *((float *)v1 - 215) = *((float *)v1 - 215) * 0.8333333333333334;*/
    }
    while ( v2 );
  }
  result = v0 - 1;
  currentDriverSelectedIndex_503518 = 0;
  if ( v0 - 1 > 0 )
  {
    while ( 1 )
    {
      v90 = currentDriverSelectedIndex_503518 + 1;
      v75 = currentDriverSelectedIndex_503518 + 1;
      if ( currentDriverSelectedIndex_503518 + 1 < v0 )
        break;
LABEL_115:
      result = numberOfParticipants_508D24 - 1;
      currentDriverSelectedIndex_503518 = v90;
      if ( v90 >= numberOfParticipants_508D24 - 1 )
        return result;
      v0 = numberOfParticipants_508D24;
    }
    //v5 = 864 * currentDriverSelectedIndex_503518;
	v5 =  currentDriverSelectedIndex_503518;
    while ( 1 )
    {
      v6 =  v75;
      v7 = (unsigned __int64)( raceParticipantIngame[v75].absolutePositionX_4A7DB4 - raceParticipantIngame[v5].absolutePositionX_4A7DB4);
      v8 = (unsigned __int64)(raceParticipantIngame[v75].absolutePositionY_4A7DB8 - raceParticipantIngame[v5].absolutePositionY_4A7DB8);
      if ( v7 >= 39 || (signed int)v8 >= 39 || v7 <= -39 || (signed int)v8 <= -39 )
        goto LABEL_114;
      if ( v7 < 0 )
      {
        v9 = 0;
        v77 = v7 + 40;
        v83 = -v7;
      }
      else
      {
        v9 = (unsigned __int64)( raceParticipantIngame[v75].absolutePositionX_4A7DB4 - raceParticipantIngame[v5].absolutePositionX_4A7DB4);
        v77 = 40;
        v83 = 0;
      }
      if ( (v8 & 0x80000000) != 0 )
      {
        v10 = 0;
        HIDWORD(v8) = v8 + 40;
		v12 = -(signed int)v8;
      }
      else
      {
        v10 = (unsigned __int64)( raceParticipantIngame[v75].absolutePositionY_4A7DB8 -  raceParticipantIngame[v5].absolutePositionY_4A7DB8);
        v11 = 40;
        v12 = 0;
      }
      v84 = v11;
      v76 = v9;
      v72 = 0;
      if ( v10 >= v11 )
        goto LABEL_114;
      v13 = v77;
      v14 = v12 - 20;
      v78 = 40 * v12;
      v15 = 40 * v10;
      v79 = v14;
      v86 = 40 * v10;
      do
      {
        v16 = v76;
        if ( v76 < v13 )
        {
          v17 = v83 - v76;
          do
          {
            if ( *((BYTE *)participantCarBpk_5034FC + v15 + raceParticipantIngame[v5/4].participantBpkOffser_4A7D10 + v16) > 3u
              && *((BYTE *)participantCarBpk_5034FC + v17 + v78 + raceParticipantIngame[v6].participantBpkOffser_4A7D10 + v16) > 3u )
            {
              v89 = v16 - 20;
              v81 = v17 + v16 - 20;
              v72 = 1;
              v80 = v10 - 20;
              v82 = v79;
            }
            v13 = v77;
            ++v16;
          }
          while ( v16 < v77 );
          v15 = v86;
          v11 = v84;
        }
        v78 += 40;
        v15 += 40;
        ++v10;
        v86 = v15;
        ++v79;
      }
      while ( v10 < v11 );
      if ( v72 != 1 )
        goto LABEL_114;
      dword_4A7E74[v5] = v89;
      dword_4A7E78[v5] = v80;
      v18 =raceParticipantIngame[v75].absolutePositionX_4A7DB4 - raceParticipantIngame[v75].dword_4A7E50;
      dword_4A7E74[v6] = v81;
      v19 = raceParticipantIngame[v75].absolutePositionY_4A7DB8;
      dword_4A7E78[v6] = v82;
      v20 = v19 - raceParticipantIngame[v75].dword_4A7E54;
      v21 = (unsigned __int64)((double)v80 * v18 - (double)v89 * v20);
      v22 =  raceParticipantIngame[v5].absolutePositionX_4A7DB4 - raceParticipantIngame[v5].dword_4A7E50;
      v23 = raceParticipantIngame[v5].absolutePositionY_4A7DB8 - raceParticipantIngame[v5].dword_4A7E54;
      v24 = v89 < 0;
      v85 = (unsigned __int64)((double)v82 * v22 - (double)v81 * v23);
      (raceParticipantIngame[v5].unk_4A7DFC) = (v18 - v22) * 0.7 + (raceParticipantIngame[v5].unk_4A7DFC);
      (raceParticipantIngame[v5].unk_4A7E00) = (v20 - v23) * 0.7 + (raceParticipantIngame[v5].unk_4A7E00);
	   
      if ( v89 > 0 )
      {
        if (  raceParticipantIngame[ v5].advanceXAxis_4A7E5C > 0.0 )
          goto LABEL_35;
        v24 = v89 < 0;
      }
      if ( v24 &&  raceParticipantIngame[ v5].advanceXAxis_4A7E5C < 0.0 )
      {
LABEL_35:
        raceParticipantIngame[v5].dword_4A7D18 = 1;
        goto LABEL_37;
      }
      raceParticipantIngame[v5].dword_4A7D18 = 2;
LABEL_37:
      v25 = v80 < 0;
      if ( v80 > 0 )
      {
        if (  raceParticipantIngame[ v5].advanceYAxis_4A7E60 > 0.0 )
          goto LABEL_42;
        v25 = v80 < 0;
      }
      if ( v25 &&  raceParticipantIngame[ v5].advanceYAxis_4A7E60 < 0.0 )
      {
LABEL_42:
        raceParticipantIngame[v5].dword_4A7D1C = 1;
        goto LABEL_44;
      }
      raceParticipantIngame[v5].dword_4A7D1C = 2;
LABEL_44:
      v26 = v81 < 0;
      v27 = raceParticipantIngame[v5].absolutePositionY_4A7DB8
          - raceParticipantIngame[v5].dword_4A7E54
          - (raceParticipantIngame[v75].absolutePositionY_4A7DB8
           - raceParticipantIngame[v75].dword_4A7E54);
		   raceParticipantIngame[v75].unk_4A7DFC= (raceParticipantIngame[v5].absolutePositionX_4A7DB4
                                           - raceParticipantIngame[v5].dword_4A7E50
                                           - (raceParticipantIngame[v75].absolutePositionX_4A7DB4
                                            - raceParticipantIngame[v75].dword_4A7E50))
                                          * 0.7
                                          + raceParticipantIngame[v75].unk_4A7DFC;
      raceParticipantIngame[v75].unk_4A7E00 = v27 * 0.7 + raceParticipantIngame[v75].unk_4A7E00;
   
	  if ( v81 > 0 )
      {
        if (  raceParticipantIngame[ v75].advanceXAxis_4A7E5C > 0.0 )
          goto LABEL_49;
        v26 = v81 < 0;
      }
      if ( v26 &&  raceParticipantIngame[ v75].advanceXAxis_4A7E5C < 0.0 )
      {
LABEL_49:
       raceParticipantIngame[v75].dword_4A7D18 = 1;
        goto LABEL_51;
      }
      raceParticipantIngame[v75].dword_4A7D18 = 2;
LABEL_51:
      v28 = v82 < 0;
      if ( v82 > 0 )
      {
        if ( raceParticipantIngame[ v75].advanceYAxis_4A7E60 > 0.0 )
          goto LABEL_56;
        v28 = v82 < 0;
      }
      if ( !v28 || raceParticipantIngame[ v75].advanceYAxis_4A7E60 >= 0.0 )
      {
        raceParticipantIngame[v75].dword_4A7D1C = 2;
        goto LABEL_58;
      }
LABEL_56:
      raceParticipantIngame[v75].dword_4A7D1C = 1;
LABEL_58:
	  /*if(debug==1){
		raceParticipantIngame[v75].dword_4A7D1C =- 1;
		raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D1C = 1;
		raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D1C = 1;
	  }*/

	  //esto son calculos de choques entre v5 jugador actual y v6 
      if ( raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D18 == 1 && raceParticipantIngame[v75].dword_4A7D18 == 1 || raceParticipantIngame[currentDriverSelectedIndex_503518].dword_4A7D1C == 1 && raceParticipantIngame[v75].dword_4A7D1C == 1 )
		  //if ( dword_4A7D18[v5 / 4] == 1 && dword_4A7D18[v6] == 1 || dword_4A7D1C[v5 / 4] == 1 && dword_4A7D1C[v6] == 1 )
      {
        if ( raceParticipantIngame[v5].carAngle_4A7DAC <=raceParticipantIngame[v75].carAngle_4A7DAC )
          goto LABEL_118;
        v29 = raceParticipantIngame[v5].carAngle_4A7DAC - raceParticipantIngame[v75].carAngle_4A7DAC;
        if ( v29 < 0.0 )
          v29 = -v29;
        if ( v29 >= 100.0 )
        {
LABEL_118:
          (raceParticipantIngame[v5].unk_4A7E04) = (raceParticipantIngame[v5].unk_4A7E04) + 2.0;
          v30 = raceParticipantIngame[v75].unk_4A7E04 - 2.0;
        }
        else
        {
          (raceParticipantIngame[v5].unk_4A7E04) = (raceParticipantIngame[v5].unk_4A7E04) - 2.0;
          v30 = raceParticipantIngame[v75].unk_4A7E04 + 2.0;
        }
        raceParticipantIngame[v75].unk_4A7E04 = v30;
        v31 = raceParticipantIngame[v5].absolutePositionX_4A7DB4;
        v32 = raceParticipantIngame[v75].absolutePositionX_4A7DB4;
        v34 = raceParticipantIngame[v5].absolutePositionX_4A7DB4;
        if ( v35 )
        {
          raceParticipantIngame[v5].absolutePositionX_4A7DB4 = v34 - 0.6;
          v36 = raceParticipantIngame[v75].absolutePositionX_4A7DB4 + 0.6;
        }
        else
        {
          raceParticipantIngame[v5].absolutePositionX_4A7DB4 = v34 + 0.6;
          v36 = raceParticipantIngame[v75].absolutePositionX_4A7DB4 - 0.6;
        }
		
        raceParticipantIngame[v75].absolutePositionX_4A7DB4 = v36;
        v37 = raceParticipantIngame[v5].absolutePositionY_4A7DB8;
        v38 = raceParticipantIngame[v75].absolutePositionY_4A7DB8;
        v40 = raceParticipantIngame[v5].absolutePositionY_4A7DB8;
        if ( v41 )
        {
          raceParticipantIngame[v5].absolutePositionY_4A7DB8 = v40 - 0.6;
          v42 = raceParticipantIngame[v75].absolutePositionY_4A7DB8 + 0.6;
        }
        else
        {
          raceParticipantIngame[v5].absolutePositionY_4A7DB8 = v40 + 0.6;
          v42 = raceParticipantIngame[v75].absolutePositionY_4A7DB8 - 0.6;
        }
        raceParticipantIngame[v75].absolutePositionY_4A7DB8 = v42;
      }
      v73 = raceParticipantIngame[v5].carAngle_4A7DAC - raceParticipantIngame[v75].carAngle_4A7DAC;
      v44 = v73;
	  v46=0;//TODO FIX puesto por mi
	  v45=0;
	  v49=0;
	  v50=0;
	  v53=0;
	  v54=0;
	  v57=0;
	  v58=0;
     if ( v45 | v46 )
        v44 = -v44;
      if ( v44 < 315.0 )
      {
        v48 = v73;
        if ( v49 | v50 )
          v48 = -v48;
        if ( v48 > 45.0 )
        {
          v52 = v73;
          if ( v53 | v54 )
            v52 = -v52;
          if ( v52 < 135.0 )
            goto LABEL_119;
          v56 = v73;
          if ( v57 | v58 )
            v56 = -v56;
          if ( v56 > 225.0 )
          {
LABEL_119:
            v59 = (double)(v21 / 4);
            v87 = v59;
            if ( v59 > 3.0 )
              v87 = 3.0;
            v60 = (double)(v85 / 4);
            if ( v60 > 3.0 )
              v60 = 3.0;
           (raceParticipantIngame[v5].unk_4A7E04) = v87 + (raceParticipantIngame[v5].unk_4A7E04);
            raceParticipantIngame[v75].unk_4A7E04 = v60 + raceParticipantIngame[v75].unk_4A7E04;
          }
        }
      }
      v74 = 0;
      if ( raceParticipant2[currentDriverSelectedIndex_503518].spikes && !raceParticipantIngame[v5].hasFinishedTheRace_4A7E0C )
      {
        v61 = raceParticipantIngame[v75].absolutePositionX_4A7DB4;
		v62 = v61 - (unsigned __int64)((raceParticipantIngame[v5].dword_4A7DCC) + raceParticipantIngame[v5].absolutePositionX_4A7DB4);
        v88 = raceParticipantIngame[v75].absolutePositionY_4A7DB8;
        v63 = v88 - (unsigned __int64)((raceParticipantIngame[v5].dword_4A7DD0) + raceParticipantIngame[v5].absolutePositionY_4A7DB8);
        v64 = v62;
        if ( v62 < 0 )
          v64 = -v62;
        if ( v64 < 20 )
        {
          v65 = v88 - (unsigned __int64)((raceParticipantIngame[v5].dword_4A7DD0) + raceParticipantIngame[v5].absolutePositionY_4A7DB8);
          if ( v63 < 0 )
            v65 = -v63;
          if ( v65 < 20 && *((BYTE *)participantCarBpk_5034FC + 40 * v63 + raceParticipantIngame[v5].participantBpkOffser_4A7D10 + v62 + 820) > 3u )
            v74 = 1;
        }
        v66 = v61 - raceParticipantIngame[v5].dword_4A7DC4 + raceParticipantIngame[v5].absolutePositionX_4A7DB4;
        v67 = v88 - raceParticipantIngame[v5].dword_4A7DC8 + raceParticipantIngame[v5].absolutePositionY_4A7DB8;
        v68 = v66;
        if ( v66 < 0 )
          v68 = -v66;
        if ( v68 < 20 )
        {
          v69 = v88 - raceParticipantIngame[v5].dword_4A7DC8 + raceParticipantIngame[v5].absolutePositionY_4A7DB8;
          if ( v67 < 0 )
            v69 = -v67;
          if ( v69 < 20 && *((BYTE *)participantCarBpk_5034FC + 40 * v67 + raceParticipantIngame[v5].participantBpkOffser_4A7D10+ v66 + 820) > 3u )
            goto LABEL_120;
        }
        if ( v74 == 1 )
        {
LABEL_120:
          v70 = 37 * v75;
          v71 = (unsigned __int64)((raceParticipantIngame[v75].unk_4A7E00 * raceParticipantIngame[v75].unk_4A7E00
                                  + raceParticipantIngame[v75].unk_4A7DFC * raceParticipantIngame[v75].unk_4A7DFC)
                                 * (double)(3 * (1024 - raceParticipant2[v75].efectiveArmour_4A689C)));
          dword_50B2B0 = v71;
          if ( (signed int)v71 > 10000 )
          {
            LODWORD(v71) = 10000;
            dword_50B2B0 = 10000;
          }
		  v24 = raceParticipant2[v75].damageBar_4A6898 - (signed int)v71 < 0;
		  raceParticipant2[v75].damageBar_4A6898 -= v71;
          if ( v24 )
			  raceParticipant2[v75].damageBar_4A6898 = 0;
        }
      }
LABEL_114:
      ++v75;
      if ( v75 >= numberOfParticipants_508D24 )
        goto LABEL_115;
    }
  }
  return result;
}

//----- (0040D560) --------------------------------------------------------
int recalculateCircuitImageOffset_40D560()
{
  int v0; // ebx@1
  double v1; // st7@1
  long double v2; // st7@1
  unsigned __int64 v3; // rax@1
  int v4; // edi@1
  unsigned __int64 v5; // rax@1
  signed int v6; // ecx@3
  unsigned __int64 v7; // rax@6
  double v8; // st7@6
  int v9; // edi@6
  int result; // eax@6

  v0 = dword_4A7A3C;
  v1 = raceParticipantIngame[userRaceOrder_4A9EA8].carAngle_4A7DAC + 180.0;
  dword_4A6B00 = dword_4A7A3C;
  dword_501264 = dword_464F1C;
  v2 = v1 * 0.01745329251994444;
  v3 = (unsigned __int64)(sin(v2) * raceParticipantIngame[ userRaceOrder_4A9EA8].carVelocity_4A7DB0 * 16.0);
  v4 = v3;
  dword_4A7A3C = v3;
  v5 = (unsigned __int64)(cos(v2) * raceParticipantIngame[ userRaceOrder_4A9EA8].carVelocity_4A7DB0 * 10.66666666666667);
  dword_464F1C = v5;
  if ( v0 == v4 && dword_501264 == (_DWORD)v5 )
  {
    v6 = dword_4A8AA4;
    if ( dword_4A8AA4 <= 0 )
      goto LABEL_6;
  }
  else
  {
    v6 = 5;
  }
  dword_46ECE8 += (v4 - dword_46ECE8) / v6;
  dword_503504 += ((signed int)v5 - dword_503504) / v6;
  dword_4A8AA4 = v6 - 1;
LABEL_6:
  v7 = raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
  v8 = raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
  v9 = dword_46ECE8 + v7 - raceEffectiveHalfWidth_445014;
  circuitImageOffsetX_456ABC = dword_46ECE8 + v7 - raceEffectiveHalfWidth_445014;
  result = dword_503504 + (unsigned __int64)v8 - raceEffectiveHalfHeight_44501C;
  circuitImageOffsetY_456AC0 = dword_503504 + (unsigned __int64)v8 - raceEffectiveHalfHeight_44501C;
  if ( v9 > circuitWidth_464F40 - raceEffectiveWidth_445010 )
  {
    v9 = circuitWidth_464F40 - raceEffectiveWidth_445010;
    circuitImageOffsetX_456ABC = circuitWidth_464F40 - raceEffectiveWidth_445010;
  }
  if ( v9 < 0 )
    circuitImageOffsetX_456ABC = 0;
  if ( result > circuitHeight_4A7CF8 - raceEffectiveHeight_445018 )
  {
    result = circuitHeight_4A7CF8 - raceEffectiveHeight_445018;
    circuitImageOffsetY_456AC0 = circuitHeight_4A7CF8 - raceEffectiveHeight_445018;
  }
  if ( result < 0 )
    circuitImageOffsetY_456AC0 = 0;
  return result;
}

//----- (0040D6B0) --------------------------------------------------------
void recalculatePolygonsInScreeenPosition_40D6B0()
{
  int v0; // edx@2
  int v1; // esi@2
  int v2; // edi@2
  _UNKNOWN *v3; // eax@2
  int v4; // ebx@3
  bool v5; // zf@3
  int v6; // [sp+0h] [bp-4h]@2
  int id3dObject =0;
  dword_4AA928 = 0;
  if ( trxSCE1Number3DObjects_479D20 > 0 )
  {
    v0 = raceEffectiveHalfWidth_445014;
    v1 = raceEffectiveHalfHeight_44501C;
    v2 = circuitImageOffsetX_456ABC;
   // v3 = &unk_4B4D00;
    v6 = trxSCE1Number3DObjects_479D20;
    dword_4AA928 = trxSCE1Number3DObjects_479D20;
    do
    {
      v4 = circuitImageOffsetY_456AC0;
       sce2Texture[id3dObject].dword_4B4D04 =  sce2Texture[id3dObject].unk_4B4CFC- raceEffectiveHalfWidth_445014 - circuitImageOffsetX_456ABC;
    //   sce2Texture[id3dObject].dword_4B4D04 = *((_DWORD *)v3 - 1) - raceEffectiveHalfWidth_445014 - circuitImageOffsetX_456ABC;
    
	   sce2Texture[id3dObject].dword_4B4D08 = sce2Texture[id3dObject].unk_4B4D00 - raceEffectiveHalfHeight_44501C - circuitImageOffsetY_456AC0;
	  v5 = strcmp(raceFilePrefix_45EA50, "TR0");
	  strcpy(raceFilePrefix_45EA50, "TR0");
      sce2Texture[id3dObject].dword_4B4F64 = 0;//+153
     // if ( !v5 )
     // {
		if ( sce2Texture[id3dObject].dword_4B4D04 << 8 > (raceEffectiveHalfWidth_445014 << 8) + sce2Texture[id3dObject].dword_4B46AC[1])// *((_DWORD *)v3 - 404) )
          sce2Texture[id3dObject].dword_4B4F64 = 1;
        if ( sce2Texture[id3dObject].dword_4B4D04 << 8 < sce2Texture[id3dObject].dword_4B46AC[0] - (raceEffectiveHalfWidth_445014 << 8) )//*((_DWORD *)v3 - 405
          sce2Texture[id3dObject].dword_4B4F64 = 1;
        if ( sce2Texture[id3dObject].dword_4B4D08 << 8 > (raceEffectiveHalfHeight_44501C << 8) + sce2Texture[id3dObject].dword_4B46AC[3])//*((_DWORD *)v3 - 402) )
          sce2Texture[id3dObject].dword_4B4F64 = 1;
        if ( sce2Texture[id3dObject].dword_4B4D08 << 8 < sce2Texture[id3dObject].dword_4B46AC[2]- (raceEffectiveHalfHeight_44501C << 8) )//*((_DWORD *)v3 - 403)
          sce2Texture[id3dObject].dword_4B4F64 = 1;
		if( sce2Texture[id3dObject].dword_4B4F64 == 0){
			sce2Texture[id3dObject].dword_4B4F64 = 0;
		}
		//}
      //v3 = (char *)v3 + 3152;
	  id3dObject++;
      --v6;
    }
    while ( v6 );
  }
}

//----- (0040D7B0) --------------------------------------------------------
int drawShadows_40D7B0()
{
  int result; // eax@1
  int v1; // edx@1
  int v2; // ecx@4 sha7
  int v3; // eax@4 sha6
  int v4; // edx@4  sha4
  int v5; // esi@4 es sha3 -offx
  int v6; // edi@4 sha3 +sha7 -offx
  int v7; // ebx@4 sha3 -off y
  int v8; // ebp@4 sha4 -offy
  int v9; // ecx@4 sha4 +sha7 -off y
  int counter;
  result = trxSHA2Bpk_501A80;
  v1 = 0;
  dword_481BE8 = 0;
  if ( trxSHA2Bpk_501A80 > 0 )
  {
	  counter =0;
    while ( 1 )//esto era un while 1
    {
      v2 = trxSHA7Bpk_4A8D40[v1];
      v3 = trxSHA6Bpk_4AA520[v1];
      v4 = trxSHA8Bpk_46E8E0[v1];
      //v2 *= 4;

	  //TODO FIX 
	  if(v2>200) v2=0;
      v5 = trxSHA3Bpk_479280[v3] - circuitImageOffsetX_456ABC;
      v6 = trxSHA3Bpk_479280[v2] - circuitImageOffsetX_456ABC;
      v7 = trxSHA3Bpk_479280[v4] - circuitImageOffsetX_456ABC;
      v8 = trxSHA4Bpk_4A9FE0[v3] - circuitImageOffsetY_456AC0;
      v9 = trxSHA4Bpk_4A9FE0[v2] - circuitImageOffsetY_456AC0;
      dword_46ECE4 = trxSHA4Bpk_4A9FE0[v4] - circuitImageOffsetY_456AC0;
      dword_50EF20 = v5;
      dword_50351C = v6;
      dword_4A8A80 = v7;

      dword_4A6AD0 = v8;
      dword_4A7A4C = v9;
      if ( (abs(v5 - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014
         || abs(v6 - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014
         || abs(v7 - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014)
        && (abs(v8 - raceEffectiveHalfHeight_44501C) < raceEffectiveHalfHeight_44501C
         || abs(v9 - raceEffectiveHalfHeight_44501C) < raceEffectiveHalfHeight_44501C
         || abs(dword_46ECE4 - raceEffectiveHalfHeight_44501C) < raceEffectiveHalfHeight_44501C) )
		iluminateTriangle_43D530(v5 + leftMenuInRaceWidth_456AA0, v8, leftMenuInRaceWidth_456AA0 + v6, v9, leftMenuInRaceWidth_456AA0 + v7, dword_46ECE4, (int)&trxVARJOTab_466F00);
      
	  result = dword_481BE8++ + 1;
      if ( dword_481BE8 >= trxSHA2Bpk_501A80 )
        break;
      v1 = dword_481BE8;
    }
  }
  return result;
}

//----- (0040D920) --------------------------------------------------------
int drawCarInRace_40D920()
{
  double v0; // st7@1
  int v1; // ebx@1
  int v2; // esi@1
  int v3; // edi@3
  double v4; // st7@5
  double v5; // st7@8
  double v6; // st6@8
  int v7; // edi@10
  double v8; // st7@12
  long double v9; // st7@17
  long double v10; // ST6C_8@17
  long double v11; // st7@17
  long double v12; // ST6C_8@17
  long double v13; // st7@17
  long double v14; // ST6C_8@17
  int v15; // ebp@18
  int v16; // esi@20
  double v17; // st7@20
  int v18; // edi@20
  int v19; // eax@20
  int v20; // ecx@20
  long double v21; // st7@26
  long double v22; // ST6C_8@26
  long double v23; // st7@26
  long double v24; // ST6C_8@26
  long double v25; // st7@26
  long double v26; // ST6C_8@26
  int v27; // ST50_4@29
  int v28; // ST4C_4@29
  int v29; // ST48_4@29
  int v30; // esi@30
  int v31; // eax@31
  bool v32; // sf@31
  int result; // eax@34
  int v34; // esi@34
  int v35; // eax@36
  int v36; // edx@36
  int v37; // ecx@38
  int v38; // eax@41
  int v39; // edx@41
  int v40; // ecx@43
  int v41; // esi@46
  int v42; // eax@47
  int v43; // eax@49
  float v44; // [sp+Ch] [bp-10h]@1
  float v45; // [sp+Ch] [bp-10h]@10
  float v46; // [sp+10h] [bp-Ch]@3
  float v47; // [sp+10h] [bp-Ch]@8

  v0 = (double)dword_46ECE8;
  v1 = userRaceOrder_4A9EA8;
  v44 = (double)raceEffectiveHalfWidth_445014;
  v2 = userRaceOrder_4A9EA8;
  currentDriverSelectedIndex_503518 = userRaceOrder_4A9EA8;
  if ( v0 + raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4 < v44 )
    raceParticipantIngame[v2].inScreenPositionX_4A7D04 = raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
  v3 = raceEffectiveHalfWidth_445014;
  v46 = (double)(circuitWidth_464F40 - raceEffectiveHalfWidth_445014);
  if ( v0 + raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4 > v46 )
    raceParticipantIngame[v2].inScreenPositionX_4A7D04 = (unsigned __int64)(raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4 - (double)(circuitWidth_464F40 - raceEffectiveWidth_445010));
  v4 = v0 + raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
  if ( v4 >= v44 && v4 <= v46 )
    raceParticipantIngame[v2].inScreenPositionX_4A7D04 = v3 - dword_46ECE8;
  v5 = (double)dword_503504;
  v6 = (double)raceEffectiveHalfHeight_44501C;
  raceParticipantIngame[v2].inScreenPositionX_4A7D04 += leftMenuInRaceWidth_456AA0;
  v47 = v6;
  if ( v5 +  raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 < v47 )
    raceParticipantIngame[v2].inScreenPositionY_4A7D08 =  raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
  v7 = raceEffectiveHalfHeight_44501C;
  v45 = (double)(circuitHeight_4A7CF8 - raceEffectiveHalfHeight_44501C);
  if ( v5 +  raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 > v45 )
    raceParticipantIngame[v2].inScreenPositionY_4A7D08 = (unsigned __int64)( raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 - (double)(circuitHeight_4A7CF8 - raceEffectiveHeight_445018));
  v8 = v5 +  raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
  if ( v8 >= v47 && v8 <= v45 )
    raceParticipantIngame[v2].inScreenPositionY_4A7D08 = v7 - dword_503504;
  if ( raceParticipant2[v1].damageBar_4A6898 > 0 && !raceParticipantIngame[v2].hasFinishedTheRace_4A7E0C )
  {

	  
    v9 = ((raceParticipantIngame[v2].carAngle_4A7DAC) - 10.0 + 180.0) * 0.01745329251994444;
    v10 = ((raceParticipantIngame[v2].carAngle_4A7DAC) + 190.0) * 0.01745329251994444;
//	    v9 = (*(float *)(v2 * 4 + carAngle_4A7DAC) - 10.0 + 180.0) * 0.01745329251994444;
  //  v10 = (*(float *)(v2 * 4 + carAngle_4A7DAC) + 190.0) * 0.01745329251994444;
	//faros coche triangulo central
	iluminateTriangle_43D530(
      raceParticipantIngame[v2].inScreenPositionX_4A7D04,
      raceParticipantIngame[v2].inScreenPositionY_4A7D08,
      raceParticipantIngame[v2].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v10) * -40.0),
      raceParticipantIngame[v2].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v10) * -33.33332),
      raceParticipantIngame[v2].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v9) * -40.0),
      raceParticipantIngame[v2].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v9) * -33.33332),
      (int)&trxLITTab_4A9EE0);
    v11 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC + 190.0) * 0.01745329251994444;
    v12 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC + 198.0) * 0.01745329251994444;
   //faros coche triangulo izquierdo
	 iluminateTriangle_43D530(
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04,
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08,
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v12) * -36.0),
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v12) * -29.999988),
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v11) * -40.0),
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v11) * -33.33332),
      (int)&trxLITTab_4A9EE0);
    v13 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC - 18.0 + 180.0) * 0.01745329251994444;
    v14 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC - 10.0 + 180.0) * 0.01745329251994444;
    
	//faros coche triangulo derecho
	iluminateTriangle_43D530(
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04,
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08,
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v14) * -40.0),
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v14) * -33.33332),
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v13) * -36.0),
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v13) * -29.999988),
      (int)&trxLITTab_4A9EE0);
    v1 = userRaceOrder_4A9EA8;
  }
  v15 = 0;
  for ( currentDriverSelectedIndex_503518 = 0; v15 < numberOfParticipants_508D24; currentDriverSelectedIndex_503518 = v15 )
  {
    if ( v15 != v1 )
    {
      v16 =  v15;
      v17 = (double)circuitImageOffsetY_456AC0;
      raceParticipantIngame[v16].inScreenPositionX_4A7D04 = (unsigned __int64)(raceParticipantIngame[v15].absolutePositionX_4A7DB4
                                           - (double)circuitImageOffsetX_456ABC
                                           + (double)leftMenuInRaceWidth_456AA0);
      v18 = raceParticipantIngame[v15].absolutePositionY_4A7DB8 - v17;
      v19 = leftMenuInRaceWidth_456AA0;
      raceParticipantIngame[v16].inScreenPositionY_4A7D08= v18;
      v20 = raceParticipantIngame[v15].inScreenPositionX_4A7D04;
      if ( v20 > v19 - 40 )
      {
		  if ( v20 < 360 && v18 > -40 && v18 < raceEffectiveHeight_445018 + 40 && raceParticipant2[v15].damageBar_4A6898 > 0 && !raceParticipantIngame[v16].hasFinishedTheRace_4A7E0C)
        {
          v21 = (raceParticipantIngame[v15].carAngle_4A7DAC- 10.0 + 180.0) * 0.01745329251994444;
          v22 = (raceParticipantIngame[v15].carAngle_4A7DAC + 190.0) * 0.01745329251994444;
          iluminateTriangle_43D530(
            raceParticipantIngame[v16].inScreenPositionX_4A7D04,
            v18,
            raceParticipantIngame[v16].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v22) * -40.0),
            v18 - (unsigned __int64)(cos(v22) * -33.33332),
            raceParticipantIngame[v16].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v21) * -40.0),
            v18 - (unsigned __int64)(cos(v21) * -33.33332),
            (int)&trxLITTab_4A9EE0);
          v23 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC + 190.0) * 0.01745329251994444;
          v24 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC + 198.0) * 0.01745329251994444;
          iluminateTriangle_43D530(
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04,
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08,
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v24) * -36.0),
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v24) * -29.999988),
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04 - (unsigned __int64)(sin(v23) * -40.0),
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v23) * -33.33332),
            (int)&trxLITTab_4A9EE0);
          v25 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC - 18.0 + 180.0) * 0.01745329251994444;
          v26 = (raceParticipantIngame[currentDriverSelectedIndex_503518].carAngle_4A7DAC - 10.0 + 180.0) * 0.01745329251994444;
          iluminateTriangle_43D530(
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04,
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08,
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04- (unsigned __int64)(sin(v26) * -40.0),
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08- (unsigned __int64)(cos(v26) * -33.33332),
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04- (unsigned __int64)(sin(v25) * -36.0),
            raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08 - (unsigned __int64)(cos(v25) * -29.999988),
            (int)&trxLITTab_4A9EE0);
          v15 = currentDriverSelectedIndex_503518;
        }
        v1 = userRaceOrder_4A9EA8;
      }
    }
    ++v15;
  }
v27 = raceParticipantIngame[v1].participantBpkOffser_4A7D10;
  v28 =raceParticipantIngame[v1].inScreenPositionY_4A7D08;
  v29 = raceParticipantIngame[v1].inScreenPositionX_4A7D04;

  currentDriverSelectedIndex_503518 = v1;
  //user car
 drawCarSprite_43AEC0(v29, v28, v27); 
  if ( raceParticipant2[ currentDriverSelectedIndex_503518].damageBar_4A6898 <= 0 )
  {
    drawCarFire_43AFC0(
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionX_4A7D04,
      raceParticipantIngame[currentDriverSelectedIndex_503518].inScreenPositionY_4A7D08,
	  raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC << 8);
    v30 =  currentDriverSelectedIndex_503518;
    if ( refreshScreenWithDelay() >= (unsigned int)(lastUserTicks_4A7EE0[v30] + 3) )
    {
      v31 =raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC + 1;
      v32 = raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC - 6 < 0;
      raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC = v31;
      if ( !((unsigned __int8)(v32 ^ __OFSUB__(v31, 7)) | (v31 == 7)) )
        raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC = 0;
      lastUserTicks_4A7EE0[216 * currentDriverSelectedIndex_503518] = refreshScreenWithDelay();
    }
  }
  result = numberOfParticipants_508D24;
  v34 = 0;
  for ( currentDriverSelectedIndex_503518 = 0; v34 < numberOfParticipants_508D24; currentDriverSelectedIndex_503518 = v34 )
  {
    if ( v34 != userRaceOrder_4A9EA8 )
    {
      v35 =  v34;
      v36 = raceParticipantIngame[v34].inScreenPositionX_4A7D04;
      if ( v36 > leftMenuInRaceWidth_456AA0 - 20 && v36 < 340 )
      {
        v37 = raceParticipantIngame[v35].inScreenPositionY_4A7D08;
        if ( v37 > -20 && v37 < raceEffectiveHeight_445018 + 20 )
        {
          drawCarSprite_43AEC0(v36, v37,raceParticipantIngame[v35].participantBpkOffser_4A7D10);
          v34 = currentDriverSelectedIndex_503518;
        }
      }
      v38 =  v34;
      v39 = raceParticipantIngame[v34].inScreenPositionX_4A7D04;
      if ( v39 > leftMenuInRaceWidth_456AA0 - 8 && v39 < 328 )
      {
        v40 = raceParticipantIngame[v38].inScreenPositionY_4A7D08;
        if ( v40 > -8 && v40 < raceEffectiveHeight_445018 + 8 && raceParticipant2[ v34].damageBar_4A6898 <= 0 )
		//if ( v40 > -8 && v40 < raceEffectiveHeight_445018 + 8 && dword_4A6898[37 * v34] <= 0 )
        {
          drawCarFire_43AFC0(v39, v40, raceParticipantIngame[v34].spriteBurnOffset_4A7EDC << 8);
          v41 = 216 * currentDriverSelectedIndex_503518;
          if ( refreshScreenWithDelay() < (unsigned int)(lastUserTicks_4A7EE0[v41] + 3) )
          {
            v34 = currentDriverSelectedIndex_503518;
          }
          else
          {
            v42 = raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC + 1;
            v32 = raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC - 6 < 0;
            raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC= v42;
            if ( !((unsigned __int8)(v32 ^ __OFSUB__(v42, 7)) | (v42 == 7)) )
              raceParticipantIngame[currentDriverSelectedIndex_503518].spriteBurnOffset_4A7EDC = 0;
            v43 = refreshScreenWithDelay();
            v34 = currentDriverSelectedIndex_503518;
            lastUserTicks_4A7EE0[ currentDriverSelectedIndex_503518] = v43;
          }
        }
      }
    }
    result = numberOfParticipants_508D24;
    ++v34;
  }
  //return result;
 return 0;
}

//----- (0040E180) --------------------------------------------------------
int shotAction_40E180()
{
  int v0; // ebp@1
  int v1; // ebx@1
  int result; // eax@1
  int v3; // esi@2
  int v4; // eax@7
  int v5; // ecx@7
  long double v6; // st7@7
  long double v7; // ST54_8@7
  double v8; // st7@7
  long double v9; // st6@7
  int v10; // ST44_4@7
  double v12; // st6@7
  char v13; // c0@7
  unsigned __int64 v14; // rax@9
  long double v15; // st6@9
  int v16; // ebx@9
  long double v17; // st5@9
  double v18; // st6@9
  double v19; // st7@11
  int v20; // ecx@11
  unsigned __int64 v21; // rax@11
  double v22; // st7@11
  int v23; // ebx@13
  unsigned __int64 v24; // rax@13
  signed int v25; // eax@13
  long double v26; // st7@16
  long double v27; // st6@16
  signed int v28; // edi@16
  long double v29; // st7@18
  signed int v30; // esi@18
  int v31; // eax@20
  int v32; // ebp@20
  signed int v33; // edi@20
  int v34; // ebx@22
  int v35; // edi@22
  int v36; // eax@22
  int v37; // esi@23
  int v38; // esi@25
  int v39; // eax@25
  int v40; // ecx@25
  int v41; // ecx@28
  char *v42; // ecx@31
  bool v43; // cf@31
  bool v44; // zf@31
  bool v45; // sf@40
  unsigned __int8 v46; // of@40
  int v47; // eax@41
  int v48; // edx@48
  int v49; // edx@49
  int v50; // edi@49
  int v51; // edi@51
  int v52; // eax@51
  int v53; // edi@57
  int v54; // edi@59
  int v55; // ST54_4@59
  unsigned __int64 v56; // rax@59
  signed int v57; // eax@59
  int v58; // eax@61
  int v59; // ecx@64
  int *v60; // eax@64
  int v61; // ebp@66
  int v62; // ecx@66
  int v63; // edx@66
  unsigned __int8 v64; // [sp-20h] [bp-5Ch]@12
  char v65; // [sp-1Ch] [bp-58h]@12
  int v66; // [sp-14h] [bp-50h]@12
  int v67; // [sp-14h] [bp-50h]@58
  int v68; // [sp+8h] [bp-34h]@9
  int v69; // [sp+Ch] [bp-30h]@22
  signed int v70; // [sp+10h] [bp-2Ch]@11
  int v71; // [sp+14h] [bp-28h]@23
  int v72; // [sp+18h] [bp-24h]@23
  char *v73; // [sp+18h] [bp-24h]@49
  signed int v74; // [sp+1Ch] [bp-20h]@20
  int v75; // [sp+20h] [bp-1Ch]@22
  int v76; // [sp+24h] [bp-18h]@22
  int v77; // [sp+28h] [bp-14h]@20
  long double v78; // [sp+2Ch] [bp-10h]@7
  int v79; // [sp+2Ch] [bp-10h]@20
  int v80; // [sp+34h] [bp-8h]@41
  int activeWeapon;
  v0 = currentDriverSelectedIndex_503518;
  v1 = 37 * currentDriverSelectedIndex_503518;
  result = raceParticipant2[ currentDriverSelectedIndex_503518].damageBar_4A6898;
  if ( result <= 0 )
    return result;
  v3 = currentDriverSelectedIndex_503518;
  result = raceParticipantIngame[currentDriverSelectedIndex_503518].hasFinishedTheRace_4A7E0C;
  if ( result )
    return result;
  if ( raceFrame_481E14 <= 430 )
    return result;
  result = dword_4A7A20 + 216 * currentDriverSelectedIndex_503518;
  if ( !(raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] & IN_RACE_GUN))//disparo )
    return result;
  result = raceParticipant2[currentDriverSelectedIndex_503518].useWeapons;
  if ( !result )
    return result;
  result = raceParticipant2[currentDriverSelectedIndex_503518].weaponsBar_4A68B0 ;
  if ( result <= 0 )
    return result;

  v4 = 37 * currentDriverSelectedIndex_503518 + raceParticipant2[currentDriverSelectedIndex_503518].activeWeapon_4A68E0;
  drawFlames_4A7EB8[v3] = 1;

  v5 = 37 * v0 + raceParticipant2[currentDriverSelectedIndex_503518].activeWeapon_4A68E0;
  activeWeapon = raceParticipant2[currentDriverSelectedIndex_503518].activeWeapon_4A68E0;
  v6 = ((double)raceParticipant2[currentDriverSelectedIndex_503518].weaponPosition_4A68E4[activeWeapon] + raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444;
  v78 = v6;
  v7 = sin(v6);
  v8 = (double)  raceParticipant2[currentDriverSelectedIndex_503518].weaponStrength_4A68F4[activeWeapon] ;
  v9 = (double)raceParticipant2[currentDriverSelectedIndex_503518].weaponStrength_4A68F4[activeWeapon]* v7;
  v10 = (unsigned __int64)(sin(((double)raceParticipant2[currentDriverSelectedIndex_503518].weaponPosition_4A68E4[activeWeapon]  + raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444) * v8);
  v12 = v7 * v8;
  if(debug==1) v13=0;
  if ( !v13 )
    v12 = v12 + 1.0;
  v14 = (unsigned __int64)v12;
  v15 = cos(v78);
  v16 = 37 * v0 + raceParticipant2[currentDriverSelectedIndex_503518].activeWeapon_4A68E0;
  activeWeapon = raceParticipant2[currentDriverSelectedIndex_503518].activeWeapon_4A68E0;
  v68 = v14;
  v17 = (double)raceParticipant2[currentDriverSelectedIndex_503518].weaponStrength_4A68F4[activeWeapon] * v15 * 0.833333;
  v18 = v15 * v8 * 0.833333;
  if ( v17
     - (double)(signed int)(unsigned __int64)(cos(((double)raceParticipant2[currentDriverSelectedIndex_503518].weaponPosition_4A68E4[activeWeapon] + raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444)
                                            * v8
                                            * 0.833333) >= 0.5 )
    v18 = v18 + 1.0;
  v19 = raceParticipantIngame[v0].absolutePositionX_4A7DB4 - 4.0;
  v70 = (unsigned __int64)v18;
  v20 = raceParticipantIngame[v3].inScreenPositionY_4A7D08; //v0 es v3
  dword_4A7A48 = raceParticipantIngame[v3].inScreenPositionX_4A7D04 + v14 - 4;
  dword_4B3144 = v20 + v70 - 4;
  v21 = (unsigned __int64)(v19 + (double)(signed int)v14);
  v22 =raceParticipantIngame[v0].absolutePositionY_4A7DB8 - 4.0;
  dword_50350C = v21;
  dword_4A6AD8 = (unsigned __int64)(v22 + (double)v70);
  if ( v0 == userRaceOrder_4A9EA8 )
  {
    v66 = 36864;
    v65 = rand() % 2 + 19; //sound_shot2 y sound_shot3
    v64 = 9;
LABEL_15:
    loadMenuSoundEffect(v64, v65, 0, v66, 135168);
    v0 = currentDriverSelectedIndex_503518;
    goto LABEL_16;
  }
  
  //calculo de distancia entre coches
  v23 = raceParticipantIngame[v0].absolutePositionX_4A7DB4 - raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
  v24 = (unsigned __int64)(raceParticipantIngame[v0].absolutePositionY_4A7DB8 - raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8);
  v25 = 36864 - 75 * (unsigned __int64)sqrt((double)(v23 * v23 + (signed int)v24 * (signed int)v24));
  if ( v25 > 4096 )
  {
    v66 = v25;
    v65 = rand() % 2 + 19;  //sound_shot2 y sound_shot3
    v64 = 10;
    goto LABEL_15;
  }
LABEL_16:
  v26 = (raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444;
  v27 = sin(v26) * 256.0;
  v28 = (unsigned __int64)v27;
  if ( v27 - (double)v28 >= 0.5 )
    v28 = (unsigned __int64)(v27 + 1.0);
  v29 = cos(v26) * 213.333248;
  v30 = (unsigned __int64)v29;
  if ( v29 - (double)v30 >= 0.5 )
    v30 = (unsigned __int64)(v29 + 1.0);
  v77 = v28 + rand() % 6 - 3;
  v31 = rand();
  v32 = currentDriverSelectedIndex_503518;
  v33 = 0;
  v74 = 0;
  v79 = v30 + v31 % 6 - 3;
  while ( 1 )
  {
    v34 = (v77 * v33 + 128) >> 8;
    v35 = (v79 * v33 + 128) >> 8;
    v36 = 0;
    v75 = v34;
    v69 = v35;
    v76 = 0;
    if ( numberOfParticipants_508D24 > 0 )
    {
		v37 = (int)raceParticipant2[0].damageBar_4A6898;
		v72 = (int)raceParticipant2[0].damageBar_4A6898;
      //v71 = (int)absolutePositionY_4A7DB8;//parece da\F1o de otro
		v71=0;
      while ( v36 == v32 )
      {
LABEL_40:
        v36 = v76 + 1;
		v71+=1;//es el id en el array de racegameparticipant
        //v71 += 864;
        v37 += 148;
        v46 = __OFSUB__(v76 + 1, numberOfParticipants_508D24);
        v45 = v76++ + 1 - numberOfParticipants_508D24 < 0;
        v72 = v37;
        if ( !(v45 ^ v46) )
          goto LABEL_41;
      }
	  v38 = (unsigned __int64)(raceParticipantIngame[v71].absolutePositionX_4A7DB4) - raceParticipantIngame[v32].absolutePositionX_4A7DB4 - v34 - v68;
	  v39 = (unsigned __int64)raceParticipantIngame[v71].absolutePositionY_4A7DB8 - raceParticipantIngame[v32].absolutePositionY_4A7DB8 - v69 - v70;
      v40 = v38;
      if ( v38 < 0 )
        v40 = -v38;
      if ( v40 >= 20 )
        goto LABEL_69;
	  v41 = (unsigned __int64)raceParticipantIngame[v71].absolutePositionY_4A7DB8 - raceParticipantIngame[v32].absolutePositionY_4A7DB8 - v69 - v70;
      if ( v39 < 0 )
        v41 = -v39;
      if ( v41 >= 20 )
      {
LABEL_69:
        v37 = v72;
      }
      else
      {
        v42 = (char *)participantCarBpk_5034FC + 40 * v39 + raceParticipantIngame[v71].participantBpkOffser_4A7D10;//*(_DWORD *)(v71 - 168);
        v43 = (unsigned __int8)v42[v38 + 820] < 3u;
        v44 = v42[v38 + 820] == 3;
        v37 = v72;
        if ( !v43 && !v44 )
        {
          v74 = 130;
		  if ( ! raceParticipantIngame[v71].hasFinishedTheRace_4A7E0C)//  *(_DWORD *)(v71 + 84) )
			  //esto hace el calculo del damagebar restando 1024 -armour del objetivo * multiplicador en funcion del tipo de coche
			  raceParticipant2[v71].damageBar_4A6898 = raceParticipant2[v71].damageBar_4A6898 - (1024 -raceParticipant2[v71].efectiveArmour_4A689C)* arrayDamageMultiplier[raceParticipant2[v32].carType];
           /* *(_DWORD *)v72 = (unsigned __int64)((double)*(signed int *)v72
                                              - (double)(1024 - *(_DWORD *)(v72 + 4))
                                              * *(float *)&dword_4A6AE0[raceParticipant2[v32].carType]);
          if ( *(_DWORD *)v72 < 0 )
            *(_DWORD *)v72 = 0;*/
		  if(raceParticipant2[v71].damageBar_4A6898 <0)
			  raceParticipant2[v71].damageBar_4A6898=0;
          v34 = v75;
          dword_4A7CF0 = v75 + dword_50350C;
          dword_4AA3E4 = v69 + dword_4A6AD8;

		  activeWeapon = raceParticipant2[v32].activeWeapon_4A68E0;
          dword_4A7EAC[216 * v32] = 3 * raceParticipant2[currentDriverSelectedIndex_503518].weaponFlameType[activeWeapon] + 1;
          goto LABEL_39;
        }
      }
      v34 = v75;
LABEL_39:
      v35 = v69;
      goto LABEL_40;
    }
LABEL_41:
    v80 = v68 + v34 + raceParticipantIngame[v32].absolutePositionX_4A7DB4;
    v47 = v70 + v35 + raceParticipantIngame[v32].absolutePositionY_4A7DB8;
    if ( v47 >= 0
      && v47 < circuitHeight_4A7CF8
      && v80 >= 0
      && v80 < circuitWidth_464F40
      && (*((BYTE *)trxImaBpk_50A16C + v47 * circuitWidth_464F40 + v80) & 0xFu) < 4 )
    {
      dword_4A7CF0 = v34 + dword_50350C;
      dword_4AA3E4 = v35 + dword_4A6AD8;
      v74 = 130;
	  activeWeapon = raceParticipant2[v32].activeWeapon_4A68E0;
	  
      dword_4A7EAC[216 * v32] = 3 * raceParticipant2[currentDriverSelectedIndex_503518].weaponFlameType[activeWeapon] + 1;
    }
    if ( !isMultiplayerGame )
    {
      v48 = rand() % 5;
      v32 = currentDriverSelectedIndex_503518;
      if ( v48 < 20 )
      {
       /* v49 = 32 * v48;
        v50 = (int)((char *)&unk_479AB8 + v49);
        v73 = (char *)&unk_479AB8 + v49;*/
		  v49 =  v48;
		  v50 = (int)(pedestrian_479AA4[v49].isDied + v49);
          v73 = pedestrian_479AA4[v49].isDied + v49;
		 while ( 1 )
        {
          if ( pedestrian_479AA4[v49].isDied )
            goto LABEL_62;
          v51 = v34 + raceParticipantIngame[v32].absolutePositionX_4A7DB4 - pedestrian_479AA4[v49].positionX + v68 - 8;
          v52 = v69 + raceParticipantIngame[v32].absolutePositionY_4A7DB8 - pedestrian_479AA4[v49].positionY + v70 - 8;
          if ( v51 < 0 )
            v51 = -v51;
          if ( v51 >= 3 )
            goto LABEL_62;
          if ( v52 < 0 )
            v52 = -v52;
          if ( v52 >= 3 )
            goto LABEL_62;
          v53 = userRaceOrder_4A9EA8;
          v44 = v32 == userRaceOrder_4A9EA8;
          pedestrian_479AA4[v49].isDied = 1;
		  pedestrian_479AA4[v49].byte5 =0;
		  /**(_DWORD *)v73 = 1;
          *((_DWORD *)v73 - 1) = 0;*/
          if ( v44 )
            break;
          v54 = 864 * v53;
          v55 = raceParticipantIngame[v32].absolutePositionX_4A7DB4 - raceParticipantIngame[v53].absolutePositionX_4A7DB4;
          v56 = raceParticipantIngame[v32].absolutePositionY_4A7DB8 - raceParticipantIngame[v53].absolutePositionY_4A7DB8;
          v57 = 0x10000 - 75 * (unsigned __int64)sqrt((double)(v55 * v55 + (signed int)v56 * (signed int)v56));
          if ( v57 > 4096 )
          {
            v67 = v57;
            goto LABEL_61;
          }
LABEL_62:
         /* pedestrian_479AA4[v49].isDied = (int)(v73 + 160);
          v73 += 160;
          if ( (signed int)v73 >= (signed int)&unk_479D38 )
            goto LABEL_63;*/
		  pedestrian_479AA4[v49].byte7 = pedestrian_479AA4[v49+5].byte7;
          v49+=5;
          if ( (signed int)v49 >= 20 )
            goto LABEL_63;
        }
        v67 = 36864;
LABEL_61:
        v58 = rand();
		//SOUND_SPEDE1,SOUND_SPEDE2,SOUND_SPEDE3  matar a un espectador
        loadMenuSoundEffect(3u, v58 % 3 + 7, 0, v67, 327680);
        v32 = currentDriverSelectedIndex_503518;
        goto LABEL_62;
      }
    }
LABEL_63:
    v46 = __OFSUB__(v74 + 5, 130);
    v45 = v74 - 125 < 0;
    v74 += 5;
    if ( !(v45 ^ v46) )
      break;
    v33 = v74;
  }
  v59 = raceParticipant2[v32].weaponsBar_4A68B0;
  v60 = &raceParticipant2[v32].weaponsBar_4A68B0;
 
  *v60 = v59 - 260;
  
  if ( v59 - 260 < 0 )
    *v60 = 0;
  v61 = v32;
  v62 = dword_4AA3E4;
  v63 = dword_50350C;
  dword_4A7EBC[v61] = dword_4A7CF0;
  result = dword_4A6AD8;
  dword_4A7EC0[v61] = v62;
  dword_4A7ED4[v61] = v63;
  dword_4A7ED8[v61] = result;
  return result;
}

//----- (0040E960) --------------------------------------------------------
int drawGunFlames_40E960()
{
  int v0; // ecx@1
  int v1; // eax@1
  int v2; // edi@2
  int v3; // ebp@2
  int v4; // ebp@6
  signed int v5; // esi@7
  char v6; // al@8
  char v7; // al@10
  char v8; // al@12
  int v9; // edx@14
  char v10; // al@14
  int v11; // ecx@19
  int v12; // ebx@19
  int result; // eax@19
  int v14; // [sp+0h] [bp-4h]@6
  int activeWeapon;

  //flame1bpk  flame6bpk dependiendo del weaponflametype

  v0 = currentDriverSelectedIndex_503518;
  v1 = 216 * currentDriverSelectedIndex_503518;
  if ( drawFlames_4A7EB8[216 * currentDriverSelectedIndex_503518] )
  {
	  //posicion y a pintar!!
    v2 = leftMenuInRaceWidth_456AA0 + dword_4A7ED4[v1] - circuitImageOffsetX_456ABC; //x position
    v3 = dword_4A7ED8[v1] - circuitImageOffsetY_456AC0; //y position
    if ( v2 >= 0 && v2 + 8 < 320 && v3 >= 0 && v3 + 8 < 200 )
    {
      v14 = 0;
      v4 = v3 << 9;
      do
      {
		  //esto son las llamas! 8*4 vueltas esta desenrrollado el bucle
        v5 = 0;
        do
        {
		  activeWeapon = raceParticipant2[currentDriverSelectedIndex_503518].activeWeapon_4A68E0;
		  
          v6 = *((BYTE *)*(&flamesBpk[raceParticipant2[currentDriverSelectedIndex_503518].weaponFlameType[activeWeapon]])
               + 8 * (v14 + 8 * (raceParticipantIngame[v0].directionRotation_4A7D0C / 2))
               + v5);
          if ( v6 )
          {
            *(BYTE *)(v5 + dword_464F14 + v4 + v2 + 96) = v6;
            v0 = currentDriverSelectedIndex_503518;
          }
          v7 = *((BYTE *)*(&flamesBpk[raceParticipant2[currentDriverSelectedIndex_503518].weaponFlameType[activeWeapon]])
               + 8 * (v14 + 8 * (raceParticipantIngame[v0].directionRotation_4A7D0C / 2))
               + v5
               + 1);
          if ( v7 )
          {
            *(BYTE *)(v5 + dword_464F14 + v4 + v2 + 97) = v7;
            v0 = currentDriverSelectedIndex_503518;
          }
          v8 = *((BYTE *)*(&flamesBpk[raceParticipant2[currentDriverSelectedIndex_503518].weaponFlameType[activeWeapon]])
               + 8 * (v14 + 8 * (raceParticipantIngame[v0].directionRotation_4A7D0C / 2))
               + v5
               + 2);
          if ( v8 )
          {
            *(BYTE *)(v5 + dword_464F14 + v4 + v2 + 98) = v8;
            v0 = currentDriverSelectedIndex_503518;
          }
          v9 = v14;
          v10 = *((BYTE *)*(&flamesBpk[raceParticipant2[currentDriverSelectedIndex_503518].weaponFlameType[activeWeapon]])
                + 8 * (v14 + 8 * (raceParticipantIngame[v0].directionRotation_4A7D0C/ 2))
                + v5
                + 3);
          if ( v10 )
          {
            *(BYTE *)(v5 + v4 + dword_464F14 + v2 + 99) = v10;
            v0 = currentDriverSelectedIndex_503518;
          }
          v5 += 4;
        }
        while ( v5 < 8 );
        v4 += 512;
        ++v14;
      }
      while ( v9 + 1 < 8 );
    }
    drawFlames_4A7EB8[216 * v0] = 0;
  }
  v11 = 37 * v0;
  v12 = raceParticipant2[v0].activeWeapon_4A68E0 + 1;
  raceParticipant2[v0].activeWeapon_4A68E0 = v12;
  result = v12;
  if ( v12 > raceParticipant2[v0].weaponsNumber_4A68DC - 1 )
	  raceParticipant2[v0].activeWeapon_4A68E0 = 0;
  return result;
}

//----- (0040EBC0) --------------------------------------------------------
int drawShots_40EBC0()
{
  int result; // eax@1
  int v1; // edx@1
  int v2; // ecx@2
  int v3; // eax@2
  signed int v4; // esi@6
  int v5; // edi@6
  int v6; // eax@6
  char v7; // dl@7
  char v8; // dl@9
  char v9; // dl@11
  char v10; // dl@13
  char v11; // dl@15
  char v12; // dl@17
  char v13; // dl@19
  char v14; // dl@21
  int v15; // ebp@26
  int v16; // edi@26
  int v17; // ecx@26
  int v18; // edx@26
  int v19; // ecx@26
  int v20; // edx@26
  int v21; // edi@30
  signed int v22; // esi@30
  int v23; // edx@30
  char v24; // al@31
  char v25; // al@33
  char v26; // al@35
  char v27; // al@37
  char v28; // al@39
  char v29; // al@41
  char v30; // al@43
  char v31; // al@45
  int v32; // ebp@50
  int v33; // edi@50
  int v34; // ecx@50
  int v35; // edx@50
  int v36; // ecx@50
  int v37; // edx@50
  int v38; // edi@54
  signed int v39; // esi@54
  int v40; // edx@54
  char v41; // al@55
  char v42; // al@57
  char v43; // al@59
  char v44; // al@61
  char v45; // al@63
  char v46; // al@65
  char v47; // al@67
  char v48; // al@69

  result = 216 * currentDriverSelectedIndex_503518;
  v1 = dword_4A7EB4[216 * currentDriverSelectedIndex_503518];
  //if(debug==1)v1=1;
  if ( v1 > 0 )
  {
    v2 = leftMenuInRaceWidth_456AA0 + dword_4A7ECC[result] - circuitImageOffsetX_456ABC;
    v3 = dword_4A7ED0[result] - circuitImageOffsetY_456AC0;

	//v2 = leftMenuInRaceWidth_456AA0 +  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 - circuitImageOffsetX_456ABC;
	//v3 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8-circuitImageOffsetY_456AC0;
	
    if ( v2 >= 0 && v2 + 8 < 320 && v3 >= 0 && v3 + 8 < 200 )
    {
      v4 = 0;
      v5 = (v1 << 6) - 64;
      v6 = v3 << 9;
      do
      {
        v7 = *((BYTE *)shotsBpk + v4 + v5);
        if ( v7 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 96) = v7;
        v8 = *((BYTE *)shotsBpk + v4 + v5 + 1);
        if ( v8 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 97) = v8;
        v9 = *((BYTE *)shotsBpk + v4 + v5 + 2);
        if ( v9 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 98) = v9;
        v10 = *((BYTE *)shotsBpk + v4 + v5 + 3);
        if ( v10 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 99) = v10;
        v11 = *((BYTE *)shotsBpk + v4 + v5 + 4);
        if ( v11 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 100) = v11;
        v12 = *((BYTE *)shotsBpk + v4 + v5 + 5);
        if ( v12 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 101) = v12;
        v13 = *((BYTE *)shotsBpk + v4 + v5 + 6);
        if ( v13 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 102) = v13;
        v14 = *((BYTE *)shotsBpk + v4 + v5 + 7);
        if ( v14 )
          *(BYTE *)(v2 + v6 + dword_464F14 + 103) = v14;
        v4 += 8;
        v6 += 512;
      }
      while ( v4 < 64 );
    }
    result = 216 * currentDriverSelectedIndex_503518;
    dword_4A7EB4[216 * currentDriverSelectedIndex_503518] = 0;
  }
  if ( dword_4A7EB0[result] > 0 )
  {
    v15 = leftMenuInRaceWidth_456AA0;
    v16 = circuitImageOffsetY_456AC0;
    v17 = dword_4A7EC4[result] - circuitImageOffsetX_456ABC;
    v18 = dword_4A7EC8[result];
    dword_4A7ECC[result] = dword_4A7EC4[result];
    v19 = v15 + v17;
    v20 = v18 - v16;
    dword_4A7ED0[result] = dword_4A7EC8[result];
    if ( v19 >= 0 && v19 + 8 < 320 && v20 >= 0 && v20 + 8 < 200 )
    {
      v21 = (dword_4A7EB0[result] << 6) - 64;
      v22 = 0;
      v23 = v20 << 9;
      do
      {
        v24 = *((BYTE *)shotsBpk + v22 + v21);
        if ( v24 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 96) = v24;
        v25 = *((BYTE *)shotsBpk + v22 + v21 + 1);
        if ( v25 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 97) = v25;
        v26 = *((BYTE *)shotsBpk + v22 + v21 + 2);
        if ( v26 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 98) = v26;
        v27 = *((BYTE *)shotsBpk + v22 + v21 + 3);
        if ( v27 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 99) = v27;
        v28 = *((BYTE *)shotsBpk + v22 + v21 + 4);
        if ( v28 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 100) = v28;
        v29 = *((BYTE *)shotsBpk + v22 + v21 + 5);
        if ( v29 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 101) = v29;
        v30 = *((BYTE *)shotsBpk + v22 + v21 + 6);
        if ( v30 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 102) = v30;
        v31 = *((BYTE *)shotsBpk + v22 + v21 + 7);
        if ( v31 )
          *(BYTE *)(v19 + v23 + dword_464F14 + 103) = v31;
        v22 += 8;
        v23 += 512;
      }
      while ( v22 < 64 );
    }
    result = 216 * currentDriverSelectedIndex_503518;
    dword_4A7EB4[result] = dword_4A7EB0[216 * currentDriverSelectedIndex_503518] + 1;
    dword_4A7EB0[result] = 0;
  }
  if ( dword_4A7EAC[result] > 0 )
  {
    v32 = leftMenuInRaceWidth_456AA0;
    v33 = circuitImageOffsetY_456AC0;
    v34 = dword_4A7EBC[result] - circuitImageOffsetX_456ABC;
    v35 = dword_4A7EC0[result];
    dword_4A7EC4[result] = dword_4A7EBC[result];
    v36 = v32 + v34;
    v37 = v35 - v33;
    dword_4A7EC8[result] = dword_4A7EC0[result];
    if ( v36 >= 0 && v36 + 8 < 320 && v37 >= 0 && v37 + 8 < 200 )
    {
      v38 = (dword_4A7EAC[result] << 6) - 64;
      v39 = 0;
      v40 = v37 << 9;
      do
      {
        v41 = *((BYTE *)shotsBpk + v39 + v38);
        if ( v41 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 96) = v41;
        v42 = *((BYTE *)shotsBpk + v39 + v38 + 1);
        if ( v42 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 97) = v42;
        v43 = *((BYTE *)shotsBpk + v39 + v38 + 2);
        if ( v43 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 98) = v43;
        v44 = *((BYTE *)shotsBpk + v39 + v38 + 3);
        if ( v44 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 99) = v44;
        v45 = *((BYTE *)shotsBpk + v39 + v38 + 4);
        if ( v45 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 100) = v45;
        v46 = *((BYTE *)shotsBpk + v39 + v38 + 5);
        if ( v46 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 101) = v46;
        v47 = *((BYTE *)shotsBpk + v39 + v38 + 6);
        if ( v47 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 102) = v47;
        v48 = *((BYTE *)shotsBpk + v39 + v38 + 7);
        if ( v48 )
          *(BYTE *)(v36 + v40 + dword_464F14 + 103) = v48;
        v39 += 8;
        v40 += 512;
      }
      while ( v39 < 64 );
    }
    result = 216 * currentDriverSelectedIndex_503518;
    dword_4A7EB0[result] = dword_4A7EAC[216 * currentDriverSelectedIndex_503518] + 1;
    dword_4A7EAC[result] = 0;
  }
  return result * 4;
}

//----- (0040F070) --------------------------------------------------------
int  showSmoke_40F070(int result)
{
  signed int v1; // esi@1
  signed int v2; // edi@1
  int v3; // ecx@2
  int v4; // edx@2
  int v5; // eax@3
  int v6; // ecx@3
  signed int v7; // esi@14
  int v8; // ecx@14
  char v9; // dl@15
  char v10; // dl@17
  char v11; // dl@19
  char v12; // dl@21
  char v13; // dl@23
  char v14; // dl@25
  char v15; // dl@27
  char v16; // dl@29
  int v17; // edx@35
  int v18; // eax@36
  int v19; // ecx@36
  signed int v20; // esi@47
  int v21; // ecx@47
  char v22; // dl@48
  char v23; // dl@50
  char v24; // dl@52
  char v25; // dl@54
  char v26; // dl@56
  char v27; // dl@58
  char v28; // dl@60
  char v29; // dl@62
  int v30; // eax@66
  int v31; // edx@66
  int v32; // edx@66
  signed int v33; // [sp+Ch] [bp-4h]@1

  v1 = 0;
  v33 = 0;
  v2 = 0;
  do
  {
    v3 = v1 + 216 * currentDriverSelectedIndex_503518;
    v4 = dword_4A7EE4[v3];
	if(debug) v4=10;
    if ( v4 <= 0 )
      goto LABEL_35;
    v5 = leftMenuInRaceWidth_456AA0 + dword_4A7F5C[v3] - circuitImageOffsetX_456ABC;
    v6 = dword_4A7FD4[v3] - circuitImageOffsetY_456AC0;
	if(debug) v6=100; 
	if(debug) v5=100;
    if ( v5 >= 4 && v5 + 4 < 320 && v6 >= 4 && v6 + 4 < 200 )
    {
      if ( v4 > 4 || (v2 = 0, v4 > 4) )
      {
        if ( v4 > 8 )
          goto LABEL_12;
        v2 = 64;
      }
      if ( v4 <= 8 )
      {
LABEL_14:
        v7 = 0;
        v8 = v6 << 9;
        do
        {
          v9 = *((BYTE *)smokeBpk + v7 + v2);
          if ( v9 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1956) = v9;
          v10 = *((BYTE *)smokeBpk + v7 + v2 + 1);
          if ( v10 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1955) = v10;
          v11 = *((BYTE *)smokeBpk + v7 + v2 + 2);
          if ( v11 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1954) = v11;
          v12 = *((BYTE *)smokeBpk + v7 + v2 + 3);
          if ( v12 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1953) = v12;
          v13 = *((BYTE *)smokeBpk + v7 + v2 + 4);
          if ( v13 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1952) = v13;
          v14 = *((BYTE *)smokeBpk + v7 + v2 + 5);
          if ( v14 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1951) = v14;
          v15 = *((BYTE *)smokeBpk + v7 + v2 + 6);
          if ( v15 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1950) = v15;
          v16 = *((BYTE *)smokeBpk + v7 + v2 + 7);
          if ( v16 )
            *(BYTE *)(v5 + v8 + dword_464F14 - 1949) = v16;
          v7 += 8;
          v8 += 512;
        }
        while ( v7 < 64 );
        v1 = v33;
        goto LABEL_33;
      }
LABEL_12:
      if ( v4 <= 12 )
        v2 = 128;
      goto LABEL_14;
    }
LABEL_33:
    v3 = v1 + 216 * currentDriverSelectedIndex_503518;
    result = dword_4A9EA4 + dword_4A7EE4[v3];
    dword_4A7EE4[v3] = result;
    if ( result >= 13 )
      dword_4A7EE4[v3] = 0;
LABEL_35:
    v17 = dword_4A7F20[v3];
    if ( v17 <= 0 )
      goto LABEL_68;
    v18 = leftMenuInRaceWidth_456AA0 + dword_4A7F98[v3] - circuitImageOffsetX_456ABC;
    v19 = dword_4A8010[v3] - circuitImageOffsetY_456AC0;
    if ( v18 >= 4 && v18 + 4 < 320 && v19 >= 4 && v19 + 4 < 200 )
    {
      if ( v17 <= 4 && (v2 = 0, v17 <= 4) )
      {
LABEL_44:
        if ( v17 > 8 )
          goto LABEL_45;
      }
      else
      {
        if ( v17 <= 8 )
        {
          v2 = 64;
          goto LABEL_44;
        }
LABEL_45:
        if ( v17 <= 12 )
          v2 = 128;
      }
      v20 = 0;
      v21 = v19 << 9;
      do
      {
        v22 = *((BYTE *)smokeBpk + v20 + v2);
        if ( v22 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1956) = v22;
        v23 = *((BYTE *)smokeBpk + v20 + v2 + 1);
        if ( v23 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1955) = v23;
        v24 = *((BYTE *)smokeBpk + v20 + v2 + 2);
        if ( v24 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1954) = v24;
        v25 = *((BYTE *)smokeBpk + v20 + v2 + 3);
        if ( v25 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1953) = v25;
        v26 = *((BYTE *)smokeBpk + v20 + v2 + 4);
        if ( v26 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1952) = v26;
        v27 = *((BYTE *)smokeBpk + v20 + v2 + 5);
        if ( v27 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1951) = v27;
        v28 = *((BYTE *)smokeBpk + v20 + v2 + 6);
        if ( v28 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1950) = v28;
        v29 = *((BYTE *)smokeBpk + v20 + v2 + 7);
        if ( v29 )
          *(BYTE *)(v18 + v21 + dword_464F14 - 1949) = v29;
        v20 += 8;
        v21 += 512;
      }
      while ( v20 < 64 );
      v1 = v33;
    }
    v30 = v1 + 216 * currentDriverSelectedIndex_503518;
    v31 = dword_4A7F20[v30];
    result = 4 * v30 + dword_4A7F20;
    v32 = dword_4A9EA4 + v31;
    *(_DWORD *)result = v32;
    if ( v32 >= 13 )
      *(_DWORD *)result = 0;
LABEL_68:
    ++v1;
    v33 = v1;
  }
  while ( v1 < 15 );
  return result;
}

//----- (0040F450) --------------------------------------------------------
int drawRocket_40F450()
{
  int v0; // ebx@1
  unsigned __int64 v1; // rax@1
  int v2; // ebp@4
  long double v3; // st7@4
  double v4; // st6@4
  long double v5; // st5@4
  signed int v6; // esi@4
  long double v7; // st7@6
  int v8; // edi@9
  int v9; // esi@9
  signed int v10; // eax@13
  int v11; // ebp@13
  int v12; // esi@13
  int v13; // edx@13
  signed int v14; // eax@14
  char v15; // cl@15
  char v16; // cl@17
  char v17; // cl@19
  char v18; // cl@21
  bool v19; // zf@26
  bool v20; // sf@26
  unsigned __int8 v21; // of@26
  signed int v23; // [sp+0h] [bp-4h]@13

  v0 = currentDriverSelectedIndex_503518;
  LODWORD(v1) = currentDriverSelectedIndex_503518;
  /*if(debug==1){
	  usingRocket_4A68D8[currentDriverSelectedIndex_503518]=1;
	  raceParticipant2[v0].rocket=1;

 }*/
  if ( usingRocket_4A68D8[currentDriverSelectedIndex_503518] == 1
	  && raceParticipant2[v0].turboBar_4A68B4 > 0
    && raceParticipant2[v0].rocket )
  {
    v2 =  currentDriverSelectedIndex_503518;
    v3 = (raceParticipantIngame[v0].carAngle_4A7DAC + 180.0) * 0.01745329251994444;
    v4 = raceParticipant2[currentDriverSelectedIndex_503518].carSize_4A6890 * -2.3;
    v5 = sin(v3) * v4;
    v6 = (unsigned __int64)v5;
    if ( v5 - (double)v6 >= 0.5 )
      v6 = (unsigned __int64)(v5 + 1.0);
    v7 = cos(v3) * v4 * 0.833333;
    if ( v7 - (double)(signed int)(unsigned __int64)v7 < 0.5 )
      LODWORD(v1) = (unsigned __int64)v7;
    else
      v1 = (unsigned __int64)(v7 + 1.0);
    v8 = raceParticipantIngame[v2].inScreenPositionX_4A7D04 + v6 - 8;
    v9 = raceParticipantIngame[v2].inScreenPositionY_4A7D08 + v1 - 8;
    if ( v8 >= 0 )
    {
      LODWORD(v1) = v8 + 16;
      if ( v8 + 16 < 320 && v9 >= 0 && v9 + 16 < 200 )
      {
        v10 = raceParticipantIngame[v2].directionRotation_4A7D0C;
        v11 = dword_456AFC;//parece que es el frame
        v12 = v9 << 9;
        v13 = v10 / 4 << 8;//12288 es el tama\F1o de la images y tiene 24 sprites 12288/24=512 bytes por sprite
        v23 = 16;
		//if(debug==1) v13=0;
        do
        {
          v14 = 0;
          do
          {

			  //v11 es para poner rocker2bpks
            v15 = *((BYTE *)rocket1Bpk + v11 + v13 + v14);
            if ( v15 )
              *(BYTE *)(v14 + v12 + dword_464F14 + v8 + 96) = v15;
            v16 = *((BYTE *)&rocket1Bpk + v11 + v13 + v14 + 1);
            if ( v16 )
              *(BYTE *)(v14 + v12 + dword_464F14 + v8 + 97) = v16;
            v17 = *((BYTE *)rocket1Bpk + v11 + v13 + v14 + 2);
            if ( v17 )
              *(BYTE *)(v14 + v12 + dword_464F14 + v8 + 98) = v17;
            v18 = *((BYTE *)rocket1Bpk + v11 + v13 + v14 + 3);
            if ( v18 )
              *(BYTE *)(v14 + v12 + dword_464F14 + v8 + 99) = v18;
            v14 += 4;
          }
          while ( v14 < 16 );
          v13 += 16;
          v12 += 512;
          --v23;
        }
        while ( v23 );
        LODWORD(v1) = refreshScreenWithDelay();
        v0 = currentDriverSelectedIndex_503518;
        if ( (unsigned int)v1 >= lastUserTicks_4A7EE0[216 * currentDriverSelectedIndex_503518] + 4 )
        {
          v21 = __OFSUB__(dword_456AFC + 1, 1);
          v19 = dword_456AFC == 0;
          v20 = dword_456AFC++ < 0;
          if ( !((unsigned __int8)(v20 ^ v21) | v19) )
            dword_456AFC = 0;
          LODWORD(v1) = refreshScreenWithDelay();
          v0 = currentDriverSelectedIndex_503518;
          lastUserTicks_4A7EE0[currentDriverSelectedIndex_503518] = v1;
        }
      }
    }
  }
  usingRocket_4A68D8[v0] = 0;
  return v1;
}

//----- (0040F6A0) --------------------------------------------------------
int drawMine_40F6A0()
{
  int v0; // ecx@1
  unsigned int v1; // ebp@1
  int v2; // eax@1
  int v3; // eax@3
  int v4; // ecx@5
  long double v5; // st7@10
  double v6; // st6@10
  long double v7; // st5@10
  int v8; // esi@13
  long double v9; // st7@13
  int v10; // ebx@16
  signed int v11; // edi@16
  int v12; // edx@17
  int v13; // eax@18
  int v14; // eax@21
  int v15; // ebx@29
  unsigned __int64 v16; // rax@29
  int v17; // eax@29
  int v18; // ecx@32
  int v19; // eax@32
  int v20; // eax@32
  signed int v21; // ecx@32
  char v22; // dl@33
  char v23; // dl@35
  char v24; // dl@37
  char v25; // dl@39
  char v26; // dl@41
  char v27; // dl@43
  char v28; // dl@45
  char v29; // dl@47
  int result; // eax@51
  int v31; // esi@52
  int v32; // ebp@53
  int v33; // eax@53
  int v34; // ecx@53
  int v35; // ecx@56
  int v36; // edx@61
  signed int v37; // edi@61
  signed int v38; // eax@62
  char v39; // cl@63
  char v40; // cl@65
  char v41; // cl@67
  char v42; // cl@69
  int v43; // edx@73
  int v44; // ecx@73
  char *v45; // edi@77
  int *v46; // edi@77
  int *v47; // edi@77
  int v48; // edi@77
  int v49; // eax@77
  int v50; // ebp@77
  bool v51; // zf@77
  int v52; // ebp@79
  int v53; // ebx@79
  unsigned __int64 v54; // rax@79
  signed int v55; // eax@79
  int v56; // [sp-Ch] [bp-24h]@78
  unsigned int v57; // [sp+10h] [bp-8h]@11
  unsigned int v58; // [sp+10h] [bp-8h]@14
  int v59; // [sp+10h] [bp-8h]@17
  int v60; // [sp+14h] [bp-4h]@16
  int v61; // [sp+14h] [bp-4h]@51

  v0 = currentDriverSelectedIndex_503518;
  v1 = 864 * currentDriverSelectedIndex_503518;
  v2 = ticksToWaitDropMine_4A7EA8[ currentDriverSelectedIndex_503518];
  if ( v2 > 0 )
    ticksToWaitDropMine_4A7EA8[v1 / 4] = v2 - 1;
  v3 = v0;
  if ( raceParticipant2[ v0].damageBar_4A6898 > 0 && !raceParticipantIngame[v0].hasFinishedTheRace_4A7E0C )
  {
    v4 = raceParticipantIngame[ v0].dword_4A7D20[dword_4A7A20];
   if(debug==1){
	   //raceParticipant2[currentDriverSelectedIndex_503518].mines=8;
	  //v4=0x40;
	 }
	if ( v4 & IN_RACE_MINE  )
    {
      if ( raceParticipant2[currentDriverSelectedIndex_503518].mines > 0 && raceFrame_481E14 > 430 && !ticksToWaitDropMine_4A7EA8[v0] && !(v4 & IN_RACE_BRAKE) )
      {
        ticksToWaitDropMine_4A7EA8[v1 / 4] = 50;//50 ticks para volver a lanzar una mina
        v5 = raceParticipantIngame[v0].carAngle_4A7DAC * 0.01745329251994444;
        v6 = raceParticipant2[v3].carSize_4A6890;
		
        v7 = sin(v5) * v6 * 2.3;
        v57 = v7 - (double)(signed int)(unsigned __int64)v7 < 0.5 ? (unsigned int)(unsigned __int64)v7 : (unsigned int)(unsigned __int64)(v7 + 1.0);
        v8 = (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 - 4.0 + (double)(signed int)v57);
        v9 = cos(v5) * v6 * 1.9166659;
        v58 = v9 - (double)(signed int)(unsigned __int64)v9 < 0.5 ? (unsigned int)(unsigned __int64)v9 : (unsigned int)(unsigned __int64)(v9 + 1.0);
        v10 = (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 - 4.0 + (double)(signed int)v58);
        v11 = 0;
        v60 = (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 - 4.0 + (double)(signed int)v58);
        if ( deployedMines_464F60 <= 0 )
          goto LABEL_85;
		v12=0;
        //v12 = (int)dword_481C04;
        v59 = deployedMines_464F60;
        do
        {
          //v13 = *(_DWORD *)(v12 - 4) - v8 - 4;
			v13 = raceMines[v12].dword_481C00 - v8 - 4;
          
          if ( v13 < 0 )
			  v13 = v8 - raceMines[v12].dword_481C00 + 4;
			  //v13 = v8 - *(_DWORD *)(v12 - 4) + 4;
          if ( v13 < 8 )
          {
			  v14 = raceMines[v12].dword_481C04 - v10 - 4;
            
			  //v14 = *(_DWORD *)v12 - v10 - 4;
            if ( v14 < 0 )
            //  v14 = v10 - *(_DWORD *)v12 + 4;
			v14 = v10 - raceMines[v12].dword_481C04 + 4;
            if ( v14 < 8 )
              v11 = 1;
          }
          //v12 += 16;
		  v12+=1;
          --v59;
        }
        while ( v59 );
        if ( !v11 )
        {
LABEL_85:
          if ( currentDriverSelectedIndex_503518 == userRaceOrder_4A9EA8 )
          {
            loadMenuSoundEffect(4u, 18, 0, 36864, 135168);
          }
          else
          {
			  //si la distancia entre el jugador y el que pone la mina es mayor de 4096 suena otro sonido
			  v15 = raceParticipantIngame[v0].absolutePositionX_4A7DB4 -raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
			  v16 = (unsigned __int64)(raceParticipantIngame[v0].absolutePositionY_4A7DB8 - raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8);
            v17 = 0x10000 - 75 * (unsigned __int64)sqrt((double)(v15 * v15 + (signed int)v16 * (signed int)v16));
            if ( v17 > 4096 )
              loadMenuSoundEffect(4u, 18, 0, v17, 135168);
            v10 = v60;
          }
          v18 = deployedMines_464F60;
          v19 = 4 * deployedMines_464F60;
          //dword_481C00[v19] = v8 + 4;
          //dword_481C04[v19] = v10 + 4;
		  raceMines[v18].dword_481C00 = v8 + 4;
		  raceMines[v18].dword_481C04 = v10 + 4;
		  deployedMines_464F60 = v18 + 1;
          v20 = v10;
          v21 = 0;
          do
          {
            v22 = *((BYTE *)mines1aBpk + v21);
            if ( v22 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8) = v22;
            v23 = *((BYTE *)mines1aBpk + v21 + 1);
            if ( v23 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8 + 1) = v23;
            v24 = *((BYTE *)mines1aBpk + v21 + 2);
            if ( v24 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8 + 2) = v24;
            v25 = *((BYTE *)mines1aBpk + v21 + 3);
            if ( v25 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8 + 3) = v25;
            v26 = *((BYTE *)mines1aBpk + v21 + 4);
            if ( v26 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8 + 4) = v26;
            v27 = *((BYTE *)mines1aBpk + v21 + 5);
            if ( v27 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8 + 5) = v27;
            v28 = *((BYTE *)mines1aBpk + v21 + 6);
            if ( v28 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8 + 6) = v28;
            v29 = *((BYTE *)mines1aBpk + v21 + 7);
            if ( v29 )
              *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 * v20 + v8 + 7) = v29;
            v21 += 8;
            ++v20;
          }
          while ( v21 < 64 );
          --raceParticipant2[currentDriverSelectedIndex_503518].mines;//esto resta una mina
        }
      }
    }
  }
  result = deployedMines_464F60;
  v61 = 0;
  if ( deployedMines_464F60 > 0 )
  {
    //v31 = (int)dword_481C00;
    v31 =0;
    
	 while ( 1 )
    {
		v32 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 - raceMines[v31].dword_481C00;
		v33 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8- raceMines[v31].dword_481C04;
      v34 = v32;
      if ( v32 < 0 )
        v34 = -v32;
      if ( v34 >= 20 )
        goto LABEL_82;
      v35 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 -raceMines[v31].dword_481C04;
      if ( v33 < 0 )
        v35 = -v33;
      if ( v35 >= 20
        || *((BYTE *)participantCarBpk_5034FC + 40 * v33 + raceParticipantIngame[currentDriverSelectedIndex_503518].participantBpkOffser_4A7D10 + v32 + 820) <= 3u
		|| raceMines[v31].unk_481C08 != -1 )
        goto LABEL_82;
      v36 = 0;
      v37 = 0;
      do
      {
        v38 = 0;
        do
        {
          v39 = *((BYTE *)blowiBpk + v37 + v38 + 1280);
          if ( v39 )
            *((char *)circuitMatrixHxW_5034F8 + raceMines[v31].dword_481C00 + circuitWidth_464F40 * (raceMines[v31].dword_481C04 + v36 - 8) + v38 - 8) = v39;
          v40 = *((BYTE *)blowiBpk + v37 + v38 + 1281);
          if ( v40 )
            *((char *)circuitMatrixHxW_5034F8 + raceMines[v31].dword_481C00 + circuitWidth_464F40 * (raceMines[v31].dword_481C04+ v36 - 8) + v38 - 7) = v40;
          v41 = *((BYTE *)blowiBpk + v37 + v38 + 1282);
          if ( v41 )
            *((char *)circuitMatrixHxW_5034F8 + raceMines[v31].dword_481C00 + circuitWidth_464F40 * (raceMines[v31].dword_481C04 + v36 - 8) + v38 - 6) = v41;
          v42 = *((BYTE *)blowiBpk + v37 + v38 + 1283);
          if ( v42 )
            *((char *)circuitMatrixHxW_5034F8 + raceMines[v31].dword_481C00 + circuitWidth_464F40 * (raceMines[v31].dword_481C04 + v36 - 8) + v38 - 5) = v42;
          v38 += 4;
        }
        while ( v38 < 16 );
        v37 += 16;
        ++v36;
      }
      while ( v37 < 256 );
      v43 = currentDriverSelectedIndex_503518;
      v44 = raceParticipantIngame[currentDriverSelectedIndex_503518].hasFinishedTheRace_4A7E0C;
	  raceMines[v31].unk_481C08 = 0;
      if ( !v44 )
		  raceParticipant2[v43].damageBar_4A6898 += 20 * (raceParticipant2[v43].efectiveArmour_4A689C - 1024);
	  if ( raceParticipant2[v43].damageBar_4A6898 < 0 )
		  raceParticipant2[ v43].damageBar_4A6898 = 0;

	  //parece que es la direccion donde echar para atras
     raceParticipantIngame[v43].unk_4A7DFC  = (double)(rand() % 3 - 1) * 0.5 + raceParticipantIngame[v43].unk_4A7DFC;
     
	 

	 //ESTOS CALCULOS SON COMPLICADOS PORQUE NO SE QUE ES CADA VARIABLE
	 //v45 = raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7E00;
     // *(float *)v45 = (double)(rand() % 3 - 1) * 0.5 + *(float *)v45;

	  //esto te hecha para atras
      //v46 = (signed int)(unsigned __int64)raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4;
	  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 =(double)(rand() % 11 - 5) + raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4;
      //*(float *)v46 = (double)(rand() % 11 - 5) + *(float *)v46;
      //v47 = (signed int)(unsigned __int64)raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8;
	  raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 =(double)(rand() % 11 - 5) + raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8;
      //*(float *)v47 = (double)(rand() % 11 - 5) + *(float *)v47;
      v48 = 864 * currentDriverSelectedIndex_503518;
      v49 = rand();
      v50 = userRaceOrder_4A9EA8;
      v51 = currentDriverSelectedIndex_503518 == userRaceOrder_4A9EA8;
      (raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7E04) = (double)(v49 % 22 - 10);
      raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - 1.7 * raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0;
      if ( v51 )
        break;
      v52 = 864 * v50;
      v53 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 -  raceParticipantIngame[v50].absolutePositionX_4A7DB4;
      v54 = (unsigned __int64)(raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 -raceParticipantIngame[v50].absolutePositionY_4A7DB8);
      v55 = 0x10000 - 75 * (unsigned __int64)sqrt((double)(v53 * v53 + (signed int)v54 * (signed int)v54));
      if ( v55 > 4096 )
      {
        v56 = v55;
        goto LABEL_81;
      }
LABEL_82:
      result = v61 + 1;
      //v31 += 16;
      v31 += 1;
      
	  ++v61;
      if ( v61 >= deployedMines_464F60 )
        return result;
    }
    v56 = 36864;
LABEL_81:
	//SOUND_MINE_EXPLOSION
    loadMenuSoundEffect(4u, 23, 0, v56, 135168);
    goto LABEL_82;
  }
  return result;
}

//----- (0040FE20) --------------------------------------------------------
int drawExplosion_40FE20()
{
  int result; // eax@1
  int v1; // esi@1
  int v2; // ebp@2
  char *v3; // edi@2
  int v4; // edx@4
  int v5; // ebx@4
  signed int v6; // esi@9
  int v7; // ebx@9
  signed int v8; // eax@10
  char v9; // cl@11
  char v10; // cl@13
  char v11; // cl@15
  char v12; // cl@17
  int v13; // ecx@25
  bool v14; // sf@25
  unsigned __int8 v15; // of@25
  char *v16; // eax@26
  int v17; // edx@26
  int v18; // [sp+4h] [bp-10h]@2
  char *v19; // [sp+8h] [bp-Ch]@2
  int v20; // [sp+Ch] [bp-8h]@1
  int v21; // [sp+10h] [bp-4h]@2

  result = deployedMines_464F60;
  v1 = 0;
  v20 = 0;
  if ( deployedMines_464F60 > 0 )
  {
//    v2 = (int)dword_481C00;
	  v2=0;
    //v3 = (char *)&unk_481C08;
    //v19 = (char *)&unk_481C0C;
    //v18 = (int)dword_481C04;
    //v21 = (int)dword_481C00;
    do
    {
      if ( raceMines[v2].unk_481C08 != -1 )
      {
		  v4 = leftMenuInRaceWidth_456AA0 + raceMines[v2].dword_481C00 - circuitImageOffsetX_456ABC;
		  v5 = raceMines[v2].dword_481C04 - circuitImageOffsetY_456AC0;
        if ( v4 >= 8 && v4 + 8 < 320 && v5 >= 8 && v5 + 8 < 200 && raceMines[v2].unk_481C08 != 5 )
        {
          v6 = 0;
          v7 = v5 << 9;
          do
          {
            v8 = 0;
            do
            {
              v9 = *((BYTE *)blowiBpk + 16 * (v6 + 16 * raceMines[v2].unk_481C08) + v8);
              if ( v9 )
                *(BYTE *)(v4 + v8 + v7 + dword_464F14 - 4008) = v9;
              v10 = *((BYTE *)blowiBpk + 16 * (v6 + 16 *raceMines[v2].unk_481C08) + v8 + 1);
              if ( v10 )
                *(BYTE *)(v4 + v8 + v7 + dword_464F14 - 4007) = v10;
              v11 = *((BYTE *)blowiBpk + 16 * (v6 + 16 * raceMines[v2].unk_481C08) + v8 + 2);
              if ( v11 )
                *(BYTE *)(v4 + v8 + v7 + dword_464F14 - 4006) = v11;
              v12 = *((BYTE *)blowiBpk + 16 * (v6 + 16 * raceMines[v2].unk_481C08) + v8 + 3);
              if ( v12 )
                *(BYTE *)(v4 + v8 + v7 + dword_464F14 - 4005) = v12;
              v8 += 4;
            }
            while ( v8 < 16 );
            ++v6;
            v7 += 512;
          }
          while ( v6 < 16 );
		  v2 = 0;//raceMines[v2].dword_481C00;
          v1 = v20;
        }
		if ( refreshScreenWithDelay() >= raceMines[v2].unk_481C0C + 5) 
        {
          ++raceMines[v2].unk_481C08;
		  raceMines[v2].unk_481C0C = refreshScreenWithDelay();
        }
        if ( raceMines[v2].unk_481C08 > 5 )
        {
          v13 = deployedMines_464F60 - 1;
          v15 = __OFSUB__(v1, deployedMines_464F60 - 1);
          v14 = v1 - (deployedMines_464F60 - 1) < 0;
          raceMines[v2].dword_481C04 = -1;
          if ( v14 ^ v15 )
          {
            v16 = v2;// raceMines[v2].unk_481C08;//v3;
            v17 = v13 - v1;
			
            do
            {
				raceMines[v2].unk_481C08 = raceMines[v2+1].unk_481C08;
				raceMines[v2].dword_481C00 = raceMines[v2+1].dword_481C00;
				raceMines[v2].dword_481C04 = raceMines[v2+1].dword_481C04;
              //*(_DWORD *)v16 = *((_DWORD *)v16 + 4);
              //*((_DWORD *)v16 - 2) = *((_DWORD *)v16 + 2);
              //*((_DWORD *)v16 - 1) = *((_DWORD *)v16 + 3);
              v16 += 1;
              --v17;
            }
            while ( v17 );
          }
          --v1;
          v2 -=1;// 16;
        //  v18 -=1;// 16;
         // v19 -=1;// 16;
         // v3 -=1;// 16;
          deployedMines_464F60 = v13;
        }
      }
      v2 += 1;//16;
      //v3 += 1;//16;
      result = deployedMines_464F60;
      ++v1;
      v20 = v1;
      v21 = v2;
      //v18 += 1;//16;
      //v19 += 1;//16;
    }
    while ( v1 < deployedMines_464F60 );
  }
  return result;
}

//----- (00410050) --------------------------------------------------------
void powerUpTaken_410050()
{
  int v0; // ecx@1
  signed int* v1; // esi@1
  int v2; // ebp@4
  int v3; // ebx@4
  unsigned int v4; // eax@9
  char *v5; // esi@9
  void *v6; // edi@9
  char v7; // cl@10
  char *v8; // edi@12
  char v9; // al@13
  char v10; // cl@16
  int v11; // [sp+14h] [bp-14h]@1
  char DstBuf[20]; // [sp+18h] [bp-10h]@9
  char v13; // [sp+1Fh] [bp-9h]@9
  __int16 v14; // [sp+20h] [bp-8h]@9
  int index = 0;
  v0 = Val;
  //v1 = (signed int)&unk_501BB4;
  //v1=malloc(4320);
  //v11 = (int)&unk_501BB4;
  do  //15 vueltas
  {
	  if ( powerups[index].dword_501BB4 > 0 && v0 > 0 )
    {
		v2 = leftMenuInRaceWidth_456AA0 +powerups[index].posX_501BA0 - circuitImageOffsetX_456ABC;
	  v3 = (powerups[index].dword_501BB4 >> 3) - circuitImageOffsetY_456AC0 + powerups[index].posY_501BA4 - 10;//*(_DWORD *)(v1 - 16)
      if ( v2 >= -18 && v2 < 320 && v3 >= 0 && v3 + 6 < 200 )
      {
        switch (powerups[index].lastPowerUp_ID_501BB8 )
        {
          case POWERUP_SMALL_MONEY:
            _itoa(v0, &DstBuf, 10);
			strcat(&DstBuf, "$");
			v6=DstBuf;
            v5 = &DstBuf;
            v4 = strlen(&DstBuf);
            goto LABEL_17;
          case POWERUP_SMALL_REPAIR:
          case POWERUP_BIG_REPAIR:
			_itoa(powerups[index].repairpercentage_501BBC,&DstBuf, 10);
			strcat(&DstBuf, "%");
			v6=DstBuf;
            v5 = &DstBuf;
            v4 = strlen(&DstBuf);
            goto LABEL_17;
			  
          case POWERUP_BIG_MONEY:
            _itoa(10 * v0, &DstBuf, 10);
            strcat(&DstBuf, "$");
			v6=DstBuf;
            v5 = &DstBuf;
            v4 = strlen(&DstBuf);
LABEL_17:
			//esta pintando en mal posicion
            memcpy(v6, v5, v4);
            writeTextInRace_402510((v3 << 9) + v2 , (const char *)&v14);
            //v1 = v11;
LABEL_18:
            v0 = Val;
            break;
          default:
            break;
        }
      }
      powerups[index].dword_501BB4 -= dword_4A9EA4;
    }
	index++;
	//index+=288;
    //v1 += 288;
    //v11 = v1;
  }
  while ( index < 16);
  //while ( v1 < (signed int)&unk_502C94 );
}

//----- (00410220) --------------------------------------------------------
int generatePowerUps()
{
  int v0; // edx@1
  int v1; // esi@2
  signed int v2; // eax@4
  signed int v3; // ecx@8
  signed int v4; // ecx@11
  signed int v5; // ecx@14
  signed int v6; // ecx@17
  signed int v7; // ecx@20
  int (  *v8)(); // ebx@24
  signed int v9; // ecx@26
  signed int v10; // eax@26
  int v11; // edx@41
  int v12; // esi@42
  int v13; // eax@42
  int v14; // edx@49
  bool v15; // sf@62
  unsigned __int8 v16; // of@62
  void *v17; // edi@76
  int v18; // ebp@76
  signed int v19; // eax@76
  int v20; // edx@77
  int v21; // ecx@77
  int v22; // ecx@77
  int v23; // edx@77
  int v24; // ecx@77
  int v25; // ecx@77
  int v26; // edx@77
  signed int v27; // ecx@78
  signed int v28; // eax@79
  char v29; // dl@80
  char v30; // dl@82
  char v31; // dl@84
  char v32; // dl@86
  signed int v33; // esi@95
  int v34; // ecx@96
  signed int v35; // edx@96
  signed int v36; // eax@96
  signed int v37; // ecx@102
  signed int v38; // eax@103
  char v39; // dl@104
  char v40; // dl@106
  char v41; // dl@108
  char v42; // dl@110
  int v43; // ecx@114
  signed int v44; // edx@114
  int result; // eax@114
  int v46; // ecx@120
  int v47; // edi@121
  char *v48; // edx@121
  char *v49; // edi@121
  char *v50; // edi@121
  signed int v51; // eax@123
  int v52; // ecx@123
  int v53; // edi@125
  char *v54; // edx@125
  char *v55; // edi@125
  char *v56; // edi@125
  int v57; // edx@125
  int v58; // eax@126
  signed __int64 v59; // rtt@126
  char *v60 = malloc(100); // [sp+10h] [bp-18h]@76
  signed int v61; // [sp+14h] [bp-14h]@40
  int v62; // [sp+18h] [bp-10h]@40
  int v63[12]; // [sp+1Ch] [bp-Ch]@40
  int v64; // [sp+20h] [bp-8h]@40
  int v65; // [sp+24h] [bp-4h]@40

  v0 = dword_4A9EA4;
  if ( dword_456AC4 <= 0 )
    v1 = 0;
  else
    v1 = dword_456AC4 - dword_4A9EA4;
  dword_456AC4 = v1;
  //v2 = (signed int)dword_501BB0;
   v2 = 0;
  do
  {

	  ///v2 -8 es el identificador del powerup
	if ( powerups[v2].timeShowed_501BB0 < 2000 && powerups[v2].powerUp_ID_501BA8 )
        powerups[v2].timeShowed_501BB0 += v0;
    v2 = v2+1;
    /*if ( v3 < 2000 && *(_DWORD *)(v2 + 280) )
      *(_DWORD *)(v2 + 288) = v0 + v3;
    v2 = v2+1;
    if ( v4 < 2000 && *(_DWORD *)(v2 + 568) )
      *(_DWORD *)(v2 + 576) = v0 + v4;
    v2 = v2+1;
    if ( v5 < 2000 && *(_DWORD *)(v2 + 856) )
      *(_DWORD *)(v2 + 864) = v0 + v5;
    v2 = v2+1;
    if ( v6 < 2000 && *(_DWORD *)(v2 + 1144) )
      *(_DWORD *)(v2 + 1152) = v0 + v6;
    v2 = v2+1;
    if ( v7 < 2000 && *(_DWORD *)(v2 + 1432) )
      *(_DWORD *)(v2 + 1440) = v0 + v7;
    v2 = v2+1;
    */
  }
  while ( v2 < 16);
  v8 = rand;
  if ( !v1 && !isRaceFinish_456AC8 )
  {
    v9 = 0;
   // v10 = (signed int)&unk_501CC8;
    v10 = 0;   
	do
    {
      if (powerups[v10].powerUp_ID_501BA8 > 0 )
        ++v9;
      if ( powerups[v10+1].powerUp_ID_501BA8 > 0 )
        ++v9;
      if ( powerups[v10+2].powerUp_ID_501BA8 > 0 )
        ++v9;
      if ( powerups[v10+3].powerUp_ID_501BA8 > 0 )
        ++v9;
      if ( powerups[v10+4].powerUp_ID_501BA8 > 0 )
        ++v9;
      if ( powerups[v10+5].powerUp_ID_501BA8 > 0 )
        ++v9;
      v10 += 5;
    }
    while ( v10 < 16);
    v63[0] = 0;
    v64 = 0;
    v61 = v9;
    v65 = 0;
    v62 = 0;
    while ( 1 )
    {
      do
        v11 = v8() % 12;
      while ( v63[v11] == 1 );
      v12 = 72 * v11;
      v13 = powerups[v11].dword_501BAC;
      v63[v11] = 1;
      powerups[v11].dword_501BAC = v13 <= 0 ? 0 : v13 - dword_4A9EA4;
	  if ( !powerups[v11].powerUp_ID_501BA8 && powerups[v11].posX_501BA0> 0 && !powerups[v11].dword_501BAC && v61 < 4 )
        break;
      v17 = circuitMatrixHxW_5034F8;
      v18 = circuitWidth_464F40;
LABEL_92:
      v16 = __OFSUB__(v62 + 1, 12);
      v15 = v62++ - 11 < 0;
      if ( !(v15 ^ v16) )
        goto LABEL_95;
    }
    v14 = v8() % 100;
    if ( raceParticipant2[userRaceOrder_4A9EA8].useWeapons )
    {
      if ( v14 >= 0 )
      {
        if ( v14 >= 30 )
        {
LABEL_54:
          if ( v14 >= 65 )
          {
LABEL_57:
            if ( v14 >= 80 )
              goto LABEL_60;
            powerups[v11].powerUp_ID_501BA8 = POWERUP_SMALL_MONEY;
LABEL_59:
            if ( v14 < 80 )
            {
LABEL_62:
              v16 = __OFSUB__(v14, 85);
              v15 = v14 - 85 < 0;
              goto LABEL_73;
            }
LABEL_60:
            if ( v14 >= 85 )
              goto LABEL_74;
            powerups[v11].powerUp_ID_501BA8= POWERUP_DRUNK;
            goto LABEL_62;
          }
          powerups[v11].powerUp_ID_501BA8 = POWERUP_TURBO;
LABEL_56:
          if ( v14 < 65 )
            goto LABEL_59;
          goto LABEL_57;
        }
        powerups[v11].powerUp_ID_501BA8= POWERUP_SHOTS;
      }
      if ( v14 < 30 )
        goto LABEL_56;
      goto LABEL_54;
    }
    if ( v14 >= 0 )
    {
      if ( v14 >= 45 )
      {
LABEL_67:
        if ( v14 >= 80 )
          goto LABEL_70;
        powerups[v11].powerUp_ID_501BA8= POWERUP_SMALL_MONEY;
LABEL_69:
        if ( v14 < 80 )
        {
LABEL_72:
          v16 = __OFSUB__(v14, 90);
          v15 = v14 - 90 < 0;
LABEL_73:
          if ( v15 ^ v16 )
          {
LABEL_76:
            v17 = circuitMatrixHxW_5034F8;
            ++v61;
			
			//esto lo he eliminado
			//powerups[v11].posX_501BA0 = 0;
            v18 = circuitWidth_464F40;
            v19 = 0;
			v21=0;
			//v60 = powerups[v11];
            /*v60 = (char *)&unk_501BD0 + v12 * 4;*/
            do
            {///esto esta hecho al reves todo!!! joer
				v20 = (int)((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4+ v19 - 8) - 8);
              //v21 = (int)(v60 - 16);
              powerups[v11].screenBackup_501BC0[v21+0] =*(_DWORD *)v20;
              powerups[v11].screenBackup_501BC0[v21+1]=*(_DWORD *)(v20 + 4);
              powerups[v11].screenBackup_501BC0[v21+2]=*(_DWORD *)(v20 + 8);
              powerups[v11].screenBackup_501BC0[v21+3]=*(_DWORD *)(v20 + 12);
			  v22 = (int)((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v19 - 7) - 8);
              powerups[v11].screenBackup_501BC0[v21+4] =*(_DWORD *)v22;
              powerups[v11].screenBackup_501BC0[v21+5]= *(_DWORD *)(v22 + 4);
              powerups[v11].screenBackup_501BC0[v21+6]= *(_DWORD *)(v22 + 8);
              powerups[v11].screenBackup_501BC0[v21+7]=*(_DWORD *)(v22 + 12);
			  v23 = (int)((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v19 - 6) - 8);
              v24 = (int)(v60 + 16);
              powerups[v11].screenBackup_501BC0[v21+8]=*(_DWORD *)v23;
              powerups[v11].screenBackup_501BC0[v21+9]=*(_DWORD *)(v23 + 4);
              powerups[v11].screenBackup_501BC0[v21+10]=*(_DWORD *)(v23 + 8);
              powerups[v11].screenBackup_501BC0[v21+11]=*(_DWORD *)(v23 + 12);
			  v25 = (int)((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4+ v19 - 5) - 8);
              v26 = (int)(v60 + 32);
               powerups[v11].screenBackup_501BC0[v21+12]=*(_DWORD *)v25;
			   powerups[v11].screenBackup_501BC0[v21+13]= *(_DWORD *)(v25 + 4);
               powerups[v11].screenBackup_501BC0[v21+14]=*(_DWORD *)(v25 + 8);
               powerups[v11].screenBackup_501BC0[v21+15]= *(_DWORD *)(v25 + 12);
              v20 += 4;
			  v21 +=16;
			  v19 +=4;
              v60 += 64;
            }
            while ( v19 < 16 );
            
			
			v27 = 0;
            
			do
            {
              v28 = 0;
              do
              {
				  v29 = *((BYTE *)obstacleBpk + 16 * (16 * powerups[v11].powerUp_ID_501BA8 + v27 - 16) + v28);
                if ( v29 )
                {
					*((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 8) = v29;
                  v17 = circuitMatrixHxW_5034F8;
                  v18 = circuitWidth_464F40;
                }
                v30 = *((char *)obstacleBpk + 16 * (v27 + 16 * powerups[v11].powerUp_ID_501BA8) + v28 - 255);
                if ( v30 )
                {
					*((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 7) = v30;
                  v17 = circuitMatrixHxW_5034F8;
                  v18 = circuitWidth_464F40;
                }
                v31 = *((char *)obstacleBpk + 16 * (v27 + 16 * powerups[v11].powerUp_ID_501BA8) + v28 - 254);
                if ( v31 )
                {
					*((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 6) = v31;
                  v17 = circuitMatrixHxW_5034F8;
                  v18 = circuitWidth_464F40;
                }
                v32 = *((char *)obstacleBpk + 16 * (v27 + 16 * powerups[v11].powerUp_ID_501BA8) + v28 - 253);
                if ( v32 )
                {
					*((char *)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 5) = v32;
                  v17 = circuitMatrixHxW_5034F8;
                  v18 = circuitWidth_464F40;
                }
                v28 += 4;
              }
              while ( v28 < 16 );
              ++v27;
            }
            while ( v27 < 16 );
            v8 = rand;
            goto LABEL_92;
          }
LABEL_74:
          if ( v14 < 100 )
            powerups[v11].powerUp_ID_501BA8 = POWERUP_SMALL_REPAIR;
          goto LABEL_76;
        }
LABEL_70:
        if ( v14 >= 90 )
          goto LABEL_74;
        powerups[v11].powerUp_ID_501BA8 = POWERUP_DRUNK;
        goto LABEL_72;
      }
      powerups[v11].powerUp_ID_501BA8 = POWERUP_TURBO;
    }
    if ( v14 < 45 )
      goto LABEL_69;
    goto LABEL_67;
  }
  v17 = circuitMatrixHxW_5034F8;
  v18 = circuitWidth_464F40;
LABEL_95:
  v33 = 0;
  do
  {
	  v34 = powerups[v33].timeShowed_501BB0;
    v35 = 0;
    v36 = 2000;
    do
    {
      if ( v34 > v36 - 10 && v34 < v36 )
        v35 = 1;
      v36 -= 20;
    }
    while ( v36 >= 1540 );
    if ( v35 )
    {
      v37 = 0;
      do
      {
        v38 = 0;
        do
        {
          v39 = *((BYTE *)obstacleBpk + 16 * (16 * powerups[v33].powerUp_ID_501BA8 + v37 - 16) + v38);
          if ( v39 )
          {
			  *((char *)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 8) = v39;
            v17 = circuitMatrixHxW_5034F8;
            v18 = circuitWidth_464F40;
          }
		  v40 = *((char *)obstacleBpk + 16 * (v37 + 16 * powerups[v33].powerUp_ID_501BA8) + v38 - 255);
          if ( v40 )
          {
			  *((char *)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 7) = v40;
            v17 = circuitMatrixHxW_5034F8;
            v18 = circuitWidth_464F40;
          }
          v41 = *((char *)obstacleBpk + 16 * (v37 + 16 * powerups[v33].powerUp_ID_501BA8) + v38 - 254);
          if ( v41 )
          {
			  *((char *)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 6) = v41;
            v17 = circuitMatrixHxW_5034F8;
            v18 = circuitWidth_464F40;
          }
          v42 = *((char *)obstacleBpk + 16 * (v37 + 16 * powerups[v33].powerUp_ID_501BA8) + v38 - 253);
          if ( v42 )
          {
			  *((char *)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 5) = v42;
            v17 = circuitMatrixHxW_5034F8;
            v18 = circuitWidth_464F40;
          }
          v38 += 4;
        }
        while ( v38 < 16 );
        ++v37;
      }
      while ( v37 < 16 );
    }
	v43 = powerups[v33].timeShowed_501BB0;
    v44 = 0;
    result = 1990;
    do
    {
      if ( v43 > result - 10 && v43 < result )
        v44 = 1;
      result -= 20;
    }
    while ( result >= 1530 );
    if ( v44 )
    {
      result = 0;
	  v46=0;
      /*v46 = (char *)&unk_501BD0 + v33 * 4*/
      do
      { ///esto sirve para hacer que vibre cuando hay se agota el tiempo
		  v47 = (int)((char *)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + result - 8) - 8);
        *(_DWORD *)v47 = powerups[v33].screenBackup_501BC0[v46+0];
        *(_DWORD *)(v47 + 4) = powerups[v33].screenBackup_501BC0[v46+1];
        *(_DWORD *)(v47 + 8) = powerups[v33].screenBackup_501BC0[v46+2];
        *(_DWORD *)(v47 + 12) = powerups[v33].screenBackup_501BC0[v46+3];
		v48 = (char *)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0+ circuitWidth_464F40 * (powerups[v33].posY_501BA4+ result - 7) - 8;
        *(_DWORD *)v48 = powerups[v33].screenBackup_501BC0[v46+4];
        *((_DWORD *)v48 + 1) = powerups[v33].screenBackup_501BC0[v46+5];
        *((_DWORD *)v48 + 2) = powerups[v33].screenBackup_501BC0[v46+6];
        *((_DWORD *)v48 + 3) = powerups[v33].screenBackup_501BC0[v46+7];
		v49 = (char *)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + result - 6) - 8;
        *(_DWORD *)v49 = powerups[v33].screenBackup_501BC0[v46+8];
        *((_DWORD *)v49 + 1) = powerups[v33].screenBackup_501BC0[v46+9];
        *((_DWORD *)v49 + 2) = powerups[v33].screenBackup_501BC0[v46+10];
        *((_DWORD *)v49 + 3) = powerups[v33].screenBackup_501BC0[v46+11];
		v50 = (char *)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + result - 5) - 8;
        *(_DWORD *)v50 = powerups[v33].screenBackup_501BC0[v46+12];
        *((_DWORD *)v50 + 1) = powerups[v33].screenBackup_501BC0[v46+13];
        *((_DWORD *)v50 + 2) = powerups[v33].screenBackup_501BC0[v46+14];
        *((_DWORD *)v50 + 3) = powerups[v33].screenBackup_501BC0[v46+15];
        result += 4;
        v46+=16;
		v18 = circuitWidth_464F40;
        v17 = circuitMatrixHxW_5034F8;
       // v46 += 64;
      }
      while ( result < 16 );
	  
    }
	if ( powerups[v33].timeShowed_501BB0 >= 2000 )
    {
      v51 = 0;
	  v52=0;
      /*v52 = (char *)&unk_501BD0 + v33 * 4;*/
      while ( 1 )
      {
		  v53 = (int)((char *)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v51 - 8) - 8);
        *(_DWORD *)v53 = powerups[v33].screenBackup_501BC0[v52+0];
        *(_DWORD *)(v53 + 4) =powerups[v33].screenBackup_501BC0[v52+1];
        *(_DWORD *)(v53 + 8) = powerups[v33].screenBackup_501BC0[v52+2];
        *(_DWORD *)(v53 + 12) = powerups[v33].screenBackup_501BC0[v52+3];
		v54 = (char *)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + v51 - 7) - 8;
        *(_DWORD *)v54 = powerups[v33].screenBackup_501BC0[v52+4];
        *((_DWORD *)v54 + 1) = powerups[v33].screenBackup_501BC0[v52+5];
        *((_DWORD *)v54 + 2) = powerups[v33].screenBackup_501BC0[v52+6];
        *((_DWORD *)v54 + 3) = powerups[v33].screenBackup_501BC0[v52+7];
		v55 = (char *)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + v51 - 6) - 8;
        *(_DWORD *)v55 = powerups[v33].screenBackup_501BC0[v52+8];
        *((_DWORD *)v55 + 1) = powerups[v33].screenBackup_501BC0[v52+9];
        *((_DWORD *)v55 + 2) = powerups[v33].screenBackup_501BC0[v52+10];
        *((_DWORD *)v55 + 3) = powerups[v33].screenBackup_501BC0[v52+11];
		v56 = (char *)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + v51 - 5) - 8;
        *(_DWORD *)v56 = powerups[v33].screenBackup_501BC0[v52+12];
        *((_DWORD *)v56 + 1) = powerups[v33].screenBackup_501BC0[v52+13];
        *((_DWORD *)v56 + 2) = powerups[v33].screenBackup_501BC0[v52+14];
        v57 = powerups[v33].screenBackup_501BC0[v52+15];
        v51 += 4;
        v52 += 16;
        *((_DWORD *)v56 + 3) = v57;
        if ( v51 >= 16 )
          break;
        v17 = circuitMatrixHxW_5034F8;
        v18 = circuitWidth_464F40;
      }
	  powerups[v33].timeShowed_501BB0 = 0;
	  powerups[v33].powerUp_ID_501BA8 = 0;
      dword_456AC4 = 280;
      v58 = rand();
      v59 = v58;
      result = v58 / 200;
      v17 = circuitMatrixHxW_5034F8;
      v18 = circuitWidth_464F40;
	  powerups[v33].dword_501BAC = (unsigned __int64)(v59 % 200) + 300;
    }
    v33 += 1;
  }
  while ( v33 < 16);//864 );
  return result;
}

//----- (00410B90) --------------------------------------------------------
char getRacePowerUps_410B90()
{
  int v0; // ebx@1
  signed int v1; // esi@1
  int v2; // edi@2
  int v3; // eax@2
  int v4; // ecx@2
  int v5; // ecx@5
  char *v6; // edx@8
  int v7; // edi@8
  double v8; // st7@15
  int v9; // ebx@15
  signed int v10; // eax@15
  signed int v11; // eax@18
  int v12; // ecx@18
  char *v13; // ebx@19
  char *v14; // edx@19
  char *v15; // ebx@19
  char *v16; // ebx@19
  int v17; // edx@19
  int *v18; // eax@21
  int v19; // edx@21
  int v20; // eax@24
  int v21; // eax@26
  int v22; // edx@26
  int *v23; // ecx@26
  int v24; // eax@26
  int v25; // edx@31
  int v26; // eax@34
  int v27; // eax@34
  signed __int64 v28; // rtt@34
  unsigned __int8 v30; // [sp-18h] [bp-2Ch]@14
  char v31; // [sp-14h] [bp-28h]@14
  int v32; // [sp-Ch] [bp-20h]@14

  v0 = currentDriverSelectedIndex_503518;
  v1 = 0;
  do
  {
	  v2 = raceParticipantIngame[v0].absolutePositionX_4A7DB4 - powerups[v1].posX_501BA0 ;
	  v3 = raceParticipantIngame[v0].absolutePositionY_4A7DB8 - powerups[v1].posY_501BA4;
    v4 = v2;
    if ( v2 < 0 )
      v4 = -v2;
    if ( v4 < 17 )
    {
      v5 = raceParticipantIngame[v0].absolutePositionY_4A7DB8 - powerups[v1].posY_501BA4;
      if ( v3 < 0 )
        v5 = -v3;
      if ( v5 < 17 )
      {
        v6 = (char *)participantCarBpk_5034FC + 40 * v3 + raceParticipantIngame[v0].participantBpkOffser_4A7D10;
        LOBYTE(v3) = v6[v2 + 738];
        v7 = (int)&v6[v2];
        if ( (unsigned __int8)v3 > 3u
          || *(BYTE *)(v7 + 742) > 3u
          || *(BYTE *)(v7 + 898) > 3u
          || *(BYTE *)(v7 + 902) > 3u )
        {
			v3 = powerups[v1].powerUp_ID_501BA8;
          if ( v3 > 0 )
          {
            if ( v0 == userRaceOrder_4A9EA8 )
            {
              v32 = 36864;
              v31 = 18;
              v30 = 4;
            }
            else
            {
              v8 = raceParticipantIngame[v0].absolutePositionY_4A7DB8 - raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
			  v9 = raceParticipantIngame[v0].absolutePositionX_4A7DB4 - raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
              v10 = 36864
                  - 75
                  * (unsigned __int64)sqrt((double)(signed int)(v9 * v9 + (unsigned __int64)v8 * (unsigned __int64)v8));
              if ( v10 <= 4096 )
              {
LABEL_18:
                v11 = 0;
                //v12 = v1 + 48;//powerups[v1] +48
                v12=0;
				//v12 = powerups[v1].screenBackup_501BC0;
				do
                {
					v13 = (char *)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0 + circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 8) - 8;
                  *(_DWORD *)v13 =  powerups[v1].screenBackup_501BC0[v12];
                  *((_DWORD *)v13 + 1) = powerups[v1].screenBackup_501BC0[v12+1];
                  *((_DWORD *)v13 + 2) = powerups[v1].screenBackup_501BC0[v12+2];
                  *((_DWORD *)v13 + 3) = powerups[v1].screenBackup_501BC0[v12+3];
				  
					
				/*	*(_DWORD *)v13 = *(_DWORD *)(v12 - 16);
                  *((_DWORD *)v13 + 1) = *(_DWORD *)(v12 - 16 + 4);
                  *((_DWORD *)v13 + 2) = *(_DWORD *)(v12 - 16 + 8);
                  *((_DWORD *)v13 + 3) = *(_DWORD *)(v12 - 16 + 12);*/

				  v14 = (char *)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0 + circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 7) - 8;
                  *(_DWORD *)v14 =  powerups[v1].screenBackup_501BC0[v12+4];
                  *((_DWORD *)v14 + 1) = powerups[v1].screenBackup_501BC0[v12+5];
                  *((_DWORD *)v14 + 2) = powerups[v1].screenBackup_501BC0[v12+6];
                  *((_DWORD *)v14 + 3) = powerups[v1].screenBackup_501BC0[v12+7];
				  
				  
				  /**(_DWORD *)v14 = *(_DWORD *)v12;
                  *((_DWORD *)v14 + 1) = *(_DWORD *)(v12 + 4);
                  *((_DWORD *)v14 + 2) = *(_DWORD *)(v12 + 8);
                  *((_DWORD *)v14 + 3) = *(_DWORD *)(v12 + 12);*/
				  v15 = (char *)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0+ circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 6) - 8;
                  *(_DWORD *)v15 =powerups[v1].screenBackup_501BC0[v12+8];
                  *((_DWORD *)v15 + 1) = powerups[v1].screenBackup_501BC0[v12+9];
                  *((_DWORD *)v15 + 2) = powerups[v1].screenBackup_501BC0[v12+10];
                  *((_DWORD *)v15 + 3) = powerups[v1].screenBackup_501BC0[v12+11];
				  
				  /**(_DWORD *)v15 = *(_DWORD *)(v12 + 16);
                  *((_DWORD *)v15 + 1) = *(_DWORD *)(v12 + 20);
                  *((_DWORD *)v15 + 2) = *(_DWORD *)(v12 + 24);
                  *((_DWORD *)v15 + 3) = *(_DWORD *)(v12 + 28);*/
				  v16 = (char *)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0 + circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 5) - 8;
                 *(_DWORD *)v16 = powerups[v1].screenBackup_501BC0[v12+12];
                  *((_DWORD *)v16 + 1) = powerups[v1].screenBackup_501BC0[v12+13];
                  *((_DWORD *)v16 + 2) = powerups[v1].screenBackup_501BC0[v12+14];
                  v17 = powerups[v1].screenBackup_501BC0[v12+15];
				  
				  /**(_DWORD *)v16 = *(_DWORD *)(v12 + 32);
                  *((_DWORD *)v16 + 1) = *(_DWORD *)(v12 + 36);
                  *((_DWORD *)v16 + 2) = *(_DWORD *)(v12 + 40);
                  v17 = *(_DWORD *)(v12 + 44);*/
                  v11 += 4;
				  v12+=16;
                 // v12 += 64;
                  *((_DWORD *)v16 + 3) = v17;
                }
                while ( v11 < 16 );
				switch ( powerups[v1].powerUp_ID_501BA8 )
                {
                  case POWERUP_SHOTS://disparos pillados
                    v18 = &raceParticipant2[currentDriverSelectedIndex_503518].weaponsBar_4A68B0;
                    v19 = raceParticipant2[currentDriverSelectedIndex_503518].weaponsBar_4A68B0 + 30720;
                    goto LABEL_32;
                  case POWERUP_TURBO://turbo pillado
					  v18 = &raceParticipant2[ currentDriverSelectedIndex_503518].turboBar_4A68B4;
					  v19 = raceParticipant2[ currentDriverSelectedIndex_503518].turboBar_4A68B4 + 15360;
                    goto LABEL_32;
                  case POWERUP_SMALL_MONEY: //dinero peque\F1o pillado
                    ++raceParticipant2[currentDriverSelectedIndex_503518].moneyPicked;
                    break;
                  case POWERUP_DRUNK://bebido
                    v20 = currentDriverSelectedIndex_503518;
                    raceParticipantIngame[currentDriverSelectedIndex_503518].mushroomPendingTime_4A8050 = 560;
                    if ( v20 == userRaceOrder_4A9EA8 )
						//SOUND_SIENI
                      loadMenuSoundEffect(2u, 6, 0, 0x10000, 327680);
                    break;
                  case POWERUP_SMALL_REPAIR://llave peque\F1a de reparacion
                    v21 = rand() % 4;
					v22 = raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898;
                    v21 += 2;
					v23 = &raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898;
                   
					powerups[v1].repairpercentage_501BBC = v21;  //+28 osbre powerups[v1].
                    v24 = (v21 << 10) + v22;
                    *v23 = v24;
                    if ( v24 > 102400 )
                      *v23 = 102400;
                    break;
                  case POWERUP_DRUGS: //drogas pilladas
                    if ( currentDriverSelectedIndex_503518 == userRaceOrder_4A9EA8 )
						raceParticipant[0].drugPicked = 1;
                    break;
                  case POWERUP_BIG_MONEY: //dinero pillado! grande
					  raceParticipant2[currentDriverSelectedIndex_503518].moneyPicked += 10;
                    break;
                  case POWERUP_BIG_REPAIR://llave grande
                    v25 = raceParticipant2[ currentDriverSelectedIndex_503518].damageBar_4A6898;
					v18 = &raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898;
                    powerups[v1].repairpercentage_501BBC = 20; //+28 sobre powerups[v1].
                    v19 = v25 + 20480;
LABEL_32:
                    *v18 = v19;
                    if ( v19 > 102400 )
                      *v18 = 102400;
                    break;
                  default:
                    break;
                }
				v26 = powerups[v1].powerUp_ID_501BA8;
				powerups[v1].dword_501BB4 = 140; // + 20 sobre powerups[v1].
				powerups[v1].lastPowerUp_ID_501BB8= v26; //+24 sobre powerups[v1].
				powerups[v1].powerUp_ID_501BA8 = 0;
                dword_456AC4 = 240;
                v27 = rand();
                v28 = v27;
                v3 = v27 / 150;
                v0 = currentDriverSelectedIndex_503518;
				powerups[v1].timeShowed_501BB0 = 0;
				powerups[v1].dword_501BAC = (unsigned __int64)(v28 % 150) + 200;
                goto LABEL_35;
              }
              v32 = v10;
              v31 = 18;
              v30 = 10;
            }
			///SOUND_MINE
            loadMenuSoundEffect(v30, v31, 0, v32, 135168);
            goto LABEL_18;
          }
        }
      }
    }
LABEL_35:
    v1 += 1;
  }
  while ( v1 < 16);
  return v3;
}

//----- (00410FA0) --------------------------------------------------------
int killPedestrian_410FA0()
{
  int result; // eax@1
  int v1; // ebx@3
  int v2; // edi@3
  int v3; // esi@3
  int v4; // eax@3
  int v5; // ecx@3
  int v6; // ecx@6
  int *v7; // esi@14
  unsigned int v8; // esi@14
  int v9; // eax@14
  int v10; // edi@14
  bool v11; // zf@14
  int v12; // edi@16
  int v13; // ebx@16
  unsigned __int64 v14; // rax@16
  signed int v15; // eax@16
  int v16; // eax@18
  int v17; // [sp-Ch] [bp-24h]@15
 // signed int v18; // [sp+10h] [bp-8h]@1
  int pedestrianIndex = 0;
  result = pedestrian_479AA4[pedestrianIndex].isDied;
  //v18 = (signed int)&unk_479AB8;
  do
  {
    if ( ! pedestrian_479AA4[pedestrianIndex].isDied )
    {
      v1 = currentDriverSelectedIndex_503518;
      v2 = 216 * currentDriverSelectedIndex_503518;
	  v3 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 - pedestrian_479AA4[pedestrianIndex].positionX - 8;
      v4 =raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 - pedestrian_479AA4[pedestrianIndex].positionY- 8;
      v5 = v3;
      if ( v3 < 0 )
        v5 = -v3;
      if ( v5 < 20 )
      {
        v6 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8- pedestrian_479AA4[pedestrianIndex].positionY - 8;
        if ( v4 < 0 )
          v6 = -v4;
        if ( v6 < 20 && *((BYTE *)participantCarBpk_5034FC + 40 * v4 +raceParticipantIngame[v1].participantBpkOffser_4A7D10 + v3 + 820) > 3u )
        {
			pedestrian_479AA4[pedestrianIndex].isDied = 1;
           pedestrian_479AA4[pedestrianIndex].byte5= 0;
           
          if ( !raceParticipantIngame[v1].hasFinishedTheRace_4A7E0C )
			  raceParticipant2[v1].damageBar_4A6898 += 3 * (raceParticipant2[v1].efectiveArmour_4A689C - 1024);
		  if ( raceParticipant2[ v1].damageBar_4A6898 < 0 )
			  raceParticipant2[ v1].damageBar_4A6898 = 0;
          raceParticipantIngame[v1].absolutePositionX_4A7DB4 = (double)(rand() % 7 - 3) + raceParticipantIngame[v1].absolutePositionX_4A7DB4;
          v7 =(signed int)(unsigned __int64)raceParticipantIngame[v1].absolutePositionY_4A7DB8;
          //parece que no se usa *(float *)v7 = (double)(rand() % 7 - 3) + *(float *)v7;
          v8 = 864 * currentDriverSelectedIndex_503518;
          v9 = rand();
          v10 = userRaceOrder_4A9EA8;
          v11 = currentDriverSelectedIndex_503518 == userRaceOrder_4A9EA8;
          (raceParticipantIngame[currentDriverSelectedIndex_503518].unk_4A7E04) = (double)(v9 % 10 - 5);
          raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 = raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 - raceParticipantIngame[ currentDriverSelectedIndex_503518].carVelocity_4A7DB0 * 1.1;
           raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A8054 = 45;
          if ( v11 )
          {
            v17 = 36864;
          }
          else
          {
            v12 = 864 * v10;
			v13 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionX_4A7DB4 - raceParticipantIngame[v10].absolutePositionX_4A7DB4;
            v14 = raceParticipantIngame[currentDriverSelectedIndex_503518].absolutePositionY_4A7DB8 - raceParticipantIngame[v10].absolutePositionY_4A7DB8;
            v15 = 0x10000 - 75 * (unsigned __int64)sqrt((double)(v13 * v13 + (signed int)v14 * (signed int)v14));
            if ( v15 <= 4096 )
              goto LABEL_19;
            v17 = v15;
          }
          v16 = rand();
		  //SOUND_SPEDE1,SOUND_SPEDE2,SOUND_SPEDE3
          loadMenuSoundEffect(3u, v16 % 3 + 7, 0, v17, 327680);
        }
      }
    }
LABEL_19:
    /*result = v18 + 32;
    v18 += 32;*/
	result = pedestrian_479AA4[pedestrianIndex+1].isDied;
    pedestrianIndex += 1;
  }
  while ( pedestrianIndex < 20 );
  return result;
}

//----- (004111F0) --------------------------------------------------------
//char drawShotPedestrian_4111F0()

//----- (00411530) --------------------------------------------------------
int sub_411530()
{
  int v0; // edi@1
  int result; // eax@1
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // ebp@2
  int v5; // ecx@2
  int v6; // eax@3

  v0 = dword_4AA928;
  result = sce2Texture[dword_4AA928].trxSCE2Bpk_4B4320;
  v2 = 0;
  dword_481BE8 = 0;
  if ( result > 0 )
  {
    v3 = raceEffectiveHalfWidth_445014;
    v4 = raceEffectiveHalfHeight_44501C;
   // v5 = sce2Texture[v0].dword_4B4580;
    v5=0;
	do
    {
      //v6 = (v5[483] << 8) / *v5;
		

		//esto hay que mirarlo a fondo
	  v6 = (sce2Texture[v0].dword_4B4D0C[v5] <<8) / sce2Texture[v0].dword_4B4580[v5];
      ++v5;
	  sce2Texture[v0].dword_4B4D0C[v5-1] = raceEffectiveHalfWidth_445014 + ((v6 + 128) >> 8);
      //v5[482] = raceEffectiveHalfWidth_445014 + ((v6 + 128) >> 8);
     // v5[557] = raceEffectiveHalfHeight_44501C + (((v5[557] << 8) / *(v5 - 1) + 128) >> 8);
      sce2Texture[v0].dword_4B4E38[v5-1] = raceEffectiveHalfHeight_44501C + (((sce2Texture[v0].dword_4B4E38[v5-1] << 8) / sce2Texture[v0].dword_4B4580[v5-1] + 128) >> 8);
     
	  
	  result = sce2Texture[v0].trxSCE2Bpk_4B4320;
      ++v2;
    }
    while ( v2 < result );
    dword_481BE8 = v2;
  }
  return result;
}

//----- (004115C0) --------------------------------------------------------
int   sub_4115C0(int a1, int a2)
{
  int v2; // ecx@1
  int v3; // ebx@1
  int v4; // edx@2
  int v5; // edi@2
  int v6; // esi@2
  int *v7; // eax@3
  int v8; // ebp@4
  int result; // eax@5
  int v10; // ebp@6
  int v11; // ecx@8
  int v12; // ebx@8
  int v13; // ebp@8
  int v14; // ebx@8

  v2 = a1;
  v3 = a2;
  while ( 1 )
  {
	v4 = sce2Texture[((v2 + v3) / 2)].dword_4B4F68;
    v5 = v2;
    v6 = v3;
    do
    {
      v7 = sce2Texture[v5].dword_4B4F68;
      if ( sce2Texture[v5].dword_4B4F68< v4 )
      {
        do
        {
          v8 = sce2Texture[v5+1].dword_4B4F68;//v7[788];
          v7 += 788;
          ++v5;
        }
        while ( v8 < v4 );
      }
      result = sce2Texture[v6].dword_4B4F68;
      if ( v4 < sce2Texture[v6].dword_4B4F68 )
      {
        do
        {
          v10 = sce2Texture[v6-1].dword_4B4F68;
          result -= 3152;
          --v6;
        }
        while ( v4 < v10 );
      }
      if ( v5 > v6 )
        break;
      v11 = v6;
      result = v5;
      v12 = sce2Texture[v5].dword_4B4F68;
      sce2Texture[result].dword_4B4F68 = sce2Texture[v6].dword_4B4F68;
      v13 = sce2Texture[v6].dword_4B4F6C;
	  //TODO FIX se pasa de tama\F1o
     sce2Texture[v11].dword_4B4F68 = v12;
      v14 = sce2Texture[v5++].dword_4B4F6C;
      --v6;
      sce2Texture[result].dword_4B4F6C = v13;
      sce2Texture[v11].dword_4B4F6C = v14;
      v2 = a1;
      v3 = a2;
    }
    while ( v5 < v6 );
    if ( v2 < v6 )
      result = sub_4115C0(v2, v6);
    if ( v5 >= v3 )
      break;
    v2 = v5;
    a1 = v5;
  }
  return result;
}
// 4B4F68: using guessed type int dword_4B4F68[];
// 4B4F6C: using guessed type int dword_4B4F6C[];

//----- (004116D0) --------------------------------------------------------
void draw3dElements_4116D0()
{
  int v0; // ebx@1
  int v1; // edi@2
  int v2; // esi@2
  bool v3; // zf@2
  int v4; // eax@3
  int v5; // ecx@3
  int v6; // eax@4
  int v7; // eax@7
  int v8; // edi@10
  int v9; // esi@10
  int v10; // eax@10
  int v11; // ecx@10
  int v12; // edx@10
  int v13; // ecx@10
  int v14; // edx@10
  int v15; // ebp@10
  int v16; // edx@10
  int v17; // eax@10
  int v18; // ebx@10
  int v19; // ebp@10
  int v20; // ecx@15
  int v21; // eax@20
  int v22; // eax@21
  unsigned int v23; // eax@23
  int v24; // ecx@23
  int v25; // edx@23
  unsigned int v26; // eax@23
  bool v27; // sf@23
  int v28; // edx@23
  int v29; // eax@23
  int v30; // eax@24
  int v31; // edx@26
  int v32; // esi@26
  unsigned int v33; // eax@26
  int v34; // ecx@26
  int v35; // eax@26
  unsigned int v36; // esi@26
  int v37; // ecx@26
  int v38; // eax@26
  int v39; // eax@27
  int v40; // ecx@38
  int v41; // esi@38
  int v42; // edi@38
  int v43; // eax@38
  int v44; // edx@39
  int v45; // ecx@40
  int v46; // edx@43
  int v47; // [sp+0h] [bp-4h]@23

  v0 = trxSCE1Number3DObjects_479D20 - 1;
  dword_4A7A38 = trxSCE1Number3DObjects_479D20 - 1;
  if ( trxSCE1Number3DObjects_479D20 - 1 >= 0 )
  {
    while ( 1 )
    {
		v1 =sce2Texture[v0].dword_4B4F6C;
      v2 = sce2Texture[v0].dword_4B4F6C;
      v3 = sce2Texture[v2].dword_4B4F64 == 1;
      dword_4AA928 = sce2Texture[v0].dword_4B4F6C;
      if ( !v3 )
      {
        v4 = sce2Texture[v2].trxSCE2Bpk_4B4320;
        v5 = 0;
        dword_481BE8 = 0;
        if ( v4 > 0 )
        {
          v6 = 0;//sce2Texture[v2].dword_4B4D0C;
          do
          {
            sce2Texture[v2].dword_4B4D0C[v6] = sce2Texture[v2].dword_4B4328[v6] + (sce2Texture[v2].dword_4B4D04<< 8);
            sce2Texture[v2].dword_4B4E38[v6] = sce2Texture[v2].dword_4B4454[v6] + (sce2Texture[v2].dword_4B4D08 << 8);
			//v6[75] = sce2Texture[v6].dword_4B4454 + (sce2Texture[v2].dword_4B4D08 << 8);
            ++v5;
            ++v6;
          }
          while ( v5 < sce2Texture[v2].trxSCE2Bpk_4B4320);
          dword_481BE8 = v5;
        }
        sub_411530();
        v7 = sce2Texture[v2].numberTriangles_4B4324;
        dword_481BE8 = 0;
        if ( v7 > 0 )
          break;
      }
LABEL_45:
      --v0;
      dword_4A7A38 = v0;
      if ( v0 < 0 )
        return;
    }
    while ( 1 )
    {

		//esto es dificil
      v8 = 788 *v1;
      v9 = v1+ dword_481BE8;
	  v10 =sce2Texture[v1].dword_4B46BC[dword_481BE8];
      v11 = sce2Texture[v1].dword_4B484C[dword_481BE8];
      v12 = sce2Texture[v1].dword_4B4D0C[v11];
      v13 = sce2Texture[v1].dword_4B4E38[v11];
      dword_50351C = v12;
      v14 = sce2Texture[v1].dword_4B49DC[dword_481BE8];
      v15 = sce2Texture[v1].dword_4B4D0C[v14];
      v16 = sce2Texture[v1].dword_4B4E38[v14];
      v17 = v8 + v10;
      v18 = sce2Texture[v1].dword_4B4D0C[v10];
      dword_4A8A80 = v15;
      v19 = sce2Texture[v1].dword_4B4E38[v10];
      dword_4A7A4C = v13;
      dword_46ECE4 = v16;
      dword_50EF20 = v18;
      dword_4A6AD0 = v19;

	  //determina si se ve
      if ( (dword_50351C - v18) * (v16 - v19) - (dword_4A8A80 - v18) * (v13 - v19) <= 0
        && (abs(v18 - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014
         || abs(dword_50351C - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014
         || abs(dword_4A8A80 - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014) )
      {
        if ( abs(v19 - raceEffectiveHalfHeight_44501C) < raceEffectiveHalfHeight_44501C )
        {
          v20 = dword_46ECE4;
        }
        else
        {
          v20 = dword_46ECE4;
          if ( abs(dword_4A7A4C - raceEffectiveHalfHeight_44501C) >= raceEffectiveHalfHeight_44501C && abs(dword_46ECE4 - raceEffectiveHalfHeight_44501C) >= raceEffectiveHalfHeight_44501C )
            goto LABEL_36;
        }
        switch ( sce2Texture[v1].polygonColour_4B4B6C[dword_481BE8*4] )
        {
          case 0x80:
            /*v21 = dword_4B46BC[v9];
            if ( 75 * dword_4B4454[v8 + dword_4B46BC[v9]] >> (54
                                                            * ((unsigned __int16)(100
                                                                                - *(_DWORD *)&dword_4B4328[2 * (v8 + dword_4B46BC[v9])]) >> 8)
                                                            + 8) >= 0 )
              v22 = 75 * dword_4B4454[v8 + v21] >> (54
                                                  * ((unsigned __int16)(100 - *(_DWORD *)&dword_4B4328[2 * (v8 + v21)]) >> 8)
                                                  + 8);
            else
              v22 = -(75 * dword_4B4454[v8 + v21] >> (54 * ((unsigned __int16)(100 - dword_4B4328[2 * (v8 + v21)]) >> 8)
                                                    + 8));
            v47 = v22 & 7;
            v23 = 4 * (v8 + dword_4B484C[v9]);
            v24 = 100 - *(_DWORD *)&dword_4B4328[v23 / 2];
            v25 = 75 * dword_4B4454[v23 / 4] >> (54 * BYTE1(v24) + 8);
            v26 = 4 * (v8 + dword_4B484C[v9]);
            v27 = v25 < 0;
            v28 = *(_DWORD *)&dword_4B4328[v26 / 2];
            v29 = dword_4B4454[v26 / 4];
            if ( v27 )
              v30 = -(75 * v29 >> (54 * ((unsigned __int16)(100 - v28) >> 8) + 8));
            else
              v30 = 75 * v29 >> (54 * ((unsigned __int16)(100 - v28) >> 8) + 8);
            v31 = v30 & 7;
            v32 = dword_4B49DC[v9];
            v33 = 4 * (v8 + v32);
            v34 = 100 - *(_DWORD *)&dword_4B4328[v33 / 2];
            v35 = 75 * dword_4B4454[v33 / 4] >> (54 * BYTE1(v34) + 8);
            v36 = 4 * (v8 + v32);
            v37 = 54 * ((100 - *(_DWORD *)&dword_4B4328[v36 / 2]) >> 8) + 8;
            v27 = v35 < 0;
            v38 = dword_4B4454[v36 / 4];
            if ( v27 )
              v39 = -(75 * v38 >> v37);
            else
              v39 = 75 * v38 >> v37;
            sub_43D050(
              v18 + leftMenuInRaceWidth_456AA0,
              v19,
              v47 + 109,
              leftMenuInRaceWidth_456AA0 + dword_50351C,
              dword_4A7A4C,
              v31 + 109,
              leftMenuInRaceWidth_456AA0 + dword_4A8A80,
              dword_46ECE4,
              (v39 & 7) + 109);*/
            break;
          /*case 0x8A:
            sub_43D050(
              v18 + leftMenuInRaceWidth_456AA0,
              v19,
              dword_467020[75 * dword_4AA928 + dword_4B46BC[v9]] + 108,
              leftMenuInRaceWidth_456AA0 + dword_50351C,
              dword_4A7A4C,
              dword_467020[75 * dword_4AA928 + dword_4B484C[v9]] + 108,
              leftMenuInRaceWidth_456AA0 + dword_4A8A80,
              v20,
              dword_467020[75 * dword_4AA928 + dword_4B49DC[v9]] + 108);
            break;*/
          case 0x81:
            iluminateTriangle_43D530(
              v18 + leftMenuInRaceWidth_456AA0,
              v19,
              leftMenuInRaceWidth_456AA0 + dword_50351C,
              dword_4A7A4C,
              leftMenuInRaceWidth_456AA0 + dword_4A8A80,
              v20,
              (int)&unk_46ED00);
            break;
          case 0x82:
            iluminateTriangle_43D530(
              v18 + leftMenuInRaceWidth_456AA0,
              v19,
              leftMenuInRaceWidth_456AA0 + dword_50351C,
              dword_4A7A4C,
              leftMenuInRaceWidth_456AA0 + dword_4A8A80,
              v20,
              (int)&unk_4A7BC0);
            break;
          case 0x83:
            iluminateTriangle_43D530(
              v18 + leftMenuInRaceWidth_456AA0,
              v19,
              leftMenuInRaceWidth_456AA0 + dword_50351C,
              dword_4A7A4C,
              leftMenuInRaceWidth_456AA0 + dword_4A8A80,
              v20,
              (int)&unk_4AA400);
            break;
          default:
            setTriangleValue_43CD50(
              v18 + leftMenuInRaceWidth_456AA0,
              v19,
              leftMenuInRaceWidth_456AA0 + dword_50351C,
              dword_4A7A4C,
              leftMenuInRaceWidth_456AA0 + dword_4A8A80,
              v20,
              sce2Texture[v1].polygonColour_4B4B6C[dword_481BE8*4]);//polygonColour_4B4B6C[v9 * 4]);
            break;
        }
      }
LABEL_36:
      if ( raceShowTextures_44502C )
      {
        //dword_4A6AFC = dword_46F220[dword_481BE8 + 100 * dword_4AA928];
		dword_4A6AFC = dword_46F220[dword_4AA928][dword_481BE8];
		
		// if(debug) dword_4A6AFC=2;
        if ( dword_4A6AFC != -1 )
        {
          v40 = 11*dword_4A6AFC;
		  v40 = dword_4A6AFC;
          v41 = raceEffectiveHalfWidth_445014;
          v42 = raceEffectiveHalfHeight_44501C;
		  sce4Texture[v40].dword_50A198 = sce4Texture[v40].dword_50A18C - (circuitImageOffsetX_456ABC << 8) - (raceEffectiveHalfWidth_445014 << 8);
          sce4Texture[v40].dword_50A19C = sce4Texture[v40].dword_50A190 - (circuitImageOffsetY_456AC0 << 8) - (v42 << 8);
          sce4Texture[v40].dword_50A198 = v41 + (((sce4Texture[v40].dword_50A198 << 8) / sce4Texture[v40].dword_50A194 + 128) >> 8);
          sce4Texture[v40].dword_50A19C = v42 + (((sce4Texture[v40].dword_50A19C << 8) / sce4Texture[v40].dword_50A194 + 128) >> 8);
          v43 = sce4Texture[v40].tetureWidth_50A180;
		  //determina si se ve en pantalla
          if ( sce4Texture[v40].dword_50A198 > -sce4Texture[v40].tetureWidth_50A180 )
          {
            v44 = sce4Texture[v40].dword_50A19C;
            if ( v44 > -sce4Texture[v40].textureHeight_50A184 )
            {
              v45 = sce4Texture[v40].dword_50A198;
			 // if(debug)v45=0;
              if ( v45 < raceEffectiveWidth_445010 && v44 < raceEffectiveHeight_445018 )
                draw3dTexture_43B2F0(leftMenuInRaceWidth_456AA0 + v45, v44, v43,v40);
            }
          }
        }
      }
	  v46 =sce2Texture[dword_4AA928].numberTriangles_4B4324;
      ++dword_481BE8;
      if ( dword_481BE8 >= v46 )
      {
        v0 = dword_4A7A38;
        goto LABEL_45;
      }
      v1 = dword_4AA928;
    }
  }
}

//----- (00411D10) --------------------------------------------------------
int recalculateCarBoundary_411D10()
{
  int result; // eax@1
  int v1; // edx@1
  int v3; // eax@4
  char *v4; // esi@8
  double v5; // st7@8
  int v6; // eax@8
  signed int v7; // ebx@11
  double v8; // st7@11
  int *v9; // edi@11
  int *v10; // ebp@11
  double v11; // st6@11
  int v12; // ST34_4@12
  float v13; // et1@12
  double v15; // st7@12
  char v16; // c0@12
  int v17; // esi@14
  int v18; // ST34_4@14
  float v19; // et1@14
  double v21; // st7@14
  char v22; // c0@14
  int v23; // eax@16
  int v24; // ST34_4@18
  int v25; // et1@18
  double v27; // st7@18
  char v28; // c0@18
  int v29; // edi@20
  int v30; // ST34_4@20
  int v31; // et1@20
  double v33; // st7@20
  char v34; // c0@20
  int v35; // eax@22
  int v36; // ST34_4@24
  int v37; // et1@24
  double v39; // st7@24
  char v40; // c0@24
  int v41; // edi@26
  int v42; // ST34_4@26
  int v43; // et1@26
  double v45; // st7@26
  char v46; // c0@26
  int v47; // eax@28
  int v48; // ST34_4@30
  int v49; // et1@30
  double v51; // st7@30
  char v52; // c0@30
  int v53; // edi@32
  int v54; // ST34_4@32
  int v55; // et1@32
  double v57; // st7@32
  char v58; // c0@32
  int v59; // eax@34
  unsigned int v60; // eax@36
  int v61; // et1@38
  double v63; // st7@38
//  unsigned __int8 v64; // c0@38
//  unsigned __int8 v65; // c2@38
  int v66; // ebx@46
  int v67; // et1@49
  double v69; // st7@49
  unsigned __int8 v70; // c0@49
  unsigned __int8 v71; // c2@49
  int v72; // et1@52
  double v74; // st7@52
  unsigned __int8 v75; // c0@52
  unsigned __int8 v76; // c2@52
  signed int v77; // ebp@63
  double v78; // st7@63
  int v79; // eax@63
  double v80; // st6@63
  signed int v81; // ebx@64
  signed int v82; // ebp@64
  int *v83; // edi@64
  int v84; // ST38_4@68
  int v85; // et1@68
  double v87; // st7@68
  char v88; // c0@68
  int v89; // ST38_4@70
  int v90; // et1@70
  double v92; // st7@70
  char v93; // c0@70
  int v94; // ST38_4@74
  int v95; // et1@74
  double v97; // st7@74
  char v98; // c0@74
  int v99; // ST38_4@76
  int v100; // et1@76
  double v102; // st7@76
  char v103; // c0@76
  bool v104; // sf@79
  unsigned __int8 v105; // of@79
  int v106; // ebx@82
  int v107; // ST38_4@86
  int v108; // et1@86
  double v110; // st7@86
  char v111; // c0@86
  int v112; // edi@88
  int v113; // ST38_4@88
  int v114; // et1@88
  double v116; // st7@88
  char v117; // c0@88
  int v118; // eax@90
  int v119; // ST38_4@92
  int v120; // et1@92
  double v122; // st7@92
  char v123; // c0@92
  int v124; // edi@94
  int v125; // ST38_4@94
  int v126; // et1@94
  double v128; // st7@94
  char v129; // c0@94
  int v130; // eax@96
  int v131; // ST38_4@98
  int v132; // et1@98
  double v134; // st7@98
  char v135; // c0@98
  int v136; // edi@100
  int v137; // ST38_4@100
  int v138; // et1@100
  double v140; // st7@100
  char v141; // c0@100
  int v142; // eax@102
  int v143; // ST38_4@104
  int v144; // et1@104
  double v146; // st7@104
  char v147; // c0@104
  int v148; // edi@106
  int v149; // ST38_4@106
  int v150; // et1@106
  double v152; // st7@106
  char v153; // c0@106
  int v154; // eax@108
  double v155; // st7@110
  int v156; // ecx@111
  int v157; // eax@111
  signed int v158; // [sp+10h] [bp-30h]@63
  float v159; // [sp+14h] [bp-2Ch]@11
  float v160; // [sp+14h] [bp-2Ch]@63
  float v161; // [sp+18h] [bp-28h]@11
  float v162; // [sp+18h] [bp-28h]@63
  float v163; // [sp+1Ch] [bp-24h]@11
  float v164; // [sp+1Ch] [bp-24h]@63
  float v165; // [sp+20h] [bp-20h]@11
  float v166; // [sp+20h] [bp-20h]@63
  float v167; // [sp+24h] [bp-1Ch]@11
  float v168; // [sp+24h] [bp-1Ch]@63
  float v169; // [sp+28h] [bp-18h]@11
  float v170; // [sp+28h] [bp-18h]@63
  float v171; // [sp+2Ch] [bp-14h]@11
  float v172; // [sp+2Ch] [bp-14h]@63
  float i; // [sp+30h] [bp-10h]@11
  float v174; // [sp+30h] [bp-10h]@40
  float v175; // [sp+30h] [bp-10h]@63
  int v176; // [sp+34h] [bp-Ch]@64

  result = numberOfParticipants_508D24;
  v1 = 0;
  currentDriverSelectedIndex_503518 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    while ( 1 )
    {
      
	  v3 = raceParticipant2[ v1].damageBar_4A6898;
	  //frontLeftAbsoluteYPosition_4A7E14 es 4A7E10
	  raceParticipantIngame[v1].frontLeftAbsoluteXPosition_4A7E10 = sin((raceParticipantIngame[v1].carAngle_4A7DAC + 180.0 - 22.0) * 0.01745329251994444) * 12.0
                               + raceParticipantIngame[v1].absolutePositionX_4A7DB4;
      raceParticipantIngame[v1].frontLeftAbsoluteYPosition_4A7E14 = cos((raceParticipantIngame[v1].carAngle_4A7DAC + 180.0 - 22.0) * 0.01745329251994444) * 9.999995999999999
                               + raceParticipantIngame[v1].absolutePositionY_4A7DB8;
      raceParticipantIngame[v1].frontRightAbsoluteXPosition_4A7E20= sin((raceParticipantIngame[v1].carAngle_4A7DAC + 202.0) * 0.01745329251994444) * 12.0
                               + raceParticipantIngame[v1].absolutePositionX_4A7DB4;
      raceParticipantIngame[v1].frontRightAbsoluteYPosition_4A7E24  = cos((raceParticipantIngame[v1].carAngle_4A7DAC + 202.0) * 0.01745329251994444) * 9.999995999999999
                               + raceParticipantIngame[v1].absolutePositionY_4A7DB8;
      raceParticipantIngame[v1].backLeftAbsoluteXPosition_4A7E30 = sin((raceParticipantIngame[v1].carAngle_4A7DAC - 22.0) * 0.01745329251994444) * 12.0
                               + raceParticipantIngame[v1].absolutePositionX_4A7DB4;
      raceParticipantIngame[v1].backLeftAbsoluteYPosition_4A7E34 = cos((raceParticipantIngame[v1].carAngle_4A7DAC - 22.0) * 0.01745329251994444) * 9.999995999999999
                               + raceParticipantIngame[v1].absolutePositionY_4A7DB8;
      raceParticipantIngame[v1].backRightAbsoluteXPosition_4A7E40 = sin((raceParticipantIngame[v1].carAngle_4A7DAC + 22.0) * 0.01745329251994444) * 12.0
                               + raceParticipantIngame[v1].absolutePositionX_4A7DB4;
	  raceParticipantIngame[v1].backRightAbsoluteYPosition_4A7E44 = cos((raceParticipantIngame[v1].carAngle_4A7DAC + 22.0) * 0.01745329251994444) * 9.999995999999999
                               + raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
      if ( v3 > 0
        && raceParticipantIngame[ v1].carVelocity_4A7DB0 > 0.0
        && raceParticipant2[v1].efectiveEngine_4A6884 * 0.55 > raceParticipantIngame[ v1].carVelocity_4A7DB0
        && raceParticipantIngame[ v1].dword_4A7D20[dword_4A7A20] & IN_RACE_ACELERATE )
      {
        //v4 = raceParticipantIngame[v1].unk_4A7E04;
        v5 = (double)rand() * 0.0000152587890625 + raceParticipantIngame[v1].unk_4A7E04;
        //*(float *)v4 = v5;
        //v2 = 864 * currentDriverSelectedIndex_503518;
        v6 = rand();
        v1 = currentDriverSelectedIndex_503518;
        (raceParticipantIngame[v1].unk_4A7E04) = v5 - (double)v6 * 0.0000152587890625;
      }

      if (  raceParticipantIngame[ v1].dword_4A8054 > 0 && raceParticipant2[userRaceOrder_4A9EA8].useWeapons )
      {
        --raceParticipantIngame[ v1].dword_4A8054;
        v7 = raceParticipantIngame[ v1].carVelocity_4A7DB0;
        v8 = (double)v7;
        v9 = raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18;
        v10 = raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C;
        v11 = raceParticipantIngame[v1].frontLeftAbsoluteXPosition_4A7E10 - raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18;
        dword_481BE8 = 0;
        v159 = v11 / v8;
        v161 = (raceParticipantIngame[v1].frontLeftAbsoluteYPosition_4A7E14 - raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C) / v8;
        v163 = (raceParticipantIngame[v1].frontRightAbsoluteXPosition_4A7E20- raceParticipantIngame[v1].lastFrontRightAbsoluteXPosition_4A7E28) / v8;
		v165 = (raceParticipantIngame[v1].frontRightAbsoluteYPosition_4A7E24 - raceParticipantIngame[v1].lastFrontRightAbsoluteYPosition_4A7E2C) / v8;
        v167 = (raceParticipantIngame[v1].backLeftAbsoluteXPosition_4A7E30 - raceParticipantIngame[v1].lastBackLeftAbsoluteXPosition_4A7E38) / v8;
        v169 = (raceParticipantIngame[v1].backLeftAbsoluteYPosition_4A7E34 - raceParticipantIngame[v1].lastBackLeftAbsoluteYPosition_4A7E3C) / v8;
        v171 = (raceParticipantIngame[v1].backRightAbsoluteXPosition_4A7E40 - raceParticipantIngame[v1].lastBackRightAbsoluteXPosition_4A7E48) / v8;
        for ( i = (raceParticipantIngame[v1].backRightAbsoluteYPosition_4A7E44 - raceParticipantIngame[v1].lastBackRightAbsoluteYPosition_4A7E4C) / v8; dword_481BE8 < v7; ++dword_481BE8 )
        {
          v12 = raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18;//(unsigned __int64)*(float *)v9;
          v13 = raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18;//*(float *)v9;
          v15 = raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18;//*(float *)v9;
		  if(raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C!=0.0)
			  v15 = v15 + 1.0;
         /*TODO FIX esto esta sin inicializar if ( !v16 )
            v15 = v15 + 1.0;*/
          v17 = (unsigned __int64)v15;
          v18 = raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C;//(unsigned __int64)*(float *)v10;
          v19 = raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C;//*(float *)v10;
          v21 = raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C;//*(float *)v10;
          if(raceParticipantIngame[v1].frontRightAbsoluteXPosition_4A7E20!=0.0)
			  v21 = v21 + 1.0;
		  /*TODO FIX esto esta sin inicializarif ( !v22 )
            v21 = v21 + 1.0;*/
          v23 = v17 + circuitWidth_464F40 * (unsigned __int64)v21;
          if ( (*((BYTE *)trxImaBpk_50A16C + v23) & 0xF) == 15 )
          {
            *((BYTE *)circuitMatrixHxW_5034F8 + v23) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v23)];
            *((BYTE *)circuitMatrixHxW_5034F8 + v23 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v23 + 1)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v23) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v23)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v23 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8
                                                                            + circuitWidth_464F40
                                                                            + v23
                                                                            + 1)];
          }
		  v24 = (unsigned __int64)*(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteXPosition_4A7E28;
          v25 = raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteXPosition_4A7E28;
          v27 = *(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteXPosition_4A7E28;
          
		  /*TODO FIX esto esta sin inicializarif ( !v28 )
            v27 = v27 + 1.0;*/
          v29 = (unsigned __int64)v27;
		  v30 = (unsigned __int64)*(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteYPosition_4A7E2C;
		  v31 = raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteYPosition_4A7E2C;
		  v33 = *(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteYPosition_4A7E2C;
          /*TODO FIX esto esta sin inicializarif ( !v34 )
            v33 = v33 + 1.0;*/
          v35 = v29 + circuitWidth_464F40 * (unsigned __int64)v33;
          if ( (*((BYTE *)trxImaBpk_50A16C + v35) & 0xF) == 15 )
          {
            *((BYTE *)circuitMatrixHxW_5034F8 + v35) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v35)];
            *((BYTE *)circuitMatrixHxW_5034F8 + v35 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v35 + 1)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v35) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v35)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v35 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8
                                                                            + circuitWidth_464F40
                                                                            + v35
                                                                            + 1)];
          }
		  v36 = (unsigned __int64)*(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteXPosition_4A7E38;
          v37 = raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteXPosition_4A7E38;
          v39 = *(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteXPosition_4A7E38;
          /*TODO FIX esto esta sin inicializarif ( !v40 )
            v39 = v39 + 1.0;*/
          v41 = (unsigned __int64)v39;
		  v42 = (unsigned __int64)*(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteYPosition_4A7E3C;
		  v43 =raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteYPosition_4A7E3C;
		  v45 = *(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteYPosition_4A7E3C;
          /*TODO FIX esto esta sin inicializarif ( !v46 )
            v45 = v45 + 1.0;*/
          v47 = v41 + circuitWidth_464F40 * (unsigned __int64)v45;
          if ( (*((BYTE *)trxImaBpk_50A16C + v47) & 0xF) == 15 )
          {
            *((BYTE *)circuitMatrixHxW_5034F8 + v47) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v47)];
            *((BYTE *)circuitMatrixHxW_5034F8 + v47 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v47 + 1)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v47) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v47)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v47 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8
                                                                            + circuitWidth_464F40
                                                                            + v47
                                                                            + 1)];
          }
		  v48 = (unsigned __int64)*(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteXPosition_4A7E48;
		  v49 = raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteXPosition_4A7E48;
		  v51 = *(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteXPosition_4A7E48;
          /*TODO FIX esto esta sin inicializarif ( !v52 )
            v51 = v51 + 1.0;*/
          v53 = (unsigned __int64)v51;
		  v54 = (unsigned __int64)*(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteYPosition_4A7E4C;
		  v55 = raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteYPosition_4A7E4C;
		  v57 = *(float *)&raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteYPosition_4A7E4C;
          /*TODO FIX esto esta sin inicializarif ( !v58 )
            v57 = v57 + 1.0;*/
          v59 = v53 + circuitWidth_464F40 * (unsigned __int64)v57;
          if ( (*((BYTE *)trxImaBpk_50A16C + v59) & 0xF) == 15 )
          {
            *((BYTE *)circuitMatrixHxW_5034F8 + v59) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v59)];
            *((BYTE *)circuitMatrixHxW_5034F8 + v59 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + v59 + 1)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v59) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v59)];
            *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v59 + 1) = trxBLOTab_479D40[*((BYTE *)circuitMatrixHxW_5034F8
                                                                            + circuitWidth_464F40
                                                                            + v59
                                                                            + 1)];
          }
          v60 = 864 * currentDriverSelectedIndex_503518;
		  (raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontLeftAbsoluteXPosition_4A7E18) = v159 + raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontLeftAbsoluteXPosition_4A7E18;
		  v9 = raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontLeftAbsoluteXPosition_4A7E18;
		  (raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontLeftAbsoluteYPosition_4A7E1C) = v161 + (raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontLeftAbsoluteYPosition_4A7E1C);
		  v10 = &raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontLeftAbsoluteYPosition_4A7E1C;
          (raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteXPosition_4A7E28) = v163 + (raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteXPosition_4A7E28);
		  (raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteYPosition_4A7E2C) = v165 + (raceParticipantIngame[currentDriverSelectedIndex_503518].lastFrontRightAbsoluteYPosition_4A7E2C);
          (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteXPosition_4A7E38) = v167 + (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteXPosition_4A7E38);
		  (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteYPosition_4A7E3C) = v169 + (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackLeftAbsoluteYPosition_4A7E3C);
		  (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteXPosition_4A7E48) = v171 + (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteXPosition_4A7E48);
		  (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteYPosition_4A7E4C) = i + (raceParticipantIngame[currentDriverSelectedIndex_503518].lastBackRightAbsoluteYPosition_4A7E4C);
        }
      }
      else
      {
        v61 = raceParticipantIngame[ v1].dword_4A7DBC;
        v63 = (raceParticipantIngame[ v1].dword_4A7DBC);
		if(raceParticipantIngame[ v1].dword_4A7DC0!=0.0 |  raceParticipantIngame[ v1].dword_4A7DC4!=0.0)
			v63 =-v63;
       //TODO FIX esto esta sin inicializar if ( v64 | v65 )      v63 = -v63;
		v174 = (double)(raceParticipant2[v1].carType + 13);
        if ( v63 > v174
          || raceParticipantIngame[ v1].carVelocity_4A7DB0 > 0.0 && raceParticipantIngame[ v1].dword_4A7D20[dword_4A7A20] & IN_RACE_BRAKE
          || raceParticipantIngame[ v1].carVelocity_4A7DB0 > 0.0
          && raceParticipant2[v1].efectiveEngine_4A6884 * 0.55 > raceParticipantIngame[ v1].carVelocity_4A7DB0
          && raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] & IN_RACE_ACELERATE )
        {
          v66 = raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20];
          if ( !(v66 & IN_RACE_BRAKE) || !(v66 & IN_RACE_MINE) )
          {
            if ( currentDriverSelectedIndex_503518 == userRaceOrder_4A9EA8 )
            {
              v67 = raceParticipantIngame[ v1].dword_4A7DBC;
              v69 = (raceParticipantIngame[ v1].dword_4A7DBC);
              //if ( v70 | v71 )

			  if(raceParticipantIngame[ v1].dword_4A7DC0!=0.0 |  raceParticipantIngame[ v1].dword_4A7DC4!=0.0)
				v69 = -v69;
              if ( v69 > v174 )
              {
                v72 = raceParticipantIngame[ v1].dword_4A7DBC;
                v74 = (raceParticipantIngame[ v1].dword_4A7DBC);
                //if ( v75 | v76 )
				 if(raceParticipantIngame[ v1].dword_4A7DC0!=0.0 |  raceParticipantIngame[ v1].dword_4A7DC4!=0.0)
			
                  v74 = -v74;
                dword_4AA92C = (unsigned __int64)(v74 * 2048.0);
              }
              if ( dword_4AA92C > 0x10000 )
                dword_4AA92C = 0x10000;
              if ( raceParticipantIngame[ v1].carVelocity_4A7DB0 > 0.0 && v66 & 2
                || raceParticipantIngame[ v1].carVelocity_4A7DB0 > 0.0
                && raceParticipant2[v1].efectiveEngine_4A6884 * 0.85 >raceParticipantIngame[ v1].carVelocity_4A7DB0
                && v66 & 1 )
                dword_4AA92C = 0x10000;
            }
            v77 = raceParticipantIngame[ v1].carVelocity_4A7DB0;
            v158 = v77;
            v78 = (double)v77;
            v79 = raceParticipantIngame[v1].dword_4A804C + 1;
            v160 = (raceParticipantIngame[v1].frontLeftAbsoluteXPosition_4A7E10 - (raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18)) / v78;
            v162 = (raceParticipantIngame[v1].frontLeftAbsoluteYPosition_4A7E14 - (raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C)) / v78;
            v164 = (raceParticipantIngame[v1].frontRightAbsoluteXPosition_4A7E20 -(raceParticipantIngame[v1].lastFrontRightAbsoluteXPosition_4A7E28)) / v78;
            v166 = (raceParticipantIngame[v1].frontRightAbsoluteYPosition_4A7E24- (raceParticipantIngame[v1].lastFrontRightAbsoluteYPosition_4A7E2C)) / v78;
            v168 = (raceParticipantIngame[v1].backLeftAbsoluteXPosition_4A7E30 - (raceParticipantIngame[v1].lastBackLeftAbsoluteXPosition_4A7E38)) / v78;
            v170 = (raceParticipantIngame[v1].backLeftAbsoluteYPosition_4A7E34 - (raceParticipantIngame[v1].lastBackLeftAbsoluteYPosition_4A7E3C)) / v78;
            v172 = ((raceParticipantIngame[v1].backRightAbsoluteXPosition_4A7E40) - (raceParticipantIngame[v1].lastBackRightAbsoluteXPosition_4A7E48)) / v78;
            v80 = (raceParticipantIngame[v1].backRightAbsoluteYPosition_4A7E44) - (raceParticipantIngame[v1].lastBackRightAbsoluteYPosition_4A7E4C);
            raceParticipantIngame[v1].dword_4A804C = v79;
            v175 = v80 / v78;
            if ( v79 == 6 )
            {
              v81 = 0;
              v176 = 0;
              v82 = 0;
              v83 = &dword_4A7EE4[v1 / 4];
              do
              {
                if ( v82 || v81 )
                  break;
                if ( !*v83 )
                {
                  *v83 = 1;
                  v84 = (raceParticipantIngame[v1].backLeftAbsoluteXPosition_4A7E30);
                  v85 = (raceParticipantIngame[v1].backLeftAbsoluteXPosition_4A7E30);
                  v87 = (raceParticipantIngame[v1].backLeftAbsoluteXPosition_4A7E30);
                  if ( !v87 )
                    v87 = v87 + 1.0;
                  v83[30] = (unsigned __int64)v87;
                  v89 = (raceParticipantIngame[v1].backLeftAbsoluteYPosition_4A7E34);
                  v90 = (raceParticipantIngame[v1].backLeftAbsoluteYPosition_4A7E34);
                  v92 = (raceParticipantIngame[v1].backLeftAbsoluteYPosition_4A7E34);
                  if ( !v92 )
                    v92 = v92 + 1.0;
                  v83[60] = (unsigned __int64)v92;
                  v82 = 1;
                }
                if ( !v83[15] )
                {
                  v83[15] = 1;
                  v94 = (raceParticipantIngame[v1].backRightAbsoluteXPosition_4A7E40);
                  v95 = (raceParticipantIngame[v1].backRightAbsoluteXPosition_4A7E40);
                  v97 =(raceParticipantIngame[v1].backRightAbsoluteXPosition_4A7E40);
                  //if ( !v98 )
				  if ( !v97 )                  
                    v97 = v97 + 1.0;
                  v83[45] = (unsigned __int64)v97;
                  v99 = (raceParticipantIngame[v1].backRightAbsoluteYPosition_4A7E44);
                  v100 =(raceParticipantIngame[v1].backRightAbsoluteYPosition_4A7E44);
                  v102 = (raceParticipantIngame[v1].backRightAbsoluteYPosition_4A7E44);
                  //if ( !v103 )
				  if ( !v102 )
                  
                    v102 = v102 + 1.0;
                  v83[75] = (unsigned __int64)v102;
                  v81 = 1;
                }
                ++v83;
                v105 = __OFSUB__(v176 + 1, 15);
                v104 = v176++ - 14 < 0;
              }
              while ( v104 ^ v105 );
              v77 = v158;
              raceParticipantIngame[v1].dword_4A804C = 0;
            }
            dword_481BE8 = 0;
            if ( v77 > 0 )
            {
              v106 = currentDriverSelectedIndex_503518;
              do
              {
                if ( raceParticipantIngame[ v1].carVelocity_4A7DB0 < 0.0
                  || raceParticipant2[v106].efectiveEngine_4A6884 * 0.85 <raceParticipantIngame[ v1].carVelocity_4A7DB0
                  || !(raceParticipantIngame[ currentDriverSelectedIndex_503518].dword_4A7D20[dword_4A7A20] & IN_RACE_ACELERATE))//acelerar )
                {
                  v107 =(raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18);
                  v108 = (raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18);
                  v110 = (raceParticipantIngame[v1].lastFrontLeftAbsoluteXPosition_4A7E18);
                  if ( !v110 )
                    v110 = v110 + 1.0;
                  v112 = (unsigned __int64)v110;
                  v113 = (raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C);
                  v114 = (raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C);
                  v116 =(raceParticipantIngame[v1].lastFrontLeftAbsoluteYPosition_4A7E1C);
                  if ( !v116 )
                    v116 = v116 + 1.0;
                  v118 = v112 + circuitWidth_464F40 * (unsigned __int64)v116;
                  if ( (*((BYTE *)trxImaBpk_50A16C + v118) & 0xF) == 15 )
                  {
                    *((BYTE *)circuitMatrixHxW_5034F8 + v118) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v118)];
                    *((BYTE *)circuitMatrixHxW_5034F8 + v118 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v118 + 1)];
                    *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v118) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                                 + circuitWidth_464F40
                                                                                 + v118)];
                    *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v118 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                                     + circuitWidth_464F40
                                                                                     + v118
                                                                                     + 1)];
                    v106 = currentDriverSelectedIndex_503518;
                  }
                  v119 = raceParticipantIngame[106].lastFrontRightAbsoluteXPosition_4A7E28;
                  v120 = raceParticipantIngame[106].lastFrontRightAbsoluteXPosition_4A7E28;
                  v122 = raceParticipantIngame[106].lastFrontRightAbsoluteXPosition_4A7E28;
                  if ( !v122 )
                    v122 = v122 + 1.0;
                  v124 = (unsigned __int64)v122;
                  v125 = raceParticipantIngame[v106].lastFrontRightAbsoluteYPosition_4A7E2C;
                  v126 = raceParticipantIngame[v106].lastFrontRightAbsoluteYPosition_4A7E2C;
                  v128 = raceParticipantIngame[v106].lastFrontRightAbsoluteYPosition_4A7E2C;
                  if ( !v128 )
                    v128 = v128 + 1.0;
                  v130 = v124 + circuitWidth_464F40 * (unsigned __int64)v128;
                  if ( (*((BYTE *)trxImaBpk_50A16C + v130) & 0xF) == 15 )
                  {
                    *((BYTE *)circuitMatrixHxW_5034F8 + v130) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v130)];
                    *((BYTE *)circuitMatrixHxW_5034F8 + v130 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v130 + 1)];
                    *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v130) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                                 + circuitWidth_464F40
                                                                                 + v130)];
                    *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v130 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                                     + circuitWidth_464F40
                                                                                     + v130
                                                                                     + 1)];
                    v106 = currentDriverSelectedIndex_503518;
                  }
                }
                v131 = raceParticipantIngame[v106].lastBackLeftAbsoluteXPosition_4A7E38;
                v132 = raceParticipantIngame[v106].lastBackLeftAbsoluteXPosition_4A7E38;
                v134 = raceParticipantIngame[v106].lastBackLeftAbsoluteXPosition_4A7E38;
                if ( !v134 )
                  v134 = v134 + 1.0;
                v136 = (unsigned __int64)v134;
                v137 = raceParticipantIngame[v106].lastBackLeftAbsoluteYPosition_4A7E3C;
                v138 = raceParticipantIngame[v106].lastBackLeftAbsoluteYPosition_4A7E3C;
                v140 = raceParticipantIngame[v106].lastBackLeftAbsoluteYPosition_4A7E3C;
                if ( !v140 )
                  v140 = v140 + 1.0;
                v142 = v136 + circuitWidth_464F40 * (unsigned __int64)v140;
                if ( (*((BYTE *)trxImaBpk_50A16C + v142) & 0xF) == 15 )
                {
                  *((BYTE *)circuitMatrixHxW_5034F8 + v142) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v142)];
                  *((BYTE *)circuitMatrixHxW_5034F8 + v142 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v142 + 1)];
                  *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v142) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                               + circuitWidth_464F40
                                                                               + v142)];
                  *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v142 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                                   + circuitWidth_464F40
                                                                                   + v142
                                                                                   + 1)];
                  v106 = currentDriverSelectedIndex_503518;
                }
                v143 = raceParticipantIngame[v106].lastBackRightAbsoluteXPosition_4A7E48;
                v144 = raceParticipantIngame[v106].lastBackRightAbsoluteXPosition_4A7E48;
                v146 = raceParticipantIngame[v106].lastBackRightAbsoluteXPosition_4A7E48;
                if ( !v146 )
                  v146 = v146 + 1.0;
                v148 = (unsigned __int64)v146;
                v149 = raceParticipantIngame[v106].lastBackRightAbsoluteYPosition_4A7E4C;
                v150 = raceParticipantIngame[v106].lastBackRightAbsoluteYPosition_4A7E4C;
                v152 = raceParticipantIngame[v106].lastBackRightAbsoluteYPosition_4A7E4C;
                if ( !v152 )
                  v152 = v152 + 1.0;
                v154 = v148 + circuitWidth_464F40 * (unsigned __int64)v152;
                if ( (*((BYTE *)trxImaBpk_50A16C + v154) & 0xF) == 15 )
                {
                  *((BYTE *)circuitMatrixHxW_5034F8 + v154) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v154)];
                  *((BYTE *)circuitMatrixHxW_5034F8 + v154 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8 + v154 + 1)];
                  *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v154) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                               + circuitWidth_464F40
                                                                               + v154)];
                  *((BYTE *)circuitMatrixHxW_5034F8 + circuitWidth_464F40 + v154 + 1) = trxSKITab_501AA0[*((BYTE *)circuitMatrixHxW_5034F8
                                                                                   + circuitWidth_464F40
                                                                                   + v154
                                                                                   + 1)];
                  v106 = currentDriverSelectedIndex_503518;
                }
                //v2 = 864 * v106;
                v105 = __OFSUB__(dword_481BE8 + 1, v77);
                v104 = dword_481BE8 + 1 - v77 < 0;
                v155 = v160 + raceParticipantIngame[106].lastFrontLeftAbsoluteXPosition_4A7E18;
                ++dword_481BE8;
                (raceParticipantIngame[v106].lastFrontLeftAbsoluteXPosition_4A7E18) = v155;
                (raceParticipantIngame[v106].lastFrontLeftAbsoluteYPosition_4A7E1C) = v162 + raceParticipantIngame[v106].lastFrontLeftAbsoluteYPosition_4A7E1C;
                (raceParticipantIngame[v106].lastFrontRightAbsoluteXPosition_4A7E28) = v164 + raceParticipantIngame[v106].lastFrontRightAbsoluteXPosition_4A7E28;
                (raceParticipantIngame[v106].lastFrontRightAbsoluteYPosition_4A7E2C) = v166 + raceParticipantIngame[v106].lastFrontRightAbsoluteYPosition_4A7E2C;
                (raceParticipantIngame[v106].lastBackLeftAbsoluteXPosition_4A7E38) = v168 + raceParticipantIngame[v106].lastBackLeftAbsoluteXPosition_4A7E38;
                (raceParticipantIngame[v106].lastBackLeftAbsoluteYPosition_4A7E3C) = v170 + raceParticipantIngame[v106].lastBackLeftAbsoluteYPosition_4A7E3C;
                (raceParticipantIngame[v106].lastBackRightAbsoluteXPosition_4A7E48) = v172 +raceParticipantIngame[v106].lastBackRightAbsoluteXPosition_4A7E48;
                (raceParticipantIngame[v106].lastBackRightAbsoluteYPosition_4A7E4C) = v175 + raceParticipantIngame[v106].lastBackRightAbsoluteYPosition_4A7E4C;
              }
              while ( v104 ^ v105 );
            }
          }
        }
      }
      v156 = currentDriverSelectedIndex_503518;
      v157 = 216 * currentDriverSelectedIndex_503518;
      raceParticipantIngame[v156].lastFrontLeftAbsoluteXPosition_4A7E18 = raceParticipantIngame[v156].frontLeftAbsoluteXPosition_4A7E10;
      raceParticipantIngame[v156].lastFrontLeftAbsoluteYPosition_4A7E1C = raceParticipantIngame[v156].frontLeftAbsoluteYPosition_4A7E14;
      raceParticipantIngame[v156].lastFrontRightAbsoluteXPosition_4A7E28 = raceParticipantIngame[v156].frontRightAbsoluteXPosition_4A7E20;
      raceParticipantIngame[v156].lastFrontRightAbsoluteYPosition_4A7E2C = raceParticipantIngame[v156].frontRightAbsoluteYPosition_4A7E24;
      raceParticipantIngame[v156].lastBackLeftAbsoluteXPosition_4A7E38 = raceParticipantIngame[v156].backLeftAbsoluteXPosition_4A7E30;
      raceParticipantIngame[v156].lastBackLeftAbsoluteYPosition_4A7E3C = raceParticipantIngame[v156].backLeftAbsoluteYPosition_4A7E34;
      raceParticipantIngame[v156].lastBackRightAbsoluteXPosition_4A7E48 = raceParticipantIngame[v156].backRightAbsoluteXPosition_4A7E40;
      raceParticipantIngame[v156].lastBackRightAbsoluteYPosition_4A7E4C = raceParticipantIngame[v156].backRightAbsoluteYPosition_4A7E44;
      result = numberOfParticipants_508D24;
      currentDriverSelectedIndex_503518 = v156 + 1;
      if ( v156 + 1 >= numberOfParticipants_508D24 )
        break;
      v1 = currentDriverSelectedIndex_503518;
    }
  }
  return result;
}

//----- (00412DF0) --------------------------------------------------------
int checkVaiZones_412DF0()
{
  int v0; // ebp@1
  int v1; // esi@1
  void *v2; // ebx@2
  int v3; // ebp@2
  unsigned int v4; // esi@3
  int v5; // edi@3
  int v6; // edi@11
  int v7; // ecx@12
  int v8; // esi@13
  int v9; // eax@13
  char v10; // bl@19
  int v11; // edx@22
  unsigned int v12; // eax@23
  int v13; // eax@29
  int v14; // eax@44
  bool v15; // zf@45
  int v16; // edx@51
  int v17; // esi@51
  int v18; // eax@52
  int result; // eax@63

  v0 = numberOfParticipants_508D24;
  v1 = 0;
  currentDriverSelectedIndex_503518 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    v2 = trxVaiBpk_5034D0;
    v3 = circuitVaiBpk_width_4A6858;
    do
    {
      v4 = 864 * v1;
      v5 = raceParticipantIngame[v1].actualVaiZone_4A7D00 + 1;
      if ( *((BYTE *)v2
           + v3 * (raceParticipantIngame[v1].frontLeftAbsoluteYPosition_4A7E14 >> 2)
           + (raceParticipantIngame[v1].frontLeftAbsoluteXPosition_4A7E10 >> 2)) == v5
        || *((BYTE *)v2
           + circuitVaiBpk_width_4A6858 * (raceParticipantIngame[v1].frontRightAbsoluteYPosition_4A7E24  >> 2)
           + (raceParticipantIngame[v1].frontRightAbsoluteXPosition_4A7E20>> 2)) == v5 )
        ++raceParticipantIngame[v1].actualVaiZone_4A7D00;
      v3 = circuitVaiBpk_width_4A6858;
       if ( *((BYTE *)v2
           + circuitVaiBpk_width_4A6858 * ((signed int)(unsigned __int64)raceParticipantIngame[v1].absolutePositionY_4A7DB8 >> 2)
           + ((signed int)(unsigned __int64)raceParticipantIngame[v1].absolutePositionX_4A7DB4 >> 2)) == circuitVaiZones_4A685C
        && raceParticipantIngame[v1].actualVaiZone_4A7D00 < circuitVaiZones_4A685C )
        raceParticipantIngame[v1].actualVaiZone_4A7D00 = 0;
      v1 = currentDriverSelectedIndex_503518++ + 1;
    }
    while ( currentDriverSelectedIndex_503518 < numberOfParticipants_508D24 );
    v0 = numberOfParticipants_508D24;
  }
  v6 = 0;
  v7=0; //indice drivers
  v9=0;//indice drives
  //comprobamos posiciones con las vai zones y actualizamos
  if ( v0 > 0 )
  {
    do
    {
      v8 = 0;
	  v9 = 0;
      do
      {
        if ( !raceParticipantIngame[v9].hasFinishedTheRace_4A7E0C
          && v8 != v6
          && raceParticipantIngame[v7].actualVaiZone_4A7D00 > raceParticipantIngame[v9].actualVaiZone_4A7D00
          && raceParticipantIngame[v7].currentLap_4A7E08 >= raceParticipantIngame[v9].currentLap_4A7E08
          &&  raceParticipantIngame[v7].racePosition_4A7E09 >  raceParticipantIngame[v9].racePosition_4A7E09 )
        {
          v10 = raceParticipantIngame[v7].racePosition_4A7E09;
          raceParticipantIngame[v7].racePosition_4A7E09 = raceParticipantIngame[v9].racePosition_4A7E09;
          raceParticipantIngame[v9].racePosition_4A7E09 = v10;
        }
        ++v8;
        v9 += 1;
      }
      while ( v8 < v0 );
      ++v6;
      v7 += 1;
    }
    while ( v6 < v0 );
  }
  v11 = 0;
  for ( currentDriverSelectedIndex_503518 = 0; v11 < v0; currentDriverSelectedIndex_503518 = v11 )
  {
    if ( raceParticipantIngame[v11].actualVaiZone_4A7D00 == circuitVaiZones_4A685C )
    {
      if ( isRaceFinish_456AC8 )
      {
        raceParticipantIngame[v11].hasFinishedTheRace_4A7E0C= 1;
        raceParticipant2[v11].efectiveEngine_4A6884 = 0;
      }
      else
      {
        ++raceParticipantIngame[v11].currentLap_4A7E08;
        if ( v11 == userRaceOrder_4A9EA8 )
        {
          if ( (unsigned __int8)raceParticipantIngame[v11].currentLap_4A7E08 == numberOfLaps )
          {
            loadMenuSoundEffect(2u, GEN_EFE_FINAL_LAP, 0, 0x10000, 327680);
            v11 = currentDriverSelectedIndex_503518;
            v0 = numberOfParticipants_508D24;
            isLapRecord_456AE4 = 210;
          }
          v13 = currentLapMilliseconds_45FC1C + 100 * (currentLapSeconds_463CD4 + 60 * currentLapMinutes_45EA64);
          if ( v13 < currentRaceBestLapMilliseconds_461FEC + 100 * (currentRaceBestLapSeconds_45EB48 + 60 * currentRaceBestLapMinutes_463CAC)
            || !currentRaceBestLapMinutes_463CAC && !currentRaceBestLapSeconds_45EB48 && !currentRaceBestLapMilliseconds_461FEC )
          {
            currentRaceBestLapMinutes_463CAC = currentLapMinutes_45EA64;
            currentRaceBestLapSeconds_45EB48 = currentLapSeconds_463CD4;
            currentRaceBestLapMilliseconds_461FEC = currentLapMilliseconds_45FC1C;
          }
          if ( v13 >= circuitRecordMilliseconds_4A9B8C + 100 * (circuitRecordSeconds_501260 + 60 * circuitRecordMinutes_50A160)
            && (circuitRecordMinutes_50A160 || circuitRecordSeconds_501260 || circuitRecordMilliseconds_4A9B8C) )
          {
            isLapRecord_456AE4 = 0;
          }
          else
          {
            if ( strcmp(raceFilePrefix_45EA50,"TR0")!=0 && !isLapRecord_456AE4 )
			//if (BYTE2(raceFilePrefix_45EA50[0]) != 48 && !isLapRecord_456AE4)
				
            {
				//SOUND_LAP_RECORD
              loadMenuSoundEffect(2u, 4, 0, 0x10000, 327680);
              v11 = currentDriverSelectedIndex_503518;
              v0 = numberOfParticipants_508D24;
            }
            circuitRecordMinutes_50A160 = currentLapMinutes_45EA64;
            circuitRecordSeconds_501260 = currentLapSeconds_463CD4;
            circuitRecordMilliseconds_4A9B8C = currentLapMilliseconds_45FC1C;
          }
          lastCompletedLapTime_503224 = currentLapTime_481E0C;
          ticksToPauseLapTimeInHud_4A9EB0 = 210;
          currentLapMilliseconds_45FC1C = 0;
          currentLapSeconds_463CD4 = 0;
          currentLapMinutes_45EA64 = 0;
          currentLapTime_481E0C = 0;
        }
      }
      raceParticipantIngame[v11].actualVaiZone_4A7D00 = 0;
      if ( (unsigned __int8)raceParticipantIngame[v11].currentLap_4A7E08 > numberOfLaps )
      {
        raceParticipantIngame[v11].currentLap_4A7E08 = numberOfLaps;
        v15 = v11 == userRaceOrder_4A9EA8;
        raceParticipantIngame[v11].hasFinishedTheRace_4A7E0C= 1;
        if ( v15 )
        {
          ticksToPauseLapTimeInHud_4A9EB0 = 9999;
          raceParticipantIngame[v11].mushroomPendingTime_4A8050 = 0;
        }
        raceParticipant2[v11].efectiveEngine_4A6884 = 0;
        isRaceFinish_456AC8 = 1;
        if ( !memcmp(raceParticipant[v11].name, &dukeNukemName, 0xBu) && raceParticipantIngame[v11].racePosition_4A7E09 == 1 )
        {
          loadMenuSoundEffect(2u, GEN_EFE_HAIL_TO_THE_KING, 0, 0x10000, 327680);
          v11 = currentDriverSelectedIndex_503518;
          v0 = numberOfParticipants_508D24;
        }
      }
    }
    ++v11;
  }
  v16 = 0;
  v17 = 0;
  currentDriverSelectedIndex_503518 = 0;
  
  //calculo para saber si estas doblado
  if ( v0 > 0 )
  {
    v18 =0;
    do
    {
		if (  raceParticipantIngame[v18].actualVaiZone_4A7D00 + circuitVaiZones_4A685C * raceParticipantIngame[v18].currentLap_4A7E08 > v17 && v16 != userRaceOrder_4A9EA8 )
        v17 = raceParticipantIngame[v18].actualVaiZone_4A7D00 + circuitVaiZones_4A685C * raceParticipantIngame[v18].currentLap_4A7E08;
      ++v16;
      v18 += 1;
    }
    while ( v16 < v0 );
    currentDriverSelectedIndex_503518 = v16;
  }
  if ( v17 > raceParticipantIngame[userRaceOrder_4A9EA8].actualVaiZone_4A7D00 + circuitVaiZones_4A685C * ((unsigned __int8)raceParticipantIngame[userRaceOrder_4A9EA8].currentLap_4A7E08 + 1)
    && !lapped_456BC0
    && raceParticipant2[0].carType != 6
    && !isMultiplayerGame )
  {
    lapped_456BC0 = 1;
	//SOUND_LAPPED
    loadMenuSoundEffect(2u, 22, 0, 0x10000, 327680);
  }
  result = 864 * userRaceOrder_4A9EA8;
  if ( v17 < raceParticipantIngame[userRaceOrder_4A9EA8].actualVaiZone_4A7D00 + circuitVaiZones_4A685C * ((unsigned __int8)raceParticipantIngame[userRaceOrder_4A9EA8].currentLap_4A7E08 + 1)
    && lapped_456BC0 == 1
    && raceParticipant2[0].carType != 6 )
  {
    result = isMultiplayerGame;
    if ( !isMultiplayerGame )
      lapped_456BC0 = 0;
  }
  return result;
}

//----- (00413300) --------------------------------------------------------
void refreshRacePositions_413300()
{
  int v0; // ebp@1
  int v1; // esi@1
  int v2; // edi@2
  int v3; // ecx@2
  int v4; // eax@5
  char v5; // dl@7

  v0 = numberOfParticipants_508D24;
  v1 = 0;
  currentDriverSelectedIndex_503518 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    v2 = userRaceOrder_4A9EA8;
   // v3 = (int)racePosition_4A7E09;
	v3= 0;//raceParticipantIngame[0].racePosition_4A7E09;
    do
    {
		//if ( v1 != v2 && !*(_DWORD *)(v3 + 3) )
		if ( v1 != v2 && !raceParticipantIngame[v3].hasFinishedTheRace_4A7E0C )
      {
        //v4 = 864 * v2;
        if ( !raceParticipantIngame[v2].hasFinishedTheRace_4A7E0C && (unsigned __int8)raceParticipantIngame[v2].racePosition_4A7E09< raceParticipantIngame[v3].racePosition_4A7E09 )
        {
          v5 = raceParticipantIngame[v3].racePosition_4A7E09;
          raceParticipantIngame[v3].racePosition_4A7E09 = raceParticipantIngame[v2].racePosition_4A7E09;
          raceParticipantIngame[v2].racePosition_4A7E09= v5;
        }
      }
      ++v1;
	  v3 += 1;
      //v3 += 864;
    }
    while ( v1 < v0 );
    currentDriverSelectedIndex_503518 = v1;
  }
}

//----- (00413380) --------------------------------------------------------
int recalculateRacePositions_413380()
{
  int v0; // ebx@1
  int v1; // ebp@1
  int v2; // edi@2
  int v3; // ecx@3
  int v4; // eax@3
  int v5; // esi@3
  char v6; // dl@8
  int result; // eax@12
  int indexParticipant; // ebp@12
  bool v9; // zf@14
  bool v10; // sf@14
  signed int v11; // edx@15
  int v12; // ecx@15
  signed int v13; // edx@23
  int v14; // ecx@23
  int i; // ecx@33
  int v16; // esi@34
  char v17; // dl@34
  int v18; // [sp+10h] [bp-8h]@2
  int v19; // [sp+14h] [bp-4h]@2
  int v20; // [sp+14h] [bp-4h]@13

  v0 = numberOfParticipants_508D24;
  v1 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
   // v2 = (int)racePosition_4A7E09;//raceParticipantIngame[0]racePosition_4A7E09;
	v2 = 0; ;
   // v19 = (int)racePosition_4A7E09;
	v19 = raceParticipantIngame[0].racePosition_4A7E09;
	v18 = 0;//(int)raceParticipant2[0].damageBar_4A6898;
	//ordenacion burbuja
    do
    {
      v3 = 0;
     // v4 = (int)racePosition_4A7E09;
	  v4= 0;
	  v5 = 0; 
      do
      {
        if ( v3 != v1 )
        {
          if ( raceParticipantIngame[v2].racePosition_4A7E09 > raceParticipantIngame[v4].racePosition_4A7E09 && raceParticipant2[v18].damageBar_4A6898 > 0 && raceParticipant2[v5].damageBar_4A6898 <= 0 )
          {
            v6 =  raceParticipantIngame[v2].racePosition_4A7E09  ;
            raceParticipantIngame[v2].racePosition_4A7E09  =  raceParticipantIngame[v19].racePosition_4A7E09 ;
            raceParticipantIngame[v19].racePosition_4A7E09  =  raceParticipantIngame[v4].racePosition_4A7E09 ;
             raceParticipantIngame[v4].racePosition_4A7E09  =  v6 ;
          }
          v0 = numberOfParticipants_508D24;
        }
        ++v3;
        v5 += 1;
        v4 += 1;
      }
      while ( v3 < v0 );
      ++v1;
      v2 += 1;
      v18 += 1;
      v19 = v2;
    }
    while ( v1 < v0 );
  }
  result = dword_479684;
  indexParticipant = 0;
  currentDriverSelectedIndex_503518 = 0;
  if ( v0 > 0 )
  {
	  v20 = 0;// (int)raceParticipant2[0].damageBar_4A6898;
    do
    {
      v9 = raceParticipant2[v20].damageBar_4A6898 == 0;
      v10 = raceParticipant2[v20].damageBar_4A6898 < 0;
      if ( !raceParticipant2[v20].damageBar_4A6898 )
      {
        v11 = 0;
        v12 = 0;
        if ( result <= 0 )
          goto LABEL_37;
        do
        {
          if ( dword_4A7CE0[v12] == indexParticipant )
            v11 = 1;
          ++v12;
        }
        while ( v12 < result );
        if ( !v11 )
LABEL_37:
          dword_4A7CE0[result++] = indexParticipant;
        v9 = 1;
        v10 = 0;
      }
      if ( !v10 && !v9 )
      {
        v13 = -1;
        v14 = 0;
        if ( result > 0 )
        {
          do
          {
            if ( dword_4A7CE0[v14] == indexParticipant )
              v13 = v14;
            ++v14;
          }
          while ( v14 < result );
          if ( v13 != -1 )
          {
            --result;
            if ( v13 < result )
              memcpy((void *)(dword_4A7CE0[v13]), (const void *)(dword_4A7CE0[1+v13]), 4 * (result - v13));
            dword_4A7CE0[result] = -1;
          }
        }
      }
      ++indexParticipant;
      v20 += 1;
    }
    while ( indexParticipant < v0 );
    currentDriverSelectedIndex_503518 = indexParticipant;
    dword_479684 = result;
  }
  for ( i = 0; i < result; raceParticipantIngame[v16].racePosition_4A7E09 = v17 )
  {
    v16 = dword_4A7CE0[i];
    v17 = v0 - i++;
  }
  return result;
}

//----- (00413500) --------------------------------------------------------
int sub_413500()
{
  int result; // eax@1
  int v1; // ebx@2
  signed int v2; // edx@3
  int v3; // esi@3
  BYTE *v4; // eax@4
  int v5; // ecx@5
  int v6; // ebp@9
  int v7; // edi@10
  int v8; // ebp@14
  unsigned __int64 v9; // rax@14
  int v10; // eax@14
  int *v11; // eax@16
  char v12; // [sp+4h] [bp-4h]@9

  result = raceFrame_481E14;
  if ( raceFrame_481E14 > 190 )
  {
    result = numberOfParticipants_508D24;
    v1 = 0;
    for ( currentDriverSelectedIndex_503518 = 0; v1 < numberOfParticipants_508D24; currentDriverSelectedIndex_503518 = v1 )
    {
      v2 = 0;
      v3 = 0;
    /*  if ( dword_503510 > 0 )
      {
        v4 = &dword_4A7D20[ v1];
        do
        {
          v5 = *(_DWORD *)v4;
          if ( *(_DWORD *)v4 & IN_RACE_BRAKE && v5 & IN_RACE_MINE ) //atras y lanzar mina
          {
            v2 = 1;
            *(_DWORD *)v4 = v5 & 0xBD;
          }
          ++v3;
          v4 += 4;
        }
        while ( v3 < dword_503510 );
      }*/
      v6 = raceParticipant2[v1].carType;
      v12 = (v6 > 1) + 33;
      if ( v2 != 1 || (v7 = 216 * v1, raceParticipantIngame[v1].hasFinishedTheRace_4A7E0C) )
      {
        v11 = &dword_4A8058[216 * v1];
        if ( *v11 == 1 )
        {
          *v11 = 0;
          stopSoundChannel_43C3E0(v1 + 11);
          goto LABEL_18;
        }
      }
      else if ( !dword_4A8058[v7] )
      {
        dword_4A8058[v7] = 1;
        if ( v1 == userRaceOrder_4A9EA8 )
        {
          loadMenuSoundEffect(v1 + 11, (v6 > 1) + 33, 0, 0x10000, (v1 + 33) << 12);
LABEL_18:
          v1 = currentDriverSelectedIndex_503518;
          goto LABEL_19;
        }
        v8 = (unsigned __int64)(*(float *)&raceParticipantIngame[ v1].absolutePositionX_4A7DB4 - *(float *)&raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4);
        v9 = (unsigned __int64)(*(float *)&raceParticipantIngame[ v1].absolutePositionY_4A7DB8 - *(float *)&raceParticipantIngame[ userRaceOrder_4A9EA8].absolutePositionY_4A7DB8);
		//calcula la distancia entre coches
        v10 = 38144 - 88 * (unsigned __int64)sqrt((double)(v8 * v8 + (signed int)v9 * (signed int)v9));
        if ( v10 > 0 ) //si la distancia es menor que 433
        {
          loadMenuSoundEffect(v1 + 11, v12, 0, v10, (v1 + 33) << 12);
          goto LABEL_18;
        }
      }
LABEL_19:
      result = numberOfParticipants_508D24;
      ++v1;
    }
  }
  return result;
}

//----- (004136C0) --------------------------------------------------------
signed int checkPokes_4136C0()
{
  char v0; // al@1
  int v1; // esi@1
  char v2; // dl@2
  char v3; // dl@2
  char v4; // dl@2
  char v5; // dl@2
  char v6; // dl@2
  char v7; // bl@2
  char v8; // cl@2
  bool v9; // zf@2
  char v10; // dl@2
  signed int result; // eax@30

  v0 = eventDetected();
  v1 = userRaceOrder_4A9EA8;
  if ( !v0 )
    goto LABEL_30;
  v2 = byte_4A9EC2;
  byte_4A9EC0 = byte_4A9EC1;
  byte_4A9EC2 = byte_4A9EC3;
  byte_4A9EC1 = v2;
  v3 = byte_4A9EC4;
  byte_4A9EC4 = byte_4A9EC5;
  byte_4A9EC3 = v3;
  v4 = byte_4A9EC6;
  byte_4A9EC6 = byte_4A9EC7;
  byte_4A9EC5 = v4;
  v5 = byte_4A9EC8;
  byte_4A9EC8 = byte_4A9EC9;
  byte_4A9EC7 = v5;
  v6 = byte_4A9ECA;
  v7 = byte_4A9ECE;
  byte_4A9ECA = byte_4A9ECB;
  v8 = byte_4A9ECC;
  v9 = byte_4A9ECC == 32;
  byte_4A9EC9 = v6;
  v10 = byte_4A9ECD;
  byte_4A9ECB = byte_4A9ECC;
  byte_4A9ECC = byte_4A9ECD;
  byte_4A9ECD = byte_4A9ECE;
  byte_4A9ECE = v0;
  if ( v9 && v10 == 19 && v7 == 22 && v0 == 34 )// todo lo de trucos drug y demas
   raceParticipantIngame[userRaceOrder_4A9EA8].mushroomPendingTime_4A8050= 999999;

  if ( byte_4A9ECA != 32 || v8 != 19 )
  {
    if ( v8 == 32 && v10 == 19 && byte_4A9ECD == 22 && v0 == 48 )
      goto LABEL_18;
  }
  else if ( v10 == 23 && byte_4A9ECD == 49 && v0 == 37 )
  {
    raceParticipant2[v1].rocket = 1;
  }
  if ( isDemo_456B10 )
LABEL_18:
    pokeDamageSelected_456AB0 = 1;
  if ( byte_4A9ECA != 32 || v8 != 19 )
  {
    if ( v8 == 32 && v10 == 19 && byte_4A9ECD == 30 && v0 == 34 )
      pokeTurboSelected_456AB8 = 1;
  }
  else if ( v10 == 18 && byte_4A9ECD == 30 && v0 == 32 )
  {
    pokeWeaponsSelected_456AB4 = 1;
  }
LABEL_30:
  result = 102400;
  if ( pokeDamageSelected_456AB0 )
	  raceParticipant2[ v1].damageBar_4A6898 = 102400;
  if ( pokeWeaponsSelected_456AB4 )
    raceParticipant2[v1].weaponsBar_4A68B0 = 102400;
  if ( pokeTurboSelected_456AB8 )
	  raceParticipant2[ v1].turboBar_4A68B4 = 102400;
  return result;
}

//----- (004138A0) --------------------------------------------------------
void sub_4138A0()
{
  char v0; // bl@1
  int v1; // edx@45
  int v2; // eax@45
  int v3; // ecx@45
  int v4; // edx@45
  int v5; // eax@45
  int v6; // ecx@45
  int v7; // edx@45
  int v8; // eax@47
  int v9; // ecx@47
  int v10; // eax@51
  int v11; // ecx@51
  int *v12; // ecx@71
  int v13; // eax@71
  bool v14; // sf@71

  v0 = 0;
  if ( isMultiplayerGame)// && dword_45E0A8 == 2 )
    nullsub_1();
  if ( dword_4A6AD4 )
  {
    ++dword_5034F4;
  }
  else
  {
    if (configuration.accelerateKey == 200 && keysRead_45E0C0[KEY_UP] )
      v0 = IN_RACE_ACELERATE;
    if (configuration.brakeKey == 208 && keysRead_45E0C0[KEY_DOWN] )
      v0 |= IN_RACE_BRAKE;
    if (configuration.leftSteeringKey == 203 && keysRead_45E0C0[KEY_LEFT] )
      v0 |= IN_RACE_LEFT;
    if (configuration.rightSteeringKey == 205 && keysRead_45E0C0[KEY_RIGHT] )
      v0 |= IN_RACE_RIGHT;
    if ( byte_45E188 )
      v0 |= IN_RACE_ACELERATE;
    if ( keysRead_45E0C0[KEY_UP] )
      v0 |= IN_RACE_ACELERATE;
    if ( keysRead_45E0C0[configuration.accelerateKey] )
      v0 |= IN_RACE_ACELERATE;
    if ( byte_45E190 )
      v0 |= IN_RACE_BRAKE;
    if ( keysRead_45E0C0[KEY_DOWN] )
      v0 |= IN_RACE_BRAKE;
    if ( keysRead_45E0C0[configuration.brakeKey] )
      v0 |= IN_RACE_BRAKE;
    if ( keysRead_45E0C0[configuration.leftSteeringKey] )
      v0 |= IN_RACE_LEFT;
    if ( keysRead_45E0C0[configuration.rightSteeringKey] )
      v0 |= IN_RACE_RIGHT;
    if ( keysRead_45E0C0[configuration.turboKey] )
      v0 |= IN_RACE_TURBO;
    if ( keysRead_45E0C0[configuration.gunKey] )
      v0 |= IN_RACE_GUN;
    if ( keysRead_45E0C0[configuration.mineKey] )
    {
      v0 |= IN_RACE_MINE;
      keysRead_45E0C0[configuration.mineKey] = 0;
    }
    if ( v0 & IN_RACE_BRAKE && v0 & IN_RACE_MINE )
		v0 &= IN_RACE_BRAKE_MINE;
    if ( keysRead_45E0C0[configuration.hornKey] )
		v0 |= IN_RACE_HORN;
    if ( configuration.useJoystick > 0 )
    {
      v1 = (unsigned __int8)configuration.defaultLeftSteeringGamepad;
      v2 = (unsigned __int8)configuration.defaultBrakeGamepad;
      byte_463E00[(unsigned __int8)configuration.defaultRightSteeringGamepad] = 0;
      v3 = (unsigned __int8)byte_44512A;
      byte_463E00[v1] = 0;
      v4 = (unsigned __int8)configuration.defaultMineGamepad;
      byte_463E00[v2] = 0;
      v5 = (unsigned __int8)configuration.defaultGunGamepad;
      byte_463E00[v3] = 0;
      v6 = (unsigned __int8)configuration.defaultTurboGamepad;
      byte_463E00[v4] = 0;
      v7 = (unsigned __int8)configuration.defaultAccelerateGamepad;
      byte_463E00[v5] = 0;
      byte_463E00[v6] = 0;
      byte_463E00[v7] = 0;
      if ( !SDLCheckJoystick() )
        configuration.useJoystick = 0;
      v8 = joystick_x_axis_default_4AA3E0;
      v9 = joystick_x_axis_4A7A44;
      if ( joystick_x_axis_4A7A44 < joystick_x_axis_default_4AA3E0 - 50 )
        byte_463E00[(unsigned __int8)configuration.defaultLeftSteeringGamepad] = 1;
      if ( v9 > v8 + 50 )
        byte_463E00[(unsigned __int8)configuration.defaultRightSteeringGamepad] = 1;
      v10 = joystick_y_axis_default_4A9EA0;
      v11 = joystick_y_axis_4A9EB8;
      if ( joystick_y_axis_4A9EB8 < joystick_y_axis_default_4A9EA0 - 50 )
        byte_463E00[(unsigned __int8)byte_44512A] = 1;
      if ( v11 > v10 + 50 )
        byte_463E00[(unsigned __int8)configuration.defaultBrakeGamepad] = 1;
      if ( byte_463E00[configuration.accelerateGamepad] )
        v0 |= IN_RACE_ACELERATE;
      if ( byte_463E00[configuration.brakeGamepad] )
        v0 |= IN_RACE_BRAKE;
      if ( byte_463E00[configuration.leftSteeringGamepad] )
        v0 |= IN_RACE_LEFT;
      if ( byte_463E00[configuration.rightSteeringGamepad] )
		  v0 |= IN_RACE_RIGHT;
      if ( byte_463E00[configuration.turboGamepad] )
        v0 |= IN_RACE_TURBO;
      if ( byte_463E00[configuration.gunGamepad] )
        v0 |= IN_RACE_GUN;
      if ( byte_463E00[configuration.mineGamepad] )
      {
        v0 |= IN_RACE_MINE;
        keysRead_45E0C0[configuration.mineKey] = 0;
      }
    }
    if ( v0 & IN_RACE_TURBO )
		v0 |= IN_RACE_ACELERATE;

	//userRaceOrder_4A9EA8 = 0; ///TODO FIX porque no tiene porque ser 0
    v12 = &raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadIndex_4A7DA0;
	
	if(v0==IN_RACE_MINE){
		  debug=1;
		  }
   raceParticipantIngame[userRaceOrder_4A9EA8].lastKeysRead_4A7D60[raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadIndex_4A7DA0] = (unsigned __int8)v0;///tecla leida
    v13 = *v12 + 1;
    v14 = *v12 - 14 < 0;
    *v12 = v13;
    if ( !((unsigned __int8)(v14 ^ __OFSUB__(v13, 15)) | (v13 == 15)) )
      *v12 = 0;
    if ( isMultiplayerGame )
    {
      if ( dword_4A7CF4 )
      {
        nullsub_1();
        if ( dword_50E540 )
          nullsub_1();
      }
    }
    ++dword_4A9EAC;
    if ( dword_4A9EAC >= 15 )
      dword_4A9EAC = 0;
    ++dword_503500;
  }
}

//----- (00413C90) --------------------------------------------------------
int  drawSmallLeftBar_413C90(int a1)
{
  int v1; // eax@1
  int v2; // ecx@1
  signed int v3; // edi@1
  signed int v4; // esi@2
  char v5; // dl@3
  char v6; // dl@5
  int v7; // eax@5
  int v8; // ecx@5
  char v9; // dl@7
  int v10; // eax@7
  int v11; // ecx@7
  char v12; // dl@9
  int v13; // eax@9
  int v14; // ecx@9
  unsigned __int64 v15; // rax@13
  unsigned __int64 v16; // rax@16
  int v17; // esi@18
  signed int v18; // edi@19
  double v19; // st7@26
  int v20; // eax@26
  int v21; // esi@26
  int result; // eax@34

  v1 = 0;
  v2 = 96;
  v3 = 32;
  do
  {
    v4 = 16;
    do
    {
      v5 = smallbarBpk_50E720[v1];
      if ( v5 )
      {
        a1 = dword_464F14;
        *(BYTE *)(dword_464F14 + v2) = v5;
      }
      v6 = smallbarBpk_50E720[v1+1];
      v7 = v1 + 1;
      v8 = v2 + 1;
      if ( v6 )
      {
        a1 = dword_464F14;
        *(BYTE *)(dword_464F14 + v8) = v6;
      }
      v9 = smallbarBpk_50E720[v7];
      v10 = v7 + 1;
      v11 = v8 + 1;
      if ( v9 )
      {
        a1 = dword_464F14;
        *(BYTE *)(dword_464F14 + v11) = v9;
      }
      v12 = smallbarBpk_50E720[v10];
      v13 = v10 + 1;
      v14 = v11 + 1;
      if ( v12 )
      {
        a1 = dword_464F14;
        *(BYTE *)(dword_464F14 + v14) = v12;
      }
      v1 = v13 + 1;
      v2 = v14 + 1;
      --v4;
    }
    while ( v4 );
    v2 += 448;
    --v3;
  }
  while ( v3 );
  v15 = (unsigned __int64)((double)raceParticipant2[ userRaceOrder_4A9EA8].turboBar_4A68B4 * 0.000556640625);
  if ( (v15 & 0x80000000) != 0 )
    LOBYTE(v15) = 0;
  drawTurboBar_43B3A0((unsigned __int8)v15 + dword_464F14 + 3684, 58 - (unsigned __int8)v15, 7, 0);
  if ( raceParticipant2[userRaceOrder_4A9EA8].useWeapons )
  {
	  v16 = (unsigned __int64)((double)raceParticipant2[userRaceOrder_4A9EA8].weaponsBar_4A68B0 * 0.000537109375);
    if ( (v16 & 0x80000000) != 0 )
      LOBYTE(v16) = 0;
    drawWeaponsBar_43BEF0(a1, (void *)((unsigned __int8)v16 + dword_464F14 + 9828), 55 - (unsigned __int8)v16, 3, 0);
    v17 = 0;
    if ( raceParticipant2[userRaceOrder_4A9EA8].mines > 0 )
    {
      v18 = 6752;
      do
      {
        drawImageInRace_43B240((int)sidebom1Bpk_481E04, 8, 6, v18 + dword_464F14);
        ++v17;
        v18 += 8;
      }
      while ( v17 < raceParticipant2[userRaceOrder_4A9EA8].mines );
    }
  }
  else if ( ticksToPauseLapTimeInHud_4A9EB0 <= 0 )//si no usas weapons ponemos el tiempo vale 0 si no has terminado la vuelta
  {
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, currentLapTime_481E0C / 70 / 60, 16, 8315, -6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, currentLapTime_481E0C / 70 % 60, 16, 8329, 6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42), 16, 8343, 6, 0);
  }
  else
  {
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 / 60, 16, 8315, -6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 % 60, 16, 8329, 6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(lastCompletedLapTime_503224 % 70) * 1.42), 16, 8343, 6, 0);
    ticksToPauseLapTimeInHud_4A9EB0 -= dword_4A9EA4;
    if ( ticksToPauseLapTimeInHud_4A9EB0 < 0 )
      ticksToPauseLapTimeInHud_4A9EB0 = 0;
  }
  v19 = 100.0 - ceil((double)raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 * 0.0009765625);
  v20 = drawSprite_402590((int)&bugnum6Bpk_46E560, 8, 10, (unsigned __int64)v19, 0, 11408, -8, -16);
 //TODO FIX drawImageInRace_43B240((int)&unk_46E880, 8, 10, v20 + dword_464F14);
  v21 = userRaceOrder_4A9EA8;
  if ( raceParticipant2[userRaceOrder_4A9EA8].damageBar_4A6898 < 20480 )
  {
    if ( !criticalDamageSoundPlayed_456ADC )
    {
		//SOUND_CRIT_DAMAGE
      loadMenuSoundEffect(2u, 1, 0, 0x10000, 327680);
      v21 = userRaceOrder_4A9EA8;
    }
    criticalDamageSoundPlayed_456ADC = 1;
  }
  if ( raceParticipant2[ v21].damageBar_4A6898 < 10240 )
  {
    if ( !criticalDamage2SoundPlayed_456AE0 )
    {
		//SOUND_CRIT_DAMAGE
      loadMenuSoundEffect(2u, 1, 0, 0x10000, 327680);
      v21 = userRaceOrder_4A9EA8;
    }
    criticalDamage2SoundPlayed_456AE0 = 1;
  }
  result = raceParticipant2[ v21].damageBar_4A6898;
  if ( !result )
  {
    result = 0;
	//si es duke nukem
    if ( !memcmp(raceParticipant[v21].name, &dukeNukemName, 0xBu) )
    {
      result = dukeNukemEndRaceSoundPlayed_456AE8;
	  if (!dukeNukemEndRaceSoundPlayed_456AE8)
	  {

		  //SOUND_THIS_SUCKS
		  result = loadMenuSoundEffect(2u, 32, 0, 0x10000, 327680);
	  }
      dukeNukemEndRaceSoundPlayed_456AE8 = 1;
    }
  }
  return result;
}

//----- (00414110) --------------------------------------------------------
int  drawSmallLeftBar_414110(int a1)
{
  int v1; // ST00_4@1

  dword_4A9EA4 = dword_503500 - dword_4A7CFC;
  v1 = (dword_503500 - dword_4A7CFC) << 16;
  dword_4A7CFC = dword_503500;
  dword_4AA500 = colorToPaletteEntry(v1, 0x20000);
  if ( raceFrame_481E14 > 190 && !raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C )
  {
    totalRaceTime_50A164 += dword_4A9EA4;
    currentLapTime_481E0C += dword_4A9EA4;
    totalRaceMinutes_45EEC0 = totalRaceTime_50A164 / 70 / 60;
    totalRaceSeconds_45EEBC = totalRaceTime_50A164 / 70 % 60;
    totalRaceMilliseconds_462D74 = (unsigned __int64)((double)(totalRaceTime_50A164 % 70) * 1.42);
    currentLapMinutes_45EA64 = currentLapTime_481E0C / 70 / 60;
    currentLapSeconds_463CD4 = currentLapTime_481E0C / 70 % 60;
    currentLapMilliseconds_45FC1C = (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42);
  }
  if ( ticksToPauseLapTimeInHud_4A9EB0 > 0 )
  {
    ticksToPauseLapTimeInHud_4A9EB0 -= dword_4A9EA4;
    if ( ticksToPauseLapTimeInHud_4A9EB0 < 0 )
      ticksToPauseLapTimeInHud_4A9EB0 = 0;
  }
  return drawSmallLeftBar_413C90(a1);
}

//----- (00414220) --------------------------------------------------------
int drawLeftRaceBar_414220()
{
  int v0; // ST3C_4@1
  char v1; // bl@1
  int v2; // edi@6
  const void *v3; // esi@6
  int v4; // eax@8
  int v5; // edi@8
  int v6; // esi@9
  int v7; // eax@13
  int v8; // esi@14
  signed int v9; // edx@15
  int i; // eax@16
  int v11; // ebp@20
  signed int v12; // esi@20
  signed int v13; // edi@21
  signed int v14; // eax@23
  signed int v15; // esi@23
  signed int v16; // edi@24
  unsigned __int64 v17; // rax@27
  int v18; // ebp@27
  unsigned __int64 v19; // rax@31
  int v20; // ebp@31
  unsigned __int64 v21; // rax@35
  int v22; // ebp@35
  signed int v23; // esi@38
  signed int v24; // edi@39
  int v25; // edx@41
  int v26; // eax@41
  signed int v27; // esi@41
  int v28; // edx@42
  int v29; // edi@42
  bool v30; // zf@42
  bool v31; // sf@42
  unsigned __int8 v32; // of@42
  int v33; // ecx@45
  int v34; // eax@45
  int v35; // eax@46
  int v36; // eax@47
  int v37; // ecx@47
  int v38; // edi@47
  int v39; // eax@47
  int v40; // eax@49
  int v41; // ecx@49
  int v42; // edi@49
  int v43; // eax@49
  signed int v44; // esi@52
  signed int v45; // edi@53
  int v46; // eax@55
  int v47; // esi@55
  int v48; // edx@55
  int v49; // ecx@55
  double v50; // st7@55
  unsigned __int64 v51; // rax@55
  signed int v52; // ecx@55
  signed int v53; // esi@58
  unsigned __int64 v54; // rax@62
  int v55; // esi@64
  signed int v56; // edi@65
  signed int v57; // edx@71
  unsigned __int64 v58; // rax@72
  unsigned __int64 v59; // rax@74
  int v60; // eax@74
  int v61; // eax@74
  unsigned __int64 v62; // rax@87
  int result; // eax@89
  int v64; // esi@89
  int v65; // edi@90
  signed int v66; // [sp+18h] [bp-4h]@27
  signed int v67; // [sp+18h] [bp-4h]@31
  signed int v68; // [sp+18h] [bp-4h]@35
  signed int aux;
  dword_4A9EA4 = dword_503500 - dword_4A7CFC;
  v0 = (dword_503500 - dword_4A7CFC) << 16;
  dword_4A7CFC = dword_503500;
  dword_4AA500 = colorToPaletteEntry(v0, 0x20000);
  v1 = 0;
  if ( raceFrame_481E14 > 190 && !raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C )
  {
    totalRaceTime_50A164 += dword_4A9EA4;
    currentLapTime_481E0C += dword_4A9EA4;
    totalRaceMinutes_45EEC0 = totalRaceTime_50A164 / 70 / 60;
    totalRaceSeconds_45EEBC = totalRaceTime_50A164 / 70 % 60;
    totalRaceMilliseconds_462D74 = (unsigned __int64)((double)(totalRaceTime_50A164 % 70) * 1.42);
    currentLapMinutes_45EA64 = currentLapTime_481E0C / 70 / 60;
    currentLapSeconds_463CD4 = currentLapTime_481E0C / 70 % 60;
    currentLapMilliseconds_45FC1C = (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42);
  }
  if ( leftMenuInRaceWidth_456AA0 < 64 )
    drawSmallLeftBar_413C90(0);
  v2 = 0;

  v3 = boardsBPK_4AA940[0];
  aux = 0;
  do
  {
    copyBuffer2Screen((void *)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
    v3 = (char *)v3 + 64;
	aux +=64;
    v2 += 512;
  }
  while ( (signed int)aux < 6700 );

  v3 = boardsBPK_4AA940[1];

  aux = 0;
  do
  {
    copyBuffer2Screen((void *)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
    v3 = (char *)v3 + 64;
	aux +=1;
    v2 += 512;
  }
  while ( (signed int)aux < 32 );

  v3 = boardsBPK_4AA940[2];
  aux = 0;
  do
  {
    copyBuffer2Screen((void *)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
    v3 = (char *)v3 + 64;
	aux +=1;
    v2 += 512;
  }
  while ( (signed int)aux < 32 );
  v3 = boardsBPK_4AA940[3];
  aux = 0;
  do
  {
    copyBuffer2Screen((void *)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
    v3 = (char *)v3 + 64;
	aux +=1;
    v2 += 512;
  }
  while ( (signed int)aux < 32 );
  //while ( (signed int)v3 < (signed int)&unk_4ADB40 );
  
  
  v4 = numberOfParticipants_508D24;
  v5 = 0;
  
  //pinta la bandera de llegada sobre el partipante
  if ( numberOfParticipants_508D24 > 0 )
  {
    v6 = 0;
    do
    {
      if ( raceParticipantIngame[participantRaceOrderUserFirst_508D44[v5]].hasFinishedTheRace_4A7E0C )
      {
        drawImageInRace_43B240((int)goalnum2Bpk_4AA50C, 22, 28, v6 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 39972);
        v4 = numberOfParticipants_508D24;
      }
      ++v5;
      v6 += 0x4000;
    }
    while ( v5 < v4 );
  }
  v7 = v4 - 1;
  if ( v7 < 3 )
  {
    v8 = 32 * v7;
    do
    {
      v9 = 0;
      do
      {
        for ( i = v9 % 2; i < 64; i += 2 )
          *(BYTE *)(leftMenuInRaceWidth_456AA0 + ((v8 + v9) << 9) + dword_464F14 + i + 53280) = 0;
        ++v9;
      }
      while ( v9 < 32 );
      v8 += 32;
    }
    while ( v8 < 96 );
  }
  drawImageInRace_43B240((int)((char *)&bugnum6Bpk_46E560 + 80 * numberOfLaps), 8, 10, dword_464F14 + leftMenuInRaceWidth_456AA0 + 46133);
  v11 = 1;
  v12 = 1;
  if ( numberOfParticipants_508D24 > 1 )
  {
    v13 = 0x4000;
    do
    {
      drawImageInRace_43B240((int)((char *)&bugnum6Bpk_46E560 + 80 * numberOfLaps), 8, 10, v13 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 46138);
      ++v12;
      v13 += 0x4000;
    }
    while ( v12 < numberOfParticipants_508D24 );
  }
  drawImageInRace_43B240(
    (int)((char *)&bugnum6Bpk_46E560 + 80 * (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[0]].currentLap_4A7E08),
    8,
    10,
    dword_464F14 + leftMenuInRaceWidth_456AA0 + 46114);
  v14 = numberOfParticipants_508D24;
  v15 = 1;
  if ( numberOfParticipants_508D24 > 1 )
  {
    v16 = 0x4000;
    do
    {
      drawImageInRace_43B240(
		  (int)((char *)&bugnum6Bpk_46E560 + 80 * (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[v15]].currentLap_4A7E08),8,10, v16 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 46116);
      v14 = numberOfParticipants_508D24;
      ++v15;
      v16 += 0x4000;
    }
    while ( v15 < numberOfParticipants_508D24 );
    if ( numberOfParticipants_508D24 > 1 )
    {
		v17 = (unsigned __int64)(64.0 - ceil((double)raceParticipant2[ participantRaceOrderUserFirst_508D44[1]].damageBar_4A6898 * 0.0009765625) * 0.6369426751592356);
      HIDWORD(v17) = -(signed int)v17;
      v18 = -(signed int)v17;
      v66 = 9;
      do
      {
        memcpy((void *)(v18 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 53344), (char *)damslidBpk + HIDWORD(v17) + 64, v17);
        HIDWORD(v17) += 64;
        v18 += 512;
        --v66;
      }
      while ( v66 );
      v14 = numberOfParticipants_508D24;
      v11 = 1;
      v1 = 0;
    }
  }
  if ( v14 > 2 )
  {
	  v19 = (unsigned __int64)(64.0 - ceil((double)raceParticipant2[ participantRaceOrderUserFirst_508D44[2]].damageBar_4A6898 * 0.0009765625) * 0.6369426751592356);
    HIDWORD(v19) = -(signed int)v19;
    v20 = -(signed int)v19;
    v67 = 9;
    do
    {
      memcpy((void *)(v20 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 69728), (char *)damslidBpk + HIDWORD(v19) + 64, v19);
      HIDWORD(v19) += 64;
      v20 += 512;
      --v67;
    }
    while ( v67 );
    v14 = numberOfParticipants_508D24;
    v1 = 0;
    v11 = 1;
  }
  if ( v14 > 3 )
  {
	  v21 = (unsigned __int64)(64.0 - ceil((double)raceParticipant2[participantRaceOrderUserFirst_508D44[3]].damageBar_4A6898 * 0.0009765625) * 0.6369426751592356);//dword_508D50->3 y los de arriba 2 y 1
    HIDWORD(v21) = -(signed int)v21;
    v22 = -(signed int)v21;
    v68 = 9;
    do
    {
      memcpy((void *)(v22 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 86112), (char *)damslidBpk + HIDWORD(v21) + 64, v21);
      HIDWORD(v21) += 64;
      v22 += 512;
      --v68;
    }
    while ( v68 );
    v11 = 1;
    v1 = 0;
  }
  writeTextInRace_402510(leftMenuInRaceWidth_456AA0 + 1059, raceParticipant2[participantRaceOrderUserFirst_508D44[0]].name);
  v23 = 1;
  if ( numberOfParticipants_508D24 > 1 )
  {
    v24 = 0x4000;
    do
    {
      writeTextInRace_402510(v24 + leftMenuInRaceWidth_456AA0 + 37923, raceParticipant2[participantRaceOrderUserFirst_508D44[v23++]].name);
      v24 += 0x4000;
    }
    while ( v23 < numberOfParticipants_508D24 );
  }
  v25 = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[1]].racePosition_4A7E09;
  racePositionTemp_481BD0[0] = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[0]].racePosition_4A7E09;
  racePositionTemp_481BD0[1] = v25;
  v26 = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[3]].racePosition_4A7E09;
  racePositionTemp_481BD0[2] = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[2]].racePosition_4A7E09;
  racePositionTemp_481BD0[3] = v26;
  v27 = 0;
  do
  {
    v28 = racePositionTemp_481BD0[v27];
    v29 = racePositionUserFirst_46E8D0[v27];
    v32 = __OFSUB__(v28, v29);
    v30 = v28 == v29;
    v31 = v28 - v29 < 0;
    if ( v28 < v29 )
    {
      dword_4A8A90[v27] = 458752 * v29 - 458752;
      dword_4AA3F0[v27] = 7 * v28 - 7;
      v1 = 0;
      dword_4A7CC0[v27] = (v28 - v29) << 16;
      v32 = __OFSUB__(v28, v29);
      v30 = v28 == v29;
      v31 = v28 - v29 < 0;
    }
    if ( !((unsigned __int8)(v31 ^ v32) | v30) )
    {
      v33 = racePositionUserFirst_46E8D0[v27];
      v34 = racePositionTemp_481BD0[v27];
      dword_4A8A90[v27] = 458752 * racePositionUserFirst_46E8D0[v27] - 458752;
      dword_4AA3F0[v27] = 7 * v34 - 7;
      dword_4A7CC0[v27] = (v34 - v33) << 16;
    }
    v35 = dword_4A7CC0[v27];
    if ( (signed int)((v35 + 0x8000) & 0xFFFF0000) <= 0 )
    {
      v40 = convertColorToPaletteColor(v35, dword_4AA500);
      v41 = dword_4AA3F0[v27];
      v42 = v40 + dword_4A8A90[v27];
      v43 = (v40 + dword_4A8A90[v27] + 0x8000) >> 16;
      dword_4A8A90[v27] = v42;
      if ( v43 < v41 )
        dword_4A8A90[v27] = 458752 * racePositionTemp_481BD0[v27] - 458752;
    }
    else
    {
      v36 = convertColorToPaletteColor(v35, dword_4AA500);
      v37 = dword_4AA3F0[v27];
      v38 = v36 + dword_4A8A90[v27];
      v39 = (v36 + dword_4A8A90[v27] + 0x8000) >> 16;
      dword_4A8A90[v27] = v38;
      if ( v39 > v37 )
        dword_4A8A90[v27] = 458752 * racePositionTemp_481BD0[v27] - 458752;
    }
    ++v27;
  }
  while ( v27 < 4 );
  //;;;;;aqui falla y en principio esta todo bien
  drawInRaceImageToBuffer_43B160(
    (int)((char *)&ownnum1Bpk_503520 + 1024 * ((dword_4A8A90[0] + 0x8000) >> 16)),
    32,
    32,
    dword_464F14 + leftMenuInRaceWidth_456AA0 + 36928);
  v44 = 1;
  if ( numberOfParticipants_508D24 > 1 )
  {
    v45 = 0x4000;
    do
    {
      drawInRaceImageToBuffer_43B160(
        (int)((char *)&othnum1Bpk_50B2C0 + 576 * ((dword_4A8A90[v44++] + 0x8000) >> 16)),///parece la posicion
        24,
        24,
        v45 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 41032);
      v45 += 0x4000;
    }
    while ( v44 < numberOfParticipants_508D24 );
  }
  v46 = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[1]].racePosition_4A7E09;//raceposition1
  v47 = userRaceOrder_4A9EA8;
  racePositionUserFirst_46E8D0[0] = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[0]].racePosition_4A7E09;//raceposition2
  v48 = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[2]].racePosition_4A7E09;//raceposition3
  racePositionUserFirst_46E8D0[1] = v46;
  v49 = (unsigned __int8)raceParticipantIngame[ participantRaceOrderUserFirst_508D44[3]].racePosition_4A7E09 ;//raceposition4
  racePositionUserFirst_46E8D0[2] = v48;
  v50 = raceParticipantIngame[ userRaceOrder_4A9EA8].carVelocity_4A7DB0;
  racePositionUserFirst_46E8D0[3] = v49;
  v51 = (unsigned __int64)(v50 / raceParticipant2[userRaceOrder_4A9EA8].efectiveEngine_4A6884 * -162.0);
  v52 = 1 - v51;
  if ( v11 - (signed int)v51 < v11 )
    v52 = 1;
  if ( v52 < 162 )
  {
    v53 = v52;
    do
    {
      sub_43C7E0(
        leftMenuInRaceWidth_456AA0 + dword_464F14 + (dword_4B3160[v53] << 9) + dword_503240[v53] + 32,
        dword_503240[v53],
        32,
        33 - dword_4B3160[v53],
        v1);
      ++v53;
    }
    while ( v53 < 162 );
    v47 = userRaceOrder_4A9EA8;
  }
  if ( raceParticipant2[userRaceOrder_4A9EA8].useWeapons )
  {
    v54 = (unsigned __int64)((double)raceParticipant2[v47].weaponsBar_4A68B0 * 0.000537109375);
    if ( (v54 & 0x80000000) != 0 )
      LOBYTE(v54) = 0;
    drawWeaponsBar_43BEF0(0, (void *)(dword_464F14 + (unsigned __int8)v54 + leftMenuInRaceWidth_456AA0 + 24100), 55 - (unsigned __int8)v54, 3, 0);
    v55 = 0;
    if ( raceParticipant2[userRaceOrder_4A9EA8].mines > 0 )
    {
      v56 = 21024;
      do
      {
        drawImageInRace_43B240((int)sidebom1Bpk_481E04, 8, 6, leftMenuInRaceWidth_456AA0 + v56 + dword_464F14);
        ++v55;
        v56 += 8;
      }
      while ( v55 < raceParticipant2[userRaceOrder_4A9EA8].mines );
    }
  }
  else if ( ticksToPauseLapTimeInHud_4A9EB0 <= 0 )
  {
    v57 = (signed int)(currentLapTime_481E0C / 70 + ((unsigned int)(-2004318071 * (currentLapTime_481E0C / 70)) >> 32)) >> 5;
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, v57 + ((unsigned int)v57 >> 31), 16, leftMenuInRaceWidth_456AA0 + 22587, -6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, currentLapTime_481E0C / 70 % 60, 16, leftMenuInRaceWidth_456AA0 + 22601, 6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42), 16,  leftMenuInRaceWidth_456AA0 + 22615, 6, 0);
  }
  else
  {
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 / 60, 16, leftMenuInRaceWidth_456AA0 + 22587, -6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 % 60, 16, leftMenuInRaceWidth_456AA0 + 22601, 6, 0);
    drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(lastCompletedLapTime_503224 % 70) * 1.42),  16, leftMenuInRaceWidth_456AA0 + 22615, 6, 0);
    ticksToPauseLapTimeInHud_4A9EB0 -= dword_4A9EA4;
    if ( ticksToPauseLapTimeInHud_4A9EB0 < 0 )
      ticksToPauseLapTimeInHud_4A9EB0 = 0;
  }
  v58 = (unsigned __int64)((double)raceParticipant2[ userRaceOrder_4A9EA8].turboBar_4A68B4 * 0.000556640625);
  if ( (v58 & 0x80000000) != 0 )
    LOBYTE(v58) = 0;
  drawTurboBar_43B3A0(dword_464F14 + (unsigned __int8)v58 + leftMenuInRaceWidth_456AA0 + 17444, 58 - (unsigned __int8)v58, 7, v1);
  v59 = (unsigned __int64)(100.0 - ceil((double)raceParticipant2[userRaceOrder_4A9EA8].damageBar_4A6898 * 0.0009765625));
  v60 = drawSprite_402590((int)&bugnum6Bpk_46E560, 8, 10, v59, 0, leftMenuInRaceWidth_456AA0 + 36398, -8, -16);
  drawImageInRace_43B240((int)&unk_46E880, 8, 10, v60 + dword_464F14);
  v61 = userRaceOrder_4A9EA8;
  if ( raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 < 20480 )
  {
    if ( !criticalDamageSoundPlayed_456ADC )
    {
      loadMenuSoundEffect(2u, v11, 0, 0x10000, 327680);
      v61 = userRaceOrder_4A9EA8;
    }
    criticalDamageSoundPlayed_456ADC = 1;
  }
  if ( raceParticipant2[v61].damageBar_4A6898 < 10240 )
  {
    if ( !criticalDamage2SoundPlayed_456AE0 )
    {
      loadMenuSoundEffect(2u, v11, 0, 0x10000, 327680);
      v61 = userRaceOrder_4A9EA8;
    }
    criticalDamage2SoundPlayed_456AE0 = 1;
  }
  if ( !raceParticipant2[v61].damageBar_4A6898 && !memcmp(raceParticipant[v61].name, &dukeNukemName, 0xBu) )
  {
    if ( !dukeNukemEndRaceSoundPlayed_456AE8 )
    {
      loadMenuSoundEffect(2u, GEN_EFE_HAIL_TO_THE_KING, 0, 0x10000, 327680);
      v61 = userRaceOrder_4A9EA8;
    }
    dukeNukemEndRaceSoundPlayed_456AE8 = 1;
  }
  v62 = (unsigned __int64)ceil((double)raceParticipant2[ v61].damageBar_4A6898 * 0.000048828125);
  if ( (v62 & 0x80000000) != 0 )
    LODWORD(v62) = 0;
 // drawInRaceImageToBuffer_43B160((int)((char *)&unk_4669C0 - 1344 * v62), 64, 21, dword_464F14 + leftMenuInRaceWidth_456AA0 + 25632);
   drawInRaceImageToBuffer_43B160((int)((char *)&damageBpk_464F80 +6720 - 1344 * v62), 64, 21, dword_464F14 + leftMenuInRaceWidth_456AA0 + 25632);
  result = numberOfParticipants_508D24;
  v64 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
    v65 = 0;
    do
    {
	  if ( raceParticipant2[ participantRaceOrderUserFirst_508D44[v64]].damageBar_4A6898 <= 0 )
        drawImageInRace_43B240((int)rast1Bpk_464F78, 64, 32, v65 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 36896);

      result = numberOfParticipants_508D24;
      ++v64;
      v65 += 0x4000;
    }
    while ( v64 < numberOfParticipants_508D24 );
  }
  return result;
}

//----- (00414FC0) --------------------------------------------------------
int raceSemaphore_414FC0 ()
{
  int result; // eax@1
  int v1; // eax@10
  int v2; // eax@11

  result = raceFrame_481E14;
  if ( raceFrame_481E14 > -10 && raceFrame_481E14 <= 130 )
  {
    if ( !rallyGoSoundPlayed_456AD8 )
    {
		//SOUND_GET_READY
      loadMenuSoundEffect(2u, 3, 0, 0x10000, 327680);
      rallyGoSoundPlayed_456AD8 = 1;
    }
    raceSemaphoreWidth_464F64 = raceSemaphoreWidth_464F64 - dword_4A9EA4 <= 0 ? 0 : raceSemaphoreWidth_464F64 - dword_4A9EA4;
	 drawInRaceImageToBuffer_43B160((int)genlamBpk, 80, 60, dword_464F14 + raceSemaphoreWidth_464F64 + 336);
    result = raceFrame_481E14;
  }
  if ( result > 190 )
  {
    if ( raceSemaphorePosition_456AD4 == 1 )
    {
      if ( isMultiplayerGame )
      {
        //multiplayer_403960();
        //multiplayer_403D50();
        dword_4A7CF4 = 1;
      }
      dword_4A8D2C = 0;
      dword_503500 = 0;
      dword_4A7CFC = 0;
      dword_503510 = 0;
      dword_4A9EAC = 0;
      v1 =  userRaceOrder_4A9EA8;
      raceParticipantIngame[v1].lastKeysReadPreviousIndex_4A7DA4 = 0;
      raceParticipantIngame[v1].lastKeysReadIndex_4A7DA0 = 0;
	  //SOUND_BEEP3
      loadMenuSoundEffect(5u, 44, 0, 0x10000, 163840);
    }
    v2 = raceSemaphoreWidth_464F64 + 2 * dword_4A9EA4;
    if ( dword_4A9EA4 + raceSemaphoreWidth_464F64 > 80 )
      v2 = 80;
    raceSemaphoreWidth_464F64 = v2;
    drawInRaceImageToBuffer_43B160((int)((char *)genlamBpk + 9600), 80, 60, dword_464F14 + v2 + 336);
    result = raceFrame_481E14;
    raceSemaphorePosition_456AD4 = 2;
  }
  if ( result > 130 && result <= 190 )
  {
    if ( !raceSemaphorePosition_456AD4 )
    {
      /*if ( isMultiplayerGame )
      {
        //if ( dword_45E0A8 == 2 )
          //multiplayer_4039D0();
        //else
          //multiplayer_403960();
      }*/
	  //SOUND_BEEP3
      loadMenuSoundEffect(5u, 44, 0, 0x10000, 0x20000);
    }
    raceSemaphorePosition_456AD4 = 1;
    result = drawInRaceImageToBuffer_43B160((int)((char *)genlamBpk + 4800), 80, 60, dword_464F14 + 336);
  }
  return result;
}

//----- (004151C0) --------------------------------------------------------
void loadRaceImagesHUD()
{
  int v0; // eax@6
  signed int v1; // esi@8
  int v2; // esi@10
  int v3; // esi@12
  int v4; // eax@21
//  int v5; // eax@1
//  char v6; // cl@2
//  char *v7; // edi@3
//  char v8; // al@4

 /* v5 = 0;
  do
  {
    v6 = *((BYTE *)raceFilePrefix_45EA50 + v5);
    *(&circuitSelectedTR_464F50 + v5++) = v6;
  }
  while ( v6 );
  v7 = &circuitSelectedTR_464F50 - 1;
  do
    v8 = (v7++)[1];
  while ( v8 );
  *(_DWORD *)v7 = 1095778862;//bpa
  v7[4] = 0;*/
  strcpy(circuitSelectedTR_464F50, raceFilePrefix_45EA50);
  strcat(circuitSelectedTR_464F50, ".BPA");
  loadCircuitPalette();
  loadCircuitImages1();
  loadCarsImages();
  loadEngineGraphics();
  loadCircuitShadows();
  parseCircuitSceFile_403190();
  loadCircuitTabFiles();
  loadCircuitDatFiles();
  extractFromBpa("ENGINE.BPA", textureTemp, "GEN-FLA.BPK");
  copyImageToBuffer((int)textureTemp, (int)genflaBpk);
  extractFromBpa("ENGINE.BPA", textureTemp, "GEN-LAM.BPK");
  copyImageToBuffer((int)textureTemp, (int)genlamBpk);
  loadEngineGraphics2();
  extractFromBpa("IBFILES.BPA", textureTemp, "BOARDS.BPK");
  if ( raceParticipant2[userRaceOrder_4A9EA8].useWeapons )
    v0 = 8704 * userRaceOrder_4A9EA8;
  else
    v0 = 6656 * userRaceOrder_4A9EA8 + 34816;
  decryptTexture((int)textureTemp, (int)boardsBPK_4AA940[0], v0, 6656);
  v1 = 0;
  if ( !userRaceOrder_4A9EA8 )
    v1 = 1;
  decryptTexture((int)textureTemp, (int)boardsBPK_4AA940[1], 8704 * v1 + 6656, 2048);//boards2BPK_4AC340
  v2 = v1 + 1;
  if ( v2 == userRaceOrder_4A9EA8 )
    ++v2;
  decryptTexture((int)textureTemp, (int)boardsBPK_4AA940[2], 8704 * v2 + 6656, 2048);//boards3BPK_4ACB40
  v3 = v2 + 1;
  if ( v3 == userRaceOrder_4A9EA8 )
    ++v3;
  decryptTexture((int)textureTemp, (int)boardsBPK_4AA940[3], 8704 * v3 + 6656, 2048);//boards4BPK_4AD340
  extractFromBpa("IBFILES.BPA", textureTemp, "RASTI1.BPK");
  copyImageToBuffer((int)textureTemp, (int)rast1Bpk_464F78);
  switch ( raceParticipant2[userRaceOrder_4A9EA8].carType )
  {
    case VAGABOND:
      extractFromBpa("IBFILES.BPA", textureTemp, "DAM-KUP.BPK");
      break;
    case DERVISH:
      extractFromBpa("IBFILES.BPA", textureTemp, "DAM-PIC.BPK");
      break;
    case SENTINEL:
      extractFromBpa("IBFILES.BPA", textureTemp,"DAM-SED.BPK");
      break;
    case SHRIEKER:
      extractFromBpa("IBFILES.BPA", textureTemp, "DAM-CAM.BPK");
      break;
    case WRAITH:
      extractFromBpa("IBFILES.BPA", textureTemp, "DAM-POR.BPK");
      break;
    case DELIVERATOR:
      extractFromBpa("IBFILES.BPA", textureTemp, "DAM-LOT.BPK");
      break;
    default:
      break;
  }
  decryptTexture((int)textureTemp, (int)&damageBpk_464F80, 8064 * userRaceOrder_4A9EA8, 8064);
  extractFromBpa("IBFILES.BPA", textureTemp,"BIGNUM6.BPK");
  copyImageToBuffer((int)textureTemp, (int)&bugnum6Bpk_46E560);
  extractFromBpa("IBFILES.BPA", textureTemp, "SMALFO4A.BPK");
  copyImageToBuffer((int)textureTemp, (int)&smalfo4aBpk_4A9160);
  extractFromBpa("IBFILES.BPA", textureTemp,"POSNUM2.BPK");
  copyImageToBuffer((int)textureTemp, (int)&posnum2Bpk_50E440);
  extractFromBpa("IBFILES.BPA", textureTemp, "OWN-NUM1.BPK");
  copyImageToBuffer((int)textureTemp, (int)&ownnum1Bpk_503520);
  extractFromBpa("IBFILES.BPA", textureTemp, "OTH-NUM1.BPK");
  copyImageToBuffer((int)textureTemp, (int)&othnum1Bpk_50B2C0);
  extractFromBpa("IBFILES.BPA", textureTemp, "GOALNUM2.BPK");
  copyImageToBuffer((int)textureTemp, (int)goalnum2Bpk_4AA50C);
  extractFromBpa("IBFILES.BPA", textureTemp, "SIDEBOM1.BPK");
  copyImageToBuffer((int)textureTemp, (int)sidebom1Bpk_481E04);
  extractFromBpa("IBFILES.BPA", textureTemp, "SMALLBAR.BPK");
  v4 = userRaceOrder_4A9EA8;
  if ( !raceParticipant2[userRaceOrder_4A9EA8].useWeapons )//si no usa weapons carga time
    v4 = userRaceOrder_4A9EA8 + 4;
  decryptTexture((int)textureTemp, (int)smallbarBpk_50E720, v4 << 11, 2048);
}

//----- (00415280) --------------------------------------------------------

//----- (004156B0) --------------------------------------------------------
int sub_4156B0()
{
  int v0; // edi@1
  int v1; // ecx@1
  int v2; // eax@2
  int id3dObject =0;
  v0 = trxSCE1Number3DObjects_479D20;
  v1 = 0;
  dword_4AA928 = 0;
  if ( trxSCE1Number3DObjects_479D20 > 0 )
  {
   // v2 = (int)dword_4B4D04;
    do
    {
	  sce2Texture[id3dObject].dword_4B4F68 = sce2Texture[id3dObject].dword_4B4D04 * sce2Texture[id3dObject].dword_4B4D04 + sce2Texture[id3dObject].dword_4B4D08 * sce2Texture[id3dObject].dword_4B4D08;
      sce2Texture[id3dObject].dword_4B4F6C = v1++;
     // v2 += 3152;
	  id3dObject++;
    }
    while ( v1 < v0 );
    dword_4AA928 = v1;
  }
  return sub_4115C0(0, v0 - 1);
}

//----- (00415710) --------------------------------------------------------
void   startRace(int a1, int numberOfParticipants)
{
	int v1;
//  int v2; // edx@2
//  unsigned int v3; // eax@2
//  int *v4; // ecx@3
//  int v5; // esi@3
//  int *v6; // ecx@6
//  int v7; // esi@6
//  int *v8; // ecx@10
  void *v9; // eax@14
  void *v10; // eax@18
  void *v11; // eax@22
  void *v12; // eax@26
  void *v13; // eax@30
  int v14; // eax@34
  void *v15; // eax@38
  void *v16; // eax@42
  void *v17; // eax@46
  void *v18; // eax@50
  void *v19; // eax@54
  void *v20; // eax@58
  void *v21; // eax@62
  void *v22; // eax@66
  void *v23; // eax@70
  void *v24; // eax@74
  void *v25; // eax@78
  void *v26; // eax@82
  void *v27; // eax@86
  void *v28; // eax@90
  void *v29; // eax@94
  void *v30; // eax@98
  void *v31; // eax@102
  void *v32; // eax@106
  void *v33; // eax@110
  void *v34; // eax@114
  void *v35; // eax@118
  void *v36; // eax@122
  void *v37; // eax@126
  void *v38; // eax@130
  void *v39; // eax@134
  void *v40; // eax@138
//  int v41; // eax@142
///  char v42; // cl@143
//  char *v43; // edi@144
//  char v44; // al@145
  int v45; // edx@154
  int v46; // edx@160
  int v47; // eax@161
  int *v48; // ecx@161
  void *v49; // eax@166
  int v50; // ebp@167
  int v51; // eax@169
  int v52; // eax@176
  int v53; // ecx@176
  int v54; // eax@181
  int v55; // ecx@181
  int v56; // ecx@184
  int v57; // eax@184
  int v58; // eax@196
  int v59; // ecx@196
  int v60; // edi@199
  int v61; // edi@201
  int v62; // eax@211
  int v63; // ecx@211
  int v64; // edi@214
  int v65; // esi@214
  unsigned __int64 v66; // rax@218
  int v67; // esi@223
  signed int v68; // ecx@226
  int v69; // ecx@237
  int v70; // eax@237
  int v71; // eax@248
  bool v72; // zf@248
  double v73; // st7@261
  int v74; // esi@263
  int v75; // edi@270
  int v76; // esi@271
  int v77; // edx@271
  int v78; // ecx@271
  char v79; // al@290
  int v80; // ebp@292
  char v81; // al@336
  int v82; // ebp@338
  int v83; // ecx@361
  int v84; // eax@361
  int v85; // ecx@369
  int v86; // eax@382
  char v87; // al@390
  int v88; // eax@398
  int v89; // eax@400
  int v90; // ecx@409
  signed int v91; // eax@409
  signed int v92; // eax@413
  bool v93; // sf@414
  unsigned __int8 v94; // of@414
  int v95; // ecx@416
  bool v96; // zf@420
  bool v97; // sf@420
  unsigned __int8 v98; // of@420
  char v99; // al@436
  char v100; // cl@453
  int v101; // edx@467
///  _UNKNOWN *v102; // ecx@468
  int v103; // eax@468
  char v104; // [sp-14h] [bp-34h]@233
  char v105; // [sp-14h] [bp-34h]@242
  int v106; // [sp-Ch] [bp-2Ch]@233
  int v107; // [sp-Ch] [bp-2Ch]@241
  int v108; // [sp-8h] [bp-28h]@233
  int v109; // [sp-8h] [bp-28h]@241
//  char v110; // [sp+Fh] [bp-11h]@144
  char v111[16]; // [sp+10h] [bp-10h]@143
  int indexRaceParticipant = 0;
  userRaceOrder_4A9EA8 = a1;
  numberOfParticipants_508D24 = numberOfParticipants;
  initParticipantValues_401060(); ///esto es muy muy abstracto hay que hacer las estrcuturas primero porque sino nada. initRaceValues
  initRaceValues_409A90();//mas init values
 /* if ( isMultiplayerGame )
  {
    v2 = numberOfParticipants_508D24;
    v3 = 0;
    dword_4A7A38 = 0;
    if ( numberOfParticipants_508D24 > 0 )
    {
      v4 = &dword_4A68B8;
      v5 = numberOfParticipants_508D24;
      do
      {
        v3 += *v4;
        v4 += 37;
        --v5;
      }
      while ( v5 );
      dword_4A7A38 = v3;
      if ( numberOfParticipants_508D24 > 0 )
      {
        v6 = &dword_4A68BC;
        v7 = numberOfParticipants_508D24;
        do
        {
          v3 += *v6;
          v6 += 37;
          --v7;
        }
        while ( v7 );
        dword_4A7A38 = v3;
      }
    }
    dword_481BE8 = 0;
    if ( numberOfParticipants_508D24 > 0 )
    {
      v8 = &dword_4A68C0;
      dword_481BE8 = numberOfParticipants_508D24;
      do
      {
        v3 += *v8;
        v8 += 37;
        --v2;
      }
      while ( v2 );
      dword_4A7A38 = v3;
    }
    srand(v3);
    dword_4A7CF4 = 0;
    dword_50E540 = 1;
    dword_4A6B04 = 0;
    dword_4A8D2C = 0;
  }*/
    dword_47968C = 0;
  
  setBackgroundRefreshFunction_43C7B0((int (*)(void))sub_4138A0);
  loadCircuitInfFile();
  v9=malloc(circuitWidth_464F40 * circuitHeight_4A7CF8);
 
  circuitMatrixHxW_5034F8 = v9;
  v10 = malloc(circuitWidth_464F40 * circuitHeight_4A7CF8);
 
  trxImaBpk_50A16C = v10;
  v11 = malloc(circuitVaiBpk_width_4A6858 * circuitVaiBpk_height_503508);
  
  trxVaiBpk_5034D0 = v11;
  v12 =malloc(circuitLR1Bpk_width_4A9B90 * circuitLR1Bpk_height_467000);
  
  trxLR1Bpk_4AA920 = v12;
 
  v13 = malloc(0x5F370u);
  trxSCE5Bpk_4A7A28 = v13;
  
  v14 = malloc(0x19400u);
  dword_464F14 = v14 + 512;
  
  v15 = malloc(0x96000u);
  participantCarBpk_5034FC = v15;
  
  v16 = malloc(0x4B000u);
  genflaBpk = v16;
  
  v17 = malloc(0x3840u);
  genlamBpk = v17;
  
  v18 = malloc(0x30u);
  sidebom1Bpk_481E04 = v18;
  
  v19 = malloc(0x240u);
  damslidBpk = v19;
  
  v20 = malloc(0x3C90u);
  genmesBpk = v20;
  
  v21 = malloc(0x3C90u);

  inRaceMessagePopup_479690 = v21;

  v22 = malloc(0x800u);
  rast1Bpk_464F78 = v22;
  
  v23 = malloc(0x268u);
  goalnum2Bpk_4AA50C = v23;
  
  v24 = malloc(0xC00u);
  flamesBpk[0] = v24;

  v25 = malloc(0xC00u);
  flamesBpk[1] = v25;
  
  v26 = malloc(0xC00u);
  flamesBpk[2] = v26;
 
  v27 = malloc(0xC00u);
  flamesBpk[3] = v27;
  
  v28 = malloc(0xC00u);
  flamesBpk[4] = v28;
  
  v29 = malloc(0xC00u);
  flamesBpk[5] = v29;
  
  v30 = malloc(0x140u);
  mines1aBpk = v30;

  v31 = malloc(0x600u);
  blowiBpk = v31;
  
  v32 = malloc(0x480u);
  shotsBpk = v32;

  v33 = malloc(0x800u);
  obstacleBpk = v33;
  
  v34 = malloc(0x2400u);
  pedestrBpk = v34;
 
  v35 = malloc(0x800u);
  splat3Bpk = v35;
 
  v36 = malloc(0x800u);
  splat4Bpk = v36;
 
  v37 = malloc(0x1800u);
  rocket1Bpk = v37;
 
  v38 = malloc(0x1800u);
  rocket2Bpk = v38;
 
  v39 = malloc(0x800u);
  burn1aBpk = v39;
  
  v40 = malloc(0xC0u);
  smokeBpk = v40;
  noMemExitScreen(); //esto no sale del juego
  dword_4A9140 = (int)exitCtrlAltDel;
  loadRaceImagesHUD();
  initRaceValues_409F90();
  sub_4022A0();
  processSceFile_40A360(); //esto hace cosas muy chungas!
  endRaceFlagFrame_481BE0 = 0;
  raceFlagWidth_4B3140 = 80;
  raceSemaphoreWidth_464F64 = 80;
  calculateSceTextureStructure_40A880();//esto hace cosas muy chungas!
  waitTwoSeconsAndExecFunc_43CBB0();
  drawToBlackScreen();//esto pone la pantalla en negro hace el degradado
  
  stopSong();
  stopAndOpenMusic();
  nullsub_1();
  setRaceWindowCaption();//cambiar el caption
  recalculateSDLTicks_43C740();//evento de teclado
  
  strcpy(v111, raceFilePrefix_45EA50);
  strcat(v111, "-MUS.CMF");
  loadMusic(1, v111, 2, "GEN-EFE.CMF");
  //setMusicVolume(0);
  musicSetmusicVolume(configuration.musicVolume);
  musicSetVolume(configuration.effectsVolume);
  nullsub_1();
  musicPlayMusic();
  //setMusicVolume(0);
  nullsub_1();
  if ( !raceMusicEnabled_445020 )
    musicSetmusicVolume(0);
  if ( !raceEffectsEnabled_445024 )
    musicSetVolume(0);
  setCircuitPalette_4B4020();//seteo de colores
  
if ( isCircuitReversed_456AA8 )
   calculateCircuitReversed_40A9A0();
   generateBigPowerUps();

  
 
   sub_4022A0();
  
  
   initRaceValues_409A90();
  
 
   //SOUND_KUPLA y demas
  loadMenuSoundEffect(1u, raceParticipant2[userRaceOrder_4A9EA8].carType + 25, 0, 0x10000, 163840);
  dword_503510 = 0;
  dword_4A9EAC = 0;
  raceFrame_481E14 = 0;
  currentLapTime_481E0C = 0;
  ticksToPauseLapTimeInHud_4A9EB0 = 0;
  lastCompletedLapTime_503224 = 0;
  totalRaceTime_50A164 = 0;
  dword_4A6AD4 = 0;
  if ( isDemo_456B10 )
    dword_464F6C = 1;
  
  refreshPaleteCheat();
  
  do
  {
	
   
    v45 = dword_4A9EAC;
    raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadPreviousIndex_4A7DA4 = raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadIndex_4A7DA0;
    dword_503510 = v45;
    dword_4A7A20 = 0;
    dword_4A9EAC = 0;
    if ( isLapRecord_456AE4 > 0 )
    {
      isLapRecord_456AE4 -= dword_4A9EA4;
      if ( isLapRecord_456AE4 <= 0 )
      {
		  //SOUND_LAP_RECORD
        loadMenuSoundEffect(2u, 4, 0, 0x10000, 327680);
        isLapRecord_456AE4 = 0;
      }
    }
    //if ( isMultiplayerGame && dword_4A7CF4 )
     // multiplayer_403E30();
    v46 = 0;
    dword_481BE8 = 0;
    if ( dword_503510 > 0 )
    {
      v47 =  userRaceOrder_4A9EA8;
      v48 = &raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadPreviousIndex_4A7DA4;
      do
      {
        v93 = (*v48)-- - 1 < 0;
        if ( v93 )
          *v48 = 15;

	  if(raceParticipantIngame[v47 ].lastKeysRead_4A7D60[raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadPreviousIndex_4A7DA4]==0x40u){
		  debug=1;
		  }
		raceParticipantIngame[dword_503510 + v47 - v46++].dword_4A7D1C = raceParticipantIngame[v47 ].lastKeysRead_4A7D60[raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadPreviousIndex_4A7DA4];
		if(debug) raceParticipantIngame[v47 ].dword_4A7D20[dword_503510- v46++] = raceParticipantIngame[v47].lastKeysRead_4A7D60[raceParticipantIngame[ userRaceOrder_4A9EA8].lastKeysReadPreviousIndex_4A7DA4];

      }
      while ( v46 < dword_503510 );
      dword_481BE8 = v46;
    }
   sub_413500();//parece como lanzar minas hacia detras
    v49 = malloc(0xAu);
    //free(v49);
    generatePowerUps();// esto es muy chungo
    if ( dword_503510 > 0 )
    {
      v50 = numberOfParticipants_508D24;
      while ( 1 )
      {
        v94 = __OFSUB__(raceFrame_481E14 + 1, 190);
        v72 = raceFrame_481E14 == 189;
        v93 = raceFrame_481E14++ - 189 < 0;
        if ( (unsigned __int8)(v93 ^ v94) | v72 )
          goto LABEL_195;
        v51 = 0;
        currentDriverSelectedIndex_503518 = 0;
        if ( v50 > 0 )
        {
          do
          {
            if ( dword_464F6C || v51 != userRaceOrder_4A9EA8 && !isMultiplayerGame )
            {
			calculateIAMovements_40AFC0();
              v50 = numberOfParticipants_508D24;
            }
            v51 = currentDriverSelectedIndex_503518++ + 1;
          }
          while ( currentDriverSelectedIndex_503518 < v50 );
          if ( v50 > 0 )
          {
            //v52 = (int)dword_4A7D14;
            v52=0;
			  v53 = v50;
            do
            {
              raceParticipantIngame[v52].dword_4A7D14 =0;
              v52 ++;//= 864;
              --v53;
            }
            while ( v53 );
          }
        }
        currentDriverSelectedIndex_503518 = 0;
        if ( v50 > 0 )
        {
          do
          {
            calculateUserMovements_40BAB0();
            v50 = numberOfParticipants_508D24;
            ++currentDriverSelectedIndex_503518;
          }
          while ( currentDriverSelectedIndex_503518 < numberOfParticipants_508D24 );
          if ( numberOfParticipants_508D24 > 0 )
          {
            //v54 = (int)dword_4A7D18;
            v54=0;
			v55 = numberOfParticipants_508D24;
            do
            {
               raceParticipantIngame[v54].dword_4A7D18 =0;
              v54 ++;
              --v55;
            }
            while ( v55 );
          }
        }
        currentDriverSelectedIndex_503518 = 0;
        if ( v50 > 0 )
        {
          v56 = v50;
          //v57 = (int)dword_4A7D1C;
		  v57=0;
          currentDriverSelectedIndex_503518 = v50;
          do
          {
             raceParticipantIngame[v57].dword_4A7D1C =0;
            v57 ++;
            --v56;
          }
          while ( v56 );
        }
       
		// recalculateRaceCarWithOrientation();
        currentDriverSelectedIndex_503518 = 0;
        if ( v50 > 0 )
        {
          do
          {
            drawMine_40F6A0();
            v50 = numberOfParticipants_508D24;
            ++currentDriverSelectedIndex_503518;
          }
          while ( currentDriverSelectedIndex_503518 < numberOfParticipants_508D24 );
        }
        if ( !isMultiplayerGame )
        {
          currentDriverSelectedIndex_503518 = 0;
          if ( v50 > 0 )
          {
            do
            {
              killPedestrian_410FA0();
              v50 = numberOfParticipants_508D24;
              ++currentDriverSelectedIndex_503518;
            }
            while ( currentDriverSelectedIndex_503518 < numberOfParticipants_508D24 );
          }
        }
        currentDriverSelectedIndex_503518 = 0;
        if ( v50 > 0 )
        {
          do
          {
            getRacePowerUps_410B90();
            v50 = numberOfParticipants_508D24;
            ++currentDriverSelectedIndex_503518;
          }
          while ( currentDriverSelectedIndex_503518 < numberOfParticipants_508D24 );
        }
        currentDriverSelectedIndex_503518 = 0;
        if ( v50 > 0 )
          break;
LABEL_213:
        currentDriverSelectedIndex_503518 = 0;
        if ( v50 > 0 )
        {
			v64 = (int)raceParticipant2[0].damageBar_4A6898;
          v65 = (int)dword_4A7E98;
          currentDriverSelectedIndex_503518 = v50;
          do
          {
            if ( (*(_DWORD *)(v65 - 4) == 2 || *(_DWORD *)v65 == 2) && !*(_DWORD *)(v65 - 140) )
            {
              v66 = (unsigned __int64)((*(float *)(v65 - 156) * *(float *)(v65 - 156)
                                      + *(float *)(v65 - 152) * *(float *)(v65 - 152))
                                     * (double)(1024 - *(_DWORD *)(v64 + 4)));
              dword_50B2B0 = v66;
              if ( (signed int)v66 > 10000 )
              {
                LODWORD(v66) = 10000;
                dword_50B2B0 = 10000;
              }
              v93 = *(_DWORD *)v64 - (signed int)v66 < 0;
              *(_DWORD *)v64 -= v66;
              if ( v93 )
                *(_DWORD *)v64 = 0;
            }
            v65 += 864;
            v64 += 148;
            --v50;
          }
          while ( v50 );
        }
        v67 = userRaceOrder_4A9EA8;
        if ( ! raceParticipantIngame[userRaceOrder_4A9EA8].dword_4A7D14 && !raceParticipantIngame[userRaceOrder_4A9EA8].dword_4A7D18 && !raceParticipantIngame[userRaceOrder_4A9EA8].dword_4A7D1C )
          goto LABEL_248;
        v68 = (unsigned __int64)(sqrt( raceParticipantIngame[userRaceOrder_4A9EA8].unk_4A7DFC
                                    * raceParticipantIngame[userRaceOrder_4A9EA8].unk_4A7DFC + raceParticipantIngame[userRaceOrder_4A9EA8].unk_4A7E00
                                                                                   * raceParticipantIngame[userRaceOrder_4A9EA8].unk_4A7E00)
                               * 25000.0);
        dword_50B2B0 = v68;
        if ( v68 > 0x10000 )
        {
          v68 = 0x10000;
          dword_50B2B0 = 0x10000;
        }
        if ( raceParticipantIngame[userRaceOrder_4A9EA8].dword_4A7D18 || raceParticipantIngame[userRaceOrder_4A9EA8].dword_4A7D1C )
        {
          if ( dword_503500 % 3 )
          {
            if ( dword_503500 % 3 == 1 )
            {
              v108 = 143360;
              v106 = v68;
              v104 = 13;
            }
            else
            {
              if ( dword_503500 % 3 != 2 )
                goto LABEL_237;
              v108 = 143360;
              v106 = v68;
              v104 = 16;
            }
          }
          else
          {
            v108 = 135168;
            v106 = v68;
            v104 = 11;
          }
		  //SOUND_HIT02
          loadMenuSoundEffect(5u, v104, 0, v106, v108);
        }
LABEL_237:
        v69 = rand() % 24576;
        v70 = dword_4A7E90[ userRaceOrder_4A9EA8];
        dword_481BE8 = v69;
        switch ( v70 )
        {
          case 0:
            if ( !(dword_503500 % 3) )
            {
              v109 = v69 + 139264;
              v107 = dword_50B2B0;
              v105 = 10;
              goto LABEL_247;
            }
            if ( dword_503500 % 3 == 1 )
              goto LABEL_244;
            if ( dword_503500 % 3 == 2 )
            {
              v109 = v69 + 139264;
              v107 = dword_50B2B0;
              goto LABEL_246;
            }
            break;
          case 1:
            v109 = v69 + 139264;
            v107 = dword_50B2B0;
            v105 = 11;
            goto LABEL_247;
          case 2:
LABEL_244:
            v109 = v69 + 139264;
            v107 = dword_50B2B0;
            v105 = 15;
            goto LABEL_247;
          case 3:
            v109 = v69 + 139264;
            v107 = dword_50B2B0;
LABEL_246:
            v105 = 16;
		LABEL_247:
			//SOUND_HIT02
            loadMenuSoundEffect(5u, v105, 0, v107, v109);
            break;
          default:
            break;
        }
LABEL_248:
        v71 = dword_4AA92C;
        v72 = dword_4AA92C == 0;
        if ( dword_4AA92C > 0 )
        {
          if ( !dword_456AD0
			  && raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 > 0
            && !raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C
            && raceSemaphorePosition_456AD4 == 2 )
          {
			  //SOUND_BRAKES
            loadMenuSoundEffect(6u, 37, 0, dword_4AA92C, 163840);
            v71 = dword_4AA92C;
            dword_456AD0 = 1;
          }
          v72 = v71 == 0;
        }
        if ( v72 && dword_456AD0 == 1 )
        {
          stopSoundChannel_43C3E0(6u);
          dword_456AD0 = 0;
        }
		v72 = raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 == 0;
		v93 = raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 < 0;
        dword_4AA92C = 0;
        if ( v93 || v72 || raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C )
        {
          stopSoundChannel_43C3E0(1u);
          stopSoundChannel_43C3E0(6u);
        }
		v73 = raceParticipantIngame[ userRaceOrder_4A9EA8].carVelocity_4A7DB0 /  raceParticipant2[userRaceOrder_4A9EA8].efectiveEngine_4A6884;
        if ( v73 < 0.0 )
          v73 = -v73;
        dword_445034 = (unsigned __int64)((double)(5 * dword_4A7EA0[ userRaceOrder_4A9EA8]) * v73
                                        + (double)(dword_4A7E9C[ userRaceOrder_4A9EA8] + 163840));
       //TODO FIX SONIDO  sub_43C1B0(1u, 0x10000, dword_445034);
        recalculateCarBoundary_411D10(); //esto peta creo que calcula posiciones con velocidad y tal.
        checkVaiZones_412DF0();
        v74 = isMultiplayerGame;
        if ( !isMultiplayerGame || !dword_4A6B04 )
			recalculateRacePositions_413380();
			
		if ( !v74 && (raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C || raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 <= 0) )
          ++framesAfterEndRaceOrCrash_4AA508;
        v50 = numberOfParticipants_508D24;
        v75 = 0;
        dword_4A7A38 = 0;
        currentDriverSelectedIndex_503518 = 0;
        if ( numberOfParticipants_508D24 > 0 )
        {
          v76 = numberOfParticipants_508D24;
		  v77 = (int)raceParticipant2[0].damageBar_4A6898;
          v78 = (int)0;
          currentDriverSelectedIndex_503518 = numberOfParticipants_508D24;
		  do
          {
            if (  raceParticipantIngame[v78].carVelocity_4A7DB0 <= 0.5 && (raceParticipantIngame[v78].hasFinishedTheRace_4A7E0C ||raceParticipant2[v78].damageBar_4A6898 <= 0) )
              ++v75;
            v78 += 1;
            v77 += 148;
            --v76;
          }
          while ( v76 );
          dword_4A7A38 = v75;
        }
        if ( v75 >= numberOfParticipants_508D24 - 1 )
          ++framesAfterEndRaceOrCrash_4AA508;
        --dword_503510;
        ++dword_4A7A20;
        if ( dword_503510 <= 0 )
          goto LABEL_281;
      }
      do
      {
        shotAction_40E180();
        v50 = numberOfParticipants_508D24;
        ++currentDriverSelectedIndex_503518;
      }
      while ( currentDriverSelectedIndex_503518 < numberOfParticipants_508D24 );
LABEL_195:
      if ( v50 > 0 )
      {

		  v58 =&raceParticipantIngame[v50].dword_4A7E94;//sustitui por raceParticipantIngame
        v59 = v50;
        do
        {
          if ( raceParticipantIngame[v59].dword_4A7E94 > 0 )
            --raceParticipantIngame[v59].dword_4A7E94;
          //v60 = *(_DWORD *)(v58 + 4);
          if ( raceParticipantIngame[v59].dword_4A7E98 > 0 )
            raceParticipantIngame[v59].dword_4A7E98 = raceParticipantIngame[v59].dword_4A7E98 - 1;
		  v61 = raceParticipantIngame[v59].backLeftAbsoluteYPosition_4A7E34;// *(_DWORD *)(v58 - 24);
          if (  raceParticipantIngame[v59].backLeftAbsoluteYPosition_4A7E34> 0 )
            raceParticipantIngame[v59].backLeftAbsoluteYPosition_4A7E34 = raceParticipantIngame[v59].backLeftAbsoluteYPosition_4A7E34; - 1;
		  if ( raceParticipantIngame[v59].dword_4A7D14==1)//; *(_DWORD *)(v58 - 384) == 1 )   //dword_4A7D14
            raceParticipantIngame[v59].dword_4A7E94 += 2;
          if ( raceParticipantIngame[v59].dword_4A7D18==1)// *(_DWORD *)(v58 - 380) == 1 )  //dword_4A7D18
          {
             raceParticipantIngame[v59].absolutePositionX_4A7DB4 = raceParticipantIngame[v59].dword_4A7E50 ;//*(_DWORD *)(v58 - 224) = *(_DWORD *)(v58 - 68); // -224 es absolutePositionX_4A7DB4  -68 es dword_4A7E50
            raceParticipantIngame[v59].dword_4A7E98 += 2;
          }
          if (raceParticipantIngame[v59].dword_4A7D1C ==1)// *(_DWORD *)(v58 - 376) == 1 ) ////dword_4A7D1c
          {
           raceParticipantIngame[v59].absolutePositionY_4A7DB8 == raceParticipantIngame[v59].dword_4A7E54;// *(_DWORD *)(v58 - 220) = *(_DWORD *)(v58 - 64); // --220   absolutePositiony_4A7DB8 -64 es dword_4A7E54
            raceParticipantIngame[v59].dword_4A7E98 += 2;
          }
          v58 += 864;
          --v59;
        }
        while ( v59 );
        if ( v50 > 0 )
        {
          //v62 = (int)dword_4A7E50;
			v62=0;
          v63 = v50;
          do
          {
			  raceParticipantIngame[v62].dword_4A7E50 = raceParticipantIngame[v62].absolutePositionX_4A7DB4; //absolutePositionX_4A7DB4
			  raceParticipantIngame[v62].dword_4A7E54 = raceParticipantIngame[v62].absolutePositionY_4A7DB8; //absolutePositionX
			  raceParticipantIngame[v62].flt_4A7E58 = raceParticipantIngame[v62].carAngle_4A7DAC;//carAngle_4A7DAC
            v62 ++;
            --v63;
          }
          while ( v63 );
        }
      }
      goto LABEL_213;
    }
LABEL_281:
    if ( isMultiplayerGame )
    {
		nullsub_1();//puesto para que no falle la compilacion
      //if ( dword_4A7CF4 )
       // multiplayer_415280();
    }
    else if ( raceParticipant2[0].carType != 6 )
    {
      balanceIAEngineInRace_40B920();
    }
	
    if ( keysRead_45E0C0[KEY_F6] )//cambiado a f11
      makeSnapshot_4092B0();

	
    if ( keysRead_45E0C0[KEY_F1] && !isMultiplayerGame  ) //f1 help  FIX DEBUG
    {
		
      v79 = 0;
      dword_456C28 = 0;
      dword_481BE8 = 0;
      do
      {
        stopSoundChannel_43C3E0(v79 + 1);
        v79 = dword_481BE8 + 1;
        v94 = __OFSUB__(dword_481BE8 + 1, 14);
        v93 = dword_481BE8++ - 13 < 0;
      }
      while ( v93 ^ v94 );
      v80 = sub_43C1F0() & 0xFF00;
      if ( !memcmp(raceFilePrefix_45EA50, "TR0", 4u) )
        musicSetOrder(7680);
      if ( !memcmp(raceFilePrefix_45EA50, "TR1", 4u) )
        musicSetOrder(14080);
      if ( !memcmp(raceFilePrefix_45EA50, "TR2", 4u) )
        musicSetOrder(11520);
      if ( !memcmp(raceFilePrefix_45EA50, "TR3", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR4", 4u) )
        musicSetOrder(11520);
      if ( !memcmp(raceFilePrefix_45EA50, "TR5", 4u) )
        musicSetOrder(14080);
      if ( !memcmp(raceFilePrefix_45EA50, "TR6", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR7", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR8", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR9", 4u) )
        musicSetOrder(12800);
      setMusicVolume(0x8000);
      keyMenuInRace_407330();
      musicSetOrder(v80);
      setMusicVolume(0x10000);
	  //SOUND_KUPLA y demas
      loadMenuSoundEffect(1u, LOBYTE(raceParticipant2[userRaceOrder_4A9EA8].carType) + 25, 0, 0x10000, 163840);
    }
    if ( dword_46F200 )
      goto LABEL_316;
    if ( keysRead_45E0C0[KEY_TAB]) //tab
    {
      dword_46F200 = 1;
      raceShowLeftPanel_445028 = raceShowLeftPanel_445028 == 0;
LABEL_316:
      if ( keysRead_45E0C0[KEY_TAB] )//tab
        goto LABEL_318;
    }
    dword_46F200 = 0;
LABEL_318:
	if ( raceParticipant2[ userRaceOrder_4A9EA8].damageBar_4A6898 <= 0 )
      raceShowLeftPanel_445028 = 1;
    if ( keysRead_45E0C0[KEY_F2] )///esto es f2 music on/off
    {
      if ( raceMusicEnabled_445020 )
      {
        raceMusicEnabled_445020 = 0;
        musicSetmusicVolume(0);
      }
      else
      {
        raceMusicEnabled_445020 = 1;
        musicSetmusicVolume(configuration.musicVolume);
      }
      keysRead_45E0C0[KEY_F2] = 0;
    }
    if ( keysRead_45E0C0[KEY_F3] )  //f3 effects on/off
    {
      if ( raceEffectsEnabled_445024 )
      {
        raceEffectsEnabled_445024 = 0;
        musicSetVolume(0);
      }
      else
      {
        raceEffectsEnabled_445024 = 1;
        musicSetVolume(configuration.effectsVolume);
      }
      
		keysRead_45E0C0[KEY_F3] = 0;
    }
    if ( keysRead_45E0C0[KEY_F4] ) //f4 //textures
    {
      keysRead_45E0C0[KEY_F4] = 0;
      raceShowTextures_44502C = raceShowTextures_44502C == 0;
    }
    if ( keysRead_45E0C0[KEY_F5] )  //f5 shadows
    {
      keysRead_45E0C0[KEY_F5] = 0;
      raceShowShadows_445030 = raceShowShadows_445030 == 0;
    }
    if ( keysRead_45E0C0[KEY_P] && !isMultiplayerGame )   //tecla p pause
    {
      v81 = 0;
      dword_456C28 = 0;
      dword_481BE8 = 0;
      do
      {
        stopSoundChannel_43C3E0(v81 + 1);
        v81 = dword_481BE8 + 1;
        v94 = __OFSUB__(dword_481BE8 + 1, 14);
        v93 = dword_481BE8++ - 13 < 0;
      }
      while ( v93 ^ v94 );
      v82 = sub_43C1F0() & 0xFF00;
      if ( !memcmp(raceFilePrefix_45EA50, "TR0", 4u) )
        musicSetOrder(7680);
      if ( !memcmp(raceFilePrefix_45EA50, "TR1", 4u) )
        musicSetOrder(14080);
      if ( !memcmp(raceFilePrefix_45EA50, "TR2", 4u) )
        musicSetOrder(11520);
      if ( !memcmp(raceFilePrefix_45EA50, "TR3", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR4", 4u) )
        musicSetOrder(11520);
      if ( !memcmp(raceFilePrefix_45EA50, "TR5", 4u) )
        musicSetOrder(14080);
      if ( !memcmp(raceFilePrefix_45EA50, "TR6", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR7", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR8", 4u) )
        musicSetOrder(12800);
      if ( !memcmp(raceFilePrefix_45EA50, "TR9", 4u) )
        musicSetOrder(12800);
      setMusicVolume(0x8000);
      memcpy(inRaceMessagePopup_479690, genmesBpk, 0x3C90u);
      drawTextInRaceScreen(0, 0, "                                ");
      drawTextInRaceScreen(0, 1, "                                ");
      drawTextInRaceScreen(0, 2, "                                ");
      drawTextInRaceScreen(0, 3, "     G A M E   P A U S E D !    ");
      drawTextInRaceScreen(0, 4, "                                ");
      drawTextInRaceScreen(0, 5, "                                ");
      drawTextInRaceScreen(0, 6, "                                ");
      drawTextInRaceScreen(0, 7, "                                ");
      drawTextInRaceScreen(0, 8, "    PRESS ENTER TO CONTINUE     ");
      racePauseMenu_4064A0(0);
      if ( mushroomTaken_456AA4 == 1 )
        memset((void *)screenPtr, 0, 0xFA00u);
      musicSetOrder(v82);
      setMusicVolume(0x10000);
	  //SOUND_KUPLA y demas
      loadMenuSoundEffect(1u, LOBYTE(raceParticipant2[userRaceOrder_4A9EA8].carType) + 25, 0, 0x10000, 163840);
    }
    recalculateCircuitImageOffset_40D560();
    recalculatePolygonsInScreeenPosition_40D6B0();
    v83 = circuitWidth_464F40;
    v84 = 0;
    dword_4A7A38 = 0;
    dword_481BE8 = 0;
    do
    {
      copyBuffer2Screen(
        (void *)(dword_464F14 + leftMenuInRaceWidth_456AA0 + v84 + 96),
        (char *)circuitMatrixHxW_5034F8 + (circuitImageOffsetX_456ABC + v83 * circuitImageOffsetY_456AC0 + dword_4A7A38),
        (raceEffectiveWidth_445010 >> 2) + 1); //esto pinta la carrera!!!!
      v83 = circuitWidth_464F40;
      v84 = dword_481BE8 + 512;
      v94 = __OFSUB__(dword_481BE8 + 512, 102400);
      v93 = dword_481BE8 - 101888 < 0;
      dword_481BE8 += 512;
      dword_4A7A38 += circuitWidth_464F40;

	  //aqui se pinta todo
    }
	//while(dword_4A7A38<102400);
    while ( v93 ^ v94 );
	 
	

    if ( !isMultiplayerGame )
      LOBYTE(v84) = drawShotPedestrian_4111F0();
    for ( currentDriverSelectedIndex_503518 = 0; currentDriverSelectedIndex_503518 < numberOfParticipants_508D24; ++currentDriverSelectedIndex_503518 )
    {
		//draw smoke
      showSmoke_40F070(v84);
      v84 = currentDriverSelectedIndex_503518 + 1;
    }
	drawCarInRace_40D920();
    //TODO FIXdrawExplosion_40FE20();
   if ( raceShowShadows_445030 )
      drawShadows_40D7B0();
    v85 = numberOfParticipants_508D24;
    for ( currentDriverSelectedIndex_503518 = 0; currentDriverSelectedIndex_503518 < numberOfParticipants_508D24; ++currentDriverSelectedIndex_503518 )
    {
		//pinta llamas
      drawGunFlames_40E960(); //TODO FIX
      v85 = numberOfParticipants_508D24;
    }
    currentDriverSelectedIndex_503518 = 0;
    if ( v85 > 0 )
    {
      do
      {
		  //pinta turbo
        drawRocket_40F450();
        ++currentDriverSelectedIndex_503518;
      }
      while ( currentDriverSelectedIndex_503518 < numberOfParticipants_508D24 );
    }

	
	sub_4156B0();
    draw3dElements_4116D0();// esto falla
    for ( currentDriverSelectedIndex_503518 = 0; currentDriverSelectedIndex_503518 < numberOfParticipants_508D24; ++currentDriverSelectedIndex_503518 )
      	drawShots_40EBC0(); //pinta disparos
    powerUpTaken_410050();
    if ( !isMultiplayerGame )
      checkPokes_4136C0();
    if ( raceFrame_481E14 < 290 )
      raceSemaphore_414FC0 ();
    if ( raceEffectiveWidth_445010 == 320 )
      drawSmallLeftBar_414110(0);
    else
		
     drawLeftRaceBar_414220();

	//drawDebugInfo();
    v86 = 0;
    for ( currentDriverSelectedIndex_503518 = 0; v86 < numberOfParticipants_508D24; currentDriverSelectedIndex_503518 = v86 )
    {
      if ( raceParticipantIngame[v86].racePosition_4A7E09 == 1 && isRaceFinish_456AC8 )
      {
        showEndRaceFlag_402490();
        v86 = currentDriverSelectedIndex_503518;
      }
      ++v86;
    }
    if ( framesAfterEndRaceOrCrash_4AA508 > 300 )
    {
      dword_456C28 = 0;
      if ( isMultiplayerGame )
        dword_4A7CF4 = 0;
      v87 = 0;
      dword_481BE8 = 0;
      do
      {
        stopSoundChannel_43C3E0(v87 + 1);
        v87 = dword_481BE8 + 1;
        v94 = __OFSUB__(dword_481BE8 + 1, 14);
        v93 = dword_481BE8++ - 13 < 0;
      }
      while ( v93 ^ v94 );
	  //SOUND_RACE_OVER
      loadMenuSoundEffect(2u, 5, 0, 0x10000, 327680);
	  inRaceMessagePopup_479690 = malloc(0x3C90u);//estaba a nulo
      memcpy(inRaceMessagePopup_479690, genmesBpk, 0x3C90u);
      drawTextInRaceScreen(0, 0, "                                ");
      drawTextInRaceScreen(0, 1, "                                ");
      drawTextInRaceScreen(0, 2, "                                ");
      drawTextInRaceScreen(0, 3, "      R A C E    O V E R !      ");
      drawTextInRaceScreen(0, 4, "                                ");
      drawTextInRaceScreen(0, 5, "                                ");
      drawTextInRaceScreen(0, 6, "                                ");
      drawTextInRaceScreen(0, 7, "                                ");
      drawTextInRaceScreen(0, 8, "    PRESS ENTER TO CONTINUE     ");
      if ( isDemo_456B10 )
        racePauseMenu_4064A0(1);
      else
        racePauseMenu_4064A0(0);
      dword_464F68 = 1;
    }
    dword_481BE8 = refreshScreenWithDelay();
    while ( dword_481BE8 == refreshScreenWithDelay() )
      ;
    v88 = userRaceOrder_4A9EA8;
    if ( raceParticipantIngame[userRaceOrder_4A9EA8].mushroomPendingTime_4A8050 > 0 )
    {
      if ( !mushroomTaken_456AA4 || (sub_405430(), !mushroomTaken_456AA4) )
        sub_404730();
    }
    else
    {
      if ( !mushroomTaken_456AA4 )
      {
        v89 = 0;
        dword_4A7A38 = 0;
        dword_481BE8 = 0;
        do
        {
			copyBuffer2Screen((void *)(v89+screenPtr) , (const void *)(dword_464F14 + dword_4A7A38 + 96), 80);
			v89 = dword_481BE8 + 320;
          v94 = __OFSUB__(dword_481BE8 + 320, 64000);
          v93 = dword_481BE8 - 63680 < 0;
          dword_481BE8 += 320;
          dword_4A7A38 += 512;
        }
        while ( v93 ^ v94 );
        v88 = userRaceOrder_4A9EA8;
      }
      if ( mushroomTaken_456AA4 == 1 )
      {
        sub_405430();
        v88 = userRaceOrder_4A9EA8;
      }
	  raceParticipantIngame[v88].mushroomPendingTime_4A8050 = 0;
    }
    v90 = dword_4A9EA4;
	
	if(raceParticipantIngame[0].mushroomPendingTime_4A8050>0) raceParticipantIngame[0].mushroomPendingTime_4A8050 =-dword_4A9EA4;
	if(raceParticipantIngame[1].mushroomPendingTime_4A8050>0) raceParticipantIngame[1].mushroomPendingTime_4A8050 =-dword_4A9EA4;
	if(raceParticipantIngame[2].mushroomPendingTime_4A8050>0) raceParticipantIngame[2].mushroomPendingTime_4A8050 =-dword_4A9EA4;
	if(raceParticipantIngame[3].mushroomPendingTime_4A8050>0) raceParticipantIngame[3].mushroomPendingTime_4A8050 =-dword_4A9EA4;
    currentDriverSelectedIndex_503518 = 4;
    
    v92 = raceEffectiveWidth_445010;

	//calcula el tama\F1o efectivo de la pantalla descontando el panel lateral de la izquierda
    if ( raceShowLeftPanel_445028 )
    {
      v94 = __OFSUB__(raceEffectiveWidth_445010, 256);
      v93 = raceEffectiveWidth_445010 - 256 < 0;
      if ( raceEffectiveWidth_445010 > 256 )
      {
        if ( !mushroomTaken_456AA4 )
        {
          v95 = -v90;
          v92 = raceEffectiveWidth_445010 + 4 * v95;
          raceEffectiveWidth_445010 += 4 * v95;
        }
        v94 = __OFSUB__(v92, 256);
        v93 = v92 - 256 < 0;
      }
      if ( v93 ^ v94 )
      {
        v92 = 256;
LABEL_426:
        raceEffectiveWidth_445010 = v92;
        goto LABEL_427;
      }
    }
    else
    {
      v98 = __OFSUB__(raceEffectiveWidth_445010, 320);
      v96 = raceEffectiveWidth_445010 == 320;
      v97 = raceEffectiveWidth_445010 - 320 < 0;
      if ( raceEffectiveWidth_445010 < 320 )
      {
        if ( !mushroomTaken_456AA4 )
        {
          v92 = raceEffectiveWidth_445010 + 2 * v90;
          raceEffectiveWidth_445010 += 2 * v90;
        }
        v98 = __OFSUB__(v92, 320);
        v96 = v92 == 320;
        v97 = v92 - 320 < 0;
      }
      if ( !((unsigned __int8)(v97 ^ v98) | v96) )
      {
        v92 = 320;
        goto LABEL_426;
      }
    }
LABEL_427:
    raceEffectiveHalfWidth_445014 = v92 >> 1;
    leftMenuInRaceWidth_456AA0 = 320 - v92;
    if ( isMultiplayerGame )
    {
		//if ( !keysRead_45E0C0[KEY_ESCAPE] && !dword_47968C || raceFrame_481E14 <= 200 )
        //goto LABEL_458;
    }
    else if ( !keysRead_45E0C0[KEY_ESCAPE] )
    {
      goto LABEL_460;
    }
    dword_456C28 = 0;
    if ( isMultiplayerGame )
    {
      /*dword_4A7CF4 = 0;
      if ( !dword_47968C )
        nullsub_1();*/
    }
    dword_464F68 = -1;
    v99 = 0;
    memcpy(inRaceMessagePopup_479690, genmesBpk, 0x3C90u);
    dword_481BE8 = 0;
    do
    {
      stopSoundChannel_43C3E0(v99 + 1);
      v99 = dword_481BE8 + 1;
      v94 = __OFSUB__(dword_481BE8 + 1, 14);
      v93 = dword_481BE8++ - 13 < 0;
    }
    while ( v93 ^ v94 );
    if ( isMultiplayerGame && dword_47968C )
    {
      /*drawTextInRaceScreen(0, 0, "                                ");
      drawTextInRaceScreen(0, 1, "                                ");
      drawTextInRaceScreen(0, 2, " S O M E O N E   I S   A B O U T");
      drawTextInRaceScreen(0, 3, "   T O   A B O R T   R A C E !  ");
      drawTextInRaceScreen(0, 4, "                                ");
      drawTextInRaceScreen(0, 5, "                                ");
      drawTextInRaceScreen(0, 6, "                                ");
      drawTextInRaceScreen(0, 7, "  WAITING FOR SIGNAL FROM HOST  ");
      drawTextInRaceScreen(0, 8, "                                ");
      //multiplayer_406D30(1);*/
    }
    else
    {
      drawTextInRaceScreen(0, 0, "                                ");
      drawTextInRaceScreen(0, 1, "                                ");
      drawTextInRaceScreen(0, 2, "                                ");
      if ( isDemo_456B10 )
        drawTextInRaceScreen(0, 3, "      A B O R T   D E M O !     ");
      else
        drawTextInRaceScreen(0, 3, "      A B O R T   R A C E !     ");
      drawTextInRaceScreen(0, 4, "                                ");
      drawTextInRaceScreen(0, 5, "             Y / N              ");
      drawTextInRaceScreen(0, 6, "                                ");
      drawTextInRaceScreen(0, 7, "                                ");
      drawTextInRaceScreen(0, 8, "                                ");
    }
    if ( !isMultiplayerGame )
      goto LABEL_473;
    if ( !dword_47968C )
      ///multiplayer_406D30(0);
    if ( !isMultiplayerGame )
LABEL_473:
      racePauseMenu_4064A0(0);
    if ( dword_464F68 == 1 )
    {
      if ( !isMultiplayerGame )
      {
        refreshRacePositions_413300();
        isDemo_456B10 = 0;
        goto LABEL_460;
      }
      goto LABEL_458;
    }
    v100 = LOBYTE(raceParticipant2[userRaceOrder_4A9EA8].carType) + 25;
    dword_464F68 = 0;
	//SOUND KUPLA Y DEMAS
    loadMenuSoundEffect(1u, v100, 0, 0x10000, 163840);
    if ( mushroomTaken_456AA4 == 1 )
      memset((void *)screenPtr, 0, 0xFA00u);
    if ( isMultiplayerGame )
    {
      if ( !dword_464F68 )
      {
        dword_4A7CF4 = 1;
        dword_47968C = 0;
      }
LABEL_458:
      if ( dword_4A6B04 == 1 )
      {
        dword_456C28 = 0;
        dword_4A7CF4 = 0;
        nullsub_1();
        dword_464F68 = -1;
        memcpy(inRaceMessagePopup_479690, genmesBpk, 0x3C90u);
        drawTextInRaceScreen(0, 0, "                                ");
        drawTextInRaceScreen(0, 1, "                                ");
        drawTextInRaceScreen(0, 2, "     M U L T I P L A Y E R      ");
        drawTextInRaceScreen(0, 3, "      C O N N E C T I O N       ");
        drawTextInRaceScreen(0, 4, "           L O S T !            ");
        drawTextInRaceScreen(0, 5, "                                ");
        drawTextInRaceScreen(0, 6, "                                ");
        drawTextInRaceScreen(0, 7, "                                ");
        drawTextInRaceScreen(0, 8, "      PRESS ENTER TO ABORT      ");
       // multiplayer_406D30(0);
        dword_464F68 = 1;
		raceParticipant[0].difficulty = -1;
      }
    }
LABEL_460:
    ++totalRacesFrame_456ACC;
    if ( totalRacesFrame_456ACC == 1 )
    {
      dword_456C28 = 0;
     // sub_404C30(); //cambia el vlaor de la paleta a vacio cuidado pinta la carrera y el menu lateral al principio
	  //TODO fix 
	  //firstRacePlayed_464F44=0;
      if ( !isMultiplayerGame )
      {

		 // if(debug==1)
			//firstRacePlayed_464F44=0;//TODO FIX esta puesto a fuego porque peta
        if ( firstRacePlayed_464F44 )
        {
          memcpy(inRaceMessagePopup_479690, genmesBpk, 0x3C90u);
          drawTextInRaceScreen(0, 0, "     WELCOME TO DEATH RALLY!    ");
          drawTextInRaceScreen(0, 1, "                                ");
          drawTextInRaceScreen(0, 2, " PRESS                          ");
          drawTextInRaceScreen(0, 3, "    F1-INFO SCREEN              ");
          drawTextInRaceScreen(0, 4, "     P-PAUSE                    ");
          drawTextInRaceScreen(0, 5, "   TAB-TOGGLE STATUS BAR        ");
          drawTextInRaceScreen(0, 6, "   ESC-ABORT RACE               ");
          drawTextInRaceScreen(0, 7, "                                ");
          drawTextInRaceScreen(0, 8, "    PRESS ENTER TO CONTINUE     ");
         if ( isDemo_456B10 )
            racePauseMenu_4064A0(1);
          else
            racePauseMenu_4064A0(0);
        }
      }
    }
    dword_456C28 = 0;
	
    refreshScreenWithDelay();
   dword_456C28 = 1;
  }
  while ( !dword_464F68 );
  dword_456C28 = 0;
  //sub_4055A0(); //hace la transicion d emenu despues de terminar la carrera
  memset((void *)screenPtr, 0, 0xFA00u);
  v101 = numberOfParticipants_508D24;
  currentDriverSelectedIndex_503518 = 0;
  if ( numberOfParticipants_508D24 > 0 )
  {
   // v102 = &racePosition;
    //v103 = (int)racePosition_4A7E09;
	  v103=0;
	  v103 =raceParticipantIngame[0].racePosition_4A7E09;
    currentDriverSelectedIndex_503518 = numberOfParticipants_508D24;
	
	
    do
    {
		--v101;
		raceParticipant2[v101].racePosition =raceParticipantIngame[v101].racePosition_4A7E09;
		//raceParticipant2[indexRaceParticipant].racePosition =raceParticipant2[v103].racePosition;
      v103 += 1;
	  //raceParticipant2[indexRaceParticipant].racePosition = (char *)raceParticipant2[indexRaceParticipant].racePosition + 148;
      
	  indexRaceParticipant++;
    }
    while ( v101 );
  }
  removeBackgroundRefreshFunction_43C730();
  stopSong();
  stopAndOpenMusic();
  updateRacePositions();
  free(circuitMatrixHxW_5034F8);
  //free(trxImaBpk_50A16C);
 // free(trxVaiBpk_5034D0);
 // free(trxLR1Bpk_4AA920);
  //free(trxSCE5Bpk_4A7A28);
  //free((void *)(dword_464F14 - 512));
  free(participantCarBpk_5034FC);
 // free(genflaBpk);
  free(sidebom1Bpk_481E04);
  free(genlamBpk);
  free(damslidBpk);
 // free(genmesBpk);
  free(inRaceMessagePopup_479690);
  //free(rast1Bpk_464F78);
  free(goalnum2Bpk_4AA50C);
  free(flamesBpk[0]);
  free(flamesBpk[1]);
  free(flamesBpk[2]);
  free(flamesBpk[3]);
  free(flamesBpk[4]);
  free(flamesBpk[5]);
  //free(flamesBpk);
  free(mines1aBpk);
  free(blowiBpk);
  free(shotsBpk);
  free(obstacleBpk);
  free(pedestrBpk);
 // free(splat3Bpk);
  free(splat4Bpk);
  /*free(rocket1Bpk);
  free(rocket2Bpk);
  free(burn1aBpk);
  free(smokeBpk);*/
  free(dword_4A6854);
  free(dword_46F204);
  keysRead_45E0C0[KEY_ESCAPE] = 0;
}

//----- (00417B90) --------------------------------------------------------
//int   getFileSizeFromBpa(char *bpaFile, char * filename)

//----- (00417DF0) --------------------------------------------------------
//int   getSizeMusic(char * music)

//----- (00417E10) --------------------------------------------------------
//void *  getMusicStream(char* musicName)

//----- (00417E80) --------------------------------------------------------
int configJoystick()
{
  int result; // eax@1

  result = configuration.useJoystick;
  if ( configuration.useJoystick > 0 )
  {
    result = SDLConfigureJoystick();
    joystick_x_axis_default_4AA3E0 = 0;
    joystick_y_axis_default_4A9EA0 = 0;
  }
  return result;
}
// 417E80: using guessed type int configJoystick(void);
// 45EA00: using guessed type int configuration.useJoystick;
// 4A9EA0: using guessed type int joystick_y_axis_default_4A9EA0;
// 4AA3E0: using guessed type int joystick_x_axis_default_4AA3E0;

//----- (00417EB0) --------------------------------------------------------
char eventDetected()
{
  char v0; // bl@1
  int v1; // eax@1
  int ticks; // eax@13
  int v3; // edi@13
  char v4; // cl@17
  char result; // al@39
  int v6; // ecx@40

  v0 = sub_43B2E0();
  v1 = dword_456B04;
  if ( dword_456B08 )
  {
    *(BYTE *)(dword_456B04 + dword_463E08) = v0;
    v1 = dword_456B04++ + 1;
  }
  if ( dword_456B0C )
  {
    if ( *(BYTE *)(v1 + dword_463E08) == 69
      && *(BYTE *)(v1 + dword_463E08 + 1) == 78
      && *(BYTE *)(v1 + dword_463E08 + 2) == 68 )
      dword_456B0C = 0;
    v0 = *(BYTE *)(v1 + dword_463E08);
    dword_456B04 = v1 + 1;
  }
  if ( isDemo_456B10 )
    v0 = 28;
  if ( configuration.useJoystick <= 0 )
    return v0;
  SDLConfigureJoystick();
  if ( configuration.useJoystick <= 0 )
    return v0;
  ticks = SDL_GetTicks();
  v3 = dword_456B28;
  if ( !dword_456B28 )
    v3 = ticks - 250;
  if ( !dword_456B2C )
    dword_456B2C = ticks - 250;
  v4 = 0;
  if ( !byte_456B00 )
  {
    if ( joystick_x_axis_4A7A44 < joystick_x_axis_default_4AA3E0 - 50 )
      v4 = -53;
    if ( joystick_x_axis_4A7A44 > joystick_x_axis_default_4AA3E0 + 50 )
      v4 = -51;
    if ( joystick_y_axis_4A9EB8 < joystick_y_axis_default_4A9EA0 - 50 )
      v4 = -56;
    if ( joystick_y_axis_4A9EB8 > joystick_y_axis_default_4A9EA0 + 50 )
      v4 = -48;
    if ( byte_463E00[(unsigned __int8)configuration.defaultAccelerateGamepad] )
      v4 = 28;
    if ( byte_463E00[(unsigned __int8)configuration.defaultTurboGamepad] )
      v4 = 1;
    if ( byte_463E00[(unsigned __int8)configuration.defaultGunGamepad] )
      v4 = 28;
    if ( byte_463E00[(unsigned __int8)configuration.defaultMineGamepad] )
      v4 = 1;
  }
  if (ticks < dword_456B1C )
  {
    if ( v4 )
    {
      dword_456B28 = ticks;
      dword_456B2C = ticks;
      return 0;
    }
    dword_456B1C = ticks;
    dword_456B28 = ticks - 400;
    dword_456B2C = ticks;
    return v0;
  }
  if ( v4 )
  {
    if (ticks - v3 >= 400 && ticks - dword_456B2C < 400 )
      dword_456B1C = ticks + 700;
    dword_456B28 = ticks;
    dword_456B2C = ticks;
    result = v4;
  }
  else
  {
    v6 = ticks - 400;
    dword_456B2C = ticks;
    result = v0;
    dword_456B28 = v6;
  }
  return result;
}
//----- (00418090) --------------------------------------------------------
char sub_418090()
{
  char v0; // bl@1
  int v1; // eax@1
  int v2; // eax@13
  int v3; // edx@14
  char result; // al@14

  v0 = sub_43B2D0();
  v1 = dword_456B04;
  if ( dword_456B08 )
  {
    *(BYTE *)(dword_456B04 + dword_463E08) = v0;
    v1 = dword_456B04++ + 1;
  }
  if ( dword_456B0C )
  {
    if ( *(BYTE *)(v1 + dword_463E08) == 69
      && *(BYTE *)(v1 + dword_463E08 + 1) == 78
      && *(BYTE *)(v1 + dword_463E08 + 2) == 68 )
      dword_456B0C = 0;
    v0 = *(BYTE *)(v1 + dword_463E08);
    dword_456B04 = v1 + 1;
  }
  if ( isDemo_456B10 )
    v0 = 13;
  if ( configuration.useJoystick > 0 )
  {
    SDLConfigureJoystick();
    if ( configuration.useJoystick > 0 )
    {
      v2 = SDL_GetTicks();
      if ( v2 >= dword_456B1C )
      {
        v3 = v2 - 400;
        dword_456B34 = v2;
        result = v0;
        dword_456B30 = v3;
        return result;
      }
      dword_456B1C = v2;
      dword_456B30 = v2 - 400;
      dword_456B34 = v2;
    }
  }
  return v0;
}

//----- (00418150) --------------------------------------------------------
int transformJoystickReadValue_418150()
{
  int result; // eax@1

  result = configuration.useJoystick;
  if ( configuration.useJoystick > 0 )
  {
    SDLConfigureJoystick();
    if ( joystick_x_axis_4A7A44 < joystick_x_axis_default_4AA3E0 - 50 )
      byte_45E18B = 1;
    if ( joystick_x_axis_4A7A44 > joystick_x_axis_default_4AA3E0 + 50 )
      byte_45E18D = 1;
    if ( joystick_y_axis_4A9EB8 < joystick_y_axis_default_4A9EA0 - 50 )
      byte_45E188 = 1;
    result = joystick_y_axis_default_4A9EA0 + 50;
    if ( joystick_y_axis_4A9EB8 > joystick_y_axis_default_4A9EA0 + 50 )
      byte_45E190 = 1;
  }
  return result;
}

//----- (004181B0) --------------------------------------------------------

//----- (004181E0) --------------------------------------------------------
//unsigned int sub_4181E0()

//----- (00418330) --------------------------------------------------------
//void decryptAnimFrame()

//----- (004185B0) --------------------------------------------------------
//void   openAnimation(const char *animFile, int a2, char * music, int a4, char * effect, char onKeyPressExit, char screenResolution)

//----- (004189C0) --------------------------------------------------------
int   setPaletteValueWithFloats(float a1, float a2, float a3)
{
  signed int v3; // edi@1
  char v4; // si@1
  float v5; // ST24_4@2
  float v6; // ST20_4@2
  float v7; // ST1C_4@2
  signed int v8; // edi@3
  float v9; // ST24_4@4
  float v10; // ST20_4@4
  float v11; // ST1C_4@4
  int result; // eax@4
  signed int v13; // [sp+0h] [bp-28h]@1
  signed int v14; // [sp+0h] [bp-28h]@3
  double v15; // [sp+10h] [bp-18h]@1
  double v16; // [sp+18h] [bp-10h]@1
  double v17; // [sp+20h] [bp-8h]@1

  v3 = 0;
  v4 = 64;
  v13 = 0;
  v17 = 0.1 * a1;
  v16 = 0.1 * a2;
  v15 = 0.1 * a3;
  do
  {
    v7 = (a3 - v15) * 0.0625;
    v6 = (a2 - v16) * 0.0625;
    v5 = (a1 - v17) * 0.0625;
    setPaletteAndGetValue(
      v4++,
      (unsigned __int64)((double)v13 * v5 + v17),
      (unsigned __int64)(v6 * (double)v13 + v16),
      (unsigned __int64)(v7 * (double)v13 + v15));
    ++v3;
    v13 = v3;
  }
  while ( v3 < 16 );
  v8 = 0;
  v14 = 0;
  do
  {
    v11 = (63.0 - a3) * 0.0625;
    v10 = (63.0 - a2) * 0.0625;
    v9 = (63.0 - a1) * 0.0625;
    result = setPaletteAndGetValue(
               v4++,
               (unsigned __int64)((double)v14 * v9 + a1),
               (unsigned __int64)(v10 * (double)v14 + a2),
               (unsigned __int64)(v11 * (double)v14 + a3));
    ++v8;
    v14 = v8;
  }
  while ( v8 < 16 );
  return result;
}

//----- (00418B00) --------------------------------------------------------
int   sub_418B00(float a1, float a2, float a3)
{
  signed int v3; // edi@1
//  _UNKNOWN *v4; // esi@1
  float v5; // ST24_4@2
  float v6; // ST28_4@2
  float v7; // ST2C_4@2
  float v8; // ST20_4@2
  signed int v9; // edi@3
  _UNKNOWN *v10; // esi@3
  float v11; // ST24_4@4
  float v12; // ST28_4@4
  float v13; // ST2C_4@4
  float v14; // ST20_4@4
  int result; // eax@4
  signed int v16; // [sp+0h] [bp-28h]@1
  signed int v17; // [sp+0h] [bp-28h]@3
  double v18; // [sp+10h] [bp-18h]@1
  double v19; // [sp+18h] [bp-10h]@1
  double v20; // [sp+20h] [bp-8h]@1
  int index;

  v3 = 0;
  v16 = 0;
  //FIXED
 // v4 = &unk_45FF44;
  index = 144;//posiciones desde dword_45FD00 que es el inicio de la paleta
  v18 = 0.1 * a1;
  v19 = 0.1 * a2;
  v20 = 0.1 * a3;
  do
  {
    v8 = (double)v16;
    v5 = (a1 - v18) * 0.0625;
    //*((_DWORD *)v4 - 1) = colorToPaletteEntry((unsigned int)(unsigned __int64)(v8 * v5 + v18) << 16, 6553600);
    v6 = (a2 - v19) * 0.0625;
    //*(_DWORD *)v4 = colorToPaletteEntry((unsigned int)(unsigned __int64)(v8 * v6 + v19) << 16, 6553600);
    v7 = (a3 - v20) * 0.0625;
    ///*((_DWORD *)v4 + 1) = colorToPaletteEntry((unsigned int)(unsigned __int64)(v8 * v7 + v20) << 16, 6553600);
    //v4 = (char *)v4 + 12;*/
	index = index + 3;

	palette1[index] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v8 * v5 + v18) << 16, 6553600);
 	palette1[index +1] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v8 * v6 + v19) << 16, 6553600);
	palette1[index +2] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v8 * v7 + v20) << 16, 6553600);
	
    ++v3;
    v16 = v3;
  }
  while ( v3 < 16 );
  v9 = 0;
  v17 = 0;
  //FIXED
  v10 = &unk_460004;
  do
  {
    v14 = (double)v17;
    v11 = (63.0 - a1) * 0.0625;
    //*((_DWORD *)v10 - 1) = colorToPaletteEntry((unsigned int)(unsigned __int64)(v14 * v11 + a1) << 16, 6553600);
    v12 = (63.0 - a2) * 0.0625;
    //*(_DWORD *)v10 = colorToPaletteEntry((unsigned int)(unsigned __int64)(v14 * v12 + a2) << 16, 6553600);
    v13 = (63.0 - a3) * 0.0625;
   // result = colorToPaletteEntry((unsigned int)(unsigned __int64)(v14 * v13 + a3) << 16, 6553600);
    //*((_DWORD *)v10 + 1) = result;
    v10 = (char *)v10 + 12;

	palette1[index] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v14 * v11 + a1) << 16, 6553600);
	palette1[index + 1] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v14 * v12 + a2) << 16, 6553600);
	palette1[index + 2] = colorToPaletteEntry((unsigned int)(unsigned __int64)(v14 * v13 + a3) << 16, 6553600);
	result = palette1[index + 2];
	index = index + 3;
    ++v9;
    v17 = v9;
  }
  while ( v9 < 16 );
  return result;
}

void freeMemoryGraphics() 
{
	//TODO peta a veces por eso lo quito free(tsahpeBpk_45EB5C); //es una textura pero vete a saber
	free(screenBuffer);
}

//----- (00419950) --------------------------------------------------------
//void loadGraphics2()

//----- (00419EA0) --------------------------------------------------------
int   loadPaletteMenu()
{
	char *v0; // eax@1
  signed int v1; // esi@1
  int v2; // ebp@3
  int v3; // edi@3
  int v4; // ebx@3
  int result; // eax@3
  int v6; // [sp+10h] [bp-304h]@1
  void * v7=malloc(768); // [sp+14h] [bp-300h]@1
//  char v8; // [sp+15h] [bp-2FFh]@1
 
  extractFromBpa("MENU.BPA",v7, "menu.pal");
  v0 = v7; // TODO antes v0 = &v8;
  v6 = v7; // TODO antes v6 = &v8;
  v1 = 0;
   while ( 1 )
  {
    v2 = (unsigned __int8)v0[2];
    v3 = (unsigned __int8)v0[0] << 16;
    v4 = (unsigned __int8)v0[1] << 16;
    palette1[v1] = colorToPaletteEntry((unsigned __int8)*(v0) << 16, 6553600);

    v2 <<= 16;
	palette1[v1+1] = colorToPaletteEntry(v4, 6553600);
	palette1[v1+2] = colorToPaletteEntry(v2, 6553600);
    palette2[v1] = colorToPaletteEntry(v3, 6553600);
	palette2[v1+1] = colorToPaletteEntry(v4, 6553600);
    result = colorToPaletteEntry(v2, 6553600);
	palette2[v1+2] = result;
    v1 += 3;
    v6 += 3;
    if ( v1 >= 768 )
      break;
    v0 = v6;
  }
  result = 0;
  
  return result;
}

//----- (00419F80) --------------------------------------------------------
//void freeMemoryGraphics2()

//----- (0041A140) --------------------------------------------------------
signed int isVesaCompatible()
{
  signed int result; // eax@2

  dword_456BA4 = 0;
  updateScreenPtr(0);
  *(BYTE *)screenPtr = 0;
  updateScreenPtr(1);
  *(BYTE *)screenPtr = 0;
  updateScreenPtr(0);
  *(BYTE *)screenPtr = 1;
  updateScreenPtr(1);
  if ( *(BYTE *)screenPtr == 1 )
  {
    result = 1;
  }
  else
  {
    updateScreenPtr(0);
    *(BYTE *)screenPtr = 0;
    updateScreenPtr(1);
    *(BYTE *)screenPtr = 0;
    result = 0;
  }
  return result;
}
// 456BA4: using guessed type int dword_456BA4;
// 456BF0: using guessed type int screenPtr;

//----- (0041A1C0) --------------------------------------------------------
void refreshBottomScreen() //solo refresca la patte inferior
{
  updateScreenPtr(3);
  copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x30000, 0x4000);
  updateScreenPtr(4);
  copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x40000, 11264);
}
// 456BF0: using guessed type int screenPtr;

//----- (0041A210) --------------------------------------------------------
void refreshAllScreen() //esto refresca la imagen
{
  updateScreenPtr(0);//setea los punteros
  copyBuffer2Screen((void *)screenPtr, screenBuffer, 0x4000);//copia el contenido de una capa a la pantalla
  updateScreenPtr(1);
  copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x10000, 0x4000);
  updateScreenPtr(2);
  copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x20000, 0x4000);
  updateScreenPtr(3);
  copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x30000, 0x4000);  
  updateScreenPtr(4);
  copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x40000, 11264);
}
// 456BF0: using guessed type int screenPtr;

//----- (0041A2D0) --------------------------------------------------------
//unsigned int   drawTextWithFont(int font, int a2, const char *text, int screenPosition)

//----- (0041A370) --------------------------------------------------------
//unsigned int   drawInGamePrices(const char *text, int position)

//----- (0041A430) --------------------------------------------------------
//int   writeTextInScreen(const char *text, int screenOffset)

//signed int   createPopup(int x, int xLenght, int y, int yLenght, int cornerType)

//----- (0041A7A0) --------------------------------------------------------
//int   drawTransparentBlock(int a1, int a2, int a3, int a4)

//----- (0041A880) --------------------------------------------------------

//pinta el menu
//menu type
// 0 es el menu principal
// 1 es comenzar racing
//int   drawMenu(int menuType, int top)

//----- (0041AA40) --------------------------------------------------------
//int   drawKeyCursor(signed int a1, const void *a2, unsigned int a3, int a4)

//----- (0041AB50) --------------------------------------------------------
//int   updateCursor(int a1)

//----- (0041AC50) --------------------------------------------------------
//int   drawCursor(int a1, int a2)

//----- (0041ACF0) --------------------------------------------------------
//int   sub_41ACF0(int a1)

//----- (0041AF40) --------------------------------------------------------
///int   refreshMenuUp(int a1)

//----- (0041B1A0) --------------------------------------------------------
//int   refreshMenuDown(int a1)

//----- (0041B400) --------------------------------------------------------
//unsigned int lappedPopUp()

//----- (0041B4F0) --------------------------------------------------------
//unsigned int winStreakPopUp()

//----- (0041B6A0) --------------------------------------------------------
//unsigned int noPaintJobPopUp()

//----- (0041B850) --------------------------------------------------------
//unsigned int allCarsCrashPopUp()

//----- (0041BA00) --------------------------------------------------------
//int steriodsNotFoundPopup()

//----- (0041BDE0) --------------------------------------------------------
//int killOnePopup()

//----- (0041C230) --------------------------------------------------------
//unsigned int welcomeShopPopup()

//----- (0041C300) --------------------------------------------------------
//unsigned int endGamePopup()

//----- (0041C4C0) --------------------------------------------------------
//int payBackTimePopup()

//----- (0041C770) --------------------------------------------------------
//unsigned int undergroundMarketPopup()

//----- (0041C840) --------------------------------------------------------
//unsigned int welcomePopup()

//----- (0041C9F0) --------------------------------------------------------
//int   getBoxBigTextOffset(const char *a1)

//----- (0041CA40) --------------------------------------------------------
//unsigned int sub_41CA40()

//----- (0041E3B0) --------------------------------------------------------
//char GamepadNotFoundPopup_41E3B0()

//----- (0041E490) --------------------------------------------------------
//int   drawRecordByCircuit(int a1)

// 41E490: using guessed type char Str[20];

//----- (0041E810) --------------------------------------------------------
char drawBottomMenuText()
{
//  signed int v0; // eax@1
//  char *v1; // esi@2
//  char *v2; // edi@2
//  int v3; // ebp@3
//  const char *v4; // edi@3
//  int v5; // esi@3
///  char result; // al@4

	

  drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "         Welcome to DreeRally - Windows Version 0.2", 640 * 395);
  drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "           Follow us on https://www.dreerally.com", 640 * 410);
  //drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "    See more developments at https://github.com/enriquesomolinos", 640 * 425);
  //drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "       (c)Remedy Entertainment - http://www.remedygames.com", 640 * 425);
  drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "  Use arrow keys to change selection and press enter to confirm.", 640 * 425);

  /*

  v0 = 243200;
  do
  {
    v1 = (char *)graphicsGeneral.menubg5Bpk + v0;
    v2 = (char *)screenBuffer + v0;
    v0 += 640;
    memcpy(v2, v1, 0x280u);
  }
  while ( v0 < 300160 );
  v3 = 0;
  v4 = (const char *)&unk_462960;
  v5 = 241932;
  do
  {
    result = *((BYTE *)&word_461ED0 + v3);
    if ( !result )
      result = drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, v4, v5);
    if ( *((BYTE *)&word_461ED0 + v3) == 1 )
      result = drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, v4, v5);
    if ( *((BYTE *)&word_461ED0 + v3) == 2 )
      result = drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, v4, v5);
    v5 += 9600;
    ++v3;
    v4 += 150;
  }
  while ( v5 < 299532 );
  return result;*/
  return 0;
}
// 4458B0: using guessed type char letterSpacing_4458B0;
// 461ED0: using guessed type __int16 word_461ED0;

//----- (0041E8D0) --------------------------------------------------------
char sub_41E8D0()
{
  signed int v0; // eax@1
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
  while ( v0 < 224000 );
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
  return result;
}
// 4458B0: using guessed type char letterSpacing_4458B0;

//----- (0041E9A0) --------------------------------------------------------

// 4458B0: using guessed type char letterSpacing_4458B0;

//----- (0041EA70) --------------------------------------------------------

// 45E064: using guessed type int dword_45E064;
// 45EA04: using guessed type int isMultiplayerGame;

//----- (0041EB80) --------------------------------------------------------

//----- (0041ED20) --------------------------------------------------------
int   sub_41ED20(float a1, float a2, float a3)
{
  float v3; // ST2C_4@2
  signed int v4; // esi@1
  float v5; // ST30_4@4
  float v6; // ST34_4@6
  double v7; // st7@2
  signed int v8; // ebx@4
  signed int v9; // edi@6
  int result; // eax@8
  signed int v11; // [sp+0h] [bp-2Ch]@1
  signed int v12; // [sp+4h] [bp-28h]@2

  v11 = 0;
  v4 = 528;
  
  do
  {
  v7 = (double)v11;
  v3 = a1 * 0.14285715;
  v12 = (unsigned __int64)(v3 * v7 + a1 * 0.1666666666666667);
  if ( v12 > 63 )
  v12 = 63;
  v5 = a2 * 0.14285715;
  v8 = (unsigned __int64)(v5 * v7 + a2 * 0.1666666666666667);
  if ( v8 > 63 )
  v8 = 63;
  v6 = a3 * 0.14285715;
  v9 = (unsigned __int64)(v7 * v6 + a3 * 0.1666666666666667);
  if ( v9 > 63 )
  v9 = 63;
  palette1[v4] = colorToPaletteEntry(v12 << 16, 6553600);
  palette1[v4+1] = colorToPaletteEntry(v8 << 16, 6553600);
  result = colorToPaletteEntry(v9 << 16, 6553600);
  palette1[v4+2] = result;
  v4 += 3;
  ++v11;
  }
  while ( v4 < 16 );
  /*v4 = (signed int)&unk_460484;
  do
  {
    v7 = (double)v11;
    v3 = a1 * 0.14285715;
    v12 = (unsigned __int64)(v3 * v7 + a1 * 0.1666666666666667);
    if ( v12 > 63 )
      v12 = 63;
    v5 = a2 * 0.14285715;
    v8 = (unsigned __int64)(v5 * v7 + a2 * 0.1666666666666667);
    if ( v8 > 63 )
      v8 = 63;
    v6 = a3 * 0.14285715;
    v9 = (unsigned __int64)(v7 * v6 + a3 * 0.1666666666666667);
    if ( v9 > 63 )
      v9 = 63;
    *(_DWORD *)(v4 - 4) = colorToPaletteEntry(v12 << 16, 6553600);
    *(_DWORD *)v4 = colorToPaletteEntry(v8 << 16, 6553600);
    result = colorToPaletteEntry(v9 << 16, 6553600);
    *(_DWORD *)(v4 + 4) = result;
    v4 += 12;
    ++v11;
  }
  while ( v4 < (signed int)&unk_4604D8 );*/
  
  return result;
}

void * getEngineBpkById(int engineId) {
	if (engineId == 0) {
		return engi1Bpk;
	}
	else if (engineId == 1) {
		return engi2Bpk;
	}
	else if (engineId == 2) {
		return engi3Bpk;
	}
	else {
		return engi4Bpk;
	}
}

void * getSceneCarBpkById(int carId) {
	if (carId == 0) {
		return scenecar1Bpk;
	}
	else if (carId == 1) {
		return scenecar2Bpk;
	}
	else if (carId == 2) {
		return scenecar3Bpk;
	}
	else if (carId == 3) {
		return scenecar4Bpk;
	}
	else if (carId == 4) {
		return scenecar5Bpk;
	}
	else {
		return scenecar6Bpk;
	}

}

void * getArmourBpkById(int armourId) {
	if (armourId == 0) {
		return armor1Bpk;
	}
	else if (armourId == 1) {
		return armor2Bpk;
	}
	else if (armourId == 2) {
		return armor3Bpk;
	}
	else {
		return armor4Bpk;
	}
}
void * getTireBpkById(int tireId) {
	if (tireId == 0) {
		return tire1Bpk;
	}
	else if (tireId == 1) {
		return tire2Bpk;
	}
	else if (tireId == 2) {
		return tire3Bpk;
	}
	else {
		return tire4Bpk;
	}
}

void * getCarBpkById(int carId) {
	if (carId == 0) {
		return kuplaBpk;
	}
	else if (carId == 1) {
		return pickupBpk;
	}
	else if (carId == 2) {
		return sedanBpk;
	}
	else if (carId == 3) {
		return camaroBpk;
	}
	else if (carId == 4) {
		return porscheBpk;
	}
	else  {
		return lotusBpk;
	}
	

}

//----- (0041EE40) --------------------------------------------------------
void loadGraphics3()
{
  
  int v0;
  v0 = drivers[driverId].carType;
  dword_45EAA4 = 100;
  dword_461EEC = 0;
  continueAnimCurrentFrame_4611D0 = 0;
  armourAnimFrameDirection_45F034 = 0;
  armourAnimCurrentFrame_461288 = 0;
  tireAnimCurrentFrame_45F034 = 0;
  engineAnimCurrentFrame_462D80 = 0;
  carAnimCurrentFrame_45FBA0 = 0;
  menuOptionSelected_463DF0 = 5;
  if ( v0 >= 5 )
    actualCarSelected = 5;
  else
    actualCarSelected = v0 + 1;
  
  dword_461ED8 = malloc(0x4B000u);
  dword_45FC00 = (int)dword_461ED8;
  drugdealBpk = malloc(0x3400u);
  spons1bBpk = malloc(0x3400u);
  event2Bpk = malloc(0x3400u);
  reaperxBpk = malloc(0x3400u);
  
  statbas7Bpk = malloc(0x5400u);
  
  statpop4Bpk = malloc(0x4B0u);
  
  fsma3fBpk = malloc(0x8F0u);
  
  choo2Bpk = malloc(0x900u);
  
  arrows1dBpk = malloc(0x1000u);
  
  maxi1fBpk = malloc(0x12000u);
  kuplaBpk = malloc(0x1AF00u);
  pickupBpk = malloc(0x1A77Bu);
  sedanBpk = malloc(0x18F14u);
  camaroBpk = malloc(0x18F51u);
  porscheBpk = malloc(0x1A060u);
  lotusBpk = malloc(0x1BEA2u);
  scenecar1Bpk = malloc(0x1800u);
  scenecar2Bpk = malloc(0x1800u);
  scenecar3Bpk = malloc(0x1800u);
  scenecar4Bpk = malloc(0x1800u);
  scenecar5Bpk = malloc(0x1800u);
  scenecar6Bpk = malloc(0x1800u);
  engi1Bpk = malloc(0xA235u);
  engi2Bpk = malloc(0xAE36u);
  engi3Bpk = malloc(0xB413u);
  engi4Bpk = malloc(0xD788u);
  tire1Bpk = malloc(0x511Cu);
  tire2Bpk = malloc(0x52B8u);
  tire3Bpk = malloc(0x5724u);
  tire4Bpk = malloc(0x5F1Eu);
  armor1Bpk = malloc(0x5FFBu);
  armor2Bpk = malloc(0x6DD9u);
  armor3Bpk = malloc(0x7922u);
  armor4Bpk = malloc(0x7801u);
  repaaniBpk = malloc(0x878Bu);
  contaniBpk = malloc(0x8AE9u);
  dword_461EA4 = malloc(0x2800u);
  volcur2Bpk = malloc(0xF0u);
  slidcur3Bpk = malloc(0xF0u);
  slidcop2Bpk = malloc(0x1260u);
  slidmus2Bpk = malloc(0x1020u);
  carnameBpk = malloc(0x2400u);
  carbas2Bpk = malloc(0x2400u);
  bases41Bpk = malloc(0x2400u);
  bases42Bpk = malloc(0x2400u);
  bases43Bpk = malloc(0x2400u);
  bases44Bpk = malloc(0x2400u);
  bases45Bpk = malloc(0x2400u);
  maret1eBpk = malloc(0x1B000u);
  dealer2bBpk = malloc(0x2400u);
  blacktx1Bpk = malloc(0x2800u);
  blacktx2Bpk = malloc(0x2800u);
  extractFromBpa("MENU.BPA", textureTemp, "statbas7.bpk");
  copyImageToBuffer((int)textureTemp, (int)statbas7Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "statpop4.bpk");
  copyImageToBuffer((int)textureTemp, (int)statpop4Bpk);
  extractFromBpa("MENU.BPA", textureTemp,"f-sma3f.bpk");
  copyImageToBuffer((int)textureTemp, (int)fsma3fBpk);
  extractFromBpa("MENU.BPA", kuplaBpk,"kupla.bpk");
  extractFromBpa("MENU.BPA", pickupBpk, "pickup.bpk");
  extractFromBpa("MENU.BPA", sedanBpk, "sedan.bpk");
  extractFromBpa("MENU.BPA", camaroBpk, "camaro.bpk");
  extractFromBpa("MENU.BPA", porscheBpk, "porsche.bpk");
  extractFromBpa("MENU.BPA", lotusBpk, "lotus.bpk");
  extractFromBpa("MENU.BPA", engi1Bpk, "engi1.bpk");
  extractFromBpa("MENU.BPA", engi2Bpk, "engi2.bpk");
  extractFromBpa("MENU.BPA", engi3Bpk, "engi3.bpk");
  extractFromBpa("MENU.BPA", engi4Bpk, "engi4.bpk");
  extractFromBpa("MENU.BPA", tire1Bpk, "tire1.bpk");
  extractFromBpa("MENU.BPA", tire2Bpk, "tire2.bpk");
  extractFromBpa("MENU.BPA", tire3Bpk, "tire3.bpk");
  extractFromBpa("MENU.BPA", tire4Bpk, "tire4.bpk");
  extractFromBpa("MENU.BPA", armor1Bpk, "armor1.bpk");
  extractFromBpa("MENU.BPA", armor2Bpk, "armor2.bpk");
  extractFromBpa("MENU.BPA", armor3Bpk, "armor3.bpk");
  extractFromBpa("MENU.BPA", armor4Bpk, "armor4.bpk");
  extractFromBpa("MENU.BPA", contaniBpk, "contani.bpk");
  extractFromBpa("MENU.BPA", repaaniBpk, "repaani.bpk");
  extractFromBpa("MENU.BPA", textureTemp, "carbas2.bpk");
  copyImageToBuffer((int)textureTemp, (int)carbas2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "spons1b.bpk");
  copyImageToBuffer((int)textureTemp, (int)spons1bBpk);
  extractFromBpa("MENU.BPA", textureTemp, "drugdeal.bpk");
  copyImageToBuffer((int)textureTemp, (int)drugdealBpk);
  extractFromBpa("MENU.BPA", textureTemp, "event_2.bpk");
  copyImageToBuffer((int)textureTemp, (int)event2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "reaper_x.bpk");
  copyImageToBuffer((int)textureTemp, (int)reaperxBpk);
  extractFromBpa("MENU.BPA", textureTemp, "blacktx1.bpk");
  copyImageToBuffer((int)textureTemp, (int)blacktx1Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "blacktx2.bpk");
  copyImageToBuffer((int)textureTemp, (int)blacktx2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "dealer2b.bpk");
  copyImageToBuffer((int)textureTemp, (int)dealer2bBpk);
  extractFromBpa("MENU.BPA", textureTemp, "market1e.bpk");
  copyImageToBuffer((int)textureTemp, (int)maret1eBpk);
  extractFromBpa("MENU.BPA", textureTemp, "bases4.bpk");
  decryptTexture((int)textureTemp, (int)bases41Bpk, 0, 9216);
  decryptTexture((int)textureTemp, (int)bases42Bpk, 9216, 9216);
  decryptTexture((int)textureTemp, (int)bases43Bpk, 18432, 9216);
  decryptTexture((int)textureTemp, (int)bases44Bpk, 27648, 9216);
  decryptTexture((int)textureTemp, (int)bases45Bpk, 36864, 9216);
  extractFromBpa("MENU.BPA", textureTemp, "scenecar.bpk");
  decryptTexture((int)textureTemp, (int)scenecar1Bpk, 0, 6144);
  decryptTexture((int)textureTemp, (int)scenecar2Bpk, 6144, 6144);
  decryptTexture((int)textureTemp, (int)scenecar3Bpk, 12288, 6144);
  decryptTexture((int)textureTemp, (int)scenecar4Bpk, 18432, 6144);
  decryptTexture((int)textureTemp, (int)scenecar5Bpk, 24576, 6144);
  decryptTexture((int)textureTemp, (int)scenecar6Bpk, 30720, 6144);
  extractFromBpa("MENU.BPA", textureTemp,"choo2.bpk");
  copyImageToBuffer((int)textureTemp, (int)choo2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "arrows1d.bpk");
  copyImageToBuffer((int)textureTemp, (int)arrows1dBpk);
  extractFromBpa("MENU.BPA", textureTemp, "maxi1f.bpk");
  copyImageToBuffer((int)textureTemp, (int)maxi1fBpk);
  extractFromBpa("MENU.BPA", textureTemp, "carname.bpk");
  copyImageToBuffer((int)textureTemp, (int)carnameBpk);
  extractFromBpa("MENU.BPA", textureTemp, "slidmus2.bpk");
  copyImageToBuffer((int)textureTemp, (int)slidmus2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "slidcur3.bpk");
  copyImageToBuffer((int)textureTemp, (int)slidcur3Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "volcur2.bpk");
  copyImageToBuffer((int)textureTemp, (int)volcur2Bpk);
  extractFromBpa("MENU.BPA", textureTemp, "slidcop2.bpk");
  copyImageToBuffer((int)textureTemp, (int)slidcop2Bpk);
}

//----- (0041F7D0) --------------------------------------------------------
void freeMemoryGraphics3()
{
  free(dword_461ED8);
  free(statbas7Bpk);
  free(statpop4Bpk);
  free(fsma3fBpk);
  free(choo2Bpk);
  free(arrows1dBpk);
  free(maxi1fBpk);
  free(scenecar1Bpk);
  free(scenecar2Bpk);
  free(scenecar3Bpk);
  free(scenecar4Bpk);
  free(scenecar5Bpk);
  free(scenecar6Bpk);
  free(kuplaBpk);
  free(pickupBpk);
  free(sedanBpk);
  free(camaroBpk);
  free(porscheBpk);
  free(lotusBpk);
  free(engi1Bpk);
  free(engi2Bpk);
  free(engi3Bpk);
  free(engi4Bpk);
  free(tire1Bpk);
  free(tire2Bpk);
  free(tire3Bpk);
  free(tire4Bpk);
  free(armor1Bpk);
  free(armor2Bpk);
  free(armor3Bpk);
  free(armor4Bpk);
  free(repaaniBpk);
  free(contaniBpk);
  
//TODO FIX peta no se porque	free(dword_461EA4);
  free(drugdealBpk);
  free(spons1bBpk);
  free(event2Bpk);
  free(reaperxBpk);
  free(volcur2Bpk);
  free(slidcur3Bpk);
  free(slidcop2Bpk);
  free(slidmus2Bpk);
  //TODO FIX peta no se porque   free(carnameBpk);
  free(carbas2Bpk);
  free(bases41Bpk);
  free(bases42Bpk);
  free(bases43Bpk);
  free(bases44Bpk);
  free(bases45Bpk);
  free(maret1eBpk);
  free(dealer2bBpk);
  free(blacktx1Bpk);
  free(blacktx2Bpk);
}

//----- (0041FA50) --------------------------------------------------------
//int   sub_41FA50(const char *a1)

//----- (0041FAB0) --------------------------------------------------------
//int   getBoxTextOffset(const char *a1)

// 445916: using guessed type char byte_445916;

//----- (0041FB20) --------------------------------------------------------
//int   getBoxTextSize(const char *a1)

//----- (0041FB70) --------------------------------------------------------
//int   getNameOffsetPositionRight(const char *a1)

//----- (0041FBD0) --------------------------------------------------------
//int   getBigTextMidSize(const char *a1)

//----- (0041FC20) --------------------------------------------------------
int drawCarRightSide()
{
//  char *v0; // eax@1
//  char *v1; // edx@1
//  char v2; // cl@2
  int namePosition; // eax@3
  int *v4; // eax@3
  unsigned int v5; // eax@5
  char *v6; // edi@5
  char v7; // cl@6
  int money; // eax@7
//  unsigned int v9; // eax@9
//  char *v10; // edi@9
//  char v11; // cl@10
  int v12; // edx@11
//  char *v13; // edi@13
//  char v14; // al@14
//  unsigned int v15; // eax@15
//  char *v16; // edi@15
//  char v17; // cl@16
  int v18; // edx@17
  signed int v19; // esi@17
  unsigned __int64 v20; // rax@18
  char *v21; // edi@18
  int v22; // eax@19
  char v23; // cl@20
  char *v24; // eax@21
  int v25; // edi@21
  unsigned int v26; // edx@21
  char v27; // cl@22
  int v28; // eax@25
  int v29; // esi@25
  int v30; // edi@26
  int v31; // esi@28
  int v32; // edi@29
  int v33; // esi@31
  int v34; // edi@32
  int v35; // ebp@34
  int v36; // edi@35
  int v37; // esi@35
  int v38; // ebp@37
  int v39; // edi@38
  int v40; // esi@38
  int result; // eax@40
  int v42; // ebx@40
  int v43; // edi@41
  int v44; // esi@41
  int v45; // [sp+1Ch] [bp-2Ch]@5
 
  char *DstBuf=malloc(20); // [sp+34h] [bp-14h]@
  char *Str=malloc(20); // [sp+20h] [bp-28h]@1
  char *moneyCount = malloc(20);
  drawImageWithPosition2((int)statbas7Bpk, 96, 224, (int)((char *)screenBuffer + 80544));
  drawImageWithPosition2(getSceneCarBpkById(drivers[driverId].carType), 96, 64, (int)((char *)screenBuffer + 90784));
  //drawImageWithPosition2((int)*(&scenecar1Bpk + dword_46085C[27 * driverId]), 96, 64, (int)((char *)screenBuffer + 90784));
  /*v0 = &byte_460840[108 * driverId];
  v0 = &byte_460840[108 * driverId];
  v1 = (char *)(Str - v0);
  do
  {
    v2 = *v0;
    v0[(_DWORD)v1] = *v0;
    ++v0;
  }
  while ( v2 );
  strupr(Str);
  /*esto creo que no es necesario*/
  //name = getNameOffsetPositionRight(Str);
  memcpy(Str, drivers[driverId].name, strlen(drivers[driverId].name));
  memset(&Str[strlen(drivers[driverId].name)], '\0', 1);
  _strupr(Str);
  namePosition = getNameOffsetPositionRight(Str);
  
  drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, namePosition + 81184);
  v4 = drivers[driverId].money;
  //v4 = &dword_460870[27 * driverId];
  if (drivers[driverId].money > 9999999 )
  //if (dword_460870[27 * driverId] > 9999999)
	  drivers[driverId].money = 9999999;
  _itoa(v4, DstBuf, 10);
  strcpy(moneyCount, "$");
  memcpy(&moneyCount[1], DstBuf, strlen(DstBuf));
  memset(&moneyCount[strlen(DstBuf)+1], '\0',1);
  
  v5 = strlen(DstBuf) + 1;
  v6 = (char *)&v45 + 3;
  do
    v7 = (v6++)[1];
  while ( v7 );
  memcpy(v6, DstBuf, v5);
  money = sub_41FA50(moneyCount);//size small text
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, moneyCount, money + 131744);
  
  ///calculo de la velocidad a partir de la velocidad inicial que es  initialVelocity (55)
  _itoa(initialVelocity + drivers[driverId].engine*5 + 5 * drivers[driverId].carType, DstBuf, 10);
  //itoa(*(&initialVelocity + dword_460850[27 * driverId] + 5 * dword_46085C[27 * driverId]), DstBuf, 10);
  Str[0] = 0;
  Str[1] = 0;
  Str[2] = 0;
  Str[3] = 0;
  if ( strlen(DstBuf) == 2 )
    strcpy(Str, " ");
  v12 = (int)graphicsGeneral.fmed1aBpk;
  

  memcpy( &Str[3- strlen(DstBuf)], DstBuf, strlen(DstBuf));
  
  //pinta la velocidad de motor
  drawTextWithFont(v12, (int)&unk_445928, Str, 204768);
  _itoa(drivers[driverId].rank, DstBuf, 10);
  //itoa(dword_460888[27 * driverId], DstBuf, 10);
  Str[0] = 0;
  Str[1] = "#";
  Str[2] = 0;
  Str[3] = 0;
  if (strlen(DstBuf) == 1) {
	  strcpy(Str, " #");
	  memcpy(&Str[2], DstBuf, strlen(DstBuf));
  }
  else {
	  strcpy(Str, "#");
	  memcpy(&Str[1], DstBuf, strlen(DstBuf));
  }
  v18 = (int)graphicsGeneral.fmed1aBpk;
  
  //pinta #20
  drawTextWithFont(v18, (int)&unk_445928, Str, 214368);
  v19 = 0;
  do
  {
    v20 = (unsigned __int64)ceil((double)drivers[driverId].damage * 0.44);
    v21 = (char *)screenBuffer + v19 + 196388;
    memset(v21, 0x3Fu, 4 * ((unsigned int)v20 >> 2));
    v19 += 640;
    memset(&v21[4 * ((unsigned int)v20 >> 2)], 63, v20 & 3);
  }
  while ( v19 < 3200 );
  _itoa(drivers[driverId].damage, DstBuf, 10);
  v22 = 0;
  do
  {
    v23 = DstBuf[v22];
    Str[v22++] = v23;
  }
  while ( v23 );
  v24 = Str;
  v25 = 0;
  v26 = 0;
  do
    v27 = *v24++;
  while ( v27 );
  v45 = v24 - &Str[1];
  if ( v24 != &Str[1] )
  {
    do
      v25 += (unsigned __int8)byte_445892[(unsigned __int8)Str[v26++]];
    while ( v26 < strlen(Str) );
  }
  drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, Str, 193903 - v25);
  v28 = driverId;
  v29 = 0;
  //dword_44E5F0 contiene los datos del coche dword_44E5F4 dword_44E5F8 engine tire armour muestra los upgrades posibles
   
	if (cars[drivers[driverId].carType].engineUpgrades> 0 )
//if (dword_44E5F0[440 * dword_46085C[27 * driverId]] > 0 )
  {
    v30 = 0;
    do
    {
      drawImageWithPosition2((int)((char *)statpop4Bpk + 800), 20, 10, (int)((char *)screenBuffer + v30 + 149667));
      v28 = driverId;
      ++v29;
      v30 += 23;
    }
	//while (v29 < dword_44E5F0[440 * dword_46085C[27 * driverId]]);
    while ( v29 < cars[drivers[driverId].carType].engineUpgrades);
  }
  v31 = 0;
  if (cars[drivers[driverId].carType].tireUpgrades > 0 )
//	  if (dword_44E5F4[440 * dword_46085C[27 * v28]] > 0)
  {
    v32 = 0;
    do
    {
      drawImageWithPosition2((int)((char *)statpop4Bpk + 800), 20, 10, (int)((char *)screenBuffer + v32 + 165027));
      v28 = driverId;
      ++v31;
      v32 += 23;
    }
    while ( v31 < cars[drivers[driverId].carType].tireUpgrades);
//  while ( v31 < dword_44E5F4[440 * dword_46085C[27 * driverId]] );
  }
  v33 = 0;
  if (cars[drivers[driverId].carType].armourUpgrades > 0 )
	  //if (dword_44E5F8[440 * dword_46085C[27 * v28]] > 0)
  {
    v34 = 0;
    do
    {
      drawImageWithPosition2((int)((char *)statpop4Bpk + 800), 20, 10, (int)((char *)screenBuffer + v34 + 180387));
      v28 = driverId;
      ++v33;
      v34 += 23;
    }
    while ( v33 < cars[drivers[driverId].carType].armourUpgrades);
	//while (v33 < dword_44E5F8[440 * dword_46085C[27 * driverId]]);
  }
  v35 = 0;
  //pinta los upgrades
  if (drivers[driverId].engine> 0 )
	  //if (dword_460850[27 * v28] > 0)
  {
    v36 = 0;
    v37 = 0;
    do
    {
      drawImageWithPosition2((int)((char *)statpop4Bpk + v36), 20, 10, (int)((char *)screenBuffer + v37 + 149667));
      v28 = driverId;
      ++v35;
      v37 += 23;
      v36 += 200;
    }
    while ( v35 < drivers[driverId].engine);
	//while (v35 < dword_460850[27 * driverId]);
  }
  v38 = 0;
  if (drivers[driverId].tire > 0 )
	  //if (dword_460854[27 * v28] > 0)
  {
    v39 = 0;
    v40 = 0;
    do
    {
      drawImageWithPosition2((int)((char *)statpop4Bpk + v39), 20, 10, (int)((char *)screenBuffer + v40 + 165027));
      v28 = driverId;
      ++v38;
      v40 += 23;
      v39 += 200;
    }
    while ( v38 < drivers[driverId].tire);
	//while (v38 < dword_460854[27 * driverId]);
  }
  result = 27 * v28;
  v42 = 0;
  if (drivers[driverId].armour > 0 )
//if ( dword_460858[result] > 0 )
  {
    v43 = 0;
    v44 = 0;
    do
    {
      drawImageWithPosition2((int)((char *)statpop4Bpk + v43), 20, 10, (int)((char *)screenBuffer + v44 + 180387));
      result = 27 * driverId;
      ++v42;
      v44 += 23;
      v43 += 200;
    }
    while ( v42 < drivers[driverId].armour);
	//while ( v42 < dword_460858[27 * driverId] );

  }
  return result * 4;
}

//----- (004201F0) --------------------------------------------------------
//int   drawMenuAnimation(int x, int y, int frame, int animation, int frameSizes[])

//----- (00420250) --------------------------------------------------------
//int reloadCarAnimation2()
//----- (004204F0) --------------------------------------------------------
//int reloadEngineAnimation2()

//----- (004207E0) --------------------------------------------------------
//int reloadTireAnimation2()

//----- (00420A80) --------------------------------------------------------
//int reloadArmourAnimation2()

//----- (00420D20) --------------------------------------------------------
//int reloadRepairAnimation()

//----- (00421010) --------------------------------------------------------
//int loadAcceptedText()

//----- (004210C0) --------------------------------------------------------
//int showCarBought()

//----- (004212F0) --------------------------------------------------------
//int reloadEngineAnimation()

//----- (00421520) --------------------------------------------------------
//int reloadTireAnimation()

//----- (00421750) --------------------------------------------------------
//int reloadArmourAnimation()

//----- (00421980) --------------------------------------------------------
int   sub_421980(int a1, int a2, int a3, int a4)
{
  int v4; // edi@1
  int v5; // ebx@1
  int result; // eax@1
  int i; // ecx@1
  char *v8; // edx@2
  int j; // ecx@3
  char *v10; // edx@4
  int v11; // ecx@6
  char *v12; // edx@7
  char *v13; // edx@10

  v4 = 640 * a2;
  drawImageWithPosition((int)choo2Bpk, 24, 12, (int)((char *)screenBuffer + 640 * a2 + a1));
  drawImageWithPosition((int)((char *)choo2Bpk + 576), 24, 12, (int)((char *)screenBuffer + 640 * a2 + a1 + a3 - 24));
  drawImageWithPosition((int)((char *)choo2Bpk + 1440), 24, 12, (int)((char *)screenBuffer + 128 * (5 * (a4 + a2) - 60) + a1));
  v5 = 640 * (a4 + a2);
  drawImageWithPosition((int)((char *)choo2Bpk + 2016), 24, 12, (int)((char *)screenBuffer + v5 + a1 + a3 - 7704));
  result = a3 - 48;
  for ( i = 0; i < result; v8[a1 + 1304] = 22 )
    v8 = (char *)screenBuffer + v4 + i++;
  for ( j = 0; j < result; v10[a1 - 1896] = 22 )
    v10 = (char *)screenBuffer + v5 + j++;
  if ( a4 - 48 > 0 )
  {
    result = 640 * a2;
    v11 = a4 - 48;
    do
    {
      v12 = (char *)screenBuffer + result;
      result += 640;
      --v11;
      v12[a1 + 15362] = 22;
    }
    while ( v11 );
    if ( a4 - 48 > 0 )
    {
      result = a4 - 48;
      do
      {
        v13 = (char *)screenBuffer + v4 + a1;
        v4 += 640;
        --result;
        v13[a3 + 15357] = 22;
      }
      while ( result );
    }
  }
  return result;
}

//----- (00421AE0) --------------------------------------------------------
//int   drawBorder(int a1, int a2, int a3, int a4)

//----- (00421C40) --------------------------------------------------------
//int   drawBorder2(int a1, int a2, unsigned int a3, int a4)

//----- (00421D90) --------------------------------------------------------
//void shopScreenMoveUp_421D90()

//----- (00421DF0) --------------------------------------------------------
//void shopScreenMoveDown_421DF0()

// 445198: using guessed type int dword_445198;
// 45DC18: using guessed type int configuration.effectsVolume;
// 463DF0: using guessed type int menuOptionSelected_463DF0;

//----- (00421E50) --------------------------------------------------------
signed int   hasInsuficientMoneyToBuy(int a1)
{
  signed int v1; // edx@2
  char *v2; // edi@3
  unsigned int v3; // eax@4
  void *v4; // edi@4
  char v5; // cl@5
  char *v6; // edi@6
  char v7; // al@7
  signed int result; // eax@8
  char *DstBuf = malloc(100); // [sp+4h] [bp-34h]@4
  char v10; // [sp+17h] [bp-21h]@4
  int v11; // [sp+18h] [bp-20h]@4
  int v12; // [sp+1Ch] [bp-1Ch]@4
  int v13; // [sp+20h] [bp-18h]@4
  int v14; // [sp+24h] [bp-14h]@4
  __int16 v15; // [sp+28h] [bp-10h]@4

  if ( drivers[driverId].money >= a1 )
  {
    result = 0;
  }
  else
  {
    v1 = 0;
    do
    {
      v2 = (char *)screenBuffer + v1 + 89770;
      memset(v2, 0xC4u, 0x158u);
      v2 += 344;
      *(_WORD *)v2 = -15164;
      v1 += 640;
      v2[2] = -60;
    }
    while ( v1 < 51200 );
    _itoa(a1 - drivers[driverId].money, DstBuf, 10);
    v11 = 1701736296;
    v12 = 1528835705;
    v14 = 543519329;
    v13 = 544567129;
    v15 = 36;
    v3 = strlen(DstBuf) + 1;
    v4 = &v10;
    do
    {
      v5 = *((BYTE *)v4 + 1);
      v4 = (char *)v4 + 1;
    }
    while ( v5 );
    memcpy(v4, DstBuf, v3);
    v6 = &v10;
    do
      v7 = (v6++)[1];
    while ( v7 );
   // *(_DWORD *)v6 = 1752390432; //hs[
   // *((_DWORD *)v6 + 1) = 779383407; //.tro
    //v6[8] = 0;
    writeTextInScreen("No dough, no go, bro. No money,", 100010);
    writeTextInScreen((const char *)&v11, 110250);
    writeTextInScreen("Gotta earn it. Go do it already.", 120490);
    refreshAllScreen();
    loadMenuSoundEffect(2u, 23, 0, configuration.effectsVolume, dword_44518C);
    framesToWaitAfterBuy_456B70 = 310;
    result = 1;
  }
  return result;
}
// 44518C: using guessed type int dword_44518C;
// 456B70: using guessed type int framesToWaitAfterBuy_456B70;
// 45DC18: using guessed type int configuration.effectsVolume;
// 460870: using guessed type int dword_460870[];
// 463CE8: using guessed type int driverId;

//----- (00421FB0) --------------------------------------------------------
//signed int setUndergroundMarketPrices()

//----- (004220D0) --------------------------------------------------------
int sub_4220D0()
{
  unsigned __int8 v0; // di@1
  signed int v1; // esi@1
  int v2; // ST0C_4@2
  int v3; // ST08_4@2
  int v4; // eax@2
  int result; // eax@5

  v0 = 16;
  v1 = (signed int)dword_461364;
  do
  {
    v2 = (convertColorToPaletteColor(*(_DWORD *)(v1 + 4), dword_45EAA4 << 16) + 0x8000) >> 16;
    v3 = (convertColorToPaletteColor(*(_DWORD *)v1, dword_45EAA4 << 16) + 0x8000) >> 16;
    v4 = convertColorToPaletteColor(*(_DWORD *)(v1 - 4), dword_45EAA4 << 16);
    setPaletteAndGetValue(v0, (v4 + 0x8000) >> 16, v3, v2);
    v1 += 12;
    ++v0;
  }
  //while ( v1 < (signed int)&unk_461424 );
  while (v1 < maxPaletteEntries*3);
  if ( dword_45EAA4 == 49 )
  {
    dword_461EEC = 1;
LABEL_5:
    result = dword_45EAA4 + 3;
    dword_45EAA4 += 3;
    return result;
  }
  if ( dword_45EAA4 == 100 )
  {
    result = 97;
    dword_461EEC = 0;
    dword_45EAA4 = 97;
  }
  else
  {
    if ( dword_461EEC )
      goto LABEL_5;
    result = dword_45EAA4 - 3;
    dword_45EAA4 -= 3;
  }
  return result;
}

//----- (004221A0) --------------------------------------------------------
signed int autoLoadSave()
{
  signed int v0; // ebp@1
  void *v1=malloc(0x883u); // eax@3
  int v2; // edi@3
  int v3; // eax@3
  int v4; // edx@3
  int *v5; // eax@3
  unsigned int v6; // ecx@3
  char v7; // bl@4
  unsigned int v8; // ebx@7
  FILE *v9; // esi@10
  void *v10=malloc(0x883u); // eax@12
  int v11; // edi@12
  FILE *v12; // eax@12
  FILE *v13; // esi@12
  unsigned int v14; // ebx@13
  int v15; // ebx@15
  int v16; // edi@15
  int v17; // esi@15
  signed int result; // eax@16
  char v19; // [sp+4h] [bp-18h]@3
  char v20; // [sp+4h] [bp-18h]@13
  int v21; // [sp+Ch] [bp-10h]@3
  int v22; // [sp+10h] [bp-Ch]@3
  int v23; // [sp+14h] [bp-8h]@3
  __int16 v24; // [sp+18h] [bp-4h]@3
  char v25; // [sp+1Ah] [bp-2h]@3

  v0 = 0;
  if ( isMultiplayerGame )
  {
    result = 0;
  }
  else
  {
    if ( keysRead_45E0C0[KEY_F2] )
    {
      v0 = 1;
      //allocateMemory(0x883u);
      Str = v1;
      memset(v1, 0, 0x880u);
      v2 = (int)((char *)v1 + 2176);
      *(_WORD *)v2 = 0;
      *(BYTE *)(v2 + 2) = 0;
      v3 = rand();
      v4 = v3 % 255;
      *(BYTE *)Str = v3 % 255;
      *((BYTE *)Str + 1) = driverId;
      *((BYTE *)Str + 2) = useWeapons;
      *((BYTE *)Str + 3) = configuration.difficulty;
      v21 = 1667855697;
      v22 = 1986098027;
      v23 = 1817387109;
      v24 = 29807;
      v5 = &v21;
      v25 = 0;
      v19 = v4;
      v6 = 0;
      do
      {
        v7 = *(BYTE *)v5;
        v5 = (int *)((char *)v5 + 1);
      }
      while ( v7 );
      if ( v5 != (int *)((char *)&v21 + 1) )
      {
        do
        {
          *((BYTE *)Str + v6 + 4) = *((BYTE *)&v21 + v6);
          ++v6;
        }
        while ( v6 < strlen((const char *)&v21) );
      }
      memcpy((char *)Str + 19, byte_460840, 0x870u);
      v8 = 1;
      while ( 1 )
      {
        *((BYTE *)Str + v8) -= v4;
        *((BYTE *)Str + v8) += 17 * v8;
        encryptByteSavegame((int)((char *)Str + v8), v8 % 6);
        ++v8;
        if ( (signed int)v8 >= 2179 )
          break;
        LOBYTE(v4) = v19;
      }
      v9 = fopen("DR.SG7", "wb");
      fwrite(Str, 0x883u, 1u, v9);
      fclose(v9);
      free(Str);
    }
    if ( !keysRead_45E0C0[KEY_F3] )
      return v0;
    v0 = 2;
    firstRacePlayed_464F44 = 0;
    useHasMorePoints_456BC4 = 0;
    //allocateMemory(0x883u);
    Str = v10;
    memset(v10, 0, 0x880u);
    v11 = (int)((char *)v10 + 2176);
    *(_WORD *)v11 = 0;
    *(BYTE *)(v11 + 2) = 0;
    v12 = fopen("DR.SG7", "rb");
    v13 = v12;
    if ( v12 )
    {
      fread(Str, 0x883u, 1u, v12);
      fclose(v13);
      v20 = *(BYTE *)Str;
      v14 = 1;
      do
      {
        decryptByteSavegame((int)((char *)Str + v14), v14 % 6);
        *((BYTE *)Str + v14) += -17 * v14;
        *((BYTE *)Str + v14++) += v20;
      }
      while ( (signed int)v14 < 2179 );
      driverId = *((BYTE *)Str + 1);
      useWeapons = *((BYTE *)Str + 2);
	  configuration.difficulty = *((BYTE *)Str + 3);
      memcpy(byte_460840, (char *)Str + 19, 0x870u);
      free(Str);
      v15 = drivers[driverId].spikes;
      v16 = drivers[driverId].rocket;
      v17 = drivers[driverId].sabotage;
      minesAvailable_45EFF0 = drivers[driverId].mines != 8;
      spikesAvailable_45EFF4 = v15 != 1;
      rocketAvailable_45EFF8 = v16 != 1;
      sabotageAvailable_45EFFC = v17 != 1;
      return v0;
    }
    result = 3;
  }
  return result;
}

//----- (004224E0) --------------------------------------------------------
int sub_4224E0()
{
  int v0; // eax@2
  char *v1; // ecx@2
  signed int v2; // edx@2
  int v3; // eax@2
  float v4; // ST30_4@2
  float v5; // ST2C_4@2
  float v6; // ST28_4@2
  int v7; // eax@2
  char *v8; // edx@2
  signed int v9; // ecx@2
  int v10; // eax@2
  float v11; // ST30_4@2
  float v12; // ST2C_4@2
  float v13; // ST28_4@2
  signed int v14; // esi@4
  float v15; // ST34_4@5
  int v16; // eax@5
  void *v17; // ecx@5
  int v18; // eax@5
  void *v19; // ecx@5
  signed int v20; // esi@6
  int v21; // eax@7
  int v22; // eax@7
  int v23; // ecx@7
  int v24; // eax@7
  int v25; // eax@7
  int v26; // edx@7
  int v27; // eax@7
  int result; // eax@7
  signed int v29; // [sp+10h] [bp-8h]@4
   int palette1Index = 48;
  int palette2Index = 48;
  int index=0;
  loadPaletteMenu();
  if (graphicsGeneral.copperPal)
  {
    ///v0 = dword_46086C[27 * driverId];
	v0 = drivers[driverId].colour;
    v1 = (char *)graphicsGeneral.copperPal + 2 * v0;
    v2 = (unsigned __int8)v1[v0 + 2];
    v3 = (int)&v1[v0];
    v4 = (double)v2;
    v5 = (double)*(BYTE *)(v3 + 1);
    v6 = (double)*(BYTE *)v3;
    sub_418B00(v6, v5, v4);
    //v7 = dword_46086C[27 * driverId];
	v7 = drivers[driverId].colour;
    v8 = (char *)graphicsGeneral.copperPal + 2 * v7;
    v9 = (unsigned __int8)v8[v7 + 2];
    v10 = (int)&v8[v7];
    v11 = (double)v9;
    v12 = (double)*(BYTE *)(v10 + 1);
    v13 = (double)*(BYTE *)v10;
    sub_41ED20(v13, v12, v11);
  }
  if (graphicsGeneral.bgcopPal)
  {
    v29 = 0;
    v14 =0;
	 index = 192; //offset de la paleta
	//int index = 192;
	//v14 = (signed int)&unk_460544;
    do
    {
      v15 = (double)v29;
      v16 = colorToPaletteEntry(
              (unsigned int)(unsigned __int64)((double)*((BYTE *)graphicsGeneral.bgcopPal + 2 * dword_456754 + dword_456754)
                                             * 0.015625
                                             * v15) << 16,
              6553600);
      v17 = graphicsGeneral.bgcopPal;
      palette1[index] = v16;
      v18 = colorToPaletteEntry(
              (unsigned int)(unsigned __int64)((double)*((BYTE *)v17 + 2 * dword_456754 + dword_456754 + 1)
                                             * 0.015625
                                             * v15) << 16,
              6553600);
      v19 = graphicsGeneral.bgcopPal;
	  palette1[index+1] = v18;
	  palette1[index+2] = colorToPaletteEntry(
                               (unsigned int)(unsigned __int64)((double)*((BYTE *)v19
                                                                        + 2 * dword_456754
                                                                        + dword_456754
                                                                        + 2)
                                                              * 0.015625
                                                              * v15) << 16,
                               6553600);
      v14 += 12;
	  index = index + 3;
	 /* v15 = (double)v29;
	  v16 = colorToPaletteEntry(
		  (unsigned int)(unsigned __int64)((double)*((BYTE *)graphicsGeneral.bgcopPal + 2 * dword_456754 + dword_456754)
			  * 0.015625
			  * v15) << 16,
		  6553600);
	  v17 = graphicsGeneral.bgcopPal;
	  *(_DWORD *)(v14 - 4) = v16;
	  v18 = colorToPaletteEntry(
		  (unsigned int)(unsigned __int64)((double)*((BYTE *)v17 + 2 * dword_456754 + dword_456754 + 1)
			  * 0.015625
			  * v15) << 16,
		  6553600);
	  v19 = graphicsGeneral.bgcopPal;
	  *(_DWORD *)v14 = v18;
	  *(_DWORD *)(v14 + 4) = colorToPaletteEntry(
		  (unsigned int)(unsigned __int64)((double)*((BYTE *)v19
			  + 2 * dword_456754
			  + dword_456754
			  + 2)
			  * 0.015625
			  * v15) << 16,
		  6553600);
	  v14 += 12;*/
      ++v29;
    }
    while ( v29 < 32 );
	//while (v14 < (signed int)&unk_4606C4);
  }
  v20 = 0;
 
  do
  {
    v21 = convertColorToPaletteColor(palette2[palette2Index], dword_45EAA4 << 16);
	//v21 = convertColorToPaletteColor(dword_461360[v20], dword_45EAA4 << 16);
    v22 = colorToPaletteEntry((v21 + 0x8000) >> 16 << 16, 6553600);
    v23 = palette2[palette2Index +1];
	//v23 = dword_461364[v20];
//    dword_45FD00[v20] = v22;
	palette1[palette1Index + 16] = v22;
    v24 = convertColorToPaletteColor(v23, dword_45EAA4 << 16);
    v25 = colorToPaletteEntry((v24 + 0x8000) >> 16 << 16, 6553600);
    v26 = dword_45EAA4 << 16;
	palette1[palette1Index +16] = v25;
    ///dword_45FD04[v20] = v25;
    v27 = convertColorToPaletteColor(palette2[palette2Index +2], v26);
	//v27 = convertColorToPaletteColor(dword_461368[v20], v26);
    result = colorToPaletteEntry((v27 + 0x8000) >> 16 << 16, 6553600);
	palette1[palette1Index +16] = result;
	
    //dword_45FD08[v20] = result;
    v20 += 3;
	palette1Index = palette1Index + 3;
	palette2Index = palette2Index + 3;
  }
  while ( v20 < 48 );
  return result;
}

//----- (00422740) --------------------------------------------------------
int copyPalette1toPalette()
{
  unsigned __int8 v0; // di@1
  signed int v1; // esi@1
  int v2; // ST0C_4@2
  int v3; // ST08_4@2
  int v4; // eax@2
  int result; // eax@2

  v0 = 0;
  //FIXED
 // v1 = (signed int)dword_45FC44;
  v1 = 0;
  do
  {
	  
    v2 = (convertColorToPaletteColor((palette1[v1+2]), 6553600) + 0x8000) >> 16;
    v3 = (convertColorToPaletteColor(palette1[v1 + 1], 6553600) + 0x8000) >> 16;
    v4 = convertColorToPaletteColor((palette1[v1] - 4), 6553600);
    result = setPaletteAndGetValue(v0, (v4 + 0x8000) >> 16, v3, v2);
    //v1 += 12;
	v1 += 3;
    ++v0;
  }
  while ( v1 < maxPaletteEntries );
  return result;
}

//----- (004227C0) --------------------------------------------------------
//int getReapirCostByCarType()

//----- (00422810) --------------------------------------------------------
//int   getBlackMarketElementText(int a1)

//----- (004228A0) --------------------------------------------------------
//int   getBlackMarketElementPurchasedText(int a1)

//----- (00422930) --------------------------------------------------------
//int outOfStockPopup_422930()

//----- (004229B0) --------------------------------------------------------
//int blackMarketSharewarePopup_4229B0()

//----- (00422A30) --------------------------------------------------------
//int drawLoanShark()

//----- (00422D00) --------------------------------------------------------
//int loanDeniedVagabondPopUp()

//----- (00422D80) --------------------------------------------------------
//int loanReturnPopup_422D80()

//----- (00422E00) --------------------------------------------------------
//int drawBlackMarketElement0()

//----- (00422F10) --------------------------------------------------------
//int drawBlackMarketElement1()

//----- (00423020) --------------------------------------------------------
//int drawBlackMarketElement2()

//----- (00423130) --------------------------------------------------------
//int drawBlackMarketElement3()

//----- (00423350) --------------------------------------------------------
//int drawBlackMarketContinue()

//----- (00423410) --------------------------------------------------------
//void underGroundMenuLeft()

//----- (00423590) --------------------------------------------------------
//void underGroundMenuRight()

//----- (004236D0) --------------------------------------------------------
//int reInitUnderGroundMarketStock()

//----- (004237A0) --------------------------------------------------------
//int drawBlackMarketScreen()

//----- (00423A20) --------------------------------------------------------
//void   addParticipantToRace(signed int a1)

//----- (00423C90) --------------------------------------------------------
int   sub_423C90(int a1, int a2)
{
  int v2; // esi@1
  int v3; // ecx@1
  int v4; // ebp@1
  int v5; // ebx@1
  int *v6; // eax@2
  int v7; // edx@3
  int result; // eax@4
  int v9; // edx@5
  char *v10; // edx@12
  bool v11; // zf@12
  signed int v12; // eax@13
  int v13; // ecx@14
  char *v14; // edx@19
  bool v15; // sf@20
  unsigned __int8 v16; // of@20
  int v17; // [sp+10h] [bp-4h]@1

  while ( 1 )
  {
    v2 = a1;
    v3 = a2;
    v4 = drivers[((a1 + a2) / 2)].points;
    v5 = a1;
    v17 = a2;
    do
    {
      v6 = &drivers[v5].points;
      if (drivers[v5].points < v4 )
      {
        do
        {
          v7 = v6[27];
          v6 += 27;
          ++v5;
        }
        while ( v7 < v4 );
      }
      result = (int)&drivers[v3].points;
      if ( v4 < *(_DWORD *)result )
      {
        do
        {
          v9 = *(_DWORD *)(result - 108);
          result -= 108;
          --v3;
        }
        while ( v4 < v9 );
        v17 = v3;
      }
      if ( v5 > v3 )
        break;
      if ( driverId == v5 )
      {
        driverId = v3;
      }
      else if ( driverId == v3 )
      {
        driverId = v5;
      }
      memcpy(&unk_4611E0, &drivers[v5].name, 0x6Cu);
      v10 = &drivers[v17].name;
      v11 = isMultiplayerGame == 0;
      memcpy(&drivers[v5].name, v10, 0x6Cu);
      memcpy(v10, &unk_4611E0, 0x6Cu);
      if ( !v11 )
      {
        v12 = 0;
        do
        {
          v13 = *((BYTE *)&dword_45FA74 + v12);
          if ( v13 == v5 )
          {
            *((BYTE *)&dword_45FA74 + v12) = v17;
          }
          else if ( v13 == v17 )
          {
            *((BYTE *)&dword_45FA74 + v12) = v5;
          }
          ++v12;
        }
        while ( v12 < 4 );
        memcpy(&unk_4611E0, raceParticipant[v5].name, 0x54u);
        v14 = raceParticipant[v17].name;
        memcpy(raceParticipant[v5].name, v14, 0x54u);
        memcpy(v14, &unk_4611E0, 0x54u);
      }
      v2 = a1;
      ++v5;
      result = v17 - 1;
      v3 = v17 - 1;
      v16 = __OFSUB__(v5, v17 - 1);
      v15 = v5 - (v17-- - 1) < 0;
    }
    while ( v15 ^ v16 );
    if ( v2 < v3 )
      result = sub_423C90(v2, v3);
    if ( v5 >= a2 )
      break;
    a1 = v5;
  }
  return result;
}
// 45EA04: using guessed type int isMultiplayerGame;
// 45FA74: using guessed type int dword_45FA74;
// 460884: using guessed type int dword_460884[];
// 463CE8: using guessed type int driverId;

//----- (00423E20) --------------------------------------------------------
void   recalcRank(int a1)
{
	void *v1 = malloc(0x870u); // eax@1
  int v2; // ebx@1
  int v3; // ebp@2
  int v4; // edx@2
  int v5; // ecx@4
  signed int v6; // eax@5
  int v7; // edx@8
  void *v8=malloc(0x870u); // eax@12
  int v9; // edx@13
  void *v10; // ebp@13
  int v11; // eax@13
  const void *v12; // esi@14
  void *v13; // edi@14
  void *v14; // [sp+14h] [bp+4h]@12

  //allocateMemory(0x870u);
  v2 = a1;
  memcpy(v1, drivers, 0x870u);
  if ( a1 > 0 )
  {
    v3 = 0;
	v4 = a1 - 1;
    do
    {
      memcpy(&drivers[v3], &drivers[v4], sizeof(drivers[v3]));
      v4 = v4-1;
	  v3 = v3 + 1;
      --a1;
    }
    while ( a1 );
  }
  free(v1);
  v5 = 0;
  driverId = v2 - driverId - 1;
  if ( v2 > 0 )
  {
    v6 = (signed int)drivers[0].rank;
    do
    {
      if ( *(_DWORD *)(v6 - 4) != *(_DWORD *)(v6 - 112) || v6 <= drivers[0].rank )
        v7 = v5 + 1;
      else
        v7 = *(_DWORD *)(v6 - 108);
      *(_DWORD *)v6 = v7;
      ++v5;
      v6 += 108;
    }
    while ( v5 < v2 );
  }
  //al no haber multiplayer pasamos
  if ( isMultiplayerGame )
  {
    //allocateMemory(0x870u);
    v14 = v8;
    memcpy(v8, byte_460840, 0x870u);
    if ( v2 > 0 )
    {
      v9 = (int)((char *)v8 + 108 * v2 - 108);
      v10 = byte_460840;
      v11 = v2;
      do
      {
        v12 = (const void *)v9;
        v13 = v10;
        v9 -= 108;
        v10 = (char *)v10 + 108;
        --v11;
        memcpy(v13, v12, 0x6Cu);
      }
      while ( v11 );
      v8 = v14;
    }
    free(v8);
    driverId = v2 - driverId - 1;
  }
}
// 45EA04: using guessed type int isMultiplayerGame;
// 460888: using guessed type int dword_460888[];
// 463CE8: using guessed type int driverId;

//----- (00423F40) --------------------------------------------------------
//
//int drawSelectRaceScreen()

//----- (004240B0) --------------------------------------------------------
//int calculateNextRaces()

//----- (00424240) --------------------------------------------------------
//int   sub_424240(int a1, float a2, float a3, float a4)

//----- (00424420) --------------------------------------------------------
//int sub_424420()

//----- (00424510) --------------------------------------------------------
int   sub_424510(int a1, int a2, int raceId)
{
  int v3; // ebx@1
  int v4; // edi@1
  
  int result; // eax@2
  int v7; // esi@2
  int v8; // ecx@2
  int v9; // edx@4
  int v10; // edx@6
  char v11; // dl@8

  v3 = a2;
  v4 = a1;
  
  //v5 = 4 * a3 + 4582224;
  while ( 1 )
  {
    result = drivers[racePositions[raceId][(v4 + v3) / 2]].carType;
	//result = dword_46085C[27 * *((BYTE *)&dword_45EB50[a3] + (v4 + v3) / 2)];
    v7 = v4;
    v8 = v3;
    do
    {
      if (drivers[racePositions[raceId][v7]].carType < result )
		  ///if (dword_46085C[27 * *(BYTE *)(v7 + v5)] < result)
      {
        do
          v9 = racePositions[raceId][v7++ + 1];
		//v9 = *(BYTE *)(v7++ + v5 + 1);
        while (drivers[v9].carType < result );
		//while (dword_46085C[27 * v9] < result);
      }
      if ( result < drivers[racePositions[raceId][v8]].carType )
		  //if (result < dword_46085C[27 * *(BYTE *)(v8 + v5)])
      {
        do
          v10 = racePositions[raceId][v8-- - 1];
		//v10 = *(BYTE *)(v8-- + v5 - 1);
        while ( result < drivers[v10].carType );
		//while (result < dword_46085C[27 * v10]);
      }
      if ( v7 > v8 )
        break;
      v11 = racePositions[raceId][v7];
	  racePositions[raceId][v7] = racePositions[raceId][v8];
	 // v11 = *(BYTE *)(v7 + v5);
	 // *(BYTE *)(v7 + v5) = *(BYTE *)(v8 + v5);
      v3 = a2;
      ++v7;
	  racePositions[raceId][v8--] = v11;
	  //*(BYTE *)(v8-- + v5) = v11;
    }
    while ( v7 < v8 );
    if ( v4 < v8 )
      result = sub_424510(v4, v8, raceId);
    if ( v7 >= v3 )
      break;
    v4 = v7;
  }
  return result;
}
// 45EB50: using guessed type int dword_45EB50[];
// 46085C: using guessed type int dword_46085C[];

//----- (004245D0) --------------------------------------------------------
//unsigned int drawStadistics()

//----- (00425980) --------------------------------------------------------
//int   writeDriverList(int a1)

//----- (00425BD0) --------------------------------------------------------
//int   drawRightPositions(int numDrivers, int a2)

//----- (00426080) --------------------------------------------------------
//signed int sub_426080()

//----- (004260D0) --------------------------------------------------------
//int drawPressAnyKeyToContinue()

//----- (00426180) --------------------------------------------------------
signed int drawCircuitPreviewImage()
{
  int v0; // edx@1
  signed int result; // eax@1
  char *v2; // esi@2
  char *v3; // edi@2

  v0 = 0;
  result = 0;
  do
  {
    v2 = (char *)tsahpeBpk_45EB5C + result;
    v3 = (char *)screenBuffer + v0 + 64264;
    result += 360;
    v0 += 640;
    memcpy(v3, v2, 0x168u);
  }
  while ( result < 7200 );
  return result;
}

//----- (004261D0) --------------------------------------------------------
//int drawWaitMultiplayer_4261D0()

//----- (00426280) --------------------------------------------------------
//int sub_426280()

//----- (00426460) --------------------------------------------------------
int   sub_426460(unsigned __int8 a1, unsigned __int8 a2)
{
  int result; // eax@4

  if ( a2 )
  {
    if ( a2 != 1 || (a1 & 0xC0) == -64 )
    {
      if ( putc(a2 | 0xC0, File) == -1 )
        result = 0;
      else
        result = putc(a1, File) != -1 ? 2 : 0;
    }
    else
    {
      result = putc(a1, File) != -1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004271F0) --------------------------------------------------------
//int   openPalFromBpa(char * filename)

//----- (00427280) --------------------------------------------------------
int transitionToCurrentImage()///esto huele a que esta pintando la pantalla con la paleta
{
  int v0; // edi@1
  unsigned __int8 v1; // bl@2
  signed int v2; // esi@2
  int v3; // ST0C_4@3
  int v4; // ST08_4@3
  int v5; // eax@3
  int result; // eax@3
    
  v0 =0;
  
  do
  {
    waitWithRefresh();
    v1 = 0;
	v2 = 0;
	
    //v2 = (signed int)dword_45FC44;
    do
    {
      v3 = (convertColorToPaletteColor(palette1[v2+2], v0) + 0x8000) >> 16;
      v4 = (convertColorToPaletteColor(palette1[v2 + 1], v0) + 0x8000) >> 16;
      v5 = (convertColorToPaletteColor(palette1[v2], v0) + 0x8000) >> 16;
      result = setPaletteAndGetValue(v1, v5 , v4, v3);
	 
      v2 += 3;
	  //v2 += 12;
      ++v1;
    }
    while (v2 < maxPaletteEntries);
    v0 += 0x40000;
  }
  while ( v0 < 6553600 );
  return result;
}
//----- (00427280) --------------------------------------------------------
int metodofalse()///esto huele a que esta pintando la pantalla con la paleta
{
	int v0; // edi@1
	unsigned __int8 v1; // bl@2
	signed int v2; // esi@2
	int v3; // ST0C_4@3
	int v4; // ST08_4@3
	int v5; // eax@3
	int result; // eax@3

	v0 = 0x640000;

	do
	{
		waitWithRefresh();
		v1 = 0;
		v2 = 0;

		//v2 = (signed int)dword_45FC44;
		do
		{
			v3 = (convertColorToPaletteColor(palette1[v2 + 2], v0) + 0x8000) >> 16;
			v4 = (convertColorToPaletteColor(palette1[v2 + 1], v0) + 0x8000) >> 16;
			v5 = (convertColorToPaletteColor(palette1[v2], v0) + 0x8000) >> 16;
			result = setPaletteAndGetValue(v1, v5, v4, v3);

			v2 += 3;
			//v2 += 12;
			++v1;
		} while (v2 < maxPaletteEntries);
		v0 += 0x40000;
	} while (v0 < 6553600);
	return result;
}

//----- (00427300) --------------------------------------------------------
int transitionToBlack()
{
  int v0; // edi@1
  unsigned __int8 v1; // bl@2
  signed int v2; // esi@2
  int v3; // ST0C_4@3
  int v4; // ST08_4@3
  int v5; // eax@3
  int result; // eax@3

  v0 = 6553600;
  do
  {
    waitWithRefresh();
    v1 = 0;
	v2 = 0;
	//v2 = (signed int)dword_45FC44;
	
    do
    {
		v3 = (convertColorToPaletteColor((palette1[v2 + 2]), v0) + 0x8000) >> 16;
		v4 = (convertColorToPaletteColor(palette1[v2 + 1], v0) + 0x8000) >> 16;
		v5 = convertColorToPaletteColor((palette1[v2] - 4), v0);
      result = setPaletteAndGetValue(v1, (v5 + 0x8000) >> 16, v4, v3);
      v2 += 3;
      ++v1;
    }
    while ( v2 < maxPaletteEntries );
	v0 -= 0x40000;
  }
  while ( v0 >= 0 );
  return result;
}

//----- (00427380) --------------------------------------------------------
//int apogeeScreen()

//----- (004274E0) --------------------------------------------------------
//int showCredits()

//----- (00427700) --------------------------------------------------------
//int showEndScreen()


//----- (00427880) --------------------------------------------------------
//int showStartScreen()

//----- (004278E0) --------------------------------------------------------
//FILE *checkAndOpenAnimation()

//----- (004279C0) --------------------------------------------------------
//char sub_4279C0()

//----- (00427BC0) --------------------------------------------------------
//int sub_427BC0()

//----- (00427D60) --------------------------------------------------------
/*int checkIntro()
{
  int v0; // ebx@1
  signed int v1; // ebp@1
  FILE *v2; // eax@2
  FILE *v3; // esi@2
  __int32 v4; // edi@3
  int v5; // eax@6
  char v6; // cl@7
  unsigned int v7; // eax@8
  char *v8; // edi@8
  char v9; // cl@9
  FILE *v10; // eax@10
  FILE *v11; // esi@10
  __int32 (  *v12)(FILE *); // ebp@11
  __int32 v13; // edi@11
  unsigned int v14; // eax@20
  char *v15; // edi@20
  char v16; // cl@21
  int v17; // eax@23
  const void *v18; // esi@23
  char v19; // cl@24
  unsigned int v20; // eax@25
  char *v21; // edi@25
  char v22; // cl@26
  FILE *v23; // eax@27
  FILE *v24; // esi@27
  __int32 v25; // edi@28
  int result; // eax@30
  bool v27; // sf@30
  unsigned __int8 v28; // of@30
  const char *v29; // [sp-8h] [bp-120h]@13
  int v30; // [sp-4h] [bp-11Ch]@13
  _UNKNOWN *v31; // [sp+10h] [bp-108h]@18
  int v32; // [sp+14h] [bp-104h]@8
  char Filename[256]; // [sp+18h] [bp-100h]@7

  v0 = 0;
  v1 = (signed int)&unk_4568D8;
  do
  {
    v2 = fopen((const char *)(v1 - 16), "rb");
    v3 = v2;
    if ( !v2 || (fseek(v2, 0, 2), v4 = ftell(v3), fclose(v3), v4 < 1) )
    {
      v30 = 20 * v0 + 4548808;
      v29 = "\nDEATH RALLY ERROR: File %s is not found!\n";
LABEL_33:
      printf(v29, v30);
      printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
      nullsub_1();
      freeMusic();
      exit(112);
    }
    if ( v4 != *(_DWORD *)v1 )
    {
      printf("\nDEATH RALLY ERROR: File %s is not in original form!\n", 20 * v0 + 4548808);
      printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
      nullsub_1();
      freeMusic();
      exit(112);
    }
    v1 += 20;
    ++v0;
  }
  while ( v1 < (signed int)&unk_4569F0 );
  byte_462D50 = 2;
  v5 = 0;
  do
  {
    v6 = byte_45FAA0[v5];
    Filename[v5++] = v6;
  }
  while ( v6 );
  v7 = strlen(aSanim_haf) + 1;
  v8 = (char *)&v32 + 3;
  do
    v9 = (v8++)[1];
  while ( v9 );
  memcpy(v8, aSanim_haf, v7);
  v10 = fopen(Filename, "rb");
 
  v11 = v10;
  if ( !v10 )
  {
    v12 = ftell;
    goto LABEL_17;
  }
  fseek(v10, 0, 2);
  v12 = ftell;
  v13 = ftell(v11);
  fclose(v11);
  if ( v13 < 1 )
LABEL_17:
    byte_462D50 = 1;
  v32 = 0;
  v31 = &unk_4569F0;
  while ( 2 )
  {
    Filename[0] = 0;
    if ( byte_462D50 == 2 )
    {
      v14 = strlen(byte_45FAA0) + 1;
      v15 = (char *)&v32 + 3;
      do
        v16 = (v15++)[1];
      while ( v16 );
      memcpy(v15, byte_45FAA0, v14);
    }
    v17 = (int)((char *)v31 - 16);
    v18 = (char *)v31 - 16;
    do
      v19 = *(BYTE *)v17++;
    while ( v19 );
    v20 = v17 - (_DWORD)v18;
    v21 = (char *)&v32 + 3;
    do
      v22 = (v21++)[1];
    while ( v22 );
    memcpy(v21, v18, v20);
    v23 = fopen(aSanim_haf, "rb");
	//v23 = fopen(Filename, "rb");
    v24 = v23;
    if ( v23 )
    {
      fseek(v23, 0, 2);
      v25 = v12(v24);
      fclose(v24);
     if ( v25 > 0 && v25 != *(_DWORD *)v31 )
      {
        v30 = 20 * v32 + 4549088;
        v29 = "\nDEATH RALLY ERROR: File %s is not in original form!\n";
        goto LABEL_33;
      }
    }
    result = (int)((char *)v31 + 20);
    v28 = __OFSUB__((char *)v31 + 20, &effectVolume_456A2C);
    v27 = (_UNKNOWN *)((char *)v31 + 20) - (_UNKNOWN *)&effectVolume_456A2C < 0;
    ++v32;
    v31 = (char *)v31 + 20;
    if ( v27 ^ v28 )
      continue;
    return result;
  }
}*/

//----- (00428070) --------------------------------------------------------

//----- (004284E0) --------------------------------------------------------
//signed int sub_4284E0()

//----- (00428740) --------------------------------------------------------
//signed int sub_428740()


//----- (00428930) --------------------------------------------------------
//int initDrivers()

//----- (00428FD0) --------------------------------------------------------
//int reloadContinueAnimation()

//----- (00429100) --------------------------------------------------------
//int drawShopAnimationAndRightSide()

//----- (004291D0) --------------------------------------------------------
//int sub_4291D0()

//----- (00429280) --------------------------------------------------------
//void   easyRaceResults(int ecx0, int a2, int a1)

//----- (004295E0) --------------------------------------------------------
//void   mediumRaceResults(int ecx0, int a2, int a1)

//----- (00429990) --------------------------------------------------------
//void   hardRaceResults(int ecx0, int a2, int a1)

//----- (00429CF0) --------------------------------------------------------
int   sub_429CF0(unsigned __int8 *a1, signed int a2)
{
  unsigned __int8 *v2; // ebp@1
  unsigned __int8 v3; // si@1
  int v4; // edi@1
  char v5; // al@1
  unsigned __int8 v6; // bl@2
  int v7; // eax@4
  int v8; // eax@7
  int v9; // eax@13
  int result; // eax@14
  unsigned __int8 v11; // [sp+10h] [bp-8h]@1
  signed int v12; // [sp+14h] [bp-4h]@1
  unsigned __int8 v13; // [sp+1Ch] [bp+4h]@1

  v2 = a1;
  v13 = *a1;
  v3 = v13;
  v4 = 0;
  v5 = 1;
  v11 = 1;
  v12 = 1;
  if ( a2 <= 1 )
    goto LABEL_13;
  do
  {
    v6 = (v2++)[1];
    if ( v6 == v13 )
    {
      ++v5;
      v11 = v5;
      if ( v5 != 63 )
        goto LABEL_11;
      v7 = sub_426460(v3, 0x3Fu);
      if ( !v7 )
        goto LABEL_14;
      v4 += v7;
      v5 = 0;
    }
    else
    {
      if ( v5 )
      {
        v8 = sub_426460(v3, v11);
        if ( !v8 )
          goto LABEL_14;
        v4 += v8;
      }
      v13 = v6;
      v3 = v6;
      v5 = 1;
    }
    v11 = v5;
LABEL_11:
    ++v12;
  }
  while ( v12 < a2 );
  if ( v5 )
  {
LABEL_13:
    v9 = sub_426460(v3, v11);
    if ( v9 )
      result = v4 + v9;
    else
LABEL_14:
      result = 0;
  }
  else
  {
    result = v4;
  }
  return result;
}

//----- (00429DC0) --------------------------------------------------------
int makeSnapshot_429DC0()
{
  unsigned int v0; // eax@4
  char *v1; // edi@4
  char v2; // cl@5
  char *v3; // edi@6
  char v4; // al@7
  FILE *v5; // eax@8
  FILE *v6; // esi@8
  __int32 v7; // edi@9
  bool v8; // sf@10
  unsigned __int8 v9; // of@10
  signed int v10; // esi@11
  char DstBuf; // [sp+Ch] [bp-318h]@2
  char v13; // [sp+Dh] [bp-317h]@3
  char v14; // [sp+Eh] [bp-316h]@3
  int Val; // [sp+10h] [bp-314h]@1
  char Filename[4]; // [sp+14h] [bp-310h]@4
  __int16 v17; // [sp+18h] [bp-30Ch]@4
  char v18; // [sp+1Ah] [bp-30Ah]@4
  char Str; // [sp+24h] [bp-300h]@13

  Val = 0;
  do
  {
    _itoa(Val, &DstBuf, 10);
    if ( strlen(&DstBuf) != 2 )
    {
      v13 = DstBuf;
      DstBuf = 48;
      v14 = 0;
    }
    *(_DWORD *)Filename = 1345147720;
    v18 = 0;
    v17 = 17225;
    v0 = strlen(&DstBuf) + 1;
    v1 = (char *)&Val + 3;
    do
      v2 = (v1++)[1];
    while ( v2 );
    memcpy(v1, &DstBuf, v0);
    v3 = (char *)&Val + 3;
    do
      v4 = (v3++)[1];
    while ( v4 );
    *(_DWORD *)v3 = 1480806446;
    v3[4] = 0;
    v5 = fopen(Filename, "rb");
    v6 = v5;
    if ( !v5 )
      break;
    fseek(v5, 0, 2);
    v7 = ftell(v6);
    fclose(v6);
    if ( v7 < 1 )
      break;
    v9 = __OFSUB__(Val + 1, 100);
    v8 = Val++ - 99 < 0;
  }
  while ( v8 ^ v9 );
  File = fopen(Filename, "wb");
  fwrite(&unk_456848, 1u, 0x80u, File);
  v10 = 0;
  do
  {
    sub_429CF0((unsigned __int8 *)screenBuffer + v10, 640);
    v10 += 640;
  }
  while ( v10 < 307200 );
  fputc(12, File);
  generateSnapshotData_43C160((int)&Str);
  fwrite(&Str, 1u, 0x300u, File);
  return fclose(File);
}

//----- (00429F70) --------------------------------------------------------
void __noreturn exitGame()
{
  saveConfiguration();
  freeMemoryGraphics();
  freeMemoryGraphics1();
  freeMemoryGraphics2();
  freeMemoryGraphics3();
  freeMemoryGraphics4();
  stopAndOpenMusic();
  freeMusic();
  nullsub_1();
  if ( isMultiplayerGame )
    nullsub_1();
  setWindowCaption();
  printf("DEATH RALLY Exit: CTRL+ALT+DEL pressed.\n");
  exit(112);
}
// 4264E0: using guessed type int saveConfiguration(void);
// 45EA04: using guessed type int isMultiplayerGame;

//----- (0042A300) --------------------------------------------------------

//----- (0042A480) --------------------------------------------------------
int sub_42A480()
{
  int result; // eax@3
  int v1; // eax@4
  char *v2; // ecx@6
  signed int v3; // edx@6
  int v4; // eax@6
  signed int v5; // ebx@6
  signed int v6; // [sp+0h] [bp-10h]@6
  float v7; // [sp+4h] [bp-Ch]@6
  float v8; // [sp+8h] [bp-8h]@6
  float v9; // [sp+Ch] [bp-4h]@6

  if ( keysRead_45E0C0[KEY_F6] )//cambiado a f11
    makeSnapshot_429DC0();
  ++dword_456BA0;
  waitWithRefresh();
  sub_4220D0();
  result = dword_456BA0 / 70;
  if ( dword_456BA0 % 70 == 1 )
  {
    v1 = dword_456754-- - 1;
    if ( dword_456754 < 0 )
    {
      v1 = 511;
      dword_456754 = 511;
    }
    v2 = (char *)graphicsGeneral.bgcopPal + 2 * v1;
    v3 = (unsigned __int8)v2[v1];
    v4 = (int)&v2[v1];
    v5 = 0;
    v9 = (double)v3 * 0.015625;
    v8 = (double)*(BYTE *)(v4 + 1) * 0.015625;
    v6 = 0;
    v7 = (double)*(BYTE *)(v4 + 2) * 0.015625;
    do
    {
      result = setPaletteAndGetValue(
                 v5++ - 64,
                 (unsigned __int64)((double)v6 * v9),
                 (unsigned __int64)(v8 * (double)v6),
                 (unsigned __int64)(v7 * (double)v6));
      v6 = v5;
    }
    while ( v5 < 32 );
  }
  return result;
}
// 456754: using guessed type int dword_456754;
// 456BA0: using guessed type int dword_456BA0;
// 45E118: using guessed type char keysRead_45E0C0[KEY_F12];

//----- (0042A570) --------------------------------------------------------
void refreshAndCheckConnection_42A570()
{
  int v0; // eax@4
  char *v1; // ecx@6
  signed int v2; // edx@6
  int v3; // eax@6
  signed int v4; // ebx@6
  signed int v5; // esi@10
  signed int v6; // eax@11
  char v7; // cl@12
  int v8; // eax@14
  char v9; // cl@15
  signed int v10; // esi@22
  signed int v11; // eax@23
  char v12; // cl@24
  int v13; // eax@26
  char v14; // cl@27
  void *v15 = malloc(0x64u); // eax@34
  char *v16; // eax@34
  char v17; // dl@35
  unsigned int v18; // eax@36
  char *v19; // edi@36
  char v20; // cl@37
  char *v21; // edi@38
  char v22; // al@39
  signed int v23; // esi@42
  signed int v24; // eax@43
  char v25; // cl@44
  int v26; // eax@46
  char v27; // cl@47
  signed int v28; // esi@55
  signed int v29; // eax@56
  char v30; // cl@57
  int v31; // eax@59
  char v32; // cl@60
  signed int v33; // edx@68
  signed int v34; // eax@69
  char v35; // cl@70
  char *v36; // eax@72
  char v37; // dl@73
  unsigned int v38; // eax@74
  char *v39; // edi@74
  char v40; // cl@75
  char *v41; // edi@76
  char v42; // al@77
  bool v43; // zf@78
  int v44; // eax@78
  signed int v45; // edx@86
  signed int v46; // eax@87
  char v47; // cl@88
  int v48; // eax@90
  signed int v49; // [sp+0h] [bp-41Ch]@6
  float v50; // [sp+4h] [bp-418h]@6
  float v51; // [sp+8h] [bp-414h]@6
  float v52; // [sp+Ch] [bp-410h]@6
  unsigned __int8 v53; // [sp+10h] [bp-40Ch]@67
  char v54[1024]; // [sp+1Ch] [bp-400h]@9

  if ( keysRead_45E0C0[KEY_F6]) //cambiado a f11)
    makeSnapshot_429DC0();
  ++dword_456BA0;
  waitWithRefresh();
  sub_4220D0();
  if ( dword_456BA0 % 70 == 1 )
  {
    v0 = dword_456754-- - 1;
    if ( dword_456754 < 0 )
    {
      v0 = 511;
      dword_456754 = 511;
    }
    v1 = (char *)graphicsGeneral.bgcopPal + 2 * v0;
    v2 = (unsigned __int8)v1[v0];
    v3 = (int)&v1[v0];
    v4 = 0;
    v51 = (double)v2 * 0.015625;
    v50 = (double)*(BYTE *)(v3 + 1) * 0.015625;
    v49 = 0;
    v52 = (double)*(BYTE *)(v3 + 2) * 0.015625;
    do
    {
      setPaletteAndGetValue(
        v4++ - 64,
        (unsigned __int64)((double)v49 * v51),
        (unsigned __int64)(v50 * (double)v49),
        (unsigned __int64)(v52 * (double)v49));
      v49 = v4;
    }
    while ( v4 < 32 );
  }
  if ( isMultiplayerGame )
  {
    /*nullsub_1();
    if ( sub_41EB80((int)v54, 1) )
    {
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
      v5 = (signed int)&unk_462096;
      unk_461ED2 = unk_461ED3;
      unk_461ED3 = word_461ED4;
      do
      {
        v6 = v5;
        do
        {
          v7 = *(BYTE *)v6;
          *(BYTE *)(v6 - 150) = *(BYTE *)v6;
          ++v6;
        }
        while ( v7 );
        v5 += 150;
      }
      while ( v5 < (signed int)&blacktx1Bpk );
      v8 = 0;
      do
      {
        v9 = v54[v8];
        *((BYTE *)&dword_462C4E + v8++) = v9;
      }
      while ( v9 );
      HIBYTE(word_461ED4) = 1;
      if ( dword_456B54 )
      {
        if ( dword_456730 == 1 )
        {
          sub_41E9A0();
          refreshAllScreen();
        }
      }
      else if ( dword_456730 == 1 )
      {
        drawBottomMenuText();
        refreshBottomScreen();
      }
    }
    if ( sub_41EB80((int)v54, 6) )
    {
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
      v10 = (signed int)&unk_462096;
      unk_461ED2 = unk_461ED3;
      unk_461ED3 = word_461ED4;
      do
      {
        v11 = v10;
        do
        {
          v12 = *(BYTE *)v11;
          *(BYTE *)(v11 - 150) = *(BYTE *)v11;
          ++v11;
        }
        while ( v12 );
        v10 += 150;
      }
      while ( v10 < (signed int)&blacktx1Bpk );
      v13 = 0;
      do
      {
        v14 = v54[v13];
        *((BYTE *)&dword_462C4E + v13++) = v14;
      }
      while ( v14 );
      HIBYTE(word_461ED4) = 0;
      if ( dword_456B54 )
      {
        if ( dword_456730 == 1 )
        {
          sub_41E9A0();
          refreshAllScreen();
        }
      }
      else if ( dword_456730 == 1 )
      {
        drawBottomMenuText();
        updateScreenPtr(3);
        copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 196608, 0x4000);
        updateScreenPtr(4);
        copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x40000, 11264);
      }
    }
    if ( sub_41EB80((int)v54, 7) )
    {
     // allocateMemory(0x64u);
      Str = v15;
      *(_DWORD *)v15 = 2108717;
      v16 = &byte_460840[108 * driverId];
      do
        v17 = *v16++;
      while ( v17 );
      v18 = v16 - &byte_460840[108 * driverId];
      v19 = (char *)Str - 1;
      do
        v20 = (v19++)[1];
      while ( v20 );
      memcpy(v19, &byte_460840[108 * driverId], v18);
      v21 = (char *)Str - 1;
      do
        v22 = (v21++)[1];
      while ( v22 );
      memcpy(v21, " is currently on Death Rally.", 0x1Eu);
      //multiplayer_41EA70((int)Str, 100, 8);
      free(Str);
    }
    if ( sub_41EB80((int)v54, 20) )
    {
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
      v23 = (signed int)&unk_462096;
      unk_461ED2 = unk_461ED3;
      unk_461ED3 = word_461ED4;
      do
      {
        v24 = v23;
        do
        {
          v25 = *(BYTE *)v24;
          *(BYTE *)(v24 - 150) = *(BYTE *)v24;
          ++v24;
        }
        while ( v25 );
        v23 += 150;
      }
      while ( v23 < (signed int)&blacktx1Bpk );
      v26 = 0;
      do
      {
        v27 = v54[v26];
        *((BYTE *)&dword_462C4E + v26++) = v27;
      }
      while ( v27 );
      HIBYTE(word_461ED4) = 0;
      if ( dword_456B54 )
      {
        if ( dword_456730 == 1 )
        {
          sub_41E9A0();
          refreshAllScreen();
        }
      }
      else if ( dword_456730 == 1 )
      {
        drawBottomMenuText();
        updateScreenPtr(3);
        copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 196608, 0x4000);
        updateScreenPtr(4);
        copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x40000, 11264);
      }
      multiplayer_42A300();
      driverId = 19;
    }
    if ( sub_41EB80((int)v54, 9) )
    {
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
      v28 = (signed int)&unk_462096;
      unk_461ED2 = unk_461ED3;
      unk_461ED3 = word_461ED4;
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
      v31 = 0;
      do
      {
        v32 = v54[v31];
        *((BYTE *)&dword_462C4E + v31++) = v32;
      }
      while ( v32 );
      HIBYTE(word_461ED4) = 0;
      if ( dword_456B54 )
      {
        if ( dword_456730 == 1 )
        {
          sub_41E9A0();
          refreshAllScreen();
        }
      }
      else if ( dword_456730 == 1 )
      {
        drawBottomMenuText();
        updateScreenPtr(3);
        copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 196608, 0x4000);
        updateScreenPtr(4);
        copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x40000, 11264);
      }
      sub_428070(1);
    }
    if ( sub_41EB80((int)&v53, 19) )
    {
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
      unk_461ED2 = unk_461ED3;
      v33 = (signed int)&unk_462096;
      unk_461ED3 = word_461ED4;
      do
      {
        v34 = v33;
        do
        {
          v35 = *(BYTE *)v34;
          *(BYTE *)(v34 - 150) = *(BYTE *)v34;
          ++v34;
        }
        while ( v35 );
        v33 += 150;
      }
      while (
		  v33 < (signed int)&blacktx1Bpk );
      v36 = &byte_460840[108 * v53];
      dword_462C4E = 2108717;
      do
        v37 = *v36++;
      while ( v37 );
      v38 = v36 - &byte_460840[108 * v53];
      v39 = (char *)&dword_462C4E - 1;
      do
        v40 = (v39++)[1];
      while ( v40 );
      memcpy(v39, &byte_460840[108 * v53], v38);
      v41 = (char *)&dword_462C4E - 1;
      do
        v42 = (v41++)[1];
      while ( v42 );
      memcpy(v41, " is waiting for you to join the next race.", 0x2Au);
      HIBYTE(word_461ED4) = 0;
      v43 = dword_456B54 == 0;
      v44 = dword_456730;
      v41[42] = aIswaitingForYo[42];
      if ( v43 )
      {
        if ( v44 == 1 )
        {
          drawBottomMenuText();
          updateScreenPtr(3);
          copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 196608, 0x4000);
          updateScreenPtr(4);
          copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x40000, 11264);
        }
      }
      else if ( v44 == 1 )
      {
        sub_41E9A0();
        refreshAllScreen();
      }
    }
    if ( (dword_45E0A8 == 3 || dword_45E0A8 == 4) && (dword_45E5E0 & 0x80) != -128 )
    {
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
      unk_461ED2 = unk_461ED3;
      v45 = (signed int)&unk_462096;
      unk_461ED3 = word_461ED4;
      do
      {
        v46 = v45;
        do
        {
          v47 = *(BYTE *)v46;
          *(BYTE *)(v46 - 150) = *(BYTE *)v46;
          ++v46;
        }
        while ( v47 );
        v45 += 150;
      }
      while ( v45 < (signed int)&blacktx1Bpk );
      memcpy(&dword_462C4E, "-- Modem connection lost!", 0x18u);
      v43 = dword_456B54 == 0;
      v48 = dword_456730;
      *((_WORD *)&dword_462C4E + 12) = *(_WORD *)"!";
      HIBYTE(word_461ED4) = 0;
      if ( v43 )
      {
        if ( v48 == 1 )
        {
          drawBottomMenuText();
          updateScreenPtr(3);
          copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 196608, 0x4000);
          updateScreenPtr(4);
          copyBuffer2Screen((void *)screenPtr, (char *)screenBuffer + 0x40000, 11264);
          sub_428070(0);
          return;
        }
      }
      else if ( v48 == 1 )
      {
        sub_41E9A0();
        refreshAllScreen();
      }
      sub_428070(0);
    }*/
  }
}

//----- (0042B1B0) --------------------------------------------------------
//void   selectRaceWarningPopup(int a1)

//----- (0042B290) --------------------------------------------------------
//int   postRaceMain(int argc, const char **argv, const char **envp)

//----- (0042BD10) --------------------------------------------------------

//----- (0042C4A0) --------------------------------------------------------
char sub_42C4A0()
{
  signed int v0; // ebp@2
  int v1; // edi@3
  signed int v2; // esi@3
  signed int v3; // ebx@3
  signed int v5; // [sp+10h] [bp-8h]@1
  signed int v6; // [sp+14h] [bp-4h]@2

  v5 = 48000;
  do
  {
    sub_42A480();
    v0 = v5;
    v6 = 22;
    do
    {
      v1 = 0;
      v2 = v0;
      v3 = 10;
      do
      {
        sub_43B080(
          (int)((char *)graphicsGeneral.t15x150Bpk + v1),
          (int)((char *)dword_461ED8 + v2),
          15,
          15,
          (int)((char *)screenBuffer + v2));
        v1 += 225;
        v2 += 15;
        --v3;
      }
      while ( v3 );
      v0 += 9600;
      --v6;
    }
    while ( v6 );
    drawKeyCursor(v5, (char *)screenBuffer + v5, 0x96u, 330);
    v5 += 15;
  }
  while ( v5 < 48645 );
  eventDetected();
  return sub_418090();
}

//----- (0042C560) --------------------------------------------------------
char   sub_42C560(int a1)
{
  signed int v1; // ebp@2
  int v2; // edi@3
  signed int v3; // esi@3
  signed int v4; // ebx@3
  bool v5; // zf@10
  bool v6; // sf@10
  signed int v8; // [sp+10h] [bp-10h]@1
  signed int v9; // [sp+14h] [bp-Ch]@1
  signed int v10; // [sp+18h] [bp-8h]@1
  signed int v11; // [sp+1Ch] [bp-4h]@2

  v10 = 0;
  v8 = 48000;
  v9 = 65532;
  do
  {
    sub_42A480();
    v1 = v8;
    v11 = 22;
    do
    {
      v2 = 0;
      v3 = v1;
      v4 = 10;
      do
      {
        sub_43B080(
          (int)((char *)graphicsGeneral.t15x150Bpk + v2),
          (int)((char *)dword_461ED8 + v3),
          15,
          15,
          (int)((char *)screenBuffer + v3));
        v2 += 225;
        v3 += 15;
        --v4;
      }
      while ( v4 );
      v1 += 9600;
      --v11;
    }
    while ( v11 );
    drawKeyCursor(v8, (char *)screenBuffer + v8, 0x96u, 330);
    if ( a1 == -1 )
    {
      setMusicVolume(v9);
    }
    else if ( a1 == 1 )
    {
      setMusicVolume(v10);
    }
    v5 = v9 == 1524;
    v6 = v9 - 1524 < 0;
    v8 += 15;
    v9 -= 1524;
    v10 += 1524;
  }
  while ( !v6 && !v5 );
  eventDetected();
  return sub_418090();
}

//----- (0042C670) --------------------------------------------------------
//int   sub_42C670(int a1)

//----- (0042C780) --------------------------------------------------------
char drawPopupCursor_42C780 ()
{
  char v0; // bl@1
  unsigned __int8 v2; // [sp+1h] [bp-1h]@1

  v0 = 0;
  v2 = 0;
  eventDetected();
  sub_418090();
  do
  {
    if ( v0 == 28 || v0 == -100 )
      break;
    if ( v2 > 0xAu )
      v0 = eventDetected();
    refreshAndCheckConnection_42A570();
    refreshAndCheckConnection_42A570();
    drawCursor(164, 321);
    ++v2;
  }
  while ( v0 != 1 );
  eventDetected();
  return sub_418090();
}

//----- (0042C7F0) --------------------------------------------------------
int   sub_42C7F0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  bool v6; // zf@1
  bool v7; // sf@1
  unsigned __int8 v8; // of@1
  int v9; // eax@2
  signed int v10; // ecx@2
  char *v11; // ebp@3
  int result; // eax@8

  refreshAndCheckConnection_42A570();
  v8 = __OFSUB__(dword_456BD0 + 1, 10);
  v6 = dword_456BD0 == 9;
  v7 = dword_456BD0++ - 9 < 0;
  if ( (unsigned __int8)(v7 ^ v8) | v6 )
  {
    drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, (const char *)&unk_443C40, a3 + a1 + 640 * a2);
  }
  else
  {
    v9 = (5 * a2 + 10) << 7;
    v10 = 30;
    do
    {
      v11 = (char *)screenBuffer + v9 + a1 + a3;
      *(_DWORD *)v11 = -993737532;
      *((_DWORD *)v11 + 1) = -993737532;
      *((_DWORD *)v11 + 2) = -993737532;
      *((_DWORD *)v11 + 3) = -993737532;
      v9 += 640;
      --v10;
      *((_DWORD *)v11 + 4) = -993737532;
    }
    while ( v10 );
  }
  if ( dword_456BD0 > 20 )
    dword_456BD0 = 0;
  drawKeyCursor(a3 + a1 + 640 * a2, (char *)screenBuffer + 640 * a2 + a1 + a3, 0x14u, 32);
  result = dword_456BD4;
  if ( dword_456BD4 )
  {
    dword_456BD4 = 0;
  }
  else
  {
    if ( a4 )
    {
	   
		//carAnimCurrentFrame_45FBA0 = 0;
		//TODO he quitado la animacion del coche!!!!
     drawMenuAnimation(a5 + 416, a6 + 80, carAnimCurrentFrame_45FBA0, getCarBpkById(0), (int)&carAnimFrameSize_45FBA0);
	 //drawMenuAnimation(a5 + 416, a6 + 80, carAnimCurrentFrame_45FBA0, (int)kuplaBpk, (int)carAnimFrameSize_45FBA0);
      drawKeyCursor(640 * a6 + a5 + 51616, (char *)screenBuffer + 640 * a6 + a5 + 51616, 0x60u, 64);
      result = carAnimCurrentFrame_45FBA0 + 1;
      v8 = __OFSUB__(carAnimCurrentFrame_45FBA0 + 1, 63);
      v6 = carAnimCurrentFrame_45FBA0 == 62;
      v7 = carAnimCurrentFrame_45FBA0++ - 62 < 0;
      if ( !((unsigned __int8)(v7 ^ v8) | v6) )
        carAnimCurrentFrame_45FBA0 = 0;
    }
    dword_456BD4 = 1;
  }
  return result;
}
// 445968: using guessed type int carAnimFrameSize_45FBA0[];
// 456BD0: using guessed type int dword_456BD0;
// 456BD4: using guessed type int dword_456BD4;
// 45FBA0: using guessed type int carAnimCurrentFrame_45FBA0;

//----- (0042C940) --------------------------------------------------------
//char seeStadistics_42C940()

//----- (0042CBF0) --------------------------------------------------------
//char sub_42CBF0()

//----- (0042CCF0) --------------------------------------------------------

//----- (0042D780) --------------------------------------------------------
int sub_42D780()
{
  bool v0; // zf@1
  bool v1; // sf@1
  unsigned __int8 v2; // of@1
  int result; // eax@7

  refreshAndCheckConnection_42A570();
  refreshAndCheckConnection_42A570();
  drawMenuAnimation(16, 141, carAnimCurrentFrame_45FBA0, getCarBpkById(actualCarSelected), (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
  v2 = __OFSUB__(carAnimCurrentFrame_45FBA0 + 1, 63);
  v0 = carAnimCurrentFrame_45FBA0 == 62;
  v1 = carAnimCurrentFrame_45FBA0++ - 62 < 0;
  if ( !((unsigned __int8)(v1 ^ v2) | v0) )
    carAnimCurrentFrame_45FBA0 = 0;
  refreshAndCheckConnection_42A570();
  refreshAndCheckConnection_42A570();
  drawMenuAnimation(16, 141, carAnimCurrentFrame_45FBA0, getCarBpkById(actualCarSelected), (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
  v2 = __OFSUB__(carAnimCurrentFrame_45FBA0 + 1, 63);
  v0 = carAnimCurrentFrame_45FBA0 == 62;
  v1 = carAnimCurrentFrame_45FBA0++ - 62 < 0;
  if ( !((unsigned __int8)(v1 ^ v2) | v0) )
    carAnimCurrentFrame_45FBA0 = 0;
  refreshAndCheckConnection_42A570();
  refreshAndCheckConnection_42A570();
  drawMenuAnimation(16, 141, carAnimCurrentFrame_45FBA0, getCarBpkById(actualCarSelected), (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
  v2 = __OFSUB__(carAnimCurrentFrame_45FBA0 + 1, 63);
  v0 = carAnimCurrentFrame_45FBA0 == 62;
  v1 = carAnimCurrentFrame_45FBA0++ - 62 < 0;
  if ( !((unsigned __int8)(v1 ^ v2) | v0) )
    carAnimCurrentFrame_45FBA0 = 0;
  refreshAndCheckConnection_42A570();
  refreshAndCheckConnection_42A570();
  drawMenuAnimation(16, 141, carAnimCurrentFrame_45FBA0, getCarBpkById(actualCarSelected), (int)&carAnimFrameSize_45FBA0[64 * actualCarSelected]);
  result = carAnimCurrentFrame_45FBA0 + 1;
  v2 = __OFSUB__(carAnimCurrentFrame_45FBA0 + 1, 63);
  v0 = carAnimCurrentFrame_45FBA0 == 62;
  v1 = carAnimCurrentFrame_45FBA0++ - 62 < 0;
  if ( !((unsigned __int8)(v1 ^ v2) | v0) )
    carAnimCurrentFrame_45FBA0 = 0;
  return result;
}
// 445968: using guessed type int carAnimFrameSize_45FBA0[];
// 45FBA0: using guessed type int carAnimCurrentFrame_45FBA0;
// 45FC30: using guessed type int actualCarSelected;

//----- (0042D8C0) --------------------------------------------------------
//void shopScreenMoveLeft_421DF0()

//----- (0042DAB0) --------------------------------------------------------
//void shopScreenMoveRight_42DAB0()

//----- (0042DC70) --------------------------------------------------------
//char   confirmationPopup(const char *a1)

//----- (0042DD10) --------------------------------------------------------
//int sabotageScreen()

//----- (0042E0B0) --------------------------------------------------------
//signed int   readEventInMenu(int menuType)

//----- (0042E310) --------------------------------------------------------
//bool   drawYesNoMenu(int a1, int a2, int a3, signed int *a4)

//----- (0042E6F0) --------------------------------------------------------
//char noCollectPopup_42E6F0()

//----- (0042E7F0) --------------------------------------------------------
signed int   readKeyboard(const char *a1, int a2, int a3, int a4, unsigned int a5, signed int a6, int ingame, int a8, int a9)
{
  char *v9; // eax@1
  signed int v10; // ebp@1
  unsigned int v11; // edx@1
  char v12; // cl@2
  int v13; // edi@5
  int face; // esi@6
  char v15; // al@6
  int v16; // ebx@6
  signed int v17; // esi@14
  signed int v18; // esi@16
  signed int v19; // esi@23
  signed int v20; // esi@25
  int v21; // ecx@29
  double v22; // st7@31
  signed int v23; // eax@31
  float v24; // ST2C_4@31
  double v25; // st7@31
  float v26; // ST28_4@31
  float v27; // ST24_4@31
  signed int v28; // edx@31
  char *v29; // edi@32
  int v30; // esi@33
  int v31; // ecx@35
  double v32; // st7@37
  signed int v33; // eax@37
  float v34; // ST2C_4@37
  double v35; // st7@37
  float v36; // ST28_4@37
  float v37; // ST24_4@37
  signed int v38; // edx@37
  char *v39; // edi@38
  int v40; // esi@39
  char *v42; // eax@42
  char v43; // cl@43
  int v44; // ecx@47
  int v45; // eax@47
  char *v46 =malloc(100); // eax@48
  char v47; // cl@49
  int v48; // edx@51
  char v49; // dl@54
  unsigned int v50; // eax@60
  char *v51; // edi@60
  char v52; // cl@61
  void *v53; // edi@62
  char *v54; // esi@62
  char v55; // cl@62
  int v56; // eax@62
  signed int v57; // ecx@62
  char *v58; // esi@63
  signed int v59; // esi@64
  int v60; // edi@64
  unsigned __int8 v61; // [sp+1Ch] [bp-5Ch]@57
  char v62; // [sp+1Dh] [bp-5Bh]@1
  int initialFace; // [sp+20h] [bp-58h]@5
  int v64; // [sp+24h] [bp-54h]@5
  int v65; // [sp+28h] [bp-50h]@5
  int v66; // [sp+2Ch] [bp-4Ch]@5
  int v67; // [sp+30h] [bp-48h]@1
  int v68; // [sp+34h] [bp-44h]@31
  int v69; // [sp+38h] [bp-40h]@1
  int v70; // [sp+3Ch] [bp-3Ch]@5
  int v71; // [sp+40h] [bp-38h]@3
  char v72[52]; // [sp+44h] [bp-34h]@1
   int  a = 0;
  //aqui se definen las teclas validas
  memset(byte_45EEE0, 0, 0x100u);
  memset(v72, 0, 52);
  v62 = 0;
  
  byte_45EEE0[2] = 49;// byte_45EEE2 = 49;
  byte_45EEE0[3] = 50; //byte_45EEE3 = 50;
  byte_45EEE0[4] = 51; //byte_45EEE4 = 51;
  byte_45EEE0[5] = 52; //byte_45EEE5 = 52;
  byte_45EEE0[6] = 53; //byte_45EEE6 = 53;
  byte_45EEE0[7] = 54;// byte_45EEE7 = 54;
  byte_45EEE0[8] = 55; //byte_45EEE8 = 55;
  byte_45EEE0[9] = 56; //byte_45EEE9 = 56;
  byte_45EEE0[10] = 57; //byte_45EEEA = 57;
  byte_45EEE0[11] = 48; //byte_45EEEB = 48;
  byte_45EEE0[12] = 45; //byte_45EEEC = 45;
  byte_45EEE0[13] = 61;// byte_45EEED = 61;

  byte_45EEE0[16] = 81; //byte_45EEF0 = 81;
  byte_45EEE0[17] = 87;// byte_45EEF1 = 87;
  byte_45EEE0[18] = 69; // byte_45EEF2 = 69;
  byte_45EEE0[19] = 82; //byte_45EEF3 = 82;
  byte_45EEE0[20] = 84;// byte_45EEF4 = 84;
  byte_45EEE0[21] = 89;// byte_45EEF5 = 89;
  byte_45EEE0[22] = 85;// byte_45EEF6 = 85;
  byte_45EEE0[23] = 73; //byte_45EEF7 = 73;
  byte_45EEE0[24] = 79;//byte_45EEF8 = 79;
  byte_45EEE0[25] = 80;//byte_45EEF9 = 80;
  byte_45EEE0[30] = 65;// byte_45EEFE = 65;
  byte_45EEE0[31] = 83;// byte_45EEFF = 83;
  
  byte_45EEE0[32] = 68; //byte_45EF00 = 68;
  byte_45EEE0[33] = 70;// byte_45EF01 = 70;
  byte_45EEE0[34] = 71; //byte_45EF02 = 71;
  byte_45EEE0[35] = 72;// byte_45EF03 = 72;
  byte_45EEE0[36] = 74; //byte_45EF04 = 74;
  byte_45EEE0[37] = 75; // byte_45EF05
  byte_45EEE0[38] = 76; //byte_45EF06

  byte_45EEE0[44] = 90; //byte_45EF0C = 90;
  byte_45EEE0[45] = 88; //byte_45EF0D = 88;
  byte_45EEE0[46] = 67; //byte_45EF0E = 67;
  byte_45EEE0[47];// byte_45EF0F = 86;

  byte_45EEE0[48] = 66; //byte_45EF10 = 66;

  byte_45EEE0[49] = 78;//byte_45EF11 = 78;
  byte_45EEE0[50] = 77;//byte_45EF12 = 77;
  byte_45EEE0[51] = 44;// byte_45EF13 = 44;
  byte_45EEE0[52] = 46; //byte_45EF14 = 46;
  byte_45EEE0[53] = 47; //byte_45EF15 = 47;
  byte_45EEE0[57] = 32; //byte_45EF19 = 32;
  
  
  strcpy(v72, a1);
  v67 = 640 * a3;
  v69 = 640 * a3 + a2;
  drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, v72, v69);
  v9 = v72;
  v10 = 0;
  v11 = 0;
  do
    v12 = *v9++;
  while ( v12 );
  v71 = v9 - &v72[1];
  if ( v9 != &v72[1] )
  {
    do
	
      v10 += (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+ (unsigned __int8)v72[v11++]];
	  //v10 += (unsigned __int8)menuActive_4457F0[58 + (unsigned __int8)v72[v11++]];
    while ( v11 < strlen(v72) );
  }
  drawKeyCursor(640 * a3 + a2, (char *)screenBuffer + 640 * a3 + a2, v10, 32);
  v13 = a9;
  v70 = 0;
  initialFace = 0;
  v64 = 128;
  v66 = 160950;
  v65 = 384;
 
  while ( 2 )
  {

	  a++;
	 face = initialFace;

	  v68 = *((BYTE *)graphicsGeneral.copperPal + v65 + 2);
    v22 = (double)v68;
    v23 = *((BYTE *)graphicsGeneral.copperPal + v65);
    v68 = *((BYTE *)graphicsGeneral.copperPal + v65 + 1);
    v24 = v22;
    v25 = (double)v68;
    v68 = v23;
    v26 = v25;
    v27 = (double)v23;
    setPaletteValueWithFloats(v27, v26, v24);
       

    sub_42C7F0(a2, a3, v10, v13, 63, 112);
    v15 = eventDetected();
    v16 = (unsigned __int8)v15;
    v71 = (unsigned __int8)v15;
    switch ( v15 )
    {
      case KEY_F1:
        //if ( ingame && isMultiplayerGame )
        //  multiplayer_sub_42CCF0();
        goto LABEL_66;
      case KEY_UP:
      case 0xC8:
        if ( v13 )
        {
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
          if (face <= 0 )
			  initialFace = 19;
          else
			  initialFace = face - 1;
          drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + initialFace), 64, 64, (int)((char *)screenBuffer + 122330));
          drawKeyCursor(122330, (char *)screenBuffer + 122330, 0x40u, 64);
          v17 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v17;
          }
          while ( v17 );
          drawImageWithPosition2((int)((char *)graphics2.facearr1Bpk + 2176), 68, 16, (int)((char *)screenBuffer + 110168));
          drawKeyCursor(110168, (char *)screenBuffer + 110168, 0x44u, 16);
          v18 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v18;
          }
          while ( v18 );
          drawImageWithPosition2((int)graphics2.facearr1Bpk, 68, 16, (int)((char *)screenBuffer + 110168));
          drawKeyCursor(110168, (char *)screenBuffer + 110168, 0x44u, 16);
          drivers[driverId].face = initialFace;
          v16 = 0;
        }
        goto LABEL_66;
      case KEY_DOWN:
      case 0xD0:
        if ( v13 )
        {
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
          if (face >= 19 )
			  initialFace = 0;
          else
			  initialFace = face + 1;
          drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + initialFace), 64, 64, (int)((char *)screenBuffer + 122330));
          drawKeyCursor(122330, (char *)screenBuffer + 122330, 0x40u, 64);
          v19 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v19;
          }
          while ( v19 );
          drawImageWithPosition2((int)((char *)graphics2.facearr1Bpk + 3264), 68, 16, (int)((char *)screenBuffer + 165208));
          drawKeyCursor(165208, (char *)screenBuffer + 165208, 0x44u, 16);
          v20 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v20;
          }
          while ( v20 );
          drawImageWithPosition2((int)((char *)graphics2.facearr1Bpk + 1088), 68, 16, (int)((char *)screenBuffer + 165208));
          drawKeyCursor(165208, (char *)screenBuffer + 165208, 0x44u, 16);
		  drivers[driverId].face = initialFace;
          v16 = 0;
        }
        goto LABEL_66;
      case KEY_LEFT:
      case 0xCB:
        if ( !v13 )
          goto LABEL_66;
        v21 = v65;
        if ( v64 > 0 )
        {
          v21 = v65 - 6;
          v64 -= 2;
          v65 -= 6;
          v66 -= 2;
        }
        v68 = *((BYTE *)graphicsGeneral.copperPal + v21 + 2);
        v22 = (double)v68;
        v23 = *((BYTE *)graphicsGeneral.copperPal + v21);
        v68 = *((BYTE *)graphicsGeneral.copperPal + v21 + 1);
        v24 = v22;
        v25 = (double)v68;
        v68 = v23;
        v26 = v25;
        v27 = (double)v23;
        setPaletteValueWithFloats(v27, v26, v24);
        v28 = 71680;
        do
        {
          v29 = (char *)screenBuffer + v28 + 89124;
          memset(v29, 0xC4u, 0x124u);
          v28 += 640;
          *((_WORD *)v29 + 146) = -15164;
        }
        while ( v28 < 87040 );
        drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 163370));
        v30 = v64;
        drawImageWithPosition((int)slidcur3Bpk, 10, 24, (int)((char *)screenBuffer + v64 + 160824));
        drawKeyCursor(v66, (char *)screenBuffer + v30 + 160822, 0xEu, 24);
        v16 = 0;
        goto LABEL_65;
      case KEY_RIGHT:
      case 0xCD:
        if ( !v13 )
          goto LABEL_66;
        v31 = v65;
        if ( v64 < 253 )
        {
          v31 = v65 + 6;
          v64 += 2;
          v65 += 6;
          v66 += 2;
        }
        v68 = *((BYTE *)graphicsGeneral.copperPal + v31 + 2);
        v32 = (double)v68;
        v33 = *((BYTE *)graphicsGeneral.copperPal + v31);
        v68 = *((BYTE *)graphicsGeneral.copperPal + v31 + 1);
        v34 = v32;
        v35 = (double)v68;
        v68 = v33;
        v36 = v35;
        v37 = (double)v33;
        setPaletteValueWithFloats(v37, v36, v34);
        v38 = 71680;
        do
        {
          v39 = (char *)screenBuffer + v38 + 89124;
          memset(v39, 0xC4u, 0x124u);
          v38 += 640;
          *((_WORD *)v39 + 146) = -15164;
        }
        while ( v38 < 87040 );
        drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 163370));
        v40 = v64;
        drawImageWithPosition((int)slidcur3Bpk, 10, 24, (int)((char *)screenBuffer + v64 + 160824));
        drawKeyCursor(v66, (char *)screenBuffer + v40 + 160822, 0xEu, 24);
        v16 = 0;
        goto LABEL_65;
      case KEY_ESCAPE:
        if ( !a8 )
          goto LABEL_66;
        return 0;
      case KEY_ENTER:
      case 0x9C:
        v42 = v72;
        do
          v43 = *v42++;
        while ( v43 );
        v71 = v42 - &v72[1];
        if ( v42 != &v72[1] )
          v70 = -1;
        if ( v13 )
        {
          v44 = v64;
          v45 = driverId;
		  drivers[driverId].face = face;
		  drivers[driverId].colour = v44;
		  //dword_460880[v45] = face;
          //dword_46086C[v45] = v44;
		  v70 = strlen(v72);
        }
        goto LABEL_66;
      case 0xE:                 //borrar
        v46 = v72;
        do
          v47 = *v46++;
        while ( v47 );
        v68 = v46 - &v72[1];
        if ( v46 == &v72[1] )
          goto LABEL_66;
        v48 = v67;
		
        v10 -= (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+ (unsigned __int8)v72[strlen(v72) - 1]];
		// v10 -= (unsigned __int8)menuActive_4457F0[58 + (unsigned __int8)v72[strlen(v72) - 1]];
        v68 = 32;
        do
        {
          memset(
            (char *)screenBuffer + v48 + v10 + a2,
            0xC4u,
            (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+ *((BYTE *)&v71 + strlen(v72) + 3)] + 20);
          v48 += 640;
          --v68;
        }
        while ( v68 );
        drawKeyCursor(
          v10 + v69,
          (char *)screenBuffer + v67 + v10 + a2,
          (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+ *((BYTE *)&v71 + strlen(v72) + 3)] + 20,
          32);
        v16 = v71;
        *((BYTE *)&v71 + strlen(v72) + 3) = 0;
        goto LABEL_65;
      default:
		
       
		  v49 = byte_45EEE0[(unsigned __int8)v15];
		  if (*(_BYTE *)((unsigned __int8)byte_45EEE0[(unsigned __int8)v15] + a4) == 1 && strlen(v72) < a5 && v10 < a6)
		  {
			  v61 = byte_45EEE0[v16];
			  if ((unsigned __int8)v49 > 0x40u && (unsigned __int8)v49 < 0x5Bu)
				  v61 = v49 + 32;
			  v50 = strlen((const char *)&v61) + 1;
			  v51 = (char *)&v71 + 3;
			  do
				  v52 = (v51++)[1];
			  while (v52);
			  //memcpy(v51, &v61, 4 * (v50 >> 2));
			  v54 = (char *)(&v61 + 4 * (v50 >> 2));
			  v53 = &v51[4 * (v50 >> 2)];
			  v55 = v50;
			  v56 = 0;
			//  memcpy(v53, v54, v55 & 3);
			  v57 = 32;
			  do
			  {
				//  v58 = (char *)screenBuffer + v56 + v10 + a2;
				 /* *(_DWORD *)v58 = -993737532;
				  *((_DWORD *)v58 + 1) = -993737532;
				  *((_DWORD *)v58 + 2) = -993737532;
				  *((_DWORD *)v58 + 3) = -993737532;
				  *((_DWORD *)v58 + 4) = -993737532;
				  *((_DWORD *)v58 + 5) = -993737532;
				  *((_DWORD *)v58 + 6) = -993737532;*/
				  v56 += 640;
				  --v57;
				  //*((_DWORD *)v58 + 7) = -993737532;
			  } while (v57);
			  v59 = v69 + v10 ;
			  drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, (const char *)&v61,  v67 + v10 + a2);
			  //drawTextWithFont((int)fbig3bBpk, (int)&bigLetterSpacing_445848, (const char *)&v61, v58 + v10);
			  v60 = v61;
			  drawKeyCursor(v59, (char *)screenBuffer + v67 + v10 + a2, (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+ v61], 40);
			  v10 += (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+ v60];
			  memcpy(&v72[strlen(v72)], &v61, 1);
LABEL_65:
          v13 = a9;
        }
	LABEL_66:
		//TODO arreglar esto pongo el nombre a fuego
		/*v70 = 4;
		v72[0] = "k";
		v72[1] = "i";
		v72[2] = "k";
		v72[3] = "e";
		v72[4] = 0;*/
        if ( !v70 )
          continue;
        if ( v16 != 1 )
          strcpy((char *)a1, v72);
        return 1;
    }
  }
}

//----- (0042F2E0) --------------------------------------------------------
//signed int loadGame()

//----- (0042F6E0) --------------------------------------------------------
//__int16 savegameWithName()

//----- (0042FB00) --------------------------------------------------------
//signed int redefineControls()

//----- (004302E0) --------------------------------------------------------
//signed int defineGamepadJoystickMenu()

//----- (004309A0) --------------------------------------------------------
//int showAdjustOptions()


//----- (00430FA0) --------------------------------------------------------
//char showHallOfFameEndGame_430FA0()//muestra hall of fame

//----- (004312D0) --------------------------------------------------------
void showEndAnim_4312D0()
{
  unsigned int v0; // eax@2
  char *v1; // edi@2
  char v2; // cl@3
  char *v3; // edi@5
  char v4; // al@6
  FILE *v5; // eax@7
  FILE *v6; // esi@7
  __int32 v7; // edi@8
  int v8; // eax@10
  char *v9; // edx@10
  signed int v10; // ecx@10
  int v11; // eax@10
  signed int v12; // edx@10
  float v13; // ST1C_4@10
  float v14; // ST18_4@10
  float v15; // ST14_4@10
  int v16; // edi@10
  signed int v17; // ebp@10
  unsigned __int8 v18; // bl@11
  signed int v19; // esi@11
  int v20; // ST1C_4@12
  int v21; // ST18_4@12
  int v22; // eax@12
  int v23; // [sp+1Ch] [bp-68h]@2
  char Filename; // [sp+20h] [bp-64h]@1

  Filename = 0;
  if ( byte_462D50 == 2 )
  {
    v0 = strlen(byte_45FAA0) + 1;
    v1 = (char *)&v23 + 3;
    do
      v2 = (v1++)[1];
    while ( v2 );
    memcpy(v1, byte_45FAA0, v0);
  }
  v3 = (char *)&v23 + 3;
  do
    v4 = (v3++)[1];
  while ( v4 );
  *(_DWORD *)v3 = 1633971813;
  *((_DWORD *)v3 + 1) = 1747872110;
  *((_WORD *)v3 + 4) = 26209;
  v3[10] = 0;
  v5 = fopen(&Filename, "rb");
  v6 = v5;
  if ( v5 )
  {
    fseek(v5, 0, 2);
    v7 = ftell(v6);
    fclose(v6);
    if ( v7 > 0 )
      openAnimation("ENDANI.haf", 1, "tr0-mus.cmf", 2, "endani-e.cmf", 1, 120);
  }
  nullsub_1();
  setWindowCaption2();
  recalculateSDLTicks_43C740();
  showStartScreen();
  loadGraphics2();
  loadGraphics3();
  loadGraphics4();
  transitionToBlack();
  loadPaletteMenu();
  v8 = drivers[driverId].colour;
  v9 = (char *)graphicsGeneral.copperPal + 2 * v8;
  v10 = (unsigned __int8)v9[v8 + 2];
  v11 = (int)&v9[v8];
  v12 = *(BYTE *)(v11 + 1);
  v13 = (double)v10;
  v23 = *(BYTE *)v11;
  v14 = (double)v12;
  v15 = (double)v23;
  sub_418B00(v15, v14, v13);
  showHallOfFameEndGame_430FA0();
  sub_4224E0();
  v16 = 6553600;
  v17 = 65500;
  do
  {
    waitWithRefresh();
    setMusicVolume(v17);
    v18 = 0;
    v19 = 0;
	//v19 = (signed int)dword_45FC44;
    do
    {
      v20 = (convertColorToPaletteColor((palette1[v19+2]), v16) + 0x8000) >> 16;
      v21 = (convertColorToPaletteColor(palette1[v19 + 1], v16) + 0x8000) >> 16;
      v22 = convertColorToPaletteColor((palette1[v19]), v16);
      setPaletteAndGetValue(v18, (v22 + 0x8000) >> 16, v21, v20);
      v19 += 3;
      ++v18;
    }
    while ( v19 <maxPaletteEntries );
    v17 -= 1310;
    v16 -= 0x20000;
  }
  while ( v17 >= 0 );
  stopSong();
  stopAndOpenMusic();
  loadMusic(1, "MEN-MUS.CMF", 2,"MEN-SAM.CMF");
  musicSetmusicVolume(configuration.musicVolume);
  nullsub_1();
  musicPlayMusic();
  nullsub_1();
}

//----- (00431510) --------------------------------------------------------
//----- (00431510) --------------------------------------------------------
//int seeHallOfFame()

//----- (00431B30) --------------------------------------------------------
//int showHitmanScreen()

//----- (004321B0) --------------------------------------------------------
//void   previewRaceScreen(signed int participants)

//----- (00434800) --------------------------------------------------------
//int   licenseScreen(int useWeapons_mal)

//----- (00435320) --------------------------------------------------------
//int  adversaryPreviewScreen(const char **a1)

//----- (004357F0) --------------------------------------------------------
//void selectRaceScreen()

//----- (004360B0) --------------------------------------------------------
//void __thiscall underGroundMenuEnter(void *this)

//----- (00436700) --------------------------------------------------------
//void enterBlackMarketScreen()

//----- (004373B0) --------------------------------------------------------
//void enterShop()

//----- (004387D0) --------------------------------------------------------
//char postLoadedOrLicense()

//----- (00439CD0) --------------------------------------------------------
//void startRacingMenu()

void inicializeGraphicVars() {
	tsahpeBpk_45EB5C = malloc(0x18150u);
}

//----- (0043A020) --------------------------------------------------------
//int mainMenu()

//----- (0043ACB0) --------------------------------------------------------
void __noreturn exitGame_43ACB0()
{
  nullsub_1();
  setWindowCaption();
  printf("DEATH RALLY Exit: CTRL+ALT+DEL pressed!\n");
  exit(112);
}

//----- (0043ACE0) --------------------------------------------------------
int  sub_43ACE0(double a1, int a2, int a3,char *args)
{
  dword_45EA0C = a2;
 
  dword_45EA24 = *(_DWORD *)(a3 + 4);
  dword_45EA28 = *(_DWORD *)(a3 + 8);
  dword_45EA2C = *(_DWORD *)(a3 + 12);
  dword_45EA30 = *(_DWORD *)(a3 + 16);
  dword_45EA34 = *(_DWORD *)(a3 + 20);
  dword_45EA38 = *(_DWORD *)(a3 + 24);
  dword_45EA3C = *(_DWORD *)(a3 + 28);
  dword_45EA40 = *(_DWORD *)(a3 + 32);
  dword_45EA44 = *(_DWORD *)(a3 + 36);  
  checkArgs(args);
  initI18n();
  initMod();
  inicializeScreen(a1);
  dword_4A9140 = (int)exitGame_43ACB0;
  nullsub_1();
  mainMenu();
  nullsub_1();
  if ( isMultiplayerGame )
    nullsub_1();
  freeMusic();
  return 0;
}

//----- (0043AEC0) --------------------------------------------------------
char   drawCarSprite_43AEC0(int xpos, int ypos, int participantBpkOffset)
{
  int v3; // edx@1
  char result; // al@1
  int v5; // ecx@1
  signed int v6; // edi@1
  signed int v7; // esi@4
  v3 = participantBpkOffset	;
  
  result = 0;
  v5 = (ypos << 9) + xpos - 10164;//posicion donde pintar
  v6 = 40;
  do
  {
    if ( v5 < 0 || v5 >= 102400 )
    {
      v5 += 512;
      v3 += 40;
    }
    else
    {
      v7 = 40;
      do
      {
        result = *((BYTE *)participantCarBpk_5034FC + v3++);
        if ( result )
          *(BYTE *)(dword_464F14 + v5) = result;
        ++v5;
        --v7;
      }
      while ( v7 );
      v5 += 472;
    }
    --v6;
  }
  while ( v6 );
  return result;
}
// 464F14: using guessed type int dword_464F14;

//----- (0043AF30) --------------------------------------------------------
//char   drawPedestrian_43AF30(int screenOffset, int pedestrianbpkOffset, int sizeToPaint)

//----- (0043AFC0) --------------------------------------------------------
char   drawCarFire_43AFC0(int posx, int posy, int spriteOffset)
{
  int v3; // edx@1
  char result; // al@1
  int v5; // ecx@1
  signed int v6; // edi@1
  signed int v7; // esi@4

  v3 = spriteOffset;
  result = 0;
  v5 = (posy << 9) + posx - 4008;
  v6 = 16;
  do
  {
    if ( v5 < 0 || v5 >= 102400 )
    {
      v5 += 512;
      v3 += 16;
    }
    else
    {
      v7 = 16;
      do
      {
        result = *((BYTE *)burn1aBpk + v3++);
        if ( result )
          *(BYTE *)(dword_464F14 + v5) = result;
        ++v5;
        --v7;
      }
      while ( v7 );
      v5 += 496;
    }
    --v6;
  }
  while ( v6 );
  return result;
}
// 464F14: using guessed type int dword_464F14;

//----- (0043B030) --------------------------------------------------------
int   sub_43B030(int a1, int a2)
{
  int v2; // ecx@1
  int result; // eax@1
  signed int v4; // edx@1

  v2 = a2;
  result = a2 + a1;
  v4 = 10;
  do
  {
    if ( v2 >= 0 )
      *(BYTE *)result = 0;
    ++result;
    ++v2;
    --v4;
  }
  while ( v4 );
  return result;
}

//----- (0043B050) --------------------------------------------------------
int   sub_43B050(int a1, signed int a2)
{
  signed int v2; // edx@1
  int result; // eax@1
  signed int v4; // ecx@1

  v2 = a2;
  result = a2 + a1;
  v4 = 0;
  do
  {
    if ( v2 > 255 )
      break;
    ++result;
    *(BYTE *)(result - 1) = 0;
    ++v2;
    ++v4;
  }
  while ( v4 < 10 );
  return result;
}

//----- (0043B080) --------------------------------------------------------
int   sub_43B080(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // edx@1
  int v6; // ecx@1
  int result; // eax@1
  int v8; // esi@1
  int v9; // edi@3

  v5 = a4;
  v6 = a2;
  result = a5;
  v8 = a1;
  if ( a4 > 0 )
  {
    do
    {
      if ( a3 > 0 )
      {
        v9 = a3;
        do
        {
          if ( *(BYTE *)v8 )
            *(BYTE *)result = *(BYTE *)v6;
          ++v6;
          ++result;
          ++v8;
          --v9;
        }
        while ( v9 );
      }
      result += 640 - a3;
      v6 += 640 - a3;
      --v5;
    }
    while ( v5 );
  }
  return result;
}

//----- (0043B0D0) --------------------------------------------------------
void   copyBuffer2Screen(void *a1, const void *a2, int a3)
{
  memcpy(a1, a2, 4 * a3);
}

//----- (0043B0F0) --------------------------------------------------------
int   extractBits(int src, signed int bitOffset, int bitLenght)
{
  int v3; // ebp@1
  int v4; // esi@1
  int v5; // edx@1
  int v6; // edi@2

  v3 = 0;
  v4 = 0;
  v5 = bitOffset % 8;
  if (bitLenght > 0 )
  {
    v6 = bitOffset / 8 + src;
    do
    {
      v3 |= ((*(BYTE *)v6 & (unsigned __int8)(1 << v5++)) != 0) << v4++;
      if ( v5 == 8 )
      {
        v5 = 0;
        ++v6;
      }
    }
    while ( v4 < bitLenght);
  }
  return v3 & ((1 << bitLenght) - 1);
}

//----- (0043B160) --------------------------------------------------------
int   drawInRaceImageToBuffer_43B160(int image, int sizex, int sizey, int buffer)
{
  int result; // eax@1
  int v5; // ecx@2
  int v6; // ebp@2
  int v7; // esi@drawInRaceImageToBuffer_43B160

  result = sizey;
  if ( sizey > 0 )
  {
    v5 = image;
    v6 = sizey;
    result = buffer;
    do
    {
      if ( sizex > 0 )
      {
        v7 = sizex;
        do
        {
          *(BYTE *)result++ = *(BYTE *)v5++;
          --v7;
        }
        while ( v7 );
      }
      result += 512 - sizex;
      --v6;
    }
    while ( v6 );
  }
  return result;
}

//----- (0043B1A0) --------------------------------------------------------
int   drawRaceCharInMenu_43B1A0(int a1, int a2, int a3, int a4)
{
  int result; // eax@1
  int v5; // ecx@2
  int v6; // edx@2
  int v7; // ebx@2
  int v8; // esi@4
  char v9; // al@5

  result = a3;
  if ( a3 > 0 )
  {
    v5 = a4;
    v6 = a1;
    v7 = a3;
    do
    {
      if ( a2 > 0 )
      {
        v8 = a2;
        do
        {
          v9 = *(BYTE *)v6++;
          if ( v9 )
            *(BYTE *)v5 = v9;
          ++v5;
          --v8;
        }
        while ( v8 );
      }
      result = 320 - a2;
      v5 += 320 - a2;
      --v7;
    }
    while ( v7 );
  }
  return result;
}

//----- (0043B1F0) --------------------------------------------------------
int   drawCharInRaceScreen(int a1, int a2, int a3, int a4)
{
  int result; // eax@1
  int v5; // ecx@2
  int v6; // edx@2
  int v7; // ebx@2
  int v8; // esi@4
  char v9; // al@5

  result = a3;
  if ( a3 > 0 )
  {
    v5 = a4;
    v6 = a1;
    v7 = a3;
    do
    {
      if ( a2 > 0 )
      {
        v8 = a2;
        do
        {
          v9 = *(BYTE *)v6++;
          if ( v9 )
            *(BYTE *)v5 = v9;
          ++v5;
          --v8;
        }
        while ( v8 );
      }
      result = 204 - a2;
      v5 += 204 - a2;
      --v7;
    }
    while ( v7 );
  }
  return result;
}

//----- (0043B240) --------------------------------------------------------
int   drawImageInRace_43B240(int filename, int width, int height, int offset)
{
  int result; // eax@1
  int v5; // ecx@2
  int v6; // edx@2
  int v7; // ebx@2
  int v8; // esi@4
  char v9; // al@5

  result = height;
  if ( height > 0 )
  {
    v5 = offset;
    v6 = filename;
    v7 = height;
    do
    {
      if ( width > 0 )
      {
        v8 = width;
        do
        {
          v9 = *(BYTE *)v6++;
          if ( v9 )
            *(BYTE *)v5 = v9;
          ++v5;
          --v8;
        }
        while ( v8 );
      }
      result = 512 - width;
      v5 += 512 - width;
      --v7;
    }
    while ( v7 );
  }
  return result;
}

//----- (0043B290) --------------------------------------------------------
int   colorToPaletteEntry(int a1, signed int a2)
{
  signed __int64 v2; // rax@2

  if ( a2 )
    v2 = ((signed __int64)a1 << 16) / a2;
  else
    LODWORD(v2) = 0;
  return v2;
}

//----- (0043B2D0) --------------------------------------------------------
int sub_43B2D0()
{
  int result; // eax@1

  result = dword_456BFC;
  dword_456BFC = 0;
  return result;
}
// 456BFC: using guessed type int dword_456BFC;

//----- (0043B2E0) --------------------------------------------------------
int sub_43B2E0()
{
  int result; // eax@1

  result = dword_456BF8;
  dword_456BF8 = 0;
  return result;
}
// 456BF8: using guessed type int dword_456BF8;

//----- (0043B2F0) --------------------------------------------------------
int   draw3dTexture_43B2F0(int a1, int a2, int a3, int textureId)//offsetx, offsety , textura,index
{
  int v3; // ebx@1
  int v4; // edi@1
  int result; // eax@1
  char *v6; // ecx@1
  int v7; // esi@1
  int i; // ebp@1
  int v9; // edi@6

  //trxSCE5Bpk_4A7A28 ancho textura siguiente alto siguiente datos
  //v3 = *(_DWORD *)(a3 + 4);
  v3 = sce4Texture[textureId].textureHeight_50A184;
  v4 = dword_464F14;
  result = dword_464F14 + (a2 << 9) + a1 + 96;
  //v6 = (char *)trxSCE5Bpk_4A7A28 + *(_DWORD *)(a3 + 8);
  v6 = (char *)trxSCE5Bpk_4A7A28 + sce4Texture[textureId].textureOffset_50A188 ;
  
  //v7 = *(_DWORD *)a3;
  v7 = sce4Texture[textureId].tetureWidth_50A180;
  for ( i = 0; i < v3; ++i )
  {
    if ( v4 + 102400 < (unsigned int)result )//si ha pintado mas de 102400 bytes cortamos
      break;
    if ( result >= (unsigned int)v4 )
    {
      if ( v7 > 0 )
      {
        v9 = v7;
        do
        {
          if ( *v6 )
            *(BYTE *)result = *v6;
          ++result;
          ++v6;
          --v9;
        }
        while ( v9 );
        v4 = dword_464F14;
      }
      result += 512 - v7;
    }
    else
    {
      v6 += v7;
      result += 512;
    }
  }
  return result;
}
// 464F14: using guessed type int dword_464F14;

//----- (0043B370) --------------------------------------------------------
int   sub_43B370(int a1, int a2, int a3)
{
  int v3; // ecx@1
  int v4; // esi@1
  int result; // eax@1
  signed int v6; // ebp@1
  char v7; // dl@2

  v3 = a2;
  v4 = a1;
  result = 0;
  v6 = 256;
  do
  {
    v7 = *(BYTE *)v3;
    result += a3;
    ++v3;
    *(BYTE *)v4 = v7;
    if ( BYTE1(result) & 1 )
    {
      result = (unsigned __int8)result;
      ++v4;
    }
    --v6;
  }
  while ( v6 );
  return result;
}

//----- (0043B3A0) --------------------------------------------------------
int   drawTurboBar_43B3A0(int a1, int a2, int a3, char a4)
{
  int result; // eax@1
  int v5; // edi@2
  int v6; // ecx@4

  result = a3;
  if ( a3 > 0 )
  {
    v5 = a3;
    result = a1;
    do
    {
      if ( a2 > 0 )
      {
        v6 = a2;
        do
        {
          if ( *(BYTE *)result >= 0x40u )
            *(BYTE *)result = a4;
          ++result;
          --v6;
        }
        while ( v6 );
      }
      result += 512 - a2;
      --v5;
    }
    while ( v5 );
  }
  return result;
}

//----- (0043B3E0) --------------------------------------------------------
void   SetVideoMode(int fullScreen)
{
  
  unsigned int flagsNoGL; // esi@1
  signed int v3; // ebp@4
#ifndef PORTABILITY
  GLsizei glWidth; // esi@4
  GLsizei glHeight; // ebx@4
  GLvoid *v6; // edi@5

#endif

  int flags; // [sp+0h] [bp-4h]@4

  flagsNoGL = 0;
  if (fullScreen)
	  flagsNoGL = SDL_FULLSCREEN;
  SDL_ShowCursor(fullScreen == 0);

#ifndef PORTABILITY

  if ( mainArgs.configGL )
  {
    v3 = 32;
	flags = 2;
	glWidth = 640;
	glHeight = 480;
    if ( pixels )
    {
      glClear(0x4000u);
      SDL_GL_SwapBuffers();
    }
    else
    {
      v6 = malloc(0x12C000u);
      pixels = v6;
      memset(v6, 0, 0x12C000u);	  
    }
    if (fullScreen)
    {
		glWidth = screenWidth;
		glHeight = screenHeight;
      v3 = screenColors;
	  flags = -2147483646;
    }
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    screenSurface = SDL_SetVideoMode(glWidth, glHeight, v3, flags);
    glMatrixMode(0x1701u);
    glLoadIdentity();
    glMatrixMode(0x1700u);
    glLoadIdentity();
    glViewport(0, 0, glWidth, glHeight);
    glBindTexture(0xDE1u, 1u);
    glTexImage2D(0xDE1u, 0, 6407, 512, 256, 0, 0x1907u, 0x1401u, 0);
    glBindTexture(0xDE1u, 2u);
    glTexImage2D(0xDE1u, 0, 6407, 1024, 512, 0, 0x1907u, 0x1401u, 0);
  }
  else
  {
#endif

    //screenSurface = SDL_SetVideoMode(640, 480, 32, v2);
	screenSurface = SDL_SetVideoMode(640, 480, 32, flagsNoGL);
#ifndef PORTABILITY

  }
#endif

}

//----- (0043B580) --------------------------------------------------------
int   refreshScreen(int a1)
{
  int result; // eax@1
  int v2; // esi@1
  signed int v3; // edi@4
  char *v4; // eax@5
  signed int v5; // edx@5
  int v6; // ecx@6
  int v7; // esi@6
  int v8; // ecx@6
  int v9; // ecx@6
  void (__stdcall *v10)(GLfloat, GLfloat); // esi@12
  void (__stdcall *v11)(GLfloat, GLfloat); // edi@12
  float y =0.0; // ST20_4@12
  float x =0.0; // ST1C_4@12
  void (__stdcall *v14)(GLfloat, GLfloat); // esi@13
  void (__stdcall *v15)(GLfloat, GLfloat); // edi@13
  char *v16; // eax@15
  signed int v17; // edx@15
  int v18; // ecx@16
  int v19; // esi@16
  int v20; // ecx@16
  int v21; // ecx@16
  float v22; // ST20_4@19
  float v23; // ST1C_4@19
  float v24; // ST20_4@20
  float v25; // ST1C_4@20
  SDL_Surface * screenSurfaceTemp; // edx@22
  //int screenSurfaceTemp; // edx@22
  
  unsigned int v27; // ecx@22
  int v28; // ebp@24
  signed int v29; // ebx@24
  int v30; // eax@25
  signed int v31; // edi@25
  int v32; // edx@26
  int v33; // edx@26
  int v34; // eax@26
  int v35; // esi@26
  int v36; // edx@26
  int v37; // edx@26
  int v38; // edx@26
  int v39; // edi@29
  int v40; // ebx@29
  int v41; // eax@31
  signed int v42; // ebp@31
  int v43; // edx@32
  int v44; // esi@32
  int v45; // edx@32
  int v46; // edx@32
  int v47; // ebx@34
  int v48; // edx@35
  signed int v49; // ebp@35
  signed int v50; // eax@36
  int v51; // edx@36
  int v52; // esi@38
  int v53; // eax@39
  signed int v54; // edx@39
  int v55; // ebx@43
  int v56; // edi@44
  int v57; // ebp@44
  int v58; // eax@45
  int i; // ecx@45
  signed int v60; // [sp+10h] [bp-1Ch]@29
  signed int v61; // [sp+10h] [bp-1Ch]@34
  signed int v62; // [sp+14h] [bp-18h]@38
  int v63; // [sp+14h] [bp-18h]@44
  SDL_Event event; // [sp+18h] [bp-14h]@51
  unsigned __int8 v65 = 0; // [sp+1Ch] [bp-10h]@58
  int v66 = 0; // [sp+20h] [bp-Ch]@56  
  int v67 = 0; // [sp+24h] [bp-8h]@60
  int v68 = 0; // [sp+28h] [bp-4h]@68
SDL_Color* color;
  result = dword_456C28;
  v2 = screenPtr_456BF4;
  if ( dword_456C28 )
    return result;
  result = a1;
  if ( dword_456C18 == a1 )
    return result;
  dword_456C18 = a1;
  SDL_Delay(1);

#ifndef PORTABILITY

  if ( mainArgs.configGL )
  {
    v3 = 0;
    if ( dword_456C14 == 19 )
    {
      do
      {
        v4 = (char *)pixels + v3;
        v5 = 64;
        do
        {
          *(_DWORD *)v4 = palette[*(BYTE *)v2] | 0xFF000000;
          v6 = palette[*(BYTE *)(v2 + 1)];
          v7 = v2 + 1;
          *((_DWORD *)v4 + 1) = v6 | 0xFF000000;
          v8 = palette[*(BYTE *)(v7++ + 1)];
          *((_DWORD *)v4 + 2) = v8 | 0xFF000000;
          v9 = palette[*(BYTE *)(v7 + 1)];
          v7 += 2;
          *((_DWORD *)v4 + 3) = v9 | 0xFF000000;
          *((_DWORD *)v4 + 4) = palette[*(BYTE *)v7] | 0xFF000000;
          v2 = v7 + 1;
          v4 += 20;
          --v5;
        }
        while ( v5 );
        v3 += 1280;
      }
      while ( v3 < 256000 );
      glEnable(0xDE1u);
      glBindTexture(0xDE1u, 1u);
      glTexSubImage2D(0xDE1u, 0, 0, 0, 320, 200, 0x1908u, 0x1401u, pixels);
      if ( mainArgs.configSmooth )
      {
        glTexParameteri(0xDE1u, 0x2801u, 9728);
        glTexParameteri(0xDE1u, 0x2800u, 9728);
      }
      else
      {
        glTexParameteri(0xDE1u, 0x2801u, 9729);
        glTexParameteri(0xDE1u, 0x2800u, 9729);
      }
      glClear(0x4000u);
      if (screenSurface ==NULL )
      {
        glBegin(7u);
        v10 = glTexCoord2f;
        glTexCoord2f(0.0, 0.78125);
        v11 = glVertex2f;
        y = -y;
        x = -x;
        glVertex2f(x, y);
        glTexCoord2f(0.625, 0.78125);
LABEL_20:
        v24 = -y;
        v11(x, v24);
        v10(0.625, 0.0);
        v11(x, y);
        v10(0.0, 0.0);
        v25 = -x;
        v11(v25, y);
        glEnd();
        SDL_GL_SwapBuffers();
        goto LABEL_49;
      }
      glBegin(7u);
      v14 = glTexCoord2f;
      glTexCoord2f(0.0, 0.78125);
      v15 = glVertex2f;
      glVertex2f(-1.0, -1.0);
      glTexCoord2f(0.625, 0.78125);
    }
    else
    {
      do
      {
        v16 = (char *)pixels + v3;
        v17 = 128;
        do
        {
          *(_DWORD *)v16 = palette[*(BYTE *)v2] | 0xFF000000;
          v18 = palette[*(BYTE *)(v2 + 1)];
          v19 = v2 + 1;
          *((_DWORD *)v16 + 1) = v18 | 0xFF000000;
          v20 = palette[*(BYTE *)(v19++ + 1)];
          *((_DWORD *)v16 + 2) = v20 | 0xFF000000;
          v21 = palette[*(BYTE *)(v19 + 1)];
          v19 += 2;
          *((_DWORD *)v16 + 3) = v21 | 0xFF000000;
          *((_DWORD *)v16 + 4) = palette[*(BYTE *)v19] | 0xFF000000;
          v2 = v19 + 1;
          v16 += 20;
          --v17;
        }
        while ( v17 );
        v3 += 2560;
      }
      while ( v3 < 1228800 );
      glEnable(0xDE1u);
      glBindTexture(0xDE1u, 2u);
      glTexSubImage2D(0xDE1u, 0, 0, 0, 640, 480, 0x1908u, 0x1401u, pixels);
      glTexParameteri(0xDE1u, 0x2801u, 9729);
      glTexParameteri(0xDE1u, 0x2800u, 9729);
      glClear(0x4000u);
      if ( *(_DWORD *)screenSurface < 0 )
      {
        glBegin(7u);
        v10 = glTexCoord2f;
        glTexCoord2f(0.0, 0.9375);
        v11 = glVertex2f;
        v22 = -y;
        v23 = -x;
        glVertex2f(v23, v22);
        glTexCoord2f(0.625, 0.9375);
        goto LABEL_20;
      }
      glBegin(7u);
      v14 = glTexCoord2f;
      glTexCoord2f(0.0, 0.9375);
      v15 = glVertex2f;
      glVertex2f(-1.0, -1.0);
      glTexCoord2f(0.625, 0.9375);
    }
    v15(1.0, -1.0);
    v14(0.625, 0.0);
    v15(1.0, 1.0);
    v14(0.0, 0.0);
    v15(-1.0, 1.0);
    glEnd();
    SDL_GL_SwapBuffers();
    goto LABEL_49;
  }
#endif

  screenSurfaceTemp = screenSurface;
  v27 = screenSurface->pitch >> 2;
  //v27 = (unsigned int)*(_WORD *)(screenSurface + 16) >> 2;

  if ( dword_456C14 == 19 )
  {
    if ( mainArgs.configSmooth )
    {
      v28 = 160 * v27;
      v29 = 200;
      do
      {
		  
		  //v30 = v28 + *(_DWORD *)(screenSurfaceTemp + 20);
		  v30 = (unsigned char*)screenSurfaceTemp->pixels + v28;
        v31 = 64;
        do
        {
          v32 = palette[*(BYTE *)v2];
          *(_DWORD *)v30 = v32;
          *(_DWORD *)(v30 + 4 * v27) = v32;
          *(_DWORD *)(v30 + 4) = v32;
          *(_DWORD *)(v30 + 4 * v27 + 4) = v32;
          v33 = palette[*(BYTE *)(v2 + 1)];
          v34 = v30 + 4;
          *(_DWORD *)(v34 + 4) = v33;
          *(_DWORD *)(v34 + 4 * v27 + 4) = v33;
          v34 += 4;
          *(_DWORD *)(v34 + 4) = v33;
          *(_DWORD *)(v34 + 4 * v27 + 4) = v33;
          v35 = v2 + 1;
          v36 = palette[*(BYTE *)(v35 + 1)];
          v34 += 4;
          *(_DWORD *)(v34 + 4) = v36;
          *(_DWORD *)(v34 + 4 * v27 + 4) = v36;
          v34 += 4;
          *(_DWORD *)(v34 + 4) = v36;
          ++v35;
          *(_DWORD *)(v34 + 4 * v27 + 4) = v36;
          v37 = palette[*(BYTE *)(v35 + 1)];
          v34 += 4;
          *(_DWORD *)(v34 + 4) = v37;
          ++v35;
          v34 += 4;
          *(_DWORD *)(v34 + 4 * v27) = v37;
          *(_DWORD *)(v34 + 4) = v37;
          v34 += 4;
          *(_DWORD *)(v34 + 4 * v27) = v37;
          v38 = palette[*(BYTE *)(v35 + 1)];
          v34 += 4;
          *(_DWORD *)v34 = v38;
          *(_DWORD *)(v34 + 4 * v27) = v38;
          v34 += 4;
          *(_DWORD *)v34 = v38;
          *(_DWORD *)(v34 + 4 * v27) = v38;
          v2 = v35 + 2;
          v30 = v34 + 4;
          --v31;
        }
        while ( v31 );
		screenSurfaceTemp = screenSurface;
        v28 += 8 * v27;
        --v29;
      }
      while ( v29 );
    }
    else
    {
      v39 = 8 * v27;
      v40 = 160 * v27;
      v60 = 200;
      while ( 1 )
      {
        v41 = v40 + (unsigned char*)screenSurfaceTemp->pixels;
        v42 = 64;
        do
        {
          *(_DWORD *)v41 = palette[*(BYTE *)v2];
          v43 = palette[*(BYTE *)(v2 + 1)];
          v44 = v2 + 1;
          *(_DWORD *)(v41 + 8) = v43;
          v45 = palette[*(BYTE *)(v44 + 1)];
          v44 += 2;
          *(_DWORD *)(v41 + 16) = v45;
          v46 = palette[*(BYTE *)v44++];
          *(_DWORD *)(v41 + 24) = v46;
          *(_DWORD *)(v41 + 32) = palette[*(BYTE *)v44];
          v2 = v44 + 1;
          v41 += 40;
          --v42;
        }
        while ( v42 );
        v40 += v39;
        --v60;
        if ( !v60 )
          break;
		screenSurfaceTemp = screenSurface;
      }
      v47 = 160 * v27;
      v61 = 200;
      do
      {
        v48 = v47 + (unsigned char*)screenSurface->pixels;
        v49 = 319;
        do
        {
          v50 = (*(_DWORD *)v48 & 0xFCFCFC) + (*(_DWORD *)(v48 + 8) & 0xFCFCFC);
          v51 = v48 + 4;
          *(_DWORD *)v51 = v50 >> 1;
          v48 = v51 + 4;
          --v49;
        }
        while ( v49 );
        v47 += v39;
        --v61;
      }
      while ( v61 );
      v52 = 160 * v27;
      v62 = 200;
      do
      {
        v53 = v52 + (unsigned char*)screenSurface->pixels;
        v54 = 213;
        do
        {
          *(_DWORD *)(v53 + 4 * v27) = ((*(_DWORD *)v53 & 0xFCFCFC) + (*(_DWORD *)(v39 + v53) & 0xFCFCFC)) >> 1;
          *(_DWORD *)(v53 + 4 * v27 + 4) = ((*(_DWORD *)(v53 + 4) & 0xFCFCFC) + (*(_DWORD *)(v39 + v53 + 4) & 0xFCFCFC)) >> 1;
          *(_DWORD *)(v53 + 4 * v27 + 8) = ((*(_DWORD *)(v53 + 8) & 0xFCFCFC) + (*(_DWORD *)(v39 + v53 + 8) & 0xFCFCFC)) >> 1;
          v53 += 12;
          --v54;
        }
        while ( v54 );
        v52 += v39;
        --v62;
      }
      while ( v62 );
	  screenSurfaceTemp = screenSurface;
    }
  }
  else
  {
    v55 = 0;
    if (screenSurface->h> 0 )
    {
      v56 = screenSurface->w; //heihgt
      v57 = 0;

	  v63 = 4 * v27;
	  //v2 = screenPtr;
	  
      do
      {
        v58 = v57 + (unsigned char*)screenSurfaceTemp->pixels;
        for ( i = 0; i < v56; ++i )
        {
			//*(_DWORD *)v58 = &screenSurfaceTemp->format->palette->colors[*(BYTE *)v2];
			
			if (palette[1] != 0) {
				int a = 0;
			}
			*(unsigned int *)v58 = palette[(*(BYTE *)v2)];
			//*(unsigned int *)v58 = palette[248];
			//*(unsigned int *)v58 = SDL_MapRGBA(screenSurface->format,BYTE2(palette[(*(BYTE *)v2)]),BYTE1(palette[(*(BYTE *)v2)]) ,BYTE4(palette[(*(BYTE *)v2)]) ,0);

		 
		  color = (SDL_Color *)&palette[*(BYTE *)v2];
		  
		  screenSurfaceTemp = screenSurface;
          //v56 = screenSurface->w;
          v58 += 4;
          ++v2;
        }
        ++v55;
        v57 += v63;
      }
      while ( v55 < screenSurfaceTemp->h );
    }
  }
  
  SDL_UpdateRect(screenSurfaceTemp, 0, 0, screenSurfaceTemp->w, screenSurfaceTemp->h);
LABEL_49:
  if ( !mainArgs.configNoSound )
    FSOUND_Update();
  for ( result = SDL_PollEvent(&event); result; result = SDL_PollEvent(&event) ) //&event v65 es event.key.keysym.scancode
  {
    switch (event.type)
    {
      case SDL_KEYDOWN: //2
		  if (event.key.keysym.sym == SDLK_RETURN) //return 
			 
			//if (v66 == 13)
        {
			 
			if ( !(event.key.keysym.mod & 0x300) ) //v67 es event.key.keysym.mod
            goto LABEL_68;
        }
        else if (event.key.keysym.sym != SDLK_F12 )
        {
LABEL_68:
			//v68 no se que es aunque no parece grave
          if ( !(v68 & 0xFF80) )
            dword_456BFC = v68 & 0x7F;
          dword_456BF8 = event.key.keysym.scancode;
          keysRead_45E0C0[event.key.keysym.scancode] = 1;
          continue;
        }
        break;
      case SDL_KEYUP: //3
        if ( event.key.keysym.sym == SDLK_F12 ) //f12
			//if (v66 == 293)
        {
          mainArgs.configSmooth = mainArgs.configSmooth == 0;
        }
        else if (event.key.keysym.sym == SDLK_RETURN &&  event.key.keysym.mod & 0x300 )
        {
          if ( *(_DWORD *)screenSurface >= 0 )
            SetVideoMode(1);
          else
            SetVideoMode(0);
          continue;
        }
        keysRead_45E0C0[event.key.keysym.scancode] = 0;
        break;
      case SDL_QUIT: //12
        exit(0);
        break;
    }
  }
  return result;
}

//----- (0043BD70) --------------------------------------------------------
int   setWindowCaption3(int a1)
{
  int result; // eax@1
  SDL_Surface *v2; // esi@4
  int v3; // ebx@4
  int v4; // ecx@5
  int v5; // edi@5
  unsigned int v6; // ebp@5
  int v7; // eax@6
  int i; // edx@6

  memset((void *)screenPtr_456BF4, 0, 0x4B000u);
  result = a1;
  if ( dword_456C14 != a1 )
  {
    if ( a1 == 19 )
    {
      if ( !mainArgs.configGL )
      {
        v2 = screenSurface;
        v3 = 0;
        if ( screenSurface->h > 0 )
        {
          v4 = screenSurface->w;
          v5 = 0;
          v6 = 4 * (screenSurface->pitch >> 2);
          do
          {
            v7 = v5 + *(_DWORD *)(v2 + 20); ///screenSurface->pixels
            for ( i = 0; i < v4; ++i )
            {
              *(_DWORD *)v7 = 0;
              v2 = screenSurface;
              v4 = screenSurface->w;
              v7 += 4;
            }
            ++v3;
            v5 += v6;
          }
          while ( v3 < screenSurface->h);
        }
      }
      screenPtr = screenPtr_456BF4;
      dword_456C14 = 19;
      //TODO fix
      SDL_WM_SetCaption("DreeRally RACE", 0);
      //result = SDL_WM_SetCaption("DreeRally", 0);
    }
    else
    {
      if ( a1 == 257 )
      {
        screenPtr = screenPtr_456BF4;
        dword_456C14 = 257;
      }
      //TODO fix
      SDL_WM_SetCaption("DreeRally RACE", 0);
      //result = SDL_WM_SetCaption("DreeRally", 0);
    }
  }
  return result;
}

//----- (0043BE60) --------------------------------------------------------
int setWindowCaption2()
{
  int result; // eax@1

  memset((void *)screenPtr_456BF4, 0, 0x4B000u);
  result = 257;
  if ( dword_456C14 != 257 )
  {
    screenPtr = screenPtr_456BF4;
    dword_456C14 = 257;
    //TODO fix
      SDL_WM_SetCaption("DreeRally", 0);
      //result = SDL_WM_SetCaption("DreeRally", 0);
  }
  return result;
}

//----- (0043BEB0) --------------------------------------------------------
int setWindowCaption()
{
  int result; // eax@1

  result = 0;
  memset((void *)screenPtr_456BF4, 0, 0x4B000u);
  if ( dword_456C14 != 3 )
    //TODO fix
      SDL_WM_SetCaption("DreeRally", 0);
      //result = SDL_WM_SetCaption("DreeRally", 0);
  return result;
}

//----- (0043BEE0) --------------------------------------------------------
int setRaceWindowCaption()
{
  return setWindowCaption3(19);
}

//----- (0043BEF0) --------------------------------------------------------
int  drawWeaponsBar_43BEF0(int a1, void *a2, unsigned int a3, int a4, char a5)
{
  int result; // eax@1
  void *v6; // ebp@2
  int v7; // eax@4

  result = a4;
  if ( a4 > 0 )
  {
    v6 = a2;
    do
    {
      if ( (signed int)a3 > 0 )
      {
        LOBYTE(a1) = a5;
        BYTE1(a1) = a5;
        v7 = a1 << 16;
        LOWORD(v7) = a1;
        memset(v6, v7, (a3 >> 2)*4);
        memset((char *)v6 + 4 * (a3 >> 2), a5, a3 & 3);
        v6 = (char *)v6 + a3;
      }
      result = 512 - a3;
      v6 = (char *)v6 + 512 - a3;
      --a4;
    }
    while ( a4 );
  }
  return result;
}

//----- (0043BF50) --------------------------------------------------------
//int   drawImageWithPosition2(int texture, int height, int width, int screenBufferPtr)

//----- (0043BF90) --------------------------------------------------------
//int   drawImageWithPosition(int icon, int width, int height, int pscreenBufferPos)

//----- (0043BFE0) --------------------------------------------------------
//devulve 15 si estas dentro del circuito y sino cero

int   sub_43BFE0(int a1, int a2)//a1 posicion de participant.bpk y a2 es el valor del circuito para la nueva absolute positionx e y 
{
  int v2; // eax@1
  int v3; // esi@1
  signed int v4; // edi@1
  signed int v5; // ecx@2

  v2 = a2;
  v3 = a1;
  v4 = 0;
  while ( 2 )
  {
    v5 = 0;
    do
    {
      if ( *(BYTE *)v3 > 3u && (*(BYTE *)v2 & 0xFu) < 4 )
      {
        dword_508D20 = v4;
        dword_4A7A40 = v5;
        return *(BYTE *)v2 & 0xF;
      }
      ++v3;
      ++v2;
      ++v5;
    }
    while ( v5 < 40 );
    ++v4;
    v2 = v2 + circuitWidth_464F40 - 40;
    if ( v4 < 40 )
      continue;
    break;
  }
  return 15;
}
// 464F40: using guessed type int circuitWidth_464F40;
// 4A7A40: using guessed type int dword_4A7A40;
// 508D20: using guessed type int dword_508D20;

//----- (0043C040) --------------------------------------------------------
int   setPaletteValue(int pos, int r, int g, int b)
{
  int result; // eax@2
SDL_Color* color ;
  if ( mainArgs.configGL )
  {
    result = 4 * (r | ((g | (b << 8)) << 8));
	/*SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	
	SDL_SetColors(screenSurface, &color, pos, 1);
	SDL_Palette *sdl_palette = screenSurface->format->palette;*/
    
	 palette[pos] = result;
  }
  else
  {
    result = pos;
    palette[pos] = 4* (b | ((g | (r << 8)) << 8)); //esta variable contiene paletas
	 color = (SDL_Color *)&palette[pos];
	/*SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	
	SDL_SetColors(screenSurface, &color, pos, 1);
	SDL_Palette *sdl_palette = screenSurface->format->palette;*/
	
  }
  return result;
}

//----- (0043C0A0) --------------------------------------------------------
int   setPaletteAndGetValue(unsigned __int8 pos, unsigned __int8 r, char g, unsigned __int8 b)
{
  unsigned __int16 v4; // ax@2
  int result; // eax@
  unsigned __int16 v6; // ax@3
  SDL_Color* color;

  if ( mainArgs.configGL )
  {
    HIBYTE(v4) = b;
    LOBYTE(v4) = g;
    result = 4 * (r | (v4 << 8));
	/*SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	
	SDL_SetColors(screenSurface, &color, pos, 1);
	SDL_Palette *sdl_palette = screenSurface->format->palette;*/
    palette[pos] = result;

  }
  else
  {
    
	result = 4* (r << 16 | g << 8 | b);
    
	/*SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
   
	SDL_SetColors(screenSurface, &color, pos, 1);
	SDL_Palette *sdl_palette = screenSurface->format->palette;*/
	
	palette[pos] = result;
	if (pos == 0) {
		int z = 0;
	}
	color = (SDL_Color *)&palette[pos];
	
  }
  return result;
}

//----- (0043C0F0) --------------------------------------------------------
int   regenerateRacePalette(int a1)
{
  int result; // eax@1
  signed int v2; // ecx@1
  int v3; // eax@2
  int v4; // eax@4
  int index = 0;
  result = a1;
  
  v2 = (signed int)palette;
  if ( mainArgs.configGL )
  {
    do
    {
      *(BYTE *)result = (*(_DWORD *)v2 >> 2) & 0x3F;
      v3 = result + 1;
      *(BYTE *)v3++ = (*(_DWORD *)v2 >> 10) & 0x3F;
      *(BYTE *)v3 = (*(_DWORD *)v2 >> 18) & 0x3F;
      v2 += 4;
      result = v3 + 1;
	  index += 3;
    }
    while ( index<768 );
	//while (v2 < (signed int)&configuration.useJoystick);
  }
  else
  {
	  index = 0;
    do
    {
      *(BYTE *)result = (*(_DWORD *)v2 >> 18) & 0x3F;
      v4 = result + 1;
      *(BYTE *)v4++ = (*(_DWORD *)v2 >> 10) & 0x3F;
      *(BYTE *)v4 = (*(_DWORD *)v2 >> 2) & 0x3F;
      v2 += 4;
      result = v4 + 1;
	  index += 3;
    }
	while (index<768);
    //while ( v2 < (signed int)&configuration.useJoystick );
  }
  return result;
}

//----- (0043C160) --------------------------------------------------------
int   generateSnapshotData_43C160(int a1)
{
  int result; // eax@1
  signed int v2; // ecx@1
  int v3; // eax@2
  int v4; // eax@4
  int v1=0;
  result = a1;
  
  v2 = palette;
  if ( mainArgs.configGL )
  {
    do
    {
      *(BYTE *)result = *(BYTE *)v2;
      v3 = result + 1;
      *(BYTE *)v3++ = *(_WORD *)v2 >> 8;
      *(BYTE *)v3 = *(BYTE *)(v2 + 2);
      v2 += 4;
	  v1++;
      result = v3 + 1;
    }
    while ( v1 < 256 );
	//while ( v2 < (signed int)&configuration.useJoystick );
  }
  else
  {
    do
    {
      *(BYTE *)result = *(BYTE *)(v2 + 2);
      v4 = result + 1;
      *(BYTE *)v4++ = *(_WORD *)v2 >> 8;
      *(BYTE *)v4 = *(BYTE *)v2;
      v2 += 4;
      result = v4 + 1;
	  v1++;
    }
    while ( v1 < 256 );
	//while ( v2 < (signed int)&configuration.useJoystick );
  }
  return result;
}

//----- (0043C1B0) --------------------------------------------------------
//int   sub_43C1B0(unsigned __int8 channelNumber, int a2, signed int a3)

//----- (0043C1F0) --------------------------------------------------------
//int sub_43C1F0()

//----- (0043C220) --------------------------------------------------------
//char __stdcall sub_43C220(int a1, int a2, signed int a3, int a4)//void streamcallback(FSOUND_STREAM *stream, void *buff, int len, int param) 

//----- (0043C250) --------------------------------------------------------
//int   musicSetVolume(signed int a1)

//----- (0043C280) --------------------------------------------------------
//int   musicSetmusicVolume(signed int a1)

//----- (0043C2B0) --------------------------------------------------------
//int   setMusicVolume(signed int a1)

//----- (0043C320) --------------------------------------------------------
//char   musicSetOrder(signed int a1)

//----- (0043C360) --------------------------------------------------------
//int musicPlayMusic()

//----- (0043C380) --------------------------------------------------------
//int   loadMenuSoundEffect(unsigned __int8 channelNumber, char soundNumber, int a3, int a4, int a5) 

//----- (0043C3C0) --------------------------------------------------------
//int stopSong()

//----- (0043C3E0) --------------------------------------------------------
//int   stopSoundChannel_43C3E0(unsigned __int8 a1)

//----- (0043C400) --------------------------------------------------------
//int stopAndOpenMusic()

//----- (0043C450) --------------------------------------------------------
int   sub_43C450(int a1)
{
  int result; // eax@1

  result = a1;
  *(_WORD *)a1 = 0;
  *(_WORD *)(a1 + 320) = 0;
  return result;
}

//----- (0043C470) --------------------------------------------------------
__int16   convert320to320_43C470(int a1, int a2)
{
  __int16 result; // ax@1

  *(_WORD *)a1 = *(_WORD *)a2;
  result = *(_WORD *)(a2 + 320);
  *(_WORD *)(a1 + 320) = result;
  return result;
}

//----- (0043C490) --------------------------------------------------------
__int16   conver512to320_43C490(int a1, int a2)
{
  __int16 result; // ax@1

  *(_WORD *)a1 = *(_WORD *)a2;
  result = *(_WORD *)(a2 + 512);
  *(_WORD *)(a1 + 320) = result;
  return result;
}

//----- (0043C4B0) --------------------------------------------------------
int sub_43C4B0()
{
  return 0;
}

//----- (0043C4D0) --------------------------------------------------------
//int freeMusic()

//----- (0043C4F0) ----
void   logJoystickClose()
{
  if ( sldJoystick_456C20 )
    SDL_JoystickClose(sldJoystick_456C20);
}
//----- (0043C51) ----
int  inicializeScreen(double a1)
{
  int v1; // esi@1
  SDL_VideoInfo * videoInfo; // eax@12
  double v3; // st7@12
  int v4; // eax@15
  int result; // eax@15
char * error;
  v1 = 0;
  if ( mainArgs.configWindow )
    v1 = 0;
  FSOUND_GetVersion();
  if ( a1 < 3.75 )
    exit(-1);
  if ( !mainArgs.configNoSound && (unsigned __int8)FSOUND_Init(44100, 64, 0) )
  {
	 #ifndef _NO_MINIFMOD
		if ( !mainArgs.configNoSound )
     

		  FSOUND_File_SetCallbacks_43F6B0(
			(int (  *)(_DWORD))FSOUND_File_OpenCallback_43AD80,
			(int (  *)(_DWORD))FSOUND_File_CloseCallback_43ADD0,
			(int (  *)(_DWORD, _DWORD, _DWORD))FSOUND_File_ReadCallback_43ADF0,
			(int (  *)(_DWORD))FSOUND_File_SeekCallback_43AE30,
			FSOUND_File_TellCallback_43AE70);
	  #endif
  }
  else
  {
    mainArgs.configNoSound = 1;
  }

  if ( SDL_Init(SDL_INIT_NOPARACHUTE | SDL_INIT_JOYSTICK | SDL_INIT_VIDEO))
    exit(-1);
  videoInfo = SDL_GetVideoInfo();
  screenWidth = videoInfo->current_w;
  screenHeight = videoInfo->current_h;
  v3 = (double)screenWidth / (double)screenHeight;
  screenColors = videoInfo->vfmt->BitsPerPixel; //ojo que esto tiene que ser 32
  
//  screenColors = *(BYTE *)(*(_DWORD *)(videoInfo->vfmt->BitsPerPixel + 8) + 4);
  if ( v3 <= 1.3333334 )
    y = v3 * 0.75;
  else
    x = 1.3333334 / v3;
  atexit(logJoystickClose);
  v4 = (int)malloc(0x96000u);
  screenPtr_456BF4 = v4;
  screenPtr = v4;
  SetVideoMode(v1);
  SDL_EnableUNICODE(1);
  result = SDL_EnableKeyRepeat(500, 30);
  if ( v1 )
  //TODO fix
    //result = SDL_Delay(2000);
    SDL_Delay(2);
  //cambiado porque no merece SDL_Delay(2000);
  return result;
}
signed int SDLCheckJoystick()
{
  signed int result; // eax@2
  char v1; // al@3
  SDL_Joystick *v2; // ST10_4@3
  char v3; // al@3
  SDL_Joystick *v4; // ST08_4@3
  char v5; // al@3
  SDL_Joystick *v6; // ST00_4@3

  if ( sldJoystick_456C20 )
  {
    SDL_JoystickUpdate();
    joystick_x_axis_4A7A44 = (signed __int16)SDL_JoystickGetAxis(sldJoystick_456C20, 0) / 256;
    joystick_y_axis_4A9EB8 = (signed __int16)SDL_JoystickGetAxis(sldJoystick_456C20, 1) / 256;
    v1 = SDL_JoystickGetButton(sldJoystick_456C20, 0);
    v2 = sldJoystick_456C20;
    byte_463E00[(unsigned __int8)configuration.defaultAccelerateGamepad] = v1;
    v3 = SDL_JoystickGetButton(v2, 1);
    v4 = sldJoystick_456C20;
    byte_463E00[(unsigned __int8)configuration.defaultTurboGamepad] = v3;
    v5 = SDL_JoystickGetButton(v4, 2);
    v6 = sldJoystick_456C20;
    byte_463E00[(unsigned __int8)configuration.defaultGunGamepad] = v5;
    byte_463E00[(unsigned __int8)configuration.defaultMineGamepad] = SDL_JoystickGetButton(v6, 3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0043C730) --------------------------------------------------------
void removeBackgroundRefreshFunction_43C730()
{
  dword_456C00 = 0;
}

//----- (0043C740) --------------------------------------------------------
signed __int64 recalculateSDLTicks_43C740()
{
  unsigned int v0; // ecx@1
  signed __int64 result; // rax@1

  v0 = SDL_GetTicks();
  result = 613566757 * v0;
  sdlTicks14 = v0 / 0xE;//sdlticks detects 15ms diference
  return result;
}

//----- (0043C760) --------------------------------------------------------
int refreshScreenWithDelay()
{
  int result; // eax@2

  if ( sdlTicks14 >= (signed int)(SDL_GetTicks() / 0xEu) )
  {
    refreshScreen(sdlTicks14);
    result = sdlTicks14;
  }
  else
  {
    result = sdlTicks14++ + 1;
    if ( dword_456C00 )
    {
      dword_456C00();
      result = sdlTicks14;
    }
  }
  return result;
}

//----- (0043C7B0) --------------------------------------------------------
int (*  setBackgroundRefreshFunction_43C7B0(int (*a1)(void)))(void)
{
  int (*result)(void); // eax@1

  result = a1;
  dword_456C00 = a1;
  return result;
}

//----- (0043C7C0) --------------------------------------------------------
int   updateScreenPtr(int a1)
{
  int result; // eax@1

  result = screenPtr_456BF4 + (a1 << 16);
  screenPtr = screenPtr_456BF4 + (a1 << 16);
  return result;
}

//----- (0043C7E0) --------------------------------------------------------
int   sub_43C7E0(int a1, int a2, int a3, signed int a4, char a5)
{
  __int64 v5; // rax@1
  int v6; // edi@2
  int v7; // ecx@3
  signed int v8; // esi@3
  signed int v10; // [sp+10h] [bp+Ch]@2

  v5 = (unsigned int)(((a3 - a2) << 8) / a4);
  if ( a4 > 0 )
  {
    v6 = 0;
    v10 = a4;
    do
    {
      HIDWORD(v5) += v5;
      v7 = a1 + v6 + (SHIDWORD(v5) >> 8);
      v8 = 2;
      do
      {
        if ( *(BYTE *)v7 >= 0x40u )
          *(BYTE *)v7 = a5;
        ++v7;
        --v8;
      }
      while ( v8 );
      v6 += 512;
      --v10;
    }
    while ( v10 );
  }
  return v5;
}

//----- (0043C850) --------------------------------------------------------
int refreshOrExecuteBackgroundFunction_43C850()
{
  int v0; // esi@5
  int result; // eax@7

  if ( sdlTicks14 >= (signed int)(SDL_GetTicks() / 0xEu) )//entre 15 porque 15ms es el tiempo minimo que detecta sdl
  {
    refreshScreen(sdlTicks14);
  }
  else
  {
    ++sdlTicks14;
    if ( dword_456C00 )
      dword_456C00();
  }
  v0 = sdlTicks14;
  while ( 1 )
  {
    if ( sdlTicks14 >= (signed int)(SDL_GetTicks() / 0xEu) )
    {
      result = refreshScreen(sdlTicks14);
    }
    else
    {
      ++sdlTicks14;
      result = (int)dword_456C00;
      if ( dword_456C00 )
        result = dword_456C00();
    }
    if ( v0 != sdlTicks14 )
      break;
    SDL_Delay(1);
  }
  return result;
}

//----- (0043C900) --------------------------------------------------------
SDL_Joystick * SDLConfigureJoystick()
{
  int v0; // esi@3
  SDL_Joystick * result; // eax@8

  if ( sldJoystick_456C20 )
    goto LABEL_13;
  if ( SDL_NumJoysticks() > 0 )
  {
    v0 = 0;
    while ( !sldJoystick_456C20 || v0 >= SDL_NumJoysticks() )
    {
      sldJoystick_456C20 = SDL_JoystickOpen(v0);
      if ( SDL_JoystickNumAxes(sldJoystick_456C20) < 2 )
      {
        SDL_JoystickClose(sldJoystick_456C20);
        sldJoystick_456C20 = 0;
        ++v0;
      }
    }
  }
  result = sldJoystick_456C20;
  if ( sldJoystick_456C20 )
LABEL_13:
    result = SDLCheckJoystick();
  else
    configuration.useJoystick = 0;
  return result;
}

//----- (0043C980) --------------------------------------------------------//
void   decryptTexture(int src,  int dest, int startPos, int lenght)
{
  int v4; // ebx@1
  signed int v5; // ebp@1
  void *v6 ; // esi@1
  signed int v7; // edi@1
  int v8; // eax@2
  int i; // eax@4
  bool v10; // zf@10
  signed int v11; // ecx@12
  signed int v12; // eax@21
  int v13; // [sp+10h] [bp-1Ch]@1
  signed int v14; // [sp+14h] [bp-18h]@1
  int imageDestposition; // [sp+18h] [bp-14h]@1
  void *Memory= malloc(0x1001u); // [sp+1Ch] [bp-10h]@1
  char v17; // [sp+20h] [bp-Ch]@1
  void *v18= malloc(0x1001u); // [sp+24h] [bp-8h]@1
  void *v19 = malloc(0x4004u); // [sp+28h] [bp-4h]@1
  
  v4 = 0;
  imageDestposition = 0;
  v5 = 0;
 
  v6 = Memory;

  v13 = 9;
  v14 = 512;
  v7 = 258;
  v17 = 0;
  if (lenght)
  {
    while ( 1 )
    {
      v8 = extractBits(src, v5, v13);
      v5 += v13;
      if ( v8 == 256 )
        goto LABEL_28;
      if ( v8 != 257 )
        break;
      v13 = 9;
      v7 = 258;
      v14 = 512;
      for ( i = extractBits(src, v5, 9); i == 257; i = extractBits(src, v5, 9) )
        v5 += 9;
      v5 += 9;
      if ( i == 256 )
        goto LABEL_28;
      if ( i >= 258 )
        i = 0;
      v17 = i;
      v4 = i;
      if (startPos)
      {
        --startPos;
LABEL_26:
        v10 = lenght == 0;
        goto LABEL_27;
      }
	  *(BYTE *)(imageDestposition++ + dest) = (32* i | (i >> 3)) ;
      v10 = lenght-- == 1;
LABEL_27:
      if ( v10 )
        goto LABEL_28;
    }
    v11 = v8;
    if ( v8 >= v7 )
    {
      *(BYTE *)v6 = v17;
      v11 = v4;
      v6 = (char *)v6 + 1;
    }
    for ( ; v11 >= 258; v6 = (char *)v6 + 1 )
    {
      *(BYTE *)v6 = *((BYTE *)v18 + v11);
      v11 = *((int *)v19 + v11);
    }
    *(BYTE *)v6 = v11;
    v6 = (char *)v6 + 1;
    if ( v7 >= v14 || (*((BYTE *)v18 + v7) = v11, v17 = v11, *((int *)v19 + v7) = v4, v4 = v8, ++v7, v7 >= v14) )
    {
      if ( v13 < 12 )
      {
        v14 *= 2;
        ++v13;
      }
    }
    while ( v6 > Memory )
    {
      v12 = *((char *)v6 - 1);
      v6 = (char *)v6 - 1;
      if (startPos)
      {
        --startPos;
      }
      else
      {
        *(BYTE *)(imageDestposition++ + dest) = (32*(BYTE)v12 | ((BYTE)v12 >> 3));
        --lenght;
        if ( !lenght)
          goto LABEL_28;
      }
    }
    goto LABEL_26;
  }
LABEL_28:
  ;
 // free(Memory);
 // free(v18);
 // free(v19);
}

//----- (0043CB90) --------------------------------------------------------
void   copyImageToBuffer(int a1, int a2)
{

 decryptTexture(a1, a2, 0, 0x40000000);
}

//----- (0043CBB0) --------------------------------------------------------
unsigned int waitTwoSeconsAndExecFunc_43CBB0()
{
  int v0; // esi@1
  unsigned int result; // eax@1

  v0 = SDL_GetTicks() + 2000;
  for ( result = SDL_GetTicks(); v0 > result; result = SDL_GetTicks() )
  {
    refreshOrExecuteBackgroundFunction_43C850();
    SDL_Delay(1);
  }
  return result;
}

//----- (0043CBF0) --------------------------------------------------------
//void   loadMusic(int a1, char * music1, int a3, char* soundEffect)

//----- (0043CD50) --------------------------------------------------------
int   setTriangleValue_43CD50(int pos1x, int pos1y, int pos2x, int pos2y, int pos3x, int pos3y, char value)
{
  int v7; // ecx@1
  signed int v8; // ecx@2
  int v9; // edx@4
  signed int v10; // edx@5
  signed int v11; // esi@7
  signed int v12; // edi@7
  int result; // eax@7
  signed int v14; // ebx@8
  int v15; // edx@8
  int v16; // eax@8
  int v17; // eax@8
  double v18; // st7@8
  int v19; // ebx@8
  int v20; // ecx@8
  double v21; // st7@12
  signed int v22; // edi@14
  unsigned __int64 v23; // rax@14
  signed int v24; // ecx@18
  double v25; // st7@29
  signed int v26; // edi@31
  unsigned __int64 v27; // rax@31
  signed int i; // ecx@35
  float v29; // [sp+18h] [bp-40h]@9
  float v30; // [sp+1Ch] [bp-3Ch]@9
  float v31; // [sp+20h] [bp-38h]@8
  float v32; // [sp+20h] [bp-38h]@26
  int v33; // [sp+24h] [bp-34h]@7
  float v34; // [sp+28h] [bp-30h]@12
  signed int v35; // [sp+2Ch] [bp-2Ch]@8
  int v36; // [sp+30h] [bp-28h]@8
  float v37; // [sp+30h] [bp-28h]@29
  float v38; // [sp+34h] [bp-24h]@8
  int v39; // [sp+38h] [bp-20h]@8
  int v40; // [sp+3Ch] [bp-1Ch]@9
  int v41; // [sp+40h] [bp-18h]@1
  int v42; // [sp+44h] [bp-14h]@1
  int v43; // [sp+48h] [bp-10h]@1
  int v44; // [sp+4Ch] [bp-Ch]@1
  int v45; // [sp+50h] [bp-8h]@1
  int v46; // [sp+54h] [bp-4h]@1
  int positions[6];
  positions[0]=pos1x;
  positions[1]=pos1y;
  positions[2]=pos2x;
  positions[3]=pos2y;
  positions[4]=pos3x;
  positions[5]=pos3y;
  //v41 = a1;
  //v43 = a3;
  v7 = 0;
  //v42 = a2;
  //v44 = a4;
  //v45 = a5;
  //v46 = a6;
  if ( pos1y >= pos2y )
  {
    LOBYTE(v7) = pos2y >= pos3y;
    v8 = 2 * v7 + 2;
  }
  else
  {
    v8 = pos1y < pos3y ? 0 : 4;
  }
  v9 = 0;
  if ( pos1y <= pos2y )
  {
    LOBYTE(v9) = pos2y <= pos3y;
    v10 = 2 * v9 + 2;
  }
  else
  {
    v10 = pos1y > pos3y ? 0 : 4;
  }
  v11 = positions[1+v8];
  //v11 = *(&v42 + v8);
  v12 = v10;
  result = 6 - v10 - v8;
  v33 = positions[1+v10];
  //v33 = *(&v42 + v10);
  if ( v33 == v11 )
    return result;
  v14 = positions[0+result];
  //v14 = *(&v41 + result);
  v15 = positions[0+v8];
  //v15 = &v41 + v8;
  v35 = v14;
  v16 = positions[1+result];
  //v16 = &v42 + result;
  v36 = v16;
  v17 = v16;
  v18 = (double)(v14 - v15) / (double)(v17 - v11);
  v19 = positions[0+ v12];
  
  //v18 = (double)(v14 - *v15) / (double)(v17 - v11);
  //v19 = *(&v41 + v12);
  v20 = v33;
  v39 = positions[0+v12];
  //v39 = *(&v41 + v12);
  v31 = v18;
  v38 = (double)(positions[0+ v12] - v15) / (double)(v33 - v11);
 // v38 = (double)(*(&v41 + v12) - *v15) / (double)(v33 - v11);
 
  if ( v17 == v11 )
  {
    v30 = (double)v35;
    v29 = (double)v15;
LABEL_26:
    result = v20 - v36;
    v32 = (double)(v19 - v35) / (double)(v20 - v36);
    if ( v11 < v20 )
    {
      do
      {
        if ( v11 > 0 && v11 < 200 )
        {
          v25 = v30;
          v37 = v29;
          if ( v30 > (double)v29 )
          {
            v25 = v29;
            v37 = v30;
          }
          v26 = (unsigned __int64)floor(v25 + 0.40000001);
          v27 = (unsigned __int64)floor(v37 + 0.60000002);
          if ( v26 < 0 )
            v26 = 0;
          if ( (signed int)v27 > 512 )
            LODWORD(v27) = 512;
          for ( i = v26; i < (signed int)v27; ++i )
            *(BYTE *)((v11 << 9) + dword_464F14 + i + 96) = value;
        }
        result = v33;
        ++v11;
        v30 = v30 + v32;
        v29 = v29 + v38;
      }
      while ( v11 < v33 );
    }
    return result;
  }
  v29 = (double)v15;
  v30 = v29;
  result = v36;
  v40 = v36;
  if ( v11 < v36 )
  {
    do
    {
      if ( v11 > 0 && v11 < 200 )
      {
        v21 = v30;
        v34 = v29;
        if ( v30 > (double)v29 )
        {
          v21 = v29;
          v34 = v30;
        }
        v22 = (unsigned __int64)floor(v21 + 0.40000001);
        v23 = (unsigned __int64)floor(v34 + 0.60000002);
        if ( v22 < 0 )
          v22 = 0;
        if ( (signed int)v23 > 512 )
          LODWORD(v23) = 512;
        v24 = v22;
        if ( v22 < (signed int)v23 )
        {
          do
            *(BYTE *)((v11 << 9) + dword_464F14 + v24++ + 96) =value;
          while ( v24 < (signed int)v23 );
          v19 = v39;
        }
      }
      result = v40;
      ++v11;
      v30 = v30 + v31;
      v29 = v29 + v38;
    }
    while ( v11 < v40 );
    v20 = v33;
  }
  if ( result != v20 )
    goto LABEL_26;
  return result;
}
// 464F14: using guessed type int dword_464F14;

//----- (0043D050) --------------------------------------------------------
int   sub_43D050(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // edx@1
  signed int v10; // edx@2
  int v11; // ecx@4
  signed int v12; // ecx@5
  int result; // eax@7
  int v14; // esi@8
  int *v15; // edi@8
  int v16; // edi@8
  int *v17; // edx@8
  double v18; // st7@8
  int v19; // edx@8
  double v20; // st6@8
  int v21; // ebx@8
  int *v22; // edx@8
  double v23; // st6@8
  double v24; // st5@8
  signed int v25; // ebx@8
  int v26; // ST14_4@8
  int v27; // ebx@8
  signed int v28; // ecx@10
  double v29; // st7@14
  signed int v30; // edi@16
  unsigned __int64 v31; // rax@16
  double v32; // st7@16
  int v33; // edi@21
  unsigned __int64 v34; // rax@22
  bool v35; // zf@24
  double v36; // st7@28
  signed int v37; // ebx@29
  double v38; // st7@33
  signed int v39; // esi@35
  unsigned __int64 v40; // rax@35
  double v41; // st7@35
  int v42; // edi@40
  int v43; // esi@40
  unsigned __int64 v44; // rax@41
  float v45; // [sp+14h] [bp-84h]@8
  float v46; // [sp+18h] [bp-80h]@9
  float v47; // [sp+1Ch] [bp-7Ch]@9
  float v48; // [sp+20h] [bp-78h]@9
  float v49; // [sp+24h] [bp-74h]@9
  int *v50; // [sp+28h] [bp-70h]@8
  int v51; // [sp+28h] [bp-70h]@10
  int v52; // [sp+28h] [bp-70h]@29
  signed int v53; // [sp+2Ch] [bp-6Ch]@8
  float v54; // [sp+2Ch] [bp-6Ch]@33
  int v55; // [sp+30h] [bp-68h]@7
  float v56; // [sp+30h] [bp-68h]@35
  int v57; // [sp+34h] [bp-64h]@8
  float v58; // [sp+34h] [bp-64h]@33
  int *v59; // [sp+38h] [bp-60h]@7
  float v60; // [sp+38h] [bp-60h]@33
  int v61; // [sp+3Ch] [bp-5Ch]@21
  signed int v62; // [sp+40h] [bp-58h]@10
  float v63; // [sp+44h] [bp-54h]@8
  float v64; // [sp+44h] [bp-54h]@28
  float v65; // [sp+48h] [bp-50h]@8
  float v66; // [sp+48h] [bp-50h]@28
  int *v67; // [sp+4Ch] [bp-4Ch]@8
  signed int v68; // [sp+50h] [bp-48h]@8
  float v69; // [sp+54h] [bp-44h]@14
  float v70; // [sp+58h] [bp-40h]@8
  float v71; // [sp+5Ch] [bp-3Ch]@14
  float v72; // [sp+60h] [bp-38h]@16
  float v73; // [sp+64h] [bp-34h]@14
  int v74; // [sp+68h] [bp-30h]@1
  int v75; // [sp+6Ch] [bp-2Ch]@1
  int v76; // [sp+70h] [bp-28h]@1
  int v77; // [sp+74h] [bp-24h]@1
  int v78; // [sp+78h] [bp-20h]@1
  int v79; // [sp+7Ch] [bp-1Ch]@1
  int v80; // [sp+80h] [bp-18h]@1
  int v81; // [sp+84h] [bp-14h]@1
  int v82; // [sp+88h] [bp-10h]@1
  int v83; // [sp+8Ch] [bp-Ch]@4

  v74 = a1;
  v77 = a4;
  v76 = a3;
  v79 = a6;
  v82 = a9;
  v9 = 0;
  v75 = a2;
  v78 = a5;
  v80 = a7;
  v81 = a8;
  if ( a2 >= a5 )
  {
    LOBYTE(v9) = a5 >= a8;
    v10 = ((v9 - 1) & 0xFFFFFFFD) + 6;
  }
  else
  {
    v10 = a2 < a8 ? 0 : 6;
  }
  v11 = 0;
  v83 = v10;
  if ( a2 <= a5 )
  {
    LOBYTE(v11) = a5 <= a8;
    v12 = ((v11 - 1) & 0xFFFFFFFD) + 6;
  }
  else
  {
    v12 = a2 > a8 ? 0 : 6;
  }
  v59 = &v75 + v12;
  result = 9 - v12 - v10;
  v55 = *v59;
  if ( *v59 == *(&v75 + v10) )
    return result;
  v14 = *(&v75 + v10);
  v68 = *(&v74 + result);
  v15 = &v75 + result;
  v67 = v15;
  v16 = *v15;
  v17 = &v74 + v10;
  v18 = (double)(v16 - v14);
  v50 = v17;
  v19 = *v17;
  v57 = *(&v74 + v12);
  v20 = (double)(v68 - v19) / v18;
  v21 = v57 - v19;
  v22 = &v76 + v83;
  v63 = v20;
  v23 = (double)(*v59 - v14);
  v24 = (double)v21;
  v25 = *(&v76 + result);
  v53 = v25;
  v26 = v25 - *v22;
  v27 = *(&v76 + v12);
  v70 = v24 / v23;
  v65 = (double)v26 / v18;
  v45 = (double)(*(&v76 + v12) - *v22) / v23;
  if ( v16 == v14 )
  {
    v47 = (double)v68;
    result = *v59;
    v46 = (double)*v50;
    v49 = (double)v53;
    v48 = (double)*v22;
LABEL_28:
    v36 = (double)(*v59 - *v67);
    v64 = (double)(v57 - v68) / v36;
    v66 = (double)(v27 - v53) / v36;
    if ( v14 < result )
    {
      v37 = v14 << 9;
      v52 = result - v14;
      do
      {
        if ( v37 > 0 && v37 < 102400 && v47 != v46 )
        {
          v38 = v47;
          v60 = v48;
          v58 = v49;
          v54 = v46;
          if ( v47 > (double)v46 )
          {
            v38 = v46;
            v54 = v47;
            v58 = v48;
            v60 = v49;
          }
          v39 = (unsigned __int64)floor(v38 + 0.40000001);
          v40 = (unsigned __int64)floor(v54 + 0.60000002);
          v41 = v58;
          v56 = (v60 - v58) / (double)((signed int)v40 - v39);
          if ( v39 < 0 )
          {
            v39 = 0;
            v41 = v41 - v56 * 0.0;
          }
          if ( (signed int)v40 > 512 )
            LODWORD(v40) = 512;
          if ( v39 < (signed int)v40 )
          {
            v42 = v37 + v39;
            v43 = v40 - v39;
            do
            {
              v44 = (unsigned __int64)v41;
              v41 = v41 + v56;
              *(BYTE *)(v42++ + dword_464F14 + 96) = v44;
              --v43;
            }
            while ( v43 );
          }
        }
        v37 += 512;
        result = v52 - 1;
        v35 = v52-- == 1;
        v47 = v47 + v64;
        v46 = v46 + v70;
        v49 = v49 + v66;
        v48 = v48 + v45;
      }
      while ( !v35 );
    }
    return result;
  }
  v46 = (double)*v50;
  v47 = v46;
  v48 = (double)*v22;
  v49 = v48;
  if ( v14 < *v67 )
  {
    v28 = v14 << 9;
    v62 = v14 << 9;
    v51 = *v67 - v14;
    v14 = *v67;
    do
    {
      if ( v28 > 0 && v28 < 102400 && v47 != v46 )
      {
        v29 = v47;
        v73 = v46;
        v71 = v49;
        v69 = v48;
        if ( v47 > (double)v46 )
        {
          v29 = v46;
          v73 = v47;
          v71 = v48;
          v69 = v49;
        }
        v30 = (unsigned __int64)floor(v29 + 0.40000001);
        v31 = (unsigned __int64)floor(v73 + 0.60000002);
        v32 = v71;
        v72 = (v69 - v71) / (double)((signed int)v31 - v30);
        if ( v30 < 0 )
        {
          v30 = 0;
          v32 = v32 - v72 * 0.0;
        }
        if ( (signed int)v31 > 512 )
          LODWORD(v31) = 512;
        if ( v30 < (signed int)v31 )
        {
          v61 = v30 + v62;
          v33 = v31 - v30;
          do
          {
            v34 = (unsigned __int64)v32;
            v32 = v32 + v72;
            *(BYTE *)(v61 + dword_464F14 + 96) = v34;
            --v33;
            ++v61;
          }
          while ( v33 );
        }
        v28 = v62;
      }
      v28 += 512;
      v35 = v51 == 1;
      v62 = v28;
      v47 = v47 + v63;
      --v51;
      v46 = v46 + v70;
      v49 = v49 + v65;
      v48 = v48 + v45;
    }
    while ( !v35 );
  }
  result = v55;
  if ( *v67 != v55 )
    goto LABEL_28;
  return result;
}
// 464F14: using guessed type int dword_464F14;

//----- (0043D530) --------------------------------------------------------
int   iluminateTriangle_43D530(int pos1x, int pos1y, int pos2x, int pos2y, int pos3x, int pos3y, int a7)
{
  int v7; // ecx@1
  signed int v8; // ecx@2
  int v9; // edx@4
  signed int v10; // edx@5
  signed int v11; // esi@7
  signed int v12; // edi@7
  int result; // eax@7
  signed int v14; // ebx@8
  //int *v15; // edx@8
  //int *v16; // eax@8
  int v15; // edx@8
  int v16; // eax@8
  
  int v17; // eax@8
  double v18; // st7@8
  int v19; // ebx@8
  int v20; // ecx@8
  double v21; // st7@12
  signed int v22; // ST1C_4@14
  unsigned __int64 v23; // rax@14
  signed int v24; // ecx@14
  signed int v25; // edi@14
  signed int j; // eax@19
  int v27; // edx@21
  double v28; // st7@31
  signed int v29; // ebx@33
  unsigned __int64 v30; // rax@33
  signed int v31; // edi@33
  signed int v32; // ecx@37
  signed int i; // eax@38
  int v34; // edx@40
  float v35; // [sp+14h] [bp-44h]@9
  float v36; // [sp+18h] [bp-40h]@9
  float v37; // [sp+20h] [bp-38h]@8
  float v38; // [sp+20h] [bp-38h]@28
  int v39; // [sp+24h] [bp-34h]@7
  float v40; // [sp+28h] [bp-30h]@12
  signed int v41; // [sp+2Ch] [bp-2Ch]@8
  int v42; // [sp+30h] [bp-28h]@8
  float v43; // [sp+30h] [bp-28h]@31
  float v44; // [sp+34h] [bp-24h]@8
  int v45; // [sp+38h] [bp-20h]@8
  int v46; // [sp+3Ch] [bp-1Ch]@9
  int v47; // [sp+40h] [bp-18h]@1
  int v48; // [sp+44h] [bp-14h]@1
  int v49; // [sp+48h] [bp-10h]@1
  int v50; // [sp+4Ch] [bp-Ch]@1
  int v51; // [sp+50h] [bp-8h]@1
  int v52; // [sp+54h] [bp-4h]@1
  int positions[6];

   v7 = 0;
  
  positions[0]=pos1x;
  positions[1]=pos1y;
  positions[2]=pos2x; 
  positions[3]=pos2y;
  positions[4]=pos3x;
  positions[5]=pos3y;
 
/*  v47 = pos1x;
  v49 = pos2x;
 
  v48 = pos1y;
  v50 = pos2y;
  v51 = pos3x;
  v52 = pos3y;
  */
  if ( pos1y >= pos2y )
  {
    LOBYTE(v7) = pos2y >= pos3y;
    v8 = 2 * v7 + 2;
  }
  else
  {
    v8 = pos1y < pos3y ? 0 : 4;
  }
  v9 = 0;
  if ( pos1y <= pos2y )
  {
    LOBYTE(v9) = pos2y <= pos3y;
    v10 = 2 * v9 + 2;
  }
  else
  {
    v10 = pos2y > pos3y ? 0 : 4;
  }
  v11= positions[1+v8];
  //v11 = *(&v48 + v8);
  v12 = v10;
  result = 6 - v10 - v8;
  v39= positions[1+v10];
  //v39 = *(&v48 + v10);
  if ( v39 == v11 )
    return result;
   v14= positions[0+result];
  //v14 = *(&v47 + result);
  //v15 = &v47 + v8;
  v15= positions[0+v8];
  v41 = v14;
  //v16 = &v48 + result;
  v16= positions[1+result];
 v42 = (int)v16;
  //v17 = *v16;
  v17 = v16;
 // v18 = (double)(v14 - *v15) / (double)(v17 - v11);
  
  v18 = (double)(v14 - v15) / (double)(v17 - v11);
  v19= positions[0+v12];
  //v19 = *(&v47 + v12);
  v20 = v39;
  v45= positions[0+v12];
  //v45 = *(&v47 + v12);
  v37 = v18;
 // v44 = (double)(*(&v47 + v12) - *v15) / (double)(v39 - v11);
  v44 = (double)(positions[0+v12] - v15) / (double)(v39 - v11);
 
  if ( v17 == v11 )
  {
    v36 = (double)v41;
    //v35 = (double)*v15;
	v35 = (double)v15;
LABEL_28:
    result = v42;
    //v38 = (double)(v19 - v41) / (double)(v20 - *(_DWORD *)v42);
	v38 = (double)(v19 - v41) / (double)(v20 - v42);
    if ( v11 < v20 )
    {
      do
      {
        if ( v11 > 0 && v11 < 200 )
        {
          v28 = v36;
          v43 = v35;
          if ( v36 > (double)v35 )
          {
            v28 = v35;
            v43 = v36;
          }
          v29 = (unsigned __int64)floor(v28 + 0.40000001);
          v30 = (unsigned __int64)floor(v43 + 0.60000002);
          v31 = v30;
          if ( v29 < 0 )
            v29 = 0;
          if ( (signed int)v30 > 512 )  //ancho de pantalla
            v31 = 512;
          v32 = v29;
          if ( v29 < v31 )
          {
            for ( i = v11 << 9; ; i = v11 << 9 )
            {
              v34 = dword_464F14 + i + v32++ + 96;
              *(BYTE *)v34 = *(BYTE *)(*(BYTE *)v34 + a7);
              if ( v32 >= v31 )
                break;
            }
          }
        }
        result = v39;
        ++v11;
        v36 = v36 + v38;
        v35 = v35 + v44;
      }
      while ( v11 < v39 );
    }
    return result;
  }
  //v35 = (double)*v15;
    v35 = (double)v15;
  v36 = v35;
  //result = *(_DWORD *)v42;
   result = v42;
 // v46 = *(_DWORD *)v42;
  v46 = v42;
  
  //if ( v11 < *(_DWORD *)v42 )
  if ( v11 < v42 )
  
  {
    do
    {
      if ( v11 > 0 && v11 < 200 )
      {
        v21 = v36;
        v40 = v35;
        if ( v36 > (double)v35 )
        {
          v21 = v35;
          v40 = v36;
        }
        v22 = (unsigned __int64)floor(v21 + 0.40000001);
        v23 = (unsigned __int64)floor(v40 + 0.60000002);
        v24 = v22;
        v25 = v23;
        if ( v22 < 0 )
          v24 = 0;
        if ( (signed int)v23 > 512 )
          v25 = 512;
        if ( v24 < v25 )
        {
          for ( j = v11 << 9; ; j = v11 << 9 )
          {
            v27 = dword_464F14 + j + v24++ + 96;
            *(BYTE *)v27 = *(BYTE *)(*(BYTE *)v27 + a7);
            if ( v24 >= v25 )
              break;
          }
          v19 = v45;
        }
      }
      result = v46;
      ++v11;
      v36 = v36 + v37;
      v35 = v35 + v44;
    }
    while ( v11 < v46 );
    v20 = v39;
  }
  if ( result != v20 )
    goto LABEL_28;
  return result;
}
// 464F14: using guessed type int dword_464F14;

//----- (0043D870) --------------------------------------------------------
int waitWithRefresh()
{
  int v0; // esi@1
  int result; // eax@1

  v0 = refreshScreenWithDelay();
  for ( result = refreshScreenWithDelay(); v0 == result; result = refreshScreenWithDelay() )
    SDL_Delay(1);
  return result;
}

//----- (0043AE80) --------------------------------------------------------
int   sub_43AE80(int a1, int a2, int a3, int a4)//a1 puntero a pantalla, a2 posicion de la imagen ,a3 4 a4 204
{
  int v4; // ecx@1
  int result; // eax@1

  *(_DWORD *)a1 = *(_DWORD *)a2;
  *(_DWORD *)(a1 + a3) = *(_DWORD *)(a4 + a2);
  v4 = a3 + a3 + a1;
  *(_DWORD *)v4 = *(_DWORD *)(a4 + a2 + a4);
  result = *(_DWORD *)(a4 + a4 + a2 + a4);
  *(_DWORD *)(v4 + a3) = result;
  return result;
}

//----- (0043FC72) --------------------------------------------------------
void sub_43FC72()
{
  unsigned int i; // [sp+Ch] [bp-1Ch]@1

  for ( i = (unsigned int)&unk_444540; i < (unsigned int)&unk_444540; i += 4 )
  {
    if ( *(_DWORD *)i )
      (*(void (**)(void))i)();
  }
}

//----- (0043FC72) --------------------------------------------------------

//----- (0043FCB6) --------------------------------------------------------
void   sub_43FCB6()
{
  unsigned int i; // [sp+Ch] [bp-1Ch]@1

  for ( i = (unsigned int)&unk_444548; i < (unsigned int)&unk_444548; i += 4 )
  {
    if ( *(_DWORD *)i )
      (*(void (**)(void))i)();
  }
}

//----- (0043FD12) --------------------------------------------------------
int sub_43FD12()
{
  return 0;
}

//----- (0043FD70) --------------------------------------------------------
int  initSystem(double fmodMinVersion, int a1, char **a2, char *args)
{
  const char *v3; // esi@1
  char *v4; // eax@1
  char *v5; // eax@4
  int v6; // eax@5
  int v7; // edi@7
//  int v8; // eax@7
//  void *v9; // esp@7
  int result; // eax@8
  char* sdlError; // eax@10
#ifndef PORTABILITY
  HMODULE v12; // eax@11
#endif
  int v13; // eax@12
  int v14; // [sp+0h] [bp-Ch]@7

  v3 = *a2;
  if(*a2==NULL)
	  *a2=malloc(sizeof(char*));
  v4 = strrchr(*a2, 92);
  if ( v4 || (v4 = strrchr(*a2, 47)) != 0 )
    v3 = v4 + 1;
  if(v3==NULL)
	  v3=malloc(sizeof(char*));
  v5 = strrchr(v3, 46);
  if ( v5 )
    v6 = v5 - v3;
  else
    v6 = strlen(v3);
  v7 = v6 + 1;
 
  if ( &v14 )
  {
    SDL_strlcpy(&v14, v3, v7);
    if ( SDL_Init(SDL_INIT_NOPARACHUTE) >= 0 )
    {
      atexit(generateExitError);
      atexit(SDL_Quit);
	  #ifndef PORTABILITY
      v12 = GetModuleHandleA(0);
      SDL_SetModuleHandle(v12);
		#endif
    
	  v13 = sub_43ACE0(fmodMinVersion, a1, (int)a2, args);
      exit(v13);
    }
    sdlError = SDL_GetError();
    logError((int)aWinmainError, sdlError);
    result = 0;
  }
  else
  {
    result = outOfMemoryError();
  }
  return result;
}

int   logError(int a1, int a2)
{
  return fprintf((FILE *)&iob[0] + 2, aSS, a1, a2);
  //return fprintf((FILE *)iob[0]._ptr + 2, aSS, a1, a2);
}

int outOfMemoryError()
{
  logError((int)aFatalError, (int)aOutOfMemoryAbo);
  return 0;
}
// 43FE80: using guessed type int outOfMemoryError(void);

void   generateExitError()
{
 // fclose((FILE *)&iob[0] + 1);
  //fclose((FILE *)&iob[0] + 2);
}

#ifdef PORTABILITY

int main( int argc, char* argv[] ){
	 double fmodMinVersion=3.75; // st7@0
  unsigned int argLenght; // kr04_4@3
  int v8; // eax@3
  char *arg; // ebx@3
  int result; // eax@4
  int v11; // eax@5
  int v12; // ebx@5
//  int v13; // eax@5
//  void *v14; // esp@5
  int v15; // [sp+0h] [bp-Ch]@3

  char* toPrint;
  int i;
  arg = getcwd(0,0);
//TODO calculate corretly the command line args
  //for (i = 0; i < argc; i++)
   // strcat (arg, argv[i]);
  argLenght = strlen(argv) + 1;
  v8 = argLenght - 1 + 4;
  
  if ( &v15 )
  {
    SDL_strlcpy(&v15, &arg, argLenght);
    //v11 = sub_43FF90(&v15, 0);
	v11=1;
	v12 = v11;
   
    if ( &v15 )
    {
     // sub_43FF90(&v15, (int)&v15);
      initSystem(fmodMinVersion, v12, (const char **)&v15, arg);
      result = 0;
    }
    else
    {
      result = outOfMemoryError();
    }
  }  else
  {
    result = outOfMemoryError();
  }
  return result;
}
#endif
#ifndef PORTABILITY
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  double fmodMinVersion=3.75; // st7@0
  HMODULE ddrawModule; // eax@1
  const char *arg; // ebx@3
  unsigned int argLenght; // kr04_4@3
  int v8; // eax@3
  
  int result; // eax@4
  int v11; // eax@5
  int v12; // ebx@5
//  int v13; // eax@5
//  void *v14; // esp@5
  int v15; // [sp+0h] [bp-Ch]@3

  ddrawModule = LoadLibraryA(LibFileName);
  if (ddrawModule)
    FreeLibrary(ddrawModule);
  arg = GetCommandLineA();
  argLenght = strlen(arg) + 1;
  v8 = argLenght - 1 + 4;
  
  if ( &v15 )
  {
    SDL_strlcpy(&v15, &arg, argLenght);
    v11 = sub_43FF90(&v15, 0);
	v12 = v11;
   
    if ( &v15 )
    {
      sub_43FF90(&v15, (int)&v15);
      initSystem(fmodMinVersion, v12, (const char **)&v15, arg);
      result = 0;
    }
    else
    {
      result = outOfMemoryError();
    }
  }  else
  {
    result = outOfMemoryError();
  }
  return result;
}

#endif

//----- (0043FF90) --------------------------------------------------------

#ifndef PORTABILITY
int   sub_43FF90(int *a1, int a2)
{
  int *v2; // esi@1
  int v3; // ebx@1
  int v4; // eax@3
  char v5; // al@8
  char v6; // al@11
  char v7; // al@18
  int v8; // eax@20
  char v9; // al@27
  int result; // eax@28

  v2 = a1;
  v3 = 0;
  if ( *(BYTE *)a1 )
  {
    do
    {
      while ( 1 )
      {
        v4 = _mb_cur_max <= 1 ? pctype[*(BYTE *)v2] & 8 : _isctype(*(BYTE *)v2, 8);
        if ( !v4 )
          break;
        v2 = (int *)((char *)v2 + 1);
      }
      if ( *(BYTE *)v2 == 34 )
      {
        v5 = *((BYTE *)v2 + 1);
        v2 = (int *)((char *)v2 + 1);
        if ( !v5 )
          break;
        if ( a2 )
          *(_DWORD *)(a2 + 4 * v3) = v2;
        v6 = *(BYTE *)v2;
        ++v3;
        if ( *(BYTE *)v2 )
        {
          do
          {
            if ( v6 == 34 )
              break;
            v6 = *((BYTE *)v2 + 1);
            v2 = (int *)((char *)v2 + 1);
          }
          while ( v6 );
        }
      }
      else if ( *(BYTE *)v2 )
      {
        if ( a2 )
          *(_DWORD *)(a2 + 4 * v3) = v2;
        v7 = *(BYTE *)v2;
        ++v3;
        if ( *(BYTE *)v2 )
        {
          do
          {
            if ( _mb_cur_max <= 1 )
              v8 = pctype[v7] & 8;
            else
              v8 = _isctype(v7, 8);
            if ( v8 )
              break;
            v7 = *((BYTE *)v2 + 1);
            v2 = (int *)((char *)v2 + 1);
          }
          while ( v7 );
        }
      }
      if ( !*(BYTE *)v2 )
        break;
      if ( a2 )
        *(BYTE *)v2 = 0;
      v9 = *((BYTE *)v2 + 1);
      v2 = (int *)((char *)v2 + 1);
    }
    while ( v9 );
  }
  result = v3;
  if ( a2 )
    *(_DWORD *)(a2 + 4 * v3) = 0;
  return result;
}
#endif
//----- (0043B2C0) --------------------------------------------------------

int   convertColorToPaletteColor(int a1, int a2)
{
  return a2 * (signed __int64)a1 >> 16;
}
// ALL OK, 396 function(s) have been successfully decompiled

 int __OFSUB__(int x, int y)
{
 
    int y2 = y;
    int8 sx = __SETS__(x);
    return (sx ^ __SETS__(y2)) & (sx ^ __SETS__(x-y2));
  
}

// sign flag
int __SETS__(int x)
{
    return x < 0;
  
}

int drawDebugInfo(){
	 char str[80];
	 int line =0;
 // writeTextInRace_402510(400+ 512*line++, raceParticipant2[0].name);

  sprintf(str, "SCREENX= %d", raceParticipantIngame[0].inScreenPositionX_4A7D04);
  writeTextInRace_402510(200+512*8*line++, str);
  sprintf(str, "SCREENY =%d", raceParticipantIngame[0].inScreenPositionY_4A7D08);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "ABSX=%f", raceParticipantIngame[0].absolutePositionX_4A7DB4);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "ABSY=%f", raceParticipantIngame[0].absolutePositionY_4A7DB8);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "VAIZONE=%d", raceParticipantIngame[0].actualVaiZone_4A7D00);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "VEL=%f", raceParticipantIngame[0].carVelocity_4A7DB0);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "LAP=%d", raceParticipantIngame[0].currentLap_4A7E08);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "DIRECTIONROTATION=%d", raceParticipantIngame[0].directionRotation_4A7D0C);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "ANGLE=%f", raceParticipantIngame[0].carAngle_4A7DAC);
  writeTextInRace_402510(200+ 512*8*line++, str);
  
  sprintf(str, "ADVANCEX=%f", raceParticipantIngame[0].advanceXAxis_4A7E5C);
  writeTextInRace_402510(200+ 512*8*line++, str);
  
  sprintf(str, "ADVANCEY=%f", raceParticipantIngame[0].advanceYAxis_4A7E60);
  writeTextInRace_402510(200+ 512*8*line++, str);

  sprintf(str, "dword_4A7DC0=%d", raceParticipantIngame[0].dword_4A7DC0);  
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "currentSteeringAngleDelta_4A7DA8=%f", raceParticipantIngame[0].currentSteeringAngleDelta_4A7DA8);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "dword_4A7DBC=%d", raceParticipantIngame[0].dword_4A7DBC);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "dword_50E71C=%d", dword_50E71C);
  writeTextInRace_402510(200+ 512*8*line++, str);
  
	  
	  
  /*sprintf(str, "PARTICIPANTBPKOFFSET:%d", raceParticipantIngame[0].participantBpkOffser_4A7D10);
  writeTextInRace_402510(200+ 512*8*line++, str);
  sprintf(str, "4A7E58:%d", raceParticipantIngame[0].flt_4A7E58);
  writeTextInRace_402510(200+ 512*8*line++, str);
 
  sprintf(str, "dword_4A7D20:%02x", raceParticipantIngame[0].dword_4A7D20);
  writeTextInRace_402510(200+ 512*8*line++, str);
 */
  return 0;
}

//----- (0041A7A0) --------------------------------------------------------
int drawTransparentBlock(int a1, int a2, int a3, int a4)
{
  int v4; // ebx@1
  int v5; // esi@1
  int v6; // eax@2
  char *v7; // esi@3
  char *v8; // edi@3
  unsigned int v10; // [sp+10h] [bp-4h]@2

  v4 = a4;
  v5 = a2;
  if ( a4 > 0 )
  {
    v10 = a3 - 6;
    v6 = 640 * a2;
    do
    {
      v7 = (char *)graphicsGeneral.menubg5Bpk + v6 + a1 - 2558;
      v8 = (char *)screenBuffer + v6 + a1 - 2558;
      memcpy(v8, v7, 4 * (v10 >> 2));
      v6 += 640;
      --v4;
      memcpy(&v8[4 * (v10 >> 2)], &v7[4 * (v10 >> 2)], v10 & 3);
    }
    while ( v4 );
    v5 = a2;
    v4 = a4;
  }
  drawImageWithPosition((int)graphics2.chatlin1Bpk, 640, 10, (int)((char *)screenBuffer + 128 * (5 * v5 + 5)));
  return drawImageWithPosition((int)graphics2.chatlin1Bpk, 640, 10, (int)((char *)screenBuffer + 640 * (v5 + v4 - 9)));
}