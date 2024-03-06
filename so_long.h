/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/06 03:53:13 by lmerveil         ###   ########.fr       */
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
# include <time.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"
#define ORANGE  "\x1b[38;5;208m"

#define ZERO 	0
#define UP 		119
#define DOWN 	115
#define LEFT 	97
#define RIGHT	100

#define U		1
#define D 		2
#define L		3
#define R		4

typedef	struct pos_s
{	
	int		map_x;		//x coordinate of player on rendered map
	int		map_y;		//y coordinate of player on rendered map
	int		x;
	int		y;
} 			t_pos;

typedef	struct enemy_s
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	char	color_flag;
	void	*img_enemy;
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
	void 	*img_enemy_red;
	void	*img_enemy_blue;
	void	*img_enemy_yellow;
	void	*img_enemy_pink;
	void	*img_exit;
	void	*img_wall;
	void	*img_path;
	void	*img_collect;
	
	char	*player_up;
	char	*player_down;
	char	*player_right;
	char	*player_left;
	char	*player_closed;
	char 	*enemy_red;
	char	*enemy_blue;
	char	*enemy_yellow;
	char	*enemy_pink;
	char	*exit;
	char	*wall;
	char	*path;
	char	*collect;
}			t_imgs;

typedef struct data_s
{
	int		fd;
	int		posx_p; //x coordinate of player on .ber map
	int		posy_p; //y coordinate of player on .ber map
	
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
int			render_map(t_data *data);
void		render_player(t_data *data);

// MLX utils
void		set_img(t_data *data);
void		free_img_data(t_data *data);
void		display_keypress_num(t_data	*data);
int			distance_to_wall(int keysym, t_data data);
void		adjust_ber_pos(t_data *data);
void		repix_mov(t_data *data);
int			check_mov_queue(int keysym, t_data data);
int			check_up(int keysym , t_data data);
int			check_down(int keysym , t_data data);
int			check_left(int keysym , t_data data);
int			check_right(int keysym , t_data data);
void		*define_current_img(t_data data);

//MLX rendering
int			render_first_frame(t_data *data);
int			render_order_x(t_data	data);
int			render_order_y(t_data	data);

//MLX keystrokes
int			handle_up(int keysym, t_data *data);
int			handle_down(int keysym, t_data *data);
int			handle_right(int keysym, t_data *data);
int			handle_left(int keysym, t_data *data);
void		handle_esc_all_collected(int keysym, t_data *data);
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


//BONUS
void		init_tab_enemy(t_data *data);
int			distance_to_wall_ghost(int i, t_data data);
void		adjust_ber_pos_enemy(int i, t_data *data);
void		get_random_dir_distance_to_wall(int i, t_data *data);
int 		getRandomDirection();
void		render_enemy(t_data *data);