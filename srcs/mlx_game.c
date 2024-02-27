/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/27 19:03:46 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->height)
	{
		x = 0;
		while (data->grid[y][x] != '\n')
		{
			if (data->grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_wall, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_path, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_player, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_collect, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_exit, data->img.width * x, data->img.height * y);
			x++;
		}
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	data->keypress_num++;
	if (keysym == XK_Escape || (data->c_collected == data->c_count && data->grid[data->posy_p][data->posx_p] == 'E'))
	{
		free_img_data(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_struct(data);
	}
	handle_up(keysym, data);
	handle_down(keysym, data);
	handle_left(keysym, data);
	handle_right(keysym, data);
	
	if (data->grid[data->posy_p][data->posx_p] == 'E' && data->c_collected < data->c_count)
		ft_printf("Collect all collectibles to exit!\n");
	if (data->grid[data->posy_p][data->posx_p] == 'C' && data->c_collected < data->c_count)
	{
		data->c_collected++;
		ft_printf("+1 collectible!\n");
	}
	if(keysym == XK_w || keysym == XK_a ||keysym == XK_s || keysym == XK_d)
		printf("Key press number: %d\n", data->keypress_num);
	return (0);
}

void	handle_up(int keysym, t_data *data)
{
	if (data->grid[data->posy_p - 1][data->posx_p] == '1' && keysym == XK_w)
		ft_printf("Can't move up! There's a wall...");
	else if (data->grid[data->posy_p - 1][data->posx_p] == 'E' && keysym == XK_w && data->c_collected < data->c_count)
		ft_printf("Can't move up! Collect remaining collectibles to exit...\n");
	else if (keysym == XK_w)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
		data->posy_p--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
	}
}

void	handle_down(int keysym, t_data *data)
{
	if (data->grid[data->posy_p + 1][data->posx_p] == '1' && keysym == XK_s)
		ft_printf("Can't move down! There's a wall...");
	else if (data->grid[data->posy_p + 1][data->posx_p] == 'E' && keysym == XK_s && data->c_collected < data->c_count)
		ft_printf("Can't move down! Collect remaining collectibles to exit...\n");
	else if (keysym == XK_s)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
		data->posy_p++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
	}
}

void	handle_right(int keysym, t_data *data)
{
	if (data->grid[data->posy_p][data->posx_p + 1] == '1' && keysym == XK_d)
		ft_printf("Can't move right! There's a wall...");
	else if (data->grid[data->posy_p + 1][data->posx_p] == 'E' && keysym == XK_d && data->c_collected < data->c_count)
		ft_printf("Can't move right! Collect remaining collectibles to exit...\n");
	else if (keysym == XK_d)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img_path, data->img.height * (data->posx_p),
			data->img.height * (data->posy_p));
		data->posx_p++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img_player, data->img.height * (data->posx_p),
			data->img.height * (data->posy_p));
	}
}

void	handle_left(int keysym, t_data *data)
{
	if (data->grid[data->posy_p][data->posx_p - 1] == '1' && keysym == XK_a)
		ft_printf("Can't move left! There's a wall...");
	else if (data->grid[data->posy_p - 1][data->posx_p] == 'E' && keysym == XK_a && data->c_collected < data->c_count)
		ft_printf("Can't move left! Collect remaining collectibles to exit...\n");
	else if (keysym == XK_a)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img_path, data->img.height * (data->posx_p),
			data->img.height * (data->posy_p));
		data->posx_p--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img_player, data->img.height * (data->posx_p),
			data->img.height * (data->posy_p));
	}
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
