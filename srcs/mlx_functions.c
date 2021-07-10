/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:07:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/10 14:16:34 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <string.h>

int		right_trans(t_saver *saver)
{
	int	j;
	int	i;

	i = 0;
	while (saver->map_ascii[i] != 'P')
		i++;
	j = 0;
	while (j < 32)
	{
		fill_player_trans(saver->saved_map, saver->front.wlk_1, i % WW, i / HH, j);
		for (int k = 0; k < WIDTH * HEIGHT * 4; k++)
			saver->img.addr[k] = saver->saved_map[k];
		mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
	//	mlx_clear_window(saver->mlx, saver->mlx_win);
		for (int k = 0; k < WIDTH * HEIGHT * 4; k++)
			;	
		j++;
	}
	return (0);
}

void	go_right(t_saver *saver)
{
	int	i;

	i = 0;
	while (saver->map_ascii[i] != 'P')
		i++;
	if (saver->map_ascii[i + 1] == '0' || saver->map_ascii[i + 1] == 'C')
	{
		saver->i = i;
		saver->map_ascii[i] = '0';
		for (int k = 0; k < WIDTH * HEIGHT * 4; k++)
			saver->img.addr[k] = saver->saved_map[k];
		fill_player(saver->img.addr, saver->front.stand, i % WW, i / HH);
		mlx_clear_window(saver->mlx, saver->mlx_win);
		mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
	}
}

/*
void	go_right(t_saver *saver)
{
	int	i;

	i = 0;
	while (saver->map_ascii[i] != 'P')
		i++;
	if (saver->map_ascii[i + 1] == '0' || saver->map_ascii[i + 1] == 'C')
	{
		saver->map_ascii[i] = '0';
		right_trans(saver, i);
		saver->map_ascii[++i] = 'P';

		fill_map(saver->map_ascii, saver->map, saver->sprt);
		fill_player(saver->img.addr, saver->front.wlk_1, i % WW, i / HH);
		mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
	}
}*/

int	key_manager(int keycode, t_saver *saver)
{
	if (keycode == ARROW_RIGHT)
		go_right(saver);
	return (0);
}
