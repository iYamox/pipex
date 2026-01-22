/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:46:24 by nohubert          #+#    #+#             */
/*   Updated: 2025/04/30 15:25:39 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i + little_len <= len)
	{
		j = 0;
		while (j < little_len && (i + j) < len && big[i + j] == little[j])
			j++;
		if (j == little_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
