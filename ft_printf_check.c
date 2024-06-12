/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:33:41 by rohta             #+#    #+#             */
/*   Updated: 2024/06/12 22:32:02 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_apply_specifier(char specifier, va_list arg_ptr)
{
	char	*str;

	str = NULL;
	if (specifier == 'c')
		str = ft_apply_character(va_arg(arg_ptr, int));
	else if (specifier == 's')
		str = ft_apply_string(va_arg(arg_ptr, char *));
	else if (specifier == 'p')
		str = ft_apply_pointer(va_arg(arg_ptr, size_t));
	else if (specifier == 'd' || specifier == 'i')
		str = ft_apply_base(va_arg(arg_ptr, int), 10, DESIMALS);
	else if (specifier == 'u')
		str = ft_apply_base(va_arg(arg_ptr, unsigned int), 10, DESIMALS);
	else if (specifier == 'x')
		str = ft_apply_base(va_arg(arg_ptr, unsigned int), 16, LOW_HEX);
	else if (specifier == 'X')
		str = ft_apply_base(va_arg(arg_ptr, unsigned int), 16, UP_HEX);
	else if (specifier == '%')
		str = ft_apply_character(specifier);
	return (stred);
}

}
static ssize_t	*ft_witch_modifire(ssize_t *width, ssize_t *precision,
		char *format)
{
	if (*format != '.')
		return (width);
	return (precision);
}

static char	*ft_check_mod_length(ssize_t *width, ssize_t *precision,
		char *format)
{
	char	*temp;
	size_t	index;
	ssize_t	*modifire_length;

	index = 0;
	temp = NULL;
	if (format[index] == '.')
	{
		*precision = 0;
		++index;
	}
	while (ft_isdigit(*format))
		++index;
	if (!index)
		return (format);
	temp = ft_substr(format, 0, index);
	modifire_length = ft_witch_modifire(width, precision, format);
	*modifire_length = ft_atoi(temp);
	if (modifire_length == precision)
		format += index;
	format = ft_check_modifire_length(width, precision, format);
	free(temp);
	return (format);
}

static char	*ft_check_flags(t_flags *flags, char *format)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			flags->flag_minus = true;
		else if (*format == '+')
			flags->flag_plus = true;
		else if (*format == ' ')
			flags->flag_space = true;
		else if (*format == '0')
			flags->flag_zero = true;
		else if (*format == '#')
			flags->flag_hashtag = true;
		++format;
	}
	return (format);
}

char	*ft_check_params(t_parameters *params, char *format, va_list arg_ptr)
{
	ft_initialize_params(params);
	format = ft_check_flags(params->flags, (char *)++format);
	format = ft_check_mod_length(params->width, params->precision,
			(char *)format);
	params->specifier = *format;
	params->converted = ft_apply_specifier(params->specifier, arg_ptr);
}
