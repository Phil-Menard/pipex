/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:03:18 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:10:00 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (i < 65 || (i > 90 && i < 97) 
			|| i > 122)
		{
			printf("Expected : 0\n");
			printf("Received : %d\n", ft_isalpha(i));
			if (ft_isalpha(i) != 0)
			{
				printf("TEST FAILED!");
				return (0);
			}
		}
		else
		{
			printf("Expected : %d\n", i);
			printf("Received : %d\n", ft_isalpha(i));
			if (ft_isalpha(i) == 0)
			{
				printf("TEST FAILED!");
				return (0);
			}
		}
		printf("\n");
		i++;
	}
	printf("SUCCESS!\n");
	return (0);
}
*/