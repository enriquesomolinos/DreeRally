
//el tamaño de los corredores es 108

typedef enum
{
	POWERUP_SHOTS = 1,
	POWERUP_TURBO = 2,
	POWERUP_SMALL_MONEY = 3,
	POWERUP_DRUNK = 4,
	POWERUP_SMALL_REPAIR = 5,
	POWERUP_DRUGS = 6,
	POWERUP_BIG_MONEY = 7,
	POWERUP_BIG_REPAIR = 8
	
}PowerUpEnum;

typedef struct Powerup {
	int posX_501BA0;
	int posY_501BA4; 
	int powerUp_ID_501BA8;
	int dword_501BAC;
	//dword_456AC4 - dword_4A9EA4  tiempos para saber cuando ponerlos y quitarlos
	int timeShowed_501BB0;
	int dword_501BB4; //+20  //parece que es el tamañao en el mapa de memoria (en pantalla es 140>>3) del powerup 140 
	int lastPowerUp_ID_501BB8;//+24 usado en las llavas y las dineros que se muestran en pantalla despues de cogerlo y el id se borra
	int repairpercentage_501BBC;//+28
	int screenBackup_501BC0[64];//+32
} Powerup;
///solucionar este! unk_501BD0
/* *(_DWORD *)(v1 + 20) = 140; // + 20 sobre powerups[v1].
                *(_DWORD *)(v1 + 24) = v26; //+24 sobre powerups[v1].
				*(_DWORD *)(v1 + 28) = 20; //+28 sobre powerups[v1].    parece el porcentaje de raparacion

				parece q unk_501BCC es donde estsa el fondo de la imagen
				*/

extern Powerup powerups[16]; //creo que son 20 pero hay qu erevisarlo
