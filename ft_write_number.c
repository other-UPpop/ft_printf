/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:19:03 by rohta             #+#    #+#             */
/*   Updated: 2024/07/04 21:18:34 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_write_flags(t_params *params, size_t *print_len, 
		size_t *conv_len)
{
	size_t	byte;
	int		sign;

	byte = 0;
	sign = ft_atoi(params->converted);
	if ((((params->flags->flag_zero && params->specifier != 'u')
		 || (size_t)*params->precision > ft_strlen(params->converted) - 1))
			&& sign < 0)
	{
		byte += write(STDOUT_FD, "-", sizeof(char));
		--(*print_len);
		--(*conv_len);
		params->converted = ft_substr(params->converted, 1,
				(size_t)conv_len);
	}
	if ((params->flags->flag_plus || params->flags->flag_space)
		&& 0 <= sign)
	{
		if (params->flags->flag_plus)
			byte += write(STDOUT_FD, "+", sizeof(char));
		else
			byte += write(STDOUT_FD, " ", sizeof(char));
		--(*print_len);
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
	if (*params->precision == 0 && ft_atoi(params->converted) == 0)
			conv_len = 0;
	else if (ft_atoi(params->converted) < 0 
			&& ((ssize_t)(conv_len - 1) < *params->precision)
			&& *params->width > *params->precision)
		++put_prec;
	if (params->flags->flag_zero && *params->precision == NOT_SPEC)
		c = '0';
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len, &conv_len);
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
		if (c == '0')
			byte += ft_write_flags(params, &print_len, &conv_len);
		while (put_prec + conv_len < print_len--)
			byte += write(STDOUT_FD, &c, sizeof(char));
		if (c == ' ')
			byte += ft_write_flags(params, &print_len, &conv_len);
		while (i++ < put_prec)
				byte += write(STDOUT_FD, "0", sizeof(char));
		byte += write(STDOUT_FD, params->converted, conv_len);
	}
	return (byte);
}

static void	ft_check_flag(t_params *params)
{
	if (params->flags->flag_minus || *params->precision != NOT_SPEC)
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
	if (*params->width <= *params->precision)
	{
		print_len = *params->precision;
		*params->width = 0;
		if (ft_atoi(params->converted) < 0)
		{
			if (!params->flags->flag_minus)
				++print_len;
//			put_prec += (*params->precision - ((ssize_t)conv_len - 1));
			++put_prec;
		}
	}
	else
		print_len = *params->width;
	if (conv_len < *params->precision || put_prec == 1)
		put_prec += (*params->precision - conv_len);
	if (*params->width <= conv_len && *params->precision <= conv_len
			&& *params->precision != 0 && put_prec != 1)
	{
		print_len = conv_len;
		put_prec = 0;
		*params->width = 0;
	}
	byte = ft_write_int(params, put_prec, print_len);
	return (byte);
}
