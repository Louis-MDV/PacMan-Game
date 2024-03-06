/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:41:12 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/29 20:36:32 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**init_grid(char **grid, t_data *data)
{
	grid = (char **)malloc(data->height * sizeof(char *));
	if (!grid)
		exit(0);
	return (grid);
}

void	fillgrid(char *filename, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open_map(filename, data);
	data->grid = (char **)malloc(data->height * sizeof(char *));
	data->parse_grid = (char **)malloc(data->height * sizeof(char *));
	if (!data->grid || !data->parse_grid)
		free_struct(data);
	while (i < data->height)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			break ;
		data->grid[i] = ft_strdup(line);
		data->parse_grid[i] = ft_strdup(line);
		if (!data->grid[i] || !data->parse_grid[i])
		{
			close(fd);
			free_struct(data);
		}
		free(line);
		i++;
	}  
	close(fd);
}
