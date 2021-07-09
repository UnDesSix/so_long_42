/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:30:23 by mlarboul          #+#    #+#             */
/*   Updated: 2021/07/09 09:43:22 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

typedef unsigned int	t_size;

typedef struct s_lista
{
	int				fd;
	int				flag_eof;
	t_size			buff_size;
	t_size			line_size;
	t_size			buff_indx;
	char			*buffer;
	struct s_lista	*next;
}				t_lista;

int		get_next_line(int fd, char **line);
int		ft_read_fd(t_lista *elm, char **line);
int		ft_fill_line(t_lista *elm, char **line);
void	ft_clear_elm(t_lista **begin_list, t_lista *elm_to_del);
t_lista	*ft_create_elmem(int fd);
t_lista	*ft_push_front(t_lista **begin_list, int fd);
char	*ft_strncpy(char *dst, char *src, size_t len);
char	*ft_realloc_spe(char *src, size_t init_len, size_t add_len);
char	*ft_strncat(char *dst, char *src,
			size_t line_offset, size_t add_len);

#endif
