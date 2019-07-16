#pragma once

//el tamaño de los corredores es 108

#define TOTAL_DRIVERS = 20;



typedef enum {
	EASY_DIFFICULTY = 0,
	MEDIUM_DIFFICULTY = 1,
	HARD_DIFFICULTY = 2
}Difficulty;

typedef enum {
	NO_LOAN = -1,
	LOAN_DELIVERATOR = 0,
	LOAN_WRAIGHT = 1,
	LOAN_SHRIEKER = 2,
	LOAN_SENTINEL = 3,
	LOAN_DERVISH = 4

}LoanType;

typedef struct Driver {
	char name[12];
	int damage; //parece que es el daño del coche!
	int engine;
	int tire;
	int armour;
	int carType;  //offset de 28
	int unk_460860;
	int unk_460864;
	int unk_460868;
	int colour;
	int money;
	int loanType;
	int loanRaces;
	int carMoneyCost;
	int face;
	int points;
	int rank;
	int racesWon;
	int totalRaces;
	int lastRaceIncome;
	int totalIncome;
	int mines;
	int spikes;
	int rocket;
	int sabotage;
	
	
} Driver;


extern Driver drivers[20];

extern int driverId; // weak

extern char driverNames[20][20];

int initDrivers(void); // weak
char * getDifficultyText(int difficulty);
int getMaxDriverPoints(int userDriverId);

/*460840 contiene 16 bytes el nombre
46084c daño del coche
460850 -> nivel de motor 0-3
460854 -> nivel de ruedas 0-3
460858 -> nivel de armadura 0-3
46085c -> tipo de coche 0-5
460860
460864
460868
46086c parece que es el color
460870 dinero que tiene
460874 es el tipo de credito
460878 carreras desde que empieza el credito 1-4
46087C lo que cuesta el coche actual
460880 es la foto
460884 puntos que tiene
460888 posicion en el ranking

46088c racesWon
460890 totalRaces
460894 dinero ganado en la ultima carreras
460898 totalIncome
46089c minas compradas (numero)
4608a0 spikes
4608a4 rocket
4608a8 sabotage



*/

/*char byte_460840[256]; // weak

int dword_46084C[256]; // weak
int dword_460850[256]; // weak
int dword_460854[256]; // weak
int dword_460858[256]; // weak
int dword_46085C[256]; // weak
int dword_46086C[256]; // weak
int dword_460870[256]; // weak
int dword_460874[256]; // weak
int dword_460878[256]; // weak
int dword_46087C[256]; // weak
int dword_460880[256]; // weak
int dword_460884[256]; // weak
int dword_460888[256]; // weak
int dword_46088C[256]; // weak
int dword_460890[256]; // weak
int dword_460894[256]; // weak
int dword_460898[256]; // weak
int dword_46089C[256]; // weak
int dword_4608A0[256]; // weak
int dword_4608A4[256]; // weak
int dword_4608A8[256]; // weak
int dword_4608C8; // weak
int dword_4608F0[256]; // weak
int dword_460904[256]; // weak
int dword_460934; // weak
int dword_4609A0; // weak
int dword_460A0C; // weak
int dword_460A78; // weak
int dword_460AE4; // weak
int dword_460B50; // weak
int dword_460BBC; // weak
int dword_460C28; // weak
int dword_460C94; // weak
int dword_460D00; // weak
int dword_460D6C; // weak
int dword_460DD8; // weak
int dword_460E44; // weak
int dword_460EB0; // weak
int dword_460F1C; // weak
int dword_460F88; // weak
int dword_460FF4; // weak
int dword_461060; // weak
_UNKNOWN unk_461094; // weak*/

/*
dword_45EB50				participantes carrera 0 cada uno un byte
dword_45EB54				1
dword_45EB58				2*/