#include "cubed_bonus.h"

void	get_wall_sw_images(t_data *data)
{
	mlx_texture_t	*wall_text;

	wall_text = mlx_load_png(data->texture_path_s);
	if (!wall_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->wall_img_s = mlx_texture_to_image(data->mlx, wall_text);
	if (!data->wall_img_s)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(wall_text);
	wall_text = mlx_load_png(data->texture_path_w);
	if (!wall_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->wall_img_w = mlx_texture_to_image(data->mlx, wall_text);
	if (!data->wall_img_w)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(wall_text);
}

void	get_wall_ne_images(t_data *data)
{
	mlx_texture_t	*wall_text;

	wall_text = mlx_load_png(data->texture_path_n);
	if (!wall_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->wall_img_n = mlx_texture_to_image(data->mlx, wall_text);
	if (!data->wall_img_n)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(wall_text);
	wall_text = mlx_load_png(data->texture_path_e);
	if (!wall_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->wall_img_e = mlx_texture_to_image(data->mlx, wall_text);
	if (!data->wall_img_e)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(wall_text);
}

void	make_image(mlx_image_t *gun, char *sprite_path, t_data *data)
{
	mlx_texture_t	*gun_text;

	gun_text = mlx_load_png(sprite_path);
	if (!gun_text)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	gun = mlx_texture_to_image(data->mlx, gun_text);
	if (!gun)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_delete_texture(gun_text);
}

void get_weapon_images(t_data *data)
{
	int	i;
	char *sprite_paths[W_S_COUNT];

	sprite_paths[0] = WS0;
	sprite_paths[1] = WS1;
	sprite_paths[2] = WS2;
	sprite_paths[3] = WS3;
	sprite_paths[4] = WS4;

	i = 0;
	while (i < W_S_COUNT)
		make_image(data->gun[i], sprite_paths[i], data);
}

void	get_images(t_data *data)
{
	get_wall_ne_images(data);
	get_wall_sw_images(data);
	get_weapon_images(data);
	data->game_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->game_img)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->player_coord[0] = data->player_x_pos * IMG_SIZE + (IMG_SIZE / 2);
	data->player_coord[1] = data->player_y_pos * IMG_SIZE + (IMG_SIZE / 2);
	data->fl_colour = get_rgba(data->floor_color->r, data->floor_color->g, \
	data->floor_color->b, 255);
	data->ceil_colour = get_rgba(data->ceiling_color->r, \
	data->ceiling_color->g, data->ceiling_color->b, 255);
}
