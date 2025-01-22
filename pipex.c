/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:50 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/22 18:13:34 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		x;
	char	*path = NULL;
	(void) argv;
	(void) argc;

	x = 0;
	i = 0;
	while (ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	path = ft_strdup(env[i] + 5);
	ft_printf("%s\n", path);
	free(path);
	return (0);
}
