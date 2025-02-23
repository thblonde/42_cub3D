#include "../include/cub3d.h"

int	game_init(t_game *game)
{
	game->playr.player_x = WIDTH / 2;
	game->playr.player_y = HEIGHT / 2;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		return (0);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return (0);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!game->addr)
		return (0);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (1);
}

