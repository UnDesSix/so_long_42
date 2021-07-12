/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:07:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 02:30:10 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_frame(t_saver *saver)
{
	draw_map(saver, saver->img.addr, saver->virgin_map);
//	draw_collect();
	draw_player(saver);
	return (0);
}


int	key_manager(int keycode, t_saver *saver)
{
	if (keycode == ARROW_RIGHT)
	{
		saver->first_frame = FALSE;
		saver->offset = 0;
		saver->curr_pos += 1;
		saver->spr_std = RIGHT;
		saver->spr_wlk1 = RIGHT_1;
		saver->spr_wlk2 = RIGHT_2;
	}
	if (keycode == ARROW_LEFT)
	{
		saver->first_frame = FALSE;
		saver->curr_pos -= 1;
		saver->offset = 0;
		saver->spr_std = LEFT;
		saver->spr_wlk1 = LEFT_1;
		saver->spr_wlk2 = LEFT_2;
	}
	if (keycode == ARROW_UP)
	{
		saver->first_frame = FALSE;
		saver->curr_pos -= saver->width_nb;
		saver->offset = 0;
		saver->spr_std = BACK;
		saver->spr_wlk1 = BACK_1;
		saver->spr_wlk2 = BACK_2;
	}
	if (keycode == ARROW_DOWN)
	{
		saver->first_frame = FALSE;
		saver->curr_pos += saver->width_nb;
		saver->offset = 0;
		saver->spr_std = FRONT;
		saver->spr_wlk1 = FRONT_1;
		saver->spr_wlk2 = FRONT_2;
	}
	return (0);
}
