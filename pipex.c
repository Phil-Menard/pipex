/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/28 16:25:40 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmds(int previous_fd, int next_fd, char *argv, char **env)
{
	char	*path;
	char	**arg;

	if (dup2(previous_fd, STDIN_FILENO) == -1)
		return (perror("dup2in"), exit(EXIT_FAILURE));
	close(previous_fd);
	if (dup2(next_fd, STDOUT_FILENO) == -1)
		return (perror("dup2out"), exit(EXIT_FAILURE));
	close(next_fd);
	path = get_right_path(env, argv);
	arg = fill_arg(path, argv);
	if (execve(path, arg, NULL) == -1)
	{
		free(path);
		free_db_array(arg);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	pipex(char **argv, char **env, int previous_fd, int outfile)
{
	int		pipefd[2];
	int		i;
	pid_t	id;

	i = -1;
	while (++i < argv_size(argv))
	{
		if (pipe(pipefd) == -1)
			return (perror("pipe"), exit(EXIT_FAILURE));
		id = fork();
		if (id == -1)
			return (perror("fork"), exit(EXIT_FAILURE));
		if (id == 0)
		{
			close(pipefd[0]);
			if (i == (argv_size(argv) - 1))
				pipefd[1] = outfile;
			exec_cmds(previous_fd, pipefd[1], argv[i], env);
		}
		previous_fd = pipefd[0];
		close(pipefd[1]);
		wait(NULL);
	}
	close(pipefd[0]);
}

int	main(int argc, char **argv, char **env)
{
	char	**args;
	int		outfile;
	int		previous_fd;

	if (argc > 2)
	{
		previous_fd = open(argv[1], O_RDONLY);
		if (previous_fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		args = get_cmds(argv, argc);
		if (args == NULL)
			return (close(previous_fd), close(outfile), 1);
		pipex(args, env, previous_fd, outfile);
		free_db_array(args);
	}
	return (0);
}
