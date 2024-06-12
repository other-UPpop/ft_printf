/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:35:52 by rohta             #+#    #+#             */
/*   Updated: 2024/06/10 12:43:41 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_manage_flags(t_parameters *params, ssize_t *len,
		long *index,size_t *pb)
{
	if(params->flags->by_minus)
	{
		ft_apply_perfixes(params, pb);
		ft_apply_precision(params, len, index, pb);
		ft_apply_conversion(params, len, pb);
		ft_apply_width(params, len, index, pb);
	}	
	else
	{
		ft_apply_zero_flag(params, len, index, pb);
		*(params->width) = ft_apply_width(params, len, index, pb);
		ft_apply_precision(params, len, index, pb);
		ft_apply_perfixes(params, pb);
		ft_apply_conversion(params, len, pb);
	}
}

size_t	ft_write_params(t_parameters *params)
{
	long	index;
	size_t	pb;
	ssize_t	len;

	pb = 0;
	index = 0;
	if (params->specifier == '%')
		return (write(STDOUT_FD, params->converted, sizeof(char)));
	if (params->flags->by_hashtag && *(params->converted) != '0')
		index += 2;
	if (params->specifier == 'c' && !*(params->converted))
		len = sizeof(char);
	else
		len = ft_strlen(params->converted);
	ft_manage_flags(params, &len, &index, &pb);
	return (pb);
}
