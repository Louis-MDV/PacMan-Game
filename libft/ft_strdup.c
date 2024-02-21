/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:31:02 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/21 10:59:36 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"  
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	ft_strlcpy(duplicate, s, ft_strlen(s) + 1);
	return (duplicate);
}

/* #include <stdio.h>
int main()
{
    char s[] = "louis";
    printf("%s", ft_strdup(s));
} */