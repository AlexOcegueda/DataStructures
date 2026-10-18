#include<stdlib.h>

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
		ht->table = malloc(capacity * sizeof(struct Entry *));
		ht->capacity = capacity;
		return ht;
};

void hash_table_insert(struct HashTable *ht, char key, int value) {
		ht->table->key = key;
		ht->table->value = value;
		ht->table->entry->next = NULL;
};

int hash_table_get(struct HashTable *ht, int position) {
		return ht->table[position];
};

int main() {
		struct HashTable *ht = hash_table_init(10);
		hash_table_insert(ht, 'a', 1);
		printf("%d\n", hash_table_get(0));
		return 0;
};

//hash_table_get()
//hash_table_remove()
//hash_table_free()
