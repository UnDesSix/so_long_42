/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:36:02 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/10 18:36:04 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_tot;

	i = 0;
	j = 0;
	len_tot = ft_strlen(dst) + ft_strlen(src);
	if (!dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst[i])
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (i < dstsize)
		return (len_tot);
	else
		return (ft_strlen(src) + dstsize);
}
