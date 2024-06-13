/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:02:51 by rohta             #+#    #+#             */
/*   Updated: 2024/06/13 13:20:07 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef printf_ERROR
#  define printf_ERROR 0
# endif

# ifndef NOT_SPEC
#  define NOT_SPEC 0
# endif

# ifndef FLAGS
#  define FLAGS "-+ 0#"
# endif

# ifndef DESIMALS
#  define DESIMALS "0123456789"
# endif

# ifndef LOW_HEX;
#  define LOW_HEX "0123456789abcdef"
# endif

# ifndef UP_HEX;
#  define UP_HEX "012345678ABCDEF"
# endif

typedef struct s_flags
{
	bool	flag_minus;
	bool	flag_plus;
	bool	flag_space;
	bool	flag_zero;
	bool	flag_hashtag;
} t_flags;

typedef struct s_parameters
{
	t_flags	*flags;
	ssize_t	*width;
	ssize_t	*precision;
	ssize_t	*base;
	char		*converted;
	char		specifier;
} t_parameters;


char	*ft_check_params(t_parameters *params, char *format, va_list arg_ptr);
void	ft_initialize_params(t_parameters *params);
char	*ft_apply_base(long long arg, size_t base_len, char *base);
char	*ft_apply_hex(unsigned long long arg, size_t base_len, const char *base);
char	*ft_apply_character(char c);

#endif
