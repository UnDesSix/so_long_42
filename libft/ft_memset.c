/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:35:22 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/10 18:35:24 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_bis;
	unsigned char	c_bis;

	i = 0;
	b_bis = (unsigned char *)b;
	c_bis = (unsigned char)c;
	while (i < len)
		b_bis[i++] = c_bis;
	return (b);
}
