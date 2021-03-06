#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "process.h"
#include "check.h"
#include "output.h"

#define str_size 2048

int main()
{
    char str[str_size];
    char delim;
    input(str, &delim);
    check(str, delim);
    process(str, delim);
    output(str);
    return 0;
}
