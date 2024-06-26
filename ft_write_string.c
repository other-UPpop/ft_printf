/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:03:40 by rohta             #+#    #+#             */
/*   Updated: 2024/06/26 19:27:16 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
ssize_t	ft_write_str(t_params *params, ssize_t print_len, ssize_t put_width)
{
	ssize_t	byte;
	ssize_t	i;
	char	c;
	
	byte = 0;
	i = 0;
	c = ' ';
	if (params->flags->flag_zero)
		c = '0';
	if (!(params->flags->flag_minus) && put_width > 0)
	{
		while (i++ < put_width)
			byte += write(STDOUT_FD, &c, sizeof(char));
	}
	byte += write(STDOUT_FD, params->converted, print_len);
	if (params->flags->flag_minus && put_width > 0)
	{
		while (i++ < put_width)
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	return (byte);
}

static ssize_t	ft_print_len(t_params *params, ssize_t conv_len)
{
		if (0 <= *params->precision && *params->precision <= conv_len
				&& *params->precision != NOT_SPEC)
			return (*params->precision);
		if ((conv_len < *params->precision && *params->precision)
				|| *params->precision == NOT_SPEC)
			return (conv_len);
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
	if (params->specifier == '%')
	{
		c = (char)(params->specifier);
		return (write(STDOUT_FD, &c, sizeof(char)));
	}
	if (params->specifier == 'c')
	{
		c = (char)(*params->converted);
		return (write(STDOUT_FD, &c, sizeof(char)));
	}
	if (params->specifier == 's')
	{
		print_len = ft_print_len(params, conv_len);
		if (print_len < *params->width && params->width)
			put_width = *params->width - print_len;
		else
			put_width = 0;
		byte = ft_write_str(params, print_len, put_width);
	}
	return (byte);
}
