/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:09 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/14 13:23:35 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_enemy_img_data(t_data *data);

static void	free_enemy_img_data(t_data *data)
{
	if (data->img.img_enemy_red)
		mlx_destroy_image(data->mlx, data->img.img_enemy_red);
	if (data->img.img_enemy_blue)
		mlx_destroy_image(data->mlx, data->img.img_enemy_blue);
	if (data->img.img_enemy_yellow)
		mlx_destroy_image(data->mlx, data->img.img_enemy_yellow);
	if (data->img.img_enemy_pink)
		mlx_destroy_image(data->mlx, data->img.img_enemy_pink);
	if (data->img.img_enemy_red_move)
		mlx_destroy_image(data->mlx, data->img.img_enemy_red_move);
	if (data->img.img_enemy_blue_move)
		mlx_destroy_image(data->mlx, data->img.img_enemy_blue_move);
	if (data->img.img_enemy_yellow_move)
		mlx_destroy_image(data->mlx, data->img.img_enemy_yellow_move);
	if (data->img.img_enemy_pink_move)
		mlx_destroy_image(data->mlx, data->img.img_enemy_pink_move);
}

void	free_img_data(t_data *data)
{
	data->img.current_img = NULL;
	if (data->img.img_wall)
		mlx_destroy_image(data->mlx, data->img.img_wall);
	if (data->img.img_path != NULL)
		mlx_destroy_image(data->mlx, data->img.img_path);
	if (data->img.img_collect)
		mlx_destroy_image(data->mlx, data->img.img_collect);
	if (data->img.img_exit)
		mlx_destroy_image(data->mlx, data->img.img_exit);
	if (data->img.img_player_left)
		mlx_destroy_image(data->mlx, data->img.img_player_left);
	if (data->img.img_player_right)
		mlx_destroy_image(data->mlx, data->img.img_player_right);
	if (data->img.img_player_up)
		mlx_destroy_image(data->mlx, data->img.img_player_up);
	if (data->img.img_player_down)
		mlx_destroy_image(data->mlx, data->img.img_player_down);
	if (data->img.img_player_closed)
		mlx_destroy_image(data->mlx, data->img.img_player_closed);
	free_enemy_img_data(data);
}

int	close_window(t_data *data)
{
	ft_printf(RED"\nThanks for playing! Game closed."RESET);
	ft_printf("\n");
	free_struct(data);
	return (0);
}

void	handle_esc_all_collected(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf(RED"\nThanks for playing! Game closed."RESET);
		ft_printf("\n");
		free_struct(data);
	}
	if (data->c_collected == data->c_count
		&& data->grid[data->posy_p][data->posx_p] == 'E')
	{
		ft_printf(GREEN "\nCongrats! YOU WIN!!" RESET);
		ft_printf("\n");
		free_struct(data);
	}
}

void	free_struct(t_data *data)
{
	free_grid(data->grid, data->height);
	free_grid(data->parse_grid, data->height);
	free_img_data(data);
	if (data->tab_enemy != NULL)
		free(data->tab_enemy);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
