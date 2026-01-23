/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:13:07 by amary             #+#    #+#             */
/*   Updated: 2025/11/15 14:27:28 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first_node;

	first_node = malloc(sizeof(t_list));
	if (!first_node)
		return (NULL);
	first_node->content = content;
	first_node->next = NULL;
	return (first_node);
}
