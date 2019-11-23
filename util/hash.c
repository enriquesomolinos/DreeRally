#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <malloc.h>
#include <string.h>

hash_t *hash_new (int size) {
    hash_t *h = malloc(sizeof (hash_t));
   // h->keys = malloc(size* sizeof (void *));
   // h->values = malloc(size* sizeof (void *));
    h->size = size;
	h->filled = 0;
    return h;
}
 
int hash_index (hash_t *h, char *key) {
    int i;// = (int) hash(key) % h->size;
	char *orig ="";
	char * dest="";
	dest =malloc(strlen(key));
	strcpy(dest,key);
	for(i=0;i<h->filled;i++){
		orig = malloc(strlen(h->keys[i]));
		strcpy(orig,h->keys[i]);
		
		if(strcmp(strupr(orig),strupr(dest))==0){
			return i;
		}
	}
   /* while (h->keys[i] && h->keys[i] != key)
        i = (i + 1) % h->size;*/
	return -1;
}
 
void hash_insert (hash_t *h, char *key, void *value) {
    //int i = hash_index(h, key);

    h->keys[h->filled] = key;
    h->values[h->filled] = value;
	h->filled = h->filled +1;
}
 
void *hash_lookup (hash_t *h, char *key) {
    signed int i = hash_index(h, key);
    if(i==-1)
		return NULL;
	h->filled = h->filled +1;

	return h->values[i];
}
