/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:13:45 by rohta             #+#    #+#             */
/*   Updated: 2024/06/10 12:39:56 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	pb;
	t_parameters	*params;

	pb = 0;
	params = NULL;
	if (!format)
		return (PRINTF_ERROR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			params = (t_parameters *)ft_calloc(1, sizeof(t_parameters));
			format = ft_check_params(params, (char *)format, ap);
			pb += ft_write_params(params);
			ft_free_params(params);
		}
		else
			pb += write(STDOUT_FD, &(*format), sizeof(char));
		++format;
	}
	va_end(ap);
	return (pb);
}
