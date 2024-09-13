/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:42:47 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/14 13:31:10 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_elements(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
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
	parse_error(data);
}

int	check_valid_elements(t_data data)
{
	int	y;
	int	x;

	y = -1;
	x = 0;
	while (++y < data.height - 1)
	{
		x = -1;
		while (++x < data.width - 1)
		{
			if (data.grid[y][x] != 'P' && data.grid[y][x] != 'C'
				&& data.grid[y][x] != 'E' && data.grid[y][x] != '0'
				&& data.grid[y][x] != '1')
				return (0);
		}
	}
	return (1);
}

void	parse_error(t_data *data)
{
	if (data->p != 1 || data->e != 1
		|| data->c_count <= 0 || !check_valid_elements(*data))
		ft_printf("Error\n");
	if (!check_valid_elements(*data))
		ft_printf("Non valid element in map!\n");
	if (data->p != 1)
		ft_printf("Map has no player!\n");
	if (data->e != 1)
		ft_printf("Map has no exit!\n");
	if (data->c_count == 0)
		ft_printf("Map has no collectibles!\n");
	if (data->p != 1 || data->e != 1
		|| data->c_count <= 0 || !check_valid_elements(*data))
		pre_free_init_struct(data);
}

void	parse(char *filename, t_data *data)
{
	check_fileformat(filename);
	is_not_folder(filename);
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
		pre_free_init_struct(data);
	}
}
