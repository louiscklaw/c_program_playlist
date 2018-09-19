
#define get_array_length(x) sizeof(x)/sizeof(x[0])

#include <stdio.h>

int test_array[10]={0};
int* test_array_2d[3] = {test_array, test_array, test_array};

int test_array_real_2d[3][10]={
    0,1,2,3,4,5,6,7,8,9,
    9,8,7,6,5,4,3,2,1,0,
    0,1,2,3,4,5,6,7,8,9
};

int main(int argc, char *argv[]);

int main(int argc, char *argv[]){

    // charge up array
    for (int i=0; i<get_array_length(test_array);i+=1){ test_array[i]=i; }

    // for (int i=0; i<10;i+=1) {printf("%d",test_array[i]);}

    // for (int i=0; i<3; i+=1){
    //     printf("%p", test_array_2d[i]);
    //     for (int j=0; j<10;j+=1){
    //         printf("%d\n",test_array_2d[i][j]);
    //     }
    // }

    int (*p)[10] = test_array_real_2d;
    for (int i=0; i< 3;i+=1){
        printf("%p,", p[i]);
        printf("%d", *(p[i]+2));
        printf("\n");
    }


    puts("helloworld");
    return 0;
}
