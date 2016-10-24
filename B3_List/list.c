#include "list.h"

list* list_create()
{
    list *l = (list*)malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->count = 0;

    return l;
}

void list_push_end(list *pl, void *value)
{
    node *p = (node*)malloc(sizeof(node));
    p->next = NULL;
    p->value = value;

    if (pl->tail == NULL)
    {
        pl->head = p;
    }
    else
    {
        pl->tail->next = p;
    }
    pl->tail = p;
    pl->count++;
}

void list_push_begin(list *pl, void *value)
{
    node *p = (node*)malloc(sizeof(node));
    p->value = value;
    p->next = pl->head;
    pl->head = p;
    pl->count++;

    if (pl->tail == NULL)
    {
        pl->tail = p;
    }
}

void list_remove_head(list *pl)
{
    node *p = pl->head;
    pl->head = p->next;
    pl->count--;

    free(p);
    if (pl->head == NULL)
    {
        pl->tail = NULL;
    }
}

void* list_pop_begin(list *pl)
{
    void *v = NULL;
    if (pl->head != NULL)
    {
        v = pl->head->value;
        list_remove_head(pl);
    }

    return v;
}

void list_clear(list *pl)
{
    node *p = pl->head;
    while (p)
    {
        pl->head = p->next;
        free(p);
        p = pl->head;
    }
    pl->tail = NULL;
    pl->count = 0;
}

void list_destroy(list *pl)
{
    list_clear(pl);
    free(pl);
}
