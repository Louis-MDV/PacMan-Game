

#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
int main(void)
{
    void	*mlx_ptr;
    void    *mlx;

    mlx_ptr = mlx_init();
    mlx_destroy_display(mlx_ptr);
    mlx = mlx_new_window(mlx_ptr, 1920, 1080, "Hello World");
    mlx_loop(mlx);
    free(mlx_ptr);
}