/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:49:18 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/22 16:03:13 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		index;

	index = 0;
	if (!s || !f)
		return (NULL);
	result = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}

/* char *replace(unsigned int index, char c[index])
{
    c[index] = 'D';
    return(&c[index]);
}

#include <stdio.h>
int main()
{
    char name[] = "NAME";
    printf("%s", ft_strmapi(name, replace(1,name)));
    return(0);
} */