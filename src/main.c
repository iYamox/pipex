/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:05:37 by amary             #+#    #+#             */
/*   Updated: 2026/01/22 18:25:52 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char envp)
{
	t_pipex	pipex;
	int		exit;

	init(&pipex, envp);
	if (!ft_parsing(argc, argv, envp, &pipex))
		return (ft_free((&pipex)), 1);
}