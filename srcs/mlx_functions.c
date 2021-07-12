/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:07:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 17:34:55 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_frame(t_saver *saver)
{
	draw_map(saver, saver->img.addr, saver->virgin_map);
	draw_player(saver);
	if (saver->stop == ESC)
		clean_mlx(saver);
	else if (saver->map->content[saver->curr_pos] == 'E'
		&& saver->offset >= 32
		&& saver->map->cons_nb < 1)
		clean_mlx(saver);
	return (0);
}

int	is_wall(t_saver *saver, int direction)
{
	int	i;

	i = saver->curr_pos + direction;
	if (saver->map->content[i] != '0'
		&& saver->map->content[i] != 'C'
		&& saver->map->content[i] != 'P'
		&& saver->map->content[i] != 'E')
		return (TRUE);
	return (FALSE);
}

int	deal_collect(t_saver *saver)
{
	int	i;
	int	w;
	int	h;

	i = saver->curr_pos;
	w = i % saver->width_nb;
	h = i / saver->width_nb;
	if (saver->map->content[i] == 'C')
	{
		fill_sprt_spe(saver, GROUND, w, h);
		saver->map->content[i] = '0';
		saver->map->cons_nb--;
	}
	return (0);
}

int	key_manager(int keycode, t_saver *saver)
{
	if (keycode == ESC)
	{
		saver->stop = ESC;
		return (0);
	}
	if (saver->offset >= 32)
		saver->move_done = TRUE;
	if (saver->move_done == TRUE)
	{
		if (keycode == ARROW_RIGHT)
			move_right(saver);
		else if (keycode == ARROW_LEFT)
			move_left(saver);
		else if (keycode == ARROW_UP)
			move_up(saver);
		else if (keycode == ARROW_DOWN)
			move_down(saver);
	}
	return (0);
}
