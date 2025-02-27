#include "cub3d.h"

void	my_pixel_put(t_game *game, int x, int y, int color)
{
	int	offset;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	offset = y * game->line_length + x * (game->bits_per_pixel / 8);
	game->addr[offset] = color & 0xFF;
	game->addr[offset + 1] = (color >> 8) & 0xFF;
	game->addr[offset + 2] = (color >> 16) & 0xFF;
}

void	draw_square(t_game *game, int x, int y, int color, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		my_pixel_put(game, x + i, y, color);
	i = -1;
	while (++i < size)
		my_pixel_put(game, x + i, y + size, color);
	i = -1;
	while (++i < size)
		my_pixel_put(game, x, y + i, color);
	i = -1;
	while (++i < size)
		my_pixel_put(game, x + size, y + i, color);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	char	**map;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(game, x * TILE, y * TILE, 0xfaf0e6, TILE);
			x++;
		}
		y++;
	}
}

void	clean_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(game, x, y, 0x0);
			x++;
		}
		y++;
	}
}

int	draw_loop(t_game *game)
{
    t_player    *player;

    player = &game->player;
    player_move(player);
    clean_image(game);
	draw_square(game, game->player.x, game->player.y, 0xe6e6fa, TILE);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (SUCCESS);
}
