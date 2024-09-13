/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/14 13:55:46 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../bonus/so_long_bonus.h"
#include "../so_long.h"

// renders map. opens exit. shows player according to arrow stroke
int	render_map(t_data *data)
{
	if (data->keypress_flag == UP || data->keypress_flag == LEFT
		|| data->keypress_flag == ZERO)
		render_up_left(0, data);
	else if (data->keypress_flag == DOWN || data->keypress_flag == RIGHT)
		render_down_right(0, data);
	return (display_keypress_num(data), usleep(4000), 0);
}

void	render_down_right(int bonus_flag, t_data *data)
{
	int	x;
	int	y;

	y = render_order_y(*data);
	while (--y >= 0)
	{
		x = data->width;
		while (x >= 0)
		{
			render_walls_collectibles(y, x, *data);
			if (bonus_flag == 1)
				ft_first_render_enemies(y, x, *data);
			if (x == data->posx_p && y == data->posy_p)
				render_player(data);
			x--;
		}
	}
}

void	render_up_left(int bonus_flag, t_data *data)
{
	int	y;
	int	x;

	y = render_order_y(*data);
	while (++y < data->height)
	{
		x = 0;
		while (x <= data->width - 1)
		{
			render_walls_collectibles(y, x, *data);
			if (bonus_flag == 1)
				ft_first_render_enemies(y, x, *data);
			if (x == data->posx_p && y == data->posy_p)
				render_player(data);
			x++;
		}
	}
}

void	render_walls_collectibles(int y, int x, t_data data)
{
	if (data.grid[y][x] == '1')
		mlx_put_image_to_window(data.mlx, data.win, data.img.img_wall,
			data.img.width * x, data.img.height * y);
	if (data.grid[y][x] == '0')
		mlx_put_image_to_window(data.mlx, data.win, data.img.img_path,
			data.img.width * x, data.img.height * y);
	if (data.grid[y][x] == 'C')
		mlx_put_image_to_window(data.mlx, data.win, data.img.img_collect,
			data.img.width * x, data.img.height * y);
	if (data.grid[y][x] == 'E' && data.c_collected < data.c_count)
		mlx_put_image_to_window(data.mlx, data.win, data.img.img_path,
			data.img.width * x, data.img.height * y);
	else if (data.grid[y][x] == 'E' && data.c_collected == data.c_count)
		mlx_put_image_to_window(data.mlx, data.win, data.img.img_exit,
			data.img.width * x, data.img.height * y);
}

int	render_order_y(t_data	data)
{
	if (data.keypress_flag == DOWN || data.keypress_flag == RIGHT)
		return (data.height - 1);
	else if (data.keypress_flag == UP || data.keypress_flag == LEFT
		|| data.keypress_flag == ZERO)
		return (-1);
	return (0);
}
