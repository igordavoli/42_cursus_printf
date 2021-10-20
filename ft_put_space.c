/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:09:11 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/19 20:52:30 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_space(int spaces, int *str_len)
{
	int	n_spaces;
	int	len;

	if (spaces)
	{
		spaces--;
		n_spaces = spaces - (*str_len - 1);
		if (n_spaces > 0)
		{
			len = n_spaces;
			while (n_spaces)
			{
				ft_putchar_fd(' ', 1);
				n_spaces--;
			}
			*str_len += len;
		}
	}
}