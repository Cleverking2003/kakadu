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

chunk* head; //Head of our linked list
chunk* tail; //Tail of our linked list

void* malloc(unsigned int size);
K_RESULT getFreeChunk(chunk* ch, unsigned int size);
void free(void* block);
void* sbrk(int increment);

#endif