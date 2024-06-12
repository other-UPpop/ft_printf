/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:44:35 by rohta             #+#    #+#             */
/*   Updated: 2024/06/08 18:34:04 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t *ft_set_worp(char format, ssize_t *width, ssize_t *precision)
{
	if (format == '.')
		return (precision);
	return (width);
}

char	*ft_check_mods(char *format, ssize_t *width, ssize_t *precision)
{
	char	*temp;
	size_t	index;
	ssize_t	*modifier;

	index = 0;
	temp = NULL;
	if (format[index] == '.')
	{
		*precision = 0;
		++format;
	}
	while (ft_isdigit(*format))
		++index;
	if (!index)
		return (format);
	temp = ft_substr(format, 0, index);
	modifier = ft_set_worp(*(format - 1), width, precision);
	*modifier = ft_atoi(temp);
	if (modifier == precision)
		format += index;
	format = ft_check_mods(format, width, precision);
	free (temp);
	return (format);
}

char	*ft_check_flags(char *format, t_flags *flags)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			flags->by_minus = true;
		else if (*format == '+')
			flags->by_plus = true;
		else if (*format == ' ')
			flags->by_space = true;
		else if (*format == '0')
			flags->by_zero = true;
		else if (*format == '#')
			flags->by_hashtag = true;
		++format;
	}
	return (format);
}

char	*ft_check_params(t_parameters *params, char *format, va_list ap)
{
	ft_init_params(params);
	format = ft_check_flags((char *)++format, params->flags);
	format = ft_check_mods((char *)format, params->width, params->precision);
	params->specifier = *format;
	params->converted = ft_apply_specifier(params->specifier, ap);
	return ((char *)format);
}
