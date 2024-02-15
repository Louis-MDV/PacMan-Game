/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:29:45 by lmerveil          #+#    #+#             */
/*   Updated: 2023/11/23 11:04:13 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	int  bob = 'A';
	printf("%c\n", tolower(bob));
	printf("%c\n", ft_tolower(bob));
} */