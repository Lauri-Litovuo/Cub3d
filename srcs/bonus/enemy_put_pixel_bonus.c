#include "cubed_bonus.h"

void	get_enemy_pixels(t_data *data, int i, double enemy_player_angle)
{
	if (enemy_player_angle > 315 || enemy_player_angle <= 45)
	{
		if (data->enemy[i].direction == 0)
			data->pixels = data->enemy_img[2]->pixels;
		else if (data->enemy[i].direction == 1)
			data->pixels = data->enemy_img[3]->pixels;
		else if (data->enemy[i].direction == 2)
			data->pixels = data->enemy_img[0]->pixels;
		else if (data->enemy[i].direction == 3)
			data->pixels = data->enemy_img[1]->pixels;
	}
	else if (enemy_player_angle > 45 && enemy_player_angle <= 135)
	{
		if (data->enemy[i].direction == 0)
			data->pixels = data->enemy_img[1]->pixels;
		else if (data->enemy[i].direction == 1)
			data->pixels = data->enemy_img[2]->pixels;
		else if (data->enemy[i].direction == 2)
			data->pixels = data->enemy_img[3]->pixels;
		else if (data->enemy[i].direction == 3)
			data->pixels = data->enemy_img[0]->pixels;
	}
	else if (enemy_player_angle > 135 && enemy_player_angle <= 225)
	{
		if (data->enemy[i].direction == 0)
			data->pixels = data->enemy_img[0]->pixels;
		else if (data->enemy[i].direction == 1)
			data->pixels = data->enemy_img[1]->pixels;
		else if (data->enemy[i].direction == 2)
			data->pixels = data->enemy_img[2]->pixels;
		else if (data->enemy[i].direction == 3)
			data->pixels = data->enemy_img[3]->pixels;
	}
	else
	{
		if (data->enemy[i].direction == 0)
			data->pixels = data->enemy_img[3]->pixels;
		else if (data->enemy[i].direction == 1)
			data->pixels = data->enemy_img[0]->pixels;
		else if (data->enemy[i].direction == 2)
			data->pixels = data->enemy_img[1]->pixels;
		else if (data->enemy[i].direction == 3)
			data->pixels = data->enemy_img[2]->pixels;
	}
}

int	colour_enemy_pixel(t_data *data, long long *start_coord, int pixel_counter, int i)
{
	int		colour;
	uint8_t	*pixels;

	pixels = data->pixels;
	colour = get_rgba(pixels[i], pixels[i + 1], pixels[i + 2], pixels[i + 3]);
	mlx_put_pixel(data->door_canvas, data->ray_iterator, *start_coord, colour);
	*start_coord += 1;
	return (pixel_counter + 1);
}

int	enemy_draw_execute(t_data *data, int i, double drawn_enemy_height, long long start_coord)
{
	int		px_cnt;
	double	pixel_iter;

	px_cnt = 0;
	pixel_iter = 0.0;
	while (i < (ENEMY_WIDTH * ENEMY_HEIGHT * 4) && px_cnt < WINDOW_HEIGHT)
	{
		if (start_coord < 0)
			start_coord++;
		else
			px_cnt = colour_enemy_pixel(data, &start_coord, px_cnt, i);
		pixel_iter += (ENEMY_HEIGHT / drawn_enemy_height);
		if (pixel_iter > 1)
		{
			while (pixel_iter > 1)
			{
				pixel_iter -= 1;
				i += (ENEMY_WIDTH * 4);
			}
		}
	}
	return (start_coord);
}

void	put_enemy_pixel(t_data *data, long long start_coord, double *enemy_limits, double ray_angle, double drawn_enemy_height)
{	
	int				column;
	double			column_width;

	column_width = (enemy_limits[1] - enemy_limits[0]) / ENEMY_WIDTH;
	column = (ray_angle - enemy_limits[0]) / column_width;

    enemy_draw_execute(data, (column * 4), drawn_enemy_height, start_coord);
}