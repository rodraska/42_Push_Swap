/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:10:44 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/30 16:02:22 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_data_type(char data_type, va_list args, int *ptl)
{
	if (data_type == 'c')
		ft_printf_c(va_arg(args, int), ptl);
	else if (data_type == 's')
		ft_printf_s(va_arg(args, char *), ptl);
	else if (data_type == 'p')
		ft_printf_p(va_arg(args, long unsigned int), ptl);
	else if (data_type == 'd' || data_type == 'i')
		ft_printf_d(va_arg(args, int), ptl);
	else if (data_type == 'u')
		ft_printf_u(va_arg(args, long unsigned int), ptl);
	else if (data_type == 'x')
		ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef", ptl);
	else if (data_type == 'X')
		ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF", ptl);
	else if (data_type == '%')
	{
		ft_putchar_fd('%', 1);
		(*ptl)++;
	}
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	data_type;

	va_start(args, placeholders);
	i = 0;
	len = 0;
	while (placeholders[i])
	{
		if (placeholders[i] == '%')
		{
			data_type = placeholders[i + 1];
			ft_data_type(data_type, args, &len);
			i++;
		}
		else
		{
			write(1, &placeholders[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	printf("%x\n", -1);
	ft_printf("%x\n", -1);
	return (0);
} */