/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:00:09 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/14 17:31:29 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_fill(int a, int b)
{
	t_list *new;
	
	new = lstnew(a);
	a++;
	while (a <= b)
	{
		lst_add_back(&new, a);
		a++;
	}
	return (new);
}

void	lst_rev_iter(t_list *lst)
{
	lst = lstlast(lst);
	while (lst)
	{
		lst->value *= 2;
		lst = lst->previous;
	}
}

void	lst_iter(t_list *lst)
{
	while (lst)
	{
		lst->value /= 2;
		lst = lst->next;
	}
}

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
		new->previous = last;
	}
	else
		*lst = new;
}

void	lst_add_front(t_list **lst, int value)
{
	t_list *new;
	
	new  = lstnew(value);
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

/* int	main(void)
{	
	t_list *a;
	t_list *b;

	a = lst_fill(1, 5);
	b = lst_fill(42, 48);
	rotate(&a);
	push(&b, &a);
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (0);
} */