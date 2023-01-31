/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:49:55 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/31 19:04:59 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst, char *id)
{
	int		tmp;

	tmp = lst->value;
	lst->value = lst->next->value;
	lst->next->value = tmp;
	ft_printf("%s\n", id);
}

void	push(t_list **src, t_list **dst, char *id)
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
	ft_printf("%s\n", id);
}

void	rotate(t_list **lst, char *id)
{
	t_list	*last;
	t_list	*tmp;

	tmp = (*lst)->next;
	last = lstlast(*lst);
	last->next = *lst;
	(*lst)->previous = last;
	(*lst)->next = NULL;
	*lst = tmp;
	(*lst)->previous = NULL;
	ft_printf("%s", id);
	ft_printf("\n");
}

void	rev_rotate(t_list **lst, char *id)
{
	t_list	*last;
	
	last = lstlast(*lst);
	if (last->previous)
		last->previous->next = NULL;
	last->next = *lst;
	last->previous = NULL;
	(*lst)->previous = last;
	*lst = last;
	ft_printf("%s", id);
	ft_printf("\n");
}