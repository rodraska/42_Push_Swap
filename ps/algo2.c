/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:42:26 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/10 17:02:45 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **a, t_list **b, t_list *elem, t_list *neigh)
{
	if (elem->move == 0 && neigh->move == 0)
		keep_rotating(a, b, elem, neigh);
	else if (elem->move == 1 && neigh->move == 1)
		keep_rev_rotating(a, b, elem, neigh);
	else if (elem->move == 1 && neigh->move == 0)
		keep_rot_rev(a, b, elem, neigh);
	else if (elem->move == 0 && neigh->move == 1)
		keep_rev_rot(a, b, elem, neigh);
}

int	best_path(t_list *a, t_list *b, t_list *elem, t_list *neigh)
{
	int	cost_a;
	int	cost_b;

	cost_b = ft_cost(&b, elem);
	cost_a = ft_cost(&a, neigh);
	if (elem->move == 0 && neigh->move == 0)
		return (ft_bigger(cost_a, cost_b));
	else if (elem->move == 1 && neigh->move == 1)
		return (ft_bigger(cost_a, cost_b));
	else
		return (cost_a + cost_b);
}

/* t_list	*best_neigh(t_list *a, t_list *b)
{
	ft_printf("ola");
	
	t_list	*neigh;
	long 	dif;

	dif = 9223372036854775807;
	// neigh = a;
	while (a)
	{
		ft_printf("bv: %d\n", b->value);
		ft_printf("av: %d\n", a->value);
		ft_printf("a-b %d\n", a->value - b->value);
		if ((long)(a->value - b->value) < dif && (long)(a->value - b->value) > 0)
		{
			neigh = a;
			dif = a->value - b->value;
		}
		a = a->next;
	}
	ft_printf("my n: %d\n", neigh->value);
	return (neigh);
} */

t_list	*best_neigh(t_list *a, t_list *b)
{
	t_list	*neigh;
	int		dif;

	dif = 2147483647;
	neigh = a;
	while (a)
	{
		if (a->value - b->value < dif && a->value - b->value > 0)
		{
			neigh = a;
			dif = a->value - b->value;
		}
		a = a->next;
	}
	return (neigh);
}

void	min_top(t_list **lst)
{
	t_list	*min;
	int		size;
	int		size_min;

	min = lst_min(*lst);
	size = lst_size(*lst);
	size_min = lst_size(min);
	if (size_min > size / 2)
	{
		while (*lst != min)
			rotate(lst, "ra");
	}
	else
	{
		while (*lst != min)
			rev_rotate(lst, "rra");
	}
}

int	ft_bigger(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
