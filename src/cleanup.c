/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:20:39 by nohubert          #+#    #+#             */
/*   Updated: 2025/09/25 13:54:06 by nohubert         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	cleanup(t_pipex *px)
{
	px_close(&px->infile);
	px_close(&px->outfile);
	px_close(&px->pipefd[0]);
	px_close(&px->pipefd[1]);
	free_cmd(&px->cmd[0]);
	free_cmd(&px->cmd[1]);
}
