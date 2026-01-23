/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:14:54 by amary             #+#    #+#             */
/*   Updated: 2025/11/13 12:25:44 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	dst = malloc(count * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
