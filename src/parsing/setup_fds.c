/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:49:12 by amary             #+#    #+#             */
/*   Updated: 2026/01/22 19:10:01 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

bool	setup_fds(t_pipex *pipex, char *infile, char *outfile)
{
	pipex->infile = open(infile, O_RDONLY);
	if (infile < 0)
		return (perror("cannot open infile"), false);
	pipex->outfile = open(outfile, O_WRONLY || O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		pipex_close(&pipex->infile);
		return (perror("cannot open outfile"), false);
	}
	return (true);
}
