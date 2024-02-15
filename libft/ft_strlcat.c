/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:05:00 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/23 10:47:17 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	count;

	if (!dst && size == 0)
		return (0);
	dstlen = ft_strlen (dst);
	srclen = ft_strlen (src);
	count = 0;
	if (dstlen >= size)
		return (size + srclen);
	while (count < size - dstlen - 1 && src[count])
	{
		dst[dstlen + count] = src[count];
		count++;
	}
	dst[dstlen + count] = '\0';
	return (dstlen + srclen);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char src[] = " mdv";
    char dst[] = "louis";
    int numdigits = 0;
    printf("%s\n", dst);
    //printf("%lu\n", strlcat(src, dst, numdigits));

    printf("%u\n", ft_strlcat(dst, src, numdigits));
} */