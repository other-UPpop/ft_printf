/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:46:42 by rohta             #+#    #+#             */
/*   Updated: 2024/06/08 16:02:43 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_init_smods(ssize_t *width, ssize_t *precision)
{
	*width = NOT_SPEC;
	*precision = NOT_SPEC;
}

static void ft_init_falgs(t_flags *flags)
{
	flags->by_minus = false;
	flags->by_plus = false;
	flags->by_space = false;
	flags->by_zero = false;
	flags->by_hashtag = false;
}

void	ft_init_params(t_parameters *params)
{
	params->flags = (t_flags *)ft_calloc(1, sizeof(t_flags));
	params->width = (ssize_t *)ft_calloc(1, sizeof(ssize_t));
	params->precision = (ssize_t *)ft_calloc(1, sizeof(ssize_t));
	ft_init_falgs(params->flags);
	ft_init_smods(params->width, params->precision);
}
