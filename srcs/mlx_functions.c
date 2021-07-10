/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:07:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/10 18:54:17 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <string.h>

void	move(t_saver *saver, int dir, char *player)
{
	int	i;
	static int	m = 0;

	i = 0;
	while (saver->map_ascii[i] != 'P')
		i++;
	for (int k = 0; k < WIDTH * HEIGHT * 4; k++)
		saver->img.addr[k] = saver->saved_map[k];
	fill_player(saver->img.addr, player, i % WW, i / HH);
	mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
	if (saver->map_ascii[i + dir] == '0'
		|| saver->map_ascii[i + dir] == 'E'
		|| saver->map_ascii[i + dir] == 'C')
	{
		printf("%d\n", ++m);
		for (int k = 0; k < WIDTH * HEIGHT * 4; k++)
			saver->img.addr[k] = saver->saved_map[k];
		fill_player(saver->img.addr, player, (i + dir) % WW,
			(i + dir) / HH);
		mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
		if (saver->map_ascii[i + dir] == 'E' && saver->map->cons_nb > 0)
			return ;
		if (saver->map_ascii[i + dir] == 'E' && saver->map->cons_nb == 0)
		{
			printf("THIS IS THE END!\n");
			return ;
		}
		if (saver->map_ascii[i + dir] == 'C')
		{
			fill_final_image(saver->saved_map, saver->sprt->ground->addr,
				(i + dir) % WW, (i + dir) / HH);
			saver->map->cons_nb--;
		}
		saver->map_ascii[i] = '0';
		saver->map_ascii[i + dir] = 'P';
	}
}

int	key_manager(int keycode, t_saver *saver)
{

	if (keycode == ARROW_RIGHT)
		move(saver, 1, saver->sprt->prof_right->addr);
	if (keycode == ARROW_LEFT)
		move(saver, -1, saver->sprt->prof_left->addr);
	if (keycode == ARROW_UP)
		move(saver, -1 * WW, saver->sprt->back->addr);
	if (keycode == ARROW_DOWN)
		move(saver, WW, saver->sprt->front->addr);
	
	return (0);
}
