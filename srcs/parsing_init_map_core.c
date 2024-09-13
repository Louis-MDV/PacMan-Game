/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_map_core.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:41:12 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/14 13:58:14 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_fileformat(char *filename)
{
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber\0", 5) == 0)
		return ;
	else
	{
		ft_printf("Error\nWrong input format!\n");
		exit(0);
	}
}

int	fillgrid(char *filename, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open_map(filename, data);
	data->grid = (char **)malloc(data->height * sizeof(char *));
	data->parse_grid = (char **)malloc(data->height * sizeof(char *));
	if (!data->grid || !data->parse_grid)
		return (free(data->grid), free(data->parse_grid), exit(0), 0);
	while (i < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->grid[i] = ft_strdup(line);
		if (!data->grid[i])
			free_close_free_struct(line, data);
		data->parse_grid[i] = ft_strdup(line);
		if (!data->parse_grid[i])
			free_close_free_struct(line, data);
		i++;
		free(line);
	}
	return (close(fd), 0);
}

void	flood_fill(t_data *data, int x, int y, char **grid)
{
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	if (grid[y][x] == 'C')
		data->c_flag++;
	if (grid[y][x] == 'E')
		data->exit_flag = 1;
	grid[y][x] = 'V';
	flood_fill(data, x - 1, y, grid);
	flood_fill(data, x, y - 1, grid);
	flood_fill(data, x + 1, y, grid);
	flood_fill(data, x, y + 1, grid);
}

void	get_dimensions_check_empty(t_data *data)
{
	char	*line;

	data->height = 1;
	line = get_next_line(data->fd);
	if (!line || line[0] == '\n')
	{
		ft_printf("Error\nEmpty map!\n");
		close(data->fd);
		free(line);
		exit(0);
	}
	data->width = ft_strlen(line) - 1;
	free(line);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(data->fd);
		if (line != NULL)
			data->height++;
		free(line);
	}
	close(data->fd);
}

void	ft_first_render_enemies(int y, int x, t_data data)
{
	if (!data.game_started)
	{
		if (data.grid[y][x] == 'B')
			mlx_put_image_to_window(data.mlx, data.win, data.img.img_enemy_blue,
				data.img.width * x, data.img.height * y);
		if (data.grid[y][x] == 'R')
			mlx_put_image_to_window(data.mlx, data.win, data.img.img_enemy_red,
				data.img.width * x, data.img.height * y);
		if (data.grid[y][x] == 'K')
			mlx_put_image_to_window(data.mlx, data.win, data.img.img_enemy_pink,
				data.img.width * x, data.img.height * y);
		if (data.grid[y][x] == 'Y')
			mlx_put_image_to_window(data.mlx, data.win,
				data.img.img_enemy_yellow, data.img.width * x, data.img.height
				* y);
	}
}
