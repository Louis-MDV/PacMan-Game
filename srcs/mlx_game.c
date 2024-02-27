/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/27 00:22:51 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx_struct(t_data	*mlx)
{
	mlx->img.img_wall 	= "xpm/wall50.xpm";
}

// void	my_mlx_pixel_put(t_imgs *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// void	render_img(t_image data, void *img, int x, int y)
// {
// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, data->img.width * x, data->img.height * y);
// }

// void	put_img_to_win(void *mlx, void *mlx_win, char *relative_path)
// {
// 	t_imgs	imgs;
// 	int		img_width;
// 	int		img_height;
	
// 	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

// void	put_img_to_win(void *mlx, void *mlx_win, char *relative_path)
// {
// 	t_imgs	img;
// 	int		img_width;
// 	int		img_height;
	
// 	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// }


void	render_map(t_data *data)
{
	int y = 0;
	int x = 0;

	while (y < data->height)
	{
		x = 0;
		while (data->grid[y][x] != '\n')
		{
			if (data->grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_wall, 50*x, 50*y);
			if (data->grid[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_path, 50*x, 50*y);
			if (data->grid[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_player, 50*x, 50*y);
			if (data->grid[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_collect, 50*x, 50*y);
			if (data->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_exit, 50*x, 50*y);
			x++;
		}
	y++;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	(void)data;
    /* This function needs to exist, but it is useless for the moment */
    return (0);
}