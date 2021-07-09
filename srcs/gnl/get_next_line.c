/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:30:09 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 09:30:14 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_next_line_part2(int fd, char **line, t_lista **elm,
		t_lista **begin_list)
{
	if (fd < 0 || !line || !BUFFER_SIZE || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(*begin_list))
	{
		*begin_list = ft_create_elmem(fd);
		if (!(*begin_list))
			return (-1);
	}
	*elm = *begin_list;
	while (*elm && (*elm)->fd != fd)
		*elm = (*elm)->next;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_lista	*begin_list = NULL;
	t_lista			*elm;
	int				return_val;

	elm = NULL;
	if (get_next_line_part2(fd, line, &elm, &begin_list) == -1)
		return (-1);
	if (!elm)
	{
		elm = ft_push_front(&begin_list, fd);
		if (!elm)
			return (-1);
	}
	*line = malloc(sizeof(char) + 1);
	if (!(*line))
		return (-1);
	(*line)[0] = '\0';
	elm->line_size = 0;
	return_val = ft_read_fd(elm, line);
	if (!return_val)
		ft_clear_elm(&begin_list, elm);
	return (return_val);
}

void	while_cont(t_lista *elm, char **line, int *return_val, int read_bytes)
{
	elm->buff_indx = 0;
	elm->buff_size = read_bytes;
	if (elm->buff_size < BUFFER_SIZE && elm->fd)
		elm->flag_eof = 1;
	if (!elm->buff_size && !(elm->fd))
		elm->flag_eof = 1;
	*return_val = ft_fill_line(elm, line);
}

int	ft_read_fd(t_lista *elm, char **line)
{
	char	buffer[BUFFER_SIZE];
	int		read_bytes;
	int		return_val;

	return_val = 2;
	if (elm->buff_indx < elm->buff_size)
		return_val = ft_fill_line(elm, line);
	while (return_val == 2)
	{
		if (elm->buffer)
			free(elm->buffer);
		read_bytes = read(elm->fd, buffer, BUFFER_SIZE);
		elm->buffer = malloc(sizeof(char) * (read_bytes + 1));
		if (!(elm->buffer))
			return (-1);
		elm->buffer = ft_strncpy(elm->buffer, buffer, read_bytes);
		while_cont(elm, line, &return_val, read_bytes);
	}
	return (return_val);
}
