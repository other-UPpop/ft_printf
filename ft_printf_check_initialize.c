/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_initialize.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:39:34 by rohta             #+#    #+#             */
/*   Updated: 2024/06/12 01:19:42 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initialize_length(t_parameters *params)
{
	*(params->width) = NOT_SPEC;
	*(params->precision) = NOT_SPEC;
	*(params->base) = NOT_SPEC;
}

static void	ft_initialize_flags(t_flags *flags)
{
	flags->flag_minus = false;
	flags->flag_plus = false;
	flags->flag_space = false;
	flags->flag_zero = false;
	flags->flag_hashtag = false;
}

void	ft_initialize_params(t_parameters *params)
{
	params->flags = (t_flags *)calloc(1, sizeof(t_parameters));
	params->width = (ssize_t *)calloc(1, sizeof(t_parameters));
	params->precision = (ssize_t *)calloc(1, sizeof(t_parameters));
	params->base = (ssize_t *)calloc(1, sizeof(t_parameters));
	ft_initialize_flags(params->flags);
	ft_initialize_length(params);
}
