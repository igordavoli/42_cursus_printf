/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/19 09:04:17 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_resolve_uns(unsigned int n, t_flags flags)
{
	int	n_zeros;
	int	len;

	n_zeros = 0;
	len = ft_num_len(n);
	if (flags.f_zero > len)
		n_zeros = flags.f_zero - len;
	ft_putuns_zero(n, n_zeros);
	len += ft_put_space(flags.f_minus, len);
	return (len + n_zeros);
}
