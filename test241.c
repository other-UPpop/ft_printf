#include <stdio.h>
#include "ft_printf.h"

int main()
{

ft_printf("ft_printf :%-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
printf("   printf :%-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

 ft_printf("ft_printf :%-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
   printf("   printf :%-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x, %-100.x\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
return (0);
}



