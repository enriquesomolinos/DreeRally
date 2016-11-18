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
	int unk_4A7AA0;
	int difficulty;
	int unk_4A7AA8;
	int unk_4A7AAc;
	int unk_4A7AB0;
	int unk_4A7AB4;


	
	
	
	int sabotage;


} RaceParticipant;

/*4A7A60 contiene 12 bytes el nombre
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
4A7AA0 -> ?
4A7AA4 -> difficulty
4A7AA8 -> ?
4A7AAc -> ?
4A7AB0 -> ?
4A7AB4 -> ?


dword_4A7A60  tamaño 84*4 hasta 4a7bb0

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