/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:16:22 by amary             #+#    #+#             */
/*   Updated: 2026/01/23 15:05:15 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_strndup(char const *s, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static void	ft_free_tab(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

static int	ft_fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[k] = ft_strndup(s, start, i);
		if (!tab[k])
			return (ft_free_tab(tab, k), 0);
		k++;
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_fill_tab(tab, s, c))
		return (NULL);
	return (tab);
}

/*
#include <stdio.h>

int	main(void)
{	
	char **dst = ft_split("---Hello-World---", '-');

	int j = 0;
	int k = 1;
	while (dst[j])
	{
		printf("%d tableau : %s \n", k, dst[j]);
		k++;
		j++;
	}
	
	return (0);
} */
