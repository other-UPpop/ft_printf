#include <stdio.h>
#include "ft_printf.h"

void run_test()
{
    printf("%%\n");
    ft_printf("%%\n");
		printf(" %%\n");
		ft_printf(" %%\n");
		printf("%%c\n");
		ft_printf("%%c\n");
		printf("%%%%%%\n");
		ft_printf("%%%%%%\n");
		printf("%%%c\n", 'x');
		ft_printf("%%%c\n", 'x');
}

int main(void)
{
    run_test();
    return (0);
}
