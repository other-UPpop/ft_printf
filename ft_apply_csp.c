/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:56:15 by rohta             #+#    #+#             */
/*   Updated: 2024/06/24 16:38:38 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_character(int arg)
{
	char	*str;

	str = NULL;
	if (arg)
	{
		str = ft_calloc(1, sizeof(char));
		if (str)
			*str = (char)arg;
	}
	else
	{
		str = ft_calloc(1, sizeof(char));
		*str = '\0';
	}
	return (str);
}

char	*ft_apply_string(char *arg)
{
	if (!arg)
		return (NULL);
	return (arg);
}

char	*ft_apply_pointer(size_t arg)
{
	char	*str;
	char	*tmp;
	if (!arg)
		return (NULL);
	tmp = ft_apply_hex(arg, 16, LOW_HEX);
	str = ft_strjoin("0x", tmp);
	return (str);
}
