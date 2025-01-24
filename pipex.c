/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/24 13:09:33 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//write result fo first cmd here
void	first_child_process(int *pipefd, char *path, char **arg)
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

void	parent_process(int *pipefd)
{
	char	*buf;

	close(pipefd[1]);
	buf = get_next_line(pipefd[0]);
	//we read the result of the cmd
	while (buf != NULL)
	{
		printf("%s", buf);
		free(buf);
		buf = get_next_line(pipefd[0]);
		//send the result of the cmd back to second child, and second child
		//apply other cmd to the result of the cmd
		//and send it back to parent?
	}
	free(buf);
	wait(NULL);
	free(buf);
	close(pipefd[0]);
}

void	pipex(char *path, char **arg)
{
	int		pipefd[2];
	int		id;

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
		first_child_process(pipefd, path, arg);
	else
		parent_process(pipefd);
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
