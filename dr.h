extern int debug;

extern int isMultiplayerGame; // weak
extern void *recotxtBpk; // idb
extern int* trsnap2m1Bpk[20];
extern void *trarr1Bpk; // idb;
extern int dword_445198 ; // weak
extern void *tsahpeBpk_45EB5C; 
extern void *fasesel1Bpk; // idb
extern void *fbig3bBpk; // idb
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
extern const INITIAL_MONEY;
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