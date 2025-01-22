/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:49:10 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/13 15:22:59 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*ptr;

	ptr = s;
	i = 0;
	while (s[i])
	{
		f(i, ptr);
		ptr++;
		i++;
	}
}

/*
#include <stdio.h>

void	u(unsigned int i, char *c)
{
	i = 0;
	if (c[i] >= 'a' && c[i] <= 'z')
		c[i] -= 32;
}

int	main(void)
{
	char	str[] = "hello";
	
	ft_striteri(str, &u);
	printf("%s\n", str);

	return (0);
}
*/