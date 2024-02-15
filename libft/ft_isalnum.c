/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:59:18 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 10:15:03 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
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

	printf("emptystr: %d\n", ft_isalnum(emptystr));
	printf("lowerstr: %d\n", ft_isalnum(lowerstr));
	printf("upperstr: %d\n", ft_isalnum(upperstr));
	printf("numberstr: %d\n", ft_isalnum(numberstr));

	printf("emptystr: %d\n", isalnum(emptystr));
	printf("lowerstr: %d\n", isalnum(lowerstr));
	printf("upperstr: %d\n", isalnum(upperstr));
	printf("numberstr: %d\n", isalnum(numberstr));
} */