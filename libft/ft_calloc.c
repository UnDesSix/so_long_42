/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:31:56 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/10 18:31:58 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	tot;

	tot = count * size;
	ptr = malloc(sizeof(void) * tot);
	if (!ptr)
		return (0);
	ft_bzero(ptr, tot);
	return (ptr);
}
