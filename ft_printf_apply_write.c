/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_write.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:24:40 by rohta             #+#    #+#             */
/*   Updated: 2024/06/10 09:47:45 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_apply_perixs(t_parameters *params, size_t *pb)
{
	if (params->flags->by_plus)
	{
		params->flags->by_space = false;
		if (ft_atoi(params->converted) >= 0)
			*pb += write(STDOUT_FD, "+", sizeof(char));
	}
	if (params->flags->by_space && ft_strchr("id", params->specifier))
		if (ft_atoi(params->converted) >= 0)
			*pb += write(STDOUT_FD, " ", sizeof(char));
	if (params->flags->by_hashtag && ft_strchr("oxX", params->specifier
				&& *(params->converted) != '0'))
	{
		*pb += write(STDOUT_FD, "0", sizeof(char));
		if (ft_strrchr("xX", params->specifier))
			*pb += write(STDOUT_FD, &(params->specifier), sizeof(char));
	}
}
