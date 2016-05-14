#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include "create_buf.h"
#include "token.h"
#include "strings.h"

/*void copy_tegname (char *str)*/

int main () 
{
    char **buf_tok = malloc(3 * sizeof(char*));
    buf_tok[0] = "<";
    buf_tok[1] = "</";
    buf_tok[2] = ">";
    
    
    int i, j;
    int flg = 0;
    
    char *buf;
    flg = create_buf(&buf);
    printf("buf:\n%s\n",buf);

    char *ptr[256];
    char delim[4] = {'\n', '\t', ' ', '\0'};
    
    struct stack *s_chteg;
    s_chteg = stack_create();
    
    struct stack *s_tegnames;
    s_tegnames = stack_create();
    
    int col = stok(buf, delim, ptr);
    for (i = 0; i < col; i++) {
	printf("ptr: %s\n", ptr[i]);
	for (j = 0; j < slen(ptr[i]); j++) {
	    if (ptr[i][j] == buf_tok[0][0]) {
		if (j == slen(ptr[i]) - 1)
		    printf("error\n");
		else {
		    if (ptr[i][j+1] == buf_tok[1][1]) {
			struct tok *token;
			token = token_create(0, buf_tok[1]);
			flg = stack_push(s_chteg, token);
			printf("push %s\n", buf_tok[1]);
		    }
		    else {
			struct tok *token;
			token = token_create(0, buf_tok[0]);
			flg = stack_push(s_chteg, token);
			printf("push %s\n", buf_tok[0]);
			printf("str %s\n", &ptr[i][1]);
			
		    }
		}
	    }
	    else if (ptr[i][j] == buf_tok[2][0]) {
		struct tok *tok_node;
		tok_node = stack_pop(s_chteg);
		if (tok_node == NULL)
		    fprintf(stderr, "stack: Stack underflow\n");
		else {
		    printf("pull: %s\n", tok_node->value);
		}
	    }
	}
    }
    int size = stack_size(s_chteg);
    printf("size %d\n", size);
    

    
    struct stack *s;
    s = stack_create();

    for (i = 1; i <= 10; i++) {
	struct tok *token;
	token = token_create(i%3, buf_tok[i%3]);
	flg = stack_push(s, token);
	if (flg == -1)
	    fprintf(stderr, "stack: Stack overflow\n");
    }

    struct tok *tok_node;
    for (i = 1; i <= 11; i++) {
	tok_node = stack_pop(s);
	if (tok_node == NULL)
	    fprintf(stderr, "stack: Stack underflow\n");
	else {
	    printf("pop: %s ", tok_node->value);
	    printf("pop: %d\n", tok_node->id);
	}
    }
    stack_free(s);

    return EXIT_SUCCESS;
}
