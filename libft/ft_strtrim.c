/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:32:32 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:12:32 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = -1;
	end = -1;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL && start < 0)
			start = i;
		i++;
	}
	while (i > 0)
	{
		if (ft_strchr(set, s1[i]) == NULL && end < 0)
			end = i;
		i--;
	}
	ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}

/*
#include <stdio.h>
#include <stdio.h>
int	main(void)
{
	char	*ptr;

	ptr = ft_strtrim("", "");
	printf("%s\n", ptr);
	free(ptr);
	return (0);
}
*/