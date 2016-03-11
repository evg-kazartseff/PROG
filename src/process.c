#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void process(char str[], char delim)
{
	int size = colch(str, delim);
    int *ptr[size][256];
	
    int c;
    c = stok(str, delim, ptr[0]);
    
    printf("col podstrok = %d\n", c);
    int i;
    for (i = 0; i < c; i++) {
        printf("ptr [0][%d] = %d\n", i, ptr[0][i]);
        printf("pstr [0][%d] = %s\n", i, ptr[0][i]);
    }
    char sl = '\\';
    int z = stok(ptr[0][0], sl, ptr[1]);
    printf("col podstrok = %d\n", z);
    for (i = 0; i < z; i++) {
        printf("ptr[1][%d] = %d\n", i, ptr[1][i]);
        printf("pstr [1][%d] = %s\n", i, ptr[1][i]);
    }
    
    int x = stok(ptr[0][1], sl, ptr[2]);
    printf("col podstrok = %d\n", x);
    for (i = 0; i < x; i++) {
        printf("ptr[2][%d] = %d\n", i, ptr[2][i]);
        printf("pstr [2][%d] = %s\n", i, ptr[2][i]);
    }
}
