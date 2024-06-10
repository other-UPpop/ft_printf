/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_itoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:32:22 by rohta             #+#    #+#             */
/*   Updated: 2024/06/08 18:08:17 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char ft_base_len(long long nbr, size_t base_len)
	{
		size_t	len;

		len = 0;
		if (nbr <= 0)
		{
			nbr = -nbr;
			++len;
		}
		while (nbr)
		{
			nbr /= base_len;
			++len;
		}
		return (len);
	}

static char	ft_base_chk(size_t *chk, char c)
{
	(*chk)++;
	return (c);
}

char	*ft_apply_itoa_base(long long nbr, size_t base_len, const char *base)
{
	char	*str;
	size_t	len;
	size_t	chk;

	len = ft_base_len(nbr, base_len);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	chk = 0;
	if (!str)
		return (NULL);
	if (!nbr)
	{
		*str = ft_base_chk(&chk, '0');
		return (str);
	}
	else if (nbr < 0)
	{
		*str = ft_base_chk(&chk, '-');
		nbr = -nbr;
	}
	while (len > chk)
	{
		str[--len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (str);
}

static size_t ft_hex_len(unsigned long long nbr, size_t base_len)
{
	size_t	len;

	len = 0;
	if (!nbr)
		++len;
	while (nbr)
	{
		nbr /= base_len;
		++len;
	}
	return (len);
}

char	*ft_apply_itoa_hexas(unsigned long long nbr, size_t base_len, const char *base)
{
	char	*str;
	size_t	len;

	len = ft_hex_len(nbr, base_len);
	str = ft_calloc(len + 1, sizeof(char));
	if (!nbr)
	{
		*str = '0';
		return (str);
	}
	while (len > 0)
	{
		str[--len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (str);
}
