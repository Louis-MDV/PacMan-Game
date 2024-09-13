/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_core.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:30:09 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/12 19:16:54 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_up(int keysym, t_data *data)
{
	if (!check_up(keysym, *data))
		return (0);
	else if (keysym == UP)
	{
		data->keypress_flag = UP;
		data->img.current_img = data->img.img_player_up;
		return (1);
	}
	return (0);
}

int	handle_down(int keysym, t_data *data)
{
	if (!check_down(keysym, *data))
		return (0);
	else if (keysym == DOWN)
	{
		data->keypress_flag = DOWN;
		data->img.current_img = data->img.img_player_down;
		return (1);
	}
	return (0);
}

int	handle_right(int keysym, t_data *data)
{
	if (!check_right(keysym, *data))
		return (0);
	else if (keysym == RIGHT)
	{
		data->keypress_flag = RIGHT;
		data->img.current_img = data->img.img_player_right;
		return (1);
	}
	return (0);
}

int	handle_left(int keysym, t_data *data)
{
	if (!check_left(keysym, *data))
		return (0);
	else if (keysym == LEFT)
	{
		data->keypress_flag = LEFT;
		data->img.current_img = data->img.img_player_left;
		return (1);
	}
	return (0);
}
