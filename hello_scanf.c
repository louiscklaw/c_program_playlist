
/* gcc test.c  -o test.out */

#include <stdio.h>

const char *HELLOWORLD = "helloconstant";

int main()
{
    // printf() displays the string inside quotation
    char str[100];
    int i;

    printf("Enter value:");
    scanf("%s %d", str, &i);

    printf("\n entered: %s %d \n", str, i);

    return 0;
}
