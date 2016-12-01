
#include "hallOfFame.h"
#include "drivers.h"
#include "cars.h"



CircuitRecords* getDefaulRecords() {

	CircuitRecords* circuitRecords = malloc(sizeof(CircuitRecords) * 18 * 6);
	int i = 0;
	while (i < 18 * 6) {
		strcpy(circuitRecords[i].name, "REMEDY");
		circuitRecords[i].min=0;
		i++;
	}
	
	circuitRecords[SUBURBIA_CIRCUIT + VAGABOND].sec = 15;
	circuitRecords[ SUBURBIA_CIRCUIT + VAGABOND].cen = 55;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DERVISH].cen = 49;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SENTINEL].cen = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * SHRIEKER].cen = 89;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * WRAITH].sec = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * WRAITH].cen = 22;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DELIVERATOR].sec = 11;
	circuitRecords[ SUBURBIA_CIRCUIT + 18 * DELIVERATOR].cen = 36;

	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * VAGABOND].sec = 18;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * VAGABOND].cen = 16;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * DERVISH].sec = 17;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * DERVISH].cen = 8;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SENTINEL].sec = 16;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SENTINEL].cen = 23;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SHRIEKER].sec = 15;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * SHRIEKER].cen = 52;
	circuitRecords[ DOWNTOWN_CIRCUIT + 18 * WRAITH].sec = 14;
	circuitRecords[DOWNTOWN_CIRCUIT + 18 * WRAITH].cen = 51;
	circuitRecords[DOWNTOWN_CIRCUIT + 18 * DELIVERATOR].sec = 13;
	circuitRecords[DOWNTOWN_CIRCUIT + 18 * DELIVERATOR].cen = 36;

	circuitRecords[UTOPIA_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[UTOPIA_CIRCUIT + 18 * VAGABOND].cen = 89;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DERVISH].sec = 25;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DERVISH].cen = 85;
	circuitRecords[UTOPIA_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[UTOPIA_CIRCUIT + 18* SENTINEL].cen = 58;
	circuitRecords[UTOPIA_CIRCUIT + 18 * SHRIEKER].sec = 24;
	circuitRecords[UTOPIA_CIRCUIT + 18 * SHRIEKER].cen = 02;
	circuitRecords[UTOPIA_CIRCUIT + 18 * WRAITH].sec = 22;
	circuitRecords[UTOPIA_CIRCUIT + 18 * WRAITH].cen = 15;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DELIVERATOR].sec = 20;
	circuitRecords[UTOPIA_CIRCUIT + 18 * DELIVERATOR].cen = 38;

	circuitRecords[ROCKZONE_CIRCUIT + 18 * VAGABOND].sec = 12;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * VAGABOND].cen = 83;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DERVISH].cen = 21;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SENTINEL].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SENTINEL].cen = 95;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * SHRIEKER].cen = 88;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * WRAITH].cen = 2;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[ROCKZONE_CIRCUIT + 18 * DELIVERATOR].cen = 42;

	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * VAGABOND].sec = 26;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * VAGABOND].cen = 79;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DERVISH].cen = 42;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SENTINEL].sec = 25;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SENTINEL].cen = 55;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SHRIEKER].sec = 24;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * SHRIEKER].cen = 82;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * WRAITH].cen = 80;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[SNAKEALLEY_CIRCUIT + 18 * DELIVERATOR].cen = 91;

	circuitRecords[OASIS_CIRCUIT + 18 * VAGABOND].sec = 13;
	circuitRecords[OASIS_CIRCUIT + 18 * VAGABOND].cen = 42;
	circuitRecords[OASIS_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[OASIS_CIRCUIT + 18 * DERVISH].cen = 81;
	circuitRecords[OASIS_CIRCUIT + 18 * SENTINEL].sec = 12;
	circuitRecords[OASIS_CIRCUIT + 18 * SENTINEL].cen = 01;
	circuitRecords[OASIS_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[OASIS_CIRCUIT + 18 * SHRIEKER].cen = 66;
	circuitRecords[OASIS_CIRCUIT + 18 * WRAITH].sec = 10;
	circuitRecords[OASIS_CIRCUIT + 18 * WRAITH].cen = 96;
	circuitRecords[OASIS_CIRCUIT + 18 * DELIVERATOR].sec = 9;
	circuitRecords[OASIS_CIRCUIT + 18 * DELIVERATOR].cen = 66;

	circuitRecords[VELODROME_CIRCUIT + 18 * VAGABOND].sec = 15;
	circuitRecords[VELODROME_CIRCUIT + 18 * VAGABOND].cen = 90;
	circuitRecords[VELODROME_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[VELODROME_CIRCUIT + 18 * DERVISH].cen = 89;
	circuitRecords[VELODROME_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[VELODROME_CIRCUIT + 18 * SENTINEL].cen = 0;
	circuitRecords[VELODROME_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[VELODROME_CIRCUIT + 18 * SHRIEKER].cen = 12;
	circuitRecords[VELODROME_CIRCUIT + 18 * WRAITH].sec = 12;
	circuitRecords[VELODROME_CIRCUIT + 18 * WRAITH].cen = 5;
	circuitRecords[VELODROME_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[VELODROME_CIRCUIT + 18 * DELIVERATOR].cen = 86;

	circuitRecords[HOLOCAUST_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * VAGABOND].cen = 80;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DERVISH].cen = 96;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SENTINEL].cen = 50;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SHRIEKER].sec = 22;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * SHRIEKER].cen = 78;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * WRAITH].cen = 30;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[HOLOCAUST_CIRCUIT + 18 * DELIVERATOR].cen = 58;

	circuitRecords[BOGOTA_CIRCUIT + 18 * VAGABOND].sec = 17;
	circuitRecords[BOGOTA_CIRCUIT + 18 * VAGABOND].cen = 57;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DERVISH].sec = 16;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DERVISH].cen = 72;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SENTINEL].sec = 15;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SENTINEL].cen = 62;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SHRIEKER].sec = 14;
	circuitRecords[BOGOTA_CIRCUIT + 18 * SHRIEKER].cen = 15;
	circuitRecords[BOGOTA_CIRCUIT + 18 * WRAITH].sec = 13;
	circuitRecords[BOGOTA_CIRCUIT + 18 * WRAITH].cen = 85;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DELIVERATOR].sec = 13;
	circuitRecords[BOGOTA_CIRCUIT + 18 * DELIVERATOR].cen = 1;

	circuitRecords[WESTEND_CIRCUIT + 18 * VAGABOND].sec = 15;
	circuitRecords[WESTEND_CIRCUIT + 18 * VAGABOND].cen = 42;
	circuitRecords[WESTEND_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[WESTEND_CIRCUIT + 18 * DERVISH].cen = 63;
	circuitRecords[WESTEND_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[WESTEND_CIRCUIT + 18 * SENTINEL].cen = 1;
	circuitRecords[WESTEND_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[WESTEND_CIRCUIT + 18 * SHRIEKER].cen = 76;
	circuitRecords[WESTEND_CIRCUIT + 18 * WRAITH].sec = 13;
	circuitRecords[WESTEND_CIRCUIT + 18 * WRAITH].cen = 14;
	circuitRecords[WESTEND_CIRCUIT + 18 * DELIVERATOR].sec = 11;
	circuitRecords[WESTEND_CIRCUIT + 18 * DELIVERATOR].cen = 48;

	circuitRecords[NEWARK_CIRCUIT + 18 * VAGABOND].sec = 18;
	circuitRecords[NEWARK_CIRCUIT + 18 * VAGABOND].cen = 0;
	circuitRecords[NEWARK_CIRCUIT + 18 * DERVISH].sec = 16;
	circuitRecords[NEWARK_CIRCUIT + 18 * DERVISH].cen = 98;
	circuitRecords[NEWARK_CIRCUIT + 18 * SENTINEL].sec = 16;
	circuitRecords[NEWARK_CIRCUIT + 18 * SENTINEL].cen = 11;
	circuitRecords[NEWARK_CIRCUIT + 18 * SHRIEKER].sec = 15;
	circuitRecords[NEWARK_CIRCUIT + 18 * SHRIEKER].cen = 62;
	circuitRecords[NEWARK_CIRCUIT + 18 * WRAITH].sec = 14;
	circuitRecords[NEWARK_CIRCUIT + 18 * WRAITH].cen = 52;
	circuitRecords[NEWARK_CIRCUIT + 18 * DELIVERATOR].sec = 13;
	circuitRecords[NEWARK_CIRCUIT + 18 * DELIVERATOR].cen = 31;

	circuitRecords[COMPLEX_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[COMPLEX_CIRCUIT + 18 * VAGABOND].cen = 49;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DERVISH].sec = 25;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DERVISH].cen = 63;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SENTINEL].cen = 22;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SHRIEKER].sec = 23;
	circuitRecords[COMPLEX_CIRCUIT + 18 * SHRIEKER].cen = 76;
	circuitRecords[COMPLEX_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[COMPLEX_CIRCUIT + 18 * WRAITH].cen = 91;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DELIVERATOR].sec = 20;
	circuitRecords[COMPLEX_CIRCUIT + 18 * DELIVERATOR].cen = 25;

	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * VAGABOND].sec = 12;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * VAGABOND].cen = 68;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DERVISH].cen = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SENTINEL].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SENTINEL].cen = 98;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * SHRIEKER].cen = 71;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * WRAITH].cen = 14;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + 18 * DELIVERATOR].cen = 31;

	circuitRecords[DESERTRUN_CIRCUIT + 18 * VAGABOND].sec = 26;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * VAGABOND].cen = 82;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DERVISH].cen = 37;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SENTINEL].sec = 25;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SENTINEL].cen = 61;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SHRIEKER].sec = 24;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * SHRIEKER].cen = 96;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * WRAITH].cen = 91;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[DESERTRUN_CIRCUIT + 18 * DELIVERATOR].cen = 69;

	circuitRecords[PALMSIDE_CIRCUIT + 18 * VAGABOND].sec = 13;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * VAGABOND].cen = 36;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DERVISH].sec = 12;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DERVISH].cen = 62;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SENTINEL].sec = 12;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SENTINEL].cen = 24;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SHRIEKER].sec = 11;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * SHRIEKER].cen = 71;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * WRAITH].cen = 8;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DELIVERATOR].sec = 9;
	circuitRecords[PALMSIDE_CIRCUIT + 18 * DELIVERATOR].cen = 81;

	circuitRecords[EIDOLON_CIRCUIT + 18 * VAGABOND].sec = 16;
	circuitRecords[EIDOLON_CIRCUIT + 18 * VAGABOND].cen = 8;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DERVISH].sec = 14;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DERVISH].cen = 67;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SENTINEL].sec = 14;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SENTINEL].cen = 24;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SHRIEKER].sec = 13;
	circuitRecords[EIDOLON_CIRCUIT + 18 * SHRIEKER].cen = 1;
	circuitRecords[EIDOLON_CIRCUIT + 18 * WRAITH].sec = 11;
	circuitRecords[EIDOLON_CIRCUIT + 18 * WRAITH].cen = 85;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DELIVERATOR].sec = 10;
	circuitRecords[EIDOLON_CIRCUIT + 18 * DELIVERATOR].cen = 78;

	circuitRecords[TOXICDUMP_CIRCUIT + 18 * VAGABOND].sec = 27;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * VAGABOND].cen = 98;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * DERVISH].sec = 26;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * DERVISH].cen = 82;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SENTINEL].sec = 24;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SENTINEL].cen = 62;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SHRIEKER].sec = 22;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * SHRIEKER].cen = 57;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * WRAITH].sec = 21;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * WRAITH].cen = 33;
	circuitRecords[TOXICDUMP_CIRCUIT + 18 * DELIVERATOR].sec = 19;
	circuitRecords[TOXICDUMP_CIRCUIT + 18*DELIVERATOR].cen = 47;

	circuitRecords[BORNEO_CIRCUIT + VAGABOND * 18].sec = 17;
	circuitRecords[BORNEO_CIRCUIT + VAGABOND * 18].cen = 42;
	circuitRecords[BORNEO_CIRCUIT + DERVISH * 18].sec = 16;
	circuitRecords[BORNEO_CIRCUIT + DERVISH * 18].cen = 86;
	circuitRecords[BORNEO_CIRCUIT + SENTINEL * 18].sec = 15;
	circuitRecords[BORNEO_CIRCUIT + SENTINEL * 18].cen = 45;
	circuitRecords[BORNEO_CIRCUIT + SHRIEKER * 18].sec = 13;
	circuitRecords[BORNEO_CIRCUIT + SHRIEKER * 18].cen = 98;
	circuitRecords[BORNEO_CIRCUIT + WRAITH * 18].sec = 13;
	circuitRecords[BORNEO_CIRCUIT + WRAITH * 18].cen = 79;
	circuitRecords[BORNEO_CIRCUIT + DELIVERATOR * 18].sec = 12;
	circuitRecords[BORNEO_CIRCUIT + DELIVERATOR * 18].cen = 94;


	return circuitRecords;
}

HallOfFameEntry* getDefaultHallOfFame() {
	HallOfFameEntry* hallOfFameEntry =malloc(sizeof(HallOfFameEntry)*10);
	strcpy(hallOfFameEntry[0].name,"SAM SPEED");
	strcpy(hallOfFameEntry[1].name,"JANE HONDA");
	strcpy(hallOfFameEntry[2].name,"DUKE NUKEM");
	strcpy(hallOfFameEntry[3].name,"NASTY NICK");
	strcpy(hallOfFameEntry[4].name,"MOTOR MARY");
	strcpy(hallOfFameEntry[5].name,"MAD MAC");
	strcpy(hallOfFameEntry[6].name,"MATT MILLER");
	strcpy(hallOfFameEntry[7].name,"CLINT WEST");
	strcpy(hallOfFameEntry[8].name,"LEE VICE");
	strcpy(hallOfFameEntry[9].name,"DARK RIDER");
	
	hallOfFameEntry[0].races = 50;
	hallOfFameEntry[1].races = 66;
	hallOfFameEntry[2].races = 82;
	hallOfFameEntry[3].races = 98;
	hallOfFameEntry[4].races = 114;
	hallOfFameEntry[5].races = 130;
	hallOfFameEntry[6].races = 146;
	hallOfFameEntry[7].races = 162;
	hallOfFameEntry[8].races = 178;
	hallOfFameEntry[9].races = 194;

	hallOfFameEntry[0].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[1].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[2].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[3].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[4].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[5].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[6].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[7].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[8].difficulty = MEDIUM_DIFFICULTY;
	hallOfFameEntry[9].difficulty = MEDIUM_DIFFICULTY;
	

	return hallOfFameEntry;
}
