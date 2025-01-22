/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:54:09 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/10 11:54:07 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itohex(unsigned int x, int loworup)
{
	size_t	i;
	char	*ptr;
	int		temp;

	i = 0;
	ptr = malloc((len_unint(x) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (x == 0)
		ptr[i++] = '0';
	while (x != 0)
	{
		temp = x % 16;
		if (temp < 10)
			ptr[i++] = 48 + temp;
		else
			ptr[i++] = loworup + temp;
		x /= 16;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_puthex(unsigned int x, int *result, char c)
{
	char	*arr;
	char	*p;
	int		i;

	if (c == 'x')
		arr = ft_itohex(x, 87);
	else
		arr = ft_itohex(x, 55);
	p = arr;
	if (arr != NULL)
	{
		i = ft_strlen(arr) - 1;
		while (i >= 0)
		{
			ft_putchar(arr[i], result);
			i--;
		}
		free(p);
	}
}
