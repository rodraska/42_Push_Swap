/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:04:22 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/04 15:32:30 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(int c, int *ptl)
{
	ft_putchar_fd(c, 1);
	(*ptl)++;
}

void	ft_printf_s(char *s, int *ptl)
{	
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		(*ptl) += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		(*ptl) += ft_strlen(s);
	}
}

void	ft_printf_p(unsigned long int n, int *ptl)
{
	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		(*ptl) += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		(*ptl) += 2;
		ft_itoa_base(n, "0123456789abcdef", ptl);
	}
}
