# Developing on Windows

## Requirements

- Visual Studio 2019 or 2022, or just the Build Tools, with the C++ x86/x64 tools and a Windows 10
  SDK.
- Build **Win32/x86** only: the libraries and the code are not ready for x64.
- The files of the original Windows release of Death Rally (see the README). `TRX.BPA` in the README
  stands for the ten tracks, `TR0.BPA` to `TR9.BPA`. `ENDANI0.HAF` is optional.

Keep the original files, saves, logs and dumps out of Git: `.gitignore` covers `runtime/`, `logs/`,
`.local/`, `*.BPA`, `*.HAF`, `*.SG*`, `*.dll` and `*.dmp`.

## Build and run

```powershell
.\scripts\Build.ps1 -Configuration Debug          # or Release
.\scripts\Check-Assets.ps1 -Source C:\DeathRally   # check the original files
.\scripts\Prepare-Runtime.ps1 -Source C:\DeathRally
.\runtime\DreeRally.exe -window
```

`Build.ps1` finds MSVC with `vswhere` and builds `DreeRally.vcxproj` with the v142 or v143 toolset,
without editing the project. `Prepare-Runtime.ps1` copies the original data and DLLs, `lang/`,
`mods/` and the executable to `runtime/`, where the game writes its configuration and saves. It
never copies saves from the original folder. Without `-Source`, both scripts read `assetSource` from
`.local/settings.json` (`{ "assetSource": "C:\\DeathRally" }`), or use `runtime/` itself.

## Diagnostics

Each run writes `logs/session-*.log` in the working folder: startup, screens, race loading, shop,
events, laps and unhandled exceptions, and in Debug the CRT reports with their stack (as offsets in
the executable).

`scripts\Start-Diagnostics.ps1` builds Debug, prepares `runtime/` and runs the game under
Sysinternals ProcDump (downloaded once to `.local/procdump`, its signature checked). Crashes and
hangs leave a dump with the executable and its symbols in `runtime/logs/diagnostic-*/`.

Environment variables to reach a situation without playing up to it:

| Variable | Effect |
| --- | --- |
| `DREERALLY_FORCE_TRACK=TR4` | Every race on that track (`TR4R` for the reversed one) |
| `DREERALLY_FORCE_EVENTS=1` | One popup per race, cycling hitman, drugs and sabotage |
| `DREERALLY_FORCE_MUSHROOM=1` | Every small power-up is a mushroom |
| `DREERALLY_FORCE_OPPONENT_LIFE=40` | Rivals start the race with that much life (%), which is stored in their record |
| `DREERALLY_FORCE_ENDING=1` | Plays the ending once after loading or creating a game; writes the Hall of Fame to `dr.cfg` |

## Checks

- `scripts\Check-Warnings.ps1` builds with `/W3` and compares the warnings with
  `scripts/warnings-baseline.txt`. It fails on any warning of a dangerous kind (missing prototype,
  uninitialised local, write past a variable, mismatched parameter types...) and on any new one.
  `-UpdateBaseline` rewrites the baseline after fixing old warnings.
- `scripts\Test-RacePalette.ps1` builds and runs `tests/race_palette_test.c` (palette and race smoke
  routines) without the game.

## The original executable as reference

The addresses in the decompiled names (`sub_424240`, `dword_4A7DFC`) are those of `dr.exe` 1.0 for
Windows, so any translation can be checked against it:

```powershell
dumpbin /nologo /disasm /range:0x424240,0x424400 dr.exe
```

`fld`/`fstp dword` on a global means a float, `fild` or `mov` an int. `.data` starts at 0x445000
(raw offset 0x45000). `tools/originalTexts.py` generates `ui/util/originalTexts.c` from the text
tables in `.data`, and `tools/ghidra/DumpKeyNames.java` generates `ui/util/keyNames.c` by emulating
the functions that build the key names.

## Pitfalls in the decompiled code

Almost every bug fixed so far was in the translation to C, not in the original game. The patterns
that came back again and again:

- **Tables split into one-byte globals.** `unk_XXXX` is a single byte; the original used it as the
  start of a table or buffer, so copies and loops (`while (p < &otherGlobal)`, `&unk_X[50 * i]`)
  write over whatever the port placed next. Rebuild the buffer with its size in the original and turn
  the loose globals into `#define` aliases into it.
- **Stack locals assumed contiguous.** Texts completed by searching the terminator from the previous
  local (`v2 = &v21; do ... while (c); *(_WORD *)v = 46`) or built over `v173..v177`. Rewrite them
  with `sprintf`/`strcat` on a buffer of the original size.
- **Floats declared `int`.** Impulse, slip, grip and interpolation fields truncated to zero, or read
  elsewhere with `*(float *)&`. `LODWORD(floatField)` copies the bits.
- **Missing prototypes.** `ceil`, `sqrt` and functions taking floats: MSVC assumes `int`, reads the
  result from `eax` and shifts the following arguments.
- **Lost FPU flags.** `char c0, c2` set to 0 "for now" are comparisons or a `fabs`.
- **Byte offsets used as indexes** (`drivers[27 * id]` for `id * 0x6C`), loops over participants
  from `N` to `1`, leftover `/4` or `216 *` strides.
- **Signedness.** `BYTE` is a signed `char` in `defs.h` unless `windows.h` is included; `_DWORD`
  shifts are unsigned where the original uses `sar`; `eventDetected` returns a signed `char`.
- **Commented-out calls and frees.** Check in the original whether it calls or frees there. Restoring
  a `free` often uncovers an old overrun that the CRT only detects when freeing.
- **`p = malloc(n)` followed by `p = something`**: the first block leaks.
- **Hand-copied tables** (animation frame sizes, font spacing) with one wrong value, and upstream
  workarounds that compensated another bug (`*0.62`, `>>5`, `- 24`): once the cause is fixed the
  workaround becomes the bug.
- **Release finds more.** With optimisation and `/GS`, buffers smaller than in the original and loops
  over 20 drivers where the original does 19 crash; test there before calling something fixed.

## Known issues

- Multiplayer still has the same patterns (`previewRaceScreen`, the news scrolling) and is untested.
- `dr.cfg`: `fread`/`fwrite` of 4 bytes over `word_462D54` (2 bytes) overwrites two configuration
  bytes just read.
- `sub_404C30` and `sub_4055A0` (a palette fade the original calls from the race) are not called;
  their 3 KB float table at 0x4B3400 still has to be rebuilt.
- About 0.3 MB per race is still not freed (4096-byte blocks reserved while loading), and three frees
  of menu graphics remain commented out.
- The menu palette flicker (`sub_4220D0`) runs its loop once; the original walks `palette2` up to
  0x461424.
- The per-participant key buffer `dword_4A7D20` is `char[16]` but written as dwords; it is 64 bytes
  in the original.
- `BYTE` in `defs.h` should become unsigned everywhere; 3D scenery polygon types are read as `char`
  (cases 0x80–0x8A never run).

These match the original and were left as they are: an AI car facing a wall keeps accelerating
until another car pushes it; the joystick is opened once at startup and only buttons 0 to 3 are
read; the sponsor win streak is not stored in the savegame.
