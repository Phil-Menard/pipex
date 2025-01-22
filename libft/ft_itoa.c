/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:12:41 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 11:47:55 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	len_int(long int n, int *sign)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		*sign = 2;
		n *= -1;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			sign;
	int			i;
	long int	x;

	x = (long int) n;
	sign = 1;
	i = len_int(x, &sign) + (sign - 1);
	if (x < 0)
		x *= -1;
	ptr = malloc((len_int(x, &sign) + sign) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i--] = '\0';
	while (x > 9)
	{
		ptr[i--] = '0' + (x % 10);
		x /= 10;
	}
	ptr[i] = '0' + x;
	if (sign > 1)
		ptr[0] = '-';
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
*/