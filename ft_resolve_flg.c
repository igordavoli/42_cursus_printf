/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_flg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:38:59 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/16 19:45:12 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flg_init(void)
{
	t_flags		flags;

	flags.f_minus = 0;
	flags.f_zero = 0;
	flags.p_dot = 0;
	flags.f_hash = 0;
	flags.f_space = 0;
	flags.f_plus = 0;
	return (flags);
}

static int	ft_is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static char *ft_resolve_space(char *str, t_flags *flags)
{
	flags->f_space = ft_atoi(str);
	while (ft_isdigit(*str))
	str++;
	return (str - 1);
}

char	*ft_flg_get(t_flags *flags, char *str)
{
	while (!ft_is_type(*str))
	{
		if (*str == '-')
			flags->f_minus = 1;
		if (*str == '0')
			flags->f_minus = 1;
		if (*str == '.')
			flags->p_dot = 1;
		if (*str == '#')
			flags->f_hash = 1;
		if (*str == ' ')
			str = ft_resolve_space(str + 1, flags);
		if (*str == '+')
			flags->f_plus = 1;
		str++;
	}
	return (str);
}
