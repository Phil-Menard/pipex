/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:48:32 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/12 10:12:20 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		i = 0;
		while (big[i] == little[i] && (i < len))
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	big[] = "voila une longue phrase.";
	char	little[] = "ras";
	
	printf("ft_strnstr : %s\n", ft_strnstr(big, little, 20));
	printf("strnstr    : %s\n", strnstr(big, little, 20));
	return (0);
}
*/