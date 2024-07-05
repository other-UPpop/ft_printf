#include <stdio.h>
#include "ft_printf.h" // ft_printfのヘッダーをインクルード

// テスト用マクロ
#define TEST(num, cmd) do { \
    printf("Test case %d:\n", num); \
    cmd; \
    printf("\n"); \
} while (0)

int run_tests() {
    TEST(1, {
        ft_printf("ft_printf: p22 %.0x\n", 100);
        printf("printf   : p22 %.0x\n", 100);
    });
    
    TEST(2, {
        ft_printf("ft_printf: %-15p\n", NULL);
        printf("printf   : %-15p\n", NULL);
    });
    
    TEST(3, {
        ft_printf("ft_printf: %-15p\n", NULL);
        printf("printf   : %-15p\n", NULL);
    });
    
    TEST(4, {
        ft_printf("ft_printf: %20.x\n", 0x1234abcdu);
        printf("printf   : %20.x\n", 0x1234abcdu);
    });
    
    TEST(5, {
        ft_printf("ft_printf: %20.0x\n", -0x1234abcdu);
        printf("printf   : %20.0x\n", -0x1234abcdu);
    });
    
    TEST(6, {
        ft_printf("ft_printf: %20.X\n", 0x1234abcdu);
        printf("printf   : %20.X\n", 0x1234abcdu);
    });
    
    TEST(7, {
        ft_printf("ft_printf: %20.0X\n", -0x1234abcdu);
        printf("printf   : %20.0X\n", -0x1234abcdu);
    });
    
    TEST(8, {
        ft_printf("ft_printf: %-163.23u%-68.0X\n", 3421138903u, 514939578u);
        printf("printf   : %-163.23u%-68.0X\n", 3421138903u, 514939578u);
    });
    
    TEST(9, {
        ft_printf("ft_printf: %-189.X%000130.137d%092.60d\n", 823761827u, -369802385, -444387222);
        printf("printf   : %-189.X%000130.137d%092.60d\n", 823761827u, -369802385, -444387222);
    });
    
    TEST(10, {
        ft_printf("ft_printf: %.x\n", 0xee);
        printf("printf   : %.x\n", 0xee);
    });
    
    TEST(11, {
        ft_printf("ft_printf: %.X\n", 0xee);
        printf("printf   : %.X\n", 0xee);
    });
    
    TEST(12, {
        ft_printf("ft_printf: %1.x\n", 0xee);
        printf("printf   : %1.x\n", 0xee);
    });
    
    TEST(13, {
        ft_printf("ft_printf: %1.X\n", 0xee);
        printf("printf   : %1.X\n", 0xee);
    });
    
    TEST(14, {
        ft_printf("ft_printf: %5.x\n", 0xee);
        printf("printf   : %5.x\n", 0xee);
    });
    
    TEST(15, {
        ft_printf("ft_printf: %5.X\n", 0xee);
        printf("printf   : %5.X\n", 0xee);
    });

    return 0;
}

int main() {
    run_tests();
    return 0;
}
