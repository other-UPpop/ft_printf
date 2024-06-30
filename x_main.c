#include <stdio.h>
#include "ft_printf.h" // ft_printfのヘッダーをインクルード

int main() {
    unsigned int num = 1234;

    // 各フォーマットのテスト
    printf("1. printf  [%%x]: [%x]\n", num);
    ft_printf("1. ft_printf [%%x]: [%x]\n", num);

    printf("2. printf  [%%5x]: [%5x]\n", num);
    ft_printf("2. ft_printf [%%5x]: [%5x]\n", num);

    printf("3. printf  [%%05x]: [%05x]\n", num);
    ft_printf("3. ft_printf [%%05x]: [%05x]\n", num);

    printf("4. printf  [%%-5x]: [%-5x]\n", num);
    ft_printf("4. ft_printf [%%-5x]: [%-5x]\n", num);

    printf("5. printf  [%%.5x]: [%.5x]\n", num);
    ft_printf("5. ft_printf [%%.5x]: [%.5x]\n", num);

    printf("6. printf  [%%8.5x]: [%8.5x]\n", num);
    ft_printf("6. ft_printf [%%8.5x]: [%8.5x]\n", num);

    printf("7. printf  [%%-8.5x]: [%-8.5x]\n", num);
    ft_printf("7. ft_printf [%%-8.5x]: [%-8.5x]\n", num);

    printf("8. printf  [%%#x]: [%#x]\n", num);
    ft_printf("8. ft_printf [%%#x]: [%#x]\n", num);

    printf("9. printf  [%%#8x]: [%#8x]\n", num);
    ft_printf("9. ft_printf [%%#8x]: [%#8x]\n", num);

    printf("10. printf  [%%#08x]: [%#08x]\n", num);
    ft_printf("10. ft_printf [%%#08x]: [%#08x]\n", num);

    printf("11. printf  [%%#-8x]: [%#-8x]\n", num);
    ft_printf("11. ft_printf [%%#-8x]: [%#-8x]\n", num);

    printf("12. printf  [%%#.5x]: [%#.5x]\n", num);
    ft_printf("12. ft_printf [%%#.5x]: [%#.5x]\n", num);

    printf("13. printf  [%%#8.5x]: [%#8.5x]\n", num);
    ft_printf("13. ft_printf [%%#8.5x]: [%#8.5x]\n", num);

    printf("14. printf  [%%#-8.5x]: [%#-8.5x]\n", num);
    ft_printf("14. ft_printf [%%#-8.5x]: [%#-8.5x]\n", num);

    printf("15 printf  [%%#x]: [%#x]\n", 0);
    ft_printf("15 ft_printf  [%%#x]: [%#x]\n", 0);

    printf("15 printf  [%%#x]: [%#x]\n", LONG_MIN);
    ft_printf("15 ft_printf  [%%#x]: [%#x]\n", LONG_MIN);

    return 0;
}
