/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/19 09:27:08 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_flgs(int n, t_flags flags)
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

static int	ft_num_len(int n)
{
	int	i;

	i = 1;
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

int	ft_resolve_dec(int n, t_flags flags)
{
	int	n_zeros;
	int	len;

	n_zeros = 0;
	len = ft_num_len(n);
	len += ft_put_space(flags.f_width, len);
	len += ft_handle_flgs(n, flags);
	if (flags.f_zero > len)
		n_zeros = flags.f_zero - len;
	ft_putnbr_zero(n, n_zeros);
	len += ft_put_space(flags.f_minus, len);
	return (len + n_zeros);
}
