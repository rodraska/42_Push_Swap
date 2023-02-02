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
		elem = cost_min(*a, *b);
		neigh = best_neigh(*a, elem);
		ft_rotate(a, b, elem, neigh);
		push(b, a, "pa");
	}
	min_top(a);
}

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

	cost_b = ft_cost(&b, elem);
	cost_a = ft_cost(&a, neigh);
	//ft_printf("elem move: %d\n", elem->move);
	//ft_printf("neigh move: %d\n", neigh->move);
	//ft_printf("cost_b: %d\n", cost_b);
	//ft_printf("cost_a: %d\n", cost_a);
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
		cost = best_path(a, b, b, neigh);
		//ft_printf("cost: %d\n", cost);
		if (cost < min)
		{
			min = cost;
			elem = b;
			//ft_printf("elem: %d\n", elem->value);
		}
		b = b->next;
	}
	return (elem);
}

int	ft_cost(t_list **lst, t_list *elem)
{
	//ft_printf("size elem: %d\n", lst_size(elem));
	//ft_printf("size list: %d\n", lst_size(lstfirst(*lst)));
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

t_list	*best_neigh(t_list *a, t_list *b)
{
	t_list	*neigh;
	int		dif;

	dif = 2147483647;
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