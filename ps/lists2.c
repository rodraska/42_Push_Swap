/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:33:53 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/03 11:46:02 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		size;

	size = lst_size(lst);
	total = 0;
	while (lst)
	{
		total += lst->value;
		lst = lst->next;
	}
	return (total / size);
}

t_list	*lstfirst(t_list *lst)
{
	t_list	*first;

	first = lst;
	while (lst != NULL)
	{
		first = lst;
		lst = lst->previous;
	}
	return (first);
}

t_list	*lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
