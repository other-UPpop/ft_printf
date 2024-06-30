#include <stdio.h>
#include "ft_printf.h"

// 自作の ft_printf 関数のプロトタイプを定義
int ft_printf(const char *format, ...);

void run_p_tests() {
    void *ptr1 = (void*)0x12345678;
    void *ptr2 = (void*)0x0;
    void *ptr3 = &ptr1;

    // 基本的な出力
    printf("Test 1 (printf)  : [%p]\n", ptr1);  // Expected: [0x12345678]
    ft_printf("Test 1 (ft_printf): [%p]\n", ptr1);

    // NULLポインタのテスト
    printf("Test 2 (printf)  : [%p]\n", ptr2);  // Expected: [(nil)]
    ft_printf("Test 2 (ft_printf): [%p]\n", ptr2);

    // 他の変数のアドレスのテスト
    printf("Test 3 (printf)  : [%p]\n", ptr3);  // Expected: [address of ptr1]
    ft_printf("Test 3 (ft_printf): [%p]\n", ptr3);

    // 幅のテスト
    printf("Test 4 (printf)  : [%20p]\n", ptr1);  // Expected: [       0x12345678]
    ft_printf("Test 4 (ft_printf): [%20p]\n", ptr1);

    printf("Test 5 (printf)  : [%-20p]\n", ptr1); // Expected: [0x12345678       ]
    ft_printf("Test 5 (ft_printf): [%-20p]\n", ptr1);

    // ゼロフラッグのテスト（通常無視されるが、確認のため）
    printf("Test 6 (printf)  : [%020p]\n", ptr1);  // Expected: [000000000012345678]
    ft_printf("Test 6 (ft_printf): [%020p]\n", ptr1);

    // プラスフラッグのテスト（無視されるべきだが確認のため）
    printf("Test 7 (printf)  : [%+p]\n", ptr1);  // Expected: [0x12345678]
    ft_printf("Test 7 (ft_printf): [%+p]\n", ptr1);

    // スペースフラッグのテスト（無視されるべきだが確認のため）
    printf("Test 8 (printf)  : [% p]\n", ptr1);  // Expected: [0x12345678]
    ft_printf("Test 8 (ft_printf): [% p]\n", ptr1);

    // ハッシュフラッグのテスト（無視されるべきだが確認のため）
    printf("Test 9 (printf)  : [%#p]\n", ptr1);  // Expected: [0x12345678]
    ft_printf("Test 9 (ft_printf): [%#p]\n", ptr1);

    // すべてのフラッグを組み合わせたテスト
    printf("Test 10 (printf) : [%+020p]\n", ptr1);  // Expected: [000000000012345678]
    ft_printf("Test 10 (ft_printf): [%+020p]\n", ptr1);

    printf("Test 11 (printf) : [% -20p]\n", ptr1);  // Expected: [0x12345678       ]
    ft_printf("Test 11 (ft_printf): [% -20p]\n", ptr1);
}

int main() {
    run_p_tests();
    return 0;
}
