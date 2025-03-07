#include "cub3d.h"

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100000000000001";
	map[2] = "100000000000001";
	map[3] = "100000100000001";
	map[4] = "10000000N000001";
	map[5] = "100000010000001";
	map[6] = "100001000000001";
	map[7] = "100000000000001";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = NULL;
	return (map);
}

void	player_init(t_player *player)
{
	player->x = 8;
	player->y = 4;
	player->angle = M_PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->key_left_arrow = false;
	player->key_right_arrow = false;
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (FAILURE);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		return (FAILURE);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return (FAILURE);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!game->addr)
		return (FAILURE);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	game->map = get_map();
	player_init(&game->player);
	return (SUCCESS);
}

int	main(void)
{
	t_game	game;

	if (game_init(&game))
		return (FAILURE);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (SUCCESS);
}
