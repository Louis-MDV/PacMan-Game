/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/27 10:53:48 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_data *data)
{
	int y = 0;
	int x = 0;

	while (y < data->height)
	{
		x = 0;
		while (data->grid[y][x] != '\n')
		{
			if (data->grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_wall, 50*x, 50*y);
			if (data->grid[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, 50*x, 50*y);
			if (data->grid[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player, 50*x, 50*y);
			if (data->grid[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_collect, 50*x, 50*y);
			if (data->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_exit, 50*x, 50*y);
			x++;
		}
	y++;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	(void)data;
    return (0);
}
