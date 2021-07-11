/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:11:45 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 19:26:03 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "define.h"

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
	int		player_is_present;
	int		cons_nb;
}				t_map;


typedef struct s_saver
{
	void		*mlx;
	void		*mlx_win;

	t_data		datas[SPRT_NB];
	t_data		img;

	char		*virgin_map;
	char		*map_ascii;
	t_map		*map;

	int			curr_pos;
	int			offset;
	int			first_frame;
}				t_saver;

#endif
