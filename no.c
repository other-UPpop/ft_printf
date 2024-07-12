#include "ft_printf.h"


static size_t ft_write_flags(t_params *params, size_t *print_len) {
    size_t byte = 0;
    if ((params->flags->flag_hashtag || params->specifier == 'p') && *params->converted != '0') {
        if (*print_len >= 2) *print_len -= 2;
        byte += write(STDOUT_FD, (params->specifier == 'x' || params->specifier == 'p') ? "0x" : "0X", 2);
        if (*params->converted == '0' && (!params->flags->flag_zero || !params->flags->flag_minus))
            --(*print_len);
    }
    return byte;
}

static size_t ft_write_xp(t_params *params, ssize_t put_prec, size_t print_len) {
    size_t conv_len = ft_strlen(params->converted);
    size_t byte = 0;
    size_t i = 0;
    char c = (params->flags->flag_zero) ? '0' : ' ';

    if ((params->precision == 0 || *params->precision == NOT_SPEC) && params->dot && *params->converted == '0')
        conv_len = 0;

    if (params->flags->flag_minus) {
        byte += ft_write_flags(params, &print_len);
        while ((ssize_t)i++ < put_prec) byte += write(STDOUT_FD, "0", 1);
        byte += write(STDOUT_FD, params->converted, conv_len);
        while (conv_len < print_len--) byte += write(STDOUT_FD, " ", 1);
    } else {
        if (params->flags->flag_zero && params->flags->flag_hashtag) byte += ft_write_flags(params, &print_len);
        else if (*params->converted != '0' && params->flags->flag_hashtag && (ssize_t)conv_len < *params->width && print_len >= 2)
            print_len -= 2;

        while (put_prec + conv_len < print_len--) byte += write(STDOUT_FD, &c, 1);
        if (put_prec != 0 && params->flags->flag_hashtag) byte += ft_write_flags(params, &print_len);
        while ((ssize_t)i++ < put_prec) byte += write(STDOUT_FD, "0", 1);
        if (!(params->flags->flag_zero) && put_prec == 0) byte += ft_write_flags(params, &print_len);
        byte += write(STDOUT_FD, params->converted, conv_len);
    }
    return byte;
}

static void ft_check_flag(t_params *params) {
    if (params->flags->flag_minus || *params->precision != NOT_SPEC) params->flags->flag_zero = false;
    params->flags->flag_space = false;
    params->flags->flag_plus = false;
    if (params->specifier == 'p') {
        params->flags->flag_hashtag = false;
        *params->precision = NOT_SPEC;
    }
}

size_t ft_write_hex(t_params *params) {
    ssize_t conv_len = ft_strlen(params->converted);
    size_t print_len = (*params->width <= *params->precision) ? *params->precision : *params->width;
    size_t put_prec = (conv_len < *params->precision) ? (*params->precision - conv_len) : 0;
    size_t byte = 0;

    ft_check_flag(params);

    if (conv_len >= *params->width && conv_len >= *params->precision) {
        print_len = conv_len;
        put_prec = 0;
    }

    byte = ft_write_xp(params, put_prec, print_len);
    return byte;
}

