/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:22:24 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/05 11:50:29 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_len(long nb)
{
	size_t	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*fill_str(char *s, long nb, size_t len)
{
	size_t	i;

	i = len - 1;
	s[len] = '\0';
	if (nb == 0)
		s[i] = '0';
	while (nb > 0)
	{
		s[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		sign;
	long	nb;
	size_t	len;
	char	*str;

	sign = 0;
	nb = n;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	len = nb_len(nb);
	len += sign;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	fill_str(str + sign, nb, len - sign);
	return (str);
}
