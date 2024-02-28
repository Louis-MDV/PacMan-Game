/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/28 18:22:59 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_map(t_data *data)
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
			{
				if (data->keypress_flag == 1)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_up, data->img.width * x, data->img.height * y);
				else if (data->keypress_flag == 2)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_down, data->img.width * x, data->img.height * y);
				else if (data->keypress_flag == 3)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_right, data->img.width * x, data->img.height * y);
				else if (data->keypress_flag == 4)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_left, data->img.width * x, data->img.height * y);
			}
			if (data->grid[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_collect, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_exit, data->img.width * x, data->img.height * y);
			x++;
		}
	}
	return(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	data->keypress_num++;
	handle_up(keysym, data);
	handle_down(keysym, data);
	handle_left(keysym, data);
	handle_right(keysym, data);
	
	if (data->grid[data->posy_p][data->posx_p] == 'C' && data->c_collected < data->c_count)
	{
		data->c_collected++;
		data->grid[data->posy_p][data->posx_p] = '0';
		ft_printf(GREEN"+1 collectible!\n"RESET);
	}
	if(keysym == XK_w || keysym == XK_a ||keysym == XK_s || keysym == XK_d)
		printf("Key press number: %d\n", data->keypress_num);
	handle_esc_all_collected(keysym, data);
	return (0);
}

void	handle_esc_all_collected(int keysym, t_data *data)
{
	if (keysym == XK_Escape || (data->c_collected == data->c_count && data->grid[data->posy_p][data->posx_p] == 'E'))
	{
		ft_printf(RED"GAME OVER!\n"RESET);
		free_img_data(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_struct(data);
	}
}

void	handle_up(int keysym, t_data *data)
{
	if (data->grid[data->posy_p - 1][data->posx_p] == '1' && keysym == XK_w)
		ft_printf(ORANGE"Can't move up! There's a wall...\n"RESET);
	else if (data->grid[data->posy_p - 1][data->posx_p] == 'E' && keysym == XK_w && data->c_collected < data->c_count)
		ft_printf(ORANGE"Can't move up! Collect remaining collectibles to exit...\n"RESET);
	else if (keysym == XK_w)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
		data->posy_p--;
		data->keypress_flag = 1;
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_up, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
	}
}

void	handle_down(int keysym, t_data *data)
{
	if (data->grid[data->posy_p + 1][data->posx_p] == '1' && keysym == XK_s)
		ft_printf(ORANGE"Can't move down! There's a wall...\n"RESET);
	else if (data->grid[data->posy_p + 1][data->posx_p] == 'E' && keysym == XK_s && data->c_collected < data->c_count)
		ft_printf(ORANGE"Can't move down! Collect remaining collectibles to exit...\n"RESET);
	 else if (keysym == XK_s)
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
        data->posy_p++;
		data->keypress_flag = 2;
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_down, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
    }
}

void	handle_right(int keysym, t_data *data)
{
	if (data->grid[data->posy_p][data->posx_p + 1] == '1' && keysym == XK_d)
		ft_printf(ORANGE"Can't move right! There's a wall...\n"RESET);
	else if (data->grid[data->posy_p][data->posx_p + 1] == 'E' && keysym == XK_d && data->c_collected < data->c_count)
		ft_printf(ORANGE"Can't move right! Collect remaining collectibles to exit...\n"RESET);
	else if (keysym == XK_d)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
		data->posx_p++;
		data->keypress_flag = 3;
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_right, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
	}
}

void	handle_left(int keysym, t_data *data)
{
	if (data->grid[data->posy_p][data->posx_p - 1] == '1' && keysym == XK_a)
		ft_printf(ORANGE"Can't move left! There's a wall...\n"RESET);
	else if (data->grid[data->posy_p][data->posx_p - 1] == 'E' && keysym == XK_a && data->c_collected < data->c_count)
		ft_printf(ORANGE"Can't move left! Collect remaining collectibles to exit...\n"RESET);
	else if (keysym == XK_a)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
		data->posx_p--;
		data->keypress_flag = 4;
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_left, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
	}
}

