/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:03:55 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 16:25:51 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	*check_res(int res, t_map *map, char *line)
{
	if (res == 0)
	{
		if (line != NULL)
			free(line);
		return (map);
	}
	return (NULL);
}

t_map	*create_map(int fd, t_map *map)
{
	char	*line;
	char	*tmp;
	int		res;

	res = 1;
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		if (res != 1)
			return (check_res(res, map, line));
		tmp = ft_strjoin(map->content, line);
		if (map->content != NULL)
			free(map->content);
		map->content = tmp;
		if (map->lines_nb == 0)
			map->size_first = ft_strlen(line);
		if (map->map_is_valid == TRUE
			&& map->size_first != (int)ft_strlen(line))
			map->map_is_valid = FALSE;
		if (line != NULL)
			free(line);
		map->lines_nb++;
	}
	return (map);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->content = malloc(sizeof(char));
	if (map->content == NULL)
		return (NULL);
	map->content[0] = '\0';
	map->lines_nb = 0;
	map->map_is_valid = TRUE;
	map->player_is_present = FALSE;
	return (map);
}

t_map	*read_map(char *map_file)
{
	int		fd;
	t_map	*map;

	map = init_map();
	if (map == NULL)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = create_map(fd, map);
	if (map == NULL)
		return (NULL);
	return (map);
}
