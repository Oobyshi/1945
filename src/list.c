#include <list.h>
#include <stdlib.h>

List* list_New() {
    List* list = (List*)malloc(sizeof(List));
    list->__head = NULL;
    list->__tail = NULL;
    return list;
}

void list_Destroy(List* list) {
    Lnode* each = list->__head;
    while(each != NULL) {
        Lnode* next = each->next;
        free(each);
        each = next;
    }
    free(list);
}

void list_Add(List* list, void* elem) {
    Lnode* node = (Lnode*)malloc(sizeof(Lnode));
    node->data = elem;
    node->next = NULL;

    if (list->__head == NULL) {
        list->__head = node;
        list->__tail = node;
    } else {
        list->__tail->next = node;
        list->__tail = node;
    }
}