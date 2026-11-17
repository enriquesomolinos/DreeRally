#ifndef DR_H
#define DR_H

#include "defs.h"
#include <stdio.h>
#include <stdlib.h>


int __SETS__(int x);
int __OFSUB__(int x, int y);

//Sin estos prototipos, los llamadores que pasan un unsigned __int64 (p. ej. el porcentaje
//de dano en leftBar.c) empujan 8 bytes y corren todos los argumentos siguientes.
int drawSprite_402590(int baseImage, int width, int height, signed int a4, int spriteNumber, int a6, int a7, int a8);
int drawImageInRace_43B240(int filename, int width, int height, int offset);
int drawInRaceImageToBuffer_43B160(int a1, int a2, int a3, int a4);
//Ranking: ordena drivers[] por puntos y recalcula los puestos.
int sub_423C90(int a1, int a2);
void recalcRank(int a1);
int updateScreenPtr(int a1);

extern char byte_463E00[256]; // weak
extern void *volcur2Bpk; // idb

//Noticias del menu. En el original son dos bloques contiguos: el color de cada linea
//(0x461EC0, 22 bytes) y las lineas (0x462000, 22 x 150 bytes). El decompilado los partio en
//globales sueltas y los bucles que desplazan las lineas corrian hasta &blacktx1Bpk, que aqui
//esta en cualquier lado: pisaban memoria cada 150 bytes (drivers[] tras una carrera).
#define MENU_NEWS_LINES 22
#define MENU_NEWS_LINE_SIZE 150
extern char unk_461EC0[256]; // idb
#define unk_461EC1 (unk_461EC0[1])
#define unk_461EC2 (unk_461EC0[2])
#define unk_461EC3 (unk_461EC0[3])
#define word_461EC4 (*(__int16 *)&unk_461EC0[4])
#define unk_461EC6 (unk_461EC0[6])
#define unk_461EC7 (unk_461EC0[7])
#define word_461EC8 (*(__int16 *)&unk_461EC0[8])
#define unk_461ECA (unk_461EC0[10])
#define unk_461ECB (unk_461EC0[11])
#define word_461ECC (*(__int16 *)&unk_461EC0[12])
#define unk_461ECE (unk_461EC0[14])
#define unk_461ECF (unk_461EC0[15])
#define word_461ED0 (*(__int16 *)&unk_461EC0[16])
#define unk_461ED2 (unk_461EC0[18])
#define unk_461ED3 (unk_461EC0[19])
#define word_461ED4 (*(__int16 *)&unk_461EC0[20])
extern char unk_462000[MENU_NEWS_LINES * MENU_NEWS_LINE_SIZE];
#define MENU_NEWS_LINE(n) (&unk_462000[(n) * MENU_NEWS_LINE_SIZE])
#define MENU_NEWS_END_462CE4 MENU_NEWS_LINE(MENU_NEWS_LINES)
#define unk_462096 (*MENU_NEWS_LINE(1))
#define unk_462960 (*MENU_NEWS_LINE(16))
#define byte_4629F6 MENU_NEWS_LINE(17)
#define byte_462A8C MENU_NEWS_LINE(18)
#define byte_462B22 MENU_NEWS_LINE(19)
#define byte_462BB8 MENU_NEWS_LINE(20)
#define dword_462C4E (*(int *)MENU_NEWS_LINE(21))
#define dword_462C52 (*(int *)(MENU_NEWS_LINE(21) + 4))
#define dword_462C56 (*(int *)(MENU_NEWS_LINE(21) + 8))
#define dword_462C5A (*(int *)(MENU_NEWS_LINE(21) + 12))
#define dword_462C5E (*(int *)(MENU_NEWS_LINE(21) + 16))
#define word_462C62 (*(__int16 *)(MENU_NEWS_LINE(21) + 20))
extern int joystick_y_axis_default_4A9EA0;
extern int joystick_y_axis_4A9EB8;
extern int joystick_x_axis_default_4AA3E0; // weak
extern int joystick_x_axis_4A7A44; // weak
extern char byte_456B00;
extern void *slidmus2Bpk; // idb
extern char byte_456B01;
extern char byte_44512A;

//Juegos de noticias de True Tom ya usados (0x45F000, un byte por cada uno de los 19). El decompilado
//los partio en globales sueltas y sub_4279C0 marcaba el usado escribiendo mas alla del primer int.
extern char newsSetUsed_45F000[19];
#define dword_45F000 (*(int *)&newsSetUsed_45F000[0])
#define dword_45F004 (*(int *)&newsSetUsed_45F000[4])
#define dword_45F008 (*(int *)&newsSetUsed_45F000[8])
#define dword_45F00C (*(int *)&newsSetUsed_45F000[12])
#define word_45F010 (*(__int16 *)&newsSetUsed_45F000[16])
#define byte_45F012 (newsSetUsed_45F000[18])
extern char byte_45FB84; // weak
extern char aGamepadDisable[50];
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
//En dr.exe cada menu es un registro de 7 enteros desde 0x4456F0; el port lo partio en un arreglo
//por campo. 0x445724 es el cursor del menu 1 (partida), que una variable suelta no movia.
extern int dword_445708[];
#define dword_445724 (dword_445708[1])
extern int dword_4456E8;
extern int dword_45FA74; // weak
extern int dword_45FC00;
extern char byte_460840[2160];
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
extern void* statpop4Bpk;
extern int initialVelocity;
extern void* statbas7Bpk;

extern void* circuitMatrixHxW_5034F8; 
extern int circuitWidth_464F40; // weak
extern int currentDriverSelectedIndex_503518; // weak
extern void* obstacleBpk; // idb;
void* participantCarBpk_5034FC; // idb
extern int isRaceFinish_456AC8;
extern int dword_4A9EA4; // weak;


extern int dword_4AA500; // weak
extern void* genflaBpk; // idb
extern int numberOfParticipants_508D24; // weak
extern int participantRaceOrderUserFirst_508D44[4];
extern int dukeNukemEndRaceSoundPlayed_456AE8; // weak
extern char dukeNukemName[12];
extern int dword_4A7CFC; // weak
extern int dword_4A8A90[4]; // weak
extern int dword_4AA3F0[4]; // weak
extern int dword_4A7CC0[4]; // weak
extern int currentLapTime_481E0C; // weak
extern int ticksToPauseLapTimeInHud_4A9EB0; // weak
extern char smalfo4aBpk_4A9160[924*8]; // weak
extern int racePositionUserFirst_46E8D0[4]; // weak
extern int criticalDamageSoundPlayed_456ADC; // weak
extern int criticalDamage2SoundPlayed_456AE0; // weak

extern int lastCompletedLapTime_503224; // weak
extern int dword_503500; // weak
extern int dword_4B3160[256]; // weak
extern int dword_503240[256]; // weak
extern int raceFrame_481E14; // weak

typedef struct RacePopupMemory
{

	int unk_479EE0; // weak  -32  posicion x donde pintar
	int unk_479EE4; // weak  -28 posicion y donde pintar
int unk_479EE8; // weak 24
int unk_479EEC; // weak 20
//Pedazo de 4x4 pixeles del cartel, guardado dentro del struct (0x479EF0..0x479EFF).
//Estaba tipado como puntero con malloc(4): sub_43AE80 copia 16 bytes y desbordaba el heap
//en cada uno de los 969 pedazos (basura en el cartel y cierre al liberar al terminar).
int unk_479EF0[4];

char unk_479F00; // weak

} RacePopupMemory;

typedef struct RacePopupMemory2{
	int dword_50E560;
} RacePopupMemory2;

#endif