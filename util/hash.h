typedef struct {
    int size;
    char *keys[150];
    char *values[150];
	int filled;
} hash_t;
 

hash_t *hash_new (int size);
int hash_index (hash_t *h, void *key);
void hash_insert (hash_t *h, void *key, void *value);
void *hash_lookup (hash_t *h, void *key);