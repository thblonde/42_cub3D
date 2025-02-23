/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.map_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:06 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/20 19:33:10 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_line_two(t_game *game, t_id *id, char *line, int i)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (msg("problem with the ft_split"), FAILURE);
	if (!ft_strncmp(tab[0], "\n", 1))
	{
		game->file[i] = line;
		return (ft_free_tab(tab), SUCCESS);
	}
	if (ft_check_identifier(game, id, tab, i))
		return (ft_free_tab(tab), FAILURE);
	if (game->map_line == -1)
		game->file[i] = line;
	else
	{
		if (ft_put_map_in_file(game, line, i))
			return (ft_free_tab(tab), ft_free_file(game, i), FAILURE);
	}
	ft_free_tab(tab);
	return (SUCCESS);
}

static int	ft_put_last_line(t_game *game, int i, int max_line)
{
	int	j;

	game->file[i] = malloc(sizeof(char *) * max_line + 1);
	if (!game->file[i])
		return (msg("problem with malloc last line of file"), FAILURE);
	j = 0;
	while (j < max_line)
		game->file[i][j++] = ' ';
	game->file[i][j] = '\0';
	return (SUCCESS);
}

int	ft_put_map_in_file(t_game *game, char *line, int i)
{
	static int	max_line;
	int			j;
	char		*ptr;

	ptr = ft_strjoin(" ", line);
	if (!ptr)
		return (msg("problem with ft_strjoin"), FAILURE);
	j = 0;
	while (ptr[j])
		j++;
	if (j > max_line)
		max_line = j;
	if (i + 1 == game->len_file)
	{
		game->file[i] = ptr;
		i++;
		if (ft_put_last_line(game, i, max_line))
			return (FAILURE);
	}
	else
		game->file[i] = ptr;
	return (SUCCESS);
}
