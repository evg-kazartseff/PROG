#include "create_buf.h"

int create_buf (char **buf)
{
    FILE *input;
    input = fopen("../cfg/cfg.xml", "rw");
    if (input == NULL) {
	    printf ("Can't open input file!!\n");
	    return -1;
    }
    unsigned int N = 1024, i = 0;   
    char* tmp = (char*) malloc(sizeof(char)*N);
    if (tmp == NULL) {
	printf("error when allocating memory!\n");
	return -1;
    }
    while ((tmp [i] = fgetc(input)) != EOF)  {                
        if (++i >= N) {
            N = N * 2;
            tmp = (char*)realloc(tmp, sizeof(char)*N);
	    if (tmp == NULL) {
		printf("error when allocating memory!\n");
		return -1;
	    }
        }   
    }
    fclose(input);
    tmp[i] = '\0';
    *buf = tmp;
    return 0;
}
