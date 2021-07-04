/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:35:10 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/10 18:35:11 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_bis;
	size_t			i;

	s_bis = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_bis[i] == (unsigned char)c)
			return (s_bis + i);
		i++;
	}
	return (0);
}
