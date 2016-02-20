#include "process.h"
#include <stdio.h>
#include <stdlib.h>

void process (char * str, char * delim)
{
	//разбиение на подстроки, запись подстрок в двумерный массив

        int cold = 0;
        int k = 0;
        while (str[k] != '\0') {
                if ((str[k] == delim) || (str[k+1] == '\0')) {
                        cold = cold + 1;
                }
                k = k + 1;
        }

        printf ("cold=%d\n",cold);

        char  mas[cold][261];
        int strok = 0;
        int stolb = 0;
        int tmpiter = 0;
        int i = 0;
        while (str[i] != '\0') {
                if ((str[i] == delim) || (str[i+1] == '\0')) {
                        for (tmpiter ; tmpiter < i; tmpiter++) {
                                mas[strok][stolb] = str[tmpiter];
                                stolb = stolb + 1;
                        }
                        mas [strok][stolb] = '\0';
                        tmpiter=i+1;
                        stolb = 0;
                        strok = strok + 1;
                }
                i = i + 1;
        }



        int q = 0;
        int w = 0;
        for (q  ; q < cold ; q++) {
                while (mas [q][w] != '\0') {
                        printf ("%c",mas[q][w]);
                        w = w + 1;
                }
                printf ("\n");
                w = 0;
        }
}
