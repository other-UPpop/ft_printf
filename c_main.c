#include <stdio.h>
#include "ft_printf.h" // ft_printfのヘッダーをインクルード

int run_c_tests() {
    // テストケース1
    printf("Test case 1:\n");
    ft_printf("ft_printf: '%c'\n", '0');
    printf("printf   : '%c'\n\n", '0');
    
    // テストケース2
    printf("Test case 2:\n");
    ft_printf("ft_printf: ' %c '\n", '0');
    printf("printf   : ' %c '\n\n", '0');
    
    // テストケース3
    printf("Test case 3:\n");
    ft_printf("ft_printf: ' %c'\n", '0' - 256);
    printf("printf   : ' %c'\n\n", '0' - 256);
    
    // テストケース4
    printf("Test case 4:\n");
    ft_printf("ft_printf: '%c '\n", '0' + 256);
    printf("printf   : '%c '\n\n", '0' + 256);
    
    // テストケース5
    printf("Test case 5:\n");
    ft_printf("ft_printf: ' %c %c %c '\n", '0', 0, '1');
    printf("printf   : ' %c %c %c '\n\n", '0', 0, '1');
    
    // テストケース6
    printf("Test case 6:\n");
    ft_printf("ft_printf: ' %c %c %c '\n", ' ', ' ', ' ');
    printf("printf   : ' %c %c %c '\n\n", ' ', ' ', ' ');
    
    // テストケース7
    printf("Test case 7:\n");
    ft_printf("ft_printf: ' %c %c %c '\n", '1', '2', '3');
    printf("printf   : ' %c %c %c '\n\n", '1', '2', '3');
    
    // テストケース8
    printf("Test case 8:\n");
    ft_printf("ft_printf: ' %c %c %c '\n", '2', '1', 0);
    printf("printf   : ' %c %c %c '\n\n", '2', '1', 0);
    
    // テストケース9
    printf("Test case 9:\n");
    ft_printf("ft_printf: ' %c %c %c '\n", 0, '1', '2');
    printf("printf   : ' %c %c %c '\n\n", 0, '1', '2');
    
    return 0;
}

int main() {
    run_c_tests();
    return 0;
}
