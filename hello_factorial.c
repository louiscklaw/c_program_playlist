
/* gcc test.c  -o test.out */

#include <stdio.h>

unsigned int factorial(unsigned int i) {

   if(i <= 1) {
      return 1;
   }
   return i * factorial(i - 1);
}

int  main() {
   int i = 20;
   printf("size of integer %ld\n", sizeof(i));
   printf("Factorial of %d is %u\n", i, factorial(i));
   return 0;
}
