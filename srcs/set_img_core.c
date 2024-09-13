/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:51:50 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/14 13:12:31 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_img_two(t_data *data);
static void	set_img_three(t_data *data);
static void	set_img_four(t_data *data);

void	set_img(t_data *data)
{
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx, data->img.wall,
			&(data->img.width), &(data->img.height));
	if (!data->img.img_wall)
		free_struct(data);
	data->img.img_path = mlx_xpm_file_to_image(data->mlx, data->img.path,
			&(data->img.width), &(data->img.height));
	if (!data->img.img_path)
		free_struct(data);
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx, data->img.collect,
			&(data->img.width), &(data->img.height));
	if (!data->img.img_collect)
		free_struct(data);
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx, data->img.exit,
			&(data->img.width), &(data->img.height));
	if (!data->img.img_exit)
		free_struct(data);
	set_img_two(data);
	set_img_three(data);
	set_img_four(data);
}

static void	set_img_two(t_data *data)
{
	data->img.img_player_left = mlx_xpm_file_to_image(data->mlx,
			data->img.player_left, &(data->img.width), &(data->img.height));
	if (!data->img.img_player_left)
		free_struct(data);
	data->img.img_player_right = mlx_xpm_file_to_image(data->mlx,
			data->img.player_right, &(data->img.width), &(data->img.height));
	if (!data->img.img_player_right)
		free_struct(data);
	data->img.img_player_up = mlx_xpm_file_to_image(data->mlx,
			data->img.player_up, &(data->img.width), &(data->img.height));
	if (!data->img.img_player_up)
		free_struct(data);
	data->img.img_player_down = mlx_xpm_file_to_image(data->mlx,
			data->img.player_down, &(data->img.width), &(data->img.height));
	if (!data->img.img_player_down)
		free_struct(data);
	data->img.img_player_closed = mlx_xpm_file_to_image(data->mlx,
			data->img.player_closed, &(data->img.width), &(data->img.height));
	if (!data->img.img_player_closed)
		free_struct(data);
}

static void	set_img_three(t_data *data)
{
	data->img.img_enemy_red = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_red, &(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_red)
		free_struct(data);
	data->img.img_enemy_blue = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_blue, &(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_blue)
		free_struct(data);
	data->img.img_enemy_yellow = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_yellow, &(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_yellow)
		free_struct(data);
	data->img.img_enemy_pink = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_pink, &(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_pink)
		free_struct(data);
}

static void	set_img_four(t_data *data)
{
	data->img.img_enemy_red_move = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_red_move, &(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_red_move)
		free_struct(data);
	data->img.img_enemy_blue_move = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_blue_move, &(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_blue_move)
		free_struct(data);
	data->img.img_enemy_yellow_move = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_yellow_move,
			&(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_yellow_move)
		free_struct(data);
	data->img.img_enemy_pink_move = mlx_xpm_file_to_image(data->mlx,
			data->img.enemy_pink_move, &(data->img.width), &(data->img.height));
	if (!data->img.img_enemy_pink_move)
		free_struct(data);
	data->img.current_img = data->img.img_player_up;
}

void	define_moving_enemy(int i, t_data *data)
{
	data->tab_enemy[i].d_wall = 0;
	data->tab_enemy[i].dir = 0;
	data->tab_enemy[i].third_dir = 0;
	if (data->tab_enemy[i].color_flag == 'R')
	{
		data->tab_enemy[i].img_enemy = data->img.img_enemy_red;
		data->tab_enemy[i].img_enemy_move = data->img.img_enemy_red_move;
	}
	else if (data->tab_enemy[i].color_flag == 'B')
	{
		data->tab_enemy[i].img_enemy_move = data->img.img_enemy_blue_move;
		data->tab_enemy[i].img_enemy = data->img.img_enemy_blue;
	}
	else if (data->tab_enemy[i].color_flag == 'K')
	{
		data->tab_enemy[i].img_enemy_move = data->img.img_enemy_pink_move;
		data->tab_enemy[i].img_enemy = data->img.img_enemy_pink;
	}
	else if (data->tab_enemy[i].color_flag == 'Y')
	{
		data->tab_enemy[i].img_enemy_move = data->img.img_enemy_yellow_move;
		data->tab_enemy[i].img_enemy = data->img.img_enemy_yellow;
	}
}
