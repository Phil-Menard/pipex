/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:18:03 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/26 18:32:34 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmds(char **argv, int argc, int nb_cmds)
{
	char	**res;
	int		i;
	int		j;

	res = malloc((nb_cmds + 1) * sizeof(char *));
	j = 0;
	i = 2;
	while (i < (argc - 1))
	{
		res[j] = ft_strdup(argv[i]);
		j++;
		i++;
	}
	res[j] = NULL;
	return (res);
}

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

char	*ft_strjoin_path(char const *s1, char slash, char const *s2)
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

void	create_child(int *id, int nb_cmds)
{
	int	i;

	if (nb_cmds > 0)
	{
		id[0] = fork();
		if (id[0] == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}
	i = 1;
	while (i < nb_cmds)
	{
		if (id[i] != 0)
		{
			id[i] = fork();
			if (id[i] == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

int	*create_pipes(int nb_cmds)
{
	int	**pipefd;
	int	i;
	int	j;

	pipefd = malloc((nb_cmds + 1) * sizeof(int *));
	pipefd[nb_cmds] = -1;
	i = 0;
	while (pipefd[i] != -1)
	{
		j = 0;
		while (j < 2)
		{
			pipefd[i][j] = j;
			j++;
		}
		if (pipe(pipefd[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (pipefd);
}
