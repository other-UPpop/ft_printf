#include <stdio.h>
#include "ft_printf.h"

int main()
{
ft_printf("ft_printf :%0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
printf("   printf :%0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X, %0#X\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
}
