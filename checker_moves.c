/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:48:15 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/03 15:53:35 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    checker_moves(t_list **a, t_list **b, char *move)
{
    if (move[0] == 's' && move[1] == 'a')
        checker_swap(a);
    else if (move[0] == 's' && move[1] == 'b')
        checker_swap(b);
    else if (move[0] == 'p' && move[1] == 'a')
        checker_push(b, a);
    else if (move[0] == 'p' && move[1] == 'b')
        checker_push(a, b);
    else if (move[0] == 'r' && move[1] == 'a')
        checker_rotate(a, NULL);
    else if (move[0] == 'r' && move[1] == 'b')
        checker_rotate(NULL, b);
    else if (move[1] == 'r' && !move[2])
        checker_rotate(a, b);
    else if (move[0] == 'r' && move[2] == 'a')
        cheker_rev_rotate(a, NULL);
    else if (move[0] == 'r' && move[2] == 'b')
        cheker_rev_rotate(NULL, b);
    else if (move[0] == 'r' && move[2] == 'r')
        cheker_rev_rotate(a, b);
}

void    checker_swap(t_list **lst)
{
    int		tmp;

	tmp = lst->value;
	lst->value = lst->next->value;
	lst->next->value = tmp;
}

void    checker_push(t_list **src, t_list **dst)
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
}

void    checker_rotate(t_list **a, t_list **b)
{
    t_list	*last;
	t_list	*tmp;

    if(a)
    {
        tmp = (*a)->next;
	    last = lstlast(*a);
	    last->next = *a;
	    (*a)->previous = last;
	    (*a)->next = NULL;
	    *a = tmp;
	    (*a)->previous = NULL;
    }
    if(b)
    {
        tmp = (*b)->next;
	    last = lstlast(*b);
	    last->next = *b;
	    (*b)->previous = last;
	    (*b)->next = NULL;
	    *b = tmp;
	    (*b)->previous = NULL;
    }
}

void    checker_rev_rotate(t_list **a, t_list **b)
{
    t_list	*last;

    if(a)
    {
        last = lstlast(*a);
	    if (last->previous)
		    last->previous->next = NULL;
	    last->next = *a;
	    last->previous = NULL;
	    (*a)->previous = last;
	    *a = last;
    }
    if (b)
    {
        last = lstlast(*b);
	    if (last->previous)
		    last->previous->next = NULL;
	    last->next = *b;
	    last->previous = NULL;
	    (*b)->previous = last;
	    *b = last;
    }
}