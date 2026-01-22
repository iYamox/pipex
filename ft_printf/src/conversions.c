/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:18:28 by nohubert          #+#    #+#             */
/*   Updated: 2025/06/10 14:48:29 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	conversions(char conv, va_list *args)
{
	int	printed;

	if (conv == 'c')
		printed = print_char(va_arg(*args, int));
	else if (conv == 's')
		printed = print_string(va_arg(*args, char *));
	else if (conv == 'd' || conv == 'i')
		printed = print_signed(va_arg(*args, int));
	else if (conv == 'u')
		printed = print_unsigned(va_arg(*args, unsigned int));
	else if (conv == 'x')
		printed = print_hex(va_arg(*args, unsigned int), 0);
	else if (conv == 'X')
		printed = print_hex(va_arg(*args, unsigned int), 1);
	else if (conv == 'p')
		printed = print_pointer(va_arg(*args, void *));
	else if (conv == '%')
		printed = print_percent();
	else
		printed = 0;
	return (printed);
}
