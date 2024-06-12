/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:04:47 by rohta             #+#    #+#             */
/*   Updated: 2024/06/11 14:12:36 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_specifier(char specifier, va_list ap)
{
	char	*str;

	str = NULL;
	if(specifier == 's')
		str = ft_apply_string(va_arg(ap, char *));
	else if (specifier == 'p')
		str = ft_apply_pointer(va_arg(ap, size_t));
	else if (specifier == 'd')
		str = ft_apply_itoa_base(va_arg(ap, int), 10, DESIMALS);
	else if (specifier == 'i')
		str = ft_apply_itoa_base(va_arg(ap, int), 10, DESIMALS);
	else if (specifier == 'u')
		str = ft_apply_itoa_base(va_arg(ap, unsigned int), 10, DESIMALS);
	else if (specifier == 'X')
		str = ft_apply_itoa_hexas(va_arg(ap, unsigned int), 10, U_HEXAS);
	else if (specifier == 'x')
		str = ft_apply_itoa_hexas(va_arg(ap, unsigned int), 10, L_HEXAS);
	else if (specifier == 'c')
		str = ft_apply_character(va_arg(ap, int));
	else if (specifier == '%')
		str = ft_apply_character(specifier);
	return (str);
}
