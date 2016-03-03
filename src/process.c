#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void process(char str[], char delim, int *ptr[])
{
    int c;
    c = stok(str, delim, ptr);
    printf("col podstrok = %d\n", c);
    int i;
    for (i = 0; i < c; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
        printf("podstroka %d = %s\n", i, ptr[i]);
    }
    printf("podstroka %d = %c\n", c, ptr[c]);
}
