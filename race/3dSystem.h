

#ifndef THREE_D_SYSTEM_H
#define THREE_D_SYSTEM_H

#include "../defs.h"
typedef struct Sce4Texture{
	int tetureWidth_50A180; // weak parece ancho de sce5
	int textureHeight_50A184; // weak parece alto de sce5 y tama�o total
	int textureOffset_50A188;
	int dword_50A18C; // weak pos x en el mapa
	int dword_50A190; // weak pos y en el mapa
	int dword_50A194; // weak
	int dword_50A198; // weak  tempoarl offset x en pantalla, lo que viene en el fichero no se usa
	int dword_50A19C; // weak 0 tempoarl offset y en pantalla, lo que viene en el ficherio no se usa
	int dword_50A1A0;
	int id3dObject_50A1A4;
	int idPolygon_50A1A8; // weak

} Sce4Texture;
extern Sce4Texture sce4Texture[100];

typedef struct Sce3DObject{

	int trxSCE2Bpk_4B4320; // weak  //estructura de 788 *100*4
	int numberTriangles_4B4324; // weak  determina el tama�o del array de 12
	int  dword_4B4328[75]; // idb tama�o trxSCE2Bpk_4B4320
	int dword_4B4454[75]; // weak tama�o trxSCE2Bpk_4B4320
	int dword_4B4580[75]; // weak tama�o trxSCE2Bpk_4B4320
	int dword_4B46AC[4];

	int dword_4B46BC[100]; // weak  924 tama�o numberTriangles_4B4324 puntero t1
	int dword_4B484C[100]; // weak  //+1324 tama�o numberTriangles_4B4324  puntero t2
	int dword_4B49DC[100]; // weak  1724 tama�o numberTriangles_4B4324 puntero t3
	char polygonColour_4B4B6C[400]; // color
	int unk_4B4CFC;  //posicion donde pintar el poligoo
	int unk_4B4D00; // weak posicion donde pintar el poligono
	int dword_4B4D04; // weak  //3152* 100 vueltas  parece ancho donde empezar a pintar respecto de donde estas, por eso se recalcula
	int dword_4B4D08; // weak parece alto donde empezar a pintar desde donde estas , por eso se recalcula
	int dword_4B4D0C[75]; // weak tama�o trxSCE2Bpk_4B4320 recalculated x
	int dword_4B4E38[75]; // weak tama�o trxSCE2Bpk_4B4320 recalculated y
	int dword_4B4F64; // weak parece que detemrina si esta en pantalla
	int dword_4B4F68; // weak paraece el area que ocupa el poligono width*width + height*height
	int dword_4B4F6C; // weak
} Sce3DObject;
extern Sce3DObject sce2Texture[100];

extern int trxSCE1Number3DObjects_479D20;
extern int trxSCE3Bpk_464F10;
extern void* trxSCE5Bpk_4A7A28;


extern int dword_4AA928; // weak
extern int dword_467020[7504]; // weak
extern float flt_4A8AC0[256]; // weak
extern float flt_4A8C00[256]; // weak
extern float flt_4A9A60[256]; // weak
extern int dword_46F220[1000][100]; // weak
extern int dword_4A6AFC; // weak
extern _UNKNOWN unk_46ED00; // weak
extern _UNKNOWN unk_4A7BC0; // weak
extern _UNKNOWN unk_4AA400; // weak

int   sub_4115C0(int a1, int a2);
int processSceFile_40A360();
int calculateSceTextureStructure_40A880();
void recalculatePolygonsInScreeenPosition_40D6B0();
int sub_411530();
void draw3dElements_4116D0();
int sub_4156B0();
void parseCircuitSceFile_403190();
int   draw3dTexture_43B2F0(int a1, int a2, int a3, int textureId);
int   setTriangleValue_43CD50(int a1, int a2, int a3, int a4, int a5, int a6, char a7);
#endif // 3DSYSTEM_H