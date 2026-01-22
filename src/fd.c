/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolhan <nolhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:51:58 by nohubert          #+#    #+#             */
/*   Updated: 2025/09/26 15:05:32 by nolhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	setup_fds(t_pipex *px, const char *infile, const char *outfile)
{
	px->infile = open(infile, O_RDONLY);
	if (px->infile < 0)
		return (perror("cannot open infile"), false);
	px->outfile = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, PX_OUTMODE);
	if (px->outfile < 0)
	{
		px_close(&px->infile);
		return (perror("cannot open outfile"), false);
	}
	return (true);
}
