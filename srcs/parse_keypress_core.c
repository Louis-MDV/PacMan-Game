/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keypress_core.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:21:54 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/12 19:15:49 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_up(int keysym, t_data data)
{
	if (keysym != UP)
		return (0);
	else if (data.grid[data.posy_p - 1][data.posx_p] == '1')
		return (
			ft_printf(ORANGE"Can't move up! There's a wall...\n"RESET)
			, 0);
	else if (data.grid[data.posy_p - 1][data.posx_p] == 'E'
		&& data.c_collected != data.c_count)
		return (
			ft_printf(ORANGE"Collect remaining collectibles to exit...\n"RESET)
			, 0);
	else
		return (1);
}

int	check_down(int keysym, t_data data)
{
	if (keysym != DOWN)
		return (0);
	else if (data.grid[data.posy_p + 1][data.posx_p] == '1')
		return (ft_printf(
				ORANGE"Can't move down! There's a wall...\n"RESET)
			, 0);
	else if (data.grid[data.posy_p + 1][data.posx_p] == 'E'
		&& data.c_collected != data.c_count)
		return (ft_printf(
				ORANGE"Collect remaining collectibles to exit...\n"RESET)
			, 0);
	else
		return (1);
}

int	check_right(int keysym, t_data data)
{
	if (keysym != RIGHT)
		return (0);
	else if (data.grid[data.posy_p][data.posx_p + 1] == '1')
		return (ft_printf(
				ORANGE"Can't move up! There's a wall...\n"RESET)
			, 0);
	else if (data.grid[data.posy_p][data.posx_p + 1] == 'E'
		&& data.c_collected != data.c_count)
		return (ft_printf(
				ORANGE"Collect remaining collectibles to exit...\n"RESET)
			, 0);
	else
		return (1);
}

int	check_left(int keysym, t_data data)
{
	if (keysym != LEFT)
		return (0);
	else if (data.grid[data.posy_p][data.posx_p - 1] == '1')
		return (ft_printf(
				ORANGE"Can't move up! There's a wall...\n"RESET)
			, 0);
	else if (data.grid[data.posy_p][data.posx_p - 1] == 'E' && keysym == LEFT
		&& data.c_collected != data.c_count)
		return (ft_printf(
				ORANGE"Collect remaining collectibles to exit...\n"RESET)
			, 0);
	else
		return (1);
}

int	check_mov_queue(int keysym, t_data data)
{
	if (check_up(keysym, data) || check_down(keysym, data)
		|| check_left(keysym, data) || check_right(keysym, data))
		return (1);
	return (0);
}
