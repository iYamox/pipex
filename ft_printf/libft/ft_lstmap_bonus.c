/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:17:48 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/05 19:37:27 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstmap_newnode(void *content_orig,
								void *(*f)(void *),
								void (*del)(void *))
{
	t_list	*node;
	void	*tmp;

	tmp = f(content_orig);
	node = ft_lstnew(tmp);
	if (!node)
	{
		if (del)
			del(tmp);
		return (NULL);
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	t_list	*tail;

	if (!lst || !f)
		return (NULL);
	result = lstmap_newnode(lst->content, f, del);
	if (!result)
		return (NULL);
	tail = result;
	lst = lst->next;
	while (lst)
	{
		node = lstmap_newnode(lst->content, f, del);
		if (!node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		tail->next = node;
		tail = node;
		lst = lst->next;
	}
	return (result);
}
