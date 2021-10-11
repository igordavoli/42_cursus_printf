#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <string.h>
#include <stdio.h>

# include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_resolve_dec(int n);
int	ft_resolve_str(char *str);

#endif
