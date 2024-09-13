/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/12 20:46:04 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_render_map(t_data *data)
{
	srand(time(NULL));
	if (data->keypress_flag == UP || data->keypress_flag == LEFT
		|| data->keypress_flag == ZERO)
	{
		if (data->keypress_flag != ZERO)
			data->game_started = 1;
		render_up_left(1, data);
	}
	else if (data->keypress_flag == DOWN || data->keypress_flag == RIGHT)
	{
		data->game_started = 1;
		render_down_right(1, data);
	}
	if (data->game_started == 1)
		render_enemy(data);
	return (display_keypress_num(data), usleep(4000), 0);
}
