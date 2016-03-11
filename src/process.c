#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void process(char str[], char delim)
{
    int size = colch(str, delim);
    int *ptr[size][256];
    
    char cygdrive[] = "/cygdrive/";
    int len_cdr = slen(cygdrive);
    
    
    int i;

    int c = stok(str, delim, ptr[0]);
    printf("ways = %d\n", c);
    for (i = 0; i < c; i++) {
        printf("adr_ptr [0][%d] = %d\n", i, ptr[0][i]);
        printf("pstr [0][%d] = %s\n", i, ptr[0][i]);
    }
	
	int h = drv_in_str(ptr[0][0]);
	printf("drive idx %d\n",h);
	
    char sl = '\\';

    int tmp, j;
    for (i = 1; i <= c; i++) {
        tmp = stok(ptr[0][i - 1], sl, ptr[i]);
        printf("margin = %d\n", tmp);
        for (j = 0; j < tmp; j++) {
            printf("adr_ptr[%d][%d] = %d\n", i, j, ptr[i][j]);
            printf("pstr [%d][%d] = %s\n", i, j, ptr[i][j]);    
        }
        printf("\n");
    }
	
	
}
