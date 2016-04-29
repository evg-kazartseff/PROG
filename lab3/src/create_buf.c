#include "create_buf.h"

int create_buf (char **buf)
{
    FILE *input;
    input = fopen("../cfg/cfg.xml", "r");
    if (input == NULL) {
	    printf ("Can't open input file!!\n");
	    return -1;
    }
    unsigned int N = 256, i = 0;   
    char* tmp = (char*) malloc(sizeof(char)*N);    
    while ((tmp [i] = fgetc(input)) != EOF)  {                
        if (++i >= N) {
            N = N * 2;
            tmp = (char*) realloc(tmp, sizeof(char)*N);        
        }   
    }
    fclose(input);
    tmp[i] = '\0';
    *buf = tmp;
    return 0;
}
