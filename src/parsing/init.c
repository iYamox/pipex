/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:07:48 by amary             #+#    #+#             */
/*   Updated: 2026/01/23 15:58:30 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	init(t_pipex *pipex, char **envp, char **argv)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->envp = envp;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
	pipex->cmd[0].name = NULL;
	pipex->cmd[0].path = NULL;
	pipex->cmd[1].name = NULL;
	pipex->cmd[1].path = NULL;
	return ;
}
