/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:46:08 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/24 11:33:09 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlenline(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	ft_strchrline(char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_putline(char *src, char *dest)
{
	int	i;

	i = 0;
	if (src[0] == '\0')
		return (NULL);
	while (src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_putstrline(char *src, char *dest, int i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_realloc(char *str, char *buffer)
{
	size_t	len_str;
	char	*new_str;

	len_str = ft_strlenline(str);
	new_str = malloc((len_str + ft_strlenline(buffer) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	if (str)
	{
		new_str = ft_putstrline(str, new_str, 0);
		free(str);
	}
	return (new_str);
}
