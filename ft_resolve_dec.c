/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/16 01:38:15 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_flgs(int n,t_flags flags)
{
	if (flags.f_plus && n >= 0)
	{
		ft_putchar_fd('+', 1);
		return (1);
	}
	if (flags.f_space && n >= 0)
	{
		ft_putchar_fd(' ', 1);
		return (1);
	}
	return (0);
}

int	ft_resolve_dec(int n, t_flags flags)
{
	int	i;

	i = 1;
	i += ft_handle_flgs(n, flags);
	ft_putnbr_fd(n, 1);
	if (n < 0)
	{
		i += 1;
		n *= -1;
	}
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}
