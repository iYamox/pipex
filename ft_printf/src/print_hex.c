/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:33:43 by nohubert          #+#    #+#             */
/*   Updated: 2025/06/10 14:45:24 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_hex(unsigned long n, int upper)
{
	char	*base;
	int		count;

	if (upper == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_hex(n / 16, upper);
	ft_putchar_fd(base[n % 16], 1);
	count++;
	return (count);
}

int	print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += print_hex((unsigned long)ptr, 0);
	return (count);
}
