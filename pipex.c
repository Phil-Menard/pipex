/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/24 11:35:44 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
child1 => write result from execve to child2
child2 => read result, and do another execve applied to the result
*/

void	pipex(char *path, char **arg)
{
	int		pipefd[2];
	int		id;
	char	*buf;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		if (execve(path, arg, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
	}
	else
	{
		close(pipefd[1]);
		buf = get_next_line(pipefd[0]);
		while (buf != NULL)
		{
			printf("%s", buf);
			free(buf);
			buf = get_next_line(pipefd[0]);
		}
		free(buf);
		wait(NULL);
		free(buf);
		close(pipefd[0]);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*path;
	char	**arg;

	if (argc > 1)
	{
		path = get_right_path(env, argv[1]);
		if (!path)
			exit(EXIT_FAILURE);
		arg = fill_arg(path, argv[1]);
		pipex(path, arg);
		free(path);
		free_db_array(arg);
	}
	return (0);
}
