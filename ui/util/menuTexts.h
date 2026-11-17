#ifndef MENU_TEXTS_H
#define MENU_TEXTS_H

//Opciones de los menus del original: 9 menus de 9 opciones de 50 bytes desde 0x446368. Aqui solo
//los menus 5 a 8 (cargar partida, teclado, modem y joystick), que el juego reescribe: las
//ranuras de guardado y "Accelerate    a" (etiqueta, relleno y tecla). El decompilado los partio
//en globales sueltas; los memcpy de 24 a 32 bytes sobre las de un byte pisaban otras globales
//(los precios del mercado negro). Contenido inicial: tools/originalTexts.py.
#define MENU_TEXT_FIRST_MENU 5
#define MENU_TEXT_ENTRIES 9
#define MENU_TEXT_SIZE 50
extern char menuTexts_446C32[4][MENU_TEXT_ENTRIES][MENU_TEXT_SIZE];
#define MENU_TEXT(menu, entry) (menuTexts_446C32[(menu) - MENU_TEXT_FIRST_MENU][entry])
#define MENU_BYTE(address) (((char *)menuTexts_446C32)[(address) - 0x446C32])

#define unk_446C32   MENU_BYTE(0x446C32)                //menu 5, opcion 0, byte 0
#define dword_446DF4 (*(int *)&MENU_BYTE(0x446DF4))     //menu 6, opcion 0, byte 0
#define dword_446DF8 (*(int *)&MENU_BYTE(0x446DF8))     //menu 6, opcion 0, byte 4
#define dword_446DFC (*(int *)&MENU_BYTE(0x446DFC))     //menu 6, opcion 0, byte 8
#define word_446E00  (*(__int16 *)&MENU_BYTE(0x446E00)) //menu 6, opcion 0, byte 12
#define byte_446E02  MENU_BYTE(0x446E02)                //menu 6, opcion 0, byte 14
#define dword_446E26 (*(int *)&MENU_BYTE(0x446E26))     //menu 6, opcion 1, byte 0
#define dword_446E2A (*(int *)&MENU_BYTE(0x446E2A))     //menu 6, opcion 1, byte 4
#define dword_446E2E (*(int *)&MENU_BYTE(0x446E2E))     //menu 6, opcion 1, byte 8
#define word_446E32  (*(__int16 *)&MENU_BYTE(0x446E32)) //menu 6, opcion 1, byte 12
#define dword_446E58 (*(int *)&MENU_BYTE(0x446E58))     //menu 6, opcion 2, byte 0
#define dword_446E5C (*(int *)&MENU_BYTE(0x446E5C))     //menu 6, opcion 2, byte 4
#define dword_446E60 (*(int *)&MENU_BYTE(0x446E60))     //menu 6, opcion 2, byte 8
#define dword_446E64 (*(int *)&MENU_BYTE(0x446E64))     //menu 6, opcion 2, byte 12
#define byte_446E68  MENU_BYTE(0x446E68)                //menu 6, opcion 2, byte 16
#define dword_446E8A (*(int *)&MENU_BYTE(0x446E8A))     //menu 6, opcion 3, byte 0
#define dword_446E8E (*(int *)&MENU_BYTE(0x446E8E))     //menu 6, opcion 3, byte 4
#define dword_446E92 (*(int *)&MENU_BYTE(0x446E92))     //menu 6, opcion 3, byte 8
#define dword_446E96 (*(int *)&MENU_BYTE(0x446E96))     //menu 6, opcion 3, byte 12
#define dword_446E9A (*(int *)&MENU_BYTE(0x446E9A))     //menu 6, opcion 3, byte 16
#define byte_446E9E  MENU_BYTE(0x446E9E)                //menu 6, opcion 3, byte 20
#define unk_446EBC   MENU_BYTE(0x446EBC)                //menu 6, opcion 4, byte 0
#define unk_446EEE   MENU_BYTE(0x446EEE)                //menu 6, opcion 5, byte 0
#define byte_446F20  ((BYTE *)&MENU_BYTE(0x446F20))     //menu 6, opcion 6, byte 0
#define unk_446F52   MENU_BYTE(0x446F52)                //menu 6, opcion 7, byte 0
#define dword_4470E2 (*(int *)&MENU_BYTE(0x4470E2))     //menu 7, opcion 6, byte 0
#define dword_4470E6 (*(int *)&MENU_BYTE(0x4470E6))     //menu 7, opcion 6, byte 4
#define dword_4470EA (*(int *)&MENU_BYTE(0x4470EA))     //menu 7, opcion 6, byte 8
#define word_4470EE  (*(__int16 *)&MENU_BYTE(0x4470EE)) //menu 7, opcion 6, byte 12
#define dword_447178 (*(int *)&MENU_BYTE(0x447178))     //menu 8, opcion 0, byte 0
#define dword_44717C (*(int *)&MENU_BYTE(0x44717C))     //menu 8, opcion 0, byte 4
#define dword_447180 (*(int *)&MENU_BYTE(0x447180))     //menu 8, opcion 0, byte 8
#define word_447184  (*(__int16 *)&MENU_BYTE(0x447184)) //menu 8, opcion 0, byte 12
#define byte_447186  MENU_BYTE(0x447186)                //menu 8, opcion 0, byte 14
#define dword_4471AA (*(int *)&MENU_BYTE(0x4471AA))     //menu 8, opcion 1, byte 0
#define dword_4471AE (*(int *)&MENU_BYTE(0x4471AE))     //menu 8, opcion 1, byte 4
#define dword_4471B2 (*(int *)&MENU_BYTE(0x4471B2))     //menu 8, opcion 1, byte 8
#define word_4471B6  (*(__int16 *)&MENU_BYTE(0x4471B6)) //menu 8, opcion 1, byte 12
#define dword_4471DC (*(int *)&MENU_BYTE(0x4471DC))     //menu 8, opcion 2, byte 0
#define dword_4471E0 (*(int *)&MENU_BYTE(0x4471E0))     //menu 8, opcion 2, byte 4
#define dword_4471E4 (*(int *)&MENU_BYTE(0x4471E4))     //menu 8, opcion 2, byte 8
#define dword_4471E8 (*(int *)&MENU_BYTE(0x4471E8))     //menu 8, opcion 2, byte 12
#define byte_4471EC  MENU_BYTE(0x4471EC)                //menu 8, opcion 2, byte 16
#define dword_44720E (*(int *)&MENU_BYTE(0x44720E))     //menu 8, opcion 3, byte 0
#define dword_447212 (*(int *)&MENU_BYTE(0x447212))     //menu 8, opcion 3, byte 4
#define dword_447216 (*(int *)&MENU_BYTE(0x447216))     //menu 8, opcion 3, byte 8
#define dword_44721A (*(int *)&MENU_BYTE(0x44721A))     //menu 8, opcion 3, byte 12
#define dword_44721E (*(int *)&MENU_BYTE(0x44721E))     //menu 8, opcion 3, byte 16
#define byte_447222  MENU_BYTE(0x447222)                //menu 8, opcion 3, byte 20
#define unk_447240   MENU_BYTE(0x447240)                //menu 8, opcion 4, byte 0
#define unk_447272   MENU_BYTE(0x447272)                //menu 8, opcion 5, byte 0
#define byte_4472A4  ((BYTE *)&MENU_BYTE(0x4472A4))     //menu 8, opcion 6, byte 0

#endif
