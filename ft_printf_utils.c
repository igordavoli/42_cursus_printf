/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:17:34 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/13 21:20:26 by idavoli-         ###   ########.fr       */
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

void	ft_putnbr_hex(unsigned int n, int is_upper)
{
	char	c;

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
		ft_putnbr_hex (n / 16, is_upper);
		ft_putnbr_hex (n % 16, is_upper);
	}
}

void	ft_putnbr(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd (n + '0', 1);
	else
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
}
