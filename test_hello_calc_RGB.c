
#include "hello_calc_RGB.c"
#include <stdio.h>
#include <assert.h>

void is_the_color_same(color_idx_t color1, color_idx_t color2){
    DUMP(color1.R);DUMP(color2.R);printf("\n");
    DUMP(color1.G);DUMP(color2.G);printf("\n");
    DUMP(color1.B);DUMP(color2.B);printf("\n");

    // assert(color1.R==color2.R);
    // assert(color1.G==color2.G);
    // assert(color1.B==color2.B);
    // printf("\ncolor is the same\n");
}

void is_the_int_array_same(uint8_t array1[], uint8_t array2[], uint8_t array_length){
    for (int i =0; i < array_length; i++){
        DUMP(array1[i]);DUMP(array2[i]);printf("\n");
        assert(array1[i] == array2[i]);
    }
    printf("array is the same\n");
}

void test_get_points(){
    printf("test_get_points\n");

    uint8_t expected_result1[3] = {4,6,8};
    uint8_t actual_result1[3];
    get_points(2,10,3,actual_result1);
    is_the_int_array_same(actual_result1, expected_result1, 3);


    uint8_t expected_result2[4]= {4,6,8,10};
    uint8_t actual_result2[4];
    get_points(2,12,4,actual_result2);
    is_the_int_array_same(actual_result2, expected_result2, 4);


    uint8_t expected_result3[3]={8,6,4};
    uint8_t actual_result3[3];
    get_points(10,2,3,actual_result3);
    is_the_int_array_same(actual_result3, expected_result3,3);

    uint8_t expected_result4[1]={127};
    uint8_t actual_result4[1];
    get_points(0,255,1,actual_result4);
    is_the_int_array_same(actual_result4, expected_result4,1);

}

void test_get_middle_color(){
    color_idx_t result_colors[1];
    color_idx_t result_color;

    get_middle_color(RED, GREEN,1, result_colors);
    result_color = result_colors[0];

    is_the_color_same(result_color, RED);

}

int main(int argc, char *argv[]){
    test_get_middle_color();
    test_get_points();
    puts("helloworld");
    return 0;
}
