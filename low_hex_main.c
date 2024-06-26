#include <stdio.h>
#include "ft_printf.h"

// 自作の ft_printf 関数のプロトタイプを定義
int ft_printf(const char *format, ...);

void run_tests() {
    unsigned int num = 305441741; // 0x12345678
    unsigned int num2 = 65535;    // 0xFFFF

    // 基本的な出力
    printf("Test 1 (printf)  : [%x]\n", num);  // Expected: [12345678]
    ft_printf("Test 1 (ft_printf): [%x]\n", num);

    // 幅のテスト
    printf("Test 2 (printf)  : [%10x]\n", num);  // Expected: [  12345678]
    ft_printf("Test 2 (ft_printf): [%10x]\n", num);

    printf("Test 3 (printf)  : [%-10x]\n", num); // Expected: [12345678  ]
    ft_printf("Test 3 (ft_printf): [%-10x]\n", num);

    // 精度のテスト
    printf("Test 4 (printf)  : [%.3x]\n", num);  // Expected: [12345678]
    ft_printf("Test 4 (ft_printf): [%.3x]\n", num);

    printf("Test 5 (printf)  : [%.10x]\n", num);  // Expected: [0012345678]
    ft_printf("Test 5 (ft_printf): [%.10x]\n", num);

    printf("Test 6 (printf)  : [%.0x]\n", num);  // Expected: [12345678]
    ft_printf("Test 6 (ft_printf): [%.0x]\n", num);

    // 幅と精度の組み合わせのテスト
    printf("Test 7 (printf)  : [%10.3x]\n", num);  // Expected: [   12345678]
    ft_printf("Test 7 (ft_printf): [%10.3x]\n", num);

    printf("Test 8 (printf)  : [%10.10x]\n", num); // Expected: [0012345678]
    ft_printf("Test 8 (ft_printf): [%10.10x]\n", num);

    printf("Test 9 (printf)  : [%10.5x]\n", num);  // Expected: [  12345678]
    ft_printf("Test 9 (ft_printf): [%10.5x]\n", num);

    printf("Test 10 (printf) : [%-10.5x]\n", num); // Expected: [12345678  ]
    ft_printf("Test 10 (ft_printf): [%-10.5x]\n", num);

    // ゼロフラッグのテスト
    printf("Test 11 (printf) : [%010x]\n", num);  // Expected: [0012345678]
    ft_printf("Test 11 (ft_printf): [%010x]\n", num);

    printf("Test 12 (printf) : [%010x]\n", num2); // Expected: [000000ffff]
    ft_printf("Test 12 (ft_printf): [%010x]\n", num2);

    // プラスフラッグのテスト（xには影響しないが、異常ケースとしてチェック）
    printf("Test 13 (printf) : [%+x]\n", num);  // Expected: [12345678]
    ft_printf("Test 13 (ft_printf): [%+x]\n", num);

    // スペースフラッグのテスト（xには影響しないが、異常ケースとしてチェック）
    printf("Test 14 (printf) : [% x]\n", num);  // Expected: [12345678]
    ft_printf("Test 14 (ft_printf): [% x]\n", num);

    // ハッシュフラッグのテスト（xには影響しないが、異常ケースとしてチェック）
    printf("Test 15 (printf) : [%#x]\n", num);  // Expected: [12345678]
    ft_printf("Test 15 (ft_printf): [%#x]\n", num);

    // すべてのフラッグを組み合わせたテスト
    printf("Test 16 (printf) : [%+010x]\n", num);  // Expected: [0012345678]
    ft_printf("Test 16 (ft_printf): [%+010x]\n", num);

    printf("Test 17 (printf) : [%+10.5x]\n", num);  // Expected: [  12345678]
    ft_printf("Test 17 (ft_printf): [%+10.5x]\n", num);

    printf("Test 18 (printf) : [% 010x]\n", num);  // Expected: [ 0012345678]
    ft_printf("Test 18 (ft_printf): [% 010x]\n", num);

    printf("Test 19 (printf) : [% -10.5x]\n", num);  // Expected: [ 12345678 ]
    ft_printf("Test 19 (ft_printf): [% -10.5x]\n", num);
}

int main() {
    run_tests();
    return 0;
}
