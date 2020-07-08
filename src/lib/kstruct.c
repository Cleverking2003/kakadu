#include "include/kstruct.h"

KLinkedList* KLinkedList_Create(){
    KLinkedList* ll = (KLinkedList*) malloc(sizeof(KLinkedList));
    ll->head = 0;
    ll->tail = 0;
}
void KLinkedList_Append(KLinkedList* list, void* value){
    KLinkedListNode* node = (KLinkedListNode*) malloc(sizeof(KLinkedListNode));
    node->value = value;
    node->next = 0;
    list->tail = node;
    if(list->head == 0){
        list->head = node;
    } else {
        KLinkedListNode* nextNode = list->head;
        while(nextNode->next != 0) {
            nextNode = (KLinkedListNode*) nextNode->next;
        }
        nextNode->next = node;
    }

}
void* KLinkedList_At(KLinkedList* list, int index){
    KLinkedListNode* nextNode = list->head;
    for(int i = 0; i < index; i++){
        if(nextNode->next != 0)
            nextNode = (KLinkedListNode*) nextNode->next;
    }
    return nextNode->value;
}
void KLinkedList_Remove(KLinkedList* list, int index){
    KLinkedListNode* nextNode = list->head;
    if(index == 0){
        list->head = list->head->next;
        free(list->head);
        return;
    }
    for(int i = 0; i < index-1; i++) {
        if(nextNode->next == 0) return;
        nextNode = (KLinkedListNode*) nextNode->next;
    }
    KLinkedListNode* nxt = (KLinkedListNode*)((KLinkedListNode*) nextNode->next)->next;
    free(nextNode->next);
    nextNode->next = nxt;
    
}
void KLinkedList_Clear(KLinkedList* list){
    KLinkedListNode* nextNode = list->head;
    while(nextNode->next != 0){
        KLinkedListNode* toDelete = nextNode;
        nextNode = (KLinkedListNode*) nextNode->next;
        free(toDelete);
    }
    list->head = 0;
    list->tail = 0;
}
int KLinkedList_Length(KLinkedList* list){
    int counter = 0;
    if(list->head != 0){
        KLinkedListNode* nextNode = list->head;
        counter = 1;
        while(nextNode->next != 0){
            nextNode = (KLinkedListNode*) nextNode->next;
            counter++;
        }
    }
    return counter;

}