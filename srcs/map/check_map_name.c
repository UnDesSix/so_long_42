/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:33:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/12 17:54:37 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_map_name(int argc, char **argv)
{
	int		len;
	char	*name;

	if (argc != 2)
	{
		ft_putstr_fd("ERROR : wrong number of argument\n", 2);
		return (EXIT_FAILURE);
	}
	name = argv[1];
	if (name[0] == '\0')
	{
		ft_putstr_fd("ERROR : wrong number of argument\n", 2);
		return (EXIT_FAILURE);
	}
	len = ft_strlen(name);
	if (name[len - 4] == '.'
		&& name[len - 3] == 'b'
		&& name[len - 2] == 'e'
		&& name[len - 1] == 'r')
		return (EXIT_SUCCESS);
	ft_putstr_fd("ERROR : wrong filename extension\n", 2);
	return (EXIT_FAILURE);
}
