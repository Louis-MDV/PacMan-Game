/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:21:09 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/22 17:48:45 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (s[slen] == (char)c)
			return ((char *)s + slen);
		slen--;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char sentence[] = "This is great...";
	int vida = 'i';
	printf("%s", strrchr(sentence, vida));
	printf("%s", ft_strrchr(sentence, vida));
} */