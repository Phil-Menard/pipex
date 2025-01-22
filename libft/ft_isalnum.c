/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:04:25 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:09:51 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	else if (c >= '0' && c <= '9')
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
		if ((i < 48 || i > 57) && (i < 65 || (i > 90 && i < 97) 
			|| i > 122))
		{
			printf("Expected : 0\n");
			printf("Received : %d\n", ft_isalnum(i));
			if (ft_isalnum(i) != 0)
			{
				printf("TEST FAILED!");
				return (0);
			}
		}
		else
		{
			printf("Expected : %d\n", i);
			printf("Received : %d\n", ft_isalnum(i));
			if (ft_isalnum(i) == 0)
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