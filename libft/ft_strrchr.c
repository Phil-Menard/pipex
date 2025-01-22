/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:38:29 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:12:26 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	s += len;
	while (len >= 0)
	{
		if (*s == (char) c)
			return ((char *)s);
		s--;
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "voila une longue phrase.";
	char	c;

	c = '\0';
	printf("ft_strrchr : %s\n", ft_strrchr(str, c));
	printf("strrchr    : %s\n", strrchr(str, c));
	return (0);
}
*/