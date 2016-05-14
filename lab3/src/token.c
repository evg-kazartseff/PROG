#include <token.h>

struct tok *token_create(int i, char *data)
{
    struct tok *node;
    node = malloc(sizeof(*node));
    if (node != NULL) {
	node->id = i;
	node->value = calloc(strlen(data) + 1 , sizeof(char));
	strcpy(node->value, data);
	return node;
    }
    return NULL;
}
