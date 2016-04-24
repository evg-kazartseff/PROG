#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

struct listnode {
    char *data; /* Data */
    struct listnode *next; /* Next node */
};

struct listnode *list_createnode(char *data);
struct listnode *list_addfront(struct listnode *list, char *data);

#endif
