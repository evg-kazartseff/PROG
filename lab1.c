#include <stdio.h>
#include <stdlib.h>

void input (char * str, char * delim);
void process (char * str, char * delim);
void check (char * str, char * delim);

int main ()
{
	char str[261];
	char delim;
	input (str, &delim);
	check (str, delim);
	process (str, delim);
	return 0;
}

void input (char * str, char * delim)
{
	printf ("Input delim: ");
	scanf ("%c%*c",delim);
	printf ("Input paths: ");
	fgets (str,261,stdin);
}

void check (char * str, char * delim)
{
//превышение допустимой длины пути
        int i=0;
        while (str[i]!='\0') {
                i = i + 1;
        }

	if (i > 261) {
		printf ("Excess path length!\n");
		return EXIT_FAILURE;
	}
}


void process (char * str, char * delim)
{

}
