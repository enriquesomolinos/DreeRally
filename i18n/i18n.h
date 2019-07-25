#include <stdio.h>

typedef enum  {
	 LANGUAGE_ENGLISH = 0,
	 LANGUAGE_SPANISH = 1

}Languages;

int initI18n();
char * getLanguageEntry(char* languageEntry);
char * readline(FILE *fp, char *buffer);
