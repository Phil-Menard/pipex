/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/28 18:44:10 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_path_errors(char **argv, char **env, int i)
{
	char	*path;

	path = get_right_path(env, argv[i]);
	if (!path)
	{
		path = get_cmd_name(argv[i]);
		ft_putstr_fd(path, 2);
		free(path);
		ft_putstr_fd(": command not found\n", 2);
		free_db_array(argv);
		exit(EXIT_FAILURE);
	}
}

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
		ft_printf("%s\n", arg[0]);
		ft_printf("%s\n", arg[1]);
		ft_printf("%s\n", arg[2]);
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
			check_path_errors(argv, env, i);
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

	if (argc > 4)
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
