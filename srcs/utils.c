/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:20:18 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/16 15:25:56 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

void	free_grid(t_data *game)
{
	int i = 0;
	while (i < game->height)
	{
		free(game->grid[i]);
		i++;
	}
	free(game->grid);
}

void	init_struct(t_data *game)
{
	game->width 	= 0;
	game->height 	= 0;
	game->p 		= 0;
	game->e 		= 0;
	game->c 		= 0;
	game->posx_p 	= 0;
	game->posy_p 	= 0;
	game->posx_e 	= 0;
	game->posy_e 	= 0;
}