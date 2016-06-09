#include "way.h"

int way(char delim, char *path)
{
    char *str = calloc(slen(path) + 256, sizeof(char));
    strcpy(str, path);
    check(str, delim);
    process(str, delim);
    output(path, str);
    free(str);
    return 0;
}
