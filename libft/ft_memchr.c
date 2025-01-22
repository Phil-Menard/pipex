/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:48:26 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:10:43 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "voila une longue phrase.";
	char	*ptr;
	char	*ptr2;
	char	c;

	c = 't';
	ptr = ft_memchr(str, c, 30);
	printf("ft_memchr : %s\n", ptr);
	ptr2 = memchr(str, c, 30);
	printf("memchr    : %s\n", ptr2);
	return (0);
}
*/