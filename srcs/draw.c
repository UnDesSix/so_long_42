/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:15:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 10:39:27 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(char *map, char *save)
{
	int	i;

	i = -1;
	while (++i < WIDTH * HEIGHT * 4)
		map[i] = save[i];
}

void	draw_player(t_saver *saver)
{
	int		i;
	int		offset;
	char	*player = saver->sprt->front->addr;
	char	*player1 = saver->sprt->prof_right_wlk1->addr;

	i = saver->curr_pos;
	offset = saver->offset;
//	printf("position (%d, %d)\n",  i % WW, i / HH);
	if (saver->first_frame == TRUE)
	{
		fill_player_trans(saver->img.addr, player, i % WW, i / HH, 0, 0);
		mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
	}
	else
	{
		if (offset >= 32)
		{
			fill_player_trans(saver->img.addr,
					player, i % WW, i / HH - 1, offset, 32);
//					player, i % WW, i / HH + 1, offset, -32);
//					player, i % WW, i / HH + 1, offset, -32);
//					player, i % WW, i / HH + 1, offset, -32);
			mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
		}
		else
		{
			fill_player_trans(saver->img.addr,
					player1, i % WW, i / HH - 1, offset, 32);
			mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
			saver->offset++;
		}
	}
}
