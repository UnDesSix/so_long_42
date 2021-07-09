/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:07:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 19:29:28 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	go_right(t_saver *saver)
{
//	int	i;

//	i = 9;
//	printf("%d\n", keycode);
//	if (saver->map_ascii[++i] == '0')
	fill_player(saver->map_saved.img, saver->front.stand, 10 % 8, 10 / 8);
	printf("RIGHT\n");
	mlx_put_image_to_window(saver->mlx, saver->mlx_win, saver->map_saved.img, 0, 0);
}

int	key_manager(int keycode, t_saver *saver)
{
	if (keycode == ARROW_RIGHT)
		go_right(saver);
	return (0);
}
