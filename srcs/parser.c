/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:50:46 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 10:24:11 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*create_map(int fd, char *map)
{
	char	*line;
	char	*tmp;
	int		res;

	res = 1;
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			return (NULL);
		tmp = ft_strjoin(map, line);
		if (map != NULL)
			free(map);
		if (line != NULL)
			free(line);
		map = tmp;
	}
	return (map);
}

int		read_map(char *map_file)
{
	int		fd;
	char	*map;

	map = malloc(sizeof(char));
	if (map == NULL)
		return (-1);
	map[0] = '\0';
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	map = create_map(fd, map);
	if (map == NULL)
		return (-1);
	printf("%s\n", map);
	free(map);
	return (0);
}
