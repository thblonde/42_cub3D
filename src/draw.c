#include "../include/cub3d.h"

void	fast_pixel_put(t_game *game, int x, int y, int color)
{
	int	offset;

  if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
    return ;
	offset = y * game->line_length + x * (game->bits_per_pixel / 8);
	game->addr[offset] = color & 0xFF;
	game->addr[offset + 1] = (color >> 8) & 0xFF;
	game->addr[offset + 2] = (color >> 16) & 0xFF;
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

void  print_map(t_game *game)
{
  int y;
  int x;
  char  **map;

  map = game->map;
  y = 0;
  while (map[y])
  {
    x = 0;
    while (map[y][x])
    {
      if (map[y][x] == '1')
        print_square(game, x * 64, y * 64, 0xfaf0e6, 64);
      x++;
    }
    y++;
  }
} 

int	print_loop(t_game *game)
{
	t_player	*player;

	player = &game->playr;
	move_player(player, game);
	clear_img(game);
	print_square(game, player->player_x, player->player_y, 0xfaf0e6, 20);
  print_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

