#include "cubed_bonus.h"

void	get_enemy_img_3(t_data *data)
{
	mlx_texture_t	*enemy_text;

	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/dead2.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_dead_img[2] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_dead_img[2])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/dead3.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_dead_img[3] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_dead_img[3])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/dead4.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_dead_img[4] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_dead_img[4])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
}

void	get_enemy_img_2(t_data *data)
{
	mlx_texture_t	*enemy_text;

	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/enemy_right.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_img[3] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_img[3])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/dead0.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_dead_img[0] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_dead_img[0])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/dead1.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_dead_img[1] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_dead_img[1])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);	
}

void	get_enemy_img_1(t_data *data)
{
	mlx_texture_t	*enemy_text;

	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/enemy_front.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_img[0] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_img[0])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/enemy_left.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_img[1] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_img[1])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
	enemy_text = mlx_load_png("./sprites/enemy/cacodeamon/enemy_back.png");
	if (!enemy_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->enemy_img[2] = mlx_texture_to_image(data->mlx, enemy_text);
	if (!data->enemy_img[2])
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(enemy_text);
}

void	set_enemy_struct(t_data *data, int i, int x, int y)
{
	if (i == 0)
	{
		data->enemy[i].x = 3 * IMG_SIZE + (IMG_SIZE / 2); // TEST
		data->enemy[i].y = 2 * IMG_SIZE + (IMG_SIZE / 2); // TEST
	}
	else
	{
		data->enemy[i].x = 4 * IMG_SIZE + (IMG_SIZE / 2); // TEST
		data->enemy[i].y = 3 * IMG_SIZE + (IMG_SIZE / 2); // TEST
	}

	// TEST FOR MINIMAP
	
	x = data->enemy[i].x / IMG_SIZE;
	y = data->enemy[i].y / IMG_SIZE;

	data->map[y][x].is_enemy = 1;

	// TEST FOR MINIMAP

	data->enemy[i].direction = -1;
	data->enemy[i].step_count = -1;
	data->enemy[i].is_dying = 0;
	data->enemy[i].is_dead = 0;
	data->enemy[i].dead_anim_iter = 0;
	data->enemy[i].prev_time = 0;
	data->enemy[i].prev_dead_time = 0;
	data->enemy[i].enemy_anim_height_iter = -10;
}
void	init_enemies(t_data *data)
{
	int		i;
	int		x = 0; // TEST
	int		y = 0; // TEST

	data->enemy_count = 2; // Fix this later.
	data->enemy = malloc(data->enemy_count * sizeof(t_enemy));
	if (data->enemy == NULL)
		sys_error_exit(data, "Malloc failed", 0);
	get_enemy_img_1(data);
	get_enemy_img_2(data);
	get_enemy_img_3(data);
	i = 0;
	while (i < data->enemy_count)
	{
		/*x = 0;
		y = 0;
		while (data->map[y][x].type == '1' || data->map[y][x].type == 'P'\
		|| check_start_coords(data, i, x, y) == 1)
		{
			x = get_rand_coord(data, 'x');
			y = get_rand_coord(data, 'y');
		} */
		set_enemy_struct(data, i, x, y);
		i++;
	}
}

/*
int	check_start_coords(t_data *data, int i, int x, int y)
{
	long long	safe_zone;
	long long	p_coord[2];

	safe_zone = 3;
	p_coord[0] = data->player_coord[0] / IMG_SIZE;
	p_coord[1] = data->player_coord[1] / IMG_SIZE;

	if (data->enemy_count == 1)
	{
		if (x >= p_coord[0] - safe_zone && x <= p_coord[0] + safe_zone && \
		y >= p_coord[1] - safe_zone && y <= p_coord[1] + safe_zone)
			return (1);
		else
			return (0);
	}
	else
	{
		i = 0; // TEST
		i++; // TEST
		i--; // TEST
		return (i);
	}
	else
	{
		while (--i > -1)
		{
			if ((game->enemies[i].x <= x + 1 && game->enemies[i].x >= x - 1) \
			&& \
			(game->enemies[i].y <= y + 1 && game->enemies[i].y >= y - 1))
				return (1);
		}
		if (x >= game->player_coord[0] - 2 && x <= game->player_coord[0] + 2 && \
		y >= game->player_coord[1] - 2 && y <= game->player_coord[1] + 2)
			return (1);
		else
			return (0);
	} 
}*/
/*
int	get_rand_coord(t_data *data, char xy)
{
	int			coord;
	int			max;

	if (xy == 'x')
		max = data->map_width - 1;
	else
		max = data->map_height - 1;
	srand(time(NULL));
	coord = rand() % max;
	return (coord);
}
*/
