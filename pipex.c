/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/24 18:14:32 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_process(int *pipefd, int *id)
{
	if (id[0] == 0)
		pipefd[0] = open("infile", O_RDONLY);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(pipefd[0]);
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
}

void	child_process(int *pipefd, char **argv, char **env, int *id)
{
	char	*path;
	char	**arg;

	path = get_right_path(env, argv[2]);
	if (!path)
		exit(EXIT_FAILURE);
	arg = fill_arg(path, argv[2]);
	read_process(pipefd, id);
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	if (execve(path, arg, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	free(path);
	free_db_array(arg);
}

/* void	parent_process(int *pipefd, char **argv, char **env)
{
	int		outfile;
	char	*path;
	char	**arg;

	path = get_right_path(env, argv[3]);
	if (!path)
		exit(EXIT_FAILURE);
	arg = fill_arg(path, argv[3]);
	outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[1]);
	close(outfile);
	if (execve(path, arg, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	free(path);
	free_db_array(arg);
} */

void	handle_processes(char **argv, char **env, int *id, int *pipefd)
{
	int	i;

	i = 0;
	if (id[i] == 0)
		child_process(pipefd, argv, env, id);
	else
		parent_process(pipefd, argv, env);
}

void	pipex(char **argv, char **env, int nb_cmds)
{
	int	pipefd[2];
	int	*id;

	id = malloc((nb_cmds + 1) * sizeof(int));
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	id[0] = fork();
	if (id[0] == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	create_child(id, nb_cmds);
	handle_processes(argv, env, id, pipefd);
	free(id);
}

int	main(int argc, char **argv, char **env)
{
	int		nb_cmds;
	char	**args;

	(void) env;
	if (argc > 1)
	{
		nb_cmds = argc - 3;
		args = get_cmds(argv, argc, nb_cmds);
		pipex(args, env, nb_cmds);
		free_db_array(args);
	}
	return (0);
}
