# A simple string hashmap implementation using external chaining to handle collision.

## Functions

```c
hash_table_t *hash_table_init(int map_size);
```
Initialize a new hashmap with a given size and return a pointer to the newly allocated hashmap.
Make sure to call `hash_table_destroy` on the hashmap to free the memory.

```c
bool hash_table_insert(hash_table_t *hash_table, char *key, char *value);
```
Insert a value into a hashmap using a string as key and a string as value.

```c
void hash_table_delete(hash_table_t *hash_table, char *key);
```
Delete a key from a hashmap.

```c
char *hash_table_get(hash_table_t *hash_table, char *key);
```
Get a value from a hashmap using the key.

```c
void hash_table_destroy(hash_table_t *hash_table);
```
Destroy a hashmap, freeing all buckets and the hashmap itself.
