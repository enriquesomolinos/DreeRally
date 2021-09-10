#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

typedef struct Pedestrian {
	int positionX; // weak   479AA4
	int positionY; // weak 479AA8
	int pedestrianId; // weak 479AAC +8
	int rotation; // weak 479AB0 +12
	int byte5; // weak 479AB4 +16  frame 
	int isDied; // weak 479AB8 +20
	int byte7; // weak 479ABC +24 parece algo de tiempo
	int byte8; // weak 479AC0 +28 framedirection para que tenga mas sensacion de movimiento

	} Pedestrian;

extern Pedestrian pedestrian_479AA4[20];

char   drawPedestrian_43AF30(int screenOffset, int pedestrianbpkOffset, int sizeToPaint);
char drawShotPedestrian_4111F0();

#endif