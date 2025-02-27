/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:18:20 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/24 13:24:21 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	question_is_it_the_new_line(char *buf, int c)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*join_the_buf_to_new_string(char *the_stc, char *buf)
{
	char	*join;
	int		i;
	int		j;

	if (!the_stc)
	{
		the_stc = ft_calloc(1, 1);
		if (!the_stc)
			return (NULL);
		the_stc[0] = '\0';
	}
	join = ft_calloc(1, ((gnl_strlen(the_stc) + gnl_strlen(buf)) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	if (the_stc != NULL)
		while (the_stc[i])
			join[j++] = the_stc[i++];
	i = 0;
	while (buf[i])
		join[j++] = buf[i++];
	join[j] = '\0';
	ft_free_for_gnl(&the_stc);
	return (join);
}

char	*recuparation_of_the_line(char *the_stc)
{
	char	*line;
	int		i;

	i = 0;
	if (!the_stc || !the_stc[i])
		return (NULL);
	while (the_stc[i] != '\n' && the_stc[i])
		i++;
	line = ft_calloc(1, (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (the_stc[i] != '\n' && the_stc[i])
	{
		line[i] = the_stc[i];
		i++;
	}
	if (the_stc[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*recuparation_of_the_rest_of_the_line(char *the_stc)
{
	char	*the_new_static_char;
	int		i;
	int		j;

	i = 0;
	if (!the_stc)
		return (NULL);
	while (the_stc[i] != '\n' && the_stc[i])
		i++;
	if (the_stc[i] == '\n')
		the_new_static_char = ft_calloc(1,
				(gnl_strlen(&the_stc[i]) + 1));
	else
		return (the_stc);
	if (!the_new_static_char)
		return (NULL);
	i++;
	j = 0;
	while (the_stc[i])
		the_new_static_char[j++] = the_stc[i++];
	the_new_static_char[j] = '\0';
	ft_free_for_gnl(&the_stc);
	return (the_new_static_char);
}
