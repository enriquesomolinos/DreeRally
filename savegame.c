
#define _CRT_NONSTDC_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#pragma warning ( disable: 4146  4700 4703 4005)

#pragma warning(push)
#pragma warning(disable: warning-code) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
// deprecated code here
#include <stdio.h>
#pragma warning(pop)
#include "savegame.h"
#include "defs.h"
#include <windows.h>

void *Str; // idb
int savegames_unk_446DC2 =10;

//----- (0043AF70) --------------------------------------------------------
char  decryptByteSavegame(int a1, char a2)
{
	char result; // al@1

	result = *(byte *)a1 << a2;
	*(byte *)a1 = result | (*(byte *)a1 >> (8 - a2));
	return a1;
}

//----- (0043AF90) --------------------------------------------------------
char  encryptByteSavegame(int a1, char a2)
{
	char result; // al@1

	result = *(byte *)a1 >> a2;
	*(byte *)a1 = result | (*(byte *)a1 << (8 - a2));
	return result;
}

//----- (0041C910) --------------------------------------------------------
int  decryptEntireSavegame(int a1, char *Filename)
{
	void *v2 = malloc(0x883u); // eax@1
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
	*(byte *)(v3 + 2) = 0;
	v4 = fopen(Filename, "rb");
	fread(Str, 0x883u, 1u, v4);
	fclose(v4);
	v7 = *(byte *)Str;
	v5 = 1;
	do
	{
		decryptByteSavegame((int)((char *)Str + v5), v5 % 6);
		*((byte *)Str + v5) += -17 * v5;
		*((byte *)Str + v5++) += v7;
	} while ((signed int)v5 < 2179);
	result = 0;
	/*do
	{
		*(BYTE *)(result + a1) = *((BYTE *)Str + result + 4);
		++result;
	} while (result < 15);*/
	return result;
}

char* getSaveGameName(int savegame) {
	char Filename[20];
	char *saveNumber = malloc(1);
	FILE * fp;
	char *saveGameName= malloc(20);
	
	strcpy(Filename, "DR.SG");
	itoa(savegame, saveNumber, 10);
	strcat(Filename, saveNumber);
	if ((signed int)fileExists(Filename) > 0) {
		
		decryptEntireSavegame(0, Filename);

		memcpy(saveGameName, ((byte *)Str + 4), 16);
		
		return saveGameName;
	}
	else {
		return NULL;
	}
}

