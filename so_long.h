/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/27 10:36:31 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SO_LONG.H

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct img_s
{
	int		height;
	int		width;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_path;
	void	*img_collect;
	char	*player;
	char	*path;
	char	*wall;
	char	*collect;
	char	*exit;
}			t_imgs;

typedef struct cnt_s
{
	int		fd;
	int		posx_p;
	int		posy_p;
	int		posx_e;
	int		posy_e;
	int		width;
	int		height;
	int 	p;      // player
	int 	e;      // exit
	int 	c;      // collectible
	int 	c_flag; // collectibles collected
	int		exit_flag;
	int		count_v;
	char	**grid;
	char	**parse_grid;
	void	*mlx_ptr;
	void	*win_ptr;
	t_imgs	img;
}			t_data;



// format check
void		check_fileformat(char *str, t_data *game);
void		get_dimensions_check_empty(t_data *game);
void		check_rectangular(char *filename, t_data *game);
char		**init_grid(char **grid, t_data *game);
void		fillgrid(char *filename, t_data *game);
void		check_closed(t_data *game);
void		check_elements(t_data *game);
t_data		*parse(char *filename);
void		flood_fill(t_data *game, int x, int y, char **grid);

// MLX GAME
void		initiate_mlx(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		put_img_to_win(void *mlx, void *mlx_win, char *relative_path);
int			handle_keypress(int keysym, t_data *data);
int			handle_keyrelease(int keysym, void *data);
int			handle_no_event(void *data);
void		render_map(t_data *data);

// MLX utils
void		set_img(t_data *data);
// utils
int			open_map(char *filename, t_data *game);
void		free_grid(char **grid, int height);
void		init_struct(char *filename, t_data *game);
void		print_map(char **map, int height, int width);
void		free_struct(t_data *game);
char		**dup_grid(t_data *game);
void		parse_error(t_data *game);

#endif // SO_LONG.H