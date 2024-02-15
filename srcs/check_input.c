/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:38:45 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/15 13:10:38 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_fileformat(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (ft_strncmp(&str[i], ".ber\0", 5) == 0)
		return (1);
	else
	{
		write(1, "Wrong input format", 18);
		exit(0);
	}
}

int	check_rectangular(char *filename, t_data *game)
{
	int		fd;
	char	*line;

	game->height = 1;
	fd = open_map(filename);
	if (fd < 0)
		exit(0);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1; //-1 cause cont dount '\0'
	free(line);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			game->height++;
		free(line);
	}
	close(fd);
	printf("width = %d\n", game->width);
	printf("height = %d\n", game->height);
	if (game->width != game->height)
		return (1);
	else
	{
		write(1, "Map not rectangular!\n", 21);
		exit(0);
	}
}

int	check_closed(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < game->height - 1)
	{
		w = 0;
		while (w < game->width - 1)
		{
			if (game->grid[0][w] != '1' || game->grid[game->height
				- 1][w] != '1')
			{
				free_grid(game);
				printf("not closed");
				exit(0);
			}
			if (h != 0 && h != game->height - 1)
			{
				if (game->grid[h][0] != '1' && game->grid[h][game->width
					- 1] != '1')
				{
					free_grid(game);
					printf("not closed");
					exit(0);
				}
			}
			w++;
		}
		h++;
	}
	printf("closed map");
	return (1);
}

// The map must contain 1 exit, at least 1 collectible,
//	and1 starting position to be valid.
// rectangular													OK
// closed / surrounded by walls
// 1 valid path
// no dups chars
