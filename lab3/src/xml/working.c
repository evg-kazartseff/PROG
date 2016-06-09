#include "working.h"

void replace(char *str_del, char *str_in, int len_del)
{
    int len_in = strlen(str_in);
    int delta = len_in - len_del;
    if(delta > 0) {
	memmove(&str_del[delta], str_del,
                strlen(str_del));
	memmove(str_del, str_in, len_in);
    }
    else if (delta == 0) {
	memmove(str_del, str_in, len_in);
    }
}

int len_before_accept(char *str, char *reject)
{
    int i, j;
    int len = strlen(str);
    int len_r = strlen(reject);
    int flg = 0;
    for (i = 0; i < len; i++) {
	for (j = 0; j < len_r; j++) {
	    if (str[i] == reject[j])
		flg = 1;
	}
	if (flg == 0)
	    return i;
	else 
	    flg = 0;
    }
    return -1;
}

int working(char *buf)
{
    int flg = 0;
    
    struct stack *s_tagnames;
    s_tagnames = stack_create();
    
    struct stack *s_delim;
    s_delim = stack_create();

    int del_name = 0;
    int i;
    int col = 0;
    for (i = 0; buf[i] != '\0'; i++) {
	if (buf[i] == '<') {
	    if (buf[i + 1] != '/') {
		char *pl_del = strstr(&buf[i], "delim=");
		char *pl_qot = strchr(&buf[i], '>');
		if((pl_del != NULL) && (pl_qot != NULL) && ((long int)pl_qot > (long int)pl_del)) {
		    del_name = 1;
		    int idx;
		    if (pl_del[6] == '"')
			idx = 7;
		    else
			idx = 6;
		    char delim[1];
		    delim[0] = pl_del[idx];
		    struct tok *del;
		    del = token_create(10, delim);
		    flg = stack_push(s_delim, del);
		    
		}
		else 
		    del_name = 0;
		
		
		int l_rej = len_befor_reject(&buf[i + 1], "> \n\t");
		char *tag_name = NULL;
		tag_name = calloc(l_rej + 1, sizeof(char));
		memmove(tag_name, &buf[i + 1], l_rej);
		struct tok *name;
		name = token_create(del_name, tag_name);
		flg = stack_push(s_tagnames, name);
		free(tag_name);
		
	    }
	    else {
		struct tok *name;
		name = stack_pop(s_tagnames);
		if (name->id == 1)
		    stack_pop(s_delim);
	    }
	}
	
	if (buf[i] == '>') {
	    if ((stack_size(s_tagnames) != 0) && (stack_size(s_delim) != 0)) {
		struct tok *tagname;
		tagname = stack_look_top(s_tagnames);
		if (tagname != NULL) {
		    if (strcmp(tagname->value, "path") == 0) {
			col++;
			printf("path %d\n", col);
			struct tok *d;
			d = stack_look_top(s_delim);
			int step = len_before_accept(&buf[i + 1], " \n\t");
			int path_len_b = strcspn(&buf[i + step + 1], "< \n\t");
			char *path = NULL;
			path = calloc(path_len_b + 256, sizeof(char));
			memmove(path, &buf[i + step + 1], path_len_b);
			
			flg = way(d->value[0], path);
			replace(&buf[i + step + 1], path, path_len_b);
		    }
		}
	    }
	}
    }
    
    return flg;
}
