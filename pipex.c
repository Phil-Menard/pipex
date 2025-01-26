/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/26 18:52:45 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
function to create pipes
function to call wait(NULL) n times, where n is the number of childs
in child process =>
	close the useless pipes
	here are the pipes useful for each child :
		1st child : pipefd[0][1] (write to next child)
		2nd child : pipefd[0][0] / pipefd[1][1] (listen from last/write to next)
		3rd child : pipefd[1][0] (listen from last)
	here are the pipes useless for each child :
		1st child : pipefd[0][0] / pipefd[1][0] / pipefd[1][1]
		2nd child : pipefd[0][1] / pipefd[1][0]
		3rd child : pipefd[0][0] / pipefd[0][1] / pipefd[1][1]
	read datas
	close reading pipe
	write datas
	close writing pipe
if statements for first and last child, respectively for reading and writing from/to file
*/

void	close_pipes(int **pipefd, int i)
{
	int	j;
	int	k;

	j = 0;
	if (i == 0)
	{
		while (pipefd[j] != -1)
		{
			k = 0;
			while (k < 2)
			{
				if (!(i == 0 && j == 1))
					close(pipefd[j][k]);
				k++;
			}
			j++;
		}
	}
}

void	read_process(int **pipefd, int i)
{
	if (i == 0)
		pipefd[0] = open("infile", O_RDONLY);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(pipefd[0]);
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
}

void	child_process(int **pipefd, char **argv, char **env, int i)
{
	char	*path;
	char	**arg;

	close_pipes(pipefd, i);
	path = get_right_path(env, argv[i]);
	if (!path)
		exit(EXIT_FAILURE);
	arg = fill_arg(path, argv[i]);
	read_process(pipefd, i);
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

void	handle_processes(char **argv, char **env, int *id, int **pipefd)
{
	int	i;

	i = 0;
	if (id[i] == 0)
		child_process(pipefd, argv, env, i);
	else
		wait(NULL);
}

void	pipex(char **argv, char **env, int nb_cmds)
{
	int	**pipefd;
	int	*id;

	pipefd = create_pipes(nb_cmds - 1);
	id = malloc((nb_cmds + 1) * sizeof(int));
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
