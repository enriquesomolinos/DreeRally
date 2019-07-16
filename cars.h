


typedef enum  {
	 VAGABOND = 0,
	 DERVISH = 1,
	 SENTINEL = 2,
	 SHRIEKER = 3,
	 WRAITH = 4,
	 DELIVERATOR =5

}CarType;




typedef struct Car {
	char* name;
	int cost;
	char texts[70][40];
	int engineUpgrades;
	int tireUpgrades;
	int armourUpgrades;
	int engineUpgradeCosts[4];
	int tireUpgradeCosts[4];
	int armourUpgradeCosts[4];	
	int repairCost;

} Car;

extern Car cars[6];

extern char* carName[6];
void initCars();

void initCar0();
void initCar1();
void initCar2();
void initCar3();
void initCar4();
void initCar5();
char * getCarName(int carType);

/*empieza en 44df50 tamaaño 440 *4 int por coche =1760 bytes en total

44df50 16 bytes para el nombre
44df5c coste del coche

44df60  textos con separacion de 40 bytes

0044E5F0 mejoras de motor
0044E5F4 mejoras de ruedas
0044E5F8 mejoras de armoadura

0044E5FC coste motor mejora 1
0044E600 coste motor mejora 2
0044E604 coste motor mejora 3
0044E608 coste motor mejora 4

0044E60C coste ruedas mejora 1
0044E610 coste ruedas mejora 2
0044E614 coste ruedas mejora 3
0044E618 coste ruedas mejora 4

0044E61C coste armadura mejora 1
0044E620 coste armadura mejora 2
0044E624 coste armadura mejora 3
0044E628 coste armadura mejora 4


0044E62c coste de reparacions



*/
