/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:38:45 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/21 19:10:26 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_fileformat(char *filename, t_data *game)
{
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber\0", 5) == 0)
		return ;
	else
	{
		ft_printf("Error\nWrong input format!\n");
		free(game);
		exit(0);
	}
}

void	get_dimensions_check_empty(t_data *game)
{
	char	*line;

	game->height = 1;
	line = get_next_line(game->fd);
	if (!line || line[0] == '\n')
	{
		ft_printf("Error\nEmpty map!\n");
		close(game->fd);
		free(line);
		free(game);
		exit(0);
	}
	game->width = ft_strlen(line) - 1;
	free(line);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(game->fd);
		if (line != NULL)
			game->height++;
		free(line);
	}
	close(game->fd);
}

void	check_rectangular(char *filename, t_data *game)
{
	int		i;
	int		fd;
	char	*line;
	int		linewidth;

	i = -1;
	fd = open_map(filename, game);
	while (++i < game->height)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			linewidth = ft_strlen(line) - 1;
		else
			linewidth = ft_strlen(line);
		free(line);
		if (game->width != linewidth)
		{
			ft_printf("Error\nMap not rectangular!\n");
			close(fd);
			free(game);
			exit(0);
		}
	}
	close(fd);
}

void	check_closed(t_data *game)
{
	int		y;
	int		x;

	y = -1;
	while (++y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if ((game->grid[0][x] != '1' || game->grid[game->height - 1][x] != '1') 
				|| (y != 0 && y != game->height - 1
				&& game->grid[y][0] != '1' 
				&& game->grid[y][game->width - 1] != '1'))
			{
				ft_printf("Error\nMap not closed!\n");
				free_struct(game);
			}
			x++;
		}
	}
}

void	check_elements(t_data *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height - 1)
	{
		x = -1;
		while (++x < game->width - 1)
		{
			if (game->grid[y][x] == 'P')
			{
				game->posx_p = x;
				game->posy_p = y;
				game->p++;
			}
			else if (game->grid[y][x] == 'C')
				game->c++;
			else if (game->grid[y][x] == 'E')
				game->e++;
		}
	}
	if (game->p != 1 || game->e != 1 || game->c <= 0)
		parse_error(game);
}

void	parse_error(t_data *game)
{
	if (game->p != 1 || game->e != 1 || game->c <= 0)
		ft_printf("Error\n");
	if (game->p != 1)
		ft_printf("Map has no player!\n");
	if (game->e != 1)
		ft_printf("Map has no exit!\n");
	if (game->c == 0)
		ft_printf("Map has no collectibles!");
	if (game->p != 1 || game->e != 1 || game->c <= 0)
		free_struct(game);
}

void	flood_fill(t_data *game, int x, int y, char **grid)
{
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	if (grid[y][x] == 'C')
		game->c_flag++;
	if (grid[y][x] == 'E')
		game->exit_flag = 1;
	grid[y][x] = 'V';
	flood_fill(game, x - 1, y, grid);
	flood_fill(game, x, y - 1, grid);
	flood_fill(game, x + 1, y, grid);
	flood_fill(game, x, y + 1, grid);
}

t_data	*parse(char *filename)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
		exit(0);
	check_fileformat(filename, game);
	init_struct(filename, game);
	get_dimensions_check_empty(game);
	check_rectangular(filename, game);
	fillgrid(filename, game);
	check_closed(game);
	check_elements(game);
	flood_fill(game, game->posx_p, game->posy_p, game->parse_grid);
	if (game->c_flag == game->c && game->exit_flag == 1)
		return (game);
	else
	{
		ft_printf("Error\nNo feasibe path to collectibles and exit!\n");
		free_struct(game);
	}
	return (game);
}
