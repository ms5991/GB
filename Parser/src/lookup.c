#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lookup.h"

static lookupEntry_t* table[LOOKUP_SIZE];

unsigned int hash(char* key)
{
    int length = strlen(key);
    int i;
    unsigned int result = 4093;

    for(i=0;i<length;i++)
    {
        result = (result << 5) + result + key[i];
    }
#ifdef DEBUG
    printf("Got result: [%d]\n", result);
#endif
    return result % LOOKUP_SIZE;
}

lookupEntry_t* getValueInternal(char* key, unsigned int precalcedHash)
{
    lookupEntry_t* ptr;

    // iterate through the entries in this bucket and compare the key value,
    // returning the value if found
    for (ptr = table[precalcedHash]; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(key, ptr->key) == 0)
            return ptr;
    }

    // not found
    return NULL;
}

char* getValue(char* key)
{
    lookupEntry_t* result = getValueInternal(key, hash(key));

    if (result != NULL)
    {
        // don't check for null since we would return null anyway. Probably should generate some sort of error
        char* returnValue = strdup(result->value);
        return returnValue;
    }

    return NULL;
}


int putValue(char* key, char* value)
{
    unsigned int hashValue = hash(key);

    lookupEntry_t* ptr = getValueInternal(key, hashValue);

    char* localKeyPtr = strdup(key);
    char* localValuePtr = strdup(value);

    // invalid ptr
    if (localKeyPtr == NULL || localValuePtr == NULL)
        return 0;

    // key not found -- new entry
    if (ptr == NULL)
    {
        // create a new entry
        ptr = (lookupEntry_t*)(malloc(sizeof(lookupEntry_t)));

        // didn't get valid ptr
        if (ptr == NULL)
            return 0;

        // set the key and value in the new entry
        ptr->key = localKeyPtr;
        ptr->value = localValuePtr;

        // put entry at beginning of bucket
        ptr->next = table[hashValue];

#ifdef DEBUG
        if (table[hashValue] != NULL)
            printf("Collision at hash value [%d], previous was [%s]!\n", hashValue, table[hashValue]->key);
#endif

        // update the table
        table[hashValue] = ptr;
    }
    // key found -- update value
    else
    {
        // previous value needs to be freed
        free(ptr->value);

        // update with new value
        ptr->value = localValuePtr;
    }

    // success
    return 1;
}

void freeTable()
{
    int i;
    for (i=0;i<LOOKUP_SIZE;i++)
    {
        lookupEntry_t* ptr = table[i];

#ifdef DEBUG
        if (ptr == NULL)
            printf("Hash value [%d] was unused\n", i);
#endif

        while (ptr != NULL)
        {
            free(ptr->key);
            free(ptr->value);
            lookupEntry_t* next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
}