/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:22:35 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/04 17:50:47 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (lst_duplicate(lst, num))
			return (NULL);
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

	if (ac == 1)
		return (0);
	a = check_error(ac, av);
	//lst_print(a);
	b = NULL;
	if (a == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	read_moves(&a, &b);
	//ft_printf("====================\n");
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
