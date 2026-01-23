/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:44:57 by amary             #+#    #+#             */
/*   Updated: 2026/01/22 18:48:59 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

bool	ft_parsing(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc != 5)
		return (ft_putstr_fd("Argument error\n", 2), false);
	if (!setup_fds(pipex, argv[1], argv[4]))
		return (false);
}