/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:44:57 by amary             #+#    #+#             */
/*   Updated: 2026/01/23 16:31:35 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

bool	ft_parsing(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc != 5)
		return (write(2, "Argument error\n", 16), false);
	if (!setup_files(pipex, argv[1], argv[4]))
		return (false);
	pipex->cmd[0].name = ft_split(argv[2], ' ');
	if (!pipex->cmd[0].name || !pipex->cmd[0].name[0])
		return (ft_free(pipex), write(2, "command not found\n", 19), false);
	pipex->cmd[0].path = find_cmd(envp, pipex->cmd[0].name);
	if (!pipex->cmd[0].path)
		return (perror(argv[2]), false);
	pipex->cmd[1].name = ft_split(argv[3], ' ');
	if (!pipex->cmd[1].name || !pipex->cmd[1].name[0])
		return (ft_free(pipex), write(2, "command not found\n", 19), false);
	pipex->cmd[1].path = find_cmd(envp, pipex->cmd[1].name);
	if (!pipex->cmd[1].path)
		return (perror(argv[3]), false);
	return (true);
}
