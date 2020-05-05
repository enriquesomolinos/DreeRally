#include "powerup.h"
#include "../dr.h"
#include "../raceParticipant.h"
#include "../defs.h"


Powerup powerups[16];
int dword_456AC4 = 0; // weak

//----- (00410050) --------------------------------------------------------
void powerUpTaken_410050()
{
    int v0; // ecx@1
    signed int* v1; // esi@1
    int v2; // ebp@4
    int v3; // ebx@4
    unsigned int v4; // eax@9
    char* v5; // esi@9
    void* v6; // edi@9
    char v7; // cl@10
    char* v8; // edi@12
    char v9; // al@13
    char v10; // cl@16
    int v11; // [sp+14h] [bp-14h]@1
    char DstBuf[20]; // [sp+18h] [bp-10h]@9
    char v13; // [sp+1Fh] [bp-9h]@9
    __int16 v14; // [sp+20h] [bp-8h]@9
    int index = 0;
    v0 = Val;
    //v1 = (signed int)&unk_501BB4;
    //v1=malloc(4320);
    //v11 = (int)&unk_501BB4;
    do  //15 vueltas
    {
        if (powerups[index].dword_501BB4 > 0 && v0 > 0)
        {
            v2 = leftMenuInRaceWidth_456AA0 + powerups[index].posX_501BA0 - circuitImageOffsetX_456ABC;
            v3 = (powerups[index].dword_501BB4 >> 3) - circuitImageOffsetY_456AC0 + powerups[index].posY_501BA4 - 10;//*(_DWORD *)(v1 - 16)
            if (v2 >= -18 && v2 < 320 && v3 >= 0 && v3 + 6 < 200)
            {
                switch (powerups[index].lastPowerUp_ID_501BB8)
                {
                case POWERUP_SMALL_MONEY:
                    _itoa(v0, &DstBuf, 10);
                    strcat(&DstBuf, "$");
                    v6 = DstBuf;
                    v5 = &DstBuf;
                    v4 = strlen(&DstBuf);
                    goto LABEL_17;
                case POWERUP_SMALL_REPAIR:
                case POWERUP_BIG_REPAIR:
                    _itoa(powerups[index].repairpercentage_501BBC, &DstBuf, 10);
                    strcat(&DstBuf, "%");
                    v6 = DstBuf;
                    v5 = &DstBuf;
                    v4 = strlen(&DstBuf);
                    goto LABEL_17;

                case POWERUP_BIG_MONEY:
                    _itoa(10 * v0, &DstBuf, 10);
                    strcat(&DstBuf, "$");
                    v6 = DstBuf;
                    v5 = &DstBuf;
                    v4 = strlen(&DstBuf);
                LABEL_17:
                    //esta pintando en mal posicion
                    memcpy(v6, v5, v4);
                    writeTextInRace_402510((v3 << 9) + v2, (const char*)&v14);
                    //v1 = v11;
                LABEL_18:
                    v0 = Val;
                    break;
                default:
                    break;
                }
            }
            powerups[index].dword_501BB4 -= dword_4A9EA4;
        }
        index++;
        //index+=288;
        //v1 += 288;
        //v11 = v1;
    } while (index < 16);
    //while ( v1 < (signed int)&unk_502C94 );
}

//----- (00410220) --------------------------------------------------------
int generatePowerUps()
{
    int v0; // edx@1
    int v1; // esi@2
    signed int v2; // eax@4
    signed int v3; // ecx@8
    signed int v4; // ecx@11
    signed int v5; // ecx@14
    signed int v6; // ecx@17
    signed int v7; // ecx@20
    int (*v8)(); // ebx@24
    signed int v9; // ecx@26
    signed int v10; // eax@26
    int v11; // edx@41
    int v12; // esi@42
    int v13; // eax@42
    int v14; // edx@49
    bool v15; // sf@62
    unsigned __int8 v16; // of@62
    void* v17; // edi@76
    int v18; // ebp@76
    signed int v19; // eax@76
    int v20; // edx@77
    int v21; // ecx@77
    int v22; // ecx@77
    int v23; // edx@77
    int v24; // ecx@77
    int v25; // ecx@77
    int v26; // edx@77
    signed int v27; // ecx@78
    signed int v28; // eax@79
    char v29; // dl@80
    char v30; // dl@82
    char v31; // dl@84
    char v32; // dl@86
    signed int v33; // esi@95
    int v34; // ecx@96
    signed int v35; // edx@96
    signed int v36; // eax@96
    signed int v37; // ecx@102
    signed int v38; // eax@103
    char v39; // dl@104
    char v40; // dl@106
    char v41; // dl@108
    char v42; // dl@110
    int v43; // ecx@114
    signed int v44; // edx@114
    int result; // eax@114
    int v46; // ecx@120
    int v47; // edi@121
    char* v48; // edx@121
    char* v49; // edi@121
    char* v50; // edi@121
    signed int v51; // eax@123
    int v52; // ecx@123
    int v53; // edi@125
    char* v54; // edx@125
    char* v55; // edi@125
    char* v56; // edi@125
    int v57; // edx@125
    int v58; // eax@126
    signed __int64 v59; // rtt@126
    char* v60 = malloc(100); // [sp+10h] [bp-18h]@76
    signed int v61; // [sp+14h] [bp-14h]@40
    int v62; // [sp+18h] [bp-10h]@40
    int v63[12]; // [sp+1Ch] [bp-Ch]@40
    int v64; // [sp+20h] [bp-8h]@40
    int v65; // [sp+24h] [bp-4h]@40

    v0 = dword_4A9EA4;
    if (dword_456AC4 <= 0)
        v1 = 0;
    else
        v1 = dword_456AC4 - dword_4A9EA4;
    dword_456AC4 = v1;
    //v2 = (signed int)dword_501BB0;
    v2 = 0;
    do
    {

        ///v2 -8 es el identificador del powerup
        if (powerups[v2].timeShowed_501BB0 < 2000 && powerups[v2].powerUp_ID_501BA8)
            powerups[v2].timeShowed_501BB0 += v0;
        v2 = v2 + 1;
        /*if ( v3 < 2000 && *(_DWORD *)(v2 + 280) )
          *(_DWORD *)(v2 + 288) = v0 + v3;
        v2 = v2+1;
        if ( v4 < 2000 && *(_DWORD *)(v2 + 568) )
          *(_DWORD *)(v2 + 576) = v0 + v4;
        v2 = v2+1;
        if ( v5 < 2000 && *(_DWORD *)(v2 + 856) )
          *(_DWORD *)(v2 + 864) = v0 + v5;
        v2 = v2+1;
        if ( v6 < 2000 && *(_DWORD *)(v2 + 1144) )
          *(_DWORD *)(v2 + 1152) = v0 + v6;
        v2 = v2+1;
        if ( v7 < 2000 && *(_DWORD *)(v2 + 1432) )
          *(_DWORD *)(v2 + 1440) = v0 + v7;
        v2 = v2+1;
        */
    } while (v2 < 16);
    v8 = rand;
    if (!v1 && !isRaceFinish_456AC8)
    {
        v9 = 0;
        // v10 = (signed int)&unk_501CC8;
        v10 = 0;
        do
        {
            if (powerups[v10].powerUp_ID_501BA8 > 0)
                ++v9;
            if (powerups[v10 + 1].powerUp_ID_501BA8 > 0)
                ++v9;
            if (powerups[v10 + 2].powerUp_ID_501BA8 > 0)
                ++v9;
            if (powerups[v10 + 3].powerUp_ID_501BA8 > 0)
                ++v9;
            if (powerups[v10 + 4].powerUp_ID_501BA8 > 0)
                ++v9;
            if (powerups[v10 + 5].powerUp_ID_501BA8 > 0)
                ++v9;
            v10 += 5;
        } while (v10 < 16);
        v63[0] = 0;
        v64 = 0;
        v61 = v9;
        v65 = 0;
        v62 = 0;
        while (1)
        {
            do
                v11 = v8() % 12;
            while (v63[v11] == 1);
            v12 = 72 * v11;
            v13 = powerups[v11].dword_501BAC;
            v63[v11] = 1;
            powerups[v11].dword_501BAC = v13 <= 0 ? 0 : v13 - dword_4A9EA4;
            if (!powerups[v11].powerUp_ID_501BA8 && powerups[v11].posX_501BA0 > 0 && !powerups[v11].dword_501BAC && v61 < 4)
                break;
            v17 = circuitMatrixHxW_5034F8;
            v18 = circuitWidth_464F40;
        LABEL_92:
            v16 = __OFSUB__(v62 + 1, 12);
            v15 = v62++ - 11 < 0;
            if (!(v15 ^ v16))
                goto LABEL_95;
        }
        v14 = v8() % 100;
        if (raceParticipant2[userRaceOrder_4A9EA8].useWeapons)
        {
            if (v14 >= 0)
            {
                if (v14 >= 30)
                {
                LABEL_54:
                    if (v14 >= 65)
                    {
                    LABEL_57:
                        if (v14 >= 80)
                            goto LABEL_60;
                        powerups[v11].powerUp_ID_501BA8 = POWERUP_SMALL_MONEY;
                    LABEL_59:
                        if (v14 < 80)
                        {
                        LABEL_62:
                            v16 = __OFSUB__(v14, 85);
                            v15 = v14 - 85 < 0;
                            goto LABEL_73;
                        }
                    LABEL_60:
                        if (v14 >= 85)
                            goto LABEL_74;
                        powerups[v11].powerUp_ID_501BA8 = POWERUP_DRUNK;
                        goto LABEL_62;
                    }
                    powerups[v11].powerUp_ID_501BA8 = POWERUP_TURBO;
                LABEL_56:
                    if (v14 < 65)
                        goto LABEL_59;
                    goto LABEL_57;
                }
                powerups[v11].powerUp_ID_501BA8 = POWERUP_SHOTS;
            }
            if (v14 < 30)
                goto LABEL_56;
            goto LABEL_54;
        }
        if (v14 >= 0)
        {
            if (v14 >= 45)
            {
            LABEL_67:
                if (v14 >= 80)
                    goto LABEL_70;
                powerups[v11].powerUp_ID_501BA8 = POWERUP_SMALL_MONEY;
            LABEL_69:
                if (v14 < 80)
                {
                LABEL_72:
                    v16 = __OFSUB__(v14, 90);
                    v15 = v14 - 90 < 0;
                LABEL_73:
                    if (v15 ^ v16)
                    {
                    LABEL_76:
                        v17 = circuitMatrixHxW_5034F8;
                        ++v61;

                        //esto lo he eliminado
                        //powerups[v11].posX_501BA0 = 0;
                        v18 = circuitWidth_464F40;
                        v19 = 0;
                        v21 = 0;
                        //v60 = powerups[v11];
                        /*v60 = (char *)&unk_501BD0 + v12 * 4;*/
                        do
                        {///esto esta hecho al reves todo!!! joer
                            v20 = (int)((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v19 - 8) - 8);
                            //v21 = (int)(v60 - 16);
                            powerups[v11].screenBackup_501BC0[v21 + 0] = *(_DWORD*)v20;
                            powerups[v11].screenBackup_501BC0[v21 + 1] = *(_DWORD*)(v20 + 4);
                            powerups[v11].screenBackup_501BC0[v21 + 2] = *(_DWORD*)(v20 + 8);
                            powerups[v11].screenBackup_501BC0[v21 + 3] = *(_DWORD*)(v20 + 12);
                            v22 = (int)((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v19 - 7) - 8);
                            powerups[v11].screenBackup_501BC0[v21 + 4] = *(_DWORD*)v22;
                            powerups[v11].screenBackup_501BC0[v21 + 5] = *(_DWORD*)(v22 + 4);
                            powerups[v11].screenBackup_501BC0[v21 + 6] = *(_DWORD*)(v22 + 8);
                            powerups[v11].screenBackup_501BC0[v21 + 7] = *(_DWORD*)(v22 + 12);
                            v23 = (int)((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v19 - 6) - 8);
                            v24 = (int)(v60 + 16);
                            powerups[v11].screenBackup_501BC0[v21 + 8] = *(_DWORD*)v23;
                            powerups[v11].screenBackup_501BC0[v21 + 9] = *(_DWORD*)(v23 + 4);
                            powerups[v11].screenBackup_501BC0[v21 + 10] = *(_DWORD*)(v23 + 8);
                            powerups[v11].screenBackup_501BC0[v21 + 11] = *(_DWORD*)(v23 + 12);
                            v25 = (int)((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v19 - 5) - 8);
                            v26 = (int)(v60 + 32);
                            powerups[v11].screenBackup_501BC0[v21 + 12] = *(_DWORD*)v25;
                            powerups[v11].screenBackup_501BC0[v21 + 13] = *(_DWORD*)(v25 + 4);
                            powerups[v11].screenBackup_501BC0[v21 + 14] = *(_DWORD*)(v25 + 8);
                            powerups[v11].screenBackup_501BC0[v21 + 15] = *(_DWORD*)(v25 + 12);
                            v20 += 4;
                            v21 += 16;
                            v19 += 4;
                            v60 += 64;
                        } while (v19 < 16);


                        v27 = 0;

                        do
                        {
                            v28 = 0;
                            do
                            {
                                v29 = *((BYTE*)obstacleBpk + 16 * (16 * powerups[v11].powerUp_ID_501BA8 + v27 - 16) + v28);
                                if (v29)
                                {
                                    *((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 8) = v29;
                                    v17 = circuitMatrixHxW_5034F8;
                                    v18 = circuitWidth_464F40;
                                }
                                v30 = *((char*)obstacleBpk + 16 * (v27 + 16 * powerups[v11].powerUp_ID_501BA8) + v28 - 255);
                                if (v30)
                                {
                                    *((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 7) = v30;
                                    v17 = circuitMatrixHxW_5034F8;
                                    v18 = circuitWidth_464F40;
                                }
                                v31 = *((char*)obstacleBpk + 16 * (v27 + 16 * powerups[v11].powerUp_ID_501BA8) + v28 - 254);
                                if (v31)
                                {
                                    *((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 6) = v31;
                                    v17 = circuitMatrixHxW_5034F8;
                                    v18 = circuitWidth_464F40;
                                }
                                v32 = *((char*)obstacleBpk + 16 * (v27 + 16 * powerups[v11].powerUp_ID_501BA8) + v28 - 253);
                                if (v32)
                                {
                                    *((char*)v17 + powerups[v11].posX_501BA0 + v18 * (powerups[v11].posY_501BA4 + v27 - 8) + v28 - 5) = v32;
                                    v17 = circuitMatrixHxW_5034F8;
                                    v18 = circuitWidth_464F40;
                                }
                                v28 += 4;
                            } while (v28 < 16);
                            ++v27;
                        } while (v27 < 16);
                        v8 = rand;
                        goto LABEL_92;
                    }
                LABEL_74:
                    if (v14 < 100)
                        powerups[v11].powerUp_ID_501BA8 = POWERUP_SMALL_REPAIR;
                    goto LABEL_76;
                }
            LABEL_70:
                if (v14 >= 90)
                    goto LABEL_74;
                powerups[v11].powerUp_ID_501BA8 = POWERUP_DRUNK;
                goto LABEL_72;
            }
            powerups[v11].powerUp_ID_501BA8 = POWERUP_TURBO;
        }
        if (v14 < 45)
            goto LABEL_69;
        goto LABEL_67;
    }
    v17 = circuitMatrixHxW_5034F8;
    v18 = circuitWidth_464F40;
LABEL_95:
    v33 = 0;
    do
    {
        v34 = powerups[v33].timeShowed_501BB0;
        v35 = 0;
        v36 = 2000;
        do
        {
            if (v34 > v36 - 10 && v34 < v36)
                v35 = 1;
            v36 -= 20;
        } while (v36 >= 1540);
        if (v35)
        {
            v37 = 0;
            do
            {
                v38 = 0;
                do
                {
                    v39 = *((BYTE*)obstacleBpk + 16 * (16 * powerups[v33].powerUp_ID_501BA8 + v37 - 16) + v38);
                    if (v39)
                    {
                        *((char*)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 8) = v39;
                        v17 = circuitMatrixHxW_5034F8;
                        v18 = circuitWidth_464F40;
                    }
                    v40 = *((char*)obstacleBpk + 16 * (v37 + 16 * powerups[v33].powerUp_ID_501BA8) + v38 - 255);
                    if (v40)
                    {
                        *((char*)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 7) = v40;
                        v17 = circuitMatrixHxW_5034F8;
                        v18 = circuitWidth_464F40;
                    }
                    v41 = *((char*)obstacleBpk + 16 * (v37 + 16 * powerups[v33].powerUp_ID_501BA8) + v38 - 254);
                    if (v41)
                    {
                        *((char*)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 6) = v41;
                        v17 = circuitMatrixHxW_5034F8;
                        v18 = circuitWidth_464F40;
                    }
                    v42 = *((char*)obstacleBpk + 16 * (v37 + 16 * powerups[v33].powerUp_ID_501BA8) + v38 - 253);
                    if (v42)
                    {
                        *((char*)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v37 - 8) + v38 - 5) = v42;
                        v17 = circuitMatrixHxW_5034F8;
                        v18 = circuitWidth_464F40;
                    }
                    v38 += 4;
                } while (v38 < 16);
                ++v37;
            } while (v37 < 16);
        }
        v43 = powerups[v33].timeShowed_501BB0;
        v44 = 0;
        result = 1990;
        do
        {
            if (v43 > result - 10 && v43 < result)
                v44 = 1;
            result -= 20;
        } while (result >= 1530);
        if (v44)
        {
            result = 0;
            v46 = 0;
            /*v46 = (char *)&unk_501BD0 + v33 * 4*/
            do
            { ///esto sirve para hacer que vibre cuando hay se agota el tiempo
                v47 = (int)((char*)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + result - 8) - 8);
                *(_DWORD*)v47 = powerups[v33].screenBackup_501BC0[v46 + 0];
                *(_DWORD*)(v47 + 4) = powerups[v33].screenBackup_501BC0[v46 + 1];
                *(_DWORD*)(v47 + 8) = powerups[v33].screenBackup_501BC0[v46 + 2];
                *(_DWORD*)(v47 + 12) = powerups[v33].screenBackup_501BC0[v46 + 3];
                v48 = (char*)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + result - 7) - 8;
                *(_DWORD*)v48 = powerups[v33].screenBackup_501BC0[v46 + 4];
                *((_DWORD*)v48 + 1) = powerups[v33].screenBackup_501BC0[v46 + 5];
                *((_DWORD*)v48 + 2) = powerups[v33].screenBackup_501BC0[v46 + 6];
                *((_DWORD*)v48 + 3) = powerups[v33].screenBackup_501BC0[v46 + 7];
                v49 = (char*)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + result - 6) - 8;
                *(_DWORD*)v49 = powerups[v33].screenBackup_501BC0[v46 + 8];
                *((_DWORD*)v49 + 1) = powerups[v33].screenBackup_501BC0[v46 + 9];
                *((_DWORD*)v49 + 2) = powerups[v33].screenBackup_501BC0[v46 + 10];
                *((_DWORD*)v49 + 3) = powerups[v33].screenBackup_501BC0[v46 + 11];
                v50 = (char*)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + result - 5) - 8;
                *(_DWORD*)v50 = powerups[v33].screenBackup_501BC0[v46 + 12];
                *((_DWORD*)v50 + 1) = powerups[v33].screenBackup_501BC0[v46 + 13];
                *((_DWORD*)v50 + 2) = powerups[v33].screenBackup_501BC0[v46 + 14];
                *((_DWORD*)v50 + 3) = powerups[v33].screenBackup_501BC0[v46 + 15];
                result += 4;
                v46 += 16;
                v18 = circuitWidth_464F40;
                v17 = circuitMatrixHxW_5034F8;
                // v46 += 64;
            } while (result < 16);

        }
        if (powerups[v33].timeShowed_501BB0 >= 2000)
        {
            v51 = 0;
            v52 = 0;
            /*v52 = (char *)&unk_501BD0 + v33 * 4;*/
            while (1)
            {
                v53 = (int)((char*)v17 + powerups[v33].posX_501BA0 + v18 * (powerups[v33].posY_501BA4 + v51 - 8) - 8);
                *(_DWORD*)v53 = powerups[v33].screenBackup_501BC0[v52 + 0];
                *(_DWORD*)(v53 + 4) = powerups[v33].screenBackup_501BC0[v52 + 1];
                *(_DWORD*)(v53 + 8) = powerups[v33].screenBackup_501BC0[v52 + 2];
                *(_DWORD*)(v53 + 12) = powerups[v33].screenBackup_501BC0[v52 + 3];
                v54 = (char*)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + v51 - 7) - 8;
                *(_DWORD*)v54 = powerups[v33].screenBackup_501BC0[v52 + 4];
                *((_DWORD*)v54 + 1) = powerups[v33].screenBackup_501BC0[v52 + 5];
                *((_DWORD*)v54 + 2) = powerups[v33].screenBackup_501BC0[v52 + 6];
                *((_DWORD*)v54 + 3) = powerups[v33].screenBackup_501BC0[v52 + 7];
                v55 = (char*)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + v51 - 6) - 8;
                *(_DWORD*)v55 = powerups[v33].screenBackup_501BC0[v52 + 8];
                *((_DWORD*)v55 + 1) = powerups[v33].screenBackup_501BC0[v52 + 9];
                *((_DWORD*)v55 + 2) = powerups[v33].screenBackup_501BC0[v52 + 10];
                *((_DWORD*)v55 + 3) = powerups[v33].screenBackup_501BC0[v52 + 11];
                v56 = (char*)circuitMatrixHxW_5034F8 + powerups[v33].posX_501BA0 + circuitWidth_464F40 * (powerups[v33].posY_501BA4 + v51 - 5) - 8;
                *(_DWORD*)v56 = powerups[v33].screenBackup_501BC0[v52 + 12];
                *((_DWORD*)v56 + 1) = powerups[v33].screenBackup_501BC0[v52 + 13];
                *((_DWORD*)v56 + 2) = powerups[v33].screenBackup_501BC0[v52 + 14];
                v57 = powerups[v33].screenBackup_501BC0[v52 + 15];
                v51 += 4;
                v52 += 16;
                *((_DWORD*)v56 + 3) = v57;
                if (v51 >= 16)
                    break;
                v17 = circuitMatrixHxW_5034F8;
                v18 = circuitWidth_464F40;
            }
            powerups[v33].timeShowed_501BB0 = 0;
            powerups[v33].powerUp_ID_501BA8 = 0;
            dword_456AC4 = 280;
            v58 = rand();
            v59 = v58;
            result = v58 / 200;
            v17 = circuitMatrixHxW_5034F8;
            v18 = circuitWidth_464F40;
            powerups[v33].dword_501BAC = (unsigned __int64)(v59 % 200) + 300;
        }
        v33 += 1;
    } while (v33 < 16);//864 );
    return result;
}

//----- (00410B90) --------------------------------------------------------
char getRacePowerUps_410B90()
{
    int v0; // ebx@1
    signed int v1; // esi@1
    int v2; // edi@2
    int v3; // eax@2
    int v4; // ecx@2
    int v5; // ecx@5
    char* v6; // edx@8
    int v7; // edi@8
    double v8; // st7@15
    int v9; // ebx@15
    signed int v10; // eax@15
    signed int v11; // eax@18
    int v12; // ecx@18
    char* v13; // ebx@19
    char* v14; // edx@19
    char* v15; // ebx@19
    char* v16; // ebx@19
    int v17; // edx@19
    int* v18; // eax@21
    int v19; // edx@21
    int v20; // eax@24
    int v21; // eax@26
    int v22; // edx@26
    int* v23; // ecx@26
    int v24; // eax@26
    int v25; // edx@31
    int v26; // eax@34
    int v27; // eax@34
    signed __int64 v28; // rtt@34
    unsigned __int8 v30; // [sp-18h] [bp-2Ch]@14
    char v31; // [sp-14h] [bp-28h]@14
    int v32; // [sp-Ch] [bp-20h]@14

    v0 = currentDriverSelectedIndex_503518;
    v1 = 0;
    do
    {
        v2 = raceParticipantIngame[v0].absolutePositionX_4A7DB4 - powerups[v1].posX_501BA0;
        v3 = raceParticipantIngame[v0].absolutePositionY_4A7DB8 - powerups[v1].posY_501BA4;
        v4 = v2;
        if (v2 < 0)
            v4 = -v2;
        if (v4 < 17)
        {
            v5 = raceParticipantIngame[v0].absolutePositionY_4A7DB8 - powerups[v1].posY_501BA4;
            if (v3 < 0)
                v5 = -v3;
            if (v5 < 17)
            {
                v6 = (char*)participantCarBpk_5034FC + 40 * v3 + raceParticipantIngame[v0].participantBpkOffser_4A7D10;
                LOBYTE(v3) = v6[v2 + 738];
                v7 = (int)&v6[v2];
                if ((unsigned __int8)v3 > 3u
                    || *(BYTE*)(v7 + 742) > 3u
                    || *(BYTE*)(v7 + 898) > 3u
                    || *(BYTE*)(v7 + 902) > 3u)
                {
                    v3 = powerups[v1].powerUp_ID_501BA8;
                    if (v3 > 0)
                    {
                        if (v0 == userRaceOrder_4A9EA8)
                        {
                            v32 = 36864;
                            v31 = 18;
                            v30 = 4;
                        }
                        else
                        {
                            v8 = raceParticipantIngame[v0].absolutePositionY_4A7DB8 - raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8;
                            v9 = raceParticipantIngame[v0].absolutePositionX_4A7DB4 - raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
                            v10 = 36864
                                - 75
                                * (unsigned __int64)sqrt((double)(signed int)(v9 * v9 + (unsigned __int64)v8 * (unsigned __int64)v8));
                            if (v10 <= 4096)
                            {
                            LABEL_18:
                                v11 = 0;
                                //v12 = v1 + 48;//powerups[v1] +48
                                v12 = 0;
                                //v12 = powerups[v1].screenBackup_501BC0;
                                do
                                {
                                    v13 = (char*)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0 + circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 8) - 8;
                                    *(_DWORD*)v13 = powerups[v1].screenBackup_501BC0[v12];
                                    *((_DWORD*)v13 + 1) = powerups[v1].screenBackup_501BC0[v12 + 1];
                                    *((_DWORD*)v13 + 2) = powerups[v1].screenBackup_501BC0[v12 + 2];
                                    *((_DWORD*)v13 + 3) = powerups[v1].screenBackup_501BC0[v12 + 3];


                                    /*	*(_DWORD *)v13 = *(_DWORD *)(v12 - 16);
                                      *((_DWORD *)v13 + 1) = *(_DWORD *)(v12 - 16 + 4);
                                      *((_DWORD *)v13 + 2) = *(_DWORD *)(v12 - 16 + 8);
                                      *((_DWORD *)v13 + 3) = *(_DWORD *)(v12 - 16 + 12);*/

                                    v14 = (char*)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0 + circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 7) - 8;
                                    *(_DWORD*)v14 = powerups[v1].screenBackup_501BC0[v12 + 4];
                                    *((_DWORD*)v14 + 1) = powerups[v1].screenBackup_501BC0[v12 + 5];
                                    *((_DWORD*)v14 + 2) = powerups[v1].screenBackup_501BC0[v12 + 6];
                                    *((_DWORD*)v14 + 3) = powerups[v1].screenBackup_501BC0[v12 + 7];


                                    /**(_DWORD *)v14 = *(_DWORD *)v12;
                                    *((_DWORD *)v14 + 1) = *(_DWORD *)(v12 + 4);
                                    *((_DWORD *)v14 + 2) = *(_DWORD *)(v12 + 8);
                                    *((_DWORD *)v14 + 3) = *(_DWORD *)(v12 + 12);*/
                                    v15 = (char*)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0 + circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 6) - 8;
                                    *(_DWORD*)v15 = powerups[v1].screenBackup_501BC0[v12 + 8];
                                    *((_DWORD*)v15 + 1) = powerups[v1].screenBackup_501BC0[v12 + 9];
                                    *((_DWORD*)v15 + 2) = powerups[v1].screenBackup_501BC0[v12 + 10];
                                    *((_DWORD*)v15 + 3) = powerups[v1].screenBackup_501BC0[v12 + 11];

                                    /**(_DWORD *)v15 = *(_DWORD *)(v12 + 16);
                                    *((_DWORD *)v15 + 1) = *(_DWORD *)(v12 + 20);
                                    *((_DWORD *)v15 + 2) = *(_DWORD *)(v12 + 24);
                                    *((_DWORD *)v15 + 3) = *(_DWORD *)(v12 + 28);*/
                                    v16 = (char*)circuitMatrixHxW_5034F8 + powerups[v1].posX_501BA0 + circuitWidth_464F40 * (powerups[v1].posY_501BA4 + v11 - 5) - 8;
                                    *(_DWORD*)v16 = powerups[v1].screenBackup_501BC0[v12 + 12];
                                    *((_DWORD*)v16 + 1) = powerups[v1].screenBackup_501BC0[v12 + 13];
                                    *((_DWORD*)v16 + 2) = powerups[v1].screenBackup_501BC0[v12 + 14];
                                    v17 = powerups[v1].screenBackup_501BC0[v12 + 15];

                                    /**(_DWORD *)v16 = *(_DWORD *)(v12 + 32);
                                    *((_DWORD *)v16 + 1) = *(_DWORD *)(v12 + 36);
                                    *((_DWORD *)v16 + 2) = *(_DWORD *)(v12 + 40);
                                    v17 = *(_DWORD *)(v12 + 44);*/
                                    v11 += 4;
                                    v12 += 16;
                                    // v12 += 64;
                                    *((_DWORD*)v16 + 3) = v17;
                                } while (v11 < 16);
                                switch (powerups[v1].powerUp_ID_501BA8)
                                {
                                case POWERUP_SHOTS://disparos pillados
                                    v18 = &raceParticipant2[currentDriverSelectedIndex_503518].weaponsBar_4A68B0;
                                    v19 = raceParticipant2[currentDriverSelectedIndex_503518].weaponsBar_4A68B0 + 30720;
                                    goto LABEL_32;
                                case POWERUP_TURBO://turbo pillado
                                    v18 = &raceParticipant2[currentDriverSelectedIndex_503518].turboBar_4A68B4;
                                    v19 = raceParticipant2[currentDriverSelectedIndex_503518].turboBar_4A68B4 + 15360;
                                    goto LABEL_32;
                                case POWERUP_SMALL_MONEY: //dinero peque\F1o pillado
                                    ++raceParticipant2[currentDriverSelectedIndex_503518].moneyPicked;
                                    break;
                                case POWERUP_DRUNK://bebido
                                    v20 = currentDriverSelectedIndex_503518;
                                    raceParticipantIngame[currentDriverSelectedIndex_503518].mushroomPendingTime_4A8050 = 560;
                                    if (v20 == userRaceOrder_4A9EA8)
                                        //SOUND_SIENI
                                        loadMenuSoundEffect(2u, 6, 0, 0x10000, 327680);
                                    break;
                                case POWERUP_SMALL_REPAIR://llave peque\F1a de reparacion
                                    v21 = rand() % 4;
                                    v22 = raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898;
                                    v21 += 2;
                                    v23 = &raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898;

                                    powerups[v1].repairpercentage_501BBC = v21;  //+28 osbre powerups[v1].
                                    v24 = (v21 << 10) + v22;
                                    *v23 = v24;
                                    if (v24 > 102400)
                                        *v23 = 102400;
                                    break;
                                case POWERUP_DRUGS: //drogas pilladas
                                    if (currentDriverSelectedIndex_503518 == userRaceOrder_4A9EA8)
                                        raceParticipant[0].drugPicked = 1;
                                    break;
                                case POWERUP_BIG_MONEY: //dinero pillado! grande
                                    raceParticipant2[currentDriverSelectedIndex_503518].moneyPicked += 10;
                                    break;
                                case POWERUP_BIG_REPAIR://llave grande
                                    v25 = raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898;
                                    v18 = &raceParticipant2[currentDriverSelectedIndex_503518].damageBar_4A6898;
                                    powerups[v1].repairpercentage_501BBC = 20; //+28 sobre powerups[v1].
                                    v19 = v25 + 20480;
                                LABEL_32:
                                    *v18 = v19;
                                    if (v19 > 102400)
                                        *v18 = 102400;
                                    break;
                                default:
                                    break;
                                }
                                v26 = powerups[v1].powerUp_ID_501BA8;
                                powerups[v1].dword_501BB4 = 140; // + 20 sobre powerups[v1].
                                powerups[v1].lastPowerUp_ID_501BB8 = v26; //+24 sobre powerups[v1].
                                powerups[v1].powerUp_ID_501BA8 = 0;
                                dword_456AC4 = 240;
                                v27 = rand();
                                v28 = v27;
                                v3 = v27 / 150;
                                v0 = currentDriverSelectedIndex_503518;
                                powerups[v1].timeShowed_501BB0 = 0;
                                powerups[v1].dword_501BAC = (unsigned __int64)(v28 % 150) + 200;
                                goto LABEL_35;
                            }
                            v32 = v10;
                            v31 = 18;
                            v30 = 10;
                        }
                        ///SOUND_MINE
                        loadMenuSoundEffect(v30, v31, 0, v32, 135168);
                        goto LABEL_18;
                    }
                }
            }
        }
    LABEL_35:
        v1 += 1;
    } while (v1 < 16);
    return v3;
}

//----- (00409460) --------------------------------------------------------
int generateBigPowerUps()
{
    signed int v0; // eax@1
    signed int v1; // eax@3
    signed int v2; // eax@5
    signed int v3; // eax@7
    int (*v4)(); // edi@9
    signed int v5; // esi@9
    signed int v6; // eax@11
    int result; // eax@13
    int v8; // esi@14
    int v9; // eax@15
    void* v10; // edi@15
    int v11; // ebp@15
    signed int v12; // eax@15
    int v13; // ecx@16
    int v14; // edx@16
    int v15; // edx@16
    int v16; // ecx@16
    int v17; // edx@16
    int v18; // edx@16
    int v19; // ecx@16
    signed int v20; // ecx@17
    char v21; // dl@19
    char v22; // dl@21
    char v23; // dl@23
    char v24; // dl@25
    void* v25; // edi@33
    int v26; // ebp@33
    signed int v27; // ecx@33
    int v28; // edx@34
    int v29; // esi@34
    int v30; // edx@34
    int v31; // edx@34
    int v32; // esi@34
    int v33; // edx@34
    int v34; // esi@34
    signed int v35; // esi@35
    signed int v36; // ecx@36
    char v37; // dl@37
    char v38; // dl@39
    char v39; // dl@41
    char v40; // dl@43
    char* v41; // [sp+0h] [bp-4h]@15
    char* v42; // [sp+0h] [bp-4h]@33

    v0 = 0;

    do {
        // powerups[v0].posX_501BA0=0;
        // powerups[v0].posY_501BA4 =0;
        powerups[v0].powerUp_ID_501BA8 = 0;
        powerups[v0].timeShowed_501BB0 = 0;
        powerups[v0].dword_501BB4 = 0;
        powerups[v0].lastPowerUp_ID_501BB8 = 0;
        powerups[v0].repairpercentage_501BBC = 0;
        v4 = rand;
        powerups[v0].dword_501BAC = rand() % 50 + 100;
        v0++;
    } while (v0 < 16);

    /*v0 =   (signed int)&unk_501BB4;
    do
    {
      *(_DWORD *)v0 = 0;
      v0 += 288;
    }
    while ( v0 < (signed int)&unk_503234 );
    v1 = (signed int)&unk_501BB8;
    do
    {
      *(_DWORD *)v1 = 0;
      v1 += 288;
    }
    while ( v1 < (signed int)&unk_503238 );
    v2 = (signed int)&unk_501BBC;
    do
    {
      *(_DWORD *)v2 = 0;
      v2 += 288;
    }
    while ( v2 < (signed int)&unk_50323C );*/

    /* v3 = (signed int)dword_501BA8;
     do
     {
       *(_DWORD *)v3 = 0;
       v3 += 288;
     }
     while ( v3 < (signed int)&unk_503228 );*/

     /*v4 = rand;
     v5 = (signed int)dword_501BAC;
     do
     {
       v5 += 288;
       *(_DWORD *)(v5 - 288) = rand() % 50 + 100;
     }
     while ( v5 < (signed int)&unk_50322C );
     v6 = (signed int)dword_501BB0;
     do
     {
       *(_DWORD *)v6 = 0;
       v6 += 288;
     }
     while ( v6 < (signed int)&unk_503230 );
     */
    dword_456AC4 = 350;
    result = rand() % 4;
    //if(debug)result=0;
    if (!result)
    {
        //v8 = 72 * (rand() % 2 + 12);
        v8 = (rand() % 2 + 12);
        result = powerups[v8].dword_501BAC;
        //result = dword_501BA0[v8];
        //if(debug)result=1;
        if (result > 0)
        {
            v9 = rand() % 2;
            v10 = circuitMatrixHxW_5034F8;
            v11 = circuitWidth_464F40;
            if (v9 == 0)
                powerups[v8].powerUp_ID_501BA8 = POWERUP_BIG_MONEY;
            if (v9 == 1)
                powerups[v8].powerUp_ID_501BA8 = POWERUP_BIG_REPAIR;
            //powerups[v8].powerUp_ID_501BA8 =v9+7;
            //dword_501BA8[v8] = v9 + 7;
            v12 = 0;
            //v41 = (char *)&unk_501BD0 + v8 * 4;
            v14 = 0;

            do
            {
                v13 = (int)((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 8) - 8);

                //v14 = (int)(v41 - 16);
                powerups[v8].screenBackup_501BC0[v14 + 0] = *(_DWORD*)(v13 + 4);
                powerups[v8].screenBackup_501BC0[v14 + 1] = *(_DWORD*)(v13 + 4);
                powerups[v8].screenBackup_501BC0[v14 + 2] = *(_DWORD*)(v13 + 8);
                powerups[v8].screenBackup_501BC0[v14 + 3] = *(_DWORD*)(v13 + 12);

                v15 = (int)((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 7) - 8);
                powerups[v8].screenBackup_501BC0[v14 + 4] = *(_DWORD*)v15;
                powerups[v8].screenBackup_501BC0[v14 + 5] = *(_DWORD*)(v15 + 4);
                powerups[v8].screenBackup_501BC0[v14 + 6] = *(_DWORD*)(v15 + 8);
                powerups[v8].screenBackup_501BC0[v14 + 7] = *(_DWORD*)(v15 + 12);
                v16 = (int)((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 6) - 8);
                //   v17 = (int)(v41 + 16);
                powerups[v8].screenBackup_501BC0[v14 + 8] = *(_DWORD*)v16;
                powerups[v8].screenBackup_501BC0[v14 + 9] = *(_DWORD*)(v16 + 4);
                powerups[v8].screenBackup_501BC0[v14 + 10] = *(_DWORD*)(v16 + 8);
                powerups[v8].screenBackup_501BC0[v14 + 11] = *(_DWORD*)(v16 + 12);
                v18 = (int)((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v12 - 5) - 8);
                //   v19 = (int)(v41 + 32);
                powerups[v8].screenBackup_501BC0[v14 + 12] = *(_DWORD*)v18;
                powerups[v8].screenBackup_501BC0[v14 + 13] = *(_DWORD*)(v18 + 4);
                powerups[v8].screenBackup_501BC0[v14 + 14] = *(_DWORD*)(v18 + 8);
                powerups[v8].screenBackup_501BC0[v14 + 15] = *(_DWORD*)(v18 + 12);
                v12 += 4;
                v14 += 16;
                // v41 += 64;
            } while (v12 < 16);

            v20 = 0;
            do
            {
                result = 0;
                do
                {
                    v21 = *((BYTE*)obstacleBpk + 16 * (16 * powerups[v8].powerUp_ID_501BA8 + v20 - 16) + result);
                    if (v21)
                    {
                        *((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 8) = v21;
                        v10 = circuitMatrixHxW_5034F8;
                        v11 = circuitWidth_464F40;
                    }
                    v22 = *((char*)obstacleBpk + 16 * (v20 + 16 * powerups[v8].powerUp_ID_501BA8) + result - 255);
                    if (v22)
                    {
                        *((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 7) = v22;
                        v10 = circuitMatrixHxW_5034F8;
                        v11 = circuitWidth_464F40;
                    }
                    v23 = *((char*)obstacleBpk + 16 * (v20 + 16 * powerups[v8].powerUp_ID_501BA8) + result - 254);
                    if (v23)
                    {
                        *((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 6) = v23;
                        v10 = circuitMatrixHxW_5034F8;
                        v11 = circuitWidth_464F40;
                    }
                    v24 = *((char*)obstacleBpk + 16 * (v20 + 16 * powerups[v8].powerUp_ID_501BA8) + result - 253);
                    if (v24)
                    {
                        *((char*)v10 + powerups[v8].posX_501BA0 + v11 * (powerups[v8].posY_501BA4 + v20 - 8) + result - 5) = v24;
                        v10 = circuitMatrixHxW_5034F8;
                        v11 = circuitWidth_464F40;
                    }
                    result += 4;
                } while (result < 16);
                ++v20;
            } while (v20 < 16);
            v4 = rand;
        }
    }
    //if(debug==1)
      ///  raceParticipant[0].drugPicked==1;
    if (raceParticipant[0].drugPicked == 1)
    {
        result = isMultiplayerGame;
        if (!isMultiplayerGame)
        {
            //result = 288 * (v4() % 2 + 14);
            result = (v4() % 2 + 14);
            ///if ( *(int *)((char *)dword_501BA0 + result) > 0 )

            if (powerups[result].posX_501BA0 > 0)
            {
                v25 = circuitMatrixHxW_5034F8;
                v26 = circuitWidth_464F40;
                powerups[result].powerUp_ID_501BA8 = POWERUP_DRUGS;
                v27 = 0;
                v29 = 0;
                //v42 = (char *)&unk_501BD0 + result;
                do
                {
                    v28 = (int)((char*)v25
                        + *(int*)((char*)powerups[result].posX_501BA0)
                        + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v27 - 8)
                        - 8);
                    //v29 = (int)(v42 - 16);

                    powerups[result].screenBackup_501BC0[v29 + 0] = *(_DWORD*)v28;
                    powerups[result].screenBackup_501BC0[v29 + 1] = *(_DWORD*)(v28 + 4);
                    powerups[result].screenBackup_501BC0[v29 + 2] = *(_DWORD*)(v28 + 8);
                    powerups[result].screenBackup_501BC0[v29 + 3] = *(_DWORD*)(v28 + 12);
                    v30 = (int)((char*)v25
                        + *(int*)((char*)powerups[result].posX_501BA0)
                        + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v27 - 7)
                        - 8);
                    powerups[result].screenBackup_501BC0[v29 + 4] = *(_DWORD*)v30;
                    powerups[result].screenBackup_501BC0[v29 + 5] = *(_DWORD*)(v30 + 4);
                    powerups[result].screenBackup_501BC0[v29 + 6] = *(_DWORD*)(v30 + 8);
                    powerups[result].screenBackup_501BC0[v29 + 7] = *(_DWORD*)(v30 + 12);
                    v31 = (int)((char*)v25
                        + *(int*)((char*)powerups[result].posX_501BA0)
                        + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v27 - 6)
                        - 8);
                    // v32 = (int)(v42 + 16);
                    powerups[result].screenBackup_501BC0[v29 + 8] = *(_DWORD*)v31;
                    powerups[result].screenBackup_501BC0[v29 + 9] = *(_DWORD*)(v31 + 4);
                    powerups[result].screenBackup_501BC0[v29 + 10] = *(_DWORD*)(v31 + 8);
                    powerups[result].screenBackup_501BC0[v29 + 11] = *(_DWORD*)(v31 + 12);
                    v33 = (int)((char*)v25
                        + *(int*)((char*)powerups[result].posX_501BA0)
                        + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v27 - 5)
                        - 8);
                    //v34 = (int)(v42 + 32);
                    powerups[result].screenBackup_501BC0[v29 + 12] = *(_DWORD*)v33;
                    powerups[result].screenBackup_501BC0[v29 + 13] = *(_DWORD*)(v33 + 4);
                    powerups[result].screenBackup_501BC0[v29 + 14] = *(_DWORD*)(v33 + 8);
                    powerups[result].screenBackup_501BC0[v29 + 15] = *(_DWORD*)(v33 + 12);
                    v27 += 4;
                    v29 += 16;
                    //v42 += 64;
                } while (v27 < 16);

                v35 = 0;
                do
                {
                    v36 = 0;
                    do
                    {
                        v37 = *((BYTE*)obstacleBpk + 16 * (16 * *(int*)((char*)powerups[result].powerUp_ID_501BA8) + v35 - 16) + v36);
                        if (v37)
                        {
                            *((char*)v25
                                + *(int*)((char*)powerups[result].posX_501BA0)
                                + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v35 - 8)
                                + v36
                                - 8) = v37;
                            v25 = circuitMatrixHxW_5034F8;
                            v26 = circuitWidth_464F40;
                        }
                        v38 = *((char*)obstacleBpk + 16 * (v35 + 16 * *(int*)((char*)powerups[result].powerUp_ID_501BA8)) + v36 - 255);
                        if (v38)
                        {
                            *((char*)v25
                                + *(int*)((char*)powerups[result].posX_501BA0)
                                + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v35 - 8)
                                + v36
                                - 7) = v38;
                            v25 = circuitMatrixHxW_5034F8;
                            v26 = circuitWidth_464F40;
                        }
                        v39 = *((char*)obstacleBpk + 16 * (v35 + 16 * *(int*)((char*)powerups[result].powerUp_ID_501BA8)) + v36 - 254);
                        if (v39)
                        {
                            *((char*)v25
                                + *(int*)((char*)powerups[result].posX_501BA0)
                                + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v35 - 8)
                                + v36
                                - 6) = v39;
                            v25 = circuitMatrixHxW_5034F8;
                            v26 = circuitWidth_464F40;
                        }
                        v40 = *((char*)obstacleBpk + 16 * (v35 + 16 * *(int*)((char*)powerups[result].powerUp_ID_501BA8)) + v36 - 253);
                        if (v40)
                        {
                            *((char*)v25
                                + *(int*)((char*)powerups[result].posX_501BA0)
                                + v26 * (*(int*)((char*)powerups[result].posY_501BA4) + v35 - 8)
                                + v36
                                - 5) = v40;
                            v25 = circuitMatrixHxW_5034F8;
                            v26 = circuitWidth_464F40;
                        }
                        v36 += 4;
                    } while (v36 < 16);
                    ++v35;
                } while (v35 < 16);
            }
            raceParticipant[0].drugPicked = 0;
        }
    }
    return result;
}
