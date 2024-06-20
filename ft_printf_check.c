/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:08:58 by rohta             #+#    #+#             */
/*   Updated: 2024/06/17 14:41:01 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_apply_args(char specifier, va_list args)
{
	char	*str;

	str = NULL;
	if (specifier == 'c')
		str = ft_apply_character(va_arg(args, int));
	else if (specifier == 's')
		str = ft_apply_string(va_arg(args, char *));
	else if (specifier == 'p')
		str = ft_apply_pointer(va_arg(args, size_t));
	else if (specifier == 'd' || specifier == 'i')
		str = ft_apply_desimals(va_arg(args, int), 10, DESIMALS);
	else if (specifier == 'u')
		str = ft_apply_hex(va_arg(args, unsigned int), 10, DESIMALS);
	else if (specifier == 'x')
		str = ft_apply_hex(va_arg(args, unsigned int), 16, LOW_HEX);
	else if (specifier == 'X')
		str = ft_apply_hex(va_arg(args, unsigned int), 16, UP_HEX);
	else if (specifier == '%')
		str = ft_apply_character(specifier);
	return (str);
}


static ssize_t	*ft_set_mod(char format, ssize_t *width, ssize_t *precision)
{
	if (format != '.')
		return (width);
	return (precision);
}

static char	*ft_check_mods(char *format, ssize_t *width, ssize_t *precision)
{
	char	*tmp;
	size_t	index;
	ssize_t	*mod;

	tmp = NULL;
	index = 0;
	if (format[index] == '.')
	{
		*precision = 0;
		++format;
	}
	while (ft_isdigit(format[index]))
		++index;
	tmp = ft_substr(format, 0, index);
	mod = ft_set_mod(*(format - 1), width, precision);
	*mod = ft_atoi(tmp);
	if (mod == precision)
		format += index;
	format = ft_check_mods(format, width, precision);
	free (tmp);
	return (format);
}

static char	*ft_check_flags(char *format, t_flags *flags)
{
	if (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			flags->flag_minus = true;
		if (*format == '+')
			flags->flag_plus = true;
		if (*format == ' ')
			flags->flag_space = true;
		if (*format == '0')
			flags->flag_zero = true;
		if (*format == '#')
			flags->flag_hashtag = true;
		++format;
	}
	return (format);
}

char	*ft_printf_check(t_params *params, char *format, va_list args)
{
	ft_init_params(params);
	format = ft_check_flags(++format, params->flags);
	format = ft_check_mods(format, params->width, params->precision);
	params->specifier = *format;
	params->converted = ft_apply_args(params->specifier, args);
	return (format);
}

