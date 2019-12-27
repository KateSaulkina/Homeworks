#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include "list_hash.h"

struct HashTable {
	struct List** entry;
	size_t size;
	size_t (*hashFunc) (char* word);
};

struct HashTable *createHashTable(size_t (*hashFunc) (char* word), size_t k);
void addEl(struct HashTable *table, char *word, size_t hash);
void deleteEl(struct HashTable *table, char *word);
size_t getData(struct HashTable *table, char *word);
void setData(struct HashTable*, char *word, size_t val);
void deleteTable(struct HashTable *table);
void statistics(struct HashTable *table);

#endif // HASHTABLE_H_INCLUDED
