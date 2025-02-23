/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.utils_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcoppo <matcoppo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:35:07 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/20 18:35:09 by matcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_id(t_id *id)
{
	id->no = 0;
	id->so = 0;
	id->we = 0;
	id->ea = 0;
	id->c = 0;
	id->f = 0;
	id->total = 0;
	return ;
}

int	ft_count_id(t_id *id, char c)
{
	if (c == 'N')
		id->no++;
	else if (c == 'S')
		id->so++;
	else if (c == 'W')
		id->we++;
	else if (c == 'E')
		id->ea++;
	else if (c == 'C')
		id->c++;
	else if (c == 'F')
		id->f++;
	if (id->no > 1 || id->so > 1 || id->we > 1
		|| id->ea > 1 || id->c > 1 || id->f > 1)
		return (0);
	id->total++;
	return (1);
}

int	ft_check_rgb(char *line)
{
	char	**tab;
	int		i;
	int		nbr;

	tab = ft_split(line, ',');
	if (!tab)
		return (msg("problem with the ft_split"), FAILURE);
	i = 0;
	nbr = -1;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]))
			return (ft_free_tab(tab),
				msg("only digit positive numbers for RGB"), FAILURE);
		nbr = ft_atoi(tab[i]);
		if (nbr < 0 || nbr > 255)
			return (ft_free_tab(tab),
				msg("only nbr between 0 and 255"), FAILURE);
		i++;
	}
	ft_free_tab(tab);
	return (SUCCESS);
}

int	ft_is_it_map(char c)
{
	if (c == 32 || c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (SUCCESS);
	return (FAILURE);
}

int	ft_is_it_player(t_game *game, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		game->player = c;
		return (SUCCESS);
	}
	return (FAILURE);
}
