/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:28 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:12:48 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	src[] = "voila";
	int		i;

	printf("Avant toupper : %s\n", src);
	i = 0;
	while (src[i])
	{
		src[i] = ft_toupper(src[i]);
		i++;
	}
	printf("Apres toupper : %s\n", src);
	return (0);
}
*/