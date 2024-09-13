/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/14 14:03:39 by lmerveil         ###   ########.fr       */
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
# include <sys/stat.h>
# include <time.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define RESET   "\x1b[0m"
# define ORANGE  "\x1b[38;5;208m"

# define ZERO 	0
# define UP 	119
# define DOWN 	115
# define LEFT 	97
# define RIGHT	100

typedef struct pos_s
{
	int	map_x;
	int	map_y;
	int	x;
	int	y;
}		t_pos;

typedef struct enemy_s
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	char	color_flag;
	void	*img_enemy;
	void	*img_enemy_move;
	int		dir;
	int		third_dir;
	int		d_wall;
	int		pix_mov;
	int		dir_counter;
}			t_enemy;

typedef struct img_s
{
	int		height;
	int		width;

	void	*current_img;

	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_player_closed;
	void	*img_enemy_red;
	void	*img_enemy_blue;
	void	*img_enemy_yellow;
	void	*img_enemy_pink;
	void	*img_enemy_red_move;
	void	*img_enemy_blue_move;
	void	*img_enemy_yellow_move;
	void	*img_enemy_pink_move;
	void	*img_exit;
	void	*img_wall;
	void	*img_path;
	void	*img_collect;
	char	*player_up;
	char	*player_down;
	char	*player_right;
	char	*player_left;
	char	*player_closed;
	char	*enemy_red;
	char	*enemy_blue;
	char	*enemy_yellow;
	char	*enemy_pink;
	char	*enemy_red_move;
	char	*enemy_blue_move;
	char	*enemy_yellow_move;
	char	*enemy_pink_move;
	char	*exit;
	char	*wall;
	char	*path;
	char	*collect;

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
	int		p;
	int		e;
	int		c_count;
	int		c_flag;
	int		exit_flag;
	int		c_collected;
	char	**grid;
	char	**parse_grid;
	void	*mlx;
	void	*win;
	int		keypress_num;
	int		keypress_flag;
	int		d_wall;
	int		pix_mov;
	int		mov_queue;
	int		render_one;
	t_enemy	*tab_enemy;
	t_imgs	img;
	t_pos	pos;

	int		enemy_count;
	int		game_started;
	int		sizex;
	int		sizey;
}			t_data;

// format check
void		check_fileformat(char *filename);
void		get_dimensions_check_empty(t_data *game);
void		check_rectangular(char *filename, t_data *game);
int			fillgrid(char *filename, t_data *game);
void		check_closed(t_data *game);
void		check_elements(t_data *game);
void		parse(char *filename, t_data *data);
void		flood_fill(t_data *game, int x, int y, char **grid);

// MLX GAME
void		initiate_mlx(t_data *data);
int			handle_keypress(int keysym, t_data *data);
int			render_map(t_data *data);
void		render_player(t_data *data);

// MLX utils
void		display_keypress_num(t_data	*data);
int			distance_to_wall(int keysym, t_data data);
void		adjust_ber_pos(t_data *data);
int			check_mov_queue(int keysym, t_data data);
int			check_up(int keysym, t_data data);
int			check_down(int keysym, t_data data);
int			check_left(int keysym, t_data data);
int			check_right(int keysym, t_data data);
void		*define_current_img(t_data data);
void		adjust_mapxy(t_data *data);

//MLX rendering - core
int			render_order_y(t_data	data);
void		render_walls_collectibles(int y, int x, t_data data);
void		render_up_left(int bonus_flag, t_data *data);
void		render_down_right(int bonus_flag, t_data *data);

//MLX keystrokes - core
int			handle_up(int keysym, t_data *data);
int			handle_down(int keysym, t_data *data);
int			handle_right(int keysym, t_data *data);
int			handle_left(int keysym, t_data *data);
void		handle_esc_all_collected(int keysym, t_data *data);
int			is_not_folder(const char *path);

// utils
int			open_map(char *filename, t_data *game);
void		free_grid(char **grid, int height);
void		init_struct(char *filename, t_data *game);
void		free_struct(t_data *game);
void		pre_free_init_struct(t_data *data);
void		parse_error(t_data *game);
void		free_close_free_struct(char *line, t_data *data);
int			check_valid_elements(t_data data);

// core
void		set_img(t_data *data);
void		set_img_path_file(t_data *data);
void		free_img_data(t_data *data);
void		set_img(t_data *data);
void		init_tab_enemy(t_data *data);
void		define_moving_enemy(int i, t_data *data);
int			close_window(t_data *data);

//bonus
void		ft_first_render_enemies(int y, int x, t_data data);

#endif // SO_LONG.H
