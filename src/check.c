#include "check.h"
#include <stdio.h>
#include <stdlib.h>

void check(char str[], char delim)
{
    int two_delim_flg = chk_two_delim(str, delim);
    if (two_delim_flg != -1) {
        printf("Warning! Two delim! '%c%c' idx '%d %d'\n", str[two_delim_flg],
               str[two_delim_flg + 1], two_delim_flg, two_delim_flg + 1);
    }

    int null_after_del = chk_null_after_delim(str, delim);
    if (null_after_del != -1) {
        printf("Warning! No path, after delim! \n");
    }

    int del_flg = chk_delim(delim);
    if (del_flg == -1) {
        printf("Incorrect value delim! '%c' \n", delim);
        exit(EXIT_FAILURE);
    }

    int str_long = chk_strlong(str);
    if (str_long > 1024) {
        printf("Excess path length!\nMAX_long:1024!\n");
        exit(EXIT_FAILURE);
    }

    int err_sym_flg = chk_err_sym(str);
    if (err_sym_flg != -1) {
        printf("Forbidden symbol! '%c' idx '%d'\n", str[err_sym_flg],
               err_sym_flg);
        exit(EXIT_FAILURE);
    }
}
