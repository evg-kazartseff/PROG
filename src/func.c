#include "func.h"

//число раз использования символа
int colch(char str[], char ch)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            j++;
        }
    }
    return j;
}

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

//посимвольное сравнивание строк
int sequal(char s1[], char s2[])
{
    int i, flg = 1;
    for (i = 0; flg && (s1[i] != '\0' || s2[i] != '\0'); i++) {
        if (s1[i] != s2[i])
            flg = 0;
    }
    return flg;
}

//поиск подстроки в строке
int sstr(char txt[], char p[])
{
    char *suf = txt;
    int len = slen(p);
    int i, pos = -1;
    while (((i = schr(suf, p[0])) >= 0) && (pos < 0)) {
        char tmp;
        suf = suf + i;
        tmp = suf[len];
        suf[len] = '\0';
        if (sequal(suf, p)) {   // посимвольное сравнение строк
            pos = suf - txt;    // разность указателей = индекс
        }
        suf[len] = tmp;
        suf++;
    }
    return pos;
}
//поиск имени диска $:
int drv_in_str(char str[])
{
	char drive[]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    char suf_drive = ':';
    int i = schr(str, suf_drive);
    if (i != -1) {
		int j = schr(drive, str[i-1]);
		if (j != -1) {
			return i-1;
		}
	}
	else {
		return i;
	} 
}
