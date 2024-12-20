/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:11:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/02 11:11:52 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	check_for_wall(t_data *data, long long *wall_coord, char vh_flag)
{
	long long	x;
	long long	y;

	x = wall_coord[0];
	y = wall_coord[1];
	if (x < 0 || y < 0)
	{
		if (vh_flag == 'V')
			data->invalid_vert = 1;
		else
			data->invalid_horiz = 1;
		return (1);
	}
	else if (data->map[y][x].type == 'X')
	{
		if (vh_flag == 'V')
			data->invalid_vert = 1;
		else
			data->invalid_horiz = 1;
		return (1);
	}
	if (data->map[y][x].type == '1')
		return (1);
	return (0);
}

void	get_horizon_intersection(t_data *data, double ray_angle, \
long long *w_coord, int cnt)
{
	long long	*p_crd;
	long long	temp_coord[2];

	p_crd = data->player_coord;
	if (ray_angle < 90 || ray_angle > 270)
	{
		temp_coord[1] = (p_crd[1] - (p_crd[1] % IMG_SIZE)) - (cnt * IMG_SIZE);
		w_coord[1] = (temp_coord[1] - 1) / IMG_SIZE;
	}
	else
	{
		temp_coord[1] = (p_crd[1] + (IMG_SIZE - (p_crd[1] % IMG_SIZE))) \
		+ (cnt * IMG_SIZE);
		w_coord[1] = (temp_coord[1] + 1) / IMG_SIZE;
	}
	if (ray_angle < 90)
		w_coord[0] = get_up_right_x(data, temp_coord, ray_angle);
	else if (ray_angle > 90 && ray_angle < 180)
		w_coord[0] = get_down_right_x(data, temp_coord, ray_angle);
	else if (ray_angle > 180 && ray_angle < 270)
		w_coord[0] = get_down_left_x(data, temp_coord, ray_angle);
	else
		w_coord[0] = get_up_left_x(data, temp_coord, ray_angle);
	data->horiz_inters_crd[0] = temp_coord[0];
	data->horiz_inters_crd[1] = temp_coord[1];
}

void	get_vert_intersection(t_data *data, double ray_angle, \
long long *w_coord, int cnt)
{
	long long	*p_crd;
	long long	temp_coord[2];

	p_crd = data->player_coord;
	if (ray_angle < 180)
	{
		temp_coord[0] = (p_crd[0] + (IMG_SIZE - (p_crd[0] % IMG_SIZE))) \
		+ (cnt * IMG_SIZE);
		w_coord[0] = (temp_coord[0] + 1) / IMG_SIZE;
	}
	else
	{
		temp_coord[0] = (p_crd[0] - (p_crd[0] % IMG_SIZE)) - (cnt * IMG_SIZE);
		w_coord[0] = (temp_coord[0] - 1) / IMG_SIZE;
	}
	if (ray_angle < 90)
		w_coord[1] = get_up_right_y(data, temp_coord, ray_angle);
	else if (ray_angle > 90 && ray_angle < 180)
		w_coord[1] = get_down_right_y(data, temp_coord, ray_angle);
	else if (ray_angle > 180 && ray_angle < 270)
		w_coord[1] = get_down_left_y(data, temp_coord, ray_angle);
	else
		w_coord[1] = get_up_left_y(data, temp_coord, ray_angle);
	data->vert_inters_crd[0] = temp_coord[0];
	data->vert_inters_crd[1] = temp_coord[1];
}

double	find_wall_distance(t_data *data, double ray_angle, double addition)
{
	int			i;
	long long	vert_coords[2];
	long long	horiz_coords[2];

	data->invalid_vert = 0;
	data->invalid_horiz = 0;
	if (ray_angle == 0.0000 || ray_angle - 90.0000 == 0 \
	|| ray_angle - 180.0000 == 0 || ray_angle - 270.0000 == 0)
		ray_angle += addition;
	get_vert_intersection(data, ray_angle, vert_coords, 0);
	i = 1;
	while (check_for_wall(data, vert_coords, 'V') != 1)
		get_vert_intersection(data, ray_angle, vert_coords, i++);
	get_horizon_intersection(data, ray_angle, horiz_coords, 0);
	i = 1;
	while (check_for_wall(data, horiz_coords, 'H') != 1)
		get_horizon_intersection(data, ray_angle, horiz_coords, i++);
	return (compare_distance(data, ray_angle, vert_coords, horiz_coords));
}
