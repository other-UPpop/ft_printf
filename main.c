#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int int_val = 42;
    unsigned int uint_val = 12345;
    char char_val = 'A';
    char *str_val = "Hello, World!";
    void *ptr_val = &int_val;
    int negative_val = -42;

    // Integer
    printf("Standard printf: %d\n", int_val);
    ft_printf("Custom printf  : %d\n", int_val);

    // Signed integer
    printf("Standard printf: %i\n", int_val);
    ft_printf("Custom printf  : %i\n", int_val);

    // Negative integer
    printf("Standard printf: %d\n", negative_val);
    ft_printf("Custom printf  : %d\n", negative_val);

    // Character
    printf("Standard printf: %c\n", char_val);
    ft_printf("Custom printf  : %c\n", char_val);

    // String
    printf("Standard printf: %s\n", str_val);
    ft_printf("Custom printf  : %s\n", str_val);

    // Pointer
    printf("Standard printf: %p\n", ptr_val);
    ft_printf("Custom printf  : %p\n", ptr_val);

    // Unsigned integer
    printf("Standard printf: %u\n", uint_val);
    ft_printf("Custom printf  : %u\n", uint_val);

    // Hexadecimal (lowercase)
    printf("Standard printf: %x\n", uint_val);
    ft_printf("Custom printf  : %x\n", uint_val);

    // Hexadecimal (uppercase)
    printf("Standard printf: %X\n", uint_val);
    ft_printf("Custom printf  : %X\n", uint_val);

    // Percent sign
    printf("Standard printf: %%\n");
    ft_printf("Custom printf  : %%\n");

    // Flags
    printf("Flags:\n");
    printf("Standard printf: %+d\n", int_val);
    ft_printf("Custom printf  : %+d\n", int_val);

    printf("Standard printf: % d\n", int_val);
    ft_printf("Custom printf  : % d\n", int_val);

    printf("Standard printf: %#x\n", uint_val);
    ft_printf("Custom printf  : %#x\n", uint_val);

    printf("Standard printf: %#X\n", uint_val);
    ft_printf("Custom printf  : %#X\n", uint_val);

    printf("Standard printf: %0d\n", int_val);
    ft_printf("Custom printf  : %0d\n", int_val);

    printf("Standard printf: %-d\n", int_val);
    ft_printf("Custom printf  : %-d\n", int_val);

    // Width
    printf("Width:\n");
    printf("Standard printf: %10d\n", int_val);
    ft_printf("Custom printf  : %10d\n", int_val);

    printf("Standard printf: %-10d\n", int_val);
    ft_printf("Custom printf  : %-10d\n", int_val);

    // Precision
    printf("Precision:\n");
    printf("Standard printf: %.5d\n", int_val);
    ft_printf("Custom printf  : %.5d\n", int_val);

    printf("Standard printf: %.5s\n", str_val);
    ft_printf("Custom printf  : %.5s\n", str_val);

    // Width and Precision
    printf("Width and Precision:\n");
    printf("Standard printf: %10.5d\n", int_val);
    ft_printf("Custom printf  : %10.5d\n", int_val);

    printf("Standard printf: %10.5s\n", str_val);
    ft_printf("Custom printf  : %10.5s\n", str_val);

    // Combination of flags, width, and precision
    printf("Combination:\n");
    printf("Standard printf: %-+10.5d\n", int_val);
    ft_printf("Custom printf  : %-+10.5d\n", int_val);

    printf("Standard printf: %0+10d\n", int_val);
    ft_printf("Custom printf  : %0+10d\n", int_val);

    return 0;
}
