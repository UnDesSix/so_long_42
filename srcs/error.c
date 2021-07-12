/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:31:33 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 19:25:58 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_screen_size(void)
{
	ft_putstr_fd("ERROR : map is too big for your screen\n", 2);
	return (EXIT_FAILURE);
}

int	error_syscall(void)
{
	ft_putstr_fd("ERROR : a syscall function returns an error\n", 2);
	return (EXIT_FAILURE);
}

int	error_reading(void)
{
	ft_putstr_fd("ERROR : something went wrong while reading.\n", 2);
	return (EXIT_FAILURE);
}

int	error_mlx_init(void)
{
	ft_putstr_fd("ERROR : a mlx function returns an error\n", 2);
	return (EXIT_FAILURE);
}

int	error_map(t_saver *saver)
{
	ft_putstr_fd("ERROR : map is wrong\n", 2);
	ft_putstr_fd("Make sure that there is '\\n' at the end of each line.\n", 2);
	ft_putstr_fd("Spaces and tabs are not supported.\n", 2);
	ft_putstr_fd("The map must be a perfect rectangle.\n", 2);
	ft_putstr_fd("Here are the accepted ASCII : '1', '0', 'E', 'P', 'C'.\n", 2);
	if (saver->map->content != NULL)
		free(saver->map->content);
	if (saver->map != NULL)
		free(saver->map);
	return (EXIT_FAILURE);
}
