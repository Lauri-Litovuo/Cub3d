#include "cubed_bonus.h"

double	get_vert_distance(t_data *data, double ray_angle)
{
	double		vert_distance;
	long long	*p_coord;

	p_coord = data->player_coord;
	if (ray_angle < 90)
	{
		vert_distance = (data->vert_intersection_coord[0]) - p_coord[0] \
		/ cos(convert_to_radians(90 - ray_angle));
	}
	else if (ray_angle > 90 && ray_angle < 180)
	{
		vert_distance = (data->vert_intersection_coord[0] - p_coord[0]) \
		/ cos(convert_to_radians(ray_angle - 90));
	}
	else if (ray_angle > 180 && ray_angle < 270)
	{
		vert_distance = (p_coord[0] - (data->vert_intersection_coord[0])) \
		/ cos(convert_to_radians(270 - ray_angle));
	}
	else
	{
		vert_distance = (p_coord[0] - (data->vert_intersection_coord[0])) \
		/ cos(convert_to_radians(ray_angle - 270));
	}
	return (vert_distance);
}

double	get_horiz_distance(t_data *data, double ray_angle)
{
	double		horiz_distance;
	long long	*p_coord;

	p_coord = data->player_coord;
	if (ray_angle < 90)
	{
		horiz_distance = (p_coord[1] - (data->horizon_intersection_coord[1])) \
		/ sin(convert_to_radians(90 - ray_angle));
	}
	else if (ray_angle > 90 && ray_angle < 180)
	{
		horiz_distance = ((data->horizon_intersection_coord[1]) - p_coord[1]) \
		/ sin(convert_to_radians(ray_angle - 90));
	}
	else if (ray_angle > 180 && ray_angle < 270)
	{
		horiz_distance = ((data->horizon_intersection_coord[1]) - p_coord[1]) \
		/ sin(convert_to_radians(270 - ray_angle));
	}
	else
	{
		horiz_distance = (p_coord[1] - (data->horizon_intersection_coord[1])) \
		/ sin(convert_to_radians(ray_angle - 270));
	}
	return (horiz_distance);
}

double	compare_distance(t_data *data, double ray_angle)
{
	double	vert_dist;
	double	horiz_dist;
	double	p_angl;

	p_angl = data->player_angle;
	if (data->invalid_vert == 0)
		vert_dist = get_vert_distance(data, ray_angle);
	if (data->invalid_horiz == 0)
		horiz_dist = get_horiz_distance(data, ray_angle);
	if (data->invalid_horiz == 1 || (data->invalid_vert == 0 && vert_dist < horiz_dist))
	{
		data->v_h_flag = 0;
		return (vert_dist * cos(convert_to_radians (p_angl - ray_angle)));
	}
	else
	{
		data->v_h_flag = 1;
		return (horiz_dist * cos(convert_to_radians (p_angl - ray_angle)));
	}
}
