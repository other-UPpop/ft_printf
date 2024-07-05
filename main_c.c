#include <stdio.h>
#include "ft_printf.h" // ft_printfのヘッダーをインクルード

// テスト用マクロ
#define TEST(num, cmd) do { \
    printf("Test case %d:\n", num); \
    cmd; \
    printf("\n"); \
} while (0)

int run_c_tests() {
    TEST(1, {
        ft_printf("ft_printf: '%-1c'\n", '0');
        printf("printf   : '%-1c'\n", '0');
    });
    
    TEST(2, {
        ft_printf("ft_printf: ' %-2c '\n", '0');
        printf("printf   : ' %-2c '\n", '0');
    });
    
    TEST(3, {
        ft_printf("ft_printf: ' %-3c'\n", '0' - 256);
        printf("printf   : ' %-3c'\n", '0' - 256);
    });
    
    TEST(4, {
        ft_printf("ft_printf: '%-4c '\n", '0' + 256);
        printf("printf   : '%-4c '\n", '0' + 256);
    });
    
    TEST(5, {
        ft_printf("ft_printf: ' %-1c %-2c %-3c '\n", '0', 0, '1');
        printf("printf   : ' %-1c %-2c %-3c '\n", '0', 0, '1');
    });
    
    TEST(6, {
        ft_printf("ft_printf: ' %-1c %-2c %-3c '\n", ' ', ' ', ' ');
        printf("printf   : ' %-1c %-2c %-3c '\n", ' ', ' ', ' ');
    });
    
    TEST(7, {
        ft_printf("ft_printf: ' %-1c %-2c %-3c '\n", '1', '2', '3');
        printf("printf   : ' %-1c %-2c %-3c '\n", '1', '2', '3');
    });
    
    TEST(8, {
        ft_printf("ft_printf: ' %-1c %-2c %-3c '\n", '2', '1', 0);
        printf("printf   : ' %-1c %-2c %-3c '\n", '2', '1', 0);
    });
    
    TEST(9, {
        ft_printf("ft_printf: ' %-1c %-2c %-3c '\n", 0, '1', '2');
        printf("printf   : ' %-1c %-2c %-3c '\n", 0, '1', '2');
    });
    
    return 0;
}

int main() {
    run_c_tests();
    return 0;
}
