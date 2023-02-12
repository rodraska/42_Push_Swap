/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:35:08 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/06 18:08:34 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ps/push_swap.h"
# include "../gnl/get_next_line.h"

void	read_moves(t_list **a, t_list **b);
void	checker_moves(t_list **a, t_list **b, char *move);
void	checker_swap(t_list *lst);
void	checker_push(t_list **src, t_list **dst);
void	checker_rotate(t_list **a, t_list **b);
void	checker_rev_rotate(t_list **a, t_list **b);
int     check_read(char *s);

#endif