/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/12 20:14:11 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SO_LONG.H

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../so_long.h"

# define U	1
# define D 	2
# define L	3
# define R	4

// format check

void		ft_check_elements(t_data *game);
int			ft_check_valid_elements(t_data data);
void		ft_parse_bonus(char *filename, t_data *data);

// MLX GAME
int			ft_handle_keypress(int keysym, t_data *data);
int			ft_render_map(t_data *data);
void		render_enemy(t_data *data);
void		ft_parse_error(t_data *game);

//BONUS
int			distance_to_wall_ghost(int i, t_data data);
void		adjust_ber_pos_enemy(int i, t_data *data);
void		get_random_dir_distance_to_wall(int i, t_data *data);
// void		ft_render_walls_collectibles(int y, int x, t_data data);
int			do_entities_overlap(int i, t_data data);
void		define_moving_enemy(int i, t_data *data);

#endif // SO_LONG_BONUS.H
