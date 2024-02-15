/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:40:40 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/15 12:03:00 by lmerveil         ###   ########.fr       */
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
	int		width;
	int		height;
	char	**grid;
}			t_data;

// format check
int			check_fileformat(char *str);
int			check_rectangular(char *filename, t_data *game);
char		**init_grid(t_data *game);
void		fillgrid(char *filename, t_data *game);
int			check_closed(t_data *game);

// utils
int			open_map(char *filename);
void		free_grid(t_data *game);
#endif // SO_LONG.H