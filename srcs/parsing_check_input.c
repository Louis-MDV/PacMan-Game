/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:38:45 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/21 12:01:15 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_fileformat(char *str, t_data *game)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".ber\0", 5) == 0)
		return (1);
	else
	{
		ft_printf("Error\nWrong input format\n");
		free(game);
		exit (0);
	}
}

void	get_dimensions(char *filename, t_data *game)
{
	int		fd;
	char	*line;

	game->height = 1; // height 1 cause line38
	fd = open_map(filename);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1; //1 cause cont dount '\0'
	free(line);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			game->height++;
		free(line);
	}
	close(fd);
	ft_printf("height: %d\n",game->height);
	ft_printf("width: %d\n", game->width);
}

int	check_rectangular(t_data *game)
{
	if (game->width != game->height)
		return (1);
	else
	{
		ft_printf("Error\nMap not rectangular!\n");
		free(game);
		exit (0);
	}
}

int	check_closed(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if ((game->grid[0][x] != '1' || game->grid[game->height - 1][x] != '1')
					|| (y != 0 && y != game->height - 1
					&& game->grid[y][0] != '1'
					&& game->grid[y][game->width - 1] != '1'))
			{
				ft_printf("Error\nMap not closed!\n");
				return(0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_elements(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if (game->grid[y][x] == 'P')
			{
				game->posx_p = x;
				game->posy_p = y;
				game->p++;
				x++;
			}
			else if (game->grid[y][x] == 'C')
			{
				game->c++;
				x++;
			}
			else if (game->grid[y][x] == 'E')
			{
				game->posx_e = x;
				game->posy_e = y;
				game->e++;
				x++;
			}
			else if (game->grid[y][x] == '1' || game->grid[y][x] == '0')
				x++;
			else
			{
				ft_printf("Error\nUnknown element in map\n");
				return(0);
			}
		}
		y++;
	}
	if (game->p != 1 || game->e != 1 || game->c <= 0)
	{
		ft_printf("Error\nMap has no player or no collectibles or no exit!\n");
		return(0);
	}
	return (1);
}

void flood_fill(t_data *game, int x, int y, char **grid)
{
	if (grid[y][x] == '1' || grid[y][x] == 'V')
        return ;

	// fprintf(stdout,"x: %d, y: %d\n", x, y);
    if (grid[y][x] == 'C')
	{
		// write(1, "collected\n", 10);
        game->c_flag++;
	}
    if (grid[y][x] == 'E')
    {
		game->exit_flag = 1;
		// fprintf(stdout, "exit_flag: %d\n c_flag: %d\n c: %d\n", game->exit_flag, game->c_flag, game->c);
		// write(1,"exited\n", 7);
	}
    grid[y][x] = 'V';
	// print_map(game->grid, game->height, game->width);
	// write(1, "\n",1);
	
	// Recursively call in all four directions
	flood_fill(game, x - 1, y, grid);
   	flood_fill(game, x, y - 1, grid);
   	flood_fill(game, x + 1, y, grid);
    flood_fill(game, x, y + 1, grid);
}

int	parse(t_data *game, char *filename)
{
	game = malloc(sizeof(t_data));
	if (!game)
		exit(0);
	init_struct(game);
	get_dimensions(filename, game);
	if (check_fileformat(filename, game) && check_rectangular(game)) //if fail exit + free game struct inside functs individually
		fillgrid(filename, game);
	if (check_closed(game) && check_elements(game))
	{
		flood_fill(game, game->posx_p, game->posy_p, game->parse_grid);
		if(game->c_flag == game->c && game->exit_flag == 1) //floodfill successful
			return (1);
		else
		{
			ft_printf("Error\nNo feasibe path to collectibles and exit\n");
			free_struct(game);
			exit (0);
		}
	}
	else
	{
		free_struct(game);
		exit (0);
	}
	free_struct(game);
	return (1);
}
