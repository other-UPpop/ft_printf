/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:05:20 by rohta             #+#    #+#             */
/*   Updated: 2024/06/12 01:18:23 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	size_t	printf_byte;
	t_parameters	*params;

	printf_byte = 0;
	params = NULL;
	if (!format)
		return (printf_ERROR);
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			params = (t_parameters *)ft_calloc(1, sizeof(t_parameters));
			format = ft_check_params(params, (char *)format, arg_ptr);
		}
	}
}
