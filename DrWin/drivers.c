#include "drivers.h"



extern Driver drivers[20];



extern char driverNames[20][20] = { "SAM SPEED",
"JANE HONDA",
"DUKE NUKEM",
"NASTY NICK",
"MOTOR MARY",
"MAD MAC",
"MATT MILLER",
"CLINT WEST",
"LEE VICE",
"DARK RIDER",
"GREG PECK",
"SUZY STOCK",
"IRON JOHN",
"MORI SATO",
"CHER STONE",
"DIESEL JOE",
"MIC DAIR",
"LIZ ARDEN",
"BOGUS BILL",
"FARMER TED" };


char * getDifficultyText(int difficulty) {
	char * EASY_DIFFICULTY_TEXT = "SPEED MAKES ME DIZZY";
	char * MEDIUM_DIFFICULTY_TEXT = "I LIVE TO RIDE";
	char * HARD_DIFFICULTY_TEXT = "PETROL IN MY VEINS";
	if (difficulty == 0) {
		return EASY_DIFFICULTY_TEXT;
	}
	if (difficulty == 1) {
		return MEDIUM_DIFFICULTY_TEXT;
	}
	if (difficulty == 2) {
		return HARD_DIFFICULTY_TEXT;
	}
}


int getMaxDriverPoints(int userDriverId) {
	int maxDriverPoints = 0;
	int indexDriver = 0;

	do {
		if (drivers[indexDriver].points > maxDriverPoints && indexDriver != userDriverId) {
			maxDriverPoints = drivers[indexDriver].points;
		}

		indexDriver++;
	} while (indexDriver < 20);
	return maxDriverPoints;
}