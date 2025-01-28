/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:18:03 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/28 15:48:13 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_name(char *argv)
{
	char	**arr;
	char	*cmd;

	arr = ft_split(argv, ' ');
	cmd = ft_strdup(arr[0]);
	free_db_array(arr);
	return (cmd);
}

char	**get_cmds(char **argv, int argc)
{
	char	**res;
	int		nb_cmds;
	int		i;
	int		j;

	nb_cmds = argc - 3;
	if (nb_cmds < 1)
		return (NULL);
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

int	argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
