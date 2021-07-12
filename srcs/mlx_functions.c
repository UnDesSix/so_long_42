/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:07:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 13:46:39 by mlarboul         ###   ########.fr       */
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
		fill_sprt_spe(saver ,GROUND, w, h);
		saver->map->content[i] = '0';
		saver->map->cons_nb--;
	}
	return (0);
}

int	key_manager(int keycode, t_saver *saver)
{
//	printf("Collect left : %d\n", saver->map->cons_nb);
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
		{
			saver->rotate = TRUE;
			saver->spr_std = RIGHT;
			if (is_wall(saver, 1) == TRUE)
				return (0);
			saver->rotate = FALSE;
			saver->move_done = FALSE;
			saver->first_frame = FALSE;
			saver->offset = 0;
			saver->curr_pos += 1;
			deal_collect(saver);
			saver->spr_std = RIGHT;
			saver->spr_wlk1 = RIGHT_1;
			saver->spr_wlk2 = RIGHT_2;
		}
		else if (keycode == ARROW_LEFT)
		{
			saver->rotate = TRUE;
			saver->spr_std = LEFT;
			if (is_wall(saver, -1) == TRUE)
				return (0);
			saver->rotate = FALSE;
			saver->move_done = FALSE;
			saver->first_frame = FALSE;
			saver->offset = 0;
			saver->curr_pos -= 1;
			deal_collect(saver);
			saver->spr_std = LEFT;
			saver->spr_wlk1 = LEFT_1;
			saver->spr_wlk2 = LEFT_2;
		}
		else if (keycode == ARROW_UP)
		{
			saver->rotate = TRUE;
			saver->spr_std = BACK;
			if (is_wall(saver, -saver->width_nb) == TRUE)
				return (0);
			saver->rotate = FALSE;
			saver->move_done = FALSE;
			saver->first_frame = FALSE;
			saver->offset = 0;
			saver->curr_pos -= saver->width_nb;
			deal_collect(saver);
			saver->spr_std = BACK;
			saver->spr_wlk1 = BACK_1;
			saver->spr_wlk2 = BACK_2;
		}
		else if (keycode == ARROW_DOWN)
		{
			saver->rotate = TRUE;
			saver->spr_std = FRONT;
			if (is_wall(saver, saver->width_nb) == TRUE)
				return (0);
			saver->rotate = FALSE;
			saver->move_done = FALSE;
			saver->first_frame = FALSE;
			saver->offset = 0;
			saver->curr_pos += saver->width_nb;
			deal_collect(saver);
			saver->spr_std = FRONT;
			saver->spr_wlk1 = FRONT_1;
			saver->spr_wlk2 = FRONT_2;
		}
	}
	return (0);
}
