#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void process(char str[], char delim, int *ptr1[], int *ptr2[])
{
    int c;
    c = stok(str, delim, ptr1);
    
    
    
    printf("col podstrok = %d\n", c);
    int i;
    for (i = 0; i < c; i++) {
        printf("ptr[%d] = %d\n", i, ptr1[i]);
        printf("pstr %d = %s\n", i, ptr1[i]);
    }
    char sl = '\\';
    int z = stok(ptr1[0], sl, ptr2);
    printf("col podstrok = %d\n", z);
    for (i = 0; i < z; i++) {
        printf("ptr[%d] = %d\n", i, ptr2[i]);
        printf("pstr %d = %s\n", i, ptr2[i]);
    }
}
