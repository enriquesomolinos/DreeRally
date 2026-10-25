

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "input.h"
#include "../../variables.h"
#include "../../defs.h"
#include "../../config.h"
#include "../../imageUtil.h"
#include "../../drivers.h"
#include "../../graphics.h"
#include "menus.h"
#include "../../dr.h"
#include "../../diagnostics.h"


char byte_45EEE0[256]; // weak
char byte_45EEE2; // weak
char byte_45EEE3; // weak
char byte_45EEE4; // weak
char byte_45EEE5; // weak
char byte_45EEE6; // weak
char byte_45EEE7; // weak
char byte_45EEE8; // weak
char byte_45EEE9; // weak
char byte_45EEEA; // weak
char byte_45EEEB; // weak
char byte_45EEEC; // weak
char byte_45EEED; // weak
char byte_45EEF0; // weak
char byte_45EEF1; // weak
char byte_45EEF2; // weak
char byte_45EEF3; // weak
char byte_45EEF4; // weak
char byte_45EEF5; // weak
char byte_45EEF6; // weak
char byte_45EEF7; // weak
char byte_45EEF8; // weak
char byte_45EEF9; // weak
char byte_45EEFE; // weak
char byte_45EEFF; // weak
char byte_45EF00; // weak
char byte_45EF01; // weak
char byte_45EF02; // weak
char byte_45EF03; // weak
char byte_45EF04; // weak
char byte_45EF05; // weak
char byte_45EF06; // weak
char byte_45EF0C; // weak
char byte_45EF0D; // weak
char byte_45EF0E; // weak
char byte_45EF0F; // weak
char byte_45EF10; // weak
char byte_45EF11; // weak
char byte_45EF12; // weak
char byte_45EF13; // weak
char byte_45EF14; // weak
char byte_45EF15; // weak
char byte_45EF19; // weak

//----- (0042E7F0) --------------------------------------------------------
signed int   readKeyboard(char *a1, int a2, int a3, int a4, unsigned int a5, signed int a6, int ingame, int a8, int a9)
{
  char *v9; // eax@1
  signed int v10; // ebp@1
  unsigned int v11; // edx@1
  char v12; // cl@2
  int v13; // edi@5
  int face; // esi@6
  char v15; // al@6
  int v16; // ebx@6
  signed int v17; // esi@14
  signed int v18; // esi@16
  signed int v19; // esi@23
  signed int v20; // esi@25
  int v21; // ecx@29
  double v22; // st7@31
  signed int v23; // eax@31
  float v24; // ST2C_4@31
  double v25; // st7@31
  float v26; // ST28_4@31
  float v27; // ST24_4@31
  signed int v28; // edx@31
  char *v29; // edi@32
  int v30; // esi@33
  int v31; // ecx@35
  double v32; // st7@37
  signed int v33; // eax@37
  float v34; // ST2C_4@37
  double v35; // st7@37
  float v36; // ST28_4@37
  float v37; // ST24_4@37
  signed int v38; // edx@37
  char *v39; // edi@38
  int v40; // esi@39
  char *v42; // eax@42
  char v43; // cl@43
  int v44; // ecx@47
  int v45; // eax@47
  char v49; // dl@54
  char v62; // [sp+1Dh] [bp-5Bh]@1
  int initialFace; // [sp+20h] [bp-58h]@5
  int v64; // [sp+24h] [bp-54h]@5
  int v65; // [sp+28h] [bp-50h]@5
  int v66; // [sp+2Ch] [bp-4Ch]@5
  int v67; // [sp+30h] [bp-48h]@1
  int v68; // [sp+34h] [bp-44h]@31
  int v69; // [sp+38h] [bp-40h]@1
  int v70; // [sp+3Ch] [bp-3Ch]@5
  int v71; // [sp+40h] [bp-38h]@3
  char v72[100]; // [sp+44h] [bp-34h]@1
  size_t length;
  int glyphWidth;
  int row;
  char glyph[2] = { 0, 0 };
  unsigned int limit = a5 < sizeof(v72) - 1 ? a5 : sizeof(v72) - 1;
   int  a = 0;
  //aqui se definen las teclas validas
  memset(byte_45EEE0, 0, 0x100u);
  memset(v72, 0, sizeof(v72));
  v62 = 0;
  
  byte_45EEE0[2] = 49;// byte_45EEE2 = 49;
  byte_45EEE0[3] = 50; //byte_45EEE3 = 50;
  byte_45EEE0[4] = 51; //byte_45EEE4 = 51;
  byte_45EEE0[5] = 52; //byte_45EEE5 = 52;
  byte_45EEE0[6] = 53; //byte_45EEE6 = 53;
  byte_45EEE0[7] = 54;// byte_45EEE7 = 54;
  byte_45EEE0[8] = 55; //byte_45EEE8 = 55;
  byte_45EEE0[9] = 56; //byte_45EEE9 = 56;
  byte_45EEE0[10] = 57; //byte_45EEEA = 57;
  byte_45EEE0[11] = 48; //byte_45EEEB = 48;
  byte_45EEE0[12] = 45; //byte_45EEEC = 45;
  byte_45EEE0[13] = 61;// byte_45EEED = 61;

  byte_45EEE0[16] = 81; //byte_45EEF0 = 81;
  byte_45EEE0[17] = 87;// byte_45EEF1 = 87;
  byte_45EEE0[18] = 69; // byte_45EEF2 = 69;
  byte_45EEE0[19] = 82; //byte_45EEF3 = 82;
  byte_45EEE0[20] = 84;// byte_45EEF4 = 84;
  byte_45EEE0[21] = 89;// byte_45EEF5 = 89;
  byte_45EEE0[22] = 85;// byte_45EEF6 = 85;
  byte_45EEE0[23] = 73; //byte_45EEF7 = 73;
  byte_45EEE0[24] = 79;//byte_45EEF8 = 79;
  byte_45EEE0[25] = 80;//byte_45EEF9 = 80;
  byte_45EEE0[30] = 65;// byte_45EEFE = 65;
  byte_45EEE0[31] = 83;// byte_45EEFF = 83;
  
  byte_45EEE0[32] = 68; //byte_45EF00 = 68;
  byte_45EEE0[33] = 70;// byte_45EF01 = 70;
  byte_45EEE0[34] = 71; //byte_45EF02 = 71;
  byte_45EEE0[35] = 72;// byte_45EF03 = 72;
  byte_45EEE0[36] = 74; //byte_45EF04 = 74;
  byte_45EEE0[37] = 75; // byte_45EF05
  byte_45EEE0[38] = 76; //byte_45EF06

  byte_45EEE0[44] = 90; //byte_45EF0C = 90;
  byte_45EEE0[45] = 88; //byte_45EF0D = 88;
  byte_45EEE0[46] = 67; //byte_45EF0E = 67;
  byte_45EEE0[47] = 86;// byte_45EF0F = 86;

  byte_45EEE0[48] = 66; //byte_45EF10 = 66;

  byte_45EEE0[49] = 78;//byte_45EF11 = 78;
  byte_45EEE0[50] = 77;//byte_45EF12 = 77;
  byte_45EEE0[51] = 44;// byte_45EF13 = 44;
  byte_45EEE0[52] = 46; //byte_45EF14 = 46;
  byte_45EEE0[53] = 47; //byte_45EF15 = 47;
  byte_45EEE0[57] = 32; //byte_45EF19 = 32;
  
  
  strncpy(v72, a1, limit);
  diagnosticLog("input begin: maxChars=%u initialLength=%u license=%d", limit, (unsigned int)strlen(v72), a9);
  v67 = 640 * a3;
  v69 = 640 * a3 + a2;
  drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, v72, v69);
  v9 = v72;
  v10 = 0;
  v11 = 0;
  do
    v12 = *v9++;
  while ( v12 );
  v71 = v9 - &v72[1];
  if ( v9 != &v72[1] )
  {
    do
	
      v10 += (unsigned __int8)bigLetterSpacing_445848[(unsigned __int8)v72[v11++] - 30];
	  //v10 += (unsigned __int8)menuActive_4457F0[58 + (unsigned __int8)v72[v11++]];
    while ( v11 < strlen(v72) );
  }
  drawKeyCursor(640 * a3 + a2, (char *)screenBuffer + 640 * a3 + a2, v10, 32);
  v13 = a9;
  v70 = 0;
  initialFace = 0;
  v64 = 128;
  v66 = 160950;
  v65 = 384;
 
  while ( 2 )
  {

	  a++;
	 face = initialFace;

	  v68 = *((BYTE *)graphicsGeneral.copperPal + v65 + 2);
    v22 = (double)v68;
    v23 = *((BYTE *)graphicsGeneral.copperPal + v65);
    v68 = *((BYTE *)graphicsGeneral.copperPal + v65 + 1);
    v24 = v22;
    v25 = (double)v68;
    v68 = v23;
    v26 = v25;
    v27 = (double)v23;
    setPaletteValueWithFloats(v27, v26, v24);
       

    sub_42C7F0(a2, a3, v10, v13, 63, 112);
    v15 = eventDetected();
    v16 = (unsigned __int8)v15;
    v71 = (unsigned __int8)v15;
    switch ( (unsigned __int8)v15 )
    {
      case KEY_F1:
        //if ( ingame && isMultiplayerGame )
        //  multiplayer_sub_42CCF0();
        goto LABEL_66;
      case KEY_UP:
      case 0xC8:
        if ( v13 )
        {
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
          if (face <= 0 )
			  initialFace = 19;
          else
			  initialFace = face - 1;
          drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + initialFace), 64, 64, (int)((char *)screenBuffer + 122330));
          drawKeyCursor(122330, (char *)screenBuffer + 122330, 0x40u, 64);
          v17 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v17;
          }
          while ( v17 );
          drawImageWithPosition2((int)((char *)graphics2.facearr1Bpk + 2176), 68, 16, (int)((char *)screenBuffer + 110168));
          drawKeyCursor(110168, (char *)screenBuffer + 110168, 0x44u, 16);
          v18 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v18;
          }
          while ( v18 );
          drawImageWithPosition2((int)graphics2.facearr1Bpk, 68, 16, (int)((char *)screenBuffer + 110168));
          drawKeyCursor(110168, (char *)screenBuffer + 110168, 0x44u, 16);
          drivers[driverId].face = initialFace;
          v16 = 0;
        }
        goto LABEL_66;
      case KEY_DOWN:
      case 0xD0:
        if ( v13 )
        {
          loadMenuSoundEffect(1u, 25, 0, configuration.effectsVolume, dword_445194);
          if (face >= 19 )
			  initialFace = 0;
          else
			  initialFace = face + 1;
          drawImageWithPosition2((int)*(&graphicsGeneral.face01Bpk + initialFace), 64, 64, (int)((char *)screenBuffer + 122330));
          drawKeyCursor(122330, (char *)screenBuffer + 122330, 0x40u, 64);
          v19 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v19;
          }
          while ( v19 );
          drawImageWithPosition2((int)((char *)graphics2.facearr1Bpk + 3264), 68, 16, (int)((char *)screenBuffer + 165208));
          drawKeyCursor(165208, (char *)screenBuffer + 165208, 0x44u, 16);
          v20 = 5;
          do
          {
            sub_42C7F0(a2, a3, v10, v13, 63, 112);
            --v20;
          }
          while ( v20 );
          drawImageWithPosition2((int)((char *)graphics2.facearr1Bpk + 1088), 68, 16, (int)((char *)screenBuffer + 165208));
          drawKeyCursor(165208, (char *)screenBuffer + 165208, 0x44u, 16);
		  drivers[driverId].face = initialFace;
          v16 = 0;
        }
        goto LABEL_66;
      case KEY_LEFT:
      case 0xCB:
        if ( !v13 )
          goto LABEL_66;
        v21 = v65;
        if ( v64 > 0 )
        {
          v21 = v65 - 6;
          v64 -= 2;
          v65 -= 6;
          v66 -= 2;
        }
        v68 = *((BYTE *)graphicsGeneral.copperPal + v21 + 2);
        v22 = (double)v68;
        v23 = *((BYTE *)graphicsGeneral.copperPal + v21);
        v68 = *((BYTE *)graphicsGeneral.copperPal + v21 + 1);
        v24 = v22;
        v25 = (double)v68;
        v68 = v23;
        v26 = v25;
        v27 = (double)v23;
        setPaletteValueWithFloats(v27, v26, v24);
        v28 = 71680;
        do
        {
          v29 = (char *)screenBuffer + v28 + 89124;
          memset(v29, 0xC4u, 0x124u);
          v28 += 640;
          *((_WORD *)v29 + 146) = -15164;
        }
        while ( v28 < 87040 );
        drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 163370));
        v30 = v64;
        drawImageWithPosition((int)slidcur3Bpk, 10, 24, (int)((char *)screenBuffer + v64 + 160824));
        drawKeyCursor(v66, (char *)screenBuffer + v30 + 160822, 0xEu, 24);
        v16 = 0;
        goto LABEL_65;
      case KEY_RIGHT:
      case 0xCD:
        if ( !v13 )
          goto LABEL_66;
        v31 = v65;
        if ( v64 < 253 )
        {
          v31 = v65 + 6;
          v64 += 2;
          v65 += 6;
          v66 += 2;
        }
        v68 = *((BYTE *)graphicsGeneral.copperPal + v31 + 2);
        v32 = (double)v68;
        v33 = *((BYTE *)graphicsGeneral.copperPal + v31);
        v68 = *((BYTE *)graphicsGeneral.copperPal + v31 + 1);
        v34 = v32;
        v35 = (double)v68;
        v68 = v33;
        v36 = v35;
        v37 = (double)v33;
        setPaletteValueWithFloats(v37, v36, v34);
        v38 = 71680;
        do
        {
          v39 = (char *)screenBuffer + v38 + 89124;
          memset(v39, 0xC4u, 0x124u);
          v38 += 640;
          *((_WORD *)v39 + 146) = -15164;
        }
        while ( v38 < 87040 );
        drawImageWithPosition((int)slidcop2Bpk, 294, 16, (int)((char *)screenBuffer + 163370));
        v40 = v64;
        drawImageWithPosition((int)slidcur3Bpk, 10, 24, (int)((char *)screenBuffer + v64 + 160824));
        drawKeyCursor(v66, (char *)screenBuffer + v40 + 160822, 0xEu, 24);
        v16 = 0;
        goto LABEL_65;
      case KEY_ESCAPE:
        if ( !a8 )
          goto LABEL_66;
        diagnosticLog("input cancelled: length=%u", (unsigned int)strlen(v72));
        return 0;
      case KEY_ENTER:
      case 0x9C:
        v42 = v72;
        do
          v43 = *v42++;
        while ( v43 );
        v71 = v42 - &v72[1];
        if ( v42 != &v72[1] )
          v70 = -1;
        if ( v13 )
        {
          v44 = v64;
          v45 = driverId;
		  drivers[driverId].face = face;
		  drivers[driverId].colour = v44;
		  //dword_460880[v45] = face;
          //dword_46086C[v45] = v44;
		  v70 = strlen(v72);
        }
        goto LABEL_66;
      case 0xE: // Backspace
        length = strlen(v72);
        if (length == 0)
          goto LABEL_66;
        glyphWidth = (unsigned char)bigLetterSpacing_445848[(unsigned char)v72[length - 1] - 30];
        v72[length - 1] = '\0';
        v10 -= glyphWidth;
        // Erase the removed glyph and the old cursor, including the last letter.
        for (row = 0; row < 32; ++row)
          memset((char *)screenBuffer + v69 + row * 640 + v10, 0xC4, glyphWidth + 32);
        drawKeyCursor(v69 + v10, (char *)screenBuffer + v69 + v10, glyphWidth + 32, 32);
        goto LABEL_65;
      default:
        v49 = byte_45EEE0[(unsigned char)v15];
        length = strlen(v72);
        if (v49 && *((unsigned char *)a4 + (unsigned char)v49) == 1 && length < limit)
        {
          glyph[0] = (v49 >= 'A' && v49 <= 'Z') ? v49 + ('a' - 'A') : v49;
          // The font header occupies two bytes; glyph widths start at ASCII 32.
          glyphWidth = (unsigned char)bigLetterSpacing_445848[(unsigned char)glyph[0] - 30];
          if (v10 + glyphWidth > a6)
            goto LABEL_66;
          for (row = 0; row < 32; ++row)
            memset((char *)screenBuffer + v69 + row * 640 + v10, 0xC4, 32);
          drawTextWithFont((int)graphics2.fbig3bBpk, (int)&bigLetterSpacing_445848, glyph, v69 + v10);
          drawKeyCursor(v69 + v10, (char *)screenBuffer + v69 + v10, 32, 32);
          v72[length] = glyph[0];
          v72[length + 1] = '\0';
          v10 += glyphWidth;
LABEL_65:
          v13 = a9;
        }
	LABEL_66:
		//TODO arreglar esto pongo el nombre a fuego
		/*v70 = 4;
		v72[0] = "k";
		v72[1] = "i";
		v72[2] = "k";
		v72[3] = "e";
		v72[4] = 0;*/
        if ( !v70 )
          continue;
        if ( v16 != 1 )
          strcpy(a1, v72);
        
        diagnosticLog("input accepted: length=%u", (unsigned int)strlen(v72));
        return 1;
    }
  }
}
