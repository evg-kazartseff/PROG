#include "check_func.h"
#include "strings.h"
#include <stdio.h>

//превышение допустимой длины строки
int chk_strlong(char str[])
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

//правильность разделителя
int chk_delim(char delim)
{
    char mas[] = { '+', '*', '#' };
    int flg = schr(mas, delim);
    return flg;
}

//проверка на запрещённые символы
int chk_err_sym(char str[])
{
    char err_sym[] =
        { '?', '<', ' ', '>', '|', '"', '@', ',', ';', '$', '%', '^', '&', '(',
')', '\0' };
    int len = slen(err_sym);
    int flg = -1;
    for (int i = 0; i < len; i++) {
        flg = schr(str, err_sym[i]);
        if (flg != -1) {
            break;
        }
    }
    int len_str = slen(str);
    for (int j = 0; j < len_str; j++) {
        if (((str[j] == '\\') && (str[j + 1] == '\\'))
            || ((str[j] == '/') && (str[j + 1] == '/'))) {
            flg = j;
        }
    }
    return flg;
}

//два разделителя подряд
int chk_two_delim(char str[], char delim)
{
    int flg = -1;
    int len_str = slen(str);
    for (int j = 0; j < len_str; j++) {
        if ((str[j] == delim) && (str[j + 1] == delim)) {
            flg = j;
        }
    }
    return flg;
}

//нет пути после делителя
int chk_null_after_delim(char str[], char delim)
{
    int flg = -1;
    int len_str = slen(str);
    for (int j = 0; j <= len_str+3; j++) {
        if ((str[j] == delim) && (str[j + 2] == '\0')) {
            flg = j;
        }
    }
    return flg;
}
