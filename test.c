#include "mlx.h"

// gcc test.c -L. -lmlx -framework OpenGL -framework AppKit

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 250, "FdF");
	i = 0;
	while (i < 230)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0x99FFCC);
		mlx_loop(mlx_ptr);
		i++;
	}
	mlx_loop(mlx_ptr);
}
