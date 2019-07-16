#pragma once



int __cdecl drawRecordByCircuit(int a1);
int seeHallOfFame();


typedef enum {
	SUBURBIA_CIRCUIT = 0,
	DOWNTOWN_CIRCUIT = 1,
	UTOPIA_CIRCUIT = 2,
	ROCKZONE_CIRCUIT = 3,
	SNAKEALLEY_CIRCUIT = 4,
	OASIS_CIRCUIT = 5,
	VELODROME_CIRCUIT = 6,
	HOLOCAUST_CIRCUIT = 7,
	BOGOTA_CIRCUIT = 8,
	WESTEND_CIRCUIT = 9,
	NEWARK_CIRCUIT = 10,
	COMPLEX_CIRCUIT = 11,
	HELLMOUNTAIN_CIRCUIT = 12,
	DESERTRUN_CIRCUIT = 13,
	PALMSIDE_CIRCUIT = 14,
	EIDOLON_CIRCUIT = 15,
	TOXICDUMP_CIRCUIT = 16,
	BORNEO_CIRCUIT = 17

}CircuitNames;
typedef struct HallOfFameEntry {
	char name[12];
	int races;
	int difficulty;

}HallOfFameEntry;

typedef struct CircuitRecords {
	char name[12];
	int min;
	int sec;
	int cen;

}CircuitRecords;


HallOfFameEntry* getDefaultHallOfFame();

CircuitRecords* getDefaulRecords();