#include<stdlib.h>
#include<stdio.h>

struct Entry {
  	char *key;
  	int value;
		struct Entry *next;
};

struct HashTable {
  	struct Entry **table;
  	int capacity;
};

struct HashTable *hash_table_init(int capacity) {
		struct HashTable *ht = malloc(sizeof(struct HashTable));
		ht->table = calloc(capacity, sizeof(struct Entry *));
		ht->capacity = capacity;
		return ht;
};

void hash_table_insert(struct HashTable *ht, char *key, int value) {
		struct Entry *entry = malloc(sizeof(struct Entry));
		entry->key = key;
		entry->value = value;
		entry->next = NULL;

		ht->table[0] = entry;
};

char *hash_table_get(struct HashTable *ht, int position) {
  	return ht->table[position]->key;
};

void hash_table_remove(struct HashTable *ht, int key) {
		
};

int main() {
		struct HashTable *ht = hash_table_init(10);
		hash_table_insert(ht, "apple", 0);
		printf("%s\n", hash_table_get(ht, 0));
		return 0;
};

//hash_table_free()
