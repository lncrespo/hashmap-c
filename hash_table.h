#define true 1
#define false 0
#define bool char

typedef struct bucket_t {
    char *key;
    char *value;
    struct bucket_t *next;
} bucket_t;

typedef struct {
	int map_size;
	int used_buckets;
	bucket_t **buckets;
} hash_table_t;

unsigned int hash(char *key, int map_size);
hash_table_t *hash_table_init(int map_size);
bool hash_table_insert(hash_table_t *hash_table, char* key, char* value);
void hash_table_delete(hash_table_t *hash_table, char* key);
char *hash_table_get(hash_table_t *hash_table, char* key);
void hash_table_destroy(hash_table_t *hash_table);
