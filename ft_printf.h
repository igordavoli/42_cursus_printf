/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:44:54 by idavoli-          #+#    #+#             */
/*   Updated: 2021/11/02 02:09:39 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	f_minus;
	int	f_zero;
	int	p_dot;
	int	f_hash;
	int	f_space;
	int	f_plus;
	int	f_width;
}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_resolve_chr(char c, t_flags flags);
int		ft_resolve_str(char *str, t_flags flags);
int		ft_resolve_dec(int n, t_flags flags);
int		ft_resolve_hex(unsigned long long n, int is_upper, t_flags flags);
int		ft_resolve_ptr(unsigned long long ptr, t_flags flags);
int		ft_resolve_uns(unsigned int n, t_flags flags);
int		ft_put_space(int spaces, int str_len);
int		ft_num_len(unsigned int n, int base);
int		ft_num_len_int(int n);
void	ft_putnbr_hex(unsigned long long n, int is_upper, int n_zeros);
void	ft_putuns_zero(unsigned int n, int n_zeros);
void	ft_putnbr_zero(int n, int n_zeros, int len);
void	ft_handle_zero_dot(unsigned int n, int *num_len, t_flags *flags);
char	*ft_flg_get(t_flags *flags, char *src);
t_flags	ft_flg_init(void);

#endif
