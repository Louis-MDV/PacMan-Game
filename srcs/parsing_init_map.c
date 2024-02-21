/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:41:12 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/21 12:09:09 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// init grid pointer on xheight string (char **)
// 1.alloc size for height strings
// 2.alloc size for
char	**init_grid(char **grid, t_data *game)
{
	// int	i;

	// i = 0;
	grid = (char **)malloc(game->height * sizeof(char *));
	if (!grid)
		exit(0);
	// while (i < game->height)
	// {
	// 	grid[i] = (char *)malloc(game->width + 1 * sizeof(char));
	// 	if (!grid[i])
	// 	{
	// 		free_grid(grid, game);
	// 		exit(0);
	// 	}
	// 	i++;
	// }
	return (grid);
}

// fill grid with all elements of map
void	fillgrid(char *filename, t_data *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open_map(filename);
	game->grid = init_grid(game->grid, game);
	game->parse_grid = init_grid(game->parse_grid, game);
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		game->grid[i] = ft_strdup(line);
		game->parse_grid[i]  = ft_strdup(line);
		free(line);
		if(!game->grid[i] || !game->parse_grid[i])
		{
			ft_printf("Error: Memory allocation failure for grid[%d]\n", i);
			free_struct(game);
			exit (0);
		}
		printf("%d\n", i);
		i++;
	}
	close(fd);

	// print_map(game->parse_grid, game->height, game->width);
	// ft_printf("\n");
	// print_map(game->grid, game->height, game->width);
}
