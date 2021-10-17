/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:30:00 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/17 00:48:07 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_resolve_ptr(unsigned long long ptr)
{
	int	i;

	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(ptr, 0, 0);
	ptr /= 16;
	i = 3;
	while (ptr)
	{
		i++;
		ptr /= 16;
	}
	return (i);
}
