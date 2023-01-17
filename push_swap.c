/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:16:03 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/17 13:42:34 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*check_error(int ac, char **av)
{
	int		i;
	int		j;
	long	num;
	t_list	*lst;

	i = 0;
	lst = NULL;
	while (++i < ac)
	{
		j = -1;
		num = ft_atoi(av[i]);
		while (av[i][++j])
		{
			if (num == 0 && (av[i][0] != 48 || av[i][1]))
			return (NULL);
			if (num > 2147483647 || num < -2147483648)
				return (NULL);
		}
		lst_add_back(&lst, num);
	}
	return (lst);
}

long int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	num *= sign;
	return (num);
}

int main(int ac, char **av)
{
	t_list *a;
	t_list *b;

	if (ac == 1)
		return (0);
	a = check_error(ac, av);
	b = NULL;
	if (a == NULL)
		printf("ERROR\n");
	swap(a);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	rotate(&a);
	rotate(&b);
	rev_rotate(&a);
	rev_rotate(&b);
	swap(a);
	push(&b, &a);
	push(&b, &a);
	push(&b, &a);
	while (a != NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("\n");
	while (b != NULL)
	{
		printf("%d\n", b->value);
		b = b->next;
	}
	return (0);
}