
/* gcc test.c  -o test.out */

#include <stdio.h>
#include <stdint.h>

uint16_t testing_unsigned_short = 65535;
uint16_t * testing_uint_16_asterisk = &testing_unsigned_short;

int main()
{
    // printf() displays the string inside quotation
    printf("%u\n", testing_unsigned_short);
    printf("%u\n", (uint32_t)testing_unsigned_short);
    printf("%p\n",(uint16_t*)testing_uint_16_asterisk);
    printf("%p\n",(uint32_t*)testing_uint_16_asterisk);
    return 0;
}
