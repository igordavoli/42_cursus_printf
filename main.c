/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 02:46:49 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/16 20:02:38 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	// char	c = 'F';
	// char *str = NULL;
	// int hex = 0xA;
	int	len;
	// void *p = ULONG_MAX;
	char  *s = "igor";

	len = ft_printf("% 5s\n", s);
	printf ("length  %d\n", len);
	len = printf("%5s\n", s);
	printf ("length  %d\n", len);

// 	len  = ft_atoi(s);
// 	printf ("length  %d\n", len);
// 	return (0);
}
