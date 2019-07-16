#include "drivers.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "dr.h"
#include "cars.h"


 Driver drivers[20];
 int driverId; // weak


 char driverNames[20][20] = { "SAM SPEED",
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

//----- (00428930) --------------------------------------------------------
int initDrivers()
{
	_UNKNOWN loc_43414A; // weak

	//TODO aqui hay que acoquinar todos los bucles porque se esta haciendo mal!

//  signed int v0; // eax@1
//  signed int v1; // esi@3
//  int v2; // eax@3
//  int v3; // edi@3
//  int v4; // edi@5
//  signed int v5; // esi@5
  int v6; // eax@6
  signed int v7; // ST10_4@6
  int v8; // eax@6
  int v9; // ecx@6
  signed int v10; // ST10_4@6
  int v11; // edx@6
  signed int v12; // ST10_4@6
  int v13; // eax@6
  int v14; // ecx@6
//  char *v15; // edi@10
//  int v16; // edx@10
//  char v17; // al@11
//  int v18; // ecx@13
///  int v19; // eax@13
  int result; // eax@13
  int v21; // [sp+10h] [bp-F8h]@6
//  signed int v22; // [sp+14h] [bp-F4h]@3
  int v23; // [sp+18h] [bp-F0h]@1
  int v24; // [sp+1Ch] [bp-ECh]@1
  __int16 v25; // [sp+20h] [bp-E8h]@1
  char v26; // [sp+22h] [bp-E6h]@1
  int v27; // [sp+23h] [bp-E5h]@1
  int v28; // [sp+27h] [bp-E1h]@1
  __int16 v29; // [sp+2Bh] [bp-DDh]@1
  char v30; // [sp+2Dh] [bp-DBh]@1
  int v31; // [sp+2Eh] [bp-DAh]@1
  int v32; // [sp+32h] [bp-D6h]@1
  __int16 v33; // [sp+36h] [bp-D2h]@1
  char v34; // [sp+38h] [bp-D0h]@1
  int v35; // [sp+39h] [bp-CFh]@1
  int v36; // [sp+3Dh] [bp-CBh]@1
  __int16 v37; // [sp+41h] [bp-C7h]@1
  char v38; // [sp+43h] [bp-C5h]@1
  int v39; // [sp+44h] [bp-C4h]@1
  int v40; // [sp+48h] [bp-C0h]@1
  __int16 v41; // [sp+4Ch] [bp-BCh]@1
  char v42; // [sp+4Eh] [bp-BAh]@1
  int v43; // [sp+4Fh] [bp-B9h]@1
  int v44; // [sp+53h] [bp-B5h]@1
  __int16 v45; // [sp+57h] [bp-B1h]@1
  char v46; // [sp+59h] [bp-AFh]@1
  int v47; // [sp+5Ah] [bp-AEh]@1
  int v48; // [sp+5Eh] [bp-AAh]@1
  __int16 v49; // [sp+62h] [bp-A6h]@1
  char v50; // [sp+64h] [bp-A4h]@1
  int v51; // [sp+65h] [bp-A3h]@1
  int v52; // [sp+69h] [bp-9Fh]@1
  __int16 v53; // [sp+6Dh] [bp-9Bh]@1
  char v54; // [sp+6Fh] [bp-99h]@1
  int v55; // [sp+70h] [bp-98h]@1
  int v56; // [sp+74h] [bp-94h]@1
  char v57; // [sp+78h] [bp-90h]@1
  __int16 v58; // [sp+79h] [bp-8Fh]@1
  int v59; // [sp+7Bh] [bp-8Dh]@1
  int v60; // [sp+7Fh] [bp-89h]@1
  __int16 v61; // [sp+83h] [bp-85h]@1
  char v62; // [sp+85h] [bp-83h]@1
  int v63; // [sp+86h] [bp-82h]@1
  int v64; // [sp+8Ah] [bp-7Eh]@1
  __int16 v65; // [sp+8Eh] [bp-7Ah]@1
  char v66; // [sp+90h] [bp-78h]@1
  int v67; // [sp+91h] [bp-77h]@1
  int v68; // [sp+95h] [bp-73h]@1
  __int16 v69; // [sp+99h] [bp-6Fh]@1
  char v70; // [sp+9Bh] [bp-6Dh]@1
  int v71; // [sp+9Ch] [bp-6Ch]@1
  int v72; // [sp+A0h] [bp-68h]@1
  __int16 v73; // [sp+A4h] [bp-64h]@1
  char v74; // [sp+A6h] [bp-62h]@1
  int v75; // [sp+A7h] [bp-61h]@1
  int v76; // [sp+ABh] [bp-5Dh]@1
  __int16 v77; // [sp+AFh] [bp-59h]@1
  char v78; // [sp+B1h] [bp-57h]@1
  int v79; // [sp+B2h] [bp-56h]@1
  int v80; // [sp+B6h] [bp-52h]@1
  __int16 v81; // [sp+BAh] [bp-4Eh]@1
  char v82; // [sp+BCh] [bp-4Ch]@1
  int v83; // [sp+BDh] [bp-4Bh]@1
  int v84; // [sp+C1h] [bp-47h]@1
  __int16 v85; // [sp+C5h] [bp-43h]@1
  char v86; // [sp+C7h] [bp-41h]@1
  int v87; // [sp+C8h] [bp-40h]@1
  int v88; // [sp+CCh] [bp-3Ch]@1
  char v89; // [sp+D0h] [bp-38h]@1
  __int16 v90; // [sp+D1h] [bp-37h]@1
  int v91; // [sp+D3h] [bp-35h]@1
  int v92; // [sp+D7h] [bp-31h]@1
  __int16 v93; // [sp+DBh] [bp-2Dh]@1
  char v94; // [sp+DDh] [bp-2Bh]@1
  int v95; // [sp+DEh] [bp-2Ah]@1
  int v96; // [sp+E2h] [bp-26h]@1
  __int16 v97; // [sp+E6h] [bp-22h]@1
  char v98; // [sp+E8h] [bp-20h]@1
  int v99; // [sp+E9h] [bp-1Fh]@1
  int v100; // [sp+EDh] [bp-1Bh]@1
  __int16 v101; // [sp+F1h] [bp-17h]@1
  char v102; // [sp+F3h] [bp-15h]@1
  int v103; // [sp+F4h] [bp-14h]@1
  int v104; // [sp+F8h] [bp-10h]@1
  int v105; // [sp+FCh] [bp-Ch]@1
  int v106; // [sp+100h] [bp-8h]@1
  int v107; // [sp+104h] [bp-4h]@1
  int index = 0;
   int offset = 0;
  v23 = 541933907; //SAM
  v27 = 1162756426; //JANE
  v24 = 1162170451; //SPEED
  v25 = 68;
  v30 = 0;
  v28 = 1313818656;
  v29 = 16708;
  v33 = 19781;
  v31 = 1162564932;
  v32 = 1263881760;
  v36 = 1229856857;
  v34 = 0;
  v35 = 1414742350;
  v39 = 1330925389;
  v37 = 19267;
  v38 = 0;
  v42 = 0;
  v40 = 1095573586;
  v41 = 22866;
  v45 = 0;
  v43 = 541344077;
  v44 = (int)((char *)&loc_43414A + 3);
  v46 = 0;
  v47 = 1414807885;
  v48 = 1279872288;
  v49 = 21061;
  v50 = 0;
  v51 = 1313426499;
  v52 = 1163337812;
  v53 = 21587;
  v54 = 0;
  v55 = 541410636;
  v56 = 1162037590;
  v57 = 0;
  v59 = 1263681860;
  v26 = 0;
  v58 = 0;
  v60 = 1146704416;
  v61 = 21061;
  v62 = 0;
  v65 = 75;
  v69 = 19267;
  v72 = 1213155872;
  v63 = 1195725383;
  v64 = 1128615968;
  v76 = 1413567264;
  v67 = 1499092307;
  v68 = 1330926368;
  v80 = 1330926368;
  v70 = 0;
  v71 = 1313821257;
  v83 = 1397049668;
  v73 = 78;
  v75 = 1230131021;
  v86 = 0;
  v77 = 79;
  v79 = 1380272195;
  v89 = 0;
  v81 = 17742;
  v82 = 0;
  v93 = 78;
  v84 = 1243630661;
  v85 = 17743;
  v97 = 19532;
  v87 = 541280589;
  v88 = 1380532548;
  v100 = 1411404357;
  v91 = 542787916;
  v92 = 1162105409;
  v103 = 0;
  v95 = 1430736706;
  v96 = 1229070419;
  v104 = 0;
  v98 = 0;
  v99 = 1297236294;
  v105 = 0;
  v66 = 0;
  v74 = 0;
  v78 = 0;
  v90 = 0;
  v94 = 0;
  v101 = 17477;
  v102 = 0;
  v106 = 0;
  v107 = 0;
  driverId = 19;
  dword_456B9C = 0;
  consecutiveWins_456BA8 = 0;
  noPaintJob_456BAC = 0;
  allCarsCrash_456BB0 = 0;
  selectedRaceId = 0;
  reInitUnderGroundMarketStock(); //esto calcula la posicion con los putnos pero no se usa :S
  isDemo_456B10 = 0;
  dword_456B68 = 0;

  //108 es el tamñao de cada estructura de piloto esta seteando a cero cosas
  
  do {
	  drivers[index].mines = 0;
	  drivers[index].spikes = 0;
	  drivers[index].rocket = 0;
	  drivers[index].sabotage = 0;
  } while (++index < 20);
  /*v0 = (signed int)dword_4608A0;
  
  do
  {
    *(_DWORD *)(v0 - 4) = 0;
    *(_DWORD *)v0 = 0;
    *(_DWORD *)(v0 + 4) = 0;
    *(_DWORD *)(v0 + 8) = 0;
    v0 += 108;
  }
  while ( v0 < (signed int)&unk_461110 );*/

  //define los coches
  drivers[0].carType = 5;
  drivers[1].carType = 5;
  drivers[2].carType = 5;
  drivers[3].carType = 4;
  drivers[4].carType = 4;
  drivers[5].carType = 4;
  drivers[6].carType = 4;
  drivers[7].carType = 3;
  drivers[8].carType = 3;
  drivers[9].carType = 3;
  drivers[10].carType = 2;
  drivers[11].carType = 2;
  drivers[12].carType = 2;
  drivers[13].carType = 2;
  drivers[14].carType = 1;
  drivers[15].carType = 1;
  drivers[16].carType = 1;
  drivers[17].carType = 0;
  drivers[18].carType = 0;
  drivers[19].carType = 0;

  /*dword_46085C[0] = 5;
  dword_4608C8 = 5;
  dword_460934 = 5;
  dword_4609A0 = 4;
  dword_460A0C = 4;
  dword_460A78 = 4;
  dword_460AE4 = 4;
  dword_460B50 = 3;
  dword_460BBC = 3;
  dword_460C28 = 3;
  dword_460C94 = 2;
  dword_460D00 = 2;
  dword_460D6C = 2;
  dword_460DD8 = 2;
 
  dword_460E44 = 1;
  dword_460EB0 = 1;
  dword_460F1C = 1;
  dword_460F88 = 0;
  dword_460FF4 = 0;
  dword_461060 = 0;*/


  
  /*v1 = 18;
  v2 = 0;
  v3 = (int)dword_460884;
  v22 = 18;
  //esto esta seteando los puntos iniciales de los compatidores solo de los 19 primeros*/
  drivers[0].points = 100;
  drivers[1].points = 86;
  drivers[2].points = 77;
  drivers[3].points = 69;
  drivers[4].points = 63;
  drivers[5].points = 57;
  drivers[6].points = 51;
  drivers[7].points = 46;
  drivers[8].points = 42;
  drivers[9].points = 37;
  drivers[10].points = 33;
  drivers[11].points = 28;
  drivers[12].points = 25;
  drivers[13].points = 20;
  drivers[14].points = 17;
  drivers[15].points = 13;
  drivers[16].points = 9;
  drivers[17].points = 5;
  drivers[18].points = 2;
  drivers[19].points = 0;
  /*do
  {
	   /**(_DWORD *)v3 = (unsigned __int64)((100.0
                                      - (double)(signed int)(unsigned __int64)(__FYL2X__(
                                                                                 (double)(v2 + 1),
                                                                                 0.30102999566398119802)
                                                                             * 77.0)
                                      + (double)v22 * 5.5
                                      + 2.0)
                                     * 0.5);*/
   /* *(_DWORD *)v3 = (unsigned __int64)((100.0
                                      - (double)(signed int)(unsigned __int64)(((double)(v2 + 1)*log(0.30102999566398119802)
                                                                             * 77.0) * 1.44269504088896340736)
                                      + (double)v22 * 5.5
                                      + 2.0)
                                     * 0.5);
    --v1;
    v3 += 108;
    ++v2;
    v22 = v1;
  }
  while ( v1 > -1 );
  v4 = 0;*/

 
  index = 0;
  do {
	  if (drivers[driverId].face == index) {
		  offset = 1;
	  }
	  drivers[index].face = index+ offset;
	  memcpy(drivers[index].name, driverNames[index+ offset], strlen(driverNames[index+offset]));
	  drivers[index].racesWon = 0;
	  drivers[index].totalRaces = 0;
	  drivers[index].lastRaceIncome = 0;
	  drivers[index].totalIncome = 0;
	  v6 = rand();
	  drivers[index].damage = 0;
	  drivers[index].money = v6 % 100000;
	  v7 = cars[drivers[index].carType].engineUpgrades;
	  v8 = rand();
	  v9 = drivers[index].carType;
	  drivers[index].engine= v8 % v7;
	  v10 = cars[v9].tireUpgrades;
	  v11 = rand() % v10;
	  v12 = cars[v9].armourUpgrades;
	  drivers[index].tire = v11; //este es el nivel de ruedas
	  v13 = rand();
	  v14 = index;
	  drivers[index].armour = v13 % v12; //este es el nivel de armour
	  drivers[index].carMoneyCost = cars[v9].cost;
	  v21 = index + 1;
	  drivers[index].rank = index + 1; ///esta es la posicion
	  drivers[index].colour = index+1;
	  
  } while (++index < 20);
 /* v5 = (signed int)dword_460890;
  do
  {
    *(_DWORD *)(v5 - 4) = 0; //puntos
    *(_DWORD *)v5 = 0; //no se lo que es
    *(_DWORD *)(v5 + 4) = 0; //no se que es
    *(_DWORD *)(v5 + 8) = 0;//no se que es
    v6 = rand();
    *(_DWORD *)(v5 - 68) = 0;   //esto no se loo que es 4c
    *(_DWORD *)(v5 - 32) = v6 % 100000; //el dinero que se tiene
   v7 = dword_44E5F0[440 * *(_DWORD *)(v5 - 52)];  //este es el coche
    v8 = rand();
    v9 = 440 * *(_DWORD *)(v5 - 52);
	*(_DWORD *)(v5 - 64) = v8 % v7; //este es el nivel de motor
    v10 = dword_44E5F4[v9];
    v11 = rand() % v10;
    v12 = dword_44E5F8[440 * *(_DWORD *)(v5 - 52)];
    *(_DWORD *)(v5 - 60) = v11; //este es el nivel de ruedas
    v13 = rand();
    v14 = v4;
    *(_DWORD *)(v5 - 56) = v13 % v12; //este es el nivel de armour
    *(_DWORD *)(v5 - 20) = *(&dword_44DF5C + 440 * *(_DWORD *)(v5 - 52));  //el coste del coche
    v21 = v4 + 1;
    *(_DWORD *)(v5 - 8) = v4 + 1; ///esta es la posicion

	//esto setea el nombre
    while ( *((byte *)&v103 + v14) || v14 == dword_460880[27 * driverId] )
      ++v14;
	  //esto devuelve el nombre del piloto
    v15 = (char *)&v23 + 11 * v14;
    *((byte *)&v103 + v14) = 1;
    v16 = v5 - (_DWORD)v15 - 80;
    do
    {
      v17 = *v15;
      v15[v16] = *v15;
      ++v15;
    }
    while ( v17 );
    v4 = v21;
    *(_DWORD *)(v5 - 16) = v14;
    *(_DWORD *)(v5 - 36) = v14; //es el color
    v5 += 108;
  }
  while ( v5 < (signed int)&unk_461094 );*/
 // v18 = dword_44DF5C;

  drivers[19].money = INITIAL_MONEY;
  drivers[19].damage = 0;
  drivers[19].engine = 0;
  drivers[19].tire = 0;
  drivers[19].armour= 0;
  drivers[19].carType = 0;
  drivers[19].totalRaces = 0;
  drivers[19].lastRaceIncome = 0;
  drivers[19].points = 0;
  drivers[19].totalIncome = 0;
  drivers[19].loanType = NO_LOAN;
  drivers[19].loanRaces = -1;
  
  /*v19 = 27 * driverId;
  dword_460870[v19] = 495;
  dword_46084C[v19] = 0;
  dword_460850[v19] = 0;
  dword_460858[v19] = 0;
  dword_460854[v19] = 0;
  dword_46085C[v19] = 0;
  dword_46087C[v19] = v18;
  dword_460888[v19] = 20;
  dword_46088C[v19] = 0;
  dword_460890[v19] = 0;
  dword_460894[v19] = 0;
  dword_460884[v19] = 0;
  dword_460898[v19] = 0;
  dword_460874[v19] = -1;
  dword_460878[v19] = -1;*/
  result = sub_4224E0();
  continueAnimCurrentFrame_4611D0 = 0;
  armourAnimFrameDirection_45F034 = 0;
  armourAnimCurrentFrame_461288 = 0;
  tireAnimCurrentFrame_45F034 = 0;
  engineAnimCurrentFrame_462D80 = 0;
  carAnimCurrentFrame_45FBA0 = 0;
  actualCarSelected = 1;
  return result;
}
