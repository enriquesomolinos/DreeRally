
#include "cars.h"

 Car cars[6];

 char* carName[6];

void initCars() {
	carName[0] = malloc(14);
	carName[1] = malloc(14);
	carName[2] = malloc(14);
	carName[3] = malloc(14);
	carName[4] = malloc(14);
	carName[5] = malloc(14);
	carName[6] = malloc(14);
	strcpy(carName[0],"KUPLA");
	strcpy(carName[1], "PICKUP");
	strcpy(carName[2], "SEDAN");
	strcpy(carName[3], "CAMARO");
	strcpy(carName[4], "PORCHE");
	strcpy(carName[5], "LOTUS");

	
	initCar0();
	initCar1();
	initCar2();
	initCar3();
	initCar4();
	initCar5();

	
}

char * getCarName(int carType) {
	if (carType == 0) {
		return "VAGABOND";
	}
	if (carType == 1) {
		return "DERVISH";
	}if (carType == 2) {
		return "SENTINEL";
	}if (carType == 3) {
		return "SHRIEKER";
	}if (carType == 4) {
		return "WRAITH";
	}if (carType == 5) {
		return "DELIVERATOR";
	}
}
void initCar0() {
	cars[0].name = "Vagabond";
	cars[0].cost = 500;
	cars[0].engineUpgrades = 1;
	cars[0].tireUpgrades = 2;
	cars[0].armourUpgrades = 1;
	cars[0].engineUpgradeCosts[0] = 1000; 
	cars[0].engineUpgradeCosts[1] = 0;
	cars[0].engineUpgradeCosts[2] = 0;
	cars[0].engineUpgradeCosts[3] = 0;
	cars[0].tireUpgradeCosts[0] = 500;
	cars[0].tireUpgradeCosts[1] = 1000;
	cars[0].tireUpgradeCosts[2] = 0;
	cars[0].tireUpgradeCosts[3] = 0;
	cars[0].armourUpgradeCosts[0] = 200;
	cars[0].armourUpgradeCosts[1] = 0;
	cars[0].armourUpgradeCosts[2] = 0;
	cars[0].armourUpgradeCosts[3] = 0;

	cars[0].repairCost = 45;
}
void initCar1() {
	cars[1].name = "Dervish";
	cars[1].cost = 2500;
	cars[1].engineUpgrades = 2;
	cars[1].tireUpgrades = 2;
	cars[1].armourUpgrades = 2;
	cars[1].engineUpgradeCosts[0] = 1250;
	cars[1].engineUpgradeCosts[1] = 2500;
	cars[1].engineUpgradeCosts[2] = 0;
	cars[1].engineUpgradeCosts[3] = 0;
	cars[1].tireUpgradeCosts[0] = 1000;
	cars[1].tireUpgradeCosts[1] = 2000;
	cars[1].tireUpgradeCosts[2] = 0;
	cars[1].tireUpgradeCosts[3] = 0;
	cars[1].armourUpgradeCosts[0] = 200;
	cars[1].armourUpgradeCosts[1] = 600;
	cars[1].armourUpgradeCosts[2] = 0;
	cars[1].armourUpgradeCosts[3] = 0;
	cars[1].repairCost = 125;
}
void initCar2() {
	cars[2].name = "Sentinel";
	cars[2].cost = 6500;
	cars[2].engineUpgrades = 2;
	cars[2].tireUpgrades = 3;
	cars[2].armourUpgrades = 2;
	cars[2].engineUpgradeCosts[0] = 2500;
	cars[2].engineUpgradeCosts[1] = 3750;
	cars[2].engineUpgradeCosts[2] = 0;
	cars[2].engineUpgradeCosts[3] = 0;
	cars[2].tireUpgradeCosts[0] = 2500;
	cars[2].tireUpgradeCosts[1] = 3000;
	cars[2].tireUpgradeCosts[2] = 4000;
	cars[2].tireUpgradeCosts[3] = 0;
	cars[2].armourUpgradeCosts[0] = 1000;
	cars[2].armourUpgradeCosts[1] = 1200;
	cars[2].armourUpgradeCosts[2] = 0;
	cars[2].armourUpgradeCosts[3] = 0;
	cars[2].repairCost = 125;
	cars[2].repairCost = 375;
}
void initCar3() {
	cars[3].name = "Shrieker";
	cars[3].cost = 11500;
	cars[3].engineUpgrades = 3;
	cars[3].tireUpgrades = 3;
	cars[3].armourUpgrades = 3;
	cars[3].engineUpgradeCosts[0] = 2500;
	cars[3].engineUpgradeCosts[1] = 3750;
	cars[3].engineUpgradeCosts[2] = 5000;
	cars[3].engineUpgradeCosts[3] = 0;
	cars[3].tireUpgradeCosts[0] = 2500;
	cars[3].tireUpgradeCosts[1] = 3000;
	cars[3].tireUpgradeCosts[2] = 4000;
	cars[3].tireUpgradeCosts[3] = 0;
	cars[3].armourUpgradeCosts[0] = 2025;
	cars[3].armourUpgradeCosts[1] = 3925;
	cars[3].armourUpgradeCosts[2] = 5950;
	cars[3].armourUpgradeCosts[3] = 0;
	cars[3].repairCost = 575;
}
void initCar4() {
	cars[4].name = "Wraith";
	cars[4].cost = 25000;
	cars[4].engineUpgrades = 3;
	cars[4].tireUpgrades = 4;
	cars[4].armourUpgrades = 3;
	cars[4].engineUpgradeCosts[0] = 5000;
	cars[4].engineUpgradeCosts[1] = 7500;
	cars[4].engineUpgradeCosts[2] = 10000;
	cars[4].engineUpgradeCosts[3] = 0;
	cars[4].tireUpgradeCosts[0] = 4000;
	cars[4].tireUpgradeCosts[1] = 5500;
	cars[4].tireUpgradeCosts[2] = 6000;
	cars[4].tireUpgradeCosts[3] = 7500;
	cars[4].armourUpgradeCosts[0] = 3200;
	cars[4].armourUpgradeCosts[1] = 4550;
	cars[4].armourUpgradeCosts[2] = 6950;
	cars[4].armourUpgradeCosts[3] = 0;
	cars[4].repairCost = 825;
}
void initCar5() {
	cars[5].name = "Deliverator";
	cars[5].cost = 45000;
	cars[5].engineUpgrades = 4;
	cars[5].tireUpgrades = 4;
	cars[5].armourUpgrades = 4;
	cars[5].engineUpgradeCosts[0] = 7550;
	cars[5].engineUpgradeCosts[1] = 11750;
	cars[5].engineUpgradeCosts[2] = 15800;
	cars[5].engineUpgradeCosts[3] = 22450;
	cars[5].tireUpgradeCosts[0] = 6000;
	cars[5].tireUpgradeCosts[1] = 8500;
	cars[5].tireUpgradeCosts[2] = 9750;
	cars[5].tireUpgradeCosts[3] = 12500;
	cars[5].armourUpgradeCosts[0] = 5525;
	cars[5].armourUpgradeCosts[1] = 7250;
	cars[5].armourUpgradeCosts[2] = 12525;
	cars[5].armourUpgradeCosts[3] = 15505;
	cars[5].repairCost = 1625;
}