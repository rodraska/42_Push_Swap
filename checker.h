/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:35:08 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/03 15:56:42 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "gnl/get_next_line.h"

typedef struct s_list
{
	int					value;
	struct s_list		*next;
	struct s_list		*previous;
	int					move;
}	t_list;

t_list	*check_error(int ac, char **av);
long	ft_atoi(char *str);

void    read_moves(t_list **a, t_list **b);

void    checker_moves(t_list **a, t_list **b, char *move);
void    checker_swap(t_list **lst);
void    checker_push(t_list **src, t_list **dst);
void    checker_rotate(t_list **a, t_list **b);
void    checker_rev_rotate(t_list **a, t_list **b);

#endif