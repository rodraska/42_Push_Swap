/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:44:59 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/06 17:57:16 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_moves(t_list **a, t_list **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		checker_moves(a, b, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (check_order(*a, *b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

