#include "cub3d.h"

void	my_pixel_put(t_game *game, float x, float y, int color)
{
	int	offset;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	offset = (int)y * game->line_length + (int)x * (game->bits_per_pixel / 8);
	game->addr[offset] = color & 0xFF;
	game->addr[offset + 1] = (color >> 8) & 0xFF;
	game->addr[offset + 2] = (color >> 16) & 0xFF;
	game->addr[offset + 3] = (color >> 24) & 0xFF;
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

void	draw_player(t_game *game, int x, int y, int color, int size)
{
	for (int i = 0; i < size; i++)
    	for (int j = 0; j < size; j++)
        	my_pixel_put(game, x + i, y + j, color);
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

bool	wall_detection(t_game *game, float px, float py)
{
	int	x;
	int	y;

	x = px / TILE;
	y = py / TILE;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return (true);
	return (game->map[y][x] == '1');
}

int	draw_loop(t_game *game)
{
    t_player	*player;
	float		ray_x;
	float		ray_y;
	float		start_angle;
	float		angle_step;
	float 		ray_angle;
	float		cos_angle;
	float		sin_angle;
	int			i;

    player = &game->player;
    player_move(player);
    clean_image(game);
	//draw_player(game, game->player.x * TILE, game->player.y * TILE, 0xfffafa, TILE);
	//draw_map(game);
	start_angle = player->angle - (M_PI / 3) / 2;
	angle_step = (M_PI / 3) / 320;
	ray_angle = start_angle;
	i = -1;
	while (++i < 320)
	{
		ray_x = player->x * TILE;
		ray_y = player->y * TILE;

		cos_angle = cos(ray_angle);
		sin_angle = sin(ray_angle);
		while (!wall_detection(game, ray_x, ray_y))
		{
			//my_pixel_put(game, ray_x, ray_y, 0xff0000);
			ray_x += cos_angle * 1.0;
			ray_y += sin_angle * 1.0;
		}
		// Calculate distance to the wall
        float distance = sqrt(pow(ray_x - player->x * TILE, 2) + pow(ray_y - player->y * TILE, 2));

        // Fix fisheye distortion
        distance *= cos(player->angle - ray_angle);

        // Project the wall slice height
        int wall_height = (TILE * HEIGHT) / distance;

        // Draw the vertical slice of the wall
        for (int y = (HEIGHT / 2) - (wall_height / 2); y < (HEIGHT / 2) + (wall_height / 2); y++)
        {
            my_pixel_put(game, i * (WIDTH / 320), y, 0xff00); // Draw wall slice
        }
		ray_angle += angle_step;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (SUCCESS);
}
