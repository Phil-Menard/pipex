/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:21:07 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/15 11:21:09 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		a;
	int		b;
	int		c;

	a = 20;
	node1 = ft_lstnew(&a);
	b = 30;
	node2 = ft_lstnew(&b);
	c = 40;
	node3 = ft_lstnew(&c);
	node1->next = node2;
	node2->next = node3;

	printf("adresse node1 : %p\n", node1->next);
	printf("adresse node2 : %p\n", node2->next);
	printf("adresse node3 : %p\n", node3->next);
	printf("nombre de noeuds : %d\n", ft_lstsize(node1));
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/