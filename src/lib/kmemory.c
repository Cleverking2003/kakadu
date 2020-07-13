#include "include/kmemory.h"

chunk* head; //Head of our linked list
chunk* tail; //Tail of our linked list

void* malloc(unsigned int size){
    void* block;
    chunk* header;
    if (!size)
        return 0;
    K_RESULT r = getFreeChunk(header,size);
    if (r) {
        // If we found free block, just occupy it.
        header->is_free = 0;
        return (void*)(header + 1);
    }
    int total_size = sizeof(chunk) + size;
    block = sbrk(total_size);
    if (block == (void*) -1) {
        return 0;
    }
    header = block;
    header->size = size;
    header->is_free = 0;
    header->next = 0;
    if (!head)
        head = header;
    if (tail)
        tail->next = header;
    tail = header;

    return (void*)(header + 1);
}
K_RESULT getFreeChunk(chunk* ch, unsigned int size){
    chunk* curr = head;
    while(curr) {
        if (curr->is_free && curr->size >= size){
            ch = curr;
            return K_SUCCESS;
        }

        curr = curr->next;
    }
    return K_FAIL;
}
void free(void* block){
    chunk *header, *tmp;
    void *brk;

    if (!block)
        return;
    header = (chunk*)block - 1;

    brk = sbrk(0);
    if ((char*)block + header->size == brk) {
        if (head == tail) {
            head = tail = 0;
        } else {
            tmp = head;
            while (tmp) {
                if(tmp->next == tail) {
                    tmp->next = 0;
                    tail = tmp;
                }
                tmp = tmp->next;
            }
        }
        sbrk(0 - sizeof(chunk) - header->size);
        return;
    }
    header->is_free = 1;
}
void *sbrk(int increment)
{
    static char global_mem[MEMORY_CAPACITY] = {0};
    static char *p_break = global_mem;

    char *const limit = global_mem + MEMORY_CAPACITY;
    char *const original = p_break;

    if (increment < global_mem - p_break  ||  increment >= limit - p_break)
    {
        return (void*)-1;
    }
    p_break += increment;

    return original;
}
