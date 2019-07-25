#include "hof/hallOfFame.h"



typedef struct MainArgs {
	int configNoSound;
	int configSmooth;
	int configGL;
	int configWindow;
	int configNoSoundEffect;
	char * language;
	char * mod;
} MainArgs;

typedef struct Configuration {
	int musicVolume; //dword_45DC14
	int effectsVolume; // dword_45DC18;
	int dword_4457CC ;
	int difficulty;
	int useJoystick; //dword_45EA00
	int dword_463D00;
	int dword_463D04;
	int dword_463D08;
	int dword_463D0C;
	int dword_463D10;
	char byte_463D14;
	int dword_45EB80;
	int dword_45EB84;
	int dword_45EB88;
	int dword_45EB8C;
	int dword_45EB90;
	char byte_45EB94;
	int dword_456734; //algo de gamepad
	int dword_45FB68;
	int dword_45DC40;
	int dword_45DC1C;

	//esto son recorrd
	CircuitRecords* circuitRecords;
	//char byte_45F040[12]; // idb

	//variable con los datos del hall of fame
	//int dword_461F20[200]; // weak
	HallOfFameEntry* hallOfFameEntries;
	int accelerateKey; //dword_461EA8;
	int brakeKey; // dword_463CA8;
	int leftSteeringKey;// dword_461FF8;
	int rightSteeringKey; //dword_45EA68
	int turboKey; //dword_45FBF4
	int gunKey; //dword_463CE4
	int mineKey; //dword_461270
	int hornKey; //dword_463D18
	int accelerateGamepad; //dword_461294
	int brakeGamepad;//dword_461F14
	int leftSteeringGamepad;//dword_45EEA0
	int rightSteeringGamepad;//dword_462D6C
	int turboGamepad;//dword_463D8C
	int gunGamepad;//dword_462CFC
	int mineGamepad;//dword_463CA4
	int timesPlayed; //dword_463CEC
	char defaultAccelerateGamepad;// byte_44512C
	char defaultBrakeGamepad; //byte_44512B
	char defaultLeftSteeringGamepad;//byte_445128
	char defaultRightSteeringGamepad;//byte_445129
	char defaultTurboGamepad; //byte_44512D
	char defaultGunGamepad; //byte_44512E
	char defaultMineGamepad; //byte_44512F
} Configuration;

extern MainArgs mainArgs;
extern Configuration configuration;

int checkArgs(char * args);

int saveConfiguration();

char loadConfig();


//dword_461F20 es la estructura halloffame