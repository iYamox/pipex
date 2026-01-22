/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:31:24 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/21 10:51:04 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(int c)
{
	ssize_t	written;

	written = write(1, &c, 1);
	if (written == -1)
		return (0);
	return (1);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
