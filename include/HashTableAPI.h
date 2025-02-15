#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

char* stralloc(const char * str);
static HashNode * newHashNode(const char* k, const char * v);
HashTable* newHashTable();
static void deleteHashNode(HashNode* toBeDeleted);
void deleteHashTable(HashTable* toBeDeleted);
char* stralloc(const char * str);

#endif