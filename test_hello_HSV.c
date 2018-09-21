
#define get_array_length(x) sizeof(x)/sizeof(x[0])

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hello_HSV.c"

int assert_RGB(double RGB_d[], double RGB_expected_d[]){
    for (int i=0; i<3;i++){
        if(abs(RGB_d[0]-RGB_expected_d[0])>=0.001){
            return 0;
        }
    }
    return 1;
}

void setup_answer(double dh, double ds, double dv, double darray[]){
    darray[0]=dh;
    darray[1]=ds;
    darray[2]=dv;
}

void test_RGB_TO_HSV(int q_r, int q_g, int q_b, double d_expected[]){
    double actual_a[3];
    rgbToHsv(q_r,q_g,q_b, actual_a);
    assert(assert_RGB(actual_a, d_expected));
}

int main(int argc, char *argv[]){
    double actual_a[3], expected_a[3];
    int q_r,q_g,q_b;

    // Question 1
    q_r=82;q_g=0;q_b=87;
    setup_answer(296.551724,1.000000,0.341176, expected_a);
    test_RGB_TO_HSV(q_r,q_g,q_b, expected_a);

    q_r=255;q_g=0;q_b=0;
    setup_answer(0,1,1, expected_a);
    test_RGB_TO_HSV(q_r,q_g,q_b, expected_a);

    q_r=0;q_g=255;q_b=0;
    setup_answer(120,1,1, expected_a);
    test_RGB_TO_HSV(q_r,q_g,q_b, expected_a);

    q_r=0;q_g=0;q_b=255;
    setup_answer(240,1,1, expected_a);
    test_RGB_TO_HSV(q_r,q_g,q_b, expected_a);

    q_r=255;q_g=255;q_b=0;
    setup_answer(60,1,1, expected_a);
    test_RGB_TO_HSV(q_r,q_g,q_b, expected_a);

    printf("\ntest done\n");

    return 0;
}
