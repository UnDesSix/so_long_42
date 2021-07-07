#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	fill_final_image(char *final, char *water, int w, int h)
{
	int		i;
	int		j;

	while (i < 320 * 320 * 4)
	{
		if (i > (w * 32 + i / 320 * 4) * (h + i % 320 * 4) && i < (w ) * ())
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	water;
	char	*relative_path = "./xpm/water.xpm";
	int		img_width = 0;
	int		img_height = 0;
	int		i = 0;
	int		j = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 320, 320, "PEKOMEN");
	img.img = mlx_new_image(mlx, 320, 320);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	water.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	printf("width : %d\n", img_width);
	printf("height : %d\n", img_height);
	water.addr = mlx_get_data_addr(water.img, &water.bits_per_pixel, &water.line_length, &water.endian);

	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			fill_final_image(img.addr, water.addr, i, j);
			i++;
		}
		j++;
	}


	mlx_put_image_to_window(mlx, mlx_win, img.img, i, j);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, water.img);
	mlx_destroy_image(mlx, img.img);
	free(mlx);
	return (0);
}

