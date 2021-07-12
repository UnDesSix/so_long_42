/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:36:36 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 12:56:45 by mlarboul         ###   ########.fr       */
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
# include "define.h"
# include "struct.h"
# include "../libft/libft.h"

t_map	*read_map(char *map_file);
void	check_map(t_map *map);
void	convert_map(t_map *map);

int		init_mlx(t_saver *saver);
int		clean_mlx(t_saver *saver);

int		key_manager(int keycode, t_saver *saver);

void	fill_player(char *map, char *player, int w, int h);
void	fill_player_trans(t_saver *saver, char *map, char *player, int w, int h, int offset, int type);
void	fill_sprt(t_saver *saver, int sprite, int w, int h);
void	fill_sprt_spe(t_saver *saver, int sprite, int w, int h);
void	fill_map(t_saver *saver);

int		next_frame(t_saver *saver);

void	draw_map(t_saver *saver, char *map, char *save);
void	draw_player(t_saver *saver);


#endif
