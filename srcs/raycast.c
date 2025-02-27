#include "cub3d.h"

void	draw_line(t_game *game, int x, int y, int ray_end_x, int ray_end_y)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(ray_end_x - x);
	dy = abs(ray_end_y - y);
	sx = x < ray_end_x ? 1 : -1;
	sy = y < ray_end_y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		my_pixel_put(game, x, y, 0xff0000);
		if (x == ray_end_x && y == ray_end_y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y += sy;
		}
	}
}

int	raycast(t_game *game)
{
	int			ray_dir_x;
	int			ray_dir_y;
	int			ray_end_x;
	int			ray_end_y;
	int			ray_len;
	t_player	*player;
	float		angle_rad;

	player = &game->player;
	angle_rad = (float)player->angle * (PI / 180.0f);
	ray_dir_x = (int)(cosf(angle_rad) * 1000);
	ray_dir_y = (int)(sinf(angle_rad) * 1000);
	ray_len = 200;
	ray_end_x = player->x * TILE + (ray_dir_x * ray_len);
	ray_end_y = player->y * TILE + (ray_dir_y * ray_len) ;
	draw_line(game, (player->x * TILE) + TILE / 2, player->y * TILE, ray_end_x, ray_end_y);
	return (SUCCESS);
}
