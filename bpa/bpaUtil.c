

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../defs.h"
#include "../dr.h"
#include "../config.h"




void * unk_463E20; // weak

//----- (004027B0) --------------------------------------------------------
int __cdecl extractFromBpa(char *bpaFilename, void *dest, char * filename)
{
  int v3; // ebx@1
  FILE *bpafile; // esi@1
  char *v5; // eax@1
  unsigned int v6; // ecx@1
  char v7; // dl@2
  int fileOrder; // ebp@5
  int fatPointer; // edi@6
  int fileDataPointer = 0;
  int fileSize = 0;
  unsigned int v10; // eax@11
  char *v11; // edi@11
  char v12; // cl@12
  char *v13; // edi@13
  char v14; // al@14
  unsigned int v15; // eax@15
  char *v16; // edi@15
  char v17; // cl@16
  char *v18; // edi@17
  char v19; // al@18
  FILE *v20; // esi@20
  __int32 v21; // eax@20
//  int *v22; // ecx@21
  int v23; // edx@21
  char buffer[4]; // [sp+10h] [bp-68h]@1
  int v26; // [sp+14h] [bp-64h]@3
  char Str[16]; // [sp+18h] [bp-60h]@1
  int v28; // [sp+28h] [bp-50h]@11
  int v29; // [sp+2Ch] [bp-4Ch]@11
  int v30; // [sp+30h] [bp-48h]@11
  int v31; // [sp+34h] [bp-44h]@11
  char fat[0x10EF];//cabecera del fichero
  char *destStream;
  int debug=1;
  char completeFile[300] = "";//"C:/proyectos/Drwin/Debug/";
  FILE *extractedFile;
  if(mainArgs.mod){
	  strcat(completeFile,"mods/");
	  strcat(completeFile, mainArgs.mod);
	   strcat(completeFile,"/files/");
	   strcpy(Str, filename);
	   strupr(Str);
	   strcat(completeFile,Str);
	  if (	extractedFile=fopen(completeFile, "rb") ) { // file does not exist

				 fseek(extractedFile, 0L, SEEK_END);

				 fileSize = ftell(extractedFile);
					destStream = malloc(fileSize * sizeof(char));
					//extractedFile=fopen(filename, "rb");
				  fseek(extractedFile, 0, SEEK_SET);


				  fread(dest, 1u,fileSize, extractedFile);
				//  dest = destStream;
			  
		 
				 return fclose(extractedFile);
	   }
	}
  v3 = filename;
  strcpy(Str, filename);
  bpafile = fopen(bpaFilename, "rb");
  fread(buffer, 4, 1, bpafile);
  fread(fat, 0x10EF, 1, bpafile);
  fclose(bpafile);
  strupr(Str);
  v5 = Str;
  v6 = 0;
  do
    v7 = *v5++;
  while ( v7 );
  v26 = v5 - &Str[1];
  if ( v5 != &Str[1] )
  {
    do
    {
      Str[v6] += 3 * (39 - v6);
      ++v6;
    }
    while ( v6 < strlen(Str) );
  }
  fileOrder = 0;
  if (buffer <= 0 )
  {
LABEL_11:
    v28 = 1651470928;//Prob
    v31 = 5972072;//h ]
    v30 = 1953068832;//wit
    v29 = 1936549228;//lems
    v10 = strlen(bpaFilename) + 1;
    v11 = &Str[15];
    do
      v12 = (v11++)[1];
    while ( v12 );
    memcpy(v11, bpaFilename, v10);
    v13 = &Str[15];
    do
      v14 = (v13++)[1];
    while ( v14 );
    *(_WORD *)v13 = 8285;
    v13[2] = 0;
    v15 = strlen((const char *)v3) + 1;
    v16 = &Str[15];
    do
      v17 = (v16++)[1];
    while ( v17 );
    memcpy(v16, (const void *)v3, v15);
    v18 = &Str[15];
    do
      v19 = (v18++)[1];
    while ( v19 );
    *(_DWORD *)v18 = 1818846752;//fil
    *((_WORD *)v18 + 2) = 8549;//e!
    v18[6] = 0;
    errorExitScreen((int)&v28);
  }
  fatPointer = 0;
  
  while ( strcmp((char *)&fat+fatPointer, Str) || fileOrder == -1 )
  {
    ++fileOrder;
	fatPointer += 17; //cada entrada son 17
    if (fileOrder >= buffer)
    {
      v3 = filename;
      goto LABEL_11;
    }
  }
  v20 = fopen(bpaFilename, "rb");
  fseek(v20, 4339, 0);
  v21 = 0;
  fileDataPointer = 0;
  if (fileOrder > 0)
  {
	  //v19 = &dword_463E2D; -> apunta a la primera posicion de tamaño de la cabecera deberia ser 18
	  fileDataPointer = 4339;
	  	  v21 += 17;
	  v23 = fileOrder;
	  do
	  {  
		  
		  
		  fseek(v20, v21, 0);
		  fread(&fileSize, 4u, 1u, v20);
		  if (fileOrder > 0) {
			  fileDataPointer += fileSize;
			  v21 += 17;
			  --v23;
		  }
		  
	  } while (v23);
	  fseek(v20, v21, 0);
	  fread(&fileSize, 4u, 1u, v20);
  }else{
	   //v19 = &dword_463E2D; -> apunta a la primera posicion de tamaño de la cabecera deberia ser 18
	  fileDataPointer = 4339;
	  v21 = 17;
	  v23 = fileOrder;
		  fseek(v20, v21, 0);
		  fread(&fileSize, 4u, 1u, v20);
		  if (fileOrder > 0) {
			  fileDataPointer += fileSize;
			  v21 += 17;
			  --v23;
		  }
		  
	  
	  fseek(v20, v21, 0);
	  fread(&fileSize, 4u, 1u, v20);
  }

LABEL_12:
  destStream = malloc(fileSize * sizeof(char));
  fseek(v20, fileDataPointer, SEEK_SET);
  
  fread(dest, fileSize, 1u, v20);
 // dest = destStream;

  //fcloseall ();
	return fclose(v20);
}

 //----- (00417B90) --------------------------------------------------------
int __cdecl getFileSizeFromBpa(char *bpaFile, char * filename)
{
  char  v2; // ebp@1
  FILE *v3; // esi@1
  signed int i; // ecx@1
  int fileOrd; // edi@3
  const char *headerOffset; // ebp@4
  unsigned int v7; // eax@9
  char *v8; // edi@9
  char v9; // cl@10
  char *v10; // edi@11
  char v11; // al@12
  unsigned int v12; // eax@13
  char *v13; // edi@13
  char v14; // cl@14
  char *v15; // edi@15
  char v16; // al@16
  FILE *bpa; // esi@18
  __int32 fileHeaderStart; // eax@18
  int *v19; // ecx@19
  int v20; // edx@19
  int filseSize; // edi@21
  int DstBuf; // [sp+14h] [bp-64h]@1
  char fileNameUpper[16]; // [sp+18h] [bp-60h]@1
  int v25; // [sp+28h] [bp-50h]@9
  int v26; // [sp+2Ch] [bp-4Ch]@9
  int v27; // [sp+30h] [bp-48h]@9
  int v28; // [sp+34h] [bp-44h]@9

  v2 = filename;
  strcpy(fileNameUpper, (const char *)filename);
  //poner aqui algo para que recompile bien cuando falle!!!!!
  v2=0;
  v3 = fopen(bpaFile, "rb");
  fread(&DstBuf, 4u, 1u, v3);
  unk_463E20 =malloc(0x10EFu);
  fread(unk_463E20, 0x10EFu, 1u, v3);
  fclose(v3);
  strupr(fileNameUpper);
  //aqui se codifica para leer la cabecera
  for ( i = 0; i < (signed int)strlen(fileNameUpper); ++i )
	  fileNameUpper[i] += 3 * (39 - i);
  fileOrd = 0;
  if ( DstBuf <= 0 )
  {
LABEL_9:
    v25 = 1651470928;
    v28 = 5972072;
    v27 = 1953068832;
    v26 = 1936549228;
    v7 = strlen(bpaFile) + 1;
    v8 = &fileNameUpper[15];
    do
      v9 = (v8++)[1];
    while ( v9 );
    memcpy(v8, bpaFile, v7);
    v10 = &fileNameUpper[15];
    do
      v11 = (v10++)[1];
    while ( v11 );
    *(_WORD *)v10 = 8285;
    v10[2] = 0;
    v12 = strlen((const char *)v2) + 1;
    v13 = &fileNameUpper[15];
    do
      v14 = (v13++)[1];
    while ( v14 );
    memcpy(v13, (const void *)v2, v12);
    v15 = &fileNameUpper[15];
    do
      v16 = (v15++)[1];
    while ( v16 );
    *(_DWORD *)v15 = 1818846752;
    *((_WORD *)v15 + 2) = 8549;
    v15[6] = 0;
    errorExitScreen((int)&v25);
  }
  headerOffset = (const char *)unk_463E20;
  while ( strcmp(headerOffset, fileNameUpper) || fileOrd == -1 )
  {
    ++fileOrd;
	headerOffset += 17;
    if (fileOrd >= DstBuf )
    {
	 //salimos con error		
      v2 = filename;
      goto LABEL_9;
    }
  }
  bpa = fopen(bpaFile, "rb");
  fseek(bpa, 4339, 0);
  fileHeaderStart = 17;
  if (fileOrd > 0 )
  {
    //v19 = &dword_463E2D; -> apunta a la primera posicion de tamaño de la cabecera deberia ser 18
	 fileHeaderStart = 17;
    v20 = fileOrd;
    do
    {
		//fileHeaderStart += *v19;
		fileHeaderStart = fileHeaderStart + 17;
      --v20;
    }
    while ( v20 );
  }
  fseek(bpa, fileHeaderStart, 0);
  fread(&filseSize, 4u, 1u, bpa);
  
 // filseSize = *(int *)((char *)&dword_463E2D + 17 * fileOrd);
  fclose(bpa);
  return filseSize;
}

//----- (004271F0) --------------------------------------------------------
int __cdecl openPalFromBpa(char * filename)
{
  signed int v1; // esi@1
  char *v2 = malloc(768); // edi@1
  int result; // eax@2
  void * v6 = malloc(768); // [sp+8h] [bp-300h]@1
  
  
  extractFromBpa("MENU.BPA", v6, filename);
  v1 = 0;
  //v1=(signed int)dword_45FC44;
  v2 = v6; 
 // v2 = &v7;
  do
  {
	 
	  
    palette1[v1] = colorToPaletteEntry(v2[0] << 16, 6553600);
	palette1[v1 + 1] = colorToPaletteEntry(v2[1] << 16, 6553600);
    result = colorToPaletteEntry(v2[2] << 16, 6553600);
	palette1[v1+2] = result;
	
    v1 += 3;
    v2 += 3;
	
  }
 while ( v1 <256*3);
  
  return result;
}


