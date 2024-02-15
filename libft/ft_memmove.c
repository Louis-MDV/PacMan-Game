/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:05:38 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 10:25:06 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*chrdest;
	char			*chrsrc;

	chrdest = (char *)dest;
	chrsrc = (char *)src;
	if (dest <= src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			chrdest[n - 1 - i] = chrsrc[n - 1 - i];
			i++;
		}
		return (chrdest);
	}
}

/* #include <string.h>
#include <stdio.h>

int main() 
{ 
char src[] = "bilob";
	char dst[] = "yesbo";

	char src2[] = "bilob";
	char dst2[] = "yesbo";


ft_memmove(dst,src, 3);
   	printf("%s\n", dst);

	memmove(dst2, src2, 3);
    printf("%s\n", dst2);
} */