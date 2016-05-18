#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include "create_buf.h"
#include "token.h"
#include "strings.h"
#include <string.h>

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
    
    char *buf_out;
    flg = create_buf(&buf_out);
    printf("buf:\n%sn",buf_out);
    

    char **ptr = NULL;
    ptr = calloc(1024, sizeof(char *));
    
    
    
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
			struct tok *teg;
			teg = token_create(0, buf_tok[1]);
			flg = stack_push(s_chteg, teg);
			printf("push %s\n", buf_tok[1]);
			struct tok *name;
			name = stack_pop(s_tegnames);
			char *tag_name = NULL;
			strcpy_c(&ptr[i][j + 2], &tag_name, buf_tok[2][0]);
			flg = sequal(name->value, tag_name);
			if (flg == 1)
			    printf("ok\n");
			else
			    printf("err\n");
		    }
		    else {
			struct tok *teg;
			teg = token_create(0, buf_tok[0]);
			flg = stack_push(s_chteg, teg);
			char *tag_name = NULL;
			strcpy_c(&ptr[i][j + 1], &tag_name, buf_tok[2][0]);
			struct tok *name;
			name = token_create(3, tag_name);
			flg = stack_push(s_tegnames, name);
			printf("push %s\n", buf_tok[0]);
			printf("str %s\n", tag_name);
			
		    }
		}
	    }
	    else if (ptr[i][j] == buf_tok[2][0]) {
		struct tok *teg;
		teg = stack_pop(s_chteg);
		if (teg == NULL)
		    fprintf(stderr, "stack: Stack underflow\n");
		else {
		    printf("pull: %s\n", teg->value);
		}
	    }
	}
    }
    int size = stack_size(s_chteg);
    printf("size %d\n", size);
    
    size = stack_size(s_tegnames);
    printf("size %d\n", size);
    
    return EXIT_SUCCESS;
}
