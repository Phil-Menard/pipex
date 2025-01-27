/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:36:53 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/27 16:51:25 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countnbstring(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**tab;
	size_t	start;
	size_t	end;

	tab = (char **) malloc ((ft_countnbstring(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
			tab[j++] = ft_substr(s, start, end - start);
	}
	tab[j] = 0;
	return (tab);
}

/*#include <stdio.h>
int	main(void)
{
	char	**ptr;
	int		i;
	printf("%d\n", count_words("tripouille", 0));
	ptr = ft_split("tripouille", 0);
	i = 0;
	while (i < count_words("tripouille", 0) + 1)
	{
		if (ptr[i] == NULL)
			printf("(null)\n");
		else
			printf("%s\n", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}
*/