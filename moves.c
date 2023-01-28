/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:49:55 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/28 17:43:46 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst)
{
	int		tmp;

	tmp = lst->value;
	lst->value = lst->next->value;
	lst->next->value = tmp;
	printf("swap\n");
}

void	push(t_list **src, t_list **dst)
{	
	t_list	*tmp;

	tmp = *src;
	if (tmp->next)
	{
		*src = tmp->next;
		(*src)->previous = NULL;
	}
	else
		*src = NULL;
	tmp->next = *dst;
	tmp->previous = NULL;
	if (*dst)
		(*dst)->previous = tmp;
	*dst = tmp;
	printf("push\n");
}

void	rotate(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;

	tmp = (*lst)->next;
	last = lstlast(*lst);
	last->next = *lst;
	(*lst)->previous = last;
	(*lst)->next = NULL;
	tmp->previous = NULL;
	*lst = tmp;
	printf("rotate\n");
}

void	rev_rotate(t_list **lst)
{
	t_list	*last;

	last = lstlast(*lst);
	last->previous->next = NULL;
	last->next = *lst;
	last->previous = NULL;
	(*lst)->previous = last;
	*lst = last;
	printf("rev rotate\n");
}