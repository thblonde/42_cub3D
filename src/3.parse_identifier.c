/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.parse_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:44:53 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/18 19:44:54 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_count_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	if (count < 2)
		return (msg("identifier missing something"), FAILURE);
	else if (count > 2)
		return (msg("too much info for identifier"), FAILURE);
	return (SUCCESS);
}

static int	ft_put_identifier_in_struct_two(t_game *game, char **tab, char c)
{
	if (c == 'E')
	{
		game->ea = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
		if (!game->ea)
			return (msg("malloc game->ea"), FAILURE);
	}
	else if (c == 'C')
	{
		game->c = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
		if (!game->c)
			return (msg("malloc game->c"), FAILURE);
		if (ft_check_rgb(game->c))
			return (FAILURE);
	}
	else if (c == 'F')
	{
		game->f = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
		if (!game->f)
			return (msg("malloc game->f"), FAILURE);
		if (ft_check_rgb(game->f))
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	ft_put_identifier_in_struct(t_game *game, char **tab, char c)
{
	if (ft_count_tab(tab))
		return (FAILURE);
	game->count_identifier++;
	if (c == 'N')
	{
		game->no = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
		if (!game->no)
			return (msg("malloc game->no"), FAILURE);
	}
	else if (c == 'S')
	{
		game->so = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
		if (!game->so)
			return (msg("malloc game->so"), FAILURE);
	}
	else if (c == 'W')
	{
		game->we = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
		if (!game->we)
			return (msg("malloc game->we"), FAILURE);
	}
	else if (ft_put_identifier_in_struct_two(game, tab, c))
		return (FAILURE);
	return (SUCCESS);
}

static int	ft_check_identifier_two(t_game *game, t_id *id, char **tab, int i)
{
	if (!ft_strncmp(tab[0], "C", 1) && ft_count_id(id, 'C'))
	{
		if (ft_put_identifier_in_struct(game, tab, 'C'))
			return (FAILURE);
	}
	else if (!ft_strncmp(tab[0], "F", 1) && ft_count_id(id, 'F'))
	{
		if (ft_put_identifier_in_struct(game, tab, 'F'))
			return (FAILURE);
	}
	else
	{
		if (id->total != 6 || id->no > 1 || id->so > 1 || id->we > 1
			|| id->ea > 1 || id->c > 1 || id->f > 1)
			return (msg("needs to have 6 identifiers"), FAILURE);
		game->map_line = i;
	}
	return (SUCCESS);
}

int	ft_check_identifier(t_game *game, t_id *id, char **tab, int i)
{
	if (!ft_strncmp(tab[0], "NO", 2) && ft_count_id(id, 'N'))
	{
		if (ft_put_identifier_in_struct(game, tab, 'N'))
			return (FAILURE);
	}
	else if (!ft_strncmp(tab[0], "SO", 2) && ft_count_id(id, 'S'))
	{
		if (ft_put_identifier_in_struct(game, tab, 'S'))
			return (FAILURE);
	}
	else if (!ft_strncmp(tab[0], "WE", 2) && ft_count_id(id, 'W'))
	{
		if (ft_put_identifier_in_struct(game, tab, 'W'))
			return (FAILURE);
	}
	else if (!ft_strncmp(tab[0], "EA", 2) && ft_count_id(id, 'E'))
	{
		if (ft_put_identifier_in_struct(game, tab, 'E'))
			return (FAILURE);
	}
	else if (ft_check_identifier_two(game, id, tab, i))
		return (FAILURE);
	return (SUCCESS);
}
