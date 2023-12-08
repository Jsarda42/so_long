#include "./mlx/mlx.h"
#include "./includes/so_long.h"

int	main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1980, 1024, "Test Window");
    init_texture(mlx_ptr);
	(void)win_ptr;

	mlx_loop(mlx_ptr);

	return (0);
}
