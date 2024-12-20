/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection_x_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:03:29 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/17 13:03:30 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

long long	get_up_right_x(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[0] = p_coord[0] + ((p_coord[1] - t_coord[1]) \
	/ tan(conv_to_rad(90 - ray_angle)));
	if (t_coord[0] >= ((data->map_width) * IMG_SIZE))
		return (data->map_width - 1);
	else
		return (t_coord[0] / IMG_SIZE);
}

long long	get_down_right_x(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[0] = p_coord[0] + ((t_coord[1] - p_coord[1]) \
	/ tan(conv_to_rad(ray_angle - 90)));
	if (t_coord[0] >= ((data->map_width) * IMG_SIZE))
		return (data->map_width - 1);
	else
		return (t_coord[0] / IMG_SIZE);
}

long long	get_down_left_x(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[0] = p_coord[0] - ((t_coord[1] - p_coord[1]) \
	/ tan(conv_to_rad(270 - ray_angle)));
	if (t_coord[0] < 0)
		return (0);
	else
		return (t_coord[0] / IMG_SIZE);
}

long long	get_up_left_x(t_data *data, long long *t_coord, double ray_angle)
{
	long long	*p_coord;

	p_coord = data->player_coord;
	t_coord[0] = p_coord[0] - ((p_coord[1] - t_coord[1]) \
	/ tan(conv_to_rad(ray_angle - 270)));
	if (t_coord[0] < 0)
		return (0);
	else
		return (t_coord[0] / IMG_SIZE);
}
