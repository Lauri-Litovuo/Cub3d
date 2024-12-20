/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:04:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/17 13:04:52 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

double	conv_to_rad(double angle_in_degrees)
{
	return (angle_in_degrees * (PI / 180.0));
}

double	conv_to_deg(double angle_in_rad)
{
	return (angle_in_rad / (PI / 180.0));
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	print_goodbye_message(void)
{
	printf("\n*****************************\n");
	printf(" *                           *\n");
	printf("*   Thank you for playing!  *\n");
	printf(" *                           *\n");
	printf("*     See you again! =)     *\n");
	printf(" *                           *\n");
	printf("*****************************\n\n");
}

void	delete_and_init_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->game_img);
	mlx_delete_image(data->mlx, data->door_canvas);
	mlx_delete_image(data->mlx, data->player_icon);
	data->game_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->game_img)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	data->door_canvas = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->door_canvas)
		error_exit(data, mlx_strerror(mlx_errno), 1);
	init_door_canvas(data);
}
