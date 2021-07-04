/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:36:26 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 08:47:44 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static size_t	ft_count_set(char const *s1, char const *set)
{
	size_t	i;
	size_t	set_nb;

	i = 0;
	set_nb = 0;
	while (s1[i] && ft_isset(set, s1[i++]))
		set_nb++;
	if (!s1[i])
		return (set_nb);
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_isset(set, s1[i--]))
		set_nb++;
	return (set_nb);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	newstr_len;

	if (!s1 || !set)
		return (0);
	newstr_len = ft_strlen(s1) - ft_count_set(s1, set) + 1;
	newstr = malloc(sizeof(char) * newstr_len);
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] && ft_isset(set, s1[i]))
		i++;
	while (j < newstr_len - 1)
		newstr[j++] = s1[i++];
	newstr[j] = '\0';
	return (newstr);
}
