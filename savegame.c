
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "savegame.h"
#include "defs.h"
#include <SDL_stdinc.h>

void *Str; // idb
int savegames_unk_446DC2 =10;

//----- (0043AF70) --------------------------------------------------------
char  decryptByteSavegame(int a1, char a2)
{
	char result; // al@1

	result = *(unsigned char *)a1 << a2;
	*(unsigned char *)a1 = result | (*(unsigned char *)a1 >> (8 - a2));
	return a1;
}

//----- (0043AF90) --------------------------------------------------------
char  encryptByteSavegame(int a1, char a2)
{
	char result; // al@1

	result = *(unsigned char *)a1 >> a2;
	*(unsigned char *)a1 = result | (*(unsigned char *)a1 << (8 - a2));
	return result;
}

//----- (0041C910) --------------------------------------------------------
int  decryptEntireSavegame(int a1, char *Filename)
{
	void *v2 = (void *) malloc(0x883u); // eax@1
	int v3; // edi@1
	FILE *v4; // esi@1
	unsigned int v5; // ebx@1
	int result; // eax@3
	char v7; // [sp+0h] [bp-4h]@1

			 // allocateMemory(0x883u);
	Str = v2;
	memset(v2, 0, 0x880u);
	v3 = (int)((char *)v2 + 2176);
	*(_WORD *)v3 = 0;
	*(BYTE *)(v3 + 2) = 0;
	v4 = fopen(Filename, "rb");
	fread(Str, 0x883u, 1u, v4);
	fclose(v4);
	v7 = *(BYTE *)Str;
	v5 = 1;
	do
	{
		decryptByteSavegame((int)((char *)Str + v5), v5 % 6);
		*((BYTE *)Str + v5) += -17 * v5;
		*((BYTE *)Str + v5++) += v7;
	} while ((signed int)v5 < 2179);
	result = 0;
	//El original copia el nombre a la tabla de ranuras (0x41C9D0), que el prompt de guardar
	//ofrece de nuevo. getSaveGameName pasa 0 porque lee el nombre por su cuenta.
	if (a1)
	{
		do
		{
			*(BYTE *)(result + a1) = *((BYTE *)Str + result + 4);
			++result;
		} while (result < 15);
		*(BYTE *)(a1 + 15) = 0;
		result = 0;
	}
	return result;
}

char* getSaveGameName(int savegame) {
	//El menu de carga pide los nombres en cada dibujado: un buffer fijo por ranura y el
	//savegame descifrado se libera aqui mismo (antes eran 2,2 KB perdidos por llamada).
	static char saveGameNames[10][20];
	char Filename[20];
	char saveNumber[12];
	char *saveGameName;
	void *previousStr;

	if (savegame < 0 || savegame >= 10)
		return NULL;
	saveGameName = saveGameNames[savegame];
	strcpy(Filename, "DR.SG");
	SDL_itoa(savegame, saveNumber, 10);
	strcat(Filename, saveNumber);
	if ((signed int)fileExists(Filename) > 0) {

		previousStr = Str;
		decryptEntireSavegame(0, Filename);

		//El nombre ocupa los bytes 4 a 18; el 19 ya es la primera letra de drivers[0]. Con 16, un
		//nombre de 15 letras mostraba una de mas. El original copia 15 (0x41C9D0).
		memcpy(saveGameName, ((unsigned char *)Str + 4), 15);
		saveGameName[15] = 0;
		free(Str);
		Str = previousStr;

		return saveGameName;
	}
	else {
		return NULL;
	}
}

