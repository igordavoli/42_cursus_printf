/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:09:11 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/29 20:49:13 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int n, int base)
{
	int	i;

	i = 1;
	n /= base;
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

void	ft_handle_zero_dot(unsigned int n, int *num_len, t_flags *flags)
{
	if (flags->f_zero > flags->p_dot && flags->p_dot < *num_len
		&& flags->p_dot != -1)
		flags->f_width = flags->f_zero;
	if (flags->f_zero > flags->p_dot && flags->p_dot > *num_len
		&& flags->p_dot != -1)
		flags->f_width = flags->f_zero - (flags->p_dot - *num_len);
	if (!n && !flags->p_dot)
		*num_len = 0;
}
