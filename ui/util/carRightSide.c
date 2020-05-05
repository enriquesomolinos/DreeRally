#include "carRightSide.h"
#include "../../cars.h"
#include "../../graphics.h"
#include "../../imageUtil.h"
#include "../../drivers.h"
#include "../../dr.h"


//----- (0041FC20) --------------------------------------------------------
int drawCarRightSide()
{
    //  char *v0; // eax@1
    //  char *v1; // edx@1
    //  char v2; // cl@2
    int namePosition; // eax@3
    int* v4; // eax@3
    unsigned int v5; // eax@5
    char* v6; // edi@5
    char v7; // cl@6
    int money; // eax@7
  //  unsigned int v9; // eax@9
  //  char *v10; // edi@9
  //  char v11; // cl@10
    int v12; // edx@11
  //  char *v13; // edi@13
  //  char v14; // al@14
  //  unsigned int v15; // eax@15
  //  char *v16; // edi@15
  //  char v17; // cl@16
    int v18; // edx@17
    signed int v19; // esi@17
    unsigned __int64 v20; // rax@18
    char* v21; // edi@18
    int v22; // eax@19
    char v23; // cl@20
    char* v24; // eax@21
    int v25; // edi@21
    unsigned int v26; // edx@21
    char v27; // cl@22
    int v28; // eax@25
    int v29; // esi@25
    int v30; // edi@26
    int v31; // esi@28
    int v32; // edi@29
    int v33; // esi@31
    int v34; // edi@32
    int v35; // ebp@34
    int v36; // edi@35
    int v37; // esi@35
    int v38; // ebp@37
    int v39; // edi@38
    int v40; // esi@38
    int result; // eax@40
    int v42; // ebx@40
    int v43; // edi@41
    int v44; // esi@41
    int v45; // [sp+1Ch] [bp-2Ch]@5

    char* DstBuf = malloc(20); // [sp+34h] [bp-14h]@
    char* Str = malloc(20); // [sp+20h] [bp-28h]@1
    char* moneyCount = malloc(20);
    drawImageWithPosition2((int)statbas7Bpk, 96, 224, (int)((char*)screenBuffer + 80544));
    drawImageWithPosition2(getSceneCarBpkById(drivers[driverId].carType), 96, 64, (int)((char*)screenBuffer + 90784));
    //drawImageWithPosition2((int)*(&scenecar1Bpk + dword_46085C[27 * driverId]), 96, 64, (int)((char *)screenBuffer + 90784));
    /*v0 = &byte_460840[108 * driverId];
    v0 = &byte_460840[108 * driverId];
    v1 = (char *)(Str - v0);
    do
    {
      v2 = *v0;
      v0[(_DWORD)v1] = *v0;
      ++v0;
    }
    while ( v2 );
    strupr(Str);
    /*esto creo que no es necesario*/
    //name = getNameOffsetPositionRight(Str);
    memcpy(Str, drivers[driverId].name, strlen(drivers[driverId].name));
    memset(&Str[strlen(drivers[driverId].name)], '\0', 1);
    _strupr(Str);
    namePosition = getNameOffsetPositionRight(Str);

    drawTextWithFont((int)graphicsGeneral.fmed1aBpk, (int)&unk_445928, Str, namePosition + 81184);
    v4 = drivers[driverId].money;
    //v4 = &dword_460870[27 * driverId];
    if (drivers[driverId].money > 9999999)
        //if (dword_460870[27 * driverId] > 9999999)
        drivers[driverId].money = 9999999;
    _itoa(v4, DstBuf, 10);
    strcpy(moneyCount, "$");
    memcpy(&moneyCount[1], DstBuf, strlen(DstBuf));
    memset(&moneyCount[strlen(DstBuf) + 1], '\0', 1);

    v5 = strlen(DstBuf) + 1;
    v6 = (char*)&v45 + 3;
    do
        v7 = (v6++)[1];
    while (v7);
    memcpy(v6, DstBuf, v5);
    money = sub_41FA50(moneyCount);//size small text
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, moneyCount, money + 131744);

    ///calculo de la velocidad a partir de la velocidad inicial que es  initialVelocity (55)
    _itoa(initialVelocity + drivers[driverId].engine * 5 + 5 * drivers[driverId].carType, DstBuf, 10);
    //itoa(*(&initialVelocity + dword_460850[27 * driverId] + 5 * dword_46085C[27 * driverId]), DstBuf, 10);
    Str[0] = 0;
    Str[1] = 0;
    Str[2] = 0;
    Str[3] = 0;
    if (strlen(DstBuf) == 2)
        strcpy(Str, " ");
    v12 = (int)graphicsGeneral.fmed1aBpk;


    memcpy(&Str[3 - strlen(DstBuf)], DstBuf, strlen(DstBuf));

    //pinta la velocidad de motor
    drawTextWithFont(v12, (int)&unk_445928, Str, 204768);
    _itoa(drivers[driverId].rank, DstBuf, 10);
    //itoa(dword_460888[27 * driverId], DstBuf, 10);
    Str[0] = 0;
    Str[1] = "#";
    Str[2] = 0;
    Str[3] = 0;
    if (strlen(DstBuf) == 1) {
        strcpy(Str, " #");
        memcpy(&Str[2], DstBuf, strlen(DstBuf));
    }
    else {
        strcpy(Str, "#");
        memcpy(&Str[1], DstBuf, strlen(DstBuf));
    }
    v18 = (int)graphicsGeneral.fmed1aBpk;

    //pinta #20
    drawTextWithFont(v18, (int)&unk_445928, Str, 214368);
    v19 = 0;
    do
    {
        v20 = (unsigned __int64)ceil((double)drivers[driverId].damage * 0.44);
        v21 = (char*)screenBuffer + v19 + 196388;
        memset(v21, 0x3Fu, 4 * ((unsigned int)v20 >> 2));
        v19 += 640;
        memset(&v21[4 * ((unsigned int)v20 >> 2)], 63, v20 & 3);
    } while (v19 < 3200);
    _itoa(drivers[driverId].damage, DstBuf, 10);
    v22 = 0;
    do
    {
        v23 = DstBuf[v22];
        Str[v22++] = v23;
    } while (v23);
    v24 = Str;
    v25 = 0;
    v26 = 0;
    do
        v27 = *v24++;
    while (v27);
    v45 = v24 - &Str[1];
    if (v24 != &Str[1])
    {
        do
            v25 += (unsigned __int8)byte_445892[(unsigned __int8)Str[v26++]];
        while (v26 < strlen(Str));
    }
    drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, Str, 193903 - v25);
    v28 = driverId;
    v29 = 0;
    //dword_44E5F0 contiene los datos del coche dword_44E5F4 dword_44E5F8 engine tire armour muestra los upgrades posibles

    if (cars[drivers[driverId].carType].engineUpgrades > 0)
        //if (dword_44E5F0[440 * dword_46085C[27 * driverId]] > 0 )
    {
        v30 = 0;
        do
        {
            drawImageWithPosition2((int)((char*)statpop4Bpk + 800), 20, 10, (int)((char*)screenBuffer + v30 + 149667));
            v28 = driverId;
            ++v29;
            v30 += 23;
        }
        //while (v29 < dword_44E5F0[440 * dword_46085C[27 * driverId]]);
        while (v29 < cars[drivers[driverId].carType].engineUpgrades);
    }
    v31 = 0;
    if (cars[drivers[driverId].carType].tireUpgrades > 0)
        //	  if (dword_44E5F4[440 * dword_46085C[27 * v28]] > 0)
    {
        v32 = 0;
        do
        {
            drawImageWithPosition2((int)((char*)statpop4Bpk + 800), 20, 10, (int)((char*)screenBuffer + v32 + 165027));
            v28 = driverId;
            ++v31;
            v32 += 23;
        } while (v31 < cars[drivers[driverId].carType].tireUpgrades);
        //  while ( v31 < dword_44E5F4[440 * dword_46085C[27 * driverId]] );
    }
    v33 = 0;
    if (cars[drivers[driverId].carType].armourUpgrades > 0)
        //if (dword_44E5F8[440 * dword_46085C[27 * v28]] > 0)
    {
        v34 = 0;
        do
        {
            drawImageWithPosition2((int)((char*)statpop4Bpk + 800), 20, 10, (int)((char*)screenBuffer + v34 + 180387));
            v28 = driverId;
            ++v33;
            v34 += 23;
        } while (v33 < cars[drivers[driverId].carType].armourUpgrades);
        //while (v33 < dword_44E5F8[440 * dword_46085C[27 * driverId]]);
    }
    v35 = 0;
    //pinta los upgrades
    if (drivers[driverId].engine > 0)
        //if (dword_460850[27 * v28] > 0)
    {
        v36 = 0;
        v37 = 0;
        do
        {
            drawImageWithPosition2((int)((char*)statpop4Bpk + v36), 20, 10, (int)((char*)screenBuffer + v37 + 149667));
            v28 = driverId;
            ++v35;
            v37 += 23;
            v36 += 200;
        } while (v35 < drivers[driverId].engine);
        //while (v35 < dword_460850[27 * driverId]);
    }
    v38 = 0;
    if (drivers[driverId].tire > 0)
        //if (dword_460854[27 * v28] > 0)
    {
        v39 = 0;
        v40 = 0;
        do
        {
            drawImageWithPosition2((int)((char*)statpop4Bpk + v39), 20, 10, (int)((char*)screenBuffer + v40 + 165027));
            v28 = driverId;
            ++v38;
            v40 += 23;
            v39 += 200;
        } while (v38 < drivers[driverId].tire);
        //while (v38 < dword_460854[27 * driverId]);
    }
    result = 27 * v28;
    v42 = 0;
    if (drivers[driverId].armour > 0)
        //if ( dword_460858[result] > 0 )
    {
        v43 = 0;
        v44 = 0;
        do
        {
            drawImageWithPosition2((int)((char*)statpop4Bpk + v43), 20, 10, (int)((char*)screenBuffer + v44 + 180387));
            result = 27 * driverId;
            ++v42;
            v44 += 23;
            v43 += 200;
        } while (v42 < drivers[driverId].armour);
        //while ( v42 < dword_460858[27 * driverId] );

    }
    return result * 4;
}
