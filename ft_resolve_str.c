/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 04:36:29 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/19 19:25:24 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnstr(char *str, int n)
{
	char	*s;

	s = str;
	while (n-- && *str)
		ft_putchar_fd(*str++, 1);
	return (str - s);
}

static int	ft_put_space_str(int spaces, int str_len)
{
	int	n_spaces;
	int	len;

	if (!spaces)
		return (0);
	n_spaces = spaces - str_len;
	if (n_spaces > 0)
	{
		len = n_spaces;
		while (n_spaces)
		{
			ft_putchar_fd(' ', 1);
			n_spaces--;
		}
		return (len);
	}
	return (0);
}

static void	ft_handle_flgs(int str_len, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.f_space)
	{
		while (flags.f_space - i++ - str_len)
			ft_putchar_fd(' ', 1);
	}
}

int	ft_resolve_str(char *str, t_flags flags)
{
	int	str_len;
	int	len;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	str_len = ft_strlen(str);
	str_len += ft_put_space(flags.f_width, str_len);
	if (flags.f_space > str_len)
	{
		len = flags.f_space;
		ft_handle_flgs(str_len, flags);
	}
	else
		len = str_len;
	if (flags.p_dot >= 0 && ft_strlen(str))
		len = ft_putnstr(str, flags.p_dot);
	else
		ft_putstr_fd(str, 1);
	len += ft_put_space_str(flags.f_minus, str_len);
	return (len);
}
