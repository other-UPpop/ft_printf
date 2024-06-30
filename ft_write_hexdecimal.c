/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexdecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:01:37 by rohta             #+#    #+#             */
/*   Updated: 2024/06/30 19:42:59 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_write_flags(t_params *params, size_t *print_len)
{
	size_t	byte;

	byte = 0;
	if (params->flags->flag_hashtag || ft_strchr("p", params->specifier))
	{
		if (*params->converted != '0')
		{
			*print_len -= 2;
			if (ft_strchr("xp", params->specifier))
				byte += write(STDOUT_FD, "0x", 2);
			else
				byte += write(STDOUT_FD, "0X", 2);
		}
		else if (ft_strlen(params->converted) < *print_len)
			--(*print_len);
	}
	return (byte);
}

static size_t	ft_write_xp(t_params *params, ssize_t put_prec, size_t print_len)
{
	size_t	conv_len;
	size_t	byte;
	size_t	i;
	char	c;

	i = 0;
	byte = 0;
	c = ' ';
	conv_len = ft_strlen(params->converted);
	if ((*params->precision == 0 || *params->precision == NOT_SPEC) && params->dot)
	{
		if (*params->width == NOT_SPEC || *params->width == 0)
			print_len = 0;
		conv_len = 0;
	}
	if (params->flags->flag_zero)
		c = '0';
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len);
		while ((ssize_t)i++ < put_prec)
		{
			byte += write(STDOUT_FD, "0", 1);
			--print_len;
		}
		byte += write(STDOUT_FD, params->converted, conv_len);
		while (conv_len < print_len--)
			byte += write(STDOUT_FD, " ", 1);
	}
	else
	{
		if (params->flags->flag_zero && params->flags->flag_hashtag)
				byte +=ft_write_flags(params, &print_len);
		else if (put_prec != 0 && params->flags->flag_hashtag)
			print_len -= 2;	
		while (put_prec + conv_len < print_len--)
			byte += write(STDOUT_FD, &c, sizeof(char));
		if (put_prec != 0 && params->flags->flag_hashtag)
			byte += ft_write_flags(params, &print_len);
		while ((ssize_t)i++ < put_prec)
			byte += write(STDOUT_FD, "0", 1);
		if (!(params->flags->flag_zero) && put_prec == 0 )
			byte += ft_write_flags(params, &print_len);
		byte += write(STDOUT_FD, params->converted, conv_len);
	}
	return (byte);
}
static void	ft_check_flag(t_params *params)
{
	if (params->flags->flag_minus || *params->precision != NOT_SPEC)
			params->flags->flag_zero = false;
	params->flags->flag_space = false;
	params->flags->flag_plus = false;
	if (params->specifier == 'p')
	{
		params->flags->flag_hashtag = false;
		*params->precision = NOT_SPEC;
	}
}

size_t	ft_write_hex(t_params *params)
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
		if (conv_len < *params->precision)
			put_prec = *params->precision - conv_len;
	}
	else if (*params->width < conv_len && *params->precision < conv_len)
	{
		print_len = conv_len;
		put_prec = 0;
		*params->width = 0;
	}
	byte = ft_write_xp(params, put_prec, print_len);
	return (byte);
}
