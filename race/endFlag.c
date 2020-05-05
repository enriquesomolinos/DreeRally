#include "endFlag.h"
#include "../dr.h"

int endRaceFlagFrame_481BE0; // weak
int raceFlagWidth_4B3140; // weak

//----- (00402490) --------------------------------------------------------
unsigned int showEndRaceFlag_402490()
{
    int v0; // eax@1
    unsigned int result; // eax@1

    raceFlagWidth_4B3140 = raceFlagWidth_4B3140 - dword_4A9EA4 <= 0 ? 0 : raceFlagWidth_4B3140 - dword_4A9EA4;
    drawInRaceImageToBuffer_43B160(
        (int)((char*)genflaBpk + 4800 * ((endRaceFlagFrame_481BE0 + 0x8000) >> 16)),
        80,
        60,
        dword_464F14 + raceFlagWidth_4B3140 + 336);
    v0 = dword_4AA500 + endRaceFlagFrame_481BE0;
    endRaceFlagFrame_481BE0 = v0;
    result = (v0 + 0x8000) & 0xFFFF0000;
    if ((signed int)result > 4128768)
        endRaceFlagFrame_481BE0 = 0;
    return result;
}