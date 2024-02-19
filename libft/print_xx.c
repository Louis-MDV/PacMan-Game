/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:15:44 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/19 21:49:47 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_xx(unsigned long nb, char format, int numdigits)
{
	char	*hexbase;

	hexbase = "0123456789abcdef0123456789ABCDEF";
	if (nb < 16)
	{
		if (format == 'x')
			numdigits += print_c(hexbase[nb % 16]);
		else if (format == 'X')
			numdigits += print_c(hexbase[(nb % 16) + 16]);
	}
	else
	{
		numdigits = print_xx((nb / 16), format, numdigits);
		numdigits = print_xx((nb % 16), format, numdigits);
	}
	return (numdigits);
}
