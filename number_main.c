#include <stdio.h>

// 自作の ft_printf 関数のプロトタイプを定義
int ft_printf(const char *format, ...);

void run_tests() {
    int num = 12345;
    int neg_num = -12345;

    // 基本的な出力
    printf("Test 1 (printf)  : [%d]\n", num);  // Expected: [12345]
    ft_printf("Test 1 (ft_printf): [%d]\n", num);

    // 幅のテスト
    printf("Test 2 (printf)  : [%10d]\n", num);  // Expected: [     12345]
    ft_printf("Test 2 (ft_printf): [%10d]\n", num);
    
    printf("Test 3 (printf)  : [%-10d]\n", num); // Expected: [12345     ]
    ft_printf("Test 3 (ft_printf): [%-10d]\n", num);

    // 精度のテスト
    printf("Test 4 (printf)  : [%.3d]\n", num);  // Expected: [12345]
    ft_printf("Test 4 (ft_printf): [%.3d]\n", num);
    
    printf("Test 5 (printf)  : [%.10d]\n", num);  // Expected: [0000012345]
    ft_printf("Test 5 (ft_printf): [%.10d]\n", num);
    
    printf("Test 6 (printf)  : [%.0d]\n", num);  // Expected: [12345]
    ft_printf("Test 6 (ft_printf): [%.0d]\n", num);
    
    printf("Test 7 (printf)  : [%.5d]\n", num);  // Expected: [12345]
    ft_printf("Test 7 (ft_printf): [%.5d]\n", num);

    // 幅と精度の組み合わせのテスト
    printf("Test 8 (printf)  : [%10.3d]\n", num);  // Expected: [     12345]
    ft_printf("Test 8 (ft_printf): [%10.3d]\n", num);
    
    printf("Test 9 (printf)  : [%10.10d]\n", num); // Expected: [0000012345]
    ft_printf("Test 9 (ft_printf): [%10.10d]\n", num);
    
    printf("Test 10 (printf) : [%10.5d]\n", num); // Expected: [   0012345]
    ft_printf("Test 10 (ft_printf): [%10.5d]\n", num);
    
    printf("Test 11 (printf) : [%-10.5d]\n", num); // Expected: [0012345   ]
    ft_printf("Test 11 (ft_printf): [%-10.5d]\n", num);

    // ゼロフラッグのテスト
    printf("Test 12 (printf) : [%010d]\n", num);  // Expected: [0000012345]
    ft_printf("Test 12 (ft_printf): [%010d]\n", num);
    
    printf("Test 13 (printf) : [%-010d]\n", num); // Expected: [12345     ]
    ft_printf("Test 13 (ft_printf): [%-010d]\n", num);

    printf("Test 14 (printf) : [%010.5d]\n", num); // Expected: [   0012345]
    ft_printf("Test 14 (ft_printf): [%010.5d]\n", num);

    printf("Test 15 (printf) : [%0-10.5d]\n", num); // Expected: [0012345   ]
    ft_printf("Test 15 (ft_printf): [%0-10.5d]\n", num);

    // プラスフラッグのテスト
    printf("Test 16 (printf) : [%+d]\n", num);  // Expected: [+12345]
    ft_printf("Test 16 (ft_printf): [%+d]\n", num);

    printf("Test 17 (printf) : [%+d]\n", neg_num);  // Expected: [-12345]
    ft_printf("Test 17 (ft_printf): [%+d]\n", neg_num);

    // スペースフラッグのテスト
    printf("Test 18 (printf) : [% d]\n", num);  // Expected: [ 12345]
    ft_printf("Test 18 (ft_printf): [% d]\n", num);

    printf("Test 19 (printf) : [% d]\n", neg_num);  // Expected: [-12345]
    ft_printf("Test 19 (ft_printf): [% d]\n", neg_num);

    // ハッシュフラッグのテスト（dには影響しないが、異常ケースとしてチェック）
    printf("Test 20 (printf) : [%#d]\n", num);  // Expected: [12345]
    ft_printf("Test 20 (ft_printf): [%#d]\n", num);

    // コンマフラッグのテスト（通常のprintfにはないが、カスタムprintfでサポートする場合）
    // printf("Test 21 (printf) : [%'d]\n", num);  // Expected: [12,345]
    // ft_printf("Test 21 (ft_printf): [%'d]\n", num);

    // すべてのフラッグを組み合わせたテスト
    printf("Test 22 (printf) : [%+010d]\n", num);  // Expected: [+000012345]
    ft_printf("Test 22 (ft_printf): [%+010d]\n", num);

    printf("Test 23 (printf) : [%+10.5d]\n", num);  // Expected: [   +0012345]
    ft_printf("Test 23 (ft_printf): [%+10.5d]\n", num);

    printf("Test 24 (printf) : [% 010d]\n", num);  // Expected: [ 000012345]
    ft_printf("Test 24 (ft_printf): [% 010d]\n", num);

    printf("Test 25 (printf) : [% -10.5d]\n", num);  // Expected: [ 0012345  ]
    ft_printf("Test 25 (ft_printf): [% -10.5d]\n", num);

    // 負の整数のフラッグテスト
    printf("Test 26 (printf) : [%10d]\n", neg_num);  // Expected: [    -12345]
    ft_printf("Test 26 (ft_printf): [%10d]\n", neg_num);

    printf("Test 27 (printf) : [%-10d]\n", neg_num);  // Expected: [-12345    ]
    ft_printf("Test 27 (ft_printf): [%-10d]\n", neg_num);

    printf("Test 28 (printf) : [%010d]\n", neg_num);  // Expected: [-000012345]
    ft_printf("Test 28 (ft_printf): [%010d]\n", neg_num);

    printf("Test 29 (printf) : [%-010d]\n", neg_num);  // Expected: [-12345    ]
    ft_printf("Test 29 (ft_printf): [%-010d]\n", neg_num);

    printf("Test 30 (printf) : [%+10d]\n", neg_num);  // Expected: [    -12345]
    ft_printf("Test 30 (ft_printf): [%+10d]\n", neg_num);

    printf("Test 31 (printf) : [%+010d]\n", neg_num);  // Expected: [-000012345]
    ft_printf("Test 31 (ft_printf): [%+010d]\n", neg_num);
}

int main() {
    run_tests();
    return 0;
}
