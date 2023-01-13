/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:00:09 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/13 14:06:07 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(int value);

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

t_list *lstlast(t_list *lst)
{
	t_list *last;

	last = lst;
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

void	lst_add_back(t_list **lst, int value)
{
	t_list *new;
	t_list *last;
	
	new = lstnew(value);
	if (*lst)
	{
		last = lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	lst_add_front(t_list **lst, int value)
{
	t_list *new;
	
	new  = lstnew(value);
	new->next = *lst;
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
	return (elem);
}

int	main(void)
{
	t_list *a = lstnew(42);
	
	lst_add_front(&a, 31);
	lst_add_back(&a, 88);
	lst_clear(&a->next);
	
	printf("%d\n", a->value);
	//printf("%d\n", a->next->value);
	printf("%d\n", lstlast(a)->value);
}