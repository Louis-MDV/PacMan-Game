

#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
int main(void)
{
    void	*mlx_ptr;
    void    *win;
	int		keysym;

	

    mlx_ptr = mlx_init();

    // mlx_destroy_display(mlx_ptr);
    win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello World");
    mlx_loop(win);
	if (keysym == XK_Escape)
    {
        mlx_destroy_window(mlx_ptr, win);
        win = NULL;
    }
    free(mlx_ptr);
}
