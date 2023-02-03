/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:33:21 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/12 14:34:31 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];
	int			i;
	int			j;
	int			f;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	f = 0;
	while (!f && (buf[0] || read(fd, buf, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buf);
		i = 0;
		j = 0;
		while (buf[i])
		{
			if (f)
				buf[j++] = buf[i];
			if (buf[i] == 10)
				f = 1;
			buf[i++] = 0;
		}
	}
	return (line);
}

/* int main(void)
{
	int fd = open("manual.txt", O_RDONLY, 00700);
	char    *s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	return (0);
} */