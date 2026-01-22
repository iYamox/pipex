/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:13:59 by nohubert          #+#    #+#             */
/*   Updated: 2025/06/10 14:53:28 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_signed(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	print_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	c = '0' + (n % 10);
	count += write(1, &c, 1);
	return (count);
}
