#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct node_t
{
    void *value;
    struct node_t *next;
} node;

typedef struct list_t
{
    node *head;
    node *tail;
    int count;
} list;

list* list_create();

void list_push_end(list *pl, void *value);

void list_push_begin(list *pl, void *value);

void list_remove_head(list *pl);

void* list_pop_begin(list *pl);

void list_clear(list *pl);

void list_destroy(list *pl);

#endif /* LIST_H */
