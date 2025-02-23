#include "../include/cub3d.h"

int	keypress(int keycode, t_player *player)
{
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	return (0);
}

int	keyrelease(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	return (0);
}

void	move_player(t_player *player, t_game *game)
{
	if (player->key_up)
		player->player_y -= 5;
	if (player->key_down)
		player->player_y += 5;
	if (player->key_left)
		player->player_x -= 5;
	if (player->key_right)
		player->player_x += 5;
}

