/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:34:54 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/10 18:35:00 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_lst;
	t_list	*new_elm;

	begin_lst = 0;
	while (lst)
	{
		new_elm = ft_lstnew((*f)(lst->content));
		if (!new_elm)
		{
			ft_lstclear(&begin_lst, (*del));
			return (0);
		}
		ft_lstadd_back(&begin_lst, new_elm);
		lst = lst->next;
	}
	return (begin_lst);
}
