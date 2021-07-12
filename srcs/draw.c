/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:15:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 02:19:18 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	draw_map(t_saver *saver, char *map, char *save)
{
	int	i;

	i = saver->curr_pos * 32 * 4 - saver->width * 4;
	while (i < saver->width * saver->height * 4)
	{
		if (map[i] != save[i])
			map[i] = save[i];
		i += 1;
	}
}

void	draw_player(t_saver *saver)
{
	int		i;
	int		offset;
	char	*player;
	char	*player1;

	i = saver->curr_pos;
	offset = saver->offset;
	if (saver->first_frame == TRUE)
	{
		fill_player_trans(saver, saver->img.addr,
			saver->datas[FRONT].addr, i % saver->width_nb, i / saver->width_nb, 0, 0);
		mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
	}
	else
	{
		player = saver->datas[saver->spr_std].addr;
		if (i % 2 == 0)
			player1 = saver->datas[saver->spr_wlk1].addr;
		else
			player1 = saver->datas[saver->spr_wlk2].addr;
		if (offset >= 32)
		{
			fill_player_trans(saver, saver->img.addr,
				player, i % saver->width_nb, i / saver->width_nb, offset, 0);
			mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
		}
		else
		{
			if (saver->spr_std == RIGHT)
				fill_player_trans(saver, saver->img.addr,
					player1, i % saver->width_nb - 1, i / saver->width_nb, offset, 1);
			else if (saver->spr_std == LEFT)
				fill_player_trans(saver, saver->img.addr,
					player1, i % saver->width_nb + 1, i / saver->width_nb, offset, -1);
			else if (saver->spr_std == BACK)
				fill_player_trans(saver, saver->img.addr,
					player1, i % saver->width_nb, i / saver->width_nb + 1, offset, -32);
			else if (saver->spr_std == FRONT)
				fill_player_trans(saver, saver->img.addr,
					player1, i % saver->width_nb, i / saver->width_nb - 1, offset, 32);
			mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
			saver->offset++;
		}
	}
}
