#include "check.h"
#include <stdio.h>
#include <stdlib.h>
int check(char *str, char *delim)
{
//превышение допустимой длины строки
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }

    if (i > 1024) {
        printf("Excess path length!\n");
        return EXIT_FAILURE;
    }
}
