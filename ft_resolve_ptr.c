/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/13 01:51:32 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_resolve_ptr(void *ptr)
{
	int				i;
	unsigned int	addr;

	addr = (int)ptr;
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(addr, 0);
	i = 3;
	while (addr)
	{
		i++;
		addr /= 16;
	}
	return (i);
}
