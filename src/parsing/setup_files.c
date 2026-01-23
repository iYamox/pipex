/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:49:12 by amary             #+#    #+#             */
/*   Updated: 2026/01/23 16:19:20 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

bool	setup_files(t_pipex *pipex, char *infile, char *outfile)
{
	pipex->infile = open(infile, O_RDONLY);
	if (pipex->infile < 0)
		return (perror("cannot open infile"), false);
	pipex->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		pipex_close(&pipex->infile);
		return (perror("cannot open outfile"), false);
	}
	return (true);
}
