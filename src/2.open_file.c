/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.open_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:31:58 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/17 16:32:00 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_count_line_file(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->av_one, O_RDONLY);
	if (fd < 1)
		return (msg("file did not open"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->len_file++;
		free(line);
	}
	close (fd);
	if (game->len_file == 0)
		return (msg("nothing in the file"), FAILURE);
	return (SUCCESS);
}

static int	ft_check_line(t_game *game, t_id *id, char *line, int i)
{
	if (game->map_line == -1)
	{
		if (ft_check_line_two(game, id, line, i))
			return (FAILURE);
	}
	else
	{
		if (ft_put_map_in_file(game, line, i))
			return (ft_free_file(game, i), FAILURE);
	}
	return (SUCCESS);
}

static int	ft_parse_file(t_game *game)
{
	t_id	id;
	int		fd;
	int		i;
	char	*line;

	ft_init_id(&id);
	fd = open(game->av_one, O_RDONLY);
	if (fd < 1)
		return (msg("file did not open"), FAILURE);
	i = 0;
	while (i < game->len_file)
	{
		line = get_next_line(fd);
		if (!line)
			return (close (fd), ft_free_file(game, i),
				msg("problem with get_next_line"), FAILURE);
		if (ft_check_line(game, &id, line, i))
			return (close (fd), ft_free_file(game, i), FAILURE);//verif avec valgrind le free(line)
		i++;
	}
	return (close (fd), SUCCESS);
}

static int	ft_get_map(t_game *game, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < game->map_line)
	{
		line = get_next_line(fd);
		if (!line)
			return (close (fd), ft_free_map(game, 0),
				msg("problem with get_next_line"), FAILURE);
		free(line);
	}
	j = 0;
	while (i < game->len_file)
	{
		line = get_next_line(fd);
		if (!line)
			return (close (fd), ft_free_map(game, j),
				msg("problem with get_next_line"), FAILURE);
		game->map[j] = line;
		j++;
		i++;
	}
	return (close (fd), SUCCESS);
}

int	ft_open_file(t_game *game)
{
	int	fd;

	if (ft_count_line_file(game))
		return (FAILURE);
	game->file = malloc(sizeof(char *) * (game->len_file + 2));
	if (!game->file)
		return (msg("malloc with game->file"), FAILURE);
	if (ft_parse_file(game))
		return (ft_free_single(game), FAILURE);
	if (ft_parse_map(game))
		return (ft_free_single(game), ft_free_file(game, -42), FAILURE);
	game->x--;
	game->y = game->y - game->map_line;
	ft_free_file(game, -42);
	game->map = malloc(sizeof(char *)
			* ((game->len_file - game->map_line) + 1));
	if (!game->map)
		return (ft_free_single(game), msg("malloc with game->map"), FAILURE);
	fd = open(game->av_one, O_RDONLY);
	if (fd < 1)
		return (ft_free_map(game, 0), ft_free_single(game),
			msg("file did not open"), FAILURE);
	if (ft_get_map(game, fd))
		return (ft_free_single(game), FAILURE);
	return (SUCCESS);
}
