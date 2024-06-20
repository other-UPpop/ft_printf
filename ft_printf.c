/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:37:52 by rohta             #+#    #+#             */
/*   Updated: 2024/06/20 16:58:49 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_free(t_params *params)
{
	free(params->flags);
	free(params->width);
	free(params->precision);
	free(params->converted);
	free(params);
}

static size_t	ft_printf_write(t_params *params)
{
	size_t	byte;

	byte = 0;
	if (ft_strchr("cs%", params->specifier))
		byte += ft_write_string(params);
	else if (ft_strchr("diu", params->specifier))
		byte += ft_write_number(params);
	else if (ft_strchr("pxX", params->specifier))
		byte += ft_write_hex(params);
	if (byte == 0)
		return (PRINTF_NULL);
	return (byte);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	byte;
	t_params	*params;

	byte = 0;
	params = NULL;
	if (!format)
		return (PRINTF_NULL);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			params = calloc(1, sizeof(t_params));
			format = ft_printf_check(params, (char *)format, args);
			byte += ft_printf_write(params);
			ft_printf_free(params);
		}
		else
		{
			byte += write(STDOUT_FD, format, sizeof(char));
			++format;
		}
	}
	va_end(args);
	return (byte);
}

