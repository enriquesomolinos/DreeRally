#include "haf.h"
#include "../defs.h"
#include "../dr.h"

#include "../asset/bpaUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *anim_currentFrameData; // idb
BYTE animPalette[768];

void *animationSoundEffectByFrame_45EEA4; // idb

char byte_4610C0[256]; // weak
char byte_461F18; // weak
void *DstBuf; // idb
int dword_4456B0[] = { 0,1,3,7,0xf,0x1f,0x3f,0x7f,0xff,0x1ff,0x3ff,0x7ff,0xfff }; // weak
int dword_456B38 = 0; // weak
int dword_456B3C = 0; // weak
int dword_456B40 = 0; // weak
int dword_456B44 = 0; // weak
int dword_45EA08; // weak
int dword_45F028; // weak
int dword_45FC28; // weak
int dword_46125C; // weak
int dword_463CD0; // weak
int dword_462CEC; // weak
int dword_461EB0; // weak
int dword_462D5C; // weak

unsigned int sub_4181E0()
{
  signed int v0; // edx@1
  int v1; // eax@1
  void *v2; // ebp@1
  int v3; // esi@1
  int v4; // edi@3
  int i; // ecx@4
  char v6; // dl@5
  char v7; // cl@8
  int v8; // edi@8
  unsigned int v9; // ebx@10
  int v10; // ecx@10
  int j; // ecx@13
  char v12; // bl@14
  int v13; // ebx@15
  unsigned int result; // eax@17
  unsigned int v15; // [sp+10h] [bp-4h]@10

  v0 = dword_456B3C;
  v1 = dword_456B38;
  v2 = DstBuf;
  v3 = dword_456B40;
  if ( dword_456B3C )
  {
    v8 = dword_45F028;
  }
  else
  {
    if ( dword_456B38 > 0 )
    {
      v4 = dword_45F028;
    }
    else
    {
		v4 = (int)byte_4610C0;
		dword_45F028 = (int)byte_4610C0;//esto empieza con 0
		//dword_456B40=301
			
			v1 = *((unsigned char *)DstBuf + dword_456B40);
			v3 = dword_456B40 + 1;
			dword_456B38 = *((unsigned char *)DstBuf + dword_456B40++);
			if (v1)
			{
				for (i = 0; i < v1 ; dword_456B40 = v3)
				{
					v6 = *((unsigned char *)v2 + v3++);
					byte_4610C0[i++] = v6;
				}
			}
		
    }
    v7 = *(unsigned char *)v4;
    v8 = v4 + 1;
    v0 = 8;
    --v1;
    byte_461F18 = v7;
    dword_45F028 = v8;
    dword_456B3C = 8;
    dword_456B38 = v1;
  }
  v9 = (unsigned int)(unsigned __int8)byte_461F18 >> (8 - v0);
  v10 = dword_462CEC;
  v15 = (unsigned int)(unsigned __int8)byte_461F18 >> (8 - v0);
  if ( dword_462CEC > v0 )
  {
    do
    {
      if ( v1 <= 0 )
      {
        v8 = (int)byte_4610C0;
        dword_45F028 = (int)byte_4610C0;
		
		v1 = *((unsigned char *)v2 + v3++);
		
        
		
        dword_456B38 = v1;
        dword_456B40 = v3;
        if ( v1 )
        {
          for ( j = 0; j < v1 ; dword_456B40 = v3 )
          {
            v12 = *((unsigned char *)v2 + v3++);
			byte_4610C0[j++] = v12;
          }
        }
      }
      byte_461F18 = *( unsigned char *)v8;
      v13 = (unsigned __int8)byte_461F18 << v0;
      ++v8;
      v0 += 8;
      v15 |= v13;
      v10 = dword_462CEC;
      --v1;
      dword_45F028 = v8;
      dword_456B3C = v0;
      dword_456B38 = v1;
    }
    while ( dword_462CEC > v0 );
    v9 = v15;
  }
  result = v9 & dword_4456B0[v10];
  dword_456B3C = v0 - v10;
  return result;
}

//----- (00418330) --------------------------------------------------------
void decryptAnimFrame()
{
  void *dataBuffer; // esi@1
  int v1; // eax@1
  int v2; // ecx@1
  int v3; // ecx@2
  int v4; // eax@2
  unsigned __int8 v5; // bl@3
  signed int v9; // edx@3
  signed int v10; // esi@3
  int v11; // ebp@3
  int v12; // ebx@3
  unsigned int v13; // edi@3
  unsigned int v14; // eax@3
  unsigned int v15; // eax@8
  int v16; // ecx@13
  char v17; // al@22
  int v18; // [sp+10h] [bp-Ch]@3
  char v19; // [sp+14h] [bp-8h]@3
  int v20; // [sp+18h] [bp-4h]@3
  void *dword_45FB9C =malloc(0x1001u); // eax@3
  void *dword_45EA94 =malloc(0x1001u); // eax@3
  void *dword_462D78 =malloc(0x4004u); // eax@3
  
  int i = 0;
  dataBuffer = DstBuf;
  v1 = 0;
  dword_456B44 = 0;
  dword_456B40 = 0;
  v2 = animPalette;
  ///lee la paleta de colores que esta al principio
  do
  {
    *(BYTE *)v2 = *((BYTE *)dataBuffer + v1);
    v3 = v2 + 1;
    v4 = v1 + 1;
    dword_456B40 = v4;
    *(BYTE *)v3++ = *((BYTE *)dataBuffer + v4++);
    dword_456B40 = v4;
    *(BYTE *)v3 = *((BYTE *)dataBuffer + v4);
    v2 = v3 + 1;
    v1 = v4 + 1;
    dword_456B40 = v1;
	i++;
  }
  while ( i <256);
 
  //while (v2 < (signed int)&configuration.leftSteeringGamepad);
  v5 = *((BYTE *)dataBuffer + v1);
  dword_456B40 = v1 + 1;
  /*dword_45FB9C = v6;
  dword_45EA94 = v7;
  dword_462D78 = v8;*/
  v9 = 1 << (v5 + 1);
  v20 = v5 + 1;
  dword_462CEC = v5 + 1;
  v10 = 1 << v5;
  dword_456B3C = 0;
  dword_456B38 = 0;
  v11 = (1 << v5) + 1;
  v12 = (1 << v5) + 2;
  v19 = 0;
  v18 = 0;
  v13 = (unsigned int)dword_45FB9C;
  dword_45FC28 = v9;
  dword_463CD0 = v10;
  dword_461EB0 = v11;
  dword_46125C = v12;
  dword_462D5C = v12;
  v14 = sub_4181E0();
  //v14 = 0;
  if ( v14 != v11 )
  {
    while ( 1 )
    {
      if ( v14 == v10 )
      {
        dword_462CEC = v20;
        dword_462D5C = v12;
        dword_45FC28 = 1 << v20;
        do
          v15 = sub_4181E0();
        while ( v15 == v10 );
        if ( v15 == v11 )
          break;
        if ( (signed int)v15 >= v12 )
          v15 = 0;
        *((BYTE *)anim_currentFrameData + dword_456B44) = v15;
        v19 = v15;
        v18 = v15;
        ++dword_456B44;
      }
      else
      {
        v16 = v14;
        if ( (signed int)v14 >= dword_462D5C )
        {
          v16 = v18;
          *(BYTE *)v13 = v19;
          v12 = dword_46125C;
          ++v13;
        }
        if ( v16 >= v12 )
        {
          do
          {
            *(BYTE *)v13 = *((BYTE *)dword_45EA94 + v16);
            v16 = *((_DWORD *)dword_462D78 + v16);
            ++v13;
			
          }
          while ( v16 >= dword_46125C );
        }
		
			*(BYTE *)v13++ = v16;
		
        if ( dword_462D5C >= dword_45FC28
          || (*((BYTE *)dword_45EA94 + dword_462D5C) = v16,
              v19 = v16,
              *((_DWORD *)dword_462D78 + dword_462D5C) = v18,
              v18 = v14,
              ++dword_462D5C,
              dword_462D5C >= dword_45FC28) )
        {
          if ( dword_462CEC < 12 )
          {
            dword_45FC28 *= 2;
            ++dword_462CEC;
          }
        }
        for ( ; v13 > (unsigned int)dword_45FB9C ; ++dword_456B44 )
        {
          v17 = *(BYTE *)(v13-- - 1);
          *((BYTE *)anim_currentFrameData + dword_456B44) = v17;
           //printf("\data %d..\n",v17);
        }
      }
      v14 = sub_4181E0();
      v11 = dword_461EB0;
      if ( v14 == dword_461EB0 )
        break;
      v10 = dword_463CD0;
      v12 = dword_46125C;
    }
  }
  free(dword_45FB9C);
  free(dword_45EA94);
  free(dword_462D78);
}

//----- (004185B0) --------------------------------------------------------
void   openAnimation(const char *animFile, int a2, char * music, int a4, char * effect, char onKeyPressExit, char screenResolution)
{
	
  unsigned int v7; // eax@2
  char *v8; // edi@2
  char v9; // cl@3
  unsigned int v10; // eax@5
  char *v11; // edi@5
  char v12; // cl@6
  void *v13 =malloc(0xFA00u); // eax@7
  void *v14 = malloc(0xFA00u); // eax@7
  int (  *v15)(FILE *); // ebx@11
  FILE *fAnimFile; // ebp@11
  unsigned __int8 v17; // ST3F_1@11
  void *v18; // eax@11
  void *v19; // eax@11
  size_t v20; // eax@11
  signed int i; // esi@11
  signed int v22; // esi@13
  signed int v23; // esi@15
  signed int v24; // edi@17
  char *v25; // esi@17
  char v26; // al@22
  int v27; // edi@24
  unsigned __int8 v28; // bl@24
  unsigned __int8 v29; // al@24
  int v30; // esi@24
  signed int v31; // edi@28
  int v32; // esi@28
  int v33; // eax@29
  int v34; // ecx@29
  int v35; // esi@29
  int v36; // edx@29
  signed int screenFrameSize; // ecx@31
  int screenFrameStartPosition; // edi@31
  char v39; // al@33
  int v40; // esi@34
  signed int v41; // esi@37
  signed int v42; // esi@39
  int v43; // [sp+Ch] [bp-404h]@1
  char Filename; // [sp+10h] [bp-400h]@1
  char *v45 = malloc(768); // [sp+110h] [bp-300h]@17
  //char v46; // [sp+111h] [bp-2FFh]@17
  int frames;
  int currentFrame;
  void *framesDelay; // idb
 
  v43 = 1;
  Filename = 0;
  if ( byte_462D50 == 2 )
  {
    v7 = strlen(byte_45FAA0) + 1;
    v8 = (char *)&v43 + 3;
    do
      v9 = (v8++)[1];
    while ( v9 );
    memcpy(v8, byte_45FAA0, v7);
  }
  v10 = strlen(animFile) + 1;
  v11 = (char *)&v43 + 3;
  do
    v12 = (v11++)[1];
  while ( v12 );
  memcpy(v11, animFile, v10);
  //allocateMemory(0xFA00u);
  //allocateMemoryPtr((void*)&v13,0xFA00u); //esto huele a un frame
  anim_currentFrameData = malloc(0xFA00u);
  //allocateMemory(0xFA00u);
  //allocateMemoryPtr((void*)&v14, 0xFA00u);
  DstBuf = v14;
  if ( (BYTE)a2 )
    loadMusic(a2, music, a4, effect);
  nullsub_1();
  setWindowCaption3(19);
  recalculateSDLTicks_43C740();
  if ( (BYTE)a2 )
  {
    nullsub_1();
    musicPlayMusic();
    nullsub_1();
  }
  v15 = getc;

/*  if((fAnimFile = fopen(animFile,"r"))!=NULL){
	  v15 = NULL;
	  }*/
  fAnimFile = fopen(animFile, "rb");
  //v16 = fopen(&Filename, "rb");
  //dos primeros bytes los frames
  //para cada frame un BYTE determina duracion
  //para cada frame un BYTE determina el efecto de sonido  
  //ahora la paleta de 720 colores porque los 16 * 3 primeros son de los frames de arriba y abajo
  //datos de cada frame
  v17 = getc(fAnimFile);
  frames = v17 + ((unsigned __int8)getc(fAnimFile) << 8);
  //allocateMemory(Size);
  v18 = malloc(frames);
  
  //esto tiene los efectos de sonido
  animationSoundEffectByFrame_45EEA4 = v18;
  v19 = malloc(frames);  
  framesDelay = v19;
  v20 = frames;
  for ( i = 0; i < (signed int)frames; ++i )
  {
    *((BYTE *)animationSoundEffectByFrame_45EEA4 + i) = getc(fAnimFile);
    v20 = frames;
  }
  v22 = 0;
  if ( (signed int)v20 > 0 )
  {
    do
      *((BYTE *)framesDelay + v22++) = getc(fAnimFile);
    while ( v22 < (signed int)frames);
  }
  v23 = 0;
  do
    setPaletteValue(v23++, 0, 0, 0);
  while ( v23 < 255 );
  DstBuf = malloc(0xFA00u);
  extractFromBpa("MENU.BPA", DstBuf, "FRAMES.BPK");
  //esto parece que pinta los cuadros de arriba y abajo
  
  
 
  decryptTexture((int)DstBuf, v45, 0, 768);
  decryptTexture((int)DstBuf, screenPtr, 768, 0xFA00u);
  v24 = 0;
  v25 = v45;
  do
  {//esta leyendo colores
    setPaletteValue(v24++, (unsigned __int8)v25[0], (unsigned __int8)v25[1], (unsigned __int8)v25[2]);
    v25 += 3;
  }
  while ( v24 < 16 );
  currentFrame = 0;
  if ( frames > 0 )
  {
    while ( 1 )
    {
      v26 = eventDetected();
      if (onKeyPressExit)
      {
        if ( v26 )
          break;
      }
      v27 = refreshScreenWithDelay();
      
	  //los dos primeros bytes contienen el tama\F1o del frame
	  v28 = v15(fAnimFile);
      v29 = getc(fAnimFile);
      fread(DstBuf, v28 + (v29 << 8), 1u, fAnimFile);
	  decryptAnimFrame();
      v30 = v27 + *((BYTE *)framesDelay + currentFrame);
      while ( refreshScreenWithDelay() < (unsigned int)v30 )
        ;
      if ( dword_45EA08 )
        callRefreshOrExecuteBackgroundFunction_43C8F0();
      v31 = 16;
      //v32 = (int)&unk_45EBD0;
	  v32 = (BYTE *)animPalette+48;

	  
	  //seteo lapaleta con el valor fijo
      do
      {
        v33 = *(BYTE *)v32;
        v34 = *(BYTE *)(v32 + 1);
        v35 = v32 + 1;
        v36 = *(BYTE *)(v35 + 1);
        v32 = v35 + 2;
        
		setPaletteValue(v31++, v33, v34, v36);
      }
      while ( v31 < 256 );
      if (screenResolution == 100 )
      {
		screenFrameSize = 8000;
		screenFrameStartPosition = screenPtr + 16000;
      }
      else
      {
		  screenFrameSize = 9600;
		  screenFrameStartPosition = screenPtr + 12800;
      }
	  //pinta los datos en pantalla
      memcpy((void *)screenFrameStartPosition, anim_currentFrameData, 4 * screenFrameSize);
      v39 = *((BYTE *)animationSoundEffectByFrame_45EEA4 + currentFrame);
      if ( v39 )
      {
        v40 = v43;
		//abirr efecto de sonido
        loadMenuSoundEffect(v43, v39, 0, 0x10000, 0x10000);
        v43 = v40 + 1;
        if ( v40 + 1 > 6 )
          v43 = 1;
      }
      ++currentFrame;
      if (currentFrame >= frames)
        break;
      v15 = getc;
    }
  }
  fclose(fAnimFile);
  v41 = 0;
  do
    setPaletteValue(v41++, 0, 0, 0);
  while ( v41 < 256 );
  v42 = 1;
  do
    stopSoundChannel_43C3E0(v42++);
  while ( v42 <= 6 );
  //free(anim_currentFrameData);
  free(DstBuf);
  free(animationSoundEffectByFrame_45EEA4);
  free(framesDelay);
}

//----- (004278E0) --------------------------------------------------------
FILE *checkAndOpenAnimation()
{
  unsigned int v0; // eax@2
  void *v1; // edi@2
  char v2; // cl@3
  char *v3; // edi@5
//  char v4; // al@6
  FILE *result; // eax@7
  FILE *v6; // esi@7
  __int32 v7; // edi@8
  char v8; // [sp+7h] [bp-65h]@2
  char Filename; // [sp+8h] [bp-64h]@1

  Filename = 0;
  if ( byte_462D50 == 2 )
  {
    v0 = strlen(byte_45FAA0) + 1;
    v1 = &v8;
    do
    {
      v2 = *((BYTE *)v1 + 1);
      v1 = (char *)v1 + 1;
    }
    while ( v2 );
    memcpy(v1, byte_45FAA0, v0);
  }
  v3 = &v8;
 /* do
    v4 = (v3++)[1];
  while ( v4 );
  *(_DWORD *)v3 = 1768841587;
  *((_DWORD *)v3 + 1) = 1634217581;
  *((_WORD *)v3 + 4) = 102;
  result = fopen(&Filename, "rb");*/
  result = fopen("SANIM.haf", "rb");
  v6 = result;
  if ( result ) ///jiwjofjofwejjfejioefjojioefjoiwef
  {
    fseek(result, 0, 2);
    v7 = ftell(v6);
    result = (FILE *)fclose(v6);
    if ( v7 > 0 )
    {
      openAnimation("SANIM.haf", 1, "tr0-mus.cmf", 2, "sanim-e.cmf", 1, 120);
	  stopSong();
      result = (FILE *)stopAndOpenMusic();
    }
  }
  return result;
}

//----- (00427D60) --------------------------------------------------------
/*int checkIntro()
{
  int v0; // ebx@1
  signed int v1; // ebp@1
  FILE *v2; // eax@2
  FILE *v3; // esi@2
  __int32 v4; // edi@3
  int v5; // eax@6
  char v6; // cl@7
  unsigned int v7; // eax@8
  char *v8; // edi@8
  char v9; // cl@9
  FILE *v10; // eax@10
  FILE *v11; // esi@10
  __int32 (  *v12)(FILE *); // ebp@11
  __int32 v13; // edi@11
  unsigned int v14; // eax@20
  char *v15; // edi@20
  char v16; // cl@21
  int v17; // eax@23
  const void *v18; // esi@23
  char v19; // cl@24
  unsigned int v20; // eax@25
  char *v21; // edi@25
  char v22; // cl@26
  FILE *v23; // eax@27
  FILE *v24; // esi@27
  __int32 v25; // edi@28
  int result; // eax@30
  bool v27; // sf@30
  unsigned __int8 v28; // of@30
  const char *v29; // [sp-8h] [bp-120h]@13
  int v30; // [sp-4h] [bp-11Ch]@13
  _UNKNOWN *v31; // [sp+10h] [bp-108h]@18
  int v32; // [sp+14h] [bp-104h]@8
  char Filename[256]; // [sp+18h] [bp-100h]@7

  v0 = 0;
  v1 = (signed int)&unk_4568D8;
  do
  {
    v2 = fopen((const char *)(v1 - 16), "rb");
    v3 = v2;
    if ( !v2 || (fseek(v2, 0, 2), v4 = ftell(v3), fclose(v3), v4 < 1) )
    {
      v30 = 20 * v0 + 4548808;
      v29 = "\nDEATH RALLY ERROR: File %s is not found!\n";
LABEL_33:
      printf(v29, v30);
      printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
      nullsub_1();
      freeMusic();
      exit(112);
    }
    if ( v4 != *(_DWORD *)v1 )
    {
      printf("\nDEATH RALLY ERROR: File %s is not in original form!\n", 20 * v0 + 4548808);
      printf("Please consult DRHELP.EXE for more information on how to resolve this problem.\n");
      nullsub_1();
      freeMusic();
      exit(112);
    }
    v1 += 20;
    ++v0;
  }
  while ( v1 < (signed int)&unk_4569F0 );
  byte_462D50 = 2;
  v5 = 0;
  do
  {
    v6 = byte_45FAA0[v5];
    Filename[v5++] = v6;
  }
  while ( v6 );
  v7 = strlen(aSanim_haf) + 1;
  v8 = (char *)&v32 + 3;
  do
    v9 = (v8++)[1];
  while ( v9 );
  memcpy(v8, aSanim_haf, v7);
  v10 = fopen(Filename, "rb");

  v11 = v10;
  if ( !v10 )
  {
    v12 = ftell;
    goto LABEL_17;
  }
  fseek(v10, 0, 2);
  v12 = ftell;
  v13 = ftell(v11);
  fclose(v11);
  if ( v13 < 1 )
LABEL_17:
    byte_462D50 = 1;
  v32 = 0;
  v31 = &unk_4569F0;
  while ( 2 )
  {
    Filename[0] = 0;
    if ( byte_462D50 == 2 )
    {
      v14 = strlen(byte_45FAA0) + 1;
      v15 = (char *)&v32 + 3;
      do
        v16 = (v15++)[1];
      while ( v16 );
      memcpy(v15, byte_45FAA0, v14);
    }
    v17 = (int)((char *)v31 - 16);
    v18 = (char *)v31 - 16;
    do
      v19 = *(BYTE *)v17++;
    while ( v19 );
    v20 = v17 - (_DWORD)v18;
    v21 = (char *)&v32 + 3;
    do
      v22 = (v21++)[1];
    while ( v22 );
    memcpy(v21, v18, v20);
    v23 = fopen(aSanim_haf, "rb");
    //v23 = fopen(Filename, "rb");
    v24 = v23;
    if ( v23 )
    {
      fseek(v23, 0, 2);
      v25 = v12(v24);
      fclose(v24);
     if ( v25 > 0 && v25 != *(_DWORD *)v31 )
      {
        v30 = 20 * v32 + 4549088;
        v29 = "\nDEATH RALLY ERROR: File %s is not in original form!\n";
        goto LABEL_33;
      }
    }
    result = (int)((char *)v31 + 20);
    v28 = __OFSUB__((char *)v31 + 20, &effectVolume_456A2C);
    v27 = (_UNKNOWN *)((char *)v31 + 20) - (_UNKNOWN *)&effectVolume_456A2C < 0;
    ++v32;
    v31 = (char *)v31 + 20;
    if ( v27 ^ v28 )
      continue;
    return result;
  }
}*/
