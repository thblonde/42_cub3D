#include "cub3d.h"

void	fast_pixel_put(t_game *game, int x, int y, int color)
{
	int	offset;

	offset = y * game->line_length + x * (game->bits_per_pixel / 8);
	game->addr[offset] = color & 0xFF;
	game->addr[offset + 1] = (color >> 8) & 0xFF;
	game->addr[offset + 2] = (color >> 16) & 0xFF;
}

int	game_init(t_game *game)
{
	game->player.player_x = WIDTH / 2;
	game->player.player_y = HEIGHT / 2;
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

void	print_square(t_game *game, int x, int y, int color, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		fast_pixel_put(game, x + i, y, color);
	i = -1;
	while (++i < size)
		fast_pixel_put(game, x + i, y + size, color);
	i = -1;
	while (++i < size)
		fast_pixel_put(game, x, y + i, color);
	i = -1;
	while (++i < size)
		fast_pixel_put(game, x + size, y + i, color);
}

int	keypress(int keycode, t_player *player)
{
	player->keypress.key_up = false;
	player->keypress.key_down = false;
	player->keypress.key_left = false;
	player->keypress.key_right = false;
	if (keycode == W)
		player->keypress.key_up = true;
	if (keycode == S)
		player->keypress.key_down = true;
	if (keycode == A)
		player->keypress.key_left = true;
	if (keycode == D)
		player->keypress.key_right = true;
	return (0);
}

int	keyrelease(int keycode, t_player *player)
{
	if (keycode == W)
		player->keypress.key_up = false;
	if (keycode == S)
		player->keypress.key_down = false;
	if (keycode == A)
		player->keypress.key_left = false;
	if (keycode == D)
		player->keypress.key_right = false;
	return (0);
}

void	move_player(t_player *player)
{
	if (player->keypress.key_up)
		player->player_y -= 5;
	if (player->keypress.key_down)
		player->player_y += 5;
	if (player->keypress.key_left)
		player->player_x -= 5;
	if (player->keypress.key_right)
		player->player_x += 5;
}

void	clear_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fast_pixel_put(game, x, y, 0);
			x++;
		}
		y++;
	}
}

int	print_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
	move_player(player);
	clear_img(game);
	print_square(game, player->player_x, player->player_y, 0xfaf0e6, 20);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;

	if (!game_init(&game))
		return (1);
	mlx_hook(game.win, 2, 1L << 0, keypress, &game.player);
	mlx_hook(game.win, 3, 1L << 1, keyrelease, &game.player);
	mlx_loop_hook(game.mlx, print_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
