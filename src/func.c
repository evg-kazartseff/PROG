#include "func.h"


//количество символов в строке\подстроке
int slen(char str[])
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

//поиск символа в строке
int schr(char str[], char ch)
{
    int i, idx = -1;
    for (i = 0; (str[i] != '\0') && (str[i] != ch); i++);
    if (str[i] == ch) {
        idx = i;
    }
    return idx;
}

//разбиение строки на поля
int stok(char str[], char delim, int *ptr[])
{
    char *suf = str;
    ptr[0] = str;
    int i, j = 1;
    while ((i = schr(suf, delim)) >= 0) {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j;
}
