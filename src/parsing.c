/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolhan <nolhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:10:52 by nohubert          #+#    #+#             */
/*   Updated: 2025/09/26 15:42:08 by nolhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	parse_args(int argc, char **argv, char **envp, t_pipex *px)
{
	if (argc != 5)
		return (ft_printf("Invalid number of arguments.\n"), false);
	if (!setup_fds(px, argv[1], argv[4]))
		return (false);
	px->cmd[0].argv = ft_split(argv[2], ' ');
	if (!px->cmd[0].argv || !px->cmd[0].argv[0])
	{
		cleanup(px);
		return (ft_printf("command not found\n"), false);
	}
	px->cmd[0].path = resolve_cmd(envp, px->cmd[0].argv[0]);
	if (!px->cmd[0].path)
		return (perror(argv[2]), false);
	px->cmd[1].argv = ft_split(argv[3], ' ');
	if (!px->cmd[1].argv || !px->cmd[1].argv[0])
	{
		cleanup(px);
		return (ft_printf("command not found\n"), false);
	}
	px->cmd[1].path = resolve_cmd(envp, px->cmd[1].argv[0]);
	if (!px->cmd[1].path)
		return (perror(argv[3]), false);
	return (true);
}
