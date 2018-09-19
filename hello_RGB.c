
#define get_array_length(x) sizeof(x)/sizeof(x[0])

// on time for BIT1
#define BIT1 30

// on time for BIT0
#define BIT0 60

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>


// 0=R,1=G,2=B
uint8_t RGB_int[3]={0};

// MSB[0] -> LSB[7]
uint8_t RGB_binary[3][8]={0};


uint16_t b_testbit[24]={
    BIT0, BIT0, BIT0, BIT0, BIT0, BIT0, BIT0, BIT0,
    BIT0, BIT0, BIT0, BIT0, BIT0, BIT0, BIT0, BIT0,
    BIT0, BIT0, BIT0, BIT0, BIT0, BIT0, BIT0, BIT1,
    };

int main(int argc, char *argv[]);

void convert_channel_to_binary(int color_value, uint8_t* output_array)
{
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

void test_convert_channel_to_binary()
{
    uint8_t test_array[8];

    uint8_t array_result_10[]={0,0,0,0,1,0,1,0};
    convert_channel_to_binary(10, test_array);
    assert(memcmp(test_array, array_result_10, sizeof(test_array))==0);

    uint8_t array_result_64[]={0,1,0,0,0,0,0,0};
    convert_channel_to_binary(64, test_array);
    assert(memcmp(test_array, array_result_64, sizeof(test_array))==0);

    uint8_t array_result_128[]={1,0,0,0,0,0,0,0};
    convert_channel_to_binary(128, test_array);
    assert(memcmp(test_array, array_result_128, sizeof(test_array))==0);

    uint8_t array_result_255[]={1,1,1,1,1,1,1,1};
    convert_channel_to_binary(255, test_array);
    assert(memcmp(test_array, array_result_255, sizeof(test_array))==0);
}

void convert_binary_to_delay(uint8_t * binary_array, uint8_t * delay_array, uint8_t get_array_length, uint8_t delay1, uint8_t delay0)
{
    // uint8_t test_value = 0;
    // uint8_t * pdelay1 = &test_value;
    // uint8_t * pdelay0 = &test_value;

    for (int i =0;i<get_array_length; i+=1)
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

    convert_binary_to_delay(test_binary_array, expected_delay_array,get_array_length(test_binary_array), delay_1, delay_0);
    assert(sizeof(result_delay_array)==sizeof(expected_delay_array));
    assert(memcmp(result_delay_array, expected_delay_array, sizeof(result_delay_array)));
}


void convert_RGB_to_ws2812_duty(uint8_t* input_RGB_int, uint8_t (*output_RGB_binary)[8],int no_of_channel, int no_of_bit){
    uint8_t temp_array[8]={0};

    for(int i=0; i < no_of_channel; i+=1){
        convert_channel_to_binary(input_RGB_int[i], temp_array);

        // output_RGB_binary[i] => solved as 1-dimensional array
        convert_binary_to_delay(temp_array, output_RGB_binary[i], get_array_length(temp_array), BIT1, BIT0);
    }
}

void test_convert_RGB_to_ws2812_duty(){
    uint8_t test_RGB_1[3] = {0,1,2};
    uint8_t result_RGB_binary_1[3][8]={0};
    uint8_t expected_RGB_binary_1[3][8]={0};

    convert_RGB_to_ws2812_duty(test_RGB_1, result_RGB_binary_1,3,8);

    for (int i=0; i<get_array_length(result_RGB_binary_1);i+=1){
        // printf("%u,", result_RGB_binary_1[i][0]);
    }
    printf("\n");

}


void convert_to_RGB_array(uint8_t (*p)[8], uint8_t *output_array, int col, int row){
    for(int i=0; i<col; i+=1){
        for (int j=0; j< row; j+=1){
            int pos = 8*i+j;
            output_array[pos]=p[i][j];
        }
    }
}

void test_convert_to_RGB_array(){
    uint8_t test_input_array[3][8]={2};
    uint8_t test_output_array[24]={1};

    convert_to_RGB_array(test_input_array, test_output_array, 3, 8);
    for(int i=0;i<24;i+=1){
        printf("%d,",test_output_array[i]);
    }
}

int main(int argc, char *argv[])
{
    printf("test_convert_channel_to_binary()\n");
    test_convert_channel_to_binary();
    test_convert_binary_to_delay();
    test_convert_RGB_to_ws2812_duty();
    test_convert_to_RGB_array();

    printf("DONE");

    return 0;
}
