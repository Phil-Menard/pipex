/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/27 19:04:30 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **env, int nb_cmds)
{
	int	*pipefd;
	int	i;
	
	while (i < argc - 1)
	{
		
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		nb_cmds;
	char	**args;

	if (argc > 1)
	{
		nb_cmds = argc - 3;
		args = get_cmds(argv, argc, nb_cmds);
		pipex(argc, args, env, nb_cmds);
		free_db_array(args);
	}
	return (0);
}
