/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:20:22 by nohubert          #+#    #+#             */
/*   Updated: 2025/06/10 14:50:44 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

/*1. Principal functions*/
int		ft_printf(const char *format, ...);
int		conversions(char conv, va_list *args);

/*2. Print functions*/
int		print_char(int c);
int		print_percent(void);
int		print_string(char *s);
int		print_signed(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned long n, int upper);
int		print_pointer(void *ptr);

#endif
