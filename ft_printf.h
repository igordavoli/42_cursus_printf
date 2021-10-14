#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_resolve_chr(char c);
int		ft_resolve_str(char *str);
int		ft_resolve_dec(int n);
int		ft_resolve_hex(unsigned int n, int is_upper);
int		ft_resolve_ptr(void *ptr);
int		ft_resolve_uns(unsigned int n);
int		ft_resolve_prc(void);
void	ft_putnbr_hex(unsigned int n, int is_upper);
void	ft_putnbr(unsigned int n);


#endif
