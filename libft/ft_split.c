/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:36:53 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 16:22:46 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(char const *s, char c)
{
	int	nb_words;
	int	i;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] != c)
			nb_words++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (nb_words);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	int		j;
	int		start_word;

	ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	start_word = 0;
	while (s[i] && i < ft_strlen(s))
	{
		if (s[i] != c && s[i])
		{
			start_word = i;
			while (s[i] && s[i] != c)
				i++;
			ptr[j++] = ft_substr(s, start_word, i - start_word);
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
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