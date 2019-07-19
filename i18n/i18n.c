
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../config.h"
#include "i18n.h"
#include "../util/hash.h"


hash_t *languageEntries;

char * readline(FILE *fp, char *buffer)
{
    int ch;
    int i = 0;
    size_t buff_len = 0;
	void *tmp;
    buffer = malloc(buff_len + 1);
    if (!buffer) return NULL;  // Out of memory

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    {
        buff_len++;
        tmp = realloc(buffer, buff_len + 1);
        if (tmp == NULL)
        {
            free(buffer);
            return NULL; // Out of memory
        }
        buffer = tmp;

        buffer[i] = (char) ch;
        i++;
    }
    buffer[i] = '\0';

    // Detect end
    if (ch == EOF && (i == 0 || ferror(fp)))
    {
        free(buffer);
        return NULL;
    }
    return buffer;
}

int initI18n(int language) {

	FILE * fp;
    char *s;
	char delim[] = "=";
	char *key ;
	char *value ;
    languageEntries = hash_new(150);
	if(mainArgs.language)
		fp = fopen(strcat(strcat("lang/",mainArgs.language),".txt"), "r");
	else
		return;
	while ((s = readline(fp, 0)) != NULL)
	{
		
		key = strtok(s, delim);

		if(key != NULL)
		{
			value = strtok(NULL, delim);
			hash_insert(languageEntries, (key), value);
		}
		//free(s);		
	}
}

char * getLanguageEntry(char * languageEntry) {
	char * result;
	result = (char *)hash_lookup(languageEntries, (languageEntry));
	if(result == NULL)
		return languageEntry;
	return result ;	
}
