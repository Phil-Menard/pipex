/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:40:45 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/18 10:24:55 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	while (len_dst < size && dst[len_dst])
		len_dst++;
	len_src = ft_strlen(src);
	if (size == len_dst)
		return (size + len_src);
	dst += len_dst;
	size -= len_dst;
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (len_dst + len_src);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[6] = "Hello";
	char	str2[5] = "World";

	printf("%zu\n", ft_strlcat(str, str2, 8));
	printf("%s\n", str);
	return (0);
}
*/