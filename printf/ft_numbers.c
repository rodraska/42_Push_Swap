/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:02:32 by rreis-de          #+#    #+#             */
/*   Updated: 2022/11/04 16:38:02 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_d(int n, int *ptl)
{
	char	*s;

	s = ft_itoa(n);
	(*ptl) += ft_strlen(s);
	ft_putnbr_fd(n, 1);
	free(s);
}

void	ft_printf_u(unsigned int n, int *ptl)
{
	if (n >= 0)
		ft_itoa_base(n, "0123456789", ptl);
	else if (n < 0)
		ft_itoa_base(4294967296 - n, "0123456789", ptl);
}

void	ft_itoa_base(unsigned long int n, char *base, int *ptl)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (n >= size)
		ft_itoa_base(n / size, base, ptl);
	ft_putchar_fd(base[n % size], 1);
	(*ptl)++;
}
