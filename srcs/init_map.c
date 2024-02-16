/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:41:12 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/16 15:21:48 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// init grid pointer on xheight string (char **)
// 1.alloc size for height strings
// 2.alloc size for
char	**init_grid(t_data *game)
{
	int	i;

	i = 0;
	game->grid = (char **)malloc(game->height * sizeof(char *));
	if (!game->grid)
		exit(0);
	while (i < game->height)
	{
		game->grid[i] = (char *)malloc(game->width * sizeof(char));
		if (!game->grid[i])
		{
			free_grid(game);
			exit(0);
		}
		i++;
	}
	return (game->grid);
}

// fill grid with all elements of map
void	fillgrid(char *filename, t_data *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open_map(filename);
	game->grid = init_grid(game);
	while (i < game->height)
	{
		line = get_next_line(fd);
		ft_strlcpy(game->grid[i], line, game->width);
		free(line);
		i++;
	}
	close(fd);
}
