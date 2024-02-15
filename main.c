/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:21 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/15 11:54:08 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*str;
	int		i;
	t_data	game;

	str = av[1];
	i = 0;
	if (ac != 2)
	{
		write(1, "Wrong input format", 18);
		return (0);
	}
	check_fileformat(av[1]);
	check_rectangular(av[1], &game);
	fillgrid(av[1], &game);
	check_closed(&game);
}
