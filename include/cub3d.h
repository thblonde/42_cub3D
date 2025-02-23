/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblonde <thblonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:17:41 by matcoppo          #+#    #+#             */
/*   Updated: 2025/02/15 16:37:26 by thblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/lib.h"
# include "../lib/mlx/mlx.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct s_game
{
	char	*av_one;
	char	**file;
	char	**map;
	int		len_file;
	int		count_identifier;
	int		map_line;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	char	player;
	int		x;
	int		y;
}			t_game;

typedef struct s_id
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		c;
	int		f;
	int		total;
}			t_id;

/* FT FREE */
void	msg(char *str);
void	ft_free_file(t_game *game, int i);
void	ft_free_map(t_game *game, int j);
void	ft_free_tab(char **tab);
void	ft_free_single(t_game *game);

/* UTILS PARSING */
void	ft_init_id(t_id *id);
int		ft_count_id(t_id *id, char c);
int		ft_check_rgb(char *line);
int		ft_is_it_map(char c);
int		ft_is_it_player(t_game *game, char c);

/* OPEN FILE */
int		ft_open_file(t_game *game);

/* PARSE IDENTIFIER */
int		ft_check_identifier(t_game *game, t_id *id, char **tab, int i);

/* MAP IN FILE */
int		ft_check_line_two(t_game *game, t_id *id, char *line, int i);
int		ft_put_map_in_file(t_game *game, char *line, int i);

/* PARSE MAP */
int		ft_parse_map(t_game *game);

#endif
