/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:26:52 by amary             #+#    #+#             */
/*   Updated: 2025/11/16 11:49:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= 10)
	{
		len++;
		nb = nb / 10;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*dst;

	nb = n;
	len = ft_getlen(nb);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	while (len > 0 && dst[len - 1] != '-')
	{
		dst[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-54845));
	
	return (0);
} */
