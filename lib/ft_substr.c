/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblonde <thblonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:17:04 by thblonde          #+#    #+#             */
/*   Updated: 2025/02/15 16:17:05 by thblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		new_ptr = (char *) malloc((sizeof(char)));
	else if (len < (ft_strlen(s) - start))
		new_ptr = (char *) malloc((sizeof(char) * (len + 1)));
	else
		new_ptr = (char *) malloc((sizeof(char)
					* ((ft_strlen(s) - start) + 1)));
	if (!new_ptr)
		return (NULL);
	while (i < len && j < ft_strlen(s))
		new_ptr[i++] = s[j++];
	new_ptr[i] = '\0';
	return (new_ptr);
}