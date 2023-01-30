/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:39:45 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/30 15:48:52 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int				ft_printf(const char *placeholders, ...);
void			ft_printf_c(int c, int *ptl);
void			ft_printf_s(char *s, int *ptl);
void			ft_printf_d(int n, int *ptl);
void			ft_printf_u(unsigned int n, int *ptl);
void			ft_printf_p(unsigned long int n, int *ptl);
void			ft_itoa_base(unsigned long int n, char *base, int *ptl);

unsigned int	nb_size(long int n);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *str);

#endif