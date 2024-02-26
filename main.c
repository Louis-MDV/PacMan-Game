/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:33:21 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/26 16:30:26 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*game;
	t_mlx	data;

	if (ac != 2)
	{
		ft_printf("Error\nWrong number of arguments!\n");
		return (0);
	}
	game = parse(av[1]); // if fails exits
	
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 450, 500, "Hello World");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (0);
	}

	init_mlx_struct(&data);
	render_map(&data, game);

	// put_img_to_win(data.mlx_ptr, data.win_ptr, "xpm/map1.xpm");
	// put_img_to_win(data.mlx_ptr, data.win_ptr, "xpm/pacman1.xpm");
	
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_struct(game);
}
int	handle_keypress(int keysym, t_mlx *data)
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