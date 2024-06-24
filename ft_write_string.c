/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:03:40 by rohta             #+#    #+#             */
/*   Updated: 2024/06/24 16:42:43 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
ssize_t	ft_write_str(t_params *params, ssize_t print_len, ssize_t put_width)
{
	ssize_t	byte;

	byte = 0;
	if (!params->flags->flag_minus && put_width)
		byte += write(STDOUT_FD, " ", put_width);
	byte += write(STDOUT_FD, params->converted, print_len);
	if (params->flags->flag_minus && put_width)
		byte += write(STDOUT_FD, " ", put_width);
	return (byte);
}

static ssize_t	ft_check_cp(t_params *params, ssize_t conv_len)
{
	if (params->specifier == 's' && params->precision)
	{
		*params->precision = 0;
		return (conv_len);
	}
	return (0);
}

ssize_t	ft_write_string(t_params *params)
{
	ssize_t	conv_len;
	ssize_t	put_width;
	ssize_t	print_len;
	ssize_t	byte;
	char	c;

	if (!params)
		return (PRINTF_NULL);
	byte = 0;
	put_width = 0;
	conv_len = ft_strlen(params->converted);
	print_len = ft_check_cp(params, conv_len);
	if (params->specifier == '%')
		return (write(STDOUT_FD, "%", sizeof(char)));
	if (params->specifier == 'c')
	{
		c = (char)(*params->converted);
		return (write(STDOUT_FD, &c, sizeof(char)));
	}
	if (params->specifier == 's')
	{
		if (params->flags->flag_minus && *params->precision < conv_len
				&& params->precision)
			print_len = *params->precision;
		else
			print_len = conv_len;
		if (print_len < *params->width)
				put_width = *params->width - print_len;
		byte = ft_write_str(params, print_len, put_width);
	}
	return (byte);
}
