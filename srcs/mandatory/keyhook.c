#include "cubed.h"

void	key_action_left(t_data *data)
{
	data->player_angle -= PLAYER_TURN_SPEED;
	if (data->player_angle < 0)
		data->player_angle = 360 - (data->player_angle * -1);
	mlx_delete_image(data->mlx, data->game_img);
	data->game_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->game_img)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	draw_image(data);
	if (mlx_image_to_window(data->mlx, data->game_img, 0, 0) < 0)
		error_exit(data, mlx_strerror(mlx_errno), 1);
}

void	key_action_right(t_data *data)
{
	data->player_angle += PLAYER_TURN_SPEED;
	if (data->player_angle >= 360)
		data->player_angle -= 360;
	mlx_delete_image(data->mlx, data->game_img);
	data->game_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->game_img)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	draw_image(data);
	if (mlx_image_to_window(data->mlx, data->game_img, 0, 0) < 0)
		error_exit(data, mlx_strerror(mlx_errno), 1);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data		*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_action_w(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_action_d(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_action_s(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_action_a(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		key_action_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		key_action_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		success_exit(data);
}