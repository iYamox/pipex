/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:05:44 by amary             #+#    #+#             */
/*   Updated: 2026/01/22 18:50:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PIPEX_H
# define PIPEX_H

# define PX_RD 0
# define PX_WR 1
# define PX_OUTMODE 0644 

# include "../libft/libft.h"
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_cmd
{
	char	**argv;
	char	*path;
}	t_cmd;

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**envp;
	t_cmd	cmd[2];
}	t_pipex;

int		main(int argc, char **argv, char envp);
void	init(t_pipex *pipex, char **envp);
void	ft_free(t_pipex *pipex);
void	pipex_close(char *fd);
void	free_cmd(t_cmd *cmd);
void	free_split(char **paths);
bool	setup_fds(t_pipex *pipex, char *infile, char *outfile);

#endif
