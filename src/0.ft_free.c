/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.ft_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:31:52 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/17 16:31:54 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	msg(char *str)
{
	printf("Error\n");
	if (str)
		printf("%s\n", str);
	return ;
}

void	ft_free_file(t_game *game, int i)
{
	int	j;

	if (i == -42)
	{
		j = -1;
		while (++j < game->len_file)
			free(game->file[j]);
		free(game->file);
		printf("\033[0;32mthe all file freed\033[0m\n");
	}
	else
	{
		j = i;
		while (j > 0)
		{
			j--;
			free(game->file[j]);
		}
		free(game->file);
		printf("\033[0;32mfile freed\033[0m\n");
	}
	return ;
}

void	ft_free_map(t_game *game, int j)
{
	int	i;

	if (j == -42)
	{
		i = -1;
		while (++i < game->len_file - game->map_line)
			free(game->map[i]);
		free(game->map);
		printf("\033[0;32mthe all map freed\033[0m\n");
	}
	else
	{
		i = j;
		while (i > 0)
		{
			i--;
			free(game->map[i]);
		}
		free(game->map);
		printf("\033[0;32mmap freed\033[0m\n");
	}
	return ;
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	ft_free_single(t_game *game)
{
	if (game->no)
		free(game->no);
	if (game->so)
		free(game->so);
	if (game->we)
		free(game->we);
	if (game->ea)
		free(game->ea);
	if (game->c)
		free(game->c);
	if (game->f)
		free(game->f);
	printf("\033[0;32msingle freed\033[0m\n");
	return ;
}
