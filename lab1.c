#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "input.h"
#include "process.h"
#include "check.h"

int main ()
{
	char str[1025];
	char delim;
	input (str, &delim);
	check (str, delim);
	process (str, delim);
	return 0;
}


