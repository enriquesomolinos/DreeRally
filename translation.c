
#include <stdio.h>
#include "i18n.h"


char * languageEntries[100];


int initLanguage() {
	languageEntries[EXIT_TO_OS]="SALIR AL OS";
}

char * getLanguageEntry(int languageEntry) {
	return languageEntries[languageEntry];
}
