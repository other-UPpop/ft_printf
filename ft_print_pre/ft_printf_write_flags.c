/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:09:38 by rohta             #+#    #+#             */
/*   Updated: 2024/06/11 14:13:22 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_lputstr_fd(char *s, int fd)
{
	size_t	written_bytes;

	written_bytes = 0;
	if (!s)
		return (write(fd, NULL, ft_strlen(NULL)));
	while (*s)
		written_bytes += write(fd, s++, sizeof(char));
	return (written_bytes);
}

void	ft_apply_zero_flag(t_parameters *params, ssize_t *len, long *index, size_t *pb)
{
	if (params->flags->by_zero && *(params->precision) == NOT_SPEC)
	{
		if (ft_atoi(params->converted) < 0
				&& ft_strchr("id", params->specifier))
			*pb += write(STDOUT_FD, "-", sizeof(char));
		while (++(*index) < (long)(*(params->width) - *len
					- params->flags->by_plus - params->flags->by_space))
			*pb += write(STDOUT_FD, "0", sizeof(char));
		*(params->width) = 0;
	}
}

ssize_t	ft_apply_width(t_parameters *params, ssize_t *len, long *index, size_t *pb)
{
		if (*(params->width))
		{
			if (*len <= *(params->precision) && params->specifier != 's')
				*(params->width) = *(params->width) - *(params->precision)\
				- (ft_atoi(params->converted) < 0 || (*(params->converted) == '0' \
				&& params->flags->by_minus)) + *len;
			else if (*len > *(params->precision) && params->specifier == 's'
					&& *(params->precision) != NOT_SPEC && !params->flags->by_minus)
				*(params->width) = *params->width - *params->precision + *len;
			while (++(*index) < (long)(*(params->width) - *len - params->flags->by_plus))
				*pb += write(STDOUT_FD, " ", sizeof(char));
			if (!params->flags->by_minus)
				*index = 0;
		}
		return (*(params->width));
}

void	ft_apply_conversion(t_parameters *params, ssize_t *len, size_t *pb)
{
	if (params->specifier == 'c' && !*(params->converted))
		pb += write(STDOUT_FD, &*(params->converted), sizeof(char));
	else if (((params->flags->by_zero && *(params->precision))
				|| *(params->precision) > 0) && ft_atoi((params->converted)) < 0
			&& ft_strchr("id", params->specifier))
			*pb += ft_lputstr_fd(params->converted + 1, STDOUT_FD);
	else if (!*(params->precision)
			&& *(params->width) && *(params->converted) == '0')
	{
		if (*(params->width) != NOT_SPEC)
			while (--(*len))
				*pb += write(STDOUT_FD, "", sizeof(char));
	}
	else if (params->specifier == 's' && !(params->flags->by_space)
			&& *(params->precision) < *len && *(params->converted) != NOT_SPEC)
	{
		if (ft_strncmp((params->converted), NULL, *len))
		{
			*pb += write(STDOUT_FD, params->converted, *(params->precision));
			if (params->flags->by_minus)
				*len = *(params->precision);
		}
	}
	else
		*pb += ft_lputstr_fd(params->converted, STDOUT_FD);
}

void	ft_apply_precision(t_parameters *params, ssize_t *len, long *index, size_t *pb)
{
	if (*(params->precision) > 0 && params->specifier != 's')
	{
		if (ft_atoi(params->converted) < 0
				&& ft_strchr("di", params->specifier))
		{
			--(*len);
			*pb += (write(STDOUT_FD, "-", sizeof(char)));
		}
		while ((*index)++ < (long)(*(params->precision) 
					- *len - params->flags->by_plus - params->flags->by_space))
			*pb += (write(STDOUT_FD, "0", sizeof(char)));
		if (params->flags->by_minus)
			*index = 0;
	}
}

void ft_apply_perfixes(t_parameters *params, size_t *pb)
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
	if (params->flags->by_hashtag && ft_strchr("xX", params->specifier
				&& *(params->converted) != '0'))
	{
		*pb += write(STDOUT_FD, "0", sizeof(char));
		*pb += write(STDOUT_FD, &(params->specifier), sizeof(char));
	}
}

