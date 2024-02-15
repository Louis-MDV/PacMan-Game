/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:25:21 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/22 18:07:00 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*s1bis;
	const unsigned char		*s2bis;

	i = 0;
	s1bis = (const unsigned char *)s1;
	s2bis = (const unsigned char *)s2;
	while (i < n)
	{
		if (s1bis[i] - s2bis[i] != 0)
			return ((int)s1bis[i] - (int)s2bis[i]);
		i++;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>

int main() 
{ 
    char s1[] = "non";
	char s2[] = "non";

   	printf("%d\n", ft_memcmp(s1, s2, 12));
    printf("%d", memcmp(s1, s2,12));
} */