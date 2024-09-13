/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:04:55 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/14 13:46:12 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_img_elements_null(t_data *data);

void	initiate_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		pre_free_init_struct(data);
	set_img_path_file(data);
	mlx_get_screen_size(data->mlx, &(data->sizex), &(data->sizey));
	if (data->width * data->img.width > data->sizex
		|| data->height * data->img.height > data->sizey)
	{
		ft_printf("Error\nMap too big for sreen!\n");
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data->tab_enemy);
		pre_free_init_struct(data);
	}
	data->win = NULL;
	set_img(data);
	init_tab_enemy(data);
	data->win = mlx_new_window(data->mlx, data->width * data->img.width,
			data->height * data->img.height, "Pac-Man");
	if (data->win == NULL)
		free_struct(data);
	data->pos.map_x = data->posx_p * 50;
	data->pos.map_y = data->posy_p * 50;
}

void	init_struct(char *filename, t_data *data)
{
	data->fd = open_map(filename, data);
	data->width = 0;
	data->height = 0;
	data->p = 0;
	data->e = 0;
	data->c_count = 0;
	data->posx_p = 0;
	data->posy_p = 0;
	data->posx_e = 0;
	data->posy_e = 0;
	data->exit_flag = 0;
	data->c_flag = 0;
	data->c_count = 0;
	data->c_collected = 0;
	data->keypress_num = 0;
	data->keypress_flag = 0;
	data->d_wall = 0;
	data->pix_mov = 50;
	data->mov_queue = ZERO;
	data->render_one = 0;
	data->enemy_count = 0;
	data->game_started = 0;
	data->sizex = 0;
	data->sizey = 0;
	data->tab_enemy = NULL;
}

void	set_img_path_file(t_data *data)
{
	data->img.height = 50;
	data->img.width = 50;
	data->img.wall = "./xpm/wall50.xpm";
	data->img.path = "./xpm/path50.xpm";
	data->img.collect = "./xpm/collect50.xpm";
	data->img.exit = "./xpm/exit50.xpm";
	data->img.player_left = "./xpm/pacmanleft.xpm";
	data->img.player_right = "./xpm/pacmanright.xpm";
	data->img.player_up = "./xpm/pacmanup.xpm";
	data->img.player_down = "./xpm/pacmandown.xpm";
	data->img.player_closed = "./xpm/pacmanclosed.xpm";
	data->img.enemy_red = "./xpm/red_enemy.xpm";
	data->img.enemy_blue = "./xpm/blue_enemy.xpm";
	data->img.enemy_yellow = "./xpm/yellow_enemy.xpm";
	data->img.enemy_pink = "./xpm/pink_enemy.xpm";
	data->img.enemy_red_move = "./xpm/red_enemy_move.xpm";
	data->img.enemy_blue_move = "./xpm/blue_enemy_move.xpm";
	data->img.enemy_yellow_move = "./xpm/yellow_enemy_move.xpm";
	data->img.enemy_pink_move = "./xpm/pink_enemy_move.xpm";
	set_img_elements_null(data);
}

//fill tab_enemy with coordiantes and color of each enemy
void	init_tab_enemy(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (++y < data->height - 1)
	{
		x = -1;
		while (++x < data->width - 1)
		{
			if (data->grid[y][x] == 'B' || data->grid[y][x] == 'Y'
			|| data->grid[y][x] == 'R' || data->grid[y][x] == 'K')
			{
				data->tab_enemy[i].x = x;
				data->tab_enemy[i].y = y;
				data->tab_enemy[i].pix_mov = 50;
				data->tab_enemy[i].map_x = x * 50;
				data->tab_enemy[i].map_y = y * 50;
				data->tab_enemy[i].color_flag = data->grid[y][x];
				define_moving_enemy(i, data);
				i++;
			}
		}
	}
}

static void	set_img_elements_null(t_data *data)
{
	data->img.img_wall = NULL;
	data->img.img_path = NULL;
	data->img.img_collect = NULL;
	data->img.img_exit = NULL;
	data->img.img_player_left = NULL;
	data->img.img_player_right = NULL;
	data->img.img_player_up = NULL;
	data->img.img_player_down = NULL;
	data->img.img_player_closed = NULL;
	data->img.img_enemy_red = NULL;
	data->img.img_enemy_blue = NULL;
	data->img.img_enemy_pink = NULL;
	data->img.img_enemy_yellow = NULL;
	data->img.img_enemy_red_move = NULL;
	data->img.img_enemy_blue_move = NULL;
	data->img.img_enemy_yellow_move = NULL;
	data->img.img_enemy_pink_move = NULL;
}
