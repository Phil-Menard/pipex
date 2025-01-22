/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:54:22 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/20 18:25:34 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_hexa(unsigned long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_longtohex(unsigned long x)
{
	size_t	i;
	char	*ptr;
	int		temp;

	i = 0;
	ptr = malloc((len_hexa(x) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (x != 0)
	{
		temp = x % 16;
		if (temp < 10)
			ptr[i++] = 48 + temp;
		else
			ptr[i++] = 87 + temp;
		x /= 16;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_putadd(void *p, int *result)
{
	unsigned long	x;
	int				i;
	char			*arr;
	char			*ptr;

	if (p != NULL)
	{
		x = (unsigned long)p;
		i = len_hexa(x);
		ft_putchar('0', result);
		ft_putchar('x', result);
		arr = ft_longtohex(x);
		ptr = arr;
		if (arr != NULL)
		{
			i = ft_strlen(arr) - 1;
			while (i >= 0)
				ft_putchar(arr[i--], result);
			free(ptr);
		}
	}
	else
		ft_putstr("(nil)", result);
}
