#include <stdio.h>  // 標準のprintfと比較するため
#include "ft_printf.h"  // 自作printfのヘッダーをインクルード

int main(void)
{
    int int_val = 42;
    unsigned int uint_val = 12345;
    char char_val = 'A';
    char *str_val = "Hello, World!";
    void *ptr_val = &int_val;

    // 整数
    printf("Standard printf: %d\n", int_val);
    ft_printf("Custom printf  : %d\n", int_val);

    // 符号付き整数
    printf("Standard printf: %i\n", int_val);
    ft_printf("Custom printf  : %i\n", int_val);

    // 文字
    printf("Standard printf: %c\n", char_val);
    ft_printf("Custom printf  : %c\n", char_val);

    // 文字列
    printf("Standard printf: %s\n", str_val);
    ft_printf("Custom printf  : %s\n", str_val);

    // ポインタ
    printf("Standard printf: %p\n", ptr_val);
    ft_printf("Custom printf  : %p\n", ptr_val);

    // 符号なし整数
    printf("Standard printf: %u\n", uint_val);
    ft_printf("Custom printf  : %u\n", uint_val);

    // 16進数 (小文字)
    printf("Standard printf: %x\n", uint_val);
    ft_printf("Custom printf  : %x\n", uint_val);

    // 16進数 (大文字)
    printf("Standard printf: %X\n", uint_val);
    ft_printf("Custom printf  : %X\n", uint_val);

    // パーセント
    printf("Standard printf: %%\n");
    ft_printf("Custom printf  : %%\n");

    return 0;
}

