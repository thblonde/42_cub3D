/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblonde <thblonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:27:25 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/15 16:11:20 by thblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static char	**ft_we_are_free(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_count_words(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_count_len_word(char **s, char c, size_t *len)
{
	size_t	i;

	*s += *len;
	*len = 0;
	i = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[i])
	{
		if ((*s)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**ptr;
	char	*word;
	size_t	word_len;

	if (!s)
		return (NULL);
	ptr = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	word = (char *) s;
	word_len = 0;
	while (i < ft_count_words(s, c))
	{
		ft_count_len_word(&word, c, &word_len);
		ptr[i] = (char *) malloc(sizeof(char) * (word_len + 1));
		if (!ptr[i])
			return (ptr = (char **)ft_we_are_free(ptr));
		ft_strlcpy(ptr[i], word, word_len + 1);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
