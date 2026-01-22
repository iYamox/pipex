/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:48:09 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/21 10:51:22 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_string(char *s)
{
	size_t	len;
	ssize_t	written;
	char	*null_str;

	null_str = "(null)";
	len = ft_strlen(null_str);
	if (s == NULL)
	{
		write(1, null_str, len);
		return (len);
	}
	else
	{
		len = ft_strlen(s);
		written = write(1, s, len);
		return (written);
	}
}
