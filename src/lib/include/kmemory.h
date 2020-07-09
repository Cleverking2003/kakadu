#ifndef KMEMORY_H
#define KMEMORY_H
#define MEMORY_CAPACITY 20000
#include "kresult.h"
typedef struct chunk
{
    int size; // Size of chunk in bytes
    unsigned is_free;
    struct chunk* next;
} chunk;

void* malloc(unsigned int size);
K_RESULT getFreeChunk(chunk* ch, unsigned int size);
void free(void* block);
void* sbrk(int increment);

#endif