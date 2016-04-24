#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include "llist.h"
#include <string.h>

struct stack {
	struct listnode *top; /* Вершина стека */
	int size;
};

struct stack *stack_create();
void stack_free(struct stack *s);
int stack_size(struct stack *s);
int stack_push(struct stack *s, char *value);
int stack_pop(struct stack *s, char **value);


#endif
