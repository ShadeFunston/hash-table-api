#include "HashTableAPI.h"

/**
 * Function used to allocate memory for a given string
 * @param str the string given to allocate
 * @return the allocated string
 */
char* stralloc(const char* str) {

    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str) + 1;
    char* strCopy = malloc(len);

    if (strCopy != NULL) {
        memcpy(strCopy, str, len);
    }

    return strCopy;
}

/**
 * Used to allocate and initialize new hash table item
 * @param k the key for the item pair
 * @param v the value for the item pair
 * @return new allocated hash node
 */
static HashNode * newHashNode(const char* k, const char * v) {

    // Allocate memory and (key/value) pair for current hash node
    HashNode * newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = stralloc(k);
    newNode->value = stralloc(v);

    return newNode;     // Return the new node created
}

HashTable* newHashTable() {

    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->size = 53;
    newTable->count = 0;
    newTable->items = calloc((size_t)newTable->size, sizeof(HashNode*));
    return newTable;
}

static void deleteHashNode(HashNode* toBeDeleted) {

    // Check that the given node is not NULL
    if (toBeDeleted != NULL) {
        
        // Check that the given key is not NULL
        if (toBeDeleted->key != NULL) {
            free(toBeDeleted->key);
        }

        // Check that the given value is not NULL
        if (toBeDeleted->value != NULL) {
            free(toBeDeleted->value);
        }

        // Free the current node
        free(toBeDeleted);
    }
}

void deleteHashTable(HashTable* toBeDeleted) {
    
    // Loop through the hashmap items
    for (int i = 0; i < toBeDeleted->size; i++) {
        
        // Delete the current node
        deleteHashNode(toBeDeleted->items[i]);
        toBeDeleted->items[i] = NULL;
    }
    
    if (toBeDeleted->items != NULL) {
        free(toBeDeleted->items);
        toBeDeleted->items = NULL;
    }
    
    if (toBeDeleted != NULL) {
        free(toBeDeleted);
        toBeDeleted = NULL;
    }
}