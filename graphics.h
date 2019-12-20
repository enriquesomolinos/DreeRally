
#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct Graphics4 {
	void *badtitBpk;
	void *badsnapBpk;
	void *escboxBpk;
	void *signlineBpk;
	void *prep4Bpk;
	void *tsahpeBpk_45EB5C;
	void *prepw1Bpk;
} Graphics4;

typedef struct GraphicsGeneral {
	void *corn3bBpk; // idb
	void *corn3aBpk; // idb
	void *copperPal; // idb
	void *carcolPal; // idb
	void *bgcopPal; // idb
	void *t15x150Bpk; // idb
	void *fbig3aBpk; // idb
	void *fsma3bBpk; // idb
	void *fsma3cBpk; // idb
	void *fsma3aBpk; // idb
	void *fmed1aBpk; // idb
	void *menubg5Bpk; // idb
	void *mulsbg2Bpk; // idb
	void *rank1cBpk; // idb
	void *resupok1Bpk; // idb
	void *rankinf1Bpk; // idb
	void *rankinf2Bpk; // idb
	void *rankinf3Bpk; // idb
	void *raceeasBpk; // idb
	void *racemedBpk; // idb
	void *raceharBpk; // idb
	void *pnameBpk; // idb
	void *ppistBpk; // idb
	void *prankBpk; // idb
	void *ptseasyBpk; // idb
	void *ptsmedBpk; // idb
	void *ptshardBpk; // idb
	void *placingBpk; // idb
	void *carresBpk; // idb
	void *face01Bpk; // idb  //hasta la 20 tiene que ser un array! adversary va por libre
	void *face02Bpk; // idb
	void *face03Bpk; // idb
	void *face04Bpk; // idb
	void *face05Bpk; // idb
	void *face06Bpk; // idb
	void *face07Bpk; // idb
	void *face08Bpk; // idb
	void *face09Bpk; // idb
	void *face10Bpk; // idb
	void *face11Bpk; // idb
	void *face12Bpk; // idb
	void *face13Bpk; // idb
	void *face14Bpk; // idb
	void *face15Bpk; // idb
	void *face16Bpk; // idb
	void *face17Bpk; // idb
	void *face18Bpk; // idb
	void *face19Bpk; // idb
	void *face20Bpk; // idb
	void *facexxBpk; // idb
} GraphicsGeneral;

typedef struct Graphics2 {

	void *fbig3bBpk; // idb

	int* trsnap2m1Bpk[20]; // idb
	void *chattextBpk; // idb
	void *fasesel1Bpk; // idb
	void *facearr1Bpk; // idb
	void *shoptxt1Bpk; // idb
	void *fametxtBpk; // idb
	void *shoptxt2Bpk; // idb
	void *recobarBpk; // idb
	void *recotxtBpk; // idb
	void *linlin1Bpk; // idb
	void *chatlin1Bpk; // idb
	void *cursorBpk; // idb
	void *fbig3dBpk; // idb
	void *mseletx1Bpk; // idb
	void *trarr1Bpk; // idb
    void *enterx2Bpk;
} Graphics2;

extern Graphics2 graphics2;

extern GraphicsGeneral graphicsGeneral;

extern Graphics4 graphics4;

extern int textureTemp[0xFFFFFu]; // weak

extern void *screenBuffer;

void loadGraphics1();

void loadGraphics2();
void loadGraphics4();

void freeMemoryGraphics1();
void freeMemoryGraphics2();
void freeMemoryGraphics4();

#endif