/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:12:05 by rohta             #+#    #+#             */
/*   Updated: 2024/06/13 13:20:50 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_character(char c)
{
	char	*str;

	if (c)
	{
		str = ft_calloc(2, sizeof(char));
		*str = c;
	}
	else
		str = ft_calloc(1, sizeof(char));
	return (str);
}
