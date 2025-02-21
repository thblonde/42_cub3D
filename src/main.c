#include "cub3d.h"

void	fast_put_pixel(t_game *game, int x, int y, int color)
{
	int	offset;

	offset = y * game->line_length + x * (game->bits_per_pixel / 8);
	game->addr[offset] = color & 0xFF;
	game->addr[offset + 1] = (color >> 8) & 0xFF;
	game->addr[offset + 2] = (color >> 16) & 0xFF;
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		return (0);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return (0);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	if (!game->addr)
		return (0);
	return (1);
}

int	main()
{
	t_game	game;

	if (!game_init(&game))
		return (1);
	fast_put_pixel(&game, WIDTH/2, HEIGHT/2, 0x00FF00);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}

