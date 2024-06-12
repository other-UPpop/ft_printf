/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:36:53 by rohta             #+#    #+#             */
/*   Updated: 2024/06/10 12:40:26 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_params(t_parameters *params)
{
	free(params->flags);
	free(params->width);
	free(params->precision);
	free(params->converted);
	free(params);
}
