
#define DUMP(varname) fprintf(stderr, "%s => %x, ", #varname, varname);
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define COLOR_IDX_MAX 255
#define COLOR_IDX_MID 128
#define COLOR_IDX_MIN 0

#include <stdio.h>
#include <stdint.h>

typedef struct { int R; int G; int B; } color_idx_t;

// color constants
color_idx_t RED={COLOR_IDX_MAX, COLOR_IDX_MIN, COLOR_IDX_MIN};
color_idx_t GREEN={COLOR_IDX_MIN, COLOR_IDX_MAX, COLOR_IDX_MIN};
color_idx_t BLUE = {COLOR_IDX_MIN, COLOR_IDX_MIN, COLOR_IDX_MAX};
color_idx_t WHITE = {COLOR_IDX_MAX, COLOR_IDX_MAX, COLOR_IDX_MAX};
color_idx_t BLACK = {COLOR_IDX_MIN, COLOR_IDX_MIN, COLOR_IDX_MIN};

void print_color_idx(color_idx_t input_color){
    printf("color index printer\n");
    printf("R:%d, G:%d, B:%d\n", input_color.R, input_color.G, input_color.B);
}

void print_color_array(color_idx_t input_colors[], uint8_t array_length){
    for(int i = 0; i<array_length; i++){
        print_color_idx(input_colors[i]);
    }
}

// start define the starting point
// end define the end point
// step define the number of division
// output[] array to output
// e.g. start 12, end 2, step 4, will output 4 6 8 10
void get_points(uint8_t start, uint8_t end, uint8_t step, uint8_t output[]){
    int diff = end-start;
    int divider = step+1;
    int diff_step = diff / divider;

    for(int i=0;i<step;i++){
        if (i==0){
            output[i] = start+diff_step;
        }else{
            output[i] = output[i-1] + diff_step;
        }
    }
}

// to calculate the color by define the start and the end color, divided by division
// use: get_middle_color(RED,GREEN,2, output_array), will calculate the YELLOW as 1 dimensional array into output_array
void get_middle_color(color_idx_t start, color_idx_t end, uint8_t division, color_idx_t colors_output[]){

    uint8_t color_step_R[division], color_step_G[division], color_step_B[division];

    get_points(start.R, end.R, division, color_step_R);
    get_points(start.G, end.G, division, color_step_G);
    get_points(start.B, end.B, division, color_step_B);

    for(int i =0; i < division; i++){
        colors_output[i].R = color_step_R[i];
        colors_output[i].G = color_step_G[i];
        colors_output[i].B = color_step_B[i];
    }



}
