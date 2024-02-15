/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:49 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 10:15:42 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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

	printf("emptystr: %d\n", ft_isalpha(emptystr));
	printf("lowerstr: %d\n", ft_isalpha(lowerstr));
	printf("upperstr: %d\n", ft_isalpha(upperstr));
	printf("numberstr: %d\n", ft_isalpha(numberstr));

	printf("emptystr: %d\n", isalpha(emptystr));
	printf("lowerstr: %d\n", isalpha(lowerstr));
	printf("upperstr: %d\n", isalpha(upperstr));
	printf("numberstr: %d\n", isalpha(numberstr));
} */