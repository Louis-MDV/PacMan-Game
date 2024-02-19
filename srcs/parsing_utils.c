/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:20:18 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/19 22:45:46 by lmerveil         ###   ########.fr       */
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
	int	i;
	
	i = 0;
	while (i < game->height - 1)
	{
		free(game->grid[i]);
		i++;
	}
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
	game->exit_flag	= 0;
	game->c_flag	= 0;
	game->count_v	= 0;
}

void	free_exit(t_data *game)
{
	free_grid(game);
	free(game);
}

void	print_map(t_data *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			ft_printf("%c", game->grid[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}