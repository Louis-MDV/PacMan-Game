/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:50:18 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/19 21:43:20 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_p(long int *ptr)
{
	int	numdigits;

	numdigits = 0;
	if (!ptr)
	{
		print_s("(nil)");
		return (5);
	}
	else
	{
		numdigits += print_s("0x");
		numdigits += print_xx((unsigned long)ptr, 'x', 0);
	}
	return (numdigits);
}
