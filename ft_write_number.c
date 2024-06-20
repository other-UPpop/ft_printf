/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:19:03 by rohta             #+#    #+#             */
/*   Updated: 2024/06/20 15:48:23 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
size_t	ft_write_flags(t_params *params, size_t *print_len, size_t *put_prec)
{
	size_t	byte;
	int	sign;

	byte = 0;
	sign = ft_atoi(params->converted);
	if (params->flags->flag_plus || 0 < sign)
	{
			byte += write(STDOUT_FD, "+", sizeof(char));
			--(*print_len);
			--(*put_prec);
	}
	else if (params->flags->flag_space || 0 < sign)
	{
		byte += write(STDOUT_FD, " ", sizeof(char));
		--(*print_len);
		--(*put_prec);
	}
	return (byte);
}

static size_t	ft_write_int(t_params *params, size_t put_prec)
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
		if (*params->precision == NOT_SPEC)
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
	if (params->flags->flag_plus)
		 params->flags->flag_space = false;
}

static size_t	ft_width_size(t_params *params, size_t conv_len)
{
	if (conv_len < *params->width && params->precision < params->width)
		return (*params->width - conv_len);
	return (0);
}

size_t	ft_write_number(t_params *params)
{
	size_t	conv_len;
	size_t	put_prec;
	size_t	put_width;
	size_t	byte;

	put_prec = 0;
	conv_len = ft_strlen(params->converted);
	put_width = ft_width_size(params ,conv_len);
	ft_check_flag(params);
	if (params->width < params->precision && conv_len < *params->precision)
		put_width = 0;
	put_prec = *params->precision - conv_len;
	byte = ft_write_int(params, put_prec);
	return (byte);
}

