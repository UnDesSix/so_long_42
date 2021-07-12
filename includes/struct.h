/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:11:45 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 17:23:02 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "define.h"
# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	*content;

	int		lines_nb;
	int		size_first;

	int		map_is_valid;
	int		player_nb;
	int		exit_nb;
	int		cons_nb;
}				t_map;

typedef struct s_saver
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;

	int		width_nb;
	int		height_nb;
	int		width;
	int		height;

	t_data	datas[SPRT_NB];
	t_data	img;

	int		curr_pos;
	int		offset;
	int		first_frame;
	int		rotate;
	int		stop;
	int		move_done;
	char	*virgin_map;
	int		spr_std;
	int		spr_wlk1;
	int		spr_wlk2;
}				t_saver;

#endif
