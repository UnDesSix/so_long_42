/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:28:05 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 17:50:11 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_down(t_saver *saver)
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
	return (0);
}

int	move_up(t_saver *saver)
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
	return (0);
}

int	move_right(t_saver *saver)
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
	return (0);
}

int	move_left(t_saver *saver)
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
	return (0);
}
