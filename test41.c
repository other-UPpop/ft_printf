#include <stdio.h>
#include "ft_printf.h"

int main()
{
 ft_printf("ft_printf :%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
 printf("   printf :%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
     return (0);
}
