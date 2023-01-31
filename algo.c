#include "push_swap.h"

void    sort_3(t_list **lst)
{
	if ((*lst)->value > (*lst)->next->value)
		swap(*lst, "sa");
	if ((*lst)->next->value > (*lst)->value && (*lst)->next->value > (*lst)->next->next->value)
		rev_rotate(lst, "rra");
	if ((*lst)->value > (*lst)->next->value)
		swap(*lst, "sa");
}

void    sort(t_list **a, t_list **b)
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
		ft_printf("size b: %d\n", lst_size(*b));
		elem = cost_min(*a, *b);
		neigh = best_neigh(*a, elem);
		ft_rotate(a, b, elem, neigh);
		push(b, a, "pa");
	}
}

void	ft_rotate(t_list **a, t_list **b, t_list *elem, t_list *neigh)
{
	
	if (elem->move == 0 && neigh->move == 0)
	{
		while (*a != neigh && *b != elem)
		{
			rotate(a, "rr");
			rotate(b, "");
		}
		while (*a != neigh)
			rotate(a, "ra");
		while (*b != elem)
			rotate(b, "rb");
	}
	else if (elem->move == 1 && neigh->move == 1)
	{
		while (*a != neigh && *b != elem)
		{
			rev_rotate(a, "rrr");
			rev_rotate(b, "");
		}
		while (*a != neigh)
			rev_rotate(a, "rra");
		while (*b != elem)
			rev_rotate(b, "rrb");
	}
	else if (elem->move == 0 && neigh->move == 1)
	{
		while (*a != neigh)
			rotate(a, "ra");
		while (*b != elem)
			rev_rotate(b, "rrb");
	}
	else if (elem->move == 1 && neigh->move == 0)
	{
		while (*a != neigh)
			rev_rotate(a, "rra");
		while (*b != elem)
			rotate(b, "rb");
	}
}

int	ft_bigger(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int		best_path(t_list *a, t_list *b, t_list *elem, t_list *neigh)
{
	int	cost_a;
	int	cost_b;

	cost_a = ft_cost(&a, neigh);
	cost_b = ft_cost(&b, elem);
	if (elem->move == 0 && neigh->move == 0)
		return (ft_bigger(cost_a, cost_b));
	else if (elem->move == 1 && neigh->move == 1)
		return (ft_bigger(cost_a, cost_b));
	else
		return (cost_a + cost_b);
}

t_list	*cost_min(t_list *a, t_list *b)
{
	int	min;
	int	cost;
	t_list	*elem;
	t_list	*neigh;

	min = 5000;
	while (b)
	{
		neigh = best_neigh(a, b);
		cost = best_path(a, b, elem, neigh);
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
	if (lst_size(elem) < lst_size(*lst) / 2)
	{
		elem->move = 0;
		return (lst_size(elem));
	}
	else
	{
		elem->move = 1;
		return (lst_size(*lst) - lst_size(elem));
	}
}

t_list	*best_neigh(t_list *a, t_list *b)
{
	t_list	*neigh;
	int		dif;

	dif = 2147483647;
	while (a)
	{
		if (a->value - b->value < dif)
		{
			neigh = a;
			dif = a->value - b->value;
		}
		a = a->next;
	}
	return (neigh);
}