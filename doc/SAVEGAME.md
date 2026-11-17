# Savegames (DR.SG0 to DR.SG9)

Format of the full Windows version, checked against `dr.exe` and real savegames. The shareware
version (`DR.SWn`) is different: it is 2195 bytes long and uses another cipher (see
`tools/sharewareSavegameDecrypt.py`).

Tool: [tools/savegame.py](../tools/savegame.py) shows, decrypts, encrypts and edits fields.

```text
python tools/savegame.py show runtime/DR.SG2 --all
python tools/savegame.py set runtime/DR.SG2 name="Light Gaby" money=5000
```

## File

`DR.SGn` is slot `n` of the menu. `DR.SG7` is also the quick save slot ("Quicksave Slot"). Every
file is 2179 bytes (0x883) long and holds a header and the `drivers[]` table copied as it is in
memory. Nothing else is stored: not the black market, the races on offer or the sponsor streaks.

| Bytes | Size | Content |
| --- | --- | --- |
| 0 | 1 | Cipher key (`rand() % 255`), stored in clear |
| 1 | 1 | `driverId`: position of the player in `drivers[]` |
| 2 | 1 | `useWeapons` (0 or 1) |
| 3 | 1 | Difficulty: 0 easy, 1 medium, 2 hard |
| 4–18 | 15 | Savegame name, padded with zeros. A 15-letter name has no terminator |
| 19–2178 | 2160 | `drivers[20]`, 20 records of 108 bytes (struct `Driver` in `drivers.h`) |

The file is written by `saveGame` (`ui/loadSaveGameScreen.c`, 0x42F6E0) and by the quick save
(`dr.c`), and read by `decryptEntireSavegame` (`savegame.c`, 0x41C910) and the load screen.

## Cipher

Byte 0 is left as it is. For each byte `i` from 1 to 2178:

- Encrypt: `b = (b - key + 17·i) mod 256`, then rotate `b` right by `i mod 6` bits.
- Decrypt: rotate `b` left by `i mod 6` bits, then `b = (b - 17·i + key) mod 256`.

The key can be kept when editing: the game accepts any value.

## Driver record (108 bytes)

Every field after the name is a signed little-endian `int32`. Offsets count from the start of the
record, which is at `19 + 108·n` in the file. The address is that of `drivers[0]` in `dr.exe` (the
table starts at 0x460840).

| Offset | Address | Field | Values |
| --- | --- | --- | --- |
| 0 | 0x460840 | `name` | 12 bytes, zero-terminated. The licence takes 10 letters and stores the name in lower case with a capital initial. Rivals are in upper case |
| 12 | 0x46084C | `damage` | Car damage, 0 to 100 |
| 16 | 0x460850 | `engine` | Engine level, 0 to `cars[carType].engineUpgrades` |
| 20 | 0x460854 | `tire` | Tire level, 0 to `cars[carType].tireUpgrades` |
| 24 | 0x460858 | `armour` | Armour level, 0 to `cars[carType].armourUpgrades` |
| 28 | 0x46085C | `carType` | 0 Vagabond, 1 Dervish, 2 Sentinel, 3 Shrieker, 4 Wraith, 5 Deliverator |
| 32 | 0x460860 | `unk_460860` | Never accessed by `dr.exe`; always 0 |
| 36 | 0x460864 | `unk_460864` | Never accessed by `dr.exe`; always 0 |
| 40 | 0x460868 | `unk_460868` | Never accessed by `dr.exe`; always 0 |
| 44 | 0x46086C | `colour` | Player: index in `COPPER.PAL` (also the position of the licence slider). Rival: index in `CARCOL.PAL`, the same as its name |
| 48 | 0x460870 | `money` | Money. A new game starts with 495 |
| 52 | 0x460874 | `loanType` | Player: −1 without a loan, 0 to 4 for the loan taken (`LoanType`). Rivals: 0, unused |
| 56 | 0x460878 | `loanRaces` | Player: races since the loan, 1 to 4; −1 without a loan. Rivals: 0 |
| 60 | 0x46087C | `carMoneyCost` | Value of the current car |
| 64 | 0x460880 | `face` | Portrait, 0 to 19 (`face01` to `face20`). For rivals it is also the index of their name |
| 68 | 0x460884 | `points` | Championship points |
| 72 | 0x460888 | `rank` | Position in the ranking, 1 to 20. Ties share the position |
| 76 | 0x46088C | `racesWon` | Races won |
| 80 | 0x460890 | `totalRaces` | Races run |
| 84 | 0x460894 | `lastRaceIncome` | Income of the last race |
| 88 | 0x460898 | `totalIncome` | Total income |
| 92 | 0x46089C | `mines` | Mines bought for the next race (8 per purchase) |
| 96 | 0x4608A0 | `spikes` | Spikes bought, 0 or 1 |
| 100 | 0x4608A4 | `rocket` | Rocket bought, 0 or 1 |
| 104 | 0x4608A8 | `sabotage` | Sabotage bought, 0 or 1. Used up in the next race |

## Editing

- After each race `drivers[]` is sorted by points and `rank` recalculated, so the player has no
  fixed position: find it with `driverId`. When changing points, keep `rank` consistent (the game
  recalculates it at the end of the next race).
- Rivals do not buy upgrades. Their engine, tires and armour are drawn when the game starts, between
  0 and the car's maximum minus one.
- The player's face and colour should not repeat a rival's. Savegames created by earlier builds of
  DreeRally may have that defect: `initDrivers` was not called after the licence, so a rival could
  have the player's face and one of the 20 drivers was missing.
- Rival weapons (`mines`, `spikes`, `rocket`, `sabotage`) are ignored: they are drawn again for
  every race.
