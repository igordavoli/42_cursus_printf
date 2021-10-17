/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:17:34 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/17 00:11:27 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr_c(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

void	ft_putnbr_hex(unsigned long long n, int is_upper, int n_zeros)
{
	char	c;
	while (n_zeros)
	{
		ft_putchar_fd('0', 1);
			n_zeros--;
	}
	if (n < 16)
	{
		c = n;
		if (n > 9 )
			c += 87;
		else
			c += '0';
		if (c >= 'a' && is_upper)
			c -= 32;
		ft_putchar(c);
	}
	else
	{
		ft_putnbr_hex (n / 16, is_upper, n_zeros);
		ft_putnbr_hex (n % 16, is_upper, n_zeros);
	}
}

void	ft_putuns_zero(unsigned int n, int n_zeros)
{
	while (n_zeros)
	{
			ft_putchar_fd('0', 1);
				n_zeros--;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putuns_zero(n / 10, n_zeros);
		ft_putuns_zero(n % 10, n_zeros);
	}
}

void	ft_putnbr_zero(int n, int n_zeros)
{


	if (n == -2147483648)
	{
		ft_putchar_fd('-',1);
		while (n_zeros)
		{
			ft_putchar_fd('0', 1);
				n_zeros--;
		}
		ft_putchar_fd('2',1);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-',1);
		while (n_zeros)
		{
			ft_putchar_fd('0', 1);
			n_zeros--;
		}
	}
	while (n_zeros)
	{
		ft_putchar_fd('0', 1);
			n_zeros--;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0',1);
	}
	else
	{
		ft_putnbr_zero(n / 10, n_zeros);
		ft_putnbr_zero(n % 10, n_zeros);
	}
}
