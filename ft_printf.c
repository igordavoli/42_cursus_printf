/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:54:47 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/16 18:56:20 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(char c, va_list args, t_flags flags)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_resolve_chr(va_arg(args, int));
	if (c == 's')
		len = ft_resolve_str(va_arg(args, char *), flags);
	if (c == 'd' || c == 'i')
		len = ft_resolve_dec(va_arg(args, int), flags);
	if (c == 'u')
		len = ft_resolve_uns(va_arg(args, unsigned int));
	if (c == 'p')
		len = ft_resolve_ptr(va_arg(args, unsigned long long));
	if (c == 'x')
		len = ft_resolve_hex(va_arg(args, unsigned int), 0, flags);
	if (c == 'X')
		len = ft_resolve_hex(va_arg(args, unsigned int), 1, flags);
	if (c == '%')
		len = ft_resolve_prc();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		length;
	char	*s;

	s = (char *)str;
	va_start(args, str);
	length = 0;
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar_fd(*s++, 1);
			length++;
		}
		else
		{
			s++;
			flags = ft_flg_init();
			s = ft_flg_get(&flags, s);
			length += ft_select_format(*s++, args, flags);
		}
	}
	va_end(args);
	return (length);
}
