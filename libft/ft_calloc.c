/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:55 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/23 10:14:03 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dst;

	if (size && (nmemb > __SIZE_MAX__ / size))
		return (NULL);
	dst = malloc(nmemb * size);
	if (dst == NULL)
		return (0);
	ft_bzero(dst, size * nmemb);
	return (dst);
}
/* 
#include <stdio.h>
 int main()
 {
    char *text;
    text = ft_calloc(1, 2);
    for(int i = 0; i < sizeof(text); i++)
        printf("c", text[i]);
    printf("\n%s", text);
 } */