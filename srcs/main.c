/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:57 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 00:34:39 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_window_size(t_saver *saver)
{
	int	w_max;
	int	h_max;

	saver->width_nb = saver->map->size_first;
	saver->height_nb = saver->map->lines_nb;
	saver->width = saver->map->size_first * 32;
	saver->height = saver->map->lines_nb * 32;
	mlx_get_screen_size(saver->mlx, &w_max, &h_max);
	if (w_max >= saver->width && h_max >= saver->height)
		return (EXIT_SUCCESS);
	free(saver->mlx);
	if (saver->map->content != NULL)
		free(saver->map->content);
	if (saver->map != NULL)
		free(saver->map);
	return (EXIT_FAILURE);
}

int	main(void)
{
	t_saver	saver;

	// TODO a function to check .ber extension
	saver.map = read_map("test.ber");
	check_map(saver.map);
	if (saver.map->map_is_valid == TRUE)
	{
		convert_map(saver.map);
		saver.mlx = mlx_init();
		if (check_window_size(&saver) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (saver.mlx == NULL)
			printf("Init MLX failed\n");
		if (init_mlx(&saver) == EXIT_FAILURE)
			printf("Inits failed\n");
		printf("Map is valid\n");
		
		fill_map(&saver);

		saver.virgin_map = malloc(sizeof(char) * saver.width * saver.height * 4);
		if (saver.virgin_map == NULL)
			return (EXIT_FAILURE);	
		for (int k = 0; k < saver.width * saver.height * 4; k++)
			saver.virgin_map[k] = saver.img.addr[k];
		saver.first_frame = TRUE;
		saver.offset = 0;
		
		int l = 0;
		while (saver.map->content[l] != 'P')
			l++;
		saver.curr_pos = l;


		mlx_loop_hook(saver.mlx, next_frame, &saver);
		mlx_hook(saver.mlx_win, 2, 1L << 0, key_manager, &saver);
		mlx_loop(saver.mlx);
		if (clean_mlx(saver) == EXIT_FAILURE)
			printf("Init failed\n");
	}
	printf("Map is wrong\n");
	if (saver.map->content != NULL)
		free(saver.map->content);
	if (saver.map != NULL)
		free(saver.map);
	return (0);
}

