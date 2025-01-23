/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/23 18:45:59 by pmenard          ###   ########.fr       */
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
	int		bytes_read;
	char	*buf;

	buf = malloc(1000 * sizeof(char));
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
	}
	else
	{
		close(pipefd[1]);
		bytes_read = read(pipefd[0], buf, 1000);
		if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		buf[bytes_read - 1] = '\0';
		wait(NULL);
		printf("%s\n", buf);
		free(buf);
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
