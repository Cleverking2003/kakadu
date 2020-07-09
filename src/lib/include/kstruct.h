#ifndef KSTRUCT_H
#define KSTRUCT_H

#include "kmemory.h"

typedef struct KLinkedListNode{
    void* value;
    void* next;
} KLinkedListNode;

typedef struct KLinkedList {
    KLinkedListNode* head;
    KLinkedListNode* tail;
} KLinkedList;

KLinkedList* KLinkedList_Create();
void KLinkedList_Append(KLinkedList* list, void* value);
void* KLinkedList_At(KLinkedList* list, int index);
void KLinkedList_Remove(KLinkedList* list, int index);
void KLinkedList_Clear(KLinkedList* list);
int KLinkedList_Length(KLinkedList* list);

#endif
