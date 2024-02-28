/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/28 18:21:04 by lmerveil         ###   ########.fr       */
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

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"
#define ORANGE  "\x1b[38;5;208m"

typedef struct img_s
{
	int		height;
	int		width;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_player_closed;

	void	*img_exit;
	void	*img_wall;
	void	*img_path;
	void	*img_collect;
	
	char	*player_up;
	char	*player_down;
	char	*player_right;
	char	*player_left;
	char	*player_closed;
	
	char	*path;
	char	*wall;
	char	*collect;
	char	*exit;
}			t_imgs;

typedef struct data_s
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
	int 	c_count;      // number collectibles
	int 	c_flag; // collectibles collected
	int		exit_flag;
	int		c_collected;
	char	**grid;
	char	**parse_grid;
	void	*mlx_ptr;
	void	*win_ptr;
	int		keypress_num;
	int		keypress_flag;	
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
void		parse(char *filename, t_data *data);
void		flood_fill(t_data *game, int x, int y, char **grid);

// MLX GAME
void		initiate_mlx(t_data *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_keyrelease(int keysym, void *data);
int			handle_no_event(void *data);
int		render_map(t_data *data);

// MLX utils
void		set_img(t_data *data);
void		free_img_data(t_data *data);

//MLX keystrokes
void		handle_up(int keysym, t_data *data);
void		handle_down(int keysym, t_data *data);
void		handle_right(int keysym, t_data *data);
void		handle_left(int keysym, t_data *data);
void		handle_esc_all_collected(int keysym, t_data *data);
int			animation_loop(t_data *data);
int 		close_window(t_data *data);

// utils
int			open_map(char *filename, t_data *game);
void		free_grid(char **grid, int height);
void		init_struct(char *filename, t_data *game);
void		print_map(char **map, int height, int width);
void		free_struct(t_data *game);
char		**dup_grid(t_data *game);
void		parse_error(t_data *game);

#endif // SO_LONG.H