#ifndef TOKEN_H
#define TOKEN_H

#include <string.h>
#include <stdlib.h>

struct tok {
	int id;
	char *value;
};

struct tok *token_create(int i, char *data);

#endif
