/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:00:09 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/03 11:38:52 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	lst_add_back(t_list **lst, int value)
{
	t_list	*new;
	t_list	*last;

	new = lstnew(value);
	if (*lst)
	{
		last = lstlast(*lst);
		last->next = new;
		new->previous = last;
	}
	else
		*lst = new;
}

void	lst_add_front(t_list **lst, int value)
{
	t_list	*new;

	new = lstnew(value);
	new->next = *lst;
	(*lst)->previous = new;
	*lst = new;
}

t_list	*lstnew(int value)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
	elem->previous = NULL;
	return (elem);
}
