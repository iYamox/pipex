/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:23:51 by nohubert          #+#    #+#             */
/*   Updated: 2026/01/22 15:22:50 by nohubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_env(char **envp, const char *key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

bool	has_slash(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (false);
	while (s[i])
	{
		if (s[i] == '/')
			return (true);
		i++;
	}
	return (false);
}

char	*join_path(const char *dir, const char *bin)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, bin);
	if (!path)
		return (free(tmp), NULL);
	free(tmp);
	return (path);
}

char	*check(const char *bin, char **envp)
{
	if (bin == NULL || bin[0] == '\0' || envp[0] == NULL)
		return (NULL);
	if (has_slash(bin))
	{
		if (access(bin, X_OK) == 0)
			return (ft_strdup(bin));
		else
			return (NULL);
	}
	return (NULL);
}

char	*resolve_cmd(char **envp, const char *bin)
{
	int		i;
	char	*p;
	char	*candidate;
	char	**paths;
	char	*temp;

	temp = check(bin, envp);
	if (temp)
		return (temp);
	p = get_env(envp, "PATH");
	if (!p)
		return (NULL);
	paths = ft_split(p, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		candidate = join_path(paths[i], bin);
		if (candidate && access(candidate, X_OK) == 0)
			return (free_split(paths), candidate);
		free(candidate);
	}
	return (free_split(paths), NULL);
}
