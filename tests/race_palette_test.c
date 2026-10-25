#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../raceParticipant.h"

RaceParticipantIngame raceParticipantIngame[4];
static int currentDriverSelectedIndex_503518;
static int leftMenuInRaceWidth_456AA0, circuitImageOffsetX_456ABC, circuitImageOffsetY_456AC0;
static int dword_4A9EA4 = 1;
static int dword_464F14;
static unsigned char framebuffer[512 * 200];
static unsigned char smokePixels[192];
static void *smokeBpk = smokePixels;

/* Guard the actual palette routines against the overflow found in the dump. */
static struct { unsigned char colors[768]; unsigned char guard[3]; } source;
static struct { int colors[768]; int guard[3]; } processed;
#define circuitPalette_4B4020 source.colors
#define circuitPaletteProcesed_50EF40 processed.colors
static int maxPaletteEntries = 768;
static int dword_456AF8;
static int calls, firstRed;
static int colorToPaletteEntry(int value, int divisor) { return (int)(((long long)value << 16) / divisor); }
static int convertColorToPaletteColor(int value, int factor) { return (int)(((long long)value * factor) >> 16); }
static int setPaletteAndGetValue(unsigned char index, unsigned char r, char g, unsigned char b)
{
    ++calls;
    if (index == 0) firstRed = r;
    return 0;
}
static void regenerateRacePalette(unsigned char *palette) { }
static void waitWithRefresh(void) { }
static void setMusicVolume(unsigned long long volume) { }

/* Generated from dr.c by Test-RacePalette.ps1; no duplicated implementation. */
#include "race-palette-functions.inc"

static int check(int (*fn)(), int expectedCalls, const char *name)
{
    int i;
    calls = 0;
    firstRed = -1;
    dword_456AF8 = 0;
    for (i = 0; i < 3; ++i) processed.guard[i] = 0x12345678;
    fn();
    for (i = 0; i < 3; ++i) {
        if (processed.guard[i] != 0x12345678) {
            printf("FAIL %s: wrote past the 768 palette components\n", name);
            return 1;
        }
    }
    if (calls != expectedCalls) {
        printf("FAIL %s: %d palette writes, expected %d\n", name, calls, expectedCalls);
        return 1;
    }
    printf("PASS %s\n", name);
    return 0;
}

int main(void)
{
    int failures = 0;
    int driver, pixel;
    memset(source.colors, 32, sizeof(source.colors));
    memset(source.guard, 63, sizeof(source.guard));
    failures += check(setCircuitPalette_4B4020, 256, "race palette initialization");
    failures += check(setCircuitPaletteBis_4B4020, 0, "race palette recalculation");
    failures += check(setCircuitPaletteTransitionToBlack_4B4020, 256, "fade to black");
    failures += check(setCircuitPaletteTransitionToOriginal_4B4020, 256, "fade from black");
    failures += check(drawToBlackScreen, 41 * 256, "pre-race fade");
    dword_464F14 = (int)framebuffer;
    memset(smokePixels, 7, sizeof(smokePixels));
    for (driver = 0; driver < 4; ++driver) {
        RaceParticipantIngame *participant = &raceParticipantIngame[driver];
        memset(raceParticipantIngame, 0, sizeof(raceParticipantIngame));
        memset(framebuffer, 0, sizeof(framebuffer));
        currentDriverSelectedIndex_503518 = driver;
        participant->dword_4A7EE4[0] = 1;
        participant->dword_4A7F5C[0] = 4;
        participant->dword_4A7FD4[0] = 4;
        participant->dword_4A7F20[14] = 12;
        participant->dword_4A7F98[14] = 315;
        participant->dword_4A8010[14] = 195;
        showSmoke_40F070(0);
        assert(participant->dword_4A7EE4[0] == 2);
        assert(participant->dword_4A7F20[14] == 0);
        for (pixel = 0; pixel < sizeof(framebuffer); ++pixel) {
            int row = pixel / 512, col = pixel % 512;
            int painted = (row < 8 && col >= 96 && col < 104) ||
                (row >= 191 && row < 199 && col >= 407 && col < 415);
            assert(framebuffer[pixel] == (painted ? 7 : 0));
        }
        // Offscreen particles and expired frames must never index the sprite.
        memset(framebuffer, 0, sizeof(framebuffer));
        participant->dword_4A7F5C[0] = -1;
        participant->dword_4A7F20[14] = 100;
        showSmoke_40F070(0);
        for (pixel = 0; pixel < sizeof(framebuffer); ++pixel) assert(framebuffer[pixel] == 0);
        assert(participant->dword_4A7F20[14] == 0);
    }
    puts("PASS smoke: all four drivers, both sides, clipping and expiration");
    return failures ? 1 : 0;
}
