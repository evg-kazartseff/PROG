#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>

int colch(char str[], char ch);
int slen(char str[]);
int schr(char str[], char ch);
int stok(char *str, char *delim, char **ptr);
int suntok(char str[], char delim, char *ptr[], int cnt);
int sequal(char s1[], char s2[]);
int sstr(char txt[], char p[]);
int drv_in_str(char str[]);
void right(char str[], int len_str, int len);
char toLowCase(char ch);
void copy(char s1[], char s2[]);
int sygdrive(char str[], int len_str);
void strcpy_c(char *src, char **dest, char c);

#endif
