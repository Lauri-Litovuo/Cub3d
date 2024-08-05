/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:27:22 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/05 13:26:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void rotation(double x_pos, double y_pos, void *param)
{
	t_data	*data;
	double	rotation;
	double	new_angle;

	data = (t_data *)param;
	(void)y_pos;
	rotation = (x_pos - WINDOW_WIDTH / 2) * PLAYER_TURN_SPEED;
	new_angle = rotation + PLAYER_TURN_SPEED;
	data->player_angle = new_angle;
	if (data->player_angle > 360)
		data->player_angle -= 360;
	if (data->player_angle < 0)
		data->player_angle += 360;
	delete_and_init_images(data);
	draw_image(data);
	if (mlx_image_to_window(data->mlx, data->game_img, 0, 0) < 0)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	mlx_set_instance_depth(&data->game_img->instances[0], 1);
	mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}


