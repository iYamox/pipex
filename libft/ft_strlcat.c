/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:19:21 by amary             #+#    #+#             */
/*   Updated: 2025/11/08 13:24:50 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_length;
	size_t	d_length;

	i = 0;
	s_length = ft_strlen(src);
	d_length = ft_strlen(dst);
	if (size <= d_length)
		return (size + s_length);
	while (src[i] && (d_length + i) < size - 1)
	{
		dst[d_length + i] = src[i];
		i++;
	}
	if (d_length + i < size)
		dst[d_length + i] = '\0';
	return (d_length + s_length);
}
