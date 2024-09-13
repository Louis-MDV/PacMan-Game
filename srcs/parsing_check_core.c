/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_core.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:38:45 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/13 18:00:04 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			if ((data->grid[0][x] != '1'
				|| data->grid[data->height - 1][x] != '1')
				|| (y != 0 && y != data->height - 1
				&& data->grid[y][0] != '1'
				&& data->grid[y][data->width - 1] != '1'))
			{
				ft_printf("Error\nMap not closed!\n");
				pre_free_init_struct(data);
			}
			x++;
		}
	}
}

void	free_close_free_struct(char *line, t_data *data)
{
	free(line);
	close(data->fd);
	pre_free_init_struct(data);
}

int	is_not_folder(const char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
	{
		ft_printf("Error\nFile does not exist!\n");
		exit(0);
	}
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_printf("Error\nProvided file map is not a file!\n");
		exit(0);
	}
	return (1);
}
