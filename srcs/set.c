/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:04:55 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/27 10:37:09 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initiate_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	set_img(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * data->img.width, data->height * data->img.height, "PAC-MAN 3.1");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
}

void	init_struct(char *filename, t_data *data)
{
	data->fd		= open_map(filename, data);
	data->width 	= 0;
	data->height 	= 0;
	data->p 		= 0;
	data->e 		= 0;
	data->c 		= 0;
	data->posx_p 	= 0;
	data->posy_p 	= 0;
	data->posx_e 	= 0;
	data->posy_e 	= 0;
	data->exit_flag	= 0;
	data->c_flag	= 0;
	data->count_v	= 0;
}

void	set_img(t_data *data)
{
	data->img.height 		= 50;
	data->img.width 		= 50;
	data->img.wall 			= "./xpm/wall50.xpm";
	data->img.path 			= "./xpm/path50.xpm";
	data->img.collect		= "./xpm/collect50.xpm";
	data->img.player 		= "./xpm/player50.xpm";
	data->img.exit 			= "./xpm/exit50.xpm";
	data->img.img_wall 		= mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall, &(data->img.width), &(data->img.height));
	data->img.img_path 		= mlx_xpm_file_to_image(data->mlx_ptr, data->img.path, &(data->img.width), &(data->img.height));
	data->img.img_collect	= mlx_xpm_file_to_image(data->mlx_ptr, data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player	= mlx_xpm_file_to_image(data->mlx_ptr, data->img.player, &(data->img.width), &(data->img.height));
	data->img.img_exit 		= mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit, &(data->img.width), &(data->img.height));
}
