
/* gcc test.c  -o test.out */

#include <stdio.h>


int main()
{
    int i = 1;
    int *pi = &i;
    int **ppi = &pi;

    printf("result \n");
    printf("i=> %d\n", i);
    printf("pi=>%p\n", pi);
    printf("ppi=>%p\n", ppi);

    printf("*ppi=>%p\n", *ppi);
    printf("**ppi=>%d\n", *pi);
    printf("*pi=>%d\n", *pi);

    return 0;
}
