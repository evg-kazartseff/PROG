#include "llist.h"

struct listnode *list_createnode(struct tok *token)
{
    struct listnode *p;
    p = malloc(sizeof(*p)); // Выделяем память
    if (p != NULL) {
	p->data = token;
	p->next = NULL;
    }
    return p;
}

struct listnode *list_addfront(struct listnode *list, struct tok *token)
{
    struct listnode *newnode;
    newnode = list_createnode(token);
    if (newnode != NULL) {
	newnode->next = list;
	return newnode;
    }
    return list;
}

