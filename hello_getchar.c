
/* gcc test.c  -o test.out */

#include <stdio.h>

const char *HELLOWORLD = "helloconstant";

int main()
{
    char c;
    // printf() displays the string inside quotation
    printf("get char");
    c = getchar();

    printf("put char");
    putchar(c);
    return 0;
}
