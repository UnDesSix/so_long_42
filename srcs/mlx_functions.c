/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:07:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 10:30:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_frame(t_saver *saver)
{
	draw_map(saver->img.addr, saver->saved_map);
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
	}
	if (keycode == ARROW_LEFT)
	{
		saver->first_frame = FALSE;
		saver->curr_pos -= 1;
		saver->offset = 0;
	}
	if (keycode == ARROW_UP)
	{
		saver->first_frame = FALSE;
		saver->curr_pos -= WW;
		saver->offset = 0;
	}
	if (keycode == ARROW_DOWN)
	{
		saver->first_frame = FALSE;
		saver->curr_pos += WW;
		saver->offset = 0;
	}
	return (0);
}
