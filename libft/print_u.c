/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:24 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/19 21:43:14 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nblen(unsigned long int nb)
{
	int	numdigits;

	numdigits = 0;
	if (nb == 0)
		numdigits++;
	while (nb > 0)
	{
		nb = nb / 10;
		numdigits++;
	}
	return (numdigits);
}

int	print_u(unsigned int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		print_c('1');
		return (1);
	}
	if (nb >= 0 && nb <= 9)
		print_c(('0' + nb));
	else
	{
		print_u(nb / 10);
		print_u(nb % 10);
	}
	return (nblen(nb));
}
