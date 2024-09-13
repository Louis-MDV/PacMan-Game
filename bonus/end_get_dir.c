/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_get_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/13 18:03:53 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_random_direction(void);

int	ft_handle_keypress(int keysym, t_data *data)
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

// check if any of the 50 pixels of player and enemy are in common
int	do_entities_overlap(int i, t_data data)
{
	int	e_topleft_x;
	int	e_topleft_y;
	int	e_bottomright_x;
	int	e_bottomright_y;

	e_topleft_x = data.tab_enemy[i].map_x;
	e_topleft_y = data.tab_enemy[i].map_y;
	e_bottomright_x = data.tab_enemy[i].map_x + 25;
	e_bottomright_y = data.tab_enemy[i].map_y + 25;
	if (data.pos.map_x <= e_bottomright_x && e_topleft_x <= data.pos.map_x + 25
		&& data.pos.map_y <= e_bottomright_y
		&& e_topleft_y <= data.pos.map_y + 25)
	{
		ft_printf(RED"You lose! Try again!!\n"RESET);
		return (1);
	}
	return (0);
}

// Function to generate a random direction between 1 and 4 U, D, L , R
static int	get_random_direction(void)
{
	return (rand() % 4 + 1);
}

// fixes a dir which enables a positive d_wall
void	get_random_dir_distance_to_wall(int i, t_data *data)
{
	int	d_wall;

	data->tab_enemy[i].dir = get_random_direction();
	d_wall = distance_to_wall_ghost(i, *data);
	while (d_wall <= 0)
	{
		data->tab_enemy[i].dir = get_random_direction();
		d_wall = distance_to_wall_ghost(i, *data);
	}
	data->tab_enemy[i].d_wall = d_wall;
}
