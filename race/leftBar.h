#ifndef LEFT_BAR_H
#define LEFT_BAR_H


extern char smallbarBpk_50E720[2048];
extern int boardsBPK_4AA940[4][2048]; // weak
extern char* damslidBpk; // idb
extern char bugnum6Bpk_46E560[43300]; // weak ///TODO ajust correct size
extern char ownnum1Bpk_503520[22528]; // weak

extern char othnum1Bpk_50B2C0[12672]; // weak
extern void* goalnum2Bpk_4AA50C; // idb
extern char damageBpk_464F80[8064]; // weak
extern void* rast1Bpk_464F78; // idb
extern void* sidebom1Bpk_481E04; // idb

// int __usercall drawSmallLeftBar_413C90@<eax>(int a1@<ebx>);
// int __usercall drawSmallLeftBar_414110@<eax>(int a1@<ebx>);
int drawLeftRaceBar_414220();
int  drawWeaponsBar_43BEF0(int a1, void* a2, unsigned int a3, int a4, char a5);
int   drawTurboBar_43B3A0(int a1, int a2, int a3, char a4);

#endif