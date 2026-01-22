/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:53:35 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/05 16:17:43 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_last = ft_lstlast(*lst);
	if (lst_last->next == NULL)
	{
		lst_last->next = new;
	}
}
