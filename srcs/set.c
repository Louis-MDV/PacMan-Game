/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:04:55 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/06 03:53:32 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initiate_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	set_img(data);
	init_tab_enemy(data);
	data->win = mlx_new_window(data->mlx, data->width * data->img.width, data->height * data->img.height, "PAC-MAN");
	if (data->win == NULL)
	{
		free(data->win);
		return ;
	}
	data->pos.map_x			= data->posx_p * 50;
	data->pos.map_y 		= data->posy_p * 50;
}

//fill tab_enemy with coordiantes and color of each enemy
void	init_tab_enemy(t_data *data)
{
	int	x;
	int	y;
	int i;
	
	i = 0;
	y = -1;
	while (++y < data->height - 1)
	{
		x = -1;
		while (++x < data->width - 1)
		{
			if (data->grid[y][x] == 'B' || data->grid[y][x] == 'Y' || data->grid[y][x] == 'R' || data->grid[y][x] == 'K')
			{	
				data->tab_enemy[i].x = x;
				data->tab_enemy[i].y = y;
				data->tab_enemy[i].pix_mov = 50;
				data->tab_enemy[i].map_x = x * 50;
				data->tab_enemy[i].map_y = y * 50;
				data->tab_enemy[i].color_flag = data->grid[y][x];
				data->tab_enemy[i].dir = 0;
				data->tab_enemy[i].third_dir = 0;
				data->tab_enemy[i].d_wall = 0;				
				if (data->grid[y][x] == 'R')
					data->tab_enemy[i].img_enemy = data->img.img_enemy_red;
				else if (data->grid[y][x] == 'B')
					data->tab_enemy[i].img_enemy = data->img.img_enemy_blue;
				else if (data->grid[y][x] == 'Y')
					data->tab_enemy[i].img_enemy = data->img.img_enemy_yellow;
				else if (data->grid[y][x] == 'K')
					data->tab_enemy[i].img_enemy = data->img.img_enemy_pink;
			i++;
			}
		}
	}
}

void	init_struct(char *filename, t_data *data)
{
	data->fd			= open_map(filename, data);
	data->width 		= 0;
	data->height 		= 0;
	data->p 			= 0;
	data->e 			= 0;
	data->c_count 		= 0;
	data->posx_p 		= 0;
	data->posy_p 		= 0;

	data->posx_e 		= 0;
	data->posy_e 		= 0;
	data->exit_flag		= 0;
	data->c_flag		= 0;
	data->c_count		= 0;
	data->c_collected	= 0;
	data->keypress_num	= 0;
	data->keypress_flag = 0;

	data->d_wall		= 0;
	data->pix_mov		= 50;
	data->mov_queue 	= ZERO;
	data->render_one	= 0;
	
	data->enemy_count 	= 0;
	data->game_started	= 0;
}

void	set_img(t_data *data)
{
	data->img.height 			= 50;
	data->img.width 			= 50;
	
	data->img.wall 				= "./xpm/wall50.xpm";
	data->img.path 				= "./xpm/path50.xpm";
	data->img.collect			= "./xpm/collect50.xpm";
	data->img.exit 				= "./xpm/exit50.xpm";
	data->img.img_wall 			= mlx_xpm_file_to_image(data->mlx, data->img.wall, &(data->img.width), &(data->img.height));
	data->img.img_path 			= mlx_xpm_file_to_image(data->mlx, data->img.path, &(data->img.width), &(data->img.height));
	data->img.img_collect		= mlx_xpm_file_to_image(data->mlx, data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_exit 			= mlx_xpm_file_to_image(data->mlx, data->img.exit, &(data->img.width), &(data->img.height));
	
	data->img.player_left 		= "./xpm/pacmanleft.xpm";
	data->img.player_right 		= "./xpm/pacmanright.xpm";
	data->img.player_up 		= "./xpm/pacmanup.xpm";
	data->img.player_down		= "./xpm/pacmandown.xpm";
	data->img.player_closed		= "./xpm/pacmanclosed.xpm";
	data->img.img_player_left	= mlx_xpm_file_to_image(data->mlx, data->img.player_left, &(data->img.width), &(data->img.height));
	data->img.img_player_right	= mlx_xpm_file_to_image(data->mlx, data->img.player_right, &(data->img.width), &(data->img.height));
	data->img.img_player_up		= mlx_xpm_file_to_image(data->mlx, data->img.player_up, &(data->img.width), &(data->img.height));
	data->img.img_player_down	= mlx_xpm_file_to_image(data->mlx, data->img.player_down, &(data->img.width), &(data->img.height));
	data->img.img_player_closed	= mlx_xpm_file_to_image(data->mlx, data->img.player_closed, &(data->img.width), &(data->img.height));

	data->img.enemy_red			= "./xpm/red_enemy.xpm";
	data->img.enemy_blue		= "./xpm/blue_enemy.xpm";
	data->img.enemy_yellow		= "./xpm/yellow_enemy.xpm";
	data->img.enemy_pink		= "./xpm/pink_enemy.xpm";
	data->img.img_enemy_red 	= mlx_xpm_file_to_image(data->mlx, data->img.enemy_red, &(data->img.width), &(data->img.height));
	data->img.img_enemy_blue 	= mlx_xpm_file_to_image(data->mlx, data->img.enemy_blue, &(data->img.width), &(data->img.height));
	data->img.img_enemy_yellow 	= mlx_xpm_file_to_image(data->mlx, data->img.enemy_yellow, &(data->img.width), &(data->img.height));
	data->img.img_enemy_pink 	= mlx_xpm_file_to_image(data->mlx, data->img.enemy_pink, &(data->img.width), &(data->img.height));

	data->img.current_img		= data->img.img_player_up;
}
void	free_img_data(t_data *data)
{
	mlx_destroy_image (data->mlx, data->img.wall);
	mlx_destroy_image (data->mlx, data->img.path);
	mlx_destroy_image (data->mlx, data->img.collect);
	mlx_destroy_image (data->mlx, data->img.player_down);
	mlx_destroy_image (data->mlx, data->img.player_up);
	mlx_destroy_image (data->mlx, data->img.player_right);
	mlx_destroy_image (data->mlx, data->img.player_left);
	mlx_destroy_image (data->mlx, data->img.player_closed);
	mlx_destroy_image (data->mlx, data->img.exit);
}