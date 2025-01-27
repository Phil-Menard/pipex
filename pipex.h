/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:25:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/27 17:07:22 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

char	**fill_arg(char *path, char *argv);
char	*get_right_path(char **env, char *argv);
int		**create_pipes(int nb_cmds);
void	close_pipes_first(int **pipefd, int nb_cmds);
void	close_pipes_last(int **pipefd, int index, int nb_cmds);
void	close_pipes(int **pipefd, int i);
int		*create_child(int *id, int nb_cmds);
void	first_child(int **pipefd, char **env, char **argv, int i);
void	last_child(int **pipefd, char **env, char **argv, int i);
char	**get_cmds(char **argv, int argc, int nb_cmds);
void	exec_cmd(int **pipefd, char **env, char **argv, int i);
int		argv_size(char **argv);
void	free_pipes(int **pipefd, int nb_cmds);
void	free_db_array(char **arr);
char	*ft_strjoin_path(char const *s1, char slash, char const *s2);

#endif