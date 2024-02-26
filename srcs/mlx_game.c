/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/26 16:26:29 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx_struct(t_mlx	*mlx)
{
	mlx->grass = "xpm/grass.xpm";
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_img_to_win(void *mlx, void *mlx_win, char *relative_path)
{
	t_image	img;
	int		img_width;
	int		img_height;
	
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

void	render_map(t_mlx *mlx, t_data *game)
{
	int y = 0;
	int x = 0;

	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 0)
				put_img_to_win(mlx->mlx_ptr, mlx->win_ptr, mlx->grass);
			x++;
		}
	y++;
	}
}
