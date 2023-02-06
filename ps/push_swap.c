/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:16:03 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/06 16:07:04 by rreis-de         ###   ########.fr       */
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
			if ((num == 0 && (av[i][0] != 48 || av[i][1]))
			|| (num > 2147483647 || num < -2147483648)
			|| (lst_duplicate(lst, num)))
			{
				lst_clear(&lst);
				return (NULL);
			}
		}
		lst_add_back(&lst, num);
	}
	return (lst);
}

long	ft_atoi(char *str)
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

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	if (ac == 1)
		return (0);
	a = check_error(ac, av);
	b = NULL;
	if (a == NULL)
	{
		ft_printf("Error\n");
		lst_clear(&a);
		return (0);
	}
	size = lst_size(a);
	if (size == 3)
		sort_3(&a);
	else if (size == 5)
		sort_5(&a, &b);
	else
		sort(&a, &b);
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
