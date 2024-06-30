#include <stdio.h>
#include "ft_printf.h" // ft_printfのヘッダーをインクルード

int main() {
    // フォーマット指定子のテスト
    printf("1. printf  [%%5%%]: [%5%]\n");
    ft_printf("1. ft_printf [%%5%%]: [%5%]\n");

    printf("2. printf  [%%-5%%]: [%-5%]\n");
    ft_printf("2. ft_printf [%%-5%%]: [%-5%]\n");

    printf("3. printf  [%%05%%]: [%05%]\n");
    ft_printf("3. ft_printf [%%05%%]: [%05%]\n");

    printf("4. printf  [%%-05%%]: [%-05%]\n");
    ft_printf("4. ft_printf [%%-05%%]: [%-05%]\n");

    printf("5. printf  [%%.c]: [%.c]\n", 'a');
    ft_printf("5. ft_printf [%%.c]: [%.c]\n", 'a');

    printf("6. printf  [%%10.5i]: [%10.5i]\n", -216);
    ft_printf("6. ft_printf [%%10.5i]: [%10.5i]\n", -216);

    printf("7. printf  [%%-10.5i]: [%-10.5i]\n", -216);
    ft_printf("7. ft_printf [%%-10.5i]: [%-10.5i]\n", -216);

    printf("8. printf  [%%010.5i]: [%010.5i]\n", -216);
    ft_printf("8. ft_printf [%%010.5i]: [%010.5i]\n", -216);

    printf("9. printf  [%%10.5d]: [%10.5d]\n", -216);
    ft_printf("9. ft_printf [%%10.5d]: [%10.5d]\n", -216);

    printf("10. printf  [%%-10.5d]: [%-10.5d]\n", -216);
    ft_printf("10. ft_printf [%%-10.5d]: [%-10.5d]\n", -216);

    printf("11. printf  [%%010.5d]: [%010.5d]\n", -216);
    ft_printf("11. ft_printf [%%010.5d]: [%010.5d]\n", -216);

    printf("12. printf  [%%.0x]: [%.0x]\n", 0);
    ft_printf("12. ft_printf [%%.0x]: [%.0x]\n", 0);

    printf("13. printf  [%%.x]: [%.x]\n", 0);
    ft_printf("13. ft_printf [%%.x]: [%.x]\n", 0);

    printf("14. printf  [%%5.0x]: [%5.0x]\n", 0);
    ft_printf("14. ft_printf [%%5.0x]: [%5.0x]\n", 0);

    printf("15. printf  [%%5.x]: [%5.x]\n", 0);
    ft_printf("15. ft_printf [%%5.x]: [%5.x]\n", 0);

    printf("16. printf  [%%-5.0x]: [%-5.0x]\n", 0);
    ft_printf("16. ft_printf [%%-5.0x]: [%-5.0x]\n", 0);

    printf("17. printf  [%%-5.x]: [%-5.x]\n", 0);
    ft_printf("17. ft_printf [%%-5.x]: [%-5.x]\n", 0);

    printf("18. printf  [%%.0X]: [%.0X]\n", 0);
    ft_printf("18. ft_printf [%%.0X]: [%.0X]\n", 0);

    printf("19. printf  [%%.X]: [%.X]\n", 0);
    ft_printf("19. ft_printf [%%.X]: [%.X]\n", 0);

    printf("20. printf  [%%5.0X]: [%5.0X]\n", 0);
    ft_printf("20. ft_printf [%%5.0X]: [%5.0X]\n", 0);

    printf("21. printf  [%%5.X]: [%5.X]\n", 0);
    ft_printf("21. ft_printf [%%5.X]: [%5.X]\n", 0);

    printf("22. printf  [%%-5.0X]: [%-5.0X]\n", 0);
    ft_printf("22. ft_printf [%%-5.0X]: [%-5.0X]\n", 0);

    printf("23. printf  [%%-5.X]: [%-5.X]\n", 0);
    ft_printf("23. ft_printf [%%-5.X]: [%-5.X]\n", 0);

    return 0;
}

