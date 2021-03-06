/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:57 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 19:30:46 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_sprt_spe(t_saver *saver, int sprite, int w, int h)
{
	int	i;
	int	j;

	i = w * 32 * 4 + h * saver->width * 4 * 32;
	j = 0;
	while (j < 32 * 32 * 4 && i < saver->width * saver->height * 4)
	{
		if (i % (saver->width * 4) >= w * 32 * 4
			&& i % (saver->width * 4) < w * 32 * 4 + 32 * 4
			&& i / saver->width / 4 >= h * 32
			&& i / saver->width / 4 < h * 32 + 32)
			saver->virgin_map[i++] = saver->datas[sprite].addr[j++];
		else
			i += 4;
	}
}

void	fill_sprt(t_saver *saver, int sprite, int w, int h)
{
	int	i;
	int	j;

	i = w * 32 * 4 + h * saver->width * 4 * 32;
	j = 0;
	while (j < 32 * 32 * 4 && i < saver->width * saver->height * 4)
	{
		if (i % (saver->width * 4) >= w * 32 * 4
			&& i % (saver->width * 4) < w * 32 * 4 + 32 * 4
			&& i / saver->width / 4 >= h * 32
			&& i / saver->width / 4 < h * 32 + 32)
			saver->img.addr[i++] = saver->datas[sprite].addr[j++];
		else
			i += 4;
	}
}

void	replace_char(t_saver *saver, int i, int width, int height)
{
	if (saver->map->content[i] == 'z')
		fill_sprt(saver, TOP_L, width, height);
	else if (saver->map->content[i] == 'x')
		fill_sprt(saver, TOP_R, width, height);
	else if (saver->map->content[i] == 'c')
		fill_sprt(saver, BOT_L, width, height);
	else if (saver->map->content[i] == 'v')
		fill_sprt(saver, BOT_R, width, height);
	else if (saver->map->content[i] == 'T')
		fill_sprt(saver, TOP, width, height);
	else if (saver->map->content[i] == 'L')
		fill_sprt(saver, LEFT_L, width, height);
	else if (saver->map->content[i] == 'R')
		fill_sprt(saver, RIGHT_R, width, height);
	else if (saver->map->content[i] == 'B')
		fill_sprt(saver, BOT, width, height);
	else if (saver->map->content[i] == 'w')
		fill_sprt(saver, WALL, width, height);
	else if (saver->map->content[i] == 'E')
		fill_sprt(saver, EXIT, width, height);
	else if (saver->map->content[i] == 'C')
		fill_sprt(saver, COLLECT, width, height);
	else
		fill_sprt(saver, GROUND, width, height);
}

void	fill_map(t_saver *saver)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	while (saver->map->content[i] != 0)
	{
		width = i % (saver->width_nb);
		height = i / (saver->width_nb);
		replace_char(saver, i, width, height);
		i++;
	}
}
