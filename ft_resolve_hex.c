/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/19 20:48:41 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned int n)
{
	int	i;

	i = 1;
 	n /= 16;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_resolve_hex(unsigned long long n, int is_upper, t_flags flags)
{
	int	len;
	int	n_zeros;

	len = 0;
	n_zeros = 0;
	len = ft_num_len(n);
	if (flags.f_zero > len)
		n_zeros = flags.f_zero - len;
	if (flags.f_hash && n)
	{
		if (is_upper)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		len += 2;
	}
	ft_putnbr_hex(n, is_upper, n_zeros);
	ft_put_space(flags.f_minus, &len);
	return (len + n_zeros);
}
