#include <stdio.h>
#include "ft_printf.h"

// 自作の ft_printf 関数のプロトタイプを定義
int ft_printf(const char *format, ...);

void run_tests() {
    char *str = "Hello";

    // 基本的な出力
    printf("Test 1 (printf)  : [%s]\n", str);  // Expected: [Hello]
    ft_printf("Test 1 (ft_printf): [%s]\n", str);

    // 幅のテスト
    printf("Test 2 (printf)  : [%10s]\n", str);  // Expected: [     Hello]
    ft_printf("Test 2 (ft_printf): [%10s]\n", str);
    
    printf("Test 3 (printf)  : [%-10s]\n", str); // Expected: [Hello     ]
    ft_printf("Test 3 (ft_printf): [%-10s]\n", str);

    // 精度のテスト
    printf("Test 4 (printf)  : [%.3s]\n", str);  // Expected: [Hel]
    ft_printf("Test 4 (ft_printf): [%.3s]\n", str);
    
    printf("Test 5 (printf)  : [%.5s]\n", str);  // Expected: [Hello]
    ft_printf("Test 5 (ft_printf): [%.5s]\n", str);
    
    printf("Test 6 (printf)  : [%.10s]\n", str); // Expected: [Hello]
    ft_printf("Test 6 (ft_printf): [%.10s]\n", str);
    
    printf("Test 7 (printf)  : [%.0s]\n", str);  // Expected: []
    ft_printf("Test 7 (ft_printf): [%.0s]\n", str);

    // 幅と精度の組み合わせのテスト
    printf("Test 8 (printf)  : [%10.3s]\n", str);  // Expected: [       Hel]
    ft_printf("Test 8 (ft_printf): [%10.3s]\n", str);
    
    printf("Test 9 (printf)  : [%-10.3s]\n", str); // Expected: [Hel       ]
    ft_printf("Test 9 (ft_printf): [%-10.3s]\n", str);
    
    printf("Test 10 (printf) : [%10.5s]\n", str); // Expected: [     Hello]
    ft_printf("Test 10 (ft_printf): [%10.5s]\n", str);
    
    printf("Test 11 (printf) : [%-10.5s]\n", str);// Expected: [Hello     ]
    ft_printf("Test 11 (ft_printf): [%-10.5s]\n", str);
    
    printf("Test 12 (printf) : [%10.0s]\n", str); // Expected: [          ]
    ft_printf("Test 12 (ft_printf): [%10.0s]\n", str);
    
    printf("Test 13 (printf) : [%-10.0s]\n", str);// Expected: [          ]
    ft_printf("Test 13 (ft_printf): [%-10.0s]\n", str);

    // ゼロフラッグのテスト (文字列には影響しない)
    printf("Test 14 (printf) : [%010s]\n", str);  // Expected: [     Hello]
    ft_printf("Test 14 (ft_printf): [%010s]\n", str);
    
    printf("Test 15 (printf) : [%0-10s]\n", str); // Expected: [Hello     ]
    ft_printf("Test 15 (ft_printf): [%0-10s]\n", str);
}

int main() {
    run_tests();
    return 0;
}
