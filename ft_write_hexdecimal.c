/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexdecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:01:37 by rohta             #+#    #+#             */
/*   Updated: 2024/06/20 15:49:21 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
size_t	ft_write_flags(t_params *params, size_t *print_len, size_t *put_prec)
{
	size_t byte;

	byte = 0;
	if (params->flags->flag_hashtag && ft_strchr("xX", params->specifier))
	{
		if (params->specifier == 'x')
			byte += write(STDOUT_FD, "0x", sizeof(char));
		byte += write(STDOUT_FD, "0X", sizeof(char));
		*print_len -= 2;
		*put_prec -= 2;
	}
	return (byte);
}

static size_t	ft_write_xp(t_params *params, size_t put_prec)
{
	size_t	print_len;
	size_t	conv_len;
	size_t	byte;
	char	*c;

	conv_len = ft_strlen(params->converted);
	print_len = print_len - (put_prec + conv_len); 
	if (params->flags->flag_zero)
		*c = '0';
	*c = ' ';
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len, &put_prec);
		byte += write(STDOUT_FD, "0", put_prec);
		byte += write(STDOUT_FD, params->converted, conv_len);
		byte += write(STDOUT_FD, " ", print_len);
	}
	else
	{
		byte += ft_write_flags(params, &print_len, &put_prec);
		if (*params->precision == NOT_SPEC || params->flags->flag_zero)
			byte += write(STDOUT_FD, c, print_len);
		byte += write(STDOUT_FD, "0", put_prec);
		byte += write(STDOUT_FD, params->converted, conv_len);
	}
	return (byte);
}

static void	ft_check_flag(t_params *params)
{
	if (params->flags->flag_minus || params->precision)
		 params->flags->flag_zero = false;
	params->flags->flag_space = false;
	params->flags->flag_plus = false;
}

static size_t	ft_width_size(t_params *params, size_t conv_len)
{
	if (conv_len < *params->width && params->precision < params->width)
		return (*params->width - conv_len);
	return (0);
}

size_t	ft_write_hex(t_params *params)
{
	size_t	conv_len;
	size_t	put_prec;
	size_t	put_width;
	size_t	print_len;
	size_t	byte;

	conv_len = ft_strlen(params->converted);
	put_width = ft_width_size(params ,conv_len);
	ft_check_flag(params);
	if (params->width < params->precision || conv_len < *params->precision)
		put_width = 0;
	put_prec = *params->precision - conv_len;
	byte = ft_write_xp(params, put_prec);
	return (byte);
}
