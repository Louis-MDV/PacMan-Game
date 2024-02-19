/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:30:11 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/19 21:43:23 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_id(int n)
{
	int			numdigits;
	long int	nb;

	nb = n;
	numdigits = 0;
	if (nb < 0)
	{
		nb = -nb;
		numdigits++;
	}
	if (nb == 0)
		numdigits++;
	while (nb > 0)
	{
		nb = nb / 10;
		numdigits++;
	}
	ft_putnbr_fd(n, 1);
	return (numdigits);
}
