#ifndef _LOOKUP_H
#define _LOOKUP_H

#define LOOKUP_SIZE 503

typedef struct ls
{
    struct ls *next;
    char* key;
    char* value;
} lookupEntry_t;

char* getValue(char* key);
int putValue(char* key, char* value);
void freeTable();


#endif