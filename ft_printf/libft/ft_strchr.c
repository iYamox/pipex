/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:35:59 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/01 15:21:45 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
void    test_strchr(const char *str, int c)
{
    printf("Standard fonction: %s, pour %d\n", strchr(str, c), c); 
    printf("Ma fonction: %s, pour %d\n\n", ft_strchr(str, c), c); 
}
int main(void)
{
    test_strchr("abcdef", 'd');
    test_strchr("", '\0');
    test_strchr("abcdef", 'g');
    test_strchr("abcdef", '\0');
    test_strchr("abcdef", 'a');
    test_strchr("abcdcef", 'c');

    return (0);
}*/
