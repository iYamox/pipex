/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:04:38 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/01 16:26:32 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	out_len;
	size_t	s_len;
	char	*sub;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	out_len = s_len - start;
	if (out_len > len)
		out_len = len;
	sub = malloc(out_len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, out_len);
	sub[out_len] = '\0';
	return (sub);
}
