/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:05:05 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/18 10:19:26 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	temp = new_lst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		current = ft_lstnew(f(lst->content));
		if (current == NULL)
			return (NULL);
		if (current->content == NULL)
		{
			del(current->content);
			free(current);
		}
		temp->next = current;
		temp = temp->next;
	}
	return (new_lst);
}

/* #include <stdio.h>

void	*f(void *content)
{
	return (content);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new_lst;
	int		*a;
	int		*b;
	int		*c;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	*a = 20;
	*b = 30;
	*c = 40;
	node1 = ft_lstnew(a);
	node2 = ft_lstnew(b);
	node3 = ft_lstnew(c);
	node1->next = node2;
	node2->next = node3;
	new_lst = ft_lstmap(node1, &f, &del);
	if (new_lst == NULL)
	{
		printf("erreur, new_lst est null!");
		return (1);
	}
	while (new_lst != NULL)
	{
		printf("content du noeud : %d\n", *(int *)new_lst->content);
		new_lst = new_lst->next;
	}
	return (0);
} */