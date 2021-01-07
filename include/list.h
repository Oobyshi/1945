#ifndef LIST_H
#define LIST_H

#include "common.h"

struct List_node {
    void* data;
    struct List_node* next;
};
typedef struct List_node Lnode;

struct List {
    Lnode* __head;
    Lnode* __tail;
};
typedef struct List List;

List* list_New();
void list_Destroy(List* list);
void list_Add(List* list, void* elem);
#endif /* VECTOR_H */