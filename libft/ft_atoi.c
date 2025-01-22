/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:15:58 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:08:49 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	result *= sign;
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	printf("ft_atoi : %d\n", ft_atoi("  \t\n\v\f\r+12345456789789456r67890"));
	printf("atoi    : %d\n", atoi("  \t\n\v\f\r+12345456789789456r67890"));

	return (0);
}
*/