/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:21 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/27 23:31:48 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Error\nWrong number of arguments!\n");
		return (0);
	}
	parse(av[1], &data); // if fails exits
	initiate_mlx(&data);
	render_map(&data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, animation_loop, &data);
	mlx_loop(data.mlx_ptr);
}
int	animation_loop(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player_closed, data->img.height * (data->posx_p), data->img.height * (data->posy_p));
	usleep (100000);
	
	return(0);
}