/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:44:58 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/18 19:44:58 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_get_player(t_game *game, int i, int j)
{
	static int	check;

	if (check == 1)
		return (msg("too many players"), FAILURE);
	game->x = j;
	game->y = i;
	check++;
	return (SUCCESS);
}

static int	ft_check_map_and_player_position(t_game *game, int i, int j)
{
	i = game->map_line;
	while (i < game->len_file)
	{
		j = 0;
		while (game->file[i][j] != '\n')
		{
			if (ft_is_it_map(game->file[i][j]))
				return (msg("wrong characters in map"), FAILURE);
			if (!ft_is_it_player(game, game->file[i][j]))
			{
				if (ft_get_player(game, i, j))
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	ft_backtracking(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->len_file + 1
		|| game->file[y][x] == '1' || game->file[y][x] == 'V')
		return (0);
	if (game->file[y][x] != '0' && game->file[y][x] != '1'
		&& game->file[y][x] != 'N' && game->file[y][x] != 'S'
		&& game->file[y][x] != 'E' && game->file[y][x] != 'W')
		return (FAILURE);
	game->file[y][x] = 'V';
	if (ft_backtracking(game, x - 1, y))
		return (FAILURE);
	if (ft_backtracking(game, x + 1, y))
		return (FAILURE);
	if (ft_backtracking(game, x, y - 1))
		return (FAILURE);
	if (ft_backtracking(game, x, y + 1))
		return (FAILURE);
	return (SUCCESS);
}

int	ft_parse_map(t_game *game)
{
	int	i;
	int	j;

	if (ft_check_map_and_player_position(game, i, j))
		return (FAILURE);
	if (game->x == -1 && game->y == -1)
		return (msg("no player found"), FAILURE);
	if (ft_backtracking(game, game->x, game->y))
		return (msg("player's map ain't close by walls"), FAILURE);
	return (SUCCESS);
}
