/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:18:03 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/27 18:54:09 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmds(char **argv, int argc, int nb_cmds)
{
	char	**res;
	int		i;
	int		j;

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
