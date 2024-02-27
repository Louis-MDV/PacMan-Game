// void	my_mlx_pixel_put(t_imgs *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// void	render_img(t_image data, void *img, int x, int y)
// {
// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, data->img.width * x, data->img.height * y);
// }

// void	put_img_to_win(void *mlx, void *mlx_win, char *relative_path)
// {
// 	t_imgs	imgs;
// 	int		img_width;
// 	int		img_height;
	
// 	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

// void	put_img_to_win(void *mlx, void *mlx_win, char *relative_path)
// {
// 	t_imgs	img;
// 	int		img_width;
// 	int		img_height;
	
// 	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// }


// struct for creating an image
// typedef struct s_image
// {
// 	void 	*img; 		/*refers to the address mlx_new_image returns*/
// 	char	*addr;
// 	int 	bpp; 		/* bits per pixel */
// 	int		line_len;
// 	int		endian;
// }			t_image;