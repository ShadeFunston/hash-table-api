#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>

// Structure for hash table item
typedef struct {
    char* key;
    char* value;
} HashNode;

// Structure for actual hash table
typedef struct {
    int size;
    int count;
    HashNode ** items;
} HashTable;


static HashNode * newItem(const char* k, const char * v);
HashNode* newHashTable();
static void deleteHashNode(HashNode* toBeDeleted);
void deleteHashTable(HashTable* toBeDeleted);

#endif