/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:21 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/16 15:19:59 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		write(1, "Wrong input format", 18);
		return (0);
	}
	init_struct(&game);
	check_fileformat(av[1]);
	check_rectangular(av[1], &game);
	fillgrid(av[1], &game);
	check_closed(&game);
	check_elements(&game);
	free_grid(&game);
}
