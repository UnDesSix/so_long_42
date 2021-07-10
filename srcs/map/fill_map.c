/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:57 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/10 12:59:54 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_player_trans(char *map, char *player, int w, int h, int offset)
{
//	int		i = w * 32 * 4 + (h * 32 - 14) * WIDTH * 4;
	int		i = 0;
	int		j = 0;
	int		line_beg;
	int		line_end;

	line_beg = w * 32 * 4;
	line_end = w * 32 * 4 + 32 * 4;
	while (j < 32 * 38 * 4 && i < WIDTH * HEIGHT * 4)
	{
		if (i / HEIGHT / 4 >= h * 32 - 14 && i / HEIGHT / 4 < h * 32 + 32
				&& i % (WIDTH * 4) >= line_beg && i % (WIDTH * 4) < line_end)
		{
			if (player[j] == -1 && player[j + 1] == -1 && player[j + 2] == -1)
			{
				i += 4;
				j += 4;
			}
			else
			{
				map[i + offset * 4] = player[j++];
				i++;
			}
		}
		else
			i += 4;
	}
}

void	fill_player(char *map, char *player, int w, int h)
{
//	int		i = w * 32 * 4 + (h * 32 - 14) * WIDTH * 4;
	int		i = 0;
	int		j = 0;
	int		line_beg;
	int		line_end;

	line_beg = w * 32 * 4;
	line_end = w * 32 * 4 + 32 * 4;
	while (j < 32 * 38 * 4 && i < WIDTH * HEIGHT * 4)
	{
		if (i / HEIGHT / 4 >= h * 32 - 14 && i / HEIGHT / 4 < h * 32 + 32
				&& i % (WIDTH * 4) >= line_beg && i % (WIDTH * 4) < line_end)
		{
			if (player[j] == -1 && player[j + 1] == -1 && player[j + 2] == -1)
			{
				i += 4;
				j += 4;
			}
			else
				map[i++] = player[j++];
		}
		else
			i += 4;
	}
}

void	fill_final_image(char *final, char *water, int w, int h)
{
	int		i = w * 32 * 4 + h * WIDTH * 4 * 32;
	int		j = 0;
	int		line_beg;
	int		line_end;

	line_beg = w * 32 * 4;
	line_end = w * 32 * 4 + 32 * 4;
	while (j < 32 * 32 * 4 && i < WIDTH * HEIGHT * 4)
	{
		if (i % (WIDTH * 4) >= line_beg && i % (WIDTH * 4) < line_end
				&& i / HEIGHT / 4 >= h * 32 && i / HEIGHT / 4 < h * 32 + 32)
			final[i++] = water[j++];
		else
			i += 4;
	}
}

void	fill_map(char *map_ascii, t_map *map, t_sprite *sprt)
{
		int	i;

		i = 0;
		while (map_ascii[i] != 0 && map->map_is_valid)
		{
			if (map_ascii[i] == 'z')
				fill_final_image(sprt->img->addr, sprt->top_l->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'x')
				fill_final_image(sprt->img->addr, sprt->top_r->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'c')
				fill_final_image(sprt->img->addr, sprt->bot_l->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'v')
				fill_final_image(sprt->img->addr, sprt->bot_r->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'T')
				fill_final_image(sprt->img->addr, sprt->top->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'L')
				fill_final_image(sprt->img->addr, sprt->left->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'R')
				fill_final_image(sprt->img->addr, sprt->right->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'B')
				fill_final_image(sprt->img->addr, sprt->bot->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'C')
				fill_final_image(sprt->img->addr, sprt->collect->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'w')
				fill_final_image(sprt->img->addr, sprt->wall->addr, i % WW, i / WW);
			else if (map_ascii[i] == 'E')
				fill_final_image(sprt->img->addr, sprt->exit->addr, i % WW, i / WW);
			else
				fill_final_image(sprt->img->addr, sprt->ground->addr, i % WW, i / WW);
			i++;
		}
}
