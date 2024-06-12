/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:26:13 by rohta             #+#    #+#             */
/*   Updated: 2024/06/13 00:37:23 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_arg_len_hex(unsigned long long arg, size_t base_len)
{
	size_t len;

	len = 0;
	if (arg == 0)
		++len;
	while (arg)
	{
		arg /= base_len;
		++len;
	}
	return (len);
}

char	*ft_apply_hex(unsigned long long arg, size_t base_len, const char *base)
{
	char	*str;
	size_t	len;

	len = ft_arg_len_hex(arg, base_len);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (arg == 0)
	{
		*str = '0';
		return (str);
	}
	while (len)
	{
		str[--len] = base[arg % base_len];
		arg /= base_len;
	}
	return (str);
}
