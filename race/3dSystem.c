#include "3dSystem.h"
#include "../defs.h"
#include "../dr.h"

Sce3DObject sce2Texture[100];
Sce4Texture sce4Texture[100];

int trxSCE1Number3DObjects_479D20; // weak
int trxSCE3Bpk_464F10; // weak
void* trxSCE5Bpk_4A7A28; // idb

int dword_4AA928; // weak
int dword_467020[7504]; // weak
float flt_4A8AC0[256]; // weak
float flt_4A8C00[256]; // weak
float flt_4A9A60[256]; // weak

int dword_46F220[1000][100]; // weak
int dword_4A6AFC; // weak
_UNKNOWN unk_46ED00; // weak
_UNKNOWN unk_4A7BC0; // weak
_UNKNOWN unk_4AA400; // weak
int textureTemp[0xFFFFFu];

//----- (0040A360) --------------------------------------------------------
int processSceFile_40A360()
{
    int result; // eax@1
    int v1; // ebp@1
    int v2; // esi@2
    int v3; // ebx@6
    int v4; // eax@7
    int v5; // edx@7
    int v6; // ecx@8
    int v7; // esi@9
    int v8; // esi@12
    int v9; // edi@12
    unsigned int v10; // eax@13
    unsigned int v11; // ecx@13
    double v12; // st7@13
    unsigned int v13; // edx@13
    double v14; // st6@13
    double v15; // st4@13
    double v16; // st2@13
    double v17; // ST48_8@13
    double v18; // ST40_8@13
    double v19; // st6@13
    double v20; // st5@13
    double v21; // st7@13
    double v22; // st7@13
    long double v23; // st6@14
    long double v24; // ST40_8@14
    long double v25; // st7@14
    long double v26; // st6@14
    long double v27; // st5@14
    int v28; // eax@16
    int v29; // ecx@16
    int v30; // edx@16
    int v31; // ebx@17
    int v32; // esi@17
    void* v33; // edi@18
    long double v34; // st7@18
    double v35; // st6@20
    double v36; // st6@21
    long double v37; // st6@23
    long double v38; // st6@23
    long double v39; // st6@25
    long double v40; // st5@25
    unsigned __int64 v41; // rax@26
    bool v42; // zf@29
    int v43; // [sp+10h] [bp-48h]@2
    void* v44; // [sp+14h] [bp-44h]@2
    double v45; // [sp+18h] [bp-40h]@13
    float v46; // [sp+18h] [bp-40h]@23
    double v47; // [sp+20h] [bp-38h]@13
    float v48; // [sp+20h] [bp-38h]@23
    int v49; // [sp+28h] [bp-30h]@2
    int v50; // [sp+2Ch] [bp-2Ch]@2
    double v51; // [sp+30h] [bp-28h]@13
    float v52; // [sp+30h] [bp-28h]@23
    int v53; // [sp+3Ch] [bp-1Ch]@2
    double v54; // [sp+50h] [bp-8h]@25
    int id3dObject = 0;
    result = trxSCE1Number3DObjects_479D20;
    v1 = 0;
    dword_4AA928 = 0;
    if (trxSCE1Number3DObjects_479D20 > 0)
    {
        //v2 = (int)trxSCE2Bpk_4B4320;
        v49 = 0;
        v44 = dword_467020;
        //v43 = (int)trxSCE2Bpk_4B4320;
        v43 = 0;
        //v50 = (int)dword_4B484C;
        v53 = trxSCE1Number3DObjects_479D20;
        dword_4AA928 = trxSCE1Number3DObjects_479D20;
        while (1)
        {

            if (sce2Texture[id3dObject].trxSCE2Bpk_4B4320 > 0)
                memset(v44, 0, 4 * sce2Texture[id3dObject].trxSCE2Bpk_4B4320);
            v3 = sce2Texture[id3dObject].numberTriangles_4B4324;
            if (v3 > 0)
            {
                // v4 = v2 + 1324;
                v4 = 0;
                v5 = sce2Texture[id3dObject].numberTriangles_4B4324;
                do
                {

                    //dword_467020 es una estructura de 300 bytes
                    ++dword_467020[v1 + sce2Texture[id3dObject].dword_4B46BC[v4]];
                    ++dword_467020[v1 + sce2Texture[id3dObject].dword_4B484C[v4]];
                    v6 = v1 + sce2Texture[id3dObject].dword_4B49DC[v4];
                    v4 += 1;
                    --v5;
                    ++dword_467020[v6];
                } while (v5);
            }
            v7 = sce2Texture[id3dObject].trxSCE2Bpk_4B4320;
            if (v7 > 0)
            {
                memset(flt_4A8C00, 0, 4 * ((unsigned int)(4 * v7) >> 2));
                memset(flt_4A8AC0, 0, 4 * ((unsigned int)(4 * v7) >> 2));
                memset(flt_4A9A60, 0, 4 * ((unsigned int)(4 * v7) >> 2));
            }
            if (v3 > 0)
            {
                //v8 = v50;
                v8 = 0;
                v9 = v3;
                do
                {
                    v10 = 4 * (sce2Texture[id3dObject].dword_4B46BC[v8 + v49]);
                    v11 = 2 * (sce2Texture[id3dObject].dword_4B484C[v8 + v49]);
                    v12 = (double)sce2Texture[id3dObject].dword_4B4328[v10 / 2] * 0.00390625; //ver si el /2 esta bien
                    v13 = 2 * (sce2Texture[id3dObject].dword_4B49DC[v8 + v49]);
                    v14 = (double)sce2Texture[id3dObject].dword_4B4454[v10 / 4] * 0.00390625;
                    v15 = (double)(sce2Texture[id3dObject].dword_4B4580[v10 / 4] - 256);
                    v16 = (double)(sce2Texture[id3dObject].dword_4B4580[v13 / 2] - 256) - v15;
                    v17 = (double)sce2Texture[id3dObject].dword_4B4454[v11 / 2] * 0.00390625 - v14;
                    v18 = (double)(sce2Texture[id3dObject].dword_4B4580[v11 / 2] - 256) - v15;
                    v19 = (double)sce2Texture[id3dObject].dword_4B4454[v13 / 2] * 0.00390625 - v14;
                    v47 = v17 * v16 - v19 * v18;
                    //v20 = (double)*(signed int *)&dword_4B4328[v13] * 0.00390625 - v12;
                    //v21 = (double)*(signed int *)&dword_4B4328[v11] * 0.00390625 - v12;
                    v20 = sce2Texture[id3dObject].dword_4B4328[v13] * 0.00390625 - v12;
                    v21 = sce2Texture[id3dObject].dword_4B4328[v11] * 0.00390625 - v12;


                    v45 = v20 * v18 - v21 * v16;
                    v51 = v21 * v19 - v20 * v17;
                    v22 = v51 * v51 + v45 * v45 + v47 * v47;
                    if (v22 <= 1.0)
                    {
                        v25 = 100.0;
                        v26 = 100.0;
                        v27 = 100.0;
                    }
                    else
                    {
                        v23 = sqrt(10000.0 / v22);
                        v24 = v23;
                        v25 = v23 * v47;
                        v26 = v23 * v45;
                        v27 = v24 * v51;
                    }
                    //v28 = 4 * sce2Texture[polygonIndex].dword_4B46BC[v8];
                    //v29 = 4 * sce2Texture[polygonIndex].dword_4B484C[v8];
                    //v30 = 4 * sce2Texture[polygonIndex].dword_4B49DC[v8];
                    v28 = sce2Texture[id3dObject].dword_4B46BC[v8];
                    v29 = sce2Texture[id3dObject].dword_4B484C[v8];
                    v30 = sce2Texture[id3dObject].dword_4B49DC[v8];

                    v8 += 1;
                    --v9;
                    flt_4A9A60[v28] += v25;
                    flt_4A9A60[v29] += v25;
                    flt_4A9A60[v30] += v25;

                    flt_4A8AC0[v28] += v26;
                    flt_4A8AC0[v29] += v26;
                    flt_4A8AC0[v30] += v26;

                    flt_4A8C00[v28] += v27;
                    flt_4A8C00[v29] += v27;
                    flt_4A8C00[v30] += v27;

                } while (v9);
            }
            //v31 = *(_DWORD *)v43;
            v31 = sce2Texture[0].trxSCE2Bpk_4B4320;
            v32 = 0;
            if (sce2Texture[id3dObject].trxSCE2Bpk_4B4320 > 0)
            {
                v33 = v44;
                v34 = sqrt(350.0);
                do
                {
                    if (*(_DWORD*)v33 >= 1)
                    {
                        v35 = 1.0 / (double)*(signed int*)v33;
                        flt_4A9A60[v32] = v35 * flt_4A9A60[v32];
                        flt_4A8AC0[v32] = v35 * flt_4A8AC0[v32];
                        flt_4A8C00[v32] = v35 * flt_4A8C00[v32];
                    }
                    v36 = flt_4A8C00[v32] * flt_4A8C00[v32]
                        + flt_4A8AC0[v32] * flt_4A8AC0[v32]
                        + flt_4A9A60[v32] * flt_4A9A60[v32];
                    if (v36 < 1.0)
                        v36 = 1.0;
                    v37 = sqrt(10000.0 / v36);
                    v46 = flt_4A9A60[v32] * v37;
                    flt_4A9A60[v32] = v46;
                    v48 = flt_4A8AC0[v32] * v37;
                    flt_4A8AC0[v32] = v48;
                    v38 = v37 * flt_4A8C00[v32];
                    flt_4A8C00[v32] = v38;
                    v52 = v38 * v38 + v48 * v48;
                    if (v46 * v46 + v52 < 1.0)
                        flt_4A9A60[v32] = v46 + 1.0;
                    v39 = v48 * -10.0 - v38 * 15.0 - flt_4A9A60[v32] * 10.0;
                    v40 = sqrt(flt_4A9A60[v32] * flt_4A9A60[v32] + v52);
                    v54 = v39 / (v40 * v34);
                    if (v54 <= 0.0)
                        v41 = (unsigned __int64)((v39 / (sqrt(425.0) * v40) + 1.0) * 3.0);
                    else
                        v41 = (unsigned __int64)(v54 * 5.0 + 3.0);
                    *(_DWORD*)v33 = v41;
                    ++v32;
                    v33 = (char*)v33 + 4;
                } while (v32 < sce2Texture[id3dObject].trxSCE2Bpk_4B4320);
            }
            v1 += 75;
            result = v53 - 1;
            v42 = v53 == 1;
            //v49 += 788;
            v49++;
            //v50 += 3152;
            //v43 += 3152;
            v43 += 1;
            id3dObject++;
            v44 = (char*)v44 + 300;
            --v53;
            if (v42)
                break;
            //v2 = v43;
        }
    }
    return result;
}

//----- (0040A880) --------------------------------------------------------
int calculateSceTextureStructure_40A880()
{
    int v0; // edx@1
    void* v1; // ebx@2
    int* v2; // esi@2
    int v3; // ebp@2
    int v4; // edx@3
    bool v5; // zf@3
    bool v6; // sf@3
    int result; // eax@7
    int v8; // ebp@8
    int v9; // ebx@8
    int v10; // ecx@9
    int v11; // edi@9
    int v12; // edx@10
    int v13; // esi@11
    int v14; // ecx@14
    int* v15; // [sp+10h] [bp-8h]@8
    int v16; // [sp+14h] [bp-4h]@9
    int id3dObject = 0;
    v0 = trxSCE1Number3DObjects_479D20;
    if (trxSCE1Number3DObjects_479D20 > 0)
    {
        v1 = dword_46F220;
        // v2 = numberTriangles_4B4324;
        v3 = trxSCE1Number3DObjects_479D20;
        do
        {
            if (id3dObject == 11) {
                id3dObject = 11;
            }
            //v4 = *v2;
            v4 = sce2Texture[id3dObject].numberTriangles_4B4324;

            v5 = sce2Texture[id3dObject].numberTriangles_4B4324 == 0;
            v6 = sce2Texture[id3dObject].numberTriangles_4B4324 < 0;
            dword_481BE8 = 0;
            if (!v6 && !v5)
            {
                memset(v1, 0xFFu, 4 * v4);
                dword_481BE8 = v4;
            }
            //v2 += 788;
            id3dObject++;
            v1 = (char*)v1 + 400;

            --v3;
        } while (v3);
        v0 = trxSCE1Number3DObjects_479D20;
    }
    result = 0;
    dword_4AA928 = 0;
    if (v0 > 0)
    {


        v8 = trxSCE3Bpk_464F10;
        v9 = 0;
        id3dObject = 0;
        //   v15 = numberTriangles_4B4324;
        do
        {
            v10 = sce2Texture[id3dObject].numberTriangles_4B4324;
            v11 = 0;
            v5 = sce2Texture[id3dObject].numberTriangles_4B4324 == 0;
            v6 = sce2Texture[id3dObject].numberTriangles_4B4324 < 0;
            dword_481BE8 = 0;
            v16 = v10;
            if (!v6 && !v5)
            {
                do
                {
                    //esto no se como va
                    v12 = 0;
                    dword_4A6AFC = 0;
                    if (v8 > 0)
                    {
                        v13 = 0;// &unk_50A1A8;
                        do
                        {
                            if (id3dObject == sce4Texture[v13].id3dObject_50A1A4 && v11 == sce4Texture[v13].idPolygon_50A1A8)
                            {
                                v14 = id3dObject + v11;
                                //if ( dword_46F220[v9 + v11] == -1 )
                                if (dword_46F220[id3dObject][v11] == -1)
                                    dword_46F220[id3dObject][v11] = v12;
                                else
                                    dword_46F220[id3dObject][v11] = v12;

                                //dword_46F220[v14-1] = v12;

                              //dword_46F21C[v14] = v12;
                            }
                            ++v12;
                            v13 = v13 + 1;//(char *)v13 + 44;
                        } while (v12 < v8);
                        v10 = v16;
                        dword_4A6AFC = v12;
                    }
                    ++v11;
                } while (v11 < v10);
                v0 = trxSCE1Number3DObjects_479D20;
                dword_481BE8 = v11;
            }
            ++result;
            id3dObject++;
            v9 += 1;//100;
         //   v15 += 788;
        } while (id3dObject < v0);
        dword_4AA928 = id3dObject;
    }
    return result;
}

//----- (0040D6B0) --------------------------------------------------------
void recalculatePolygonsInScreeenPosition_40D6B0()
{
    int v0; // edx@2
    int v1; // esi@2
    int v2; // edi@2
    _UNKNOWN* v3; // eax@2
    int v4; // ebx@3
    bool v5; // zf@3
    int v6; // [sp+0h] [bp-4h]@2
    int id3dObject = 0;
    dword_4AA928 = 0;
    if (trxSCE1Number3DObjects_479D20 > 0)
    {
        v0 = raceEffectiveHalfWidth_445014;
        v1 = raceEffectiveHalfHeight_44501C;
        v2 = circuitImageOffsetX_456ABC;
        // v3 = &unk_4B4D00;
        v6 = trxSCE1Number3DObjects_479D20;
        dword_4AA928 = trxSCE1Number3DObjects_479D20;
        do
        {
            v4 = circuitImageOffsetY_456AC0;
            sce2Texture[id3dObject].dword_4B4D04 = sce2Texture[id3dObject].unk_4B4CFC - raceEffectiveHalfWidth_445014 - circuitImageOffsetX_456ABC;
            //   sce2Texture[id3dObject].dword_4B4D04 = *((_DWORD *)v3 - 1) - raceEffectiveHalfWidth_445014 - circuitImageOffsetX_456ABC;

            sce2Texture[id3dObject].dword_4B4D08 = sce2Texture[id3dObject].unk_4B4D00 - raceEffectiveHalfHeight_44501C - circuitImageOffsetY_456AC0;
            v5 = strcmp(raceFilePrefix_45EA50, "TR0");
            strcpy(raceFilePrefix_45EA50, "TR0");
            sce2Texture[id3dObject].dword_4B4F64 = 0;//+153
           // if ( !v5 )
           // {
            if (sce2Texture[id3dObject].dword_4B4D04 << 8 > (raceEffectiveHalfWidth_445014 << 8) + sce2Texture[id3dObject].dword_4B46AC[1])// *((_DWORD *)v3 - 404) )
                sce2Texture[id3dObject].dword_4B4F64 = 1;
            if (sce2Texture[id3dObject].dword_4B4D04 << 8 < sce2Texture[id3dObject].dword_4B46AC[0] - (raceEffectiveHalfWidth_445014 << 8))//*((_DWORD *)v3 - 405
                sce2Texture[id3dObject].dword_4B4F64 = 1;
            if (sce2Texture[id3dObject].dword_4B4D08 << 8 > (raceEffectiveHalfHeight_44501C << 8) + sce2Texture[id3dObject].dword_4B46AC[3])//*((_DWORD *)v3 - 402) )
                sce2Texture[id3dObject].dword_4B4F64 = 1;
            if (sce2Texture[id3dObject].dword_4B4D08 << 8 < sce2Texture[id3dObject].dword_4B46AC[2] - (raceEffectiveHalfHeight_44501C << 8))//*((_DWORD *)v3 - 403)
                sce2Texture[id3dObject].dword_4B4F64 = 1;
            if (sce2Texture[id3dObject].dword_4B4F64 == 0) {
                sce2Texture[id3dObject].dword_4B4F64 = 0;
            }
            //}
          //v3 = (char *)v3 + 3152;
            id3dObject++;
            --v6;
        } while (v6);
    }
}

//----- (00411530) --------------------------------------------------------
int sub_411530()
{
    int v0; // edi@1
    int result; // eax@1
    int v2; // esi@1
    int v3; // ebx@2
    int v4; // ebp@2
    int v5; // ecx@2
    int v6; // eax@3

    v0 = dword_4AA928;
    result = sce2Texture[dword_4AA928].trxSCE2Bpk_4B4320;
    v2 = 0;
    dword_481BE8 = 0;
    if (result > 0)
    {
        v3 = raceEffectiveHalfWidth_445014;
        v4 = raceEffectiveHalfHeight_44501C;
        // v5 = sce2Texture[v0].dword_4B4580;
        v5 = 0;
        do
        {
            //v6 = (v5[483] << 8) / *v5;


              //esto hay que mirarlo a fondo
            v6 = (sce2Texture[v0].dword_4B4D0C[v5] << 8) / sce2Texture[v0].dword_4B4580[v5];
            ++v5;
            sce2Texture[v0].dword_4B4D0C[v5 - 1] = raceEffectiveHalfWidth_445014 + ((v6 + 128) >> 8);
            //v5[482] = raceEffectiveHalfWidth_445014 + ((v6 + 128) >> 8);
           // v5[557] = raceEffectiveHalfHeight_44501C + (((v5[557] << 8) / *(v5 - 1) + 128) >> 8);
            sce2Texture[v0].dword_4B4E38[v5 - 1] = raceEffectiveHalfHeight_44501C + (((sce2Texture[v0].dword_4B4E38[v5 - 1] << 8) / sce2Texture[v0].dword_4B4580[v5 - 1] + 128) >> 8);


            result = sce2Texture[v0].trxSCE2Bpk_4B4320;
            ++v2;
        } while (v2 < result);
        dword_481BE8 = v2;
    }
    return result;
}


//----- (004116D0) --------------------------------------------------------
void draw3dElements_4116D0()
{
    int v0; // ebx@1
    int v1; // edi@2
    int v2; // esi@2
    bool v3; // zf@2
    int v4; // eax@3
    int v5; // ecx@3
    int v6; // eax@4
    int v7; // eax@7
    int v8; // edi@10
    int v9; // esi@10
    int v10; // eax@10
    int v11; // ecx@10
    int v12; // edx@10
    int v13; // ecx@10
    int v14; // edx@10
    int v15; // ebp@10
    int v16; // edx@10
    int v17; // eax@10
    int v18; // ebx@10
    int v19; // ebp@10
    int v20; // ecx@15
    int v21; // eax@20
    int v22; // eax@21
    unsigned int v23; // eax@23
    int v24; // ecx@23
    int v25; // edx@23
    unsigned int v26; // eax@23
    bool v27; // sf@23
    int v28; // edx@23
    int v29; // eax@23
    int v30; // eax@24
    int v31; // edx@26
    int v32; // esi@26
    unsigned int v33; // eax@26
    int v34; // ecx@26
    int v35; // eax@26
    unsigned int v36; // esi@26
    int v37; // ecx@26
    int v38; // eax@26
    int v39; // eax@27
    int v40; // ecx@38
    int v41; // esi@38
    int v42; // edi@38
    int v43; // eax@38
    int v44; // edx@39
    int v45; // ecx@40
    int v46; // edx@43
    int v47; // [sp+0h] [bp-4h]@23

    v0 = trxSCE1Number3DObjects_479D20 - 1;
    dword_4A7A38 = trxSCE1Number3DObjects_479D20 - 1;
    if (trxSCE1Number3DObjects_479D20 - 1 >= 0)
    {
        while (1)
        {
            v1 = sce2Texture[v0].dword_4B4F6C;
            v2 = sce2Texture[v0].dword_4B4F6C;
            v3 = sce2Texture[v2].dword_4B4F64 == 1;
            dword_4AA928 = sce2Texture[v0].dword_4B4F6C;
            if (!v3)
            {
                v4 = sce2Texture[v2].trxSCE2Bpk_4B4320;
                v5 = 0;
                dword_481BE8 = 0;
                if (v4 > 0)
                {
                    v6 = 0;//sce2Texture[v2].dword_4B4D0C;
                    do
                    {
                        sce2Texture[v2].dword_4B4D0C[v6] = sce2Texture[v2].dword_4B4328[v6] + (sce2Texture[v2].dword_4B4D04 << 8);
                        sce2Texture[v2].dword_4B4E38[v6] = sce2Texture[v2].dword_4B4454[v6] + (sce2Texture[v2].dword_4B4D08 << 8);
                        //v6[75] = sce2Texture[v6].dword_4B4454 + (sce2Texture[v2].dword_4B4D08 << 8);
                        ++v5;
                        ++v6;
                    } while (v5 < sce2Texture[v2].trxSCE2Bpk_4B4320);
                    dword_481BE8 = v5;
                }
                sub_411530();
                v7 = sce2Texture[v2].numberTriangles_4B4324;
                dword_481BE8 = 0;
                if (v7 > 0)
                    break;
            }
        LABEL_45:
            --v0;
            dword_4A7A38 = v0;
            if (v0 < 0)
                return;
        }
        while (1)
        {

            //esto es dificil
            v8 = 788 * v1;
            v9 = v1 + dword_481BE8;
            v10 = sce2Texture[v1].dword_4B46BC[dword_481BE8];
            v11 = sce2Texture[v1].dword_4B484C[dword_481BE8];
            v12 = sce2Texture[v1].dword_4B4D0C[v11];
            v13 = sce2Texture[v1].dword_4B4E38[v11];
            dword_50351C = v12;
            v14 = sce2Texture[v1].dword_4B49DC[dword_481BE8];
            v15 = sce2Texture[v1].dword_4B4D0C[v14];
            v16 = sce2Texture[v1].dword_4B4E38[v14];
            v17 = v8 + v10;
            v18 = sce2Texture[v1].dword_4B4D0C[v10];
            dword_4A8A80 = v15;
            v19 = sce2Texture[v1].dword_4B4E38[v10];
            dword_4A7A4C = v13;
            dword_46ECE4 = v16;
            dword_50EF20 = v18;
            dword_4A6AD0 = v19;

            //determina si se ve
            if ((dword_50351C - v18) * (v16 - v19) - (dword_4A8A80 - v18) * (v13 - v19) <= 0
                && (abs(v18 - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014
                    || abs(dword_50351C - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014
                    || abs(dword_4A8A80 - raceEffectiveHalfWidth_445014) < raceEffectiveHalfWidth_445014))
            {
                if (abs(v19 - raceEffectiveHalfHeight_44501C) < raceEffectiveHalfHeight_44501C)
                {
                    v20 = dword_46ECE4;
                }
                else
                {
                    v20 = dword_46ECE4;
                    if (abs(dword_4A7A4C - raceEffectiveHalfHeight_44501C) >= raceEffectiveHalfHeight_44501C && abs(dword_46ECE4 - raceEffectiveHalfHeight_44501C) >= raceEffectiveHalfHeight_44501C)
                        goto LABEL_36;
                }
                switch (sce2Texture[v1].polygonColour_4B4B6C[dword_481BE8 * 4])
                {
                case 0x80:
                    /*v21 = dword_4B46BC[v9];
                    if ( 75 * dword_4B4454[v8 + dword_4B46BC[v9]] >> (54
                                                                    * ((unsigned __int16)(100
                                                                                        - *(_DWORD *)&dword_4B4328[2 * (v8 + dword_4B46BC[v9])]) >> 8)
                                                                    + 8) >= 0 )
                      v22 = 75 * dword_4B4454[v8 + v21] >> (54
                                                          * ((unsigned __int16)(100 - *(_DWORD *)&dword_4B4328[2 * (v8 + v21)]) >> 8)
                                                          + 8);
                    else
                      v22 = -(75 * dword_4B4454[v8 + v21] >> (54 * ((unsigned __int16)(100 - dword_4B4328[2 * (v8 + v21)]) >> 8)
                                                            + 8));
                    v47 = v22 & 7;
                    v23 = 4 * (v8 + dword_4B484C[v9]);
                    v24 = 100 - *(_DWORD *)&dword_4B4328[v23 / 2];
                    v25 = 75 * dword_4B4454[v23 / 4] >> (54 * BYTE1(v24) + 8);
                    v26 = 4 * (v8 + dword_4B484C[v9]);
                    v27 = v25 < 0;
                    v28 = *(_DWORD *)&dword_4B4328[v26 / 2];
                    v29 = dword_4B4454[v26 / 4];
                    if ( v27 )
                      v30 = -(75 * v29 >> (54 * ((unsigned __int16)(100 - v28) >> 8) + 8));
                    else
                      v30 = 75 * v29 >> (54 * ((unsigned __int16)(100 - v28) >> 8) + 8);
                    v31 = v30 & 7;
                    v32 = dword_4B49DC[v9];
                    v33 = 4 * (v8 + v32);
                    v34 = 100 - *(_DWORD *)&dword_4B4328[v33 / 2];
                    v35 = 75 * dword_4B4454[v33 / 4] >> (54 * BYTE1(v34) + 8);
                    v36 = 4 * (v8 + v32);
                    v37 = 54 * ((100 - *(_DWORD *)&dword_4B4328[v36 / 2]) >> 8) + 8;
                    v27 = v35 < 0;
                    v38 = dword_4B4454[v36 / 4];
                    if ( v27 )
                      v39 = -(75 * v38 >> v37);
                    else
                      v39 = 75 * v38 >> v37;
                    sub_43D050(
                      v18 + leftMenuInRaceWidth_456AA0,
                      v19,
                      v47 + 109,
                      leftMenuInRaceWidth_456AA0 + dword_50351C,
                      dword_4A7A4C,
                      v31 + 109,
                      leftMenuInRaceWidth_456AA0 + dword_4A8A80,
                      dword_46ECE4,
                      (v39 & 7) + 109);*/
                    break;
                    /*case 0x8A:
                      sub_43D050(
                        v18 + leftMenuInRaceWidth_456AA0,
                        v19,
                        dword_467020[75 * dword_4AA928 + dword_4B46BC[v9]] + 108,
                        leftMenuInRaceWidth_456AA0 + dword_50351C,
                        dword_4A7A4C,
                        dword_467020[75 * dword_4AA928 + dword_4B484C[v9]] + 108,
                        leftMenuInRaceWidth_456AA0 + dword_4A8A80,
                        v20,
                        dword_467020[75 * dword_4AA928 + dword_4B49DC[v9]] + 108);
                      break;*/
                case 0x81:
                    iluminateTriangle_43D530(
                        v18 + leftMenuInRaceWidth_456AA0,
                        v19,
                        leftMenuInRaceWidth_456AA0 + dword_50351C,
                        dword_4A7A4C,
                        leftMenuInRaceWidth_456AA0 + dword_4A8A80,
                        v20,
                        (int)&unk_46ED00);
                    break;
                case 0x82:
                    iluminateTriangle_43D530(
                        v18 + leftMenuInRaceWidth_456AA0,
                        v19,
                        leftMenuInRaceWidth_456AA0 + dword_50351C,
                        dword_4A7A4C,
                        leftMenuInRaceWidth_456AA0 + dword_4A8A80,
                        v20,
                        (int)&unk_4A7BC0);
                    break;
                case 0x83:
                    iluminateTriangle_43D530(
                        v18 + leftMenuInRaceWidth_456AA0,
                        v19,
                        leftMenuInRaceWidth_456AA0 + dword_50351C,
                        dword_4A7A4C,
                        leftMenuInRaceWidth_456AA0 + dword_4A8A80,
                        v20,
                        (int)&unk_4AA400);
                    break;
                default:
                    setTriangleValue_43CD50(
                        v18 + leftMenuInRaceWidth_456AA0,
                        v19,
                        leftMenuInRaceWidth_456AA0 + dword_50351C,
                        dword_4A7A4C,
                        leftMenuInRaceWidth_456AA0 + dword_4A8A80,
                        v20,
                        sce2Texture[v1].polygonColour_4B4B6C[dword_481BE8 * 4]);//polygonColour_4B4B6C[v9 * 4]);
                    break;
                }
            }
        LABEL_36:
            if (raceShowTextures_44502C)
            {
                //dword_4A6AFC = dword_46F220[dword_481BE8 + 100 * dword_4AA928];
                dword_4A6AFC = dword_46F220[dword_4AA928][dword_481BE8];

                // if(debug) dword_4A6AFC=2;
                if (dword_4A6AFC != -1)
                {
                    v40 = 11 * dword_4A6AFC;
                    v40 = dword_4A6AFC;
                    v41 = raceEffectiveHalfWidth_445014;
                    v42 = raceEffectiveHalfHeight_44501C;
                    sce4Texture[v40].dword_50A198 = sce4Texture[v40].dword_50A18C - (circuitImageOffsetX_456ABC << 8) - (raceEffectiveHalfWidth_445014 << 8);
                    sce4Texture[v40].dword_50A19C = sce4Texture[v40].dword_50A190 - (circuitImageOffsetY_456AC0 << 8) - (v42 << 8);
                    sce4Texture[v40].dword_50A198 = v41 + (((sce4Texture[v40].dword_50A198 << 8) / sce4Texture[v40].dword_50A194 + 128) >> 8);
                    sce4Texture[v40].dword_50A19C = v42 + (((sce4Texture[v40].dword_50A19C << 8) / sce4Texture[v40].dword_50A194 + 128) >> 8);
                    v43 = sce4Texture[v40].tetureWidth_50A180;
                    //determina si se ve en pantalla
                    if (sce4Texture[v40].dword_50A198 > -sce4Texture[v40].tetureWidth_50A180)
                    {
                        v44 = sce4Texture[v40].dword_50A19C;
                        if (v44 > -sce4Texture[v40].textureHeight_50A184)
                        {
                            v45 = sce4Texture[v40].dword_50A198;
                            // if(debug)v45=0;
                            if (v45 < raceEffectiveWidth_445010 && v44 < raceEffectiveHeight_445018)
                                draw3dTexture_43B2F0(leftMenuInRaceWidth_456AA0 + v45, v44, v43, v40);
                        }
                    }
                }
            }
            v46 = sce2Texture[dword_4AA928].numberTriangles_4B4324;
            ++dword_481BE8;
            if (dword_481BE8 >= v46)
            {
                v0 = dword_4A7A38;
                goto LABEL_45;
            }
            v1 = dword_4AA928;
        }
    }
}

//----- (004156B0) --------------------------------------------------------
int sub_4156B0()
{
    int v0; // edi@1
    int v1; // ecx@1
    int v2; // eax@2
    int id3dObject = 0;
    v0 = trxSCE1Number3DObjects_479D20;
    v1 = 0;
    dword_4AA928 = 0;
    if (trxSCE1Number3DObjects_479D20 > 0)
    {
        // v2 = (int)dword_4B4D04;
        do
        {
            sce2Texture[id3dObject].dword_4B4F68 = sce2Texture[id3dObject].dword_4B4D04 * sce2Texture[id3dObject].dword_4B4D04 + sce2Texture[id3dObject].dword_4B4D08 * sce2Texture[id3dObject].dword_4B4D08;
            sce2Texture[id3dObject].dword_4B4F6C = v1++;
            // v2 += 3152;
            id3dObject++;
        } while (v1 < v0);
        dword_4AA928 = v1;
    }
    return sub_4115C0(0, v0 - 1);
}

//----- (00403190) --------------------------------------------------------
void parseCircuitSceFile_403190()
{
    //  int v0; // eax@1
    //  char v1; // cl@2
    //  char *v2; // edi@3
    //  char v3; // al@4
    int v4; // eax@5

    int v7; // [sp-4h] [bp-14h]@10
    BYTE v8[16]; // [sp+0h] [bp-10h]@2

   /* v0 = 0;
    do
    {
      v1 = *((BYTE *)raceFilePrefix_45EA50 + v0);
      v8[v0++] = v1;
    }
    while ( v1 );
    v2 = (char *)&v5 + 3;
    do
      v3 = (v2++)[1];
    while ( v3 );
    *(_DWORD *)v2 = 1162040109;
    *((_DWORD *)v2 + 1) = 1263551022;
    v2[8] = 0;*/
    strcpy((char*)v8, raceFilePrefix_45EA50);
    strcat((char*)v8, "-SCE.BPK");
    extractFromBpa(circuitSelectedTR_464F50, textureTemp, (char*)v8);
    decryptTexture((int)textureTemp, (int)&trxSCE1Number3DObjects_479D20, 0, 1);
    // decryptTexture((int)textureTemp, (int)trxSCE2Bpk_4B4320, 1, 3152 * trxSCE1Number3DObjects_479D20 + 1);
    decryptTexture((int)textureTemp, &sce2Texture, 1, 3152 * trxSCE1Number3DObjects_479D20 + 1);
    decryptTexture((int)textureTemp, (int)&trxSCE3Bpk_464F10, 3152 * trxSCE1Number3DObjects_479D20 + 1, 1);
    v4 = trxSCE3Bpk_464F10;
    if (44 * trxSCE3Bpk_464F10)
    {
        decryptTexture((int)textureTemp, (int)sce4Texture, 3152 * trxSCE1Number3DObjects_479D20 + 2, 44 * trxSCE3Bpk_464F10);
        v4 = trxSCE3Bpk_464F10;
    }
    switch (raceFilePrefix_45EA50[2])
        //switch (BYTE2(raceFilePrefix_45EA50[0]))
    {
    case 0x31u:
    case 0x32u:
        v7 = 390000;
        goto LABEL_10;
    case 0x30u:
    case 0x33u:
    case 0x34u:
    case 0x35u:
    case 0x36u:
    case 0x37u:
    case 0x38u:
    case 0x39u:
        v7 = 300000;
    LABEL_10:
        decryptTexture((int)textureTemp, (int)trxSCE5Bpk_4A7A28, 3152 * trxSCE1Number3DObjects_479D20 + 44 * v4 + 2, v7);
        break;
    default:
        return;
    }
}


//----- (0043B2F0) --------------------------------------------------------
int   draw3dTexture_43B2F0(int a1, int a2, int a3, int textureId)//offsetx, offsety , textura,index
{
    int v3; // ebx@1
    int v4; // edi@1
    int result; // eax@1
    char* v6; // ecx@1
    int v7; // esi@1
    int i; // ebp@1
    int v9; // edi@6

    //trxSCE5Bpk_4A7A28 ancho textura siguiente alto siguiente datos
    //v3 = *(_DWORD *)(a3 + 4);
    v3 = sce4Texture[textureId].textureHeight_50A184;
    v4 = dword_464F14;
    result = dword_464F14 + (a2 << 9) + a1 + 96;
    //v6 = (char *)trxSCE5Bpk_4A7A28 + *(_DWORD *)(a3 + 8);
    v6 = (char*)trxSCE5Bpk_4A7A28 + sce4Texture[textureId].textureOffset_50A188;

    //v7 = *(_DWORD *)a3;
    v7 = sce4Texture[textureId].tetureWidth_50A180;
    for (i = 0; i < v3; ++i)
    {
        if (v4 + 102400 < (unsigned int)result)//si ha pintado mas de 102400 bytes cortamos
            break;
        if (result >= (unsigned int)v4)
        {
            if (v7 > 0)
            {
                v9 = v7;
                do
                {
                    if (*v6)
                        *(BYTE*)result = *v6;
                    ++result;
                    ++v6;
                    --v9;
                } while (v9);
                v4 = dword_464F14;
            }
            result += 512 - v7;
        }
        else
        {
            v6 += v7;
            result += 512;
        }
    }
    return result;
}