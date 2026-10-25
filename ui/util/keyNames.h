#ifndef KEY_NAMES_H
#define KEY_NAMES_H

//Nombres de las teclas por scancode, como los arma el dr.exe original (ver
//tools/ghidra/DumpKeyNames.java). En el original se escriben de a pedazos sobre una tabla de
//256 x 15 bytes; el decompilado la partio en cientos de globales sueltas.
#define KEY_NAMES 256
#define KEY_NAME_SIZE 15
//Menu de definir teclado: "left arrow  ", sin asignar "UNAVAILABLE ".
extern const char originalKeyNames[KEY_NAMES][KEY_NAME_SIZE];
//Pantalla de teclas en carrera: alineados a la derecha con puntos, "...LEFT ARROW".
extern const char originalKeyNamesInRace[KEY_NAMES][KEY_NAME_SIZE];

#endif
