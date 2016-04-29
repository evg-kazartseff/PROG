#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include "create_buf.h"
#include "token.h"

int main () 
{
    struct stack *s;
    int i;
    int flg = 0;
    s = stack_create();
    
    char *buf;
    flg = create_buf(&buf);
    printf("buf: %s",buf);
    
    struct tok *tok_node;
    
    for (i = 1; i <= 10; i++) {
	struct tok *token;
	token = malloc(sizeof(*token));
	token->id = i;
	token->value = "uwi";
	flg = stack_push(s, token);
	if (flg == -1)
	    fprintf(stderr, "stack: Stack overflow\n");
    }
    for (i = 1; i <= 12; i++) {
	tok_node = stack_pop(s);
	if (tok_node == NULL)
	    fprintf(stderr, "stack: Stack underflow\n");
	else {
	    printf("pop: %s\n", tok_node->value);
	    printf("pop: %d\n", tok_node->id);
	}
    }
    stack_free(s);
    
    
    return EXIT_SUCCESS;
}
