
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../config.h"
#include "mod.h"

#include "../util/hash.h"


hash_t *modEntries;

char * readlineConfig(FILE *fp, char *buffer)
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
int initMod() {

	FILE * fp;
    char *s;
	char delim[] = "=";
	char *key ;
	char *value ;
	char completeFile[300] = "";
	if(mainArgs.mod){
	    modEntries = hash_new(150);
		 strcat(completeFile,"mods/");
	  strcat(completeFile, mainArgs.mod);
	   strcat(completeFile,"/config.txt");
		fp = fopen(completeFile, "r");
	}else
		return;
	while ((s = readlineConfig(fp, 0)) != NULL)
	{
		
		key = strtok(s, delim);

		if(key != NULL)
		{
			value = strtok(NULL, delim);
			hash_insert(modEntries, (key), value);
		}
		//free(s);		
	}
	fclose(fp);
}

char * getModCharEntry(char * modEntryKey, char * fallbackValue) {
	char * result;
	if(!mainArgs.mod)
		return fallbackValue;
	result = (char *)hash_lookup(modEntries, (modEntryKey));
	if(result == NULL)
		return fallbackValue;
	return result ;	
}

int getModIntEntry(char * modEntryKey, int fallbackValue) {
	char * result;
	if(!mainArgs.mod)
		return fallbackValue ;
	result = (char *)hash_lookup(modEntries, (modEntryKey));
	if(result == NULL)
		return fallbackValue;
	return atoi(result) ;	
}