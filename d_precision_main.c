#include <stdio.h>
#include "ft_printf.h"

// 自作の ft_printf 関数のプロトタイプを定義
int ft_printf(const char *format, ...);

void run_d_precision_tests() {
    int num1 = 12345;
    int num2 = -12345;
    int num3 = 0;
    
    // 基本的な精度のテスト
    printf("Test 1 (printf)  : [%.2d]\n", -1);  // Expected: [12345]
    ft_printf("Test 1 (ft_printf): [%.2d]\n", -1);

    printf("Test 2 (printf)  : [%.10d]\n", num1); // Expected: [0000012345]
    ft_printf("Test 2 (ft_printf): [%.10d]\n", num1);

    printf("Test 3 (printf)  : [%.5d]\n", num2);  // Expected: [-12345]
    ft_printf("Test 3 (ft_printf): [%.5d]\n", num2);

    printf("Test 4 (printf)  : [%.10d]\n", num2); // Expected: [-000012345]
    ft_printf("Test 4 (ft_printf): [%.10d]\n", num2);

    printf("Test 5 (printf)  : [%.0d]\n", num3);  // Expected: []
    ft_printf("Test 5 (ft_printf): [%.0d]\n", num3);

    // 幅と精度の組み合わせのテスト
    printf("Test 6 (printf)  : [%10.5d]\n", num1);  // Expected: [     12345]
    ft_printf("Test 6 (ft_printf): [%10.5d]\n", num1);

    printf("Test 7 (printf)  : [%10.10d]\n", num1); // Expected: [0000012345]
    ft_printf("Test 7 (ft_printf): [%10.10d]\n", num1);

    printf("Test 8 (printf)  : [%10.5d]\n", num2);  // Expected: [    -12345]
    ft_printf("Test 8 (ft_printf): [%10.5d]\n", num2);

    printf("Test 9 (printf)  : [%10.10d]\n", num2); // Expected: [-000012345]
    ft_printf("Test 9 (ft_printf): [%10.10d]\n", num2);

    printf("Test 10 (printf) : [%10.0d]\n", num3);  // Expected: [          ]
    ft_printf("Test 10 (ft_printf): [%10.0d]\n", num3);

    // ゼロフラッグと精度の組み合わせのテスト
    printf("Test 11 (printf) : [%010.5d]\n", num1); // Expected: [0000012345]
    ft_printf("Test 11 (ft_printf): [%010.5d]\n", num1);

    printf("Test 12 (printf) : [%010.10d]\n", num1); // Expected: [0000012345]
    ft_printf("Test 12 (ft_printf): [%010.10d]\n", num1);

    printf("Test 13 (printf) : [%010.5d]\n", num2); // Expected: [-000012345]
    ft_printf("Test 13 (ft_printf): [%010.5d]\n", num2);

    printf("Test 14 (printf) : [%010.10d]\n", num2); // Expected: [-000012345]
    ft_printf("Test 14 (ft_printf): [%010.10d]\n", num2);

    printf("Test 15 (printf) : [%010.0d]\n", num3); // Expected: [          ]
    ft_printf("Test 15 (ft_printf): [%010.0d]\n", num3);

    // マイナスフラッグと精度の組み合わせのテスト
    printf("Test 16 (printf) : [%-10.5d]\n", num1); // Expected: [12345     ]
    ft_printf("Test 16 (ft_printf): [%-10.5d]\n", num1);

    printf("Test 17 (printf) : [%-10.10d]\n", num1); // Expected: [0000012345]
    ft_printf("Test 17 (ft_printf): [%-10.10d]\n", num1);

    printf("Test 18 (printf) : [%-10.5d]\n", num2); // Expected: [-12345    ]
    ft_printf("Test 18 (ft_printf): [%-10.5d]\n", num2);

    printf("Test 19 (printf) : [%-10.10d]\n", num2); // Expected: [-000012345]
    ft_printf("Test 19 (ft_printf): [%-10.10d]\n", num2);

    printf("Test 20 (printf) : [%-10.0d]\n", num3); // Expected: [          ]
    ft_printf("Test 20 (ft_printf): [%-10.0d]\n", num3);
}

int main() {
    run_d_precision_tests();
    return 0;
}
