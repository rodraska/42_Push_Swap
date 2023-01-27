/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:55:51 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/16 10:30:51 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int					value;
	struct s_list		*next;
	struct s_list		*previous;
}	t_list;

t_list	*lstnew(int value);
void	lst_add_front(t_list **lst, int value);
void	lst_add_back(t_list **lst, int value);
t_list	*lstlast(t_list *lst);
void	lst_clear(t_list **lst);
void	lst_iter(t_list *lst);
void	lst_rev_iter(t_list *lst);
t_list	*lst_fill(int a, int b);

void	swap(t_list *lst);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **lst);
void	rev_rotate(t_list **lst);

long int	ft_atoi(char *str);
t_list	*check_error(int ac, char **av);
int		lst_duplicate(t_list *lst, int n);

void    sort_3(t_list **lst);

#endif