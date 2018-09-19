
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[]){
    uint64_t test_value_small = 1U;
    uint64_t test_value_max_255 = 255U;
    uint64_t test_value_max_256 = 256U;
    uint64_t test_value_large = 512U;

    uint8_t test_uint8_small = (uint8_t)test_value_small;
    uint8_t test_uint8_large = (uint8_t)test_value_large;

    printf("%u\n", test_uint8_small);
    printf("%u\n", test_value_max_255);
    printf("%u\n", test_value_max_256);
    printf("%u\n", test_uint8_large);
    return 0;
}
