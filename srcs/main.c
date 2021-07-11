/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:57 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 18:32:24 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "string.h"
/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	ground;
	t_data	front;
	t_data	back;
	t_data	prof_left;
	t_data	prof_right;
	t_data	prof_right_wlk1;
	t_data	wall;
	t_data	water;
	t_data	collect;
	t_data	exit;
	t_data	top_l;
	t_data	top_r;
	t_data	bot_l;
	t_data	bot_r;
	t_data	top;
	t_data	bot;
	t_data	left;
	t_data	right;

	char	*ground_p = "./xpm/ground.xpm";
	char	*front_p = "./xpm/front.xpm";
	char	*back_p = "./xpm/back.xpm";
	char	*prof_left_p = "./xpm/prof_left.xpm";
	char	*prof_right_p = "./xpm/prof_right.xpm";
	char	*prof_right_wlk1_p = "./xpm/prof_right_wlk1.xpm";
	char	*collect_p = "./xpm/collectible.xpm";
	char	*wall_p = "./xpm/wall.xpm";
	char	*water_p = "./xpm/water.xpm";
	char	*exit_p = "./xpm/exit.xpm";

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
	t_map	*test;

	char	*map;
	
	t_sprite	sprt;

	test = read_map("test.ber");
	check_map(test);
	convert_map(test);
	map = test->content;

	if (test->map_is_valid == TRUE)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "PEKOMEN");
		img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);

		// GROUND, WALL, COLLECT, EXIT
		front.img = mlx_xpm_file_to_image(mlx, front_p, &img_width, &img_height);
		front.addr = mlx_get_data_addr(front.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		back.img = mlx_xpm_file_to_image(mlx, back_p, &img_width, &img_height);
		back.addr = mlx_get_data_addr(back.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		prof_left.img = mlx_xpm_file_to_image(mlx, prof_left_p, &img_width, &img_height);
		prof_left.addr = mlx_get_data_addr(prof_left.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		prof_right.img = mlx_xpm_file_to_image(mlx, prof_right_p, &img_width, &img_height);
		prof_right.addr = mlx_get_data_addr(prof_right.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		prof_right_wlk1.img = mlx_xpm_file_to_image(mlx, prof_right_wlk1_p, &img_width, &img_height);
		prof_right_wlk1.addr = mlx_get_data_addr(prof_right_wlk1.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		ground.img = mlx_xpm_file_to_image(mlx, ground_p, &img_width, &img_height);
		ground.addr = mlx_get_data_addr(ground.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		water.img = mlx_xpm_file_to_image(mlx, water_p, &img_width, &img_height);
		water.addr = mlx_get_data_addr(water.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		wall.img = mlx_xpm_file_to_image(mlx, wall_p, &img_width, &img_height);
		wall.addr = mlx_get_data_addr(wall.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		collect.img = mlx_xpm_file_to_image(mlx, collect_p, &img_width, &img_height);
		collect.addr = mlx_get_data_addr(collect.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		exit.img = mlx_xpm_file_to_image(mlx, exit_p, &img_width, &img_height);
		exit.addr = mlx_get_data_addr(exit.img, &water.bits_per_pixel, &water.line_length,
				&water.endian);

		// WATER WALL
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

		sprt.img = &img;
		sprt.ground = &ground;
		sprt.front = &front;
		sprt.back = &back;
		sprt.prof_left = &prof_left;
		sprt.prof_right = &prof_right;
		sprt.prof_right_wlk1 = &prof_right_wlk1;
		sprt.wall = &wall;
		sprt.water = &water;
		sprt.collect = &collect;
		sprt.exit = &exit;
		sprt.top_l = &top_l;
		sprt.top_r = &top_r;
		sprt.bot_l = &bot_l;
		sprt.bot_r = &bot_r;
		sprt.top = &top;
		sprt.bot = &bot;
		sprt.left = &left;
		sprt.right = &right;


		fill_map(map, test, &sprt);
		t_saver	*saver;
		
		saver = malloc(sizeof(t_saver));
		if (saver == NULL)
			return (-1);
		saver->saved_map = malloc(sizeof(char) * WIDTH * HEIGHT * 4);
		saver->mlx = mlx;
		saver->mlx_win = mlx_win;
		saver->img = img;
		saver->map = test;
		saver->map_ascii = map;
		saver->sprt = &sprt;
		saver->first_frame = TRUE;
		saver->offset = 0;

		for (int k = 0; k < WIDTH * HEIGHT * 4; k++)
			saver->saved_map[k] = img.addr[k];

		int l = 0;
		while (saver->map_ascii[l] != 'P')
			l++;
		saver->curr_pos = l;
		if (test->map_is_valid == TRUE)
		{
			mlx_loop_hook(mlx, next_frame, saver);
			mlx_hook(mlx_win, 2, 1L << 0, key_manager, saver);
			mlx_loop(mlx);
		}

		mlx_destroy_image(mlx, top_l.img);
		mlx_destroy_image(mlx, top_r.img);
		mlx_destroy_image(mlx, bot_l.img);
		mlx_destroy_image(mlx, bot_r.img);
		mlx_destroy_image(mlx, top.img);
		mlx_destroy_image(mlx, bot.img);
		mlx_destroy_image(mlx, left.img);
		mlx_destroy_image(mlx, right.img);
		mlx_destroy_image(mlx, collect.img);
		mlx_destroy_image(mlx, wall.img);
		mlx_destroy_image(mlx, exit.img);
		mlx_destroy_image(mlx, ground.img);
		mlx_destroy_image(mlx, img.img);
		free(mlx);
	}
	free(map);
	free(test);
	return (0);
}
*/
