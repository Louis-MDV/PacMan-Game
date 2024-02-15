/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:34:38 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 11:36:09 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	srclen;

	i = 0;
	srclen = ft_strlen(s);
	while (i <= srclen)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char	sentence[] = "bonjour";
	int	vida = 'v';
	printf ("%s\n", ft_strchr(sentence, vida));
	printf ("%s", strchr(sentence, vida));
} */