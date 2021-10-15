/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:44:54 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/14 23:45:29 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_resolve_chr(char c);
int		ft_resolve_str(char *str);
int		ft_resolve_dec(int n);
int		ft_resolve_hex(unsigned long long n, int is_upper);
int		ft_resolve_ptr(unsigned long long ptr);
int		ft_resolve_uns(unsigned int n);
int		ft_resolve_prc(void);
void	ft_putnbr_hex(unsigned long long n, int is_upper);
void	ft_putnbr(unsigned int n);

#endif
