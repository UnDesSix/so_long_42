/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:05:09 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 12:29:33 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	convert_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->content[++i] != '\0')
		if (map->content[i] == '1')
			map->content[i] = 'w';
	i = 0;
	while (++i < map->lines_nb - 1)
	{
		map->content[i * map->size_first] = 'L';
		map->content[i * map->size_first + map->size_first - 1] = 'R';
	}
	i = 0;
	while (++i < map->size_first - 1)
	{
		map->content[i] = 'T';
		map->content[i + map->size_first * (map->lines_nb - 1)] = 'B';
	}
	map->content[0] = 'z';
	map->content[map->size_first - 1] = 'x';
	map->content[map->size_first * (map->lines_nb - 1)] = 'c';
	map->content[map->size_first * map->lines_nb - 1] = 'v';
}
