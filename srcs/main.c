#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH	256
#define HEIGHT	256


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	fill_final_image(char *final, char *water, int w, int h)
{
	int		i = w * 32 * 4 + h * WIDTH * 4;
	int		j = 0;
	int		line_beg;
	int		line_end;

	line_beg = w * 32 * 4;
	line_end = w * 32 * 4 + 32 * 4;
	while (j < 32 * 32 * 4 && i < WIDTH * HEIGHT * 4)
	{
		if (i % (WIDTH * 4) >= line_beg && i % (WIDTH * 4) < line_end
				&& i / HEIGHT / 4 >= h * 32 && i / HEIGHT / 4 < h * 32 + 32)
			final[i++] = water[j++];
		else
			i += 4;
	}
}

int	main(void)
{
	char 	map[] = "2333333450000007500000075000000750000007500000075000000769999998";
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	water;
	t_data	ground;

	t_data	top_l;
	t_data	top_r;
	t_data	bot_l;
	t_data	bot_r;
	t_data	top;
	t_data	bot;
	t_data	left;
	t_data	right;
	
	char	*ground_p = "./xpm/ground.xpm";
	char	*water_p = "./xpm/water.xpm";
	char	*top_l_p = "./xpm/top_left.xpm";
	char	*top_r_p = "./xpm/top_right.xpm";
	char	*bot_l_p = "./xpm/bot_left.xpm";
	char	*bot_r_p = "./xpm/bot_right.xpm";
	char	*top_p = "./xpm/top.xpm";
	char	*bot_p = "./xpm/bot.xpm";
	char	*left_p = "./xpm/left.xpm";
	char	*right_p = "./xpm/right.xpm";
	int		img_width = 0;
	int		img_height = 0;
	int		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "PEKOMEN");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	water.img = mlx_xpm_file_to_image(mlx, water_p, &img_width, &img_height);
	water.addr = mlx_get_data_addr(water.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	ground.img = mlx_xpm_file_to_image(mlx, ground_p, &img_width, &img_height);
	ground.addr = mlx_get_data_addr(ground.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	top_l.img = mlx_xpm_file_to_image(mlx, top_l_p, &img_width, &img_height);
	top_l.addr = mlx_get_data_addr(top_l.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	top_r.img = mlx_xpm_file_to_image(mlx, top_r_p, &img_width, &img_height);
	top_r.addr = mlx_get_data_addr(top_r.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	bot_l.img = mlx_xpm_file_to_image(mlx, bot_l_p, &img_width, &img_height);
	bot_l.addr = mlx_get_data_addr(bot_l.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	bot_r.img = mlx_xpm_file_to_image(mlx, bot_r_p, &img_width, &img_height);
	bot_r.addr = mlx_get_data_addr(bot_r.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	top.img = mlx_xpm_file_to_image(mlx, top_p, &img_width, &img_height);
	top.addr = mlx_get_data_addr(top.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	bot.img = mlx_xpm_file_to_image(mlx, bot_p, &img_width, &img_height);
	bot.addr = mlx_get_data_addr(bot.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	left.img = mlx_xpm_file_to_image(mlx, left_p, &img_width, &img_height);
	left.addr = mlx_get_data_addr(left.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);

	right.img = mlx_xpm_file_to_image(mlx, right_p, &img_width, &img_height);
	right.addr = mlx_get_data_addr(right.img, &water.bits_per_pixel, &water.line_length,
								&water.endian);
	
	i = 0;
	while (map[i] != 0)
	{
		if (map[i] == '2')
			fill_final_image(img.addr, top_l.addr, i % 8, i / 8);
		else if (map[i] == '4')
			fill_final_image(img.addr, top_r.addr, i % 8, i / 8);
		else if (map[i] == '6')
			fill_final_image(img.addr, bot_l.addr, i % 8, i / 8);
		else if (map[i] == '8')
			fill_final_image(img.addr, bot_r.addr, i % 8, i / 8);
		else if (map[i] == '3')
			fill_final_image(img.addr, top.addr, i % 8, i / 8);
		else if (map[i] == '5')
			fill_final_image(img.addr, left.addr, i % 8, i / 8);
		else if (map[i] == '7')
			fill_final_image(img.addr, right.addr, i % 8, i / 8);
		else if (map[i] == '9')
			fill_final_image(img.addr, bot.addr, i % 8, i / 8);
		else
			fill_final_image(img.addr, ground.addr, i % 8, i / 8);
		i++;
	}

/*
	fill_final_image(img.addr, water.addr, 0, 0);
	fill_final_image(img.addr, water.addr, 1, 0);
	fill_final_image(img.addr, water.addr, 2, 0);
	fill_final_image(img.addr, water.addr, 3, 0);
	fill_final_image(img.addr, water.addr, 4, 0);
	fill_final_image(img.addr, water.addr, 5, 0);
	fill_final_image(img.addr, water.addr, 6, 0);
	fill_final_image(img.addr, water.addr, 7, 0);
	fill_final_image(img.addr, water.addr, 8, 0);
	fill_final_image(img.addr, water.addr, 9, 0);
	fill_final_image(img.addr, water.addr, 0, 1);
*/
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, water.img);
	mlx_destroy_image(mlx, img.img);
	free(mlx);
	return (0);
}

