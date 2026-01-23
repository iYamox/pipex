/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:14:44 by amary             #+#    #+#             */
/*   Updated: 2026/01/22 18:44:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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
	return ;
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
	return ;
}

void	pipex_close(char *fd)
{
	if (fd && (*fd >= 0))
	{
		close(*fd);
		*fd = -1;
	}
	return ;
}

void	ft_free(t_pipex *pipex)
{
	pipex_close(&pipex->infile);
	pipex_close(&pipex->outfile);
	pipex_close(&pipex->pipefd[0]);
	pipex_close(&pipex->pipefd[1]);
	free_cmd(&pipex->cmd[0]);
	free_cmd(&pipex->cmd[1]);
	return ;
}
