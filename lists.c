/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:00:09 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/02 14:26:34 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
}

t_list	*lst_max(t_list *lst)
{
	t_list	*max;

	max = lst;
	while (lst)
	{
		if (lst->value > max->value)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

t_list	*lst_min(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if (lst->value < min->value)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

float	lst_average(t_list *lst)
{
	float	total;
	int	size;

	size = lst_size(lst);
	total = 0;
	while (lst)
	{
		total += lst->value;
		lst = lst->next;
	}
	return (total / size);
}

int		lst_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int		lst_duplicate(t_list *lst, int n)
{
	while (lst)
	{
		if (lst->value == n)
			return (1);
		lst = lst->next;
	}
	return (0);
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

t_list	*lstfirst(t_list *lst)
{
	t_list *first;

	first = lst;
	while (lst != NULL)
	{
		first = lst;
		lst = lst->previous;
	}
	return (first);
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