/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:51:28 by rohta             #+#    #+#             */
/*   Updated: 2024/06/13 00:01:11 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_arg_len(long long arg, size_t base_len)
{
	size_t	arg_len;

	arg_len = 0;
	if (arg < 0)
	{
		arg = -arg;
		++arg_len;
	}
	while (arg)
	{
		arg /= base_len;
		++arg_len;
	}
	return (arg_len);
}

char	*ft_apply_base(long long arg, size_t base_len, char *base)
{
	char	*str;
	size_t	len;

	len = ft_arg_len(arg, base_len);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (arg == '0')
	{
		str[0] = '0';
		return (str);
	}
	else if (arg < 0)
	{
		str[0] = '-';
		arg = -arg;
	}
	while (len)
	{
		str[--len] = base[arg % base_len];
		arg /= base_len;
	}
	return (str);
}
