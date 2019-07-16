
#define _CRT_NONSTDC_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS


#pragma warning(push)
#pragma warning(disable: warning-code) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
// deprecated code here
#include <stdio.h>
#pragma warning(pop)

#include "config.h"
#include "defs.h"
#include <string.h>
#include "hof/hallOfFame.h"




MainArgs mainArgs = { 0,1,1,1,1 };

Configuration configuration;


int checkArgs(char * args)
{
	int result = 0;
	
	if (strstr(args, "-nosound"))
		mainArgs.configNoSound = 0;
	if (strstr(args, "-noeffect"))
		mainArgs.configNoSoundEffect = 0;
	if (strstr(args, "-gl"))
		mainArgs.configGL = 0;
	if (strstr(args, "-smooth"))
		mainArgs.configSmooth = 0;
	result = strstr(args, "-window");
	if (result)
		
	return result;

}

char byte_45FB6C; // weak
char byte_45FBF0; // weak
char byte_463D9C; // weak
__int16 word_462D54; // weak





char loadConfig()
{
	FILE *v0; // eax@1
	FILE *v1; // esi@1
	__int32 v2; // ebx@2
	int v3; // eax@3
	int v4; // ebx@3
	FILE *v5; // esi@3
	char DstBuf; // [sp+13h] [bp-1h]@3

	v0=0;
	v0 = fopen("dr.cfg", "rb");
	v1 = v0;
	if (v0 && (fseek(v0, 0, 2), v2 = ftell(v1), fclose(v1), v2 > 7))
	{
		v3 =malloc(0x1388u);
		v4 = v3;
		v5 = fopen("dr.cfg", "rb");
		
		fread(&byte_45FB6C, 1u, 1u, v5);
		fread(&byte_45FBF0, 1u, 1u, v5);
		fread(&byte_463D9C, 1u, 1u, v5);
		fread(&word_462D54, 4u, 1u, v5);
		fread(&DstBuf, 1u, 1u, v5);
		fread((void *)v4, 1u, 0x1388u, v5);
		fclose(v5);
		configuration.musicVolume = *(_DWORD *)v4;
		configuration.effectsVolume = *(_DWORD *)(v4 + 4);
		configuration.dword_4457CC = *(_DWORD *)(v4 + 8);
		configuration.difficulty = *(_DWORD *)(v4 + 12);
		configuration.useJoystick = *(_DWORD *)(v4 + 16);
		configuration.dword_463D00 = *(_DWORD *)(v4 + 20);
		configuration.dword_463D04 = *(_DWORD *)(v4 + 24);
		configuration.dword_463D08 = *(_DWORD *)(v4 + 28);
		configuration.dword_463D0C = *(_DWORD *)(v4 + 32);
		configuration.dword_463D10 = *(_DWORD *)(v4 + 36);
		configuration.byte_463D14 = *(_BYTE *)(v4 + 40);
		configuration.dword_45EB80 = *(_DWORD *)(v4 + 41);
		configuration.dword_45EB84 = *(_DWORD *)(v4 + 45);
		configuration.dword_45EB88 = *(_DWORD *)(v4 + 49);
		configuration.dword_45EB8C = *(_DWORD *)(v4 + 53);
		configuration.dword_45EB90 = *(_DWORD *)(v4 + 57);
		configuration.byte_45EB94 = *(_BYTE *)(v4 + 61);
		configuration.dword_456734 = *(_DWORD *)(v4 + 62);
		configuration.dword_45FB68 = *(_DWORD *)(v4 + 66);
		configuration.dword_45DC40 = *(_DWORD *)(v4 + 70);
		configuration.dword_45DC1C = *(_DWORD *)(v4 + 74);
		configuration.circuitRecords= malloc(0xA20u);
		memcpy(configuration.circuitRecords, (const void *)(v4 + 78), 0xA20u);		
		configuration.hallOfFameEntries = malloc(0xC8u);
		memcpy(configuration.hallOfFameEntries, (const void *)(v4 + 2670), 0xC8u);
		configuration.accelerateKey = *(_DWORD *)(v4 + 2870);
		configuration.brakeKey = *(_DWORD *)(v4 + 2874);
		configuration.leftSteeringKey = *(_DWORD *)(v4 + 2878);
		configuration.rightSteeringKey = *(_DWORD *)(v4 + 2882);
		configuration.turboKey = *(_DWORD *)(v4 + 2886);
		configuration.gunKey = *(_DWORD *)(v4 + 2890);
		configuration.mineKey = *(_DWORD *)(v4 + 2894);
		configuration.hornKey = *(_DWORD *)(v4 + 2898);
		configuration.accelerateGamepad = *(_DWORD *)(v4 + 2902);
		configuration.brakeGamepad = *(_DWORD *)(v4 + 2906);
		configuration.leftSteeringGamepad = *(_DWORD *)(v4 + 2910);
		configuration.rightSteeringGamepad= *(_DWORD *)(v4 + 2914);
		configuration.turboGamepad = *(_DWORD *)(v4 + 2918);
		configuration.gunGamepad = *(_DWORD *)(v4 + 2922);
		configuration.mineGamepad = *(_DWORD *)(v4 + 2926);
		configuration.timesPlayed= *(_DWORD *)(v4 + 2930);
		switch (configuration.dword_4457CC)
		{
		case 0:
			configuration.dword_45FB68 = 0;
			configuration.dword_45DC40 = 1016;
			configuration.dword_45DC1C = 4;
			break;
		case 1:
			configuration.dword_45FB68 = 1;
			configuration.dword_45DC40 = 760;
			configuration.dword_45DC1C = 3;
			break;
		case 2:
			configuration.dword_45FB68 = 2;
			configuration.dword_45DC40 = 1000;
			configuration.dword_45DC1C = 4;
			break;
		case 3:
			configuration.dword_45FB68 = 3;
			configuration.dword_45DC40 = 744;
			configuration.dword_45DC1C = 3;
			break;
		default:
			return 0;
		}
	}
	else
	{
		defaultConfig();
	}
	return 0;
}


//----- (004264E0) --------------------------------------------------------
int saveConfiguration()
{
	unsigned __int8 v0; // bl@1
	int v1 = 0; // eax@1
	const void *v2; // ebp@1
	int v3; // edx@1
	int v4; // edx@1
	FILE *v5; // esi@1

	v0 = rand();
	//allocateMemory(0x1388u);
	v1=malloc( 0x1388u);
	v2 = (const void *)v1;
	*(_DWORD *)v1 = configuration.musicVolume;
	*(_DWORD *)(v1 + 4) = configuration.effectsVolume;
	*(_DWORD *)(v1 + 8) = configuration.dword_4457CC;
	*(_DWORD *)(v1 + 12) = configuration.difficulty;
	*(_DWORD *)(v1 + 16) = configuration.useJoystick;
	v3 = v1 + 20;
	*(_DWORD *)v3 = configuration.dword_463D00;
	*(_DWORD *)(v3 + 4) = configuration.dword_463D04;
	*(_DWORD *)(v3 + 8) = configuration.dword_463D08;
	*(_DWORD *)(v3 + 12) = configuration.dword_463D0C;
	*(_DWORD *)(v3 + 16) = configuration.dword_463D10;
	*(_BYTE *)(v3 + 20) = configuration.byte_463D14;
	v4 = v1 + 41;
	*(_DWORD *)v4 = configuration.dword_45EB80;
	*(_DWORD *)(v4 + 4) = configuration.dword_45EB84;
	*(_DWORD *)(v4 + 8) = configuration.dword_45EB88;
	*(_DWORD *)(v4 + 12) = configuration.dword_45EB8C;
	*(_DWORD *)(v4 + 16) = configuration.dword_45EB90;
	*(_BYTE *)(v4 + 20) = configuration.byte_45EB94;
	*(_DWORD *)(v1 + 62) = configuration.dword_456734;
	*(_DWORD *)(v1 + 66) = configuration.dword_45FB68;
	*(_DWORD *)(v1 + 70) = configuration.dword_45DC40;
	*(_DWORD *)(v1 + 74) = configuration.dword_45DC1C;
	memcpy((void *)(v1 + 78), configuration.circuitRecords, 0xA20u);
	memcpy((void *)(v1 + 2670), configuration.hallOfFameEntries, 0xC8u);
	*(_DWORD *)(v1 + 2870) = configuration.accelerateKey;
	*(_DWORD *)(v1 + 2874) = configuration.brakeKey;
	*(_DWORD *)(v1 + 2878) = configuration.leftSteeringKey;
	*(_DWORD *)(v1 + 2882) = configuration.rightSteeringKey;
	*(_DWORD *)(v1 + 2886) = configuration.turboKey;
	*(_DWORD *)(v1 + 2890) = configuration.gunKey;
	*(_DWORD *)(v1 + 2894) = configuration.mineKey;
	*(_DWORD *)(v1 + 2898) = configuration.hornKey;
	*(_DWORD *)(v1 + 2902) = configuration.accelerateGamepad;
	*(_DWORD *)(v1 + 2906) = configuration.brakeGamepad;
	*(_DWORD *)(v1 + 2910) = configuration.leftSteeringGamepad;
	*(_DWORD *)(v1 + 2914) = configuration.rightSteeringGamepad;
	*(_DWORD *)(v1 + 2918) = configuration.turboGamepad;
	*(_DWORD *)(v1 + 2922) = configuration.gunGamepad;
	*(_DWORD *)(v1 + 2926) = configuration.mineGamepad;
	*(_DWORD *)(v1 + 2930) = configuration.timesPlayed;
	v5 = fopen("dr.cfg", "wb");
	fwrite(&byte_45FB6C, 1u, 1u, v5);
	fwrite(&byte_45FBF0, 1u, 1u, v5);
	fwrite(&byte_463D9C, 1u, 1u, v5);
	fwrite(&word_462D54, 4u, 1u, v5);
	fputc(v0, v5);
	fwrite(v2, 0xB76u, 1u, v5);
	return fclose(v5);
}

void *dword_45FA70; // idb

//esto son records
/*int dword_45F050; // idb
int dword_45F054; // idb


int dword_45F714; // weak
int dword_45F740; // weak
int dword_45F594; // weak
int dword_45F75C; // weak
int dword_45F8C0; // weak
int dword_45F8C4; // weak
int dword_45F710; // weak
int dword_45F560; // weak
int dword_45F564; // weak
int dword_45F3B0; // weak
int dword_45F3B4; // weak
int dword_45F200; // weak
int dword_45F204; // weak

int dword_45F8D8; // weak
int dword_45F8DC; // weak
int dword_45F728; // weak
int dword_45F72C; // weak
int dword_45F578; // weak
int dword_45F57C; // weak
int dword_45F3C8; // weak
int dword_45F3CC; // weak
int dword_45F218; // weak
int dword_45F21C; // weak
int dword_45F068; // weak
int dword_45F06C; // weak
int dword_45F8F0; // weak
int dword_45F8F4; // weak
int dword_45F744; // weak
int dword_45F590; // weak
int dword_45F3E0; // weak
int dword_45F3E4; // weak
int dword_45F230; // weak
int dword_45F234; // weak
int dword_45F080; // weak
int dword_45F084; // weak
int dword_45F908; // weak
int dword_45F90C; // weak
int dword_45F758; // weak
int dword_45F5A8; // weak
int dword_45F5AC; // weak
int dword_45F3F8; // weak
int dword_45F3FC; // weak
int dword_45F248; // weak
int dword_45F24C; // weak
int dword_45F098; // weak
int dword_45F09C; // weak
int dword_45F920; // weak
int dword_45F924; // weak
int dword_45F770; // weak
int dword_45F774; // weak
int dword_45F5C0; // weak
int dword_45F5C4; // weak
int dword_45F410; // weak
int dword_45F414; // weak
int dword_45F260; // weak
int dword_45F264; // weak
int dword_45F0B0; // weak
int dword_45F0B4; // weak
int dword_45F938; // weak
int dword_45F93C; // weak
int dword_45F788; // weak
int dword_45F78C; // weak
int dword_45F5D8; // weak
int dword_45F5DC; // weak
int dword_45F428; // weak
int dword_45F42C; // weak
int dword_45F278; // weak
int dword_45F27C; // weak
int dword_45F0C8; // weak
int dword_45F0CC; // weak
int dword_45F950; // weak
int dword_45F954; // weak
int dword_45F7A0; // weak
int dword_45F7A4; // weak
int dword_45F5F0; // weak
int dword_45F5F4; // weak
int dword_45F440; // weak
int dword_45F444; // weak
int dword_45F290; // weak
int dword_45F294; // weak
int dword_45F0E0; // weak
int dword_45F0E4; // weak
int dword_45F968; // weak
int dword_45F96C; // weak
int dword_45F7B8; // weak
int dword_45F7BC; // weak
int dword_45F608; // weak
int dword_45F60C; // weak
int dword_45F458; // weak
int dword_45F45C; // weak
int dword_45F2A8; // weak
int dword_45F2AC; // weak
int dword_45F0F8; // weak
int dword_45F0FC; // weak
int dword_45F980; // weak
int dword_45F984; // weak
int dword_45F7D0; // weak
int dword_45F7D4; // weak
int dword_45F620; // weak
int dword_45F624; // weak
int dword_45F470; // weak
int dword_45F474; // weak

int dword_45F2C0; // weak
int dword_45F2C4; // weak
int dword_45F110; // weak
int dword_45F114; // weak
int dword_45F998; // weak
int dword_45F99C; // weak
int dword_45F7E8; // weak
int dword_45F7EC; // weak
int dword_45F638; // weak
int dword_45F63C; // weak
int dword_45F488; // weak
int dword_45F48C; // weak
int dword_45F2D8; // weak
int dword_45F2DC; // weak
int dword_45F128; // weak
int dword_45F12C; // weak
int dword_45F9B0; // weak
int dword_45F9B4; // weak
int dword_45F800; // weak
int dword_45F804; // weak
int dword_45F650; // weak
int dword_45F654; // weak
int dword_45F4A0; // weak
int dword_45F4A4; // weak
int dword_45F2F0; // weak
int dword_45F2F4; // weak
int dword_45F140; // weak
int dword_45F144; // weak
int dword_45F9C8; // weak
int dword_45F9CC; // weak
int dword_45F818; // weak
int dword_45F81C; // weak
int dword_45F668; // weak
int dword_45F66C; // weak
int dword_45F4B8; // weak
int dword_45F4BC; // weak
int dword_45F308; // weak
int dword_45F30C; // weak
int dword_45F158; // weak
int dword_45F15C; // weak
int dword_45F9E0; // weak
int dword_45F9E4; // weak
int dword_45F830; // weak
int dword_45F834; // weak
int dword_45F680; // weak
int dword_45F684; // weak
int dword_45F4D0; // weak
int dword_45F4D4; // weak
int dword_45F320; // weak
int dword_45F324; // weak
int dword_45F170; // weak
int dword_45F1A0; // weak

int dword_45F6C8; // weak
int dword_45F8A8; // weak
int dword_45F6F8; // weak
int dword_45F1EC; // weak

int dword_45F698; // weak
int dword_45F860; // weak
int dword_45F6B0; // weak
int dword_45F504; // weak
int dword_45F878; // weak
int dword_45F518; // weak
int dword_45F51C; // weak
int dword_45F368; // weak
int dword_45F530; // weak
int dword_45F174; // weak
int dword_45F9F8; // weak
int dword_45F9FC; // weak
int dword_45F848; // weak
int dword_45F84C; // weak
int dword_45F69C; // weak
int dword_45F4E8; // weak
int dword_45F4EC; // weak
int dword_45F338; // weak
int dword_45F33C; // weak
int dword_45F188; // weak
int dword_45F18C; // weak

int dword_45FA10; // weak
int dword_45FA14; // weak
int dword_45F864; // weak
int dword_45F6B4; // weak
int dword_45F500; // weak
int dword_45F350; // weak
int dword_45F354; // weak
int dword_45F1A4; // weak
int dword_45FA28; // weak
int dword_45FA2C; // weak
int dword_45F87C; // weak
int dword_45F6CC; // weak
int dword_45F36C; // weak
int dword_45F1B8; // weak
int dword_45F1BC; // weak
int dword_45FA40; // weak
int dword_45FA44; // weak
int dword_45F890; // weak
int dword_45F894; // weak
int dword_45F6E0; // weak
int dword_45F6E4; // weak
int dword_45F534; // weak
int dword_45F380; // weak
int dword_45F384; // weak
int dword_45F1D0; // weak
int dword_45F1D4; // weak
int dword_45FA58; // weak
int dword_45FA5C; // weak
int dword_45F8AC; // weak
int dword_45F6FC; // weak
int dword_45F548; // weak
int dword_45F54C; // weak
int dword_45F398; // weak
int dword_45F39C; // weak
int dword_45F1E8; // weak*/

//todo esto es hall of fame
/*int dword_461F24; // weak
__int16 word_461F28; // weak
char byte_461F2A; // weak
int dword_461F34; // weak
int dword_461F38; // weak
__int16 word_461F3C; // weak
char byte_461F3E; // weak
int dword_461F48; // weak
int dword_461F4C; // weak
__int16 word_461F50; // weak
char byte_461F52; // weak
int dword_461F5C; // weak
int dword_461F60; // weak
__int16 word_461F64; // weak
int dword_461F68; // weak
char byte_461F66; // weak
int dword_461F70; // weak
int dword_461F74; // weak
__int16 word_461F78; // weak
char byte_461F7A; // weak
int dword_461F84; // weak
int dword_461F88; // weak
__int16 word_461F8C; // weak
char byte_461F8E; // weak
int dword_461F98; // weak
int dword_461F9C; // weak
__int16 word_461FA0; // weak
char byte_461FA2; // weak
int dword_461FAC; // weak
int dword_461FB0; // weak
__int16 word_461FB4; // weak
char byte_461FB6; // weak
int dword_461F40; // weak
int dword_461F2C[256]; // weak
int dword_461F54; // weak
int dword_461F7C; // weak
int dword_461F90; // weak
int dword_461FA4; // weak
int dword_461FB8; // weak
int dword_461FC0; // weak
int dword_461FC4; // weak
__int16 word_461FC8; // weak
char byte_461FCA; // weak
int dword_461FD4; // weak
int dword_461FD8; // weak
int dword_461FCC; // weak
__int16 word_461FDC; // weak
char byte_461FDE; // weak
int dword_461FE0; // weak
int dword_461F30[256]; //weak
int dword_461F44; // weak
int dword_461F58; // weak
int dword_461F6C; // weak
int dword_461F80; // weak
int dword_461F94; // weak
int dword_461FA8; // weak
int dword_461FBC; // weak
int dword_461FD0; // weak
int dword_461FE4; // weak*/









int defaultConfig()
{
	//seteados por mi
	configuration.dword_4457CC = 0; // weak
	configuration.defaultAccelerateGamepad = '\x05'; // weak
	configuration.defaultBrakeGamepad = '\x04'; // weak
	configuration.defaultLeftSteeringGamepad = '\x01'; // weak
	configuration.defaultRightSteeringGamepad = '\x02'; // weak
	configuration.defaultTurboGamepad = '\x06'; // weak
	configuration.defaultGunGamepad = '\a'; // weak
	configuration.defaultMineGamepad = '\b'; // weak
//	signed int v0; // esi@1
//	signed int v1; // edi@2
//	int v2; // eax@3

	configuration.musicVolume = 0x8000;
	configuration.effectsVolume = 49152;
	configuration.dword_45FB68 = 0;
	configuration.dword_45DC40 = 1016;
	configuration.dword_45DC1C = 4;
	configuration.difficulty = 1;
	configuration.useJoystick = 0;
	configuration.dword_456734 = 1;
	configuration.timesPlayed = 0;
	LOBYTE(configuration.dword_463D00) = 0;
	configuration.dword_45EB80 = 8025185; //atz
	configuration.circuitRecords = getDefaulRecords();
	//todo esto son circuit records.
	/*v0 = (signed int)&dword_45F050;
	do
	{
		v1 = 18;
		do
		{
			v2 = v0 - 16;
			*(_DWORD *)v2 = 1701668178; //-> esto es remedy
			*(_WORD *)(v2 + 4) = 31076;
			*(_DWORD *)(v0 + 4) = 0;
			*(_DWORD *)v0 = 0;
			*(_DWORD *)(v0 - 4) = 0;
			v0 += 24;
			--v1;
			*(_BYTE *)(v2 + 6) = 0;
		} while (v1);
	} while (v0 < (signed int)&dword_45FA70);
	dword_45F714 = 22;
	dword_45F740 = 22;
	dword_45F594 = 2;
	dword_45F75C = 2;
	dword_45F8C0 = 11;
	dword_45F8C4 = 36;
	dword_45F710 = 13;
	dword_45F560 = 13;
	dword_45F564 = 89;
	dword_45F3B0 = 14;
	dword_45F3B4 = 13;
	dword_45F200 = 14;
	dword_45F204 = 49;
	dword_45F050 = 15;
	dword_45F054 = 55;
	dword_45F8D8 = 13;
	dword_45F8DC = 36;
	dword_45F728 = 14;
	dword_45F72C = 51;
	dword_45F578 = 15;
	dword_45F57C = 52;
	dword_45F3C8 = 16;
	dword_45F3CC = 23;
	dword_45F218 = 17;
	dword_45F21C = 8;
	dword_45F068 = 18;
	dword_45F06C = 16;
	dword_45F8F0 = 20;
	dword_45F8F4 = 38;
	dword_45F744 = 15;
	dword_45F590 = 24;
	dword_45F3E0 = 24;
	dword_45F3E4 = 58;
	dword_45F230 = 25;
	dword_45F234 = 85;
	dword_45F080 = 27;
	dword_45F084 = 89;
	dword_45F908 = 10;
	dword_45F90C = 42;
	dword_45F758 = 11;
	dword_45F5A8 = 11;
	dword_45F5AC = 88;
	dword_45F3F8 = 11;
	dword_45F3FC = 95;
	dword_45F248 = 12;
	dword_45F24C = 21;
	dword_45F098 = 12;
	dword_45F09C = 83;
	dword_45F920 = 19;
	dword_45F924 = 91;
	dword_45F770 = 21;
	dword_45F774 = 80;
	dword_45F5C0 = 24;
	dword_45F5C4 = 82;
	dword_45F410 = 25;
	dword_45F414 = 55;
	dword_45F260 = 26;
	dword_45F264 = 42;
	dword_45F0B0 = 26;
	dword_45F0B4 = 79;
	dword_45F938 = 9;
	dword_45F93C = 66;
	dword_45F788 = 10;
	dword_45F78C = 96;
	dword_45F5D8 = 11;
	dword_45F5DC = 66;
	dword_45F428 = 12;
	dword_45F42C = 1;
	dword_45F278 = 12;
	dword_45F27C = 81;
	dword_45F0C8 = 13;
	dword_45F0CC = 42;
	dword_45F950 = 10;
	dword_45F954 = 86;
	dword_45F7A0 = 12;
	dword_45F7A4 = 5;
	dword_45F5F0 = 13;
	dword_45F5F4 = 12;
	dword_45F440 = 14;
	dword_45F444 = 0;
	dword_45F290 = 14;
	dword_45F294 = 89;
	dword_45F0E0 = 15;
	dword_45F0E4 = 90;
	dword_45F968 = 19;
	dword_45F96C = 58;
	dword_45F7B8 = 21;
	dword_45F7BC = 30;
	dword_45F608 = 22;
	dword_45F60C = 78;
	dword_45F458 = 24;
	dword_45F45C = 50;
	dword_45F2A8 = 26;
	dword_45F2AC = 96;
	dword_45F0F8 = 27;
	dword_45F0FC = 80;
	dword_45F980 = 13;
	dword_45F984 = 1;
	dword_45F7D0 = 13;
	dword_45F7D4 = 85;
	dword_45F620 = 14;
	dword_45F624 = 15;
	dword_45F470 = 15;
	dword_45F474 = 62;
	dword_45F2C0 = 16;
	dword_45F2C4 = 72;
	dword_45F110 = 17;
	dword_45F114 = 57;
	dword_45F998 = 11;
	dword_45F99C = 48;
	dword_45F7E8 = 13;
	dword_45F7EC = 14;
	dword_45F638 = 13;
	dword_45F63C = 76;
	dword_45F488 = 14;
	dword_45F48C = 1;
	dword_45F2D8 = 14;
	dword_45F2DC = 63;
	dword_45F128 = 15;
	dword_45F12C = 42;
	dword_45F9B0 = 13;
	dword_45F9B4 = 31;
	dword_45F800 = 14;
	dword_45F804 = 52;
	dword_45F650 = 15;
	dword_45F654 = 62;
	dword_45F4A0 = 16;
	dword_45F4A4 = 11;
	dword_45F2F0 = 16;
	dword_45F2F4 = 98;
	dword_45F140 = 18;
	dword_45F144 = 0;
	dword_45F9C8 = 20;
	dword_45F9CC = 25;
	dword_45F818 = 21;
	dword_45F81C = 91;
	dword_45F668 = 23;
	dword_45F66C = 76;
	dword_45F4B8 = 24;
	dword_45F4BC = 22;
	dword_45F308 = 25;
	dword_45F30C = 63;
	dword_45F158 = 27;
	dword_45F15C = 49;
	dword_45F9E0 = 10;
	dword_45F9E4 = 31;
	dword_45F830 = 11;
	dword_45F834 = 14;
	dword_45F680 = 11;
	dword_45F684 = 71;
	dword_45F4D0 = 11;
	dword_45F4D4 = 98;
	dword_45F320 = 12;
	dword_45F324 = 11;
	dword_45F170 = 12;
	dword_45F1A0 = 13;
	dword_45F6C8 = 13;
	dword_45F8A8 = 13;
	dword_45F6F8 = 13;
	dword_45F1EC = 42;
	dword_45F698 = 24;
	dword_45F860 = 11;
	dword_45F6B0 = 11;
	dword_45F504 = 24;
	dword_45F878 = 11;
	dword_45F518 = 14;
	dword_45F51C = 24;
	dword_45F368 = 14;
	dword_45F530 = 24;
	dword_45F174 = 68;
	dword_45F9F8 = 19;
	dword_45F9FC = 69;
	dword_45F848 = 21;
	dword_45F84C = 91;
	dword_45F69C = 96;
	dword_45F4E8 = 25;
	dword_45F4EC = 61;
	dword_45F338 = 26;
	dword_45F33C = 37;
	dword_45F188 = 26;
	dword_45F18C = 82;
	dword_45FA10 = 9;
	dword_45FA14 = 81;
	dword_45F864 = 8;
	dword_45F6B4 = 71;
	dword_45F500 = 12;
	dword_45F350 = 12;
	dword_45F354 = 62;
	dword_45F1A4 = 36;
	dword_45FA28 = 10;
	dword_45FA2C = 78;
	dword_45F87C = 85;
	dword_45F6CC = 1;
	dword_45F36C = 67;
	dword_45F1B8 = 16;
	dword_45F1BC = 8;
	dword_45FA40 = 19;
	dword_45FA44 = 47;
	dword_45F890 = 21;
	dword_45F894 = 33;
	dword_45F6E0 = 22;
	dword_45F6E4 = 57;
	dword_45F534 = 62;
	dword_45F380 = 26;
	dword_45F384 = 82;
	dword_45F1D0 = 27;
	dword_45F1D4 = 98;
	dword_45FA58 = 12;
	dword_45FA5C = 94;
	dword_45F8AC = 79;
	dword_45F6FC = 98;
	dword_45F548 = 15;
	dword_45F54C = 45;
	dword_45F398 = 16;
	dword_45F39C = 86;
	dword_45F1E8 = 17;*/
	configuration.turboKey = 42;
	configuration.accelerateGamepad = (unsigned __int8)configuration.defaultAccelerateGamepad;
	configuration.brakeGamepad = (unsigned __int8)configuration.defaultBrakeGamepad;
	configuration.leftSteeringGamepad = (unsigned __int8)configuration.defaultLeftSteeringGamepad;
	
	configuration.accelerateKey = 30;
	configuration.brakeKey = 44;
	configuration.leftSteeringKey = 203;
	configuration.rightSteeringKey = 205;
	configuration.gunKey = 29;
	configuration.mineKey = 56;
	configuration.hornKey = 57;
	configuration.rightSteeringGamepad = (unsigned __int8)configuration.defaultRightSteeringGamepad;
	configuration.turboGamepad = (unsigned __int8)configuration.defaultTurboGamepad;
	configuration.gunGamepad = (unsigned __int8)configuration.defaultGunGamepad;
	configuration.mineGamepad = (unsigned __int8)configuration.defaultMineGamepad;
	configuration.hallOfFameEntries = getDefaultHallOfFame();
	/*configuration.dword_461F20[0] = 541933907; //estas tres lineas son sam speed y asi los nombres
	dword_461F24 = 1162170451;
	word_461F28 = 8260;
	byte_461F2A = 0;
	dword_461F34 = 1162756426;
	dword_461F38 = 1313818656;
	word_461F3C = 16708;
	byte_461F3E = 0;
	dword_461F48 = 1162564932;
	dword_461F4C = 1263881760;
	word_461F50 = 19781;
	byte_461F52 = 0;
	dword_461F5C = 1414742350;
	dword_461F60 = 1229856857;
	word_461F64 = 19267;
	dword_461F68 = 98;
	byte_461F66 = 0;
	dword_461F70 = 1330925389;
	dword_461F74 = 1095573586;
	word_461F78 = 22866;
	byte_461F7A = 0;
	dword_461F84 = 541344077;
	dword_461F88 = 541278541;
	word_461F8C = 8224;
	byte_461F8E = 0;
	dword_461F98 = 1414807885;
	dword_461F9C = 1279872288;
	word_461FA0 = 21061;
	byte_461FA2 = 0;
	dword_461FAC = 1313426499;
	dword_461FB0 = 1163337812;
	word_461FB4 = 21587;
	byte_461FB6 = 0;
	dword_461F2C[0] = 50;
	dword_461F40 = 66;
	dword_461F54 = 82;
	dword_461F7C = 114;
	dword_461F90 = 130;
	dword_461FA4 = 146;
	dword_461FB8 = 162;
	dword_461FC0 = 541410636;
	dword_461FC4 = 1162037590;
	word_461FC8 = 8224;
	byte_461FCA = 0;
	dword_461FD4 = 1263681860;
	dword_461FD8 = 1146704416;
	dword_461FCC = 178;
	word_461FDC = 21061;
	byte_461FDE = 0;
	dword_461FE0 = 194;
	dword_461F30[0] = 1;
	dword_461F44 = 1;
	dword_461F58 = 1;
	dword_461F6C = 1;
	dword_461F80 = 1;
	dword_461F94 = 1;
	dword_461FA8 = 1;
	dword_461FBC = 1;
	dword_461FD0 = 1;
	dword_461FE4 = 1;*/
	return saveConfiguration();
}