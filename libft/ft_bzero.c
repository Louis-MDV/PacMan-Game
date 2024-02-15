/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:52:40 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/23 11:28:25 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*schr;

	schr = 0;
	schr = (char *)s;
	ft_memset(schr, 0, n);
}

/*
#include <stdio.h>
#include <strings.h>
int main()
{
    char text[] = "bib is nice.";
    char text2[] = "bob is very nice";

    bzero(text, 3);
    for (int i = 0; i < numdigitsof(text); i++)
        printf("%d ", text[i]);
    printf("%s", text);

    ft_bzero(text2+3, 3);
    printf("%s", text2);
}*/