/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:00:32 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:11:17 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr = (char)c;
		ptr++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hello";
	int		arr[5];

	printf("Avant memset : %s\n", str);
	ft_memset(str, 'c', 3);
	printf("Apres memset : %s\n", str);
	printf("\n---------\n");
	memset(arr, 1, sizeof(arr));
	int i = 0;
	while (i < 5)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
*/