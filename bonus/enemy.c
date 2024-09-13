/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:37:59 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/12 19:59:33 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_moving_enemy(int i, t_data data);

void	render_enemy(t_data *data)
{
	int	i;

	i = -1;
	while (i++ < data->enemy_count - 1)
	{
		if (data->tab_enemy[i].d_wall == 0)
			get_random_dir_distance_to_wall(i, data);
		if (data->tab_enemy[i].dir == U)
			data->tab_enemy[i].map_y--;
		else if (data->tab_enemy[i].dir == D)
			data->tab_enemy[i].map_y++;
		else if (data->tab_enemy[i].dir == L)
			data->tab_enemy[i].map_x--;
		else if (data->tab_enemy[i].dir == R)
			data->tab_enemy[i].map_x++;
		put_moving_enemy(i, *data);
		data->tab_enemy[i].d_wall--;
		data->tab_enemy[i].pix_mov--;
		if (data->tab_enemy[i].pix_mov == 0)
			adjust_ber_pos_enemy(i, data);
		if (do_entities_overlap(i, *data))
			free_struct(data);
	}
}

static void	put_moving_enemy(int i, t_data data)
{
	if (data.tab_enemy[i].pix_mov % 2 == 0)
		mlx_put_image_to_window(data.mlx, data.win,
			data.tab_enemy[i].img_enemy, data.tab_enemy[i].map_x,
			data.tab_enemy[i].map_y);
	else
		mlx_put_image_to_window(data.mlx, data.win,
			data.tab_enemy[i].img_enemy_move, data.tab_enemy[i].map_x,
			data.tab_enemy[i].map_y);
}

int	distance_to_wall_ghost(int i, t_data data)
{
	int	d_wall;
	int	temp_x;
	int	temp_y;

	d_wall = -1;
	temp_x = data.tab_enemy[i].x;
	temp_y = data.tab_enemy[i].y;
	while (data.grid[temp_y][temp_x] != '1' && data.grid[temp_y][temp_x] != 'E')
	{
		if (data.tab_enemy[i].dir == U)
			temp_y--;
		else if (data.tab_enemy[i].dir == D)
			temp_y++;
		else if (data.tab_enemy[i].dir == R)
			temp_x++;
		else if (data.tab_enemy[i].dir == L)
			temp_x--;
		d_wall++;
	}
	return (d_wall * 50);
}

//  adjusts the grid ber pos every 50 maps frames rendered
void	adjust_ber_pos_enemy(int i, t_data *data)
{
	if (data->tab_enemy[i].dir == U)
		data->tab_enemy[i].y--;
	else if (data->tab_enemy[i].dir == D)
		data->tab_enemy[i].y++;
	else if (data->tab_enemy[i].dir == L)
		data->tab_enemy[i].x--;
	else if (data->tab_enemy[i].dir == R)
		data->tab_enemy[i].x++;
	data->tab_enemy[i].pix_mov = 50;
}
