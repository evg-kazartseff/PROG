#include "check.h"
#include <stdio.h>
#include <stdlib.h>

//превышение допустимой длины строки
int strlong(char str[], char delim)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }

    if (i > 1024) {
        printf("Excess path length!\n");
        return EXIT_FAILURE;
    }
}

