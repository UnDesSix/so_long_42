/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:36:36 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/10 14:09:27 by mlarboul         ###   ########.fr       */
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

# define WW		20
# define HH		20

# define WIDTH	(WW * 32)
# define HEIGHT	(HH * 32)


//# define ARROW_LEFT		65361
# define ARROW_LEFT		97
//# define ARROW_RIGHT	65363
# define ARROW_RIGHT	100
//# define ARROW_UP		65362
# define ARROW_UP		119
//# define ARROW_DOWN		65364
# define ARROW_DOWN		115
# define esc		65307

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

typedef struct s_player
{
	char	*stand;
	char	*wlk_1;
	char	*wlk_2;
}				t_player;

typedef struct s_sprite
{
	t_data	*img;
	t_data	*ground;
	t_data	*player;
	t_data	*wall;
	t_data	*water;
	t_data	*collect;
	t_data	*exit;

	t_data	*top_l;
	t_data	*top_r;
	t_data	*bot_l;
	t_data	*bot_r;

	t_data	*top;
	t_data	*bot;
	t_data	*left;
	t_data	*right;
}				t_sprite;

typedef struct s_saver
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	char		*saved_map;
	char		*map_ascii;
	t_map		*map;
	t_sprite	*sprt;

	int		i;

	char		*ground;
	t_player	front;
	t_player	back;
	t_player	left;
	t_player	right;
}				t_saver;


t_map	*read_map(char *map_file);
void	check_map(t_map *map);
void	convert_map(t_map *map);

int		key_manager(int keycode, t_saver *saver);

void	fill_player(char *map, char *player, int w, int h);
void	fill_player_trans(char *map, char *player, int w, int h, int offset);
void	fill_final_image(char *map, char *player, int w, int h);
void	fill_map(char *map_ascii, t_map *map, t_sprite *sprt);

int		right_trans(t_saver *saver);

#endif
