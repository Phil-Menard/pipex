/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:19:45 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/28 16:22:38 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**fill_arg(char *path, char *argv)
{
	char	**arg;

	if (!path)
		return (NULL);
	arg = ft_split(argv, ' ');
	free(arg[0]);
	arg[0] = ft_strdup(path);
	return (arg);
}

char	*get_next_path(char **arr, char *argv, int i)
{
	char	*path;
	char	*cmd;
	char	**args;

	args = ft_split(argv, ' ');
	cmd = ft_strdup(args[0]);
	free_db_array(args);
	path = ft_strjoin_path(arr[i], '/', cmd);
	free(cmd);
	return (path);
}

char	*get_right_path(char **env, char *argv)
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
		path = get_next_path(arr, argv, i);
		if (access(path, X_OK) == 0)
		{
			free_db_array(arr);
			return (path);
		}
		free(path);
		i++;
	}
	free_db_array(arr);
	return (NULL);
}
