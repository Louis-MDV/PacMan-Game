/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:55:57 by lmerveil          #+#    #+#             */
/*   Updated: 2024/03/06 11:49:44 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//renders map. opens exit. shows player according to arrow stroke
int		render_map(t_data *data)
{	
	int	y;
	int	x;
	srand(time(NULL));
	
	if (data->render_one == 0)
	{
		render_first_frame(data);
		data->render_one = 1;
		return (0);
	}
	if (data->keypress_flag == UP || data->keypress_flag == LEFT || data->keypress_flag == ZERO)
	{
		if (data->keypress_flag != ZERO)
			data->game_started = 1;
		y = render_order_y(*data);
		while (++y < data->height)
		{
			x = render_order_x(*data);
			while (data->grid[y][x] != '\n')
			{
				if (data->grid[y][x] == '1')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_wall, data->img.width * x, data->img.height * y);
				if (data->grid[y][x] == '0')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_path, data->img.width * x, data->img.height * y);
				if (data->grid[y][x] == 'C')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_collect, data->img.width * x, data->img.height * y);
				if (data->grid[y][x] == 'E' && data->c_collected < data->c_count)
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_wall, data->img.width * x, data->img.height * y);		
				else if (data->grid[y][x] == 'E' && data->c_collected == data->c_count)
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_exit, data->img.width * x, data->img.height * y);
				if (x == data->posx_p && y == data->posy_p)
					render_player(data);
				x++;
			}
		}
	}
	else if (data->keypress_flag == DOWN || data->keypress_flag == RIGHT)
	{
		data->game_started = 1;
		y = render_order_y(*data) - 1;
		while (y >= 0)
		{
			x = render_order_x(*data);
			while (data->grid[y][x])
			{
				if (data->grid[y][x] == '1')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_wall, data->img.width * x, data->img.height * y);
				if (data->grid[y][x] == '0')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_path, data->img.width * x, data->img.height * y);
				if (data->grid[y][x] == 'C')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_collect, data->img.width * x, data->img.height * y);
				if (data->grid[y][x] == 'E' && data->c_collected < data->c_count)
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_wall, data->img.width * x, data->img.height * y);
				else if (data->grid[y][x] == 'E' && data->c_collected == data->c_count)
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_exit, data->img.width * x, data->img.height * y);
				if (x == data->posx_p && y == data->posy_p)
					render_player(data);
				x--;
			}
			y--;
		}

	}
	if (data->game_started == 1)
		render_enemy(data);
	display_keypress_num(data);
	return (0);
}
int	render_first_frame(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->height)
	{
		x = 0;
		while (data->grid[y][x] != '\n')
		{
			if (data->grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_wall, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_path, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_collect, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'E' && data->c_collected < data->c_count)
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_wall, data->img.width * x, data->img.height * y);
			else if (data->grid[y][x] == 'E' && data->c_collected == data->c_count)
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_exit, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'Y')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_enemy_yellow, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'B')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_enemy_blue, data->img.width * x, data->img.height * y);
			if (data->grid[y][x] == 'R')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_enemy_red, data->img.width * x, data->img.height * y);		
			if (data->grid[y][x] == 'K')
					mlx_put_image_to_window(data->mlx, data->win, data->img.img_enemy_pink, data->img.width * x, data->img.height * y);		
			if (x == data->posx_p && y == data->posy_p)
				render_player(data);
			x++;
		}
	}
	display_keypress_num(data);
	return(0);
}

int	render_order_x(t_data	data)
{
	if (data.keypress_flag == DOWN || data.keypress_flag == RIGHT)
		return (data.width);
	else if (data.keypress_flag == UP || data.keypress_flag == LEFT)
		return (0);
	return (0);
}

int	render_order_y(t_data	data)
{
	if (data.keypress_flag == DOWN || data.keypress_flag == RIGHT)
		return (data.height);
	else if (data.keypress_flag == UP || data.keypress_flag == LEFT)
		return (-1);
	return (0);
}

void	display_keypress_num(t_data	*data)
{
	char *str;
 	str = ft_itoa(data->keypress_num);
	mlx_string_put(data->mlx, data->win, data->width * data->img.width - (data->img.width *2.55), 28, -1, str);
	free(str);
}
int		handle_keypress(int keysym, t_data *data)
{
	if (data->keypress_flag != ZERO)
	{
		data->mov_queue = keysym;
		data->keypress_num++;
	}
	else if (handle_up(keysym, data) || handle_down(keysym, data) || handle_left(keysym, data) || handle_right(keysym, data))
	{
		data->d_wall = distance_to_wall(keysym, *data) * 50;  	//frames to render till wall
		repix_mov(data); 										//reinitiating pix_mov to 50 frames
		data->keypress_num++;
	}
	// updateEnemyPosition(data);
	handle_esc_all_collected(keysym, data);
	return (0);
}

int		check_mov_queue(int keysym, t_data data)
{
	if (check_up(keysym, data) || check_down(keysym, data) || check_left(keysym, data) || check_right(keysym, data))
		return (1);
	return (0);
}

void	handle_esc_all_collected(int keysym, t_data *data)
{
	if (keysym == XK_Escape  || (data->c_collected == data->c_count && data->grid[data->posy_p][data->posx_p] == 'E'))
	{
		ft_printf(RED"GAME OVER!\n"RESET);
		free_img_data(data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_struct(data);
	}
}

int	check_up(int keysym , t_data data)
{
	if (keysym != UP)
		return (0);
	else if (data.grid[data.posy_p - 1][data.posx_p] == '1')
		return (ft_printf(ORANGE"Can't move up! There's a wall...\n"RESET), 0);
	else if (data.grid[data.posy_p - 1][data.posx_p] == 'E' && data.c_collected != data.c_count)
		return (ft_printf(ORANGE"Can't move up! Collect remaining collectibles to exit...\n"RESET), 0);
	else
		return (1);
}

int	check_down(int keysym , t_data data)
{
	if (keysym != DOWN)
		return (0);
	else if (data.grid[data.posy_p + 1][data.posx_p] == '1')
		return (ft_printf(ORANGE"Can't move down! There's a wall...\n"RESET), 0);
	else if (data.grid[data.posy_p + 1][data.posx_p] == 'E' && data.c_collected != data.c_count)
		return(ft_printf(ORANGE"Can't move d! Collect remaining collectibles to exit...\n"RESET), 0);
	else
		return (1);
}

int	check_right(int keysym , t_data data)
{
	if (keysym != RIGHT)
		return (0);
	else if (data.grid[data.posy_p][data.posx_p + 1] == '1')
		return (ft_printf(ORANGE"Can't move up! There's a wall...\n"RESET), 0);
	else if (data.grid[data.posy_p][data.posx_p + 1] == 'E' && data.c_collected != data.c_count)
		return (ft_printf(ORANGE"Can't move up! Collect remaining collectibles to exit...\n"RESET), 0);
	else
		return (1);
}

int	check_left(int keysym , t_data data)
{
	if (keysym != LEFT)
		return (0);
	else if (data.grid[data.posy_p][data.posx_p - 1] == '1')
		return (ft_printf(ORANGE"Can't move up! There's a wall...\n"RESET), 0);
	else if (data.grid[data.posy_p][data.posx_p - 1] == 'E' && keysym == LEFT && data.c_collected != data.c_count)
		return (ft_printf(ORANGE"Can't move up! Collect remaining collectibles to exit...\n"RESET), 0);
	else
		return (1);
}

int		handle_up(int keysym, t_data *data)
{
	if (!check_up(keysym, *data))
		return (0);
	else if (keysym == UP)
	{
		data->keypress_flag = UP;
		data->img.current_img = data->img.img_player_up;
		return (1);
	}
	return(0);
}

int		handle_down(int keysym, t_data *data)
{
	if (!check_down(keysym, *data))
		return (0);
	else if (keysym == DOWN)
    {
		data->keypress_flag = DOWN;
		data->img.current_img = data->img.img_player_down;
		return (1);
    }
	return(0);
}

int		handle_right(int keysym, t_data *data)
{
	if (!check_right(keysym, *data))
		return (0);
	else if (keysym == RIGHT)
	{
		data->keypress_flag = RIGHT;
		data->img.current_img = data->img.img_player_right;
		return (1);
	}
	return (0);
}

int		handle_left(int keysym, t_data *data)
{
	if (!check_left(keysym, *data))
		return (0);
	else if (keysym == LEFT)
	{
		data->keypress_flag = LEFT;
		data->img.current_img = data->img.img_player_left;
		return (1);
	}
	return (0);
}

 //using a copy of data
int	distance_to_wall(int keysym, t_data data)
{
	int	d_wall;

	d_wall = -1;
	while ((data.grid[data.posy_p][data.posx_p] != '1' && data.grid[data.posy_p][data.posx_p] != 'E' && (data.c_collected != data.c_count)) || data.grid[data.posy_p][data.posx_p] != '1') //if current pos != C then go to next pos and increment dwall
	{
		if (keysym == UP)
			data.posy_p--;
		else if (keysym == DOWN)
			data.posy_p++;
		else if (keysym == RIGHT)
			data.posx_p++;
		else if (keysym == LEFT)
			data.posx_p--;
		d_wall++;
	}
	return (d_wall);
}

 //adjusts the grid ber pos every 50 maps frames rendered
void	adjust_ber_pos(t_data *data)
{
	if (data->keypress_flag == UP)
		data->posy_p--;
	else if (data->keypress_flag == DOWN)
		data->posy_p++;
	else if (data->keypress_flag == RIGHT)
		data->posx_p++;
	else if (data->keypress_flag == LEFT)
		data->posx_p--;
	data->pix_mov = 50;
}


void	repix_mov(t_data *data)
{
	data->pix_mov = 50;
}

void	*define_current_img(t_data data)
{
	void *current_img;
	
	if (data.pix_mov % 2 == 0)
		current_img = data.img.img_player_closed;
	else
	{
		if (data.keypress_flag == UP)
			current_img = data.img.img_player_up;
		else if (data.keypress_flag == DOWN)
			current_img = data.img.img_player_down;
		else if (data.keypress_flag == RIGHT)
			current_img = data.img.img_player_right;
		else if (data.keypress_flag == LEFT)
			current_img = data.img.img_player_left;
	}
	return (current_img);
}

void	render_player(t_data *data)
{
	// updateEnemyPosition(data);
	if (data->grid[data->posy_p][data->posx_p] == 'C' && data->c_collected < data->c_count)
	{
		data->c_collected++;
		data->grid[data->posy_p][data->posx_p] = '0';
		ft_printf(GREEN"+1 collectible!\n"RESET);
	}
	if (data->img.current_img != NULL && data->d_wall > 0 && data->keypress_flag != ZERO) //KeyPress state
	{
		if (data->keypress_flag == UP)
			data->pos.map_y--;
		else if (data->keypress_flag == DOWN)
			data->pos.map_y++;		
		else if (data->keypress_flag == RIGHT)
			data->pos.map_x++;
		else if (data->keypress_flag == LEFT)
			data->pos.map_x--;
		data->img.current_img = define_current_img(*data); //define current image according to keypress_flag
		mlx_put_image_to_window(data->mlx, data->win, data->img.current_img, data->pos.map_x, data->pos.map_y);
		data->d_wall--;
		data->pix_mov--;
		if (data->pix_mov == 0)
		{	
			adjust_ber_pos(data);
			if(data->mov_queue != ZERO && check_mov_queue(data->mov_queue, *data))
			{
				//check if new direction change possible
				//if possible change direction
				//if not possible wait till possible -> store new move dir in mov_queue and continue execution of current dir mov
				
				data->keypress_flag = data->mov_queue;
				data->mov_queue = ZERO;
				data->d_wall = distance_to_wall(data->keypress_flag, *data) * 50;
			}
		}
		usleep(1500);
		handle_esc_all_collected(data->keypress_flag, data);
	}
	else //idle state
		mlx_put_image_to_window(data->mlx, data->win, data->img.current_img, data->pos.map_x, data->pos.map_y);
	if (data->d_wall == 0) //if mouvement to wall finished, set keypressflag to zero
		data->keypress_flag = ZERO;
}

void	render_enemy(t_data *data)
{
	int i;
	i = 0;
	while (i < data->enemy_count)
	{
		if (data->tab_enemy[i].d_wall == 0) //if its the first render or if ghost next to wall and ended patrol set new dir
			get_random_dir_distance_to_wall(i, data);
		if (data->tab_enemy[i].dir == U)
			data->tab_enemy[i].map_y--;
		else if (data->tab_enemy[i].dir == D)
			data->tab_enemy[i].map_y++;
		else if (data->tab_enemy[i].dir == L)
			data->tab_enemy[i].map_x--;
		else if (data->tab_enemy[i].dir == R)
			data->tab_enemy[i].map_x++;
		// printf("x: %d, y: %d, dir: %d, d_wall: %d, color_flag: %d\n", data->tab_enemy[i].x, data->tab_enemy[i].y, data->tab_enemy[i].dir, data->tab_enemy[i].d_wall, data->tab_enemy[i].color_flag);
		mlx_put_image_to_window(data->mlx, data->win, data->tab_enemy[i].img_enemy, data->tab_enemy[i].map_x, data->tab_enemy[i].map_y);
		data->tab_enemy[i].d_wall--;
		data->tab_enemy[i].pix_mov--;
		
		if (data->tab_enemy[i].pix_mov == 0) // Check if it's time to update the position on the grid
			adjust_ber_pos_enemy(i, data);
		
		if (data->tab_enemy[i].x == data->posx_p && data->tab_enemy[i].y == data->posy_p)
		{
			ft_printf(RED"GAME OVER!\n"RESET);
			free_img_data(data);
			mlx_destroy_window(data->mlx, data->win);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			free_struct(data);
		}
		i++;
	}
	usleep(2300);
}

// fixes a dir which enables a positive d_wall
void	get_random_dir_distance_to_wall(int i, t_data *data)
{	
	int d_wall;
	// if (data->tab_enemy[i].dir == 0)
	// {
	// 	data->tab_enemy[i].dir = getRandomDirection();
	// 	data->tab_enemy[i].third_dir = data->tab_enemy[i].dir;
	// }
	// data->tab_enemy[i].third_dir = getRandomDirection();
	// while (data->tab_enemy[i].dir_counter % 3 == 0 && data->tab_enemy[i].dir == data->tab_enemy[i].third_dir)
	data->tab_enemy[i].dir = getRandomDirection();
		
	d_wall  = distance_to_wall_ghost(i, *data);
	// printf("dir: %d, d_wall: %d\n", data->tab_enemy[i].dir, d_wall);

	while (d_wall <= 0)
	{	
		data->tab_enemy[i].dir = getRandomDirection();
		d_wall  = distance_to_wall_ghost(i, *data);
	}
	data->tab_enemy[i].d_wall = d_wall;
}

//merci CHAT GPT
// Function to generate a random direction between 1 and 4 U, D, L , R
int getRandomDirection()
{
    return (rand() % 4 + 1);
}

int distance_to_wall_ghost(int i, t_data data)
{
    int d_wall = -1;
    int temp_x = data.tab_enemy[i].x;
    int temp_y = data.tab_enemy[i].y;

	// printf("x: %d, y: %d", data.tab_enemy[i].x, data.tab_enemy[i].y);
    while (data.grid[temp_y][temp_x] != '1' && data.grid[temp_y][temp_x] != 'E')
    {
        if (data.tab_enemy[i].dir == U)
            temp_y--;
        else if (data.tab_enemy[i].dir == D)
            temp_y++;
        else if (data.tab_enemy[i].dir == R)
            temp_x++;
        else if (data.tab_enemy[i].dir == L)
            temp_x--;
        d_wall++;
    }
    return (d_wall * 50);
}

//  adjusts the grid ber pos every 50 maps frames rendered
void	adjust_ber_pos_enemy(int i, t_data *data)
{
	if (data->tab_enemy[i].dir == U)
		data->tab_enemy[i].y--;
	else if (data->tab_enemy[i].dir == D)
		data->tab_enemy[i].y++;
	else if (data->tab_enemy[i].dir == L)
		data->tab_enemy[i].x--;
	else if (data->tab_enemy[i].dir == R)
		data->tab_enemy[i].x++;
	data->tab_enemy[i].pix_mov = 50;

}