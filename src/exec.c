/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:42:07 by nohubert          #+#    #+#             */
/*   Updated: 2026/01/22 15:29:27 by nohubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ensure_cmd_or_die(t_cmd *c)
{
	if (!c->argv || !c->argv[0])
	{
		ft_putstr_fd("command not found\n", 2);
		exit(1);
	}
	if (!c->path)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(1);
	}
}

static void	child_exec1(t_pipex *px)
{
	if (dup2(px->infile, 0) == -1)
	{
		perror("dup2 infile\n");
		exit(1);
	}
	if (dup2(px->pipefd[PX_WR], 1) == -1)
	{
		perror("dup2 pipe write\n");
		exit(1);
	}
	close(px->pipefd[PX_RD]);
	close(px->pipefd[PX_WR]);
	close(px->infile);
	close(px->outfile);
	ensure_cmd_or_die(&px->cmd[0]);
	execve(px->cmd[0].path, px->cmd[0].argv, px->envp);
	perror(px->cmd[0].argv[0]);
	exit(1);
}

static void	child_exec2(t_pipex *px)
{
	if (dup2(px->pipefd[PX_RD], 0) == -1)
	{
		perror("dup2 pipe read\n");
		exit(1);
	}
	if (dup2(px->outfile, 1) == -1)
	{
		perror("dup2 outfile\n");
		exit(1);
	}
	close(px->pipefd[PX_WR]);
	close(px->pipefd[PX_RD]);
	close(px->outfile);
	close(px->infile);
	ensure_cmd_or_die(&px->cmd[1]);
	execve(px->cmd[1].path, px->cmd[1].argv, px->envp);
	perror(px->cmd[1].argv[0]);
	exit(1);
}

int	run_pipeline(t_pipex *px)
{
	int	pid1;
	int	pid2;
	int	st1;
	int	st2;

	if (pipe(px->pipefd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		child_exec1(px);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		child_exec2(px);
	px_close(&px->infile);
	px_close(&px->outfile);
	px_close(&px->pipefd[PX_RD]);
	px_close(&px->pipefd[PX_WR]);
	waitpid(pid1, &st1, 0);
	waitpid(pid2, &st2, 0);
	return (0);
}
