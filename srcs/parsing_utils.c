/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:20:18 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/20 13:15:17 by lmerveil         ###   ########.fr       */
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

void	free_grid(char **grid, t_data *game)
{
	int	i;
	
	i = 0;
	while (i < game->height - 1)
	{
		free(grid[i]);
		i++;
	}
}

void	free_struct(t_data *game)
{
	free_grid(game->grid, game);
	free_grid(game->parse_grid, game);
	free(game);
}

void	print_map(char **map, int height, int width)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < height)
	{
		x = 0;
		while(x < width)
		{
			ft_printf("%c", map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

char	**dup_grid(t_data *game)
{
	int		y;
	char	**dup_grid;

	y = 0;
	dup_grid = NULL;
	while (y < game->height)
	{
		dup_grid[y] = ft_strdup(game->grid[y]);
		y++;
	}
	return (dup_grid);
}