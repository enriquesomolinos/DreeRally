#pragma once

typedef enum {
	RACE_EASY =0,
	RACE_MEDIUM=1,
	RACE_HARD=2

}RaceTypes;

typedef enum {
	RACE_POSITION_1 = 1,
	RACE_POSITION_2 = 2,
	RACE_POSITION_3 = 3,
	RACE_POSITION_4 = 4

}RacePosition;

typedef struct RaceParticipant {
	char name[12];
	int currentRacePosition;
	int damage; //parece que es el daño del coche!
	int engine;
	int tire;
	int armour;
	int rocket;
	int spikes;
	int mines;
	int useWeapons;
	int carType;  
	int r;
	int g;
	int b;
	int racePosition;
	int difficulty;
	int isCircuitReversed_4A7AA8;
	int drugPicked;
	int unk_4A7AB0;
	


} RaceParticipant;


typedef struct RaceParticipant2 {
	int carType;
	float unk_4A6884;
	float unk_4A6888;
	int unk_4A688C;
	int unk_4A6890;
	float unk_4A6894;
	int unk_4A6898;
	int unk_4A689C;
	int rocket;
	int spikes;
	int mines;
	int useWeapons;
	int unk_4A68B0;
	int unk_4A68B4;
	int r;
	int g;
	int b;
	char name[12];
	int currentRacePosition;
	int racePosition;
	int unk_4A68D8;
	int unk_4A68DC;
	int unk_4A68E0;
	int unk_4A68E4;
	int unk_4A68E8;
	int unk_4A68EC;
	int unk_4A68F0;
	int unk_4A68F4;

	int unk_4A68F8;
	int unk_4A68FC;
	int unk_4A6900;
	int unk_4A6904;
	int unk_4A6908;
	int unk_4A690C;

} RaceParticipant2;

/*RaceParticipant 4A7A60 contiene 12 bytes el nombre
4A7A6c posicion en carrera
4A7A70 daño
4A7A74 -> nivel de motor 0-3
4A7A78 -> nivel de ruedas 0-3
4A7A7c -> nivel de armadura 0-3
4A7A80 ->rocket
4A7A84 ->spikes
4A7A88 ->mines
4A7A8c ->useweapons
4A7A90 ->carType
4A7A94 ->R
4A7A98 ->G
4A7A9c ->B
4A7AA0 -> race position  dword_4A7AF4  dword_4A7B48  dword_4A7B9C
4A7AA4 -> difficulty
4A7AA8 -> circuit reversed!
4A7AAc -> cogida las drogas
4A7AB0 -> ? es la variable val que no se usa que yo sepa
4A7AB4 -> ya es el siguiente


dword_4A7A60  tamaño 84*4 hasta 4a7bb0






/*RaceParticipant2 dword_4A6880  estreuctura de 37 *4 bytes  para cada tipo de coche 6 en total hasta 4A6AD0
1 dword_4A6880 -> carType
dword_4A6884
dword_4A6888
dword_4A688C
5 dword_4A688C - parece que el tire efectivo
dword_4A6890
flt_4A6894 ->parece que es engine efectivo
dword_4A6898
dword_4A689C -> parece que armour efectivo
10dword_4A68A0 ->rocket
dword_4A68A4 ->spikes
dword_4A68A8 -> mines
dword_4A68AC ->use weapons
dword_4A68B0
15dword_4A68B4
dword_4A68B8 ->r
dword_4A68BC ->g
dword_4A68C0 ->b
4A68C4 -> es el nombre del participante 12 bytes
20

dword_4A68D0 ->currentRacePosition
dword_4A68D4  ->racePosition
dword_4A68D8
25dword_4A68DC
dword_4A68E0
dword_4A68E4
dword_4A68E8
dword_4A68EC
30dword_4A68F0
dword_4A68F4
dword_4A68F8
dword_4A68FC
dword_4A6900
35dword_4A6904
dword_4A6908
dword_4A690C




otra estructura que no se qu ees 
_4A7EA0   ->216 *4 bytes hasta unk_4A7BC4 864 de tamaño y son 4 participantes




int dword_4A6880[256]; // weak
int dword_4A6884[256]; // weak
int dword_4A6888; // weak
int dword_4A688C[256]; // weak
int dword_4A6890[256]; // weak
float flt_4A6894[256]; // weak
int dword_4A6898[256]; // weak
int dword_4A689C[256]; // weak
int dword_4A68A0[256]; // weak
int dword_4A68A4[256]; // weak
int dword_4A68A8[256]; // weak
int dword_4A68AC[256]; // weak
int dword_4A68B0[256]; // weak
int dword_4A68B4[256]; // weak
int dword_4A68B8; // weak
int dword_4A68BC; // weak
int dword_4A68C0; // weak
char byte_4A68C4[256]; // weak
*/
/*
char dword_4A7A60[256];
int dword_4A7A64; // weak
__int16 word_4A7A68; // weak
int dword_4A7A6C; // weak
int dword_4A7A70[256]; // weak
_UNKNOWN unk_4A7A74; // weak
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
int dword_4A7AA8; // weak
int dword_4A7AAC; // weak
int Val; // idb
char byte_4A7AB4[256]; // weak
int dword_4A7AC4; // weak
int dword_4A7AC8; // weak
int dword_4A7AE8; // weak
int dword_4A7AEC; // weak
int dword_4A7AF0; // weak
int dword_4A7AF4; // weak
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

*/