
/* gcc test.c  -o test.out */

#include <stdio.h>

const char *HELLOWORLD = "helloconstant";

int main()
{
    // printf() displays the string inside quotation
    for(int i=1;i<=3;i+=1){
        printf("%d",i);
    }
    return 0;
}
