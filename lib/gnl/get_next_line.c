/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:18:07 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/24 13:23:02 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	ft_free_for_gnl(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((size != 0 && ((count * size) / size != count)) || (size >= 2147483647
			&& count >= 2147483647))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*read_the_file(int fd, char *the_stc)
{
	char	*buf;
	int		readed;

	buf = ft_calloc(1, (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_for_gnl(&the_stc), NULL);
	readed = 1;
	while (!question_is_it_the_new_line(buf, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			ft_free_for_gnl(&buf);
			return (NULL);
		}
		buf[readed] = '\0';
		the_stc = join_the_buf_to_new_string(the_stc, buf);
	}
	ft_free_for_gnl(&buf);
	return (the_stc);
}

char	*get_next_line(int fd)
{
	static char	*the_stc;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read(fd, 0, 0) < 0)
		return (ft_free_for_gnl(&the_stc), NULL);
	the_stc = read_the_file(fd, the_stc);
	if (!the_stc)
		return (NULL);
	line = recuparation_of_the_line(the_stc);
	the_stc = recuparation_of_the_rest_of_the_line(the_stc);
	if (!question_is_it_the_new_line(line, '\n'))
		ft_free_for_gnl(&the_stc);
	return (line);
}
