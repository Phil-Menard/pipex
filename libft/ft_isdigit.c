/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:03:07 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:10:15 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
		if (i < 48 || i > 57)
		{
			printf("Expected : 0\n");
			printf("Received : %d\n", ft_isdigit(i));
			if (ft_isdigit(i) != 0)
			{
				printf("TEST FAILED!");
				return (0);
			}
		}
		else
		{
			printf("Expected : %d\n", i);
			printf("Received : %d\n", ft_isdigit(i));
			if (ft_isdigit(i) == 0)
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