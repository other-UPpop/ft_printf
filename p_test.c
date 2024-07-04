#include <stdio.h>
#include "ft_printf.h" // ft_printfのヘッダーをインクルード

int main() {
    int a01 = 1, a02 = 2, a03 = 3, a04 = 4, a05 = 5, a06 = 6, a07 = 7, a08 = 8, a09 = 9, a10 = 10, a11 = 11, a12 = 12;

    // printfによる出力
    printf("printf:\n");
    printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n",
           (void*)&a01, (void*)&a02, (void*)&a03, (void*)&a04, 
           (void*)&a05, (void*)&a06, (void*)&a07, (void*)&a08, 
           (void*)&a09, (void*)&a10, (void*)&a11, (void*)&a12);

    // ft_printfによる出力
    printf("ft_printf:\n");
    ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n",
              (void*)&a01, (void*)&a02, (void*)&a03, (void*)&a04, 
              (void*)&a05, (void*)&a06, (void*)&a07, (void*)&a08, 
              (void*)&a09, (void*)&a10, (void*)&a11, (void*)&a12);

    return 0;
}
