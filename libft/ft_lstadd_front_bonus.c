/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:21:13 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/15 11:21:14 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int main(void)
{
	t_list  *head;
	int     *a;

	a = malloc(sizeof(int));
	*a = 20;
	head = ft_lstnew(a);
	printf("valeur de content : %d\n", *(int *)head->content);
	printf("adresse de next : %p\n", (void *)head->next);


	return (0);
}
*/