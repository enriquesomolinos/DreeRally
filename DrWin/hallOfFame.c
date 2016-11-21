
#include "hallOfFame.h"
#include "drivers.h"
#include "cars.h"



CircuitRecords* getDefaulRecords() {

	CircuitRecords circuitRecords[18*6];
	int i = 0;
	while (i < 18 * 6) {
		strcpy(circuitRecords[i].name, "REMEDY");
		circuitRecords[i].min=0;
		i++;
	}
	
	circuitRecords[SUBURBIA_CIRCUIT + VAGABOND].sec = 15;
	circuitRecords[ SUBURBIA_CIRCUIT + VAGABOND].cen = 55;
	circuitRecords[ SUBURBIA_CIRCUIT + DERVISH].sec = 14;
	circuitRecords[ SUBURBIA_CIRCUIT + DERVISH].cen = 49;
	circuitRecords[ SUBURBIA_CIRCUIT + SENTINEL].sec = 14;
	circuitRecords[ SUBURBIA_CIRCUIT + SENTINEL].cen = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + SHRIEKER].sec = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + SHRIEKER].cen = 89;
	circuitRecords[ SUBURBIA_CIRCUIT + WRAITH].sec = 13;
	circuitRecords[ SUBURBIA_CIRCUIT + WRAITH].cen = 22;
	circuitRecords[ SUBURBIA_CIRCUIT + DELIVERATOR].sec = 11;
	circuitRecords[ SUBURBIA_CIRCUIT + DELIVERATOR].cen = 36;

	circuitRecords[ DOWNTOWN_CIRCUIT + VAGABOND].sec = 18;
	circuitRecords[ DOWNTOWN_CIRCUIT + VAGABOND].cen = 16;
	circuitRecords[ DOWNTOWN_CIRCUIT + DERVISH].sec = 17;
	circuitRecords[ DOWNTOWN_CIRCUIT + DERVISH].cen = 8;
	circuitRecords[ DOWNTOWN_CIRCUIT + SENTINEL].sec = 16;
	circuitRecords[ DOWNTOWN_CIRCUIT + SENTINEL].cen = 23;
	circuitRecords[ DOWNTOWN_CIRCUIT + SHRIEKER].sec = 15;
	circuitRecords[ DOWNTOWN_CIRCUIT + SHRIEKER].cen = 52;
	circuitRecords[ DOWNTOWN_CIRCUIT + WRAITH].sec = 14;
	circuitRecords[DOWNTOWN_CIRCUIT + WRAITH].cen = 51;
	circuitRecords[DOWNTOWN_CIRCUIT + DELIVERATOR].sec = 13;
	circuitRecords[DOWNTOWN_CIRCUIT + DELIVERATOR].cen = 36;

	circuitRecords[UTOPIA_CIRCUIT + VAGABOND].sec = 27;
	circuitRecords[UTOPIA_CIRCUIT + VAGABOND].cen = 89;
	circuitRecords[UTOPIA_CIRCUIT + DERVISH].sec = 25;
	circuitRecords[UTOPIA_CIRCUIT + DERVISH].cen = 85;
	circuitRecords[UTOPIA_CIRCUIT + SENTINEL].sec = 24;
	circuitRecords[UTOPIA_CIRCUIT + SENTINEL].cen = 58;
	circuitRecords[UTOPIA_CIRCUIT + SHRIEKER].sec = 24;
	circuitRecords[UTOPIA_CIRCUIT + SHRIEKER].cen = 02;
	circuitRecords[UTOPIA_CIRCUIT + WRAITH].sec = 22;
	circuitRecords[UTOPIA_CIRCUIT + WRAITH].cen = 15;
	circuitRecords[UTOPIA_CIRCUIT + DELIVERATOR].sec = 20;
	circuitRecords[UTOPIA_CIRCUIT + DELIVERATOR].cen = 38;

	circuitRecords[ROCKZONE_CIRCUIT + VAGABOND].sec = 12;
	circuitRecords[ROCKZONE_CIRCUIT + VAGABOND].cen = 83;
	circuitRecords[ROCKZONE_CIRCUIT + DERVISH].sec = 12;
	circuitRecords[ROCKZONE_CIRCUIT + DERVISH].cen = 21;
	circuitRecords[ROCKZONE_CIRCUIT + SENTINEL].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + SENTINEL].cen = 95;
	circuitRecords[ROCKZONE_CIRCUIT + SHRIEKER].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + SHRIEKER].cen = 88;
	circuitRecords[ROCKZONE_CIRCUIT + WRAITH].sec = 11;
	circuitRecords[ROCKZONE_CIRCUIT + WRAITH].cen = 2;
	circuitRecords[ROCKZONE_CIRCUIT + DELIVERATOR].sec = 10;
	circuitRecords[ROCKZONE_CIRCUIT + DELIVERATOR].cen = 42;

	circuitRecords[SNAKEALLEY_CIRCUIT + VAGABOND].sec = 26;
	circuitRecords[SNAKEALLEY_CIRCUIT + VAGABOND].cen = 79;
	circuitRecords[SNAKEALLEY_CIRCUIT + DERVISH].sec = 26;
	circuitRecords[SNAKEALLEY_CIRCUIT + DERVISH].cen = 42;
	circuitRecords[SNAKEALLEY_CIRCUIT + SENTINEL].sec = 25;
	circuitRecords[SNAKEALLEY_CIRCUIT + SENTINEL].cen = 55;
	circuitRecords[SNAKEALLEY_CIRCUIT + SHRIEKER].sec = 24;
	circuitRecords[SNAKEALLEY_CIRCUIT + SHRIEKER].cen = 82;
	circuitRecords[SNAKEALLEY_CIRCUIT + WRAITH].sec = 21;
	circuitRecords[SNAKEALLEY_CIRCUIT + WRAITH].cen = 80;
	circuitRecords[SNAKEALLEY_CIRCUIT + DELIVERATOR].sec = 19;
	circuitRecords[SNAKEALLEY_CIRCUIT + DELIVERATOR].cen = 91;

	circuitRecords[OASIS_CIRCUIT + VAGABOND].sec = 13;
	circuitRecords[OASIS_CIRCUIT + VAGABOND].cen = 42;
	circuitRecords[OASIS_CIRCUIT + DERVISH].sec = 12;
	circuitRecords[OASIS_CIRCUIT + DERVISH].cen = 81;
	circuitRecords[OASIS_CIRCUIT + SENTINEL].sec = 12;
	circuitRecords[OASIS_CIRCUIT + SENTINEL].cen = 01;
	circuitRecords[OASIS_CIRCUIT + SHRIEKER].sec = 11;
	circuitRecords[OASIS_CIRCUIT + SHRIEKER].cen = 66;
	circuitRecords[OASIS_CIRCUIT + WRAITH].sec = 10;
	circuitRecords[OASIS_CIRCUIT + WRAITH].cen = 96;
	circuitRecords[OASIS_CIRCUIT + DELIVERATOR].sec = 9;
	circuitRecords[OASIS_CIRCUIT + DELIVERATOR].cen = 66;

	circuitRecords[VELODROME_CIRCUIT + VAGABOND].sec = 15;
	circuitRecords[VELODROME_CIRCUIT + VAGABOND].cen = 90;
	circuitRecords[VELODROME_CIRCUIT + DERVISH].sec = 14;
	circuitRecords[VELODROME_CIRCUIT + DERVISH].cen = 89;
	circuitRecords[VELODROME_CIRCUIT + SENTINEL].sec = 14;
	circuitRecords[VELODROME_CIRCUIT + SENTINEL].cen = 0;
	circuitRecords[VELODROME_CIRCUIT + SHRIEKER].sec = 13;
	circuitRecords[VELODROME_CIRCUIT + SHRIEKER].cen = 12;
	circuitRecords[VELODROME_CIRCUIT + WRAITH].sec = 12;
	circuitRecords[VELODROME_CIRCUIT + WRAITH].cen = 5;
	circuitRecords[VELODROME_CIRCUIT + DELIVERATOR].sec = 10;
	circuitRecords[VELODROME_CIRCUIT + DELIVERATOR].cen = 86;

	circuitRecords[HOLOCAUST_CIRCUIT + VAGABOND].sec = 27;
	circuitRecords[HOLOCAUST_CIRCUIT + VAGABOND].cen = 80;
	circuitRecords[HOLOCAUST_CIRCUIT + DERVISH].sec = 26;
	circuitRecords[HOLOCAUST_CIRCUIT + DERVISH].cen = 96;
	circuitRecords[HOLOCAUST_CIRCUIT + SENTINEL].sec = 24;
	circuitRecords[HOLOCAUST_CIRCUIT + SENTINEL].cen = 50;
	circuitRecords[HOLOCAUST_CIRCUIT + SHRIEKER].sec = 22;
	circuitRecords[HOLOCAUST_CIRCUIT + SHRIEKER].cen = 78;
	circuitRecords[HOLOCAUST_CIRCUIT + WRAITH].sec = 21;
	circuitRecords[HOLOCAUST_CIRCUIT + WRAITH].cen = 30;
	circuitRecords[HOLOCAUST_CIRCUIT + DELIVERATOR].sec = 19;
	circuitRecords[HOLOCAUST_CIRCUIT + DELIVERATOR].cen = 58;

	circuitRecords[BOGOTA_CIRCUIT + VAGABOND].sec = 17;
	circuitRecords[BOGOTA_CIRCUIT + VAGABOND].cen = 57;
	circuitRecords[BOGOTA_CIRCUIT + DERVISH].sec = 16;
	circuitRecords[BOGOTA_CIRCUIT + DERVISH].cen = 72;
	circuitRecords[BOGOTA_CIRCUIT + SENTINEL].sec = 15;
	circuitRecords[BOGOTA_CIRCUIT + SENTINEL].cen = 62;
	circuitRecords[BOGOTA_CIRCUIT + SHRIEKER].sec = 14;
	circuitRecords[BOGOTA_CIRCUIT + SHRIEKER].cen = 15;
	circuitRecords[BOGOTA_CIRCUIT + WRAITH].sec = 13;
	circuitRecords[BOGOTA_CIRCUIT + WRAITH].cen = 85;
	circuitRecords[BOGOTA_CIRCUIT + DELIVERATOR].sec = 13;
	circuitRecords[BOGOTA_CIRCUIT + DELIVERATOR].cen = 1;

	circuitRecords[WESTEND_CIRCUIT + VAGABOND].sec = 15;
	circuitRecords[WESTEND_CIRCUIT + VAGABOND].cen = 42;
	circuitRecords[WESTEND_CIRCUIT + DERVISH].sec = 14;
	circuitRecords[WESTEND_CIRCUIT + DERVISH].cen = 63;
	circuitRecords[WESTEND_CIRCUIT + SENTINEL].sec = 14;
	circuitRecords[WESTEND_CIRCUIT + SENTINEL].cen = 1;
	circuitRecords[WESTEND_CIRCUIT + SHRIEKER].sec = 13;
	circuitRecords[WESTEND_CIRCUIT + SHRIEKER].cen = 76;
	circuitRecords[WESTEND_CIRCUIT + WRAITH].sec = 13;
	circuitRecords[WESTEND_CIRCUIT + WRAITH].cen = 14;
	circuitRecords[WESTEND_CIRCUIT + DELIVERATOR].sec = 11;
	circuitRecords[WESTEND_CIRCUIT + DELIVERATOR].cen = 48;

	circuitRecords[NEWARK_CIRCUIT + VAGABOND].sec = 18;
	circuitRecords[NEWARK_CIRCUIT + VAGABOND].cen = 0;
	circuitRecords[NEWARK_CIRCUIT + DERVISH].sec = 16;
	circuitRecords[NEWARK_CIRCUIT + DERVISH].cen = 98;
	circuitRecords[NEWARK_CIRCUIT + SENTINEL].sec = 16;
	circuitRecords[NEWARK_CIRCUIT + SENTINEL].cen = 11;
	circuitRecords[NEWARK_CIRCUIT + SHRIEKER].sec = 15;
	circuitRecords[NEWARK_CIRCUIT + SHRIEKER].cen = 62;
	circuitRecords[NEWARK_CIRCUIT + WRAITH].sec = 14;
	circuitRecords[NEWARK_CIRCUIT + WRAITH].cen = 52;
	circuitRecords[NEWARK_CIRCUIT + DELIVERATOR].sec = 13;
	circuitRecords[NEWARK_CIRCUIT + DELIVERATOR].cen = 31;

	circuitRecords[COMPLEX_CIRCUIT + VAGABOND].sec = 27;
	circuitRecords[COMPLEX_CIRCUIT + VAGABOND].cen = 49;
	circuitRecords[COMPLEX_CIRCUIT + DERVISH].sec = 25;
	circuitRecords[COMPLEX_CIRCUIT + DERVISH].cen = 63;
	circuitRecords[COMPLEX_CIRCUIT + SENTINEL].sec = 24;
	circuitRecords[COMPLEX_CIRCUIT + SENTINEL].cen = 22;
	circuitRecords[COMPLEX_CIRCUIT + SHRIEKER].sec = 23;
	circuitRecords[COMPLEX_CIRCUIT + SHRIEKER].cen = 76;
	circuitRecords[COMPLEX_CIRCUIT + WRAITH].sec = 21;
	circuitRecords[COMPLEX_CIRCUIT + WRAITH].cen = 91;
	circuitRecords[COMPLEX_CIRCUIT + DELIVERATOR].sec = 20;
	circuitRecords[COMPLEX_CIRCUIT + DELIVERATOR].cen = 25;

	circuitRecords[HELLMOUNTAIN_CIRCUIT + VAGABOND].sec = 12;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + VAGABOND].cen = 68;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + DERVISH].sec = 12;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + DERVISH].cen = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + SENTINEL].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + SENTINEL].cen = 98;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + SHRIEKER].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + SHRIEKER].cen = 71;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + WRAITH].sec = 11;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + WRAITH].cen = 14;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + DELIVERATOR].sec = 10;
	circuitRecords[HELLMOUNTAIN_CIRCUIT + DELIVERATOR].cen = 31;

	circuitRecords[DESERTRUN_CIRCUIT + VAGABOND].sec = 26;
	circuitRecords[DESERTRUN_CIRCUIT + VAGABOND].cen = 82;
	circuitRecords[DESERTRUN_CIRCUIT + DERVISH].sec = 26;
	circuitRecords[DESERTRUN_CIRCUIT + DERVISH].cen = 37;
	circuitRecords[DESERTRUN_CIRCUIT + SENTINEL].sec = 25;
	circuitRecords[DESERTRUN_CIRCUIT + SENTINEL].cen = 61;
	circuitRecords[DESERTRUN_CIRCUIT + SHRIEKER].sec = 24;
	circuitRecords[DESERTRUN_CIRCUIT + SHRIEKER].cen = 96;
	circuitRecords[DESERTRUN_CIRCUIT + WRAITH].sec = 21;
	circuitRecords[DESERTRUN_CIRCUIT + WRAITH].cen = 91;
	circuitRecords[DESERTRUN_CIRCUIT + DELIVERATOR].sec = 19;
	circuitRecords[DESERTRUN_CIRCUIT + DELIVERATOR].cen = 69;

	circuitRecords[PALMSIDE_CIRCUIT + VAGABOND].sec = 13;
	circuitRecords[PALMSIDE_CIRCUIT + VAGABOND].cen = 36;
	circuitRecords[PALMSIDE_CIRCUIT + DERVISH].sec = 12;
	circuitRecords[PALMSIDE_CIRCUIT + DERVISH].cen = 62;
	circuitRecords[PALMSIDE_CIRCUIT + SENTINEL].sec = 12;
	circuitRecords[PALMSIDE_CIRCUIT + SENTINEL].cen = 24;
	circuitRecords[PALMSIDE_CIRCUIT + SHRIEKER].sec = 11;
	circuitRecords[PALMSIDE_CIRCUIT + SHRIEKER].cen = 71;
	circuitRecords[PALMSIDE_CIRCUIT + WRAITH].sec = 11;
	circuitRecords[PALMSIDE_CIRCUIT + WRAITH].cen = 8;
	circuitRecords[PALMSIDE_CIRCUIT + DELIVERATOR].sec = 9;
	circuitRecords[PALMSIDE_CIRCUIT + DELIVERATOR].cen = 81;

	circuitRecords[EIDOLON_CIRCUIT + VAGABOND].sec = 16;
	circuitRecords[EIDOLON_CIRCUIT + VAGABOND].cen = 8;
	circuitRecords[EIDOLON_CIRCUIT + DERVISH].sec = 14;
	circuitRecords[EIDOLON_CIRCUIT + DERVISH].cen = 67;
	circuitRecords[EIDOLON_CIRCUIT + SENTINEL].sec = 14;
	circuitRecords[EIDOLON_CIRCUIT + SENTINEL].cen = 24;
	circuitRecords[EIDOLON_CIRCUIT + SHRIEKER].sec = 13;
	circuitRecords[EIDOLON_CIRCUIT + SHRIEKER].cen = 1;
	circuitRecords[EIDOLON_CIRCUIT + WRAITH].sec = 11;
	circuitRecords[EIDOLON_CIRCUIT + WRAITH].cen = 85;
	circuitRecords[EIDOLON_CIRCUIT + DELIVERATOR].sec = 10;
	circuitRecords[EIDOLON_CIRCUIT + DELIVERATOR].cen = 78;

	circuitRecords[TOXICDUMP_CIRCUIT + VAGABOND].sec = 27;
	circuitRecords[TOXICDUMP_CIRCUIT + VAGABOND].cen = 98;
	circuitRecords[TOXICDUMP_CIRCUIT + DERVISH].sec = 26;
	circuitRecords[TOXICDUMP_CIRCUIT + DERVISH].cen = 82;
	circuitRecords[TOXICDUMP_CIRCUIT + SENTINEL].sec = 24;
	circuitRecords[TOXICDUMP_CIRCUIT + SENTINEL].cen = 62;
	circuitRecords[TOXICDUMP_CIRCUIT + SHRIEKER].sec = 22;
	circuitRecords[TOXICDUMP_CIRCUIT + SHRIEKER].cen = 57;
	circuitRecords[TOXICDUMP_CIRCUIT + WRAITH].sec = 21;
	circuitRecords[TOXICDUMP_CIRCUIT + WRAITH].cen = 33;
	circuitRecords[TOXICDUMP_CIRCUIT + DELIVERATOR].sec = 19;
	circuitRecords[TOXICDUMP_CIRCUIT + DELIVERATOR].cen = 47;

	circuitRecords[BORNEO_CIRCUIT + VAGABOND].sec = 17;
	circuitRecords[BORNEO_CIRCUIT + VAGABOND].cen = 42;
	circuitRecords[BORNEO_CIRCUIT + DERVISH].sec = 16;
	circuitRecords[BORNEO_CIRCUIT + DERVISH].cen = 86;
	circuitRecords[BORNEO_CIRCUIT + SENTINEL].sec = 15;
	circuitRecords[BORNEO_CIRCUIT + SENTINEL].cen = 45;
	circuitRecords[BORNEO_CIRCUIT + SHRIEKER].sec = 13;
	circuitRecords[BORNEO_CIRCUIT + SHRIEKER].cen = 98;
	circuitRecords[BORNEO_CIRCUIT + WRAITH].sec = 13;
	circuitRecords[BORNEO_CIRCUIT + WRAITH ].cen = 79;
	circuitRecords[BORNEO_CIRCUIT + DELIVERATOR].sec = 12;
	circuitRecords[BORNEO_CIRCUIT + DELIVERATOR].cen = 94;


	return circuitRecords;
}

HallOfFameEntry* getDefaultHallOfFame() {
	HallOfFameEntry hallOfFameEntry[10];
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

	hallOfFameEntry[0].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[1].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[2].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[3].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[4].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[5].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[6].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[7].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[8].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[9].difficulty = EASY_DIFFICULTY;
	hallOfFameEntry[0].difficulty = EASY_DIFFICULTY;

	return hallOfFameEntry;
}
