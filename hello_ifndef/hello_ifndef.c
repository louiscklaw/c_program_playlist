
/* gcc test.c  -o test.out */

#include <stdio.h>
#include "hello_ifndef.h"
#include "hello_ifndef_again.h"

const char *HELLOWORLD = "helloconstant";

int main()
{
    // printf() displays the string inside quotation
    printf("%d", TEST_DEFINE);
    printf("%d", TEST_DEFINE_AGAIN);
    return 0;
}
