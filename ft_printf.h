/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:21:34 by rohta             #+#    #+#             */
/*   Updated: 2024/06/10 09:07:27 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef FLAGS
#  define FLAGS "-+ 0#"
# endif

# ifndef PRINTF_ERROR
#  define PRINTF_ERROR -1
# endif

# ifndef NOT_SPEC
#  define NOT_SPEC -1
# endif

# ifndef BINARIES
#  define BINARIES "01"
# endif

# ifndef OCTALS
#  define OCTALS "012345667"
# endif

# ifndef DESIMALS
#  define DESIMALS "0123456789"
# endif

# ifndef U_HEXAS
#  define U_HEXAS "0123456789ABCDEF"
# endif

# ifndef L_HEXAS
#  define L_HEXAS "0123456789abcdef"
# endif

# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

typedef struct s_flags
{
	bool	by_minus;
	bool	by_plus;
	bool	by_space;
	bool	by_zero;
	bool	by_hashtag;
}	t_flags;

typedef struct s_parameters
{
	t_flags	*flags;
	ssize_t	*width;
	ssize_t	*precision;
	char		*converted;
	char		specifier;
}	t_parameters;

int	ft_printf(const char *str, ...);

char	*ft_check_params(t_parameters *params, char *format, va_list ap);
char	*ft_check_flags(char *format, t_flags *flags);
char	*ft_check_mods(char *format, ssize_t *width, ssize_t *precision);
ssize_t *ft_set_worp(char format, ssize_t *width, ssize_t *precision);

void	ft_init_params(t_parameters *params);
static void ft_init_falgs(t_flags *flags);
static void ft_init_smods(ssize_t *width, ssize_t *precision);

char	*ft_apply_specifier(char	specifier, va_list ap);

char	*ft_apply_string(char *str);
char	*ft_apply_pointer(size_t nbr);
char	*ft_apply_character(char c);

char	*ft_apply_itoa_base(long long nbr, size_t base_len, const char *base);
char	*ft_apply_itoa_hexas(unsigned long long nbr, size_t base_len, const char *base);

#endif
