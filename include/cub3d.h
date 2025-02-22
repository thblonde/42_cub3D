#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

# define WIDTH 500
# define HEIGHT 500

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
