/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:31:50 by nohubert          #+#    #+#             */
/*   Updated: 2025/10/21 18:00:47 by nohubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* Macros */
# define PX_RD 0
# define PX_WR 1
# define PX_OUTMODE 0644 //Permissions

/* Libraries */
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

/* Structures */
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

/* init */
void	init(t_pipex *px, char **envp);

/* fds */
bool	setup_fds(t_pipex *px, const char *infile, const char *outfile);

/* utils */
void	free_split(char **paths);
void	free_cmd(t_cmd *cmd);
void	px_close(int *fd);
void	cleanup(t_pipex *px);

/* parsing */
bool	parse_args(int argc, char **argv, char **envp, t_pipex *px);

/* path functions */
char	*get_env(char **envp, const char *key);
bool	has_slash(const char *s);
char	*join_path(const char *dir, const char *bin);
char	*resolve_cmd(char **envp, const char *bin);
int		run_pipeline(t_pipex *px);

#endif
