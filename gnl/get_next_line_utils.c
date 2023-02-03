/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:38:45 by rreis-de          #+#    #+#             */
/*   Updated: 2023/02/03 14:15:51 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*new_line;
	int		i;
	int		k;
	int		buf_len;
	int		line_len;

	buf_len = ft_strlen_gnl(buf);
	line_len = ft_strlen_gnl(line);
	new_line = (char *)malloc(buf_len + line_len + 1);
	if (!new_line)
		return (NULL);
	i = -1;
	k = -1;
	while (++i < line_len)
		new_line[i] = line[i];
	while (++k < buf_len)
		new_line[i++] = buf[k];
	new_line[i] = 0;
	free(line);
	return (new_line);
}
