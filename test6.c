#include <stdio.h>
#include "ft_printf.h"


void run_test()
{
printf("printf    :%+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
ft_printf("ft_printf :%+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

}

int main(void)
{
    run_test();
    return (0);
}
