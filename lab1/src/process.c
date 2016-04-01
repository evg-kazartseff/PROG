#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "check_func.h"

#define DEBUG 0
#define way_size 260

void process(char str[], char delim)
{
    int size = colch(str, delim);
    int *ptr[size + 1][256];
    int margin[size + 1];
    int len_str = slen(str);

    int i;

	

    margin[0] = stok(str, delim, ptr[0]);
#if (DEBUG == 1)
    printf("ways = %d\n", margin[0]);
    for (i = 0; i < margin[0]; i++) {
        printf("adr_ptr [0][%d] = %d\n", i, ptr[0][i]);
        printf("way [0][%d] = %s\n", i, ptr[0][i]);
    }
#endif
	int mass_err[margin[0]];
	for (i = 0; i <= margin[0]; i++) {
		mass_err[i] = 0;
	}
	
//check ways
    for (i = 0; i < margin[0]; i++) {
        int way_long = chk_strlong(ptr[0][i]);
        if (way_long > way_size) {
            printf("Warning! Excess path %d length!\nMAX_long:%d!\n", i+1,
                   way_size);
        }
        
        int flg_err_sym = chk_err_sym(ptr[0][i]);
        if (flg_err_sym != -1) {
			printf("Forbidden symbol! idx '%d' '%c' path %d\n",
               flg_err_sym+1,str[((ptr[0][i] - ptr[0][0]) * sizeof(int))+flg_err_sym], i+1);
            mass_err[i] = 1;
		}
    }

    char sl = '\\';

    int j, tmp = 1;

    for (i = 1; i <= margin[0]; i++) {
		if (mass_err[i-1] != 1) {
			margin[tmp] = stok(ptr[0][i - 1], sl, ptr[i]);
#if (DEBUG == 1)
			printf("margin-%d = %d\n", tmp, margin[tmp]);
			for (j = 0; j < margin[tmp]; j++) {
				printf("adr_ptr[%d][%d] = %d\n", i, j, ptr[i][j]);
				printf("margin [%d][%d] = %s\n", i, j, ptr[i][j]);
			}
#endif
			tmp++;
#if (DEBUG == 1)
			printf("\n");
#endif
		}
		else {
			ptr[i][0] = ptr[0][i-1];
			margin[tmp] = 1;
			tmp++;
		}
    }

    char cygdrive[] = "/cygdrive/$";
    int len_cdr = slen(cygdrive);
    for (i = 1; i <= margin[0]; i++) {
			for (j = 0; j < margin[i]; j++) {
				if (mass_err[i-1] != 1) {				
					int flg = sygdrive(ptr[i][j], len_str);
				}
				int k = i;
				int p = j;
				int before = (ptr[i][j] - ptr[1][0]) * sizeof(int);
				int now = slen(ptr[i][j]);
				int step = before + now + 1;
				if (p != (margin[i] - 1)) {
					p++;
					ptr[k][p] = &(str[step]);
#if (DEBUG == 1)
					printf("ptr [%d][%d] = %s\n", k, p, ptr[k][p]);
#endif
				} else if (k != margin[0]) {
					k = i + 1;
					p = 0;
					ptr[k][p] = &(str[step]);
#if (DEBUG == 1)
					printf("ptr [%d][%d] = %s\n", k, p, ptr[k][p]);
#endif
				}
#if (DEBUG == 1)
				printf("ptr[%d][%d]\n", i, j);
				printf("ptr [%d][%d] = %s\n", i, j, ptr[i][j]);
				printf("ptr [%d][%d] = %d\n", i, j, ptr[i][j]);
				printf("before %d\n", before);
				printf("now %d\n", now);
				printf("step %d\n", step);
				printf("cdrv [%d][%d] = %s\n", k, p, ptr[k][p]);
				printf("adrv [%d][%d] = %d\n", k, p, ptr[k][p]);
				printf("\n");
#endif
		}
        ptr[0][i - 1] = ptr[i][0];
    }


    for (i = 1; i <= margin[0]; i++) {
        suntok(str, '/', ptr[i], margin[i]);
    }
    suntok(str, delim, ptr[0], margin[0]);
#if (DEBUG == 1)
    for (int r = 0; r < len_str + len_cdr + len_cdr; r++) {
        if (str[r] == '\0') {
            printf(" ");
        }
        printf("%c", str[r]);
    }
    printf("\n");
#endif
}
