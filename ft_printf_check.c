/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:08:58 by rohta             #+#    #+#             */
/*   Updated: 2024/07/09 09:58:41 by rohta            ###   ########.fr       */
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


static char	*ft_check_mods(char *format, t_params *params)
{
	char	*tmp;
	size_t	index;
	size_t	start;
	ssize_t	*mod;

	index = 0;
	mod = params->width;
	tmp = NULL;
	while (ft_isdigit(format[index]) || format[index] == '.')
	{
		if (format[index] == '.')
		{
			params->dot = true;
			*params->precision = 0;
			mod = params->precision;
			++index;
		}
		start = index;
		while (ft_isdigit(format[index]))
			++index;
		tmp = ft_substr(format, start, index - start);
		*mod = ft_atoi(tmp);
		free (tmp);
		tmp = NULL;
	}
	return (format + index);
}

static char	*ft_check_flags(char *format, t_flags *flags)
{
	while (ft_strchr(FLAGS, *format))
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
	format = ft_check_mods(format, params);
	params->specifier = *format;
	params->converted = ft_apply_args(params->specifier, args);
	++format;
	return (format);
}

