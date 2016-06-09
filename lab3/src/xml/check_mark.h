#ifndef CHECK_MARK_H
#define CHECK_MARK_H

#include <string.h>
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include "token.h"

int len_befor_reject(char *src, char *reject);
int check_mark(char *buf);

#endif
