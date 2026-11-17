# DreeRally Changelog

### Unreleased (0.3.x): a full campaign on Windows

A complete campaign can now be played on Windows, in Debug and in Release, from a new game to
beating the Adversary, without crashes or memory growth. Nearly every fix corrects the translation
of the decompiled code, cross-checked against the original `dr.exe` 1.0 for Windows (addresses are
quoted in the commits and comments); see the pitfalls in [DEVELOPMENT.md](DEVELOPMENT.md).

Race
- Car-to-car collision is enabled again, with the lost FPU flags, the float impulse, rotation and
  previous position, and the collision damage.
- Handling follows the original tables: armour per car, tire grip and lateral slip as floats,
  skidding, skid marks and sound on both sides, the spikes sensor.
- AI: engine balance, stuck-car recovery and gun aiming.
- Power-ups: spawning, the mushroom timer and view; big power-ups no longer vanish and drugs on
  the track no longer crash the race.
- Graphics: light tables read unsigned (no dotted headlight cones), shadows, turbo flame, skid
  smoke, start and finish message boxes, the HUD damage percentage and lap minutes.
- Tracks: circuit file names on medium, hard and arena races, the original track list per
  difficulty, reversed circuits keep each car's sprites, and every track keeps its own name
  (lap record voice and pause music).

Results, ranking and statistics
- Race positions, the results table, the ranking update and its highlight, races won, race income,
  the starting grid, the statistics screen and the records per circuit.
- Rivals: the 19 rivals get their names, faces and colours, again after the licence.

Menus, shop and events
- The original texts per car (sponsor, loan, shop, repair) and the menu lines are generated from
  `dr.exe` (`ui/util/originalTexts.c`, `ui/util/keyNames.c`).
- Sponsor, hitman, drug, sabotage and loan popups, the hitman contract and the prize table.
- Shop: animations and their frame tables, the armour crash, the cursor, trade-in rounding, buying
  a car, the game-over check, car colour ramps.
- Menus: box heights, the game menu cursor, "Continue Racing" / "Enter The Shop", the news strip and
  True Tom's 19 news items, the original font spacing, the volume screens, key names in the
  keyboard, gamepad and F1 screens, and gamepad navigation.
- Ending: the Adversary race, the ending animation (black also in `dr.exe` 1.0), the Hall of Fame and
  the final message.

Savegames
- Load and save slots, the quick save (F2/F3), save names of 15 letters, and the format documented
  in [SAVEGAME.md](SAVEGAME.md) with `tools/savegame.py`.

Memory
- Overruns: tables the decompiler split into one-byte globals (menu news, key names, menu lines,
  mushroom buffers, save slots) and texts built over stack locals assumed contiguous.
- Leaks: the buffers freed at the end of each race, textures, BPA and HAF reads, songs, per-frame
  allocations and hash lookups. Memory stays flat over a campaign.

Sound
- The effects stream is signed 16-bit stereo, as in the original, without the volume and pitch
  workarounds; FMOD is closed on exit; songs are freed with the library that loaded them; MOD loader
  overruns.

Other
- F6 screenshots write valid PCX files. Mods (`-mod=`) no longer crash.
- Build: compiler warnings are on (`/W3`) with a gate for dangerous ones
  (`scripts/Check-Warnings.ps1`); Release uses `NDEBUG` and a single CRT.
- Windows scripts to build, prepare the runtime folder, run with crash dumps and run the palette
  tests; a session log in `logs/`. See [DEVELOPMENT.md](DEVELOPMENT.md).

### January 15, 2019
- Initial release

