/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:54:47 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/14 20:46:48 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_resolve_chr(va_arg(args, int));
	if (c == 's')
		len = ft_resolve_str(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		len = ft_resolve_dec(va_arg(args, int));
	if (c == 'u')
		len = ft_resolve_uns(va_arg(args, unsigned int));
	if (c == 'p')
		len = ft_resolve_ptr(va_arg(args, unsigned long long));
	if (c == 'x')
		len = ft_resolve_hex(va_arg(args, unsigned int), 0);
	if (c == 'X')
		len = ft_resolve_hex(va_arg(args, unsigned int), 1);
	if (c == '%')
		len = ft_resolve_prc();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		lengths;

	va_start(args, str);
	lengths = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		else
			lengths += ft_select_format(str[++i], args) - 2;
		i++;
	}
	va_end(args);
	return (i + lengths);
}
