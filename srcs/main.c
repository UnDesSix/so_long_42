#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*relative_path = "./xpm/water.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "POKOMEN");
	img.img = mlx_new_image(mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 32, 32);
	mlx_loop(mlx);
	return (0);
}

