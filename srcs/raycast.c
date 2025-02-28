#include "cub3d.h"

void bresenham_line_algo(t_game *game, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1; // Step in x direction
    int sy = (y1 < y2) ? 1 : -1; // Step in y direction
    int err = dx - dy;           // Error value

    while (1) {
        my_pixel_put(game, x1, y1, 0xff0000);  // Plot the current point
        
        if (x1 == x2 && y1 == y2) {
            break;  // If we've reached the endpoint, stop the loop
        }

        int e2 = err * 2;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int	raycast(t_game *game)
{
	t_player	*player;
	float			x_end; /* end position of the ray */
	float			y_end; /* end position of the ray */
	float			len; /* len of the ray */

	player = &game->player;
	len = 100;
	x_end = player->x * TILE + len * cos(player->angle);
	y_end = player->x * TILE + len * sin(player->angle);
	bresenham_line_algo(game, player->x * TILE, player->y * TILE, x_end, y_end);
	return (SUCCESS);
}
