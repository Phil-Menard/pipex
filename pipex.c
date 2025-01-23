/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/23 17:20:47 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	char	*path;
	char	**arg;

	if (argc > 1)
	{
		path = get_right_path(env, argv[1]);
		arg = fill_arg(path, argv[1]);
		ft_printf("%s\n", path);
		if (execve(path, arg, NULL) == -1)
		{
			perror("execve");
			return (1);
		}
		free(path);
	}
	return (0);
}
