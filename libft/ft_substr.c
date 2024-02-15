/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:55:54 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/22 17:38:34 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	unsigned int	total_size;
	char			*new;

	if (s == NULL)
		return (NULL);
	total_size = 0;
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	s = s + start;
	while (s[total_size] && len--)
		total_size++;
	new = malloc(sizeof(char) * (total_size + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s, total_size + 1);
	return (new);
}

	/* #include <stdio.h>

	int main()
	{
	char *sentence = "life is good";
	int len = 5;

	printf("%s", ft_substr(sentence, 400, len));
	return(0);
	} */