/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:38:45 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/28 16:07:50 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_fileformat(char *filename, t_data *data)
{
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber\0", 5) == 0)
		return ;
	else
	{
		ft_printf("Error\nWrong input format!\n");
		free(data);
		exit(0);
	}
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
		free(data);
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

void	check_rectangular(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;
	int		linewidth;

	i = -1;
	fd = open_map(filename, data);
	while (++i < data->height)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			linewidth = ft_strlen(line) - 1;
		else
			linewidth = ft_strlen(line);
		free(line);
		if (data->width != linewidth)
		{
			ft_printf("Error\nMap not rectangular!\n");
			close(fd);
			free(data);
			exit(0);
		}
	}
	close(fd);
}

void	check_closed(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (++y < data->height - 1)
	{
		x = 0;
		while (x < data->width - 1)
		{
			if ((data->grid[0][x] != '1' || data->grid[data->height - 1][x] != '1') 
				|| (y != 0 && y != data->height - 1
				&& data->grid[y][0] != '1' 
				&& data->grid[y][data->width - 1] != '1'))
			{
				ft_printf("Error\nMap not closed!\n");
				free_struct(data);
			}
			x++;
		}
	}
}

void	check_elements(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height - 1)
	{
		x = -1;
		while (++x < data->width - 1)
		{
			if (data->grid[y][x] == 'P')
			{
				data->posx_p = x;
				data->posy_p = y;
				data->p++;
			}
			else if (data->grid[y][x] == 'C')
				data->c_count++;
			else if (data->grid[y][x] == 'E')
				data->e++;
		}
	}
	if (data->p != 1 || data->e != 1 || data->c_count <= 0)
		parse_error(data);
}

void	parse_error(t_data *data)
{
	if (data->p != 1 || data->e != 1 || data->c_count <= 0)
		ft_printf("Error\n");
	if (data->p != 1)
		ft_printf("Map has no player!\n");
	if (data->e != 1)
		ft_printf("Map has no exit!\n");
	if (data->c_count == 0)
		ft_printf("Map has no collectibles!");
	if (data->p != 1 || data->e != 1 || data->c_count <= 0)
		free_struct(data);
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

void	parse(char *filename, t_data *data)
{
	check_fileformat(filename, data);
	init_struct(filename, data);
	get_dimensions_check_empty(data);
	check_rectangular(filename, data);
	fillgrid(filename, data);
	check_closed(data);
	check_elements(data);
	flood_fill(data, data->posx_p, data->posy_p, data->parse_grid);
	if (!(data->c_flag == data->c_count && data->exit_flag == 1))
	{
		ft_printf("Error\nNo feasibe path to collectibles and exit!\n");
		free_struct(data);
	}
}
