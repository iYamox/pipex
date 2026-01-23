/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:17:55 by amary             #+#    #+#             */
/*   Updated: 2026/01/23 15:42:14 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*get_env(char **envp, char *key)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(key);
	while (envp[j])
	{
		if (ft_strncmp(envp[j], key, len) == 0 && envp[j][len] == '=')
			return (envp[j] + len + 1);
		j++;
	}
	return (NULL);
}

char	*join_path(char *dir, char *cmd_name)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, cmd_name);
	if (!path)
		return (free(tmp), NULL);
	return (free(tmp), path);
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

char	*check(char *cmd_name, char **envp)
{
	if (cmd_name == NULL || cmd_name[0] == '\0' || envp[0] == NULL)
		return (NULL);
	if (has_slash(cmd_name))
	{
		if (access(cmd_name, X_OK) == 0)
			return (cmd_name);
		else
			return (NULL);
	}
	return (NULL);
}

char	*find_cmd(char **envp, char **cmd_name)
{
	int		j;
	char	*env;
	char	*cmd;
	char	**paths;
	char	*tmp;

	tmp = check(cmd_name[0], envp);
	if (tmp)
		return (tmp);
	env = get_env(envp, "PATH");
	if (!env)
		return (NULL);
	paths = ft_split(env, ':');
	if (!paths)
		return (NULL);
	j = 0;
	while (paths[j])
	{
		cmd = join_path(paths[j], cmd_name[0]);
		if (cmd && access(cmd, X_OK) == 0)
			return (free_split(paths), cmd);
		free(cmd);
		j++;
	}
	return (free_split(paths), NULL);
}
