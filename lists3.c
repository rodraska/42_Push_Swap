/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:01 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/03 11:46:07 by rreis-de         ###   ########.fr       */
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

int	lst_size(t_list *lst)
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

int	lst_duplicate(t_list *lst, int n)
{
	while (lst)
	{
		if (lst->value == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}