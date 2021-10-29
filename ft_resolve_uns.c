/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/28 23:07:18 by idavoli-         ###   ########.fr       */
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
	int num_len;
	int	len;

	n_zeros = 0;
	len = 0;
	num_len = ft_num_len(n);

	if (flags.f_zero > flags.p_dot && flags.p_dot < num_len
		&& flags.p_dot != -1)
		flags.f_width = flags.f_zero;

	if (flags.f_zero > flags.p_dot && flags.p_dot > num_len
		&& flags.p_dot != -1)
		flags.f_width = flags.f_zero - (flags.p_dot - num_len );

	len += ft_put_space(flags.f_width, num_len);
	if (flags.f_zero > len)
		n_zeros = flags.f_zero - (len + num_len);
	if (flags.p_dot > (len + num_len) - 1)
		n_zeros = flags.p_dot - (len + num_len);
	if (n_zeros < 0)
		n_zeros = 0;
	if (!(!n && !flags.p_dot))
		ft_putuns_zero(n, n_zeros);
	else
		num_len = 0;

	len += n_zeros + num_len;


	len += ft_put_space(flags.f_minus, len);
	return (len);
}
