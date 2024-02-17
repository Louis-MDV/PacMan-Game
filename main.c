/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:21 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/17 23:24:46 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		printf("Error\nWrong number of arguments!\n");
		return (0);
	}
	init_struct(&game);
	// check_fileformat(av[1]);
	// check_rectangular(av[1], &game);
	// fillgrid(av[1], &game);
	// check_closed(&game);
	// check_elements(&game);
	// free_fill(game->grid, game->height, game->width, game->posx_p, game->posy_p);
	if(parse(&game, av[1]) == 0)
		printf("flooded");
	free_grid(&game);
}
