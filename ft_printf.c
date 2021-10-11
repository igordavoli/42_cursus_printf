/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 02:46:34 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/11 04:35:03 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(char c , va_list args)
{
	int	len;

	len = 0;
	if (c == 'd')
		len = ft_resolve_dec(va_arg(args, int));
	if (c == 's')
		len = ft_resolve_str(va_arg(args, char *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int lengths;

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
	return(i + lengths);
}
