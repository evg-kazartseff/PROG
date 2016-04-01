#include "check.h"
#include <stdio.h>
#include <stdlib.h>
#include "check_func.h"

#define str_size 1024

void check(char str[], char delim)
{
//убирает пробел перед строкой
    while (str[0] == ' ') {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = str[i + 1];
        }
    }

    int two_delim_flg = chk_two_delim(str, delim);
    if (two_delim_flg != -1) {
        printf("Warning! Two delim! '%c%c' idx '%d %d'\n", str[two_delim_flg],
               str[two_delim_flg + 1], two_delim_flg, two_delim_flg + 1);
    }

    int str_long = chk_strlong(str);
    if (str_long > str_size) {
        printf("Excess path length!\nMAX_long:%d!\n", str_size);
        exit(EXIT_FAILURE);
    }
}
