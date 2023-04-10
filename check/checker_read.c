/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:44:59 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/13 09:06:53 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_read(char *s)
{
	if (s[0] == 's' && (s[1] == 'a' || s[1] == 'b') && s[2] == '\n')
		return (1);
	else if (s[0] == 'p' && (s[1] == 'a' || s[1] == 'b') && s[2] == '\n')
		return (1);
	else if (s[0] == 'r' && (s[1] == 'r' || \
	s[1] == 'a' || s[1] == 'b') && s[2] == '\n')
		return (1);
	else if (s[0] == 'r' && s[1] == 'r' && (s[2] == 'a' \
	|| s[2] == 'b' || s[2] == 'r') && s[3] == '\n')
		return (1);
	return (0);
}

void	read_moves(t_list **a, t_list **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!check_read(move))
		{
			write(2, "Error\n", 6);
			free(move);
			return ;
		}
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
