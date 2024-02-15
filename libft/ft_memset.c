/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:11:32 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/23 10:29:16 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		((char *)s)[i] = (char)c;
		i++;
		n--;
	}
	return (s);
}

/* #include <stdio.h> 
int main() 
{ 
    char str[] = "Life is good."; 
    ft_memset(str, '.', 8);
    printf("%s\n", str);
    memset(str, '.', 8);
    printf("%s", str);
    return 0;
} */