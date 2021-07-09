/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:33:42 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 09:33:49 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_fill_line(t_lista *elm, char **line)
{
	size_t	i;
	size_t	add_len;
	int		return_val;

	return_val = 2;
	if (elm->flag_eof && !elm->buff_size)
		return (0);
	i = elm->buff_indx;
	while (i < elm->buff_size && elm->buffer[i] != '\n')
		i++;
	if (elm->buffer[i] == '\n')
		return_val = 1;
	add_len = i - elm->buff_indx;
	*line = ft_realloc_spe(*line, elm->line_size, add_len);
	*line = ft_strncat(*line,
			elm->buffer + elm->buff_indx, elm->line_size, add_len);
	elm->line_size = elm->line_size + add_len;
	elm->buff_indx = i;
	if (elm->buffer[i] == '\n')
		elm->buff_indx = i + 1;
	if (elm->flag_eof && i == elm->buff_size)
		return_val = 0;
	return (return_val);
}

void	ft_clear_elm(t_lista **begin_list, t_lista *elm_to_del)
{
	t_lista	*elm;
	t_lista	*tmp;

	if (*begin_list == elm_to_del)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp->buffer);
		free(tmp);
		return ;
	}
	elm = (*begin_list);
	while (elm->next != elm_to_del)
		elm = elm->next;
	elm->next = elm_to_del->next;
	free(elm_to_del->buffer);
	free(elm_to_del);
}
