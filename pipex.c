/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/22 19:00:34 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	free_db_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*get_path(char **env)
{
	int		i;
	char	*path;
	char	**arr;

	i = 0;
	while (ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	arr = ft_split(env[i] + 5, ':');
	i = 0;
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		if (access(arr[i], R_OK) == 0)
		{
			path = ft_strdup(arr[i]);
			free_db_array(arr);
			return (path);
		}
		else
			perror("access");
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	char	*path;
	(void) argv;
	(void) argc;

	path = get_path(env);
	ft_printf("RIGHT PATH : %s\n", path);
	free(path);
	return (0);
}
