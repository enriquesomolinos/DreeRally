#ifndef BPAUTIL_H
#define BPAUTIL_H

int   openPalFromBpa(char * a1);
int    getFileSizeFromBpa(char *bpaFile, char * filename);
int   extractFromBpa(char* bpaFilename, void *dest, char* filename);


#endif