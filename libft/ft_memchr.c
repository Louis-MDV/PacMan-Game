/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:57:30 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/22 18:07:28 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)((char *)s + i));
		i++;
	}
	return (0);
}

/* #include <stdio.h> 
#include <string.h> 

int main() 
{ 
    char str[] = "Life is good"; 
    printf("%c\n", ft_memchr(str, 'o', 8));
    printf("%c", memchr(str, 'o', 8));
    return 0; 
} */