
/* ack -f --c |entr -c -s "gcc ./test.c; ./a.out" */

#include <stdio.h>

int main()
{
    // printf() displays the string inside quotation
    int test_a=1;
    int test_b=1;
    float test_float = 1.111;

    int* ptr_a;
    int* ptr_b;

    ptr_a = &test_a;
    ptr_b = &test_b;

    int test_array[] = {1,2,3,4,5};
    unsigned int u_int_test;

    printf("%p\n",test_array);
    printf("%p\n",&test_array);
    u_int_test = test_array[0];
    printf("%d\n", u_int_test);

    // if (test_a == test_b){
    //     printf("\nvalue is same");
    // }else{
    //     printf("\nvalue is not same");
    // }

    // if (ptr_a == ptr_b){
    //     printf("\nptr is same");
    // }else{
    //     printf("\nptr is not same");
    // }

    // if (*ptr_a == *ptr_b){
    //     printf("\nderef is same");
    // }else{
    //     printf("\nderef is not same");
    // }

    printf("start\n\n");

    printf("%d", (int)test_float);

    printf("\n\n\n");

   return 0;
}
