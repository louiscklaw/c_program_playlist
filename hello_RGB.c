
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>


int main(int argc, char *argv[]);

uint8_t rgb_bit_array[24];

void convert_digit_to_binary(int color_value, uint8_t* output_array){
    int j =0;
    for(int i = 128U; i >0; i = i >> 1){
        if (color_value >= i){
            output_array[j]=1;
            color_value -= i;
        }else{
            output_array[j]=0;
        }
        j+=1;
    }

}

int main(int argc, char *argv[]){
    uint8_t test_array[8];

    uint8_t array_result_10[]={0,0,0,0,1,0,1,0};
    convert_digit_to_binary(10, test_array);
    assert(memcmp(test_array, array_result_10, sizeof(test_array))==0);

    uint8_t array_result_64[]={0,1,0,0,0,0,0,0};
    convert_digit_to_binary(64, test_array);
    assert(memcmp(test_array, array_result_64, sizeof(test_array))==0);

    uint8_t array_result_128[]={1,0,0,0,0,0,0,0};
    convert_digit_to_binary(128, test_array);
    assert(memcmp(test_array, array_result_128, sizeof(test_array))==0);

    uint8_t array_result_255[]={1,1,1,1,1,1,1,1};
    convert_digit_to_binary(255, test_array);
    assert(memcmp(test_array, array_result_255, sizeof(test_array))==0);


    // for(int i =0; i<8;i+=1){
    //     printf("%d\n", test_array[i]);
    // }


    printf("DONE");

    return 0;
}
