#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/lib.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1200
# define HEIGHT 800
# define TILE 64
# define SUCCESS 0
# define FAILURE 1

// Macos
// # define W 115
// # define S 119
// # define A 100
// # define D 97
// # define LEFT_ARROW 65363
// # define RIGHT_ARROW 65361

// Linux
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	bool		key_left_arrow;
	bool		key_right_arrow;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player	player;
	char		**map;
}				t_game;

/* draw */
int				draw_loop(t_game *game);
void			my_pixel_put(t_game *game, float x, float y, int color);

/* player */
void			player_move(t_player *player);
int				key_press(int keycode, t_player *player);
int				key_release(int keycode, t_player *player);

/* raycast */

#endif
