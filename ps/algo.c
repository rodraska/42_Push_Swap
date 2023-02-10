/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:39:03 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/10 17:01:42 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **lst)
{
	if ((*lst)->value > (*lst)->next->value)
		swap(*lst, "sa");
	if ((*lst)->next->value > (*lst)->value \
	&& (*lst)->next->value > (*lst)->next->next->value)
		rev_rotate(lst, "rra");
	if ((*lst)->value > (*lst)->next->value)
		swap(*lst, "sa");
}

void	sort_5(t_list **a, t_list **b)
{
	min_top(a);
	push(a, b, "pb");
	min_top(a);
	push(a, b, "pb");
	sort_3(a);
	push(b, a, "pa");
	push(b, a, "pa");
}

void	sort(t_list **a, t_list **b)
{
	t_list	*elem;
	t_list	*neigh;

	while (lst_size((*a)) > 1)
	{
		if ((*a)->value <= lst_average(*a))
			push(a, b, "pb");
		else
			rotate(a, "ra");
	}
	while (*b)
	{
		elem = cost_min(*a, *b);
		neigh = best_neigh(*a, elem);
		ft_rotate(a, b, elem, neigh);
		push(b, a, "pa");
	}
	min_top(a);
}

t_list	*cost_min(t_list *a, t_list *b)
{
	int		min;
	int		cost;
	t_list	*elem;
	t_list	*neigh;

	min = 5000;
	while (b)
	{
		neigh = best_neigh(a, b);
		cost = best_path(a, b, b, neigh);
		if (cost < min)
		{
			min = cost;
			elem = b;
		}
		b = b->next;
	}
	return (elem);
}

int	ft_cost(t_list **lst, t_list *elem)
{
	if (lst_size(elem) > lst_size(lstfirst(*lst)) / 2)
	{
		elem->move = 0;
		return (lst_size(lstfirst(*lst)) - lst_size(elem));
	}
	else
	{
		elem->move = 1;
		return (lst_size(elem));
	}
}
