#include "leftBar.h"
#include "../defs.h"
#include "../dr.h"
#include "../raceParticipant.h"
#include "../sfx/soundEffects.h"

char smallbarBpk_50E720[2048]; // weak
int boardsBPK_4AA940[4][2048]; // weak
char* damslidBpk; // idb
char bugnum6Bpk_46E560[43300]; // weak ///TODO ajust correct size
int racePositionTemp_481BD0[4]; // weak
char ownnum1Bpk_503520[22528]; // weak

char othnum1Bpk_50B2C0[12672]; // weak
void* goalnum2Bpk_4AA50C; // idb
char damageBpk_464F80[8064]; // weak
void* rast1Bpk_464F78; // idb
_UNKNOWN unk_46E880; // weak
void* sidebom1Bpk_481E04; // idb

//----- (00413C90) --------------------------------------------------------
int  drawSmallLeftBar_413C90(int a1)
{
    int v1; // eax@1
    int v2; // ecx@1
    signed int v3; // edi@1
    signed int v4; // esi@2
    char v5; // dl@3
    char v6; // dl@5
    int v7; // eax@5
    int v8; // ecx@5
    char v9; // dl@7
    int v10; // eax@7
    int v11; // ecx@7
    char v12; // dl@9
    int v13; // eax@9
    int v14; // ecx@9
    unsigned __int64 v15; // rax@13
    unsigned __int64 v16; // rax@16
    int v17; // esi@18
    signed int v18; // edi@19
    double v19; // st7@26
    int v20; // eax@26
    int v21; // esi@26
    int result; // eax@34

    v1 = 0;
    v2 = 96;
    v3 = 32;
    do
    {
        v4 = 16;
        do
        {
            v5 = smallbarBpk_50E720[v1];
            if (v5)
            {
                a1 = dword_464F14;
                *(BYTE*)(dword_464F14 + v2) = v5;
            }
            v6 = smallbarBpk_50E720[v1 + 1];
            v7 = v1 + 1;
            v8 = v2 + 1;
            if (v6)
            {
                a1 = dword_464F14;
                *(BYTE*)(dword_464F14 + v8) = v6;
            }
            v9 = smallbarBpk_50E720[v7];
            v10 = v7 + 1;
            v11 = v8 + 1;
            if (v9)
            {
                a1 = dword_464F14;
                *(BYTE*)(dword_464F14 + v11) = v9;
            }
            v12 = smallbarBpk_50E720[v10];
            v13 = v10 + 1;
            v14 = v11 + 1;
            if (v12)
            {
                a1 = dword_464F14;
                *(BYTE*)(dword_464F14 + v14) = v12;
            }
            v1 = v13 + 1;
            v2 = v14 + 1;
            --v4;
        } while (v4);
        v2 += 448;
        --v3;
    } while (v3);
    v15 = (unsigned __int64)((double)raceParticipant2[userRaceOrder_4A9EA8].turboBar_4A68B4 * 0.000556640625);
    if ((v15 & 0x80000000) != 0)
        LOBYTE(v15) = 0;
    drawTurboBar_43B3A0((unsigned __int8)v15 + dword_464F14 + 3684, 58 - (unsigned __int8)v15, 7, 0);
    if (raceParticipant2[userRaceOrder_4A9EA8].useWeapons)
    {
        v16 = (unsigned __int64)((double)raceParticipant2[userRaceOrder_4A9EA8].weaponsBar_4A68B0 * 0.000537109375);
        if ((v16 & 0x80000000) != 0)
            LOBYTE(v16) = 0;
        drawWeaponsBar_43BEF0(a1, (void*)((unsigned __int8)v16 + dword_464F14 + 9828), 55 - (unsigned __int8)v16, 3, 0);
        v17 = 0;
        if (raceParticipant2[userRaceOrder_4A9EA8].mines > 0)
        {
            v18 = 6752;
            do
            {
                drawImageInRace_43B240((int)sidebom1Bpk_481E04, 8, 6, v18 + dword_464F14);
                ++v17;
                v18 += 8;
            } while (v17 < raceParticipant2[userRaceOrder_4A9EA8].mines);
        }
    }
    else if (ticksToPauseLapTimeInHud_4A9EB0 <= 0)//si no usas weapons ponemos el tiempo vale 0 si no has terminado la vuelta
    {
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, currentLapTime_481E0C / 70 / 60, 16, 8315, -6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, currentLapTime_481E0C / 70 % 60, 16, 8329, 6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42), 16, 8343, 6, 0);
    }
    else
    {
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 / 60, 16, 8315, -6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 % 60, 16, 8329, 6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(lastCompletedLapTime_503224 % 70) * 1.42), 16, 8343, 6, 0);
        ticksToPauseLapTimeInHud_4A9EB0 -= dword_4A9EA4;
        if (ticksToPauseLapTimeInHud_4A9EB0 < 0)
            ticksToPauseLapTimeInHud_4A9EB0 = 0;
    }
    v19 = 100.0 - ceil((double)raceParticipant2[userRaceOrder_4A9EA8].damageBar_4A6898 * 0.0009765625);
    drawSprite_402590((int)&bugnum6Bpk_46E560, 8, 10, (unsigned __int64)v19, 0, 11408, -8, -16);
    //TODO FIX drawImageInRace_43B240((int)&unk_46E880, 8, 10, v20 + dword_464F14);
    v21 = userRaceOrder_4A9EA8;
    if (raceParticipant2[userRaceOrder_4A9EA8].damageBar_4A6898 < 20480)
    {
        if (!criticalDamageSoundPlayed_456ADC)
        {
            //SOUND_CRIT_DAMAGE
            loadMenuSoundEffect(2u, 1, 0, 0x10000, 327680);
            v21 = userRaceOrder_4A9EA8;
        }
        criticalDamageSoundPlayed_456ADC = 1;
    }
    if (raceParticipant2[v21].damageBar_4A6898 < 10240)
    {
        if (!criticalDamage2SoundPlayed_456AE0)
        {
            //SOUND_CRIT_DAMAGE
            loadMenuSoundEffect(2u, 1, 0, 0x10000, 327680);
            v21 = userRaceOrder_4A9EA8;
        }
        criticalDamage2SoundPlayed_456AE0 = 1;
    }
    result = raceParticipant2[v21].damageBar_4A6898;
    if (!result)
    {
        result = 0;
        //si es duke nukem
        if (!memcmp(raceParticipant[v21].name, &dukeNukemName, 0xBu))
        {
            result = dukeNukemEndRaceSoundPlayed_456AE8;
            if (!dukeNukemEndRaceSoundPlayed_456AE8)
            {

                //SOUND_THIS_SUCKS
                result = loadMenuSoundEffect(2u, 32, 0, 0x10000, 327680);
            }
            dukeNukemEndRaceSoundPlayed_456AE8 = 1;
        }
    }
    return result;
}

//----- (00414110) --------------------------------------------------------
int  drawSmallLeftBar_414110(int a1)
{
    int v1; // ST00_4@1

    dword_4A9EA4 = dword_503500 - dword_4A7CFC;
    v1 = (dword_503500 - dword_4A7CFC) << 16;
    dword_4A7CFC = dword_503500;
    dword_4AA500 = colorToPaletteEntry(v1, 0x20000);
    if (raceFrame_481E14 > 190 && !raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C)
    {
        totalRaceTime_50A164 += dword_4A9EA4;
        currentLapTime_481E0C += dword_4A9EA4;
        totalRaceMinutes_45EEC0 = totalRaceTime_50A164 / 70 / 60;
        totalRaceSeconds_45EEBC = totalRaceTime_50A164 / 70 % 60;
        totalRaceMilliseconds_462D74 = (unsigned __int64)((double)(totalRaceTime_50A164 % 70) * 1.42);
        currentLapMinutes_45EA64 = currentLapTime_481E0C / 70 / 60;
        currentLapSeconds_463CD4 = currentLapTime_481E0C / 70 % 60;
        currentLapMilliseconds_45FC1C = (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42);
    }
    if (ticksToPauseLapTimeInHud_4A9EB0 > 0)
    {
        ticksToPauseLapTimeInHud_4A9EB0 -= dword_4A9EA4;
        if (ticksToPauseLapTimeInHud_4A9EB0 < 0)
            ticksToPauseLapTimeInHud_4A9EB0 = 0;
    }
    return drawSmallLeftBar_413C90(a1);
}

//----- (00414220) --------------------------------------------------------
int drawLeftRaceBar_414220()
{
    int v0; // ST3C_4@1
    char v1; // bl@1
    int v2; // edi@6
    const void* v3; // esi@6
    int v4; // eax@8
    int v5; // edi@8
    int v6; // esi@9
    int v7; // eax@13
    int v8; // esi@14
    signed int v9; // edx@15
    int i; // eax@16
    int v11; // ebp@20
    signed int v12; // esi@20
    signed int v13; // edi@21
    signed int v14; // eax@23
    signed int v15; // esi@23
    signed int v16; // edi@24
    unsigned __int64 v17; // rax@27
    int v18; // ebp@27
    unsigned __int64 v19; // rax@31
    int v20; // ebp@31
    unsigned __int64 v21; // rax@35
    int v22; // ebp@35
    signed int v23; // esi@38
    signed int v24; // edi@39
    int v25; // edx@41
    int v26; // eax@41
    signed int v27; // esi@41
    int v28; // edx@42
    int v29; // edi@42
    bool v30; // zf@42
    bool v31; // sf@42
    unsigned __int8 v32; // of@42
    int v33; // ecx@45
    int v34; // eax@45
    int v35; // eax@46
    int v36; // eax@47
    int v37; // ecx@47
    int v38; // edi@47
    int v39; // eax@47
    int v40; // eax@49
    int v41; // ecx@49
    int v42; // edi@49
    int v43; // eax@49
    signed int v44; // esi@52
    signed int v45; // edi@53
    int v46; // eax@55
    int v47; // esi@55
    int v48; // edx@55
    int v49; // ecx@55
    double v50; // st7@55
    unsigned __int64 v51; // rax@55
    signed int v52; // ecx@55
    signed int v53; // esi@58
    unsigned __int64 v54; // rax@62
    int v55; // esi@64
    signed int v56; // edi@65
    signed int v57; // edx@71
    unsigned __int64 v58; // rax@72
    unsigned __int64 v59; // rax@74
    int v60; // eax@74
    int v61; // eax@74
    unsigned __int64 v62; // rax@87
    int result; // eax@89
    int v64; // esi@89
    int v65; // edi@90
    signed int v66; // [sp+18h] [bp-4h]@27
    signed int v67; // [sp+18h] [bp-4h]@31
    signed int v68; // [sp+18h] [bp-4h]@35
    signed int aux;
    dword_4A9EA4 = dword_503500 - dword_4A7CFC;
    v0 = (dword_503500 - dword_4A7CFC) << 16;
    dword_4A7CFC = dword_503500;
    dword_4AA500 = colorToPaletteEntry(v0, 0x20000);
    v1 = 0;
    if (raceFrame_481E14 > 190 && !raceParticipantIngame[userRaceOrder_4A9EA8].hasFinishedTheRace_4A7E0C)
    {
        totalRaceTime_50A164 += dword_4A9EA4;
        currentLapTime_481E0C += dword_4A9EA4;
        totalRaceMinutes_45EEC0 = totalRaceTime_50A164 / 70 / 60;
        totalRaceSeconds_45EEBC = totalRaceTime_50A164 / 70 % 60;
        totalRaceMilliseconds_462D74 = (unsigned __int64)((double)(totalRaceTime_50A164 % 70) * 1.42);
        currentLapMinutes_45EA64 = currentLapTime_481E0C / 70 / 60;
        currentLapSeconds_463CD4 = currentLapTime_481E0C / 70 % 60;
        currentLapMilliseconds_45FC1C = (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42);
    }
    if (leftMenuInRaceWidth_456AA0 < 64)
        drawSmallLeftBar_413C90(0);
    v2 = 0;

    v3 = boardsBPK_4AA940[0];
    aux = 0;
    do
    {
        copyBuffer2Screen((void*)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
        v3 = (char*)v3 + 64;
        aux += 64;
        v2 += 512;
    } while ((signed int)aux < 6700);

    v3 = boardsBPK_4AA940[1];

    aux = 0;
    do
    {
        copyBuffer2Screen((void*)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
        v3 = (char*)v3 + 64;
        aux += 1;
        v2 += 512;
    } while ((signed int)aux < 32);

    v3 = boardsBPK_4AA940[2];
    aux = 0;
    do
    {
        copyBuffer2Screen((void*)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
        v3 = (char*)v3 + 64;
        aux += 1;
        v2 += 512;
    } while ((signed int)aux < 32);
    v3 = boardsBPK_4AA940[3];
    aux = 0;
    do
    {
        copyBuffer2Screen((void*)(v2 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 32), v3, 16);
        v3 = (char*)v3 + 64;
        aux += 1;
        v2 += 512;
    } while ((signed int)aux < 32);
    //while ( (signed int)v3 < (signed int)&unk_4ADB40 );


    v4 = numberOfParticipants_508D24;
    v5 = 0;

    //pinta la bandera de llegada sobre el partipante
    if (numberOfParticipants_508D24 > 0)
    {
        v6 = 0;
        do
        {
            if (raceParticipantIngame[participantRaceOrderUserFirst_508D44[v5]].hasFinishedTheRace_4A7E0C)
            {
                drawImageInRace_43B240((int)goalnum2Bpk_4AA50C, 22, 28, v6 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 39972);
                v4 = numberOfParticipants_508D24;
            }
            ++v5;
            v6 += 0x4000;
        } while (v5 < v4);
    }
    v7 = v4 - 1;
    if (v7 < 3)
    {
        v8 = 32 * v7;
        do
        {
            v9 = 0;
            do
            {
                for (i = v9 % 2; i < 64; i += 2)
                    *(BYTE*)(leftMenuInRaceWidth_456AA0 + ((v8 + v9) << 9) + dword_464F14 + i + 53280) = 0;
                ++v9;
            } while (v9 < 32);
            v8 += 32;
        } while (v8 < 96);
    }
    drawImageInRace_43B240((int)((char*)&bugnum6Bpk_46E560 + 80 * numberOfLaps), 8, 10, dword_464F14 + leftMenuInRaceWidth_456AA0 + 46133);
    v11 = 1;
    v12 = 1;
    if (numberOfParticipants_508D24 > 1)
    {
        v13 = 0x4000;
        do
        {
            drawImageInRace_43B240((int)((char*)&bugnum6Bpk_46E560 + 80 * numberOfLaps), 8, 10, v13 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 46138);
            ++v12;
            v13 += 0x4000;
        } while (v12 < numberOfParticipants_508D24);
    }
    drawImageInRace_43B240(
        (int)((char*)&bugnum6Bpk_46E560 + 80 * (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[0]].currentLap_4A7E08),
        8,
        10,
        dword_464F14 + leftMenuInRaceWidth_456AA0 + 46114);
    v14 = numberOfParticipants_508D24;
    v15 = 1;
    if (numberOfParticipants_508D24 > 1)
    {
        v16 = 0x4000;
        do
        {
            drawImageInRace_43B240(
                (int)((char*)&bugnum6Bpk_46E560 + 80 * (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[v15]].currentLap_4A7E08), 8, 10, v16 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 46116);
            v14 = numberOfParticipants_508D24;
            ++v15;
            v16 += 0x4000;
        } while (v15 < numberOfParticipants_508D24);
        if (numberOfParticipants_508D24 > 1)
        {
            v17 = (unsigned char)(64.0 - ceil((double)raceParticipant2[participantRaceOrderUserFirst_508D44[1]].damageBar_4A6898 * 0.0009765625) * 0.6369426751592356);

            HIDWORD(v17) = -(signed int)v17;
            v18 = -(signed int)v17;
            v66 = 9;
            do
            {
                memcpy((void*)(v18 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 53344), (char*)damslidBpk + HIDWORD(v17) + 64, v17);
                HIDWORD(v17) += 64;
                v18 += 512;
                --v66;
            } while (v66);
            v14 = numberOfParticipants_508D24;
            v11 = 1;
            v1 = 0;
        }
    }
    if (v14 > 2)
    {
        v19 = (unsigned char)(64.0 - ceil((double)raceParticipant2[participantRaceOrderUserFirst_508D44[2]].damageBar_4A6898 * 0.0009765625) * 0.6369426751592356);
        HIDWORD(v19) = -(signed int)v19;
        v20 = -(signed int)v19;
        v67 = 9;
        do
        {
            memcpy((void*)(v20 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 69728), (char*)damslidBpk + HIDWORD(v19) + 64, v19);
            HIDWORD(v19) += 64;
            v20 += 512;
            --v67;
        } while (v67);
        v14 = numberOfParticipants_508D24;
        v1 = 0;
        v11 = 1;
    }
    if (v14 > 3)
    {
        v21 = (unsigned char)(64.0 - ceil((double)raceParticipant2[participantRaceOrderUserFirst_508D44[3]].damageBar_4A6898 * 0.0009765625) * 0.6369426751592356);//dword_508D50->3 y los de arriba 2 y 1
        HIDWORD(v21) = -(signed int)v21;
        v22 = -(signed int)v21;
        v68 = 9;
        do
        {
            memcpy((void*)(v22 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 86112), (char*)damslidBpk + HIDWORD(v21) + 64, v21);
            HIDWORD(v21) += 64;
            v22 += 512;
            --v68;
        } while (v68);
        v11 = 1;
        v1 = 0;
    }
    writeTextInRace_402510(leftMenuInRaceWidth_456AA0 + 1059, raceParticipant2[participantRaceOrderUserFirst_508D44[0]].name);
    v23 = 1;
    if (numberOfParticipants_508D24 > 1)
    {
        v24 = 0x4000;
        do
        {
            writeTextInRace_402510(v24 + leftMenuInRaceWidth_456AA0 + 37923, raceParticipant2[participantRaceOrderUserFirst_508D44[v23++]].name);
            v24 += 0x4000;
        } while (v23 < numberOfParticipants_508D24);
    }
    v25 = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[1]].racePosition_4A7E09;
    racePositionTemp_481BD0[0] = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[0]].racePosition_4A7E09;
    racePositionTemp_481BD0[1] = v25;
    v26 = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[3]].racePosition_4A7E09;
    racePositionTemp_481BD0[2] = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[2]].racePosition_4A7E09;
    racePositionTemp_481BD0[3] = v26;
    v27 = 0;
    do
    {
        v28 = racePositionTemp_481BD0[v27];
        v29 = racePositionUserFirst_46E8D0[v27];
        v32 = __OFSUB__(v28, v29);
        v30 = v28 == v29;
        v31 = v28 - v29 < 0;
        if (v28 < v29)
        {
            dword_4A8A90[v27] = 458752 * v29 - 458752;
            dword_4AA3F0[v27] = 7 * v28 - 7;
            v1 = 0;
            dword_4A7CC0[v27] = (v28 - v29) << 16;
            v32 = __OFSUB__(v28, v29);
            v30 = v28 == v29;
            v31 = v28 - v29 < 0;
        }
        if (!((unsigned __int8)(v31 ^ v32) | v30))
        {
            v33 = racePositionUserFirst_46E8D0[v27];
            v34 = racePositionTemp_481BD0[v27];
            dword_4A8A90[v27] = 458752 * racePositionUserFirst_46E8D0[v27] - 458752;
            dword_4AA3F0[v27] = 7 * v34 - 7;
            dword_4A7CC0[v27] = (v34 - v33) << 16;
        }
        v35 = dword_4A7CC0[v27];
        if ((signed int)((v35 + 0x8000) & 0xFFFF0000) <= 0)
        {
            v40 = convertColorToPaletteColor(v35, dword_4AA500);
            v41 = dword_4AA3F0[v27];
            v42 = v40 + dword_4A8A90[v27];
            v43 = (v40 + dword_4A8A90[v27] + 0x8000) >> 16;
            dword_4A8A90[v27] = v42;
            if (v43 < v41)
                dword_4A8A90[v27] = 458752 * racePositionTemp_481BD0[v27] - 458752;
        }
        else
        {
            v36 = convertColorToPaletteColor(v35, dword_4AA500);
            v37 = dword_4AA3F0[v27];
            v38 = v36 + dword_4A8A90[v27];
            v39 = (v36 + dword_4A8A90[v27] + 0x8000) >> 16;
            dword_4A8A90[v27] = v38;
            if (v39 > v37)
                dword_4A8A90[v27] = 458752 * racePositionTemp_481BD0[v27] - 458752;
        }
        ++v27;
    } while (v27 < 4);
    //;;;;;aqui falla y en principio esta todo bien
    drawInRaceImageToBuffer_43B160(
        (int)((char*)&ownnum1Bpk_503520 + 1024 * ((dword_4A8A90[0] + 0x8000) >> 16)),
        32,
        32,
        dword_464F14 + leftMenuInRaceWidth_456AA0 + 36928);
    v44 = 1;
    if (numberOfParticipants_508D24 > 1)
    {
        v45 = 0x4000;
        do
        {
            drawInRaceImageToBuffer_43B160(
                (int)((char*)&othnum1Bpk_50B2C0 + 576 * ((dword_4A8A90[v44++] + 0x8000) >> 16)),///parece la posicion
                24,
                24,
                v45 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 41032);
            v45 += 0x4000;
        } while (v44 < numberOfParticipants_508D24);
    }
    v46 = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[1]].racePosition_4A7E09;//raceposition1
    v47 = userRaceOrder_4A9EA8;
    racePositionUserFirst_46E8D0[0] = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[0]].racePosition_4A7E09;//raceposition2
    v48 = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[2]].racePosition_4A7E09;//raceposition3
    racePositionUserFirst_46E8D0[1] = v46;
    v49 = (unsigned __int8)raceParticipantIngame[participantRaceOrderUserFirst_508D44[3]].racePosition_4A7E09;//raceposition4
    racePositionUserFirst_46E8D0[2] = v48;
    v50 = raceParticipantIngame[userRaceOrder_4A9EA8].carVelocity_4A7DB0;
    racePositionUserFirst_46E8D0[3] = v49;
    v51 = (unsigned __int64)(v50 / raceParticipant2[userRaceOrder_4A9EA8].efectiveEngine_4A6884 * -162.0);
    v52 = 1 - v51;
    if (v11 - (signed int)v51 < v11)
        v52 = 1;
    if (v52 < 162)
    {
        v53 = v52;
        do
        {
            sub_43C7E0(
                leftMenuInRaceWidth_456AA0 + dword_464F14 + (dword_4B3160[v53] << 9) + dword_503240[v53] + 32,
                dword_503240[v53],
                32,
                33 - dword_4B3160[v53],
                v1);
            ++v53;
        } while (v53 < 162);
        v47 = userRaceOrder_4A9EA8;
    }
    if (raceParticipant2[userRaceOrder_4A9EA8].useWeapons)
    {
        v54 = (unsigned __int64)((double)raceParticipant2[v47].weaponsBar_4A68B0 * 0.000537109375);
        if ((v54 & 0x80000000) != 0)
            LOBYTE(v54) = 0;
        drawWeaponsBar_43BEF0(0, (void*)(dword_464F14 + (unsigned __int8)v54 + leftMenuInRaceWidth_456AA0 + 24100), 55 - (unsigned __int8)v54, 3, 0);
        v55 = 0;
        if (raceParticipant2[userRaceOrder_4A9EA8].mines > 0)
        {
            v56 = 21024;
            do
            {
                drawImageInRace_43B240((int)sidebom1Bpk_481E04, 8, 6, leftMenuInRaceWidth_456AA0 + v56 + dword_464F14);
                ++v55;
                v56 += 8;
            } while (v55 < raceParticipant2[userRaceOrder_4A9EA8].mines);
        }
    }
    else if (ticksToPauseLapTimeInHud_4A9EB0 <= 0)
    {
        v57 = (signed int)(currentLapTime_481E0C / 70 + ((unsigned int)(-2004318071 * (currentLapTime_481E0C / 70)) >> 32)) >> 5;
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, v57 + ((unsigned int)v57 >> 31), 16, leftMenuInRaceWidth_456AA0 + 22587, -6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, currentLapTime_481E0C / 70 % 60, 16, leftMenuInRaceWidth_456AA0 + 22601, 6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(currentLapTime_481E0C % 70) * 1.42), 16, leftMenuInRaceWidth_456AA0 + 22615, 6, 0);
    }
    else
    {
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 / 60, 16, leftMenuInRaceWidth_456AA0 + 22587, -6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, lastCompletedLapTime_503224 / 70 % 60, 16, leftMenuInRaceWidth_456AA0 + 22601, 6, 0);
        drawSprite_402590((int)&smalfo4aBpk_4A9160, 6, 6, (unsigned __int64)((double)(lastCompletedLapTime_503224 % 70) * 1.42), 16, leftMenuInRaceWidth_456AA0 + 22615, 6, 0);
        ticksToPauseLapTimeInHud_4A9EB0 -= dword_4A9EA4;
        if (ticksToPauseLapTimeInHud_4A9EB0 < 0)
            ticksToPauseLapTimeInHud_4A9EB0 = 0;
    }
    v58 = (unsigned __int64)((double)raceParticipant2[userRaceOrder_4A9EA8].turboBar_4A68B4 * 0.000556640625);
    if ((v58 & 0x80000000) != 0)
        LOBYTE(v58) = 0;
    drawTurboBar_43B3A0(dword_464F14 + (unsigned __int8)v58 + leftMenuInRaceWidth_456AA0 + 17444, 58 - (unsigned __int8)v58, 7, v1);
    v59 = (unsigned __int64)(100.0 - ceil((double)raceParticipant2[userRaceOrder_4A9EA8].damageBar_4A6898 * 0.0009765625));
    v60 = drawSprite_402590((int)&bugnum6Bpk_46E560, 8, 10, v59, 0, leftMenuInRaceWidth_456AA0 + 36398, -8, -16);
    drawImageInRace_43B240((int)&unk_46E880, 8, 10, v60 + dword_464F14);
    v61 = userRaceOrder_4A9EA8;
    if (raceParticipant2[userRaceOrder_4A9EA8].damageBar_4A6898 < 20480)
    {
        if (!criticalDamageSoundPlayed_456ADC)
        {
            loadMenuSoundEffect(2u, v11, 0, 0x10000, 327680);
            v61 = userRaceOrder_4A9EA8;
        }
        criticalDamageSoundPlayed_456ADC = 1;
    }
    if (raceParticipant2[v61].damageBar_4A6898 < 10240)
    {
        if (!criticalDamage2SoundPlayed_456AE0)
        {
            loadMenuSoundEffect(2u, v11, 0, 0x10000, 327680);
            v61 = userRaceOrder_4A9EA8;
        }
        criticalDamage2SoundPlayed_456AE0 = 1;
    }
    if (!raceParticipant2[v61].damageBar_4A6898 && !memcmp(raceParticipant[v61].name, &dukeNukemName, 0xBu))
    {
        if (!dukeNukemEndRaceSoundPlayed_456AE8)
        {
            loadMenuSoundEffect(2u, GEN_EFE_HAIL_TO_THE_KING, 0, 0x10000, 327680);
            v61 = userRaceOrder_4A9EA8;
        }
        dukeNukemEndRaceSoundPlayed_456AE8 = 1;
    }
    v62 = (unsigned char)ceil((double)raceParticipant2[v61].damageBar_4A6898 * 0.000048828125);
    if ((v62 & 0x80000000) != 0)
        LODWORD(v62) = 0;
    // drawInRaceImageToBuffer_43B160((int)((char *)&unk_4669C0 - 1344 * v62), 64, 21, dword_464F14 + leftMenuInRaceWidth_456AA0 + 25632);
    drawInRaceImageToBuffer_43B160((int)((char*)&damageBpk_464F80 + 6720 - 1344 * v62), 64, 21, dword_464F14 + leftMenuInRaceWidth_456AA0 + 25632);
    result = numberOfParticipants_508D24;
    v64 = 0;
    if (numberOfParticipants_508D24 > 0)
    {
        v65 = 0;
        do
        {
            if (raceParticipant2[participantRaceOrderUserFirst_508D44[v64]].damageBar_4A6898 <= 0)
                drawImageInRace_43B240((int)rast1Bpk_464F78, 64, 32, v65 + dword_464F14 + leftMenuInRaceWidth_456AA0 + 36896);

            result = numberOfParticipants_508D24;
            ++v64;
            v65 += 0x4000;
        } while (v64 < numberOfParticipants_508D24);
    }
    return result;
}

//----- (0043B3A0) --------------------------------------------------------
int   drawTurboBar_43B3A0(int a1, int a2, int a3, char a4)
{
    int result; // eax@1
    int v5; // edi@2
    int v6; // ecx@4

    result = a3;
    if (a3 > 0)
    {
        v5 = a3;
        result = a1;
        do
        {
            if (a2 > 0)
            {
                v6 = a2;
                do
                {
                    if (*(BYTE*)result >= 0x40u)
                        *(BYTE*)result = a4;
                    ++result;
                    --v6;
                } while (v6);
            }
            result += 512 - a2;
            --v5;
        } while (v5);
    }
    return result;
}
//----- (0043BEF0) --------------------------------------------------------
int  drawWeaponsBar_43BEF0(int a1, void* a2, unsigned int a3, int a4, char a5)
{
    int result; // eax@1
    void* v6; // ebp@2
    int v7; // eax@4

    result = a4;
    if (a4 > 0)
    {
        v6 = a2;
        do
        {
            if ((signed int)a3 > 0)
            {
                LOBYTE(a1) = a5;
                BYTE1(a1) = a5;
                v7 = a1 << 16;
                LOWORD(v7) = a1;
                memset(v6, v7, (a3 >> 2) * 4);
                memset((char*)v6 + 4 * (a3 >> 2), a5, a3 & 3);
                v6 = (char*)v6 + a3;
            }
            result = 512 - a3;
            v6 = (char*)v6 + 512 - a3;
            --a4;
        } while (a4);
    }
    return result;
}
