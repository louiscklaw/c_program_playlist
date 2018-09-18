
/* gcc test.c  -o test.out */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("number of arguments %d\n" , argc);
    for (int i =0; i <argc; i+=1){
        printf("parameter %d => %s\n", i, argv[i]);
    }
    return EXIT_SUCCESS;
}
