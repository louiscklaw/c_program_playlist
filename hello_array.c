
#define get_array_length(x) sizeof(x)/sizeof(x[0])

#include <stdio.h>
#include <stdint.h>
#include <string.h>


void test_function_1(uint8_t * input_array, int array_length){
    for (int i=0; i< array_length;i+=1){
        printf("%d", input_array[i]);

    }
    printf("\n");
}

void test_function(uint8_t (*p)[8]){
    // printf("%p\n", p);
    // printf("%p\n", &p[0][0]);
    // printf("%p\n", &p[1][0]);
    for (int i=0;i<3;i+=1){
        test_function_1(p[i], 8);
    }
}

void flatten_array(uint8_t (*p)[8], int num_row, uint8_t *output_array){
    for(int i=0; i < num_row; i+=1){
        for(int j=0; j<8;j+=1){
            int pos = i*8+j;
            output_array[pos] = p[i][j];
        }
    }
}

int main(int argc, char *argv[]);

int main(int argc, char *argv[]){

    uint8_t two_dimenions_array[3][8]={
        1,2,3,4,5,6,7,8,
        8,7,6,5,4,3,2,1,
        1,2,3,4,5,6,7,8,
    };
    uint8_t result_array[24]={1};


    // for(int i=0; i < get_array_length(two_dimenions_array); i+=1){
    //     for(int j =0; j < get_array_length(two_dimenions_array[i]); j+=1){
    //         printf("%d,%d=> value %d, ", i,j, two_dimenions_array[i][j]);
    //         printf("%d,%d=> address %p", i,j , &two_dimenions_array[i]);
    //         printf("\n");
    //     }
    // }

    // test_function(two_dimenions_array);
    flatten_array(two_dimenions_array,3, result_array);
    for(int i=0;i<24;i+=1){
        printf("%d,", result_array[i]);
    }

    puts("helloworld");
    return 0;
}
