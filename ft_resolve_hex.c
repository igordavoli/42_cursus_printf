/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/16 01:34:09 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_resolve_hex(unsigned long long n, int is_upper, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.f_hash && n)
	{
		if (is_upper)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		i += 2;
	}
	ft_putnbr_hex(n, is_upper);
	n /= 16;
	i += 1;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}
