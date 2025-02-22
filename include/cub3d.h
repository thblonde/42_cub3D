#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

# define WIDTH 500
# define HEIGHT 500

# define PI 3.14159265359

// Linux
# define W 119 
# define S 115
# define A 97
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

// Macos
//# define W 13
//# define S 1
//# define A 0
//# define D 2
//# define ESC 53

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_game;

#endif
