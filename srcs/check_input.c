/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:38:45 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/16 15:43:53 by lmerveil         ###   ########.fr       */
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
		write(1, "Error\nWrong input format", 24);
		exit(0);
	}
}

int	check_rectangular(char *filename, t_data *game)
{
	int		fd;
	char	*line;

	game->height = 1; // height 1 cause line38
	fd = open_map(filename);
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
	if (game->width != game->height)
		return (1);
	else
	{
		write(1, "Error\nMap not rectangular!\n", 27);
		exit(0);
	}
}

int	check_closed(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->height - 1)
	{
		w = 0;
		while (w < game->width - 1)
		{
			if ((game->grid[0][w] != '1' || game->grid[game->height
					- 1][w] != '1') || (h != 0 && h != game->height - 1
					&& game->grid[h][0] != '1' && game->grid[h][game->width
					- 1] != '1'))
			{
				free_grid(game);
				write(1, "Error\nMap not closed!\n", 24);
				exit(0);
			}
			w++;
		}
		h++;
	}
	return (1);
}

int	check_elements(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if (game->grid[y][x] == 'P')
			{
				game->posx_p = x;
				game->posy_p = y;
				game->p++;
				// printf("%d\n", game->posx_p);
				// printf("%d\n", game->posy_p);
			}
			if (game->grid[y][x] == 'C')
				game->c++;
			if (game->grid[y][x] == 'E')
			{
				game->posx_e = x;
				game->posy_e = y;
				game->e++;
				// printf("%d\n", game->posx_e);
				// printf("%d\n", game->posy_e);
			}
			x++;
		}
		y++;
	}
	if (game->p != 1 || game->e != 1 || game->c <= 0)
		return (printf("Error\nMap has no player or no collectibles or no exit!\n"),0);
	return (1);
}

int	flood_fill(t_data *game)
{
	
}



// The map must contain 1 exit, at least 1 collectible,
//	and1 starting position to be valid.							OK
// rectangular													OK
// closed / surrounded by walls									OK
// 1 valid path