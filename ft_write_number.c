/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:19:03 by rohta             #+#    #+#             */
/*   Updated: 2024/07/13 21:12:21 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_write_flags(t_params *params, size_t *print_len, 
		size_t *conv_len, int *number)
{
	bool plus_space;
	size_t	len;
	size_t	byte;

	len = ft_strlen(params->converted);
	byte = 0;
	plus_space = false;
	if(params->flags->flag_plus || params->flags->flag_space)
		plus_space = true;
	if ((*number < 0 && *params->converted != '0')
		&& ((size_t)*params->precision > len - 1 || plus_space))
	{
		byte += write(STDOUT_FD, "-", sizeof(char));
		if (0 < *print_len)
			--(*print_len);
		--(*conv_len);
		params->converted = ft_substr(params->converted, 1,
				(size_t)conv_len);
	}
	if (plus_space && 0 <= *number)
	{
		if (0 < *print_len)
		{
			if (!params->flags->flag_zero)
				--(*print_len);
			if ((conv_len + 1) < print_len && 0 < *print_len)
				*print_len -= *conv_len + 1;
			if (*number < 0 && params->flags->flag_minus 
					&& (ssize_t)*conv_len < *params->width)
				--(*print_len);
		}
		if (params->flags->flag_plus)
			byte += write(STDOUT_FD, "+", sizeof(char));
		else
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	return (byte);
}

static size_t	ft_write_int(t_params *params, size_t put_prec,
		size_t print_len, size_t conv_len, int number)
{
	bool plus_space;
	size_t	byte;
	size_t	i;
	char	c;

	i = 0;
	byte = 0;
	plus_space = false;
	if(params->flags->flag_plus || params->flags->flag_space)
		plus_space = true;
	c = ' ';
	if (params->flags->flag_zero && *params->precision == NOT_SPEC)
		c = '0';
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len, &conv_len, &number);
		while (i++ < put_prec && print_len--)
			byte += write(STDOUT_FD, "0", sizeof(char));
		byte += write(STDOUT_FD, params->converted, conv_len);
		if (plus_space && number < 0 && 0 < print_len)
			--print_len;
		while (conv_len < print_len--)
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	else
	{
		if (c == '0')
			byte += ft_write_flags(params, &print_len, &conv_len, &number);
		if (plus_space && 0 < print_len)
					--print_len;
		while (put_prec + conv_len < print_len--)
			byte += write(STDOUT_FD, &c, sizeof(char));
		if (c == ' ')
			byte += ft_write_flags(params, &print_len, &conv_len, &number);
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
	int	number;
	size_t	print_len;
	size_t	put_prec;
	ssize_t	conv_len;

	print_len = 0;
	put_prec = 0;
	conv_len = ft_strlen(params->converted);
	number = ft_atoi(params->converted);
	ft_check_flag(params);
	print_len = *params->width;
	if (*params->width <= *params->precision && params->dot)
	{
		print_len = *params->precision;
		if (number < 0)
		{
			if (!params->flags->flag_minus || conv_len < *params->width)
				++print_len;
			if (0 < *params->precision)
				++put_prec;
		}
	}
	if (conv_len < *params->width && number < 0
			&& (params->flags->flag_plus || params->flags->flag_space))
		++print_len;
	if (*params->precision != 0)
	{
		if (put_prec == 1 || conv_len < *params->precision)
				put_prec += (*params->precision - conv_len);
		if (*params->width <= conv_len && *params->precision <= conv_len
				&& put_prec != 1)
		{
			print_len = conv_len;
			put_prec = 0;
			*params->width = 0;
		}
	}
	if (*params->precision == 0 && number == 0)
			conv_len = 0;
	else if (number < 0 && ((ssize_t)conv_len - 1 < *params->precision)
			&& *params->width > *params->precision)
		++put_prec;
	return (ft_write_int(params, put_prec, print_len, conv_len, number));
}
