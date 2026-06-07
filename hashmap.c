#include "hashmap.h"

int key2code(char *key) {
	int sum = 0;
	int len = strlen(key);
				// null terminator making everything easier
	for(int i = 0; key[i]; i++) {
		sum = 31 * sum + key[i];
	}
	return sum;
}

void hash_add(hashmap_t *hashmap, char *key, char *value) {
	int code = key2code(key);
	code %= hashmap->len;
	if(!hashmap->buckets[code].has_next) {
		hashmap->buckets[code].key = key;
		hashmap->buckets[code].value = value;
		hashmap->buckets[code].has_next = false;
	}
	else {
		hashbucket_t *tmp = &hashmap->buckets[code];
		for(;tmp->has_next; tmp = tmp->next);
		tmp->has_next = true;
		tmp->next = &(hashbucket_t) {
			.key = key,
			.value = value,
			.has_next = false
		};
	}
}

hashmap_t hash_create(int len) {
	return (hashmap_t) {
		.len = len,
		.buckets = malloc(len * sizeof(hashbucket_t))
	};
}
