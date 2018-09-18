
/* gcc test.c  -o test.out */

#include <stdio.h>

#define def_helloworld(x) printf("helloworld_define %s", x);

const char *HELLOWORLD = "helloconstant";

int main()
{
    // printf() displays the string inside quotation
    def_helloworld(HELLOWORLD);
    return 0;
}
