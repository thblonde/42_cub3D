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
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 2000
# define HEIGHT 1500 

// Linux
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define SUCCESS 0
# define FAILURE 1


typedef struct s_player
{
	int			player_x;
	int			player_y;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
}             t_player;

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
  void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
  t_player playr;
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

/* INIT */ 
int   game_init(t_game *game);

/* DRAW */ 
void  fast_pixel_put(t_game *game, int x, int y, int color);
void  print_square(t_game *game, int x, int y, int color, int size);
int   print_loop(t_game *game);

/* MOVE */ 
void  move_player (t_player *player, t_game *game);
int   keypress(int keycode, t_player *player);
int   keyrelease(int keycode, t_player *player);
void  clear_image(t_game *game);

#endif
