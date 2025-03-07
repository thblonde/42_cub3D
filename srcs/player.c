#include "cub3d.h"

int	key_press(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT_ARROW)
		player->key_left_arrow = true;
	if (keycode == RIGHT_ARROW)
		player->key_right_arrow = true;
	return (SUCCESS);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT_ARROW)
		player->key_left_arrow = false;
	if (keycode == RIGHT_ARROW)
		player->key_right_arrow = false;
	return (SUCCESS);
}

// void	player_move(t_player *player)
// {
// 	int	pixel_move;

// 	pixel_move = 1;
// 	if (player->key_up)
// 		player->y -= pixel_move;
// 	if (player->key_down)
// 		player->y += pixel_move;
// 	if (player->key_left)
// 		player->x -= pixel_move;
// 	if (player->key_right)
// 		player->x += pixel_move;
// }

void	player_move(t_player *player)
{
	int		pixel_move;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	pixel_move = 1;
	angle_speed = 0.1;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);

	if (player->key_left_arrow)
		player->angle -= angle_speed;
	if (player->key_right_arrow)
		player->angle += angle_speed;
	if (player->angle > 2 * M_PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * M_PI;

	if (player->key_up)
	{
		player->x += cos_angle * pixel_move;
		player->y += sin_angle * pixel_move;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * pixel_move;
		player->y -= sin_angle * pixel_move;
	}
	if (player->key_left)
	{
		player->x += sin_angle * pixel_move;
		player->y -= cos_angle * pixel_move;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * pixel_move;
		player->y += cos_angle * pixel_move;
	}
}
