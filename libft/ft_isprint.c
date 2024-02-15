/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:46:14 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 10:16:55 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main()
{
	int	emptystr = ' ';
	int	lowerstr= 'c';
	int	upperstr = 'L';
	int	numberstr = '1';

	printf("emptystr: %d\n", ft_isprint(emptystr));
	printf("lowerstr: %d\n", ft_isprint(lowerstr));
	printf("upperstr: %d\n", ft_isprint(upperstr));
	printf("numberstr: %d\n", ft_isprint(numberstr));

	printf("emptystr: %d\n", isprint(emptystr));
	printf("lowerstr: %d\n", isprint(lowerstr));
	printf("upperstr: %d\n", isprint(upperstr));
	printf("numberstr: %d\n", isprint(numberstr));
}*/