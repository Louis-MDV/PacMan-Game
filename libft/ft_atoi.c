/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:14:55 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/09 16:25:05 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (nptr[i] - '0');
		i++;
	}
	nb = nb * sign;
	return (nb);
}

/* #include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char text[] = "life is good";
		char text2[] = "-+54";
		char text3[] = "-12louis3";
		char text4[] = " ++12louis3";
		char text5[] = "!!12louis3";

	printf("%s\n", "FT_atoi:");
	printf("%d\n", ft_atoi(text));
	printf("%d\n", ft_atoi(text2));
	printf("%d\n", ft_atoi(text3));
	printf("%d\n", ft_atoi(text4));
	printf("%d\n", ft_atoi(text5));
	printf("%s\n", "atoi:");
	printf("%d\n", atoi(text));
	printf("%d\n", atoi(text2));
	printf("%d\n", atoi(text3));
	printf("%d\n", atoi(text4));
	printf("%d\n", atoi(text5));
} */