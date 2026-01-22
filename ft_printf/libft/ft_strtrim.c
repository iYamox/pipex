/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:39:14 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/02 14:36:21 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (in_set(s1[start], set))
		start++;
	while (end > start && in_set(s1[end - 1], set))
		end--;
	if (start >= end)
		len = 0;
	else
		len = end - start;
	trim = malloc(len + 1);
	if (!trim)
		return (NULL);
	ft_memcpy(trim, s1 + start, len);
	trim[len] = '\0';
	return (trim);
}
