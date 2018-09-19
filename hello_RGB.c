
#define array_length(x) sizeof(x)/sizeof(x[0])

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


void test_convert_digit_to_binary(){
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
}

void convert_binary_to_delay(uint8_t* binary_array, uint8_t* delay_array, uint8_t array_length, uint8_t delay1, uint8_t delay0)
{
    // uint8_t test_value = 0;
    // uint8_t * pdelay1 = &test_value;
    // uint8_t * pdelay0 = &test_value;

    for (int i =0;i<array_length; i+=1)
    {
    //     memcpy(delay_array+i, binary_array[i]==1?pdelay1:pdelay0,sizeof(uint8_t));
        if (binary_array[i]==1){
            delay_array[i] = delay1;
        }else{
            delay_array[i] = delay0;
        }
    }
}

void test_convert_binary_to_delay()
{
    uint8_t delay_1=12,delay_0=34;
    uint8_t test_binary_array[3]={1,0,1};
    uint8_t result_delay_array[3];
    uint8_t expected_delay_array[3]={delay_1, delay_0, delay_1};

    convert_binary_to_delay(test_binary_array, expected_delay_array,array_length(test_binary_array), delay_1, delay_0);
    assert(sizeof(result_delay_array)==sizeof(expected_delay_array));
    assert(memcmp(result_delay_array, expected_delay_array, sizeof(result_delay_array)));
}

void test_get_array_length(){
    uint8_t test_array[100];
    printf("arraylength %ld", array_length(test_array));
}

int main(int argc, char *argv[]){

    printf("test_convert_digit_to_binary()\n");
    test_convert_digit_to_binary();
    test_convert_binary_to_delay();

    test_get_array_length();

    printf("DONE");

    return 0;
}
