/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexdecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:01:37 by rohta             #+#    #+#             */
/*   Updated: 2024/06/24 07:24:38 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
size_t	ft_write_flags(t_params *params, size_t *print_len, size_t *put_prec)
{
	size_t	byte;

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
	size_t	i;
	char	c;

	i = 0;
	byte = 0;
	conv_len = ft_strlen(params->converted);
	print_len = *params->width - (put_prec + conv_len);
	if (params->flags->flag_zero)
		c = '0';
	c = ' ';
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len, &put_prec);
		while (i++ < put_prec)
			byte += write(STDOUT_FD, "0", 1);
		byte += write(STDOUT_FD, params->converted, conv_len);
		i = 0;
		while (i++ < print_len)
			byte += write(STDOUT_FD, " ", 1);
	}
	else
	{
		byte += ft_write_flags(params, &print_len, &put_prec);
		if (*params->precision == NOT_SPEC || params->flags->flag_zero)
		{
			while (i++ < print_len)
				byte += write(STDOUT_FD, &c, 1);
		}
		i = 0;
		while (i++ < put_prec)
			byte += write(STDOUT_FD, "0", 1);
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

size_t	ft_write_hex(t_params *params)
{
	ssize_t	conv_len;
	size_t	put_prec;
	size_t	byte;

	conv_len = ft_strlen(params->converted);
	ft_check_flag(params);
	if (params->width < params->precision || conv_len < *params->precision)
		*params->width = 0;
	put_prec = *params->precision - conv_len;
	byte = ft_write_xp(params, put_prec);
	return (byte);
}
