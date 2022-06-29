#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "hash_table.h"

void dump_bucket(bucket_t *bucket) {
	int level = 0;
	printf("TOP: BUCKET: %s: %s, NEXT: %p\n", bucket->key, bucket->value, bucket->next);

	while (bucket->next != NULL) {
		bucket = bucket->next;

		level++;

		printf("%d: BUCKET: %s: %s, NEXT: %p\n", level, bucket->key, bucket->value, bucket->next);
	}
}

void destroy_bucket(bucket_t *bucket) {
	if (bucket == NULL) {
		return;
	}

	free(bucket->key);
	free(bucket->value);
	free(bucket);
}

unsigned int hash(char *key, int map_size) {
	int length = strlen(key);

	unsigned int hash_value = 17;

	for (int i = 0; i < length; ++i) {
		hash_value += key[i];
		hash_value = (hash_value * key[i]) % map_size;
	}

	return hash_value;
}

hash_table_t *hash_table_init(int map_size) {
	hash_table_t *hash_table = malloc(sizeof(hash_table_t));
	hash_table->buckets = malloc(map_size * sizeof(bucket_t));
	hash_table->map_size = map_size;
	hash_table->used_buckets = 0;

	for (int i = 0; i < map_size; i++) {
		hash_table->buckets[i] = NULL;
	}

	return hash_table;
}

bool hash_table_insert(hash_table_t *hash_table, char *key, char *value) {
	int index = hash(key, hash_table->map_size);

	if (hash_table->buckets[index] == NULL) {
		hash_table->used_buckets++;
	}

	bucket_t *entry = malloc(sizeof(bucket_t));
	entry->value = malloc(sizeof(value));
	entry->key = malloc(sizeof(key));
	entry->next = hash_table->buckets[index];

	strcpy(entry->value, value);
	strcpy(entry->key, key);

	hash_table->buckets[index] = entry;

	return true;
}

void hash_table_delete(hash_table_t *hash_table, char *key) {
	int index = hash(key, hash_table->map_size);
	bucket_t *current_bucket = hash_table->buckets[index];

	if (current_bucket != NULL && current_bucket->next == NULL) {
		hash_table->buckets[index] = NULL;

		hash_table->used_buckets--;
	} else if (hash_table->buckets[index] != NULL && hash_table->buckets[index]->next != NULL) {
		bucket_t *prev = NULL;

		while (strcmp(current_bucket->key, key) != 0 && current_bucket->next != NULL) {
			prev = current_bucket;

			current_bucket = current_bucket->next;
		}

		if (strcmp(current_bucket->key, key) == 0) {
			prev->next = current_bucket->next;
		}
	}

	destroy_bucket(current_bucket);
}

char *hash_table_get(hash_table_t *hash_table, char *key) {
	bucket_t *bucket;

	if ((bucket = hash_table->buckets[hash(key, hash_table->map_size)]) == NULL) {
		return NULL;
	}

	if (strcmp(bucket->key, key) == 0) {
		return bucket->value;
	}

	if (bucket->next != NULL) {
		while (strcmp(bucket->key, key) != 0 && bucket->next != NULL) {
			bucket = bucket->next;
		}

		if (strcmp(bucket->key, key) == 0) {
			return bucket->value;
		}
	}

	return NULL;
}

void hash_table_dump(hash_table_t *hash_table) {
	for (int i = 0; i < hash_table->map_size; ++i) {
		if (hash_table->buckets[i] == NULL) {
			printf("%d: ---\n", i);
		} else {
			dump_bucket(hash_table->buckets[i]);
		}
	}
}
