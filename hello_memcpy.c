
/* gcc test.c  -o test.out */

#include <stdio.h>
#include <string.h>

const char *HELLOWORLD = "helloconstant";

int a1[4]={1,2,3,4};
int * pa1 = &a1;

int a2[4]={4,5,6,7};

int a3[6];
int a_result[6];

void hello_memcpy(int* input_a1, int* input_a2){
    int size_of_input_a1 = sizeof(input_a1);
    int size_of_input_a2 = sizeof(input_a2);

    memcpy(a3, input_a1, sizeof(input_a1));
    memcpy(a3+size_of_input_a2, input_a2, sizeof(input_a2));

}

int get_array_length(int *input_a){
    int test_a[] = {1,2,3,4};
    int length = sizeof(test_a)/sizeof(test_a[0]);
    int length1 = sizeof(**input_a);
    // /sizeof(test_a[0]);
    printf("haha0 %ld\n", (long int)input_a);
    printf("haha1 %ld\n", (long int)test_a);
    printf("haha2 %ld\n", (int)sizeof(input_a));
    printf("haha3 %ld\n", (long int)sizeof(test_a));
    printf("haha4 %d\n", test_a[0]);
    printf("result length %d\n",length);
    printf("result length1 %d\n",length1);
    return length;
}

int main()
{
    // printf() displays the string inside quotation
    hello_memcpy(a1,a2);

    printf("result\n");
    printf("expression a1 =>%ld\n", (long int)a1);
    printf("expression &a1 =>%ld\n", (long int)&pa1);
    printf("expression &a1[0] =>%ld\n", (long int)&a1[0]);
    printf("expression &a1[1] =>%ld\n", (long int)&a1[1]);
    printf("expression *&a1 =>%ld\n", (long int)*&a1);
    printf("expression *&a1[0] =>%ld\n", (long int)*&a1[0]);
    printf("expression *&a1[1] =>%ld\n", (long int)*&a1[1]);

    printf("array length %d\n", get_array_length(&a1));
    // for (int i=0;i<get_array_length(a3);i+=1){
    //     printf("%d",a3[i]);
    // }
    printf("\n");

    return 0;
}
