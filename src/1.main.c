/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblonde <thblonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:17:50 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/15 16:28:34 by thblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_struct(t_game *game, char *av)
{
	game->av_one = av;
	game->file = NULL;
	game->map = NULL;
	game->len_file = 0;
	game->count_identifier = 0;
	game->map_line = -1;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->c = NULL;
	game->f = NULL;
	game->player = 0;
	game->x = -1;
	game->y = -1;
	return ;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (msg("it has to be one arguments only"), FAILURE);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		return (msg("file not correctly formated"), FAILURE);
	ft_init_struct(&game, av[1]);
	if (ft_open_file(&game))
		return (FAILURE);
	//(exec)
	//return (ft_free_map(&game, -42), ft_free_single(&game), FAILURE);
	ft_free_map(&game, -42);
	ft_free_single(&game);
	return (SUCCESS);
}
