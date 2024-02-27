/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:21 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/26 22:26:31 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		exit(0);
	
	if (ac != 2)
	{
		ft_printf("Error\nWrong number of arguments!\n");
		return (0);
	}
	data = parse(av[1]); // if fails exits
	
	//MLX INITIATION
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	set_img(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * data->img.width, data->height * data->img.height, "PAC-MAN 3.1");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_wall, 0, 0);
	render_map(data);
	
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data->mlx_ptr);

	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_struct(data);
}
