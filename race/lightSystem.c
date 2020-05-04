#pragma once
#include "lightSystem.h"
#include "../defs.h"
#include "../dr.h"



//----- (0043D530) --------------------------------------------------------
int   iluminateTriangle_43D530(int pos1x, int pos1y, int pos2x, int pos2y, int pos3x, int pos3y, int a7)
{
    int v7; // ecx@1
    signed int v8; // ecx@2
    int v9; // edx@4
    signed int v10; // edx@5
    signed int v11; // esi@7
    signed int v12; // edi@7
    int result; // eax@7
    signed int v14; // ebx@8
    //int *v15; // edx@8
    //int *v16; // eax@8
    int v15; // edx@8
    int v16; // eax@8

    int v17; // eax@8
    double v18; // st7@8
    int v19; // ebx@8
    int v20; // ecx@8
    double v21; // st7@12
    signed int v22; // ST1C_4@14
    unsigned __int64 v23; // rax@14
    signed int v24; // ecx@14
    signed int v25; // edi@14
    signed int j; // eax@19
    int v27; // edx@21
    double v28; // st7@31
    signed int v29; // ebx@33
    unsigned __int64 v30; // rax@33
    signed int v31; // edi@33
    signed int v32; // ecx@37
    signed int i; // eax@38
    int v34; // edx@40
    float v35; // [sp+14h] [bp-44h]@9
    float v36; // [sp+18h] [bp-40h]@9
    float v37; // [sp+20h] [bp-38h]@8
    float v38; // [sp+20h] [bp-38h]@28
    int v39; // [sp+24h] [bp-34h]@7
    float v40; // [sp+28h] [bp-30h]@12
    signed int v41; // [sp+2Ch] [bp-2Ch]@8
    int v42; // [sp+30h] [bp-28h]@8
    float v43; // [sp+30h] [bp-28h]@31
    float v44; // [sp+34h] [bp-24h]@8
    int v45; // [sp+38h] [bp-20h]@8
    int v46; // [sp+3Ch] [bp-1Ch]@9
    int v47; // [sp+40h] [bp-18h]@1
    int v48; // [sp+44h] [bp-14h]@1
    int v49; // [sp+48h] [bp-10h]@1
    int v50; // [sp+4Ch] [bp-Ch]@1
    int v51; // [sp+50h] [bp-8h]@1
    int v52; // [sp+54h] [bp-4h]@1
    int positions[6];

    v7 = 0;

    positions[0] = pos1x;
    positions[1] = pos1y;
    positions[2] = pos2x;
    positions[3] = pos2y;
    positions[4] = pos3x;
    positions[5] = pos3y;

    /*  v47 = pos1x;
      v49 = pos2x;

      v48 = pos1y;
      v50 = pos2y;
      v51 = pos3x;
      v52 = pos3y;
      */
    if (pos1y >= pos2y)
    {
        LOBYTE(v7) = pos2y >= pos3y;
        v8 = 2 * v7 + 2;
    }
    else
    {
        v8 = pos1y < pos3y ? 0 : 4;
    }
    v9 = 0;
    if (pos1y <= pos2y)
    {
        LOBYTE(v9) = pos2y <= pos3y;
        v10 = 2 * v9 + 2;
    }
    else
    {
        v10 = pos2y > pos3y ? 0 : 4;
    }
    v11 = positions[1 + v8];
    //v11 = *(&v48 + v8);
    v12 = v10;
    result = 6 - v10 - v8;
    v39 = positions[1 + v10];
    //v39 = *(&v48 + v10);
    if (v39 == v11)
        return result;
    v14 = positions[0 + result];
    //v14 = *(&v47 + result);
    //v15 = &v47 + v8;
    v15 = positions[0 + v8];
    v41 = v14;
    //v16 = &v48 + result;
    v16 = positions[1 + result];
    v42 = (int)v16;
    //v17 = *v16;
    v17 = v16;
    // v18 = (double)(v14 - *v15) / (double)(v17 - v11);

    v18 = (double)(v14 - v15) / (double)(v17 - v11);
    v19 = positions[0 + v12];
    //v19 = *(&v47 + v12);
    v20 = v39;
    v45 = positions[0 + v12];
    //v45 = *(&v47 + v12);
    v37 = v18;
    // v44 = (double)(*(&v47 + v12) - *v15) / (double)(v39 - v11);
    v44 = (double)(positions[0 + v12] - v15) / (double)(v39 - v11);

    if (v17 == v11)
    {
        v36 = (double)v41;
        //v35 = (double)*v15;
        v35 = (double)v15;
    LABEL_28:
        result = v42;
        //v38 = (double)(v19 - v41) / (double)(v20 - *(_DWORD *)v42);
        v38 = (double)(v19 - v41) / (double)(v20 - v42);
        if (v11 < v20)
        {
            do
            {
                if (v11 > 0 && v11 < 200)
                {
                    v28 = v36;
                    v43 = v35;
                    if (v36 > (double)v35)
                    {
                        v28 = v35;
                        v43 = v36;
                    }
                    v29 = (unsigned __int64)floor(v28 + 0.40000001);
                    v30 = (unsigned __int64)floor(v43 + 0.60000002);
                    v31 = v30;
                    if (v29 < 0)
                        v29 = 0;
                    if ((signed int)v30 > 512)  //ancho de pantalla
                        v31 = 512;
                    v32 = v29;
                    if (v29 < v31)
                    {
                        for (i = v11 << 9; ; i = v11 << 9)
                        {
                            v34 = dword_464F14 + i + v32++ + 96;
                            *(BYTE*)v34 = *(BYTE*)(*(BYTE*)v34 + a7);
                            if (v32 >= v31)
                                break;
                        }
                    }
                }
                result = v39;
                ++v11;
                v36 = v36 + v38;
                v35 = v35 + v44;
            } while (v11 < v39);
        }
        return result;
    }
    //v35 = (double)*v15;
    v35 = (double)v15;
    v36 = v35;
    //result = *(_DWORD *)v42;
    result = v42;
    // v46 = *(_DWORD *)v42;
    v46 = v42;

    //if ( v11 < *(_DWORD *)v42 )
    if (v11 < v42)

    {
        do
        {
            if (v11 > 0 && v11 < 200)
            {
                v21 = v36;
                v40 = v35;
                if (v36 > (double)v35)
                {
                    v21 = v35;
                    v40 = v36;
                }
                v22 = (unsigned __int64)floor(v21 + 0.40000001);
                v23 = (unsigned __int64)floor(v40 + 0.60000002);
                v24 = v22;
                v25 = v23;
                if (v22 < 0)
                    v24 = 0;
                if ((signed int)v23 > 512)
                    v25 = 512;
                if (v24 < v25)
                {
                    for (j = v11 << 9; ; j = v11 << 9)
                    {
                        v27 = dword_464F14 + j + v24++ + 96;
                        *(BYTE*)v27 = *(BYTE*)(*(BYTE*)v27 + a7);
                        if (v24 >= v25)
                            break;
                    }
                    v19 = v45;
                }
            }
            result = v46;
            ++v11;
            v36 = v36 + v37;
            v35 = v35 + v44;
        } while (v11 < v46);
        v20 = v39;
    }
    if (result != v20)
        goto LABEL_28;
    return result;
}
// 464F14: using guessed type int dword_464F14;

