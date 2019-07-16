#pragma once

extern int savegames_unk_446DC2;
char  decryptByteSavegame(int a1, char a2);
char  encryptByteSavegame(int a1, char a2);
int   decryptEntireSavegame(int, char *Filename); // idb