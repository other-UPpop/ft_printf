/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:19:03 by rohta             #+#    #+#             */
/*   Updated: 2024/07/18 19:35:26 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_write_flags(t_params *params, size_t *print_len,
		size_t *conv_len, int *number)
{
	bool	plus_space;
	size_t	byte;

	byte = 0;
	plus_space = (params->flags->flag_plus || params->flags->flag_space);
	if (*number < 0 && *params->converted != '0')
	{
		byte += write(STDOUT_FD, "-", sizeof(char));
		if (0 < *print_len)
			--(*print_len);
		--(*conv_len);
		params->converted = ft_substr(params->converted, 1,
				(size_t)conv_len);
	}
	else if (plus_space && 0 <= *number)
	{
		if (((*number < 0 && params->flags->flag_minus)
				|| (!params->flags->flag_zero)) && (0 < *print_len))
			--(*print_len);
		if (params->flags->flag_plus)
			byte += write(STDOUT_FD, "+", sizeof(char));
		else
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	return (byte);
}

static	void	ft_print_len(t_params *params, bool plus_space,
		int number, size_t *print_len)
{
	if ((plus_space && number < 0 && 0 < *print_len)
		|| (plus_space && 0 < *print_len && !params->flags->flag_minus))
		--(*print_len);
}

static	int	ft_zero_check(t_params *params, char *c)
{
	if (params->flags->flag_zero && *params->precision == NOT_SPEC)
	{
		*c = '0';
		return (1);
	}
	return (0);
}

static	size_t	ft_write_prec(t_params *params, size_t put_prec,
		size_t *print_len, size_t conv_len)
{
	size_t	i;
	size_t	byte;

	i = 0;
	byte = 0;
	if (params->flags->flag_minus)
	{
		while (i++ < put_prec && (*print_len)--)
			byte += write(STDOUT_FD, "0", sizeof(char));
		byte += write(STDOUT_FD, params->converted, conv_len);
	}
	else
	{
		while (i++ < put_prec)
			byte += write(STDOUT_FD, "0", sizeof(char));
		byte += write(STDOUT_FD, params->converted, conv_len);
	}
	return (byte);
}

//static	size_t	ft_write_width(t_params *params, size_t put_prec,
//		size_t conv_len, size_t *print_len)
//{
//	size_t	byte;
//	char	c;
//
//	byte = 0;
//	c = ' ';
//	if (params->flags->flag_minus)
//	{
//		while (conv_len < (*print_len)--)
//			byte += write(STDOUT_FD, " ", sizeof(char));
//	}
//	else
//	{
//		ft_zero_check(params, &c);
//		while (put_prec + conv_len < (*print_len)--)
//			byte += write(STDOUT_FD, &c, sizeof(char));
//	}
//	return (byte);
//}

static size_t	ft_write_int(t_params *params, size_t put_prec,
		size_t print_len, size_t conv_len)
{
	size_t	byte;
//	size_t	i;
	bool	plus_space;
	char	c;
	int		number;

//	i = 0;
	byte = 0;
	plus_space = (params->flags->flag_plus || params->flags->flag_space);
	c = ' ';
	number = ft_atoi(params->converted);
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len, &conv_len, &number);
//		while (i++ < put_prec && print_len--)
//			byte += write(STDOUT_FD, "0", sizeof(char));
//		byte += write(STDOUT_FD, params->converted, conv_len);
		byte += ft_write_prec(params, put_prec, &print_len, conv_len);
		ft_print_len(params, plus_space, number, &print_len);
		while (conv_len < print_len--)
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	else
	{
		if (ft_zero_check(params, &c) == 1)
			byte += ft_write_flags(params, &print_len, &conv_len, &number);
		ft_print_len(params, plus_space, number, &print_len);
//		byte += ft_write_prec(params, put_prec, &print_len, conv_len);
		while (put_prec + conv_len < print_len--)
			byte += write(STDOUT_FD, &c, sizeof(char));
		if (c == ' ')
			byte += ft_write_flags(params, &print_len, &conv_len, &number);
		byte += ft_write_prec(params, put_prec, &print_len, conv_len);
//		while (i++ < put_prec)
//			byte += write(STDOUT_FD, "0", sizeof(char));
//		byte += write(STDOUT_FD, params->converted, conv_len);
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
	int		number;

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
	return (ft_write_int(params, put_prec, print_len, conv_len));
}
