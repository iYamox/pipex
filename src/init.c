/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolhan <nolhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:47:59 by nohubert          #+#    #+#             */
/*   Updated: 2025/09/26 18:46:45 by nolhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init(t_pipex *px, char **envp)
{
	px->infile = -1;
	px->outfile = -1;
	px->pipefd[0] = -1;
	px->pipefd[1] = -1;
	px->envp = envp;
	px->cmd[0].argv = NULL;
	px->cmd[0].path = NULL;
	px->cmd[1].argv = NULL;
	px->cmd[1].path = NULL;
}
