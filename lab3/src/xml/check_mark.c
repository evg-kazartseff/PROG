#include "check_mark.h"

int len_befor_reject(char *src, char *reject)
{
    int len_s = strlen(src);
    int len_r = strlen(reject);
    int i, j;
    for (i = 0; i < len_s; i++) {
	for (j = 0; j < len_r; j++) {
	    if (src[i] == reject[j])
		return i;
	}
    }
    return -1;
}

int look_pattern(char *buf)
{
    int flg = 0;
    int len = strlen(buf);
    int i;
    for (i = 0; i < len; i++) {
	if ((buf[i] == '<') && (buf[i + 1] != '/')) {
	    char *ch_cl_tag = strchr(&buf[i], '>');
	    char *space = strchr(&buf[i], ' ');
	    if ((space != NULL) && ((long int)ch_cl_tag > (long int)space)) {
		int len_sp_pat = (long int)ch_cl_tag - (long int)space - 1;
		char *tmp = NULL;
		tmp = calloc(len_sp_pat + 1, sizeof(char));
		memmove(tmp, &space[1], len_sp_pat);
		char *str_tok = strtok(tmp, " ");
		while (str_tok != NULL) {
		    char *eq = strchr(str_tok, '=');
		    if (eq == NULL) {
			printf("incorrect paterrn\n");
			return -1;
		    }
		    else {
			if(eq[1] == '"') {
			    char *quotes = strchr(&eq[2], '"');
			    if (quotes == NULL) {
				printf("incorrect paterrn\n");
				return -1;
			    }
			}
		    }
		    str_tok = strtok(NULL, " ");
		}
		free(tmp);
	    }
	    
	    
	}
    }
    return flg;
}

int look_tagname(char *buf)
{
    int flg = 0;
    int len = strlen(buf);
    
    struct stack *s_tagnames;
    s_tagnames = stack_create();
    
    for (int i = 0; i < len; i++) {
	if (buf[i] == '<') {
	    if (buf[i + 1] != '/') {
		int l_rej = len_befor_reject(&buf[i + 1], "> \n\t");
		char *tag_name = NULL;
		tag_name = calloc(l_rej + 1, sizeof(char));
		memmove(tag_name, &buf[i + 1], l_rej);
		struct tok *name;
		name = token_create(3, tag_name);
		flg = stack_push(s_tagnames, name);
		free(tag_name);
	    }
	    else if (buf[i + 1] == '/') {
		int l_rej = len_befor_reject(&buf[i + 2], ">");
		char *tag_name = NULL;
		tag_name = calloc(l_rej + 1, sizeof(char));
		memmove(tag_name, &buf[i + 2], l_rej);
		struct tok *name;
		name = stack_pop(s_tagnames);
		flg = strcmp(name->value, tag_name);
		if (flg != 0) {
		    printf("incorrect tagname \"%s\" - \"%s\"\n", name->value, tag_name);
		    return -1;
		}
		free(tag_name);
	    }
	}
    }
    if (stack_size(s_tagnames) != 0) {
	printf("incorrect tagname\n");
	flg = -1;
    }
    stack_free(s_tagnames);
    return flg;
}

int look_open_close_tag(char *buf)
{
    int flg = 0;
    char **quotes = malloc(3 * sizeof(char*));
    quotes[0] = "<";
    quotes[1] = "</";
    quotes[2] = ">";
    
    struct stack *s_chtag;
    s_chtag = stack_create();
    
    int len = strlen(buf);
    
    for (int i = 0; i < len; i++) {
	if (buf[i] == quotes[0][0]) {
	    if (buf[i + 1] == quotes[1][1]) {
		struct tok *tag;
		tag = token_create(0, quotes[1]);
		flg = stack_push(s_chtag, tag);
	    }
	    else {
		struct tok *tag;
		tag = token_create(0, quotes[0]);
		flg = stack_push(s_chtag, tag);
	    }
	}
	else if (buf[i] == quotes[2][0]) {
	    struct tok *tag;
	    tag = stack_pop(s_chtag);
	    if (tag == NULL) {
		fprintf(stderr, "incorrect close tag\n");
		return -1;
	    }
	}
    }
    int size = stack_size(s_chtag);
    if (size != 0) {
	printf("incorrect tag\n");
	flg = -1;
    }
    stack_free(s_chtag);
    free(quotes);
    return flg;
}

int look_begin_end(char *buf)
{
    int i;
    
    for (i = 0; (buf[i] != '<') && (buf[i] != '\0'); i++) {
	if ((buf[i] != ' ') && (buf[i] != '\n') && (buf[i] != '\t'))
	    return -1;
    }
    int len = strlen(buf);
    for (i = len - 1; (buf[i] != '>') && (i != 0); i--) {
	if ((buf[i] != ' ') && (buf[i] != '\n') && (buf[i] != '\t'))
	    return -1;
    }
    return 0;
}

int check_mark(char *buf)
{
    int flg = 0;
    
    flg = look_begin_end(buf);
    if (flg == -1)
	return flg;
    
    flg = look_open_close_tag(buf);
    if (flg == -1)
	return flg;
    
    flg = look_tagname(buf);
    if (flg == -1)
	return flg;
	
    flg = look_pattern(buf);
    if (flg == -1)
	return flg;
    
    return flg;
}
