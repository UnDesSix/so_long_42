/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:15:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 18:39:03 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_standing(t_saver *saver)
{
	int		i;
	int		offset;

	i = saver->curr_pos;
	offset = saver->offset;
	if (offset == 0 && saver->rotate == TRUE)
	{
		fill_player_trans_2(saver, i % saver->width_nb,
			i / saver->width_nb, 0);
		mlx_put_image_to_window(saver->mlx,
			saver->mlx_win, saver->img.img, 0, 0);
	}
}

void	draw_transition(t_saver *saver)
{
	int		i;

	i = saver->curr_pos;
	if (saver->spr_std == RIGHT)
		fill_player_trans_1(saver, i % saver->width_nb - 1,
			i / saver->width_nb,  1);
	else if (saver->spr_std == LEFT)
		fill_player_trans_1(saver, i % saver->width_nb + 1,
			i / saver->width_nb, -1);
	else if (saver->spr_std == BACK)
		fill_player_trans_1(saver, i % saver->width_nb,
			i / saver->width_nb + 1, -32);
	else if (saver->spr_std == FRONT)
		fill_player_trans_1(saver, i % saver->width_nb,
			i / saver->width_nb - 1, 32);
	mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->img.img, 0, 0);
	saver->offset++;
}

void	draw_first_frame(t_saver *saver)
{
	int		i;
	int		offset;
	char	*player;

	i = saver->curr_pos;
	offset = saver->offset;
	if (offset == 0 && saver->rotate == TRUE)
	{
		player = saver->datas[saver->spr_std].addr;
		fill_player_trans_2(saver, i % saver->width_nb,
			i / saver->width_nb, 0);
		mlx_put_image_to_window(saver->mlx,
			saver->mlx_win, saver->img.img, 0, 0);
	}
	else
	{
		saver->spr_std = FRONT;
		fill_player_trans_2(saver, i % saver->width_nb, i / saver->width_nb, 0);
		mlx_put_image_to_window(saver->mlx,
			saver->mlx_win, saver->img.img, 0, 0);
	}
}

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

	i = saver->curr_pos;
	offset = saver->offset;
	if (saver->first_frame == TRUE)
		draw_first_frame(saver);
	else
	{
		player = saver->datas[saver->spr_std].addr;
		draw_standing(saver);
		if (offset >= 32)
		{
			fill_player_trans_2(saver, i % saver->width_nb,
				i / saver->width_nb, 0);
			mlx_put_image_to_window(saver->mlx, saver->mlx_win,
				saver->img.img, 0, 0);
		}
		else
			draw_transition(saver);
	}
}
