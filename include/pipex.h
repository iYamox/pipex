/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:05:44 by amary             #+#    #+#             */
/*   Updated: 2026/01/24 11:42:17 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	char	**name;
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

int		main(int argc, char **argv, char **envp);
void	init(t_pipex *pipex, char **envp, char **argv);
void	ft_free(t_pipex *pipex);
void	pipex_close(int *fd);
void	free_cmd(t_cmd *cmd);
void	free_split(char **paths);
bool	ft_parsing(int argc, char **argv, char **envp, t_pipex *pipex);
bool	setup_files(t_pipex *pipex, char *infile, char *outfile);
char	*find_cmd(char **envp, char **cmd_name);
char	*check(char *cmd_name, char **envp);
bool	has_slash(const char *s);
char	*get_env(char **envp, char *key);
char	*join_path(char *dir, char *cmd_name);
int		ft_pipex(t_pipex *pipex);
void	child_exec2(t_pipex *pipex);
void	child_process(t_pipex *pipex);
void	ensure_cmd_or_die(t_cmd *cmd);

#endif
