/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:36:36 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 12:41:47 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
 #include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"
# include "../libft/libft.h"

# define WIDTH	256
# define HEIGHT	256

# define FALSE	0
# define TRUE	1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	*content;
	int		lines_nb;
	int		size_first;
	int		map_is_valid;
	int		player_is_present;
}				t_map;

t_map	*read_map(char *map_file);
void	check_map(t_map *map);
void	convert_map(t_map *map);

#endif
