/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:03:35 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/15 14:55:09 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

/*
[nnew]
[*lst] [node1] [node2] [node3]
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last_node;
	int		a;
	int		b;
	int		c;
	int		*d;

	int		*a;
	int		*b;
	int		*c;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	d = malloc(sizeof(int));
	*a = 20;
	*b = 30;
	*c = 40;
	*d = 50;
	node1 = ft_lstnew(a);
	node2 = ft_lstnew(b);
	node3 = ft_lstnew(c);
	last_node = ft_lstnew(d);
	node1->next = node2;
	node2->next = node3;
	ft_lstadd_back(&node1, last_node);
	printf("adresse dernier noeud : %p\n", last_node);
	printf("adresse pointe par avant dernier noeud : %p\n", node3->next);
	return (0);
}
*/