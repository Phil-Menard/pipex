/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:23:12 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:12:36 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size_left;
	size_t	s_len;

	s_len = ft_strlen(s);
	size_left = s_len - start;
	if (start >= s_len)
		len = 0;
	else if (len > size_left)
		len = s_len - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (len > 0 && size_left > 0)
	{
		ptr[i++] = s[start++];
		size_left--;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>
int	main(void)
{
	char const	s[] = "01234";
	char		*ptr;

	ptr = ft_substr(s, 10, 10);
	printf("%s\n", ptr);
	//printf("%ld\n", ft_strlen(ptr));
	free(ptr);
	return (0);
}
*/