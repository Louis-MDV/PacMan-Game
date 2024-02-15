/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:25:10 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 10:20:04 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	numdigits;
	int				sign;
	long			nb;

	nb = n;
	sign = 0;
	numdigits = count(nb);
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	result = ft_calloc((numdigits + sign + 1), sizeof(char));
	if (result == 0)
		return (0);
	while (numdigits > 0)
	{
		result[numdigits + sign - 1] = '0' + (nb % 10);
		nb = nb / 10;
		numdigits--;
	}
	if (sign == 1)
		result[0] = '-';
	return (result);
}

/* int	main(void)
{
	int	s;

	s = 225;
	printf("%s", ft_itoa(s));
}
 */