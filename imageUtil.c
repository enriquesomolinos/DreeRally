#define _CRT_NONSTDC_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#pragma warning ( disable: 4146  4700 4703 4005)

#pragma warning(push)
#pragma warning(disable: warning-code) //4996 for _CRT_SECURE_NO_WARNINGS equivalent

#pragma warning(pop)

#include "graphics.h"
#include "defs.h"
#include "menus.h"
#include "dr.h"
#include <windows.h>

const int DEFAULT_BIGLETTER_SPACING_OFFSET = -23;

 void *choo2Bpk; // idb

 char  unk_445928[] = {9,0xc,
					  9,9,9,9,9,9,9,9,9,9, 
					  9,9,9,9,9,9,9,9,9,9, 
					  9,9,9,9,9,9,9,9,9,9, 
					  9,9,9,9,9,9,9,9,9,9, 
					  9,9,9,9,9,9,9,9,9,9,
					  9,9,9,9,9,9,9,9,9,9, 
					  9,9 };

 char byte_445892[] = { '\x12','\x8','\x0E','\x13','\x10','\x16','\x12','\x12','\x20','\x12',
	                    '\x12','\x11','\x10','\x12','\x13','\x1A','\x12','\x13','\x10','\x0B',
						'\x6','\x0B','\x0F','\x14'}; // weak
//char byte_445892[] = { '\x12','\x8','\x0E','\x13','\x10','\x16','\x12','\x12','\x10','\x12','\x12','\x11','\x10','\x12','\x13','\x1A','\x12','\x13','\x10','\x0B','\x6','\x0B','\x0F','\x14','\x0','\x0','\x0','\x0','\x0','\x0' }; // weak

 //char byte_4458B0[] = { '\x10', '\x10', '\x0A', '\x5', '\x8', '\x0B', '\x0B', '\x0D', '\x0B', '\x5', '\x6', '\x6', '\x9', '\x0B', '\x5', '\x0B', '\x4', '\x0A', '\x0B', '\x5', '\x9', '\x0A', '\x0A', '\x0A', '\x0A', '\x0A', '\x0A', '\x0A', '\x4', '\x5', '\x9', '\x0B', '\x8', '\x8', '\x0C', '\x0B', '\x0B', '\x0A', '\x0B', '\x0A', '\x0A', '\x0C', '\x0B', '\x5', '\x9', '\x0B', '\x0A', '\x0E', '\x0B', '\x0B', '\x0A', '\x0B', '\x0B', '\x0A', '\x0A', '\x0B', '\x0C', '\x0F', '\x0B', '\x0B', '\x0A', '\x7', '\x0A', '\x6', '\x0A', '\x0A', '\x5', '\x0B', '\x0A', '\x9', '\x0A', '\x9', '\x9', '\x0A', '\x0A', '\x5', '\x8', '\x0A', '\x9', '\x0C', '\x0A', '\x0A', '\x9', '\x0A', '\x0A', '\x9', '\x9', '\x0A', '\x0A', '\x0E', '\x0A', '\x0A', '\x9', '\x7', '\x4', '\x7', '\x9', '\x0B', '\x10', '\x0D', '\x0E', '\x0D', '\x9', '\x0D', '\x0D', '\x0D', '\x0D', '\x0D', '\x0C', '\x0D', '\x0D', '\x0', '\x0', '\x0', '\x0', '\x0', '\x0', '\x0', '\x9', '\x0C', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9' };
//ver porque byte_445892
 char letterSpacing_4458B0[] = { '\x10', '\x10', '\x0A', '\x5', '\x8', '\x0B', '\x0B', '\x0D', '\x0B', '\x5',
					   '\x6',  '\x6',  '\x9',  '\x0B', '\xB', '\x5', '\x4', '\x0A', '\x0B', '\x5', //20
						'\x5', '\x0A', '\x5', '\x0A', '\x0A', '\x0A', '\x0A', '\x0A', '\x4', '\x5',
						'\x9', '\x0B', '\x8', '\x8', '\x5', '\x0B', '\x0B', '\x0A', '\x0B', '\x0A', //40
						'\x0A', '\x0C', '\x0B', '\x5', '\x0B', '\x0B', '\x0A', '\x0E', '\x0B', '\x0B', 
						'\x0A', '\x0B', '\x0B', '\x0A', '\x0A', '\x0B', '\x0C', '\x0F', '\x0B', '\x0B',//60
						'\x0A', '\x7',  '\x0A', '\x0F',  '\x0A', '\x0A', '\x5', '\x0B', '\x0A', '\x9', 
						'\x0A', '\x9',  '\x9',  '\x0A', '\x0A', '\x0A', '\x0A',  '\x0A', '\x9', '\x0C', //80
						'\x0A', '\x4', '\x9', '\x0A', '\x0A', '\x0A', '\x9', '\x0A', '\x0A', '\x0E', 
						'\x0A', '\x0A', '\x9', '\x9', '\x4', '\x0C', '\x9', '\x0B', '\x10', '\x0D', //100
						'\x0E', '\x0D', '\x9', '\x0D', '\x0D', '\x0D', '\x0D', '\x0D', '\x0C', '\x0D', 
						'\x0D', '\x0',  '\x0', '\x0',  '\x0',  '\x0',  '\x0',  '\x0',  '\x9',  '\x0C',//120
						'\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9',
						'\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', //140
						'\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', 
						'\x9', '\x9', '\x9',  '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', //160
						'\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9', 
						'\x9', '\x9', '\x9', '\x9', '\x9','\x9', '\x9', '\x9', '\x9', '\x9', '\x9', '\x9' };
 char bigLetterSpacing_445848[] ={ '\x20','\x20','\x14','\x9','\x0E','\x14','\x15','\x18','\x15','\x0A','\x0C','\x0B','\x10','\x15','\x9','\x14','\x8','\x13',
						'\x15','\x0A','\x14','\x13','\x14','\x14','\x13','\x12','\x13','\x12','\x8','\x9','\x10',
                         '\x15','\x10','\x0F','\x16','\x16','\x15','\x14','\x16','\x13','\x12','\x16','\x16','\x0A','\x11','\x15','\x13','\x1B','\x15','\x16','\x14',
						'\x16','\x15','\x14','\x14','\x16','\x18','\x1F','\x16','\x17',
	                    '\x13','\x0C','\x14','\x0C','\x14','\x13','\x9','\x14','\x12','\x11','\x12','\x10','\x0F','\x13',
						'\x12','\x8','\x0E','\x13','\x10','\x16','\x12','\x12','\x10','\x12','\x12','\x11','\x10','\x12','\x13','\x1A','\x12','\x13',
						'\x10','\x0B','\x6','\x0B','\x0F','\x14','\x0','\x0','\x0','\x0','\x0','\x0','\x10','\x10','\x0A','\x5','\x8','\x0B',
						'\x0B','\x0D','\x0B','\x5','\x6','\x6','\x9','\x0B','\x5','\x0B','\x4','\x0A','\x0B','\x5','\x9','\x0A','\x0A',
						'\x0A','\x0A','\x0A','\x0A','\x0A','\x4','\x5','\x9','\x0B','\x8','\x8','\x0C','\x0B','\x0B','\x0A','\x0B','\x0A',
						'\x0A','\x0C','\x0B','\x5','\x9','\x0B','\x0A','\x0E','\x0B','\x0B','\x0A','\x0B','\x0B','\x0A','\x0A','\x0B',
						'\x0C','\x0F','\x0B','\x0B','\x0A','\x7','\x0A','\x6','\x0A','\x0A','\x5','\x0B','\x0A','\x9','\x0A','\x9','\x9',
						'\x0A','\x0A','\x5','\x8','\x0A','\x9','\x0C','\x0A','\x0A','\x9','\x0A','\x0A','\x9','\x9','\x0A','\x0A','\x0E',
						'\x0A','\x0A','\x9','\x7','\x4','\x7','\x9','\x0B','\x10','\x0D','\x0E','\x0D','\x9','\x0D','\x0D','\x0D','\x0D',
						'\x0D','\x0C','\x0D','\x0D','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x9' }; // weak

 //----- (0041A370) --------------------------------------------------------
 
 /* for(v5=0;v5<10;v5++){
	  
	  drawImageWithPosition2((int)fsma3fBpk+16*13*v5, 16, 13,(int)((char *)screenBuffer+v5*16));
  }*/
unsigned int __cdecl drawInGamePrices(const char *text, int position)

{
  int height; // ebx@1
  int width; // ebp@1
  unsigned int v4; // esi@1
  unsigned int result; // eax@1
  int v6; // edi@2
  char v7; // al@3
  int v8; // [sp-8h] [bp-18h]@3

  //height = (unsigned __int8)letterSpacing_4458B0[95];//95
  //  width = (unsigned __int8)letterSpacing_4458B0[96];//96
  height = 16;
  width = 13;
  v4 = 0;
  result = strlen(text);
  if ( result )
  {
    v6 = position;
    do
    {
      v7 =text[v4];
      v8 = (int)((char *)screenBuffer + v6);
      if ( v7 == 36 ) //es el char $
      {
        drawImageWithPosition2((int)fsma3fBpk, height, width, v8);
        v6 += (unsigned __int8)letterSpacing_4458B0[0];//97
      }
      else
      {
        drawImageWithPosition2((int)((char *)fsma3fBpk + height * width * ((unsigned __int8)v7 - 47)), height, width, v8);
        v6 += (unsigned __int8)letterSpacing_4458B0[55+text[v4]];//55+text[v4]
      }
      ++v4;
      result = strlen(text);
    }
    while ( v4 < result );
  }
  return result;
}
// 445914: using guessed type char byte_445914;
// 445915: using guessed type char byte_445915;
// 445916: using guessed type char byte_445916;

//----- (0041A430) --------------------------------------------------------
int __cdecl writeTextInScreen(const char *text, int screenOffset)
{
  int v2; // esi@1
  unsigned int v3; // ebp@1
  int v4; // edi@1
  int result; // eax@1
  int v6; // ebx@2
  const char *v7; // edx@3
  int v8; // eax@3
  void *v9; // edx@7
  const char *v10; // eax@17
  int v11; // edx@17
  char v12; // cl@18
  signed int v13; // [sp+Ch] [bp-8h]@1

  //ancho y alto escribe un 10h
  v2 = (unsigned __int8)letterSpacing_4458B0[0];
  v3 = 0;
  v4 = (unsigned __int8)letterSpacing_4458B0[1];
  //v4 = (unsigned __int8)byte_4458B1;
  v13 = 0;
  result = strlen(text);
  if ( result )
  {
    v6 = screenOffset;
    do
    {
      v7 = text;
      v8 = text[v3];
      if ( v8 == 91 )
      {
        v13 = 2;
      }
      else if (text[v3] == 123 )
      {
        v13 = 0;
      }
      else
      {
        if (text[v3] != 125 )
        {
          if ( !v13 )
          {
            v9 = graphicsGeneral.fsma3bBpk;
            goto LABEL_12;
          }
          if ( v13 == 1 )
          {
            drawImageWithPosition((int)((char *)graphicsGeneral.fsma3cBpk + v2 * v4 * (v8 - 32)), v2, v4, (int)((char *)screenBuffer + v6));
          }
          else if ( v13 == 2 )
          {
            v9 = graphicsGeneral.fsma3aBpk;
LABEL_12:
            drawImageWithPosition((int)((char *)v9 + v2 * v4 * (v8 - 32)), v2, v4, (int)((char *)screenBuffer + v6));
          }
          v7 = text;
		  if(text[v3] == 'i' || text[v3] == 'I'  ){
			  int a =0;
		  }
         v6 += (unsigned __int8)byte_445892[text[v3]];
		  //cambiado para que se vea algo mejor pero lo comentado es lo que habia
		 // v6 += (unsigned __int8)letterSpacing_4458B0[45+text[v3]];
          goto LABEL_17;
        }
        v13 = 1;
      }
LABEL_17:
      v10 = v7;
      ++v3;
      v11 = (int)(v7 + 1);
      do
        v12 = *v10++;
      while ( v12 );
      result = (int)&v10[-v11];
    }
    while ( v3 < result );
  }
  return result;
}
// 4458B0: using guessed type char letterSpacing_4458B0;
// 4458B1: using guessed type char byte_4458B1;


//----- (0041C9F0) --------------------------------------------------------
int __cdecl getBoxBigTextOffset(const char *a1)
{
  const char *v1; // ecx@1
  int result; // eax@1
  unsigned int v3; // esi@1
  char v4; // dl@2

  v1 = a1;
  result = 0;
  v3 = 0;
  do
    v4 = *v1++;
  while ( v4 );
  if ( v1 != a1 + 1 )
  {
    do

	
      //result += (unsigned __int8)menuActive_4457F0[58+a1[v3++]];
	result += (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+a1[v3++]];
    while ( v3 < strlen(a1) );
  }
  return result;
}
 
 
 //----- (0041FA50) --------------------------------------------------------
int __cdecl sub_41FA50(const char *a1)
{
  const char *v1; // eax@1
  int v2; // ebx@1
  unsigned int v3; // edx@1
  char v4; // cl@2

  v1 = a1;
  v2 = 0;
  v3 = 0;
  do
    v4 = *v1++;
  while ( v4 );
  if ( v1 != a1 + 1 )
  {
    do
      v2 += (unsigned __int8)byte_445892[a1[v3++]];
    while ( v3 < strlen(a1) );
  }
  return (96 - v2) / 2;
}

//----- (0041FAB0) --------------------------------------------------------
//offset para los textos en los recuadros de las pantallas para que quede centrado el texto
int __cdecl getBoxTextOffset(const char *a1)
{
  const char *v1; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edx@1
  char v4; // cl@2
  char v5; // al@4
  int v6; // eax@5

  v1 = a1;
  v2 = 0;
  v3 = 0;
  do
    v4 = *v1++;
  while ( v4 );
  if ( v1 != a1 + 1 )
  {
    do
    {
      v5 = a1[v3];
      if ( v5 == 36 )//es el $
        v6 = (unsigned __int8)letterSpacing_4458B0[97];
      else
        v6 = (unsigned __int8)letterSpacing_4458B0[55+(unsigned __int8)v5];
      v2 += v6;
      ++v3;
    }
    while ( v3 < strlen(a1) );
  }
  return (96 - v2) / 2;
}
// 445916: using guessed type char byte_445916;

//----- (0041FB20) --------------------------------------------------------
int __cdecl getBoxTextSize(const char *a1)
{
  const char *v1; // ecx@1
  int result; // eax@1
  unsigned int v3; // esi@1
  char v4; // dl@2

  v1 = a1;
  result = 0;
  v3 = 0;
  do
    v4 = *v1++;
  while ( v4 );
  if ( v1 != a1 + 1 )
  {
    do
      result += (unsigned __int8)letterSpacing_4458B0[90+a1[v3++]];
	//result += (unsigned __int8)byte_44590A[a1[v3++]];
    while ( v3 < strlen(a1) );
  }
  return result;
}

//----- (0041FB70) --------------------------------------------------------
/*esto creo que no es necesario*/
int __cdecl getNameOffsetPositionRight(const char *a1)
{
  const char *v1; // eax@1
  int v2; // ebx@1
  unsigned int v3; // edx@1
  char v4; // cl@2

  v1 = a1;
  v2 = 0;
  v3 = 0;
  do
    v4 = *v1++;
  while ( v4 );
  if ( v1 != a1 + 1 )
  {
    do
      v2 += (unsigned __int8)letterSpacing_4458B0[90+a1[v3++]];
	//v2 += (unsigned __int8)byte_44590A[a1[v3++]];


	
    while ( v3 < strlen(a1) );
  }
  return (96 - v2) / 2;
}

//----- (0041FBD0) --------------------------------------------------------
int __cdecl getBigTextMidSize(const char *a1)
{
  const char *v1; // ecx@1
  signed int v2; // eax@1
  unsigned int v3; // esi@1
  char v4; // dl@2

  v1 = a1;
  v2 = 0;
  v3 = 0;
  do
    v4 = *v1++;
  while ( v4 );
  if ( v1 != a1 + 1 )
  {
    do
	//no es menu active es bigspacing
      v2 += (unsigned __int8)bigLetterSpacing_445848[DEFAULT_BIGLETTER_SPACING_OFFSET+ a1[v3++]];
	  //v2 += (unsigned __int8)menuActive_4457F0[587ç+ a1[v3++]];
    while ( v3 < strlen(a1) );
  }
  return v2 / 2;
}
// 41FBD0: could not find valid save-restore pair for edi
// 41FBD0: could not find valid save-restore pair for esi



//----- (00421AE0) --------------------------------------------------------
int __cdecl drawBorder(int a1, int a2, int a3, int a4)
{
  int v4; // edi@1
  int v5; // ebx@1
  int result; // eax@1
  int i; // ecx@1
  char *v8; // edx@2
  int j; // ecx@3
  char *v10; // edx@4
  int v11; // ecx@6
  char *v12; // edx@7
  char *v13; // edx@10

  v4 = 640 * a2;
  drawImageWithPosition((int)choo2Bpk, 24, 24, (int)((char *)screenBuffer + 640 * a2 + a1));
  drawImageWithPosition((int)((char *)choo2Bpk + 576), 24, 24, (int)((char *)screenBuffer + 640 * a2 + a1 + a3 - 24));
  drawImageWithPosition((int)((char *)choo2Bpk + 1152), 24, 24, (int)((char *)screenBuffer + 128 * (5 * (a4 + a2) - 120) + a1));
  v5 = 640 * (a4 + a2);
  drawImageWithPosition((int)((char *)choo2Bpk + 1728), 24, 24, (int)((char *)screenBuffer + v5 + a1 + a3 - 15384));
  result = a3 - 48;
  for ( i = 0; i < result; v8[a1 + 1304] = 22 )
    v8 = (char *)screenBuffer + v4 + i++;
  for ( j = 0; j < result; v10[a1 - 1896] = 22 )
    v10 = (char *)screenBuffer + v5 + j++;
  if ( a4 - 48 > 0 )
  {
    result = 640 * a2;
    v11 = a4 - 48;
    do
    {
      v12 = (char *)screenBuffer + result;
      result += 640;
      --v11;
      v12[a1 + 15362] = 22;
    }
    while ( v11 );
    if ( a4 - 48 > 0 )
    {
      result = a4 - 48;
      do
      {
        v13 = (char *)screenBuffer + v4 + a1;
        v4 += 640;
        --result;
        v13[a3 + 15357] = 22;
      }
      while ( result );
    }
  }
  return result;
}

//----- (00421C40) --------------------------------------------------------
int __cdecl drawBorder2(int a1, int a2, unsigned int a3, int a4)
{
  int result; // eax@1
  int v5; // edx@1
  int v6; // edx@3
  int v7; // ecx@6
  int v8; // edi@6
  char *v9; // edx@7
  char *v10; // esi@7
  int v11; // esi@8
  int v12; // ecx@9
  char *v13; // edx@10
  char *v14; // edi@10
  signed int v15; // [sp+10h] [bp-8h]@1
  signed int v16; // [sp+10h] [bp-8h]@3

  result = a1;
  v5 = 640 * a2;
  v15 = 5;
  do
  {
    memcpy((char *)screenBuffer + v5 + a1, (char *)graphicsGeneral.menubg5Bpk + v5 + a1, a3);
    v5 += 640;
    --v15;
  }
  while ( v15 );
  v6 = 640 * (a2 + a4 - 5);
  v16 = 5;
  do
  {
    memcpy((char *)screenBuffer + v6 + a1, (char *)graphicsGeneral.menubg5Bpk + v6 + a1, a3);
    v6 += 640;
    --v16;
  }
  while ( v16 );
  if ( a4 > 0 )
  {
    v7 = 640 * a2;
    v8 = a4;
    do
    {
      v9 = (char *)graphicsGeneral.menubg5Bpk + v7 + a1;
      v10 = (char *)screenBuffer + v7 + a1;
      *(_DWORD *)v10 = *(_DWORD *)v9;
      v7 += 640;
      --v8;
      v10[4] = v9[4];
    }
    while ( v8 );
    v11 = a4;
    if ( a4 > 0 )
    {
      v12 = 640 * a2;
      do
      {
        v13 = (char *)graphicsGeneral.menubg5Bpk + v12 + a1 + a3 - 5;
        v14 = (char *)screenBuffer + v12 + a1 + a3 - 5;
        *(_DWORD *)v14 = *(_DWORD *)v13;
        v12 += 640;
        --v11;
        v14[4] = v13[4];
      }
      while ( v11 );
    }
  }
  return result;
}

//----- (0043BF50) --------------------------------------------------------
int __cdecl drawImageWithPosition2(int texture, int height, int width, int screenBufferPtr)
{
  int v4; // ecx@1
  int result; // eax@1
  int v6; // ebp@2
  int v7; // esi@4
  char v8; // dl@5

  v4 = texture;
  result = screenBufferPtr;
  if (width > 0 )
  {
    v6 = width;
    do
    {
      if (height > 0 )
      {
        v7 = height;
        do
        {
          v8 = *(byte *)v4++;
          *(byte *)result++ = v8;
          --v7;
        }
        while ( v7 );
      }
      result += 640 - height;
      --v6;
    }
    while ( v6 );
  }
  return result;
}

//----- (0043BF90) --------------------------------------------------------
int __cdecl drawImageWithPosition(int icon, int width, int height, int pscreenBufferPos)
{
  int result; // eax@1
  int screenIcon; // edx@1
  int screenPos; // ecx@1
  int v7; // ebx@2
  int v8; // esi@4

  result = height;
  screenIcon = icon;
  screenPos = pscreenBufferPos;
  if (height > 0 )
  {
    v7 = height;
    do
    {
      if (width > 0 )
      {
        v8 = width;
        do
        {
          if ( *(byte *)screenIcon)
            *(byte *)screenPos = *(byte *)screenIcon;
          ++screenIcon;
          ++screenPos;
          --v8;
        }
        while ( v8 );
      }
      result = 640 - width;
	  screenPos += 640 - width;
      --v7;
    }
    while ( v7 );
  }
  return result;
}

unsigned int __cdecl drawTextWithFont(int font, int a2, const char *text, int screenPosition)
{
  int height; // edx@1
  int width; // ebp@1
  unsigned int v6; // esi@1
  unsigned int result; // eax@1
  int screenPositionOffset; // ebx@2
  char v9; // al@3
  int v10; // [sp+10h] [bp-8h]@1

  height = *(byte *)(a2 + 1); 
  width = *(byte *)a2;
  v10 = *(byte *)(a2 + 1);
  /*height = 32;
  width = 32;
  v10 = 32;*/
  
  v6 = 0;
  result = strlen(text);
  if ( result )
  {
	  screenPositionOffset = screenPosition;
    do
    {
      v9 = text[v6];
      if ( v9 == -6 )
      {
        ++screenPositionOffset;
      }
      else
      {
		  //TODO fix controlamos que no sea negativo que la lia!
		  if (v9 < 32) {
			  v9 = 32;
		  }
        drawImageWithPosition(font + width * height * ((unsigned __int8)v9 - 32), width, height, (int)((char *)screenBuffer + screenPositionOffset));
		height = v10;
		//aqui era -24 pero se ve mal!
		if(*(byte *)a2== *(byte *)bigLetterSpacing_445848){
			
			screenPositionOffset += *(byte *)(text[v6] + a2 - 30);
		}else{
			screenPositionOffset += *(byte *)(text[v6] + a2 - 24);
		}
		
      }
      ++v6;
      result = strlen(text);
    }
    while ( v6 < result );
  }
  return result;
}
