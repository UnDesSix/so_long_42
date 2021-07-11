/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:26:47 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/11 18:31:17 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_xpm(t_saver *saver)
{
	int			info[2];
	const char	*path[] =
		{"./xpm/ground.xpm", "./xpm/collect.xpm", "./xpm/exit.xpm",
		"./xpm/wall.xpm", "./xpm/top_l.xpm", "./xpm/top_r.xpm",
		"./xpm/bot_l.xpm", "./xpm/bot_r.xpm", "./xpm/top.xpm",
		"./xpm/bot.xpm", "./xpm/left_l.xpm", "./xpm/right_r.xpm",
		"./xpm/front.xpm", "./xpm/front_1.xpm", "./xpm/front_2.xpm",
		"./xpm/back.xpm", "./xpm/back_1.xpm", "./xpm/back_2.xpm",
		"./xpm/left.xpm", "./xpm/left_1.xpm", "./xpm/left_2.xpm",
		"./xpm/right.xpm", "./xpm/right_1.xpm", "./xpm/right_2.xpm",
		NULL};

	i = 0;
	while (path[i] == NULL)
	{
		saver->datas[i].img
			= mlx_xpm_file_to_image(saver->mlx, path[i], &info[0], &info[1]);
		saver->datas[i].addr
			= mlx_get_data_addr(saver->datas[i].img, &saver->datas[i].bpp,
				&saver->datas[i].line_length, &saver->datas[i].endian);
		i++;
	}
}

int	main(void)
{
	t_saver saver;

	init_xpm(&saver);
	return (0);
}
