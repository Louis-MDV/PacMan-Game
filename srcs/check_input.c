/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:38:45 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/18 00:12:15 by lmerveil         ###   ########.fr       */
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
		printf("Error\nWrong input format\n");
		return (0);
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
		return (0);
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
				printf("Error\nMap not closed!\n");
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
			}
			if (game->grid[y][x] == 'C')
				game->c++;
			if (game->grid[y][x] == 'E')
			{
				game->posx_e = x;
				game->posy_e = y;
				game->e++;
			}
			x++;
		}
		y++;
	}
	if (game->p != 1 || game->e != 1 || game->c <= 0)
		return (printf("Error\nMap has no player or no collectibles or no exit!\n"),0);
	return (1);
}

int flood_fill(char **map, int rows, int cols, int x, int y, int c, int c_flag, int exit_flag)
{
    if (x < 0 || x >= cols || y < 0 || y >= rows || map[y][x] == '1') //if out of map or wall, return 0
        return (0);
    else if (map[y][x] == 'C') //if collectable, increment flag
        c_flag++;
    else if (map[y][x] == 'E') //if exit, set exit_flag
        exit_flag = 1;
    map[y][x] = 'V';  // Mark the current position as visited

    if (c_flag == c && exit_flag)
        return (1);

    // Recursively call in all four directions
    return (
        flood_fill(map, rows, cols, x - 1, y, c, c_flag, exit_flag) ||
        flood_fill(map, rows, cols, x + 1, y, c, c_flag, exit_flag) ||
        flood_fill(map, rows, cols, x, y - 1, c, c_flag, exit_flag) ||
        flood_fill(map, rows, cols, x, y + 1, c, c_flag, exit_flag)
    );
}

int	parse(t_data *game, char *filename)
{
	game = malloc(sizeof(t_data));
	if(!game)
		exit(0);
	if(	check_fileformat(filename) && check_rectangular(filename, game))
			fillgrid(filename, game);
	else
	{
		free_grid(game);
		exit(0);
	}
	if(	check_closed(game)
		&& check_elements(game)
		&& flood_fill(game->grid, game->height, game->width, game->posx_p, game->posy_p, game->c, 0, 0))
		return (1);
	else
	{
		free_grid(game);
		return(0);
	}
}