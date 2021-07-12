/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:57 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 19:42:31 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mouse_close_win(t_saver *saver)
{
	saver->stop = ESC;
	return (0);
}

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
	if (saver->mlx != NULL)
	{
		mlx_loop_end(saver->mlx);
		mlx_destroy_display(saver->mlx);
		free(saver->mlx);
	}
	if (saver->map->content != NULL)
		free(saver->map->content);
	if (saver->map != NULL)
		free(saver->map);
	ft_putstr_fd("ERROR : map is too big for your screen\n", 2);
	exit(EXIT_FAILURE);
}

int	init_saver(t_saver *saver)
{
	int	i;

	i = -1;
	saver->virgin_map = malloc(sizeof(char) * saver->width * saver->height * 4);
	if (saver->virgin_map == NULL)
		return (EXIT_FAILURE);
	while (++i < saver->width * saver->height * 4)
		saver->virgin_map[i] = saver->img.addr[i];
	saver->step = 0;
	saver->offset = 0;
	saver->curr_pos = 0;
	saver->stop = FALSE;
	saver->rotate = FALSE;
	saver->move_done = TRUE;
	saver->first_frame = TRUE;
	while (saver->map->content[saver->curr_pos] != 'P')
		saver->curr_pos++;
	return (EXIT_SUCCESS);
}

void	routine(t_saver *saver)
{
	mlx_loop_hook(saver->mlx, next_frame, saver);
	mlx_hook(saver->mlx_win, 2, 1L << 0, key_manager, saver);
	mlx_hook(saver->mlx_win, 33, 1L << 5, mouse_close_win, saver);
	mlx_loop(saver->mlx);
	free(saver->mlx);
}

int	main(int argc, char **argv)
{
	t_saver	saver;

	if (check_map_name(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	saver.map = read_map(argv[1]);
	if (saver.map == NULL)
		return (error_reading());
	check_map(saver.map);
	if (saver.map->map_is_valid == FALSE)
		return (error_map(&saver));
	convert_map(saver.map);
	saver.mlx = mlx_init();
	if (saver.mlx == NULL)
		return (error_mlx_init());
	check_window_size(&saver);
	if (init_mlx(&saver) == EXIT_FAILURE)
		return (error_mlx_init());
	fill_map(&saver);
	if (init_saver(&saver) == EXIT_FAILURE)
		return (error_syscall());
	routine(&saver);
	return (0);
}
