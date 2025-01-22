/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:19:56 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/18 17:56:00 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb != 0 && size > 4294967295 / nmemb)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, nmemb * size);
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*str;
	int	i;

	str = calloc(0, 0);
	i = 0;
	while (i < 10)
	{
		printf("%c\n", str[i]);
		i++;
	}
	free(str);
	return 0;
}
*/