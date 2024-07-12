#include <stdio.h>
#include "ft_printf.h"

int main()
{

ft_printf("ft_printf :%-100.d, %-100.d, %-100.d, %-100.d, %-100.d, %-100.d, %-100.d, %-100.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
printf("   printf :%-100.d, %-100.d, %-100.d, %-100.d, %-100.d, %-100.d, %-100.d, %-100.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

return (0);
}



