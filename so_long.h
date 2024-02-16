/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/16 15:04:41 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SO_LONG.H

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	int		posx_p;
	int		posy_p;
	int		posx_e;
	int		posy_e;
	int		width;
	int		height;
	int		p; // player
	int		e; // exit
	int 	c;  // collectible
	char	**grid;
}			t_data;

// format check
int			check_fileformat(char *str);
int			check_rectangular(char *filename, t_data *game);
char		**init_grid(t_data *game);
void		fillgrid(char *filename, t_data *game);
int			check_closed(t_data *game);
int			check_elements(t_data *game);

// utils
int			open_map(char *filename);
void		free_grid(t_data *game);
void		init_struct(t_data *game);
#endif // SO_LONG.H