// Hash.c
#include "Hash.h"
#include <string.h>

void initializeHashTable(HashTable* hashTable) {
    // Initialize the hash table
    for (int i = 0; i < MAX_BOOKS; ++i) {
        initializeBook(&hashTable->books[i], "", "", "", 0);
    }
}

int hashFunction(const char* key) {
    // Simple hash function for illustration purposes
    int sum = 0;
    while (*key) {
        sum += *key++;
    }
    return sum % HASH_TABLE_SIZE;
}

void insertBook(HashTable* hashTable, const Book* book) {
    int index = hashFunction(book->isbn);
    initializeBook(&hashTable->books[index], book->isbn, book->title, book->author, book->publicationYear);
}

const Book* findBook(const HashTable* hashTable, const char* isbn) {
    int index = hashFunction(isbn);
    return &hashTable->books[index];
}