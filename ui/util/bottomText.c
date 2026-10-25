#include "bottomText.h"

#include "../../graphics.h"
#include "../../imageUtil.h"
#include "../../dr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----- (0041E810) --------------------------------------------------------
//Las ultimas seis lineas de las noticias (16 a 21), cada una con el color de su bandera. Upstream
//las habia reemplazado por tres lineas fijas de bienvenida; esos creditos ahora entran como
//noticias al abrir el menu principal (initMenuNews).
char drawBottomMenuText()
{
  int line;
  int offset;
  char flag;

  for ( offset = 243200; offset < 300160; offset += 640 )
    memcpy((char *)screenBuffer + offset, (char *)graphicsGeneral.menubg5Bpk + offset, 0x280u);
  flag = 0;
  for ( line = 16, offset = 241932; line < MENU_NEWS_LINES; ++line, offset += 9600 )
  {
    flag = unk_461EC0[line];
    if ( !flag )
      drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, MENU_NEWS_LINE(line), offset);
    if ( flag == 1 )
      drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, MENU_NEWS_LINE(line), offset);
    if ( flag == 2 )
      drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, MENU_NEWS_LINE(line), offset);
  }
  return flag;
}

//Sube las noticias una linea, con la bandera de color de cada una (0x461EC0, una por linea). Los
//corrimientos del decompilado perdian las banderas 4, 8, 12, 16 y 20.
void scrollMenuNews()
{
  memmove(unk_461EC0, unk_461EC0 + 1, MENU_NEWS_LINES - 1);
  memmove(MENU_NEWS_LINE(0), MENU_NEWS_LINE(1), (MENU_NEWS_LINES - 1) * MENU_NEWS_LINE_SIZE);
  // Mas alla del original: la ultima linea quedaba con su texto y se repetia arriba y abajo de
  // cada noticia nueva (la version DOS las muestra con renglones vacios alrededor).
  memset(MENU_NEWS_LINE(MENU_NEWS_LINES - 1), 0, MENU_NEWS_LINE_SIZE);
  unk_461EC0[MENU_NEWS_LINES - 1] = 0;
}

//Agrega una noticia abajo de todo (linea 21) con su color: 0 normal, 1 resaltada, 2 tercer color.
void addMenuNews(const char *text, char colour)
{
  scrollMenuNews();
  strncpy(MENU_NEWS_LINE(MENU_NEWS_LINES - 1), text, MENU_NEWS_LINE_SIZE - 1);
  MENU_NEWS_LINE(MENU_NEWS_LINES - 1)[MENU_NEWS_LINE_SIZE - 1] = 0;
  unk_461EC0[MENU_NEWS_LINES - 1] = colour;
}

//0x43A298: al abrir el menu principal el original borra las noticias y pone su bienvenida. Se
//agrega el credito de DreeRally, el port en el que se basa este.
void initMenuNews()
{
  memset(unk_461EC0, 0, MENU_NEWS_LINES);
  memset(MENU_NEWS_LINE(0), 0, MENU_NEWS_LINES * MENU_NEWS_LINE_SIZE);
  addMenuNews("     Welcome to Death Rally(tm) - Windows Version 1.0", 1);
  addMenuNews("         Port by Jari Komppa - http://iki.fi/sol/", 1);
  addMenuNews("    (c)Remedy Entertainment - http://www.remedygames.com", 1);
  addMenuNews("  DreeRally by Enrique Somolinos - github.com/enriquesomolinos", 1);
  addMenuNews("", 1);
  addMenuNews("Use arrow keys to change selection and press enter to confirm.", 1);
}
// 4458B0: using guessed type char letterSpacing_4458B0;
// 461ED0: using guessed type __int16 word_461ED0;