#include <stdio.h>
#include "ft_printf.h"

int run_c_tests() {
    ft_ptintf("%c", '0');
    ptintf("%c", '0');
    ft_ptintf(" %c ", '0');
    ptintf(" %c ", '0');
    ft_ptintf(" %c", '0' - 256);
    ptintf(" %c", '0' - 256);
    ft_ptintf("%c ", '0' + 256);
    ptintf("%c ", '0' + 256);
    ft_ptintf(" %c %c %c ", '0', 0, '1');
    ptintf(" %c %c %c ", '0', 0, '1');
    ft_ptintf(" %c %c %c ", ' ', ' ', ' ');
    ptintf(" %c %c %c ", ' ', ' ', ' ');
    ft_ptintf(" %c %c %c ", '1', '2', '3');
    ptintf(" %c %c %c ", '1', '2', '3');
    ft_ptintf(" %c %c %c ", '2', '1', 0);
    ptintf(" %c %c %c ", '2', '1', 0);
    ft_ptintf(" %c %c %c ", 0, '1', '2');
    ptintf(" %c %c %c ", 0, '1', '2');
   return (0);
}
int main() {
    run_c_tests();
    return 0;
}
