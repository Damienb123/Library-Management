//creation of Hash.h
#ifndef HASH_H
#define HASH_H

#include "Book.h"

#define HASH_TABLE_SIZE 100

typedef struct {
    Book books[MAX_BOOKS];
} HashTable;

void initializeHashTable(HashTable* hashTable);
int hashFunction(const char* key);
void insertBook(HashTable* hashTable, const Book* book);
const Book* findBook(const HashTable* hashTable, const char* isbn);

#endif // HASH_H
