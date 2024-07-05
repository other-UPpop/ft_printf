#include <stdio.h>
#include <string.h>
#include "ft_printf.h" // ft_printfのヘッダーをインクルード

void test_char_width() {
    char test_chars[] = {
        (char)1, (char)2, (char)3, (char)4, (char)5, (char)6, (char)7, (char)8, 
        (char)9, (char)10, (char)11, (char)12, (char)13, (char)14, (char)15, (char)16, 
        (char)17, (char)18, (char)19, (char)20, (char)21, (char)22, (char)23, (char)24, 
        (char)25, (char)26, (char)27, (char)28, (char)29, (char)30, (char)31
    };

    char buffer_printf[1024];
    char buffer_ft_printf[1024];

    // テストケース1: 幅指定
    // printfの出力を取得
   printf("printf : %2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",
                              test_chars[0], test_chars[1], test_chars[2], test_chars[3], test_chars[4], test_chars[5], test_chars[6], test_chars[7], 
                              test_chars[8], test_chars[9], test_chars[10], test_chars[11], test_chars[12], test_chars[13], test_chars[14], test_chars[15], 
                              test_chars[16], test_chars[17], test_chars[18], test_chars[19], test_chars[20], test_chars[21], test_chars[22], test_chars[23], 
                              test_chars[24], test_chars[25], test_chars[26], test_chars[27], test_chars[28], test_chars[29], test_chars[30]);

    // ft_printfの出力を取得
    ft_printf("ft_printf : %2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",
                                  test_chars[0], test_chars[1], test_chars[2], test_chars[3], test_chars[4], test_chars[5], test_chars[6], test_chars[7], 
                                  test_chars[8], test_chars[9], test_chars[10], test_chars[11], test_chars[12], test_chars[13], test_chars[14], test_chars[15], 
                                  test_chars[16], test_chars[17], test_chars[18], test_chars[19], test_chars[20], test_chars[21], test_chars[22], test_chars[23], 
                                  test_chars[24], test_chars[25], test_chars[26], test_chars[27], test_chars[28], test_chars[29], test_chars[30]);

}

int main() {
    test_char_width();
    return 0;
}
