#include <stdio.h>
#include "ft_printf.h"

// 自作の ft_printf 関数のプロトタイプを定義
int ft_printf(const char *format, ...);

void run_u_zero_flag_tests() {
    unsigned int num1 = 123456789;
    unsigned int num2 = 0;
    unsigned int num3 = 4294967295U;  // 最大の unsigned int 値

    // 基本的な zero flag のテスト
    printf("Test 1 (printf)  : [%010u]\n", num1);  // Expected: [0123456789]
    ft_printf("Test 1 (ft_printf): [%010u]\n", num1);

    printf("Test 2 (printf)  : [%010u]\n", num2);  // Expected: [0000000000]
    ft_printf("Test 2 (ft_printf): [%010u]\n", num2);

    printf("Test 3 (printf)  : [%010u]\n", num3);  // Expected: [4294967295]
    ft_printf("Test 3 (ft_printf): [%010u]\n", num3);

    // ゼロフラッグと精度の組み合わせのテスト
    printf("Test 4 (printf)  : [%010.5u]\n", num1); // Expected: [  123456789]
    ft_printf("Test 4 (ft_printf): [%010.5u]\n", num1);

    printf("Test 5 (printf)  : [%010.10u]\n", num1); // Expected: [00123456789]
    ft_printf("Test 5 (ft_printf): [%010.10u]\n", num1);

    printf("Test 6 (printf)  : [%010.5u]\n", num2); // Expected: [     00000]
    ft_printf("Test 6 (ft_printf): [%010.5u]\n", num2);

    printf("Test 7 (printf)  : [%010.10u]\n", num2); // Expected: [0000000000]
    ft_printf("Test 7 (ft_printf): [%010.10u]\n", num2);

    printf("Test 8 (printf)  : [%010.5u]\n", num3); // Expected: [  4294967295]
    ft_printf("Test 8 (ft_printf): [%010.5u]\n", num3);

    printf("Test 9 (printf)  : [%010.10u]\n", num3); // Expected: [04294967295]
    ft_printf("Test 9 (ft_printf): [%010.10u]\n", num3);

    // ゼロフラッグとマイナスフラッグの組み合わせのテスト
    printf("Test 10 (printf) : [%-010u]\n", num1); // Expected: [123456789 ]
    ft_printf("Test 10 (ft_printf): [%-010u]\n", num1);

    printf("Test 11 (printf) : [%-010u]\n", num2); // Expected: [0         ]
    ft_printf("Test 11 (ft_printf): [%-010u]\n", num2);

    printf("Test 12 (printf) : [%-010u]\n", num3); // Expected: [4294967295]
    ft_printf("Test 12 (ft_printf): [%-010u]\n", num3);
}

int main() {
    run_u_zero_flag_tests();
    return 0;
}
