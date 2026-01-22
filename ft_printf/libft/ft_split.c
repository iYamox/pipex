/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:43:09 by nohubert          #+#    #+#             */
/*   Updated: 2025/05/05 10:47:20 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (c == '\0')
	{
		if (*s == '\0')
			return (0);
		return (1);
	}
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*alloc_word(const char *start, size_t len)
{
	return (ft_substr(start, 0, len));
}

static void	free_tab(char **tab, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	fill_tab(char **tab, const char *s, char c)
{
	size_t	i;
	char	*start;
	char	*end;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		end = (char *)s;
		tab[i] = alloc_word(start, end - start);
		if (tab[i] == NULL)
		{
			free_tab(tab, i);
			return (1);
		}
		i++;
	}
	tab[i] = NULL;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (fill_tab(tab, s, c))
		return (NULL);
	return (tab);
}
