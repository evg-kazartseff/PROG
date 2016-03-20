#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void process(char str[], char delim)
{
    int size = colch(str, delim);
//    printf ("size = %d",size);
    int *ptr[size+1][256];
    int margin[size+1];
    int len_str = slen(str);
	
	int i;
	
    margin[0] = stok(str, delim, ptr[0]);
    printf("ways = %d\n", margin[0]);
    for (i = 0; i < margin[0]; i++) {
        printf("adr_ptr [0][%d] = %d\n", i, ptr[0][i]);
        printf("way [0][%d] = %s\n", i, ptr[0][i]);
    }
	
    char sl = '\\';

    int j, tmp = 1;
    
    for (i = 1; i <= margin[0]; i++) {
        margin[tmp] = stok(ptr[0][i - 1], sl, ptr[i]);
        printf("margin = %d\n", margin[tmp]);
        for (j = 0; j < margin[tmp]; j++) {
            printf("adr_ptr[%d][%d] = %d\n", i, j, ptr[i][j]);
            printf("margin [%d][%d] = %s\n", i, j, ptr[i][j]);    
        }
        tmp++;
        printf("\n");
    }
    
    char cygdrive[] = "/cygdrive/$";
    int len_cdr = slen(cygdrive);
    printf ("len_cdr %d\n",len_cdr);
	for (i = 1; i <= margin[0]; i++) {
		for (j = 0; j < margin[i]; j++) {
			int flg = sygdrive(ptr[i][j], len_str);
			if ((i != margin[0]) || (j != (margin[i] - 1))) {
				int k,p;
				if (((j+1) != margin[i]) && (i != margin[0]) ) {
					k = i;
					p = j+1;
				}
				else if (i != margin[0]) {
					k = i+1;
					p = 0;
				}
				int before = (ptr[i][j] - ptr[1][0])*sizeof(int);
				int now = slen(ptr[i][j]);
				int step = before + now +1;
				ptr[k][p] = &(str[step]);
				printf("ptr[%d][%d]\n",i,j);
				printf("ptr [%d][%d] = %s\n", i, j, ptr[i][j]);
				printf("ptr [%d][%d] = %d\n", i, j, ptr[i][j]);
				printf("before %d\n",before);
				printf("now %d\n",now);
				printf("step %d\n",step);
				printf("cdrv [%d][%d] = %s\n", k, p, ptr[k][p]);
				printf("adrv [%d][%d] = %d\n", k, p, ptr[k][p]);
				printf("\n");
			}
		}
	}
	
	printf("cdrv [1][0] = %s\n",ptr[1][0]);
	printf("adrv [1][0] = %d\n",ptr[1][0]);
	printf("cdrv [1][1] = %s\n",ptr[1][1]);
	printf("adrv [1][1] = %d\n",ptr[1][1]);
	printf("cdrv [1][2] = %s\n",ptr[1][2]);
	printf("cdrv [2][0] = %s\n",ptr[2][0]);
	printf("cdrv [2][1] = %s\n",ptr[2][1]);
	printf("cdrv [2][2] = %s\n",ptr[2][2]);
	printf("cdrv [3][0] = %s\n",ptr[3][0]);

	for ( i = 0; i <=margin[0]; i++) {
			suntok (str, '/', ptr[i], margin[i]);
	}
	//suntok (str, delim, ptr[0], margin[0]);
	
	for (int r = 0; r < len_str + len_cdr + len_cdr; r++) {	
		if (str[r] == '\0') {
				printf(" ");
		}
		printf ("%c",str[r]);
	}
	printf("\n");
}
