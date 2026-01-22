/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:36 by nohubert          #+#    #+#             */
/*   Updated: 2025/06/13 09:24:43 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	handle_conv(const char *fmt, size_t *i, va_list *args)
{
	char	conv;
	int		printed;

	conv = fmt[*i + 1];
	printed = conversions(conv, args);
	*i += 2;
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		total;
	int		step;

	i = 0;
	total = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			step = handle_conv(format, &i, &args);
			total += step;
		}
		else
		{
			write(1, &format[i++], 1);
			total++;
		}
	}
	va_end(args);
	return (total);
}

/*#include <stdio.h>
int	main(void)
{
	char *str = "Hello";
	int nbr = 42;

	ft_printf("c\n");
	printf("printf : %c\n", 'A');
	ft_printf("ft_printf : %c\n\n", 'A');

	ft_printf("s\n");
	printf("printf : %s\n", str);
	ft_printf("ft_printf : %s\n\n", str);

	ft_printf("d\n");
	printf("printf : %d\n", nbr);
	ft_printf("ft_printf : %d\n\n", nbr);

	ft_printf("u\n");
	printf("printf : %u\n", (unsigned int)nbr);
	ft_printf("ft_printf : %u\n\n", (unsigned int)nbr);

	ft_printf("x et X\n");
	printf("printf : %x - %X\n", nbr, nbr);
	ft_printf("ft_printf : %x - %X\n\n", nbr, nbr);

	ft_printf("p\n");
	printf("printf : %p\n", &nbr);
	ft_printf("ft_printf : %p\n\n", &nbr);

	ft_printf("p -> NULL\n");
	printf("printf : %p\n", NULL);
	ft_printf("ft_printf : %p\n\n", NULL);

	ft_printf("%%\n");
	printf("printf : %%\n");
	ft_printf("ft_printf : %%\n\n");

	return (0);
}*/
