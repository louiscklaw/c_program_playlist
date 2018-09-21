
/* gcc test.c  -o test.out */

#define PRINT_COMPARE 1

#include <stdio.h>
#include "hello_HSV_RGB.c"
#include <assert.h>

void setup_test_answer(int i_r, int i_g, int i_b, int rgb[]){
    rgb[0]=i_r;
    rgb[1]=i_g;
    rgb[2]=i_b;
}

int compare_answer(int rgb_1[], int rgb_2[]){
    if(PRINT_COMPARE){
        for(int i=0;i<3;i++){
            printf("\nrgb_1=>%d, rgb_2=>%d", rgb_1[i], rgb_2[i]);
        }
    }

    return rgb_1[0]==rgb_2[0]&&
    rgb_1[1]==rgb_2[1]&&
    rgb_1[2]==rgb_2[2];
}

int main()
{
    int expected_rgb[3], actual_rgb[3];

    // Question 1
    printf("\nQuestion1");
    setup_test_answer(255,0,0, expected_rgb);
    HSVToRGB(0,1,1, actual_rgb);
    assert(compare_answer(expected_rgb, actual_rgb));

    printf("\nQuestion2");
    setup_test_answer(0,255,0,expected_rgb);
    HSVToRGB(120,1,1, actual_rgb);
    assert(compare_answer(expected_rgb, actual_rgb));

    printf("\nQuestion3");
    setup_test_answer(0,0,255,expected_rgb);
    HSVToRGB(240,1,1, actual_rgb);
    assert(compare_answer(expected_rgb, actual_rgb));

    printf("\nQuestion4");
    setup_test_answer(255,255,0,expected_rgb);
    HSVToRGB(60,1,1, actual_rgb);
    assert(compare_answer(expected_rgb, actual_rgb));


    printf("\ntest done\n");
    return 0;
}
