/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:57 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 19:37:16 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_saver	saver;

	// TODO a function to check .ber extension
	// TODO check WIDHT // WW and HEIGH // HH and if they are not mixed up
	saver->map = read_map("test.ber");
	check_map(saver->map);
	convert_map(saver->map);
	if (saver.map->map_is_valid == TRUE)
	{
		printf("Map is valid\n");
		if (init_mlx(&saver) == EXIT_FAILURE)
			printf("Init failed\n");
		if (clean_mlx(saver) == EXIT_FAILURE)
			printf("Init failed\n");
	}
	/*
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
	}*/
	free(saver->map->content);
	free(saver->map);
	return (0);
}

