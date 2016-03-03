#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "process.h"
#include "check.h"
#include "func.h"

#define str_size 1025
#define ptr_size 1025
int main()
{
    char str[str_size];
    char delim;
    int *ptr[ptr_size];
    input(str, &delim);
    process(str, delim, ptr);
    return 0;
}
