/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plryr_transition2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:57:59 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 18:36:16 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	increment_i_and_j_2(int *i, int *j)
{
	*i += 4;
	*j += 4;
}

int	must_write_2(t_saver *saver, int i, int w, int h)
{
	if (i / saver->width / 4 >= h * 32 - 14
			&& i / saver->width / 4 < h * 32 + 32
			&& i % (saver->width * 4) >=  w * 32 * 4
			&& i % (saver->width * 4) < w * 32 * 4 + 32 * 4)
		return (TRUE);
	return (FALSE);
}

void	fill_player_trans_2b(t_saver *saver, int *i, int *j, int type)
{
	char	*player;
	char	*map;

	map = saver->img.addr;
	player = saver->datas[saver->spr_std].addr;
	if (saver->first_frame == TRUE)
		map[*i + type * saver->offset * 4] = player[(*j)++];
	else if (saver->spr_std == RIGHT || saver->spr_std == LEFT)
		map[*i + type * saver->offset * 4] = player[(*j)++];
	else if (saver->spr_std == FRONT || saver->spr_std == BACK)
		map[*i + saver->width_nb * type * saver->offset * 4]
			= player[(*j)++];
	(*i)++;

}

void	fill_player_trans_2(t_saver *saver, int w, int h, int type)
{
	int		i;
	int		j;
	char	*map;
	char	*player;

	i = w * 32 * 4 + (h * 32 - 14) * saver->width * 4;
	j = 0;
	map = saver->img.addr;
	player = saver->datas[saver->spr_std].addr;
	while (j < 32 * 38 * 4 && i < saver->width * saver->height * 4)
	{
		if (must_write_2(saver, i, w, h) == TRUE)
		{
			if (player[j] == -1 && player[j + 1] == -1 && player[j + 2] == -1)
				increment_i_and_j_2(&i, &j);
			else
				fill_player_trans_2b(saver, &i, &j, type);
		}
		else
			i += 4;
	}
}
