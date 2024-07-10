#include <stdio.h>
#include "ft_printf.h"

int main ()
{
ft_printf("%0+d, %0+d, %0+d, %0+d, %0+d, %0+d, %0+d, %0+d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
printf("%0+d, %0+d, %0+d, %0+d, %0+d, %0+d, %0+d, %0+d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
return (0);
}
