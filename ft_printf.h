/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:44:54 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/17 00:10:40 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	f_minus;
	int	f_zero;
	int	p_dot;
	int	f_hash;
	int	f_space;
	int	f_plus;
}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_resolve_chr(char c);
int		ft_resolve_str(char *str, t_flags flags);
int		ft_resolve_dec(int n, t_flags flags);
int		ft_resolve_hex(unsigned long long n, int is_upper, t_flags flags);
int		ft_resolve_ptr(unsigned long long ptr);
int		ft_resolve_uns(unsigned int n, t_flags flags);
int		ft_resolve_prc(void);
void	ft_putnbr_hex(unsigned long long n, int is_upper, int n_zeros);
void	ft_putuns_zero(unsigned int n, int n_zeros);

t_flags	ft_flg_init(void);
char	*ft_flg_get(t_flags *flags, char *src);

void	ft_putnbr_zero(int n, int n_zeros);

#endif
