#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <malloc.h>
#include <string.h>
#include <SDL_stdinc.h>

hash_t *hash_new (int size) {
    hash_t *h = malloc(sizeof (hash_t));
   // h->keys = malloc(size* sizeof (void *));
   // h->values = malloc(size* sizeof (void *));
	if (h != NULL) {
		h->size = size;
		h->filled = 0;
	}
    return h;
}
 
int hash_index (hash_t *h, char *key) {
    int i;// = (int) hash(key) % h->size;
	//Comparacion sin mayusculas y sin copias: antes cada busqueda reservaba la clave y todas
	//las guardadas (sin sitio para el terminador) y nunca las liberaba.
	for(i=0;i<h->filled;i++){
		if(SDL_strcasecmp(h->keys[i], key)==0){
			return i;
		}
	}
   /* while (h->keys[i] && h->keys[i] != key)
        i = (i + 1) % h->size;*/
	return -1;
}
 
void hash_insert (hash_t *h, char *key, void *value) {
    //int i = hash_index(h, key);

    if (h->filled >= 150)
        return;
    h->keys[h->filled] = key;
    h->values[h->filled] = value;
	h->filled = h->filled +1;
}
 
void *hash_lookup (hash_t *h, char *key) {
    signed int i = hash_index(h, key);
    if(i==-1)
		return NULL;
	//Aqui se sumaba 1 a filled en cada busqueda con exito: las siguientes recorrian claves sin
	//inicializar y el juego se cerraba con cualquier mod activo (con -mod, al llegar al final).

	return h->values[i];
}
