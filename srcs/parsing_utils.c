/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:20:18 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/27 14:40:03 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_map(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nUnknown file.\n"), free(data), exit(0), 0);
	return (fd);
}



void	free_grid(char **grid, int height)
{
	int	i;
	
	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_struct(t_data *data)
{
	free_grid(data->grid, data->height);
	free_grid(data->parse_grid, data->height);
	exit (0);
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

char	**dup_grid(t_data *data)
{
	int		y;
	char	**dup_grid;

	y = 0;
	dup_grid = NULL;
	while (y < data->height)
	{
		dup_grid[y] = ft_strdup(data->grid[y]);
		y++;
	}
	return (dup_grid);
}