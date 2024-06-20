/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:03:40 by rohta             #+#    #+#             */
/*   Updated: 2024/06/20 15:50:49 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
size_t	ft_write_csp(t_params *params, size_t print_len, size_t put_prec)
{
	size_t	byte;

	byte = 0;
	if (params->flags->flag_minus)
	{
		byte += write(STDOUT_FD, params->converted, print_len);
		byte += write(STDOUT_FD, " ", put_prec);
	}
	else
	{
		byte += write(STDOUT_FD, " ", put_prec);
		byte += write(STDOUT_FD, params->converted, print_len);
	}
	return (byte);
}

static size_t	ft_width_size(t_params *params, size_t conv_size)
{
	if (conv_size < *params->width)
		return (*params->width - conv_size);
	return (0);
}

static size_t	ft_check_cp(t_params *params, size_t print_len, size_t conv_size)
{
	if (ft_strchr("cp", params->specifier))
	{
		*params->precision = 0;
		return (conv_size);
	}
	return (0);
}

size_t	ft_write_string(t_params *params)
{
	size_t	conv_size;
	size_t	put_prec;
	size_t	put_width;
	size_t	print_len;
	size_t	byte;

	conv_size = ft_strlen(params->converted);
	put_width = ft_width_size(params, conv_size);
	print_len = ft_check_cp(params, print_len, conv_size);
	if (params->specifier == '%')
		byte = write(STDOUT_FD, "%", sizeof(char));
	if (params->specifier == 's' && *params->precision < conv_size
		&& params->precision)
	{
		put_prec = conv_size - *params->precision;
		print_len = *params->precision;
		if (*params->precision < *params->width)
			put_width += put_prec;
	}
	byte = ft_write_csp(params, print_len, put_prec);
	return (byte);
}
