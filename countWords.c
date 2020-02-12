#include "hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

const char marks[] = {',','.','?','!','(',')','-',':',';','\'','\"'};
const size_t size = 100000;

void mark (char *word){
	size_t l = strlen(word);
	if (strchr(marks, word[l - 1])) {
		word[l - 1] = 0;
	}
	return;
}

size_t constant (char *word) {
	return 1;
}

size_t sum (char *word) {
	size_t k = 0;
	while (*word) {
		k = k + (unsigned char) *word;
		word++;
	}
	return k % size;
}

size_t good (char *word) {
	size_t hash = 0;
	while (*word) {
		hash += (unsigned char)(*word);
		hash += (hash << 10);
		hash ^= (hash >> 6);
		word ++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash % size;
}

void up(char *word) {
	while (*word) {
		*word = toupper((size_t) *word);
		word++;
	}
	return;
}


int main() {
	size_t (*hashFunc[]) (char * word) = {constant, sum, good};
	struct HashTable* table;
	char word[MaxLen];
	clock_t begin, end;
	for (size_t i = 0; i <= 2; i++) {
		begin = clock();
		table = createHashTable(hashFunc[i], size);
		if (!table) {
			printf("Table was not create");
			break;
		}
		FILE* text = fopen("text.txt", "r");
		if (!text) {
			printf("File was not open");
			break;
		}
		fscanf(text, "%s", word);
		while (*word) {
			mark(word);
			up(word);
			if (*word) {
				setData(table, word, getData(table, word) + 1);
			}
			*word = 0;
			fscanf(text, "%s", word);
		}
		end = clock();
		statistics(table);
		fclose(text);
		deleteTable(table);
		printf("Time %d = %f\n\n", i, (float)(end - begin) / CLOCKS_PER_SEC);
	}
	return 0;
}
