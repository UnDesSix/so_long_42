/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:31:24 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 09:33:16 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_lista	*ft_create_elmem(int fd)
{
	t_lista	*elm;

	elm = malloc(sizeof(t_lista));
	if (!elm)
		return (NULL);
	elm->fd = fd;
	elm->flag_eof = 0;
	elm->buff_size = 0;
	elm->line_size = 0;
	elm->buff_indx = 0;
	elm->buffer = NULL;
	elm->next = NULL;
	return (elm);
}

t_lista	*ft_push_front(t_lista **begin_list, int fd)
{
	t_lista	*elm;

	if (!(*begin_list))
		(*begin_list) = ft_create_elmem(fd);
	else
	{
		elm = ft_create_elmem(fd);
		elm->next = (*begin_list);
		(*begin_list) = elm;
	}
	return (*begin_list);
}

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncat(char *dst, char *src, size_t line_offset, size_t add_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < line_offset)
		i++;
	j = 0;
	while (j < add_len)
	{
		if (src[j] == '\n')
			dst[i] = '\0';
		else
			dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_realloc_spe(char *src, size_t init_len, size_t add_len)
{
	char	*dst;
	size_t	i;

	dst = malloc(sizeof(char) * (init_len + add_len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < init_len)
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
	return (dst);
}
