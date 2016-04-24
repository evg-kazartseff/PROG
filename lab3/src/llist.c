#include "llist.h"

struct listnode *list_createnode(char *data)
{
    struct listnode *p;
    p = malloc(sizeof(*p)); // Выделяем память
    if (p != NULL) {
	p->data = data;
	p->next = NULL;
    }
    return p;
}

struct listnode *list_addfront(struct listnode *list, char *data)
{
    struct listnode *newnode;
    newnode = list_createnode(data);
    if (newnode != NULL) {
	newnode->next = list;
	return newnode;
    }
    return list;
}

