/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:56:50 by amary             #+#    #+#             */
/*   Updated: 2025/11/10 19:00:17 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_is_inset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*dst;

	start = 0;
	while (s1[start] && ft_is_inset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_inset(s1[end - 1], set))
		end--;
	dst = malloc(((end - start) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dst[i] = s1[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
