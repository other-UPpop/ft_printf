#include <stdio.h>
#include "ft_printf.h"

// 自作の ft_printf 関数のプロトタイプを定義
int ft_printf(const char *format, ...);

void run_c_tests() {
    // テストケース
    printf("Test 1:\n");
    printf("ft_printf : [");
    ft_printf("%c", '0');
    printf("]\n");
    printf("printf    : [");
    printf("%c", '0');
    printf("]\n");

    printf("\nTest 2:\n");
    printf("ft_printf : [");
    ft_printf(" %c ", '0');
    printf("]\n");
    printf("printf    : [");
    printf(" %c ", '0');
    printf("]\n");

    printf("\nTest 3:\n");
    printf("ft_printf : [");
    ft_printf(" %c", '0' - 256);
    printf("]\n");
    printf("printf    : [");
    printf(" %c", '0' - 256);
    printf("]\n");

    printf("\nTest 4:\n");
    printf("ft_printf : [");
    ft_printf("%c ", '0' + 256);
    printf("]\n");
    printf("printf    : [");
    printf("%c ", '0' + 256);
    printf("]\n");

    printf("\nTest 5:\n");
    printf("ft_printf : [");
    ft_printf(" %c %c %c ", '0', 0, '1');
    printf("]\n");
    printf("printf    : [");
    printf(" %c %c %c ", '0', 0, '1');
    printf("]\n");

    printf("\nTest 6:\n");
    printf("ft_printf : [");
    ft_printf(" %c %c %c ", ' ', ' ', ' ');
    printf("]\n");
    printf("printf    : [");
    printf(" %c %c %c ", ' ', ' ', ' ');
    printf("]\n");

    printf("\nTest 7:\n");
    printf("ft_printf : [");
    ft_printf(" %c %c %c ", '1', '2', '3');
    printf("]\n");
    printf("printf    : [");
    printf(" %c %c %c ", '1', '2', '3');
    printf("]\n");

    printf("\nTest 8:\n");
    printf("ft_printf : [");
    ft_printf(" %c %c %c ", '2', '1', 0);
    printf("]\n");
    printf("printf    : [");
    printf(" %c %c %c ", '2', '1', 0);
    printf("]\n");

    printf("\nTest 9:\n");
    printf("ft_printf : [");
    ft_printf(" %c %c %c ", 0, '1', '2');
    printf("]\n");
    printf("printf    : [");
    printf(" %c %c %c ", 0, '1', '2');
    printf("]\n");
}

int main() {
    run_c_tests();
    return 0;
    }
