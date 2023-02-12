/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:55:51 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/10 15:31:54 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../printf/ft_printf.h"

typedef struct s_list
{
	int					value;
	struct s_list		*next;
	struct s_list		*previous;
	int					move;
}	t_list;

void	lst_clear(t_list **lst);
void	lst_add_back(t_list **lst, int value);
void	lst_add_front(t_list **lst, int value);
t_list	*lstnew(int value);
t_list	*lst_max(t_list *lst);
t_list	*lst_min(t_list *lst);
double	lst_average(t_list *lst);
t_list	*lstfirst(t_list *lst);
t_list	*lstlast(t_list *lst);
void	lst_print(t_list *lst);
int		lst_size(t_list *lst);
int		lst_duplicate(t_list *lst, int n);
int		check_order(t_list *a, t_list *b);
double	abs_sub(double a, double b);

void	swap(t_list *lst, char *id);
void	push(t_list **src, t_list **dst, char *id);
void	rotate(t_list **lst, char *id);
void	rev_rotate(t_list **lst, char *id);

void	keep_rotating(t_list **a, t_list **b, t_list *elem, t_list *neigh);
void	keep_rev_rotating(t_list **a, t_list **b, t_list *elem, t_list *neigh);
void	keep_rot_rev(t_list **a, t_list **b, t_list *elem, t_list *neigh);
void	keep_rev_rot(t_list **a, t_list **b, t_list *elem, t_list *neigh);

void	sort_3(t_list **lst);
void	sort_5(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b);
t_list	*cost_min(t_list *a, t_list *b);
int		ft_cost(t_list **lst, t_list *elem);
void	ft_rotate(t_list **a, t_list **b, t_list *elem, t_list *neigh);
int		best_path(t_list *a, t_list *b, t_list *elem, t_list *neigh);
t_list	*best_neigh(t_list *a, t_list *b);
void	min_top(t_list **lst);
int		ft_bigger(int a, int b);

t_list	*check_error(int ac, char **av);
long	ft_atoi(char *str);
void	general_sort(t_list **a, t_list **b);
int		is_digit(char *s);

#endif