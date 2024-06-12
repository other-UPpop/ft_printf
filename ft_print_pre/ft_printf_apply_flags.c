/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:05:26 by rohta             #+#    #+#             */
/*   Updated: 2024/06/08 17:31:59 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_string(char *str)
{
	if (!str)
		return (NULL);
	return (ft_strdup(str));
}

char	*ft_apply_pointer(size_t nbr)
{
	char	*str;
	char	*tmp;

	if (!nbr)
		return (NULL);
	tmp = ft_apply_itoa_hexas(nbr, 16, L_HEXAS);
	str = ft_strjoin("0x", tmp);
	return (str);
}

char	*ft_apply_character(char c)
{
		char	*str;

		if(c)
		{
			str = ft_calloc(2, sizeof(char));
			*str = c;
		}
		else
			str = ft_calloc(1, sizeof(char));
		return (str);
}
