/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:12:33 by nohubert          #+#    #+#             */
/*   Updated: 2025/04/29 17:02:06 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (len > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		len--;
	}
	return (s);
}
