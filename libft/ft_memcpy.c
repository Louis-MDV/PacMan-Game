/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:19:30 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 10:23:56 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destchr;
	char	*srcchr;

	i = 0;
	destchr = (char *)dest;
	srcchr = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		destchr[i] = srcchr[i];
		i++;
	}
	return (destchr);
}

/* #include <string.h>
#include <stdio.h>

int main() 
{
    char dst[] = "yessir.";
	char src[] = "bobe";

	char dst2[] = "yessir.";
	char src2[] = "bobe";

	ft_memcpy(dst, src, 3);
   	printf("%s\n", dst);

	memcpy(dst2, src2, 3);
    printf("%s", dst2);
} */