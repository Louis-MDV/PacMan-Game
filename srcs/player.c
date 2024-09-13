/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:31:27 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/11 15:50:41 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_player(t_data *data)
{
	if (data->grid[data->posy_p][data->posx_p] == 'C'
		&& data->c_collected < data->c_count)
	{
		data->c_collected++;
		data->grid[data->posy_p][data->posx_p] = '0';
		ft_printf(GREEN"+1 collectible!\n"RESET);
	}
	if (data->img.current_img != NULL && data->d_wall > 0
		&& data->keypress_flag != ZERO)
	{
		data->img.current_img = define_current_img(*data);
		adjust_mapxy(data);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.current_img, data->pos.map_x, data->pos.map_y);
		data->d_wall--;
		data->pix_mov--;
		if (data->pix_mov == 0)
			adjust_ber_pos(data);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.current_img, data->pos.map_x, data->pos.map_y);
	handle_esc_all_collected(data->keypress_flag, data);
	if (data->d_wall == 0)
		data->keypress_flag = ZERO;
}

void	adjust_mapxy(t_data *data)
{
	if (data->keypress_flag == UP)
		data->pos.map_y--;
	else if (data->keypress_flag == DOWN)
		data->pos.map_y++;
	else if (data->keypress_flag == RIGHT)
		data->pos.map_x++;
	else if (data->keypress_flag == LEFT)
		data->pos.map_x--;
}

void	adjust_ber_pos(t_data *data)
{
	if (data->keypress_flag == UP)
		data->posy_p--;
	else if (data->keypress_flag == DOWN)
		data->posy_p++;
	else if (data->keypress_flag == RIGHT)
		data->posx_p++;
	else if (data->keypress_flag == LEFT)
		data->posx_p--;
	data->pix_mov = 50;
	if (data->mov_queue != ZERO && check_mov_queue(data->mov_queue, *data))
	{
		data->keypress_flag = data->mov_queue;
		data->mov_queue = ZERO;
		data->d_wall = distance_to_wall(data->keypress_flag, *data) * 50;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (data->keypress_flag != ZERO)
	{
		data->mov_queue = keysym;
		data->keypress_num++;
	}
	else if (handle_up(keysym, data) || handle_down(keysym, data)
		|| handle_left(keysym, data) || handle_right(keysym, data))
	{
		data->d_wall = distance_to_wall(keysym, *data) * 50;
		data->pix_mov = 50;
		data->keypress_num++;
	}
	handle_esc_all_collected(keysym, data);
	return (0);
}

int	distance_to_wall(int keysym, t_data data)
{
	int	d_wall;

	d_wall = -1;
	while ((data.grid[data.posy_p][data.posx_p] != '1'
		&& data.grid[data.posy_p][data.posx_p] != 'E'
		&& (data.c_collected != data.c_count))
		|| data.grid[data.posy_p][data.posx_p] != '1')
	{
		if (keysym == UP)
			data.posy_p--;
		else if (keysym == DOWN)
			data.posy_p++;
		else if (keysym == RIGHT)
			data.posx_p++;
		else if (keysym == LEFT)
			data.posx_p--;
		d_wall++;
	}
	return (d_wall);
}
