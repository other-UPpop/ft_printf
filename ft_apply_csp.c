/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:56:15 by rohta             #+#    #+#             */
/*   Updated: 2024/06/28 12:18:00 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_character(int arg)
{
	char	*str;

	str = NULL;
	str = ft_calloc(1, sizeof(char));
//	if (!ft_isascii(arg))
//	{
//		*str = ' '; 
//		return (str);
//	}
	if (str)
	{
		if (arg)
			*str = (char)arg;
		else
			*str = '\0';
	}
	return (str);
}

char	*ft_apply_string(char *arg)
{
	char	*str;

	if (!arg)
		return (ft_strdup("(NULL)"));
	else
		str = ft_strdup(arg);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_apply_pointer(size_t arg)
{
	char	*str;

	if (!arg)
		return (ft_strdup("0"));
	str = ft_apply_hex(arg, 16, LOW_HEX);
	if (!str)
		return (NULL);
	return (str);
}
