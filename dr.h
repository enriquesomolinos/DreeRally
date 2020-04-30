#ifndef DR_H
#define DR_H

#include "defs.h"
extern char byte_463E00[256]; // weak
extern _UNKNOWN unk_462096; // weak

extern __int16 word_461ED4; // weak
extern void *volcur2Bpk; // idb

extern char unk_461EC0[256]; // idb
extern _UNKNOWN unk_461EC1; // weak
extern _UNKNOWN unk_461EC2; // weak
extern _UNKNOWN unk_461EC3; // weak
extern __int16 word_461EC4; // weak
extern _UNKNOWN unk_461EC6; // weak
extern _UNKNOWN unk_461EC7; // weak
extern __int16 word_461EC8; // weak
extern _UNKNOWN unk_461ECA; // weak
extern _UNKNOWN unk_461ECB; // weak
extern __int16 word_461ECC; // weak
extern _UNKNOWN unk_461ECE; // weak
extern _UNKNOWN unk_461ECF; // weak
extern __int16 word_461ED0; // weak
extern _UNKNOWN unk_461ED2; // weak
extern _UNKNOWN unk_461ED3; // weak
extern int joystick_y_axis_default_4A9EA0;
extern int joystick_y_axis_4A9EB8;
extern int joystick_x_axis_default_4AA3E0; // weak
extern int joystick_x_axis_4A7A44; // weak
extern char byte_456B00;
extern void *slidmus2Bpk; // idb
extern char byte_456B01;
extern char byte_44512A;
extern char byte_4629F6[256]; // weak
extern char byte_462A8C[256]; // weak
extern char byte_462B22[256]; // weak
extern char byte_462BB8[256]; // weak
extern char byte_456618[] ;
extern char byte_45665E[] ;
extern char byte_4566A4[] ;
extern char byte_4566EA[];
extern __int16 word_45F010; // weak
extern int dword_4A9140; // weak
extern int dword_45F000; // weak
extern int dword_45F004; // weak
extern int dword_45F008; // weak
extern int dword_45F00C; // weak
extern char byte_45FB84; // weak
extern char byte_45F012; // weak
extern char aGamepadDisable[17];
extern int menuOptionSelected_463DF0; // weak
extern int debug;
extern int cursorBpkFrame; 
extern int participantInRaceById_45EA80[20];
extern int useHasMorePoints_456BC4;
extern int Val; // [sp+10h] [bp-314h]@1
extern int userRacePosition_456B50; // weak
extern int userRaceOrder_45FC20; // weak
extern int userLasRacePriceIncome_456BDC; // weak
extern int userLastRaceIncomeNoPrice_456BE0; // weak
extern int totalRaceSeconds_45EEBC; // weak
extern int totalRaceMinutes_45EEC0; // weak
extern int currentLapMilliseconds_45FC1C; // weak
extern int totalRaceMilliseconds_462D74; // weak
extern int currentRaceBestLapMinutes_463CAC; // idb
extern int currentRaceBestLapSeconds_45EB48; // idb
extern int currentLapSeconds_463CD4; // weak
extern int currentLapMinutes_45EA64; // weak
extern int currentRaceBestLapMilliseconds_461FEC; // idb
extern int circuitRecordSeconds_501260; // weak
extern int circuitRecordMilliseconds_4A9B8C; // weak
extern int circuitRecordMinutes_50A160; // weak
extern int totalRaceTime_50A164; // weake
extern int showWelcomePopup_456B74; // weak
extern int showUndergroundPopup_456B78; // weak
extern int showMediumWarningRace; // weak
extern int showHardWarningRace; // weak

extern int numberOfLaps; // idb
extern char raceFilePrefix_45EA50[8];
extern int participantsRace[3];
extern int firstRacePlayed_464F44; 
extern int dword_461250; // weak
extern int dword_45F04C; // idb
extern int dword_4608F0[256]; // weak (solo un uso en dr.c)
extern int dword_45F050; // idb
extern int dword_45F054; // idb
extern int dword_456BD8;
extern int dword_456730;
extern int dword_445724;
extern int dword_4456E8;
extern int dword_45FA74; // weak
extern int dword_45FC00;
extern char byte_460840[256];
extern char circuitsToSelect_46126C[3];
extern char byte_462D50;
extern char byte_45FAA0[256];
extern int screenPtr;

extern int isMultiplayerGame; // weak
extern int dword_445198 ; // weak
extern void *tsahpeBpk_45EB5C; 
extern void *slidcop2Bpk; // idb
extern void *slidcur3Bpk; // idb
extern void *carnameBpk; // idb
extern void *carbas2Bpk; // idb
extern void *kuplaBpk; // idb
extern void *spons1bBpk; // idb
extern void *event2Bpk; // idb
extern void *reaperxBpk; // idb;
extern void *drugdealBpk; // idb;
extern void *dealer2bBpk; // idbM;
extern void *arrows1dBpk;
extern void *bases41Bpk;
extern void *bases42Bpk;
extern void *bases43Bpk;
extern void *bases44Bpk;
extern void *bases45Bpk;
extern void *repaaniBpk;
extern void *maxi1fBpk;
extern void* contaniBpk;
extern void *maret1eBpk; // idb
extern void *blacktx2Bpk; // idb
extern void *blacktx1Bpk; // idb

extern char keysRead_45E0C0[256]; // weak

extern int drugQuest_456BB4; // weak
extern int killOneQuest_456BB8; // weak
extern int killQuestDriverId_456BBC; // weak

extern int useWeapons;

extern int dword_45678C ; // weak
extern int dword_45FA78; // weak
extern int dword_445194;
extern int dword_4451A0;
extern int dword_44DF5C;
extern void *dword_461EA4;
extern int dword_45EB50[256]; // weak
//extern char keysRead_45E0C0[KEY_F2]; // weak
//extern char keysRead_45E0C0[KEY_F3]; // weak

extern int userRaceOrder_4A9EA8;
extern int isCircuitReversed_456AA8;
extern void *splat4Bpk;
extern void *splat3Bpk;
extern void * pedestrBpk;

extern int circuitImageOffsetX_456ABC ;
extern int leftMenuInRaceWidth_456AA0;

extern int circuitImageOffsetY_456AC0;
extern int dword_464F14;
extern int carAnimFrameSize_45FBA0[6*64];

extern int palette1[768];
extern int selectedRace_462CE8; // weak;
extern int racePositions[3][4];

extern int lapped_456BC0 ; // weak
extern int maxPaletteEntries;
extern int dword_456B9C;
extern int consecutiveWins_456BA8;
extern int noPaintJob_456BAC; // weak
extern int allCarsCrash_456BB0 ;
extern int selectedRaceId ;
extern int isDemo_456B10;
extern int dword_456B68;
extern const int INITIAL_MONEY;
extern int continueAnimCurrentFrame_4611D0; // weak;
extern int armourAnimFrameDirection_45F034; // weak
extern int armourAnimCurrentFrame_461288;
extern int tireAnimCurrentFrame_45F034 ;
extern int engineAnimCurrentFrame_462D80 ;
extern int carAnimCurrentFrame_45FBA0 ;
extern int actualCarSelected;
extern void * fsma3fBpk;

extern int undergroundPricesSet_456B84;
extern int showUndergroundPopup_456B78;

extern int dword_456B58;
extern int dword_462D7C; // weak
extern int framesToWaitAfterBuy_456B70;
extern void *dword_461ED8; // idb
extern int dword_456B60;
extern int dword_456B6C;
extern int dword_456B64;

extern int dword_4451A4;
extern int dword_44518C;
extern int raceDrivers_456758;
extern int dword_445190;



extern int dword_481BE8;

extern int raceEffectiveHalfWidth_445014;
extern int raceEffectiveHeight_445018;
extern int raceEffectiveHalfHeight_44501C;
extern int dword_4A7A38;

//shadow 3d system
extern int dword_50351C;
extern int dword_4A8A80;
extern int dword_4A7A4C;
extern int dword_46ECE4;
extern int dword_50EF20;
extern int dword_4A6AD0;

extern int raceShowTextures_44502C;
extern int raceEffectiveWidth_445010;
extern char circuitSelectedTR_464F50[8];

typedef struct RacePopupMemory
{

	int unk_479EE0; // weak  -32  posicion x donde pintar
	int unk_479EE4; // weak  -28 posicion y donde pintar
int unk_479EE8; // weak 24
int unk_479EEC; // weak 20
int * unk_479EF0; // weak 16 puntero que contiene la imagen a mostras :)
int unk_479EF4; // weak 12
int unk_479EF8; // weak 8
int unk_479EFC; // weak 4

char unk_479F00; // weak

} RacePopupMemory;

typedef struct RacePopupMemory2{
	int dword_50E560;
} RacePopupMemory2;

#endif