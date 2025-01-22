/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:12:40 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/10 11:53:47 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_unint(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_untoa(unsigned int x)
{
	char			*ptr;
	size_t			i;

	i = len_unint(x);
	ptr = malloc((len_unint(x) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i--] = '\0';
	while (x > 9)
	{
		ptr[i--] = '0' + (x % 10);
		x /= 10;
	}
	ptr[i] = '0' + x;
	return (ptr);
}

void	ft_putnum(int nb, int *result)
{
	char	*arr;
	char	*p;

	if (nb < 0)
	{
		ft_putchar('-', result);
		nb *= -1;
	}
	arr = ft_untoa((unsigned int) nb);
	p = arr;
	if (arr != NULL)
	{
		while (*arr)
		{
			ft_putchar(*arr, result);
			arr++;
		}
		free(p);
	}
}

void	ft_put_unum(unsigned int nb, int *result)
{
	char	*arr;
	char	*p;

	arr = ft_untoa(nb);
	p = arr;
	if (arr != NULL)
	{
		while (*arr)
		{
			ft_putchar(*arr, result);
			arr++;
		}
		free(p);
	}
}
