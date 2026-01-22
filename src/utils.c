/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:16:44 by nohubert          #+#    #+#             */
/*   Updated: 2025/09/25 14:40:41 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_split(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd->argv)
	{
		free_split(cmd->argv);
		cmd->argv = NULL;
	}
	if (cmd->path)
	{
		free(cmd->path);
		cmd->path = NULL;
	}
}

void	px_close(int *fd)
{
	if (fd && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}
