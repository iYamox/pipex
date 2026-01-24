/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:18:57 by amary             #+#    #+#             */
/*   Updated: 2026/01/24 17:51:58 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ensure_cmd_or_die(t_cmd *cmd)
{
	if (!cmd->name)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(1);
	}
	if (!cmd->path)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(1);
	}
}

void	child_process(t_pipex *pipex)
{
	if (dup2(pipex->infile, 0) == -1)
	{
		perror("dup2, infiles error\n");
		exit(1);
	}
	if (dup2(pipex->pipefd[1], 1) == -1)
	{
		perror("dup2 pipe write\n");
		exit(1);
	}
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	ensure_cmd_or_die(&pipex->cmd[0]);
	execve(pipex->cmd[0].path, pipex->cmd[0].name, pipex->envp);
	perror(pipex->cmd[0].name[0]);
	exit(1);
}

void	child_process2(t_pipex *pipex)
{
	if (dup2(pipex->pipefd[1], 0) == -1)
	{
		perror("dup2 pipe read\n");
		exit(1);
	}
	if (dup2(pipex->outfile, 1) == -1)
	{
		perror("dup2 outfile\n");
		exit(1);
	}
	close(pipex->pipefd[1]);
	close(pipex->pipefd[0]);
	close(pipex->outfile);
	close(pipex->infile);
	ensure_cmd_or_die(&pipex->cmd[1]);
	execve(pipex->cmd[1].path, pipex->cmd[1].name, pipex->envp);
	perror(pipex->cmd[1].name[0]);
	exit(1);
}

int	ft_pipex(t_pipex *pipex)
{
	int	pid;
	int	pid2;

	if (pipe(pipex->pipefd) == -1)
		return (perror("pipe error\n"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("fork error\n"), 1);
	if (pid == 0)
		child_process(pipex);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork2 error\n"), 1);
	if (pid2 == 0)
		child_process2(pipex);
	pipex_close(&pipex->infile);
	pipex_close(&pipex->outfile);
	pipex_close(&pipex->pipefd[0]);
	pipex_close(&pipex->pipefd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid, NULL, 0);
	return (0);
}
