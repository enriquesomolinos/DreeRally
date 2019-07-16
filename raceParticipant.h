#pragma once

typedef enum {
	RACE_EASY =0,
	RACE_MEDIUM=1,
	RACE_HARD=2,
	RACE_ARENA = 3

}RaceTypes;

typedef enum {
	RACE_POSITION_1 = 1,
	RACE_POSITION_2 = 2,
	RACE_POSITION_3 = 3,
	RACE_POSITION_4 = 4

}RacePosition;

typedef struct Mines{

	//parece un array de minas en pantalla estructura de 4 enteros
int dword_481C00; // weak coordenada x de la mina
int dword_481C04; // weak coordenada y de la mina
int unk_481C08; // weak
int unk_481C0C; // weak
} Mines;

extern Mines raceMines[32];


typedef struct RaceParticipant {
	char name[12];
	int moneyPicked;
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
	float efectiveEngine_4A6884;
	float efectiveEngineBackup_4A6888;//backup del motor porque cambia en medio de carrera
	int efectiveTire_4A688C;
	float carSize_4A6890;
	float steeringCapacity_4A6894;//parece que es la oposicin al giro del coche (cuanto peor coche es mas alto)
	int damageBar_4A6898;
	int efectiveArmour_4A689C;
	//d<word_4A68A0 ->rocket
//dword_4A68A4 ->spikes
//dword_4A68A8 -> mines
//dword_4A68AC ->use weapons
	int rocket;
	int spikes;
	int mines;
	int useWeapons;
	int weaponsBar_4A68B0;
	int turboBar_4A68B4;
	int r;
	int g;
	int b;
	char name[12];
	int moneyPicked;
	int racePosition;
	int usingRocket_4A68D8;

	//numero de pistolas 1 o 2 dependiendo del coche
	int weaponsNumber_4A68DC;
	
	
	int activeWeapon_4A68E0;

	//hacen referencia a las pistolas  posiciones de las pistolas respecto al punto central positivo izquierda, negativo derecha
	int weaponPosition_4A68E4[2];
	//int unk_4A68E4;
	//int unk_4A68E8;
	
	int unk_4A68EC;
	int unk_4A68F0;
	
	//hacen referencia a las pistolas potencia de fuego de cada pistola
	int weaponStrength_4A68F4[2];
	//int unk_4A68F4;
	//int unk_4A68F8;
	
	int unk_4A68FC;
	int unk_4A6900;
	
	//tipo de flame a ostrar en funcion del arma
	int weaponFlameType[2];

	//int unk_4A6904;
	//int unk_4A6908;


	int unk_4A690C;

} RaceParticipant2;

extern RaceParticipant raceParticipant[4];
extern RaceParticipant2 raceParticipant2[4];

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






/*RaceParticipant2 dword_4A6880  estreuctura de 37 *4 bytes  para cada tipo de coche 4 en total hasta 4A6AD0
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
15dword_4A68B4 ->turboBar
dword_4A68B8 ->r
dword_4A68BC ->g
dword_4A68C0 ->b
4A68C4 -> es el nombre del participante 12 bytes
20

dword_4A68D0 ->moneyPicked
dword_4A68D4  ->racePosition
usingRocket_4A68D8
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
int dword_4A6898[256]; // weak   -barra de daño
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


typedef struct RaceParticipantIngame {
	int actualVaiZone_4A7D00; // weak
	int inScreenPositionX_4A7D04; // weak  //parece x e y
	int inScreenPositionY_4A7D08; // weak
	int directionRotation_4A7D0C; // weak
	int participantBpkOffser_4A7D10; // weak   //parece el offset de participantRaceCar_bkp
	int dword_4A7D14; // weak
	int dword_4A7D18; // weak
	int dword_4A7D1C; // weak teclas pulsadas
	char dword_4A7D20[16]; // idb array de bytes teclas pulsadas
	int lastKeysRead_4A7D60[64]; // weak// ultimas teclas pulsadas
	int lastKeysReadIndex_4A7DA0; // weak
	int lastKeysReadPreviousIndex_4A7DA4; // weak
	float currentSteeringAngleDelta_4A7DA8; // weak
	float carAngle_4A7DAC; // weak  //parece el angulo en grados
	double carVelocity_4A7DB0; // weak //parece la velocidad que llevas
	float absolutePositionX_4A7DB4; // weak
	float absolutePositionY_4A7DB8; // weak
	int dword_4A7DBC;//este no venia
	int dword_4A7DC0;//este no venia  parece como el tiempo que llevas girando
	int dword_4A7DC4; //este n venia  estos son para el calculo del mobvimiento dle usuario
	float dword_4A7DC8; //este no venia
	float dword_4A7DCC;//float
	float dword_4A7DD0;
	float dword_4A7DD4;
	float dword_4A7DD8;
	float dword_4A7DDC;
	float dword_4A7DE0;
	float dword_4A7DE4;
	float dword_4A7DE8;
	float dword_4A7DEC;
	float dword_4A7DF0;
	
	int dword_4A7DF4;//est eno venia
	int dword_4A7DF8;//este no venia
	int unk_4A7DFC; // weak  modificador del avance ejex
	int unk_4A7E00; // weak modificador del avance eje y sobre todo para choques
	int unk_4A7E04; // weak modificador del angulo con choques y terreno.
	char currentLap_4A7E08; // weak
	char racePosition_4A7E09; // weak
	int hasFinishedTheRace_4A7E0C; // weak
	int frontLeftAbsoluteXPosition_4A7E10; // weak
	int frontLeftAbsoluteYPosition_4A7E14; // weak
	int lastFrontLeftAbsoluteXPosition_4A7E18; // weak  relacionado con la anterios
 	int lastFrontLeftAbsoluteYPosition_4A7E1C; // weak relacionado con la anterios
	int frontRightAbsoluteXPosition_4A7E20;
	int frontRightAbsoluteYPosition_4A7E24; // weak
	int lastFrontRightAbsoluteXPosition_4A7E28; // weak relacionado con la anterios
	int lastFrontRightAbsoluteYPosition_4A7E2C; // weak relacionado con la anterios
	int backLeftAbsoluteXPosition_4A7E30; // weak  //esquina de atras izquierda
	int backLeftAbsoluteYPosition_4A7E34; // weak
	int lastBackLeftAbsoluteXPosition_4A7E38; // weak
	int lastBackLeftAbsoluteYPosition_4A7E3C; // weak  
	int backRightAbsoluteXPosition_4A7E40; // weak//esquina de atras derecha
	int backRightAbsoluteYPosition_4A7E44; // weak
	int lastBackRightAbsoluteXPosition_4A7E48; // weak 
	int lastBackRightAbsoluteYPosition_4A7E4C; // weak
	int dword_4A7E50; // weak
	int dword_4A7E54; // weak
	float flt_4A7E58; // weak//parece algo relacionado con el angulo del coche
	float advanceXAxis_4A7E5C; // weak   //avance eje x    parece que son float
	float advanceYAxis_4A7E60; // weak   //avance eje y 
	int unk_4A7E64; // weak
	int dword_4A7E68;//este no venia
	int dword_4A7E6C; // weak
	int dword_4A7E70; // weak
	int dword_4A7E74[256]; // weak
	int dword_4A7E78[256]; // weak
	int dword_4A7E80; // weak
	int dword_4A7E84; // weak
	int dword_4A7E88; // weak parece que es solo par la ia, como si pudiera mover. operaciones de movimiento que le quedan parece
	int dword_4A7E8C;
	int dword_4A7E90[256]; // weak
	int dword_4A7E94; // weak
	int dword_4A7E98; // weak
	int dword_4A7E9C; // weak
	int dword_4A7EA0; // weak parece la barra de rocket
	int timeToDeployMine_4A7EA4; // weak //tiempo de espera entre lanzamiento de minas
	int dword_4A7EA8; // weak
	int dword_4A7EAC; // weak
	int dword_4A7EB0; // weak
	int dword_4A7EB4; // weak si se puede disparar
	int dword_4A7EB8; // weak drawFlames_4A7EB8
	int dword_4A7EBC[256]; // weak
	int dword_4A7EC0[256]; // weak
	int dword_4A7EC4[256]; // weak
	int dword_4A7EC8[256]; // weak
	int dword_4A7ECC[256]; // weak
	int dword_4A7ED0[256]; // weak
	int dword_4A7ED4[256]; // weak
	int dword_4A7ED8[256]; // weak
	int spriteBurnOffset_4A7EDC; // weak


	///ticks desde que se inicializa la libreria sdl
	int dword_4A7EE0; // weak
	int dword_4A7EE4[16]; // array de 16 posiciones weak  relacionado con smoke para habilitarlo patinaje izquierdo
	int dword_4A7F20[16]; // array de 16 posiciones weak  relacionado con smoke para habilitarlo patinaje derecho
	int dword_4A7F5C[256]; // weak smoke parece posicion x del coche la parte de atras parece una rueda izquierd
	int dword_4A7F98[256]; // weaksmoke parece posicion x del coche la parte de atras rueda derecha
	int dword_4A7FD4[256]; // weak smoke parece posicion y del coche la parte de atras
	int dword_4A8010[256]; // weaksmoke parece posicion y del coche la parte de atras
	int dword_4A804C; // weak tiene que ver algo con el smoke
	int mushroomPendingTime_4A8050; // weak  //tiempo bebido pendiente
	int dword_4A8054; // weak
	int dword_4A8058; // weak relacionado con el sonido del motor
	int hornPlayed_4A805C; // horn si vale 1

} RaceParticipantIngame;

extern RaceParticipantIngame raceParticipantIngame[4];


/*raceparticipant3 son los datos en pantalla de carrera de los participantes
int dword_4A7D00[256]; // weak
int inScreenPositionX_4A7D04[256]; // weak
int inScreenPositionY_4A7D08[256]; // weak
int directionRotation_4A7D0C[256]; // weak
int participantBpkOffser_4A7D10[256]; // weak
int dword_4A7D14[256]; // weak
int dword_4A7D18[256]; // weak
int dword_4A7D1C[256]; // weak
byte dword_4A7D20[64]; // idb
int dword_4A7D60[256]; // weak
int lastKeysReadIndex_4A7DA0[256]; // weak
int lastKeysReadPreviousIndex_4A7DA4[256]; // weak
_UNKNOWN currentSteeringAngleDelta_4A7DA8; // weak
float carAngle_4A7DAC[256]; // weak
int carVelocity_4A7DB0[256]; // weak
int absolutePositionX_4A7DB4[256]; // weak
int absolutePositionY_4A7DB8[256]; // weak
_UNKNOWN unk_4A7DFC; // weak
_UNKNOWN unk_4A7E00; // weak
_UNKNOWN unk_4A7E04; // weak
char currentLap_4A7E08[256]; // weak
char racePosition_4A7E09[256]; // weak
int hasFinishedTheRace_4A7E0C[256]; // weak
int frontLeftAbsoluteXPosition_4A7E10[256]; // weak
int frontLeftAbsoluteYPosition_4A7E14[256]; // weak
int lastFrontLeftAbsoluteXPosition_4A7E18[256]; // weak
int lastFrontLeftAbsoluteYPosition_4A7E1C[256]; // weak
int frontRightAbsoluteYPosition_4A7E24[256]; // weak
int frontRightAbsoluteXPosition_4A7E20[256]; // weak
int lastFrontRightAbsoluteXPosition_4A7E28[256]; // weak
int lastFrontRightAbsoluteYPosition_4A7E2C[256]; // weak
int backLeftAbsoluteXPosition_4A7E30[256]; // weak
int backLeftAbsoluteYPosition_4A7E34[256]; // weak
int lastBackLeftAbsoluteXPosition_4A7E38[256]; // weak
int lastBackLeftAbsoluteYPosition_4A7E3C[256]; // weak
int backRightAbsoluteXPosition_4A7E40[256]; // weak
int backRightAbsoluteYPosition_4A7E44[256]; // weak
int lastBackRightAbsoluteXPosition_4A7E48[256]; // weak
int lastBackRightAbsoluteYPosition_4A7E4C[256]; // weak
int dword_4A7E50[256]; // weak
int dword_4A7E54[256]; // weak
float flt_4A7E58; // weak
int advanceXAxis_4A7E5C[256]; // weak
int advanceYAxis_4A7E60[256]; // weak
_UNKNOWN unk_4A7E64; // weak
int dword_4A7E6C[256]; // weak
int dword_4A7E70[256]; // weak
int dword_4A7E74[256]; // weak
int dword_4A7E78[256]; // weak
int dword_4A7E80[256]; // weak
int dword_4A7E84[256]; // weak
int dword_4A7E88[256]; // weak
int dword_4A7E90[256]; // weak
int dword_4A7E94[256]; // weak
int dword_4A7E98[256]; // weak
int dword_4A7E9C[256]; // weak
int dword_4A7EA0[256]; // weak
int dword_4A7EA4[256]; // weak
int dword_4A7EA8[256]; // weak
int dword_4A7EAC[256]; // weak
int dword_4A7EB0[256]; // weak
int dword_4A7EB4[256]; // weak
int dword_4A7EB8[256]; // weak
int dword_4A7EBC[256]; // weak
int dword_4A7EC0[256]; // weak
int dword_4A7EC4[256]; // weak
int dword_4A7EC8[256]; // weak
int dword_4A7ECC[256]; // weak
int dword_4A7ED0[256]; // weak
int dword_4A7ED4[256]; // weak
int dword_4A7ED8[256]; // weak
int spriteBurnOffset_4A7EDC[256]; // weak
int dword_4A7EE0[256]; // weak
int dword_4A7EE4[256]; // weak
int dword_4A7F20[256]; // weak
int dword_4A7F5C[256]; // weak
int dword_4A7F98[256]; // weak
int dword_4A7FD4[256]; // weak
int dword_4A8010[256]; // weak
int dword_4A804C[256]; // weak
int dword_4A8050[256]; // weak
int dword_4A8054[256]; // weak
int dword_4A8058[256]; // weak
int hornPlayed_4A805C[256]; // weak
//primer raceparticiant3


int directionRotation_4A7D0C[1]; // weak
int dword_4A8070; // weak
float flt_4A810C; // weak
float absolutePositionX_4A7DB4[1]; // weak
float absolutePositionY_4A7DB8[1]; // weak
char byte_4A8168; // weak
char byte_4A8169; // weak
int dword_4A81B0; // weak
int dword_4A81B4; // weak
float flt_4A81B8; // weak
int dword_4A83AC; // weak
int directionRotation_4A7D0C[2]; // weak
int dword_4A83D0; // weak
float flt_4A846C; // weak
float absolutePositionX_4A7DB4[2]; // weak
float absolutePositionY_4A7DB8[2]; // weak
char byte_4A84C8; // weak
char byte_4A84C9; // weak
int dword_4A8510; // weak
int dword_4A8514; // weak
float flt_4A8518; // weak
int dword_4A870C; // weak
int directionRotation_4A7D0C[3]; // weak
int dword_4A8730; // weak
float flt_4A87CC; // weak
float absolutePositionX_4A7DB4[3]; // weak
float absolutePositionY_4A7DB8[3]; // weak
char byte_4A8828; // weak
char byte_4A8829; // weak
int dword_4A8870; // weak
int dword_4A8874; // weak
float flt_4A8878; // weak
int dword_4A8A6C; // weak

*/