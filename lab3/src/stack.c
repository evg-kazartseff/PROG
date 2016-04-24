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
	stack_pop(s, NULL); /* Delete All items */
    free(s);
}

int stack_size(struct stack *s)
{
    return s->size;
}

int stack_push(struct stack *s, char *value)
{
    s->top = list_addfront(s->top, value);
    if (s->top == NULL) {
	return -1;
    }
    s->size++;
    return 0;
}

int stack_pop(struct stack *s, char **value)
{
    struct listnode *next;
    char *data;
    if (s->top == NULL) {
	return -1;
    }
    next = s->top->next;
    data = s->top->data;
    free(s->top);
    s->top = next;
    s->size--;
    char *tmp = malloc(strlen(data) * sizeof(data));
    strcpy(tmp, data);
    *value = tmp;
    return 0;
}
