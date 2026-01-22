/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:16:12 by nohubert          #+#    #+#             */
/*   Updated: 2025/10/27 00:53:44 by nohubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		exit_code;

	init(&px, envp);
	if (!parse_args(argc, argv, envp, &px))
		return (cleanup(&px), 1);
	exit_code = run_pipeline(&px);
	cleanup(&px);
	return (exit_code);
}
