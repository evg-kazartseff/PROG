#include "stack.h"

struct stack *stack_create()
{
    struct stack *s = malloc(sizeof(*s));
    if (s != NULL) {
	s->size = 0;
	s->top = NULL;
    }
    return s;
}

void stack_free(struct stack *s)
{
    while (s->size > 0)
	stack_pop(s); /* Delete All items */
    free(s);
}

int stack_size(struct stack *s)
{
    return s->size;
}

int stack_push(struct stack *s, struct tok *token)
{
    s->top = list_addfront(s->top, token);
    if (s->top == NULL) {
	return -1;
    }
    s->size++;
    return 0;
}

struct tok *stack_pop(struct stack *s)
{
    struct listnode *next;
    struct tok *data;
    if (s->top == NULL) {
	return NULL;
    }
    else {
	next = s->top->next;
	data = s->top->data;
	free(s->top);
	s->top = next;
	s->size--;
	return data;
    }
}
