/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:18:57 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:09:12 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hello";
	int		arr[] = {10, 20, 30, 40, 50};
	int		i;

	printf("Avant bzero : %s\n", str);
	ft_bzero(str, 0);
	printf("Apres bzero : %s\n", str);
	printf("Apres bzero + 1 : %s\n", str + 1);
	printf("Apres bzero + 2 : %s\n", str + 2);
	printf("Apres bzero + 3 : %s\n", str + 3);
	printf("\n---------\n");
	i = 0;
	while (i < 5)
	{
		printf("Avant bzero : %d\n", arr[i]);
		i++;
	}
	ft_bzero(arr, sizeof(arr));
	printf("\n");
	i = 0;
	while (i < 5)
	{
		printf("Apres bzero : %d\n", arr[i]);
		i++;
	}
	return (0);
}
*/
