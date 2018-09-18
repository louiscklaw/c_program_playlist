
/* ack -f --c |entr -c -s "gcc ./test.c; ./a.out" */

#include <stdio.h>
#include <string.h>

const unsigned int BIT0 = 30;
const unsigned int BIT1 = 60;

int main()
{
    int white_test_pattern_length=0;

    unsigned int white_testbit[24]={
        BIT1, BIT1, BIT1, BIT1, BIT1, BIT1, BIT1, BIT1,
        BIT1, BIT1, BIT1, BIT1, BIT1, BIT1, BIT1, BIT1,
        BIT1, BIT1, BIT1, BIT1, BIT1, BIT1, BIT1, BIT1,
        };
    unsigned int test_pattern[6]={
        BIT1,BIT0,BIT1,BIT1,BIT0,BIT0
    };

    unsigned int test_0_pattern[]={BIT0};
    unsigned int test_1_pattern[]={BIT1};
    unsigned int test_0_50_us[40] = {0};

    unsigned int test_RET_pattern[42]={0};
    test_RET_pattern[41] = BIT1;

    unsigned int white_test_pattern[66];
    memcpy(white_test_pattern, white_testbit, sizeof(white_test_pattern));
    memcpy(white_test_pattern+24, test_0_50_us, sizeof(test_RET_pattern));

    for (int i =0; i<66; i+=1){
        printf("%d=>%d\n", i, white_test_pattern[i]);
    }

    // printf("%u",white_test_pattern[0]);

    printf("\n\n\n");

   return 0;
}
