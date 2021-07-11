/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:26:47 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 19:31:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	init_xpm(t_saver *saver, char **path)
{
	int			i;
	int			info[2];

	i = 0;
	while (path[i] != NULL)
	{
		saver->datas[i].img
			= mlx_xpm_file_to_image(saver->mlx, path[i], &info[0], &info[1]);
		if (saver->datas[i].img == NULL)
			return (EXIT_FAILURE);
		saver->datas[i].addr
			= mlx_get_data_addr(saver->datas[i].img, &saver->datas[i].bpp,
				&saver->datas[i].line_length, &saver->datas[i].endian);
		if (saver->datas[i].addr == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_mlx(t_saver *saver)
{
	const char	*path[] =
		{"./xpm/ground.xpm", "./xpm/collect.xpm", "./xpm/exit.xpm",
		"./xpm/wall.xpm", "./xpm/top_l.xpm", "./xpm/top_r.xpm",
		"./xpm/bot_l.xpm", "./xpm/bot_r.xpm", "./xpm/top.xpm",
		"./xpm/bot.xpm", "./xpm/left_l.xpm", "./xpm/right_r.xpm",
		"./xpm/front.xpm", "./xpm/front_1.xpm", "./xpm/front_2.xpm",
		"./xpm/back.xpm", "./xpm/back_1.xpm", "./xpm/back_2.xpm",
		"./xpm/left.xpm", "./xpm/left_1.xpm", "./xpm/left_2.xpm",
		"./xpm/right.xpm", "./xpm/right_1.xpm", "./xpm/right_2.xpm",
		NULL};

	saver->mlx_win = mlx_new_window(saver->mlx, WIDTH, HEIGHT, "PEKOMEN");
	if (saver->mlx_win)
		return (EXIT_FAILURE);
	saver->img.img = mlx_new_image(saver->mlx, WIDTH, HEIGHT);
	if (saver->img.img)
		return (EXIT_FAILURE);
	saver->img.addr
		= mlx_get_data_addr(saver->img.img, &saver->img.bpp,
			&saver->img.line_length, &saver->img.endian);
	if (saver->img.addr)
		return (EXIT_FAILURE);
	if (init_xpm(saver, (char **)path) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		clean_mlx(t_saver saver)
{
	int	i;

	i = 0;
	while (i < SPRT_NB)
		if (mlx_destroy_image(saver.mlx, saver.datas[i++].img) != 1)
			return (EXIT_FAILURE);
	if (mlx_destroy_image(saver.mlx, saver.img) != 1)
		return (EXIT_FAILURE);
	free(saver.mlx);
	return (EXIT_SUCCESS);
}

/*
int	main(void)
{
	t_saver	saver;

	saver.mlx = mlx_init();
	init_xpm(&saver);
	printf("OK!\n");
	clean_mlx(saver);
	return (0);
}*/
