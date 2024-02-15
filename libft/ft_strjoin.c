/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:23:19 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/23 10:46:25 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s2)+i) && s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	return (result);
}

/* #include <stdio.h>

int main()
{
    char const s1[] = "Louis";
    char const s2[] = "mdv";

    printf("%s", ft_strjoin(s1,s2));
    return(0);
} */