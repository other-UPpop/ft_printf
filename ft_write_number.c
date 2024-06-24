/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:19:03 by rohta             #+#    #+#             */
/*   Updated: 2024/06/24 14:44:18 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	my_putstr_fd(char *s, int fd)
{
	size_t	byte;

	byte = 0;
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	return (byte);
}

static
size_t	ft_write_flags(t_params *params, size_t *print_len, size_t *put_prec)
{
	size_t	byte;
	int		sign;

	byte = 0;
	sign = ft_atoi(params->converted);
	if (params->flags->flag_plus && 0 <= sign)
	{
			byte += write(STDOUT_FD, "+", sizeof(char));
			--(*print_len);
			--(*put_prec);
	}
	else if (params->flags->flag_space && 0 <= sign)
	{
		byte += write(STDOUT_FD, " ", sizeof(char));
		--(*print_len);
		--(*put_prec);
	}
	return (byte);
}

static size_t	ft_write_int(t_params *params, size_t put_prec, size_t print_len)
{
	size_t	conv_len;
	size_t	byte;
	size_t	i;
	char	c;

	i = 0;
	byte = 0;
	c = ' ';
	conv_len = ft_strlen(params->converted);
	if (params->flags->flag_zero)
		c = '0';
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len, &put_prec);
		while (i++ < put_prec)
		{
			byte += write(STDOUT_FD, "0", sizeof(char));
			--print_len;
		}
		byte += write(STDOUT_FD, params->converted, conv_len);
		while (conv_len < print_len--)
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	else
	{
		byte += ft_write_flags(params, &print_len, &put_prec);
			while (*params->precision + conv_len < print_len--)
				byte += write(STDOUT_FD, &c, 1);
			while (i++ < put_prec)
				byte += write(STDOUT_FD, "0", 1);
		}
		byte += write(STDOUT_FD, params->converted, conv_len);
	return (byte);
}

static void	ft_check_flag(t_params *params)
{
	if (params->flags->flag_minus || params->precision)
		params->flags->flag_zero = false;
	if (params->flags->flag_plus)
		params->flags->flag_space = false;
}

size_t	ft_write_number(t_params *params)
{
	ssize_t	conv_len;
	size_t	print_len;
	size_t	put_prec;
	size_t	byte;

	print_len = 0;
	put_prec = 0;
	byte = 0;
	conv_len = ft_strlen(params->converted);
	ft_check_flag(params);
	if (*params->width < *params->precision && conv_len < *params->precision)
	{
		print_len = *params->precision;
		put_prec = *params->precision - conv_len;
		*params->width = 0;
	}
	else if (conv_len < *params->width)
	{
		if (*params->precision < *params->width)
			print_len = *params->width;
		else
			print_len = *params->precision;
		put_prec = *params->precision - conv_len;
	}
	else if (*params->width < conv_len && *params->precision < conv_len)
	{
		print_len = conv_len;
		put_prec = 0;
		*params->width = 0;
	}
	byte = ft_write_int(params, put_prec, print_len);
	return (byte);
}