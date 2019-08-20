#include "pedestrian.h"
#include "../defs.h"
#include "../dr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../raceParticipant.h"

Pedestrian pedestrian_479AA4[20];

//----- (0043AF30) --------------------------------------------------------
char   drawPedestrian_43AF30(int screenOffset, int pedestrianbpkOffset, int sizeToPaint)
{
  char result; // al@1
  int v4; // edx@2
  int v5; // ecx@2
  int v6; // edi@2
  signed int v7; // esi@3

  result = sizeToPaint;
  if ( sizeToPaint > 0 )
  {
    v4 = pedestrianbpkOffset;
    v5 = screenOffset;
    v6 = sizeToPaint;
    do
    {
      v7 = 16;
      do
      {
        result = *(BYTE *)v4;
        if ( *(BYTE *)v4 )
          *(BYTE *)v5 = result;
        ++v4;
        ++v5;
        --v7;
      }
      while ( v7 );
      v5 += 496;
      --v6;
    }
    while ( v6 );
  }
  return result;
}


//----- (004111F0) --------------------------------------------------------
char drawShotPedestrian_4111F0()
{
  //signed int v0; // esi@1
  int v1; // eax@4
  signed int v2; // eax@5
  int v3; // eax@9
  int v4; // edi@13
  double v5; // st7@13
  int v6; // ebp@14
  int v7; // ebx@14
  bool v8; // zf@14
  bool v9; // sf@14
  unsigned __int8 v10; // of@14
  bool v11; // zf@21
  bool v12; // sf@21
  unsigned __int8 v13; // of@21
  int v14; // ebp@28
  int v15; // ebx@28
  bool v16; // zf@28
  bool v17; // sf@28
  unsigned __int8 v18; // of@28
  bool v19; // zf@35
  bool v20; // sf@35
  unsigned __int8 v21; // of@35
  signed int v22; // eax@43
 // signed int v23; // esi@46
  signed int posXTemp; // edx@47
  int posYTemp; // eax@47
  int v26; // edi@53
  int v27; // ecx@53
  int v28; // eax@53
  int v29; // edi@58
  char *v31; // [sp-8h] [bp-18h]@60
  int v32; // [sp-4h] [bp-14h]@58
  int pedestrianIndex;
  //v0 = (signed int)&unk_479AA0;
  pedestrianIndex =0;
  do
  {
	  if (pedestrian_479AA4[pedestrianIndex].isDied )
    {
      if ( refreshScreenWithDelay() >= (unsigned int)(pedestrian_479AA4[pedestrianIndex].byte7 + 5) )
      {
        v22 =  pedestrian_479AA4[pedestrianIndex].byte5;
        if ( v22 < 7 )
        {
           pedestrian_479AA4[pedestrianIndex].byte5 = v22 + 1;
           pedestrian_479AA4[pedestrianIndex].byte7 = refreshScreenWithDelay();
        }
      }
    }
    else
    {
      if ( refreshScreenWithDelay() >= (unsigned int)( pedestrian_479AA4[pedestrianIndex].byte7 + 5) )
      {
        v1 =  pedestrian_479AA4[pedestrianIndex].byte8;
        if ( v1 )
        {
          if ( v1 == 1 )
          {
            v3 =  pedestrian_479AA4[pedestrianIndex].byte5;
            if ( v3 <= 0 )
			   pedestrian_479AA4[pedestrianIndex].byte8 = 0;
            else
               pedestrian_479AA4[pedestrianIndex].byte5 = v3 - 1;
          }
        }
        else
        {
          v2 =  pedestrian_479AA4[pedestrianIndex].byte5;
          if ( v2 >= 2 )
			 
             pedestrian_479AA4[pedestrianIndex].byte8 = 1;
          else
             pedestrian_479AA4[pedestrianIndex].byte5 = v2 + 1;
        }
         pedestrian_479AA4[pedestrianIndex].byte7 = refreshScreenWithDelay();
      }
      //v4 = 864 * userRaceOrder_4A9EA8;
      v4 = userRaceOrder_4A9EA8;
	  v5 = raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionX_4A7DB4;
      if ( isCircuitReversed_456AA8 )
      {
		  v14 =  pedestrian_479AA4[pedestrianIndex].positionX;
        v15 = (unsigned __int64)v5;
        v18 = __OFSUB__(v15, pedestrian_479AA4[pedestrianIndex].positionX);
        v16 = v15 == pedestrian_479AA4[pedestrianIndex].positionX;
        v17 = v15 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        if ( v15 <pedestrian_479AA4[pedestrianIndex].positionX )
        {
          if ( (signed int)(raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8) < pedestrian_479AA4[pedestrianIndex].positionY )
            pedestrian_479AA4[pedestrianIndex].rotation = 0;
          v18 = __OFSUB__(v15, pedestrian_479AA4[pedestrianIndex].positionX);
          v16 = v15 == pedestrian_479AA4[pedestrianIndex].positionX;
          v17 = v15 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        }
        if ( !((unsigned __int8)(v17 ^ v18) | v16)
          && raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 < pedestrian_479AA4[pedestrianIndex].positionY )
          pedestrian_479AA4[pedestrianIndex].rotation = 1;
        v21 = __OFSUB__(v15, pedestrian_479AA4[pedestrianIndex].positionX);
        v19 = v15 == pedestrian_479AA4[pedestrianIndex].positionX;
        v20 = v15 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        if ( v15 < pedestrian_479AA4[pedestrianIndex].positionX )
        {
          if ( raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 >pedestrian_479AA4[pedestrianIndex].positionY)
            pedestrian_479AA4[pedestrianIndex].rotation = 3;
          v21 = __OFSUB__(v15, pedestrian_479AA4[pedestrianIndex].positionX);
          v19 = v15 == pedestrian_479AA4[pedestrianIndex].positionX;
          v20 = v15 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        }
        if ( !((unsigned __int8)(v20 ^ v21) | v19)
          && raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 > pedestrian_479AA4[pedestrianIndex].positionY )
          pedestrian_479AA4[pedestrianIndex].rotation = 2;
      }
      else
      {
        v6 = pedestrian_479AA4[pedestrianIndex].positionX;
        v7 = (unsigned __int64)v5;
        v10 = __OFSUB__(v7, pedestrian_479AA4[pedestrianIndex].positionX);
        v8 = v7 == pedestrian_479AA4[pedestrianIndex].positionX;
        v9 = v7 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        if ( v7 < pedestrian_479AA4[pedestrianIndex].positionX )
        {
          if ( raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 < pedestrian_479AA4[pedestrianIndex].positionY )
             pedestrian_479AA4[pedestrianIndex].rotation = 2;
          v10 = __OFSUB__(v7, pedestrian_479AA4[pedestrianIndex].positionX);
          v8 = v7 == pedestrian_479AA4[pedestrianIndex].positionX;
          v9 = v7 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        }
        if ( !((unsigned __int8)(v9 ^ v10) | v8)
          && raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 <  pedestrian_479AA4[pedestrianIndex].positionY )
          pedestrian_479AA4[pedestrianIndex].rotation = 3;
        v13 = __OFSUB__(v7, pedestrian_479AA4[pedestrianIndex].positionX);
        v11 = v7 == pedestrian_479AA4[pedestrianIndex].positionX;
        v12 = v7 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        if ( v7 < pedestrian_479AA4[pedestrianIndex].positionX )
        {
          if (raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 >  pedestrian_479AA4[pedestrianIndex].positionY )
             pedestrian_479AA4[pedestrianIndex].rotation = 1;
          v13 = __OFSUB__(v7, pedestrian_479AA4[pedestrianIndex].positionX);
          v11 = v7 == pedestrian_479AA4[pedestrianIndex].positionX;
          v12 = v7 - pedestrian_479AA4[pedestrianIndex].positionX < 0;
        }
        if ( !((unsigned __int8)(v12 ^ v13) | v11)
          && raceParticipantIngame[userRaceOrder_4A9EA8].absolutePositionY_4A7DB8 >  pedestrian_479AA4[pedestrianIndex].positionY )
           pedestrian_479AA4[pedestrianIndex].rotation = 0;
      }
    }
    //v0 += 32;
	pedestrianIndex++;
  }
  //while ( v0 < (signed int)&trxSCE1Number3DObjects_479D20 );
   while ( pedestrianIndex <20 );
  //v23 = (signed int)&unk_479AA4;//estructura de 20 pedestrina con 32 bytes. 1 x 2 y 7 splat frame 8 vivo muerto
  pedestrianIndex = 0;
  do
  {
    //v24 = *(_DWORD *)(v23 - 4);
	  posXTemp =pedestrian_479AA4[pedestrianIndex].positionX;
	  posYTemp =pedestrian_479AA4[pedestrianIndex].positionY;
	  
	  // v25 = *(_DWORD *)v23;
    if ( posXTemp > circuitImageOffsetX_456ABC - 16
      && posXTemp < circuitImageOffsetX_456ABC + 320
      && posYTemp > circuitImageOffsetY_456AC0 - 16
      && posYTemp < circuitImageOffsetY_456AC0 + 200
      && posXTemp
      && posYTemp )
    {
      v26 = 0;
      v27 = leftMenuInRaceWidth_456AA0 + posXTemp - circuitImageOffsetX_456ABC;
      v28 = posYTemp - circuitImageOffsetY_456AC0;
      if ( v28 >= 0 )
      {
        if ( v28 > 183 )
        {
          v29 = 200 - v28;
          v28 = 200 - (200 - v28);
          v32 = v29;
          //if ( !*(_DWORD *)(v23 + 20) )
		  if ( !pedestrian_479AA4[pedestrianIndex].isDied )
		  {
            (posYTemp) = drawPedestrian_43AF30(
                            dword_464F14 + (v28 << 9) + v27 + 96,
                            (int)((char *)pedestrBpk
                                + 256 * (pedestrian_479AA4[pedestrianIndex].byte5 + 3 * (pedestrian_479AA4[pedestrianIndex].rotation + 4 * pedestrian_479AA4[pedestrianIndex].pedestrianId))),
                            v29);
            goto LABEL_63;
          }
		  v31 = (char *)splat3Bpk + 256 * pedestrian_479AA4[pedestrianIndex].byte5;
		  if(posXTemp % 2==1)
			v31 = (char *)splat4Bpk  + 256 * pedestrian_479AA4[pedestrianIndex].byte5;
          goto LABEL_62;
        }
      }
      else
      {
        v26 = -v28;
        v28 = 0;
      }
      if ( !pedestrian_479AA4[pedestrianIndex].isDied  )
      
	  //if ( !*(_DWORD *)(v23 + 20) ) 
      {
        (posYTemp) = drawPedestrian_43AF30(
                        dword_464F14 + (v28 << 9) + v27 + 96,
                        (int)((char *)pedestrBpk
                            + 16
                            * (v26
                             + 16 * (pedestrian_479AA4[pedestrianIndex].byte5 + 3 * (pedestrian_479AA4[pedestrianIndex].rotation + 4 * pedestrian_479AA4[pedestrianIndex].pedestrianId)))),
                        16 - v26);
        goto LABEL_63;
      }
      v32 = 16 - v26;
	   v31 = (char *)splat3Bpk + 256 * pedestrian_479AA4[pedestrianIndex].byte5;
	  if(posXTemp % 2==1)
		v31 = (char *)splat4Bpk+ 16 * (v26 + 16 * pedestrian_479AA4[pedestrianIndex].byte5);
LABEL_62:
      (posYTemp) = drawPedestrian_43AF30(dword_464F14 + (v28 << 9) + v27 + 96, (int)v31, v32);
    }
LABEL_63:
    //v23 += 32;
	pedestrianIndex++;
  }
  //while ( v23 < (signed int)&unk_479D24 );
  while( pedestrianIndex<20);
  return posYTemp;
}
