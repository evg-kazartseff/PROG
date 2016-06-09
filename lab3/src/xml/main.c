#include <stdio.h>
#include "create_buf.h"
#include <string.h>
#include "check_mark.h"
#include "working.h"

int main()
{
    int flg = 0;

    char *buf = NULL;
    flg = create_buf(&buf);
    if (flg == -1)
	return EXIT_FAILURE;
    printf("buf:\n%s\n",buf);
    
    flg = check_mark(buf);
    if (flg != 0) {
	return EXIT_FAILURE;
    }
    
    flg = working(buf);
    printf("buf:\n%s\n",buf);
}
