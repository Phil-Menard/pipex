/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:33:34 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:12:43 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	src[] = "VOILA";
	int		i;

	printf("Avant ft_tolower : %s\n", src);
	i = 0;
	while (src[i])
	{
		src[i] = ft_tolower(src[i]);
		i++;
	}
	printf("Apres ft_tolower : %s\n", src);
	return (0);
}
*/