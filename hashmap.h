#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define hash_at(hashmap, key) hashmap.buckets[key2code(key) % hashmap.len]

typedef struct hashbucket hashbucket_t;

typedef struct hashbucket {
	bool has_next;
	char *key;
	char *value;
	hashbucket_t *next;
} hashbucket_t;

typedef struct hashmap {
	hashbucket_t *buckets;
	size_t len;
} hashmap_t;

int key2code(char *key);
void hash_add(hashmap_t *hashmap, char *key, char *value);
hashmap_t hash_create(int len);
