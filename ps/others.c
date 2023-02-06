/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:06:50 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/06 16:29:27 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_rotating(t_list **a, t_list **b, t_list *elem, t_list *neigh)
{
	while (*a != neigh && *b != elem)
	{
		rotate(a, "rr");
		rotate(b, NULL);
	}
	while (*a != neigh)
		rotate(a, "ra");
	while (*b != elem)
		rotate(b, "rb");
}

void	keep_rev_rotating(t_list **a, t_list **b, t_list *elem, t_list *neigh)
{
	while (*a != neigh && *b != elem)
	{
		rev_rotate(a, "rrr");
		rev_rotate(b, NULL);
	}
	while (*a != neigh)
		rev_rotate(a, "rra");
	while (*b != elem)
		rev_rotate(b, "rrb");
}

void	keep_rot_rev(t_list **a, t_list **b, t_list *elem, t_list *neigh)
{
	while (*a != neigh)
		rotate(a, "ra");
	while (*b != elem)
		rev_rotate(b, "rrb");
}

void	keep_rev_rot(t_list **a, t_list **b, t_list *elem, t_list *neigh)
{
	while (*a != neigh)
		rev_rotate(a, "rra");
	while (*b != elem)
		rotate(b, "rb");
}
