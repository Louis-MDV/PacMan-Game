/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:20:18 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/12 22:01:04 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_map(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nUnknown file.\n"), exit(0), 0);
	data->fd = fd;
	return (data->fd);
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

void	*define_current_img(t_data data)
{
	void	*current_img;

	current_img = NULL;
	if (data.pix_mov % 2 == 0)
		current_img = data.img.img_player_closed;
	else
	{
		if (data.keypress_flag == UP)
			current_img = data.img.img_player_up;
		else if (data.keypress_flag == DOWN)
			current_img = data.img.img_player_down;
		else if (data.keypress_flag == RIGHT)
			current_img = data.img.img_player_right;
		else if (data.keypress_flag == LEFT)
			current_img = data.img.img_player_left;
	}
	return (current_img);
}

void	display_keypress_num(t_data *data)
{
	char	*str;

	str = ft_itoa(data->keypress_num);
	mlx_string_put(data->mlx, data->win, data->width * data->img.width
		- (data->img.width * 2.55), 28, -1, str);
	free(str);
}

void	pre_free_init_struct(t_data *data)
{
	free_grid(data->grid, data->height);
	free_grid(data->parse_grid, data->height);
	exit(0);
}
