/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/26 16:25:40 by lmerveil         ###   ########.fr       */
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

typedef struct s_data
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
}			t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	char 	*grass;
}			t_mlx;

// struct for creating an image
typedef struct s_image
{
	void 	*img; /*refers to the address mlx_new_image returns*/
	char	*addr;
	int 	bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}			t_image;

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
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		put_img_to_win(void *mlx, void *mlx_win, char *relative_path);
int			handle_keypress(int keysym, t_mlx *data);
int			handle_keyrelease(int keysym, void *data);
int			handle_no_event(void *data);
void		render_map(t_mlx *mlx, t_data *game);

// MLX utils
void	init_mlx_struct(t_mlx	*mlx);

// utils
int			open_map(char *filename, t_data *game);
void		free_grid(char **grid, int height);
void		init_struct(char *filename, t_data *game);
void		print_map(char **map, int height, int width);
void		free_struct(t_data *game);
char		**dup_grid(t_data *game);
void		parse_error(t_data *game);

#endif // SO_LONG.H