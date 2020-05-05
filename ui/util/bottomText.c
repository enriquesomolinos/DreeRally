#include "bottomText.h"

#include "../graphics.h"
#include "../imageUtil.h"
#include "../dr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----- (0041E810) --------------------------------------------------------
char drawBottomMenuText()
{
    //  signed int v0; // eax@1
    //  char *v1; // esi@2
    //  char *v2; // edi@2
    //  int v3; // ebp@3
    //  const char *v4; // edi@3
    //  int v5; // esi@3
    ///  char result; // al@4



    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "         Welcome to DreeRally - Windows Version 0.2", 640 * 395);
    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "           Follow us on https://www.dreerally.com", 640 * 410);
    //drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "    See more developments at https://github.com/enriquesomolinos", 640 * 425);
    //drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "       (c)Remedy Entertainment - http://www.remedygames.com", 640 * 425);
    drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, "  Use arrow keys to change selection and press enter to confirm.", 640 * 425);

    /*

    v0 = 243200;
    do
    {
      v1 = (char *)graphicsGeneral.menubg5Bpk + v0;
      v2 = (char *)screenBuffer + v0;
      v0 += 640;
      memcpy(v2, v1, 0x280u);
    }
    while ( v0 < 300160 );
    v3 = 0;
    v4 = (const char *)&unk_462960;
    v5 = 241932;
    do
    {
      result = *((BYTE *)&word_461ED0 + v3);
      if ( !result )
        result = drawTextWithFont((int)graphicsGeneral.fsma3aBpk, (int)&letterSpacing_4458B0, v4, v5);
      if ( *((BYTE *)&word_461ED0 + v3) == 1 )
        result = drawTextWithFont((int)graphicsGeneral.fsma3bBpk, (int)&letterSpacing_4458B0, v4, v5);
      if ( *((BYTE *)&word_461ED0 + v3) == 2 )
        result = drawTextWithFont((int)graphicsGeneral.fsma3cBpk, (int)&letterSpacing_4458B0, v4, v5);
      v5 += 9600;
      ++v3;
      v4 += 150;
    }
    while ( v5 < 299532 );
    return result;*/
    return 0;
}
// 4458B0: using guessed type char letterSpacing_4458B0;
// 461ED0: using guessed type __int16 word_461ED0;