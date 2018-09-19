
#include <stdio.h>

int md_array[2][3]={
    1,2,3,
    4,5,6
};

int (*p)[3] = md_array;


int main(int argc, char *argv[]){

    printf("%p\n", p[0]);
    printf("%p\n", p[1]);
    printf("%p\n", p[2]);
    return 0;
}
