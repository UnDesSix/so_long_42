/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:48:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 20:25:12 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map_body(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->lines_nb - 1)
	{
		if ((map->content[0 + j * map->size_first]) != '1'
			|| (map->content[map->size_first - 1 + j * map->size_first] != '1'))
			map->map_is_valid = FALSE;
		i = 0;
		while (++i < map->size_first - 1)
			if (map->content[i + j * map->size_first] != '1'
				&& map->content[i + j * map->size_first] != '0'
				&& map->content[i + j * map->size_first] != 'E'
				&& map->content[i + j * map->size_first] != 'P'
				&& map->content[i + j * map->size_first] != 'C')
				map->map_is_valid = FALSE;
	}
}

void	check_numbers(t_map *map)
{
	int	i;

	i = 0;
	while (map->content[i] != '\0')
	{
		if (map->content[i] == 'P')
			map->player_nb++;
		else if (map->content[i] == 'C')
			map->cons_nb++;
		else if (map->content[i] == 'E')
			map->exit_nb++;
		i++;
	}
	if (map->player_nb != 1 || map->cons_nb < 1 || map->exit_nb < 1)
		map->map_is_valid = FALSE;
}

void	check_map(t_map *map)
{
	int	i;

	i = 0;
	if (ft_strlen(map->content) < 15)
	{
		map->map_is_valid = FALSE;
		return ;
	}
	while (i < map->size_first)
	{
		if (map->content[i] != '1')
			map->map_is_valid = FALSE;
		i++;
	}
	check_map_body(map);
	i = (map->lines_nb - 1) * map->size_first;
	while (map->content[i] != '\0')
	{
		if (map->content[i] != '1')
			map->map_is_valid = FALSE;
		i++;
	}
	check_numbers(map);
}
