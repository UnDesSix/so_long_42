/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:36:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 08:48:03 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup1(const char *s1, size_t n)
{
	unsigned int	i;
	char			*s2;

	s2 = malloc(sizeof(char) * (n + 1));
	if (!s2)
		return (0);
	i = -1;
	while (++i < n)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strndup1(s, 0));
	while (s[i + start] && i < len)
		i++;
	return (ft_strndup1(s + start, i));
}
