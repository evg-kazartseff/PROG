#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>
#include "token.h"

struct listnode {
    struct tok *data; /* Data */
    struct listnode *next; /* Next node */
};

struct listnode *list_createnode(struct tok *token);
struct listnode *list_addfront(struct listnode *list, struct tok *token);

#endif
