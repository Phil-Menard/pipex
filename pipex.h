/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:25:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/26 18:32:45 by pmenard          ###   ########.fr       */
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
void	create_child(int *id, int nb_cmds);
char	**get_cmds(char **argv, int argc, int nb_cmds);
int		*create_pipes(int nb_cmds);
void	free_db_array(char **arr);
char	*ft_strjoin_path(char const *s1, char slash, char const *s2);

#endif