/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:36:49 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 10:16:18 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int	main()
{
	int	emptystr = ' ';
	int	lowerstr= 'c';
	int	upperstr = 'L';
	int	numberstr = '1';

	printf("emptystr: %d\n", ft_isascii(emptystr));
	printf("lowerstr: %d\n", ft_isascii(lowerstr));
	printf("upperstr: %d\n", ft_isascii(upperstr));
	printf("numberstr: %d\n", ft_isascii(numberstr));

	printf("emptystr: %d\n", isascii(emptystr));
	printf("lowerstr: %d\n", isascii(lowerstr));
	printf("upperstr: %d\n", isascii(upperstr));
	printf("numberstr: %d\n", isascii(numberstr));
} */