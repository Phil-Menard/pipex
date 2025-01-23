/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/23 11:20:26 by pmenard          ###   ########.fr       */
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

char	*ft_strjoin_cmd(char const *s1, char slash, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc((ft_strlen(s1) + 1 + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = slash;
	i++;
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_path(char **arr, char *argv, int i)
{
	char	*path;
	char	*cmd;
	char	**args;

	args = ft_split(argv, ' ');
	cmd = ft_strdup(args[0]);
	free_db_array(args);
	path = ft_strjoin_cmd(arr[i], '/', cmd);
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
		else
			perror("access");
		free(path);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	char	*path;

	(void) argv;
	(void) argc;
	path = get_right_path(env, argv[1]);
	ft_printf("RIGHT PATH : %s\n", path);
	free(path);
	return (0);
}
