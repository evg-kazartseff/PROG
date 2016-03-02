#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "input.h"
#include "process.h"
#include "check.h"
#include "func.h"

int main ()
{
	char str[1025];
	char delim;
	int ptr[1025];
	input (str, &delim);
	process (str, delim, ptr);
	return 0;
}


